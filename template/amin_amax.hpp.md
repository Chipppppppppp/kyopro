---
data:
  _extendedDependsOn: []
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
  bundledCode: "#line 2 \"template/amin_amax.hpp\"\n\nnamespace kyopro {\n  template<class\
    \ T, class U>\n  constexpr bool amin(T& a, U&& b) noexcept {\n    if (b < a) {\n\
    \      a = b;\n      return true;\n    }\n    return false;\n  }\n\n  template<class\
    \ T, class U>\n  constexpr bool amax(T& a, U&& b) noexcept {\n    if (a < b) {\n\
    \      a = b;\n      return true;\n    }\n    return false;\n  }\n}\n"
  code: "#pragma once\n\nnamespace kyopro {\n  template<class T, class U>\n  constexpr\
    \ bool amin(T& a, U&& b) noexcept {\n    if (b < a) {\n      a = b;\n      return\
    \ true;\n    }\n    return false;\n  }\n\n  template<class T, class U>\n  constexpr\
    \ bool amax(T& a, U&& b) noexcept {\n    if (a < b) {\n      a = b;\n      return\
    \ true;\n    }\n    return false;\n  }\n}"
  dependsOn: []
  isVerificationFile: false
  path: template/amin_amax.hpp
  requiredBy:
  - template/all.hpp
  - all/all.hpp
  timestamp: '2022-04-21 22:07:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/amin_amax.hpp
layout: document
redirect_from:
- /library/template/amin_amax.hpp
- /library/template/amin_amax.hpp.html
title: template/amin_amax.hpp
---
