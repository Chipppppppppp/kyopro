---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: meta/settings.hpp
    title: meta/settings.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all/all.hpp
    title: all/all.hpp
  - icon: ':warning:'
    path: template/all.hpp
    title: template/all.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: '#line 2 "template/macro.hpp"

    #include <iterator>

    #include <type_traits>

    #line 2 "meta/settings.hpp"

    #include <cstdint>


    #ifndef KYOPRO_BASE_INT

    #define KYOPRO_BASE_INT std::int64_t

    #endif


    #ifndef KYOPRO_BASE_UINT

    #define KYOPRO_BASE_UINT std::uint64_t

    #endif


    #ifndef KYOPRO_BASE_FLOAT

    #define KYOPRO_BASE_FLOAT double

    #endif


    #ifndef KYOPRO_DEFAULT_MOD

    #define KYOPRO_DEFAULT_MOD static_cast<KYOPRO_BASE_UINT>(998244353)

    #endif


    #ifndef KYOPRO_DECIMAL_PRECISION

    #define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)

    #endif


    #ifndef KYOPRO_INF_DIV

    #define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)

    #endif


    #ifndef KYOPRO_BUFFER_SIZE

    #define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)

    #endif

    #line 5 "template/macro.hpp"


    #define KYOPRO_OVERLOAD_MACRO(_1, _2, _3, _4, name, ...) name

    #define KYOPRO_REP0() for (; ; )

    #define KYOPRO_REP1(i) for (KYOPRO_BASE_INT i = 0; ; ++(i))

    #define KYOPRO_REP2(i, last) for (KYOPRO_BASE_INT i = 0, KYOPRO_LAST_ ## i = (last);
    (i) < (KYOPRO_LAST_ ## i); ++(i))

    #define KYOPRO_REP3(i, first, last) for (KYOPRO_BASE_INT i = (first), KYOPRO_LAST_
    ## i = last; (i) < (KYOPRO_LAST_ ## i); ++(i))

    #define KYOPRO_REP4(i, first, last, step) for (KYOPRO_BASE_INT i = (first), KYOPRO_LAST_
    ## i = (last), KYOPRO_STEP_ ## i = (step); (KYOPRO_STEP_ ## i) > 0 ? (i) < (KYOPRO_LAST_
    ## i) : (i) > (KYOPRO_LAST_ ## i); (i) += (KYOPRO_BASE_INT)(step))

    #define rep(...) KYOPRO_OVERLOAD_MACRO(__VA_ARGS__ __VA_OPT__(,) KYOPRO_REP4,
    KYOPRO_REP3, KYOPRO_REP2, KYOPRO_REP1, KYOPRO_REP0)(__VA_ARGS__)

    #define KYOPRO_ITER2(i, last) for (auto i = std::decay_t<decltype(last)>(), KYOPRO_LAST_
    ## i = (last); (i) != (KYOPRO_LAST_ ## i); ++(i))

    #define KYOPRO_ITER3(i, first, last) for (auto i = (first), KYOPRO_LAST_ ## i
    = (last); (i) != (KYOPRO_LAST_ ## i); ++(i))

    #define KYOPRO_ITER4(i, first, last, step) for (auto i = (first), KYOPRO_LAST_
    ## i = (last); (step) > 0 ? (i) < (KYOPRO_LAST_ ## i) : (i) > (KYOPRO_LAST_ ##
    i); (i) += (step))

    #define iter(...) KYOPRO_OVERLOAD_MACRO(__VA_ARGS__, KYOPRO_ITER4, KYOPRO_ITER3,
    KYOPRO_ITER2)(__VA_ARGS__)

    #define KYOPRO_LAMBDA1(value) ([&]() noexcept { return (value);})

    #define KYOPRO_LAMBDA2(_1, value) ([&](auto&& _1) noexcept { return (value); })

    #define KYOPRO_LAMBDA3(_1, _2, value) ([&](auto&& _1, auto&& _2) noexcept { return
    (value); })

    #define KYOPRO_LAMBDA4(_1, _2, _3, value) ([&](auto&& _1, auto&& _2, auto&& _3)
    noexcept { return (value); })

    #define lambda(...) KYOPRO_OVERLOAD_MACRO(__VA_ARGS__, KYOPRO_LAMBDA4, KYOPRO_LAMBDA3,
    KYOPRO_LAMBDA2, KYOPRO_LAMBDA1)(__VA_ARGS__)

    #define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)

    #define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)

    '
  code: '#pragma once

    #include <iterator>

    #include <type_traits>

    #include "../meta/settings.hpp"


    #define KYOPRO_OVERLOAD_MACRO(_1, _2, _3, _4, name, ...) name

    #define KYOPRO_REP0() for (; ; )

    #define KYOPRO_REP1(i) for (KYOPRO_BASE_INT i = 0; ; ++(i))

    #define KYOPRO_REP2(i, last) for (KYOPRO_BASE_INT i = 0, KYOPRO_LAST_ ## i = (last);
    (i) < (KYOPRO_LAST_ ## i); ++(i))

    #define KYOPRO_REP3(i, first, last) for (KYOPRO_BASE_INT i = (first), KYOPRO_LAST_
    ## i = last; (i) < (KYOPRO_LAST_ ## i); ++(i))

    #define KYOPRO_REP4(i, first, last, step) for (KYOPRO_BASE_INT i = (first), KYOPRO_LAST_
    ## i = (last), KYOPRO_STEP_ ## i = (step); (KYOPRO_STEP_ ## i) > 0 ? (i) < (KYOPRO_LAST_
    ## i) : (i) > (KYOPRO_LAST_ ## i); (i) += (KYOPRO_BASE_INT)(step))

    #define rep(...) KYOPRO_OVERLOAD_MACRO(__VA_ARGS__ __VA_OPT__(,) KYOPRO_REP4,
    KYOPRO_REP3, KYOPRO_REP2, KYOPRO_REP1, KYOPRO_REP0)(__VA_ARGS__)

    #define KYOPRO_ITER2(i, last) for (auto i = std::decay_t<decltype(last)>(), KYOPRO_LAST_
    ## i = (last); (i) != (KYOPRO_LAST_ ## i); ++(i))

    #define KYOPRO_ITER3(i, first, last) for (auto i = (first), KYOPRO_LAST_ ## i
    = (last); (i) != (KYOPRO_LAST_ ## i); ++(i))

    #define KYOPRO_ITER4(i, first, last, step) for (auto i = (first), KYOPRO_LAST_
    ## i = (last); (step) > 0 ? (i) < (KYOPRO_LAST_ ## i) : (i) > (KYOPRO_LAST_ ##
    i); (i) += (step))

    #define iter(...) KYOPRO_OVERLOAD_MACRO(__VA_ARGS__, KYOPRO_ITER4, KYOPRO_ITER3,
    KYOPRO_ITER2)(__VA_ARGS__)

    #define KYOPRO_LAMBDA1(value) ([&]() noexcept { return (value);})

    #define KYOPRO_LAMBDA2(_1, value) ([&](auto&& _1) noexcept { return (value); })

    #define KYOPRO_LAMBDA3(_1, _2, value) ([&](auto&& _1, auto&& _2) noexcept { return
    (value); })

    #define KYOPRO_LAMBDA4(_1, _2, _3, value) ([&](auto&& _1, auto&& _2, auto&& _3)
    noexcept { return (value); })

    #define lambda(...) KYOPRO_OVERLOAD_MACRO(__VA_ARGS__, KYOPRO_LAMBDA4, KYOPRO_LAMBDA3,
    KYOPRO_LAMBDA2, KYOPRO_LAMBDA1)(__VA_ARGS__)

    #define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)

    #define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)'
  dependsOn:
  - meta/settings.hpp
  isVerificationFile: false
  path: template/macro.hpp
  requiredBy:
  - all/all.hpp
  - template/all.hpp
  timestamp: '2022-03-30 17:18:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/macro.hpp
layout: document
redirect_from:
- /library/template/macro.hpp
- /library/template/macro.hpp.html
title: template/macro.hpp
---
