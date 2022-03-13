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
    path: math/DynamicModInt.hpp
    title: math/DynamicModInt.hpp
  - icon: ':warning:'
    path: math/all.hpp
    title: math/all.hpp
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
  bundledCode: "#line 2 \"math/Barrett.hpp\"\n#include <cstdint>\n#line 3 \"base/settings.hpp\"\
    \n\n#ifndef KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT std::int64_t\n#endif\n\n\
    #ifndef KYOPRO_BASE_UINT\n#define KYOPRO_BASE_UINT std::uint64_t\n#endif\n\n#ifndef\
    \ KYOPRO_BASE_FLOAT\n#define KYOPRO_BASE_FLOAT double\n#endif\n\n#ifndef KYOPRO_DEFAULT_MOD\n\
    #define KYOPRO_DEFAULT_MOD static_cast<KYOPRO_BASE_UINT>(1000000007)\n#endif\n\
    \n#ifndef KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n\
    #endif\n\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 4 \"math/Barrett.hpp\"\n\nstruct Barrett {\nprivate:\n  std::uint_fast64_t\
    \ _mod;\n  __uint128_t _m;\n\npublic:\n  constexpr void set_mod(KYOPRO_BASE_UINT\
    \ _mod) noexcept {\n    this->_mod = _mod;\n    _m = (static_cast<__uint128_t>(1)\
    \ << 64) / _mod;\n  }\n\n  constexpr KYOPRO_BASE_INT get_mod() const noexcept\
    \ {\n    return static_cast<KYOPRO_BASE_INT>(_mod);\n  }\n\n  Barrett() noexcept\
    \ = default;\n  Barrett(KYOPRO_BASE_UINT _mod) noexcept: _mod(_mod), _m((static_cast<__uint128_t>(1)\
    \ << 64) / _mod) {}\n\n  constexpr KYOPRO_BASE_UINT operator ()(KYOPRO_BASE_UINT\
    \ _x) const noexcept {\n\t  _x -= static_cast<std::uint_fast64_t>((_x * _m) >>\
    \ 64) * _mod;\n    return _x < _mod ? _x : _x - _mod;\n  }\n};\n"
  code: "#pragma once\n#include <cstdint>\n#include \"../base/settings.hpp\"\n\nstruct\
    \ Barrett {\nprivate:\n  std::uint_fast64_t _mod;\n  __uint128_t _m;\n\npublic:\n\
    \  constexpr void set_mod(KYOPRO_BASE_UINT _mod) noexcept {\n    this->_mod =\
    \ _mod;\n    _m = (static_cast<__uint128_t>(1) << 64) / _mod;\n  }\n\n  constexpr\
    \ KYOPRO_BASE_INT get_mod() const noexcept {\n    return static_cast<KYOPRO_BASE_INT>(_mod);\n\
    \  }\n\n  Barrett() noexcept = default;\n  Barrett(KYOPRO_BASE_UINT _mod) noexcept:\
    \ _mod(_mod), _m((static_cast<__uint128_t>(1) << 64) / _mod) {}\n\n  constexpr\
    \ KYOPRO_BASE_UINT operator ()(KYOPRO_BASE_UINT _x) const noexcept {\n\t  _x -=\
    \ static_cast<std::uint_fast64_t>((_x * _m) >> 64) * _mod;\n    return _x < _mod\
    \ ? _x : _x - _mod;\n  }\n};"
  dependsOn:
  - base/settings.hpp
  isVerificationFile: false
  path: math/Barrett.hpp
  requiredBy:
  - math/DynamicModInt.hpp
  - math/all.hpp
  - template/all.hpp
  - template/alias.hpp
  - all.hpp
  timestamp: '2022-03-13 23:42:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/Barrett.hpp
layout: document
redirect_from:
- /library/math/Barrett.hpp
- /library/math/Barrett.hpp.html
title: math/Barrett.hpp
---
