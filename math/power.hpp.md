---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
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
    path: function/all.hpp
    title: function/all.hpp
  - icon: ':heavy_check_mark:'
    path: function/monoid.hpp
    title: function/monoid.hpp
  - icon: ':heavy_check_mark:'
    path: math/DynamicModInt.hpp
    title: math/DynamicModInt.hpp
  - icon: ':warning:'
    path: math/ModInt.hpp
    title: math/ModInt.hpp
  - icon: ':warning:'
    path: math/all.hpp
    title: math/all.hpp
  - icon: ':heavy_check_mark:'
    path: math/factorize.hpp
    title: math/factorize.hpp
  - icon: ':heavy_check_mark:'
    path: math/is_prime.hpp
    title: math/is_prime.hpp
  - icon: ':warning:'
    path: meta/all.hpp
    title: meta/all.hpp
  - icon: ':heavy_check_mark:'
    path: meta/constant.hpp
    title: meta/constant.hpp
  - icon: ':heavy_check_mark:'
    path: structure/FenwickTree.hpp
    title: structure/FenwickTree.hpp
  - icon: ':warning:'
    path: structure/all.hpp
    title: structure/all.hpp
  - icon: ':heavy_check_mark:'
    path: system/all.hpp
    title: system/all.hpp
  - icon: ':heavy_check_mark:'
    path: system/in.hpp
    title: system/in.hpp
  - icon: ':warning:'
    path: template/alias.hpp
    title: template/alias.hpp
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
  bundledCode: "#line 2 \"meta/settings.hpp\"\n#include <cstdint>\n\n#ifndef KYOPRO_BASE_INT\n\
    #define KYOPRO_BASE_INT std::int64_t\n#endif\n\n#ifndef KYOPRO_BASE_UINT\n#define\
    \ KYOPRO_BASE_UINT std::uint64_t\n#endif\n\n#ifndef KYOPRO_BASE_FLOAT\n#define\
    \ KYOPRO_BASE_FLOAT double\n#endif\n\n#ifndef KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD\
    \ static_cast<KYOPRO_BASE_UINT>(998244353)\n#endif\n\n#ifndef KYOPRO_DECIMAL_PRECISION\n\
    #define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n#endif\n\n\
    #ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 3 \"math/power.hpp\"\n\nnamespace kyopro {\n  inline constexpr struct\
    \ {\n    template<class T>\n    constexpr T operator ()(T a, KYOPRO_BASE_UINT\
    \ n, T init = 1) const noexcept {\n      while (n > 0) {\n        if (n & 1) init\
    \ *= a;\n        a *= a;\n        n >>= 1;\n      }\n      return init;\n    }\n\
    \  } power;\n}\n"
  code: "#pragma once\n#include \"../meta/settings.hpp\"\n\nnamespace kyopro {\n \
    \ inline constexpr struct {\n    template<class T>\n    constexpr T operator ()(T\
    \ a, KYOPRO_BASE_UINT n, T init = 1) const noexcept {\n      while (n > 0) {\n\
    \        if (n & 1) init *= a;\n        a *= a;\n        n >>= 1;\n      }\n \
    \     return init;\n    }\n  } power;\n}"
  dependsOn:
  - meta/settings.hpp
  isVerificationFile: false
  path: math/power.hpp
  requiredBy:
  - meta/constant.hpp
  - meta/all.hpp
  - all/all.hpp
  - math/DynamicModInt.hpp
  - math/is_prime.hpp
  - math/ModInt.hpp
  - math/factorize.hpp
  - math/all.hpp
  - structure/FenwickTree.hpp
  - structure/all.hpp
  - function/monoid.hpp
  - function/all.hpp
  - all.hpp
  - template/alias.hpp
  - template/all.hpp
  - template/macro.hpp
  - system/in.hpp
  - system/all.hpp
  timestamp: '2022-07-07 16:11:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/PrimeNumber.test.cpp
  - verify/yosupo/many_aplusb.test.cpp
  - verify/yosupo/point_add_range_sum.test.cpp
  - verify/yosupo/unionfind.test.cpp
  - verify/yosupo/factorize.test.cpp
documentation_of: math/power.hpp
layout: document
redirect_from:
- /library/math/power.hpp
- /library/math/power.hpp.html
title: math/power.hpp
---
