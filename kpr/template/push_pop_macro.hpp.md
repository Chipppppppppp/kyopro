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
  bundledCode: '#line 2 "kpr/template/push_pop_macro.hpp"


    #define pushf(...) emplace_front(__VA_ARGS__)

    #define popf(...) pop_front(__VA_ARGS__)

    #define pushb(...) emplace_back(__VA_ARGS__)

    #define popb(...) pop_back(__VA_ARGS__)

    #define push(...) emplace(__VA_ARGS__)

    '
  code: '#pragma once


    #define pushf(...) emplace_front(__VA_ARGS__)

    #define popf(...) pop_front(__VA_ARGS__)

    #define pushb(...) emplace_back(__VA_ARGS__)

    #define popb(...) pop_back(__VA_ARGS__)

    #define push(...) emplace(__VA_ARGS__)

    '
  dependsOn: []
  isVerificationFile: false
  path: kpr/template/push_pop_macro.hpp
  requiredBy:
  - kpr/all.hpp
  - kpr/template/template.hpp
  - kpr/template/macro.hpp
  timestamp: '2023-04-04 01:42:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kpr/template/push_pop_macro.hpp
layout: document
redirect_from:
- /library/kpr/template/push_pop_macro.hpp
- /library/kpr/template/push_pop_macro.hpp.html
title: kpr/template/push_pop_macro.hpp
---
