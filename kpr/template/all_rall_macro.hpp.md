---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: kpr/all.hpp
    title: kpr/all.hpp
  - icon: ':warning:'
    path: kpr/template/macro.hpp
    title: kpr/template/macro.hpp
  - icon: ':warning:'
    path: kpr/template/template.hpp
    title: kpr/template/template.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: '#line 2 "kpr/template/all_rall_macro.hpp"

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
  path: kpr/template/all_rall_macro.hpp
  requiredBy:
  - kpr/template/macro.hpp
  - kpr/template/template.hpp
  - kpr/all.hpp
  timestamp: '2023-04-04 01:42:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kpr/template/all_rall_macro.hpp
layout: document
redirect_from:
- /library/kpr/template/all_rall_macro.hpp
- /library/kpr/template/all_rall_macro.hpp.html
title: kpr/template/all_rall_macro.hpp
---
