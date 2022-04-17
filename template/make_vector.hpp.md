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
  bundledCode: "#line 2 \"template/make_vector.hpp\"\n#include <cstdint>\n#include\
    \ <utility>\n#include <vector>\n#line 3 \"meta/settings.hpp\"\n\n#ifndef KYOPRO_BASE_INT\n\
    #define KYOPRO_BASE_INT std::int64_t\n#endif\n\n#ifndef KYOPRO_BASE_UINT\n#define\
    \ KYOPRO_BASE_UINT std::uint64_t\n#endif\n\n#ifndef KYOPRO_BASE_FLOAT\n#define\
    \ KYOPRO_BASE_FLOAT double\n#endif\n\n#ifndef KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD\
    \ static_cast<KYOPRO_BASE_UINT>(998244353)\n#endif\n\n#ifndef KYOPRO_DECIMAL_PRECISION\n\
    #define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n#endif\n\n\
    #ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 6 \"template/make_vector.hpp\"\n\nnamespace kyopro {\n  template<KYOPRO_BASE_UINT\
    \ _idx = 0, KYOPRO_BASE_UINT _n, class _typeT>\n  auto make_vector(const KYOPRO_BASE_UINT\
    \ (&_d)[_n], _typeT&& _init) noexcept {\n    if constexpr (_idx < _n) return std::vector(_d[_idx],\
    \ make_vector<_idx + 1>(_d, std::forward<_typeT>(_init)));\n    else return _init;\n\
    \  }\n\n  template<class _typeT, KYOPRO_BASE_UINT _idx = 0, KYOPRO_BASE_UINT _n>\n\
    \  auto make_vector(const KYOPRO_BASE_UINT (&_d)[_n], const _typeT& _init = _typeT())\
    \ noexcept {\n    if constexpr (_idx < _n) return std::vector(_d[_idx], make_vector<_idx\
    \ + 1>(_d, _init));\n    else return _init;\n  }\n}\n"
  code: "#pragma once\n#include <cstdint>\n#include <utility>\n#include <vector>\n\
    #include \"../meta/settings.hpp\"\n\nnamespace kyopro {\n  template<KYOPRO_BASE_UINT\
    \ _idx = 0, KYOPRO_BASE_UINT _n, class _typeT>\n  auto make_vector(const KYOPRO_BASE_UINT\
    \ (&_d)[_n], _typeT&& _init) noexcept {\n    if constexpr (_idx < _n) return std::vector(_d[_idx],\
    \ make_vector<_idx + 1>(_d, std::forward<_typeT>(_init)));\n    else return _init;\n\
    \  }\n\n  template<class _typeT, KYOPRO_BASE_UINT _idx = 0, KYOPRO_BASE_UINT _n>\n\
    \  auto make_vector(const KYOPRO_BASE_UINT (&_d)[_n], const _typeT& _init = _typeT())\
    \ noexcept {\n    if constexpr (_idx < _n) return std::vector(_d[_idx], make_vector<_idx\
    \ + 1>(_d, _init));\n    else return _init;\n  }\n}"
  dependsOn:
  - meta/settings.hpp
  isVerificationFile: false
  path: template/make_vector.hpp
  requiredBy:
  - template/all.hpp
  - all/all.hpp
  timestamp: '2022-04-17 23:28:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/make_vector.hpp
layout: document
redirect_from:
- /library/template/make_vector.hpp
- /library/template/make_vector.hpp.html
title: template/make_vector.hpp
---
