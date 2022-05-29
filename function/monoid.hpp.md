---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/power.hpp
    title: math/power.hpp
  - icon: ':heavy_check_mark:'
    path: meta/constant.hpp
    title: meta/constant.hpp
  - icon: ':heavy_check_mark:'
    path: meta/settings.hpp
    title: meta/settings.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  - icon: ':warning:'
    path: all/all.hpp
    title: all/all.hpp
  - icon: ':warning:'
    path: function/all.hpp
    title: function/all.hpp
  - icon: ':heavy_check_mark:'
    path: structure/FenwickTree.hpp
    title: structure/FenwickTree.hpp
  - icon: ':warning:'
    path: structure/all.hpp
    title: structure/all.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/point_add_range_sum.test.cpp
    title: verify/yosupo/point_add_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"function/monoid.hpp\"\n#include <type_traits>\n#line 2 \"\
    meta/constant.hpp\"\n#include <array>\n#include <limits>\n#include <utility>\n\
    #line 2 \"meta/settings.hpp\"\n#include <cstdint>\n\n#ifndef KYOPRO_BASE_INT\n\
    #define KYOPRO_BASE_INT std::int64_t\n#endif\n\n#ifndef KYOPRO_BASE_UINT\n#define\
    \ KYOPRO_BASE_UINT std::uint64_t\n#endif\n\n#ifndef KYOPRO_BASE_FLOAT\n#define\
    \ KYOPRO_BASE_FLOAT double\n#endif\n\n#ifndef KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD\
    \ static_cast<KYOPRO_BASE_UINT>(998244353)\n#endif\n\n#ifndef KYOPRO_DECIMAL_PRECISION\n\
    #define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n#endif\n\n\
    #ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 3 \"math/power.hpp\"\n\nnamespace kpr {\n  template<class T>\n \
    \ constexpr T power(T a, KYOPRO_BASE_UINT n, T init = 1) noexcept {\n    while\
    \ (n > 0) {\n      if (n & 1) init *= a;\n      a *= a;\n      n >>= 1;\n    }\n\
    \    return init;\n  }\n}\n#line 7 \"meta/constant.hpp\"\n\nnamespace kpr {\n\
    \  template<class T>\n  inline constexpr T MOD = KYOPRO_DEFAULT_MOD;\n  inline\
    \ constexpr KYOPRO_BASE_INT mod = MOD<KYOPRO_BASE_INT>;\n\n  template<class T>\n\
    \  inline constexpr T INF = std::numeric_limits<T>::max() / KYOPRO_INF_DIV;\n\
    \  inline constexpr KYOPRO_BASE_INT inf = INF<KYOPRO_BASE_INT>;\n\n  template<class\
    \ T, KYOPRO_BASE_UINT decimal_precision = KYOPRO_DECIMAL_PRECISION>\n  inline\
    \ constexpr KYOPRO_BASE_FLOAT EPS = static_cast<T>(1) / power(10ULL, decimal_precision);\n\
    \  inline constexpr KYOPRO_BASE_FLOAT eps = EPS<KYOPRO_BASE_FLOAT>;\n\n  template<class\
    \ T>\n  inline constexpr T PI = 3.14159265358979323846;\n  inline constexpr KYOPRO_BASE_FLOAT\
    \ pi = PI<KYOPRO_BASE_FLOAT>;\n}\n#line 4 \"function/monoid.hpp\"\n\nnamespace\
    \ kpr {\n  template<class T, T _id = 0>\n  struct Plus {\n    static_assert(std::is_arithmetic_v<T>);\n\
    \    using value_type = T;\n    static constexpr T id = _id;\n\n    constexpr\
    \ T operator ()(T a, T b) const noexcept { return a + b; }\n    constexpr T inverse(T\
    \ a) const noexcept { return -a; }\n  };\n\n  template<class T, T _id = 1>\n \
    \ struct Mul {\n    static_assert(std::is_arithmetic_v<T>);\n    using value_type\
    \ = T;\n    static constexpr T id = _id;\n\n    constexpr T operator ()(T a, T\
    \ b) const noexcept { return a * b; }\n    constexpr T inverse(T a) const noexcept\
    \ {\n      static_assert(!std::is_integral_v<T>);\n      return 1 / a;\n    }\n\
    \  };\n\n  template<class T, T _id = std::is_integral_v<T> ? -INF<T> : -inf>\n\
    \  struct Max {\n    static_assert(std::is_arithmetic_v<T>);\n    using value_type\
    \ = T;\n    static constexpr T id = _id;\n\n    constexpr T operator ()(T a, T\
    \ b) const noexcept { return a > b ? a : b; }\n  };\n\n  template<class T, T _id\
    \ = std::is_integral_v<T> ? INF<T> : inf>\n  struct Min {\n    static_assert(std::is_arithmetic_v<T>);\n\
    \    using value_type = T;\n    static constexpr T id = _id;\n\n    constexpr\
    \ T operator ()(T a, T b) const noexcept { return a < b ? a : b; }\n  };\n}\n"
  code: "#pragma once\n#include <type_traits>\n#include \"../meta/constant.hpp\"\n\
    \nnamespace kpr {\n  template<class T, T _id = 0>\n  struct Plus {\n    static_assert(std::is_arithmetic_v<T>);\n\
    \    using value_type = T;\n    static constexpr T id = _id;\n\n    constexpr\
    \ T operator ()(T a, T b) const noexcept { return a + b; }\n    constexpr T inverse(T\
    \ a) const noexcept { return -a; }\n  };\n\n  template<class T, T _id = 1>\n \
    \ struct Mul {\n    static_assert(std::is_arithmetic_v<T>);\n    using value_type\
    \ = T;\n    static constexpr T id = _id;\n\n    constexpr T operator ()(T a, T\
    \ b) const noexcept { return a * b; }\n    constexpr T inverse(T a) const noexcept\
    \ {\n      static_assert(!std::is_integral_v<T>);\n      return 1 / a;\n    }\n\
    \  };\n\n  template<class T, T _id = std::is_integral_v<T> ? -INF<T> : -inf>\n\
    \  struct Max {\n    static_assert(std::is_arithmetic_v<T>);\n    using value_type\
    \ = T;\n    static constexpr T id = _id;\n\n    constexpr T operator ()(T a, T\
    \ b) const noexcept { return a > b ? a : b; }\n  };\n\n  template<class T, T _id\
    \ = std::is_integral_v<T> ? INF<T> : inf>\n  struct Min {\n    static_assert(std::is_arithmetic_v<T>);\n\
    \    using value_type = T;\n    static constexpr T id = _id;\n\n    constexpr\
    \ T operator ()(T a, T b) const noexcept { return a < b ? a : b; }\n  };\n}"
  dependsOn:
  - meta/constant.hpp
  - math/power.hpp
  - meta/settings.hpp
  isVerificationFile: false
  path: function/monoid.hpp
  requiredBy:
  - all/all.hpp
  - all.hpp
  - structure/all.hpp
  - structure/FenwickTree.hpp
  - function/all.hpp
  timestamp: '2022-04-27 22:05:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/point_add_range_sum.test.cpp
documentation_of: function/monoid.hpp
layout: document
redirect_from:
- /library/function/monoid.hpp
- /library/function/monoid.hpp.html
title: function/monoid.hpp
---
