---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base/settings.hpp
    title: base/settings.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  - icon: ':warning:'
    path: math/all.hpp
    title: math/all.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/divisors.hpp\"\n#include <cstdint>\n#include <vector>\n\
    #line 3 \"base/settings.hpp\"\n#ifndef KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT\
    \ std::int64_t\n#endif\n#ifndef KYOPRO_BASE_UINT\n#define KYOPRO_BASE_UINT std::size_t\n\
    #endif\n#ifndef KYOPRO_BASE_FLOAT\n#define KYOPRO_BASE_FLOAT double\n#endif\n\
    #ifndef KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD 1000000007\n#endif\n#ifndef\
    \ KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION 12\n#endif\n#ifndef\
    \ KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV 3\n#endif\n#line 5 \"math/divisors.hpp\"\
    \n\nnamespace kyopro {\n  template<class KyoproContainer = std::vector<KYOPRO_BASE_INT>>\n\
    \  KyoproContainer divisors(std::uint64_t kyopro_n) {\n    KyoproContainer kyopro_lower,\
    \ kyopro_upper;\n    std::uint64_t kyopro_i;\n    for (kyopro_i = 1; kyopro_i\
    \ * kyopro_i < kyopro_n; ++kyopro_i) if (kyopro_n % kyopro_i == 0) {\n      kyopro_lower.emplace_back(kyopro_i);\n\
    \      kyopro_upper.emplace_back(kyopro_n / kyopro_i);\n    }\n    if (kyopro_i\
    \ * kyopro_i == kyopro_n) kyopro_lower.emplace_back(kyopro_i);\n    kyopro_lower.insert(end(kyopro_lower),\
    \ rall(kyopro_upper));\n    return kyopro_lower;\n  }\n}\n"
  code: "#pragma once\n#include <cstdint>\n#include <vector>\n#include \"../base/settings.hpp\"\
    \n\nnamespace kyopro {\n  template<class KyoproContainer = std::vector<KYOPRO_BASE_INT>>\n\
    \  KyoproContainer divisors(std::uint64_t kyopro_n) {\n    KyoproContainer kyopro_lower,\
    \ kyopro_upper;\n    std::uint64_t kyopro_i;\n    for (kyopro_i = 1; kyopro_i\
    \ * kyopro_i < kyopro_n; ++kyopro_i) if (kyopro_n % kyopro_i == 0) {\n      kyopro_lower.emplace_back(kyopro_i);\n\
    \      kyopro_upper.emplace_back(kyopro_n / kyopro_i);\n    }\n    if (kyopro_i\
    \ * kyopro_i == kyopro_n) kyopro_lower.emplace_back(kyopro_i);\n    kyopro_lower.insert(end(kyopro_lower),\
    \ rall(kyopro_upper));\n    return kyopro_lower;\n  }\n}"
  dependsOn:
  - base/settings.hpp
  isVerificationFile: false
  path: math/divisors.hpp
  requiredBy:
  - math/all.hpp
  - all.hpp
  timestamp: '2022-01-10 19:46:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/divisors.hpp
layout: document
redirect_from:
- /library/math/divisors.hpp
- /library/math/divisors.hpp.html
title: math/divisors.hpp
---
