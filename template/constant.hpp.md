---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: meta/setting.hpp
    title: "\u57FA\u672C\u7B26\u53F7\u4ED8\u304D\u6574\u6570\u578B"
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  - icon: ':warning:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/constant.hpp\"\n#include <array>\n#line 2 \"meta/setting.hpp\"\
    \n#include <cstdint>\n\n#ifndef KYOPRO_BASE_INT\n/// @brief \u57FA\u672C\u7B26\
    \u53F7\u4ED8\u304D\u6574\u6570\u578B\n#define KYOPRO_BASE_INT std::int64_t\n#endif\n\
    \n#ifndef KYOPRO_BASE_UINT\n/// @brief \u57FA\u672C\u7B26\u53F7\u306A\u3057\u6574\
    \u6570\u578B\n#define KYOPRO_BASE_UINT std::uint64_t\n#endif\n\n#ifndef KYOPRO_BASE_FLOAT\n\
    /// @brief \u57FA\u672C\u6D6E\u52D5\u5C0F\u6570\u70B9\u6570\u578B\n#define KYOPRO_BASE_FLOAT\
    \ double\n#endif\n\n#ifndef KYOPRO_DEFAULT_MOD\n/// @brief \u554F\u984C\u3067\u8A2D\
    \u5B9A\u3055\u308C\u305Fmod\n#define KYOPRO_DEFAULT_MOD (static_cast<KYOPRO_BASE_UINT>(998244353))\n\
    #endif\n\n#ifndef KYOPRO_DECIMAL_PRECISION\n/// @brief \u5C0F\u6570\u7CBE\u5EA6\
    (\u6841)\n#define KYOPRO_DECIMAL_PRECISION (static_cast<KYOPRO_BASE_UINT>(12))\n\
    #endif\n\n#ifndef KYOPRO_INF_DIV\n/// @brief \u7121\u9650\u5927\u3092\u8868\u3059\
    \u6574\u6570\u304C\u6700\u5927\u5024\u306E\u4F55\u5206\u306E\u4E00\u304B\u3092\
    \u8868\u3059\n#define KYOPRO_INF_DIV (static_cast<KYOPRO_BASE_UINT>(3))\n#endif\n\
    \n#ifndef KYOPRO_BUFFER_SIZE\n/// @brief \u30C7\u30D5\u30A9\u30EB\u30C8\u306E\u30D0\
    \u30C3\u30D5\u30A1\u30B5\u30A4\u30BA\n#define KYOPRO_BUFFER_SIZE (static_cast<KYOPRO_BASE_UINT>(2048))\n\
    #endif\n#line 4 \"template/constant.hpp\"\n\nnamespace kpr {\n    inline constexpr\
    \ std::array<std::pair<KYOPRO_BASE_INT, KYOPRO_BASE_INT>, 4> beside{{{-1, 0},\
    \ {0, -1}, {1, 0}, {0, 1}}};\n    inline constexpr std::array<std::pair<KYOPRO_BASE_INT,\
    \ KYOPRO_BASE_INT>, 8> around{{{-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1,\
    \ 1}, {0, 1}, {-1, 1}}};\n} // namespace kpr\n"
  code: "#pragma once\n#include <array>\n#include \"../meta/setting.hpp\"\n\nnamespace\
    \ kpr {\n    inline constexpr std::array<std::pair<KYOPRO_BASE_INT, KYOPRO_BASE_INT>,\
    \ 4> beside{{{-1, 0}, {0, -1}, {1, 0}, {0, 1}}};\n    inline constexpr std::array<std::pair<KYOPRO_BASE_INT,\
    \ KYOPRO_BASE_INT>, 8> around{{{-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1,\
    \ 1}, {0, 1}, {-1, 1}}};\n} // namespace kpr\n"
  dependsOn:
  - meta/setting.hpp
  isVerificationFile: false
  path: template/constant.hpp
  requiredBy:
  - template/template.hpp
  - all.hpp
  timestamp: '2023-02-01 00:00:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/constant.hpp
layout: document
redirect_from:
- /library/template/constant.hpp
- /library/template/constant.hpp.html
title: template/constant.hpp
---
