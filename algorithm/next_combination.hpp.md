---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: algorithm/algorithm.hpp
    title: algorithm/algorithm.hpp
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  - icon: ':warning:'
    path: all/all.hpp
    title: all/all.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algorithm/next_combination.hpp\"\n#include <algorithm>\n\
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
  path: algorithm/next_combination.hpp
  requiredBy:
  - all/all.hpp
  - all.hpp
  - algorithm/algorithm.hpp
  timestamp: '2023-03-29 00:32:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/next_combination.hpp
layout: document
redirect_from:
- /library/algorithm/next_combination.hpp
- /library/algorithm/next_combination.hpp.html
title: algorithm/next_combination.hpp
---
