---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"kpr/math/mod.hpp\"\n#include <cassert>\r\n#include <type_traits>\r\
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
  path: kpr/math/mod.hpp
  requiredBy: []
  timestamp: '2023-04-04 01:42:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kpr/math/mod.hpp
layout: document
redirect_from:
- /library/kpr/math/mod.hpp
- /library/kpr/math/mod.hpp.html
title: kpr/math/mod.hpp
---
