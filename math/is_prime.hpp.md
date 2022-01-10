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
  bundledCode: "#line 2 \"math/is_prime.hpp\"\n#include <cstdint>\n\nnamespace kyopro\
    \ {\n  constexpr bool is_prime(std::uint64_t kyopro_n) noexcept {\n    if (kyopro_n\
    \ < 2) return false;\n    if (kyopro_n < 4) return true;\n    if ((kyopro_n &\
    \ 1) == 0 || kyopro_n % 3 == 0) return false;\n    for (std::uint64_t kyopro_i\
    \ = 5; kyopro_i * kyopro_i <= kyopro_n; kyopro_i += 4) {\n      if (kyopro_n %\
    \ kyopro_i == 0) return false;\n      if (kyopro_n % (kyopro_i += 2) == 0) return\
    \ false;\n    }\n    return true;\n  }\n}\n"
  code: "#pragma once\n#include <cstdint>\n\nnamespace kyopro {\n  constexpr bool\
    \ is_prime(std::uint64_t kyopro_n) noexcept {\n    if (kyopro_n < 2) return false;\n\
    \    if (kyopro_n < 4) return true;\n    if ((kyopro_n & 1) == 0 || kyopro_n %\
    \ 3 == 0) return false;\n    for (std::uint64_t kyopro_i = 5; kyopro_i * kyopro_i\
    \ <= kyopro_n; kyopro_i += 4) {\n      if (kyopro_n % kyopro_i == 0) return false;\n\
    \      if (kyopro_n % (kyopro_i += 2) == 0) return false;\n    }\n    return true;\n\
    \  }\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/is_prime.hpp
  requiredBy: []
  timestamp: '2022-01-10 19:46:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/is_prime.hpp
layout: document
redirect_from:
- /library/math/is_prime.hpp
- /library/math/is_prime.hpp.html
title: math/is_prime.hpp
---
