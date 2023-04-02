---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: kyopro/algorithm/algorithm.hpp
    title: kyopro/algorithm/algorithm.hpp
  - icon: ':warning:'
    path: kyopro/all/all.hpp
    title: kyopro/all/all.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"kyopro/algorithm/next_combination.hpp\"\n#include <algorithm>\n\
    \nnamespace kpr {\n    [[maybe_unused]] inline constexpr struct {\n        template<class\
    \ T>\n        bool operator ()(T first, T last, int k) {\n            T subset\
    \ = first + k;\n            if (first == last || first == subset || last == subset)\
    \ return false;\n            T src = subset;\n            while (first != src)\
    \ {\n                --src;\n                if (*src < *(last - 1)) {\n     \
    \               T dest = subset;\n                    while (*src >= *dest) ++dest;\n\
    \                    std::iter_swap(src, dest);\n                    std::rotate(src\
    \ + 1, dest + 1, last);\n                    std::rotate(subset, subset + (last\
    \ - dest) - 1, last);\n                    return true;\n                }\n \
    \           }\n            std::rotate(first, subset, last);\n            return\
    \ false;\n        }\n    } next_combination;\n} // namespace kpr\n"
  code: "#pragma once\n#include <algorithm>\n\nnamespace kpr {\n    [[maybe_unused]]\
    \ inline constexpr struct {\n        template<class T>\n        bool operator\
    \ ()(T first, T last, int k) {\n            T subset = first + k;\n          \
    \  if (first == last || first == subset || last == subset) return false;\n   \
    \         T src = subset;\n            while (first != src) {\n              \
    \  --src;\n                if (*src < *(last - 1)) {\n                    T dest\
    \ = subset;\n                    while (*src >= *dest) ++dest;\n             \
    \       std::iter_swap(src, dest);\n                    std::rotate(src + 1, dest\
    \ + 1, last);\n                    std::rotate(subset, subset + (last - dest)\
    \ - 1, last);\n                    return true;\n                }\n         \
    \   }\n            std::rotate(first, subset, last);\n            return false;\n\
    \        }\n    } next_combination;\n} // namespace kpr\n"
  dependsOn: []
  isVerificationFile: false
  path: kyopro/algorithm/next_combination.hpp
  requiredBy:
  - kyopro/all/all.hpp
  - kyopro/algorithm/algorithm.hpp
  timestamp: '2023-04-02 21:40:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kyopro/algorithm/next_combination.hpp
layout: document
redirect_from:
- /library/kyopro/algorithm/next_combination.hpp
- /library/kyopro/algorithm/next_combination.hpp.html
title: kyopro/algorithm/next_combination.hpp
---
