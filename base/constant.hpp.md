---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base/settings.hpp
    title: base/settings.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  - icon: ':warning:'
    path: base/all.hpp
    title: base/all.hpp
  - icon: ':x:'
    path: base/monoid.hpp
    title: base/monoid.hpp
  - icon: ':x:'
    path: structure/FenwickTree.hpp
    title: structure/FenwickTree.hpp
  - icon: ':warning:'
    path: structure/all.hpp
    title: structure/all.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: yosupo/FenwickTree.test.cpp
    title: yosupo/FenwickTree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"base/constant.hpp\"\n#include <limits>\n#include <array>\n\
    #include <utility>\n#line 1 \"base/settings.hpp\"\n#include <cstdint>\n#ifndef\
    \ KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT std::int64_t\n#endif\n#ifndef KYOPRO_BASE_UINT\n\
    #define KYOPRO_BASE_UINT std::size_t\n#endif\n#ifndef KYOPRO_BASE_FLOAT\n#define\
    \ KYOPRO_BASE_FLOAT double\n#endif\n#ifndef KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD\
    \ 1000000007\n#endif\n#ifndef KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION\
    \ 12\n#endif\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV 3\n#endif\n#line\
    \ 6 \"base/constant.hpp\"\n\nnamespace kyopro {\n  template<class KyoproT>\n \
    \ inline constexpr KyoproT MOD = KYOPRO_DEFAULT_MOD;\n  inline constexpr KYOPRO_BASE_INT\
    \ mod = MOD<KYOPRO_BASE_INT>;\n  template<class KyoproT>\n  inline constexpr KyoproT\
    \ INF = std::numeric_limits<KyoproT>::max() / KYOPRO_INF_DIV;\n  inline constexpr\
    \ KYOPRO_BASE_INT inf = INF<KYOPRO_BASE_INT>;\n  template<class KyoproT>\n  inline\
    \ constexpr KyoproT PI = 3.14159265358979323846;\n  inline constexpr KYOPRO_BASE_FLOAT\
    \ pi = PI<KYOPRO_BASE_FLOAT>;\n  using KyoproPair = std::pair<KYOPRO_BASE_INT,\
    \ KYOPRO_BASE_INT>;\n  inline constexpr std::array<KyoproPair, 4> beside{KyoproPair{1,\
    \ 0}, KyoproPair{0, 1}, KyoproPair{-1, 0}, KyoproPair{0, -1}};\n  inline constexpr\
    \ std::array<KyoproPair, 8> around{KyoproPair{1, 0}, KyoproPair{1, 1}, KyoproPair{0,\
    \ 1}, KyoproPair{-1, 1}, KyoproPair{-1, 0}, KyoproPair{-1, -1}, KyoproPair{0,\
    \ -1}, KyoproPair{1, -1}};\n}\n"
  code: "#pragma once\n#include <limits>\n#include <array>\n#include <utility>\n#include\
    \ \"settings.hpp\"\n\nnamespace kyopro {\n  template<class KyoproT>\n  inline\
    \ constexpr KyoproT MOD = KYOPRO_DEFAULT_MOD;\n  inline constexpr KYOPRO_BASE_INT\
    \ mod = MOD<KYOPRO_BASE_INT>;\n  template<class KyoproT>\n  inline constexpr KyoproT\
    \ INF = std::numeric_limits<KyoproT>::max() / KYOPRO_INF_DIV;\n  inline constexpr\
    \ KYOPRO_BASE_INT inf = INF<KYOPRO_BASE_INT>;\n  template<class KyoproT>\n  inline\
    \ constexpr KyoproT PI = 3.14159265358979323846;\n  inline constexpr KYOPRO_BASE_FLOAT\
    \ pi = PI<KYOPRO_BASE_FLOAT>;\n  using KyoproPair = std::pair<KYOPRO_BASE_INT,\
    \ KYOPRO_BASE_INT>;\n  inline constexpr std::array<KyoproPair, 4> beside{KyoproPair{1,\
    \ 0}, KyoproPair{0, 1}, KyoproPair{-1, 0}, KyoproPair{0, -1}};\n  inline constexpr\
    \ std::array<KyoproPair, 8> around{KyoproPair{1, 0}, KyoproPair{1, 1}, KyoproPair{0,\
    \ 1}, KyoproPair{-1, 1}, KyoproPair{-1, 0}, KyoproPair{-1, -1}, KyoproPair{0,\
    \ -1}, KyoproPair{1, -1}};\n}"
  dependsOn:
  - base/settings.hpp
  isVerificationFile: false
  path: base/constant.hpp
  requiredBy:
  - structure/FenwickTree.hpp
  - structure/all.hpp
  - all.hpp
  - base/all.hpp
  - base/monoid.hpp
  timestamp: '2022-01-05 11:31:07+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - yosupo/FenwickTree.test.cpp
documentation_of: base/constant.hpp
layout: document
redirect_from:
- /library/base/constant.hpp
- /library/base/constant.hpp.html
title: base/constant.hpp
---
