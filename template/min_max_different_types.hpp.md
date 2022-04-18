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
  bundledCode: "#line 2 \"template/min_max_different_types.hpp\"\n#include <algorithm>\n\
    #include <type_traits>\n\nusing std::min, std::max;\n\ntemplate<class _typeT,\
    \ class _typeU, std::enable_if_t<!std::is_same_v<_typeT, _typeU>>* = nullptr>\n\
    constexpr std::common_type_t<_typeT, _typeU> min(const _typeT& a, const _typeU&\
    \ b) noexcept {\n  return a < b ? a : b;\n}\n\ntemplate<class _typeT, class _typeU,\
    \ std::enable_if_t<!std::is_same_v<_typeT, _typeU>>* = nullptr>\nconstexpr std::common_type_t<_typeT,\
    \ _typeU> max(const _typeT& a, const _typeU& b) noexcept {\n  return a > b ? a\
    \ : b;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <type_traits>\n\nusing std::min,\
    \ std::max;\n\ntemplate<class _typeT, class _typeU, std::enable_if_t<!std::is_same_v<_typeT,\
    \ _typeU>>* = nullptr>\nconstexpr std::common_type_t<_typeT, _typeU> min(const\
    \ _typeT& a, const _typeU& b) noexcept {\n  return a < b ? a : b;\n}\n\ntemplate<class\
    \ _typeT, class _typeU, std::enable_if_t<!std::is_same_v<_typeT, _typeU>>* = nullptr>\n\
    constexpr std::common_type_t<_typeT, _typeU> max(const _typeT& a, const _typeU&\
    \ b) noexcept {\n  return a > b ? a : b;\n}"
  dependsOn: []
  isVerificationFile: false
  path: template/min_max_different_types.hpp
  requiredBy:
  - template/all.hpp
  - all/all.hpp
  timestamp: '2022-04-18 12:13:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/min_max_different_types.hpp
layout: document
redirect_from:
- /library/template/min_max_different_types.hpp
- /library/template/min_max_different_types.hpp.html
title: template/min_max_different_types.hpp
---
