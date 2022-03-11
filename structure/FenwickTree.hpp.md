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
    \ <utility>\n#include <vector>\n#line 2 \"base/settings.hpp\"\n#include <cstdint>\n\
    \n#ifndef KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT std::int64_t\n#endif\n\n#ifndef\
    \ KYOPRO_BASE_UINT\n#define KYOPRO_BASE_UINT std::uint64_t\n#endif\n\n#ifndef\
    \ KYOPRO_BASE_FLOAT\n#define KYOPRO_BASE_FLOAT double\n#endif\n\n#ifndef KYOPRO_DEFAULT_MOD\n\
    #define KYOPRO_DEFAULT_MOD static_cast<KYOPRO_BASE_UINT>(1000000007)\n#endif\n\
    \n#ifndef KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n\
    #endif\n\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 2 \"math/monoid.hpp\"\n#include <type_traits>\n#line 2 \"base/constant.hpp\"\
    \n#include <array>\n#line 4 \"base/constant.hpp\"\n#include <limits>\n#line 4\
    \ \"math/power.hpp\"\n\nnamespace kyopro {\n  template<class _typeT>\n  constexpr\
    \ _typeT power(_typeT _a, std::uint_fast64_t _n, _typeT _init = 1) noexcept {\n\
    \    while (_n > 0) {\n      if (_n & 1) _init *= _a;\n      _a *= _a;\n     \
    \ _n >>= 1;\n    }\n    return _init;\n  }\n}\n#line 8 \"base/constant.hpp\"\n\
    \nnamespace kyopro {\n  template<class _typeT>\n  inline constexpr _typeT MOD\
    \ = KYOPRO_DEFAULT_MOD;\n  inline constexpr KYOPRO_BASE_INT mod = MOD<KYOPRO_BASE_INT>;\n\
    \n  template<class _typeT>\n  inline constexpr _typeT INF = std::numeric_limits<_typeT>::max()\
    \ / KYOPRO_INF_DIV;\n  inline constexpr KYOPRO_BASE_INT inf = INF<KYOPRO_BASE_INT>;\n\
    \n  template<class _typeT, KYOPRO_BASE_UINT _decimal_precision = KYOPRO_DECIMAL_PRECISION>\n\
    \  inline constexpr KYOPRO_BASE_FLOAT EPS = static_cast<_typeT>(1) / power(static_cast<std::uint_fast64_t>(10),\
    \ _decimal_precision);\n  inline constexpr KYOPRO_BASE_FLOAT eps = EPS<KYOPRO_BASE_FLOAT>;\n\
    \n  template<class _typeT>\n  inline constexpr _typeT PI = 3.14159265358979323846;\n\
    \  inline constexpr KYOPRO_BASE_FLOAT pi = PI<KYOPRO_BASE_FLOAT>;\n\n  inline\
    \ constexpr std::array<std::pair<KYOPRO_BASE_INT, KYOPRO_BASE_INT>, 4> beside{{{1,\
    \ 0}, {0, 1}, {-1, 0}, {0, -1}}};\n  inline constexpr std::array<std::pair<KYOPRO_BASE_INT,\
    \ KYOPRO_BASE_INT>, 8> around{{{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1,\
    \ -1}, {0, -1}, {1, -1}}};\n}\n#line 4 \"math/monoid.hpp\"\n\nnamespace kyopro\
    \ {\n  template<class _typeT, _typeT _id = 0>\n  struct Plus {\n    static_assert(std::is_arithmetic_v<_typeT>);\n\
    \    static constexpr _typeT id = _id;\n    constexpr _typeT operator ()(_typeT\
    \ _a, _typeT _b) const noexcept { return _a + _b; }\n    constexpr _typeT inv(_typeT\
    \ _a) const noexcept { return -_a; }\n  };\n  template<class _typeT, _typeT _id\
    \ = 1>\n  struct Mul {\n    static_assert(std::is_arithmetic_v<_typeT>);\n   \
    \ static constexpr _typeT id = _id;\n    constexpr _typeT operator ()(_typeT _a,\
    \ _typeT _b) const noexcept { return _a * _b; }\n    constexpr _typeT inv(_typeT\
    \ _a) const noexcept {\n      static_assert(!std::is_integral_v<_typeT>);\n  \
    \    return 1 / _a;\n    }\n  };\n  template<class _typeT, _typeT _id = std::is_integral_v<_typeT>\
    \ ? -INF<_typeT> : -inf>\n  struct Max {\n    static_assert(std::is_arithmetic_v<_typeT>);\n\
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
    \    KYOPRO_BASE_UINT size() noexcept { return _tree.size(); }\n\n    void apply(int\
    \ _p, const _typeT& _x) {\n      ++_p;\n      while (_p <= (int)size()) {\n  \
    \      _tree[_p - 1] = _op(_tree[_p - 1], _x);\n        _p += _p & -_p;\n    \
    \  }\n    }\n\n    _typeT prod(int _r) const {\n      _typeT _s = _op.id;\n  \
    \    while (_r > 0) {\n        _s = _op(_s, _tree[_r - 1]);\n        _r -= _r\
    \ & -_r;\n      }\n      return _s;\n    }\n    _typeT prod(int _l, int _r) const\
    \ { return _op(prod(_r), _op.inv(prod(_l))); }\n\n    _typeT all_prod() { return\
    \ prod(_tree.size()); }\n\n    _typeT get(int _p) { return _op(prod(_p + 1), _op.inv(prod(_p)));\
    \ }\n\n    void set(int _p, const _typeT& _x) { apply(_p, _op(_x, _op.inv(get(_p))));\
    \ }\n  };\n}\n"
  code: "#pragma once\n/* FenwickTree */\n#include <utility>\n#include <vector>\n\
    #include \"../base/settings.hpp\"\n#include \"../math/monoid.hpp\"\n\nnamespace\
    \ kyopro {\n  template<class _typeT, class _typeOp = Plus<_typeT>>\n  struct FenwickTree\
    \ {\n  private:\n    [[no_unique_address]] _typeOp _op;\n    std::vector<_typeT>\
    \ _tree;\n\n  public:\n    using value_type = _typeT;\n    using size_type = KYOPRO_BASE_UINT;\n\
    \    using reference = _typeT&;\n    using const_reference = const _typeT&;\n\n\
    \    FenwickTree() noexcept = default;\n    FenwickTree(KYOPRO_BASE_UINT _n) noexcept:\
    \ _op(), _tree(_n, _op.id) {}\n\n    KYOPRO_BASE_UINT size() noexcept { return\
    \ _tree.size(); }\n\n    void apply(int _p, const _typeT& _x) {\n      ++_p;\n\
    \      while (_p <= (int)size()) {\n        _tree[_p - 1] = _op(_tree[_p - 1],\
    \ _x);\n        _p += _p & -_p;\n      }\n    }\n\n    _typeT prod(int _r) const\
    \ {\n      _typeT _s = _op.id;\n      while (_r > 0) {\n        _s = _op(_s, _tree[_r\
    \ - 1]);\n        _r -= _r & -_r;\n      }\n      return _s;\n    }\n    _typeT\
    \ prod(int _l, int _r) const { return _op(prod(_r), _op.inv(prod(_l))); }\n\n\
    \    _typeT all_prod() { return prod(_tree.size()); }\n\n    _typeT get(int _p)\
    \ { return _op(prod(_p + 1), _op.inv(prod(_p))); }\n\n    void set(int _p, const\
    \ _typeT& _x) { apply(_p, _op(_x, _op.inv(get(_p)))); }\n  };\n}\n"
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
  timestamp: '2022-03-11 23:13:04+09:00'
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