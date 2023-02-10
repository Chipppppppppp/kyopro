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
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/make_vector.hpp\"\n#include <cstddef>\r\n#include\
    \ <cstdint>\r\n#include <utility>\r\n#include <vector>\r\n\r\nnamespace kpr {\r\
    \n    [[maybe_unused]] inline constexpr struct {\r\n        template<std::size_t\
    \ idx = 0, std::size_t n, class T>\r\n        auto operator ()(const std::size_t\
    \ (&d)[n], T&& init) noexcept {\r\n            if constexpr (idx < n) return std::vector(d[idx],\
    \ operator ()<idx + 1>(d, std::forward<T>(init)));\r\n            else return\
    \ init;\r\n        }\r\n\r\n        template<class T, std::size_t idx = 0, std::size_t\
    \ n>\r\n        auto operator ()(const std::size_t (&d)[n], const T& init = {})\
    \ noexcept {\r\n            if constexpr (idx < n) return std::vector(d[idx],\
    \ operator ()<idx + 1>(d, init));\r\n            else return init;\r\n       \
    \ }\r\n    } make_vector;\r\n} // namespace kpr\r\n"
  code: "#pragma once\r\n#include <cstddef>\r\n#include <cstdint>\r\n#include <utility>\r\
    \n#include <vector>\r\n\r\nnamespace kpr {\r\n    [[maybe_unused]] inline constexpr\
    \ struct {\r\n        template<std::size_t idx = 0, std::size_t n, class T>\r\n\
    \        auto operator ()(const std::size_t (&d)[n], T&& init) noexcept {\r\n\
    \            if constexpr (idx < n) return std::vector(d[idx], operator ()<idx\
    \ + 1>(d, std::forward<T>(init)));\r\n            else return init;\r\n      \
    \  }\r\n\r\n        template<class T, std::size_t idx = 0, std::size_t n>\r\n\
    \        auto operator ()(const std::size_t (&d)[n], const T& init = {}) noexcept\
    \ {\r\n            if constexpr (idx < n) return std::vector(d[idx], operator\
    \ ()<idx + 1>(d, init));\r\n            else return init;\r\n        }\r\n   \
    \ } make_vector;\r\n} // namespace kpr\r\n"
  dependsOn: []
  isVerificationFile: false
  path: template/make_vector.hpp
  requiredBy:
  - template/template.hpp
  - all.hpp
  timestamp: '2023-02-11 02:36:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/make_vector.hpp
layout: document
redirect_from:
- /library/template/make_vector.hpp
- /library/template/make_vector.hpp.html
title: template/make_vector.hpp
---
