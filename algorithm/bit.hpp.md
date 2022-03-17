---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: meta/settings.hpp
    title: meta/settings.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: algorithm/all.hpp
    title: algorithm/all.hpp
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"meta/settings.hpp\"\n#include <cstdint>\n\n#ifndef KYOPRO_BASE_INT\n\
    #define KYOPRO_BASE_INT std::int64_t\n#endif\n\n#ifndef KYOPRO_BASE_UINT\n#define\
    \ KYOPRO_BASE_UINT std::uint64_t\n#endif\n\n#ifndef KYOPRO_BASE_FLOAT\n#define\
    \ KYOPRO_BASE_FLOAT double\n#endif\n\n#ifndef KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD\
    \ static_cast<KYOPRO_BASE_UINT>(1000000007)\n#endif\n\n#ifndef KYOPRO_DECIMAL_PRECISION\n\
    #define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n#endif\n\n\
    #ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 3 \"algorithm/bit.hpp\"\n\nnamespace kyopro {\n  constexpr KYOPRO_BASE_INT\
    \ popcount(KYOPRO_BASE_INT _x) noexcept {\n    _x = _x - ((_x >> 1) & 0x5555555555555555);\n\
    \    _x = (_x & 0x3333333333333333) + ((_x >> 2) & 0x3333333333333333);\n    _x\
    \ = (_x + (_x >> 4)) & 0x0f0f0f0f0f0f0f0f;\n    _x = _x + (_x >> 8);\n    _x =\
    \ _x + (_x >> 16);\n    _x = _x + (_x >> 32);\n    return _x & 0x0000007f;\n \
    \ }\n}\n"
  code: "#pragma once\n#include \"../meta/settings.hpp\"\n\nnamespace kyopro {\n \
    \ constexpr KYOPRO_BASE_INT popcount(KYOPRO_BASE_INT _x) noexcept {\n    _x =\
    \ _x - ((_x >> 1) & 0x5555555555555555);\n    _x = (_x & 0x3333333333333333) +\
    \ ((_x >> 2) & 0x3333333333333333);\n    _x = (_x + (_x >> 4)) & 0x0f0f0f0f0f0f0f0f;\n\
    \    _x = _x + (_x >> 8);\n    _x = _x + (_x >> 16);\n    _x = _x + (_x >> 32);\n\
    \    return _x & 0x0000007f;\n  }\n}"
  dependsOn:
  - meta/settings.hpp
  isVerificationFile: false
  path: algorithm/bit.hpp
  requiredBy:
  - algorithm/all.hpp
  - all.hpp
  timestamp: '2022-03-17 14:48:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/bit.hpp
layout: document
redirect_from:
- /library/algorithm/bit.hpp
- /library/algorithm/bit.hpp.html
title: algorithm/bit.hpp
---
