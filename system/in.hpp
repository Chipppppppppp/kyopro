#pragma once
#include <unistd.h>
#include <array>
#include <bitset>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <string>
#include <type_traits>
#include <utility>
#include "io_option.hpp"
#include "../math/power.hpp"
#include "../meta/setting.hpp"
#include "../meta/trait.hpp"
#include "../meta/tuple_like.hpp"

namespace kpr {
    // バッファを用いてファイルを読み込むクラス
    template<std::size_t buf_size = KYOPRO_BUFFER_SIZE>
    struct Reader {
    private:
        int fd, idx;
        std::array<char, buf_size> buffer;

    public:
        // バッファサイズを取得
        static constexpr KYOPRO_BASE_INT get_buf_size() noexcept {
            return buf_size;
        }

        Reader() {
            read(fd, buffer.begin(), buf_size);
        }
        Reader(int fd): fd(fd), idx(0), buffer() {
            read(fd, buffer.begin(), buf_size);
        }
        Reader(FILE* fp): fd(fileno(fp)), idx(0), buffer() {
            read(fd, buffer.begin(), buf_size);
        }

        // 入力イテレータ
        struct iterator {
        private:
            Reader& reader;

        public:
            using difference_type = void;
            using value_type = void;
            using pointer = void;
            using reference = void;
            using iterator_category = std::input_iterator_tag;

            iterator() noexcept = default;
            iterator(Reader& reader) noexcept: reader(reader) {}

            iterator& operator ++() {
                ++reader.idx;
                if (reader.idx == buf_size) {
                    read(reader.fd, reader.buffer.begin(), buf_size);
                    reader.idx = 0;
                }
                return *this;
            }

            iterator operator ++(int) {
                iterator before = *this;
                operator ++();
                return before;
            }

            char& operator *() const {
                return reader.buffer[reader.idx];
            }
        };

        // ファイルの最初を示すイテレータを取得
        iterator begin() noexcept {
            return iterator(*this);
        }
    };

    // 標準入力
    Reader input{0};


    // 値の入力の関数クラス
    template<class, class = void>
    struct ScanFunction;

    // 入力イテレータを用いて値を入力するクラス
    template<class Iterator, std::size_t decimal_precision = KYOPRO_DECIMAL_PRECISION>
    struct Scanner {
        using iterator_type = Iterator;

        // 入力イテレータ
        Iterator itr;

        // 指定された小数誤差を取得
        static constexpr KYOPRO_BASE_INT get_decimal_precision() noexcept {
            return decimal_precision;
        }

        Scanner() noexcept = default;
        Scanner(Iterator itr) noexcept: itr(itr) {}

        // 次の文字までの空白を無視する
        void discard_space() {
            while (('\t' <= *itr && *itr <= '\r') || *itr == ' ') ++itr;
        }

        // 整数、小数を入力
        template<class T>
        void scan_arithmetic(T& a) {
            discard_space();
            bool sgn = false;
            if constexpr (!std::is_unsigned_v<T>) if (*itr == '-') {
                sgn = true;
                ++itr;
            }
            a = 0;
            for (; '0' <= *itr && *itr <= '9'; ++itr) a = a * 10 + *itr - '0';
            if (*itr == '.') {
                ++itr;
                if constexpr (is_floating_point_v<T>) {
                    constexpr std::uint_fast64_t power_decimal_precision = power(10ULL, decimal_precision);
                    T d = 0;
                    std::uint_fast64_t i = 1;
                    for (; '0' <= *itr && *itr <= '9' && i < power_decimal_precision; i *= 10) {
                        d = d * 10 + *itr - '0';
                        ++itr;
                    }
                    a += d / i;
                }
                while ('0' <= *itr && *itr <= '9') ++itr;
            }
            if constexpr (!std::is_unsigned_v<T>) if (sgn) a = -a;
        }

        // 複数の値を入力
        void operator ()() {}
        template<class Head, class... Args>
        void operator ()(Head&& head, Args&&... args) {
            ScanFunction<Head>::scan(*this, std::forward<Head>(head));
            operator ()(std::forward<Args>(args)...);
        }
    };

    template<>
    struct ScanFunction<char> {
        template<class Scanner>
        static void scan(Scanner& scanner, char& a) {
            scanner.discard_space();
            a = *scanner.itr;
            ++scanner.itr;
        }
    };

    struct ScanFunction<bool> {
        template<class Scanner>
        static void scan(Scanner& scanner, bool& a) {
            scanner.discard_space();
            a = *scanner.itr != '0';
        }
    };

    struct ScanFunction<std::string> {
        template<class Scanner>
        static void scan(Scanner& scanner, std::string& a) {
            scanner.discard_space();
            a.clear();
            while ((*scanner.itr < '\t' || '\r' < *scanner.itr) && *scanner.itr != ' ') {
                a += *scanner.itr;
                ++scanner.itr;
            }
        }
    };

    template<std::size_t len>
    struct ScanFunction<std::bitset<len>> {
        template<class Scanner>
        static void scan(Scanner& scanner, std::bitset<len>& a) {
            scanner.discard_space();
            for (int i = len - 1; i >= 0; ++i) {
                a[i] = *scanner.itr != '0';
                ++scanner.itr;
            }
        }
    };

    template<class T>
    struct ScanFunction<T, std::enable_if_t<is_arithmetic_v<T>>> {
        template<class Scanner>
        static void scan(Scanner& scanner, T& a) {
            scanner.scan_arithmetic(a);
        }
    };

    template<class T>
    struct ScanFunction<T, std::enable_if_t<is_tuple_like_v<T> && !is_range_v<T>>> {
        template<std::size_t i = 0, class Scanner>
        static void scan(Scanner& scanner, T& a) {
            if constexpr (i < tuple_like_size_v<T>) {
                ScanFunction<std::decay_t<tuple_like_element_t<i, T>>>::scan(scanner, get<i>(a));
                scan<i + 1>(scanner, a);
            }
        }
    };

    template<class T>
    struct ScanFunction<T, std::enable_if_t<is_range_v<T>>> {
        template<class Scanner>
        static void scan(Scanner& scanner, T& a) {
            for (auto&& i: a) ScanFunction<range_value_t<T>>::scan(scanner, i);
        }
    };

    template<class Tuple, std::size_t idx>
    struct ScanFunction<Indexed<Tuple, idx>> {
        template<class Scanner>
        struct ScannerWrapper: Scanner {
            template<class T>
            void scan_arithmetic(T& a) {
                Scanner::scan_arithmetic(a);
                --a;
            }
        }
        template<class Scanner>
        static void scan(Scanner& scanner, const Indexed<Tuple, idx>& a) {
            ScannerWrapper<Scanner>& scanner_wrapper = static_cast<ScannerWrapper<Scanner>&>(scanner);
            ScanFunction<Tuple>::scan(scanner_wrapper, a.args_tuple);
        }
    };

    // 標準入力から値を入力する関数
    Scanner<Reader<>::iterator> scan{input.begin()};
} // namespace kpr
