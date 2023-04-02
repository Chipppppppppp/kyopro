---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"kyopro/template/chmin_chmax.hpp\"\n\r\nnamespace kpr {\r\
    \n    // assign min\r\n    [[maybe_unused]] inline constexpr struct {\r\n    \
    \    template<class T, class U = T>\r\n        constexpr bool operator ()(T& a,\
    \ const U& b) noexcept {\r\n            if (a > b) {\r\n                a = b;\r\
    \n                return true;\r\n            }\r\n            return false;\r\
    \n        }\r\n    } chmin;\r\n\r\n    // assign max\r\n    [[maybe_unused]] inline\
    \ constexpr struct {\r\n        template<class T, class U = T>\r\n        constexpr\
    \ bool operator ()(T& a, const U& b) noexcept {\r\n            if (a < b) {\r\n\
    \                a = b;\r\n                return true;\r\n            }\r\n \
    \           return false;\r\n        }\r\n    } chmax;\r\n} // namespace kpr\r\
    \n"
  code: "#pragma once\r\n\r\nnamespace kpr {\r\n    // assign min\r\n    [[maybe_unused]]\
    \ inline constexpr struct {\r\n        template<class T, class U = T>\r\n    \
    \    constexpr bool operator ()(T& a, const U& b) noexcept {\r\n            if\
    \ (a > b) {\r\n                a = b;\r\n                return true;\r\n    \
    \        }\r\n            return false;\r\n        }\r\n    } chmin;\r\n\r\n \
    \   // assign max\r\n    [[maybe_unused]] inline constexpr struct {\r\n      \
    \  template<class T, class U = T>\r\n        constexpr bool operator ()(T& a,\
    \ const U& b) noexcept {\r\n            if (a < b) {\r\n                a = b;\r\
    \n                return true;\r\n            }\r\n            return false;\r\
    \n        }\r\n    } chmax;\r\n} // namespace kpr\r\n"
  dependsOn: []
  isVerificationFile: false
  path: kyopro/template/chmin_chmax.hpp
  requiredBy: []
  timestamp: '2023-04-02 20:21:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kyopro/template/chmin_chmax.hpp
layout: document
redirect_from:
- /library/kyopro/template/chmin_chmax.hpp
- /library/kyopro/template/chmin_chmax.hpp.html
title: kyopro/template/chmin_chmax.hpp
---
