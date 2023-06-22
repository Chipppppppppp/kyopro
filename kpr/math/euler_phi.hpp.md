---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: kpr/meta/setting.hpp
    title: kpr/meta/setting.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: kpr/all.hpp
    title: kpr/all.hpp
  - icon: ':warning:'
    path: kpr/all/all.hpp
    title: kpr/all/all.hpp
  - icon: ':warning:'
    path: kpr/math/math.hpp
    title: kpr/math/math.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"kpr/math/euler_phi.hpp\"\n#include <cstdint>\r\n#line 3\
    \ \"kpr/meta/setting.hpp\"\n\r\n#ifndef KYOPRO_BASE_INT\r\n// \u57FA\u672C\u7B26\
    \u53F7\u4ED8\u304D\u6574\u6570\u578B\r\n#define KYOPRO_BASE_INT std::int64_t\r\
    \n#endif\r\n\r\n#ifndef KYOPRO_BASE_UINT\r\n// \u57FA\u672C\u7B26\u53F7\u306A\u3057\
    \u6574\u6570\u578B\r\n#define KYOPRO_BASE_UINT std::uint64_t\r\n#endif\r\n\r\n\
    #ifndef KYOPRO_BASE_FLOAT\r\n// \u57FA\u672C\u6D6E\u52D5\u5C0F\u6570\u70B9\u6570\
    \u578B\r\n#define KYOPRO_BASE_FLOAT double\r\n#endif\r\n\r\n#ifndef KYOPRO_LL\r\
    \n// ll\r\n#define KYOPRO_LL long long\r\n#endif\r\n\r\n#ifndef KYOPRO_LF\r\n\
    // lf\r\n#define KYOPRO_LF double\r\n#endif\r\n\r\n#ifndef KYOPRO_MINT\r\n// mint\r\
    \n#define KYOPRO_MINT kpr::ModInt<mod>\r\n#endif\r\n\r\n#ifndef KYOPRO_DEFAULT_MOD\r\
    \n// \u554F\u984C\u3067\u8A2D\u5B9A\u3055\u308C\u305Fmod\r\n#define KYOPRO_DEFAULT_MOD\
    \ (static_cast<KYOPRO_BASE_UINT>(998244353))\r\n#endif\r\n\r\n#ifndef KYOPRO_DECIMAL_PRECISION\r\
    \n// \u5C0F\u6570\u7CBE\u5EA6(\u6841)\r\n#define KYOPRO_DECIMAL_PRECISION (static_cast<KYOPRO_BASE_UINT>(12))\r\
    \n#endif\r\n\r\n#ifndef KYOPRO_INF_DIV\r\n// \u7121\u9650\u5927\u3092\u8868\u3059\
    \u6574\u6570\u304C\u6700\u5927\u5024\u306E\u4F55\u5206\u306E\u4E00\u304B\u3092\
    \u8868\u3059\r\n#define KYOPRO_INF_DIV (static_cast<KYOPRO_BASE_UINT>(3))\r\n\
    #endif\r\n\r\n#ifndef KYOPRO_BUFFER_SIZE\r\n// \u30C7\u30D5\u30A9\u30EB\u30C8\u306E\
    \u30D0\u30C3\u30D5\u30A1\u30B5\u30A4\u30BA\r\n#define KYOPRO_BUFFER_SIZE (static_cast<KYOPRO_BASE_UINT>(2048))\r\
    \n#endif\r\n\r\n#ifndef KYOPRO_BINOM_MOD_MAX\r\n// \u30C7\u30D5\u30A9\u30EB\u30C8\
    \u306EBinomMod\u306E\u8A08\u7B97\u4E0A\u9650\r\n#define KYOPRO_BINOM_MOD_MAX (static_cast<KYOPRO_BASE_UINT>(1000000))\r\
    \n#endif\r\n#line 4 \"kpr/math/euler_phi.hpp\"\n\r\nnamespace kpr {\r\n    //\
    \ \u30AA\u30A4\u30E9\u30FC\u306E\u03C6\u95A2\u6570\r\n    [[maybe_unused]] inline\
    \ constexpr struct {\r\n        constexpr KYOPRO_BASE_INT operator ()(std::uint_fast64_t\
    \ n) const noexcept {\r\n            std::uint_fast64_t res = n;\r\n         \
    \   if ((n & 1) == 0) {\r\n                res -= res >> 1;\r\n              \
    \  n >>= 1;\r\n                while ((n & 1) == 0) n >>= 1;\r\n            }\r\
    \n            for (std::uint_fast64_t i = 3; i * i <= n; i += 2) {\r\n       \
    \         if (n % i == 0) {\r\n                res -= res / i;\r\n           \
    \     n /= i;\r\n                while (n % i == 0) n /= i;\r\n              \
    \  }\r\n            }\r\n            if (n != 1) res -= res / n;\r\n         \
    \   return res;\r\n        }\r\n    } euler_phi;\r\n} // namespace kpr\r\n"
  code: "#pragma once\r\n#include <cstdint>\r\n#include \"../meta/setting.hpp\"\r\n\
    \r\nnamespace kpr {\r\n    // \u30AA\u30A4\u30E9\u30FC\u306E\u03C6\u95A2\u6570\
    \r\n    [[maybe_unused]] inline constexpr struct {\r\n        constexpr KYOPRO_BASE_INT\
    \ operator ()(std::uint_fast64_t n) const noexcept {\r\n            std::uint_fast64_t\
    \ res = n;\r\n            if ((n & 1) == 0) {\r\n                res -= res >>\
    \ 1;\r\n                n >>= 1;\r\n                while ((n & 1) == 0) n >>=\
    \ 1;\r\n            }\r\n            for (std::uint_fast64_t i = 3; i * i <= n;\
    \ i += 2) {\r\n                if (n % i == 0) {\r\n                res -= res\
    \ / i;\r\n                n /= i;\r\n                while (n % i == 0) n /= i;\r\
    \n                }\r\n            }\r\n            if (n != 1) res -= res / n;\r\
    \n            return res;\r\n        }\r\n    } euler_phi;\r\n} // namespace kpr\r\
    \n"
  dependsOn:
  - kpr/meta/setting.hpp
  isVerificationFile: false
  path: kpr/math/euler_phi.hpp
  requiredBy:
  - kpr/math/math.hpp
  - kpr/all/all.hpp
  - kpr/all.hpp
  timestamp: '2023-05-30 09:27:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kpr/math/euler_phi.hpp
layout: document
redirect_from:
- /library/kpr/math/euler_phi.hpp
- /library/kpr/math/euler_phi.hpp.html
title: kpr/math/euler_phi.hpp
---