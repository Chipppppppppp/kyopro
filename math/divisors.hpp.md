---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: meta/setting.hpp
    title: "\u57FA\u672C\u7B26\u53F7\u4ED8\u304D\u6574\u6570\u578B"
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/math.hpp
    title: math/math.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/divisors.hpp\"\n#include <cstdint>\n#include <vector>\n\
    #line 3 \"meta/setting.hpp\"\n\n#ifndef KYOPRO_BASE_INT\n/// @brief \u57FA\u672C\
    \u7B26\u53F7\u4ED8\u304D\u6574\u6570\u578B\n#define KYOPRO_BASE_INT std::int64_t\n\
    #endif\n\n#ifndef KYOPRO_BASE_UINT\n/// @brief \u57FA\u672C\u7B26\u53F7\u306A\u3057\
    \u6574\u6570\u578B\n#define KYOPRO_BASE_UINT std::uint64_t\n#endif\n\n#ifndef\
    \ KYOPRO_BASE_FLOAT\n/// @brief \u57FA\u672C\u6D6E\u52D5\u5C0F\u6570\u70B9\u6570\
    \u578B\n#define KYOPRO_BASE_FLOAT double\n#endif\n\n#ifndef KYOPRO_DEFAULT_MOD\n\
    /// @brief \u554F\u984C\u3067\u8A2D\u5B9A\u3055\u308C\u305Fmod\n#define KYOPRO_DEFAULT_MOD\
    \ (static_cast<KYOPRO_BASE_UINT>(998244353))\n#endif\n\n#ifndef KYOPRO_DECIMAL_PRECISION\n\
    /// @brief \u5C0F\u6570\u7CBE\u5EA6(\u6841)\n#define KYOPRO_DECIMAL_PRECISION\
    \ (static_cast<KYOPRO_BASE_UINT>(12))\n#endif\n\n#ifndef KYOPRO_INF_DIV\n/// @brief\
    \ \u7121\u9650\u5927\u3092\u8868\u3059\u6574\u6570\u304C\u6700\u5927\u5024\u306E\
    \u4F55\u5206\u306E\u4E00\u304B\u3092\u8868\u3059\n#define KYOPRO_INF_DIV (static_cast<KYOPRO_BASE_UINT>(3))\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n/// @brief \u30C7\u30D5\u30A9\u30EB\u30C8\
    \u306E\u30D0\u30C3\u30D5\u30A1\u30B5\u30A4\u30BA\n#define KYOPRO_BUFFER_SIZE (static_cast<KYOPRO_BASE_UINT>(2048))\n\
    #endif\n#line 5 \"math/divisors.hpp\"\n\nnamespace kpr {\n    // \u5168\u3066\u306E\
    \u6B63\u306E\u7D04\u6570\u3092\u8FD4\u3059\n    [[maybe_unused]] inline constexpr\
    \ struct {\n        std::vector<KYOPRO_BASE_INT> operator ()(std::uint_fast64_t\
    \ n) const {\n            std::vector<KYOPRO_BASE_INT> lower, upper;\n       \
    \     std::uint_fast64_t i;\n            for (i = 1; i * i < n; ++i) if (n % i\
    \ == 0) {\n                lower.emplace_back(i);\n                upper.emplace_back(n\
    \ / i);\n            }\n            if (i * i == n) lower.emplace_back(i);\n \
    \           lower.insert(end(lower), upper.rbegin(), upper.rend());\n        \
    \    return lower;\n        }\n    } divisors;\n} // namespace kpr\n"
  code: "#pragma once\n#include <cstdint>\n#include <vector>\n#include \"../meta/setting.hpp\"\
    \n\nnamespace kpr {\n    // \u5168\u3066\u306E\u6B63\u306E\u7D04\u6570\u3092\u8FD4\
    \u3059\n    [[maybe_unused]] inline constexpr struct {\n        std::vector<KYOPRO_BASE_INT>\
    \ operator ()(std::uint_fast64_t n) const {\n            std::vector<KYOPRO_BASE_INT>\
    \ lower, upper;\n            std::uint_fast64_t i;\n            for (i = 1; i\
    \ * i < n; ++i) if (n % i == 0) {\n                lower.emplace_back(i);\n  \
    \              upper.emplace_back(n / i);\n            }\n            if (i *\
    \ i == n) lower.emplace_back(i);\n            lower.insert(end(lower), upper.rbegin(),\
    \ upper.rend());\n            return lower;\n        }\n    } divisors;\n} //\
    \ namespace kpr\n"
  dependsOn:
  - meta/setting.hpp
  isVerificationFile: false
  path: math/divisors.hpp
  requiredBy:
  - math/math.hpp
  timestamp: '2023-02-01 00:00:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/divisors.hpp
layout: document
redirect_from:
- /library/math/divisors.hpp
- /library/math/divisors.hpp.html
title: math/divisors.hpp
---
