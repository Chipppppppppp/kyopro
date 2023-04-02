---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: kyopro/algorithm/algorithm.hpp
    title: kyopro/algorithm/algorithm.hpp
  - icon: ':heavy_check_mark:'
    path: kyopro/algorithm/bit.hpp
    title: kyopro/algorithm/bit.hpp
  - icon: ':warning:'
    path: kyopro/algorithm/count_all.hpp
    title: kyopro/algorithm/count_all.hpp
  - icon: ':warning:'
    path: kyopro/all/all.hpp
    title: kyopro/all/all.hpp
  - icon: ':heavy_check_mark:'
    path: kyopro/data_structure/FenwickTree.hpp
    title: kyopro/data_structure/FenwickTree.hpp
  - icon: ':heavy_check_mark:'
    path: kyopro/data_structure/UnionFind.hpp
    title: kyopro/data_structure/UnionFind.hpp
  - icon: ':warning:'
    path: kyopro/data_structure/data_structure.hpp
    title: kyopro/data_structure/data_structure.hpp
  - icon: ':warning:'
    path: kyopro/data_structure/structure.hpp
    title: kyopro/data_structure/structure.hpp
  - icon: ':warning:'
    path: kyopro/function/function.hpp
    title: kyopro/function/function.hpp
  - icon: ':heavy_check_mark:'
    path: kyopro/function/monoid.hpp
    title: kyopro/function/monoid.hpp
  - icon: ':heavy_check_mark:'
    path: kyopro/io/in.hpp
    title: kyopro/io/in.hpp
  - icon: ':heavy_check_mark:'
    path: kyopro/io/io.hpp
    title: kyopro/io/io.hpp
  - icon: ':heavy_check_mark:'
    path: kyopro/io/out.hpp
    title: kyopro/io/out.hpp
  - icon: ':warning:'
    path: kyopro/math/Barrett.hpp
    title: kyopro/math/Barrett.hpp
  - icon: ':warning:'
    path: kyopro/math/BinomMod.hpp
    title: kyopro/math/BinomMod.hpp
  - icon: ':heavy_check_mark:'
    path: kyopro/math/DynamicModInt.hpp
    title: kyopro/math/DynamicModInt.hpp
  - icon: ':warning:'
    path: kyopro/math/ModInt.hpp
    title: kyopro/math/ModInt.hpp
  - icon: ':heavy_check_mark:'
    path: kyopro/math/Montgomery.hpp
    title: kyopro/math/Montgomery.hpp
  - icon: ':warning:'
    path: kyopro/math/divisors.hpp
    title: kyopro/math/divisors.hpp
  - icon: ':warning:'
    path: kyopro/math/euler_phi.hpp
    title: kyopro/math/euler_phi.hpp
  - icon: ':heavy_check_mark:'
    path: kyopro/math/factorize.hpp
    title: kyopro/math/factorize.hpp
  - icon: ':heavy_check_mark:'
    path: kyopro/math/is_prime.hpp
    title: kyopro/math/is_prime.hpp
  - icon: ':warning:'
    path: kyopro/math/math.hpp
    title: kyopro/math/math.hpp
  - icon: ':heavy_check_mark:'
    path: kyopro/math/power.hpp
    title: kyopro/math/power.hpp
  - icon: ':heavy_check_mark:'
    path: kyopro/meta/constant.hpp
    title: kyopro/meta/constant.hpp
  - icon: ':warning:'
    path: kyopro/meta/meta.hpp
    title: kyopro/meta/meta.hpp
  - icon: ':warning:'
    path: kyopro/template/alias.hpp
    title: kyopro/template/alias.hpp
  - icon: ':warning:'
    path: kyopro/template/constant.hpp
    title: kyopro/template/constant.hpp
  - icon: ':warning:'
    path: kyopro/template/io_macro.hpp
    title: kyopro/template/io_macro.hpp
  - icon: ':warning:'
    path: kyopro/template/len.hpp
    title: kyopro/template/len.hpp
  - icon: ':warning:'
    path: kyopro/template/macro.hpp
    title: kyopro/template/macro.hpp
  - icon: ':warning:'
    path: kyopro/template/named_tuple_macro.hpp
    title: kyopro/template/named_tuple_macro.hpp
  - icon: ':warning:'
    path: kyopro/template/template.hpp
    title: kyopro/template/template.hpp
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
  bundledCode: "#line 2 \"kyopro/meta/setting.hpp\"\n#include <cstdint>\r\n\r\n#ifndef\
    \ KYOPRO_BASE_INT\r\n// \u57FA\u672C\u7B26\u53F7\u4ED8\u304D\u6574\u6570\u578B\
    \r\n#define KYOPRO_BASE_INT std::int64_t\r\n#endif\r\n\r\n#ifndef KYOPRO_BASE_UINT\r\
    \n// \u57FA\u672C\u7B26\u53F7\u306A\u3057\u6574\u6570\u578B\r\n#define KYOPRO_BASE_UINT\
    \ std::uint64_t\r\n#endif\r\n\r\n#ifndef KYOPRO_BASE_FLOAT\r\n// \u57FA\u672C\u6D6E\
    \u52D5\u5C0F\u6570\u70B9\u6570\u578B\r\n#define KYOPRO_BASE_FLOAT double\r\n#endif\r\
    \n\r\n#ifndef KYOPRO_DEFAULT_MOD\r\n// \u554F\u984C\u3067\u8A2D\u5B9A\u3055\u308C\
    \u305Fmod\r\n#define KYOPRO_DEFAULT_MOD (static_cast<KYOPRO_BASE_UINT>(998244353))\r\
    \n#endif\r\n\r\n#ifndef KYOPRO_DECIMAL_PRECISION\r\n// \u5C0F\u6570\u7CBE\u5EA6\
    (\u6841)\r\n#define KYOPRO_DECIMAL_PRECISION (static_cast<KYOPRO_BASE_UINT>(12))\r\
    \n#endif\r\n\r\n#ifndef KYOPRO_INF_DIV\r\n// \u7121\u9650\u5927\u3092\u8868\u3059\
    \u6574\u6570\u304C\u6700\u5927\u5024\u306E\u4F55\u5206\u306E\u4E00\u304B\u3092\
    \u8868\u3059\r\n#define KYOPRO_INF_DIV (static_cast<KYOPRO_BASE_UINT>(3))\r\n\
    #endif\r\n\r\n#ifndef KYOPRO_BUFFER_SIZE\r\n// \u30C7\u30D5\u30A9\u30EB\u30C8\u306E\
    \u30D0\u30C3\u30D5\u30A1\u30B5\u30A4\u30BA\r\n#define KYOPRO_BUFFER_SIZE (static_cast<KYOPRO_BASE_UINT>(2048))\r\
    \n#endif\r\n"
  code: "#pragma once\r\n#include <cstdint>\r\n\r\n#ifndef KYOPRO_BASE_INT\r\n// \u57FA\
    \u672C\u7B26\u53F7\u4ED8\u304D\u6574\u6570\u578B\r\n#define KYOPRO_BASE_INT std::int64_t\r\
    \n#endif\r\n\r\n#ifndef KYOPRO_BASE_UINT\r\n// \u57FA\u672C\u7B26\u53F7\u306A\u3057\
    \u6574\u6570\u578B\r\n#define KYOPRO_BASE_UINT std::uint64_t\r\n#endif\r\n\r\n\
    #ifndef KYOPRO_BASE_FLOAT\r\n// \u57FA\u672C\u6D6E\u52D5\u5C0F\u6570\u70B9\u6570\
    \u578B\r\n#define KYOPRO_BASE_FLOAT double\r\n#endif\r\n\r\n#ifndef KYOPRO_DEFAULT_MOD\r\
    \n// \u554F\u984C\u3067\u8A2D\u5B9A\u3055\u308C\u305Fmod\r\n#define KYOPRO_DEFAULT_MOD\
    \ (static_cast<KYOPRO_BASE_UINT>(998244353))\r\n#endif\r\n\r\n#ifndef KYOPRO_DECIMAL_PRECISION\r\
    \n// \u5C0F\u6570\u7CBE\u5EA6(\u6841)\r\n#define KYOPRO_DECIMAL_PRECISION (static_cast<KYOPRO_BASE_UINT>(12))\r\
    \n#endif\r\n\r\n#ifndef KYOPRO_INF_DIV\r\n// \u7121\u9650\u5927\u3092\u8868\u3059\
    \u6574\u6570\u304C\u6700\u5927\u5024\u306E\u4F55\u5206\u306E\u4E00\u304B\u3092\
    \u8868\u3059\r\n#define KYOPRO_INF_DIV (static_cast<KYOPRO_BASE_UINT>(3))\r\n\
    #endif\r\n\r\n#ifndef KYOPRO_BUFFER_SIZE\r\n// \u30C7\u30D5\u30A9\u30EB\u30C8\u306E\
    \u30D0\u30C3\u30D5\u30A1\u30B5\u30A4\u30BA\r\n#define KYOPRO_BUFFER_SIZE (static_cast<KYOPRO_BASE_UINT>(2048))\r\
    \n#endif\r\n"
  dependsOn: []
  isVerificationFile: false
  path: kyopro/meta/setting.hpp
  requiredBy:
  - kyopro/io/in.hpp
  - kyopro/io/out.hpp
  - kyopro/io/io.hpp
  - kyopro/all/all.hpp
  - kyopro/function/monoid.hpp
  - kyopro/function/function.hpp
  - kyopro/meta/constant.hpp
  - kyopro/meta/meta.hpp
  - kyopro/math/is_prime.hpp
  - kyopro/math/euler_phi.hpp
  - kyopro/math/factorize.hpp
  - kyopro/math/ModInt.hpp
  - kyopro/math/math.hpp
  - kyopro/math/BinomMod.hpp
  - kyopro/math/divisors.hpp
  - kyopro/math/power.hpp
  - kyopro/math/DynamicModInt.hpp
  - kyopro/math/Barrett.hpp
  - kyopro/math/Montgomery.hpp
  - kyopro/algorithm/algorithm.hpp
  - kyopro/algorithm/bit.hpp
  - kyopro/algorithm/count_all.hpp
  - kyopro/template/template.hpp
  - kyopro/template/len.hpp
  - kyopro/template/constant.hpp
  - kyopro/template/macro.hpp
  - kyopro/template/io_macro.hpp
  - kyopro/template/named_tuple_macro.hpp
  - kyopro/template/alias.hpp
  - kyopro/data_structure/structure.hpp
  - kyopro/data_structure/UnionFind.hpp
  - kyopro/data_structure/data_structure.hpp
  - kyopro/data_structure/FenwickTree.hpp
  timestamp: '2023-04-02 21:40:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/many_aplusb.test.cpp
  - verify/yosupo/factorize.test.cpp
  - verify/yosupo/point_add_range_sum.test.cpp
  - verify/yosupo/unionfind.test.cpp
  - verify/aoj/PrimeNumber.test.cpp
documentation_of: kyopro/meta/setting.hpp
layout: document
redirect_from:
- /library/kyopro/meta/setting.hpp
- /library/kyopro/meta/setting.hpp.html
title: kyopro/meta/setting.hpp
---
