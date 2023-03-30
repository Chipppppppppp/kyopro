---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/power.hpp
    title: math/power.hpp
  - icon: ':heavy_check_mark:'
    path: meta/setting.hpp
    title: meta/setting.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  - icon: ':warning:'
    path: all/all.hpp
    title: all/all.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/FenwickTree.hpp
    title: data_structure/FenwickTree.hpp
  - icon: ':warning:'
    path: data_structure/data_structure.hpp
    title: data_structure/data_structure.hpp
  - icon: ':warning:'
    path: data_structure/structure.hpp
    title: data_structure/structure.hpp
  - icon: ':warning:'
    path: function/function.hpp
    title: function/function.hpp
  - icon: ':heavy_check_mark:'
    path: function/monoid.hpp
    title: function/monoid.hpp
  - icon: ':warning:'
    path: math/BinomMod.hpp
    title: math/BinomMod.hpp
  - icon: ':heavy_check_mark:'
    path: math/DynamicModInt.hpp
    title: math/DynamicModInt.hpp
  - icon: ':warning:'
    path: math/ModInt.hpp
    title: math/ModInt.hpp
  - icon: ':heavy_check_mark:'
    path: math/factorize.hpp
    title: math/factorize.hpp
  - icon: ':heavy_check_mark:'
    path: math/is_prime.hpp
    title: math/is_prime.hpp
  - icon: ':warning:'
    path: math/math.hpp
    title: math/math.hpp
  - icon: ':warning:'
    path: meta/meta.hpp
    title: meta/meta.hpp
  - icon: ':warning:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':warning:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/PrimeNumber.test.cpp
    title: verify/aoj/PrimeNumber.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/factorize.test.cpp
    title: verify/yosupo/factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/point_add_range_sum.test.cpp
    title: verify/yosupo/point_add_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"meta/constant.hpp\"\n#include <limits>\r\n#line 2 \"math/power.hpp\"\
    \n#include <cstdint>\r\n\r\nnamespace kpr {\r\n    [[maybe_unused]] inline constexpr\
    \ struct {\r\n        template<class T>\r\n        constexpr T operator ()(T a,\
    \ std::uint_fast64_t n, T init = 1) const noexcept {\r\n            while (n >\
    \ 0) {\r\n                if (n & 1) init *= a;\r\n                a *= a;\r\n\
    \                n >>= 1;\r\n            }\r\n            return init;\r\n   \
    \     }\r\n    } power;\r\n} // namespace kpr\r\n#line 3 \"meta/setting.hpp\"\n\
    \r\n#ifndef KYOPRO_BASE_INT\r\n// \u57FA\u672C\u7B26\u53F7\u4ED8\u304D\u6574\u6570\
    \u578B\r\n#define KYOPRO_BASE_INT std::int64_t\r\n#endif\r\n\r\n#ifndef KYOPRO_BASE_UINT\r\
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
    \n#endif\r\n#line 5 \"meta/constant.hpp\"\n\r\nnamespace kpr {\r\n    // \u554F\
    \u984C\u3067\u8A2D\u5B9A\u3055\u308C\u305Fmod\r\n    template<class T>\r\n   \
    \ inline constexpr T MOD = KYOPRO_DEFAULT_MOD;\r\n    // \u554F\u984C\u3067\u8A2D\
    \u5B9A\u3055\u308C\u305Fmod\r\n    inline constexpr KYOPRO_BASE_INT mod = MOD<KYOPRO_BASE_INT>;\r\
    \n\r\n    // \u7121\u9650\u5927\u3092\u8868\u3059\u6574\u6570\r\n    template<class\
    \ T>\r\n    inline constexpr T INF = std::numeric_limits<T>::max() / KYOPRO_INF_DIV;\r\
    \n    // \u7121\u9650\u5927\u3092\u8868\u3059\u6574\u6570\r\n    inline constexpr\
    \ KYOPRO_BASE_INT inf = INF<KYOPRO_BASE_INT>;\r\n\r\n    // \u8A31\u5BB9\u3055\
    \u308C\u308B\u5C0F\u6570\u8AA4\u5DEE\r\n    template<class T, KYOPRO_BASE_UINT\
    \ decimal_precision = KYOPRO_DECIMAL_PRECISION>\r\n    inline constexpr KYOPRO_BASE_FLOAT\
    \ EPS = static_cast<T>(1) / power(10ULL, decimal_precision);\r\n    // \u8A31\u5BB9\
    \u3055\u308C\u308B\u5C0F\u6570\u8AA4\u5DEE\r\n    inline constexpr KYOPRO_BASE_FLOAT\
    \ eps = EPS<KYOPRO_BASE_FLOAT>;\r\n\r\n    // \u5186\u5468\u7387\r\n    template<class\
    \ T>\r\n    inline constexpr T PI = 3.14159265358979323846;\r\n    // \u5186\u5468\
    \u7387\r\n    inline constexpr KYOPRO_BASE_FLOAT pi = PI<KYOPRO_BASE_FLOAT>;\r\
    \n} // namespace kpr\r\n"
  code: "#pragma once\r\n#include <limits>\r\n#include \"../math/power.hpp\"\r\n#include\
    \ \"setting.hpp\"\r\n\r\nnamespace kpr {\r\n    // \u554F\u984C\u3067\u8A2D\u5B9A\
    \u3055\u308C\u305Fmod\r\n    template<class T>\r\n    inline constexpr T MOD =\
    \ KYOPRO_DEFAULT_MOD;\r\n    // \u554F\u984C\u3067\u8A2D\u5B9A\u3055\u308C\u305F\
    mod\r\n    inline constexpr KYOPRO_BASE_INT mod = MOD<KYOPRO_BASE_INT>;\r\n\r\n\
    \    // \u7121\u9650\u5927\u3092\u8868\u3059\u6574\u6570\r\n    template<class\
    \ T>\r\n    inline constexpr T INF = std::numeric_limits<T>::max() / KYOPRO_INF_DIV;\r\
    \n    // \u7121\u9650\u5927\u3092\u8868\u3059\u6574\u6570\r\n    inline constexpr\
    \ KYOPRO_BASE_INT inf = INF<KYOPRO_BASE_INT>;\r\n\r\n    // \u8A31\u5BB9\u3055\
    \u308C\u308B\u5C0F\u6570\u8AA4\u5DEE\r\n    template<class T, KYOPRO_BASE_UINT\
    \ decimal_precision = KYOPRO_DECIMAL_PRECISION>\r\n    inline constexpr KYOPRO_BASE_FLOAT\
    \ EPS = static_cast<T>(1) / power(10ULL, decimal_precision);\r\n    // \u8A31\u5BB9\
    \u3055\u308C\u308B\u5C0F\u6570\u8AA4\u5DEE\r\n    inline constexpr KYOPRO_BASE_FLOAT\
    \ eps = EPS<KYOPRO_BASE_FLOAT>;\r\n\r\n    // \u5186\u5468\u7387\r\n    template<class\
    \ T>\r\n    inline constexpr T PI = 3.14159265358979323846;\r\n    // \u5186\u5468\
    \u7387\r\n    inline constexpr KYOPRO_BASE_FLOAT pi = PI<KYOPRO_BASE_FLOAT>;\r\
    \n} // namespace kpr\r\n"
  dependsOn:
  - math/power.hpp
  - meta/setting.hpp
  isVerificationFile: false
  path: meta/constant.hpp
  requiredBy:
  - all/all.hpp
  - function/monoid.hpp
  - function/function.hpp
  - meta/meta.hpp
  - all.hpp
  - math/is_prime.hpp
  - math/factorize.hpp
  - math/ModInt.hpp
  - math/math.hpp
  - math/BinomMod.hpp
  - math/DynamicModInt.hpp
  - template/template.hpp
  - template/alias.hpp
  - data_structure/structure.hpp
  - data_structure/data_structure.hpp
  - data_structure/FenwickTree.hpp
  timestamp: '2023-02-11 02:36:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/factorize.test.cpp
  - verify/yosupo/point_add_range_sum.test.cpp
  - verify/aoj/PrimeNumber.test.cpp
documentation_of: meta/constant.hpp
layout: document
redirect_from:
- /library/meta/constant.hpp
- /library/meta/constant.hpp.html
title: meta/constant.hpp
---
