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
  bundledCode: "#line 2 \"template/amin_amax.hpp\"\n\nnamespace kpr {\n    template<class\
    \ T, class U = T>\n    constexpr bool amin(T& a, const U& b) noexcept {\n    \
    \    if (b < a) {\n            a = b;\n            return true;\n        }\n \
    \       return false;\n    }\n\n    template<class T, class U = T>\n    constexpr\
    \ bool amax(T& a, const U& b) noexcept {\n        if (a < b) {\n            a\
    \ = b;\n            return true;\n        }\n        return false;\n    }\n} //\
    \ namespace kpr\n"
  code: "#pragma once\n\nnamespace kpr {\n    template<class T, class U = T>\n   \
    \ constexpr bool amin(T& a, const U& b) noexcept {\n        if (b < a) {\n   \
    \         a = b;\n            return true;\n        }\n        return false;\n\
    \    }\n\n    template<class T, class U = T>\n    constexpr bool amax(T& a, const\
    \ U& b) noexcept {\n        if (a < b) {\n            a = b;\n            return\
    \ true;\n        }\n        return false;\n    }\n} // namespace kpr\n"
  dependsOn: []
  isVerificationFile: false
  path: template/amin_amax.hpp
  requiredBy:
  - template/template.hpp
  - all.hpp
  timestamp: '2023-02-01 00:00:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/amin_amax.hpp
layout: document
redirect_from:
- /library/template/amin_amax.hpp
- /library/template/amin_amax.hpp.html
title: template/amin_amax.hpp
---
