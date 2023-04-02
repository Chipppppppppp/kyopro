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
  bundledCode: '#line 2 "kyopro/template/match_macro.hpp"


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
  path: kyopro/template/match_macro.hpp
  requiredBy: []
  timestamp: '2023-04-02 20:21:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kyopro/template/match_macro.hpp
layout: document
redirect_from:
- /library/kyopro/template/match_macro.hpp
- /library/kyopro/template/match_macro.hpp.html
title: kyopro/template/match_macro.hpp
---
