---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/Hash.hpp
    title: algorithm/Hash.hpp
  - icon: ':warning:'
    path: algorithm/algorithm.hpp
    title: algorithm/algorithm.hpp
  - icon: ':warning:'
    path: algorithm/all.hpp
    title: algorithm/all.hpp
  - icon: ':heavy_check_mark:'
    path: algorithm/bit.hpp
    title: algorithm/bit.hpp
  - icon: ':warning:'
    path: function/RecursiveLambda.hpp
    title: function/RecursiveLambda.hpp
  - icon: ':warning:'
    path: function/all.hpp
    title: function/all.hpp
  - icon: ':warning:'
    path: function/compare.hpp
    title: function/compare.hpp
  - icon: ':warning:'
    path: function/identity.hpp
    title: function/identity.hpp
  - icon: ':heavy_check_mark:'
    path: function/monoid.hpp
    title: function/monoid.hpp
  - icon: ':warning:'
    path: iterator/all.hpp
    title: iterator/all.hpp
  - icon: ':warning:'
    path: iterator/imap.hpp
    title: iterator/imap.hpp
  - icon: ':warning:'
    path: iterator/iterator_base.hpp
    title: iterator/iterator_base.hpp
  - icon: ':heavy_check_mark:'
    path: math/DynamicModInt.hpp
    title: math/DynamicModInt.hpp
  - icon: ':warning:'
    path: math/ModInt.hpp
    title: math/ModInt.hpp
  - icon: ':heavy_check_mark:'
    path: math/Montgomery.hpp
    title: math/Montgomery.hpp
  - icon: ':warning:'
    path: math/all.hpp
    title: math/all.hpp
  - icon: ':warning:'
    path: math/div.hpp
    title: math/div.hpp
  - icon: ':warning:'
    path: math/divisors.hpp
    title: math/divisors.hpp
  - icon: ':warning:'
    path: math/euler_phi.hpp
    title: math/euler_phi.hpp
  - icon: ':heavy_check_mark:'
    path: math/factorize.hpp
    title: math/factorize.hpp
  - icon: ':heavy_check_mark:'
    path: math/is_prime.hpp
    title: math/is_prime.hpp
  - icon: ':warning:'
    path: math/mod.hpp
    title: math/mod.hpp
  - icon: ':heavy_check_mark:'
    path: math/power.hpp
    title: math/power.hpp
  - icon: ':heavy_check_mark:'
    path: meta/aggregate.hpp
    title: meta/aggregate.hpp
  - icon: ':warning:'
    path: meta/all.hpp
    title: meta/all.hpp
  - icon: ':heavy_check_mark:'
    path: meta/constant.hpp
    title: meta/constant.hpp
  - icon: ':heavy_check_mark:'
    path: meta/settings.hpp
    title: meta/settings.hpp
  - icon: ':heavy_check_mark:'
    path: meta/trait.hpp
    title: meta/trait.hpp
  - icon: ':heavy_check_mark:'
    path: structure/FenwickTree.hpp
    title: structure/FenwickTree.hpp
  - icon: ':heavy_check_mark:'
    path: structure/UnionFind.hpp
    title: structure/UnionFind.hpp
  - icon: ':warning:'
    path: structure/all.hpp
    title: structure/all.hpp
  - icon: ':heavy_check_mark:'
    path: system/all.hpp
    title: system/all.hpp
  - icon: ':heavy_check_mark:'
    path: system/in.hpp
    title: system/in.hpp
  - icon: ':heavy_check_mark:'
    path: system/out.hpp
    title: system/out.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algorithm/bit.hpp\"\n#include <limits>\n#include <type_traits>\n\
    #line 2 \"meta/settings.hpp\"\n#include <cstdint>\n\n#ifndef KYOPRO_BASE_INT\n\
    #define KYOPRO_BASE_INT std::int64_t\n#endif\n\n#ifndef KYOPRO_BASE_UINT\n#define\
    \ KYOPRO_BASE_UINT std::uint64_t\n#endif\n\n#ifndef KYOPRO_BASE_FLOAT\n#define\
    \ KYOPRO_BASE_FLOAT double\n#endif\n\n#ifndef KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD\
    \ static_cast<KYOPRO_BASE_UINT>(998244353)\n#endif\n\n#ifndef KYOPRO_DECIMAL_PRECISION\n\
    #define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n#endif\n\n\
    #ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
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
    } // namespace kyopro\n#line 2 \"algorithm/algorithm.hpp\"\n#include <algorithm>\n\
    #include <functional>\n#include <iterator>\n#line 6 \"algorithm/algorithm.hpp\"\
    \n#include <unordered_map>\n#include <utility>\n#include <vector>\n#line 2 \"\
    function/compare.hpp\"\n\nnamespace kyopro {\n    struct Equal {\n        template<class\
    \ T>\n        constexpr bool operator()(const T& x, const T& y) const noexcept(noexcept(x\
    \ == y)) {\n            return x == y;\n        }\n    };\n\n    struct NotEqual\
    \ {\n        template<class T>\n        constexpr bool operator()(const T& x,\
    \ const T& y) const noexcept(noexcept(x != y)) {\n            return x != y;\n\
    \        }\n    };\n\n    struct Less {\n        template<class T>\n        constexpr\
    \ bool operator()(const T& x, const T& y) const noexcept(noexcept(x < y)) {\n\
    \            return x < y;\n        }\n    };\n\n    struct LessEqual {\n    \
    \    template<class T>\n        constexpr bool operator()(const T& x, const T&\
    \ y) const noexcept(noexcept(x <= y)) {\n            return x <= y;\n        }\n\
    \    };\n\n    struct Greater {\n        template<class T>\n        constexpr\
    \ bool operator()(const T& x, const T& y) const noexcept(noexcept(x > y)) {\n\
    \            return x > y;\n        }\n    };\n\n    struct GreaterEqual {\n \
    \       template<class T>\n        constexpr bool operator()(const T& x, const\
    \ T& y) const noexcept(noexcept(x >= y)) {\n            return x >= y;\n     \
    \   }\n    };\n} // namespace kyopro\n#line 3 \"function/identity.hpp\"\n\nnamespace\
    \ kyopro {\n    struct Identity {\n        template<class T>\n        T&& operator\
    \ ()(T&& a) const noexcept {\n            return std::forward<T>(a);\n       \
    \ }\n    };\n}\n#line 3 \"meta/trait.hpp\"\n#include <queue>\n#line 5 \"meta/trait.hpp\"\
    \n#include <stack>\n#line 9 \"meta/trait.hpp\"\n\ntemplate<>\nstruct std::is_integral<__int128_t>:\
    \ std::true_type {};\ntemplate<>\nstruct std::is_integral<__uint128_t>: std::true_type\
    \ {};\ntemplate<>\nstruct std::is_floating_point<__float128>: std::true_type {};\n\
    \nnamespace kyopro {\n    template<KYOPRO_BASE_UINT size>\n    struct int_least\
    \ {\n    private:\n        static constexpr auto get_type() noexcept {\n     \
    \       static_assert(size <= 128, \"Integer size is too large\");\n         \
    \   if constexpr (size <= 8) return std::int_least8_t{};\n            else if\
    \ constexpr (size <= 16) return std::int_least16_t{};\n            else if constexpr\
    \ (size <= 32) return std::int_least32_t{};\n            else if constexpr (size\
    \ <= 64) return std::int_least64_t{};\n            else return __int128_t{};\n\
    \        }\n\n    public:\n        using type = decltype(get_type());\n    };\n\
    \n    template<KYOPRO_BASE_UINT size>\n    using int_least_t = typename int_least<size>::type;\n\
    \n    template<KYOPRO_BASE_UINT size>\n    struct uint_least {\n    private:\n\
    \        static constexpr auto get_type() noexcept {\n            static_assert(size\
    \ <= 128, \"Integer size is too large\");\n            if constexpr (size <= 8)\
    \ return std::uint_least8_t{};\n            else if constexpr (size <= 16) return\
    \ std::uint_least16_t{};\n            else if constexpr (size <= 32) return std::uint_least32_t{};\n\
    \            else if constexpr (size <= 64) return std::uint_least64_t{};\n  \
    \          else return __uint128_t{};\n        }\n\n    public:\n        using\
    \ type = decltype(get_type());\n    };\n\n    template<KYOPRO_BASE_UINT size>\n\
    \    using uint_least_t = typename uint_least<size>::type;\n\n    template<class,\
    \ class = void>\n    struct is_iterator: std::false_type {};\n    template<class\
    \ T>\n    struct is_iterator<T, std::void_t<typename std::iterator_traits<T>::iterator_category>>:\
    \ std::true_type {};\n\n    template<class T>\n    constexpr bool is_iterator_v\
    \ = is_iterator<T>::value;\n\n    template<class, class = void>\n    struct is_iterable:\
    \ std::false_type {};\n    template<class T>\n    struct is_iterable<T, std::void_t<decltype(std::begin(std::declval<std::add_lvalue_reference_t<T>>()),\
    \ std::end(std::declval<std::add_lvalue_reference_t<T>>()))>>: std::true_type\
    \ {};\n\n    template<class T>\n    constexpr bool is_iterable_v = is_iterable<T>::value;\n\
    \n    template<class T>\n    struct iterable_value {\n        using type = std::decay_t<decltype(*std::begin(std::declval<T>()))>;\n\
    \    };\n\n    template<class T>\n    using iterable_value_t = typename iterable_value<T>::type;\n\
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
    \ is_agg: std::conjunction<std::is_aggregate<T>, std::negation<is_iterable<T>>>\
    \ {};\n\n    template<class T>\n    inline constexpr bool is_agg_v = is_agg<T>::value;\n\
    } // namespace kyopro\n#line 13 \"algorithm/algorithm.hpp\"\n\nnamespace kyopro::range\
    \ {\n    inline constexpr struct {\n        template<class Container = void, class\
    \ T, class Proj = Identity, class Compare = Less>\n        constexpr auto operator\
    \ ()(T range, const Proj& proj = {}, const Compare& comp = {}) const {\n     \
    \       sort(std::begin(range), std::end(range), proj, comp);\n            auto\
    \ end = std::unique(std::begin(range), std::end(range));\n            std::conditional_t<std::is_same_v<Container,\
    \ void>, std::unordered_map<typename std::iterator_traits<Iterator>::value_type,\
    \ KYOPRO_BASE_INT>, Container> mem;\n            int cnt = 0;\n            for\
    \ (auto i = std::begin(range); i != end; ++i) mem[*i] = cnt++;\n            return\
    \ mem;\n        }\n    } compress;\n\n    inline constexpr struct {\n        template<class\
    \ T, class Proj = Identity>\n        constexpr bool operator ()(T&& range, const\
    \ Proj& proj = {}) const {\n            return std::all_of(std::begin(range),\
    \ std::end(range), proj);\n        }\n    } all_of;\n\n    inline constexpr struct\
    \ {\n        template<class T, class Proj = Identity>\n        constexpr bool\
    \ operator ()(T&& range, const Proj& proj = {}) const {\n            return std::any_of(std::begin(range),\
    \ std::end(range), proj);\n        }\n    } any_of;\n\n    inline constexpr struct\
    \ {\n        template<class T, class Proj = Identity>\n        constexpr bool\
    \ operator ()(T&& range, const Proj& proj = {}) const {\n            return std::none_of(std::begin(range),\
    \ std::end(range), proj);\n        }\n    } none_of;\n\n    inline constexpr struct\
    \ {\n        template<class T, class Func, class Proj = Identity>\n        constexpr\
    \ auto operator ()(T&& range, const Func& func, const Proj& proj = {}) const {\n\
    \            return std::for_each(std::begin(range), std::end(range), func);\n\
    \        }\n    } for_each;\n} // namespace kyopro::range\n#line 2 \"algorithm/Hash.hpp\"\
    \n#include <cstddef>\n#line 5 \"algorithm/Hash.hpp\"\n#include <tuple>\n#line\
    \ 7 \"meta/aggregate.hpp\"\n\nnamespace kyopro {\n    namespace helper {\n   \
    \     #define DEFINE_ACCESS(n, ...)                                          \
    \                                 \\\n        template<std::size_t idx, class\
    \ T, std::enable_if_t<aggregate_size_v<std::decay_t<T>> == n>* = nullptr> \\\n\
    \            constexpr decltype(auto) access_impl(T&& aggregate, char) noexcept\
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
    \ {\n        using value_type = T;\n\n        template<KYOPRO_BASE_UINT i = 0>\n\
    \        constexpr std::size_t operator ()(const T& a) const noexcept {\n    \
    \        if constexpr (i == aggregate_size_v<T>) return aggregate_size_v<T>;\n\
    \            else {\n                std::uint_fast64_t seed = operator()<i +\
    \ 1>(a);\n                return seed ^ (Hash<aggregate_element_t<i, T>>()(access<i>(a))\
    \ + 0x9e3779b97f4a7c15LU + (seed << 12) + (seed >> 4));\n            }\n     \
    \   }\n    };\n\n    template<class T>\n    struct Hash<T, std::enable_if_t<is_iterable_v<T>>>:\
    \ Hash<iterable_value_t<T>> {\n        using value_type = T;\n\n        constexpr\
    \ std::size_t operator ()(const T& a) const {\n            std::uint_fast64_t\
    \ seed = a.size();\n            for (auto&& i: a) seed ^= Hash<iterable_value_t<T>>(i)\
    \ + 0x9e3779b97f4a7c15LU + (seed << 12) + (seed >> 4);\n            return seed;\n\
    \        }\n    };\n} // namespace kyopro\n#line 2 \"meta/constant.hpp\"\n#include\
    \ <array>\n#line 3 \"math/power.hpp\"\n\nnamespace kyopro {\n    inline constexpr\
    \ struct {\n        template<class T>\n        constexpr T operator ()(T a, KYOPRO_BASE_UINT\
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
    \ pi = PI<KYOPRO_BASE_FLOAT>;\n} // namespace kyopro\n#line 5 \"function/monoid.hpp\"\
    \n\nnamespace kyopro {\n    template<class T, T _id = 0>\n    struct Add {\n \
    \       static_assert(std::is_arithmetic_v<T>);\n        using value_type = T;\n\
    \n        constexpr T id() const noexcept {\n            return _id;\n       \
    \ }\n\n        constexpr T operator ()(T a, T b) const noexcept {\n          \
    \  return a + b;\n        }\n\n        constexpr T inverse(T a) const noexcept\
    \ {\n            return -a;\n        }\n    };\n\n    template<class T, T _id\
    \ = 1>\n    struct Mul {\n        static_assert(std::is_arithmetic_v<T>);\n  \
    \      using value_type = T;\n\n        constexpr T id() const noexcept {\n  \
    \          return _id;\n        }\n\n        constexpr T operator ()(T a, T b)\
    \ const noexcept {\n            return a * b;\n        }\n\n        constexpr\
    \ T inverse(T a) const noexcept {\n        static_assert(!std::is_integral_v<T>);\n\
    \            return 1 / a;\n        }\n    };\n\n    template<class T, T _id =\
    \ std::is_integral_v<T> ? INF<T> : std::numeric_limits<T>::infinity()>\n    struct\
    \ Min {\n        static_assert(std::is_arithmetic_v<T>);\n        using value_type\
    \ = T;\n\n        constexpr T id() const noexcept {\n            return _id;\n\
    \        }\n\n        constexpr T operator ()(T a, T b) const noexcept {\n   \
    \         return a < b ? a : b;\n        }\n    };\n\n    template<class T, T\
    \ _id = std::is_integral_v<T> ? std::is_signed_v<T> ? -INF<T> : 0 : -std::numeric_limits<T>::infinity()>\n\
    \    struct Max {\n        static_assert(std::is_arithmetic_v<T>);\n        using\
    \ value_type = T;\n\n        constexpr T id() const noexcept {\n            return\
    \ _id;\n        }\n\n        constexpr T operator ()(T a, T b) const noexcept\
    \ {\n            return a > b ? a : b;\n        }\n    };\n} // namespace kyopro\n\
    #line 4 \"function/RecursiveLambda.hpp\"\n\nnamespace kyopro {\n    template<class\
    \ F>\n    struct RecursiveLambda {\n        using value_type = F;\n\n    private:\n\
    \        F func;\n\n    public:\n        template<class G>\n        constexpr\
    \ RecursiveLambda(G&& func) noexcept: func(std::forward<G>(func)) {}\n       \
    \ template<class... Args>\n        constexpr decltype(auto) operator ()(Args&&...\
    \ args) const noexcept(noexcept(func(*this, std::forward<Args>(args)...))) {\n\
    \            return func(*this, std::forward<Args>(args)...);\n        }\n   \
    \ };\n\n    template<class F>\n    RecursiveLambda(F&&) -> RecursiveLambda<std::decay_t<F>>;\n\
    } // namespace kyopro\n#line 4 \"iterator/iterator_base.hpp\"\n\nnamespace kyopro\
    \ {\n    template<class, class, class, class>\n    struct IteratorBase;\n\n  \
    \  template<class Derived, class ValueType, class Dereference>\n    struct IteratorBase<Derived,\
    \ ValueType, Dereference, std::forward_iterator_tag> {\n        using value_type\
    \ = ValueType;\n        using pointer = ValueType*;\n        using reference =\
    \ ValueType&;\n        using difference_type = std::ptrdiff_t;\n        using\
    \ iterator_category = std::forward_iterator_tag;\n\n        virtual constexpr\
    \ reference operator *() const noexcept;\n        virtual constexpr Derived& operator\
    \ ++() noexcept;\n        virtual constexpr bool operator ==(const Derived&) const\
    \ noexcept;\n\n        constexpr Derived operator ++(int) noexcept {\n       \
    \     Derived before = *this;\n            ++*this;\n            return before;\n\
    \        }\n        constexpr Dereference operator !=(const Derived& rhs) const\
    \ noexcept {\n            return !(*this == rhs);\n        }\n    };\n\n    template<class\
    \ Derived, class ValueType, class Dereference>\n    struct IteratorBase<Derived,\
    \ ValueType, Dereference, std::bidirectional_iterator_tag>: IteratorBase<Derived,\
    \ ValueType, Dereference, std::forward_iterator_tag> {\n        using iterator_category\
    \ = std::bidirectional_iterator_tag;\n\n        virtual constexpr Derived& operator\
    \ --() noexcept;\n\n        constexpr Derived operator --(int) noexcept {\n  \
    \          Derived before = *this;\n            --*this;\n            return before;\n\
    \        }\n    };\n\n    template<class Derived, class ValueType, class Dereference>\n\
    \    struct IteratorBase<Derived, ValueType, Dereference, std::random_access_iterator_tag>:\
    \ IteratorBase<Derived, ValueType, Dereference, std::bidirectional_iterator_tag>\
    \ {\n        using iterator_category = std::random_access_iterator_tag;\n\n  \
    \      virtual constexpr Derived operator +(std::ptrdiff_t rhs) const noexcept;\n\
    \        virtual constexpr std::ptrdiff_t operator -(const Derived&) const noexcept;\n\
    \n    private:\n        virtual constexpr int compare(const Derived&) const noexcept;\n\
    \n    public:\n\n        constexpr Derived& operator +=(std::ptrdiff_t rhs) noexcept\
    \ {\n            return *this = *this + rhs;\n        }\n        constexpr Derived\
    \ operator -(std::ptrdiff_t rhs) const noexcept {\n            return *this +\
    \ -rhs;\n        }\n        constexpr Derived& operator -=(std::ptrdiff_t rhs)\
    \ noexcept {\n            return *this = *this - rhs;\n        }\n        virtual\
    \ constexpr bool operator ==(const Derived& rhs) const noexcept {\n          \
    \  return compare(rhs) == 0;\n        }\n        virtual constexpr bool operator\
    \ !=(const Derived& rhs) const noexcept {\n            return compare(rhs) !=\
    \ 0;\n        }\n        virtual constexpr bool operator <(const Derived& rhs)\
    \ const noexcept {\n            return compare(rhs) < 0;\n        }\n        virtual\
    \ constexpr bool operator <=(const Derived& rhs) const noexcept {\n          \
    \  return compare(rhs) <= 0;\n        }\n        virtual constexpr bool operator\
    \ >(const Derived& rhs) const noexcept {\n            return compare(rhs) > 0;\n\
    \        }\n        virtual constexpr bool operator >=(const Derived& rhs) const\
    \ noexcept {\n            return compare(rhs) >= 0;\n        }\n        virtual\
    \ constexpr bool operator [](std::size_t idx) const noexcept {\n            return\
    \ *(*this + idx);\n        }\n    };\n} // namespace kyopro\n#line 8 \"iterator/imap.hpp\"\
    \n\nnamespace kyopro {\n    template<class Func, class Range>\n    struct imap\
    \ {\n        using value_type = std::decay_t<decltype(func(std::declval<iterable_value_t<Range>>()))>;\n\
    \        using size_type = std::size_t;\n        using difference_type = std::ptrdiff_t;\n\
    \        using reference = value_type&;\n        using const_reference = const\
    \ value_type&;\n        using pointer = value_type*;\n        using const_pointer\
    \ = const value_type*;\n\n    private:\n        Func func;\n        Range range;\n\
    \n        template<class F, class R>\n        imap(F&& func, R&& range): func(std::forward<F>(func)),\
    \ range(std::forward<R>(range)) {}\n\n    public:\n        using BaseIterator\
    \ = std::decay_t<decltype(std::begin(std::declval<Range>()))>;\n\n        struct\
    \ iterator: BaseIterator {\n        private:\n            Func func;\n\n     \
    \   public:\n            iterator() noexcept = default;\n            template<class\
    \ F>\n            iterator(F&& func, BaseIterator itr) noexcept: func(std::forward<F>(func)),\
    \ itr(itr) {}\n\n            constexpr decltype(auto) operator *() const noexcept\
    \ {\n                return func(*itr);\n            }\n        };\n    };\n\n\
    \    template<class F, class R>\n    imap(F&&, R&&) -> imap<std::decay_t<F>, std::decay_t<R>>;\n\
    }\n#line 3 \"math/div.hpp\"\n\nnamespace kyopro {\n    inline constexpr struct\
    \ {\n        template<class T, class U>\n        constexpr std::common_type_t<T,\
    \ U> operator ()(T x, U m) const noexcept {\n            static_assert(std::is_integral_v<T>\
    \ && std::is_integral_v<U>, \"Integer is required\");\n            if constexpr\
    \ (std::is_unsigned_v<T> || std::is_unsigned_v<U>) return x / m;\n           \
    \ auto d = x / m;\n            return d * m == x ? d : d - ((x < 0) ^ (m < 0));\n\
    \        }\n    } floor_div;\n\n    inline constexpr struct {\n        template<class\
    \ T, class U>\n        constexpr std::common_type_t<T, U> operator ()(T x, U m)\
    \ const noexcept {\n            return floor_div(x + m - static_cast<T>(1), m);\n\
    \        }\n    } ceil_div;\n} // namespace kyopro\n#line 5 \"math/divisors.hpp\"\
    \n\nnamespace kyopro {\n    inline constexpr struct {\n        template<class\
    \ Container = std::vector<KYOPRO_BASE_INT>>\n        Container operator ()(KYOPRO_BASE_UINT\
    \ n) const {\n            Container lower, upper;\n            std::uint_fast64_t\
    \ i;\n            for (i = 1; i * i < n; ++i) if (n % i == 0) {\n            \
    \    lower.emplace_back(i);\n                upper.emplace_back(n / i);\n    \
    \        }\n            if (i * i == n) lower.emplace_back(i);\n            lower.insert(end(lower),\
    \ rall(upper));\n            return lower;\n        }\n    } divisors;\n} // namespace\
    \ kyopro\n#line 2 \"math/DynamicModInt.hpp\"\n#include <cassert>\n#line 6 \"math/Montgomery.hpp\"\
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
    \ T, KYOPRO_BASE_UINT _kind = 0>\n    struct DynamicModInt {\n        static_assert(std::is_unsigned_v<T>,\
    \ \"T must be unsigned integer\");\n        using value_type = T;\n        static\
    \ constexpr KYOPRO_BASE_INT kind = _kind;\n\n    private:\n        using larger_type\
    \ = uint_least_t<std::numeric_limits<T>::digits * 2>;\n\n        inline static\
    \ Montgomery<T> montgomery;\n\n    public:\n        T value;\n\n        static\
    \ void set_mod(T mod) noexcept {\n            montgomery.set_mod(mod);\n     \
    \   }\n\n        static KYOPRO_BASE_INT get_mod() noexcept {\n            return\
    \ montgomery.mod;\n        }\n\n        KYOPRO_BASE_INT get_val() noexcept {\n\
    \            return montgomery.inverse_transform(value);\n        }\n\n      \
    \  DynamicModInt() noexcept = default;\n        DynamicModInt(T value) noexcept:\
    \ value(montgomery.transform(value % montgomery.mod + montgomery.mod)) {}\n\n\
    \        template<class U>\n        explicit operator U() const noexcept {\n \
    \           return montgomery.inverse_transform(value);\n        }\n\n       \
    \ static DynamicModInt raw(T value) noexcept {\n            DynamicModInt res;\n\
    \            res.value = montgomery.transform(value);\n            return res;\n\
    \        }\n\n        DynamicModInt power(KYOPRO_BASE_UINT n) const noexcept {\n\
    \            DynamicModInt res = 1, a = *this;\n            while (n > 0) {\n\
    \                if (n & 1) res = res * a;\n                a = a * a;\n     \
    \           n >>= 1;\n            }\n            return res;\n        }\n\n  \
    \      DynamicModInt inverse() const noexcept {\n            return power(montgomery.mod\
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
    \       }\n    };\n\n    template<class T, KYOPRO_BASE_UINT kind>\n    struct\
    \ Hash<DynamicModInt<T, kind>> {\n        using value_type = DynamicModInt<T,\
    \ kind>;\n\n        std::size_t operator ()(DynamicModInt<T, kind> a) const noexcept\
    \ {\n            return static_cast<std::size_t>(a);\n        }\n    };\n} //\
    \ namespace kyopro\n#line 4 \"math/euler_phi.hpp\"\n\nnamespace kyopro {\n   \
    \ inline constexpr struct {\n        constexpr KYOPRO_BASE_UINT operator ()(KYOPRO_BASE_UINT\
    \ n) const noexcept {\n            std::uint_fast64_t res = n;\n            if\
    \ ((n & 1) == 0) {\n                res -= res >> 1;\n                n >>= 1;\n\
    \                while ((n & 1) == 0) n >>= 1;\n            }\n            for\
    \ (std::uint_fast64_t i = 3; i * i <= n; i += 2) {\n                if (n % i\
    \ == 0) {\n                res -= res / i;\n                n /= i;\n        \
    \        while (n % i == 0) n /= i;\n                }\n            }\n      \
    \      if (n != 1) res -= res / n;\n            return res;\n        }\n    }\
    \ euler_phi;\n} // namespace kyopro\n#line 4 \"math/factorize.hpp\"\n#include\
    \ <numeric>\n#include <random>\n#line 7 \"math/is_prime.hpp\"\n\nnamespace kyopro\
    \ {\n    inline constexpr struct {\n        template<class T>\n        constexpr\
    \ bool operator ()(T x) const {\n            using U = std::make_unsigned_t<T>;\n\
    \            using DynamicModInt = DynamicModInt<U, KYOPRO_BASE_UINT(-1)>;\n \
    \           U n = x;\n            if (n <= 1) return false;\n            if (!(n\
    \ & 1)) return n == 2;\n            DynamicModInt::set_mod(n);\n            std::uint_fast64_t\
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
    \ }\n    } is_prime;\n} // namespace kyopro\n#line 11 \"math/factorize.hpp\"\n\
    \nnamespace kyopro {\n    inline constexpr struct {\n        template<class T>\n\
    \        constexpr T operator ()(T p, KYOPRO_BASE_UINT c) const {\n          \
    \  using U = std::make_unsigned_t<T>;\n            using DynamicModInt = DynamicModInt<U,\
    \ KYOPRO_BASE_UINT(-1)>;\n            U n = p;\n            DynamicModInt::set_mod(n);\n\
    \            DynamicModInt cc = c;\n            auto f = [=](DynamicModInt x)\
    \ noexcept {\n                return x * x + cc;\n            };\n           \
    \ auto x = DynamicModInt::raw(1), y = DynamicModInt::raw(2), z = DynamicModInt::raw(1),\
    \ q = DynamicModInt::raw(1);\n            U g = 1;\n            const int m =\
    \ 1 << (floor_bit(n) / 5);\n            for (int r = 1; g == 1; r <<= 1) {\n \
    \               x = y;\n                for (int i = 0; i < r; ++i) y = f(y);\n\
    \                for (int k = 0; k < r && g == 1; k += m) {\n                z\
    \ = y;\n                int min = std::min(m, r - k);\n                for (int\
    \ i = 0; i < min; ++i) {\n                    y = f(y);\n                    q\
    \ *= x - y;\n                }\n                g = std::gcd(static_cast<U>(q),\
    \ n);\n                }\n            }\n            if (g == n) {\n         \
    \       do {\n                z = f(z);\n                g = std::gcd(static_cast<U>(x\
    \ - z), n);\n                } while (g == 1);\n            }\n            return\
    \ g;\n        }\n    } pollard_rho;\n\n    inline constexpr struct {\n       \
    \ KYOPRO_BASE_UINT operator ()(KYOPRO_BASE_UINT n) const noexcept {\n        \
    \    static std::mt19937_64 mt(std::random_device{}());\n            std::uniform_int_distribution<std::uint_fast64_t>\
    \ rnd(0, n - 1);\n            if (is_prime(n)) return n;\n            for (int\
    \ i = 0; i < 100; ++i) {\n                std::uint_fast64_t m = pollard_rho(n,\
    \ rnd(mt));\n                if (is_prime(m)) return m;\n                n = m;\n\
    \            }\n            return 1;\n        }\n    } find_factor;\n\n    inline\
    \ constexpr struct {\n        template<bool sorted = true, class Container = std::vector<KYOPRO_BASE_INT>>\n\
    \        Container operator ()(KYOPRO_BASE_UINT n) const {\n            Container\
    \ res;\n            for (int p = 2; p < 100 && p * p <= n; ++p) {\n          \
    \      while (n % p == 0) {\n                n /= p;\n                res.emplace_back(p);\n\
    \                }\n            }\n            while (n > 1) {\n             \
    \   std::uint_fast64_t p = find_factor(n);\n                do {\n           \
    \     n /= p;\n                res.emplace_back(p);\n                } while (n\
    \ % p == 0);\n            }\n            if constexpr (sorted) std::sort(res.begin(),\
    \ res.end());\n            return res;\n        }\n    } factorize;\n} // namespace\
    \ kyopro\n#line 4 \"math/mod.hpp\"\n\nnamespace kyopro {\n    inline constexpr\
    \ struct {\n        template<class T, class U>\n        constexpr std::common_type_t<T,\
    \ U> operator ()(T x, U m) const noexcept {\n            static_assert(std::is_integral_v<T>\
    \ && std::is_integral_v<U>, \"Integer is required\");\n            if constexpr\
    \ (std::is_unsigned_v<T> || std::is_unsigned_v<U>) return x % m;\n           \
    \ return (x %= m) < 0 ? x + m : x;\n        }\n    } floor_mod;\n\n    inline\
    \ constexpr struct {\n        template<class T, class U>\n        constexpr std::common_type_t<T,\
    \ U> operator ()(T x, U m) const noexcept {\n            return m - floor_mod(x\
    \ - 1, m) - static_cast<T>(1);\n        }\n    } ceil_mod;\n} // namespace kyopro\n\
    #line 14 \"math/ModInt.hpp\"\n\nnamespace kyopro {\n    template<KYOPRO_BASE_UINT\
    \ m>\n    struct ModInt {\n        using value_type = uint_least_t<bit_len(m *\
    \ 2 - 2)>;\n        static constexpr KYOPRO_BASE_INT mod = m;\n\n    private:\n\
    \        static constexpr value_type _mod = m;\n\n    public:\n        value_type\
    \ value;\n\n        static constexpr KYOPRO_BASE_INT get_mod() noexcept {\n  \
    \          return mod;\n        }\n\n        constexpr ModInt() noexcept = default;\n\
    \        template<class T>\n        constexpr ModInt(T value) noexcept: value(floor_mod(value,\
    \ _mod)) {}\n\n        template<class T>\n        explicit constexpr operator\
    \ T() const noexcept {\n            return value;\n        }\n\n        static\
    \ constexpr ModInt raw(value_type value) noexcept {\n            ModInt res;\n\
    \            res.value = value;\n            return res;\n        }\n\n      \
    \  constexpr ModInt power(KYOPRO_BASE_UINT n) const noexcept {\n            std::uint_fast64_t\
    \ res = 1, a = value;\n            while (n > 0) {\n                if (n & 1)\
    \ res = res * a % _mod;\n                a = a * a % _mod;\n                n\
    \ >>= 1;\n            }\n            return res;\n        }\n\n        constexpr\
    \ ModInt inverse() const noexcept {\n            std::uint_fast64_t a = value,\
    \ b = _mod;\n            std::int_fast64_t u = 1, v = 0;\n            while (b\
    \ > 0) {\n                std::uint_fast64_t t = a / b;\n                a -=\
    \ t * b;\n                std::swap(a, b);\n                u -= t * v;\n    \
    \            std::swap(u, v);\n            }\n            return floor_mod(u,\
    \ _mod);\n        }\n\n        constexpr ModInt operator +() const noexcept {\n\
    \            return *this;\n        }\n\n        constexpr ModInt operator -()\
    \ const noexcept {\n            return value == 0 ? 0 : _mod - value;\n      \
    \  }\n\n        constexpr ModInt& operator ++() noexcept {\n            if (++value\
    \ >= _mod) value -= _mod;\n            return *this;\n        }\n\n        constexpr\
    \ ModInt operator ++(int) noexcept {\n            ModInt before = *this;\n   \
    \         ++*this;\n            return before;\n        }\n\n        constexpr\
    \ ModInt& operator --() noexcept {\n            if (value == 0) value = _mod;\n\
    \            --value;\n            return *this;\n        }\n\n        constexpr\
    \ ModInt operator --(int) noexcept {\n            ModInt before = *this;\n   \
    \         --*this;\n            return before;\n        }\n\n        constexpr\
    \ ModInt& operator +=(ModInt rhs) noexcept {\n            if ((value += rhs.value)\
    \ >= _mod) value -= _mod;\n            return *this;\n        }\n\n        constexpr\
    \ ModInt& operator -=(ModInt rhs) noexcept {\n            if (value < rhs.value)\
    \ value += _mod;\n            value -= rhs.value;\n            return *this;\n\
    \        }\n\n        constexpr ModInt& operator *=(ModInt rhs) noexcept {\n \
    \           value = static_cast<uint_least_t<bit_len(_mod) * 2>>(value) * rhs.value\
    \ % _mod;\n            return *this;\n        }\n\n        constexpr ModInt& operator\
    \ /=(ModInt rhs) noexcept {\n            value = static_cast<uint_least_t<bit_len(_mod)\
    \ * 2>>(value) * rhs.inverse().value % _mod;\n            return *this;\n    \
    \    }\n\n        friend constexpr ModInt operator +(ModInt lhs, ModInt rhs) noexcept\
    \ {\n            return lhs += rhs;\n        }\n\n        friend constexpr ModInt\
    \ operator -(ModInt lhs, ModInt rhs) noexcept {\n            return lhs -= rhs;\n\
    \        }\n\n        friend constexpr ModInt operator *(ModInt lhs, ModInt rhs)\
    \ noexcept {\n            return lhs *= rhs;\n        }\n\n        friend constexpr\
    \ ModInt operator /(ModInt lhs, ModInt rhs) noexcept {\n            return lhs\
    \ /= rhs;\n        }\n\n        friend constexpr bool operator ==(ModInt lhs,\
    \ ModInt rhs) noexcept {\n            return lhs.value == rhs.value;\n       \
    \ }\n\n        friend constexpr bool operator !=(ModInt lhs, ModInt rhs) noexcept\
    \ {\n            return lhs.value != rhs.value;\n        }\n\n        template<class\
    \ Scanner>\n        void scan(Scanner& scanner) {\n            std::int_fast64_t\
    \ value;\n            scanner.scan(value);\n            value = floor_mod(value,\
    \ _mod);\n        }\n\n        template<class Printer>\n        void print(Printer&\
    \ printer) const {\n            printer.print(value);\n        }\n    };\n\n \
    \   template<KYOPRO_BASE_UINT _mod>\n    struct Hash<ModInt<_mod>> {\n       \
    \ using value_type = ModInt<_mod>;\n        constexpr std::size_t operator ()(ModInt<_mod>\
    \ a) const noexcept {\n            return static_cast<std::size_t>(a);\n     \
    \   }\n    };\n} // namespace kyopro\n#line 7 \"structure/FenwickTree.hpp\"\n\n\
    namespace kyopro {\n    template<class T, class Op = Add<T>, class Container =\
    \ std::vector<T>>\n    struct FenwickTree {\n        using value_type = T;\n \
    \       using size_type = KYOPRO_BASE_UINT;\n        using reference = T&;\n \
    \       using const_reference = const T&;\n        using operator_type = Op;\n\
    \        using container_type = Container;\n\n    private:\n        [[no_unique_address]]\
    \ Op op;\n        Container tree;\n\n    public:\n        FenwickTree() noexcept\
    \ = default;\n        FenwickTree(KYOPRO_BASE_UINT n) noexcept: tree(n, op.id())\
    \ {}\n        template<class C, std::enable_if_t<std::is_same_v<Container, std::decay_t<C>>>>\n\
    \        FenwickTree(C&& tree): tree(std::forward<C>(tree)) {}\n\n        KYOPRO_BASE_UINT\
    \ size() noexcept {\n            return tree.size();\n        }\n\n        void\
    \ apply(int p, const T& x) {\n            ++p;\n            while (p <= (int)size())\
    \ {\n                tree[p - 1] = op(tree[p - 1], x);\n                p += p\
    \ & -p;\n            }\n        }\n\n        T prod(int r) const {\n         \
    \   T s = op.id();\n            while (r > 0) {\n                s = op(s, tree[r\
    \ - 1]);\n                r -= r & -r;\n            }\n            return s;\n\
    \        }\n        T prod(int l, int r) const {\n            return op(prod(r),\
    \ op.inverse(prod(l)));\n        }\n\n        T all_prod() {\n            return\
    \ prod(tree.size());\n        }\n\n        T get(int p) {\n            return\
    \ op(prod(p + 1), op.inverse(prod(p)));\n        }\n\n        void set(int p,\
    \ const T& x) { apply(p, op(x, op.inverse(get(p)))); }\n    };\n} // namespace\
    \ kyopro\n#line 9 \"structure/UnionFind.hpp\"\n\nnamespace kyopro {\n    template<class\
    \ Container = std::vector<int>>\n    struct UnionFind {\n        using value_type\
    \ = iterable_value_t<Container>;\n        using container_type = Container;\n\n\
    \    private:\n        Container par;\n\n    public:\n        UnionFind() noexcept\
    \ = default;\n        UnionFind(KYOPRO_BASE_UINT n) noexcept: par(n, -1) {}\n\
    \        template<class C, std::enable_if_t<std::is_same_v<Container, std::decay_t<C>>>>\n\
    \        UnionFind(C&& par): par(std::forward<C>(par)) {}\n\n        void resize(KYOPRO_BASE_UINT\
    \ x) { par.resize(x, -1); }\n        void assign(KYOPRO_BASE_UINT x) { par.assign(x,\
    \ -1); }\n        void reset() { std::fill(std::begin(par), std::end(par), -1);\
    \ }\n\n        KYOPRO_BASE_UINT size() const noexcept {\n            return par.size();\n\
    \        }\n\n        KYOPRO_BASE_INT find(int x) {\n            int p = x;\n\
    \            while (par[p] >= 0) p = par[p];\n            while (x != p) {\n \
    \               int tmp = x;\n                x = par[x];\n                par[tmp]\
    \ = p;\n            }\n            return p;\n        }\n\n        bool merge(int\
    \ x, int y) {\n            x = find(x), y = find(y);\n            if (x == y)\
    \ return false;\n            if (par[x] > par[y]) {\n                int tmp =\
    \ x;\n                x = y;\n                y = tmp;\n            }\n      \
    \      par[x] += par[y];\n            par[y] = x;\n            return true;\n\
    \        }\n\n        bool same(int x, int y) {\n            return find(x) ==\
    \ find(y);\n        }\n\n        KYOPRO_BASE_INT group_size(int x) {\n       \
    \     return -par[find(x)];\n        }\n\n        std::vector<int> group_members(int\
    \ x) {\n            x = find(x);\n            std::vector<int> a;\n          \
    \  for (int i = 0; i < (int)(size()); ++i) if (find(i) == x) a.emplace_back(i);\n\
    \            return a;\n        }\n\n        template<class Vector = std::vector<KYOPRO_BASE_INT>>\n\
    \        Vector roots() const {\n            Vector a;\n            for (int i\
    \ = 0; i < (int)(size()); ++i) if (par[i] < 0) a.emplace_back(i);\n          \
    \  return a;\n        }\n\n        KYOPRO_BASE_INT group_count() const {\n   \
    \         KYOPRO_BASE_INT cnt = 0;\n            for (int i = 0; i < (int)(size());\
    \ ++i) if (par[i] < 0) ++cnt;\n            return cnt;\n        }\n\n        template<class\
    \ Map = std::unordered_map<KYOPRO_BASE_INT, std::vector<KYOPRO_BASE_INT>>>\n \
    \       Map all_group_members() {\n            Map group_members;\n          \
    \  for (int member = 0; member < (int)(size()); ++member) group_members[find(member)].emplace_back(member);\n\
    \            return group_members;\n        }\n    };\n} // namespace kyopro\n\
    #line 2 \"system/in.hpp\"\n#include <unistd.h>\n#line 4 \"system/in.hpp\"\n#include\
    \ <bitset>\n#line 7 \"system/in.hpp\"\n#include <cstdio>\n#include <string>\n\
    #line 15 \"system/in.hpp\"\n\nnamespace kyopro {\n    template<std::size_t _buf_size\
    \ = KYOPRO_BUFFER_SIZE>\n    struct Reader {\n        static constexpr KYOPRO_BASE_UINT\
    \ buf_size = _buf_size;\n\n    private:\n        int fd, idx;\n        std::array<char,\
    \ buf_size> buffer;\n\n    public:\n        Reader() {\n            read(fd, buffer.begin(),\
    \ buf_size);\n        }\n        Reader(int fd): fd(fd), idx(0), buffer() {\n\
    \            read(fd, buffer.begin(), buf_size);\n        }\n        Reader(FILE*\
    \ fp): fd(fileno(fp)), idx(0), buffer() {\n            read(fd, buffer.begin(),\
    \ buf_size);\n        }\n\n        struct iterator {\n        private:\n     \
    \       Reader& reader;\n\n        public:\n            using difference_type\
    \ = void;\n            using value_type = void;\n            using pointer = void;\n\
    \            using reference = void;\n            using iterator_category = std::input_iterator_tag;\n\
    \n            iterator() noexcept = default;\n            iterator(Reader& reader)\
    \ noexcept: reader(reader) {}\n\n            iterator& operator ++() {\n     \
    \           ++reader.idx;\n                if (reader.idx == buf_size) {\n   \
    \             read(reader.fd, reader.buffer.begin(), buf_size);\n            \
    \    reader.idx = 0;\n                }\n                return *this;\n     \
    \       }\n\n            iterator operator ++(int) {\n                iterator\
    \ before = *this;\n                operator ++();\n                return before;\n\
    \            }\n\n            char& operator *() const {\n                return\
    \ reader.buffer[reader.idx];\n            }\n        };\n\n        iterator begin()\
    \ noexcept {\n            return iterator(*this);\n        }\n    };\n\n    Reader\
    \ input(0);\n\n    template<class Iterator, std::size_t _decimal_precision = KYOPRO_DECIMAL_PRECISION>\n\
    \    struct Scanner {\n        using iterator_type = Iterator;\n        static\
    \ constexpr KYOPRO_BASE_UINT decimal_precision = _decimal_precision;\n\n    private:\n\
    \        template<class, class = void>\n        struct has_scan: std::false_type\
    \ {};\n        template<class T>\n        struct has_scan<T, std::void_t<decltype(std::declval<T>().scan(std::declval<Scanner&>()))>>:\
    \ std::true_type {};\n\n    public:\n        Iterator itr;\n\n        Scanner()\
    \ noexcept = default;\n        Scanner(Iterator itr) noexcept: itr(itr) {}\n\n\
    \        void discard_space() {\n            while (('\\t' <= *itr && *itr <=\
    \ '\\r') || *itr == ' ') ++itr;\n        }\n\n        void scan(char& a) {\n \
    \           discard_space();\n            a = *itr;\n            ++itr;\n    \
    \    }\n        void scan(bool& a) {\n            discard_space();\n         \
    \   a = *itr != '0';\n        }\n        void scan(std::string& a) {\n       \
    \     discard_space();\n            while ((*itr < '\\t' || '\\r' < *itr) && *itr\
    \ != ' ') {\n                a += *itr;\n                ++itr;\n            }\n\
    \        }\n        template<std::size_t len>\n        void scan(std::bitset<len>&\
    \ a) {\n            discard_space();\n            for (int i = len - 1; i >= 0;\
    \ ++i) {\n                a[i] = *itr != '0';\n                ++itr;\n      \
    \      }\n        }\n        template<class T, std::enable_if_t<std::is_arithmetic_v<T>\
    \ && !has_scan<T>::value>* = nullptr>\n        void scan(T& a) {\n           \
    \ discard_space();\n            bool sgn = false;\n            if constexpr (!std::is_unsigned_v<T>)\
    \ if (*itr == '-') {\n                sgn = true;\n                ++itr;\n  \
    \          }\n            a = 0;\n            for (; '0' <= *itr && *itr <= '9';\
    \ ++itr) a = a * 10 + *itr - '0';\n            if (*itr == '.') {\n          \
    \      ++itr;\n                if constexpr (std::is_floating_point_v<T>) {\n\
    \                constexpr std::uint_fast64_t power_decimal_precision = power(10ULL,\
    \ decimal_precision);\n                T d = 0;\n                std::uint_fast64_t\
    \ i = 1;\n                for (; '0' <= *itr && *itr <= '9' && i < power_decimal_precision;\
    \ i *= 10) {\n                    d = d * 10 + *itr - '0';\n                 \
    \   ++itr;\n                }\n                a += d / i;\n                }\n\
    \                while ('0' <= *itr && *itr <= '9') ++itr;\n            }\n  \
    \          if constexpr (!std::is_unsigned_v<T>) if (sgn) a = -a;\n        }\n\
    \        template<KYOPRO_BASE_UINT i = 0, class T, std::enable_if_t<is_agg_v<T>\
    \ && !has_scan<T>::value>* = nullptr>\n        void scan(T& a) {\n           \
    \ if constexpr (i < std::tuple_size_v<T>) {\n                scan(std::get<i>(a));\n\
    \                scan<i + 1>(a);\n            }\n        }\n        template<class\
    \ T, std::enable_if_t<is_iterable_v<T> && !has_scan<T>::value>* = nullptr>\n \
    \       void scan(T& a) {\n            for (auto&& i: a) scan(i);\n        }\n\
    \        template<class T, std::enable_if_t<has_scan<T>::value>* = nullptr>\n\
    \        void scan(T& a) {\n            a.scan(*this);\n        }\n\n        void\
    \ operator ()() {}\n        template<class Head, class... Args>\n        void\
    \ operator ()(Head& head, Args&... args) {\n            scan(head);\n        \
    \    operator ()(args...);\n        }\n    };\n\n    Scanner<Reader<>::iterator>\
    \ scan(input.begin());\n} // namespace kyopro\n#line 6 \"system/out.hpp\"\n#include\
    \ <cmath>\n#line 17 \"system/out.hpp\"\n\nnamespace kyopro {\n    template<std::size_t\
    \ _buf_size = KYOPRO_BUFFER_SIZE>\n    struct Writer {\n        static constexpr\
    \ KYOPRO_BASE_UINT buf_size = _buf_size;\n\n    private:\n        int fd, idx;\n\
    \        std::array<char, buf_size> buffer;\n\n    public:\n        Writer() noexcept\
    \ = default;\n        Writer(int fd) noexcept: fd(fd), idx(0), buffer() {}\n \
    \       Writer(FILE* fp) noexcept: fd(fileno(fp)), idx(0), buffer() {}\n\n   \
    \     ~Writer() {\n            write(fd, buffer.begin(), idx);\n        }\n\n\
    \        struct iterator {\n        private:\n            Writer& writer;\n\n\
    \        public:\n            using difference_type = void;\n            using\
    \ value_type = void;\n            using pointer = void;\n            using reference\
    \ = void;\n            using iterator_category = std::output_iterator_tag;\n\n\
    \            iterator() noexcept = default;\n            iterator(Writer& writer)\
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
    \ _decimal_precision = KYOPRO_DECIMAL_PRECISION>\n    struct Printer {\n     \
    \   using iterator_type = Iterator;\n        static constexpr bool sep = _sep,\
    \ end_line = _end_line, sep_line = _sep_line, debug = _debug, comment = _comment,\
    \ flush = _flush;\n        static constexpr KYOPRO_BASE_UINT decimal_precision\
    \ = _decimal_precision;\n\n    private:\n        template<class, class = void>\n\
    \        struct has_print: std::false_type {};\n        template<class T>\n  \
    \      struct has_print<T, std::void_t<decltype(std::declval<T>().print(std::declval<Printer&>()))>>:\
    \ std::true_type {};\n\n    public:\n\n        template<class, class = void>\n\
    \        struct max_rank {\n            static constexpr std::size_t value = 0;\n\
    \        };\n        template<class T>\n        struct max_rank<T, std::enable_if_t<is_agg_v<T>>>\
    \ {\n            template<std::size_t... idx>\n            static constexpr bool\
    \ get_value_rank(std::index_sequence<idx...>) {\n                return std::max({max_rank<aggregate_element_t<idx,\
    \ T>>::value...});\n            }\n            static constexpr std::size_t value\
    \ = get_value_rank(std::make_index_sequence<aggregate_size_v<T>>()) + 1;\n   \
    \     };\n        template<class T>\n        struct max_rank<T, std::enable_if_t<is_iterable_v<T>>>\
    \ {\n            static constexpr std::size_t value = max_rank<iterable_value_t<T>>::value\
    \ + 1;\n        };\n\n        template<class T>\n        static constexpr KYOPRO_BASE_UINT\
    \ max_rank_v = max_rank<T>::value;\n\n        Iterator itr;\n\n        Printer()\
    \ noexcept = default;\n        Printer(Iterator itr) noexcept: itr(itr) {}\n\n\
    \        void print_char(char c) {\n            *itr = c;\n            ++itr;\n\
    \        }\n\n        template<std::size_t rank>\n        void print_sep() {\n\
    \            if constexpr (sep) {\n                if constexpr (debug) print_char(',');\n\
    \                if constexpr (sep_line && rank >= 2) {\n                print_char('\\\
    n');\n                if constexpr (comment) {\n                    print_char('#');\n\
    \                    print_char(' ');\n                }\n                } else\
    \ print_char(' ');\n            }\n        }\n\n        void print(char a) {\n\
    \            if constexpr (debug) print_char('\\'');\n            print_char(a);\n\
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
    \            }\n        }\n        template<KYOPRO_BASE_UINT i = 0, class T, std::enable_if_t<is_agg_v<T>\
    \ && !has_print<T>::value>* = nullptr>\n        void print(const T& a) {\n   \
    \         if constexpr (debug && i == 0) print_char('{');\n            if constexpr\
    \ (aggregate_size_v<T> != 0) print(access<i>(a));\n            if constexpr (i\
    \ + 1 < aggregate_size_v<T>) {\n                print_sep<max_rank_v<T>>();\n\
    \                print<i + 1>(a);\n            } else if constexpr (debug) print_char('}');\n\
    \        }\n        template<class T, std::enable_if_t<is_iterable_v<T> && !has_print<T>::value>*\
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
    \ eprintln(error.begin());\n} // namespace kyopro\n#line 9 \"all/all.hpp\"\n"
  code: '#pragma once

    #include "../algorithm/all.hpp"

    #include "../function/all.hpp"

    #include "../iterator/all.hpp"

    #include "../math/all.hpp"

    #include "../meta/all.hpp"

    #include "../structure/all.hpp"

    #include "../system/all.hpp"'
  dependsOn:
  - algorithm/all.hpp
  - algorithm/bit.hpp
  - meta/settings.hpp
  - algorithm/algorithm.hpp
  - function/compare.hpp
  - function/identity.hpp
  - meta/trait.hpp
  - algorithm/Hash.hpp
  - meta/aggregate.hpp
  - function/all.hpp
  - function/monoid.hpp
  - meta/constant.hpp
  - math/power.hpp
  - function/RecursiveLambda.hpp
  - iterator/all.hpp
  - iterator/imap.hpp
  - iterator/iterator_base.hpp
  - math/all.hpp
  - math/div.hpp
  - math/divisors.hpp
  - math/DynamicModInt.hpp
  - math/Montgomery.hpp
  - math/euler_phi.hpp
  - math/factorize.hpp
  - math/is_prime.hpp
  - math/mod.hpp
  - math/ModInt.hpp
  - meta/all.hpp
  - structure/all.hpp
  - structure/FenwickTree.hpp
  - structure/UnionFind.hpp
  - system/all.hpp
  - system/in.hpp
  - system/out.hpp
  isVerificationFile: false
  path: all/all.hpp
  requiredBy:
  - all.hpp
  timestamp: '2022-07-28 17:52:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: all/all.hpp
layout: document
redirect_from:
- /library/all/all.hpp
- /library/all/all.hpp.html
title: all/all.hpp
---
