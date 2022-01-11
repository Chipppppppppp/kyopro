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
    \nnamespace kyopro {\n  template<class _typeT, class _typeU>\n  constexpr _typeT\
    \ floor_mod(_typeT _x, _typeU _m) noexcept {\n    static_assert(std::is_integral_v<_typeT>\
    \ && std::is_integral_v<_typeU>);\n    if constexpr (std::is_unsigned_v<_typeT>)\
    \ return _x % _m;\n    return (_x %= _m) < 0 ? _x + _m : _x;\n  }\n\n  template<class\
    \ _typeT, class _typeU>\n  constexpr _typeT ceil_mod(_typeT _x, _typeU _m) noexcept\
    \ { return _m - floor_mod(_x - 1, _m) - 1; }\n}\n"
  code: "#pragma once\n#include <type_traits>\n#include <cassert>\n\nnamespace kyopro\
    \ {\n  template<class _typeT, class _typeU>\n  constexpr _typeT floor_mod(_typeT\
    \ _x, _typeU _m) noexcept {\n    static_assert(std::is_integral_v<_typeT> && std::is_integral_v<_typeU>);\n\
    \    if constexpr (std::is_unsigned_v<_typeT>) return _x % _m;\n    return (_x\
    \ %= _m) < 0 ? _x + _m : _x;\n  }\n\n  template<class _typeT, class _typeU>\n\
    \  constexpr _typeT ceil_mod(_typeT _x, _typeU _m) noexcept { return _m - floor_mod(_x\
    \ - 1, _m) - 1; }\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/mod.hpp
  requiredBy:
  - math/ModInt.hpp
  - math/all.hpp
  - template/alias.hpp
  - template/all.hpp
  - all.hpp
  timestamp: '2022-01-11 23:13:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/mod.hpp
layout: document
redirect_from:
- /library/math/mod.hpp
- /library/math/mod.hpp.html
title: math/mod.hpp
---
