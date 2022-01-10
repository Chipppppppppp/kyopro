---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base/constant.hpp
    title: base/constant.hpp
  - icon: ':question:'
    path: base/settings.hpp
    title: base/settings.hpp
  - icon: ':heavy_check_mark:'
    path: math/monoid.hpp
    title: math/monoid.hpp
  - icon: ':heavy_check_mark:'
    path: math/power.hpp
    title: math/power.hpp
  - icon: ':heavy_check_mark:'
    path: structure/FenwickTree.hpp
    title: structure/FenwickTree.hpp
  - icon: ':heavy_check_mark:'
    path: structure/UnionFind.hpp
    title: structure/UnionFind.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/UnionFind.hpp\"\n/* UnionFind */\n#include <vector>\n\
    #include <unordered_map>\n#include <algorithm>\n#line 2 \"base/settings.hpp\"\n\
    #include <cstdint>\n\n#ifndef KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT std::int64_t\n\
    #endif\n#ifndef KYOPRO_BASE_UINT\n#define KYOPRO_BASE_UINT std::size_t\n#endif\n\
    #ifndef KYOPRO_BASE_FLOAT\n#define KYOPRO_BASE_FLOAT double\n#endif\n#ifndef KYOPRO_DEFAULT_MOD\n\
    #define KYOPRO_DEFAULT_MOD 1000000007\n#endif\n#ifndef KYOPRO_DECIMAL_PRECISION\n\
    #define KYOPRO_DECIMAL_PRECISION 12\n#endif\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV\
    \ 3\n#endif\n#line 7 \"structure/UnionFind.hpp\"\n\nnamespace kyopro {\n  template<class\
    \ KyoproContainer = std::vector<int>>\n  struct UnionFind {\n  private:\n    KyoproContainer\
    \ kyopro_par;\n  public:\n    UnionFind() noexcept = default;\n    UnionFind(KYOPRO_BASE_UINT\
    \ kyopro_n) noexcept: kyopro_par(kyopro_n, -1) {}\n    void resize(KYOPRO_BASE_UINT\
    \ kyopro_x) { kyopro_par.resize(kyopro_x, -1); }\n    void assign(KYOPRO_BASE_UINT\
    \ kyopro_x) { kyopro_par.assign(kyopro_x, -1); }\n    void reset() { std::fill(std::begin(kyopro_par),\
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
    \      return kyopro_group_members;\n    }\n  };\n}\n#line 2 \"structure/FenwickTree.hpp\"\
    \n/* FenwickTree */\n#line 4 \"structure/FenwickTree.hpp\"\n#include <utility>\n\
    #line 2 \"math/monoid.hpp\"\n#include <type_traits>\n#line 3 \"base/constant.hpp\"\
    \n#include <limits>\n#include <array>\n#line 4 \"math/power.hpp\"\nnamespace kyopro\
    \ {\n  template<class KyoproT>\n  constexpr KyoproT power(KyoproT a, std::uint64_t\
    \ n, KyoproT init = 1) noexcept {\n    while (n > 0) {\n      if (n & 1) init\
    \ *= a;\n      a *= a;\n      n >>= 1;\n    }\n    return init;\n  }\n}\n#line\
    \ 8 \"base/constant.hpp\"\n\nnamespace kyopro {\n  inline constexpr std::uint64_t\
    \ kyopro_decimal_max = power(static_cast<std::uint64_t>(10), KYOPRO_DECIMAL_PRECISION);\n\
    \  template<class KyoproT>\n  inline constexpr KyoproT MOD = KYOPRO_DEFAULT_MOD;\n\
    \  inline constexpr KYOPRO_BASE_INT mod = MOD<KYOPRO_BASE_INT>;\n  template<class\
    \ KyoproT>\n  inline constexpr KyoproT INF = std::numeric_limits<KyoproT>::max()\
    \ / KYOPRO_INF_DIV;\n  inline constexpr KYOPRO_BASE_INT inf = INF<KYOPRO_BASE_INT>;\n\
    \  template<class KyoproT>\n  inline constexpr KYOPRO_BASE_FLOAT EPS = static_cast<KyoproT>(1)\
    \ / kyopro_decimal_max;\n  inline constexpr KYOPRO_BASE_FLOAT eps = EPS<KYOPRO_BASE_FLOAT>;\n\
    \  template<class KyoproT>\n  inline constexpr KyoproT PI = 3.14159265358979323846;\n\
    \  inline constexpr KYOPRO_BASE_FLOAT pi = PI<KYOPRO_BASE_FLOAT>;\n  inline constexpr\
    \ std::array<std::pair<KYOPRO_BASE_INT, KYOPRO_BASE_INT>, 4> beside{{{1, 0}, {0,\
    \ 1}, {-1, 0}, {0, -1}}};\n  inline constexpr std::array<std::pair<KYOPRO_BASE_INT,\
    \ KYOPRO_BASE_INT>, 8> around{{{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1,\
    \ -1}, {0, -1}, {1, -1}}};\n}\n#line 4 \"math/monoid.hpp\"\n\nnamespace kyopro\
    \ {\n  template<class KyoproT, KyoproT kyopro_id = 0>\n  struct Plus {\n    static\
    \ constexpr KyoproT id = kyopro_id;\n    static constexpr KyoproT op(KyoproT kyopro_a,\
    \ KyoproT kyopro_b) noexcept { return kyopro_a + kyopro_b; }\n    static constexpr\
    \ KyoproT inv(KyoproT kyopro_a) noexcept { return -kyopro_a; }\n  };\n  template<class\
    \ KyoproT, KyoproT kyopro_id = 1>\n  struct Mul {\n    static constexpr KyoproT\
    \ id = kyopro_id;\n    static constexpr KyoproT op(KyoproT kyopro_a, KyoproT kyopro_b)\
    \ noexcept { return kyopro_a * kyopro_b; }\n    static constexpr KyoproT inv(KyoproT\
    \ kyopro_a) noexcept {\n      static_assert(!std::is_integral_v<KyoproT>);\n \
    \     return 1 / kyopro_a;\n    }\n  };\n  template<class KyoproT, KyoproT kyopro_id\
    \ = -inf>\n  struct Max {\n    static constexpr KyoproT id = kyopro_id;\n    static\
    \ constexpr KyoproT op(KyoproT kyopro_a, KyoproT kyopro_b) noexcept { return kyopro_a\
    \ > kyopro_b ? kyopro_a : kyopro_b; }\n  };\n  template<class KyoproT, KyoproT\
    \ kyopro_id = inf>\n  struct Min {\n    static constexpr KyoproT id = kyopro_id;\n\
    \    static constexpr KyoproT op(KyoproT kyopro_a, KyoproT kyopro_b) noexcept\
    \ { return kyopro_a < kyopro_b ? kyopro_a : kyopro_b; }\n  };\n}\n#line 7 \"structure/FenwickTree.hpp\"\
    \n\nnamespace kyopro {\n  template<class KyoproT, class KyoproOp = Plus<KyoproT>,\
    \ class KyoproContainer = std::vector<KyoproT>>\n  struct FenwickTree {\n  private:\n\
    \    KyoproContainer kyopro_tree;\n  public:\n    using value_type = KyoproT;\n\
    \    using size_type = KYOPRO_BASE_UINT;\n    using reference = KyoproT&;\n  \
    \  using const_reference = const KyoproT&;\n    FenwickTree() noexcept = default;\n\
    \    FenwickTree(KYOPRO_BASE_UINT kyopro_n) noexcept: kyopro_tree(kyopro_n, KyoproOp::id)\
    \ {}\n    KYOPRO_BASE_UINT size() noexcept { return kyopro_tree.size(); }\n  \
    \  void apply(int kyopro_p, const KyoproT& kyopro_x) {\n      ++kyopro_p;\n  \
    \    while (kyopro_p <= (int)size()) {\n        kyopro_tree[kyopro_p - 1] = KyoproOp::op(kyopro_tree[kyopro_p\
    \ - 1], kyopro_x);\n        kyopro_p += kyopro_p & -kyopro_p;\n      }\n    }\n\
    \    KyoproT prod(int kyopro_r) const {\n      KyoproT kyopro_s = KyoproOp::id;\n\
    \      while (kyopro_r > 0) {\n        kyopro_s = KyoproOp::op(kyopro_s, kyopro_tree[kyopro_r\
    \ - 1]);\n        kyopro_r -= kyopro_r & -kyopro_r;\n      }\n      return kyopro_s;\n\
    \    }\n    KyoproT prod(int kyopro_l, int kyopro_r) const { return KyoproOp::op(prod(kyopro_r),\
    \ KyoproOp::inv(prod(kyopro_l))); }\n    KyoproT get(int kyopro_p) { return KyoproOp::op(prod(kyopro_p\
    \ + 1), KyoproOp::inv(prod(kyopro_p))); }\n    KyoproT all_query() { return prod(kyopro_tree.size());\
    \ }\n    void set(int kyopro_p, const KyoproT& kyopro_x) { apply(kyopro_p, KyoproOp::op(kyopro_x,\
    \ KyoproOp::inv(get(kyopro_p)))); }\n  };\n}\n#line 4 \"structure/all.hpp\"\n"
  code: '#pragma once

    #include "UnionFind.hpp"

    #include "FenwickTree.hpp"'
  dependsOn:
  - structure/UnionFind.hpp
  - base/settings.hpp
  - structure/FenwickTree.hpp
  - math/monoid.hpp
  - base/constant.hpp
  - math/power.hpp
  isVerificationFile: false
  path: structure/all.hpp
  requiredBy:
  - all.hpp
  timestamp: '2022-01-10 20:12:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/all.hpp
layout: document
redirect_from:
- /library/structure/all.hpp
- /library/structure/all.hpp.html
title: structure/all.hpp
---
