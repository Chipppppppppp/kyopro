---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: template/all.hpp
    title: template/all.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/make_vector.hpp\"\n#include <cstddef>\n#include\
    \ <cstdint>\n#include <utility>\n#include <vector>\n\nnamespace kyopro {\n   \
    \ inline constexpr struct {\n        template<std::size_t idx = 0, std::size_t\
    \ n, class T>\n        auto operator ()(const std::size_t (&d)[n], T&& init) noexcept\
    \ {\n            if constexpr (idx < n) return std::vector(d[idx], operator ()<idx\
    \ + 1>(d, std::forward<T>(init)));\n            else return init;\n        }\n\
    \n        template<class T, std::size_t idx = 0, std::size_t n>\n        auto\
    \ operator ()(const std::size_t (&d)[n], const T& init = T()) noexcept {\n   \
    \         if constexpr (idx < n) return std::vector(d[idx], operator ()<idx +\
    \ 1>(d, init));\n            else return init;\n        }\n    } make_vector;\n\
    } // namespace kyopro\n"
  code: "#pragma once\n#include <cstddef>\n#include <cstdint>\n#include <utility>\n\
    #include <vector>\n\nnamespace kyopro {\n    inline constexpr struct {\n     \
    \   template<std::size_t idx = 0, std::size_t n, class T>\n        auto operator\
    \ ()(const std::size_t (&d)[n], T&& init) noexcept {\n            if constexpr\
    \ (idx < n) return std::vector(d[idx], operator ()<idx + 1>(d, std::forward<T>(init)));\n\
    \            else return init;\n        }\n\n        template<class T, std::size_t\
    \ idx = 0, std::size_t n>\n        auto operator ()(const std::size_t (&d)[n],\
    \ const T& init = T()) noexcept {\n            if constexpr (idx < n) return std::vector(d[idx],\
    \ operator ()<idx + 1>(d, init));\n            else return init;\n        }\n\
    \    } make_vector;\n} // namespace kyopro"
  dependsOn: []
  isVerificationFile: false
  path: template/make_vector.hpp
  requiredBy:
  - template/all.hpp
  timestamp: '2022-08-08 07:54:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/make_vector.hpp
layout: document
redirect_from:
- /library/template/make_vector.hpp
- /library/template/make_vector.hpp.html
title: template/make_vector.hpp
---
