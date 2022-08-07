---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: algorithm/Hash.hpp
    title: algorithm/Hash.hpp
  - icon: ':x:'
    path: algorithm/bit.hpp
    title: algorithm/bit.hpp
  - icon: ':x:'
    path: math/DynamicModInt.hpp
    title: math/DynamicModInt.hpp
  - icon: ':x:'
    path: math/Montgomery.hpp
    title: math/Montgomery.hpp
  - icon: ':x:'
    path: math/factorize.hpp
    title: math/factorize.hpp
  - icon: ':x:'
    path: math/is_prime.hpp
    title: math/is_prime.hpp
  - icon: ':question:'
    path: math/power.hpp
    title: math/power.hpp
  - icon: ':question:'
    path: meta/aggregate.hpp
    title: meta/aggregate.hpp
  - icon: ':x:'
    path: meta/constant.hpp
    title: meta/constant.hpp
  - icon: ':question:'
    path: meta/settings.hpp
    title: meta/settings.hpp
  - icon: ':question:'
    path: meta/trait.hpp
    title: meta/trait.hpp
  - icon: ':question:'
    path: system/all.hpp
    title: system/all.hpp
  - icon: ':question:'
    path: system/in.hpp
    title: system/in.hpp
  - icon: ':question:'
    path: system/out.hpp
    title: system/out.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/factorize
    links:
    - https://judge.yosupo.jp/problem/factorize
  bundledCode: "#line 1 \"verify/yosupo/factorize.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\
    \n#line 2 \"math/factorize.hpp\"\n#include <algorithm>\n#include <cstddef>\n#include\
    \ <cstdint>\n#include <numeric>\n#include <random>\n#include <type_traits>\n#line\
    \ 2 \"algorithm/bit.hpp\"\n#include <limits>\n#line 3 \"meta/settings.hpp\"\n\n\
    #ifndef KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT std::int64_t\n#endif\n\n#ifndef\
    \ KYOPRO_BASE_UINT\n#define KYOPRO_BASE_UINT std::uint64_t\n#endif\n\n#ifndef\
    \ KYOPRO_BASE_FLOAT\n#define KYOPRO_BASE_FLOAT double\n#endif\n\n#ifndef KYOPRO_DEFAULT_MOD\n\
    #define KYOPRO_DEFAULT_MOD static_cast<KYOPRO_BASE_UINT>(998244353)\n#endif\n\n\
    #ifndef KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n\
    #endif\n\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 5 \"algorithm/bit.hpp\"\n\nnamespace kyopro {\n    inline constexpr\
    \ struct {\n        template<class T>\n        constexpr KYOPRO_BASE_INT operator\
    \ ()(T x) const noexcept {\n            constexpr auto digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;\n\
    \            static_assert(digits <= std::numeric_limits<unsigned long long>::digits,\
    \ \"Integer size is too large\");\n            if constexpr (digits <= std::numeric_limits<unsigned\
    \ int>::digits) return __builtin_popcount(x);\n            else if constexpr (digits\
    \ <= std::numeric_limits<unsigned long>::digits) return __builtin_popcountl(x);\n\
    \            else return __builtin_popcountll(x);\n        }\n    } pop_count;\n\
    \n    inline constexpr struct {\n        template<class T>\n        constexpr\
    \ KYOPRO_BASE_INT operator ()(T x) const noexcept {\n            constexpr auto\
    \ digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;\n           \
    \ static_assert(digits <= std::numeric_limits<unsigned long long>::digits, \"\
    Integer size is too large\");\n            if (x == 0) return 0;\n           \
    \ if constexpr (digits <= std::numeric_limits<unsigned int>::digits) return __builtin_clz(x)\
    \ + digits - std::numeric_limits<unsigned int>::digits;\n            else if constexpr\
    \ (digits <= std::numeric_limits<unsigned long>::digits) return __builtin_clzl(x)\
    \ + digits - std::numeric_limits<unsigned long>::digits;\n            else return\
    \ __builtin_clzll(x) + digits - std::numeric_limits<unsigned long long>::digits;\n\
    \        }\n    } leading_zero;\n\n    inline constexpr struct {\n        template<class\
    \ T>\n        constexpr KYOPRO_BASE_INT operator ()(T x) const noexcept {\n  \
    \          constexpr auto digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;\n\
    \            static_assert(digits <= std::numeric_limits<unsigned long long>::digits,\
    \ \"Integer size is too large\");\n            if constexpr (digits <= std::numeric_limits<unsigned\
    \ int>::digits) return __builtin_ctz(x);\n            else if constexpr (digits\
    \ <= std::numeric_limits<unsigned long>::digits) return __builtin_ctzl(x);\n \
    \           else return __builtin_ctzll(x);\n        }\n    } trailing_zero;\n\
    \n    inline constexpr struct {\n        template<class T>\n        constexpr\
    \ KYOPRO_BASE_INT operator ()(T x) const noexcept {\n            constexpr auto\
    \ digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;\n           \
    \ static_assert(digits <= std::numeric_limits<unsigned long long>::digits, \"\
    Integer size is too large\");\n            if (x == 0) return 0;\n           \
    \ if constexpr (digits <= std::numeric_limits<unsigned int>::digits) return std::numeric_limits<unsigned\
    \ int>::digits - __builtin_clz(x);\n            else if constexpr (digits <= std::numeric_limits<unsigned\
    \ long>::digits) return std::numeric_limits<unsigned long>::digits - __builtin_clzl(x);\n\
    \            else return std::numeric_limits<unsigned long long>::digits - __builtin_clzll(x);\n\
    \        }\n    } bit_len;\n\n    inline constexpr struct {\n        template<class\
    \ T>\n        constexpr KYOPRO_BASE_INT operator ()(T x) const noexcept {\n  \
    \          return bit_len(x >> static_cast<T>(1));\n        }\n    } floor_bit;\n\
    \n    inline constexpr struct {\n        template<class T>\n        constexpr\
    \ KYOPRO_BASE_INT operator ()(T x) const noexcept {\n            if (x == 0) return\
    \ 0;\n            return bit_len(x - static_cast<T>(1));\n        }\n    } ceil_bit;\n\
    } // namespace kyopro\n#line 2 \"math/DynamicModInt.hpp\"\n#include <cassert>\n\
    #line 4 \"algorithm/Hash.hpp\"\n#include <functional>\n#include <tuple>\n#line\
    \ 7 \"algorithm/Hash.hpp\"\n#include <utility>\n#line 3 \"meta/trait.hpp\"\n#include\
    \ <iterator>\n#include <queue>\n#line 6 \"meta/trait.hpp\"\n#include <stack>\n\
    #line 9 \"meta/trait.hpp\"\n\ntemplate<>\nstruct std::is_integral<__int128_t>:\
    \ std::true_type {};\ntemplate<>\nstruct std::is_integral<__uint128_t>: std::true_type\
    \ {};\ntemplate<>\nstruct std::is_floating_point<__float128>: std::true_type {};\n\
    \nnamespace kyopro {\n    template<std::size_t size>\n    struct int_least {\n\
    \    private:\n        static constexpr auto get_type() noexcept {\n         \
    \   static_assert(size <= 128, \"Integer size is too large\");\n            if\
    \ constexpr (size <= 8) return std::int_least8_t{};\n            else if constexpr\
    \ (size <= 16) return std::int_least16_t{};\n            else if constexpr (size\
    \ <= 32) return std::int_least32_t{};\n            else if constexpr (size <=\
    \ 64) return std::int_least64_t{};\n            else return __int128_t{};\n  \
    \      }\n\n    public:\n        using type = decltype(get_type());\n    };\n\n\
    \    template<std::size_t size>\n    using int_least_t = typename int_least<size>::type;\n\
    \n    template<std::size_t size>\n    struct uint_least {\n    private:\n    \
    \    static constexpr auto get_type() noexcept {\n            static_assert(size\
    \ <= 128, \"Integer size is too large\");\n            if constexpr (size <= 8)\
    \ return std::uint_least8_t{};\n            else if constexpr (size <= 16) return\
    \ std::uint_least16_t{};\n            else if constexpr (size <= 32) return std::uint_least32_t{};\n\
    \            else if constexpr (size <= 64) return std::uint_least64_t{};\n  \
    \          else return __uint128_t{};\n        }\n\n    public:\n        using\
    \ type = decltype(get_type());\n    };\n\n    template<std::size_t size>\n   \
    \ using uint_least_t = typename uint_least<size>::type;\n\n    template<class,\
    \ class = void>\n    struct is_iterator: std::false_type {};\n    template<class\
    \ T>\n    struct is_iterator<T, std::void_t<typename std::iterator_traits<T>::iterator_category>>:\
    \ std::true_type {};\n\n    template<class T>\n    constexpr bool is_iterator_v\
    \ = is_iterator<T>::value;\n\n    template<class, class = void>\n    struct is_range:\
    \ std::false_type {};\n    template<class T>\n    struct is_range<T, std::void_t<decltype(std::begin(std::declval<std::add_lvalue_reference_t<T>>()),\
    \ std::end(std::declval<std::add_lvalue_reference_t<T>>()))>>: std::true_type\
    \ {};\n\n    template<class T>\n    constexpr bool is_range_v = is_range<T>::value;\n\
    \n    template<class T>\n    struct range_iterator {\n        using type = std::decay_t<decltype(std::begin(std::declval<T>()))>;\n\
    \    };\n\n    template<class T>\n    using range_iterator_t = typename range_iterator<T>::type;\n\
    \n    template<class T>\n    struct range_const_iterator {\n        using type\
    \ = std::decay_t<decltype(std::cbegin(std::declval<T>()))>;\n    };\n\n    template<class\
    \ T>\n    using range_const_iterator_t = typename range_iterator<T>::type;\n\n\
    \    template<class T>\n    struct range_value {\n        using type = std::decay_t<decltype(*std::begin(std::declval<T>()))>;\n\
    \    };\n\n    template<class T>\n    using range_value_t = typename range_value<T>::type;\n\
    \n    namespace helper {\n        struct CastableToAny {\n            template<class\
    \ T>\n            operator T() const noexcept;\n        };\n\n        template<class\
    \ T, std::size_t... idx, std::void_t<decltype(T{((void)idx, CastableToAny{})...})>*\
    \ = nullptr>\n        constexpr bool is_aggregate_initializable(std::index_sequence<idx...>,\
    \ bool) noexcept {\n            return true;\n        }\n        template<class\
    \ T, std::size_t... idx>\n        constexpr bool is_aggregate_initializable(std::index_sequence<idx...>,\
    \ char) noexcept {\n            return false;\n        }\n\n        template<class\
    \ T, std::size_t n, std::enable_if_t<is_aggregate_initializable<T>(std::make_index_sequence<n>(),\
    \ false)>* = nullptr>\n        constexpr std::size_t aggregate_size_impl() {\n\
    \            return n;\n        }\n        template<class T, std::size_t n, std::enable_if_t<!is_aggregate_initializable<T>(std::make_index_sequence<n>(),\
    \ false)>* = nullptr>\n        constexpr std::size_t aggregate_size_impl() {\n\
    \            static_assert(n != 0, \"Aggregate is required\");\n            return\
    \ aggregate_size_impl<T, n - 1>();\n        }\n    } // namespace helper\n\n \
    \   template<class T, class = void>\n    struct aggregate_size {\n        static_assert(std::is_aggregate_v<T>,\
    \ \"Aggregate is required\");\n        static constexpr std::size_t value = helper::aggregate_size_impl<T,\
    \ std::numeric_limits<unsigned char>::digits * sizeof(T)>();\n    };\n    template<class\
    \ T>\n    struct aggregate_size<T, std::void_t<decltype(std::tuple_size<T>::value)>>\
    \ {\n        static_assert(std::is_aggregate_v<T>, \"Aggregate is required\");\n\
    \        static constexpr std::size_t value = std::tuple_size_v<T>;\n    };\n\
    \    template<class T>\n    constexpr std::size_t aggregate_size_v = aggregate_size<T>::value;\n\
    \n    template<std::size_t idx, class T>\n    struct aggregate_element {\n   \
    \     static_assert(std::is_aggregate_v<T>);\n\n    private:\n        template<class\
    \ U>\n        struct Type {\n            using type = U;\n        };\n\n     \
    \   template<class U, std::enable_if_t<aggregate_size_v<std::decay_t<U>> == 1>*\
    \ = nullptr>\n        static constexpr auto get_type(U aggregate, char) noexcept\
    \ {\n            auto&& [a] = aggregate;\n            static_assert(idx < 1, \"\
    Tuple index out of range\");\n            return Type<decltype(a)>{};\n      \
    \  }\n        template<class U, std::enable_if_t<aggregate_size_v<std::decay_t<U>>\
    \ == 2>* = nullptr>\n        static constexpr auto get_type(U aggregate, char)\
    \ noexcept {\n            auto&& [a, b] = aggregate;\n            static_assert(idx\
    \ < 2, \"Tuple index out of range\");\n            if constexpr (idx == 0) return\
    \ Type<decltype(a)>{};\n            else return Type<decltype(b)>{};\n       \
    \ }\n        template<class U, std::enable_if_t<aggregate_size_v<std::decay_t<U>>\
    \ == 3>* = nullptr>\n        static constexpr auto get_type(U aggregate, char)\
    \ noexcept {\n            auto&& [a, b, c] = aggregate;\n            static_assert(idx\
    \ < 3, \"Tuple index out of range\");\n            if constexpr (idx == 0) return\
    \ Type<decltype(a)>{};\n            else if constexpr (idx == 1) return Type<decltype(b)>{};\n\
    \            else return Type<decltype(c)>{};\n        }\n        template<class\
    \ U, std::enable_if_t<aggregate_size_v<std::decay_t<U>> == 4>* = nullptr>\n  \
    \      static constexpr auto access_impl(U aggregate, char) noexcept {\n     \
    \       auto&& [a, b, c, d] = aggregate;\n            static_assert(idx < 4, \"\
    Tuple index out of range\");\n            if constexpr (idx == 0) return Type<decltype(a)>{};\n\
    \            else if constexpr (idx == 1) return Type<decltype(b)>{};\n      \
    \      else if constexpr (idx == 2) return Type<decltype(c)>{};\n            else\
    \ return Type<decltype(d)>{};\n        }\n        template<class U, std::enable_if_t<aggregate_size_v<std::decay_t<U>>\
    \ == 5>* = nullptr>\n        static constexpr auto get_type(U aggregate, char)\
    \ noexcept {\n            auto&& [a, b, c, d, e] = aggregate;\n            static_assert(idx\
    \ < 5, \"Tuple index out of range\");\n            if constexpr (idx == 0) return\
    \ Type<decltype(a)>{};\n            else if constexpr (idx == 1) return Type<decltype(b)>{};\n\
    \            else if constexpr (idx == 2) return Type<decltype(c)>{};\n      \
    \      else if constexpr (idx == 3) return Type<decltype(d)>{};\n            else\
    \ return Type<decltype(e)>{};\n        }\n        template<class U, std::enable_if_t<aggregate_size_v<std::decay_t<U>>\
    \ == 6>* = nullptr>\n        static constexpr auto get_type(U aggregate, char)\
    \ noexcept {\n            auto&& [a, b, c, d, e, f] = aggregate;\n           \
    \ static_assert(idx < 6, \"Tuple index out of range\");\n            if constexpr\
    \ (idx == 0) return Type<decltype(a)>{};\n            else if constexpr (idx ==\
    \ 1) return Type<decltype(b)>{};\n            else if constexpr (idx == 2) return\
    \ Type<decltype(c)>{};\n            else if constexpr (idx == 3) return Type<decltype(d)>{};\n\
    \            else if constexpr (idx == 4) return Type<decltype(e)>{};\n      \
    \      else return Type<decltype(f)>{};\n        }\n        template<class U,\
    \ std::enable_if_t<aggregate_size_v<std::decay_t<U>> == 7>* = nullptr>\n     \
    \   static constexpr auto get_type(U aggregate, char) noexcept {\n           \
    \ auto&& [a, b, c, d, e, f, g] = aggregate;\n            static_assert(idx < 7,\
    \ \"Tuple index out of range\");\n            if constexpr (idx == 0) return Type<decltype(a)>{};\n\
    \            else if constexpr (idx == 1) return Type<decltype(b)>{};\n      \
    \      else if constexpr (idx == 2) return Type<decltype(c)>{};\n            else\
    \ if constexpr (idx == 3) return Type<decltype(d)>{};\n            else if constexpr\
    \ (idx == 4) return Type<decltype(e)>{};\n            else if constexpr (idx ==\
    \ 5) return Type<decltype(f)>{};\n            else return Type<decltype(g)>{};\n\
    \        }\n        template<class U, std::enable_if_t<aggregate_size_v<std::decay_t<U>>\
    \ == 8>* = nullptr>\n        static constexpr auto get_type(U aggregate, char)\
    \ noexcept {\n            auto&& [a, b, c, d, e, f, g, h] = aggregate;\n     \
    \       static_assert(idx < 8, \"Tuple index out of range\");\n            if\
    \ constexpr (idx == 0) return Type<decltype(a)>{};\n            else if constexpr\
    \ (idx == 1) return Type<decltype(b)>{};\n            else if constexpr (idx ==\
    \ 2) return Type<decltype(c)>{};\n            else if constexpr (idx == 3) return\
    \ Type<decltype(d)>{};\n            else if constexpr (idx == 4) return Type<decltype(e)>{};\n\
    \            else if constexpr (idx == 5) return Type<decltype(f)>{};\n      \
    \      else if constexpr (idx == 6) return Type<decltype(g)>{};\n            else\
    \ return Type<decltype(h)>{};\n        }\n        template<class U, std::void_t<std::tuple_element_t<idx,\
    \ U>>* = nullptr>\n        static constexpr auto get_type(U, bool) noexcept {\n\
    \            return Type<std::tuple_element_t<idx, U>>{};\n        }\n\n    public:\n\
    \        using type = typename decltype(get_type(std::declval<T>(), false))::type;\n\
    \    };\n\n    template<std::size_t idx, class T>\n    using aggregate_element_t\
    \ = typename aggregate_element<idx, T>::type;\n\n    template<class T>\n    struct\
    \ is_agg: std::conjunction<std::is_aggregate<T>, std::negation<is_range<T>>> {};\n\
    \n    template<class T>\n    inline constexpr bool is_agg_v = is_agg<T>::value;\n\
    } // namespace kyopro\n#line 7 \"meta/aggregate.hpp\"\n\nnamespace kyopro {\n\
    \    namespace helper {\n        #define DEFINE_ACCESS(n, ...)               \
    \                                                            \\\n        template<std::size_t\
    \ idx, class T, std::enable_if_t<aggregate_size_v<std::decay_t<T>> == n>* = nullptr>\
    \ \\\n            constexpr decltype(auto) access_impl(T&& aggregate, char) noexcept\
    \ {                                \\\n            auto&& [__VA_ARGS__] = std::forward<T>(aggregate);\
    \                                                  \\\n            return std::get<idx>(std::forward_as_tuple(__VA_ARGS__));\
    \                                           \\\n        }\n\n        DEFINE_ACCESS(1,\
    \ a)\n        DEFINE_ACCESS(2, a, b)\n        DEFINE_ACCESS(3, a, b, c)\n    \
    \    DEFINE_ACCESS(4, a, b, c, d)\n        DEFINE_ACCESS(5, a, b, c, d, e)\n \
    \       DEFINE_ACCESS(6, a, b, c, d, e, f)\n        DEFINE_ACCESS(7, a, b, c,\
    \ d, e, f, g)\n        DEFINE_ACCESS(8, a, b, c, d, e, f, g, h)\n\n        template<std::size_t\
    \ idx, class T, std::void_t<decltype(std::get<idx>(std::declval<std::decay_t<T>>()))>*\
    \ = nullptr>\n        constexpr decltype(auto) access_impl(T&& aggregate, bool)\
    \ noexcept {\n            return std::get<idx>(std::forward<T>(aggregate));\n\
    \        }\n\n        #undef DEFINE_ACCESS\n    } // namespace helper\n\n    template<std::size_t\
    \ idx, class T>\n    constexpr decltype(auto) access(T&& aggregate) noexcept {\n\
    \        return helper::access_impl<idx>(std::forward<T>(aggregate), false);\n\
    \    }\n} // namespace kyopro\n#line 11 \"algorithm/Hash.hpp\"\n\nnamespace kyopro\
    \ {\n    template<class, class = void>\n    struct Hash;\n\n    template<class\
    \ T>\n    struct Hash<T, std::enable_if_t<std::is_scalar_v<T>>>: std::hash<T>\
    \ {\n        using value_type = T;\n\n        constexpr std::size_t operator ()(T\
    \ a) const noexcept {\n            return std::hash<T>::operator ()(a);\n    \
    \    }\n    };\n\n    template<class T>\n    struct Hash<T, std::enable_if_t<is_agg_v<T>>>\
    \ {\n        using value_type = T;\n\n        template<std::size_t i = 0>\n  \
    \      constexpr std::size_t operator ()(const T& a) const noexcept {\n      \
    \      if constexpr (i == aggregate_size_v<T>) return aggregate_size_v<T>;\n \
    \           else {\n                std::uint_fast64_t seed = operator()<i + 1>(a);\n\
    \                return seed ^ (Hash<aggregate_element_t<i, T>>()(access<i>(a))\
    \ + 0x9e3779b97f4a7c15LU + (seed << 12) + (seed >> 4));\n            }\n     \
    \   }\n    };\n\n    template<class T>\n    struct Hash<T, std::enable_if_t<is_range_v<T>>>:\
    \ Hash<range_value_t<T>> {\n        using value_type = T;\n\n        constexpr\
    \ std::size_t operator ()(const T& a) const {\n            std::uint_fast64_t\
    \ seed = a.size();\n            for (auto&& i: a) seed ^= Hash<range_value_t<T>>(i)\
    \ + 0x9e3779b97f4a7c15LU + (seed << 12) + (seed >> 4);\n            return seed;\n\
    \        }\n    };\n} // namespace kyopro\n#line 2 \"meta/constant.hpp\"\n#include\
    \ <array>\n#line 3 \"math/power.hpp\"\n\nnamespace kyopro {\n    inline constexpr\
    \ struct {\n        template<class T>\n        constexpr T operator ()(T a, std::uint_fast64_t\
    \ n, T init = 1) const noexcept {\n            while (n > 0) {\n             \
    \   if (n & 1) init *= a;\n                a *= a;\n                n >>= 1;\n\
    \            }\n            return init;\n        }\n    } power;\n} // namespace\
    \ kyopro\n#line 7 \"meta/constant.hpp\"\n\nnamespace kyopro {\n    template<class\
    \ T>\n    inline constexpr T MOD = KYOPRO_DEFAULT_MOD;\n    inline constexpr KYOPRO_BASE_INT\
    \ mod = MOD<KYOPRO_BASE_INT>;\n\n    template<class T>\n    inline constexpr T\
    \ INF = std::numeric_limits<T>::max() / KYOPRO_INF_DIV;\n    inline constexpr\
    \ KYOPRO_BASE_INT inf = INF<KYOPRO_BASE_INT>;\n\n    template<class T, KYOPRO_BASE_UINT\
    \ decimal_precision = KYOPRO_DECIMAL_PRECISION>\n    inline constexpr KYOPRO_BASE_FLOAT\
    \ EPS = static_cast<T>(1) / power(10ULL, decimal_precision);\n    inline constexpr\
    \ KYOPRO_BASE_FLOAT eps = EPS<KYOPRO_BASE_FLOAT>;\n\n    template<class T>\n \
    \   inline constexpr T PI = 3.14159265358979323846;\n    inline constexpr KYOPRO_BASE_FLOAT\
    \ pi = PI<KYOPRO_BASE_FLOAT>;\n} // namespace kyopro\n#line 6 \"math/Montgomery.hpp\"\
    \n\nnamespace kyopro {\n    template<class T>\n    struct Montgomery {\n     \
    \   static_assert(std::is_unsigned_v<T>, \"Unsigned integer is required\");\n\
    \        using value_type = T;\n\n        T mod;\n\n    private:\n        using\
    \ larger_type = uint_least_t<std::numeric_limits<T>::digits * 2>;\n\n        T\
    \ r, n2;\n\n    public:\n        constexpr void set_mod(T _mod) noexcept {\n \
    \           mod = _mod;\n            n2 = -static_cast<larger_type>(mod) % mod;\n\
    \            T t = 0;\n            r = 0;\n            for (int i = 0; i < std::numeric_limits<T>::digits;\
    \ ++i) {\n                if (!(t & 1)) {\n                t += mod;\n       \
    \         r += static_cast<T>(1) << static_cast<T>(i);\n                }\n  \
    \              t >>= 1;\n            }\n        }\n\n        constexpr KYOPRO_BASE_INT\
    \ get_mod() const noexcept {\n            return mod;\n        }\n\n        Montgomery()\
    \ noexcept = default;\n        Montgomery(T mod) noexcept {\n            set_mod(mod);\n\
    \        }\n\n        constexpr T transform(T x) const noexcept {\n          \
    \  return reduce(static_cast<larger_type>(x) * n2);\n        }\n\n        constexpr\
    \ T inverse_transform(T x) const noexcept {\n            T y = reduce(x);\n  \
    \          return y >= mod ? y - mod : y;\n        }\n\n        constexpr T reduce(larger_type\
    \ x) const noexcept {\n            return (x + static_cast<larger_type>(static_cast<T>(x)\
    \ * r) * mod) >> std::numeric_limits<T>::digits;\n        }\n    };\n} // namespace\
    \ kyopro\n#line 10 \"math/DynamicModInt.hpp\"\n\nnamespace kyopro {\n    template<class\
    \ T, std::size_t kind = 0>\n    struct DynamicModInt {\n        static_assert(std::is_unsigned_v<T>,\
    \ \"T must be unsigned integer\");\n        using value_type = T;\n\n    private:\n\
    \        using larger_type = uint_least_t<std::numeric_limits<T>::digits * 2>;\n\
    \n        inline static Montgomery<T> montgomery;\n\n    public:\n        T value;\n\
    \n        static constexpr KYOPRO_BASE_INT get_kind() noexcept {\n           \
    \ return kind;\n        }\n\n        static void set_mod(T mod) noexcept {\n \
    \           montgomery.set_mod(mod);\n        }\n\n        static KYOPRO_BASE_INT\
    \ get_mod() noexcept {\n            return montgomery.mod;\n        }\n\n    \
    \    KYOPRO_BASE_INT get_val() noexcept {\n            return montgomery.inverse_transform(value);\n\
    \        }\n\n        DynamicModInt() noexcept = default;\n        DynamicModInt(T\
    \ value) noexcept: value(montgomery.transform(value % montgomery.mod + montgomery.mod))\
    \ {}\n\n        template<class U>\n        explicit operator U() const noexcept\
    \ {\n            return montgomery.inverse_transform(value);\n        }\n\n  \
    \      static DynamicModInt raw(T value) noexcept {\n            DynamicModInt\
    \ res;\n            res.value = montgomery.transform(value);\n            return\
    \ res;\n        }\n\n        DynamicModInt power(std::uint_fast64_t n) const noexcept\
    \ {\n            DynamicModInt res = 1, a = *this;\n            while (n > 0)\
    \ {\n                if (n & 1) res = res * a;\n                a = a * a;\n \
    \               n >>= 1;\n            }\n            return res;\n        }\n\n\
    \        DynamicModInt inverse() const noexcept {\n            return power(montgomery.mod\
    \ - 2);\n        }\n\n        DynamicModInt operator +() const noexcept {\n  \
    \          return *this;\n        }\n\n        DynamicModInt operator -() const\
    \ noexcept {\n            return value == 0 ? 0 : montgomery.mod - value;\n  \
    \      }\n\n        DynamicModInt& operator ++() noexcept {\n            *this\
    \ += DynamicModInt::raw(1);\n            return *this;\n        }\n\n        DynamicModInt\
    \ operator ++(int) noexcept {\n            DynamicModInt before = *this;\n   \
    \         ++*this;\n            return before;\n        }\n\n        DynamicModInt&\
    \ operator --() noexcept {\n            *this -= DynamicModInt::raw(1);\n    \
    \        return *this;\n        }\n\n        DynamicModInt operator --(int) noexcept\
    \ {\n            DynamicModInt before = *this;\n            --*this;\n       \
    \     return before;\n        }\n\n        DynamicModInt& operator +=(DynamicModInt\
    \ rhs) noexcept {\n            if ((value += rhs.value - (montgomery.mod << 1))\
    \ > std::numeric_limits<std::make_signed_t<T>>::max()) value += montgomery.mod\
    \ << 1;\n            return *this;\n        }\n\n        DynamicModInt& operator\
    \ -=(DynamicModInt rhs) noexcept {\n            if ((value -= rhs.value) > std::numeric_limits<std::make_signed_t<T>>::max())\
    \ value += montgomery.mod << 1;\n            return *this;\n        }\n\n    \
    \    DynamicModInt& operator *=(DynamicModInt rhs) noexcept {\n            value\
    \ = montgomery.reduce(static_cast<larger_type>(value) * rhs.value);\n        \
    \    return *this;\n        }\n\n        DynamicModInt& operator /=(DynamicModInt\
    \ rhs) noexcept {\n            value = montgomery.reduce(static_cast<larger_type>(value)\
    \ * rhs.inverse().value);\n            return *this;\n        }\n\n        friend\
    \ DynamicModInt operator +(DynamicModInt lhs, DynamicModInt rhs) noexcept {\n\
    \            return lhs += rhs;\n        }\n\n        friend DynamicModInt operator\
    \ -(DynamicModInt lhs, DynamicModInt rhs) noexcept {\n            return lhs -=\
    \ rhs;\n        }\n\n        friend DynamicModInt operator *(DynamicModInt lhs,\
    \ DynamicModInt rhs) noexcept {\n            return lhs *= rhs;\n        }\n\n\
    \        friend DynamicModInt operator /(DynamicModInt lhs, DynamicModInt rhs)\
    \ noexcept {\n            return lhs /= rhs;\n        }\n\n        friend bool\
    \ operator ==(DynamicModInt lhs, DynamicModInt rhs) noexcept {\n            return\
    \ lhs.value == rhs.value;\n        }\n\n        friend bool operator !=(DynamicModInt\
    \ lhs, DynamicModInt rhs) noexcept {\n            return lhs.value != rhs.value;\n\
    \        }\n\n        template<class Scanner>\n        void scan(Scanner& scanner)\
    \ {\n            std::int_fast64_t value;\n            scanner.scan(value);\n\
    \            value = montgomery.transform(value % montgomery.mod + montgomery.mod);\n\
    \        }\n\n        template<class Printer>\n        void print(Printer& printer)\
    \ const {\n            printer.print(montgomery.inverse_transform(value));\n \
    \       }\n    };\n\n    namespace helper {\n        template<class T>\n     \
    \   struct InternalDynamicModInt: DynamicModInt<T> {};\n    } // namespace helper\n\
    \n    template<class T, std::size_t kind>\n    struct Hash<DynamicModInt<T, kind>>\
    \ {\n        using value_type = DynamicModInt<T, kind>;\n\n        std::size_t\
    \ operator ()(DynamicModInt<T, kind> a) const noexcept {\n            return static_cast<std::size_t>(a);\n\
    \        }\n    };\n} // namespace kyopro\n#line 8 \"math/is_prime.hpp\"\n\nnamespace\
    \ kyopro {\n    inline constexpr struct {\n        template<class T>\n       \
    \ constexpr bool operator ()(T x) const {\n            using U = std::make_unsigned_t<T>;\n\
    \            using DynamicModInt = helper::InternalDynamicModInt<U>;\n       \
    \     U n = x;\n            if (n <= 1) return false;\n            if (!(n & 1))\
    \ return n == 2;\n            DynamicModInt::set_mod(n);\n            std::uint_fast64_t\
    \ d = (n - 1) >> trailing_zero(n - 1);\n            DynamicModInt one = 1, minus_one\
    \ = n - 1;\n            auto ng = [&](std::uint_fast64_t a) noexcept {\n     \
    \           auto y = DynamicModInt(a).power(d);\n                std::uint_fast64_t\
    \ t = d;\n                while (y != one and y != minus_one and t != n - 1) y\
    \ *= y, t <<= 1;\n                if (y != minus_one and !(t & 1)) return true;\n\
    \                return false;\n            };\n            if (std::numeric_limits<U>::digits\
    \ <= 32 || n < (static_cast<U>(1) << 32)) {\n                for (auto i: (std::uint_fast64_t[3]){2,\
    \ 7, 61}) {\n                if (n <= i) return true;\n                if (ng(i))\
    \ return false;\n                }\n            } else {\n                for\
    \ (auto i: (std::uint_fast64_t[7]){2, 325, 9375, 28178, 450775, 9780504, 1795265022})\
    \ {\n                if (n <= i) return true;\n                if (ng(i)) return\
    \ false;\n                }\n            }\n            return true;\n       \
    \ }\n    } is_prime;\n} // namespace kyopro\n#line 12 \"math/factorize.hpp\"\n\
    \nnamespace kyopro {\n    inline constexpr struct {\n        template<class T>\n\
    \        constexpr T operator ()(T p, std::uint_fast64_t c) const {\n        \
    \    using U = std::make_unsigned_t<T>;\n            using DynamicModInt = helper::InternalDynamicModInt<U>;\n\
    \            U n = p;\n            DynamicModInt::set_mod(n);\n            DynamicModInt\
    \ cc = c;\n            auto f = [=](DynamicModInt x) noexcept {\n            \
    \    return x * x + cc;\n            };\n            auto x = DynamicModInt::raw(1),\
    \ y = DynamicModInt::raw(2), z = DynamicModInt::raw(1), q = DynamicModInt::raw(1);\n\
    \            U g = 1;\n            const int m = 1 << (floor_bit(n) / 5);\n  \
    \          for (int r = 1; g == 1; r <<= 1) {\n                x = y;\n      \
    \          for (int i = 0; i < r; ++i) y = f(y);\n                for (int k =\
    \ 0; k < r && g == 1; k += m) {\n                z = y;\n                int min\
    \ = std::min(m, r - k);\n                for (int i = 0; i < min; ++i) {\n   \
    \                 y = f(y);\n                    q *= x - y;\n               \
    \ }\n                g = std::gcd(static_cast<U>(q), n);\n                }\n\
    \            }\n            if (g == n) {\n                do {\n            \
    \    z = f(z);\n                g = std::gcd(static_cast<U>(x - z), n);\n    \
    \            } while (g == 1);\n            }\n            return g;\n       \
    \ }\n    } pollard_rho;\n\n    inline constexpr struct {\n        KYOPRO_BASE_UINT\
    \ operator ()(std::uint_fast64_t n) const noexcept {\n            static std::mt19937_64\
    \ mt(std::random_device{}());\n            std::uniform_int_distribution<std::uint_fast64_t>\
    \ rnd(0, n - 1);\n            if (is_prime(n)) return n;\n            for (int\
    \ i = 0; i < 100; ++i) {\n                std::uint_fast64_t m = pollard_rho(n,\
    \ rnd(mt));\n                if (is_prime(m)) return m;\n                n = m;\n\
    \            }\n            return 1;\n        }\n    } find_factor;\n\n    inline\
    \ constexpr struct {\n        template<bool sorted = true, class Container = std::vector<KYOPRO_BASE_INT>>\n\
    \        Container operator ()(std::uint_fast64_t n) const {\n            Container\
    \ res;\n            for (int p = 2; p < 100 && p * p <= n; ++p) {\n          \
    \      while (n % p == 0) {\n                n /= p;\n                res.emplace_back(p);\n\
    \                }\n            }\n            while (n > 1) {\n             \
    \   std::uint_fast64_t p = find_factor(n);\n                do {\n           \
    \     n /= p;\n                res.emplace_back(p);\n                } while (n\
    \ % p == 0);\n            }\n            if constexpr (sorted) std::sort(res.begin(),\
    \ res.end());\n            return res;\n        }\n    } factorize;\n} // namespace\
    \ kyopro\n#line 2 \"system/in.hpp\"\n#include <unistd.h>\n#line 4 \"system/in.hpp\"\
    \n#include <bitset>\n#line 7 \"system/in.hpp\"\n#include <cstdio>\n#include <string>\n\
    #line 15 \"system/in.hpp\"\n\nnamespace kyopro {\n    template<std::size_t buf_size\
    \ = KYOPRO_BUFFER_SIZE>\n    struct Reader {\n    private:\n        int fd, idx;\n\
    \        std::array<char, buf_size> buffer;\n\n    public:\n        static constexpr\
    \ KYOPRO_BASE_INT get_buf_size() noexcept {\n            return buf_size;\n  \
    \      }\n\n        Reader() {\n            read(fd, buffer.begin(), buf_size);\n\
    \        }\n        Reader(int fd): fd(fd), idx(0), buffer() {\n            read(fd,\
    \ buffer.begin(), buf_size);\n        }\n        Reader(FILE* fp): fd(fileno(fp)),\
    \ idx(0), buffer() {\n            read(fd, buffer.begin(), buf_size);\n      \
    \  }\n\n        struct iterator {\n        private:\n            Reader& reader;\n\
    \n        public:\n            using difference_type = void;\n            using\
    \ value_type = void;\n            using pointer = void;\n            using reference\
    \ = void;\n            using iterator_category = std::input_iterator_tag;\n\n\
    \            iterator() noexcept = default;\n            iterator(Reader& reader)\
    \ noexcept: reader(reader) {}\n\n            iterator& operator ++() {\n     \
    \           ++reader.idx;\n                if (reader.idx == buf_size) {\n   \
    \                 read(reader.fd, reader.buffer.begin(), buf_size);\n        \
    \            reader.idx = 0;\n                }\n                return *this;\n\
    \            }\n\n            iterator operator ++(int) {\n                iterator\
    \ before = *this;\n                operator ++();\n                return before;\n\
    \            }\n\n            char& operator *() const {\n                return\
    \ reader.buffer[reader.idx];\n            }\n        };\n\n        iterator begin()\
    \ noexcept {\n            return iterator(*this);\n        }\n    };\n\n    Reader\
    \ input(0);\n\n    template<class Iterator, std::size_t decimal_precision = KYOPRO_DECIMAL_PRECISION>\n\
    \    struct Scanner {\n        using iterator_type = Iterator;\n    private:\n\
    \        template<class, class = void>\n        struct has_scan: std::false_type\
    \ {};\n        template<class T>\n        struct has_scan<T, std::void_t<decltype(std::declval<T>().scan(std::declval<Scanner&>()))>>:\
    \ std::true_type {};\n\n    public:\n        Iterator itr;\n\n        static constexpr\
    \ KYOPRO_BASE_INT get_decimal_precision() noexcept {\n            return decimal_precision;\n\
    \        }\n\n        Scanner() noexcept = default;\n        Scanner(Iterator\
    \ itr) noexcept: itr(itr) {}\n\n        void discard_space() {\n            while\
    \ (('\\t' <= *itr && *itr <= '\\r') || *itr == ' ') ++itr;\n        }\n\n    \
    \    void scan(char& a) {\n            discard_space();\n            a = *itr;\n\
    \            ++itr;\n        }\n        void scan(bool& a) {\n            discard_space();\n\
    \            a = *itr != '0';\n        }\n        void scan(std::string& a) {\n\
    \            discard_space();\n            while ((*itr < '\\t' || '\\r' < *itr)\
    \ && *itr != ' ') {\n                a += *itr;\n                ++itr;\n    \
    \        }\n        }\n        template<std::size_t len>\n        void scan(std::bitset<len>&\
    \ a) {\n            discard_space();\n            for (int i = len - 1; i >= 0;\
    \ ++i) {\n                a[i] = *itr != '0';\n                ++itr;\n      \
    \      }\n        }\n        template<class T, std::enable_if_t<std::is_arithmetic_v<T>\
    \ && !has_scan<T>::value>* = nullptr>\n        void scan(T& a) {\n           \
    \ discard_space();\n            bool sgn = false;\n            if constexpr (!std::is_unsigned_v<T>)\
    \ if (*itr == '-') {\n                sgn = true;\n                ++itr;\n  \
    \          }\n            a = 0;\n            for (; '0' <= *itr && *itr <= '9';\
    \ ++itr) a = a * 10 + *itr - '0';\n            if (*itr == '.') {\n          \
    \      ++itr;\n                if constexpr (std::is_floating_point_v<T>) {\n\
    \                    constexpr std::uint_fast64_t power_decimal_precision = power(10ULL,\
    \ decimal_precision);\n                    T d = 0;\n                    std::uint_fast64_t\
    \ i = 1;\n                    for (; '0' <= *itr && *itr <= '9' && i < power_decimal_precision;\
    \ i *= 10) {\n                        d = d * 10 + *itr - '0';\n             \
    \           ++itr;\n                    }\n                    a += d / i;\n \
    \               }\n                while ('0' <= *itr && *itr <= '9') ++itr;\n\
    \            }\n            if constexpr (!std::is_unsigned_v<T>) if (sgn) a =\
    \ -a;\n        }\n        template<std::size_t i = 0, class T, std::enable_if_t<is_agg_v<T>\
    \ && !has_scan<T>::value>* = nullptr>\n        void scan(T& a) {\n           \
    \ if constexpr (i < std::tuple_size_v<T>) {\n                scan(std::get<i>(a));\n\
    \                scan<i + 1>(a);\n            }\n        }\n        template<class\
    \ T, std::enable_if_t<is_range_v<T> && !has_scan<T>::value>* = nullptr>\n    \
    \    void scan(T& a) {\n            for (auto&& i: a) scan(i);\n        }\n  \
    \      template<class T, std::enable_if_t<has_scan<T>::value>* = nullptr>\n  \
    \      void scan(T& a) {\n            a.scan(*this);\n        }\n\n        void\
    \ operator ()() {}\n        template<class Head, class... Args>\n        void\
    \ operator ()(Head& head, Args&... args) {\n            scan(head);\n        \
    \    operator ()(args...);\n        }\n    };\n\n    Scanner<Reader<>::iterator>\
    \ scan(input.begin());\n} // namespace kyopro\n#line 6 \"system/out.hpp\"\n#include\
    \ <cmath>\n#line 17 \"system/out.hpp\"\n\nnamespace kyopro {\n    template<std::size_t\
    \ buf_size = KYOPRO_BUFFER_SIZE>\n    struct Writer {\n    private:\n        int\
    \ fd, idx;\n        std::array<char, buf_size> buffer;\n\n    public:\n      \
    \  static constexpr KYOPRO_BASE_INT get_buf_size() noexcept {\n            return\
    \ buf_size;\n        }\n\n        Writer() noexcept = default;\n        Writer(int\
    \ fd) noexcept: fd(fd), idx(0), buffer() {}\n        Writer(FILE* fp) noexcept:\
    \ fd(fileno(fp)), idx(0), buffer() {}\n\n        ~Writer() {\n            write(fd,\
    \ buffer.begin(), idx);\n        }\n\n        struct iterator {\n        private:\n\
    \            Writer& writer;\n\n        public:\n            using difference_type\
    \ = void;\n            using value_type = void;\n            using pointer = void;\n\
    \            using reference = void;\n            using iterator_category = std::output_iterator_tag;\n\
    \n            iterator() noexcept = default;\n            iterator(Writer& writer)\
    \ noexcept: writer(writer) {}\n\n            iterator& operator ++() {\n     \
    \           ++writer.idx;\n                if (writer.idx == buf_size) {\n   \
    \             write(writer.fd, writer.buffer.begin(), buf_size);\n           \
    \     writer.idx = 0;\n                }\n                return *this;\n    \
    \        }\n\n            iterator operator ++(int) {\n                iterator\
    \ before = *this;\n                operator ++();\n                return before;\n\
    \            }\n\n            char& operator *() const {\n                return\
    \ writer.buffer[writer.idx];\n            }\n\n            void flush() const\
    \ {\n                write(writer.fd, writer.buffer.begin(), writer.idx);\n  \
    \          }\n        };\n\n        iterator begin() noexcept {\n            return\
    \ iterator(*this);\n        }\n    };\n\n    Writer output(1), error(2);\n\n \
    \   template<class Iterator, bool _sep = true, bool _sep_line = true, bool _end_line\
    \ = true, bool _debug = false, bool _comment = false, bool _flush = false, std::size_t\
    \ decimal_precision = KYOPRO_DECIMAL_PRECISION>\n    struct Printer {\n      \
    \  using iterator_type = Iterator;\n        static constexpr bool sep = _sep,\
    \ end_line = _end_line, sep_line = _sep_line, debug = _debug, comment = _comment,\
    \ flush = _flush;\n\n    private:\n        template<class, class = void>\n   \
    \     struct has_print: std::false_type {};\n        template<class T>\n     \
    \   struct has_print<T, std::void_t<decltype(std::declval<T>().print(std::declval<Printer&>()))>>:\
    \ std::true_type {};\n\n    public:\n        static constexpr KYOPRO_BASE_INT\
    \ get_decimal_precision() noexcept {\n            return decimal_precision;\n\
    \        }\n\n        template<class, class = void>\n        struct max_rank {\n\
    \            static constexpr std::size_t value = 0;\n        };\n        template<class\
    \ T>\n        struct max_rank<T, std::enable_if_t<is_agg_v<T>>> {\n          \
    \  template<std::size_t... idx>\n            static constexpr bool get_value_rank(std::index_sequence<idx...>)\
    \ {\n                return std::max({max_rank<aggregate_element_t<idx, T>>::value...});\n\
    \            }\n            static constexpr std::size_t value = get_value_rank(std::make_index_sequence<aggregate_size_v<T>>())\
    \ + 1;\n        };\n        template<class T>\n        struct max_rank<T, std::enable_if_t<is_range_v<T>>>\
    \ {\n            static constexpr std::size_t value = max_rank<range_value_t<T>>::value\
    \ + 1;\n        };\n\n        template<class T>\n        static constexpr KYOPRO_BASE_UINT\
    \ max_rank_v = max_rank<T>::value;\n\n        Iterator itr;\n\n        Printer()\
    \ noexcept = default;\n        Printer(Iterator itr) noexcept: itr(itr) {}\n\n\
    \        void print_char(char c) {\n            *itr = c;\n            ++itr;\n\
    \        }\n\n        template<std::size_t rank>\n        void print_sep() {\n\
    \            if constexpr (sep) {\n                if constexpr (debug) print_char(',');\n\
    \                if constexpr (sep_line && rank >= 2) {\n                    print_char('\\\
    n');\n                    if constexpr (comment) {\n                        print_char('#');\n\
    \                        print_char(' ');\n                    }\n           \
    \     } else print_char(' ');\n            }\n        }\n\n        void print(char\
    \ a) {\n            if constexpr (debug) print_char('\\'');\n            print_char(a);\n\
    \            if constexpr (debug) print_char('\\'');\n        }\n        void\
    \ print(bool a) {\n            print_char(static_cast<char>('0' + a));\n     \
    \   }\n        void print(const char* a) {\n            if constexpr (debug) print_char('\"\
    ');\n            for (; *a != '\\0'; ++a) print_char(*a);\n            if constexpr\
    \ (debug) print_char('\"');\n        }\n        template<std::size_t len>\n  \
    \      void print(const char (&a)[len]) {\n            if constexpr (debug) print_char('\"\
    ');\n            for (auto i: a) print_char(i);\n            if constexpr (debug)\
    \ print_char('\"');\n        }\n        void print(const std::string& a) {\n \
    \           if constexpr (debug) print_char('\"');\n            for (auto i: a)\
    \ print_char(i);\n            if constexpr (debug) print_char('\"');\n       \
    \ }\n        template<std::size_t len>\n        void print(const std::bitset<len>&\
    \ a) {\n            for (int i = len - 1; i >= 0; --i) print(a[i]);\n        }\n\
    \        template<class T, std::enable_if_t<std::is_arithmetic_v<T> && !has_print<T>::value>*\
    \ = nullptr>\n        void print(T a) {\n            if constexpr (std::is_floating_point_v<T>)\
    \ {\n                if (a == std::numeric_limits<T>::infinity()) {\n        \
    \        print(\"inf\");\n                return;\n                }\n       \
    \         if (a == -std::numeric_limits<T>::infinity()) {\n                print(\"\
    -inf\");\n                return;\n                }\n                if (std::isnan(a))\
    \ {\n                print(\"nan\");\n                return;\n              \
    \  }\n            }\n            if constexpr (std::is_signed_v<T>) if (a < 0)\
    \ {\n                print_char('-');\n                a = -a;\n            }\n\
    \            std::uint_fast64_t p = a;\n            std::string s;\n         \
    \   do {\n                s += '0' + p % 10;\n                p /= 10;\n     \
    \       } while (p > 0);\n            for (auto i = s.rbegin(); i != s.rend();\
    \ ++i) print_char(*i);\n            if constexpr (std::is_integral_v<T>) return;\n\
    \            print_char('.');\n            a -= p;\n            for (int i = 0;\
    \ i < static_cast<int>(decimal_precision); ++i) {\n                a *= 10;\n\
    \                print_char('0' + static_cast<std::uint_fast64_t>(a) % 10);\n\
    \            }\n        }\n        template<std::size_t i = 0, class T, std::enable_if_t<is_agg_v<T>\
    \ && !has_print<T>::value>* = nullptr>\n        void print(const T& a) {\n   \
    \         if constexpr (debug && i == 0) print_char('{');\n            if constexpr\
    \ (aggregate_size_v<T> != 0) print(access<i>(a));\n            if constexpr (i\
    \ + 1 < aggregate_size_v<T>) {\n                print_sep<max_rank_v<T>>();\n\
    \                print<i + 1>(a);\n            } else if constexpr (debug) print_char('}');\n\
    \        }\n        template<class T, std::enable_if_t<is_range_v<T> && !has_print<T>::value>*\
    \ = nullptr>\n        void print(const T& a) {\n            if constexpr (debug)\
    \ print_char('{');\n            if (std::empty(a)) return;\n            for (auto\
    \ i = std::begin(a); ; ) {\n                print(*i);\n                if (++i\
    \ != std::end(a)) {\n                print_sep<max_rank_v<T>>();\n           \
    \     } else break;\n            }\n            if constexpr (debug) print_char('}');\n\
    \        }\n        template<class T, std::enable_if_t<has_print<T>::value>* =\
    \ nullptr>\n        void print(const T& a) {\n            a.print(*this);\n  \
    \      }\n\n        template<bool first = true>\n        void operator ()() {\n\
    \            if constexpr (comment && first) print_char('#');\n            if\
    \ constexpr (end_line) print_char('\\n');\n            if constexpr (flush) itr.flush();\n\
    \        }\n        template<bool first = true, class Head, class... Args>\n \
    \       void operator ()(Head&& head, Args&&... args) {\n            if constexpr\
    \ (comment && first) {\n                print_char('#');\n                print_char('\
    \ ');\n            }\n            if constexpr (sep && !first) print_sep<0>();\n\
    \            print(std::forward<Head>(head));\n            operator ()<false>(std::forward<Args>(args)...);\n\
    \        }\n    };\n\n    Printer<Writer<>::iterator, false, false, false> print(output.begin()),\
    \ eprint(error.begin());\n    Printer<Writer<>::iterator> println(output.begin()),\
    \ eprintln(error.begin());\n} // namespace kyopro\n#line 4 \"verify/yosupo/factorize.test.cpp\"\
    \n\nint main() {\n  long long q;\n  kyopro::scan(q);\n  for (int i = 0; i < q;\
    \ ++i) {\n    long long a;\n    kyopro::scan(a);\n    auto res = kyopro::factorize(a);\n\
    \    kyopro::println(res.size(), res);\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\n#include \"\
    ../../math/factorize.hpp\"\n#include \"../../system/all.hpp\"\n\nint main() {\n\
    \  long long q;\n  kyopro::scan(q);\n  for (int i = 0; i < q; ++i) {\n    long\
    \ long a;\n    kyopro::scan(a);\n    auto res = kyopro::factorize(a);\n    kyopro::println(res.size(),\
    \ res);\n  }\n}"
  dependsOn:
  - math/factorize.hpp
  - algorithm/bit.hpp
  - meta/settings.hpp
  - math/DynamicModInt.hpp
  - algorithm/Hash.hpp
  - meta/aggregate.hpp
  - meta/trait.hpp
  - meta/constant.hpp
  - math/power.hpp
  - math/Montgomery.hpp
  - math/is_prime.hpp
  - system/all.hpp
  - system/in.hpp
  - system/out.hpp
  isVerificationFile: true
  path: verify/yosupo/factorize.test.cpp
  requiredBy: []
  timestamp: '2022-08-08 07:54:18+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo/factorize.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/factorize.test.cpp
- /verify/verify/yosupo/factorize.test.cpp.html
title: verify/yosupo/factorize.test.cpp
---