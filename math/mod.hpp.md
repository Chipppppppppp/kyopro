---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/ModInt.hpp
    title: math/ModInt.hpp
  - icon: ':warning:'
    path: math/math.hpp
    title: math/math.hpp
  - icon: ':warning:'
    path: template/alias.hpp
    title: template/alias.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/mod.hpp\"\n#include <cassert>\n#include <type_traits>\n\
    \nnamespace kpr {\n    [[maybe_unused]] inline constexpr struct {\n        template<class\
    \ T, class U>\n        constexpr std::common_type_t<T, U> operator ()(T x, U m)\
    \ const noexcept {\n            static_assert(is_integer_v<T> && is_integer_v<U>,\
    \ \"Both of the arguments must be integers\");\n            if constexpr (is_unsigned_integer_v<T>\
    \ || is_unsigned_integer_v<U>) return x % m;\n            return (x %= m) < 0\
    \ ? x + m : x;\n        }\n    } floor_mod;\n\n    [[maybe_unused]] inline constexpr\
    \ struct {\n        template<class T, class U>\n        constexpr std::common_type_t<T,\
    \ U> operator ()(T x, U m) const noexcept {\n            return m - floor_mod(x\
    \ - 1, m) - static_cast<T>(1);\n        }\n    } ceil_mod;\n} // namespace kpr\n"
  code: "#pragma once\n#include <cassert>\n#include <type_traits>\n\nnamespace kpr\
    \ {\n    [[maybe_unused]] inline constexpr struct {\n        template<class T,\
    \ class U>\n        constexpr std::common_type_t<T, U> operator ()(T x, U m) const\
    \ noexcept {\n            static_assert(is_integer_v<T> && is_integer_v<U>, \"\
    Both of the arguments must be integers\");\n            if constexpr (is_unsigned_integer_v<T>\
    \ || is_unsigned_integer_v<U>) return x % m;\n            return (x %= m) < 0\
    \ ? x + m : x;\n        }\n    } floor_mod;\n\n    [[maybe_unused]] inline constexpr\
    \ struct {\n        template<class T, class U>\n        constexpr std::common_type_t<T,\
    \ U> operator ()(T x, U m) const noexcept {\n            return m - floor_mod(x\
    \ - 1, m) - static_cast<T>(1);\n        }\n    } ceil_mod;\n} // namespace kpr\n"
  dependsOn: []
  isVerificationFile: false
  path: math/mod.hpp
  requiredBy:
  - template/alias.hpp
  - math/ModInt.hpp
  - math/math.hpp
  timestamp: '2023-02-01 00:00:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/mod.hpp
layout: document
redirect_from:
- /library/math/mod.hpp
- /library/math/mod.hpp.html
title: math/mod.hpp
---
