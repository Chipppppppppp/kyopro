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
  bundledCode: '#line 2 "template/push_pop.hpp"


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
  path: template/push_pop.hpp
  requiredBy:
  - all.hpp
  - template/template.hpp
  - template/macro.hpp
  timestamp: '2023-03-28 19:27:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/push_pop.hpp
layout: document
redirect_from:
- /library/template/push_pop.hpp
- /library/template/push_pop.hpp.html
title: template/push_pop.hpp
---
