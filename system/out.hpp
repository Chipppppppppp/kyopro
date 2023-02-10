#pragma once
#include <unistd.h>
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <iterator>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>
#include "io_option.hpp"
#include "../meta/setting.hpp"
#include "../meta/trait.hpp"
#include "../meta/tuple_like.hpp"

namespace kpr {
    // バッファを用いてファイルに書き込むクラス
    template<std::size_t buf_size = KYOPRO_BUFFER_SIZE>
    struct Writer {
    private:
        int fd, idx;
        std::array<char, buf_size> buffer;

    public:
        // バッファサイズを取得
        static constexpr KYOPRO_BASE_INT get_buf_size() noexcept {
            return buf_size;
        }

        Writer() noexcept = default;
        Writer(int fd) noexcept: fd(fd), idx(0), buffer() {}
        Writer(FILE* fp) noexcept: fd(fileno(fp)), idx(0), buffer() {}

        ~Writer() {
            write(fd, buffer.begin(), idx);
        }

        // 出力イテレータ
        struct iterator {
        private:
            Writer& writer;

        public:
            using difference_type = void;
            using value_type = void;
            using pointer = void;
            using reference = void;
            using iterator_category = std::output_iterator_tag;

            iterator() noexcept = default;
            iterator(Writer& writer) noexcept: writer(writer) {}

            iterator& operator ++() {
                ++writer.idx;
                if (writer.idx == buf_size) {
                write(writer.fd, writer.buffer.begin(), buf_size);
                writer.idx = 0;
                }
                return *this;
            }

            iterator operator ++(int) {
                iterator before = *this;
                operator ++();
                return before;
            }

            char& operator *() const {
                return writer.buffer[writer.idx];
            }

            // バッファを全て出力する
            void flush() const {
                write(writer.fd, writer.buffer.begin(), writer.idx);
            }
        };

        // ファイルの最初を示すイテレータを取得
        iterator begin() noexcept {
            return iterator(*this);
        }
    };

    // 標準出力、標準エラー出力
    Writer output{1}, error{2};

    // 値の出力の関数クラス
    template<class, class = void>
    struct PrintFunction;

    // 出力イテレータを用いて値を出力するクラス
    template<class Iterator, bool _space = true, bool _line = true, bool _debug = false, bool _comment = false, bool _flush = false, std::size_t decimal_precision = KYOPRO_DECIMAL_PRECISION>
    struct Printer {
        using iterator_type = Iterator;

        // 指定されたオプション
        static constexpr bool space = _space, line = _line, debug = _debug, comment = _comment, flush = _flush;

        // 指定された小数誤差を取得
        static constexpr KYOPRO_BASE_INT get_decimal_precision() noexcept {
            return decimal_precision;
        }

        // 出力イテレータ
        Iterator itr;

        Printer() noexcept = default;
        Printer(Iterator itr) noexcept: itr(itr) {}

        // 一文字出力する
        void print_char(char c) {
            *itr = c;
            ++itr;
        }

        // 整数、小数を出力
        template<class T>
        void print_arithmetic(T a) {
            if constexpr (is_floating_point_v<T>) {
                if (a == std::numeric_limits<T>::infinity()) {
                    PrintFunction<const char[4]>::print(printer, "inf");
                    return;
                }
                if (a == -std::numeric_limits<T>::infinity()) {
                    PrintFunction<const char[5]>::print(printer, "-inf");
                    return;
                }
                if (std::isnan(a)) {
                    PrintFunction<const char[4]>::print(printer, "nan");
                    return;
                }
            }
            if constexpr (std::is_signed_v<T>) if (a < 0) {
                printer.print_char('-');
                a = -a;
            }
            std::uint_fast64_t p = a;
            std::string s;
            do {
                s += '0' + p % 10;
                p /= 10;
            } while (p > 0);
            for (auto i = s.rbegin(); i != s.rend(); ++i) printer.print_char(*i);
            if constexpr (is_integer_v<T>) return;
            printer.print_char('.');
            a -= p;
            for (int i = 0; i < static_cast<int>(decimal_precision); ++i) {
                a *= 10;
                printer.print_char('0' + static_cast<std::uint_fast64_t>(a) % 10);
            }
        }

        // 区切りを出力する
        void print_sep() {
            if constexpr (debug) print_char(',');
            if constexpr (space) print_char(' ');
        }

        // 最後の文字を出力する
        void print_end() {
            if constexpr (debug) print_char(',');
            if constexpr (line) print_char('\n');
        }

        // コメント記号を出力する
        void print_comment() {
            if constexpr (comment) {
                print_char('#');
                print_char(' ');
            }
        }

        // 複数の値を出力
        template<bool first = true>
        void operator ()() {
            if constexpr (first) print_comment();
            print_end();
            if constexpr (flush) itr.flush();
        }
        template<bool first = true, class Head, class... Args>
        void operator ()(Head&& head, Args&&... args) {
            if constexpr (first) print_comment();
            else {
                if constexpr (debug) print_char(',');
                print_sep();
            }
            PrintFunction<std::decay_t<Head>>::print(*this, std::forward<Head>(head));
            operator ()<false>(std::forward<Args>(args)...);
        }
    };

    template<>
    struct PrintFunction<char> {
        template<class Printer>
        static void print(Printer& printer, char a) {
            if constexpr (debug) printer.print_char('\'');
            printer.print_char(a);
            if constexpr (debug) printer.print_char('\'');
        }
    };

    template<>
    struct PrintFunction<bool> {
        template<class Printer>
        static void print(Printer& printer, bool a) {
            printer.print_char(static_cast<char>('0' + a));
        }
    };

    template<class T>
    struct PrintFunction<T, std::enable_if_t<std::is_convertible_v<T, std::string_view>>> {
        template<class Printer>
        static void print(Printer& printer, std::string_view a) {
            if constexpr (debug) printer.print_char('"');
            for (char i: a) printer.print_char(i);
            if constexpr (debug) printer.print_char('"');
        }
    };

    template<std::size_t len>
    struct PrintFunction<std::bitset<len>> {
        template<class Printer>
        static void print(Printer& printer, const std::bitset<len>& a) {
            for (int i = len - 1; i >= 0; --i) PrintFunction<bool>::print(printer, a[i]);
        }
    };

    template<class T>
    struct PrintFunction<T, std::enable_if_t<std::is_arithmetic_v<T>>> {
        template<class Printer>
        static void print(Printer& printer, T a) {

        }
    };

    template<class T>
    struct PrintFunction<T, std::enable_if_t<is_tuple_like_v<T> && !is_range_v<T>>> {
        template<class Printer, std::size_t i = 0>
        static void print(Printer& printer, const T& a) {
            if constexpr (debug && i == 0) printer.print_char('{');
            if constexpr (tuple_like_size_v<T> != 0) PrintFunction<std::decay_t<tuple_like_element_t<i, T>>>::print(printer, get<i>(a));
            if constexpr (i + 1 < tuple_like_size_v<T>) {
                printer.print_sep();
                print<i + 1>(printer, a);
            } else if constexpr (debug) printer.print_char('}');
        }
    };

    template<class T>
    struct PrintFunction<T, std::enable_if_t<is_range_v<T>>> {
        template<class Printer>
        static void print(Printer& printer, const T& a) {
            if constexpr (debug) print_char('{');
            if (std::empty(a)) return;
            for (auto i = std::begin(a); ; ) {
                PrintFunction<range_value_t<T>>::print(printer, *i);
                if (++i != std::end(a)) printer.print_sep();
                else break;
            }
            if constexpr (debug) print_char('}');
        }
    };

    template<class Tuple, std::size_t idx>
    struct PrintFunction<Indexed<Tuple, idx>> {
        template<class Printer>
        struct PrinterWrapper: Printer {
            template<class T>
            void printer_arithmetic(T a) {
                print_arithmetic(a - 1);
            }
        };
        template<class Printer>
        static void scan(Printer& printer, const Indexed<Tuple, idx>& a) {
            PrinterWrapper<Printer>& printer_wrapper = static_cast<PrinterWrapper<Printer>&>(printer);
            PrintFunction<Tuple>::print(printer_wrapper, a.args_tuple);
        }
    };

    // 標準出力、標準エラー出力に値を出力する(改行、区切り文字なし)
    Printer<Writer<>::iterator, false, false> print{output.begin()}, eprint{error.begin()};
    // 標準出力、標準エラー出力に値を出力する(改行、区切り文字あり)
    Printer<Writer<>::iterator> println{output.begin()}, eprintln{error.begin()};
} // namespace kpr
