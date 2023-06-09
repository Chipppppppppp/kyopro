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
  bundledCode: '#line 2 "kpr/template/match_macro.hpp"


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
  path: kpr/template/match_macro.hpp
  requiredBy:
  - kpr/template/template.hpp
  - kpr/template/macro.hpp
  - kpr/all.hpp
  timestamp: '2023-04-04 01:42:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kpr/template/match_macro.hpp
layout: document
redirect_from:
- /library/kpr/template/match_macro.hpp
- /library/kpr/template/match_macro.hpp.html
title: kpr/template/match_macro.hpp
---
