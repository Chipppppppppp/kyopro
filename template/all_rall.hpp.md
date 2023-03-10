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
  - icon: ':warning:'
    path: test.cpp
    title: test.cpp
  - icon: ':warning:'
    path: verify/hello_world.cpp
    title: verify/hello_world.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: '#line 2 "template/all_rall.hpp"

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
  path: template/all_rall.hpp
  requiredBy:
  - all.hpp
  - test.cpp
  - verify/hello_world.cpp
  - template/template.hpp
  - template/macro.hpp
  timestamp: '2023-02-19 20:41:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/all_rall.hpp
layout: document
redirect_from:
- /library/template/all_rall.hpp
- /library/template/all_rall.hpp.html
title: template/all_rall.hpp
---
