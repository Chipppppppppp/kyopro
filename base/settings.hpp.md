---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  - icon: ':warning:'
    path: base/all.hpp
    title: base/all.hpp
  - icon: ':heavy_check_mark:'
    path: base/constant.hpp
    title: base/constant.hpp
  - icon: ':heavy_check_mark:'
    path: base/monoid.hpp
    title: base/monoid.hpp
  - icon: ':heavy_check_mark:'
    path: structure/FenwickTree.hpp
    title: structure/FenwickTree.hpp
  - icon: ':heavy_check_mark:'
    path: structure/FenwickTree.hpp
    title: structure/FenwickTree.hpp
  - icon: ':heavy_check_mark:'
    path: structure/UnionFind.hpp
    title: structure/UnionFind.hpp
  - icon: ':warning:'
    path: structure/all.hpp
    title: structure/all.hpp
  - icon: ':warning:'
    path: structure/all.hpp
    title: structure/all.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: yosupo/FenwickTree.test.cpp
    title: yosupo/FenwickTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: yosupo/FenwickTree.test.cpp
    title: yosupo/FenwickTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: yosupo/UnionFind.test.cpp
    title: yosupo/UnionFind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: '#line 1 "base/settings.hpp"

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
  code: '#include <cstdint>

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
  - structure/FenwickTree.hpp
  - structure/UnionFind.hpp
  - structure/all.hpp
  - structure/all.hpp
  - all.hpp
  - all.hpp
  - base/constant.hpp
  - base/all.hpp
  - base/monoid.hpp
  timestamp: '2022-01-04 18:22:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - yosupo/UnionFind.test.cpp
  - yosupo/FenwickTree.test.cpp
  - yosupo/FenwickTree.test.cpp
documentation_of: base/settings.hpp
layout: document
redirect_from:
- /library/base/settings.hpp
- /library/base/settings.hpp.html
title: base/settings.hpp
---
