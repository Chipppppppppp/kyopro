---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base/settings.hpp
    title: base/settings.hpp
  - icon: ':warning:'
    path: math/mod.hpp
    title: math/mod.hpp
  - icon: ':warning:'
    path: math/modpow.hpp
    title: math/modpow.hpp
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
  bundledCode: "#line 2 \"math/is_prime.hpp\"\n#include <array>\n#include <cstdint>\n\
    #line 3 \"base/settings.hpp\"\n\n#ifndef KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT\
    \ std::int64_t\n#endif\n\n#ifndef KYOPRO_BASE_UINT\n#define KYOPRO_BASE_UINT std::uint64_t\n\
    #endif\n\n#ifndef KYOPRO_BASE_FLOAT\n#define KYOPRO_BASE_FLOAT double\n#endif\n\
    \n#ifndef KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD static_cast<KYOPRO_BASE_UINT>(1000000007)\n\
    #endif\n\n#ifndef KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n\
    #endif\n\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 3 \"math/modpow.hpp\"\n#include <type_traits>\n#line 2 \"math/mod.hpp\"\
    \n#include <cassert>\n#line 4 \"math/mod.hpp\"\n\nnamespace kyopro {\n  template<class\
    \ _typeT, class _typeU>\n  constexpr std::common_type_t<_typeT, _typeU> floor_mod(_typeT\
    \ _x, _typeU _m) noexcept {\n    static_assert(std::is_integral_v<_typeT> && std::is_integral_v<_typeU>);\n\
    \    if constexpr (std::is_unsigned_v<_typeT> || std::is_unsigned_v<_typeU>) return\
    \ _x % _m;\n    return (_x %= _m) < 0 ? _x + _m : _x;\n  }\n\n  template<class\
    \ _typeT, class _typeU>\n  constexpr std::common_type_t<_typeT, _typeU> ceil_mod(_typeT\
    \ _x, _typeU _m) noexcept {\n    return _m - floor_mod(_x - 1, _m) - static_cast<_typeT>(1);\n\
    \  }\n}\n#line 6 \"math/modpow.hpp\"\n\nnamespace kyopro {\n  template<class _typeT>\n\
    \  constexpr _typeT modpow(_typeT _a, KYOPRO_BASE_UINT _n, KYOPRO_BASE_UINT _mod)\
    \ noexcept {\n    static_assert(std::is_integral_v<_typeT>);\n    std::uint_fast64_t\
    \ _b = floor_mod(_a, static_cast<_typeT>(_mod));\n    std::uint_fast64_t _res\
    \ = 1;\n    while (_n > 0) {\n      if (_n & 1) _res = _res * _b % _mod;\n   \
    \   _b *= _b;\n      _n >>= 1;\n    }\n    return static_cast<_typeT>(_res);\n\
    \  }\n}\n#line 6 \"math/is_prime.hpp\"\n\nnamespace kyopro {\n  constexpr bool\
    \ is_prime(KYOPRO_BASE_UINT _n) {\n    if (_n <= 1) return false;\n    if (~_n\
    \ & 1) return _n == 2;\n    std::uint_fast64_t _d = _n - 1;\n    while (~_d &\
    \ 1) _d >>= 1;\n    std::uint_fast64_t _e = 1, _rev = _n - 1;\n    for (auto _a:\
    \ std::array<std::uint_fast64_t, 7>{2, 325, 9375, 28178, 450775, 9780504, 1795265022})\
    \ {\n      if (_n <= _a) break;\n      std::uint_fast64_t _t = _d, _y = modpow(_a,\
    \ _t, _n);\n      while (_t != _n - 1 && _y != _e && _y != _rev) {\n        _y\
    \ = _y * _y % _n;\n        _t <<= 1;\n      }\n      if (_y != _rev && !(_t &\
    \ 1)) return false;\n    }\n    return true;\n  }\n}\n"
  code: "#pragma once\n#include <array>\n#include <cstdint>\n#include \"../base/settings.hpp\"\
    \n#include \"modpow.hpp\"\n\nnamespace kyopro {\n  constexpr bool is_prime(KYOPRO_BASE_UINT\
    \ _n) {\n    if (_n <= 1) return false;\n    if (~_n & 1) return _n == 2;\n  \
    \  std::uint_fast64_t _d = _n - 1;\n    while (~_d & 1) _d >>= 1;\n    std::uint_fast64_t\
    \ _e = 1, _rev = _n - 1;\n    for (auto _a: std::array<std::uint_fast64_t, 7>{2,\
    \ 325, 9375, 28178, 450775, 9780504, 1795265022}) {\n      if (_n <= _a) break;\n\
    \      std::uint_fast64_t _t = _d, _y = modpow(_a, _t, _n);\n      while (_t !=\
    \ _n - 1 && _y != _e && _y != _rev) {\n        _y = _y * _y % _n;\n        _t\
    \ <<= 1;\n      }\n      if (_y != _rev && !(_t & 1)) return false;\n    }\n \
    \   return true;\n  }\n}"
  dependsOn:
  - base/settings.hpp
  - math/modpow.hpp
  - math/mod.hpp
  isVerificationFile: false
  path: math/is_prime.hpp
  requiredBy:
  - math/factorize.hpp
  - math/all.hpp
  - all.hpp
  timestamp: '2022-03-12 18:34:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/is_prime.hpp
layout: document
redirect_from:
- /library/math/is_prime.hpp
- /library/math/is_prime.hpp.html
title: math/is_prime.hpp
---
