---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base/constant.hpp
    title: base/constant.hpp
  - icon: ':heavy_check_mark:'
    path: base/monoid.hpp
    title: base/monoid.hpp
  - icon: ':heavy_check_mark:'
    path: base/settings.hpp
    title: base/settings.hpp
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
    \ 3\n#endif\n#line 2 \"base/monoid.hpp\"\n#include <type_traits>\n#line 2 \"base/constant.hpp\"\
    \n#include <limits>\n#include <array>\n#line 2 \"base/settings.hpp\"\n#ifndef\
    \ KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT std::int64_t\n#endif\n#ifndef KYOPRO_BASE_UINT\n\
    #define KYOPRO_BASE_UINT std::size_t\n#endif\n#ifndef KYOPRO_BASE_FLOAT\n#define\
    \ KYOPRO_BASE_FLOAT double\n#endif\n#ifndef KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD\
    \ 1000000007\n#endif\n#ifndef KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION\
    \ 12\n#endif\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV 3\n#endif\n#line\
    \ 6 \"base/constant.hpp\"\n\nnamespace kyopro {\n  template<class KyoproT>\n \
    \ inline constexpr KyoproT MOD = KYOPRO_DEFAULT_MOD;\n  inline constexpr KYOPRO_BASE_INT\
    \ mod = MOD<KYOPRO_BASE_INT>;\n  template<class KyoproT>\n  inline constexpr KyoproT\
    \ INF = std::numeric_limits<KyoproT>::max() / KYOPRO_INF_DIV;\n  inline constexpr\
    \ KYOPRO_BASE_INT inf = INF<KYOPRO_BASE_INT>;\n  template<class KyoproT>\n  inline\
    \ constexpr KyoproT PI = 3.14159265358979323846;\n  inline constexpr KYOPRO_BASE_FLOAT\
    \ pi = PI<KYOPRO_BASE_FLOAT>;\n  using KyoproPair = std::pair<KYOPRO_BASE_INT,\
    \ KYOPRO_BASE_INT>;\n  inline constexpr std::array<KyoproPair, 4> beside{KyoproPair{1,\
    \ 0}, KyoproPair{0, 1}, KyoproPair{-1, 0}, KyoproPair{0, -1}};\n  inline constexpr\
    \ std::array<KyoproPair, 8> around{KyoproPair{1, 0}, KyoproPair{1, 1}, KyoproPair{0,\
    \ 1}, KyoproPair{-1, 1}, KyoproPair{-1, 0}, KyoproPair{-1, -1}, KyoproPair{0,\
    \ -1}, KyoproPair{1, -1}};\n}\n#line 4 \"base/monoid.hpp\"\n\nnamespace kyopro\
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
    \ KyoproOp::inv(get(kyopro_p)))); }\n  };\n}\n#line 4 \"yosupo/FenwickTree.test.cpp\"\
    \nusing ll = long long;\n\nint main() {\n  int n, q;\n  std::cin >> n >> q;\n\
    \  kyopro::FenwickTree<ll> ft(n);\n  for (int i = 0; i < n; ++i) {\n    int a;\n\
    \    std::cin >> a;\n    ft.apply(i, a);\n  }\n  for (int i = 0; i < q; ++i) {\n\
    \    int t, x, y;\n    std::cin >> t >> x >> y;\n    if (t == 0) ft.apply(x, y);\n\
    \    else std::cout << ft.prod(x, y) << '\\n';\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include <iostream>\n#include \"../structure/FenwickTree.hpp\"\nusing ll = long\
    \ long;\n\nint main() {\n  int n, q;\n  std::cin >> n >> q;\n  kyopro::FenwickTree<ll>\
    \ ft(n);\n  for (int i = 0; i < n; ++i) {\n    int a;\n    std::cin >> a;\n  \
    \  ft.apply(i, a);\n  }\n  for (int i = 0; i < q; ++i) {\n    int t, x, y;\n \
    \   std::cin >> t >> x >> y;\n    if (t == 0) ft.apply(x, y);\n    else std::cout\
    \ << ft.prod(x, y) << '\\n';\n  }\n}\n"
  dependsOn:
  - structure/FenwickTree.hpp
  - base/settings.hpp
  - base/monoid.hpp
  - base/constant.hpp
  - base/settings.hpp
  isVerificationFile: true
  path: yosupo/FenwickTree.test.cpp
  requiredBy: []
  timestamp: '2022-01-05 11:38:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: yosupo/FenwickTree.test.cpp
layout: document
redirect_from:
- /verify/yosupo/FenwickTree.test.cpp
- /verify/yosupo/FenwickTree.test.cpp.html
title: yosupo/FenwickTree.test.cpp
---
