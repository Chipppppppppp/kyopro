---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: meta/settings.hpp
    title: meta/settings.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all/all.hpp
    title: all/all.hpp
  - icon: ':warning:'
    path: structure/all.hpp
    title: structure/all.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: yosupo/UnionFind.test.cpp
    title: yosupo/UnionFind.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/UnionFind.hpp\"\n#include <algorithm>\n#include\
    \ <type_traits>\n#include <unordered_map>\n#include <utility>\n#include <vector>\n\
    #line 2 \"meta/settings.hpp\"\n#include <cstdint>\n\n#ifndef KYOPRO_BASE_INT\n\
    #define KYOPRO_BASE_INT std::int64_t\n#endif\n\n#ifndef KYOPRO_BASE_UINT\n#define\
    \ KYOPRO_BASE_UINT std::uint64_t\n#endif\n\n#ifndef KYOPRO_BASE_FLOAT\n#define\
    \ KYOPRO_BASE_FLOAT double\n#endif\n\n#ifndef KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD\
    \ static_cast<KYOPRO_BASE_UINT>(998244353)\n#endif\n\n#ifndef KYOPRO_DECIMAL_PRECISION\n\
    #define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n#endif\n\n\
    #ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 8 \"structure/UnionFind.hpp\"\n\nnamespace kyopro {\n  template<class\
    \ Container = std::vector<int>>\n  struct UnionFind {\n  private:\n    Container\
    \ par;\n\n  public:\n    UnionFind() noexcept = default;\n    UnionFind(KYOPRO_BASE_UINT\
    \ n) noexcept: par(n, -1) {}\n    template<class C, std::enable_if_t<std::is_same_v<Container,\
    \ std::decay_t<C>>>>\n    UnionFind(C&& par): par(std::forward<C>(par)) {}\n\n\
    \    void resize(KYOPRO_BASE_UINT x) { par.resize(x, -1); }\n    void assign(KYOPRO_BASE_UINT\
    \ x) { par.assign(x, -1); }\n    void reset() { std::fill(std::begin(par), std::end(par),\
    \ -1); }\n\n    KYOPRO_BASE_UINT size() const noexcept { return par.size(); }\n\
    \n    KYOPRO_BASE_INT find(int x) {\n      int p = x;\n      while (par[p] >=\
    \ 0) p = par[p];\n      while (x != p) {\n        int tmp = x;\n        x = par[x];\n\
    \        par[tmp] = p;\n      }\n      return p;\n    }\n\n    bool merge(int\
    \ x, int y) {\n      x = find(x), y = find(y);\n      if (x == y) return false;\n\
    \      if (par[x] > par[y]) {\n        int tmp = x;\n        x = y;\n        y\
    \ = tmp;\n      }\n      par[x] += par[y];\n      par[y] = x;\n      return true;\n\
    \    }\n\n    bool same(int x, int y) { return find(x) == find(y); }\n\n    KYOPRO_BASE_INT\
    \ group_size(int x) { return -par[find(x)]; }\n\n    std::vector<int> group_members(int\
    \ x) {\n      x = find(x);\n      std::vector<int> a;\n      for (int i = 0; i\
    \ < (int)(size()); ++i) if (find(i) == x) a.emplace_back(i);\n      return a;\n\
    \    }\n\n    template<class Vector = std::vector<KYOPRO_BASE_INT>>\n    Vector\
    \ roots() const {\n      Vector a;\n      for (int i = 0; i < (int)(size()); ++i)\
    \ if (par[i] < 0) a.emplace_back(i);\n      return a;\n    }\n\n    KYOPRO_BASE_INT\
    \ group_count() const {\n      KYOPRO_BASE_INT cnt = 0;\n      for (int i = 0;\
    \ i < (int)(size()); ++i) if (par[i] < 0) ++cnt;\n      return cnt;\n    }\n\n\
    \    template<class Map = std::unordered_map<KYOPRO_BASE_INT, std::vector<KYOPRO_BASE_INT>>>\n\
    \    Map all_group_members() {\n      Map group_members;\n      for (int member\
    \ = 0; member < (int)(size()); ++member) group_members[find(member)].emplace_back(member);\n\
    \      return group_members;\n    }\n  };\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <type_traits>\n#include <unordered_map>\n\
    #include <utility>\n#include <vector>\n#include \"../meta/settings.hpp\"\n\nnamespace\
    \ kyopro {\n  template<class Container = std::vector<int>>\n  struct UnionFind\
    \ {\n  private:\n    Container par;\n\n  public:\n    UnionFind() noexcept = default;\n\
    \    UnionFind(KYOPRO_BASE_UINT n) noexcept: par(n, -1) {}\n    template<class\
    \ C, std::enable_if_t<std::is_same_v<Container, std::decay_t<C>>>>\n    UnionFind(C&&\
    \ par): par(std::forward<C>(par)) {}\n\n    void resize(KYOPRO_BASE_UINT x) {\
    \ par.resize(x, -1); }\n    void assign(KYOPRO_BASE_UINT x) { par.assign(x, -1);\
    \ }\n    void reset() { std::fill(std::begin(par), std::end(par), -1); }\n\n \
    \   KYOPRO_BASE_UINT size() const noexcept { return par.size(); }\n\n    KYOPRO_BASE_INT\
    \ find(int x) {\n      int p = x;\n      while (par[p] >= 0) p = par[p];\n   \
    \   while (x != p) {\n        int tmp = x;\n        x = par[x];\n        par[tmp]\
    \ = p;\n      }\n      return p;\n    }\n\n    bool merge(int x, int y) {\n  \
    \    x = find(x), y = find(y);\n      if (x == y) return false;\n      if (par[x]\
    \ > par[y]) {\n        int tmp = x;\n        x = y;\n        y = tmp;\n      }\n\
    \      par[x] += par[y];\n      par[y] = x;\n      return true;\n    }\n\n   \
    \ bool same(int x, int y) { return find(x) == find(y); }\n\n    KYOPRO_BASE_INT\
    \ group_size(int x) { return -par[find(x)]; }\n\n    std::vector<int> group_members(int\
    \ x) {\n      x = find(x);\n      std::vector<int> a;\n      for (int i = 0; i\
    \ < (int)(size()); ++i) if (find(i) == x) a.emplace_back(i);\n      return a;\n\
    \    }\n\n    template<class Vector = std::vector<KYOPRO_BASE_INT>>\n    Vector\
    \ roots() const {\n      Vector a;\n      for (int i = 0; i < (int)(size()); ++i)\
    \ if (par[i] < 0) a.emplace_back(i);\n      return a;\n    }\n\n    KYOPRO_BASE_INT\
    \ group_count() const {\n      KYOPRO_BASE_INT cnt = 0;\n      for (int i = 0;\
    \ i < (int)(size()); ++i) if (par[i] < 0) ++cnt;\n      return cnt;\n    }\n\n\
    \    template<class Map = std::unordered_map<KYOPRO_BASE_INT, std::vector<KYOPRO_BASE_INT>>>\n\
    \    Map all_group_members() {\n      Map group_members;\n      for (int member\
    \ = 0; member < (int)(size()); ++member) group_members[find(member)].emplace_back(member);\n\
    \      return group_members;\n    }\n  };\n}\n"
  dependsOn:
  - meta/settings.hpp
  isVerificationFile: false
  path: structure/UnionFind.hpp
  requiredBy:
  - structure/all.hpp
  - all/all.hpp
  timestamp: '2022-04-21 22:07:36+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - yosupo/UnionFind.test.cpp
documentation_of: structure/UnionFind.hpp
layout: document
redirect_from:
- /library/structure/UnionFind.hpp
- /library/structure/UnionFind.hpp.html
title: structure/UnionFind.hpp
---
