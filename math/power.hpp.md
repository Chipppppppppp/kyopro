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
  - icon: ':x:'
    path: math/monoid.hpp
    title: math/monoid.hpp
  - icon: ':x:'
    path: structure/FenwickTree.hpp
    title: structure/FenwickTree.hpp
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
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/power.hpp\"\n#include <cstdint>\n#line 3 \"base/settings.hpp\"\
    \n#ifndef KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT std::int64_t\n#endif\n#ifndef\
    \ KYOPRO_BASE_UINT\n#define KYOPRO_BASE_UINT std::size_t\n#endif\n#ifndef KYOPRO_BASE_FLOAT\n\
    #define KYOPRO_BASE_FLOAT double\n#endif\n#ifndef KYOPRO_DEFAULT_MOD\n#define\
    \ KYOPRO_DEFAULT_MOD 1000000007\n#endif\n#ifndef KYOPRO_DECIMAL_PRECISION\n#define\
    \ KYOPRO_DECIMAL_PRECISION 12\n#endif\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV\
    \ 3\n#endif\n#line 4 \"math/power.hpp\"\nnamespace kyopro {\n  template<class\
    \ KyoproT>\n  constexpr KyoproT power(KyoproT a, std::uint64_t n, KyoproT init\
    \ = 1) noexcept {\n    while (n > 0) {\n      if (n & 1) init *= a;\n      a *=\
    \ a;\n      n >>= 1;\n    }\n    return init;\n  }\n}\n"
  code: "#pragma once\n#include <cstdint>\n#include \"../base/settings.hpp\"\nnamespace\
    \ kyopro {\n  template<class KyoproT>\n  constexpr KyoproT power(KyoproT a, std::uint64_t\
    \ n, KyoproT init = 1) noexcept {\n    while (n > 0) {\n      if (n & 1) init\
    \ *= a;\n      a *= a;\n      n >>= 1;\n    }\n    return init;\n  }\n}"
  dependsOn:
  - base/settings.hpp
  isVerificationFile: false
  path: math/power.hpp
  requiredBy:
  - structure/FenwickTree.hpp
  - structure/all.hpp
  - math/ModInt.hpp
  - math/all.hpp
  - math/monoid.hpp
  - template/alias.hpp
  - template/all.hpp
  - all.hpp
  - base/Hash.hpp
  - base/constant.hpp
  - base/all.hpp
  timestamp: '2022-01-10 19:46:56+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - yosupo/FenwickTree.test.cpp
documentation_of: math/power.hpp
layout: document
redirect_from:
- /library/math/power.hpp
- /library/math/power.hpp.html
title: math/power.hpp
---
