---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: kyopro.hpp
    title: kyopro.hpp
  - icon: ':warning:'
    path: template/all.hpp
    title: template/all.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/min_max_different_types.hpp\"\n#include <algorithm>\n\
    #include <type_traits>\n\nusing std::min, std::max;\n\ntemplate<class T, class\
    \ U, std::enable_if_t<!std::is_same_v<T, U>>* = nullptr>\nconstexpr std::common_type_t<T,\
    \ U> min(const T& a, const U& b) noexcept {\n  return a < b ? a : b;\n}\n\ntemplate<class\
    \ T, class U, std::enable_if_t<!std::is_same_v<T, U>>* = nullptr>\nconstexpr std::common_type_t<T,\
    \ U> max(const T& a, const U& b) noexcept {\n  return a > b ? a : b;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <type_traits>\n\nusing std::min,\
    \ std::max;\n\ntemplate<class T, class U, std::enable_if_t<!std::is_same_v<T,\
    \ U>>* = nullptr>\nconstexpr std::common_type_t<T, U> min(const T& a, const U&\
    \ b) noexcept {\n  return a < b ? a : b;\n}\n\ntemplate<class T, class U, std::enable_if_t<!std::is_same_v<T,\
    \ U>>* = nullptr>\nconstexpr std::common_type_t<T, U> max(const T& a, const U&\
    \ b) noexcept {\n  return a > b ? a : b;\n}"
  dependsOn: []
  isVerificationFile: false
  path: template/min_max_different_types.hpp
  requiredBy:
  - kyopro.hpp
  - template/all.hpp
  timestamp: '2022-04-21 22:07:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/min_max_different_types.hpp
layout: document
redirect_from:
- /library/template/min_max_different_types.hpp
- /library/template/min_max_different_types.hpp.html
title: template/min_max_different_types.hpp
---
