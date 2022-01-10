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
  bundledCode: "#line 2 \"math/factorize.hpp\"\n#include <cstdint>\n#include <vector>\n\
    #include <utility>\n#line 3 \"base/settings.hpp\"\n#ifndef KYOPRO_BASE_INT\n#define\
    \ KYOPRO_BASE_INT std::int64_t\n#endif\n#ifndef KYOPRO_BASE_UINT\n#define KYOPRO_BASE_UINT\
    \ std::size_t\n#endif\n#ifndef KYOPRO_BASE_FLOAT\n#define KYOPRO_BASE_FLOAT double\n\
    #endif\n#ifndef KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD 1000000007\n#endif\n\
    #ifndef KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION 12\n#endif\n\
    #ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV 3\n#endif\n#line 6 \"math/factorize.hpp\"\
    \n\nnamespace kyopro {\n  template<class KyoproContainer = std::vector<std::pair<KYOPRO_BASE_INT,\
    \ KYOPRO_BASE_INT>>>\n  KyoproContainer factorize(size_t kyopro_n) {\n    KyoproContainer\
    \ kyopro_res;\n    if ((kyopro_n & 1) == 0) {\n      kyopro_res.emplace_back(2,\
    \ 1);\n      kyopro_n >>= 1;\n      while ((kyopro_n & 1) == 0) {\n        ++kyopro_res.back().second;\n\
    \        kyopro_n >>= 1;\n      }\n    }\n    for (size_t kyopro_i = 3; kyopro_i\
    \ * kyopro_i <= kyopro_n; kyopro_i += 2) if (kyopro_n % kyopro_i == 0) {\n   \
    \   kyopro_res.emplace_back(2, 1);\n      kyopro_n /= kyopro_i;\n      while (kyopro_n\
    \ % kyopro_i == 0) {\n        ++kyopro_res.back().second;\n        kyopro_n /=\
    \ kyopro_i;\n      }\n    }\n    if (kyopro_n != 1) kyopro_res.emplace_back(kyopro_n,\
    \ 1);\n    return kyopro_res;\n  }\n}\n"
  code: "#pragma once\n#include <cstdint>\n#include <vector>\n#include <utility>\n\
    #include \"../base/settings.hpp\"\n\nnamespace kyopro {\n  template<class KyoproContainer\
    \ = std::vector<std::pair<KYOPRO_BASE_INT, KYOPRO_BASE_INT>>>\n  KyoproContainer\
    \ factorize(size_t kyopro_n) {\n    KyoproContainer kyopro_res;\n    if ((kyopro_n\
    \ & 1) == 0) {\n      kyopro_res.emplace_back(2, 1);\n      kyopro_n >>= 1;\n\
    \      while ((kyopro_n & 1) == 0) {\n        ++kyopro_res.back().second;\n  \
    \      kyopro_n >>= 1;\n      }\n    }\n    for (size_t kyopro_i = 3; kyopro_i\
    \ * kyopro_i <= kyopro_n; kyopro_i += 2) if (kyopro_n % kyopro_i == 0) {\n   \
    \   kyopro_res.emplace_back(2, 1);\n      kyopro_n /= kyopro_i;\n      while (kyopro_n\
    \ % kyopro_i == 0) {\n        ++kyopro_res.back().second;\n        kyopro_n /=\
    \ kyopro_i;\n      }\n    }\n    if (kyopro_n != 1) kyopro_res.emplace_back(kyopro_n,\
    \ 1);\n    return kyopro_res;\n  }\n}"
  dependsOn:
  - base/settings.hpp
  isVerificationFile: false
  path: math/factorize.hpp
  requiredBy:
  - math/all.hpp
  - all.hpp
  timestamp: '2022-01-10 19:46:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/factorize.hpp
layout: document
redirect_from:
- /library/math/factorize.hpp
- /library/math/factorize.hpp.html
title: math/factorize.hpp
---
