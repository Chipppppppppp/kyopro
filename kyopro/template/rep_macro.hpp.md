---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: kyopro/all.hpp
    title: kyopro/all.hpp
  - icon: ':warning:'
    path: kyopro/template/macro.hpp
    title: kyopro/template/macro.hpp
  - icon: ':warning:'
    path: kyopro/template/template.hpp
    title: kyopro/template/template.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"kyopro/template/rep_macro.hpp\"\n#include <type_traits>\n\
    \n#define KYOPRO_OVERLOAD_REP(_1, _2, _3, name, ...) name\n\n#define KYOPRO_REP0()\
    \ for (; ; )\n#define KYOPRO_REP1(last) KYOPRO_REP2(KYOPRO_COUNTER, last)\n#define\
    \ KYOPRO_REP2(i, last) for (auto i = std::decay_t<decltype(last)>(), KYOPRO_LAST\
    \ = (last); (i) != (KYOPRO_LAST); ++(i))\n#define KYOPRO_REP3(i, first, last)\
    \ for (auto i = (first), KYOPRO_LAST = last; (i) != (KYOPRO_LAST); ++(i))\n\n\
    #define rep(...) KYOPRO_OVERLOAD_REP(__VA_ARGS__ __VA_OPT__(,) KYOPRO_REP3, KYOPRO_REP2,\
    \ KYOPRO_REP1, KYOPRO_REP0)(__VA_ARGS__)\n\nnamespace kpr::helper {\n    template<class\
    \ T>\n    constexpr auto prev(T x) noexcept {\n        return --x;\n    }\n} //\
    \ namespace kpr::helper\n\n#define KYOPRO_RREP0() for (; ; )\n#define KYOPRO_RREP1(last)\
    \ KYOPRO_RREP2(KYOPRO_COUNTER, last)\n#define KYOPRO_RREP2(i, last) for (auto\
    \ i = kpr::helper::prev(last), KYOPRO_FIRST = kpr::helper::prev(std::decay_t<decltype(last)>());\
    \ (i) != (KYOPRO_FIRST); --(i))\n#define KYOPRO_RREP3(i, first, last) for (auto\
    \ i = kpr::helper::prev(last), KYOPRO_FIRST = kpr::helper::prev(first); (i) !=\
    \ (KYOPRO_FIRST); --(i))\n\n#define rrep(...) KYOPRO_OVERLOAD_REP(__VA_ARGS__\
    \ __VA_OPT__(,) KYOPRO_RREP3, KYOPRO_RREP2, KYOPRO_RREP1, KYOPRO_RREP0)(__VA_ARGS__)\n"
  code: "#pragma once\n#include <type_traits>\n\n#define KYOPRO_OVERLOAD_REP(_1, _2,\
    \ _3, name, ...) name\n\n#define KYOPRO_REP0() for (; ; )\n#define KYOPRO_REP1(last)\
    \ KYOPRO_REP2(KYOPRO_COUNTER, last)\n#define KYOPRO_REP2(i, last) for (auto i\
    \ = std::decay_t<decltype(last)>(), KYOPRO_LAST = (last); (i) != (KYOPRO_LAST);\
    \ ++(i))\n#define KYOPRO_REP3(i, first, last) for (auto i = (first), KYOPRO_LAST\
    \ = last; (i) != (KYOPRO_LAST); ++(i))\n\n#define rep(...) KYOPRO_OVERLOAD_REP(__VA_ARGS__\
    \ __VA_OPT__(,) KYOPRO_REP3, KYOPRO_REP2, KYOPRO_REP1, KYOPRO_REP0)(__VA_ARGS__)\n\
    \nnamespace kpr::helper {\n    template<class T>\n    constexpr auto prev(T x)\
    \ noexcept {\n        return --x;\n    }\n} // namespace kpr::helper\n\n#define\
    \ KYOPRO_RREP0() for (; ; )\n#define KYOPRO_RREP1(last) KYOPRO_RREP2(KYOPRO_COUNTER,\
    \ last)\n#define KYOPRO_RREP2(i, last) for (auto i = kpr::helper::prev(last),\
    \ KYOPRO_FIRST = kpr::helper::prev(std::decay_t<decltype(last)>()); (i) != (KYOPRO_FIRST);\
    \ --(i))\n#define KYOPRO_RREP3(i, first, last) for (auto i = kpr::helper::prev(last),\
    \ KYOPRO_FIRST = kpr::helper::prev(first); (i) != (KYOPRO_FIRST); --(i))\n\n#define\
    \ rrep(...) KYOPRO_OVERLOAD_REP(__VA_ARGS__ __VA_OPT__(,) KYOPRO_RREP3, KYOPRO_RREP2,\
    \ KYOPRO_RREP1, KYOPRO_RREP0)(__VA_ARGS__)\n"
  dependsOn: []
  isVerificationFile: false
  path: kyopro/template/rep_macro.hpp
  requiredBy:
  - kyopro/all.hpp
  - kyopro/template/template.hpp
  - kyopro/template/macro.hpp
  timestamp: '2023-04-02 21:40:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kyopro/template/rep_macro.hpp
layout: document
redirect_from:
- /library/kyopro/template/rep_macro.hpp
- /library/kyopro/template/rep_macro.hpp.html
title: kyopro/template/rep_macro.hpp
---