---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: meta/settings.hpp
    title: meta/settings.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  - icon: ':warning:'
    path: math/all.hpp
    title: math/all.hpp
  - icon: ':warning:'
    path: math/factorize.hpp
    title: math/factorize.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/is_prime.hpp\"\n#include <cstdint>\n#include <initializer_list>\n\
    #line 3 \"meta/settings.hpp\"\n\n#ifndef KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT\
    \ std::int64_t\n#endif\n\n#ifndef KYOPRO_BASE_UINT\n#define KYOPRO_BASE_UINT std::uint64_t\n\
    #endif\n\n#ifndef KYOPRO_BASE_FLOAT\n#define KYOPRO_BASE_FLOAT double\n#endif\n\
    \n#ifndef KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD static_cast<KYOPRO_BASE_UINT>(1000000007)\n\
    #endif\n\n#ifndef KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n\
    #endif\n\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 5 \"math/is_prime.hpp\"\n\nnamespace kyopro {\n  constexpr bool\
    \ is_prime(KYOPRO_BASE_UINT _n) {\n    auto modpow = [](std::uint_fast64_t _a,\
    \ std::uint_fast64_t _n, std::uint_fast64_t _mod) noexcept {\n      std::uint_fast64_t\
    \ _b = _a % _mod;\n      std::uint_fast64_t _res = 1;\n      while (_n > 0) {\n\
    \        if (_n & 1) _res = static_cast<__uint128_t>(_res) * _b % _mod;\n    \
    \    _b = static_cast<__uint128_t>(_b) * _b % _mod;\n        _n >>= 1;\n     \
    \ }\n      return _res;\n    };\n    if (_n <= 1) return false;\n    if (!(_n\
    \ & 1)) return _n == 2;\n    std::uint_fast64_t _d = _n - 1;\n    while (!(_d\
    \ & 1)) _d >>= 1;\n    std::uint_fast64_t _e = 1, _rev = _n - 1;\n    for (auto\
    \ _a: (_n < (1ULL << 32) ? std::initializer_list<std::uint_fast64_t>{2, 7, 61}\
    \ : std::initializer_list<std::uint_fast64_t>{2, 325, 9375, 28178, 450775, 9780504,\
    \ 1795265022})) {\n      if (_n <= _a) break;\n      std::uint_fast64_t _t = _d,\
    \ _y = modpow(_a, _d, _n);\n      while (_t != _n - 1 && _y != _e && _y != _rev)\
    \ {\n        _y = static_cast<__uint128_t>(_y) * _y % _n;\n        _t <<= 1;\n\
    \      }\n      if (_y != _rev && !(_t & 1)) return false;\n    }\n    return\
    \ true;\n  }\n}\n"
  code: "#pragma once\n#include <cstdint>\n#include <initializer_list>\n#include \"\
    ../meta/settings.hpp\"\n\nnamespace kyopro {\n  constexpr bool is_prime(KYOPRO_BASE_UINT\
    \ _n) {\n    auto modpow = [](std::uint_fast64_t _a, std::uint_fast64_t _n, std::uint_fast64_t\
    \ _mod) noexcept {\n      std::uint_fast64_t _b = _a % _mod;\n      std::uint_fast64_t\
    \ _res = 1;\n      while (_n > 0) {\n        if (_n & 1) _res = static_cast<__uint128_t>(_res)\
    \ * _b % _mod;\n        _b = static_cast<__uint128_t>(_b) * _b % _mod;\n     \
    \   _n >>= 1;\n      }\n      return _res;\n    };\n    if (_n <= 1) return false;\n\
    \    if (!(_n & 1)) return _n == 2;\n    std::uint_fast64_t _d = _n - 1;\n   \
    \ while (!(_d & 1)) _d >>= 1;\n    std::uint_fast64_t _e = 1, _rev = _n - 1;\n\
    \    for (auto _a: (_n < (1ULL << 32) ? std::initializer_list<std::uint_fast64_t>{2,\
    \ 7, 61} : std::initializer_list<std::uint_fast64_t>{2, 325, 9375, 28178, 450775,\
    \ 9780504, 1795265022})) {\n      if (_n <= _a) break;\n      std::uint_fast64_t\
    \ _t = _d, _y = modpow(_a, _d, _n);\n      while (_t != _n - 1 && _y != _e &&\
    \ _y != _rev) {\n        _y = static_cast<__uint128_t>(_y) * _y % _n;\n      \
    \  _t <<= 1;\n      }\n      if (_y != _rev && !(_t & 1)) return false;\n    }\n\
    \    return true;\n  }\n}"
  dependsOn:
  - meta/settings.hpp
  isVerificationFile: false
  path: math/is_prime.hpp
  requiredBy:
  - math/factorize.hpp
  - math/all.hpp
  - all.hpp
  timestamp: '2022-03-17 14:38:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/is_prime.hpp
layout: document
redirect_from:
- /library/math/is_prime.hpp
- /library/math/is_prime.hpp.html
title: math/is_prime.hpp
---
