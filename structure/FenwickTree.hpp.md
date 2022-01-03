---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base/base_int.hpp
    title: base/base_int.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: yosupo/FenwickTree.test.cpp
    title: yosupo/FenwickTree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"structure/FenwickTree.hpp\"\n\n\n/* FenwickTree */\n#include\
    \ <cstdint>\n#include <vector>\n#line 2 \"base/base_int.hpp\"\n#ifndef KYOPRO_BASE_INT\n\
    #define KYOPRO_BASE_INT std::int64_t\n#endif\n#line 7 \"structure/FenwickTree.hpp\"\
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
    \ }\n    T all_query() { return query(kyopro_tree.size()); }\n  };\n}\n\n"
  code: "#ifndef KYOPRO_FENWICK_TREE\n#define KYOPRO_FENWICK_TREE\n/* FenwickTree\
    \ */\n#include <cstdint>\n#include <vector>\n#include \"../base/base_int.hpp\"\
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
    \ }\n    T all_query() { return query(kyopro_tree.size()); }\n  };\n}\n#endif\n"
  dependsOn:
  - base/base_int.hpp
  isVerificationFile: false
  path: structure/FenwickTree.hpp
  requiredBy: []
  timestamp: '2022-01-03 20:00:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - yosupo/FenwickTree.test.cpp
documentation_of: structure/FenwickTree.hpp
layout: document
redirect_from:
- /library/structure/FenwickTree.hpp
- /library/structure/FenwickTree.hpp.html
title: structure/FenwickTree.hpp
---
