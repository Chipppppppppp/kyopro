---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base/settings.hpp
    title: base/settings.hpp
  - icon: ':x:'
    path: math/factorize.hpp
    title: math/factorize.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/factorize
    links:
    - https://judge.yosupo.jp/problem/factorize
  bundledCode: "#line 1 \"yosupo/factorize.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\
    \n#include <iostream>\n#line 2 \"math/factorize.hpp\"\n#include <cstdint>\n#include\
    \ <vector>\n#include <utility>\n#line 3 \"base/settings.hpp\"\n\n#ifndef KYOPRO_BASE_INT\n\
    #define KYOPRO_BASE_INT std::int64_t\n#endif\n#ifndef KYOPRO_BASE_UINT\n#define\
    \ KYOPRO_BASE_UINT std::size_t\n#endif\n#ifndef KYOPRO_BASE_FLOAT\n#define KYOPRO_BASE_FLOAT\
    \ double\n#endif\n#ifndef KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD 1000000007\n\
    #endif\n#ifndef KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION 12\n\
    #endif\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV 3\n#endif\n#line 6 \"math/factorize.hpp\"\
    \n\nnamespace kyopro {\n  template<class KyoproContainer = std::vector<KYOPRO_BASE_INT>>\n\
    \  KyoproContainer factorize(std::uint64_t kyopro_n) {\n    KyoproContainer kyopro_res;\n\
    \    while ((kyopro_n & 1) == 0) {\n      kyopro_res.emplace_back(2);\n      kyopro_n\
    \ >>= 1;\n    }\n    for (std::uint64_t kyopro_i = 3; kyopro_i * kyopro_i <= kyopro_n;\
    \ kyopro_i += 2) while (kyopro_n % kyopro_i == 0) {\n      kyopro_res.emplace_back(2);\n\
    \      kyopro_n /= kyopro_i;\n    }\n    if (kyopro_n != 1) kyopro_res.emplace_back(kyopro_n);\n\
    \    return kyopro_res;\n  }\n}\n#line 4 \"yosupo/factorize.test.cpp\"\n\nint\
    \ main() {\n  int q;\n  std::cin >> q;\n  for (int i = 0; i < q; ++i) {\n    long\
    \ long a;\n    std::cin >> a;\n    auto primes = kyopro::factorize(a);\n    std::cout\
    \ << primes.size();\n    for (auto i: primes) std::cout << ' ' << i;\n    std::cout\
    \ << '\\n';\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\n#include <iostream>\n\
    #include \"../math/factorize.hpp\"\n\nint main() {\n  int q;\n  std::cin >> q;\n\
    \  for (int i = 0; i < q; ++i) {\n    long long a;\n    std::cin >> a;\n    auto\
    \ primes = kyopro::factorize(a);\n    std::cout << primes.size();\n    for (auto\
    \ i: primes) std::cout << ' ' << i;\n    std::cout << '\\n';\n  }\n}"
  dependsOn:
  - math/factorize.hpp
  - base/settings.hpp
  isVerificationFile: true
  path: yosupo/factorize.test.cpp
  requiredBy: []
  timestamp: '2022-01-10 23:35:20+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: yosupo/factorize.test.cpp
layout: document
redirect_from:
- /verify/yosupo/factorize.test.cpp
- /verify/yosupo/factorize.test.cpp.html
title: yosupo/factorize.test.cpp
---
