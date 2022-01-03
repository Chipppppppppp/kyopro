---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base/base_int.hpp
    title: base/base_int.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: yosupo/FenwickTree.test.cpp
    title: yosupo/FenwickTree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"structure/FenwickTree.hpp\"\n\n\n/* FenwickTree */\n#include\
    \ <cstdint>\n#include <vector>\n#include <utility>\n#line 2 \"base/base_int.hpp\"\
    \n#ifndef KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT std::int64_t\n#endif\n#line\
    \ 8 \"structure/FenwickTree.hpp\"\n\nnamespace kyopro {\n  template<class KyoproT,\
    \ class KyoproContainer = std::vector<KyoproT>>\n  struct FenwickTree {\n  private:\n\
    \    KyoproContainer kyopro_tree;\n  public:\n    using value_type = KyoproT;\n\
    \    using size_type = std::size_t;\n    using reference = KyoproT&;\n    using\
    \ const_reference = const KyoproT&;\n    FenwickTree() noexcept = default;\n \
    \   FenwickTree(std::size_t kyopro_n) noexcept: kyopro_tree(kyopro_n) {}\n   \
    \ template<class... KyoproArgs>\n    FenwickTree(KyoproArgs&&... kyopro_args)\
    \ noexcept {\n      KyoproContainer kyopro_a(std::forward<KyoproArgs>(kyopro_args)...);\n\
    \      FenwickTree(kyopro_a.size());\n      int kyopro_cnt = 0;\n      for (KyoproT&\
    \ kyopro_i: kyopro_a) {\n        add(kyopro_cnt, kyopro_i);\n        ++kyopro_cnt;\n\
    \      }\n    }\n    std::size_t size() noexcept { return kyopro_tree.size();\
    \ }\n    void add(int kyopro_p, const KyoproT& kyopro_x) {\n      ++kyopro_p;\n\
    \      while (kyopro_p <= (int)size()) {\n        kyopro_tree[kyopro_p - 1] +=\
    \ kyopro_x;\n        kyopro_p += kyopro_p & -kyopro_p;\n      }\n    }\n    void\
    \ set(int kyopro_p, const KyoproT& kyopro_x) { add(kyopro_p, kyopro_x - get(kyopro_p));\
    \ }\n    KyoproT query(int kyopro_r) {\n      KyoproT kyopro_s = 0;\n      while\
    \ (kyopro_r > 0) {\n        kyopro_s += kyopro_tree[kyopro_r - 1];\n        kyopro_r\
    \ -= kyopro_r & -kyopro_r;\n      }\n      return kyopro_s;\n    }\n    KyoproT\
    \ query(int kyopro_l, int kyopro_r) { return query(kyopro_r) - query(kyopro_l);\
    \ }\n    KyoproT get(int kyopro_p) { return query(kyopro_p + 1) - query(kyopro_p);\
    \ }\n    KyoproT all_query() { return query(kyopro_tree.size()); }\n  };\n}\n\n"
  code: "#ifndef KYOPRO_FENWICK_TREE\n#define KYOPRO_FENWICK_TREE\n/* FenwickTree\
    \ */\n#include <cstdint>\n#include <vector>\n#include <utility>\n#include \"../base/base_int.hpp\"\
    \n\nnamespace kyopro {\n  template<class KyoproT, class KyoproContainer = std::vector<KyoproT>>\n\
    \  struct FenwickTree {\n  private:\n    KyoproContainer kyopro_tree;\n  public:\n\
    \    using value_type = KyoproT;\n    using size_type = std::size_t;\n    using\
    \ reference = KyoproT&;\n    using const_reference = const KyoproT&;\n    FenwickTree()\
    \ noexcept = default;\n    FenwickTree(std::size_t kyopro_n) noexcept: kyopro_tree(kyopro_n)\
    \ {}\n    template<class... KyoproArgs>\n    FenwickTree(KyoproArgs&&... kyopro_args)\
    \ noexcept {\n      KyoproContainer kyopro_a(std::forward<KyoproArgs>(kyopro_args)...);\n\
    \      FenwickTree(kyopro_a.size());\n      int kyopro_cnt = 0;\n      for (KyoproT&\
    \ kyopro_i: kyopro_a) {\n        add(kyopro_cnt, kyopro_i);\n        ++kyopro_cnt;\n\
    \      }\n    }\n    std::size_t size() noexcept { return kyopro_tree.size();\
    \ }\n    void add(int kyopro_p, const KyoproT& kyopro_x) {\n      ++kyopro_p;\n\
    \      while (kyopro_p <= (int)size()) {\n        kyopro_tree[kyopro_p - 1] +=\
    \ kyopro_x;\n        kyopro_p += kyopro_p & -kyopro_p;\n      }\n    }\n    void\
    \ set(int kyopro_p, const KyoproT& kyopro_x) { add(kyopro_p, kyopro_x - get(kyopro_p));\
    \ }\n    KyoproT query(int kyopro_r) {\n      KyoproT kyopro_s = 0;\n      while\
    \ (kyopro_r > 0) {\n        kyopro_s += kyopro_tree[kyopro_r - 1];\n        kyopro_r\
    \ -= kyopro_r & -kyopro_r;\n      }\n      return kyopro_s;\n    }\n    KyoproT\
    \ query(int kyopro_l, int kyopro_r) { return query(kyopro_r) - query(kyopro_l);\
    \ }\n    KyoproT get(int kyopro_p) { return query(kyopro_p + 1) - query(kyopro_p);\
    \ }\n    KyoproT all_query() { return query(kyopro_tree.size()); }\n  };\n}\n\
    #endif\n"
  dependsOn:
  - base/base_int.hpp
  isVerificationFile: false
  path: structure/FenwickTree.hpp
  requiredBy: []
  timestamp: '2022-01-03 21:52:54+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - yosupo/FenwickTree.test.cpp
documentation_of: structure/FenwickTree.hpp
layout: document
redirect_from:
- /library/structure/FenwickTree.hpp
- /library/structure/FenwickTree.hpp.html
title: structure/FenwickTree.hpp
---
