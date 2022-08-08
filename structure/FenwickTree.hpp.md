---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: function/monoid.hpp
    title: function/monoid.hpp
  - icon: ':question:'
    path: math/power.hpp
    title: math/power.hpp
  - icon: ':question:'
    path: meta/constant.hpp
    title: meta/constant.hpp
  - icon: ':question:'
    path: meta/settings.hpp
    title: meta/settings.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  - icon: ':warning:'
    path: all/all.hpp
    title: all/all.hpp
  - icon: ':warning:'
    path: structure/all.hpp
    title: structure/all.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo/point_add_range_sum.test.cpp
    title: verify/yosupo/point_add_range_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/FenwickTree.hpp\"\n#include <cstddef>\n#include\
    \ <utility>\n#include <vector>\n#line 2 \"function/monoid.hpp\"\n#include <limits>\n\
    #include <type_traits>\n#line 2 \"meta/constant.hpp\"\n#include <array>\n#line\
    \ 3 \"math/power.hpp\"\n\nnamespace kyopro {\n    inline constexpr struct {\n\
    \        template<class T>\n        constexpr T operator ()(T a, std::uint_fast64_t\
    \ n, T init = 1) const noexcept {\n            while (n > 0) {\n             \
    \   if (n & 1) init *= a;\n                a *= a;\n                n >>= 1;\n\
    \            }\n            return init;\n        }\n    } power;\n} // namespace\
    \ kyopro\n#line 2 \"meta/settings.hpp\"\n#include <cstdint>\n\n#ifndef KYOPRO_BASE_INT\n\
    #define KYOPRO_BASE_INT std::int64_t\n#endif\n\n#ifndef KYOPRO_BASE_UINT\n#define\
    \ KYOPRO_BASE_UINT std::uint64_t\n#endif\n\n#ifndef KYOPRO_BASE_FLOAT\n#define\
    \ KYOPRO_BASE_FLOAT double\n#endif\n\n#ifndef KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD\
    \ static_cast<KYOPRO_BASE_UINT>(998244353)\n#endif\n\n#ifndef KYOPRO_DECIMAL_PRECISION\n\
    #define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n#endif\n\n\
    #ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
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
    \        }\n    };\n} // namespace kyopro\n"
  code: "#pragma once\n#include <cstddef>\n#include <utility>\n#include <vector>\n\
    #include \"../function/monoid.hpp\"\n\nnamespace kyopro {\n    template<class\
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
    \        }\n    };\n} // namespace kyopro"
  dependsOn:
  - function/monoid.hpp
  - meta/constant.hpp
  - math/power.hpp
  - meta/settings.hpp
  isVerificationFile: false
  path: structure/FenwickTree.hpp
  requiredBy:
  - all/all.hpp
  - structure/all.hpp
  - all.hpp
  timestamp: '2022-08-08 14:06:09+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo/point_add_range_sum.test.cpp
documentation_of: structure/FenwickTree.hpp
layout: document
redirect_from:
- /library/structure/FenwickTree.hpp
- /library/structure/FenwickTree.hpp.html
title: structure/FenwickTree.hpp
---
