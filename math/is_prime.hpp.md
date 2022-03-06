---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/all.hpp
    title: math/all.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/is_prime.hpp\"\n#include <cstdint>\n\nnamespace kyopro\
    \ {\n  constexpr bool is_prime(std::uint_fast64_t _n) noexcept {\n    if (_n <\
    \ 2) return false;\n    if (_n < 4) return true;\n    if ((_n & 1) == 0 || _n\
    \ % 3 == 0) return false;\n    for (std::uint_fast64_t _i = 5; _i * _i <= _n;\
    \ _i += 4) {\n      if (_n % _i == 0) return false;\n      if (_n % (_i += 2)\
    \ == 0) return false;\n    }\n    return true;\n  }\n}\n"
  code: "#pragma once\n#include <cstdint>\n\nnamespace kyopro {\n  constexpr bool\
    \ is_prime(std::uint_fast64_t _n) noexcept {\n    if (_n < 2) return false;\n\
    \    if (_n < 4) return true;\n    if ((_n & 1) == 0 || _n % 3 == 0) return false;\n\
    \    for (std::uint_fast64_t _i = 5; _i * _i <= _n; _i += 4) {\n      if (_n %\
    \ _i == 0) return false;\n      if (_n % (_i += 2) == 0) return false;\n    }\n\
    \    return true;\n  }\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/is_prime.hpp
  requiredBy:
  - math/all.hpp
  timestamp: '2022-01-23 17:00:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/is_prime.hpp
layout: document
redirect_from:
- /library/math/is_prime.hpp
- /library/math/is_prime.hpp.html
title: math/is_prime.hpp
---
