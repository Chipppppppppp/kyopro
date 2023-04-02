---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: kyopro/all.hpp
    title: kyopro/all.hpp
  - icon: ':warning:'
    path: kyopro/template/macro.hpp
    title: kyopro/template/macro.hpp
  - icon: ':warning:'
    path: kyopro/template/template.hpp
    title: kyopro/template/template.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: '#line 2 "kyopro/template/all_rall_macro.hpp"

    #include <iterator>


    #define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)

    #define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)

    '
  code: '#pragma once

    #include <iterator>


    #define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)

    #define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)

    '
  dependsOn: []
  isVerificationFile: false
  path: kyopro/template/all_rall_macro.hpp
  requiredBy:
  - kyopro/all.hpp
  - kyopro/template/template.hpp
  - kyopro/template/macro.hpp
  timestamp: '2023-04-02 21:40:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kyopro/template/all_rall_macro.hpp
layout: document
redirect_from:
- /library/kyopro/template/all_rall_macro.hpp
- /library/kyopro/template/all_rall_macro.hpp.html
title: kyopro/template/all_rall_macro.hpp
---
