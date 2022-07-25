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
#include "../meta/aggregate.hpp"
#include "../meta/settings.hpp"
#include "../meta/trait.hpp"

namespace kyopro {
    template<std::size_t _buf_size = KYOPRO_BUFFER_SIZE>
    struct Writer {
        static constexpr KYOPRO_BASE_UINT buf_size = _buf_size;

    private:
        int fd, idx;
        std::array<char, buf_size> buffer;

    public:
        Writer() noexcept = default;
        Writer(int fd) noexcept: fd(fd), idx(0), buffer() {}
        Writer(FILE* fp) noexcept: fd(fileno(fp)), idx(0), buffer() {}

        ~Writer() {
        write(fd, buffer.begin(), idx);
        }

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

        void flush() const {
            write(writer.fd, writer.buffer.begin(), writer.idx);
        }
        };

        iterator begin() noexcept {
        return iterator(*this);
        }
    };

    Writer output(1), error(2);

    template<class Iterator, bool _sep = true, bool _sep_line = true, bool _end_line = true, bool _debug = false, bool _comment = false, bool _flush = false, std::size_t _decimal_precision = KYOPRO_DECIMAL_PRECISION>
    struct Printer {
        using iterator_type = Iterator;
        static constexpr bool sep = _sep, end_line = _end_line, sep_line = _sep_line, debug = _debug, comment = _comment, flush = _flush;
        static constexpr KYOPRO_BASE_UINT decimal_precision = _decimal_precision;

    private:
        template<class, class = void>
        struct has_print: std::false_type {};
        template<class T>
        struct has_print<T, std::void_t<decltype(std::declval<T>().print(std::declval<Printer&>()))>>: std::true_type {};

    public:

        template<class, class = void>
        struct max_rank {
        static constexpr std::size_t value = 0;
        };
        template<class T>
        struct max_rank<T, std::enable_if_t<is_agg_v<T>>> {
        template<std::size_t... idx>
        static constexpr bool get_value_rank(std::index_sequence<idx...>) {
            return std::max({max_rank<aggregate_element_t<idx, T>>::value...});
        }
        static constexpr std::size_t value = get_value_rank(std::make_index_sequence<aggregate_size_v<T>>()) + 1;
        };
        template<class T>
        struct max_rank<T, std::enable_if_t<is_iterable_v<T>>> {
        static constexpr std::size_t value = max_rank<iterable_value_t<T>>::value + 1;
        };

        template<class T>
        static constexpr KYOPRO_BASE_UINT max_rank_v = max_rank<T>::value;

        Iterator itr;

        Printer() noexcept = default;
        Printer(Iterator itr) noexcept: itr(itr) {}

        void print_char(char c) {
        *itr = c;
        ++itr;
        }

        template<std::size_t rank>
        void print_sep() {
        if constexpr (sep) {
            if constexpr (debug) print_char(',');
            if constexpr (sep_line && rank >= 2) {
            print_char('\n');
            if constexpr (comment) {
                print_char('#');
                print_char(' ');
            }
            } else print_char(' ');
        }
        }

        void print(char a) {
        if constexpr (debug) print_char('\'');
        print_char(a);
        if constexpr (debug) print_char('\'');
        }
        void print(bool a) {
        print_char(static_cast<char>('0' + a));
        }
        void print(const char* a) {
        if constexpr (debug) print_char('"');
        for (; *a != '\0'; ++a) print_char(*a);
        if constexpr (debug) print_char('"');
        }
        template<std::size_t len>
        void print(const char (&a)[len]) {
        if constexpr (debug) print_char('"');
        for (auto i: a) print_char(i);
        if constexpr (debug) print_char('"');
        }
        void print(const std::string& a) {
        if constexpr (debug) print_char('"');
        for (auto i: a) print_char(i);
        if constexpr (debug) print_char('"');
        }
        template<std::size_t len>
        void print(const std::bitset<len>& a) {
        for (int i = len - 1; i >= 0; --i) print(a[i]);
        }
        template<class T, std::enable_if_t<std::is_arithmetic_v<T> && !has_print<T>::value>* = nullptr>
        void print(T a) {
        if constexpr (std::is_floating_point_v<T>) {
            if (a == std::numeric_limits<T>::infinity()) {
            print("inf");
            return;
            }
            if (a == -std::numeric_limits<T>::infinity()) {
            print("-inf");
            return;
            }
            if (std::isnan(a)) {
            print("nan");
            return;
            }
        }
        if constexpr (std::is_signed_v<T>) if (a < 0) {
            print_char('-');
            a = -a;
        }
        std::uint_fast64_t p = a;
        std::string s;
        do {
            s += '0' + p % 10;
            p /= 10;
        } while (p > 0);
        for (auto i = s.rbegin(); i != s.rend(); ++i) print_char(*i);
        if constexpr (std::is_integral_v<T>) return;
        print_char('.');
        a -= p;
        for (int i = 0; i < static_cast<int>(decimal_precision); ++i) {
            a *= 10;
            print_char('0' + static_cast<std::uint_fast64_t>(a) % 10);
        }
        }
        template<KYOPRO_BASE_UINT i = 0, class T, std::enable_if_t<is_agg_v<T> && !has_print<T>::value>* = nullptr>
        void print(const T& a) {
        if constexpr (debug && i == 0) print_char('{');
        if constexpr (aggregate_size_v<T> != 0) print(access<i>(a));
        if constexpr (i + 1 < aggregate_size_v<T>) {
            print_sep<max_rank_v<T>>();
            print<i + 1>(a);
        } else if constexpr (debug) print_char('}');
        }
        template<class T, std::enable_if_t<is_iterable_v<T> && !has_print<T>::value>* = nullptr>
        void print(const T& a) {
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
        template<class T, std::enable_if_t<has_print<T>::value>* = nullptr>
        void print(const T& a) {
        a.print(*this);
        }

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
        print(std::forward<Head>(head));
        operator ()<false>(std::forward<Args>(args)...);
        }
    };

    Printer<Writer<>::iterator, false, false, false> print(output.begin()), eprint(error.begin());
    Printer<Writer<>::iterator> println(output.begin()), eprintln(error.begin());
} // namespace kyopro