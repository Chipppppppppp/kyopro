---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: kpr/algorithm/algorithm.hpp
    title: kpr/algorithm/algorithm.hpp
  - icon: ':warning:'
    path: kpr/all.hpp
    title: kpr/all.hpp
  - icon: ':warning:'
    path: kpr/all/all.hpp
    title: kpr/all/all.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"kpr/algorithm/next_combination.hpp\"\n#include <algorithm>\n\
    \nnamespace kpr {\n    // \u5148\u982Dk\u500B\u3092\u6B21\u306E\u7D44\u307F\u5408\
    \u308F\u305B\u306B\u3057\u3066\u3001\u6B21\u306E\u7D44\u307F\u5408\u308F\u305B\
    \u304C\u5B58\u5728\u3059\u308B\u304B\u3092\u8FD4\u3059\n    [[maybe_unused]] inline\
    \ constexpr struct {\n        template<class T>\n        bool operator ()(T first,\
    \ T last, int k) const {\n            T subset = first + k;\n            if (first\
    \ == last || first == subset || last == subset) return false;\n            T src\
    \ = subset;\n            while (first != src) {\n                --src;\n    \
    \            if (*src < *(last - 1)) {\n                    T dest = subset;\n\
    \                    while (*src >= *dest) ++dest;\n                    std::iter_swap(src,\
    \ dest);\n                    std::rotate(src + 1, dest + 1, last);\n        \
    \            std::rotate(subset, subset + (last - dest) - 1, last);\n        \
    \            return true;\n                }\n            }\n            std::rotate(first,\
    \ subset, last);\n            return false;\n        }\n    } next_combination;\n\
    } // namespace kpr\n"
  code: "#pragma once\n#include <algorithm>\n\nnamespace kpr {\n    // \u5148\u982D\
    k\u500B\u3092\u6B21\u306E\u7D44\u307F\u5408\u308F\u305B\u306B\u3057\u3066\u3001\
    \u6B21\u306E\u7D44\u307F\u5408\u308F\u305B\u304C\u5B58\u5728\u3059\u308B\u304B\
    \u3092\u8FD4\u3059\n    [[maybe_unused]] inline constexpr struct {\n        template<class\
    \ T>\n        bool operator ()(T first, T last, int k) const {\n            T\
    \ subset = first + k;\n            if (first == last || first == subset || last\
    \ == subset) return false;\n            T src = subset;\n            while (first\
    \ != src) {\n                --src;\n                if (*src < *(last - 1)) {\n\
    \                    T dest = subset;\n                    while (*src >= *dest)\
    \ ++dest;\n                    std::iter_swap(src, dest);\n                  \
    \  std::rotate(src + 1, dest + 1, last);\n                    std::rotate(subset,\
    \ subset + (last - dest) - 1, last);\n                    return true;\n     \
    \           }\n            }\n            std::rotate(first, subset, last);\n\
    \            return false;\n        }\n    } next_combination;\n} // namespace\
    \ kpr\n"
  dependsOn: []
  isVerificationFile: false
  path: kpr/algorithm/next_combination.hpp
  requiredBy:
  - kpr/all.hpp
  - kpr/all/all.hpp
  - kpr/algorithm/algorithm.hpp
  timestamp: '2023-04-22 22:30:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kpr/algorithm/next_combination.hpp
layout: document
redirect_from:
- /library/kpr/algorithm/next_combination.hpp
- /library/kpr/algorithm/next_combination.hpp.html
title: kpr/algorithm/next_combination.hpp
---
