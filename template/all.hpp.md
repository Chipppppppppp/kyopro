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
    #include <queue>\n#include <stack>\n#line 2 \"base/Hash.hpp\"\n#include <type_traits>\n\
    #include <tuple>\n#line 3 \"base/settings.hpp\"\n\n#ifndef KYOPRO_BASE_INT\n#define\
    \ KYOPRO_BASE_INT std::int64_t\n#endif\n#ifndef KYOPRO_BASE_UINT\n#define KYOPRO_BASE_UINT\
    \ std::size_t\n#endif\n#ifndef KYOPRO_BASE_FLOAT\n#define KYOPRO_BASE_FLOAT double\n\
    #endif\n#ifndef KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD 1000000007\n#endif\n\
    #ifndef KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION 12\n#endif\n\
    #ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV 3\n#endif\n#line 4 \"base/trait.hpp\"\
    \n#include <iterator>\n#line 7 \"base/trait.hpp\"\n\n#ifdef __SIZEOF_INT128__\n\
    struct std::is_integral<__int128_t>: std::true_type {};\nstruct std::is_signed<__int128_t>:\
    \ std::true_type {};\nstruct std::is_integral<__uint128_t>: std::true_type {};\n\
    struct std::is_unsigned<__uint128_t>: std::true_type {};\n#endif\n#ifdef __SIZEOF_FLOAT128__\n\
    struct std::is_floating_point<__float128>: std::true_type {};\n#endif\n\nnamespace\
    \ kyopro {\n  template<class _typeT, class = void>\n  struct is_iterator: std::false_type\
    \ {};\n  template<class _typeT>\n  struct is_iterator<_typeT, std::enable_if_t<!std::is_same_v<typename\
    \ std::iterator_traits<_typeT>::value_type, void>>>: std::true_type {};\n  template<class\
    \ _typeT>\n  constexpr bool is_iterator_v = is_iterator<_typeT>::value;\n\n  template<class\
    \ _typeT, class = void>\n  struct is_container: std::false_type {};\n  template<class\
    \ _typeT>\n  struct is_container<_typeT, std::void_t<decltype(std::begin(std::declval<_typeT>()),\
    \ std::end(std::declval<_typeT>()), std::empty(std::declval<_typeT>()))>>: std::true_type\
    \ {};\n  template<class _typeT>\n  constexpr bool is_container_v = is_container<_typeT>::value;\n\
    \n  template<class _typeT>\n  struct is_tuple: std::false_type {};\n  template<class\
    \ _typeT, class U>\n  struct is_tuple<std::pair<_typeT, U>>: std::true_type {};\n\
    \  template<class... Args>\n  struct is_tuple<std::tuple<Args...>>: std::true_type\
    \ {};\n  template<class _typeT>\n  constexpr bool is_tuple_v = is_tuple<_typeT>::value;\n\
    \n  template<class _typeT>\n  struct is_iterable: is_container<_typeT> {};\n \
    \ template<class _typeT, class Container>\n  struct is_iterable<std::stack<_typeT,\
    \ Container>>: std::false_type {};\n  template<class _typeT, class Container>\n\
    \  struct is_iterable<std::queue<_typeT, Container>>: std::false_type {};\n  template<class\
    \ _typeT, class Container, class Compare>\n  struct is_iterable<std::priority_queue<_typeT,\
    \ Container, Compare>>: std::false_type {};\n  template<class _typeT>\n  constexpr\
    \ bool is_iterable_v = is_iterable<_typeT>::value;\n}\n#line 6 \"base/Hash.hpp\"\
    \n\nnamespace kyopro {\n  template<class, class = void>\n  struct Hash;\n\n  template<class\
    \ _typeT>\n  struct Hash<_typeT, std::enable_if_t<std::is_integral_v<_typeT>>>\
    \ { constexpr KYOPRO_BASE_UINT operator ()(_typeT _a) const noexcept { return\
    \ _a; } };\n\n  template<class _typeT>\n  struct Hash<_typeT, std::enable_if_t<std::is_floating_point_v<_typeT>>>\
    \ { constexpr KYOPRO_BASE_UINT operator ()(_typeT _a) const noexcept { return\
    \ (KYOPRO_BASE_UINT)_a & 0xfffff000; } };\n\n  template<class _typeT>\n  struct\
    \ Hash<_typeT, std::enable_if_t<is_tuple_v<_typeT>>> {\n    template<KYOPRO_BASE_UINT\
    \ _i = 0>\n    constexpr KYOPRO_BASE_UINT operator ()(const _typeT& _a) const\
    \ noexcept {\n      if constexpr (_i == std::tuple_size_v<_typeT>) return std::tuple_size_v<_typeT>;\n\
    \      else {\n        KYOPRO_BASE_UINT _seed = operator()<_i + 1>(_a);\n    \
    \    return _seed ^ (Hash<std::tuple_element_t<_i, _typeT>>()(get<_i>(_a)) + 0x9e3779b97f4a7c15LU\
    \ + (_seed << 12) + (_seed >> 4));\n      }\n    }\n  };\n\n  template<class _typeT>\n\
    \  struct Hash<_typeT, std::enable_if_t<is_container_v<_typeT>>> {\n  private:\n\
    \    [[no_unique_address]] Hash<typename _typeT::value_type> make_hash;\n  public:\n\
    \    constexpr KYOPRO_BASE_UINT operator ()(const _typeT& _a) const noexcept {\n\
    \      KYOPRO_BASE_UINT _seed = _a.size();\n      for (auto& _i: _a) _seed ^=\
    \ make_hash(_i) + 0x9e3779b97f4a7c15LU + (_seed << 12) + (_seed >> 4);\n     \
    \ return _seed;\n    }\n  };\n}\n#line 4 \"math/ModInt.hpp\"\n#include <cassert>\n\
    #line 4 \"base/constant.hpp\"\n#include <array>\n#line 4 \"math/power.hpp\"\n\
    namespace kyopro {\n  template<class _typeT>\n  constexpr _typeT power(_typeT\
    \ a, std::uint64_t n, _typeT init = 1) noexcept {\n    while (n > 0) {\n     \
    \ if (n & 1) init *= a;\n      a *= a;\n      n >>= 1;\n    }\n    return init;\n\
    \  }\n}\n#line 8 \"base/constant.hpp\"\n\nnamespace kyopro {\n  inline constexpr\
    \ std::uint64_t _decimal_max = power(static_cast<std::uint64_t>(10), KYOPRO_DECIMAL_PRECISION);\n\
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
    \ -1}, {0, -1}, {1, -1}}};\n}\n#line 4 \"math/mod.hpp\"\n\nnamespace kyopro {\n\
    \  template<class _typeT, class _typeU>\n  constexpr _typeT floor_mod(_typeT _x,\
    \ _typeU _m) noexcept {\n    static_assert(std::is_integral_v<_typeT> && std::is_integral_v<_typeU>);\n\
    \    if constexpr (std::is_unsigned_v<_typeT>) return _x % _m;\n    return (_x\
    \ %= _m) < 0 ? _x + _m : _x;\n  }\n\n  template<class _typeT, class _typeU>\n\
    \  constexpr _typeT ceil_mod(_typeT _x, _typeU _m) noexcept { return _m - floor_mod(_x\
    \ - 1, _m) - 1; }\n}\n#line 9 \"math/ModInt.hpp\"\n\nnamespace kyopro {\n  template<std::uint64_t\
    \ m>\n  struct ModInt {\n    static constexpr std::uint64_t mod = m;\n    std::uint64_t\
    \ value;\n    constexpr ModInt() noexcept = default;\n    template<class T>\n\
    \    constexpr ModInt(T value) noexcept: value(floor_mod(value, m)) { static_assert(std::is_integral_v<T>);\
    \ }\n    template<class T>\n    explicit constexpr operator T() const noexcept\
    \ { return value; }\n    static constexpr ModInt raw(std::uint64_t n) noexcept\
    \ {\n      ModInt res;\n      res.value = n;\n      return res;\n    }\n    constexpr\
    \ ModInt power(std::uint64_t n) const noexcept {\n      std::uint64_t res = 1,\
    \ a = value;\n      while (n > 0) {\n        if (n & 1) res = res * a % m;\n \
    \       a = a * a % m;\n        n >>= 1;\n      }\n      return res;\n    }\n\
    \    constexpr ModInt inv() const noexcept {\n      std::uint64_t a = value, b\
    \ = m;\n      std::int64_t u = 1, v = 0;\n      while (b > 0) {\n        std::uint64_t\
    \ t = a / b;\n        a -= t * b;\n        std::swap(a, b);\n        u -= t *\
    \ v;\n        std::swap(u, v);\n      }\n      return floor_mod(u, m);\n    }\n\
    \    constexpr ModInt operator +() const noexcept { return *this; }\n    constexpr\
    \ ModInt operator -() const noexcept { return m - value; }\n    constexpr ModInt&\
    \ operator ++() noexcept {\n      if (++value >= m) value -= m;\n      return\
    \ *this;\n    }\n    constexpr ModInt operator ++(int) noexcept {\n      ModInt\
    \ before = *this;\n      operator ++();\n      return before;\n    }\n    constexpr\
    \ ModInt& operator --() noexcept {\n      if (value == 0) value = m;\n      --value;\n\
    \      return *this;\n    }\n    constexpr ModInt operator --(int) noexcept {\n\
    \      ModInt before = *this;\n      operator --();\n      return before;\n  \
    \  }\n    constexpr ModInt& operator +=(ModInt rhs) noexcept {\n      if ((value\
    \ += rhs.value) >= m) value -= m;\n      return *this;\n    }\n    constexpr ModInt&\
    \ operator -=(ModInt rhs) noexcept {\n      if (value < rhs.value) value += m;\n\
    \      value -= rhs.value;\n      return *this;\n    }\n    constexpr ModInt&\
    \ operator *=(ModInt rhs) noexcept {\n      value = value * rhs.value % m;\n \
    \     return *this;\n    }\n    constexpr ModInt& operator /=(ModInt rhs) noexcept\
    \ {\n      value = value * rhs.inv().value % m;\n      return *this;\n    }\n\
    \    friend constexpr ModInt operator +(ModInt lhs, ModInt rhs) noexcept { return\
    \ lhs += rhs; }\n    friend constexpr ModInt operator -(ModInt lhs, ModInt rhs)\
    \ noexcept { return lhs -= rhs; }\n    friend constexpr ModInt operator *(ModInt\
    \ lhs, ModInt rhs) noexcept { return lhs *= rhs; }\n    friend constexpr ModInt\
    \ operator /(ModInt lhs, ModInt rhs) noexcept { return lhs /= rhs; }\n    friend\
    \ constexpr bool operator ==(ModInt lhs, ModInt rhs) noexcept { return lhs.value\
    \ == rhs.value; }\n    friend constexpr bool operator !=(ModInt lhs, ModInt rhs)\
    \ noexcept { return lhs.value != rhs.value; }\n  };\n\n  template<KYOPRO_BASE_UINT\
    \ m>\n  struct Hash<ModInt<m>> { constexpr KYOPRO_BASE_UINT operator ()(ModInt<m>\
    \ _a) const noexcept { return _a; } };\n\n  constexpr ModInt<mod> operator \"\"\
    \ _m(unsigned long long a) noexcept { return a; }\n}\n#line 16 \"template/alias.hpp\"\
    \n\nnamespace kyopro {\n  using ll = int64_t;\n  using ull = uint64_t;\n  using\
    \ lf = double;\n  #ifdef __SIZEOF_INT128__\n  using i128 = __int128_t;\n  using\
    \ u128 = __uint128_t;\n  #endif\n  #ifdef __SIZEOF_FLOAT128__\n  using f128 =\
    \ __float128;\n  #endif\n\n  template<class T>\n  using vec = std::vector<T>;\n\
    \  using str = std::string;\n  template<class Key>\n  using hash_set = std::unordered_set<Key,\
    \ Hash<Key>>;\n  template<class Key, class T>\n  using hash_map = std::unordered_map<Key,\
    \ T, Hash<Key>>;\n  template<class Key>\n  using hash_multiset = std::unordered_multiset<Key,\
    \ Hash<Key>>;\n  template<class Key, class T>\n  using hash_multimap = std::unordered_multimap<Key,\
    \ T, Hash<Key>>;\n  template<class T, class Compare = std::less<T>, class Container\
    \ = vec<T>>\n  using priq = std::priority_queue<T, Container, Compare>;\n  template<class\
    \ T, class Compare = std::greater<T>, class Container = vec<T>>\n  using heapq\
    \ = priq<T, Container, Compare>;\n\n  using pll = std::pair<ll, ll>;\n  using\
    \ l3 = std::tuple<ll, ll, ll>;\n  using l4 = std::tuple<ll, ll, ll, ll>;\n  using\
    \ l5 = std::tuple<ll, ll, ll, ll, ll>;\n  using mll = std::map<ll, ll>;\n  using\
    \ hmll = hash_map<ll, ll>;\n  using mmll = std::multimap<ll, ll>;\n  using hmmll\
    \ = std::multimap<ll, ll>;\n  using sl = std::set<ll>;\n  using spll = std::set<pll>;\n\
    \  using hsl = hash_set<ll>;\n  using hspll = hash_set<pll>;\n  using msl = std::multiset<ll>;\n\
    \  using mspll = std::multiset<pll>;\n  using hmsl = hash_multiset<ll>;\n  using\
    \ hmspll = hash_multiset<pll>;\n  using dql = std::deque<ll>;\n  using dqpll =\
    \ std::deque<pll>;\n  using quel = std::queue<ll>;\n  using quepll = std::queue<pll>;\n\
    \  using stkl = std::stack<ll>;\n  using stkpll = std::stack<pll>;\n  using pql\
    \ = priq<ll>;\n  using pqpll = priq<pll>;\n  using hql = heapq<ll>;\n  using hqpll\
    \ = heapq<pll>;\n  using vl = vec<ll>;\n  using vvl = vec<vl>;\n  using vvvl =\
    \ vec<vvl>;\n  using vi = vec<int>;\n  using vvi = vec<vi>;\n  using vvvi = vec<vvi>;\n\
    \  using vf = vec<lf>;\n  using vvf = vec<vf>;\n  using vvvf = vec<vvf>;\n  using\
    \ vb = vec<char>;\n  using vvb = vec<vb>;\n  using vvvb = vec<vvb>;\n  using vc\
    \ = vec<char>;\n  using vvc = vec<vc>;\n  using vvvc = vec<vvc>;\n  using vs =\
    \ vec<str>;\n  using vvs = vec<vs>;\n  using vvvs = vec<vvs>;\n  using vpll =\
    \ vec<pll>;\n  using vvpll = vec<vpll>;\n  using vvvpll = vec<vvpll>;\n  using\
    \ vsl = vec<sl>;\n  using vhsl = vec<hsl>;\n  using vmll = vec<mll>;\n  using\
    \ vhmll = vec<hmll>;\n  using mint = ModInt<mod>;\n  using vm = vec<mint>;\n \
    \ using vvm = vec<vm>;\n  using vvvm = vec<vvm>;\n}\n\nusing namespace std;\n\
    using namespace kyopro;\n#line 3 \"template/all.hpp\"\n"
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
  timestamp: '2022-01-11 23:13:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/all.hpp
layout: document
redirect_from:
- /library/template/all.hpp
- /library/template/all.hpp.html
title: template/all.hpp
---
