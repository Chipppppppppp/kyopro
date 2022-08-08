---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: function/RecursiveLambda.hpp
    title: function/RecursiveLambda.hpp
  - icon: ':warning:'
    path: function/compare.hpp
    title: function/compare.hpp
  - icon: ':x:'
    path: function/monoid.hpp
    title: function/monoid.hpp
  - icon: ':question:'
    path: math/power.hpp
    title: math/power.hpp
  - icon: ':x:'
    path: meta/constant.hpp
    title: meta/constant.hpp
  - icon: ':question:'
    path: meta/settings.hpp
    title: meta/settings.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  - icon: ':warning:'
    path: all/all.hpp
    title: all/all.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"function/compare.hpp\"\n\nnamespace kyopro {\n    struct\
    \ Equal {\n        template<class T>\n        constexpr bool operator()(const\
    \ T& x, const T& y) const noexcept(noexcept(x == y)) {\n            return x ==\
    \ y;\n        }\n    };\n\n    struct NotEqual {\n        template<class T>\n\
    \        constexpr bool operator()(const T& x, const T& y) const noexcept(noexcept(x\
    \ != y)) {\n            return x != y;\n        }\n    };\n\n    struct Less {\n\
    \        template<class T>\n        constexpr bool operator()(const T& x, const\
    \ T& y) const noexcept(noexcept(x < y)) {\n            return x < y;\n       \
    \ }\n    };\n\n    struct LessEqual {\n        template<class T>\n        constexpr\
    \ bool operator()(const T& x, const T& y) const noexcept(noexcept(x <= y)) {\n\
    \            return x <= y;\n        }\n    };\n\n    struct Greater {\n     \
    \   template<class T>\n        constexpr bool operator()(const T& x, const T&\
    \ y) const noexcept(noexcept(x > y)) {\n            return x > y;\n        }\n\
    \    };\n\n    struct GreaterEqual {\n        template<class T>\n        constexpr\
    \ bool operator()(const T& x, const T& y) const noexcept(noexcept(x >= y)) {\n\
    \            return x >= y;\n        }\n    };\n} // namespace kyopro\n#line 2\
    \ \"function/monoid.hpp\"\n#include <limits>\n#include <type_traits>\n#line 2\
    \ \"meta/constant.hpp\"\n#include <array>\n#line 4 \"meta/constant.hpp\"\n#include\
    \ <utility>\n#line 2 \"math/power.hpp\"\n#include <cstddef>\n\nnamespace kyopro\
    \ {\n    inline constexpr struct {\n        template<class T>\n        constexpr\
    \ T operator ()(T a, std::uint_fast64_t n, T init = 1) const noexcept {\n    \
    \        while (n > 0) {\n                if (n & 1) init *= a;\n            \
    \    a *= a;\n                n >>= 1;\n            }\n            return init;\n\
    \        }\n    } power;\n} // namespace kyopro\n#line 2 \"meta/settings.hpp\"\
    \n#include <cstdint>\n\n#ifndef KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT std::int64_t\n\
    #endif\n\n#ifndef KYOPRO_BASE_UINT\n#define KYOPRO_BASE_UINT std::uint64_t\n#endif\n\
    \n#ifndef KYOPRO_BASE_FLOAT\n#define KYOPRO_BASE_FLOAT double\n#endif\n\n#ifndef\
    \ KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD static_cast<KYOPRO_BASE_UINT>(998244353)\n\
    #endif\n\n#ifndef KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n\
    #endif\n\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 7 \"meta/constant.hpp\"\n\nnamespace kyopro {\n    template<class\
    \ T>\n    inline constexpr T MOD = KYOPRO_DEFAULT_MOD;\n    inline constexpr KYOPRO_BASE_INT\
    \ mod = MOD<KYOPRO_BASE_INT>;\n\n    template<class T>\n    inline constexpr T\
    \ INF = std::numeric_limits<T>::max() / KYOPRO_INF_DIV;\n    inline constexpr\
    \ KYOPRO_BASE_INT inf = INF<KYOPRO_BASE_INT>;\n\n    template<class T, KYOPRO_BASE_UINT\
    \ decimal_precision = KYOPRO_DECIMAL_PRECISION>\n    inline constexpr KYOPRO_BASE_FLOAT\
    \ EPS = static_cast<T>(1) / power(10ULL, decimal_precision);\n    inline constexpr\
    \ KYOPRO_BASE_FLOAT eps = EPS<KYOPRO_BASE_FLOAT>;\n\n    template<class T>\n \
    \   inline constexpr T PI = 3.14159265358979323846;\n    inline constexpr KYOPRO_BASE_FLOAT\
    \ pi = PI<KYOPRO_BASE_FLOAT>;\n} // namespace kyopro\n#line 5 \"function/monoid.hpp\"\
    \n\nnamespace kyopro {\n    template<class T>\n    struct Add {\n        using\
    \ value_type = T;\n\n        constexpr T id() const noexcept {\n            return\
    \ T{};\n        }\n\n        constexpr T operator ()(const T& a, const T& b) const\
    \ noexcept {\n            return a + b;\n        }\n\n        constexpr T inverse(const\
    \ T& a) const noexcept {\n            return -a;\n        }\n    };\n\n    template<class\
    \ T>\n    struct Mul {\n        using value_type = T;\n\n        constexpr T id()\
    \ const noexcept {\n            return 1;\n        }\n\n        constexpr T operator\
    \ ()(const T& a, const T& b) const noexcept {\n            return a * b;\n   \
    \     }\n\n        constexpr T inverse(const T& a) const noexcept {\n        \
    \    return 1 / a;\n        }\n    };\n\n    template<class T>\n    struct Min\
    \ {\n        using value_type = T;\n\n        constexpr T id() const noexcept\
    \ {\n            return std::is_integral_v<T> ? INF<T> : std::numeric_limits<T>::infinity();\n\
    \        }\n\n        constexpr T operator ()(const T& a, const T& b) const noexcept\
    \ {\n            return a < b ? a : b;\n        }\n    };\n\n    template<class\
    \ T>\n    struct Max {\n        using value_type = T;\n\n        constexpr T id()\
    \ const noexcept {\n            return std::is_integral_v<T> ? std::is_signed_v<T>\
    \ ? -INF<T> : 0 : -std::numeric_limits<T>::infinity();\n        }\n\n        constexpr\
    \ T operator ()(const T& a, const T& b) const noexcept {\n            return a\
    \ > b ? a : b;\n        }\n    };\n\n    template<class, class = void>\n    struct\
    \ has_inversible: std::false_type {};\n    template<class T>\n    struct has_inverse<T,\
    \ std::void_t<decltype(&T::inverse)>>: std::true_type {};\n\n    template<class\
    \ T>\n    inline constexpr bool has_inverse_v = has_inverse<T>::value;\n} // namespace\
    \ kyopro\n#line 4 \"function/RecursiveLambda.hpp\"\n\nnamespace kyopro {\n   \
    \ template<class F>\n    struct RecursiveLambda {\n        using value_type =\
    \ F;\n\n    private:\n        F func;\n\n    public:\n        template<class G>\n\
    \        constexpr RecursiveLambda(G&& func) noexcept: func(std::forward<G>(func))\
    \ {}\n        template<class... Args>\n        constexpr decltype(auto) operator\
    \ ()(Args&&... args) const noexcept(noexcept(func(*this, std::forward<Args>(args)...)))\
    \ {\n            return func(*this, std::forward<Args>(args)...);\n        }\n\
    \    };\n\n    template<class F>\n    RecursiveLambda(F&&) -> RecursiveLambda<std::decay_t<F>>;\n\
    } // namespace kyopro\n#line 5 \"function/all.hpp\"\n"
  code: '#pragma once

    #include "compare.hpp"

    #include "monoid.hpp"

    #include "RecursiveLambda.hpp"'
  dependsOn:
  - function/compare.hpp
  - function/monoid.hpp
  - meta/constant.hpp
  - math/power.hpp
  - meta/settings.hpp
  - function/RecursiveLambda.hpp
  isVerificationFile: false
  path: function/all.hpp
  requiredBy:
  - all/all.hpp
  - all.hpp
  timestamp: '2022-08-08 07:54:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: function/all.hpp
layout: document
redirect_from:
- /library/function/all.hpp
- /library/function/all.hpp.html
title: function/all.hpp
---
