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
  bundledCode: "#line 2 \"template/make_array.hpp\"\n#include <cstddef>\n#include\
    \ <array>\n\nnamespace kpr {\n    [[maybe_unused]] inline constexpr struct {\n\
    \        template<class T>\n        constexpr auto operator ()(const T& init =\
    \ {}) noexcept {\n            return init;\n        }\n\n        template<class\
    \ T, std::size_t length, std::size_t... lengths>\n        constexpr auto operator\
    \ ()(const T& init = {}) noexcept {\n            auto elm = operator ()<T, lengths...>(init);\n\
    \            std::array<decltype(elm), length> res;\n            for (auto& i:\
    \ res) i = elm;\n            return res;\n        }\n    } make_array;\n} // namespace\
    \ kpr\n"
  code: "#pragma once\n#include <cstddef>\n#include <array>\n\nnamespace kpr {\n \
    \   [[maybe_unused]] inline constexpr struct {\n        template<class T>\n  \
    \      constexpr auto operator ()(const T& init = {}) noexcept {\n           \
    \ return init;\n        }\n\n        template<class T, std::size_t length, std::size_t...\
    \ lengths>\n        constexpr auto operator ()(const T& init = {}) noexcept {\n\
    \            auto elm = operator ()<T, lengths...>(init);\n            std::array<decltype(elm),\
    \ length> res;\n            for (auto& i: res) i = elm;\n            return res;\n\
    \        }\n    } make_array;\n} // namespace kpr\n"
  dependsOn: []
  isVerificationFile: false
  path: template/make_array.hpp
  requiredBy: []
  timestamp: '2023-02-01 00:00:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/make_array.hpp
layout: document
redirect_from:
- /library/template/make_array.hpp
- /library/template/make_array.hpp.html
title: template/make_array.hpp
---
