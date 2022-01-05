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
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: yosupo/UnionFind.test.cpp
    title: yosupo/UnionFind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/UnionFind.hpp\"\n/* UnionFind */\n#include <vector>\n\
    #include <unordered_map>\n#include <algorithm>\n#include <initializer_list>\n\
    #line 1 \"base/settings.hpp\"\n#include <cstdint>\n#ifndef KYOPRO_BASE_INT\n#define\
    \ KYOPRO_BASE_INT std::int64_t\n#endif\n#ifndef KYOPRO_BASE_UINT\n#define KYOPRO_BASE_UINT\
    \ std::size_t\n#endif\n#ifndef KYOPRO_BASE_FLOAT\n#define KYOPRO_BASE_FLOAT double\n\
    #endif\n#ifndef KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD 1000000007\n#endif\n\
    #ifndef KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION 12\n#endif\n\
    #ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV 3\n#endif\n#line 8 \"structure/UnionFind.hpp\"\
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
    \      return kyopro_group_members;\n    }\n  };\n}\n"
  code: "#pragma once\n/* UnionFind */\n#include <vector>\n#include <unordered_map>\n\
    #include <algorithm>\n#include <initializer_list>\n#include \"../base/settings.hpp\"\
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
    \      return kyopro_group_members;\n    }\n  };\n}\n"
  dependsOn:
  - base/settings.hpp
  isVerificationFile: false
  path: structure/UnionFind.hpp
  requiredBy:
  - all.hpp
  timestamp: '2022-01-04 18:22:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - yosupo/UnionFind.test.cpp
documentation_of: structure/UnionFind.hpp
layout: document
redirect_from:
- /library/structure/UnionFind.hpp
- /library/structure/UnionFind.hpp.html
title: structure/UnionFind.hpp
---
