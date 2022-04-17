---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: meta/settings.hpp
    title: meta/settings.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all/all.hpp
    title: all/all.hpp
  - icon: ':warning:'
    path: function/all.hpp
    title: function/all.hpp
  - icon: ':x:'
    path: function/monoid.hpp
    title: function/monoid.hpp
  - icon: ':question:'
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
  - icon: ':question:'
    path: math/is_prime.hpp
    title: math/is_prime.hpp
  - icon: ':warning:'
    path: meta/all.hpp
    title: meta/all.hpp
  - icon: ':question:'
    path: meta/constant.hpp
    title: meta/constant.hpp
  - icon: ':x:'
    path: structure/FenwickTree.hpp
    title: structure/FenwickTree.hpp
  - icon: ':warning:'
    path: structure/all.hpp
    title: structure/all.hpp
  - icon: ':question:'
    path: system/all.hpp
    title: system/all.hpp
  - icon: ':question:'
    path: system/in.hpp
    title: system/in.hpp
  - icon: ':warning:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':warning:'
    path: template/all.hpp
    title: template/all.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: aoj/PrimeNumber.test.cpp
    title: aoj/PrimeNumber.test.cpp
  - icon: ':x:'
    path: yosupo/UnionFind.test.cpp
    title: yosupo/UnionFind.test.cpp
  - icon: ':x:'
    path: yosupo/factorize.test.cpp
    title: yosupo/factorize.test.cpp
  - icon: ':x:'
    path: yosupo/many_aplusb.test.cpp
    title: yosupo/many_aplusb.test.cpp
  - icon: ':x:'
    path: yosupo/point_add_range_sum.test.cpp
    title: yosupo/point_add_range_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
    #endif\n#line 3 \"math/power.hpp\"\n\nnamespace kyopro {\n  template<class _typeT>\n\
    \  constexpr _typeT power(_typeT _a, KYOPRO_BASE_UINT _n, _typeT _init = 1) noexcept\
    \ {\n    while (_n > 0) {\n      if (_n & 1) _init *= _a;\n      _a *= _a;\n \
    \     _n >>= 1;\n    }\n    return _init;\n  }\n}\n"
  code: "#pragma once\n#include \"../meta/settings.hpp\"\n\nnamespace kyopro {\n \
    \ template<class _typeT>\n  constexpr _typeT power(_typeT _a, KYOPRO_BASE_UINT\
    \ _n, _typeT _init = 1) noexcept {\n    while (_n > 0) {\n      if (_n & 1) _init\
    \ *= _a;\n      _a *= _a;\n      _n >>= 1;\n    }\n    return _init;\n  }\n}"
  dependsOn:
  - meta/settings.hpp
  isVerificationFile: false
  path: math/power.hpp
  requiredBy:
  - math/DynamicModInt.hpp
  - math/factorize.hpp
  - math/is_prime.hpp
  - math/all.hpp
  - math/ModInt.hpp
  - system/all.hpp
  - system/in.hpp
  - meta/constant.hpp
  - meta/all.hpp
  - structure/FenwickTree.hpp
  - structure/all.hpp
  - function/monoid.hpp
  - function/all.hpp
  - template/all.hpp
  - template/alias.hpp
  - all/all.hpp
  timestamp: '2022-03-19 00:51:47+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - aoj/PrimeNumber.test.cpp
  - yosupo/many_aplusb.test.cpp
  - yosupo/UnionFind.test.cpp
  - yosupo/factorize.test.cpp
  - yosupo/point_add_range_sum.test.cpp
documentation_of: math/power.hpp
layout: document
redirect_from:
- /library/math/power.hpp
- /library/math/power.hpp.html
title: math/power.hpp
---
