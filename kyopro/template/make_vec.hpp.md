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
  bundledCode: "#line 2 \"kyopro/template/make_vec.hpp\"\n#include <cstddef>\r\n#include\
    \ <cstdint>\r\n#include <utility>\r\n#include <vector>\r\n\r\nnamespace kpr {\r\
    \n    [[maybe_unused]] inline constexpr struct {\r\n        template<class T,\
    \ std::size_t n, std::size_t i = 0>\r\n        auto operator ()(const std::size_t\
    \ (&d)[n], const T& init = {}) noexcept {\r\n            if constexpr (i < n)\
    \ return std::vector(d[i], operator ()<T, n, i + 1>(d, init));\r\n           \
    \ else return init;\r\n        }\r\n\r\n        template<class T, std::size_t\
    \ n>\r\n        auto operator ()(const std::size_t (&d)[n]) noexcept {\r\n   \
    \         return operator ()(d, T{});\r\n        }\r\n    } make_vec;\r\n} //\
    \ namespace kpr\r\n"
  code: "#pragma once\r\n#include <cstddef>\r\n#include <cstdint>\r\n#include <utility>\r\
    \n#include <vector>\r\n\r\nnamespace kpr {\r\n    [[maybe_unused]] inline constexpr\
    \ struct {\r\n        template<class T, std::size_t n, std::size_t i = 0>\r\n\
    \        auto operator ()(const std::size_t (&d)[n], const T& init = {}) noexcept\
    \ {\r\n            if constexpr (i < n) return std::vector(d[i], operator ()<T,\
    \ n, i + 1>(d, init));\r\n            else return init;\r\n        }\r\n\r\n \
    \       template<class T, std::size_t n>\r\n        auto operator ()(const std::size_t\
    \ (&d)[n]) noexcept {\r\n            return operator ()(d, T{});\r\n        }\r\
    \n    } make_vec;\r\n} // namespace kpr\r\n"
  dependsOn: []
  isVerificationFile: false
  path: kyopro/template/make_vec.hpp
  requiredBy:
  - kyopro/template/template.hpp
  timestamp: '2023-04-02 21:40:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kyopro/template/make_vec.hpp
layout: document
redirect_from:
- /library/kyopro/template/make_vec.hpp
- /library/kyopro/template/make_vec.hpp.html
title: kyopro/template/make_vec.hpp
---
