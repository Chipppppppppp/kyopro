---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: kpr/algorithm/algorithm.hpp
    title: kpr/algorithm/algorithm.hpp
  - icon: ':heavy_check_mark:'
    path: kpr/algorithm/bit.hpp
    title: kpr/algorithm/bit.hpp
  - icon: ':warning:'
    path: kpr/algorithm/count_all.hpp
    title: kpr/algorithm/count_all.hpp
  - icon: ':warning:'
    path: kpr/all.hpp
    title: kpr/all.hpp
  - icon: ':warning:'
    path: kpr/all/all.hpp
    title: kpr/all/all.hpp
  - icon: ':heavy_check_mark:'
    path: kpr/data_structure/FenwickTree.hpp
    title: kpr/data_structure/FenwickTree.hpp
  - icon: ':heavy_check_mark:'
    path: kpr/data_structure/SegmentTree.hpp
    title: kpr/data_structure/SegmentTree.hpp
  - icon: ':heavy_check_mark:'
    path: kpr/data_structure/UnionFind.hpp
    title: kpr/data_structure/UnionFind.hpp
  - icon: ':heavy_check_mark:'
    path: kpr/data_structure/WeightedUnionFind.hpp
    title: kpr/data_structure/WeightedUnionFind.hpp
  - icon: ':warning:'
    path: kpr/data_structure/data_structure.hpp
    title: kpr/data_structure/data_structure.hpp
  - icon: ':warning:'
    path: kpr/function/function.hpp
    title: kpr/function/function.hpp
  - icon: ':heavy_check_mark:'
    path: kpr/function/monoid.hpp
    title: kpr/function/monoid.hpp
  - icon: ':heavy_check_mark:'
    path: kpr/io/in.hpp
    title: kpr/io/in.hpp
  - icon: ':heavy_check_mark:'
    path: kpr/io/io.hpp
    title: kpr/io/io.hpp
  - icon: ':heavy_check_mark:'
    path: kpr/io/out.hpp
    title: kpr/io/out.hpp
  - icon: ':warning:'
    path: kpr/math/Barrett.hpp
    title: kpr/math/Barrett.hpp
  - icon: ':warning:'
    path: kpr/math/BinomMod.hpp
    title: kpr/math/BinomMod.hpp
  - icon: ':heavy_check_mark:'
    path: kpr/math/DynamicModInt.hpp
    title: kpr/math/DynamicModInt.hpp
  - icon: ':heavy_check_mark:'
    path: kpr/math/ModInt.hpp
    title: kpr/math/ModInt.hpp
  - icon: ':heavy_check_mark:'
    path: kpr/math/Montgomery.hpp
    title: kpr/math/Montgomery.hpp
  - icon: ':warning:'
    path: kpr/math/divisors.hpp
    title: kpr/math/divisors.hpp
  - icon: ':warning:'
    path: kpr/math/euler_phi.hpp
    title: kpr/math/euler_phi.hpp
  - icon: ':heavy_check_mark:'
    path: kpr/math/factorize.hpp
    title: kpr/math/factorize.hpp
  - icon: ':heavy_check_mark:'
    path: kpr/math/is_prime.hpp
    title: kpr/math/is_prime.hpp
  - icon: ':warning:'
    path: kpr/math/math.hpp
    title: kpr/math/math.hpp
  - icon: ':heavy_check_mark:'
    path: kpr/math/power.hpp
    title: kpr/math/power.hpp
  - icon: ':heavy_check_mark:'
    path: kpr/meta/constant.hpp
    title: kpr/meta/constant.hpp
  - icon: ':warning:'
    path: kpr/meta/meta.hpp
    title: kpr/meta/meta.hpp
  - icon: ':warning:'
    path: kpr/template/alias.hpp
    title: kpr/template/alias.hpp
  - icon: ':warning:'
    path: kpr/template/constant.hpp
    title: kpr/template/constant.hpp
  - icon: ':warning:'
    path: kpr/template/io_macro.hpp
    title: kpr/template/io_macro.hpp
  - icon: ':warning:'
    path: kpr/template/len.hpp
    title: kpr/template/len.hpp
  - icon: ':warning:'
    path: kpr/template/macro.hpp
    title: kpr/template/macro.hpp
  - icon: ':warning:'
    path: kpr/template/named_tuple_macro.hpp
    title: kpr/template/named_tuple_macro.hpp
  - icon: ':warning:'
    path: kpr/template/template.hpp
    title: kpr/template/template.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/WeightedUnionFind.test.cpp
    title: verify/aoj/WeightedUnionFind.test.cpp
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
    path: verify/yosupo/point_set_range_composite.test.cpp
    title: verify/yosupo/point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/unionfind.test.cpp
    title: verify/yosupo/unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"kpr/meta/setting.hpp\"\n#include <cstdint>\r\n\r\n#ifndef\
    \ KYOPRO_BASE_INT\r\n// \u57FA\u672C\u7B26\u53F7\u4ED8\u304D\u6574\u6570\u578B\
    \r\n#define KYOPRO_BASE_INT std::int64_t\r\n#endif\r\n\r\n#ifndef KYOPRO_BASE_UINT\r\
    \n// \u57FA\u672C\u7B26\u53F7\u306A\u3057\u6574\u6570\u578B\r\n#define KYOPRO_BASE_UINT\
    \ std::uint64_t\r\n#endif\r\n\r\n#ifndef KYOPRO_BASE_FLOAT\r\n// \u57FA\u672C\u6D6E\
    \u52D5\u5C0F\u6570\u70B9\u6570\u578B\r\n#define KYOPRO_BASE_FLOAT double\r\n#endif\r\
    \n\r\n#ifndef KYOPRO_LL\r\n// ll\r\n#define KYOPRO_LL long long\r\n#endif\r\n\r\
    \n#ifndef KYOPRO_LF\r\n// lf\r\n#define KYOPRO_LF double\r\n#endif\r\n\r\n#ifndef\
    \ KYOPRO_MINT\r\n// mint\r\n#define KYOPRO_MINT kpr::ModInt<mod>\r\n#endif\r\n\
    \r\n#ifndef KYOPRO_DEFAULT_MOD\r\n// \u554F\u984C\u3067\u8A2D\u5B9A\u3055\u308C\
    \u305Fmod\r\n#define KYOPRO_DEFAULT_MOD (static_cast<KYOPRO_BASE_UINT>(998244353))\r\
    \n#endif\r\n\r\n#ifndef KYOPRO_DECIMAL_PRECISION\r\n// \u5C0F\u6570\u7CBE\u5EA6\
    (\u6841)\r\n#define KYOPRO_DECIMAL_PRECISION (static_cast<KYOPRO_BASE_UINT>(12))\r\
    \n#endif\r\n\r\n#ifndef KYOPRO_INF_DIV\r\n// \u7121\u9650\u5927\u3092\u8868\u3059\
    \u6574\u6570\u304C\u6700\u5927\u5024\u306E\u4F55\u5206\u306E\u4E00\u304B\u3092\
    \u8868\u3059\r\n#define KYOPRO_INF_DIV (static_cast<KYOPRO_BASE_UINT>(3))\r\n\
    #endif\r\n\r\n#ifndef KYOPRO_BUFFER_SIZE\r\n// \u30C7\u30D5\u30A9\u30EB\u30C8\u306E\
    \u30D0\u30C3\u30D5\u30A1\u30B5\u30A4\u30BA\r\n#define KYOPRO_BUFFER_SIZE (static_cast<KYOPRO_BASE_UINT>(2048))\r\
    \n#endif\r\n\r\n#ifndef KYOPRO_BINOM_MOD_MAX\r\n// \u30C7\u30D5\u30A9\u30EB\u30C8\
    \u306EBinomMod\u306E\u8A08\u7B97\u4E0A\u9650\r\n#define KYOPRO_BINOM_MOD_MAX (static_cast<KYOPRO_BASE_UINT>(1000000))\r\
    \n#endif\r\n"
  code: "#pragma once\r\n#include <cstdint>\r\n\r\n#ifndef KYOPRO_BASE_INT\r\n// \u57FA\
    \u672C\u7B26\u53F7\u4ED8\u304D\u6574\u6570\u578B\r\n#define KYOPRO_BASE_INT std::int64_t\r\
    \n#endif\r\n\r\n#ifndef KYOPRO_BASE_UINT\r\n// \u57FA\u672C\u7B26\u53F7\u306A\u3057\
    \u6574\u6570\u578B\r\n#define KYOPRO_BASE_UINT std::uint64_t\r\n#endif\r\n\r\n\
    #ifndef KYOPRO_BASE_FLOAT\r\n// \u57FA\u672C\u6D6E\u52D5\u5C0F\u6570\u70B9\u6570\
    \u578B\r\n#define KYOPRO_BASE_FLOAT double\r\n#endif\r\n\r\n#ifndef KYOPRO_LL\r\
    \n// ll\r\n#define KYOPRO_LL long long\r\n#endif\r\n\r\n#ifndef KYOPRO_LF\r\n\
    // lf\r\n#define KYOPRO_LF double\r\n#endif\r\n\r\n#ifndef KYOPRO_MINT\r\n// mint\r\
    \n#define KYOPRO_MINT kpr::ModInt<mod>\r\n#endif\r\n\r\n#ifndef KYOPRO_DEFAULT_MOD\r\
    \n// \u554F\u984C\u3067\u8A2D\u5B9A\u3055\u308C\u305Fmod\r\n#define KYOPRO_DEFAULT_MOD\
    \ (static_cast<KYOPRO_BASE_UINT>(998244353))\r\n#endif\r\n\r\n#ifndef KYOPRO_DECIMAL_PRECISION\r\
    \n// \u5C0F\u6570\u7CBE\u5EA6(\u6841)\r\n#define KYOPRO_DECIMAL_PRECISION (static_cast<KYOPRO_BASE_UINT>(12))\r\
    \n#endif\r\n\r\n#ifndef KYOPRO_INF_DIV\r\n// \u7121\u9650\u5927\u3092\u8868\u3059\
    \u6574\u6570\u304C\u6700\u5927\u5024\u306E\u4F55\u5206\u306E\u4E00\u304B\u3092\
    \u8868\u3059\r\n#define KYOPRO_INF_DIV (static_cast<KYOPRO_BASE_UINT>(3))\r\n\
    #endif\r\n\r\n#ifndef KYOPRO_BUFFER_SIZE\r\n// \u30C7\u30D5\u30A9\u30EB\u30C8\u306E\
    \u30D0\u30C3\u30D5\u30A1\u30B5\u30A4\u30BA\r\n#define KYOPRO_BUFFER_SIZE (static_cast<KYOPRO_BASE_UINT>(2048))\r\
    \n#endif\r\n\r\n#ifndef KYOPRO_BINOM_MOD_MAX\r\n// \u30C7\u30D5\u30A9\u30EB\u30C8\
    \u306EBinomMod\u306E\u8A08\u7B97\u4E0A\u9650\r\n#define KYOPRO_BINOM_MOD_MAX (static_cast<KYOPRO_BASE_UINT>(1000000))\r\
    \n#endif\r\n"
  dependsOn: []
  isVerificationFile: false
  path: kpr/meta/setting.hpp
  requiredBy:
  - kpr/algorithm/count_all.hpp
  - kpr/algorithm/bit.hpp
  - kpr/algorithm/algorithm.hpp
  - kpr/io/out.hpp
  - kpr/io/in.hpp
  - kpr/io/io.hpp
  - kpr/meta/constant.hpp
  - kpr/meta/meta.hpp
  - kpr/function/monoid.hpp
  - kpr/function/function.hpp
  - kpr/math/euler_phi.hpp
  - kpr/math/factorize.hpp
  - kpr/math/Barrett.hpp
  - kpr/math/BinomMod.hpp
  - kpr/math/ModInt.hpp
  - kpr/math/divisors.hpp
  - kpr/math/power.hpp
  - kpr/math/DynamicModInt.hpp
  - kpr/math/math.hpp
  - kpr/math/is_prime.hpp
  - kpr/math/Montgomery.hpp
  - kpr/template/constant.hpp
  - kpr/template/alias.hpp
  - kpr/template/template.hpp
  - kpr/template/io_macro.hpp
  - kpr/template/len.hpp
  - kpr/template/macro.hpp
  - kpr/template/named_tuple_macro.hpp
  - kpr/all/all.hpp
  - kpr/all.hpp
  - kpr/data_structure/WeightedUnionFind.hpp
  - kpr/data_structure/data_structure.hpp
  - kpr/data_structure/FenwickTree.hpp
  - kpr/data_structure/SegmentTree.hpp
  - kpr/data_structure/UnionFind.hpp
  timestamp: '2023-05-30 09:27:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/WeightedUnionFind.test.cpp
  - verify/yosupo/point_add_range_sum.test.cpp
  - verify/yosupo/many_aplusb.test.cpp
  - verify/yosupo/factorize.test.cpp
  - verify/yosupo/unionfind.test.cpp
  - verify/yosupo/point_set_range_composite.test.cpp
documentation_of: kpr/meta/setting.hpp
layout: document
redirect_from:
- /library/kpr/meta/setting.hpp
- /library/kpr/meta/setting.hpp.html
title: kpr/meta/setting.hpp
---
