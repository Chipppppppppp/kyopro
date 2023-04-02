---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: '#line 2 "kyopro/template/push_pop_macro.hpp"


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
  path: kyopro/template/push_pop_macro.hpp
  requiredBy: []
  timestamp: '2023-04-02 20:21:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kyopro/template/push_pop_macro.hpp
layout: document
redirect_from:
- /library/kyopro/template/push_pop_macro.hpp
- /library/kyopro/template/push_pop_macro.hpp.html
title: kyopro/template/push_pop_macro.hpp
---
