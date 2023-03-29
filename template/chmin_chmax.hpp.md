---
data:
  _extendedDependsOn: []
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
  bundledCode: "#line 2 \"template/chmin_chmax.hpp\"\n\r\nnamespace kpr {\r\n    //\
    \ min assign\r\n    template<class T, class U = T>\r\n    constexpr bool chmin(T&\
    \ a, const U& b) noexcept {\r\n        if (b < a) {\r\n            a = b;\r\n\
    \            return true;\r\n        }\r\n        return false;\r\n    }\r\n\r\
    \n    // max assign\r\n    template<class T, class U = T>\r\n    constexpr bool\
    \ chmax(T& a, const U& b) noexcept {\r\n        if (a < b) {\r\n            a\
    \ = b;\r\n            return true;\r\n        }\r\n        return false;\r\n \
    \   }\r\n} // namespace kpr\r\n"
  code: "#pragma once\r\n\r\nnamespace kpr {\r\n    // min assign\r\n    template<class\
    \ T, class U = T>\r\n    constexpr bool chmin(T& a, const U& b) noexcept {\r\n\
    \        if (b < a) {\r\n            a = b;\r\n            return true;\r\n  \
    \      }\r\n        return false;\r\n    }\r\n\r\n    // max assign\r\n    template<class\
    \ T, class U = T>\r\n    constexpr bool chmax(T& a, const U& b) noexcept {\r\n\
    \        if (a < b) {\r\n            a = b;\r\n            return true;\r\n  \
    \      }\r\n        return false;\r\n    }\r\n} // namespace kpr\r\n"
  dependsOn: []
  isVerificationFile: false
  path: template/chmin_chmax.hpp
  requiredBy:
  - all.hpp
  - template/template.hpp
  timestamp: '2023-03-29 16:52:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/chmin_chmax.hpp
layout: document
redirect_from:
- /library/template/chmin_chmax.hpp
- /library/template/chmin_chmax.hpp.html
title: template/chmin_chmax.hpp
---
