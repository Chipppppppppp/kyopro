---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: kpr/all.hpp
    title: kpr/all.hpp
  - icon: ':warning:'
    path: kpr/template/template.hpp
    title: kpr/template/template.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"kpr/template/make_array.hpp\"\n#include <cstddef>\r\n#include\
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
  path: kpr/template/make_array.hpp
  requiredBy:
  - kpr/template/template.hpp
  - kpr/all.hpp
  timestamp: '2023-04-04 01:42:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kpr/template/make_array.hpp
layout: document
redirect_from:
- /library/kpr/template/make_array.hpp
- /library/kpr/template/make_array.hpp.html
title: kpr/template/make_array.hpp
---
