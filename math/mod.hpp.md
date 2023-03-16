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
    path: math/math.hpp
    title: math/math.hpp
  - icon: ':warning:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':warning:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':warning:'
    path: verify/hello_world.cpp
    title: verify/hello_world.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/mod.hpp\"\n#include <cassert>\r\n#include <type_traits>\r\
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
  path: math/mod.hpp
  requiredBy:
  - all/all.hpp
  - all.hpp
  - math/ModInt.hpp
  - math/math.hpp
  - verify/hello_world.cpp
  - template/template.hpp
  - template/alias.hpp
  timestamp: '2023-02-11 02:36:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/mod.hpp
layout: document
redirect_from:
- /library/math/mod.hpp
- /library/math/mod.hpp.html
title: math/mod.hpp
---
