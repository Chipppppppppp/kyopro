---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: algorithm/Hash.hpp
    title: algorithm/Hash.hpp
  - icon: ':warning:'
    path: algorithm/all.hpp
    title: algorithm/all.hpp
  - icon: ':x:'
    path: algorithm/bit.hpp
    title: algorithm/bit.hpp
  - icon: ':warning:'
    path: algorithm/compress.hpp
    title: algorithm/compress.hpp
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
  - icon: ':x:'
    path: math/DynamicModInt.hpp
    title: math/DynamicModInt.hpp
  - icon: ':warning:'
    path: math/ModInt.hpp
    title: math/ModInt.hpp
  - icon: ':x:'
    path: math/Montgomery.hpp
    title: math/Montgomery.hpp
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
  - icon: ':question:'
    path: math/power.hpp
    title: math/power.hpp
  - icon: ':question:'
    path: meta/aggregate.hpp
    title: meta/aggregate.hpp
  - icon: ':warning:'
    path: meta/all.hpp
    title: meta/all.hpp
  - icon: ':question:'
    path: meta/constant.hpp
    title: meta/constant.hpp
  - icon: ':question:'
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
  - icon: ':question:'
    path: system/all.hpp
    title: system/all.hpp
  - icon: ':question:'
    path: system/in.hpp
    title: system/in.hpp
  - icon: ':question:'
    path: system/out.hpp
    title: system/out.hpp
  - icon: ':warning:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':warning:'
    path: template/all.hpp
    title: template/all.hpp
  - icon: ':warning:'
    path: template/constant.hpp
    title: template/constant.hpp
  - icon: ':warning:'
    path: template/len.hpp
    title: template/len.hpp
  - icon: ':warning:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':warning:'
    path: template/make_array.hpp
    title: template/make_array.hpp
  - icon: ':warning:'
    path: template/make_vector.hpp
    title: template/make_vector.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/aoj/PrimeNumber.test.cpp
    title: verify/aoj/PrimeNumber.test.cpp
  - icon: ':x:'
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
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: '#line 2 "meta/settings.hpp"

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

    #define KYOPRO_DEFAULT_MOD static_cast<KYOPRO_BASE_UINT>(998244353)

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

    #define KYOPRO_DEFAULT_MOD static_cast<KYOPRO_BASE_UINT>(998244353)

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
  path: meta/settings.hpp
  requiredBy:
  - all.hpp
  - function/all.hpp
  - function/monoid.hpp
  - math/all.hpp
  - math/factorize.hpp
  - math/euler_phi.hpp
  - math/Montgomery.hpp
  - math/divisors.hpp
  - math/power.hpp
  - math/ModInt.hpp
  - math/is_prime.hpp
  - math/DynamicModInt.hpp
  - algorithm/all.hpp
  - algorithm/bit.hpp
  - algorithm/Hash.hpp
  - algorithm/compress.hpp
  - all/all.hpp
  - template/all.hpp
  - template/len.hpp
  - template/alias.hpp
  - template/macro.hpp
  - template/make_vector.hpp
  - template/constant.hpp
  - template/make_array.hpp
  - meta/all.hpp
  - meta/aggregate.hpp
  - meta/trait.hpp
  - meta/constant.hpp
  - structure/all.hpp
  - structure/FenwickTree.hpp
  - structure/UnionFind.hpp
  - system/all.hpp
  - system/out.hpp
  - system/in.hpp
  timestamp: '2022-03-19 00:51:47+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/yosupo/many_aplusb.test.cpp
  - verify/yosupo/unionfind.test.cpp
  - verify/yosupo/point_add_range_sum.test.cpp
  - verify/yosupo/factorize.test.cpp
  - verify/aoj/PrimeNumber.test.cpp
documentation_of: meta/settings.hpp
layout: document
redirect_from:
- /library/meta/settings.hpp
- /library/meta/settings.hpp.html
title: meta/settings.hpp
---
