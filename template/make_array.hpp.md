---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: meta/settings.hpp
    title: meta/settings.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: template/all.hpp
    title: template/all.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/make_array.hpp\"\n#include <array>\n#line 2 \"\
    meta/settings.hpp\"\n#include <cstdint>\n\n#ifndef KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT\
    \ std::int64_t\n#endif\n\n#ifndef KYOPRO_BASE_UINT\n#define KYOPRO_BASE_UINT std::uint64_t\n\
    #endif\n\n#ifndef KYOPRO_BASE_FLOAT\n#define KYOPRO_BASE_FLOAT double\n#endif\n\
    \n#ifndef KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD static_cast<KYOPRO_BASE_UINT>(998244353)\n\
    #endif\n\n#ifndef KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n\
    #endif\n\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 4 \"template/make_array.hpp\"\n\nnamespace kyopro {\n    inline\
    \ constexpr struct {\n        template<class T>\n        constexpr auto operator\
    \ ()(const T& init = T()) noexcept {\n            return init;\n        }\n\n\
    \        template<class T, KYOPRO_BASE_UINT length, KYOPRO_BASE_UINT... lengths>\n\
    \        constexpr auto operator ()(const T& init = T()) noexcept {\n        \
    \    auto elm = operator ()<T, lengths...>(init);\n            std::array<decltype(elm),\
    \ length> res;\n            for (auto& i: res) i = elm;\n            return res;\n\
    \        }\n    } make_array;\n} // namespace kyopro\n"
  code: "#pragma once\n#include <array>\n#include \"../meta/settings.hpp\"\n\nnamespace\
    \ kyopro {\n    inline constexpr struct {\n        template<class T>\n       \
    \ constexpr auto operator ()(const T& init = T()) noexcept {\n            return\
    \ init;\n        }\n\n        template<class T, KYOPRO_BASE_UINT length, KYOPRO_BASE_UINT...\
    \ lengths>\n        constexpr auto operator ()(const T& init = T()) noexcept {\n\
    \            auto elm = operator ()<T, lengths...>(init);\n            std::array<decltype(elm),\
    \ length> res;\n            for (auto& i: res) i = elm;\n            return res;\n\
    \        }\n    } make_array;\n} // namespace kyopro"
  dependsOn:
  - meta/settings.hpp
  isVerificationFile: false
  path: template/make_array.hpp
  requiredBy:
  - template/all.hpp
  timestamp: '2022-07-28 17:38:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/make_array.hpp
layout: document
redirect_from:
- /library/template/make_array.hpp
- /library/template/make_array.hpp.html
title: template/make_array.hpp
---
