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
    path: math/all.hpp
    title: math/all.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/div.hpp\"\n#include <type_traits>\n\nnamespace kyopro\
    \ {\n    inline constexpr struct {\n        template<class T, class U>\n     \
    \   constexpr std::common_type_t<T, U> operator ()(T x, U m) const noexcept {\n\
    \            static_assert(std::is_integral_v<T> && std::is_integral_v<U>, \"\
    Integer is required\");\n            if constexpr (std::is_unsigned_v<T> || std::is_unsigned_v<U>)\
    \ return x / m;\n            auto d = x / m;\n            return d * m == x ?\
    \ d : d - ((x < 0) ^ (m < 0));\n        }\n    } floor_div;\n\n    inline constexpr\
    \ struct {\n        template<class T, class U>\n        constexpr std::common_type_t<T,\
    \ U> operator ()(T x, U m) const noexcept {\n            return floor_div(x +\
    \ m - static_cast<T>(1), m);\n        }\n    } ceil_div;\n} // namespace kyopro\n"
  code: "#pragma once\n#include <type_traits>\n\nnamespace kyopro {\n    inline constexpr\
    \ struct {\n        template<class T, class U>\n        constexpr std::common_type_t<T,\
    \ U> operator ()(T x, U m) const noexcept {\n            static_assert(std::is_integral_v<T>\
    \ && std::is_integral_v<U>, \"Integer is required\");\n            if constexpr\
    \ (std::is_unsigned_v<T> || std::is_unsigned_v<U>) return x / m;\n           \
    \ auto d = x / m;\n            return d * m == x ? d : d - ((x < 0) ^ (m < 0));\n\
    \        }\n    } floor_div;\n\n    inline constexpr struct {\n        template<class\
    \ T, class U>\n        constexpr std::common_type_t<T, U> operator ()(T x, U m)\
    \ const noexcept {\n            return floor_div(x + m - static_cast<T>(1), m);\n\
    \        }\n    } ceil_div;\n} // namespace kyopro"
  dependsOn: []
  isVerificationFile: false
  path: math/div.hpp
  requiredBy:
  - all/all.hpp
  - math/all.hpp
  - all.hpp
  timestamp: '2022-07-28 17:38:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/div.hpp
layout: document
redirect_from:
- /library/math/div.hpp
- /library/math/div.hpp.html
title: math/div.hpp
---
