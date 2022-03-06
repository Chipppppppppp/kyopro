---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
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
    \ {\n  template<class _typeT, class _typeU>\n  constexpr std::common_type_t<_typeT,\
    \ _typeU> floor_div(_typeT _x, _typeU _m) noexcept {\n    static_assert(std::is_integral_v<_typeT>\
    \ && std::is_integral_v<_typeU>);\n    if constexpr (std::is_unsigned_v<_typeT>\
    \ || std::is_unsigned_v<_typeU>) return _x / _m;\n    auto _d = _x / _m;\n   \
    \ return _d * _m == _x ? _d : _d - ((_x < 0) ^ (_m < 0));\n  }\n\n  template<class\
    \ _typeT, class _typeU>\n  constexpr std::common_type_t<_typeT, _typeU> ceil_div(_typeT\
    \ _x, _typeU _m) noexcept { return floor_div(_x + _m - static_cast<_typeT>(1),\
    \ _m); }\n}\n"
  code: "#pragma once\n#include <type_traits>\n\nnamespace kyopro {\n  template<class\
    \ _typeT, class _typeU>\n  constexpr std::common_type_t<_typeT, _typeU> floor_div(_typeT\
    \ _x, _typeU _m) noexcept {\n    static_assert(std::is_integral_v<_typeT> && std::is_integral_v<_typeU>);\n\
    \    if constexpr (std::is_unsigned_v<_typeT> || std::is_unsigned_v<_typeU>) return\
    \ _x / _m;\n    auto _d = _x / _m;\n    return _d * _m == _x ? _d : _d - ((_x\
    \ < 0) ^ (_m < 0));\n  }\n\n  template<class _typeT, class _typeU>\n  constexpr\
    \ std::common_type_t<_typeT, _typeU> ceil_div(_typeT _x, _typeU _m) noexcept {\
    \ return floor_div(_x + _m - static_cast<_typeT>(1), _m); }\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/div.hpp
  requiredBy:
  - math/all.hpp
  timestamp: '2022-03-06 15:44:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/div.hpp
layout: document
redirect_from:
- /library/math/div.hpp
- /library/math/div.hpp.html
title: math/div.hpp
---
