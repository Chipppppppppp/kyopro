---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base/settings.hpp
    title: base/settings.hpp
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
    \n#include <iostream>\n#line 2 \"structure/UnionFind.hpp\"\n/* UnionFind */\n\
    #include <vector>\n#include <unordered_map>\n#include <algorithm>\n#line 2 \"\
    base/settings.hpp\"\n#include <cstdint>\n\n#ifndef KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT\
    \ std::int64_t\n#endif\n#ifndef KYOPRO_BASE_UINT\n#define KYOPRO_BASE_UINT std::size_t\n\
    #endif\n#ifndef KYOPRO_BASE_FLOAT\n#define KYOPRO_BASE_FLOAT double\n#endif\n\
    #ifndef KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD 1000000007\n#endif\n#ifndef\
    \ KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION 12\n#endif\n#ifndef\
    \ KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV 3\n#endif\n#line 7 \"structure/UnionFind.hpp\"\
    \n\nnamespace kyopro {\n  template<class KyoproContainer = std::vector<int>>\n\
    \  struct UnionFind {\n  private:\n    KyoproContainer kyopro_par;\n  public:\n\
    \    UnionFind() noexcept = default;\n    UnionFind(KYOPRO_BASE_UINT kyopro_n)\
    \ noexcept: kyopro_par(kyopro_n, -1) {}\n    void resize(KYOPRO_BASE_UINT kyopro_x)\
    \ { kyopro_par.resize(kyopro_x, -1); }\n    void assign(KYOPRO_BASE_UINT kyopro_x)\
    \ { kyopro_par.assign(kyopro_x, -1); }\n    void reset() { std::fill(std::begin(kyopro_par),\
    \ std::end(kyopro_par), -1); }\n    KYOPRO_BASE_UINT size() const noexcept { return\
    \ kyopro_par.size(); }\n    KYOPRO_BASE_INT find(int kyopro_x) {\n      int kyopro_p\
    \ = kyopro_x;\n      while (kyopro_par[kyopro_p] >= 0) kyopro_p = kyopro_par[kyopro_p];\n\
    \      while (kyopro_x != kyopro_p) {\n        int kyopro_tmp = kyopro_x;\n  \
    \      kyopro_x = kyopro_par[kyopro_x];\n        kyopro_par[kyopro_tmp] = kyopro_p;\n\
    \      }\n      return kyopro_p;\n    }\n    bool unite(int kyopro_x, int kyopro_y)\
    \ {\n      kyopro_x = find(kyopro_x), kyopro_y = find(kyopro_y);\n      if (kyopro_x\
    \ == kyopro_y) return false;\n      if (kyopro_par[kyopro_x] > kyopro_par[kyopro_y])\
    \ {\n        int kyopro_tmp = kyopro_x;\n        kyopro_x = kyopro_y;\n      \
    \  kyopro_y = kyopro_tmp;\n      }\n      kyopro_par[kyopro_x] += kyopro_par[kyopro_y];\n\
    \      kyopro_par[kyopro_y] = kyopro_x;\n      return true;\n    }\n    bool same(int\
    \ kyopro_x, int kyopro_y) { return find(kyopro_x) == find(kyopro_y); }\n    KYOPRO_BASE_INT\
    \ group_size(int kyopro_x) { return -kyopro_par[find(kyopro_x)]; }\n    KyoproContainer\
    \ group_members(int kyopro_x) {\n      kyopro_x = find(kyopro_x);\n      KyoproContainer\
    \ kyopro_a;\n      for (int kyopro_i = 0; kyopro_i < (int)(size()); ++kyopro_i)\
    \ if (find(kyopro_i) == kyopro_x) kyopro_a.emplace_back(kyopro_i);\n      return\
    \ kyopro_a;\n    }\n    template<class KyoproVector = std::vector<KYOPRO_BASE_INT>>\n\
    \    KyoproVector roots() const {\n      KyoproVector kyopro_a;\n      for (int\
    \ kyopro_i = 0; kyopro_i < (int)(size()); ++kyopro_i) if (kyopro_par[kyopro_i]\
    \ < 0) kyopro_a.emplace_back(kyopro_i);\n      return kyopro_a;\n    }\n    KYOPRO_BASE_INT\
    \ group_count() const {\n      KYOPRO_BASE_INT kyopro_cnt = 0;\n      for (int\
    \ kyopro_i = 0; kyopro_i < (int)(size()); ++kyopro_i) if (kyopro_par[kyopro_i]\
    \ < 0) ++kyopro_cnt;\n      return kyopro_cnt;\n    }\n    template<class KyoproMap\
    \ = std::unordered_map<KYOPRO_BASE_INT, std::vector<KYOPRO_BASE_INT>>>\n    KyoproMap\
    \ all_group_members() {\n      KyoproMap kyopro_group_members;\n      for (int\
    \ kyopro_member = 0; kyopro_member < (int)(size()); ++kyopro_member) kyopro_group_members[find(kyopro_member)].emplace_back(kyopro_member);\n\
    \      return kyopro_group_members;\n    }\n  };\n}\n#line 4 \"yosupo/UnionFind.test.cpp\"\
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
  - base/settings.hpp
  isVerificationFile: true
  path: yosupo/UnionFind.test.cpp
  requiredBy: []
  timestamp: '2022-01-10 20:12:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: yosupo/UnionFind.test.cpp
layout: document
redirect_from:
- /verify/yosupo/UnionFind.test.cpp
- /verify/yosupo/UnionFind.test.cpp.html
title: yosupo/UnionFind.test.cpp
---