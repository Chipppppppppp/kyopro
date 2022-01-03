---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base/base_int.hpp
    title: base/base_int.hpp
  - icon: ':heavy_check_mark:'
    path: structure/UnionFind.hpp
    title: structure/UnionFind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"yosupo/UnionFind.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n#include <iostream>\n#line 1 \"structure/UnionFind.hpp\"\n\n\n/* UnionFind */\n\
    #include <vector>\n#include <unordered_map>\n#include <algorithm>\n#include <initializer_list>\n\
    #include <cstdint>\n#line 2 \"base/base_int.hpp\"\n#ifndef KYOPRO_BASE_INT\n#define\
    \ KYOPRO_BASE_INT std::int64_t\n#endif\n#line 10 \"structure/UnionFind.hpp\"\n\
    \nnamespace kyopro {\n  template<class KyoproContainer = std::vector<int>>\n \
    \ struct UnionFind {\n  private:\n    KyoproContainer kyopro_par;\n  public:\n\
    \    UnionFind() noexcept = default;\n    UnionFind(std::size_t kyopro_n) noexcept:\
    \ kyopro_par(kyopro_n, -1) {}\n    void resize(std::size_t kyopro_x) { kyopro_par.resize(kyopro_x,\
    \ -1); }\n    void assign(std::size_t kyopro_x) { kyopro_par.assign(kyopro_x,\
    \ -1); }\n    void reset() { std::fill(std::begin(kyopro_par), std::end(kyopro_par),\
    \ -1); }\n    std::size_t size() const noexcept { return kyopro_par.size(); }\n\
    \    KYOPRO_BASE_INT find(int kyopro_x) {\n      int kyopro_p = kyopro_x;\n  \
    \    while (kyopro_par[kyopro_p] >= 0) kyopro_p = kyopro_par[kyopro_p];\n    \
    \  while (kyopro_x != kyopro_p) {\n        int kyopro_tmp = kyopro_x;\n      \
    \  kyopro_x = kyopro_par[kyopro_x];\n        kyopro_par[kyopro_tmp] = kyopro_p;\n\
    \      }\n      return kyopro_p;\n    }\n    bool unite(int kyopro_x, int kyopro_y)\
    \ {\n      kyopro_x = find(kyopro_x), kyopro_y = find(kyopro_y);\n      if (kyopro_x\
    \ == kyopro_y) return false;\n      if (kyopro_par[kyopro_x] > kyopro_par[kyopro_y])\
    \ {\n        int kyopro_tmp = kyopro_x;\n        kyopro_x = kyopro_y;\n      \
    \  kyopro_y = kyopro_tmp;\n      }\n      kyopro_par[kyopro_x] += kyopro_par[kyopro_y];\n\
    \      kyopro_par[kyopro_y] = kyopro_x;\n      return true;\n    }\n    bool same(int\
    \ kyopro_x, int kyopro_y) { return find(kyopro_x) == find(kyopro_y); }\n    KYOPRO_BASE_INT\
    \ group_size(int kyopro_x) { return -kyopro_par[find(kyopro_x)]; }\n    KyoproContainer\
    \ group_members(int kyopro_x) {\n      int root = find(kyopro_x);\n      KyoproContainer\
    \ kyopro_a;\n      for (int kyopro_i = 0; kyopro_i < (int)(size()); ++kyopro_i)\
    \ if (find(kyopro_i) == root) kyopro_a.emplace_back(kyopro_i);\n      return kyopro_a;\n\
    \    }\n    std::vector<KYOPRO_BASE_INT> roots() const {\n      std::vector<KYOPRO_BASE_INT>\
    \ kyopro_a;\n      for (int kyopro_i = 0; kyopro_i < (int)(size()); ++kyopro_i)\
    \ if (kyopro_par[kyopro_i] < 0) kyopro_a.emplace_back(kyopro_i);\n      return\
    \ kyopro_a;\n    }\n    KYOPRO_BASE_INT group_count() const {\n      KYOPRO_BASE_INT\
    \ cnt = 0;\n      for (int kyopro_i = 0; kyopro_i < (int)(size()); ++kyopro_i)\
    \ if (kyopro_par[kyopro_i] < 0) ++cnt;\n      return cnt;\n    }\n    template<class\
    \ Container = std::unordered_map<KYOPRO_BASE_INT, std::vector<KYOPRO_BASE_INT>>>\n\
    \    Container all_group_members() {\n      Container group_members;\n      for\
    \ (int member = 0; member < (int)(size()); ++member) group_members[find(member)].emplace_back(member);\n\
    \      return group_members;\n    }\n  };\n}\n\n#line 4 \"yosupo/UnionFind.test.cpp\"\
    \n\nint main() {\n  int n, q;\n  std::cin >> n >> q;\n  kyopro::UnionFind uf(n);\n\
    \  for (int i = 0; i < q; ++i) {\n    int t, u, v;\n    std::cin >> t >> u >>\
    \ v;\n    if (t == 0) uf.unite(u, v);\n    else std::cout << uf.same(u, v) <<\
    \ '\\n';\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#include <iostream>\n\
    #include \"../structure/UnionFind.hpp\"\n\nint main() {\n  int n, q;\n  std::cin\
    \ >> n >> q;\n  kyopro::UnionFind uf(n);\n  for (int i = 0; i < q; ++i) {\n  \
    \  int t, u, v;\n    std::cin >> t >> u >> v;\n    if (t == 0) uf.unite(u, v);\n\
    \    else std::cout << uf.same(u, v) << '\\n';\n  }\n}\n"
  dependsOn:
  - structure/UnionFind.hpp
  - base/base_int.hpp
  isVerificationFile: true
  path: yosupo/UnionFind.test.cpp
  requiredBy: []
  timestamp: '2022-01-03 19:59:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: yosupo/UnionFind.test.cpp
layout: document
redirect_from:
- /verify/yosupo/UnionFind.test.cpp
- /verify/yosupo/UnionFind.test.cpp.html
title: yosupo/UnionFind.test.cpp
---