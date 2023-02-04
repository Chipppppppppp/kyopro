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
#include <tuple>
#include <type_traits>
#include <utility>
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
        Writer(FILE* fp) noexcept: fd(std::fileno(fp)), idx(0), buffer() {}

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
    Writer output(1), error(2);

    // 出力イテレータを用いて値を出力するクラス
    template<class Iterator, bool _sep = true, bool _sep_line = true, bool _end_line = true, bool _debug = false, bool _comment = false, bool _flush = false, std::size_t decimal_precision = KYOPRO_DECIMAL_PRECISION>
    struct Printer {
        using iterator_type = Iterator;

        // 指定されたオプションを取得
        static constexpr bool sep = _sep, end_line = _end_line, sep_line = _sep_line, debug = _debug, comment = _comment, flush = _flush;

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

        // 区切り文字を出力する
        void print_sep() {
            if constexpr (sep) {
                if constexpr (debug) print_char(',');
                print_char(' ');
            }
        }

        // 値の出力の関数クラス
        template<class, class = void>
        struct PrintFunction;

        template<class T>
        struct PrintFunction<char, T> {
            static void print(Printer& printer, char a) {
                if constexpr (debug) printer.print_char('\'');
                printer.print_char(a);
                if constexpr (debug) printer.print_char('\'');
            }
        };

        template<class T>
        struct PrintFunction<bool, T> {
            static void print(Printer& printer, bool a) {
                printer.print_char(static_cast<char>('0' + a));
            }
        };

        template<class T>
        struct PrintFunction<T, std::enable_if_t<std::is_convertible_v<T, std::string_view>>> {
            static void print(Printer& printer, std::string_view a) {
                if constexpr (debug) printer.print_char('"');
                for (; *a != '\0'; ++a) printer.print_char(*a);
                if constexpr (debug) printer.print_char('"');
            }
        };

        template<std::size_t len>
        struct PrintFunction<std::bitset<len>> {
            static void print(Printer& printer, const std::bitset<len>& a) {
                for (int i = len - 1; i >= 0; --i) PrintFunction<bool>::print(a[i]);
            }
        };

        template<class T>
        struct PrintFunction<T, std::enable_if_t<std::is_arithmetic_v<T>>> {
            static void print(Printer& printer, T a) {
                if constexpr (std::is_floating_point_v<T>) {
                    if (a == std::numeric_limits<T>::infinity()) {
                        PrintFunction<const char*>::print("inf");
                        return;
                    }
                    if (a == -std::numeric_limits<T>::infinity()) {
                        PrintFunction<const char*>::print("-inf");
                        return;
                    }
                    if (std::isnan(a)) {
                        PrintFunction<const char*>::print("nan");
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
                if constexpr (std::is_integral_v<T>) return;
                printer.print_char('.');
                a -= p;
                for (int i = 0; i < static_cast<int>(decimal_precision); ++i) {
                    a *= 10;
                    printer.print_char('0' + static_cast<std::uint_fast64_t>(a) % 10);
                }
            }
        };

        template<class T>
        struct PrintFunction<T, std::enable_if_t<is_tuple_like_v<T> && !is_range_v<T>>> {
            template<std::size_t i = 0>
            static void print(Printer& printer, const T& a) {
                if constexpr (debug && i == 0) printer.print_char('{');
                if constexpr (tuple_like_size_v<T> != 0) print(get<i>(a));
                if constexpr (i + 1 < tuple_like_size_v<T>) {
                    printer.print_sep<max_rank_v<T>>();
                    PrintFunction<>::print<i + 1>(a);
                } else if constexpr (debug) print_char('}');
            }
        };

        template<class T>
        struct PrintFunction<T, std::enable_if_t<is_range_v<T>>> {
            static void print(Printer& printer, const T& a) {
                if constexpr (debug) print_char('{');
                if (std::empty(a)) return;
                for (auto i = std::begin(a); ; ) {
                    print(*i);
                    if (++i != std::end(a)) {
                    print_sep<max_rank_v<T>>();
                    } else break;
                }
                if constexpr (debug) print_char('}');
            }
        };

        // 複数の値を出力
        template<bool first = true>
        void operator ()() {
            if constexpr (comment && first) print_char('#');
            if constexpr (end_line) print_char('\n');
            if constexpr (flush) itr.flush();
        }
        template<bool first = true, class Head, class... Args>
        void operator ()(Head&& head, Args&&... args) {
            if constexpr (comment && first) {
                print_char('#');
                print_char(' ');
            }
            if constexpr (sep && !first) print_sep<0>();
            PrintFunction<std::decay_t<Head>>::print(std::forward<Head>(head));
            operator ()<false>(std::forward<Args>(args)...);
        }
    };

    // 標準出力、標準エラー出力に値を出力する(改行、区切り文字なし)
    Printer<Writer<>::iterator, false, false, false> print(output.begin()), eprint(error.begin());

    // 標準出力、標準エラー出力に値を出力する(改行、区切り文字あり)
    Printer<Writer<>::iterator> println(output.begin()), eprintln(error.begin());
} // namespace kpr
