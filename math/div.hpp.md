---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all/all.hpp
    title: all/all.hpp
  - icon: ':warning:'
    path: math/all.hpp
    title: math/all.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/div.hpp\"\n#include <type_traits>\n\nnamespace kpr\
    \ {\n  template<class T, class U>\n  constexpr std::common_type_t<T, U> floor_div(T\
    \ x, U m) noexcept {\n    static_assert(std::is_integral_v<T> && std::is_integral_v<U>,\
    \ \"Integer is required\");\n    if constexpr (std::is_unsigned_v<T> || std::is_unsigned_v<U>)\
    \ return x / m;\n    auto d = x / m;\n    return d * m == x ? d : d - ((x < 0)\
    \ ^ (m < 0));\n  }\n\n  template<class T, class U>\n  constexpr std::common_type_t<T,\
    \ U> ceil_div(T x, U m) noexcept { return floor_div(x + m - static_cast<T>(1),\
    \ m); }\n}\n"
  code: "#pragma once\n#include <type_traits>\n\nnamespace kpr {\n  template<class\
    \ T, class U>\n  constexpr std::common_type_t<T, U> floor_div(T x, U m) noexcept\
    \ {\n    static_assert(std::is_integral_v<T> && std::is_integral_v<U>, \"Integer\
    \ is required\");\n    if constexpr (std::is_unsigned_v<T> || std::is_unsigned_v<U>)\
    \ return x / m;\n    auto d = x / m;\n    return d * m == x ? d : d - ((x < 0)\
    \ ^ (m < 0));\n  }\n\n  template<class T, class U>\n  constexpr std::common_type_t<T,\
    \ U> ceil_div(T x, U m) noexcept { return floor_div(x + m - static_cast<T>(1),\
    \ m); }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/div.hpp
  requiredBy:
  - math/all.hpp
  - all/all.hpp
  timestamp: '2022-04-27 22:05:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/div.hpp
layout: document
redirect_from:
- /library/math/div.hpp
- /library/math/div.hpp.html
title: math/div.hpp
---
