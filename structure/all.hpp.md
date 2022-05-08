---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: function/monoid.hpp
    title: function/monoid.hpp
  - icon: ':heavy_check_mark:'
    path: math/power.hpp
    title: math/power.hpp
  - icon: ':heavy_check_mark:'
    path: meta/constant.hpp
    title: meta/constant.hpp
  - icon: ':heavy_check_mark:'
    path: meta/settings.hpp
    title: meta/settings.hpp
  - icon: ':heavy_check_mark:'
    path: meta/trait.hpp
    title: meta/trait.hpp
  - icon: ':heavy_check_mark:'
    path: structure/FenwickTree.hpp
    title: structure/FenwickTree.hpp
  - icon: ':heavy_check_mark:'
    path: structure/UnionFind.hpp
    title: structure/UnionFind.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all/all.hpp
    title: all/all.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/FenwickTree.hpp\"\n#include <type_traits>\n#include\
    \ <utility>\n#include <vector>\n#line 2 \"meta/constant.hpp\"\n#include <array>\n\
    #include <limits>\n#line 2 \"meta/settings.hpp\"\n#include <cstdint>\n\n#ifndef\
    \ KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT std::int64_t\n#endif\n\n#ifndef KYOPRO_BASE_UINT\n\
    #define KYOPRO_BASE_UINT std::uint64_t\n#endif\n\n#ifndef KYOPRO_BASE_FLOAT\n\
    #define KYOPRO_BASE_FLOAT double\n#endif\n\n#ifndef KYOPRO_DEFAULT_MOD\n#define\
    \ KYOPRO_DEFAULT_MOD static_cast<KYOPRO_BASE_UINT>(998244353)\n#endif\n\n#ifndef\
    \ KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n\
    #endif\n\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 3 \"math/power.hpp\"\n\nnamespace kpr {\n  template<class T>\n \
    \ constexpr T power(T a, KYOPRO_BASE_UINT n, T init = 1) noexcept {\n    while\
    \ (n > 0) {\n      if (n & 1) init *= a;\n      a *= a;\n      n >>= 1;\n    }\n\
    \    return init;\n  }\n}\n#line 7 \"meta/constant.hpp\"\n\nnamespace kpr {\n\
    \  template<class T>\n  inline constexpr T MOD = KYOPRO_DEFAULT_MOD;\n  inline\
    \ constexpr KYOPRO_BASE_INT mod = MOD<KYOPRO_BASE_INT>;\n\n  template<class T>\n\
    \  inline constexpr T INF = std::numeric_limits<T>::max() / KYOPRO_INF_DIV;\n\
    \  inline constexpr KYOPRO_BASE_INT inf = INF<KYOPRO_BASE_INT>;\n\n  template<class\
    \ T, KYOPRO_BASE_UINT decimal_precision = KYOPRO_DECIMAL_PRECISION>\n  inline\
    \ constexpr KYOPRO_BASE_FLOAT EPS = static_cast<T>(1) / power(10ULL, decimal_precision);\n\
    \  inline constexpr KYOPRO_BASE_FLOAT eps = EPS<KYOPRO_BASE_FLOAT>;\n\n  template<class\
    \ T>\n  inline constexpr T PI = 3.14159265358979323846;\n  inline constexpr KYOPRO_BASE_FLOAT\
    \ pi = PI<KYOPRO_BASE_FLOAT>;\n}\n#line 4 \"function/monoid.hpp\"\n\nnamespace\
    \ kpr {\n  template<class T, T _id = 0>\n  struct Plus {\n    static_assert(std::is_arithmetic_v<T>);\n\
    \    using value_type = T;\n    static constexpr T id = _id;\n\n    constexpr\
    \ T operator ()(T a, T b) const noexcept { return a + b; }\n    constexpr T inverse(T\
    \ a) const noexcept { return -a; }\n  };\n\n  template<class T, T _id = 1>\n \
    \ struct Mul {\n    static_assert(std::is_arithmetic_v<T>);\n    using value_type\
    \ = T;\n    static constexpr T id = _id;\n\n    constexpr T operator ()(T a, T\
    \ b) const noexcept { return a * b; }\n    constexpr T inverse(T a) const noexcept\
    \ {\n      static_assert(!std::is_integral_v<T>);\n      return 1 / a;\n    }\n\
    \  };\n\n  template<class T, T _id = std::is_integral_v<T> ? -INF<T> : -inf>\n\
    \  struct Max {\n    static_assert(std::is_arithmetic_v<T>);\n    using value_type\
    \ = T;\n    static constexpr T id = _id;\n\n    constexpr T operator ()(T a, T\
    \ b) const noexcept { return a > b ? a : b; }\n  };\n\n  template<class T, T _id\
    \ = std::is_integral_v<T> ? INF<T> : inf>\n  struct Min {\n    static_assert(std::is_arithmetic_v<T>);\n\
    \    using value_type = T;\n    static constexpr T id = _id;\n\n    constexpr\
    \ T operator ()(T a, T b) const noexcept { return a < b ? a : b; }\n  };\n}\n\
    #line 7 \"structure/FenwickTree.hpp\"\n\nnamespace kpr {\n  template<class T,\
    \ class Op = Plus<T>, class Container = std::vector<T>>\n  struct FenwickTree\
    \ {\n    using value_type = T;\n    using size_type = KYOPRO_BASE_UINT;\n    using\
    \ reference = T&;\n    using const_reference = const T&;\n    using operator_type\
    \ = Op;\n    using container_type = Container;\n\n  private:\n    [[no_unique_address]]\
    \ Op op;\n    Container tree;\n\n  public:\n    FenwickTree() noexcept = default;\n\
    \    FenwickTree(KYOPRO_BASE_UINT n) noexcept: tree(n, op.id) {}\n    template<class\
    \ C, std::enable_if_t<std::is_same_v<Container, std::decay_t<C>>>>\n    FenwickTree(C&&\
    \ tree): tree(std::forward<C>(tree)) {}\n\n    KYOPRO_BASE_UINT size() noexcept\
    \ { return tree.size(); }\n\n    void apply(int p, const T& x) {\n      ++p;\n\
    \      while (p <= (int)size()) {\n        tree[p - 1] = op(tree[p - 1], x);\n\
    \        p += p & -p;\n      }\n    }\n\n    T prod(int r) const {\n      T s\
    \ = op.id;\n      while (r > 0) {\n        s = op(s, tree[r - 1]);\n        r\
    \ -= r & -r;\n      }\n      return s;\n    }\n    T prod(int l, int r) const\
    \ { return op(prod(r), op.inverse(prod(l))); }\n\n    T all_prod() { return prod(tree.size());\
    \ }\n\n    T get(int p) { return op(prod(p + 1), op.inverse(prod(p))); }\n\n \
    \   void set(int p, const T& x) { apply(p, op(x, op.inverse(get(p)))); }\n  };\n\
    }\n#line 2 \"structure/UnionFind.hpp\"\n#include <algorithm>\n#line 4 \"structure/UnionFind.hpp\"\
    \n#include <unordered_map>\n#line 2 \"meta/trait.hpp\"\n#include <iterator>\n\
    #include <queue>\n#line 5 \"meta/trait.hpp\"\n#include <stack>\n#line 9 \"meta/trait.hpp\"\
    \n\ntemplate<>\nstruct std::is_integral<__int128_t>: std::true_type {};\ntemplate<>\n\
    struct std::is_integral<__uint128_t>: std::true_type {};\ntemplate<>\nstruct std::is_floating_point<__float128>:\
    \ std::true_type {};\n\nnamespace kpr {\n  template<KYOPRO_BASE_UINT size>\n \
    \ struct int_least {\n  private:\n    static constexpr auto get_type() noexcept\
    \ {\n      static_assert(size <= 128, \"Integer size is too large\");\n      if\
    \ constexpr (size <= 8) return std::int_least8_t();\n      else if constexpr (size\
    \ <= 16) return std::int_least16_t();\n      else if constexpr (size <= 32) return\
    \ std::int_least32_t();\n      else if constexpr (size <= 64) return std::int_least64_t();\n\
    \      else return __int128_t();\n    }\n\n  public:\n    using type = decltype(get_type());\n\
    \  };\n\n  template<KYOPRO_BASE_UINT size>\n  using int_least_t = typename int_least<size>::type;\n\
    \n  template<KYOPRO_BASE_UINT size>\n  struct uint_least {\n  private:\n    static\
    \ constexpr auto get_type() noexcept {\n      static_assert(size <= 128, \"Integer\
    \ size is too large\");\n      if constexpr (size <= 8) return std::uint_least8_t();\n\
    \      else if constexpr (size <= 16) return std::uint_least16_t();\n      else\
    \ if constexpr (size <= 32) return std::uint_least32_t();\n      else if constexpr\
    \ (size <= 64) return std::uint_least64_t();\n      else return __uint128_t();\n\
    \    }\n\n  public:\n    using type = decltype(get_type());\n  };\n\n  template<KYOPRO_BASE_UINT\
    \ size>\n  using uint_least_t = typename uint_least<size>::type;\n\n  template<class,\
    \ class = void>\n  struct is_iterator: std::false_type {};\n  template<class T>\n\
    \  struct is_iterator<T, std::void_t<typename std::iterator_traits<T>::iterator_category>>:\
    \ std::true_type {};\n\n  template<class T>\n  constexpr bool is_iterator_v =\
    \ is_iterator<T>::value;\n\n  template<class, class = void>\n  struct is_iterable:\
    \ std::false_type {};\n  template<class T>\n  struct is_iterable<T, std::void_t<decltype(std::begin(std::declval<T>()))>>:\
    \ std::true_type {};\n\n  template<class T>\n  constexpr bool is_iterable_v =\
    \ is_iterable<T>::value;\n\n  template<class>\n  struct is_tuple: std::false_type\
    \ {};\n  template<class T, class U>\n  struct is_tuple<std::pair<T, U>>: std::true_type\
    \ {};\n  template<class... Args>\n  struct is_tuple<std::tuple<Args...>>: std::true_type\
    \ {};\n\n  template<class T>\n  constexpr bool is_tuple_v = is_tuple<T>::value;\n\
    \n  template<class T>\n  struct iterable_value {\n    using type = std::decay_t<decltype(*std::begin(std::declval<T>()))>;\n\
    \  };\n\n  template<class T>\n  using iterable_value_t = typename iterable_value<T>::type;\n\
    }\n#line 9 \"structure/UnionFind.hpp\"\n\nnamespace kpr {\n  template<class Container\
    \ = std::vector<int>>\n  struct UnionFind {\n    using value_type = iterable_value_t<Container>;\n\
    \    using container_type = Container;\n\n  private:\n    Container par;\n\n \
    \ public:\n    UnionFind() noexcept = default;\n    UnionFind(KYOPRO_BASE_UINT\
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
    \      return group_members;\n    }\n  };\n}\n#line 4 \"structure/all.hpp\"\n"
  code: '#pragma once

    #include "FenwickTree.hpp"

    #include "UnionFind.hpp"'
  dependsOn:
  - structure/FenwickTree.hpp
  - function/monoid.hpp
  - meta/constant.hpp
  - math/power.hpp
  - meta/settings.hpp
  - structure/UnionFind.hpp
  - meta/trait.hpp
  isVerificationFile: false
  path: structure/all.hpp
  requiredBy:
  - all/all.hpp
  timestamp: '2022-05-08 20:22:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/all.hpp
layout: document
redirect_from:
- /library/structure/all.hpp
- /library/structure/all.hpp.html
title: structure/all.hpp
---
