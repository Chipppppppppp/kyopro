---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: meta/settings.hpp
    title: meta/settings.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/DynamicModInt.hpp
    title: math/DynamicModInt.hpp
  - icon: ':warning:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':warning:'
    path: template/all.hpp
    title: template/all.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/Montgomery.hpp\"\n#include <cstdint>\n#line 3 \"meta/settings.hpp\"\
    \n\n#ifndef KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT std::int64_t\n#endif\n\n\
    #ifndef KYOPRO_BASE_UINT\n#define KYOPRO_BASE_UINT std::uint64_t\n#endif\n\n#ifndef\
    \ KYOPRO_BASE_FLOAT\n#define KYOPRO_BASE_FLOAT double\n#endif\n\n#ifndef KYOPRO_DEFAULT_MOD\n\
    #define KYOPRO_DEFAULT_MOD static_cast<KYOPRO_BASE_UINT>(998244353)\n#endif\n\n\
    #ifndef KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n\
    #endif\n\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 4 \"math/Montgomery.hpp\"\n\nnamespace kyopro {\n  struct Montgomery\
    \ {\n  private:\n    std::uint_fast64_t _m, _r, _n2;\n\n  public:\n    constexpr\
    \ void set_mod(KYOPRO_BASE_UINT _mod) noexcept {\n      _m = _mod;\n      _n2\
    \ = -static_cast<__uint128_t>(_m) % _m;\n      _r = _m;\n      _r *= 2 - _m *\
    \ _r;\n      _r *= 2 - _m * _r;\n      _r *= 2 - _m * _r;\n      _r *= 2 - _m\
    \ * _r;\n      _r *= 2 - _m * _r;\n      _r = -_r;\n    }\n\n    constexpr KYOPRO_BASE_INT\
    \ get_mod() const noexcept {\n      return _m;\n    }\n\n    Montgomery() noexcept\
    \ = default;\n    Montgomery(KYOPRO_BASE_UINT _mod) noexcept {\n      set_mod(_mod);\n\
    \    }\n\n    constexpr KYOPRO_BASE_UINT operator ()(__uint128_t _x) const noexcept\
    \ {\n      return (_x + static_cast<__uint128_t>(static_cast<std::uint_fast64_t>(_x)\
    \ * _r) * _m) >> 64;\n    }\n  };\n}\n"
  code: "#pragma once\n#include <cstdint>\n#include \"../meta/settings.hpp\"\n\nnamespace\
    \ kyopro {\n  struct Montgomery {\n  private:\n    std::uint_fast64_t _m, _r,\
    \ _n2;\n\n  public:\n    constexpr void set_mod(KYOPRO_BASE_UINT _mod) noexcept\
    \ {\n      _m = _mod;\n      _n2 = -static_cast<__uint128_t>(_m) % _m;\n     \
    \ _r = _m;\n      _r *= 2 - _m * _r;\n      _r *= 2 - _m * _r;\n      _r *= 2\
    \ - _m * _r;\n      _r *= 2 - _m * _r;\n      _r *= 2 - _m * _r;\n      _r = -_r;\n\
    \    }\n\n    constexpr KYOPRO_BASE_INT get_mod() const noexcept {\n      return\
    \ _m;\n    }\n\n    Montgomery() noexcept = default;\n    Montgomery(KYOPRO_BASE_UINT\
    \ _mod) noexcept {\n      set_mod(_mod);\n    }\n\n    constexpr KYOPRO_BASE_UINT\
    \ operator ()(__uint128_t _x) const noexcept {\n      return (_x + static_cast<__uint128_t>(static_cast<std::uint_fast64_t>(_x)\
    \ * _r) * _m) >> 64;\n    }\n  };\n}"
  dependsOn:
  - meta/settings.hpp
  isVerificationFile: false
  path: math/Montgomery.hpp
  requiredBy:
  - math/DynamicModInt.hpp
  - template/all.hpp
  - template/alias.hpp
  timestamp: '2022-03-19 20:47:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/Montgomery.hpp
layout: document
redirect_from:
- /library/math/Montgomery.hpp
- /library/math/Montgomery.hpp.html
title: math/Montgomery.hpp
---
