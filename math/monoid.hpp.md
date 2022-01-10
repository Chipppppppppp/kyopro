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
    \n#include <cstdint>\n#include <limits>\n#include <array>\n#include <utility>\n\
    #line 3 \"base/settings.hpp\"\n\n#ifndef KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT\
    \ std::int64_t\n#endif\n#ifndef KYOPRO_BASE_UINT\n#define KYOPRO_BASE_UINT std::size_t\n\
    #endif\n#ifndef KYOPRO_BASE_FLOAT\n#define KYOPRO_BASE_FLOAT double\n#endif\n\
    #ifndef KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD 1000000007\n#endif\n#ifndef\
    \ KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION 12\n#endif\n#ifndef\
    \ KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV 3\n#endif\n#line 4 \"math/power.hpp\"\
    \nnamespace kyopro {\n  template<class KyoproT>\n  constexpr KyoproT power(KyoproT\
    \ a, std::uint64_t n, KyoproT init = 1) noexcept {\n    while (n > 0) {\n    \
    \  if (n & 1) init *= a;\n      a *= a;\n      n >>= 1;\n    }\n    return init;\n\
    \  }\n}\n#line 8 \"base/constant.hpp\"\n\nnamespace kyopro {\n  inline constexpr\
    \ std::uint64_t kyopro_decimal_max = power(static_cast<std::uint64_t>(10), KYOPRO_DECIMAL_PRECISION);\n\
    \  template<class KyoproT>\n  inline constexpr KyoproT MOD = KYOPRO_DEFAULT_MOD;\n\
    \  inline constexpr KYOPRO_BASE_INT mod = MOD<KYOPRO_BASE_INT>;\n  template<class\
    \ KyoproT>\n  inline constexpr KyoproT INF = std::numeric_limits<KyoproT>::max()\
    \ / KYOPRO_INF_DIV;\n  inline constexpr KYOPRO_BASE_INT inf = INF<KYOPRO_BASE_INT>;\n\
    \  template<class KyoproT>\n  inline constexpr KYOPRO_BASE_FLOAT EPS = static_cast<KyoproT>(1)\
    \ / kyopro_decimal_max;\n  inline constexpr KYOPRO_BASE_FLOAT eps = EPS<KYOPRO_BASE_FLOAT>;\n\
    \  template<class KyoproT>\n  inline constexpr KyoproT PI = 3.14159265358979323846;\n\
    \  inline constexpr KYOPRO_BASE_FLOAT pi = PI<KYOPRO_BASE_FLOAT>;\n  inline constexpr\
    \ std::array<std::pair<KYOPRO_BASE_INT, KYOPRO_BASE_INT>, 4> beside{{{1, 0}, {0,\
    \ 1}, {-1, 0}, {0, -1}}};\n  inline constexpr std::array<std::pair<KYOPRO_BASE_INT,\
    \ KYOPRO_BASE_INT>, 8> around{{{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1,\
    \ -1}, {0, -1}, {1, -1}}};\n}\n#line 4 \"math/monoid.hpp\"\n\nnamespace kyopro\
    \ {\n  template<class KyoproT, KyoproT kyopro_id = 0>\n  struct Plus {\n    static\
    \ constexpr KyoproT id = kyopro_id;\n    static constexpr KyoproT op(KyoproT kyopro_a,\
    \ KyoproT kyopro_b) noexcept { return kyopro_a + kyopro_b; }\n    static constexpr\
    \ KyoproT inv(KyoproT kyopro_a) noexcept { return -kyopro_a; }\n  };\n  template<class\
    \ KyoproT, KyoproT kyopro_id = 1>\n  struct Mul {\n    static constexpr KyoproT\
    \ id = kyopro_id;\n    static constexpr KyoproT op(KyoproT kyopro_a, KyoproT kyopro_b)\
    \ noexcept { return kyopro_a * kyopro_b; }\n    static constexpr KyoproT inv(KyoproT\
    \ kyopro_a) noexcept {\n      static_assert(!std::is_integral_v<KyoproT>);\n \
    \     return 1 / kyopro_a;\n    }\n  };\n  template<class KyoproT, KyoproT kyopro_id\
    \ = -inf>\n  struct Max {\n    static constexpr KyoproT id = kyopro_id;\n    static\
    \ constexpr KyoproT op(KyoproT kyopro_a, KyoproT kyopro_b) noexcept { return kyopro_a\
    \ > kyopro_b ? kyopro_a : kyopro_b; }\n  };\n  template<class KyoproT, KyoproT\
    \ kyopro_id = inf>\n  struct Min {\n    static constexpr KyoproT id = kyopro_id;\n\
    \    static constexpr KyoproT op(KyoproT kyopro_a, KyoproT kyopro_b) noexcept\
    \ { return kyopro_a < kyopro_b ? kyopro_a : kyopro_b; }\n  };\n}\n"
  code: "#pragma once\n#include <type_traits>\n#include \"../base/constant.hpp\"\n\
    \nnamespace kyopro {\n  template<class KyoproT, KyoproT kyopro_id = 0>\n  struct\
    \ Plus {\n    static constexpr KyoproT id = kyopro_id;\n    static constexpr KyoproT\
    \ op(KyoproT kyopro_a, KyoproT kyopro_b) noexcept { return kyopro_a + kyopro_b;\
    \ }\n    static constexpr KyoproT inv(KyoproT kyopro_a) noexcept { return -kyopro_a;\
    \ }\n  };\n  template<class KyoproT, KyoproT kyopro_id = 1>\n  struct Mul {\n\
    \    static constexpr KyoproT id = kyopro_id;\n    static constexpr KyoproT op(KyoproT\
    \ kyopro_a, KyoproT kyopro_b) noexcept { return kyopro_a * kyopro_b; }\n    static\
    \ constexpr KyoproT inv(KyoproT kyopro_a) noexcept {\n      static_assert(!std::is_integral_v<KyoproT>);\n\
    \      return 1 / kyopro_a;\n    }\n  };\n  template<class KyoproT, KyoproT kyopro_id\
    \ = -inf>\n  struct Max {\n    static constexpr KyoproT id = kyopro_id;\n    static\
    \ constexpr KyoproT op(KyoproT kyopro_a, KyoproT kyopro_b) noexcept { return kyopro_a\
    \ > kyopro_b ? kyopro_a : kyopro_b; }\n  };\n  template<class KyoproT, KyoproT\
    \ kyopro_id = inf>\n  struct Min {\n    static constexpr KyoproT id = kyopro_id;\n\
    \    static constexpr KyoproT op(KyoproT kyopro_a, KyoproT kyopro_b) noexcept\
    \ { return kyopro_a < kyopro_b ? kyopro_a : kyopro_b; }\n  };\n}"
  dependsOn:
  - base/constant.hpp
  - base/settings.hpp
  - math/power.hpp
  isVerificationFile: false
  path: math/monoid.hpp
  requiredBy:
  - structure/FenwickTree.hpp
  - structure/all.hpp
  timestamp: '2022-01-10 20:12:50+09:00'
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
