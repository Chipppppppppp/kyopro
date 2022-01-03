---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base/base_int.hpp
    title: base/base_int.hpp
  - icon: ':x:'
    path: structure/FenwickTree.hpp
    title: structure/FenwickTree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"yosupo/FenwickTree.test.cpp\"\n#define problem \"https://judge.yosupo.jp/problem/point_add_range_sum\"\
    \n#include <iostream>\n#include <vector>\n#line 1 \"structure/FenwickTree.hpp\"\
    \n\n\n/* FenwickTree */\n#include <cstdint>\n#line 2 \"base/base_int.hpp\"\n#ifndef\
    \ KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT std::int64_t\n#endif\n#line 7 \"structure/FenwickTree.hpp\"\
    \n\nnamespace kyopro {\n  template<class T, class Container = std::vector<T>>\n\
    \  struct FenwickTree {\n  private:\n    Container kyopro_tree;\n  public:\n \
    \   using value_type = T;\n    using size_type = std::size_t;\n    using reference\
    \ = T&;\n    using const_reference = const T&;\n    FenwickTree() noexcept = default;\n\
    \    FenwickTree(std::size_t kyopro_n) noexcept: kyopro_tree(kyopro_n) {}\n  \
    \  std::size_t size() noexcept { return kyopro_tree.size(); }\n    void add(int\
    \ kyopro_p, const T& kyopro_x) {\n      ++kyopro_p;\n      while (kyopro_p <=\
    \ (int)size()) {\n        kyopro_tree[kyopro_p - 1] += kyopro_x;\n        kyopro_p\
    \ += kyopro_p & -kyopro_p;\n      }\n    }\n    T query(int kyopro_r) {\n    \
    \  T kyopro_s = 0;\n      while (kyopro_r > 0) {\n        kyopro_s += kyopro_tree[kyopro_r\
    \ - 1];\n        kyopro_r -= kyopro_r & -kyopro_r;\n      }\n      return kyopro_s;\n\
    \    }\n    T query(int kyopro_l, int kyopro_r) { return query(kyopro_r) - query(kyopro_l);\
    \ }\n    T all_query() { return query(kyopro_tree.size()); }\n  };\n}\n\n#line\
    \ 5 \"yosupo/FenwickTree.test.cpp\"\nusing ll = long long;\n\nint main() {\n \
    \ int n, q;\n  std::cin >> n >> q;\n  kyopro::FenwickTree<ll> ft;\n  for (int\
    \ i = 0; i < n; ++i) {\n    int a;\n    std::cin >> a;\n    ft.add(i, a);\n  }\n\
    \  for (int i = 0; i < q; ++i) {\n    int t, x, y;\n    std::cin >> t >> x >>\
    \ y;\n    if (t == 0) ft.add(x, y);\n    else std::cout << ft.query(x, y) << '\\\
    n';\n  }\n}\n"
  code: "#define problem \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include <iostream>\n#include <vector>\n#include \"../structure/FenwickTree.hpp\"\
    \nusing ll = long long;\n\nint main() {\n  int n, q;\n  std::cin >> n >> q;\n\
    \  kyopro::FenwickTree<ll> ft;\n  for (int i = 0; i < n; ++i) {\n    int a;\n\
    \    std::cin >> a;\n    ft.add(i, a);\n  }\n  for (int i = 0; i < q; ++i) {\n\
    \    int t, x, y;\n    std::cin >> t >> x >> y;\n    if (t == 0) ft.add(x, y);\n\
    \    else std::cout << ft.query(x, y) << '\\n';\n  }\n}\n"
  dependsOn:
  - structure/FenwickTree.hpp
  - base/base_int.hpp
  isVerificationFile: true
  path: yosupo/FenwickTree.test.cpp
  requiredBy: []
  timestamp: '2022-01-03 20:00:34+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: yosupo/FenwickTree.test.cpp
layout: document
redirect_from:
- /verify/yosupo/FenwickTree.test.cpp
- /verify/yosupo/FenwickTree.test.cpp.html
title: yosupo/FenwickTree.test.cpp
---
