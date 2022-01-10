---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  - icon: ':warning:'
    path: base/Hash.hpp
    title: base/Hash.hpp
  - icon: ':warning:'
    path: base/all.hpp
    title: base/all.hpp
  - icon: ':x:'
    path: base/constant.hpp
    title: base/constant.hpp
  - icon: ':warning:'
    path: math/ModInt.hpp
    title: math/ModInt.hpp
  - icon: ':warning:'
    path: math/all.hpp
    title: math/all.hpp
  - icon: ':warning:'
    path: math/divisors.hpp
    title: math/divisors.hpp
  - icon: ':warning:'
    path: math/factorize.hpp
    title: math/factorize.hpp
  - icon: ':x:'
    path: math/monoid.hpp
    title: math/monoid.hpp
  - icon: ':x:'
    path: math/power.hpp
    title: math/power.hpp
  - icon: ':x:'
    path: structure/FenwickTree.hpp
    title: structure/FenwickTree.hpp
  - icon: ':heavy_check_mark:'
    path: structure/UnionFind.hpp
    title: structure/UnionFind.hpp
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
    path: yosupo/FenwickTree.test.cpp
    title: yosupo/FenwickTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: yosupo/UnionFind.test.cpp
    title: yosupo/UnionFind.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: '#line 2 "base/settings.hpp"

    #include <cstdint>

    #ifndef KYOPRO_BASE_INT

    #define KYOPRO_BASE_INT std::int64_t

    #endif

    #ifndef KYOPRO_BASE_UINT

    #define KYOPRO_BASE_UINT std::size_t

    #endif

    #ifndef KYOPRO_BASE_FLOAT

    #define KYOPRO_BASE_FLOAT double

    #endif

    #ifndef KYOPRO_DEFAULT_MOD

    #define KYOPRO_DEFAULT_MOD 1000000007

    #endif

    #ifndef KYOPRO_DECIMAL_PRECISION

    #define KYOPRO_DECIMAL_PRECISION 12

    #endif

    #ifndef KYOPRO_INF_DIV

    #define KYOPRO_INF_DIV 3

    #endif

    '
  code: '#pragma once

    #include <cstdint>

    #ifndef KYOPRO_BASE_INT

    #define KYOPRO_BASE_INT std::int64_t

    #endif

    #ifndef KYOPRO_BASE_UINT

    #define KYOPRO_BASE_UINT std::size_t

    #endif

    #ifndef KYOPRO_BASE_FLOAT

    #define KYOPRO_BASE_FLOAT double

    #endif

    #ifndef KYOPRO_DEFAULT_MOD

    #define KYOPRO_DEFAULT_MOD 1000000007

    #endif

    #ifndef KYOPRO_DECIMAL_PRECISION

    #define KYOPRO_DECIMAL_PRECISION 12

    #endif

    #ifndef KYOPRO_INF_DIV

    #define KYOPRO_INF_DIV 3

    #endif'
  dependsOn: []
  isVerificationFile: false
  path: base/settings.hpp
  requiredBy:
  - structure/FenwickTree.hpp
  - structure/UnionFind.hpp
  - structure/all.hpp
  - math/power.hpp
  - math/factorize.hpp
  - math/ModInt.hpp
  - math/divisors.hpp
  - math/all.hpp
  - math/monoid.hpp
  - template/alias.hpp
  - template/all.hpp
  - all.hpp
  - base/Hash.hpp
  - base/constant.hpp
  - base/all.hpp
  timestamp: '2022-01-10 19:46:56+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - yosupo/UnionFind.test.cpp
  - yosupo/FenwickTree.test.cpp
documentation_of: base/settings.hpp
layout: document
redirect_from:
- /library/base/settings.hpp
- /library/base/settings.hpp.html
title: base/settings.hpp
---
