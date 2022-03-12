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
  - icon: ':x:'
    path: base/in.hpp
    title: base/in.hpp
  - icon: ':x:'
    path: base/io.hpp
    title: base/io.hpp
  - icon: ':x:'
    path: base/out.hpp
    title: base/out.hpp
  - icon: ':warning:'
    path: math/DynamicModInt.hpp
    title: math/DynamicModInt.hpp
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
    path: math/euler_phi.hpp
    title: math/euler_phi.hpp
  - icon: ':x:'
    path: math/factorize.hpp
    title: math/factorize.hpp
  - icon: ':x:'
    path: math/is_prime.hpp
    title: math/is_prime.hpp
  - icon: ':warning:'
    path: math/modpow.hpp
    title: math/modpow.hpp
  - icon: ':x:'
    path: math/monoid.hpp
    title: math/monoid.hpp
  - icon: ':x:'
    path: math/power.hpp
    title: math/power.hpp
  - icon: ':x:'
    path: structure/FenwickTree.hpp
    title: structure/FenwickTree.hpp
  - icon: ':x:'
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
    path: yosupo/Factorize.test.cpp
    title: yosupo/Factorize.test.cpp
  - icon: ':x:'
    path: yosupo/UnionFind.test.cpp
    title: yosupo/UnionFind.test.cpp
  - icon: ':x:'
    path: yosupo/many_aplusb.test.cpp
    title: yosupo/many_aplusb.test.cpp
  - icon: ':x:'
    path: yosupo/point_add_range_sum.test.cpp
    title: yosupo/point_add_range_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: '#line 2 "base/settings.hpp"

    #include <cstdint>


    #ifndef KYOPRO_BASE_INT

    #define KYOPRO_BASE_INT std::int64_t

    #endif


    #ifndef KYOPRO_BASE_UINT

    #define KYOPRO_BASE_UINT std::uint64_t

    #endif


    #ifndef KYOPRO_BASE_FLOAT

    #define KYOPRO_BASE_FLOAT double

    #endif


    #ifndef KYOPRO_DEFAULT_MOD

    #define KYOPRO_DEFAULT_MOD static_cast<KYOPRO_BASE_UINT>(1000000007)

    #endif


    #ifndef KYOPRO_DECIMAL_PRECISION

    #define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)

    #endif


    #ifndef KYOPRO_INF_DIV

    #define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)

    #endif


    #ifndef KYOPRO_BUFFER_SIZE

    #define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)

    #endif

    '
  code: '#pragma once

    #include <cstdint>


    #ifndef KYOPRO_BASE_INT

    #define KYOPRO_BASE_INT std::int64_t

    #endif


    #ifndef KYOPRO_BASE_UINT

    #define KYOPRO_BASE_UINT std::uint64_t

    #endif


    #ifndef KYOPRO_BASE_FLOAT

    #define KYOPRO_BASE_FLOAT double

    #endif


    #ifndef KYOPRO_DEFAULT_MOD

    #define KYOPRO_DEFAULT_MOD static_cast<KYOPRO_BASE_UINT>(1000000007)

    #endif


    #ifndef KYOPRO_DECIMAL_PRECISION

    #define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)

    #endif


    #ifndef KYOPRO_INF_DIV

    #define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)

    #endif


    #ifndef KYOPRO_BUFFER_SIZE

    #define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)

    #endif'
  dependsOn: []
  isVerificationFile: false
  path: base/settings.hpp
  requiredBy:
  - math/factorize.hpp
  - math/ModInt.hpp
  - math/divisors.hpp
  - math/DynamicModInt.hpp
  - math/is_prime.hpp
  - math/monoid.hpp
  - math/euler_phi.hpp
  - math/all.hpp
  - math/power.hpp
  - math/modpow.hpp
  - structure/UnionFind.hpp
  - structure/FenwickTree.hpp
  - structure/all.hpp
  - template/all.hpp
  - template/alias.hpp
  - base/in.hpp
  - base/constant.hpp
  - base/out.hpp
  - base/io.hpp
  - base/all.hpp
  - base/Hash.hpp
  - all.hpp
  timestamp: '2022-03-11 22:32:55+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - yosupo/Factorize.test.cpp
  - yosupo/UnionFind.test.cpp
  - yosupo/point_add_range_sum.test.cpp
  - yosupo/many_aplusb.test.cpp
documentation_of: base/settings.hpp
layout: document
redirect_from:
- /library/base/settings.hpp
- /library/base/settings.hpp.html
title: base/settings.hpp
---
