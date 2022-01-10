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
  bundledCode: "#line 2 \"math/euler_phi.hpp\"\n#include <cstdint>\n\nnamespace kyopro\
    \ {\n  constexpr std::uint64_t euler_phi(std::uint64_t kyopro_n) noexcept {\n\
    \    std::uint64_t kyopro_res = kyopro_n;\n    if ((kyopro_n & 1) == 0) {\n  \
    \    kyopro_res -= kyopro_res >> 1;\n      kyopro_n >>= 1;\n      while ((kyopro_n\
    \ & 1) == 0) kyopro_n >>= 1;\n    }\n    for (std::uint64_t kyopro_i = 3; kyopro_i\
    \ * kyopro_i <= kyopro_n; kyopro_i += 2) {\n      if (kyopro_n % kyopro_i == 0)\
    \ {\n        kyopro_res -= kyopro_res / kyopro_i;\n        kyopro_n /= kyopro_i;\n\
    \        while (kyopro_n % kyopro_i == 0) kyopro_n /= kyopro_i;\n      }\n   \
    \ }\n    if (kyopro_n != 1) kyopro_res -= kyopro_res / kyopro_n;\n    return kyopro_res;\n\
    \  }\n}\n"
  code: "#pragma once\n#include <cstdint>\n\nnamespace kyopro {\n  constexpr std::uint64_t\
    \ euler_phi(std::uint64_t kyopro_n) noexcept {\n    std::uint64_t kyopro_res =\
    \ kyopro_n;\n    if ((kyopro_n & 1) == 0) {\n      kyopro_res -= kyopro_res >>\
    \ 1;\n      kyopro_n >>= 1;\n      while ((kyopro_n & 1) == 0) kyopro_n >>= 1;\n\
    \    }\n    for (std::uint64_t kyopro_i = 3; kyopro_i * kyopro_i <= kyopro_n;\
    \ kyopro_i += 2) {\n      if (kyopro_n % kyopro_i == 0) {\n        kyopro_res\
    \ -= kyopro_res / kyopro_i;\n        kyopro_n /= kyopro_i;\n        while (kyopro_n\
    \ % kyopro_i == 0) kyopro_n /= kyopro_i;\n      }\n    }\n    if (kyopro_n !=\
    \ 1) kyopro_res -= kyopro_res / kyopro_n;\n    return kyopro_res;\n  }\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/euler_phi.hpp
  requiredBy: []
  timestamp: '2022-01-10 19:46:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/euler_phi.hpp
layout: document
redirect_from:
- /library/math/euler_phi.hpp
- /library/math/euler_phi.hpp.html
title: math/euler_phi.hpp
---
