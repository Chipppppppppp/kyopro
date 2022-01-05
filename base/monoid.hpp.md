---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: base/constant.hpp
    title: base/constant.hpp
  - icon: ':question:'
    path: base/settings.hpp
    title: base/settings.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  - icon: ':x:'
    path: structure/FenwickTree.hpp
    title: structure/FenwickTree.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: yosupo/FenwickTree.test.cpp
    title: yosupo/FenwickTree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"base/monoid.hpp\"\n#include <type_traits>\n#line 2 \"base/constant.hpp\"\
    \n#include <limits>\n#include <array>\n#include <utility>\n#line 1 \"base/settings.hpp\"\
    \n#include <cstdint>\n#ifndef KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT std::int64_t\n\
    #endif\n#ifndef KYOPRO_BASE_UINT\n#define KYOPRO_BASE_UINT std::size_t\n#endif\n\
    #ifndef KYOPRO_BASE_FLOAT\n#define KYOPRO_BASE_FLOAT double\n#endif\n#ifndef KYOPRO_DEFAULT_MOD\n\
    #define KYOPRO_DEFAULT_MOD 1000000007\n#endif\n#ifndef KYOPRO_DECIMAL_PRECISION\n\
    #define KYOPRO_DECIMAL_PRECISION 12\n#endif\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV\
    \ 3\n#endif\n#line 6 \"base/constant.hpp\"\n\nnamespace kyopro {\n  template<class\
    \ KyoproT>\n  inline constexpr KyoproT MOD = KYOPRO_DEFAULT_MOD;\n  inline constexpr\
    \ KYOPRO_BASE_INT mod = MOD<KYOPRO_BASE_INT>;\n  template<class KyoproT>\n  inline\
    \ constexpr KyoproT INF = std::numeric_limits<KyoproT>::max() / KYOPRO_INF_DIV;\n\
    \  inline constexpr KYOPRO_BASE_INT inf = INF<KYOPRO_BASE_INT>;\n  template<class\
    \ KyoproT>\n  inline constexpr KyoproT PI = 3.14159265358979323846;\n  inline\
    \ constexpr KYOPRO_BASE_FLOAT pi = PI<KYOPRO_BASE_FLOAT>;\n  inline constexpr\
    \ std::array<std::pair<KYOPRO_BASE_INT, KYOPRO_BASE_INT>, 4> beside{{{1, 0}},\
    \ {{0, 1}}, {{-1, 0}}, {{0, -1}}};\n  inline constexpr std::array<std::pair<KYOPRO_BASE_INT,\
    \ KYOPRO_BASE_INT>, 8> around{{{1, 0}}, {{1, 1}}, {{0, 1}}, {{-1, 1}}, {{-1, 0}},\
    \ {{-1, -1}}, {{0, -1}}, {{1, -1}}};\n}\n#line 4 \"base/monoid.hpp\"\n\nnamespace\
    \ kyopro {\n  template<class KyoproT, KyoproT kyopro_id = 0>\n  struct Plus {\n\
    \    static constexpr KyoproT id = kyopro_id;\n    static constexpr op(KyoproT\
    \ kyopro_a, KyoproT kyopro_b) noexcept { return kyopro_a + kyopro_b; }\n    static\
    \ constexpr inv(KyoproT a) noexcept { return -kyopro_a; }\n  };\n  template<class\
    \ KyoproT, KyoproT kyopro_id = 1>\n  struct Mul {\n    static constexpr KyoproT\
    \ id = kyopro_id;\n    static constexpr op(KyoproT kyopro_a, KyoproT kyopro_b)\
    \ noexcept { return kyopro_a * kyopro_b; }\n    static constexpr inv(KyoproT a)\
    \ noexcept {\n      static_assert(!std::is_integral_v<KyoproT>);\n      return\
    \ 1 / kyopro_a;\n    }\n  };\n  template<class KyoproT, KyoproT kyopro_id = -inf>\n\
    \  struct Max {\n    static constexpr KyoproT id = kyopro_id;\n    static constexpr\
    \ op(KyoproT kyopro_a, KyoproT kyopro_b) noexcept { return kyopro_a > kyopro_b\
    \ ? kyopro_a : kyopro_b; }\n  };\n  template<class KyoproT, KyoproT kyopro_id\
    \ = inf>\n  struct Min {\n    static constexpr KyoproT id = kyopro_id;\n    static\
    \ constexpr op(KyoproT kyopro_a, KyoproT kyopro_b) noexcept { return kyopro_a\
    \ < kyopro_b ? kyopro_a : kyopro_b; }\n  };\n}\n"
  code: "#pragma once\n#include <type_traits>\n#include \"constant.hpp\"\n\nnamespace\
    \ kyopro {\n  template<class KyoproT, KyoproT kyopro_id = 0>\n  struct Plus {\n\
    \    static constexpr KyoproT id = kyopro_id;\n    static constexpr op(KyoproT\
    \ kyopro_a, KyoproT kyopro_b) noexcept { return kyopro_a + kyopro_b; }\n    static\
    \ constexpr inv(KyoproT a) noexcept { return -kyopro_a; }\n  };\n  template<class\
    \ KyoproT, KyoproT kyopro_id = 1>\n  struct Mul {\n    static constexpr KyoproT\
    \ id = kyopro_id;\n    static constexpr op(KyoproT kyopro_a, KyoproT kyopro_b)\
    \ noexcept { return kyopro_a * kyopro_b; }\n    static constexpr inv(KyoproT a)\
    \ noexcept {\n      static_assert(!std::is_integral_v<KyoproT>);\n      return\
    \ 1 / kyopro_a;\n    }\n  };\n  template<class KyoproT, KyoproT kyopro_id = -inf>\n\
    \  struct Max {\n    static constexpr KyoproT id = kyopro_id;\n    static constexpr\
    \ op(KyoproT kyopro_a, KyoproT kyopro_b) noexcept { return kyopro_a > kyopro_b\
    \ ? kyopro_a : kyopro_b; }\n  };\n  template<class KyoproT, KyoproT kyopro_id\
    \ = inf>\n  struct Min {\n    static constexpr KyoproT id = kyopro_id;\n    static\
    \ constexpr op(KyoproT kyopro_a, KyoproT kyopro_b) noexcept { return kyopro_a\
    \ < kyopro_b ? kyopro_a : kyopro_b; }\n  };\n}"
  dependsOn:
  - base/constant.hpp
  - base/settings.hpp
  isVerificationFile: false
  path: base/monoid.hpp
  requiredBy:
  - structure/FenwickTree.hpp
  - all.hpp
  timestamp: '2022-01-05 11:14:02+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - yosupo/FenwickTree.test.cpp
documentation_of: base/monoid.hpp
layout: document
redirect_from:
- /library/base/monoid.hpp
- /library/base/monoid.hpp.html
title: base/monoid.hpp
---
