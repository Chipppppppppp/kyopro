---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base/constant.hpp
    title: base/constant.hpp
  - icon: ':heavy_check_mark:'
    path: base/settings.hpp
    title: base/settings.hpp
  - icon: ':heavy_check_mark:'
    path: math/power.hpp
    title: math/power.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  - icon: ':warning:'
    path: math/all.hpp
    title: math/all.hpp
  - icon: ':heavy_check_mark:'
    path: structure/FenwickTree.hpp
    title: structure/FenwickTree.hpp
  - icon: ':warning:'
    path: structure/all.hpp
    title: structure/all.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: yosupo/FenwickTree.test.cpp
    title: yosupo/FenwickTree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/monoid.hpp\"\n#include <type_traits>\n#line 2 \"base/constant.hpp\"\
    \n#include <array>\n#include <cstdint>\n#include <limits>\n#include <utility>\n\
    #line 3 \"base/settings.hpp\"\n\n#ifndef KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT\
    \ std::int64_t\n#endif\n\n#ifndef KYOPRO_BASE_UINT\n#define KYOPRO_BASE_UINT std::size_t\n\
    #endif\n\n#ifndef KYOPRO_BASE_FLOAT\n#define KYOPRO_BASE_FLOAT double\n#endif\n\
    \n#ifndef KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD static_cast<KYOPRO_BASE_UINT>(1000000007)\n\
    #endif\n\n#ifndef KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n\
    #endif\n\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 4 \"math/power.hpp\"\nnamespace kyopro {\n  template<class _typeT>\n\
    \  constexpr _typeT power(_typeT _a, std::uint_fast64_t _n, _typeT _init = 1)\
    \ noexcept {\n    while (_n > 0) {\n      if (_n & 1) _init *= _a;\n      _a *=\
    \ _a;\n      _n >>= 1;\n    }\n    return _init;\n  }\n}\n#line 8 \"base/constant.hpp\"\
    \n\nnamespace kyopro {\n  inline constexpr std::uint_fast64_t _decimal_max = power(static_cast<std::uint_fast64_t>(10),\
    \ KYOPRO_DECIMAL_PRECISION);\n\n  template<class _typeT>\n  inline constexpr _typeT\
    \ MOD = KYOPRO_DEFAULT_MOD;\n  inline constexpr KYOPRO_BASE_INT mod = MOD<KYOPRO_BASE_INT>;\n\
    \n  template<class _typeT>\n  inline constexpr _typeT INF = std::numeric_limits<_typeT>::max()\
    \ / KYOPRO_INF_DIV;\n  inline constexpr KYOPRO_BASE_INT inf = INF<KYOPRO_BASE_INT>;\n\
    \n  template<class _typeT>\n  inline constexpr KYOPRO_BASE_FLOAT EPS = static_cast<_typeT>(1)\
    \ / _decimal_max;\n  inline constexpr KYOPRO_BASE_FLOAT eps = EPS<KYOPRO_BASE_FLOAT>;\n\
    \n  template<class _typeT>\n  inline constexpr _typeT PI = 3.14159265358979323846;\n\
    \  inline constexpr KYOPRO_BASE_FLOAT pi = PI<KYOPRO_BASE_FLOAT>;\n\n  inline\
    \ constexpr std::array<std::pair<KYOPRO_BASE_INT, KYOPRO_BASE_INT>, 4> beside{{{1,\
    \ 0}, {0, 1}, {-1, 0}, {0, -1}}};\n  inline constexpr std::array<std::pair<KYOPRO_BASE_INT,\
    \ KYOPRO_BASE_INT>, 8> around{{{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1,\
    \ -1}, {0, -1}, {1, -1}}};\n}\n#line 4 \"math/monoid.hpp\"\n\nnamespace kyopro\
    \ {\n  template<class _typeT, _typeT _id = 0>\n  struct Plus {\n    static constexpr\
    \ _typeT id = _id;\n    static constexpr _typeT op(_typeT _a, _typeT _b) noexcept\
    \ { return _a + _b; }\n    static constexpr _typeT inv(_typeT _a) noexcept { return\
    \ -_a; }\n  };\n  template<class _typeT, _typeT _id = 1>\n  struct Mul {\n   \
    \ static constexpr _typeT id = _id;\n    static constexpr _typeT op(_typeT _a,\
    \ _typeT _b) noexcept { return _a * _b; }\n    static constexpr _typeT inv(_typeT\
    \ _a) noexcept {\n      static_assert(!std::is_integral_v<_typeT>);\n      return\
    \ 1 / _a;\n    }\n  };\n  template<class _typeT, _typeT _id = -inf>\n  struct\
    \ Max {\n    static constexpr _typeT id = _id;\n    static constexpr _typeT op(_typeT\
    \ _a, _typeT _b) noexcept { return _a > _b ? _a : _b; }\n  };\n  template<class\
    \ _typeT, _typeT _id = inf>\n  struct Min {\n    static constexpr _typeT id =\
    \ _id;\n    static constexpr _typeT op(_typeT _a, _typeT _b) noexcept { return\
    \ _a < _b ? _a : _b; }\n  };\n}\n"
  code: "#pragma once\n#include <type_traits>\n#include \"../base/constant.hpp\"\n\
    \nnamespace kyopro {\n  template<class _typeT, _typeT _id = 0>\n  struct Plus\
    \ {\n    static constexpr _typeT id = _id;\n    static constexpr _typeT op(_typeT\
    \ _a, _typeT _b) noexcept { return _a + _b; }\n    static constexpr _typeT inv(_typeT\
    \ _a) noexcept { return -_a; }\n  };\n  template<class _typeT, _typeT _id = 1>\n\
    \  struct Mul {\n    static constexpr _typeT id = _id;\n    static constexpr _typeT\
    \ op(_typeT _a, _typeT _b) noexcept { return _a * _b; }\n    static constexpr\
    \ _typeT inv(_typeT _a) noexcept {\n      static_assert(!std::is_integral_v<_typeT>);\n\
    \      return 1 / _a;\n    }\n  };\n  template<class _typeT, _typeT _id = -inf>\n\
    \  struct Max {\n    static constexpr _typeT id = _id;\n    static constexpr _typeT\
    \ op(_typeT _a, _typeT _b) noexcept { return _a > _b ? _a : _b; }\n  };\n  template<class\
    \ _typeT, _typeT _id = inf>\n  struct Min {\n    static constexpr _typeT id =\
    \ _id;\n    static constexpr _typeT op(_typeT _a, _typeT _b) noexcept { return\
    \ _a < _b ? _a : _b; }\n  };\n}"
  dependsOn:
  - base/constant.hpp
  - math/power.hpp
  - base/settings.hpp
  isVerificationFile: false
  path: math/monoid.hpp
  requiredBy:
  - all.hpp
  - structure/FenwickTree.hpp
  - structure/all.hpp
  - math/all.hpp
  timestamp: '2022-01-23 18:51:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - yosupo/FenwickTree.test.cpp
documentation_of: math/monoid.hpp
layout: document
redirect_from:
- /library/math/monoid.hpp
- /library/math/monoid.hpp.html
title: math/monoid.hpp
---
