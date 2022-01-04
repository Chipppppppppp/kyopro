---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base/settings.hpp
    title: base/settings.hpp
  - icon: ':heavy_check_mark:'
    path: structure/FenwickTree.hpp
    title: structure/FenwickTree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"yosupo/FenwickTree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\
    \n#include <iostream>\n#line 2 \"structure/FenwickTree.hpp\"\n/* FenwickTree */\n\
    #include <vector>\n#include <utility>\n#line 1 \"base/settings.hpp\"\n#include\
    \ <cstdint>\n#ifndef KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT std::int64_t\n#endif\n\
    #ifndef KYOPRO_BASE_UINT\n#define KYOPRO_BASE_UINT std::size_t\n#endif\n#ifndef\
    \ KYOPRO_BASE_FLOAT\n#define KYOPRO_BASE_FLOAT double\n#endif\n#ifndef KYOPRO_DEFAULT_MOD\n\
    #define KYOPRO_DEFAULT_MOD 1000000007\n#endif\n#ifndef KYOPRO_DECIMAL_PRECISION\n\
    #define KYOPRO_DECIMAL_PRECISION 12\n#endif\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV\
    \ 3\n#endif\n#line 6 \"structure/FenwickTree.hpp\"\n\nnamespace kyopro {\n  template<class\
    \ KyoproT, class KyoproContainer = std::vector<KyoproT>>\n  struct FenwickTree\
    \ {\n  private:\n    KyoproContainer kyopro_tree;\n  public:\n    using value_type\
    \ = KyoproT;\n    using size_type = KYOPRO_BASE_UINT;\n    using reference = KyoproT&;\n\
    \    using const_reference = const KyoproT&;\n    FenwickTree() noexcept = default;\n\
    \    FenwickTree(KYOPRO_BASE_UINT kyopro_n) noexcept: kyopro_tree(kyopro_n) {}\n\
    \    KYOPRO_BASE_UINT size() noexcept { return kyopro_tree.size(); }\n    void\
    \ add(int kyopro_p, const KyoproT& kyopro_x) {\n      ++kyopro_p;\n      while\
    \ (kyopro_p <= (int)size()) {\n        kyopro_tree[kyopro_p - 1] += kyopro_x;\n\
    \        kyopro_p += kyopro_p & -kyopro_p;\n      }\n    }\n    void set(int kyopro_p,\
    \ const KyoproT& kyopro_x) { add(kyopro_p, kyopro_x - get(kyopro_p)); }\n    KyoproT\
    \ query(int kyopro_r) {\n      KyoproT kyopro_s = 0;\n      while (kyopro_r >\
    \ 0) {\n        kyopro_s += kyopro_tree[kyopro_r - 1];\n        kyopro_r -= kyopro_r\
    \ & -kyopro_r;\n      }\n      return kyopro_s;\n    }\n    KyoproT query(int\
    \ kyopro_l, int kyopro_r) { return query(kyopro_r) - query(kyopro_l); }\n    KyoproT\
    \ get(int kyopro_p) { return query(kyopro_p + 1) - query(kyopro_p); }\n    KyoproT\
    \ all_query() { return query(kyopro_tree.size()); }\n  };\n}\n#line 4 \"yosupo/FenwickTree.test.cpp\"\
    \nusing ll = long long;\n\nint main() {\n  int n, q;\n  std::cin >> n >> q;\n\
    \  kyopro::FenwickTree<ll> ft(n);\n  for (int i = 0; i < n; ++i) {\n    int a;\n\
    \    std::cin >> a;\n    ft.add(i, a);\n  }\n  for (int i = 0; i < q; ++i) {\n\
    \    int t, x, y;\n    std::cin >> t >> x >> y;\n    if (t == 0) ft.add(x, y);\n\
    \    else std::cout << ft.query(x, y) << '\\n';\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include <iostream>\n#include \"../structure/FenwickTree.hpp\"\nusing ll = long\
    \ long;\n\nint main() {\n  int n, q;\n  std::cin >> n >> q;\n  kyopro::FenwickTree<ll>\
    \ ft(n);\n  for (int i = 0; i < n; ++i) {\n    int a;\n    std::cin >> a;\n  \
    \  ft.add(i, a);\n  }\n  for (int i = 0; i < q; ++i) {\n    int t, x, y;\n   \
    \ std::cin >> t >> x >> y;\n    if (t == 0) ft.add(x, y);\n    else std::cout\
    \ << ft.query(x, y) << '\\n';\n  }\n}\n"
  dependsOn:
  - structure/FenwickTree.hpp
  - base/settings.hpp
  isVerificationFile: true
  path: yosupo/FenwickTree.test.cpp
  requiredBy: []
  timestamp: '2022-01-04 18:22:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: yosupo/FenwickTree.test.cpp
layout: document
redirect_from:
- /verify/yosupo/FenwickTree.test.cpp
- /verify/yosupo/FenwickTree.test.cpp.html
title: yosupo/FenwickTree.test.cpp
---
