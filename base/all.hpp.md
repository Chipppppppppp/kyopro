---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base/constant.hpp
    title: base/constant.hpp
  - icon: ':heavy_check_mark:'
    path: base/monoid.hpp
    title: base/monoid.hpp
  - icon: ':heavy_check_mark:'
    path: base/settings.hpp
    title: base/settings.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"base/settings.hpp\"\n#include <cstdint>\n#ifndef KYOPRO_BASE_INT\n\
    #define KYOPRO_BASE_INT std::int64_t\n#endif\n#ifndef KYOPRO_BASE_UINT\n#define\
    \ KYOPRO_BASE_UINT std::size_t\n#endif\n#ifndef KYOPRO_BASE_FLOAT\n#define KYOPRO_BASE_FLOAT\
    \ double\n#endif\n#ifndef KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD 1000000007\n\
    #endif\n#ifndef KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION 12\n\
    #endif\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV 3\n#endif\n#line 2 \"base/constant.hpp\"\
    \n#include <limits>\n#include <array>\n#include <utility>\n#line 2 \"base/settings.hpp\"\
    \n#ifndef KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT std::int64_t\n#endif\n#ifndef\
    \ KYOPRO_BASE_UINT\n#define KYOPRO_BASE_UINT std::size_t\n#endif\n#ifndef KYOPRO_BASE_FLOAT\n\
    #define KYOPRO_BASE_FLOAT double\n#endif\n#ifndef KYOPRO_DEFAULT_MOD\n#define\
    \ KYOPRO_DEFAULT_MOD 1000000007\n#endif\n#ifndef KYOPRO_DECIMAL_PRECISION\n#define\
    \ KYOPRO_DECIMAL_PRECISION 12\n#endif\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV\
    \ 3\n#endif\n#line 6 \"base/constant.hpp\"\n\nnamespace kyopro {\n  template<class\
    \ KyoproT>\n  inline constexpr KyoproT MOD = KYOPRO_DEFAULT_MOD;\n  inline constexpr\
    \ KYOPRO_BASE_INT mod = MOD<KYOPRO_BASE_INT>;\n  template<class KyoproT>\n  inline\
    \ constexpr KyoproT INF = std::numeric_limits<KyoproT>::max() / KYOPRO_INF_DIV;\n\
    \  inline constexpr KYOPRO_BASE_INT inf = INF<KYOPRO_BASE_INT>;\n  template<class\
    \ KyoproT>\n  inline constexpr KyoproT PI = 3.14159265358979323846;\n  inline\
    \ constexpr KYOPRO_BASE_FLOAT pi = PI<KYOPRO_BASE_FLOAT>;\n  inline constexpr\
    \ std::array<std::pair<KYOPRO_BASE_INT, KYOPRO_BASE_INT>, 4> beside{{{1, 0}, {0,\
    \ 1}, {-1, 0}, {0, -1}}};\n  inline constexpr std::array<std::pair<KYOPRO_BASE_INT,\
    \ KYOPRO_BASE_INT>, 8> around{{{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1,\
    \ -1}, {0, -1}, {1, -1}}};\n}\n#line 2 \"base/monoid.hpp\"\n#include <type_traits>\n\
    #line 4 \"base/monoid.hpp\"\n\nnamespace kyopro {\n  template<class KyoproT, KyoproT\
    \ kyopro_id = 0>\n  struct Plus {\n    static constexpr KyoproT id = kyopro_id;\n\
    \    static constexpr KyoproT op(KyoproT kyopro_a, KyoproT kyopro_b) noexcept\
    \ { return kyopro_a + kyopro_b; }\n    static constexpr KyoproT inv(KyoproT kyopro_a)\
    \ noexcept { return -kyopro_a; }\n  };\n  template<class KyoproT, KyoproT kyopro_id\
    \ = 1>\n  struct Mul {\n    static constexpr KyoproT id = kyopro_id;\n    static\
    \ constexpr KyoproT op(KyoproT kyopro_a, KyoproT kyopro_b) noexcept { return kyopro_a\
    \ * kyopro_b; }\n    static constexpr KyoproT inv(KyoproT kyopro_a) noexcept {\n\
    \      static_assert(!std::is_integral_v<KyoproT>);\n      return 1 / kyopro_a;\n\
    \    }\n  };\n  template<class KyoproT, KyoproT kyopro_id = -inf>\n  struct Max\
    \ {\n    static constexpr KyoproT id = kyopro_id;\n    static constexpr KyoproT\
    \ op(KyoproT kyopro_a, KyoproT kyopro_b) noexcept { return kyopro_a > kyopro_b\
    \ ? kyopro_a : kyopro_b; }\n  };\n  template<class KyoproT, KyoproT kyopro_id\
    \ = inf>\n  struct Min {\n    static constexpr KyoproT id = kyopro_id;\n    static\
    \ constexpr KyoproT op(KyoproT kyopro_a, KyoproT kyopro_b) noexcept { return kyopro_a\
    \ < kyopro_b ? kyopro_a : kyopro_b; }\n  };\n}\n#line 5 \"base/all.hpp\"\n"
  code: '#pragma once

    #include "settings.hpp"

    #include "constant.hpp"

    #include "monoid.hpp"'
  dependsOn:
  - base/settings.hpp
  - base/constant.hpp
  - base/monoid.hpp
  isVerificationFile: false
  path: base/all.hpp
  requiredBy:
  - all.hpp
  timestamp: '2022-01-05 12:00:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: base/all.hpp
layout: document
redirect_from:
- /library/base/all.hpp
- /library/base/all.hpp.html
title: base/all.hpp
---
