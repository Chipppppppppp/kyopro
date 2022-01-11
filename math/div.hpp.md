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
    \ {\n  template<class _typeT, class _typeU>\n  constexpr _typeT floor_div(_typeT\
    \ _x, _typeU _m) noexcept {\n    static_assert(std::is_integral_v<_typeT> && std::is_integral_v<_typeU>);\n\
    \    if constexpr (std::is_unsigned_v<_typeT>) return _x / _m;\n    if (_m < 0)\
    \ return -_x / -_m;\n    if (_x < 0) return (_x + 1) / _m - 1;\n    return _x\
    \ / _m;\n  }\n\n  template<class _typeT, class _typeU>\n  constexpr _typeT ceil_div(_typeT\
    \ _x, _typeU _m) noexcept { return floor_div(_x + _m - 1, _m); }\n}\n"
  code: "#pragma once\n#include <type_traits>\n\nnamespace kyopro {\n  template<class\
    \ _typeT, class _typeU>\n  constexpr _typeT floor_div(_typeT _x, _typeU _m) noexcept\
    \ {\n    static_assert(std::is_integral_v<_typeT> && std::is_integral_v<_typeU>);\n\
    \    if constexpr (std::is_unsigned_v<_typeT>) return _x / _m;\n    if (_m < 0)\
    \ return -_x / -_m;\n    if (_x < 0) return (_x + 1) / _m - 1;\n    return _x\
    \ / _m;\n  }\n\n  template<class _typeT, class _typeU>\n  constexpr _typeT ceil_div(_typeT\
    \ _x, _typeU _m) noexcept { return floor_div(_x + _m - 1, _m); }\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/div.hpp
  requiredBy:
  - math/all.hpp
  - all.hpp
  timestamp: '2022-01-11 23:13:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/div.hpp
layout: document
redirect_from:
- /library/math/div.hpp
- /library/math/div.hpp.html
title: math/div.hpp
---
