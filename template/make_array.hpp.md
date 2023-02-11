---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
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
  bundledCode: "#line 2 \"template/make_array.hpp\"\n#include <cstddef>\r\n#include\
    \ <array>\r\n\r\nnamespace kpr {\r\n    [[maybe_unused]] inline constexpr struct\
    \ {\r\n        template<class T>\r\n        constexpr auto operator ()(const T&\
    \ init = {}) noexcept {\r\n            return init;\r\n        }\r\n\r\n     \
    \   template<class T, std::size_t length, std::size_t... lengths>\r\n        constexpr\
    \ auto operator ()(const T& init = {}) noexcept {\r\n            auto elm = operator\
    \ ()<T, lengths...>(init);\r\n            std::array<decltype(elm), length> res;\r\
    \n            for (auto& i: res) i = elm;\r\n            return res;\r\n     \
    \   }\r\n    } make_array;\r\n} // namespace kpr\r\n"
  code: "#pragma once\r\n#include <cstddef>\r\n#include <array>\r\n\r\nnamespace kpr\
    \ {\r\n    [[maybe_unused]] inline constexpr struct {\r\n        template<class\
    \ T>\r\n        constexpr auto operator ()(const T& init = {}) noexcept {\r\n\
    \            return init;\r\n        }\r\n\r\n        template<class T, std::size_t\
    \ length, std::size_t... lengths>\r\n        constexpr auto operator ()(const\
    \ T& init = {}) noexcept {\r\n            auto elm = operator ()<T, lengths...>(init);\r\
    \n            std::array<decltype(elm), length> res;\r\n            for (auto&\
    \ i: res) i = elm;\r\n            return res;\r\n        }\r\n    } make_array;\r\
    \n} // namespace kpr\r\n"
  dependsOn: []
  isVerificationFile: false
  path: template/make_array.hpp
  requiredBy:
  - verify/hello_world.cpp
  - template/template.hpp
  - all.hpp
  timestamp: '2023-02-11 02:36:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/make_array.hpp
layout: document
redirect_from:
- /library/template/make_array.hpp
- /library/template/make_array.hpp.html
title: template/make_array.hpp
---
