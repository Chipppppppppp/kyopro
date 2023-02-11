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
  - icon: ':warning:'
    path: verify/hello_world.cpp
    title: verify/hello_world.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/amin_amax.hpp\"\n\r\nnamespace kpr {\r\n    template<class\
    \ T, class U = T>\r\n    constexpr bool amin(T& a, const U& b) noexcept {\r\n\
    \        if (b < a) {\r\n            a = b;\r\n            return true;\r\n  \
    \      }\r\n        return false;\r\n    }\r\n\r\n    template<class T, class\
    \ U = T>\r\n    constexpr bool amax(T& a, const U& b) noexcept {\r\n        if\
    \ (a < b) {\r\n            a = b;\r\n            return true;\r\n        }\r\n\
    \        return false;\r\n    }\r\n} // namespace kpr\r\n"
  code: "#pragma once\r\n\r\nnamespace kpr {\r\n    template<class T, class U = T>\r\
    \n    constexpr bool amin(T& a, const U& b) noexcept {\r\n        if (b < a) {\r\
    \n            a = b;\r\n            return true;\r\n        }\r\n        return\
    \ false;\r\n    }\r\n\r\n    template<class T, class U = T>\r\n    constexpr bool\
    \ amax(T& a, const U& b) noexcept {\r\n        if (a < b) {\r\n            a =\
    \ b;\r\n            return true;\r\n        }\r\n        return false;\r\n   \
    \ }\r\n} // namespace kpr\r\n"
  dependsOn: []
  isVerificationFile: false
  path: template/amin_amax.hpp
  requiredBy:
  - verify/hello_world.cpp
  - template/template.hpp
  - all.hpp
  timestamp: '2023-02-11 02:36:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/amin_amax.hpp
layout: document
redirect_from:
- /library/template/amin_amax.hpp
- /library/template/amin_amax.hpp.html
title: template/amin_amax.hpp
---
