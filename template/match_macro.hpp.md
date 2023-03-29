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
  bundledCode: '#line 2 "template/match_macro.hpp"


    #define KYOPRO_MATCH1(_1) break; case _1:

    #define KYOPRO_MATCH2(_1, _2) break; case _1: case _2:

    #define KYOPRO_MATCH3(_1, _2, _3) break; case _1: case _2: case _3:

    #define KYOPRO_MATCH4(_1, _2, _3, _4) break; case _1: case _2: case _3: case _4:


    #define KYOPRO_OVERLOAD_MATCH(_1, _2, _3, _4, name, ...) name

    #define match(...) KYOPRO_OVERLOAD_MATCH(__VA_ARGS__, KYOPRO_MATCH4, KYOPRO_MATCH3,
    KYOPRO_MATCH2, KYOPRO_MATCH1)(__VA_ARGS__)

    #define otherwise break; default:

    '
  code: '#pragma once


    #define KYOPRO_MATCH1(_1) break; case _1:

    #define KYOPRO_MATCH2(_1, _2) break; case _1: case _2:

    #define KYOPRO_MATCH3(_1, _2, _3) break; case _1: case _2: case _3:

    #define KYOPRO_MATCH4(_1, _2, _3, _4) break; case _1: case _2: case _3: case _4:


    #define KYOPRO_OVERLOAD_MATCH(_1, _2, _3, _4, name, ...) name

    #define match(...) KYOPRO_OVERLOAD_MATCH(__VA_ARGS__, KYOPRO_MATCH4, KYOPRO_MATCH3,
    KYOPRO_MATCH2, KYOPRO_MATCH1)(__VA_ARGS__)

    #define otherwise break; default:

    '
  dependsOn: []
  isVerificationFile: false
  path: template/match_macro.hpp
  requiredBy:
  - all.hpp
  - template/template.hpp
  - template/macro.hpp
  timestamp: '2023-03-29 16:52:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/match_macro.hpp
layout: document
redirect_from:
- /library/template/match_macro.hpp
- /library/template/match_macro.hpp.html
title: template/match_macro.hpp
---
