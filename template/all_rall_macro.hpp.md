---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  - icon: ':warning:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':warning:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: '#line 2 "template/all_rall_macro.hpp"

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
  path: template/all_rall_macro.hpp
  requiredBy:
  - all.hpp
  - template/template.hpp
  - template/macro.hpp
  timestamp: '2023-03-29 16:54:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/all_rall_macro.hpp
layout: document
redirect_from:
- /library/template/all_rall_macro.hpp
- /library/template/all_rall_macro.hpp.html
title: template/all_rall_macro.hpp
---
