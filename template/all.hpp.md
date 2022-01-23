---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: base/Hash.hpp
    title: base/Hash.hpp
  - icon: ':heavy_check_mark:'
    path: base/constant.hpp
    title: base/constant.hpp
  - icon: ':heavy_check_mark:'
    path: base/settings.hpp
    title: base/settings.hpp
  - icon: ':warning:'
    path: base/trait.hpp
    title: base/trait.hpp
  - icon: ':warning:'
    path: math/ModInt.hpp
    title: math/ModInt.hpp
  - icon: ':warning:'
    path: math/mod.hpp
    title: math/mod.hpp
  - icon: ':heavy_check_mark:'
    path: math/power.hpp
    title: math/power.hpp
  - icon: ':warning:'
    path: template/alias.hpp
    title: template/alias.hpp
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
  bundledCode: "#line 2 \"template/alias.hpp\"\n#include <cstdint>\n#include <limits>\n\
    #include <functional>\n#include <utility>\n#include <vector>\n#include <string>\n\
    #include <set>\n#include <map>\n#include <unordered_set>\n#include <unordered_map>\n\
    #include <queue>\n#include <stack>\n#line 2 \"base/Hash.hpp\"\n#include <cstddef>\n\
    #include <type_traits>\n#include <tuple>\n#line 3 \"base/settings.hpp\"\n\n#ifndef\
    \ KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT std::int64_t\n#endif\n\n#ifndef KYOPRO_BASE_UINT\n\
    #define KYOPRO_BASE_UINT std::size_t\n#endif\n\n#ifndef KYOPRO_BASE_FLOAT\n#define\
    \ KYOPRO_BASE_FLOAT double\n#endif\n\n#ifndef KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD\
    \ static_cast<KYOPRO_BASE_UINT>(1000000007)\n#endif\n\n#ifndef KYOPRO_DECIMAL_PRECISION\n\
    #define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n#endif\n\n\
    #ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 4 \"base/trait.hpp\"\n#include <iterator>\n#line 7 \"base/trait.hpp\"\
    \n\n#ifdef __SIZEOF_INT128__\ntemplate<>\nstruct std::is_integral<__int128_t>:\
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
    \ 7 \"base/Hash.hpp\"\n\nnamespace kyopro {\n  template<class, class = void>\n\
    \  struct Hash;\n\n  template<class _typeT>\n  struct Hash<_typeT, std::enable_if_t<std::is_integral_v<_typeT>>>\
    \ { constexpr KYOPRO_BASE_UINT operator ()(_typeT _a) const noexcept { return\
    \ _a; } };\n\n  template<class _typeT>\n  struct Hash<_typeT, std::enable_if_t<std::is_floating_point_v<_typeT>>>\
    \ { constexpr KYOPRO_BASE_UINT operator ()(_typeT _a) const noexcept { return\
    \ static_cast<KYOPRO_BASE_UINT>(_a) & 0xfffff000; } };\n\n  template<class _typeT>\n\
    \  struct Hash<_typeT*, void> { constexpr KYOPRO_BASE_UINT operator ()(_typeT*\
    \ _a) const noexcept { return reinterpret_cast<KYOPRO_BASE_UINT>(_a); } };\n\n\
    \  template<>\n  struct Hash<std::nullptr_t, void> { constexpr KYOPRO_BASE_UINT\
    \ operator ()(std::nullptr_t) const noexcept { return 0; } };\n\n  template<class\
    \ _typeT>\n  struct Hash<_typeT, std::enable_if_t<is_tuple_v<_typeT>>> {\n   \
    \ template<KYOPRO_BASE_UINT _i = 0>\n    constexpr KYOPRO_BASE_UINT operator ()(const\
    \ _typeT& _a) const noexcept {\n      if constexpr (_i == std::tuple_size_v<_typeT>)\
    \ return std::tuple_size_v<_typeT>;\n      else {\n        KYOPRO_BASE_UINT _seed\
    \ = operator()<_i + 1>(_a);\n        return _seed ^ (Hash<std::tuple_element_t<_i,\
    \ _typeT>>()(get<_i>(_a)) + 0x9e3779b97f4a7c15LU + (_seed << 12) + (_seed >> 4));\n\
    \      }\n    }\n  };\n\n  template<class _typeT>\n  struct Hash<_typeT, std::enable_if_t<is_iterable_v<_typeT>>>\
    \ {\n  private:\n    [[no_unique_address]] Hash<typename _typeT::value_type> make_hash;\n\
    \  public:\n    constexpr KYOPRO_BASE_UINT operator ()(const _typeT& _a) const\
    \ noexcept {\n      KYOPRO_BASE_UINT _seed = _a.size();\n      for (auto& _i:\
    \ _a) _seed ^= make_hash(_i) + 0x9e3779b97f4a7c15LU + (_seed << 12) + (_seed >>\
    \ 4);\n      return _seed;\n    }\n  };\n}\n#line 4 \"math/ModInt.hpp\"\n#include\
    \ <cassert>\n#line 4 \"base/constant.hpp\"\n#include <array>\n#line 4 \"math/power.hpp\"\
    \nnamespace kyopro {\n  template<class _typeT>\n  constexpr _typeT power(_typeT\
    \ _a, std::uint_fast64_t _n, _typeT _init = 1) noexcept {\n    while (_n > 0)\
    \ {\n      if (_n & 1) _init *= _a;\n      _a *= _a;\n      _n >>= 1;\n    }\n\
    \    return _init;\n  }\n}\n#line 8 \"base/constant.hpp\"\n\nnamespace kyopro\
    \ {\n  inline constexpr std::uint_fast64_t _decimal_max = power(static_cast<std::uint_fast64_t>(10),\
    \ KYOPRO_DECIMAL_PRECISION);\n\n  template<class _typeT>\n  inline constexpr _typeT\
    \ MOD = KYOPRO_DEFAULT_MOD;\n  inline constexpr KYOPRO_BASE_INT mod = MOD<KYOPRO_BASE_INT>;\n\
    \n  template<class _typeT>\n  inline constexpr _typeT INF = std::numeric_limits<_typeT>::max()\
    \ / KYOPRO_INF_DIV;\n  inline constexpr KYOPRO_BASE_INT inf = INF<KYOPRO_BASE_INT>;\n\
    \n  template<class _typeT>\n  inline constexpr KYOPRO_BASE_FLOAT EPS = static_cast<_typeT>(1)\
    \ / _decimal_max;\n  inline constexpr KYOPRO_BASE_FLOAT eps = EPS<KYOPRO_BASE_FLOAT>;\n\
    \n  template<class _typeT>\n  inline constexpr _typeT PI = 3.14159265358979323846;\n\
    \  inline constexpr KYOPRO_BASE_FLOAT pi = PI<KYOPRO_BASE_FLOAT>;\n\n  inline\
    \ constexpr std::array<std::pair<KYOPRO_BASE_INT, KYOPRO_BASE_INT>, 4> beside{{{1,\
    \ 0}, {0, 1}, {-1, 0}, {0, -1}}};\n  inline constexpr std::array<std::pair<KYOPRO_BASE_INT,\
    \ KYOPRO_BASE_INT>, 8> around{{{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1,\
    \ -1}, {0, -1}, {1, -1}}};\n}\n#line 4 \"math/mod.hpp\"\n\nnamespace kyopro {\n\
    \  template<class _typeT, class _typeU>\n  constexpr _typeT floor_mod(_typeT _x,\
    \ _typeU _m) noexcept {\n    static_assert(std::is_integral_v<_typeT> && std::is_integral_v<_typeU>);\n\
    \    if constexpr (std::is_unsigned_v<_typeT>) return _x % _m;\n    return (_x\
    \ %= _m) < 0 ? _x + _m : _x;\n  }\n\n  template<class _typeT, class _typeU>\n\
    \  constexpr _typeT ceil_mod(_typeT _x, _typeU _m) noexcept { return _m - floor_mod(_x\
    \ - 1, _m) - 1; }\n}\n#line 9 \"math/ModInt.hpp\"\n\nnamespace kyopro {\n  template<std::uint_fast64_t\
    \ _m>\n  struct ModInt {\n    static constexpr KYOPRO_BASE_INT mod = _m;\n   \
    \ std::uint_fast64_t _value;\n\n    constexpr ModInt() noexcept = default;\n \
    \   template<class T>\n    constexpr ModInt(T _value) noexcept: _value(floor_mod(_value,\
    \ _m)) { static_assert(std::is_integral_v<T>); }\n\n    template<class T>\n  \
    \  explicit constexpr operator T() const noexcept { return _value; }\n\n    static\
    \ constexpr ModInt raw(std::uint_fast64_t _n) noexcept {\n      ModInt _res;\n\
    \      _res._value = _n;\n      return _res;\n    }\n\n    constexpr ModInt power(std::uint_fast64_t\
    \ _n) const noexcept {\n      std::uint_fast64_t _res = 1, _a = _value;\n    \
    \  while (_n > 0) {\n        if (_n & 1) _res = _res * _a % _m;\n        _a =\
    \ _a * _a % _m;\n        _n >>= 1;\n      }\n      return _res;\n    }\n\n   \
    \ constexpr ModInt inv() const noexcept {\n      std::uint_fast64_t _a = _value,\
    \ _b = _m;\n      std::int64_t _u = 1, _v = 0;\n      while (_b > 0) {\n     \
    \   std::uint_fast64_t _t = _a / _b;\n        _a -= _t * _b;\n        std::swap(_a,\
    \ _b);\n        _u -= _t * _v;\n        std::swap(_u, _v);\n      }\n      return\
    \ floor_mod(_u, _m);\n    }\n\n    constexpr ModInt operator +() const noexcept\
    \ { return *this; }\n    constexpr ModInt operator -() const noexcept { return\
    \ _m - _value; }\n\n    constexpr ModInt& operator ++() noexcept {\n      if (++_value\
    \ >= _m) _value -= _m;\n      return *this;\n    }\n    constexpr ModInt operator\
    \ ++(int) noexcept {\n      ModInt _before = *this;\n      operator ++();\n  \
    \    return _before;\n    }\n    constexpr ModInt& operator --() noexcept {\n\
    \      if (_value == 0) _value = _m;\n      --_value;\n      return *this;\n \
    \   }\n    constexpr ModInt operator --(int) noexcept {\n      ModInt _before\
    \ = *this;\n      operator --();\n      return _before;\n    }\n\n    constexpr\
    \ ModInt& operator +=(ModInt _rhs) noexcept {\n      if ((_value += _rhs._value)\
    \ >= _m) _value -= _m;\n      return *this;\n    }\n    constexpr ModInt& operator\
    \ -=(ModInt _rhs) noexcept {\n      if (_value < _rhs._value) _value += _m;\n\
    \      _value -= _rhs._value;\n      return *this;\n    }\n    constexpr ModInt&\
    \ operator *=(ModInt _rhs) noexcept {\n      _value = _value * _rhs._value % _m;\n\
    \      return *this;\n    }\n    constexpr ModInt& operator /=(ModInt _rhs) noexcept\
    \ {\n      _value = _value * _rhs.inv()._value % _m;\n      return *this;\n  \
    \  }\n\n    friend constexpr ModInt operator +(ModInt _lhs, ModInt _rhs) noexcept\
    \ { return _lhs += _rhs; }\n    friend constexpr ModInt operator -(ModInt _lhs,\
    \ ModInt _rhs) noexcept { return _lhs -= _rhs; }\n    friend constexpr ModInt\
    \ operator *(ModInt _lhs, ModInt _rhs) noexcept { return _lhs *= _rhs; }\n   \
    \ friend constexpr ModInt operator /(ModInt _lhs, ModInt _rhs) noexcept { return\
    \ _lhs /= _rhs; }\n    friend constexpr bool operator ==(ModInt _lhs, ModInt _rhs)\
    \ noexcept { return _lhs._value == _rhs._value; }\n    friend constexpr bool operator\
    \ !=(ModInt _lhs, ModInt _rhs) noexcept { return _lhs._value != _rhs._value; }\n\
    \  };\n\n  template<KYOPRO_BASE_UINT _m>\n  struct Hash<ModInt<_m>> { constexpr\
    \ KYOPRO_BASE_UINT operator ()(ModInt<_m> _a) const noexcept { return _a; } };\n\
    \n  constexpr ModInt<mod> operator \"\" _m(unsigned long long _a) noexcept { return\
    \ _a; }\n}\n#line 16 \"template/alias.hpp\"\n\nnamespace kyopro {\n  using ll\
    \ = int64_t;\n  using ull = uint_fast64_t;\n  using lf = double;\n  #ifdef __SIZEOF_INT128__\n\
    \  using i128 = __int128_t;\n  using u128 = __uint128_t;\n  #endif\n  #ifdef __SIZEOF_FLOAT128__\n\
    \  using f128 = __float128;\n  #endif\n\n  template<class _typeT>\n  using vec\
    \ = std::vector<_typeT>;\n  using str = std::string;\n  template<class Key>\n\
    \  using hash_set = std::unordered_set<Key, Hash<Key>>;\n  template<class Key,\
    \ class _typeT>\n  using hash_map = std::unordered_map<Key, _typeT, Hash<Key>>;\n\
    \  template<class Key>\n  using hash_multiset = std::unordered_multiset<Key, Hash<Key>>;\n\
    \  template<class Key, class _typeT>\n  using hash_multimap = std::unordered_multimap<Key,\
    \ _typeT, Hash<Key>>;\n  template<class _typeT, class Compare = std::less<_typeT>,\
    \ class Container = vec<_typeT>>\n  using priq = std::priority_queue<_typeT, Container,\
    \ Compare>;\n  template<class _typeT, class Compare = std::greater<_typeT>, class\
    \ Container = vec<_typeT>>\n  using heapq = priq<_typeT, Container, Compare>;\n\
    \n  using pll = std::pair<ll, ll>;\n  using l3 = std::tuple<ll, ll, ll>;\n  using\
    \ l4 = std::tuple<ll, ll, ll, ll>;\n  using l5 = std::tuple<ll, ll, ll, ll, ll>;\n\
    \  using mll = std::map<ll, ll>;\n  using hmll = hash_map<ll, ll>;\n  using mmll\
    \ = std::multimap<ll, ll>;\n  using hmmll = std::multimap<ll, ll>;\n  using sl\
    \ = std::set<ll>;\n  using spll = std::set<pll>;\n  using hsl = hash_set<ll>;\n\
    \  using hspll = hash_set<pll>;\n  using msl = std::multiset<ll>;\n  using mspll\
    \ = std::multiset<pll>;\n  using hmsl = hash_multiset<ll>;\n  using hmspll = hash_multiset<pll>;\n\
    \  using dql = std::deque<ll>;\n  using dqpll = std::deque<pll>;\n  using quel\
    \ = std::queue<ll>;\n  using quepll = std::queue<pll>;\n  using stkl = std::stack<ll>;\n\
    \  using stkpll = std::stack<pll>;\n  using pql = priq<ll>;\n  using pqpll = priq<pll>;\n\
    \  using hql = heapq<ll>;\n  using hqpll = heapq<pll>;\n  using vl = vec<ll>;\n\
    \  using vvl = vec<vl>;\n  using vvvl = vec<vvl>;\n  using vi = vec<int>;\n  using\
    \ vvi = vec<vi>;\n  using vvvi = vec<vvi>;\n  using vf = vec<lf>;\n  using vvf\
    \ = vec<vf>;\n  using vvvf = vec<vvf>;\n  using vb = vec<char>;\n  using vvb =\
    \ vec<vb>;\n  using vvvb = vec<vvb>;\n  using vc = vec<char>;\n  using vvc = vec<vc>;\n\
    \  using vvvc = vec<vvc>;\n  using vs = vec<str>;\n  using vvs = vec<vs>;\n  using\
    \ vvvs = vec<vvs>;\n  using vpll = vec<pll>;\n  using vvpll = vec<vpll>;\n  using\
    \ vvvpll = vec<vvpll>;\n  using vsl = vec<sl>;\n  using vhsl = vec<hsl>;\n  using\
    \ vmll = vec<mll>;\n  using vhmll = vec<hmll>;\n  using mint = ModInt<mod>;\n\
    \  using vm = vec<mint>;\n  using vvm = vec<vm>;\n  using vvvm = vec<vvm>;\n}\n\
    \nusing namespace std;\nusing namespace kyopro;\n#line 3 \"template/all.hpp\"\n"
  code: '#pragma once

    #include "alias.hpp"'
  dependsOn:
  - template/alias.hpp
  - base/Hash.hpp
  - base/settings.hpp
  - base/trait.hpp
  - math/ModInt.hpp
  - base/constant.hpp
  - math/power.hpp
  - math/mod.hpp
  isVerificationFile: false
  path: template/all.hpp
  requiredBy:
  - all.hpp
  timestamp: '2022-01-23 17:04:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/all.hpp
layout: document
redirect_from:
- /library/template/all.hpp
- /library/template/all.hpp.html
title: template/all.hpp
---
