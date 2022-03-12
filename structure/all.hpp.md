---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: base/constant.hpp
    title: base/constant.hpp
  - icon: ':x:'
    path: base/settings.hpp
    title: base/settings.hpp
  - icon: ':x:'
    path: math/monoid.hpp
    title: math/monoid.hpp
  - icon: ':x:'
    path: math/power.hpp
    title: math/power.hpp
  - icon: ':x:'
    path: structure/FenwickTree.hpp
    title: structure/FenwickTree.hpp
  - icon: ':x:'
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
  bundledCode: "#line 2 \"structure/FenwickTree.hpp\"\n/* FenwickTree */\n#include\
    \ <utility>\n#include <vector>\n#line 2 \"base/settings.hpp\"\n#include <cstdint>\n\
    \n#ifndef KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT std::int64_t\n#endif\n\n#ifndef\
    \ KYOPRO_BASE_UINT\n#define KYOPRO_BASE_UINT std::uint64_t\n#endif\n\n#ifndef\
    \ KYOPRO_BASE_FLOAT\n#define KYOPRO_BASE_FLOAT double\n#endif\n\n#ifndef KYOPRO_DEFAULT_MOD\n\
    #define KYOPRO_DEFAULT_MOD static_cast<KYOPRO_BASE_UINT>(1000000007)\n#endif\n\
    \n#ifndef KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n\
    #endif\n\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 2 \"math/monoid.hpp\"\n#include <type_traits>\n#line 2 \"base/constant.hpp\"\
    \n#include <array>\n#include <limits>\n#line 3 \"math/power.hpp\"\n\nnamespace\
    \ kyopro {\n  template<class _typeT>\n  constexpr _typeT power(_typeT _a, KYOPRO_BASE_UINT\
    \ _n, _typeT _init = 1) noexcept {\n    while (_n > 0) {\n      if (_n & 1) _init\
    \ *= _a;\n      _a *= _a;\n      _n >>= 1;\n    }\n    return _init;\n  }\n}\n\
    #line 7 \"base/constant.hpp\"\n\nnamespace kyopro {\n  template<class _typeT>\n\
    \  inline constexpr _typeT MOD = KYOPRO_DEFAULT_MOD;\n  inline constexpr KYOPRO_BASE_INT\
    \ mod = MOD<KYOPRO_BASE_INT>;\n\n  template<class _typeT>\n  inline constexpr\
    \ _typeT INF = std::numeric_limits<_typeT>::max() / KYOPRO_INF_DIV;\n  inline\
    \ constexpr KYOPRO_BASE_INT inf = INF<KYOPRO_BASE_INT>;\n\n  template<class _typeT,\
    \ KYOPRO_BASE_UINT _decimal_precision = KYOPRO_DECIMAL_PRECISION>\n  inline constexpr\
    \ KYOPRO_BASE_FLOAT EPS = static_cast<_typeT>(1) / power(10ULL, _decimal_precision);\n\
    \  inline constexpr KYOPRO_BASE_FLOAT eps = EPS<KYOPRO_BASE_FLOAT>;\n\n  template<class\
    \ _typeT>\n  inline constexpr _typeT PI = 3.14159265358979323846;\n  inline constexpr\
    \ KYOPRO_BASE_FLOAT pi = PI<KYOPRO_BASE_FLOAT>;\n\n  inline constexpr std::array<std::pair<KYOPRO_BASE_INT,\
    \ KYOPRO_BASE_INT>, 4> beside{{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}};\n  inline constexpr\
    \ std::array<std::pair<KYOPRO_BASE_INT, KYOPRO_BASE_INT>, 8> around{{{1, 0}, {1,\
    \ 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}}};\n}\n#line 4 \"math/monoid.hpp\"\
    \n\nnamespace kyopro {\n  template<class _typeT, _typeT _id = 0>\n  struct Plus\
    \ {\n    static_assert(std::is_arithmetic_v<_typeT>);\n    static constexpr _typeT\
    \ id = _id;\n    constexpr _typeT operator ()(_typeT _a, _typeT _b) const noexcept\
    \ { return _a + _b; }\n    constexpr _typeT inv(_typeT _a) const noexcept { return\
    \ -_a; }\n  };\n  template<class _typeT, _typeT _id = 1>\n  struct Mul {\n   \
    \ static_assert(std::is_arithmetic_v<_typeT>);\n    static constexpr _typeT id\
    \ = _id;\n    constexpr _typeT operator ()(_typeT _a, _typeT _b) const noexcept\
    \ { return _a * _b; }\n    constexpr _typeT inv(_typeT _a) const noexcept {\n\
    \      static_assert(!std::is_integral_v<_typeT>);\n      return 1 / _a;\n   \
    \ }\n  };\n  template<class _typeT, _typeT _id = std::is_integral_v<_typeT> ?\
    \ -INF<_typeT> : -inf>\n  struct Max {\n    static_assert(std::is_arithmetic_v<_typeT>);\n\
    \    static constexpr _typeT id = _id;\n    constexpr _typeT operator ()(_typeT\
    \ _a, _typeT _b) const noexcept { return _a > _b ? _a : _b; }\n  };\n  template<class\
    \ _typeT, _typeT _id = std::is_integral_v<_typeT> ? INF<_typeT> : inf>\n  struct\
    \ Min {\n    static_assert(std::is_arithmetic_v<_typeT>);\n    static constexpr\
    \ _typeT id = _id;\n    constexpr _typeT operator ()(_typeT _a, _typeT _b) const\
    \ noexcept { return _a < _b ? _a : _b; }\n  };\n}\n#line 7 \"structure/FenwickTree.hpp\"\
    \n\nnamespace kyopro {\n  template<class _typeT, class _typeOp = Plus<_typeT>>\n\
    \  struct FenwickTree {\n  private:\n    [[no_unique_address]] _typeOp _op;\n\
    \    std::vector<_typeT> _tree;\n\n  public:\n    using value_type = _typeT;\n\
    \    using size_type = KYOPRO_BASE_UINT;\n    using reference = _typeT&;\n   \
    \ using const_reference = const _typeT&;\n\n    FenwickTree() noexcept = default;\n\
    \    FenwickTree(KYOPRO_BASE_UINT _n) noexcept: _op(), _tree(_n, _op.id) {}\n\n\
    \    KYOPRO_BASE_UINT size() noexcept { return static_cast<KYOPRO_BASE_UINT>(_tree.size());\
    \ }\n\n    void apply(int _p, const _typeT& _x) {\n      ++_p;\n      while (_p\
    \ <= (int)size()) {\n        _tree[_p - 1] = _op(_tree[_p - 1], _x);\n       \
    \ _p += _p & -_p;\n      }\n    }\n\n    _typeT prod(int _r) const {\n      _typeT\
    \ _s = _op.id;\n      while (_r > 0) {\n        _s = _op(_s, _tree[_r - 1]);\n\
    \        _r -= _r & -_r;\n      }\n      return _s;\n    }\n    _typeT prod(int\
    \ _l, int _r) const { return _op(prod(_r), _op.inv(prod(_l))); }\n\n    _typeT\
    \ all_prod() { return prod(_tree.size()); }\n\n    _typeT get(int _p) { return\
    \ _op(prod(_p + 1), _op.inv(prod(_p))); }\n\n    void set(int _p, const _typeT&\
    \ _x) { apply(_p, _op(_x, _op.inv(get(_p)))); }\n  };\n}\n#line 2 \"structure/UnionFind.hpp\"\
    \n/* UnionFind */\n#include <algorithm>\n#include <unordered_map>\n#line 7 \"\
    structure/UnionFind.hpp\"\n\nnamespace kyopro {\n  struct UnionFind {\n  private:\n\
    \    std::vector<int> _par;\n\n  public:\n    UnionFind() noexcept = default;\n\
    \    UnionFind(KYOPRO_BASE_UINT _n) noexcept: _par(_n, -1) {}\n\n    void resize(KYOPRO_BASE_UINT\
    \ _x) { _par.resize(_x, -1); }\n    void assign(KYOPRO_BASE_UINT _x) { _par.assign(_x,\
    \ -1); }\n    void reset() { std::fill(std::begin(_par), std::end(_par), -1);\
    \ }\n\n    KYOPRO_BASE_UINT size() const noexcept { return static_cast<KYOPRO_BASE_UINT>(_par.size());\
    \ }\n\n    KYOPRO_BASE_INT find(int _x) {\n      int _p = _x;\n      while (_par[_p]\
    \ >= 0) _p = _par[_p];\n      while (_x != _p) {\n        int _tmp = _x;\n   \
    \     _x = _par[_x];\n        _par[_tmp] = _p;\n      }\n      return _p;\n  \
    \  }\n\n    bool merge(int _x, int _y) {\n      _x = find(_x), _y = find(_y);\n\
    \      if (_x == _y) return false;\n      if (_par[_x] > _par[_y]) {\n       \
    \ int _tmp = _x;\n        _x = _y;\n        _y = _tmp;\n      }\n      _par[_x]\
    \ += _par[_y];\n      _par[_y] = _x;\n      return true;\n    }\n\n    bool same(int\
    \ _x, int _y) { return find(_x) == find(_y); }\n\n    KYOPRO_BASE_INT group_size(int\
    \ _x) { return -_par[find(_x)]; }\n\n    std::vector<int> group_members(int _x)\
    \ {\n      _x = find(_x);\n      std::vector<int> _a;\n      for (int _i = 0;\
    \ _i < (int)(size()); ++_i) if (find(_i) == _x) _a.emplace_back(_i);\n      return\
    \ _a;\n    }\n\n    template<class _typeVector = std::vector<KYOPRO_BASE_INT>>\n\
    \    _typeVector roots() const {\n      _typeVector _a;\n      for (int _i = 0;\
    \ _i < (int)(size()); ++_i) if (_par[_i] < 0) _a.emplace_back(_i);\n      return\
    \ _a;\n    }\n\n    KYOPRO_BASE_INT group_count() const {\n      KYOPRO_BASE_INT\
    \ _cnt = 0;\n      for (int _i = 0; _i < (int)(size()); ++_i) if (_par[_i] < 0)\
    \ ++_cnt;\n      return _cnt;\n    }\n\n    template<class _typeMap = std::unordered_map<KYOPRO_BASE_INT,\
    \ std::vector<KYOPRO_BASE_INT>>>\n    _typeMap all_group_members() {\n      _typeMap\
    \ _group_members;\n      for (int _member = 0; _member < (int)(size()); ++_member)\
    \ _group_members[find(_member)].emplace_back(_member);\n      return _group_members;\n\
    \    }\n  };\n}\n#line 4 \"structure/all.hpp\"\n"
  code: '#pragma once

    #include "FenwickTree.hpp"

    #include "UnionFind.hpp"'
  dependsOn:
  - structure/FenwickTree.hpp
  - base/settings.hpp
  - math/monoid.hpp
  - base/constant.hpp
  - math/power.hpp
  - structure/UnionFind.hpp
  isVerificationFile: false
  path: structure/all.hpp
  requiredBy:
  - all.hpp
  timestamp: '2022-03-12 18:14:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/all.hpp
layout: document
redirect_from:
- /library/structure/all.hpp
- /library/structure/all.hpp.html
title: structure/all.hpp
---
