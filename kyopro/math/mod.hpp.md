---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: kyopro/all.hpp
    title: kyopro/all.hpp
  - icon: ':warning:'
    path: kyopro/all/all.hpp
    title: kyopro/all/all.hpp
  - icon: ':warning:'
    path: kyopro/math/BinomMod.hpp
    title: kyopro/math/BinomMod.hpp
  - icon: ':warning:'
    path: kyopro/math/ModInt.hpp
    title: kyopro/math/ModInt.hpp
  - icon: ':warning:'
    path: kyopro/math/math.hpp
    title: kyopro/math/math.hpp
  - icon: ':warning:'
    path: kyopro/template/alias.hpp
    title: kyopro/template/alias.hpp
  - icon: ':warning:'
    path: kyopro/template/template.hpp
    title: kyopro/template/template.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"kyopro/math/mod.hpp\"\n#include <cassert>\r\n#include <type_traits>\r\
    \n\r\nnamespace kpr {\r\n    [[maybe_unused]] inline constexpr struct {\r\n  \
    \      template<class T, class U>\r\n        constexpr std::common_type_t<T, U>\
    \ operator ()(T x, U m) const noexcept {\r\n            static_assert(is_integer_v<T>\
    \ && is_integer_v<U>, \"Both of the arguments must be integers\");\r\n       \
    \     if constexpr (is_unsigned_integer_v<T> || is_unsigned_integer_v<U>) return\
    \ x % m;\r\n            return (x %= m) < 0 ? x + m : x;\r\n        }\r\n    }\
    \ floor_mod;\r\n\r\n    [[maybe_unused]] inline constexpr struct {\r\n       \
    \ template<class T, class U>\r\n        constexpr std::common_type_t<T, U> operator\
    \ ()(T x, U m) const noexcept {\r\n            return m - floor_mod(x - 1, m)\
    \ - static_cast<T>(1);\r\n        }\r\n    } ceil_mod;\r\n} // namespace kpr\r\
    \n"
  code: "#pragma once\r\n#include <cassert>\r\n#include <type_traits>\r\n\r\nnamespace\
    \ kpr {\r\n    [[maybe_unused]] inline constexpr struct {\r\n        template<class\
    \ T, class U>\r\n        constexpr std::common_type_t<T, U> operator ()(T x, U\
    \ m) const noexcept {\r\n            static_assert(is_integer_v<T> && is_integer_v<U>,\
    \ \"Both of the arguments must be integers\");\r\n            if constexpr (is_unsigned_integer_v<T>\
    \ || is_unsigned_integer_v<U>) return x % m;\r\n            return (x %= m) <\
    \ 0 ? x + m : x;\r\n        }\r\n    } floor_mod;\r\n\r\n    [[maybe_unused]]\
    \ inline constexpr struct {\r\n        template<class T, class U>\r\n        constexpr\
    \ std::common_type_t<T, U> operator ()(T x, U m) const noexcept {\r\n        \
    \    return m - floor_mod(x - 1, m) - static_cast<T>(1);\r\n        }\r\n    }\
    \ ceil_mod;\r\n} // namespace kpr\r\n"
  dependsOn: []
  isVerificationFile: false
  path: kyopro/math/mod.hpp
  requiredBy:
  - kyopro/all/all.hpp
  - kyopro/all.hpp
  - kyopro/math/ModInt.hpp
  - kyopro/math/math.hpp
  - kyopro/math/BinomMod.hpp
  - kyopro/template/template.hpp
  - kyopro/template/alias.hpp
  timestamp: '2023-04-02 21:40:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kyopro/math/mod.hpp
layout: document
redirect_from:
- /library/kyopro/math/mod.hpp
- /library/kyopro/math/mod.hpp.html
title: kyopro/math/mod.hpp
---