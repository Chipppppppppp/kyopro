---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: base/Hash.hpp
    title: base/Hash.hpp
  - icon: ':x:'
    path: base/constant.hpp
    title: base/constant.hpp
  - icon: ':x:'
    path: base/settings.hpp
    title: base/settings.hpp
  - icon: ':x:'
    path: base/trait.hpp
    title: base/trait.hpp
  - icon: ':warning:'
    path: math/ModInt.hpp
    title: math/ModInt.hpp
  - icon: ':warning:'
    path: math/div.hpp
    title: math/div.hpp
  - icon: ':warning:'
    path: math/divisors.hpp
    title: math/divisors.hpp
  - icon: ':warning:'
    path: math/euler_phi.hpp
    title: math/euler_phi.hpp
  - icon: ':warning:'
    path: math/factorize.hpp
    title: math/factorize.hpp
  - icon: ':warning:'
    path: math/is_prime.hpp
    title: math/is_prime.hpp
  - icon: ':warning:'
    path: math/mod.hpp
    title: math/mod.hpp
  - icon: ':x:'
    path: math/monoid.hpp
    title: math/monoid.hpp
  - icon: ':x:'
    path: math/power.hpp
    title: math/power.hpp
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
  bundledCode: "#line 2 \"math/div.hpp\"\n#include <type_traits>\n\nnamespace kyopro\
    \ {\n  template<class _typeT, class _typeU>\n  constexpr std::common_type_t<_typeT,\
    \ _typeU> floor_div(_typeT _x, _typeU _m) noexcept {\n    static_assert(std::is_integral_v<_typeT>\
    \ && std::is_integral_v<_typeU>);\n    if constexpr (std::is_unsigned_v<_typeT>\
    \ || std::is_unsigned_v<_typeU>) return _x / _m;\n    auto _d = _x / _m;\n   \
    \ return _d * _m == _x ? _d : _d - ((_x < 0) ^ (_m < 0));\n  }\n\n  template<class\
    \ _typeT, class _typeU>\n  constexpr std::common_type_t<_typeT, _typeU> ceil_div(_typeT\
    \ _x, _typeU _m) noexcept { return floor_div(_x + _m - static_cast<_typeT>(1),\
    \ _m); }\n}\n#line 2 \"math/divisors.hpp\"\n#include <cstdint>\n#include <vector>\n\
    #line 3 \"base/settings.hpp\"\n\n#ifndef KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT\
    \ std::int64_t\n#endif\n\n#ifndef KYOPRO_BASE_UINT\n#define KYOPRO_BASE_UINT std::size_t\n\
    #endif\n\n#ifndef KYOPRO_BASE_FLOAT\n#define KYOPRO_BASE_FLOAT double\n#endif\n\
    \n#ifndef KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD static_cast<KYOPRO_BASE_UINT>(1000000007)\n\
    #endif\n\n#ifndef KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n\
    #endif\n\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 5 \"math/divisors.hpp\"\n\nnamespace kyopro {\n  template<class\
    \ _typeContainer = std::vector<KYOPRO_BASE_INT>>\n  _typeContainer divisors(std::uint_fast64_t\
    \ _n) {\n    _typeContainer _lower, _upper;\n    std::uint_fast64_t _i;\n    for\
    \ (_i = 1; _i * _i < _n; ++_i) if (_n % _i == 0) {\n      _lower.emplace_back(_i);\n\
    \      _upper.emplace_back(_n / _i);\n    }\n    if (_i * _i == _n) _lower.emplace_back(_i);\n\
    \    _lower.insert(end(_lower), rall(_upper));\n    return _lower;\n  }\n}\n#line\
    \ 3 \"math/euler_phi.hpp\"\n\nnamespace kyopro {\n  constexpr std::uint_fast64_t\
    \ euler_phi(std::uint_fast64_t _n) noexcept {\n    std::uint_fast64_t _res = _n;\n\
    \    if ((_n & 1) == 0) {\n      _res -= _res >> 1;\n      _n >>= 1;\n      while\
    \ ((_n & 1) == 0) _n >>= 1;\n    }\n    for (std::uint_fast64_t _i = 3; _i * _i\
    \ <= _n; _i += 2) {\n      if (_n % _i == 0) {\n        _res -= _res / _i;\n \
    \       _n /= _i;\n        while (_n % _i == 0) _n /= _i;\n      }\n    }\n  \
    \  if (_n != 1) _res -= _res / _n;\n    return _res;\n  }\n}\n#line 3 \"math/factorize.hpp\"\
    \n#include <utility>\n#line 6 \"math/factorize.hpp\"\n\nnamespace kyopro {\n \
    \ template<class _typeContainer = std::vector<KYOPRO_BASE_INT>>\n  _typeContainer\
    \ factorize(std::uint_fast64_t _n) {\n    _typeContainer _res;\n    while ((_n\
    \ & 1) == 0) {\n      _res.emplace_back(2);\n      _n >>= 1;\n    }\n    for (std::uint_fast64_t\
    \ _i = 3; _i * _i <= _n; _i += 2) while (_n % _i == 0) {\n      _res.emplace_back(2);\n\
    \      _n /= _i;\n    }\n    if (_n != 1) _res.emplace_back(_n);\n    return _res;\n\
    \  }\n}\n#line 3 \"math/is_prime.hpp\"\n\nnamespace kyopro {\n  constexpr bool\
    \ is_prime(std::uint_fast64_t _n) noexcept {\n    if (_n < 2) return false;\n\
    \    if (_n < 4) return true;\n    if ((_n & 1) == 0 || _n % 3 == 0) return false;\n\
    \    for (std::uint_fast64_t _i = 5; _i * _i <= _n; _i += 4) {\n      if (_n %\
    \ _i == 0) return false;\n      if (_n % (_i += 2) == 0) return false;\n    }\n\
    \    return true;\n  }\n}\n#line 2 \"math/mod.hpp\"\n#include <cassert>\n#line\
    \ 4 \"math/mod.hpp\"\n\nnamespace kyopro {\n  template<class _typeT, class _typeU>\n\
    \  constexpr std::common_type_t<_typeT, _typeU> floor_mod(_typeT _x, _typeU _m)\
    \ noexcept {\n    static_assert(std::is_integral_v<_typeT> && std::is_integral_v<_typeU>);\n\
    \    if constexpr (std::is_unsigned_v<_typeT> || std::is_unsigned_v<_typeU>) return\
    \ _x % _m;\n    return (_x %= _m) < 0 ? _x + _m : _x;\n  }\n\n  template<class\
    \ _typeT, class _typeU>\n  constexpr std::common_type_t<_typeT, _typeU> ceil_mod(_typeT\
    \ _x, _typeU _m) noexcept {\n    return _m - floor_mod(_x - 1, _m) - static_cast<_typeT>(1);\n\
    \  }\n}\n#line 2 \"base/constant.hpp\"\n#include <array>\n#line 4 \"base/constant.hpp\"\
    \n#include <limits>\n#line 4 \"math/power.hpp\"\nnamespace kyopro {\n  template<class\
    \ _typeT>\n  constexpr _typeT power(_typeT _a, std::uint_fast64_t _n, _typeT _init\
    \ = 1) noexcept {\n    while (_n > 0) {\n      if (_n & 1) _init *= _a;\n    \
    \  _a *= _a;\n      _n >>= 1;\n    }\n    return _init;\n  }\n}\n#line 8 \"base/constant.hpp\"\
    \n\nnamespace kyopro {\n  template<class _typeT>\n  inline constexpr _typeT MOD\
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
    \ -1}, {0, -1}, {1, -1}}};\n}\n#line 2 \"base/Hash.hpp\"\n#include <cstddef>\n\
    #include <functional>\n#include <initializer_list>\n#include <tuple>\n#line 2\
    \ \"base/trait.hpp\"\n#include <iterator>\n#include <queue>\n#include <stack>\n\
    #line 7 \"base/trait.hpp\"\n\n#ifdef __SIZEOF_INT128__\ntemplate<>\nstruct std::is_integral<__int128_t>:\
    \ std::true_type {};\ntemplate<>\nstruct std::is_signed<__int128_t>: std::true_type\
    \ {};\ntemplate<>\nstruct std::is_integral<__uint128_t>: std::true_type {};\n\
    template<>\nstruct std::is_unsigned<__uint128_t>: std::true_type {};\n#endif\n\
    #ifdef __SIZEOF_FLOAT128__\ntemplate<>\nstruct std::is_floating_point<__float128>:\
    \ std::true_type {};\n#endif\n\nnamespace kyopro {\n  template<class, class =\
    \ void>\n  struct is_iterator: std::false_type {};\n  template<class _typeT>\n\
    \  struct is_iterator<_typeT, std::void_t<typename std::iterator_traits<_typeT>::iterator_category>>:\
    \ std::true_type {};\n  template<class _typeT>\n  constexpr bool is_iterator_v\
    \ = is_iterator<_typeT>::value;\n\n  template<class, class = void>\n  struct is_iterable:\
    \ std::false_type {};\n  template<class _typeT>\n  struct is_iterable<_typeT,\
    \ std::void_t<typename _typeT::iterator>>: std::true_type {};\n  template<class\
    \ _typeT>\n  constexpr bool is_iterable_v = is_iterable<_typeT>::value;\n\n  template<class>\n\
    \  struct is_tuple: std::false_type {};\n  template<class _typeT, class U>\n \
    \ struct is_tuple<std::pair<_typeT, U>>: std::true_type {};\n  template<class...\
    \ Args>\n  struct is_tuple<std::tuple<Args...>>: std::true_type {};\n  template<class\
    \ _typeT>\n  constexpr bool is_tuple_v = is_tuple<_typeT>::value;\n\n  template<class,\
    \ class = void>\n  struct is_container_adapter: std::false_type {};\n  template<class\
    \ _typeT>\n  struct is_container_adapter<_typeT, std::void_t<decltype(std::empty(std::declval<_typeT>()))>>:\
    \ std::negation<is_iterable<_typeT>> {};\n  template<class _typeT>\n  constexpr\
    \ bool is_container_adapter_v = is_container_adapter<_typeT>::value;\n}\n#line\
    \ 10 \"base/Hash.hpp\"\n\nnamespace kyopro {\n  template<class, class = void>\n\
    \  struct Hash;\n\n  template<class _typeT>\n  struct Hash<_typeT, std::enable_if_t<std::is_scalar_v<_typeT>>>\
    \ {\n  private:\n    [[no_unique_address]] std::hash<_typeT> _hashser;\n\n  public:\n\
    \    constexpr KYOPRO_BASE_UINT operator ()(_typeT a) const noexcept {\n     \
    \ return _hasher(a);\n    }\n  };\n\n  template<class _typeT>\n  struct Hash<_typeT,\
    \ std::enable_if_t<is_tuple_v<_typeT>>> {\n    template<KYOPRO_BASE_UINT _i =\
    \ 0>\n    constexpr KYOPRO_BASE_UINT operator ()(const _typeT& _a) const noexcept\
    \ {\n      if constexpr (_i == std::tuple_size_v<_typeT>) return std::tuple_size_v<_typeT>;\n\
    \      else {\n        KYOPRO_BASE_UINT _seed = operator()<_i + 1>(_a);\n    \
    \    return _seed ^ (Hash<std::tuple_element_t<_i, _typeT>>()(get<_i>(_a)) + 0x9e3779b97f4a7c15LU\
    \ + (_seed << 12) + (_seed >> 4));\n      }\n    }\n  };\n\n  template<class _typeT>\n\
    \  struct Hash<_typeT, std::enable_if_t<is_iterable_v<_typeT>>> {\n  private:\n\
    \    [[no_unique_address]] Hash<decltype(*std::begin(std::declval<_typeT>()))>\
    \ _hasher;\n\n  public:\n    constexpr KYOPRO_BASE_UINT operator ()(const _typeT&\
    \ _a) const noexcept {\n      KYOPRO_BASE_UINT _seed = _a.size();\n      for (auto&\
    \ _i: _a) _seed ^= _hasher(_i) + 0x9e3779b97f4a7c15LU + (_seed << 12) + (_seed\
    \ >> 4);\n      return _seed;\n    }\n  };\n}\n#line 9 \"math/ModInt.hpp\"\n\n\
    namespace kyopro {\n  template<std::uint_fast64_t _m>\n  struct ModInt {\n   \
    \ static constexpr KYOPRO_BASE_INT mod = _m;\n    std::uint_fast64_t value;\n\n\
    \    constexpr ModInt() noexcept = default;\n    template<class T>\n    constexpr\
    \ ModInt(T value) noexcept: value(floor_mod(value, _m)) { static_assert(std::is_integral_v<T>);\
    \ }\n\n    template<class T>\n    explicit constexpr operator T() const noexcept\
    \ { return value; }\n\n    static constexpr ModInt raw(std::uint_fast64_t _n)\
    \ noexcept {\n      ModInt _res;\n      _res.value = _n;\n      return _res;\n\
    \    }\n\n    constexpr ModInt power(std::uint_fast64_t _n) const noexcept {\n\
    \      std::uint_fast64_t _res = 1, _a = value;\n      while (_n > 0) {\n    \
    \    if (_n & 1) _res = _res * _a % _m;\n        _a = _a * _a % _m;\n        _n\
    \ >>= 1;\n      }\n      return _res;\n    }\n\n    constexpr ModInt inv() const\
    \ noexcept {\n      std::uint_fast64_t _a = value, _b = _m;\n      std::int64_t\
    \ _u = 1, _v = 0;\n      while (_b > 0) {\n        std::uint_fast64_t _t = _a\
    \ / _b;\n        _a -= _t * _b;\n        std::swap(_a, _b);\n        _u -= _t\
    \ * _v;\n        std::swap(_u, _v);\n      }\n      return floor_mod(_u, _m);\n\
    \    }\n\n    constexpr ModInt operator +() const noexcept { return *this; }\n\
    \n    constexpr ModInt operator -() const noexcept { return _m - value; }\n\n\
    \    constexpr ModInt& operator ++() noexcept {\n      if (++value >= _m) value\
    \ -= _m;\n      return *this;\n    }\n\n    constexpr ModInt operator ++(int)\
    \ noexcept {\n      ModInt _before = *this;\n      operator ++();\n      return\
    \ _before;\n    }\n\n    constexpr ModInt& operator --() noexcept {\n      if\
    \ (value == 0) value = _m;\n      --value;\n      return *this;\n    }\n\n   \
    \ constexpr ModInt operator --(int) noexcept {\n      ModInt _before = *this;\n\
    \      operator --();\n      return _before;\n    }\n\n    constexpr ModInt& operator\
    \ +=(ModInt _rhs) noexcept {\n      if ((value += _rhs.value) >= _m) value -=\
    \ _m;\n      return *this;\n    }\n\n    constexpr ModInt& operator -=(ModInt\
    \ _rhs) noexcept {\n      if (value < _rhs.value) value += _m;\n      value -=\
    \ _rhs.value;\n      return *this;\n    }\n\n    constexpr ModInt& operator *=(ModInt\
    \ _rhs) noexcept {\n      value = value * _rhs.value % _m;\n      return *this;\n\
    \    }\n\n    constexpr ModInt& operator /=(ModInt _rhs) noexcept {\n      value\
    \ = value * _rhs.inv().value % _m;\n      return *this;\n    }\n\n    friend constexpr\
    \ ModInt operator +(ModInt _lhs, ModInt _rhs) noexcept { return _lhs += _rhs;\
    \ }\n\n    friend constexpr ModInt operator -(ModInt _lhs, ModInt _rhs) noexcept\
    \ { return _lhs -= _rhs; }\n\n    friend constexpr ModInt operator *(ModInt _lhs,\
    \ ModInt _rhs) noexcept { return _lhs *= _rhs; }\n\n    friend constexpr ModInt\
    \ operator /(ModInt _lhs, ModInt _rhs) noexcept { return _lhs /= _rhs; }\n\n \
    \   friend constexpr bool operator ==(ModInt _lhs, ModInt _rhs) noexcept { return\
    \ _lhs.value == _rhs.value; }\n\n    friend constexpr bool operator !=(ModInt\
    \ _lhs, ModInt _rhs) noexcept { return _lhs.value != _rhs.value; }\n\n    template<class\
    \ _typePrinter>\n    void print(_typePrinter& _printer) {\n      _printer.print(value);\n\
    \    }\n  };\n\n  template<KYOPRO_BASE_UINT _m>\n  struct Hash<ModInt<_m>> { constexpr\
    \ KYOPRO_BASE_UINT operator ()(ModInt<_m> _a) const noexcept { return _a; } };\n\
    }\n#line 4 \"math/monoid.hpp\"\n\nnamespace kyopro {\n  template<class _typeT,\
    \ _typeT _id = 0>\n  struct Plus {\n    static constexpr _typeT id = _id;\n  \
    \  static constexpr _typeT op(_typeT _a, _typeT _b) noexcept { return _a + _b;\
    \ }\n    static constexpr _typeT inv(_typeT _a) noexcept { return -_a; }\n  };\n\
    \  template<class _typeT, _typeT _id = 1>\n  struct Mul {\n    static constexpr\
    \ _typeT id = _id;\n    static constexpr _typeT op(_typeT _a, _typeT _b) noexcept\
    \ { return _a * _b; }\n    static constexpr _typeT inv(_typeT _a) noexcept {\n\
    \      static_assert(!std::is_integral_v<_typeT>);\n      return 1 / _a;\n   \
    \ }\n  };\n  template<class _typeT, _typeT _id = -inf>\n  struct Max {\n    static\
    \ constexpr _typeT id = _id;\n    static constexpr _typeT op(_typeT _a, _typeT\
    \ _b) noexcept { return _a > _b ? _a : _b; }\n  };\n  template<class _typeT, _typeT\
    \ _id = inf>\n  struct Min {\n    static constexpr _typeT id = _id;\n    static\
    \ constexpr _typeT op(_typeT _a, _typeT _b) noexcept { return _a < _b ? _a : _b;\
    \ }\n  };\n}\n#line 11 \"math/all.hpp\"\n"
  code: '#pragma once

    #include "div.hpp"

    #include "divisors.hpp"

    #include "euler_phi.hpp"

    #include "factorize.hpp"

    #include "is_prime.hpp"

    #include "mod.hpp"

    #include "ModInt.hpp"

    #include "monoid.hpp"

    #include "power.hpp"'
  dependsOn:
  - math/div.hpp
  - math/divisors.hpp
  - base/settings.hpp
  - math/euler_phi.hpp
  - math/factorize.hpp
  - math/is_prime.hpp
  - math/mod.hpp
  - math/ModInt.hpp
  - base/constant.hpp
  - math/power.hpp
  - base/Hash.hpp
  - base/trait.hpp
  - math/monoid.hpp
  isVerificationFile: false
  path: math/all.hpp
  requiredBy:
  - all.hpp
  timestamp: '2022-03-07 13:04:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/all.hpp
layout: document
redirect_from:
- /library/math/all.hpp
- /library/math/all.hpp.html
title: math/all.hpp
---
