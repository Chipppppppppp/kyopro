---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base/constant.hpp
    title: base/constant.hpp
  - icon: ':heavy_check_mark:'
    path: base/settings.hpp
    title: base/settings.hpp
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
    path: base/Hash.hpp
    title: base/Hash.hpp
  - icon: ':warning:'
    path: base/all.hpp
    title: base/all.hpp
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
    #include <cassert>\n#line 3 \"base/settings.hpp\"\n#ifndef KYOPRO_BASE_INT\n#define\
    \ KYOPRO_BASE_INT std::int64_t\n#endif\n#ifndef KYOPRO_BASE_UINT\n#define KYOPRO_BASE_UINT\
    \ std::size_t\n#endif\n#ifndef KYOPRO_BASE_FLOAT\n#define KYOPRO_BASE_FLOAT double\n\
    #endif\n#ifndef KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD 1000000007\n#endif\n\
    #ifndef KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION 12\n#endif\n\
    #ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV 3\n#endif\n#line 3 \"base/constant.hpp\"\
    \n#include <limits>\n#include <array>\n#include <utility>\n#line 4 \"math/power.hpp\"\
    \nnamespace kyopro {\n  template<class KyoproT>\n  constexpr KyoproT power(KyoproT\
    \ a, std::uint64_t n, KyoproT init = 1) noexcept {\n    while (n > 0) {\n    \
    \  if (n & 1) init *= a;\n      a *= a;\n      n >>= 1;\n    }\n    return init;\n\
    \  }\n}\n#line 8 \"base/constant.hpp\"\n\nnamespace kyopro {\n  inline constexpr\
    \ std::uint64_t kyopro_decimal_max = power(static_cast<std::uint64_t>(10), KYOPRO_DECIMAL_PRECISION);\n\
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
    \ -1}, {0, -1}, {1, -1}}};\n}\n#line 4 \"math/mod.hpp\"\n\nnamespace kyopro {\n\
    \  template<class KyoproT, class KyoproU>\n  constexpr KyoproT floor_mod(KyoproT\
    \ kyopro_x, KyoproU kyopro_m) noexcept {\n    static_assert(std::is_integral_v<KyoproT>\
    \ && std::is_integral_v<KyoproU>);\n    if constexpr (std::is_unsigned_v<KyoproT>)\
    \ return kyopro_x % kyopro_m;\n    return (kyopro_x %= kyopro_m) < 0 ? kyopro_x\
    \ + kyopro_m : kyopro_x;\n  }\n\n  template<class KyoproT, class KyoproU>\n  constexpr\
    \ KyoproT ceil_mod(KyoproT kyopro_x, KyoproU kyopro_m) noexcept { return kyopro_m\
    \ - floor_mod(kyopro_x - 1, kyopro_m) - 1; }\n}\n#line 8 \"math/ModInt.hpp\"\n\
    \nnamespace kyopro {\n  template<std::uint64_t m>\n  struct ModInt {\n    static\
    \ constexpr std::uint64_t mod = m;\n    std::uint64_t value;\n    constexpr ModInt()\
    \ noexcept = default;\n    template<class T>\n    constexpr ModInt(T value) noexcept:\
    \ value(floor_mod(value, m)) { static_assert(std::is_integral_v<T>); }\n    template<class\
    \ T>\n    explicit constexpr operator T() const noexcept { return value; }\n \
    \   static constexpr ModInt raw(std::uint64_t n) noexcept {\n      ModInt res;\n\
    \      res.value = n;\n      return res;\n    }\n    constexpr ModInt power(std::uint64_t\
    \ n) const noexcept {\n      std::uint64_t res = 1, a = value;\n      while (n\
    \ > 0) {\n        if (n & 1) res = res * a % m;\n        a = a * a % m;\n    \
    \    n >>= 1;\n      }\n      return res;\n    }\n    constexpr ModInt inv() const\
    \ noexcept {\n      std::uint64_t a = value, b = m;\n      std::int64_t u = 1,\
    \ v = 0;\n      while (b > 0) {\n        std::uint64_t t = a / b;\n        a -=\
    \ t * b;\n        std::swap(a, b);\n        u -= t * v;\n        std::swap(u,\
    \ v);\n      }\n      return floor_mod(u, m);\n    }\n    constexpr ModInt operator\
    \ +() const noexcept { return *this; }\n    constexpr ModInt operator -() const\
    \ noexcept { return m - value; }\n    constexpr ModInt& operator ++() noexcept\
    \ {\n      if (++value >= m) value -= m;\n      return *this;\n    }\n    constexpr\
    \ ModInt operator ++(int) noexcept {\n      ModInt before = *this;\n      operator\
    \ ++();\n      return before;\n    }\n    constexpr ModInt& operator --() noexcept\
    \ {\n      if (value == 0) value = m;\n      --value;\n      return *this;\n \
    \   }\n    constexpr ModInt operator --(int) noexcept {\n      ModInt before =\
    \ *this;\n      operator --();\n      return before;\n    }\n    constexpr ModInt&\
    \ operator +=(ModInt rhs) noexcept {\n      if ((value += rhs.value) >= m) value\
    \ -= m;\n      return *this;\n    }\n    constexpr ModInt& operator -=(ModInt\
    \ rhs) noexcept {\n      if (value < rhs.value) value += m;\n      value -= rhs.value;\n\
    \      return *this;\n    }\n    constexpr ModInt& operator *=(ModInt rhs) noexcept\
    \ {\n      value = value * rhs.value % m;\n      return *this;\n    }\n    constexpr\
    \ ModInt& operator /=(ModInt rhs) noexcept {\n      value = value * rhs.inv().value\
    \ % m;\n      return *this;\n    }\n    friend constexpr ModInt operator +(ModInt\
    \ lhs, ModInt rhs) noexcept { return lhs += rhs; }\n    friend constexpr ModInt\
    \ operator -(ModInt lhs, ModInt rhs) noexcept { return lhs -= rhs; }\n    friend\
    \ constexpr ModInt operator *(ModInt lhs, ModInt rhs) noexcept { return lhs *=\
    \ rhs; }\n    friend constexpr ModInt operator /(ModInt lhs, ModInt rhs) noexcept\
    \ { return lhs /= rhs; }\n    friend constexpr bool operator ==(ModInt lhs, ModInt\
    \ rhs) noexcept { return lhs.value == rhs.value; }\n    friend constexpr bool\
    \ operator !=(ModInt lhs, ModInt rhs) noexcept { return lhs.value != rhs.value;\
    \ }\n  };\n  constexpr ModInt<mod> operator \"\" _m(unsigned long long a) noexcept\
    \ { return a; }\n}\n"
  code: "#pragma once\n#include <cstdint>\n#include <type_traits>\n#include <cassert>\n\
    #include \"../base/settings.hpp\"\n#include \"../base/constant.hpp\"\n#include\
    \ \"mod.hpp\"\n\nnamespace kyopro {\n  template<std::uint64_t m>\n  struct ModInt\
    \ {\n    static constexpr std::uint64_t mod = m;\n    std::uint64_t value;\n \
    \   constexpr ModInt() noexcept = default;\n    template<class T>\n    constexpr\
    \ ModInt(T value) noexcept: value(floor_mod(value, m)) { static_assert(std::is_integral_v<T>);\
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
    \ noexcept { return lhs.value != rhs.value; }\n  };\n  constexpr ModInt<mod> operator\
    \ \"\" _m(unsigned long long a) noexcept { return a; }\n}"
  dependsOn:
  - base/settings.hpp
  - base/constant.hpp
  - math/power.hpp
  - math/mod.hpp
  isVerificationFile: false
  path: math/ModInt.hpp
  requiredBy:
  - math/all.hpp
  - template/alias.hpp
  - template/all.hpp
  - all.hpp
  - base/Hash.hpp
  - base/all.hpp
  timestamp: '2022-01-10 20:01:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/ModInt.hpp
layout: document
redirect_from:
- /library/math/ModInt.hpp
- /library/math/ModInt.hpp.html
title: math/ModInt.hpp
---
