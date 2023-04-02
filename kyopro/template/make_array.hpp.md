---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: kyopro/template/template.hpp
    title: kyopro/template/template.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"kyopro/template/make_array.hpp\"\n#include <cstddef>\r\n\
    #include <array>\r\n\r\nnamespace kpr {\r\n    [[maybe_unused]] inline constexpr\
    \ struct {\r\n        template<class T>\r\n        constexpr auto operator ()(const\
    \ T& init = {}) noexcept {\r\n            return init;\r\n        }\r\n\r\n  \
    \      template<class T, std::size_t length, std::size_t... lengths>\r\n     \
    \   constexpr auto operator ()(const T& init = {}) noexcept {\r\n            auto\
    \ elm = operator ()<T, lengths...>(init);\r\n            std::array<decltype(elm),\
    \ length> res;\r\n            for (auto& i: res) i = elm;\r\n            return\
    \ res;\r\n        }\r\n    } make_array;\r\n} // namespace kpr\r\n"
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
  path: kyopro/template/make_array.hpp
  requiredBy:
  - kyopro/template/template.hpp
  timestamp: '2023-04-02 21:40:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kyopro/template/make_array.hpp
layout: document
redirect_from:
- /library/kyopro/template/make_array.hpp
- /library/kyopro/template/make_array.hpp.html
title: kyopro/template/make_array.hpp
---
