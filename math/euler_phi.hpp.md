---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: meta/settings.hpp
    title: meta/settings.hpp
  _extendedRequiredBy: []
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
    #endif\n#line 4 \"math/euler_phi.hpp\"\n\nnamespace kyopro {\n  constexpr KYOPRO_BASE_UINT\
    \ euler_phi(KYOPRO_BASE_UINT _n) noexcept {\n    std::uint_fast64_t _res = _n;\n\
    \    if ((_n & 1) == 0) {\n      _res -= _res >> 1;\n      _n >>= 1;\n      while\
    \ ((_n & 1) == 0) _n >>= 1;\n    }\n    for (std::uint_fast64_t _i = 3; _i * _i\
    \ <= _n; _i += 2) {\n      if (_n % _i == 0) {\n        _res -= _res / _i;\n \
    \       _n /= _i;\n        while (_n % _i == 0) _n /= _i;\n      }\n    }\n  \
    \  if (_n != 1) _res -= _res / _n;\n    return _res;\n  }\n}\n"
  code: "#pragma once\n#include <cstdint>\n#include \"../meta/settings.hpp\"\n\nnamespace\
    \ kyopro {\n  constexpr KYOPRO_BASE_UINT euler_phi(KYOPRO_BASE_UINT _n) noexcept\
    \ {\n    std::uint_fast64_t _res = _n;\n    if ((_n & 1) == 0) {\n      _res -=\
    \ _res >> 1;\n      _n >>= 1;\n      while ((_n & 1) == 0) _n >>= 1;\n    }\n\
    \    for (std::uint_fast64_t _i = 3; _i * _i <= _n; _i += 2) {\n      if (_n %\
    \ _i == 0) {\n        _res -= _res / _i;\n        _n /= _i;\n        while (_n\
    \ % _i == 0) _n /= _i;\n      }\n    }\n    if (_n != 1) _res -= _res / _n;\n\
    \    return _res;\n  }\n}"
  dependsOn:
  - meta/settings.hpp
  isVerificationFile: false
  path: math/euler_phi.hpp
  requiredBy: []
  timestamp: '2022-03-19 00:51:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/euler_phi.hpp
layout: document
redirect_from:
- /library/math/euler_phi.hpp
- /library/math/euler_phi.hpp.html
title: math/euler_phi.hpp
---
