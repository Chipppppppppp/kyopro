---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/power.hpp
    title: math/power.hpp
  - icon: ':heavy_check_mark:'
    path: meta/settings.hpp
    title: meta/settings.hpp
  - icon: ':heavy_check_mark:'
    path: meta/trait.hpp
    title: meta/trait.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  - icon: ':warning:'
    path: all/all.hpp
    title: all/all.hpp
  - icon: ':heavy_check_mark:'
    path: system/all.hpp
    title: system/all.hpp
  - icon: ':warning:'
    path: template/all.hpp
    title: template/all.hpp
  - icon: ':warning:'
    path: template/macro.hpp
    title: template/macro.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/PrimeNumber.test.cpp
    title: verify/aoj/PrimeNumber.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/factorize.test.cpp
    title: verify/yosupo/factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/many_aplusb.test.cpp
    title: verify/yosupo/many_aplusb.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/point_add_range_sum.test.cpp
    title: verify/yosupo/point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/unionfind.test.cpp
    title: verify/yosupo/unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"system/in.hpp\"\n#include <unistd.h>\n#include <array>\n\
    #include <bitset>\n#include <cstddef>\n#include <cstdint>\n#include <cstdio>\n\
    #include <string>\n#include <tuple>\n#include <type_traits>\n#include <utility>\n\
    #line 3 \"meta/settings.hpp\"\n\n#ifndef KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT\
    \ std::int64_t\n#endif\n\n#ifndef KYOPRO_BASE_UINT\n#define KYOPRO_BASE_UINT std::uint64_t\n\
    #endif\n\n#ifndef KYOPRO_BASE_FLOAT\n#define KYOPRO_BASE_FLOAT double\n#endif\n\
    \n#ifndef KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD static_cast<KYOPRO_BASE_UINT>(998244353)\n\
    #endif\n\n#ifndef KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n\
    #endif\n\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 3 \"math/power.hpp\"\n\nnamespace kyopro {\n    inline constexpr\
    \ struct {\n        template<class T>\n        constexpr T operator ()(T a, KYOPRO_BASE_UINT\
    \ n, T init = 1) const noexcept {\n        while (n > 0) {\n            if (n\
    \ & 1) init *= a;\n            a *= a;\n            n >>= 1;\n        }\n    \
    \    return init;\n        }\n    } power;\n} // namespace kyopro\n#line 2 \"\
    meta/trait.hpp\"\n#include <iterator>\n#include <queue>\n#include <limits>\n#include\
    \ <stack>\n#line 9 \"meta/trait.hpp\"\n\ntemplate<>\nstruct std::is_integral<__int128_t>:\
    \ std::true_type {};\ntemplate<>\nstruct std::is_integral<__uint128_t>: std::true_type\
    \ {};\ntemplate<>\nstruct std::is_floating_point<__float128>: std::true_type {};\n\
    \nnamespace kyopro {\n    template<KYOPRO_BASE_UINT size>\n    struct int_least\
    \ {\n    private:\n        static constexpr auto get_type() noexcept {\n     \
    \   static_assert(size <= 128, \"Integer size is too large\");\n        if constexpr\
    \ (size <= 8) return std::int_least8_t();\n        else if constexpr (size <=\
    \ 16) return std::int_least16_t();\n        else if constexpr (size <= 32) return\
    \ std::int_least32_t();\n        else if constexpr (size <= 64) return std::int_least64_t();\n\
    \        else return __int128_t();\n        }\n\n    public:\n        using type\
    \ = decltype(get_type());\n    };\n\n    template<KYOPRO_BASE_UINT size>\n   \
    \ using int_least_t = typename int_least<size>::type;\n\n    template<KYOPRO_BASE_UINT\
    \ size>\n    struct uint_least {\n    private:\n        static constexpr auto\
    \ get_type() noexcept {\n        static_assert(size <= 128, \"Integer size is\
    \ too large\");\n        if constexpr (size <= 8) return std::uint_least8_t();\n\
    \        else if constexpr (size <= 16) return std::uint_least16_t();\n      \
    \  else if constexpr (size <= 32) return std::uint_least32_t();\n        else\
    \ if constexpr (size <= 64) return std::uint_least64_t();\n        else return\
    \ __uint128_t();\n        }\n\n    public:\n        using type = decltype(get_type());\n\
    \    };\n\n    template<KYOPRO_BASE_UINT size>\n    using uint_least_t = typename\
    \ uint_least<size>::type;\n\n    template<class, class = void>\n    struct is_iterator:\
    \ std::false_type {};\n    template<class T>\n    struct is_iterator<T, std::void_t<typename\
    \ std::iterator_traits<T>::iterator_category>>: std::true_type {};\n\n    template<class\
    \ T>\n    constexpr bool is_iterator_v = is_iterator<T>::value;\n\n    template<class,\
    \ class = void>\n    struct is_iterable: std::false_type {};\n    template<class\
    \ T>\n    struct is_iterable<T, std::void_t<decltype(std::begin(std::declval<std::add_lvalue_reference_t<T>>()),\
    \ std::end(std::declval<std::add_lvalue_reference_t<T>>()))>>: std::true_type\
    \ {};\n\n    template<class T>\n    constexpr bool is_iterable_v = is_iterable<T>::value;\n\
    \n    template<class T>\n    struct iterable_value {\n        using type = std::decay_t<decltype(*std::begin(std::declval<T>()))>;\n\
    \    };\n\n    template<class T>\n    using iterable_value_t = typename iterable_value<T>::type;\n\
    \n    namespace helper {\n        struct CastableToAny {\n        template<class\
    \ T>\n        operator T() const noexcept;\n        };\n\n        template<class\
    \ T, std::size_t... idx, std::void_t<decltype(T{((void)idx, CastableToAny{})...})>*\
    \ = nullptr>\n        constexpr bool is_aggregate_initializable(std::index_sequence<idx...>,\
    \ bool) noexcept {\n        return true;\n        }\n        template<class T,\
    \ std::size_t... idx>\n        constexpr bool is_aggregate_initializable(std::index_sequence<idx...>,\
    \ char) noexcept {\n        return false;\n        }\n\n        template<class\
    \ T, std::size_t n, std::enable_if_t<is_aggregate_initializable<T>(std::make_index_sequence<n>(),\
    \ false)>* = nullptr>\n        constexpr std::size_t aggregate_size_impl() {\n\
    \        return n;\n        }\n        template<class T, std::size_t n, std::enable_if_t<!is_aggregate_initializable<T>(std::make_index_sequence<n>(),\
    \ false)>* = nullptr>\n        constexpr std::size_t aggregate_size_impl() {\n\
    \        static_assert(n != 0, \"Aggregate is required\");\n        return aggregate_size_impl<T,\
    \ n - 1>();\n        }\n    } // namespace helper\n\n    template<class T, class\
    \ = void>\n    struct aggregate_size {\n        static_assert(std::is_aggregate_v<T>,\
    \ \"Aggregate is required\");\n        static constexpr std::size_t value = helper::aggregate_size_impl<T,\
    \ std::numeric_limits<unsigned char>::digits * sizeof(T)>();\n    };\n    template<class\
    \ T>\n    struct aggregate_size<T, std::void_t<decltype(std::tuple_size<T>::value)>>\
    \ {\n        static_assert(std::is_aggregate_v<T>, \"Aggregate is required\");\n\
    \        static constexpr std::size_t value = std::tuple_size_v<T>;\n    };\n\
    \    template<class T>\n    constexpr std::size_t aggregate_size_v = aggregate_size<T>::value;\n\
    \n    template<std::size_t idx, class T>\n    struct aggregate_element {\n   \
    \     static_assert(std::is_aggregate_v<T>);\n\n    private:\n        template<class\
    \ U>\n        struct Type {\n        using type = U;\n        };\n\n        template<class\
    \ U, std::enable_if_t<aggregate_size_v<std::decay_t<U>> == 1>* = nullptr>\n  \
    \      static constexpr auto get_type(U aggregate, char) noexcept {\n        auto&&\
    \ [a] = aggregate;\n        static_assert(idx < 1, \"Tuple index out of range\"\
    );\n        return Type<decltype(a)>();\n        }\n        template<class U,\
    \ std::enable_if_t<aggregate_size_v<std::decay_t<U>> == 2>* = nullptr>\n     \
    \   static constexpr auto get_type(U aggregate, char) noexcept {\n        auto&&\
    \ [a, b] = aggregate;\n        static_assert(idx < 2, \"Tuple index out of range\"\
    );\n        if constexpr (idx == 0) return Type<decltype(a)>();\n        else\
    \ return Type<decltype(b)>();\n        }\n        template<class U, std::enable_if_t<aggregate_size_v<std::decay_t<U>>\
    \ == 3>* = nullptr>\n        static constexpr auto get_type(U aggregate, char)\
    \ noexcept {\n        auto&& [a, b, c] = aggregate;\n        static_assert(idx\
    \ < 3, \"Tuple index out of range\");\n        if constexpr (idx == 0) return\
    \ Type<decltype(a)>();\n        else if constexpr (idx == 1) return Type<decltype(b)>();\n\
    \        else return Type<decltype(c)>();\n        }\n        template<class U,\
    \ std::enable_if_t<aggregate_size_v<std::decay_t<U>> == 4>* = nullptr>\n     \
    \   static constexpr auto access_impl(U aggregate, char) noexcept {\n        auto&&\
    \ [a, b, c, d] = aggregate;\n        static_assert(idx < 4, \"Tuple index out\
    \ of range\");\n        if constexpr (idx == 0) return Type<decltype(a)>();\n\
    \        else if constexpr (idx == 1) return Type<decltype(b)>();\n        else\
    \ if constexpr (idx == 2) return Type<decltype(c)>();\n        else return Type<decltype(d)>();\n\
    \        }\n        template<class U, std::enable_if_t<aggregate_size_v<std::decay_t<U>>\
    \ == 5>* = nullptr>\n        static constexpr auto get_type(U aggregate, char)\
    \ noexcept {\n        auto&& [a, b, c, d, e] = aggregate;\n        static_assert(idx\
    \ < 5, \"Tuple index out of range\");\n        if constexpr (idx == 0) return\
    \ Type<decltype(a)>();\n        else if constexpr (idx == 1) return Type<decltype(b)>();\n\
    \        else if constexpr (idx == 2) return Type<decltype(c)>();\n        else\
    \ if constexpr (idx == 3) return Type<decltype(d)>();\n        else return Type<decltype(e)>();\n\
    \        }\n        template<class U, std::enable_if_t<aggregate_size_v<std::decay_t<U>>\
    \ == 6>* = nullptr>\n        static constexpr auto get_type(U aggregate, char)\
    \ noexcept {\n        auto&& [a, b, c, d, e, f] = aggregate;\n        static_assert(idx\
    \ < 6, \"Tuple index out of range\");\n        if constexpr (idx == 0) return\
    \ Type<decltype(a)>();\n        else if constexpr (idx == 1) return Type<decltype(b)>();\n\
    \        else if constexpr (idx == 2) return Type<decltype(c)>();\n        else\
    \ if constexpr (idx == 3) return Type<decltype(d)>();\n        else if constexpr\
    \ (idx == 4) return Type<decltype(e)>();\n        else return Type<decltype(f)>();\n\
    \        }\n        template<class U, std::enable_if_t<aggregate_size_v<std::decay_t<U>>\
    \ == 7>* = nullptr>\n        static constexpr auto get_type(U aggregate, char)\
    \ noexcept {\n        auto&& [a, b, c, d, e, f, g] = aggregate;\n        static_assert(idx\
    \ < 7, \"Tuple index out of range\");\n        if constexpr (idx == 0) return\
    \ Type<decltype(a)>();\n        else if constexpr (idx == 1) return Type<decltype(b)>();\n\
    \        else if constexpr (idx == 2) return Type<decltype(c)>();\n        else\
    \ if constexpr (idx == 3) return Type<decltype(d)>();\n        else if constexpr\
    \ (idx == 4) return Type<decltype(e)>();\n        else if constexpr (idx == 5)\
    \ return Type<decltype(f)>();\n        else return Type<decltype(g)>();\n    \
    \    }\n        template<class U, std::enable_if_t<aggregate_size_v<std::decay_t<U>>\
    \ == 8>* = nullptr>\n        static constexpr auto get_type(U aggregate, char)\
    \ noexcept {\n        auto&& [a, b, c, d, e, f, g, h] = aggregate;\n        static_assert(idx\
    \ < 8, \"Tuple index out of range\");\n        if constexpr (idx == 0) return\
    \ Type<decltype(a)>();\n        else if constexpr (idx == 1) return Type<decltype(b)>();\n\
    \        else if constexpr (idx == 2) return Type<decltype(c)>();\n        else\
    \ if constexpr (idx == 3) return Type<decltype(d)>();\n        else if constexpr\
    \ (idx == 4) return Type<decltype(e)>();\n        else if constexpr (idx == 5)\
    \ return Type<decltype(f)>();\n        else if constexpr (idx == 6) return Type<decltype(g)>();\n\
    \        else return Type<decltype(h)>();\n        }\n        template<class U,\
    \ std::void_t<std::tuple_element_t<idx, U>>* = nullptr>\n        static constexpr\
    \ auto get_type(U, bool) noexcept {\n        return Type<std::tuple_element_t<idx,\
    \ U>>();\n        }\n\n    public:\n        using type = typename decltype(get_type(std::declval<T>(),\
    \ false))::type;\n    };\n\n    template<std::size_t idx, class T>\n    using\
    \ aggregate_element_t = typename aggregate_element<idx, T>::type;\n\n    template<class\
    \ T>\n    struct is_agg: std::conjunction<std::is_aggregate<T>, std::negation<is_iterable<T>>>\
    \ {};\n\n    template<class T>\n    inline constexpr bool is_agg_v = is_agg<T>::value;\n\
    } // namespace kyopro\n#line 15 \"system/in.hpp\"\n\nnamespace kyopro {\n    template<std::size_t\
    \ _buf_size = KYOPRO_BUFFER_SIZE>\n    struct Reader {\n        static constexpr\
    \ KYOPRO_BASE_UINT buf_size = _buf_size;\n\n    private:\n        int fd, idx;\n\
    \        std::array<char, buf_size> buffer;\n\n    public:\n        Reader() {\n\
    \        read(fd, buffer.begin(), buf_size);\n        }\n        Reader(int fd):\
    \ fd(fd), idx(0), buffer() {\n        read(fd, buffer.begin(), buf_size);\n  \
    \      }\n        Reader(FILE* fp): fd(fileno(fp)), idx(0), buffer() {\n     \
    \   read(fd, buffer.begin(), buf_size);\n        }\n\n        struct iterator\
    \ {\n        private:\n        Reader& reader;\n\n        public:\n        using\
    \ difference_type = void;\n        using value_type = void;\n        using pointer\
    \ = void;\n        using reference = void;\n        using iterator_category =\
    \ std::input_iterator_tag;\n\n        iterator() noexcept = default;\n       \
    \ iterator(Reader& reader) noexcept: reader(reader) {}\n\n        iterator& operator\
    \ ++() {\n            ++reader.idx;\n            if (reader.idx == buf_size) {\n\
    \            read(reader.fd, reader.buffer.begin(), buf_size);\n            reader.idx\
    \ = 0;\n            }\n            return *this;\n        }\n\n        iterator\
    \ operator ++(int) {\n            iterator before = *this;\n            operator\
    \ ++();\n            return before;\n        }\n\n        char& operator *() const\
    \ {\n            return reader.buffer[reader.idx];\n        }\n        };\n\n\
    \        iterator begin() noexcept {\n        return iterator(*this);\n      \
    \  }\n    };\n\n    Reader input(0);\n\n    template<class Iterator, std::size_t\
    \ _decimal_precision = KYOPRO_DECIMAL_PRECISION>\n    struct Scanner {\n     \
    \   using iterator_type = Iterator;\n        static constexpr KYOPRO_BASE_UINT\
    \ decimal_precision = _decimal_precision;\n\n    private:\n        template<class,\
    \ class = void>\n        struct has_scan: std::false_type {};\n        template<class\
    \ T>\n        struct has_scan<T, std::void_t<decltype(std::declval<T>().scan(std::declval<Scanner&>()))>>:\
    \ std::true_type {};\n\n    public:\n        Iterator itr;\n\n        Scanner()\
    \ noexcept = default;\n        Scanner(Iterator itr) noexcept: itr(itr) {}\n\n\
    \        void discard_space() {\n        while (('\\t' <= *itr && *itr <= '\\\
    r') || *itr == ' ') ++itr;\n        }\n\n        void scan(char& a) {\n      \
    \  discard_space();\n        a = *itr;\n        ++itr;\n        }\n        void\
    \ scan(bool& a) {\n        discard_space();\n        a = *itr != '0';\n      \
    \  }\n        void scan(std::string& a) {\n        discard_space();\n        while\
    \ ((*itr < '\\t' || '\\r' < *itr) && *itr != ' ') {\n            a += *itr;\n\
    \            ++itr;\n        }\n        }\n        template<std::size_t len>\n\
    \        void scan(std::bitset<len>& a) {\n        discard_space();\n        for\
    \ (int i = len - 1; i >= 0; ++i) {\n            a[i] = *itr != '0';\n        \
    \    ++itr;\n        }\n        }\n        template<class T, std::enable_if_t<std::is_arithmetic_v<T>\
    \ && !has_scan<T>::value>* = nullptr>\n        void scan(T& a) {\n        discard_space();\n\
    \        bool sgn = false;\n        if constexpr (!std::is_unsigned_v<T>) if (*itr\
    \ == '-') {\n            sgn = true;\n            ++itr;\n        }\n        a\
    \ = 0;\n        for (; '0' <= *itr && *itr <= '9'; ++itr) a = a * 10 + *itr -\
    \ '0';\n        if (*itr == '.') {\n            ++itr;\n            if constexpr\
    \ (std::is_floating_point_v<T>) {\n            constexpr std::uint_fast64_t power_decimal_precision\
    \ = power(10ULL, decimal_precision);\n            T d = 0;\n            std::uint_fast64_t\
    \ i = 1;\n            for (; '0' <= *itr && *itr <= '9' && i < power_decimal_precision;\
    \ i *= 10) {\n                d = d * 10 + *itr - '0';\n                ++itr;\n\
    \            }\n            a += d / i;\n            }\n            while ('0'\
    \ <= *itr && *itr <= '9') ++itr;\n        }\n        if constexpr (!std::is_unsigned_v<T>)\
    \ if (sgn) a = -a;\n        }\n        template<KYOPRO_BASE_UINT i = 0, class\
    \ T, std::enable_if_t<is_agg_v<T> && !has_scan<T>::value>* = nullptr>\n      \
    \  void scan(T& a) {\n        if constexpr (i < std::tuple_size_v<T>) {\n    \
    \        scan(std::get<i>(a));\n            scan<i + 1>(a);\n        }\n     \
    \   }\n        template<class T, std::enable_if_t<is_iterable_v<T> && !has_scan<T>::value>*\
    \ = nullptr>\n        void scan(T& a) {\n        for (auto&& i: a) scan(i);\n\
    \        }\n        template<class T, std::enable_if_t<has_scan<T>::value>* =\
    \ nullptr>\n        void scan(T& a) {\n        a.scan(*this);\n        }\n\n \
    \       void operator ()() {}\n        template<class Head, class... Args>\n \
    \       void operator ()(Head& head, Args&... args) {\n        scan(head);\n \
    \       operator ()(args...);\n        }\n    };\n\n    Scanner<Reader<>::iterator>\
    \ scan(input.begin());\n} // namespace kyopro\n"
  code: "#pragma once\n#include <unistd.h>\n#include <array>\n#include <bitset>\n\
    #include <cstddef>\n#include <cstdint>\n#include <cstdio>\n#include <string>\n\
    #include <tuple>\n#include <type_traits>\n#include <utility>\n#include \"../math/power.hpp\"\
    \n#include \"../meta/settings.hpp\"\n#include \"../meta/trait.hpp\"\n\nnamespace\
    \ kyopro {\n    template<std::size_t _buf_size = KYOPRO_BUFFER_SIZE>\n    struct\
    \ Reader {\n        static constexpr KYOPRO_BASE_UINT buf_size = _buf_size;\n\n\
    \    private:\n        int fd, idx;\n        std::array<char, buf_size> buffer;\n\
    \n    public:\n        Reader() {\n        read(fd, buffer.begin(), buf_size);\n\
    \        }\n        Reader(int fd): fd(fd), idx(0), buffer() {\n        read(fd,\
    \ buffer.begin(), buf_size);\n        }\n        Reader(FILE* fp): fd(fileno(fp)),\
    \ idx(0), buffer() {\n        read(fd, buffer.begin(), buf_size);\n        }\n\
    \n        struct iterator {\n        private:\n        Reader& reader;\n\n   \
    \     public:\n        using difference_type = void;\n        using value_type\
    \ = void;\n        using pointer = void;\n        using reference = void;\n  \
    \      using iterator_category = std::input_iterator_tag;\n\n        iterator()\
    \ noexcept = default;\n        iterator(Reader& reader) noexcept: reader(reader)\
    \ {}\n\n        iterator& operator ++() {\n            ++reader.idx;\n       \
    \     if (reader.idx == buf_size) {\n            read(reader.fd, reader.buffer.begin(),\
    \ buf_size);\n            reader.idx = 0;\n            }\n            return *this;\n\
    \        }\n\n        iterator operator ++(int) {\n            iterator before\
    \ = *this;\n            operator ++();\n            return before;\n        }\n\
    \n        char& operator *() const {\n            return reader.buffer[reader.idx];\n\
    \        }\n        };\n\n        iterator begin() noexcept {\n        return\
    \ iterator(*this);\n        }\n    };\n\n    Reader input(0);\n\n    template<class\
    \ Iterator, std::size_t _decimal_precision = KYOPRO_DECIMAL_PRECISION>\n    struct\
    \ Scanner {\n        using iterator_type = Iterator;\n        static constexpr\
    \ KYOPRO_BASE_UINT decimal_precision = _decimal_precision;\n\n    private:\n \
    \       template<class, class = void>\n        struct has_scan: std::false_type\
    \ {};\n        template<class T>\n        struct has_scan<T, std::void_t<decltype(std::declval<T>().scan(std::declval<Scanner&>()))>>:\
    \ std::true_type {};\n\n    public:\n        Iterator itr;\n\n        Scanner()\
    \ noexcept = default;\n        Scanner(Iterator itr) noexcept: itr(itr) {}\n\n\
    \        void discard_space() {\n        while (('\\t' <= *itr && *itr <= '\\\
    r') || *itr == ' ') ++itr;\n        }\n\n        void scan(char& a) {\n      \
    \  discard_space();\n        a = *itr;\n        ++itr;\n        }\n        void\
    \ scan(bool& a) {\n        discard_space();\n        a = *itr != '0';\n      \
    \  }\n        void scan(std::string& a) {\n        discard_space();\n        while\
    \ ((*itr < '\\t' || '\\r' < *itr) && *itr != ' ') {\n            a += *itr;\n\
    \            ++itr;\n        }\n        }\n        template<std::size_t len>\n\
    \        void scan(std::bitset<len>& a) {\n        discard_space();\n        for\
    \ (int i = len - 1; i >= 0; ++i) {\n            a[i] = *itr != '0';\n        \
    \    ++itr;\n        }\n        }\n        template<class T, std::enable_if_t<std::is_arithmetic_v<T>\
    \ && !has_scan<T>::value>* = nullptr>\n        void scan(T& a) {\n        discard_space();\n\
    \        bool sgn = false;\n        if constexpr (!std::is_unsigned_v<T>) if (*itr\
    \ == '-') {\n            sgn = true;\n            ++itr;\n        }\n        a\
    \ = 0;\n        for (; '0' <= *itr && *itr <= '9'; ++itr) a = a * 10 + *itr -\
    \ '0';\n        if (*itr == '.') {\n            ++itr;\n            if constexpr\
    \ (std::is_floating_point_v<T>) {\n            constexpr std::uint_fast64_t power_decimal_precision\
    \ = power(10ULL, decimal_precision);\n            T d = 0;\n            std::uint_fast64_t\
    \ i = 1;\n            for (; '0' <= *itr && *itr <= '9' && i < power_decimal_precision;\
    \ i *= 10) {\n                d = d * 10 + *itr - '0';\n                ++itr;\n\
    \            }\n            a += d / i;\n            }\n            while ('0'\
    \ <= *itr && *itr <= '9') ++itr;\n        }\n        if constexpr (!std::is_unsigned_v<T>)\
    \ if (sgn) a = -a;\n        }\n        template<KYOPRO_BASE_UINT i = 0, class\
    \ T, std::enable_if_t<is_agg_v<T> && !has_scan<T>::value>* = nullptr>\n      \
    \  void scan(T& a) {\n        if constexpr (i < std::tuple_size_v<T>) {\n    \
    \        scan(std::get<i>(a));\n            scan<i + 1>(a);\n        }\n     \
    \   }\n        template<class T, std::enable_if_t<is_iterable_v<T> && !has_scan<T>::value>*\
    \ = nullptr>\n        void scan(T& a) {\n        for (auto&& i: a) scan(i);\n\
    \        }\n        template<class T, std::enable_if_t<has_scan<T>::value>* =\
    \ nullptr>\n        void scan(T& a) {\n        a.scan(*this);\n        }\n\n \
    \       void operator ()() {}\n        template<class Head, class... Args>\n \
    \       void operator ()(Head& head, Args&... args) {\n        scan(head);\n \
    \       operator ()(args...);\n        }\n    };\n\n    Scanner<Reader<>::iterator>\
    \ scan(input.begin());\n} // namespace kyopro"
  dependsOn:
  - math/power.hpp
  - meta/settings.hpp
  - meta/trait.hpp
  isVerificationFile: false
  path: system/in.hpp
  requiredBy:
  - all/all.hpp
  - system/all.hpp
  - all.hpp
  - template/macro.hpp
  - template/all.hpp
  timestamp: '2022-07-25 23:25:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/PrimeNumber.test.cpp
  - verify/yosupo/point_add_range_sum.test.cpp
  - verify/yosupo/factorize.test.cpp
  - verify/yosupo/unionfind.test.cpp
  - verify/yosupo/many_aplusb.test.cpp
documentation_of: system/in.hpp
layout: document
redirect_from:
- /library/system/in.hpp
- /library/system/in.hpp.html
title: system/in.hpp
---
