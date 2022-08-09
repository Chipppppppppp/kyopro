---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: function/monoid.hpp
    title: function/monoid.hpp
  - icon: ':heavy_check_mark:'
    path: math/power.hpp
    title: math/power.hpp
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
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  - icon: ':warning:'
    path: all/all.hpp
    title: all/all.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/FenwickTree.hpp\"\n#include <cstddef>\n#include\
    \ <utility>\n#include <vector>\n#line 2 \"function/monoid.hpp\"\n#include <limits>\n\
    #include <type_traits>\n#line 2 \"meta/constant.hpp\"\n#include <array>\n#line\
    \ 2 \"math/power.hpp\"\n#include <cstdint>\n\nnamespace kyopro {\n    inline constexpr\
    \ struct {\n        template<class T>\n        constexpr T operator ()(T a, std::uint_fast64_t\
    \ n, T init = 1) const noexcept {\n            while (n > 0) {\n             \
    \   if (n & 1) init *= a;\n                a *= a;\n                n >>= 1;\n\
    \            }\n            return init;\n        }\n    } power;\n} // namespace\
    \ kyopro\n#line 3 \"meta/settings.hpp\"\n\n#ifndef KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT\
    \ std::int64_t\n#endif\n\n#ifndef KYOPRO_BASE_UINT\n#define KYOPRO_BASE_UINT std::uint64_t\n\
    #endif\n\n#ifndef KYOPRO_BASE_FLOAT\n#define KYOPRO_BASE_FLOAT double\n#endif\n\
    \n#ifndef KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD static_cast<KYOPRO_BASE_UINT>(998244353)\n\
    #endif\n\n#ifndef KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n\
    #endif\n\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 7 \"meta/constant.hpp\"\n\nnamespace kyopro {\n    template<class\
    \ T>\n    inline constexpr T MOD = KYOPRO_DEFAULT_MOD;\n    inline constexpr KYOPRO_BASE_INT\
    \ mod = MOD<KYOPRO_BASE_INT>;\n\n    template<class T>\n    inline constexpr T\
    \ INF = std::numeric_limits<T>::max() / KYOPRO_INF_DIV;\n    inline constexpr\
    \ KYOPRO_BASE_INT inf = INF<KYOPRO_BASE_INT>;\n\n    template<class T, KYOPRO_BASE_UINT\
    \ decimal_precision = KYOPRO_DECIMAL_PRECISION>\n    inline constexpr KYOPRO_BASE_FLOAT\
    \ EPS = static_cast<T>(1) / power(10ULL, decimal_precision);\n    inline constexpr\
    \ KYOPRO_BASE_FLOAT eps = EPS<KYOPRO_BASE_FLOAT>;\n\n    template<class T>\n \
    \   inline constexpr T PI = 3.14159265358979323846;\n    inline constexpr KYOPRO_BASE_FLOAT\
    \ pi = PI<KYOPRO_BASE_FLOAT>;\n} // namespace kyopro\n#line 5 \"function/monoid.hpp\"\
    \n\nnamespace kyopro {\n    template<class T>\n    struct Add {\n        using\
    \ value_type = T;\n\n        constexpr T id() const noexcept {\n            return\
    \ T{};\n        }\n\n        constexpr T operator ()(const T& a, const T& b) const\
    \ noexcept {\n            return a + b;\n        }\n\n        constexpr T inverse(const\
    \ T& a) const noexcept {\n            return -a;\n        }\n    };\n\n    template<class\
    \ T>\n    struct Mul {\n        using value_type = T;\n\n        constexpr T id()\
    \ const noexcept {\n            return 1;\n        }\n\n        constexpr T operator\
    \ ()(const T& a, const T& b) const noexcept {\n            return a * b;\n   \
    \     }\n\n        constexpr T inverse(const T& a) const noexcept {\n        \
    \    return 1 / a;\n        }\n    };\n\n    template<class T>\n    struct Min\
    \ {\n        using value_type = T;\n\n        constexpr T id() const noexcept\
    \ {\n            return std::is_integral_v<T> ? INF<T> : std::numeric_limits<T>::infinity();\n\
    \        }\n\n        constexpr T operator ()(const T& a, const T& b) const noexcept\
    \ {\n            return a < b ? a : b;\n        }\n    };\n\n    template<class\
    \ T>\n    struct Max {\n        using value_type = T;\n\n        constexpr T id()\
    \ const noexcept {\n            return std::is_integral_v<T> ? std::is_signed_v<T>\
    \ ? -INF<T> : 0 : -std::numeric_limits<T>::infinity();\n        }\n\n        constexpr\
    \ T operator ()(const T& a, const T& b) const noexcept {\n            return a\
    \ > b ? a : b;\n        }\n    };\n\n    template<class, class = void>\n    struct\
    \ has_inverse: std::false_type {};\n    template<class T>\n    struct has_inverse<T,\
    \ std::void_t<decltype(&T::inverse)>>: std::true_type {};\n\n    template<class\
    \ T>\n    inline constexpr bool has_inverse_v = has_inverse<T>::value;\n} // namespace\
    \ kyopro\n#line 6 \"structure/FenwickTree.hpp\"\n\nnamespace kyopro {\n    template<class\
    \ T, class Op = Add<T>, class Container = std::vector<T>>\n    struct FenwickTree:\
    \ private Op {\n        using value_type = T;\n        using size_type = std::size_t;\n\
    \        using reference = T&;\n        using const_reference = const T&;\n  \
    \      using operator_type = Op;\n        using container_type = Container;\n\n\
    \    private:\n        Container tree;\n\n    public:\n        FenwickTree() noexcept\
    \ = default;\n        FenwickTree(std::size_t n) noexcept: tree(n, Op::id()) {}\n\
    \n        std::size_t size() noexcept {\n            return tree.size();\n   \
    \     }\n\n        void apply(int p, const T& x) {\n            ++p;\n       \
    \     while (p <= (int)size()) {\n                tree[p - 1] = Op::operator ()(tree[p\
    \ - 1], x);\n                p += p & -p;\n            }\n        }\n\n      \
    \  T prod(int r) const {\n            T s = Op::id();\n            while (r >\
    \ 0) {\n                s = Op::operator ()(s, tree[r - 1]);\n               \
    \ r -= r & -r;\n            }\n            return s;\n        }\n        T prod(int\
    \ l, int r) const {\n            static_assert(has_inverse_v<Op>, \"Operator doesn't\
    \ have an inverse\");\n            return Op::operator ()(prod(r), Op::inverse(prod(l)));\n\
    \        }\n\n        T all_prod() {\n            return prod(tree.size());\n\
    \        }\n\n        T get(int p) {\n            static_assert(has_inverse_v<Op>,\
    \ \"Operator doesn't have an inverse\");\n            return Op::operator ()(prod(p\
    \ + 1), Op::inverse(prod(p)));\n        }\n\n        void set(int p, const T&\
    \ x) {\n            static_assert(has_inverse_v<Op>, \"Operator doesn't have an\
    \ inverse\");\n            apply(p, Op::operator ()(x, Op::inverse(get(p))));\n\
    \        }\n    };\n} // namespace kyopro\n#line 2 \"structure/UnionFind.hpp\"\
    \n#include <algorithm>\n#line 4 \"structure/UnionFind.hpp\"\n#include <unordered_map>\n\
    #line 3 \"meta/trait.hpp\"\n#include <iterator>\n#include <queue>\n#line 6 \"\
    meta/trait.hpp\"\n#include <stack>\n#line 9 \"meta/trait.hpp\"\n\n#if defined(__STRICT_ANSI__)\
    \ && defined(__SIZEOF_INT128__)\ntemplate<>\nstruct std::is_integral<__int128_t>:\
    \ std::true_type {};\ntemplate<>\nstruct std::is_integral<__uint128_t>: std::true_type\
    \ {};\n#endif\n\n\nnamespace kyopro {\n    template<std::size_t size>\n    struct\
    \ int_least {\n    private:\n        static constexpr auto get_type() noexcept\
    \ {\n            static_assert(size <= 128, \"Integer size is too large\");\n\
    \            if constexpr (size <= 8) return std::int_least8_t{};\n          \
    \  else if constexpr (size <= 16) return std::int_least16_t{};\n            else\
    \ if constexpr (size <= 32) return std::int_least32_t{};\n            else if\
    \ constexpr (size <= 64) return std::int_least64_t{};\n            else return\
    \ __int128_t{};\n        }\n\n    public:\n        using type = decltype(get_type());\n\
    \    };\n\n    template<std::size_t size>\n    using int_least_t = typename int_least<size>::type;\n\
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
    } // namespace kyopro\n#line 9 \"structure/UnionFind.hpp\"\n\nnamespace kyopro\
    \ {\n    template<class Container = std::vector<int>>\n    struct UnionFind {\n\
    \        using value_type = range_value_t<Container>;\n        using container_type\
    \ = Container;\n\n    private:\n        Container par;\n\n    public:\n      \
    \  UnionFind() noexcept = default;\n        UnionFind(std::size_t n) noexcept:\
    \ par(n, -1) {}\n        template<class C, std::enable_if_t<std::is_same_v<Container,\
    \ std::decay_t<C>>>>\n        UnionFind(C&& par): par(std::forward<C>(par)) {}\n\
    \n        void resize(std::size_t x) { par.resize(x, -1); }\n        void assign(std::size_t\
    \ x) { par.assign(x, -1); }\n        void reset() { std::fill(std::begin(par),\
    \ std::end(par), -1); }\n\n        std::size_t size() const noexcept {\n     \
    \       return par.size();\n        }\n\n        KYOPRO_BASE_INT find(int x) {\n\
    \            int p = x;\n            while (par[p] >= 0) p = par[p];\n       \
    \     while (x != p) {\n                int tmp = x;\n                x = par[x];\n\
    \                par[tmp] = p;\n            }\n            return p;\n       \
    \ }\n\n        bool merge(int x, int y) {\n            x = find(x), y = find(y);\n\
    \            if (x == y) return false;\n            if (par[x] > par[y]) {\n \
    \               int tmp = x;\n                x = y;\n                y = tmp;\n\
    \            }\n            par[x] += par[y];\n            par[y] = x;\n     \
    \       return true;\n        }\n\n        bool same(int x, int y) {\n       \
    \     return find(x) == find(y);\n        }\n\n        KYOPRO_BASE_INT group_size(int\
    \ x) {\n            return -par[find(x)];\n        }\n\n        std::vector<int>\
    \ group_members(int x) {\n            x = find(x);\n            std::vector<int>\
    \ a;\n            for (int i = 0; i < (int)(size()); ++i) if (find(i) == x) a.emplace_back(i);\n\
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
    #line 4 \"structure/all.hpp\"\n"
  code: '#pragma once

    #include "FenwickTree.hpp"

    #include "UnionFind.hpp"'
  dependsOn:
  - structure/FenwickTree.hpp
  - function/monoid.hpp
  - meta/constant.hpp
  - math/power.hpp
  - meta/settings.hpp
  - structure/UnionFind.hpp
  - meta/trait.hpp
  isVerificationFile: false
  path: structure/all.hpp
  requiredBy:
  - all/all.hpp
  - all.hpp
  timestamp: '2022-08-09 17:24:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/all.hpp
layout: document
redirect_from:
- /library/structure/all.hpp
- /library/structure/all.hpp.html
title: structure/all.hpp
---
