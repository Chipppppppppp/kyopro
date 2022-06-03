---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: meta/settings.hpp
    title: meta/settings.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  - icon: ':warning:'
    path: all/all.hpp
    title: all/all.hpp
  - icon: ':warning:'
    path: math/all.hpp
    title: math/all.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/euler_phi.hpp\"\n#include <cstdint>\n#line 3 \"meta/settings.hpp\"\
    \n\n#ifndef KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT std::int64_t\n#endif\n\n\
    #ifndef KYOPRO_BASE_UINT\n#define KYOPRO_BASE_UINT std::uint64_t\n#endif\n\n#ifndef\
    \ KYOPRO_BASE_FLOAT\n#define KYOPRO_BASE_FLOAT double\n#endif\n\n#ifndef KYOPRO_DEFAULT_MOD\n\
    #define KYOPRO_DEFAULT_MOD static_cast<KYOPRO_BASE_UINT>(998244353)\n#endif\n\n\
    #ifndef KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n\
    #endif\n\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 4 \"math/euler_phi.hpp\"\n\nnamespace kpr {\n  constexpr KYOPRO_BASE_UINT\
    \ euler_phi(KYOPRO_BASE_UINT n) noexcept {\n    std::uint_fast64_t res = n;\n\
    \    if ((n & 1) == 0) {\n      res -= res >> 1;\n      n >>= 1;\n      while\
    \ ((n & 1) == 0) n >>= 1;\n    }\n    for (std::uint_fast64_t i = 3; i * i <=\
    \ n; i += 2) {\n      if (n % i == 0) {\n        res -= res / i;\n        n /=\
    \ i;\n        while (n % i == 0) n /= i;\n      }\n    }\n    if (n != 1) res\
    \ -= res / n;\n    return res;\n  }\n}\n"
  code: "#pragma once\n#include <cstdint>\n#include \"../meta/settings.hpp\"\n\nnamespace\
    \ kpr {\n  constexpr KYOPRO_BASE_UINT euler_phi(KYOPRO_BASE_UINT n) noexcept {\n\
    \    std::uint_fast64_t res = n;\n    if ((n & 1) == 0) {\n      res -= res >>\
    \ 1;\n      n >>= 1;\n      while ((n & 1) == 0) n >>= 1;\n    }\n    for (std::uint_fast64_t\
    \ i = 3; i * i <= n; i += 2) {\n      if (n % i == 0) {\n        res -= res /\
    \ i;\n        n /= i;\n        while (n % i == 0) n /= i;\n      }\n    }\n  \
    \  if (n != 1) res -= res / n;\n    return res;\n  }\n}"
  dependsOn:
  - meta/settings.hpp
  isVerificationFile: false
  path: math/euler_phi.hpp
  requiredBy:
  - math/all.hpp
  - all.hpp
  - all/all.hpp
  timestamp: '2022-04-27 22:05:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/euler_phi.hpp
layout: document
redirect_from:
- /library/math/euler_phi.hpp
- /library/math/euler_phi.hpp.html
title: math/euler_phi.hpp
---
