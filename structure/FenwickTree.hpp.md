---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base/constant.hpp
    title: base/constant.hpp
  - icon: ':heavy_check_mark:'
    path: base/settings.hpp
    title: base/settings.hpp
  - icon: ':heavy_check_mark:'
    path: math/monoid.hpp
    title: math/monoid.hpp
  - icon: ':heavy_check_mark:'
    path: math/power.hpp
    title: math/power.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  - icon: ':warning:'
    path: structure/all.hpp
    title: structure/all.hpp
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
    \ <vector>\n#include <utility>\n#line 2 \"base/settings.hpp\"\n#include <cstdint>\n\
    \n#ifndef KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT std::int64_t\n#endif\n#ifndef\
    \ KYOPRO_BASE_UINT\n#define KYOPRO_BASE_UINT std::size_t\n#endif\n#ifndef KYOPRO_BASE_FLOAT\n\
    #define KYOPRO_BASE_FLOAT double\n#endif\n#ifndef KYOPRO_DEFAULT_MOD\n#define\
    \ KYOPRO_DEFAULT_MOD 1000000007\n#endif\n#ifndef KYOPRO_DECIMAL_PRECISION\n#define\
    \ KYOPRO_DECIMAL_PRECISION 12\n#endif\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV\
    \ 3\n#endif\n#line 2 \"math/monoid.hpp\"\n#include <type_traits>\n#line 3 \"base/constant.hpp\"\
    \n#include <limits>\n#include <array>\n#line 4 \"math/power.hpp\"\nnamespace kyopro\
    \ {\n  template<class _typeT>\n  constexpr _typeT power(_typeT a, std::uint64_t\
    \ n, _typeT init = 1) noexcept {\n    while (n > 0) {\n      if (n & 1) init *=\
    \ a;\n      a *= a;\n      n >>= 1;\n    }\n    return init;\n  }\n}\n#line 8\
    \ \"base/constant.hpp\"\n\nnamespace kyopro {\n  inline constexpr std::uint64_t\
    \ _decimal_max = power(static_cast<std::uint64_t>(10), KYOPRO_DECIMAL_PRECISION);\n\
    \  template<class _typeT>\n  inline constexpr _typeT MOD = KYOPRO_DEFAULT_MOD;\n\
    \  inline constexpr KYOPRO_BASE_INT mod = MOD<KYOPRO_BASE_INT>;\n  template<class\
    \ _typeT>\n  inline constexpr _typeT INF = std::numeric_limits<_typeT>::max()\
    \ / KYOPRO_INF_DIV;\n  inline constexpr KYOPRO_BASE_INT inf = INF<KYOPRO_BASE_INT>;\n\
    \  template<class _typeT>\n  inline constexpr KYOPRO_BASE_FLOAT EPS = static_cast<_typeT>(1)\
    \ / _decimal_max;\n  inline constexpr KYOPRO_BASE_FLOAT eps = EPS<KYOPRO_BASE_FLOAT>;\n\
    \  template<class _typeT>\n  inline constexpr _typeT PI = 3.14159265358979323846;\n\
    \  inline constexpr KYOPRO_BASE_FLOAT pi = PI<KYOPRO_BASE_FLOAT>;\n  inline constexpr\
    \ std::array<std::pair<KYOPRO_BASE_INT, KYOPRO_BASE_INT>, 4> beside{{{1, 0}, {0,\
    \ 1}, {-1, 0}, {0, -1}}};\n  inline constexpr std::array<std::pair<KYOPRO_BASE_INT,\
    \ KYOPRO_BASE_INT>, 8> around{{{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1,\
    \ -1}, {0, -1}, {1, -1}}};\n}\n#line 4 \"math/monoid.hpp\"\n\nnamespace kyopro\
    \ {\n  template<class _typeT, _typeT _id = 0>\n  struct Plus {\n    static constexpr\
    \ _typeT id = _id;\n    static constexpr _typeT op(_typeT _a, _typeT _b) noexcept\
    \ { return _a + _b; }\n    static constexpr _typeT inv(_typeT _a) noexcept { return\
    \ -_a; }\n  };\n  template<class _typeT, _typeT _id = 1>\n  struct Mul {\n   \
    \ static constexpr _typeT id = _id;\n    static constexpr _typeT op(_typeT _a,\
    \ _typeT _b) noexcept { return _a * _b; }\n    static constexpr _typeT inv(_typeT\
    \ _a) noexcept {\n      static_assert(!std::is_integral_v<_typeT>);\n      return\
    \ 1 / _a;\n    }\n  };\n  template<class _typeT, _typeT _id = -inf>\n  struct\
    \ Max {\n    static constexpr _typeT id = _id;\n    static constexpr _typeT op(_typeT\
    \ _a, _typeT _b) noexcept { return _a > _b ? _a : _b; }\n  };\n  template<class\
    \ _typeT, _typeT _id = inf>\n  struct Min {\n    static constexpr _typeT id =\
    \ _id;\n    static constexpr _typeT op(_typeT _a, _typeT _b) noexcept { return\
    \ _a < _b ? _a : _b; }\n  };\n}\n#line 7 \"structure/FenwickTree.hpp\"\n\nnamespace\
    \ kyopro {\n  template<class _typeT, class _typeOp = Plus<_typeT>, class _typeContainer\
    \ = std::vector<_typeT>>\n  struct FenwickTree {\n  private:\n    _typeContainer\
    \ _tree;\n  public:\n    using value_type = _typeT;\n    using size_type = KYOPRO_BASE_UINT;\n\
    \    using reference = _typeT&;\n    using const_reference = const _typeT&;\n\
    \    FenwickTree() noexcept = default;\n    FenwickTree(KYOPRO_BASE_UINT _n) noexcept:\
    \ _tree(_n, _typeOp::id) {}\n    KYOPRO_BASE_UINT size() noexcept { return _tree.size();\
    \ }\n    void apply(int _p, const _typeT& _x) {\n      ++_p;\n      while (_p\
    \ <= (int)size()) {\n        _tree[_p - 1] = _typeOp::op(_tree[_p - 1], _x);\n\
    \        _p += _p & -_p;\n      }\n    }\n    _typeT prod(int _r) const {\n  \
    \    _typeT _s = _typeOp::id;\n      while (_r > 0) {\n        _s = _typeOp::op(_s,\
    \ _tree[_r - 1]);\n        _r -= _r & -_r;\n      }\n      return _s;\n    }\n\
    \    _typeT prod(int _l, int _r) const { return _typeOp::op(prod(_r), _typeOp::inv(prod(_l)));\
    \ }\n    _typeT get(int _p) { return _typeOp::op(prod(_p + 1), _typeOp::inv(prod(_p)));\
    \ }\n    _typeT all_query() { return prod(_tree.size()); }\n    void set(int _p,\
    \ const _typeT& _x) { apply(_p, _typeOp::op(_x, _typeOp::inv(get(_p)))); }\n \
    \ };\n}\n"
  code: "#pragma once\n/* FenwickTree */\n#include <vector>\n#include <utility>\n\
    #include \"../base/settings.hpp\"\n#include \"../math/monoid.hpp\"\n\nnamespace\
    \ kyopro {\n  template<class _typeT, class _typeOp = Plus<_typeT>, class _typeContainer\
    \ = std::vector<_typeT>>\n  struct FenwickTree {\n  private:\n    _typeContainer\
    \ _tree;\n  public:\n    using value_type = _typeT;\n    using size_type = KYOPRO_BASE_UINT;\n\
    \    using reference = _typeT&;\n    using const_reference = const _typeT&;\n\
    \    FenwickTree() noexcept = default;\n    FenwickTree(KYOPRO_BASE_UINT _n) noexcept:\
    \ _tree(_n, _typeOp::id) {}\n    KYOPRO_BASE_UINT size() noexcept { return _tree.size();\
    \ }\n    void apply(int _p, const _typeT& _x) {\n      ++_p;\n      while (_p\
    \ <= (int)size()) {\n        _tree[_p - 1] = _typeOp::op(_tree[_p - 1], _x);\n\
    \        _p += _p & -_p;\n      }\n    }\n    _typeT prod(int _r) const {\n  \
    \    _typeT _s = _typeOp::id;\n      while (_r > 0) {\n        _s = _typeOp::op(_s,\
    \ _tree[_r - 1]);\n        _r -= _r & -_r;\n      }\n      return _s;\n    }\n\
    \    _typeT prod(int _l, int _r) const { return _typeOp::op(prod(_r), _typeOp::inv(prod(_l)));\
    \ }\n    _typeT get(int _p) { return _typeOp::op(prod(_p + 1), _typeOp::inv(prod(_p)));\
    \ }\n    _typeT all_query() { return prod(_tree.size()); }\n    void set(int _p,\
    \ const _typeT& _x) { apply(_p, _typeOp::op(_x, _typeOp::inv(get(_p)))); }\n \
    \ };\n}\n"
  dependsOn:
  - base/settings.hpp
  - math/monoid.hpp
  - base/constant.hpp
  - math/power.hpp
  isVerificationFile: false
  path: structure/FenwickTree.hpp
  requiredBy:
  - structure/all.hpp
  - all.hpp
  timestamp: '2022-01-11 23:13:11+09:00'
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
