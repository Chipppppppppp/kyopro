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
  bundledCode: '#line 2 "template/rep_macro.hpp"

    #include <type_traits>


    #define KYOPRO_REP0() for (; ; )

    #define KYOPRO_REP1(last) KYOPRO_REP2(KYOPRO_COUNTER, last)

    #define KYOPRO_REP2(i, last) for (auto i = std::decay_t<decltype(last)>(), KYOPRO_LAST
    = (last); (i) < (KYOPRO_LAST); ++(i))

    #define KYOPRO_REP3(i, first, last) for (auto i = (first), KYOPRO_LAST = last;
    (i) < (KYOPRO_LAST); ++(i))


    #define KYOPRO_OVERLOAD_REP(_1, _2, _3, name, ...) name

    #define rep(...) KYOPRO_OVERLOAD_REP(__VA_ARGS__ __VA_OPT__(,) KYOPRO_REP3, KYOPRO_REP2,
    KYOPRO_REP1, KYOPRO_REP0)(__VA_ARGS__)

    '
  code: '#pragma once

    #include <type_traits>


    #define KYOPRO_REP0() for (; ; )

    #define KYOPRO_REP1(last) KYOPRO_REP2(KYOPRO_COUNTER, last)

    #define KYOPRO_REP2(i, last) for (auto i = std::decay_t<decltype(last)>(), KYOPRO_LAST
    = (last); (i) < (KYOPRO_LAST); ++(i))

    #define KYOPRO_REP3(i, first, last) for (auto i = (first), KYOPRO_LAST = last;
    (i) < (KYOPRO_LAST); ++(i))


    #define KYOPRO_OVERLOAD_REP(_1, _2, _3, name, ...) name

    #define rep(...) KYOPRO_OVERLOAD_REP(__VA_ARGS__ __VA_OPT__(,) KYOPRO_REP3, KYOPRO_REP2,
    KYOPRO_REP1, KYOPRO_REP0)(__VA_ARGS__)

    '
  dependsOn: []
  isVerificationFile: false
  path: template/rep_macro.hpp
  requiredBy:
  - all.hpp
  - template/template.hpp
  - template/macro.hpp
  timestamp: '2023-03-29 16:52:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/rep_macro.hpp
layout: document
redirect_from:
- /library/template/rep_macro.hpp
- /library/template/rep_macro.hpp.html
title: template/rep_macro.hpp
---
