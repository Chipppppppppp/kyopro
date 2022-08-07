---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/power.hpp
    title: math/power.hpp
  - icon: ':question:'
    path: meta/settings.hpp
    title: meta/settings.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: function/all.hpp
    title: function/all.hpp
  - icon: ':x:'
    path: function/monoid.hpp
    title: function/monoid.hpp
  - icon: ':x:'
    path: math/DynamicModInt.hpp
    title: math/DynamicModInt.hpp
  - icon: ':warning:'
    path: math/ModInt.hpp
    title: math/ModInt.hpp
  - icon: ':warning:'
    path: math/all.hpp
    title: math/all.hpp
  - icon: ':x:'
    path: math/factorize.hpp
    title: math/factorize.hpp
  - icon: ':x:'
    path: math/is_prime.hpp
    title: math/is_prime.hpp
  - icon: ':warning:'
    path: meta/all.hpp
    title: meta/all.hpp
  - icon: ':x:'
    path: structure/FenwickTree.hpp
    title: structure/FenwickTree.hpp
  - icon: ':warning:'
    path: structure/all.hpp
    title: structure/all.hpp
  - icon: ':warning:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':warning:'
    path: template/all.hpp
    title: template/all.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/aoj/PrimeNumber.test.cpp
    title: verify/aoj/PrimeNumber.test.cpp
  - icon: ':x:'
    path: verify/yosupo/factorize.test.cpp
    title: verify/yosupo/factorize.test.cpp
  - icon: ':x:'
    path: verify/yosupo/point_add_range_sum.test.cpp
    title: verify/yosupo/point_add_range_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"meta/constant.hpp\"\n#include <array>\n#include <limits>\n\
    #include <utility>\n#line 2 \"math/power.hpp\"\n#include <cstddef>\n\nnamespace\
    \ kyopro {\n    inline constexpr struct {\n        template<class T>\n       \
    \ constexpr T operator ()(T a, std::uint_fast64_t n, T init = 1) const noexcept\
    \ {\n            while (n > 0) {\n                if (n & 1) init *= a;\n    \
    \            a *= a;\n                n >>= 1;\n            }\n            return\
    \ init;\n        }\n    } power;\n} // namespace kyopro\n#line 2 \"meta/settings.hpp\"\
    \n#include <cstdint>\n\n#ifndef KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT std::int64_t\n\
    #endif\n\n#ifndef KYOPRO_BASE_UINT\n#define KYOPRO_BASE_UINT std::uint64_t\n#endif\n\
    \n#ifndef KYOPRO_BASE_FLOAT\n#define KYOPRO_BASE_FLOAT double\n#endif\n\n#ifndef\
    \ KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD static_cast<KYOPRO_BASE_UINT>(998244353)\n\
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
    \ pi = PI<KYOPRO_BASE_FLOAT>;\n} // namespace kyopro\n"
  code: "#pragma once\n#include <array>\n#include <limits>\n#include <utility>\n#include\
    \ \"../math/power.hpp\"\n#include \"settings.hpp\"\n\nnamespace kyopro {\n   \
    \ template<class T>\n    inline constexpr T MOD = KYOPRO_DEFAULT_MOD;\n    inline\
    \ constexpr KYOPRO_BASE_INT mod = MOD<KYOPRO_BASE_INT>;\n\n    template<class\
    \ T>\n    inline constexpr T INF = std::numeric_limits<T>::max() / KYOPRO_INF_DIV;\n\
    \    inline constexpr KYOPRO_BASE_INT inf = INF<KYOPRO_BASE_INT>;\n\n    template<class\
    \ T, KYOPRO_BASE_UINT decimal_precision = KYOPRO_DECIMAL_PRECISION>\n    inline\
    \ constexpr KYOPRO_BASE_FLOAT EPS = static_cast<T>(1) / power(10ULL, decimal_precision);\n\
    \    inline constexpr KYOPRO_BASE_FLOAT eps = EPS<KYOPRO_BASE_FLOAT>;\n\n    template<class\
    \ T>\n    inline constexpr T PI = 3.14159265358979323846;\n    inline constexpr\
    \ KYOPRO_BASE_FLOAT pi = PI<KYOPRO_BASE_FLOAT>;\n} // namespace kyopro"
  dependsOn:
  - math/power.hpp
  - meta/settings.hpp
  isVerificationFile: false
  path: meta/constant.hpp
  requiredBy:
  - math/ModInt.hpp
  - math/all.hpp
  - math/factorize.hpp
  - math/is_prime.hpp
  - math/DynamicModInt.hpp
  - structure/all.hpp
  - structure/FenwickTree.hpp
  - function/all.hpp
  - function/monoid.hpp
  - template/all.hpp
  - template/alias.hpp
  - meta/all.hpp
  timestamp: '2022-08-08 07:54:18+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/aoj/PrimeNumber.test.cpp
  - verify/yosupo/point_add_range_sum.test.cpp
  - verify/yosupo/factorize.test.cpp
documentation_of: meta/constant.hpp
layout: document
redirect_from:
- /library/meta/constant.hpp
- /library/meta/constant.hpp.html
title: meta/constant.hpp
---
