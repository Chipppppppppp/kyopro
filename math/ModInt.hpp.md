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
    path: math/mod.hpp
    title: math/mod.hpp
  - icon: ':heavy_check_mark:'
    path: math/power.hpp
    title: math/power.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  - icon: ':warning:'
    path: math/all.hpp
    title: math/all.hpp
  - icon: ':warning:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':warning:'
    path: template/all.hpp
    title: template/all.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/ModInt.hpp\"\n#include <cstdint>\n#include <type_traits>\n\
    #include <cassert>\n#line 3 \"base/settings.hpp\"\n\n#ifndef KYOPRO_BASE_INT\n\
    #define KYOPRO_BASE_INT std::int64_t\n#endif\n#ifndef KYOPRO_BASE_UINT\n#define\
    \ KYOPRO_BASE_UINT std::size_t\n#endif\n#ifndef KYOPRO_BASE_FLOAT\n#define KYOPRO_BASE_FLOAT\
    \ double\n#endif\n#ifndef KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD 1000000007\n\
    #endif\n#ifndef KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION 12\n\
    #endif\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV 3\n#endif\n#line 3 \"base/constant.hpp\"\
    \n#include <limits>\n#include <array>\n#include <utility>\n#line 4 \"math/power.hpp\"\
    \nnamespace kyopro {\n  template<class _typeT>\n  constexpr _typeT power(_typeT\
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
    \ -1}, {0, -1}, {1, -1}}};\n}\n#line 3 \"base/Hash.hpp\"\n#include <tuple>\n#line\
    \ 4 \"base/trait.hpp\"\n#include <iterator>\n#include <stack>\n#include <queue>\n\
    \n#ifdef __SIZEOF_INT128__\nstruct std::is_integral<__int128_t>: std::true_type\
    \ {};\nstruct std::is_signed<__int128_t>: std::true_type {};\nstruct std::is_integral<__uint128_t>:\
    \ std::true_type {};\nstruct std::is_unsigned<__uint128_t>: std::true_type {};\n\
    #endif\n#ifdef __SIZEOF_FLOAT128__\nstruct std::is_floating_point<__float128>:\
    \ std::true_type {};\n#endif\n\nnamespace kyopro {\n  template<class _typeT, class\
    \ = void>\n  struct is_iterator: std::false_type {};\n  template<class _typeT>\n\
    \  struct is_iterator<_typeT, std::enable_if_t<!std::is_same_v<typename std::iterator_traits<_typeT>::value_type,\
    \ void>>>: std::true_type {};\n  template<class _typeT>\n  constexpr bool is_iterator_v\
    \ = is_iterator<_typeT>::value;\n\n  template<class _typeT, class = void>\n  struct\
    \ is_container: std::false_type {};\n  template<class _typeT>\n  struct is_container<_typeT,\
    \ std::void_t<decltype(std::begin(std::declval<_typeT>()), std::end(std::declval<_typeT>()),\
    \ std::empty(std::declval<_typeT>()))>>: std::true_type {};\n  template<class\
    \ _typeT>\n  constexpr bool is_container_v = is_container<_typeT>::value;\n\n\
    \  template<class _typeT>\n  struct is_tuple: std::false_type {};\n  template<class\
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
    \ return _seed;\n    }\n  };\n}\n#line 4 \"math/mod.hpp\"\n\nnamespace kyopro\
    \ {\n  template<class _typeT, class _typeU>\n  constexpr _typeT floor_mod(_typeT\
    \ _x, _typeU _m) noexcept {\n    static_assert(std::is_integral_v<_typeT> && std::is_integral_v<_typeU>);\n\
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
    \ _m(unsigned long long a) noexcept { return a; }\n}\n"
  code: "#pragma once\n#include <cstdint>\n#include <type_traits>\n#include <cassert>\n\
    #include \"../base/settings.hpp\"\n#include \"../base/constant.hpp\"\n#include\
    \ \"../base/Hash.hpp\"\n#include \"mod.hpp\"\n\nnamespace kyopro {\n  template<std::uint64_t\
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
    \ _m(unsigned long long a) noexcept { return a; }\n}"
  dependsOn:
  - base/settings.hpp
  - base/constant.hpp
  - math/power.hpp
  - base/Hash.hpp
  - base/trait.hpp
  - math/mod.hpp
  isVerificationFile: false
  path: math/ModInt.hpp
  requiredBy:
  - math/all.hpp
  - template/alias.hpp
  - template/all.hpp
  - all.hpp
  timestamp: '2022-01-11 23:13:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/ModInt.hpp
layout: document
redirect_from:
- /library/math/ModInt.hpp
- /library/math/ModInt.hpp.html
title: math/ModInt.hpp
---
