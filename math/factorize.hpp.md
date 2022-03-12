---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: base/settings.hpp
    title: base/settings.hpp
  - icon: ':x:'
    path: math/is_prime.hpp
    title: math/is_prime.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  - icon: ':warning:'
    path: math/all.hpp
    title: math/all.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: yosupo/Factorize.test.cpp
    title: yosupo/Factorize.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/factorize.hpp\"\n#include <algorithm>\n#include <cstdint>\n\
    #include <numeric>\n#include <random>\n#line 3 \"base/settings.hpp\"\n\n#ifndef\
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
    \ {\n  template<class T>\n  constexpr T pollard_rho(T n, KYOPRO_BASE_UINT c) {\n\
    \    std::uint_fast64_t cc = c % n;\n    auto f = [=](std::uint_fast64_t x) noexcept\
    \ { return (x * x + cc) % n; };\n    std::uint_fast64_t x = 1, y = 2, z = 1, q\
    \ = 1;\n    T g = 1;\n    for (int r = 1; g == 1; r <<= 1) {\n      x = y;\n \
    \     for (int i = 0; i < r; ++i) y = f(y);\n      for (int k = 0; k < r and g\
    \ == 1; k += 128) {\n        z = y;\n        int min = std::min(128, r - k);\n\
    \        for (int i = 0; i < min; ++i) {\n          y = f(y);\n          q = q\
    \ * (x + n - y) % n;\n        }\n        g = std::gcd(q, n);\n      }\n    }\n\
    \    if (g == n) {\n      do {\n        z = f(z);\n        g = std::gcd((x + n\
    \ - z) % n, n);\n      } while (g == 1);\n    }\n    return g;\n  }\n\n  KYOPRO_BASE_UINT\
    \ find_prime_factor(KYOPRO_BASE_UINT n) noexcept {\n    static std::mt19937_64\
    \ mt(std::random_device{}());\n    std::uniform_int_distribution<std::uint_fast64_t>\
    \ rnd(0, n - 1);\n    if (is_prime(n)) return n;\n    for (int i = 0; i < 100;\
    \ ++i) {\n      std::uint_fast64_t m = pollard_rho(n, rnd(mt));\n      if (is_prime(m))\
    \ return m;\n      n = m;\n    }\n    return 1;\n  }\n\n  template<bool sorted\
    \ = true, class _typeContainer = std::vector<KYOPRO_BASE_INT>>\n  _typeContainer\
    \ factorize(KYOPRO_BASE_UINT n) {\n    _typeContainer res;\n    for (int p = 2;\
    \ p < 100 && p * p <= n; ++p) {\n      while (n % p == 0) {\n        n /= p;\n\
    \        res.emplace_back(p);\n      }\n    }\n    while (n > 1) {\n      std::uint_fast64_t\
    \ p = find_prime_factor(n);\n      while (n % p == 0) {\n        n /= p;\n   \
    \     res.emplace_back(p);\n      }\n    }\n    if constexpr (sorted) std::sort(res.begin(),\
    \ res.end());\n    return res;\n  }\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <cstdint>\n#include <numeric>\n\
    #include <random>\n#include \"../base/settings.hpp\"\n#include \"is_prime.hpp\"\
    \n\nnamespace kyopro {\n  template<class T>\n  constexpr T pollard_rho(T n, KYOPRO_BASE_UINT\
    \ c) {\n    std::uint_fast64_t cc = c % n;\n    auto f = [=](std::uint_fast64_t\
    \ x) noexcept { return (x * x + cc) % n; };\n    std::uint_fast64_t x = 1, y =\
    \ 2, z = 1, q = 1;\n    T g = 1;\n    for (int r = 1; g == 1; r <<= 1) {\n   \
    \   x = y;\n      for (int i = 0; i < r; ++i) y = f(y);\n      for (int k = 0;\
    \ k < r and g == 1; k += 128) {\n        z = y;\n        int min = std::min(128,\
    \ r - k);\n        for (int i = 0; i < min; ++i) {\n          y = f(y);\n    \
    \      q = q * (x + n - y) % n;\n        }\n        g = std::gcd(q, n);\n    \
    \  }\n    }\n    if (g == n) {\n      do {\n        z = f(z);\n        g = std::gcd((x\
    \ + n - z) % n, n);\n      } while (g == 1);\n    }\n    return g;\n  }\n\n  KYOPRO_BASE_UINT\
    \ find_prime_factor(KYOPRO_BASE_UINT n) noexcept {\n    static std::mt19937_64\
    \ mt(std::random_device{}());\n    std::uniform_int_distribution<std::uint_fast64_t>\
    \ rnd(0, n - 1);\n    if (is_prime(n)) return n;\n    for (int i = 0; i < 100;\
    \ ++i) {\n      std::uint_fast64_t m = pollard_rho(n, rnd(mt));\n      if (is_prime(m))\
    \ return m;\n      n = m;\n    }\n    return 1;\n  }\n\n  template<bool sorted\
    \ = true, class _typeContainer = std::vector<KYOPRO_BASE_INT>>\n  _typeContainer\
    \ factorize(KYOPRO_BASE_UINT n) {\n    _typeContainer res;\n    for (int p = 2;\
    \ p < 100 && p * p <= n; ++p) {\n      while (n % p == 0) {\n        n /= p;\n\
    \        res.emplace_back(p);\n      }\n    }\n    while (n > 1) {\n      std::uint_fast64_t\
    \ p = find_prime_factor(n);\n      while (n % p == 0) {\n        n /= p;\n   \
    \     res.emplace_back(p);\n      }\n    }\n    if constexpr (sorted) std::sort(res.begin(),\
    \ res.end());\n    return res;\n  }\n}"
  dependsOn:
  - base/settings.hpp
  - math/is_prime.hpp
  isVerificationFile: false
  path: math/factorize.hpp
  requiredBy:
  - math/all.hpp
  - all.hpp
  timestamp: '2022-03-12 19:55:46+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - yosupo/Factorize.test.cpp
documentation_of: math/factorize.hpp
layout: document
redirect_from:
- /library/math/factorize.hpp
- /library/math/factorize.hpp.html
title: math/factorize.hpp
---
