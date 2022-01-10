---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  - icon: ':warning:'
    path: math/all.hpp
    title: math/all.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/div.hpp\"\n#include <type_traits>\n\nnamespace kyopro\
    \ {\n  template<class KyoproT, class KyoproU>\n  constexpr KyoproT floor_div(KyoproT\
    \ kyopro_x, KyoproU kyopro_m) noexcept {\n    static_assert(std::is_integral_v<KyoproT>\
    \ && std::is_integral_v<KyoproU>);\n    if constexpr (std::is_unsigned_v<KyoproT>)\
    \ return kyopro_x / kyopro_m;\n    if (kyopro_m < 0) return -kyopro_x / -kyopro_m;\n\
    \    if (kyopro_x < 0) return (kyopro_x + 1) / kyopro_m - 1;\n    return kyopro_x\
    \ / kyopro_m;\n  }\n\n  template<class KyoproT, class KyoproU>\n  constexpr KyoproT\
    \ ceil_div(KyoproT kyopro_x, KyoproU kyopro_m) noexcept { return floor_div(kyopro_x\
    \ + kyopro_m - 1, kyopro_m); }\n}\n"
  code: "#pragma once\n#include <type_traits>\n\nnamespace kyopro {\n  template<class\
    \ KyoproT, class KyoproU>\n  constexpr KyoproT floor_div(KyoproT kyopro_x, KyoproU\
    \ kyopro_m) noexcept {\n    static_assert(std::is_integral_v<KyoproT> && std::is_integral_v<KyoproU>);\n\
    \    if constexpr (std::is_unsigned_v<KyoproT>) return kyopro_x / kyopro_m;\n\
    \    if (kyopro_m < 0) return -kyopro_x / -kyopro_m;\n    if (kyopro_x < 0) return\
    \ (kyopro_x + 1) / kyopro_m - 1;\n    return kyopro_x / kyopro_m;\n  }\n\n  template<class\
    \ KyoproT, class KyoproU>\n  constexpr KyoproT ceil_div(KyoproT kyopro_x, KyoproU\
    \ kyopro_m) noexcept { return floor_div(kyopro_x + kyopro_m - 1, kyopro_m); }\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: math/div.hpp
  requiredBy:
  - math/all.hpp
  - all.hpp
  timestamp: '2022-01-10 19:46:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/div.hpp
layout: document
redirect_from:
- /library/math/div.hpp
- /library/math/div.hpp.html
title: math/div.hpp
---
