---
data:
  _extendedDependsOn:
  - icon: ':question:'
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
    \ idx = 0, KYOPRO_BASE_UINT n, class T>\n  auto make_vector(const KYOPRO_BASE_UINT\
    \ (&d)[n], T&& init) noexcept {\n    if constexpr (idx < n) return std::vector(d[idx],\
    \ make_vector<idx + 1>(d, std::forward<T>(init)));\n    else return init;\n  }\n\
    \n  template<class T, KYOPRO_BASE_UINT idx = 0, KYOPRO_BASE_UINT n>\n  auto make_vector(const\
    \ KYOPRO_BASE_UINT (&d)[n], const T& init = T()) noexcept {\n    if constexpr\
    \ (idx < n) return std::vector(d[idx], make_vector<idx + 1>(d, init));\n    else\
    \ return init;\n  }\n}\n"
  code: "#pragma once\n#include <cstdint>\n#include <utility>\n#include <vector>\n\
    #include \"../meta/settings.hpp\"\n\nnamespace kyopro {\n  template<KYOPRO_BASE_UINT\
    \ idx = 0, KYOPRO_BASE_UINT n, class T>\n  auto make_vector(const KYOPRO_BASE_UINT\
    \ (&d)[n], T&& init) noexcept {\n    if constexpr (idx < n) return std::vector(d[idx],\
    \ make_vector<idx + 1>(d, std::forward<T>(init)));\n    else return init;\n  }\n\
    \n  template<class T, KYOPRO_BASE_UINT idx = 0, KYOPRO_BASE_UINT n>\n  auto make_vector(const\
    \ KYOPRO_BASE_UINT (&d)[n], const T& init = T()) noexcept {\n    if constexpr\
    \ (idx < n) return std::vector(d[idx], make_vector<idx + 1>(d, init));\n    else\
    \ return init;\n  }\n}"
  dependsOn:
  - meta/settings.hpp
  isVerificationFile: false
  path: template/make_vector.hpp
  requiredBy:
  - template/all.hpp
  - all/all.hpp
  timestamp: '2022-04-21 22:07:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/make_vector.hpp
layout: document
redirect_from:
- /library/template/make_vector.hpp
- /library/template/make_vector.hpp.html
title: template/make_vector.hpp
---
