---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base/settings.hpp
    title: base/settings.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  - icon: ':warning:'
    path: math/all.hpp
    title: math/all.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/factorize.hpp\"\n#include <cstdint>\n#include <vector>\n\
    #include <utility>\n#line 3 \"base/settings.hpp\"\n\n#ifndef KYOPRO_BASE_INT\n\
    #define KYOPRO_BASE_INT std::int64_t\n#endif\n\n#ifndef KYOPRO_BASE_UINT\n#define\
    \ KYOPRO_BASE_UINT std::size_t\n#endif\n\n#ifndef KYOPRO_BASE_FLOAT\n#define KYOPRO_BASE_FLOAT\
    \ double\n#endif\n\n#ifndef KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD static_cast<KYOPRO_BASE_UINT>(1000000007)\n\
    #endif\n\n#ifndef KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n\
    #endif\n\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 6 \"math/factorize.hpp\"\n\nnamespace kyopro {\n  template<class\
    \ _typeContainer = std::vector<KYOPRO_BASE_INT>>\n  _typeContainer factorize(std::uint_fast64_t\
    \ _n) {\n    _typeContainer _res;\n    while ((_n & 1) == 0) {\n      _res.emplace_back(2);\n\
    \      _n >>= 1;\n    }\n    for (std::uint_fast64_t _i = 3; _i * _i <= _n; _i\
    \ += 2) while (_n % _i == 0) {\n      _res.emplace_back(2);\n      _n /= _i;\n\
    \    }\n    if (_n != 1) _res.emplace_back(_n);\n    return _res;\n  }\n}\n"
  code: "#pragma once\n#include <cstdint>\n#include <vector>\n#include <utility>\n\
    #include \"../base/settings.hpp\"\n\nnamespace kyopro {\n  template<class _typeContainer\
    \ = std::vector<KYOPRO_BASE_INT>>\n  _typeContainer factorize(std::uint_fast64_t\
    \ _n) {\n    _typeContainer _res;\n    while ((_n & 1) == 0) {\n      _res.emplace_back(2);\n\
    \      _n >>= 1;\n    }\n    for (std::uint_fast64_t _i = 3; _i * _i <= _n; _i\
    \ += 2) while (_n % _i == 0) {\n      _res.emplace_back(2);\n      _n /= _i;\n\
    \    }\n    if (_n != 1) _res.emplace_back(_n);\n    return _res;\n  }\n}"
  dependsOn:
  - base/settings.hpp
  isVerificationFile: false
  path: math/factorize.hpp
  requiredBy:
  - all.hpp
  - math/all.hpp
  timestamp: '2022-01-23 17:00:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/factorize.hpp
layout: document
redirect_from:
- /library/math/factorize.hpp
- /library/math/factorize.hpp.html
title: math/factorize.hpp
---
