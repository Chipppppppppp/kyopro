---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: kpr/all.hpp
    title: kpr/all.hpp
  - icon: ':warning:'
    path: kpr/all/all.hpp
    title: kpr/all/all.hpp
  - icon: ':question:'
    path: kpr/math/BinomMod.hpp
    title: kpr/math/BinomMod.hpp
  - icon: ':question:'
    path: kpr/math/ModInt.hpp
    title: kpr/math/ModInt.hpp
  - icon: ':warning:'
    path: kpr/math/math.hpp
    title: kpr/math/math.hpp
  - icon: ':warning:'
    path: kpr/template/alias.hpp
    title: kpr/template/alias.hpp
  - icon: ':warning:'
    path: kpr/template/template.hpp
    title: kpr/template/template.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/mod/DPL_5_A.test.cpp
    title: verify/aoj/mod/DPL_5_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj/mod/DPL_5_B.test.cpp
    title: verify/aoj/mod/DPL_5_B.test.cpp
  - icon: ':x:'
    path: verify/aoj/mod/DPL_5_C.test.cpp
    title: verify/aoj/mod/DPL_5_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj/mod/DPL_5_D.test.cpp
    title: verify/aoj/mod/DPL_5_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj/mod/DPL_5_E.test.cpp
    title: verify/aoj/mod/DPL_5_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj/mod/DPL_5_F.test.cpp
    title: verify/aoj/mod/DPL_5_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/point_set_range_composite.test.cpp
    title: verify/yosupo/point_set_range_composite.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
  requiredBy:
  - kpr/all/all.hpp
  - kpr/math/ModInt.hpp
  - kpr/math/math.hpp
  - kpr/math/BinomMod.hpp
  - kpr/template/alias.hpp
  - kpr/template/template.hpp
  - kpr/all.hpp
  timestamp: '2023-04-04 01:42:52+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/yosupo/point_set_range_composite.test.cpp
  - verify/aoj/mod/DPL_5_B.test.cpp
  - verify/aoj/mod/DPL_5_F.test.cpp
  - verify/aoj/mod/DPL_5_C.test.cpp
  - verify/aoj/mod/DPL_5_A.test.cpp
  - verify/aoj/mod/DPL_5_D.test.cpp
  - verify/aoj/mod/DPL_5_E.test.cpp
documentation_of: kpr/math/mod.hpp
layout: document
redirect_from:
- /library/kpr/math/mod.hpp
- /library/kpr/math/mod.hpp.html
title: kpr/math/mod.hpp
---
