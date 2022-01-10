---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  - icon: ':warning:'
    path: math/ModInt.hpp
    title: math/ModInt.hpp
  - icon: ':warning:'
    path: math/all.hpp
    title: math/all.hpp
  - icon: ':warning:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':warning:'
    path: template/all.hpp
    title: template/all.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/mod.hpp\"\n#include <type_traits>\n#include <cassert>\n\
    \nnamespace kyopro {\n  template<class KyoproT, class KyoproU>\n  constexpr KyoproT\
    \ floor_mod(KyoproT kyopro_x, KyoproU kyopro_m) noexcept {\n    static_assert(std::is_integral_v<KyoproT>\
    \ && std::is_integral_v<KyoproU>);\n    if constexpr (std::is_unsigned_v<KyoproT>)\
    \ return kyopro_x % kyopro_m;\n    return (kyopro_x %= kyopro_m) < 0 ? kyopro_x\
    \ + kyopro_m : kyopro_x;\n  }\n\n  template<class KyoproT, class KyoproU>\n  constexpr\
    \ KyoproT ceil_mod(KyoproT kyopro_x, KyoproU kyopro_m) noexcept { return kyopro_m\
    \ - floor_mod(kyopro_x - 1, kyopro_m) - 1; }\n}\n"
  code: "#pragma once\n#include <type_traits>\n#include <cassert>\n\nnamespace kyopro\
    \ {\n  template<class KyoproT, class KyoproU>\n  constexpr KyoproT floor_mod(KyoproT\
    \ kyopro_x, KyoproU kyopro_m) noexcept {\n    static_assert(std::is_integral_v<KyoproT>\
    \ && std::is_integral_v<KyoproU>);\n    if constexpr (std::is_unsigned_v<KyoproT>)\
    \ return kyopro_x % kyopro_m;\n    return (kyopro_x %= kyopro_m) < 0 ? kyopro_x\
    \ + kyopro_m : kyopro_x;\n  }\n\n  template<class KyoproT, class KyoproU>\n  constexpr\
    \ KyoproT ceil_mod(KyoproT kyopro_x, KyoproU kyopro_m) noexcept { return kyopro_m\
    \ - floor_mod(kyopro_x - 1, kyopro_m) - 1; }\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/mod.hpp
  requiredBy:
  - math/ModInt.hpp
  - math/all.hpp
  - template/alias.hpp
  - template/all.hpp
  - all.hpp
  timestamp: '2022-01-10 19:46:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/mod.hpp
layout: document
redirect_from:
- /library/math/mod.hpp
- /library/math/mod.hpp.html
title: math/mod.hpp
---
