---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/is_prime.hpp
    title: math/is_prime.hpp
  - icon: ':heavy_check_mark:'
    path: meta/settings.hpp
    title: meta/settings.hpp
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
  bundledCode: "#line 2 \"math/factorize.hpp\"\n#include <algorithm>\n#include <cstdint>\n\
    #include <numeric>\n#include <random>\n#line 3 \"meta/settings.hpp\"\n\n#ifndef\
    \ KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT std::int64_t\n#endif\n\n#ifndef KYOPRO_BASE_UINT\n\
    #define KYOPRO_BASE_UINT std::uint64_t\n#endif\n\n#ifndef KYOPRO_BASE_FLOAT\n\
    #define KYOPRO_BASE_FLOAT double\n#endif\n\n#ifndef KYOPRO_DEFAULT_MOD\n#define\
    \ KYOPRO_DEFAULT_MOD static_cast<KYOPRO_BASE_UINT>(1000000007)\n#endif\n\n#ifndef\
    \ KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n\
    #endif\n\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 3 \"math/is_prime.hpp\"\n#include <initializer_list>\n#line 5 \"\
    math/is_prime.hpp\"\n\nnamespace kyopro {\n  constexpr bool is_prime(KYOPRO_BASE_UINT\
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
    \    return true;\n  }\n}\n#line 8 \"math/factorize.hpp\"\n\nnamespace kyopro\
    \ {\n  template<class T>\n  constexpr T pollard_rho(T _n, KYOPRO_BASE_UINT _c)\
    \ {\n    std::uint_fast64_t _cc = _c % _n;\n    auto _f = [=](std::uint_fast64_t\
    \ _x) noexcept { return (_x * _x + _cc) % _n; };\n    std::uint_fast64_t _x =\
    \ 1, _y = 2, _z = 1, _q = 1;\n    T _g = 1;\n    for (int _r = 1; _g == 1; _r\
    \ <<= 1) {\n      _x = _y;\n      for (int _i = 0; _i < _r; ++_i) _y = _f(_y);\n\
    \      for (int _k = 0; _k < _r && _g == 1; _k += 128) {\n        _z = _y;\n \
    \       int _min = std::min(128, _r - _k);\n        for (int _i = 0; _i < _min;\
    \ ++_i) {\n          _y = _f(_y);\n          _q = _q * (_x + _n - _y) % _n;\n\
    \        }\n        _g = std::gcd(_q, _n);\n      }\n    }\n    if (_g == _n)\
    \ {\n      do {\n        _z = _f(_z);\n        _g = std::gcd((_x + _n - _z) %\
    \ _n, _n);\n      } while (_g == 1);\n    }\n    return _g;\n  }\n\n  KYOPRO_BASE_UINT\
    \ find_prime_factor(KYOPRO_BASE_UINT _n) noexcept {\n    static std::mt19937_64\
    \ _mt(std::random_device{}());\n    std::uniform_int_distribution<std::uint_fast64_t>\
    \ _rnd(0, _n - 1);\n    if (is_prime(_n)) return _n;\n    for (int _i = 0; _i\
    \ < 100; ++_i) {\n      std::uint_fast64_t _m = pollard_rho(_n, _rnd(_mt));\n\
    \      if (is_prime(_m)) return _m;\n      _n = _m;\n    }\n    return 1;\n  }\n\
    \n  template<bool _sorted = true, class _typeContainer = std::vector<KYOPRO_BASE_INT>>\n\
    \  _typeContainer factorize(KYOPRO_BASE_UINT _n) {\n    _typeContainer _res;\n\
    \    for (int _p = 2; _p < 100 && _p * _p <= _n; ++_p) {\n      while (_n % _p\
    \ == 0) {\n        _n /= _p;\n        _res.emplace_back(_p);\n      }\n    }\n\
    \    while (_n > 1) {\n      std::uint_fast64_t _p = find_prime_factor(_n);\n\
    \      while (_n % _p == 0) {\n        _n /= _p;\n        _res.emplace_back(_p);\n\
    \      }\n    }\n    if constexpr (_sorted) std::sort(_res.begin(), _res.end());\n\
    \    return _res;\n  }\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <cstdint>\n#include <numeric>\n\
    #include <random>\n#include \"../meta/settings.hpp\"\n#include \"is_prime.hpp\"\
    \n\nnamespace kyopro {\n  template<class T>\n  constexpr T pollard_rho(T _n, KYOPRO_BASE_UINT\
    \ _c) {\n    std::uint_fast64_t _cc = _c % _n;\n    auto _f = [=](std::uint_fast64_t\
    \ _x) noexcept { return (_x * _x + _cc) % _n; };\n    std::uint_fast64_t _x =\
    \ 1, _y = 2, _z = 1, _q = 1;\n    T _g = 1;\n    for (int _r = 1; _g == 1; _r\
    \ <<= 1) {\n      _x = _y;\n      for (int _i = 0; _i < _r; ++_i) _y = _f(_y);\n\
    \      for (int _k = 0; _k < _r && _g == 1; _k += 128) {\n        _z = _y;\n \
    \       int _min = std::min(128, _r - _k);\n        for (int _i = 0; _i < _min;\
    \ ++_i) {\n          _y = _f(_y);\n          _q = _q * (_x + _n - _y) % _n;\n\
    \        }\n        _g = std::gcd(_q, _n);\n      }\n    }\n    if (_g == _n)\
    \ {\n      do {\n        _z = _f(_z);\n        _g = std::gcd((_x + _n - _z) %\
    \ _n, _n);\n      } while (_g == 1);\n    }\n    return _g;\n  }\n\n  KYOPRO_BASE_UINT\
    \ find_prime_factor(KYOPRO_BASE_UINT _n) noexcept {\n    static std::mt19937_64\
    \ _mt(std::random_device{}());\n    std::uniform_int_distribution<std::uint_fast64_t>\
    \ _rnd(0, _n - 1);\n    if (is_prime(_n)) return _n;\n    for (int _i = 0; _i\
    \ < 100; ++_i) {\n      std::uint_fast64_t _m = pollard_rho(_n, _rnd(_mt));\n\
    \      if (is_prime(_m)) return _m;\n      _n = _m;\n    }\n    return 1;\n  }\n\
    \n  template<bool _sorted = true, class _typeContainer = std::vector<KYOPRO_BASE_INT>>\n\
    \  _typeContainer factorize(KYOPRO_BASE_UINT _n) {\n    _typeContainer _res;\n\
    \    for (int _p = 2; _p < 100 && _p * _p <= _n; ++_p) {\n      while (_n % _p\
    \ == 0) {\n        _n /= _p;\n        _res.emplace_back(_p);\n      }\n    }\n\
    \    while (_n > 1) {\n      std::uint_fast64_t _p = find_prime_factor(_n);\n\
    \      while (_n % _p == 0) {\n        _n /= _p;\n        _res.emplace_back(_p);\n\
    \      }\n    }\n    if constexpr (_sorted) std::sort(_res.begin(), _res.end());\n\
    \    return _res;\n  }\n}"
  dependsOn:
  - meta/settings.hpp
  - math/is_prime.hpp
  isVerificationFile: false
  path: math/factorize.hpp
  requiredBy:
  - math/all.hpp
  - all.hpp
  timestamp: '2022-03-17 14:38:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/factorize.hpp
layout: document
redirect_from:
- /library/math/factorize.hpp
- /library/math/factorize.hpp.html
title: math/factorize.hpp
---
