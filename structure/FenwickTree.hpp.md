---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base/settings.hpp
    title: base/settings.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: yosupo/FenwickTree.test.cpp
    title: yosupo/FenwickTree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/FenwickTree.hpp\"\n/* FenwickTree */\n#include\
    \ <vector>\n#include <utility>\n#line 1 \"base/settings.hpp\"\n#include <cstdint>\n\
    #ifndef KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT std::int64_t\n#endif\n#ifndef\
    \ KYOPRO_BASE_UINT\n#define KYOPRO_BASE_UINT std::size_t\n#endif\n#ifndef KYOPRO_BASE_FLOAT\n\
    #define KYOPRO_BASE_FLOAT double\n#endif\n#ifndef KYOPRO_DEFAULT_MOD\n#define\
    \ KYOPRO_DEFAULT_MOD 1000000007\n#endif\n#ifndef KYOPRO_DECIMAL_PRECISION\n#define\
    \ KYOPRO_DECIMAL_PRECISION 12\n#endif\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV\
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
    \ all_query() { return query(kyopro_tree.size()); }\n  };\n}\n"
  code: "#pragma once\n/* FenwickTree */\n#include <vector>\n#include <utility>\n\
    #include \"../base/settings.hpp\"\n\nnamespace kyopro {\n  template<class KyoproT,\
    \ class KyoproContainer = std::vector<KyoproT>>\n  struct FenwickTree {\n  private:\n\
    \    KyoproContainer kyopro_tree;\n  public:\n    using value_type = KyoproT;\n\
    \    using size_type = KYOPRO_BASE_UINT;\n    using reference = KyoproT&;\n  \
    \  using const_reference = const KyoproT&;\n    FenwickTree() noexcept = default;\n\
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
    \ all_query() { return query(kyopro_tree.size()); }\n  };\n}\n"
  dependsOn:
  - base/settings.hpp
  isVerificationFile: false
  path: structure/FenwickTree.hpp
  requiredBy:
  - all.hpp
  timestamp: '2022-01-04 18:22:10+09:00'
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
