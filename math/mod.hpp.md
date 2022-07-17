---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  - icon: ':warning:'
    path: all/all.hpp
    title: all/all.hpp
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
  bundledCode: "#line 2 \"math/mod.hpp\"\n#include <cassert>\n#include <type_traits>\n\
    \nnamespace kyopro {\n  inline constexpr struct {\n    template<class T, class\
    \ U>\n    constexpr std::common_type_t<T, U> operator ()(T x, U m) const noexcept\
    \ {\n      static_assert(std::is_integral_v<T> && std::is_integral_v<U>, \"Integer\
    \ is required\");\n      if constexpr (std::is_unsigned_v<T> || std::is_unsigned_v<U>)\
    \ return x % m;\n      return (x %= m) < 0 ? x + m : x;\n    }\n  } floor_mod;\n\
    \n  inline constexpr struct {\n    template<class T, class U>\n    constexpr std::common_type_t<T,\
    \ U> operator ()(T x, U m) const noexcept {\n      return m - floor_mod(x - 1,\
    \ m) - static_cast<T>(1);\n    }\n   } ceil_mod;\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <type_traits>\n\nnamespace kyopro\
    \ {\n  inline constexpr struct {\n    template<class T, class U>\n    constexpr\
    \ std::common_type_t<T, U> operator ()(T x, U m) const noexcept {\n      static_assert(std::is_integral_v<T>\
    \ && std::is_integral_v<U>, \"Integer is required\");\n      if constexpr (std::is_unsigned_v<T>\
    \ || std::is_unsigned_v<U>) return x % m;\n      return (x %= m) < 0 ? x + m :\
    \ x;\n    }\n  } floor_mod;\n\n  inline constexpr struct {\n    template<class\
    \ T, class U>\n    constexpr std::common_type_t<T, U> operator ()(T x, U m) const\
    \ noexcept {\n      return m - floor_mod(x - 1, m) - static_cast<T>(1);\n    }\n\
    \   } ceil_mod;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/mod.hpp
  requiredBy:
  - all/all.hpp
  - math/ModInt.hpp
  - math/all.hpp
  - all.hpp
  - template/alias.hpp
  - template/all.hpp
  timestamp: '2022-07-07 16:11:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/mod.hpp
layout: document
redirect_from:
- /library/math/mod.hpp
- /library/math/mod.hpp.html
title: math/mod.hpp
---
