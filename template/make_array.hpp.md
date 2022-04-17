---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: meta/settings.hpp
    title: meta/settings.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all/all.hpp
    title: all/all.hpp
  - icon: ':warning:'
    path: template/all.hpp
    title: template/all.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/make_array.hpp\"\n#include <array>\n#include <utility>\n\
    #line 2 \"meta/settings.hpp\"\n#include <cstdint>\n\n#ifndef KYOPRO_BASE_INT\n\
    #define KYOPRO_BASE_INT std::int64_t\n#endif\n\n#ifndef KYOPRO_BASE_UINT\n#define\
    \ KYOPRO_BASE_UINT std::uint64_t\n#endif\n\n#ifndef KYOPRO_BASE_FLOAT\n#define\
    \ KYOPRO_BASE_FLOAT double\n#endif\n\n#ifndef KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD\
    \ static_cast<KYOPRO_BASE_UINT>(998244353)\n#endif\n\n#ifndef KYOPRO_DECIMAL_PRECISION\n\
    #define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n#endif\n\n\
    #ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 5 \"template/make_array.hpp\"\n\nnamespace kyopro {\n  template<class\
    \ _typeT>\n  constexpr auto make_array(const _typeT& _init = _typeT()) noexcept\
    \ { return _init; }\n\n  template<class _typeT, KYOPRO_BASE_UINT _length, KYOPRO_BASE_UINT...\
    \ _lengths>\n  constexpr auto make_array(const _typeT& _init = _typeT()) noexcept\
    \ {\n    auto _elm = make_array<_typeT, _lengths...>(_init);\n    std::array<decltype(_elm),\
    \ _length> _res;\n    for (auto& _i: _res) _i = _elm;\n    return std::move(_res);\n\
    \  }\n}\n"
  code: "#pragma once\n#include <array>\n#include <utility>\n#include \"../meta/settings.hpp\"\
    \n\nnamespace kyopro {\n  template<class _typeT>\n  constexpr auto make_array(const\
    \ _typeT& _init = _typeT()) noexcept { return _init; }\n\n  template<class _typeT,\
    \ KYOPRO_BASE_UINT _length, KYOPRO_BASE_UINT... _lengths>\n  constexpr auto make_array(const\
    \ _typeT& _init = _typeT()) noexcept {\n    auto _elm = make_array<_typeT, _lengths...>(_init);\n\
    \    std::array<decltype(_elm), _length> _res;\n    for (auto& _i: _res) _i =\
    \ _elm;\n    return std::move(_res);\n  }\n}"
  dependsOn:
  - meta/settings.hpp
  isVerificationFile: false
  path: template/make_array.hpp
  requiredBy:
  - template/all.hpp
  - all/all.hpp
  timestamp: '2022-04-17 23:28:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/make_array.hpp
layout: document
redirect_from:
- /library/template/make_array.hpp
- /library/template/make_array.hpp.html
title: template/make_array.hpp
---
