---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: structure/FenwickTree.hpp
    title: structure/FenwickTree.hpp
  - icon: ':heavy_check_mark:'
    path: structure/UnionFind.hpp
    title: structure/UnionFind.hpp
  _extendedVerifiedWith:
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
  bundledCode: '#line 1 "base/types.hpp"

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

    '
  dependsOn: []
  isVerificationFile: false
  path: base/types.hpp
  requiredBy:
  - structure/FenwickTree.hpp
  - structure/UnionFind.hpp
  timestamp: '2022-01-03 23:22:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - yosupo/UnionFind.test.cpp
  - yosupo/FenwickTree.test.cpp
documentation_of: base/types.hpp
layout: document
redirect_from:
- /library/base/types.hpp
- /library/base/types.hpp.html
title: base/types.hpp
---
