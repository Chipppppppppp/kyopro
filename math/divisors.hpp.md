---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: meta/setting.hpp
    title: meta/setting.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  - icon: ':warning:'
    path: all/all.hpp
    title: all/all.hpp
  - icon: ':warning:'
    path: math/math.hpp
    title: math/math.hpp
  - icon: ':warning:'
    path: verify/hello_world.cpp
    title: verify/hello_world.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/divisors.hpp\"\n#include <cstdint>\r\n#include <vector>\r\
    \n#line 3 \"meta/setting.hpp\"\n\r\n#ifndef KYOPRO_BASE_INT\r\n// \u57FA\u672C\
    \u7B26\u53F7\u4ED8\u304D\u6574\u6570\u578B\r\n#define KYOPRO_BASE_INT std::int64_t\r\
    \n#endif\r\n\r\n#ifndef KYOPRO_BASE_UINT\r\n// \u57FA\u672C\u7B26\u53F7\u306A\u3057\
    \u6574\u6570\u578B\r\n#define KYOPRO_BASE_UINT std::uint64_t\r\n#endif\r\n\r\n\
    #ifndef KYOPRO_BASE_FLOAT\r\n// \u57FA\u672C\u6D6E\u52D5\u5C0F\u6570\u70B9\u6570\
    \u578B\r\n#define KYOPRO_BASE_FLOAT double\r\n#endif\r\n\r\n#ifndef KYOPRO_DEFAULT_MOD\r\
    \n// \u554F\u984C\u3067\u8A2D\u5B9A\u3055\u308C\u305Fmod\r\n#define KYOPRO_DEFAULT_MOD\
    \ (static_cast<KYOPRO_BASE_UINT>(998244353))\r\n#endif\r\n\r\n#ifndef KYOPRO_DECIMAL_PRECISION\r\
    \n// \u5C0F\u6570\u7CBE\u5EA6(\u6841)\r\n#define KYOPRO_DECIMAL_PRECISION (static_cast<KYOPRO_BASE_UINT>(12))\r\
    \n#endif\r\n\r\n#ifndef KYOPRO_INF_DIV\r\n// \u7121\u9650\u5927\u3092\u8868\u3059\
    \u6574\u6570\u304C\u6700\u5927\u5024\u306E\u4F55\u5206\u306E\u4E00\u304B\u3092\
    \u8868\u3059\r\n#define KYOPRO_INF_DIV (static_cast<KYOPRO_BASE_UINT>(3))\r\n\
    #endif\r\n\r\n#ifndef KYOPRO_BUFFER_SIZE\r\n// \u30C7\u30D5\u30A9\u30EB\u30C8\u306E\
    \u30D0\u30C3\u30D5\u30A1\u30B5\u30A4\u30BA\r\n#define KYOPRO_BUFFER_SIZE (static_cast<KYOPRO_BASE_UINT>(2048))\r\
    \n#endif\r\n#line 5 \"math/divisors.hpp\"\n\r\nnamespace kpr {\r\n    // \u5168\
    \u3066\u306E\u6B63\u306E\u7D04\u6570\u3092\u8FD4\u3059\r\n    [[maybe_unused]]\
    \ inline constexpr struct {\r\n        std::vector<KYOPRO_BASE_INT> operator ()(std::uint_fast64_t\
    \ n) const {\r\n            std::vector<KYOPRO_BASE_INT> lower, upper;\r\n   \
    \         std::uint_fast64_t i;\r\n            for (i = 1; i * i < n; ++i) if\
    \ (n % i == 0) {\r\n                lower.emplace_back(i);\r\n               \
    \ upper.emplace_back(n / i);\r\n            }\r\n            if (i * i == n) lower.emplace_back(i);\r\
    \n            lower.insert(end(lower), upper.rbegin(), upper.rend());\r\n    \
    \        return lower;\r\n        }\r\n    } divisors;\r\n} // namespace kpr\r\
    \n"
  code: "#pragma once\r\n#include <cstdint>\r\n#include <vector>\r\n#include \"../meta/setting.hpp\"\
    \r\n\r\nnamespace kpr {\r\n    // \u5168\u3066\u306E\u6B63\u306E\u7D04\u6570\u3092\
    \u8FD4\u3059\r\n    [[maybe_unused]] inline constexpr struct {\r\n        std::vector<KYOPRO_BASE_INT>\
    \ operator ()(std::uint_fast64_t n) const {\r\n            std::vector<KYOPRO_BASE_INT>\
    \ lower, upper;\r\n            std::uint_fast64_t i;\r\n            for (i = 1;\
    \ i * i < n; ++i) if (n % i == 0) {\r\n                lower.emplace_back(i);\r\
    \n                upper.emplace_back(n / i);\r\n            }\r\n            if\
    \ (i * i == n) lower.emplace_back(i);\r\n            lower.insert(end(lower),\
    \ upper.rbegin(), upper.rend());\r\n            return lower;\r\n        }\r\n\
    \    } divisors;\r\n} // namespace kpr\r\n"
  dependsOn:
  - meta/setting.hpp
  isVerificationFile: false
  path: math/divisors.hpp
  requiredBy:
  - all/all.hpp
  - verify/hello_world.cpp
  - math/math.hpp
  - all.hpp
  timestamp: '2023-02-11 02:36:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/divisors.hpp
layout: document
redirect_from:
- /library/math/divisors.hpp
- /library/math/divisors.hpp.html
title: math/divisors.hpp
---
