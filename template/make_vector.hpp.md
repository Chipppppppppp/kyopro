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
  bundledCode: "#line 2 \"template/make_vector.hpp\"\n#include <cstddef>\n#include\
    \ <cstdint>\n#include <utility>\n#include <vector>\n\nnamespace kpr {\n    [[maybe_unused]]\
    \ inline constexpr struct {\n        template<std::size_t idx = 0, std::size_t\
    \ n, class T>\n        auto operator ()(const std::size_t (&d)[n], T&& init) noexcept\
    \ {\n            if constexpr (idx < n) return std::vector(d[idx], operator ()<idx\
    \ + 1>(d, std::forward<T>(init)));\n            else return init;\n        }\n\
    \n        template<class T, std::size_t idx = 0, std::size_t n>\n        auto\
    \ operator ()(const std::size_t (&d)[n], const T& init = {}) noexcept {\n    \
    \        if constexpr (idx < n) return std::vector(d[idx], operator ()<idx + 1>(d,\
    \ init));\n            else return init;\n        }\n    } make_vector;\n} //\
    \ namespace kpr\n"
  code: "#pragma once\n#include <cstddef>\n#include <cstdint>\n#include <utility>\n\
    #include <vector>\n\nnamespace kpr {\n    [[maybe_unused]] inline constexpr struct\
    \ {\n        template<std::size_t idx = 0, std::size_t n, class T>\n        auto\
    \ operator ()(const std::size_t (&d)[n], T&& init) noexcept {\n            if\
    \ constexpr (idx < n) return std::vector(d[idx], operator ()<idx + 1>(d, std::forward<T>(init)));\n\
    \            else return init;\n        }\n\n        template<class T, std::size_t\
    \ idx = 0, std::size_t n>\n        auto operator ()(const std::size_t (&d)[n],\
    \ const T& init = {}) noexcept {\n            if constexpr (idx < n) return std::vector(d[idx],\
    \ operator ()<idx + 1>(d, init));\n            else return init;\n        }\n\
    \    } make_vector;\n} // namespace kpr\n"
  dependsOn: []
  isVerificationFile: false
  path: template/make_vector.hpp
  requiredBy:
  - template/template.hpp
  - all.hpp
  timestamp: '2023-02-01 00:00:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/make_vector.hpp
layout: document
redirect_from:
- /library/template/make_vector.hpp
- /library/template/make_vector.hpp.html
title: template/make_vector.hpp
---
