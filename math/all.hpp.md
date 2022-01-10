---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: base/Hash.hpp
    title: base/Hash.hpp
  - icon: ':heavy_check_mark:'
    path: base/constant.hpp
    title: base/constant.hpp
  - icon: ':question:'
    path: base/settings.hpp
    title: base/settings.hpp
  - icon: ':warning:'
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
  - icon: ':x:'
    path: math/factorize.hpp
    title: math/factorize.hpp
  - icon: ':warning:'
    path: math/is_prime.hpp
    title: math/is_prime.hpp
  - icon: ':warning:'
    path: math/mod.hpp
    title: math/mod.hpp
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
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/div.hpp\"\n#include <type_traits>\n\nnamespace kyopro\
    \ {\n  template<class KyoproT, class KyoproU>\n  constexpr KyoproT floor_div(KyoproT\
    \ kyopro_x, KyoproU kyopro_m) noexcept {\n    static_assert(std::is_integral_v<KyoproT>\
    \ && std::is_integral_v<KyoproU>);\n    if constexpr (std::is_unsigned_v<KyoproT>)\
    \ return kyopro_x / kyopro_m;\n    if (kyopro_m < 0) return -kyopro_x / -kyopro_m;\n\
    \    if (kyopro_x < 0) return (kyopro_x + 1) / kyopro_m - 1;\n    return kyopro_x\
    \ / kyopro_m;\n  }\n\n  template<class KyoproT, class KyoproU>\n  constexpr KyoproT\
    \ ceil_div(KyoproT kyopro_x, KyoproU kyopro_m) noexcept { return floor_div(kyopro_x\
    \ + kyopro_m - 1, kyopro_m); }\n}\n#line 3 \"math/mod.hpp\"\n#include <cassert>\n\
    \nnamespace kyopro {\n  template<class KyoproT, class KyoproU>\n  constexpr KyoproT\
    \ floor_mod(KyoproT kyopro_x, KyoproU kyopro_m) noexcept {\n    static_assert(std::is_integral_v<KyoproT>\
    \ && std::is_integral_v<KyoproU>);\n    if constexpr (std::is_unsigned_v<KyoproT>)\
    \ return kyopro_x % kyopro_m;\n    return (kyopro_x %= kyopro_m) < 0 ? kyopro_x\
    \ + kyopro_m : kyopro_x;\n  }\n\n  template<class KyoproT, class KyoproU>\n  constexpr\
    \ KyoproT ceil_mod(KyoproT kyopro_x, KyoproU kyopro_m) noexcept { return kyopro_m\
    \ - floor_mod(kyopro_x - 1, kyopro_m) - 1; }\n}\n#line 2 \"math/power.hpp\"\n\
    #include <cstdint>\n#line 3 \"base/settings.hpp\"\n\n#ifndef KYOPRO_BASE_INT\n\
    #define KYOPRO_BASE_INT std::int64_t\n#endif\n#ifndef KYOPRO_BASE_UINT\n#define\
    \ KYOPRO_BASE_UINT std::size_t\n#endif\n#ifndef KYOPRO_BASE_FLOAT\n#define KYOPRO_BASE_FLOAT\
    \ double\n#endif\n#ifndef KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD 1000000007\n\
    #endif\n#ifndef KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION 12\n\
    #endif\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV 3\n#endif\n#line 4 \"math/power.hpp\"\
    \nnamespace kyopro {\n  template<class KyoproT>\n  constexpr KyoproT power(KyoproT\
    \ a, std::uint64_t n, KyoproT init = 1) noexcept {\n    while (n > 0) {\n    \
    \  if (n & 1) init *= a;\n      a *= a;\n      n >>= 1;\n    }\n    return init;\n\
    \  }\n}\n#line 3 \"base/constant.hpp\"\n#include <limits>\n#include <array>\n\
    #include <utility>\n#line 8 \"base/constant.hpp\"\n\nnamespace kyopro {\n  inline\
    \ constexpr std::uint64_t kyopro_decimal_max = power(static_cast<std::uint64_t>(10),\
    \ KYOPRO_DECIMAL_PRECISION);\n  template<class KyoproT>\n  inline constexpr KyoproT\
    \ MOD = KYOPRO_DEFAULT_MOD;\n  inline constexpr KYOPRO_BASE_INT mod = MOD<KYOPRO_BASE_INT>;\n\
    \  template<class KyoproT>\n  inline constexpr KyoproT INF = std::numeric_limits<KyoproT>::max()\
    \ / KYOPRO_INF_DIV;\n  inline constexpr KYOPRO_BASE_INT inf = INF<KYOPRO_BASE_INT>;\n\
    \  template<class KyoproT>\n  inline constexpr KYOPRO_BASE_FLOAT EPS = static_cast<KyoproT>(1)\
    \ / kyopro_decimal_max;\n  inline constexpr KYOPRO_BASE_FLOAT eps = EPS<KYOPRO_BASE_FLOAT>;\n\
    \  template<class KyoproT>\n  inline constexpr KyoproT PI = 3.14159265358979323846;\n\
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
    \ std::true_type {};\n#endif\n\nnamespace kyopro {\n  template<class KyoproT,\
    \ class = void>\n  struct is_iterator: std::false_type {};\n  template<class KyoproT>\n\
    \  struct is_iterator<KyoproT, std::enable_if_t<!std::is_same_v<typename std::iterator_traits<KyoproT>::value_type,\
    \ void>>>: std::true_type {};\n  template<class KyoproT>\n  constexpr bool is_iterator_v\
    \ = is_iterator<KyoproT>::value;\n\n  template<class KyoproT, class = void>\n\
    \  struct is_container: std::false_type {};\n  template<class KyoproT>\n  struct\
    \ is_container<KyoproT, std::void_t<decltype(std::begin(std::declval<KyoproT>()),\
    \ std::end(std::declval<KyoproT>()), std::empty(std::declval<KyoproT>()))>>: std::true_type\
    \ {};\n  template<class KyoproT>\n  constexpr bool is_container_v = is_container<KyoproT>::value;\n\
    \n  template<class KyoproT>\n  struct is_tuple: std::false_type {};\n  template<class\
    \ KyoproT, class U>\n  struct is_tuple<std::pair<KyoproT, U>>: std::true_type\
    \ {};\n  template<class... Args>\n  struct is_tuple<std::tuple<Args...>>: std::true_type\
    \ {};\n  template<class KyoproT>\n  constexpr bool is_tuple_v = is_tuple<KyoproT>::value;\n\
    \n  template<class KyoproT>\n  struct is_iterable: is_container<KyoproT> {};\n\
    \  template<class KyoproT, class Container>\n  struct is_iterable<std::stack<KyoproT,\
    \ Container>>: std::false_type {};\n  template<class KyoproT, class Container>\n\
    \  struct is_iterable<std::queue<KyoproT, Container>>: std::false_type {};\n \
    \ template<class KyoproT, class Container, class Compare>\n  struct is_iterable<std::priority_queue<KyoproT,\
    \ Container, Compare>>: std::false_type {};\n  template<class KyoproT>\n  constexpr\
    \ bool is_iterable_v = is_iterable<KyoproT>::value;\n}\n#line 6 \"base/Hash.hpp\"\
    \n\nnamespace kyopro {\n  template<class, class = void>\n  struct Hash;\n\n  template<class\
    \ KyoproT>\n  struct Hash<KyoproT, std::enable_if_t<std::is_integral_v<KyoproT>>>\
    \ { constexpr KYOPRO_BASE_UINT operator ()(KyoproT kyopro_a) const noexcept {\
    \ return kyopro_a; } };\n\n  template<class KyoproT>\n  struct Hash<KyoproT, std::enable_if_t<std::is_floating_point_v<KyoproT>>>\
    \ { constexpr KYOPRO_BASE_UINT operator ()(KyoproT kyopro_a) const noexcept {\
    \ return (KYOPRO_BASE_UINT)kyopro_a & 0xfffff000; } };\n\n  template<class KyoproT>\n\
    \  struct Hash<KyoproT, std::enable_if_t<is_tuple_v<KyoproT>>> {\n    template<KYOPRO_BASE_UINT\
    \ kyopro_i = 0>\n    constexpr KYOPRO_BASE_UINT operator ()(const KyoproT& kyopro_a)\
    \ const noexcept {\n      if constexpr (kyopro_i == std::tuple_size_v<KyoproT>)\
    \ return std::tuple_size_v<KyoproT>;\n      else {\n        KYOPRO_BASE_UINT kyopro_seed\
    \ = operator()<kyopro_i + 1>(kyopro_a);\n        return kyopro_seed ^ (Hash<std::tuple_element_t<kyopro_i,\
    \ KyoproT>>()(get<kyopro_i>(kyopro_a)) + 0x9e3779b97f4a7c15LU + (kyopro_seed <<\
    \ 12) + (kyopro_seed >> 4));\n      }\n    }\n  };\n\n  template<class KyoproT>\n\
    \  struct Hash<KyoproT, std::enable_if_t<is_container_v<KyoproT>>> {\n  private:\n\
    \    [[no_unique_address]] Hash<typename KyoproT::value_type> make_hash;\n  public:\n\
    \    constexpr KYOPRO_BASE_UINT operator ()(const KyoproT& kyopro_a) const noexcept\
    \ {\n      KYOPRO_BASE_UINT kyopro_seed = kyopro_a.size();\n      for (auto& kyopro_i:\
    \ kyopro_a) kyopro_seed ^= make_hash(kyopro_i) + 0x9e3779b97f4a7c15LU + (kyopro_seed\
    \ << 12) + (kyopro_seed >> 4);\n      return kyopro_seed;\n    }\n  };\n}\n#line\
    \ 9 \"math/ModInt.hpp\"\n\nnamespace kyopro {\n  template<std::uint64_t m>\n \
    \ struct ModInt {\n    static constexpr std::uint64_t mod = m;\n    std::uint64_t\
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
    \ kyopro_a) const noexcept { return kyopro_a; } };\n\n  constexpr ModInt<mod>\
    \ operator \"\" _m(unsigned long long a) noexcept { return a; }\n}\n#line 4 \"\
    math/monoid.hpp\"\n\nnamespace kyopro {\n  template<class KyoproT, KyoproT kyopro_id\
    \ = 0>\n  struct Plus {\n    static constexpr KyoproT id = kyopro_id;\n    static\
    \ constexpr KyoproT op(KyoproT kyopro_a, KyoproT kyopro_b) noexcept { return kyopro_a\
    \ + kyopro_b; }\n    static constexpr KyoproT inv(KyoproT kyopro_a) noexcept {\
    \ return -kyopro_a; }\n  };\n  template<class KyoproT, KyoproT kyopro_id = 1>\n\
    \  struct Mul {\n    static constexpr KyoproT id = kyopro_id;\n    static constexpr\
    \ KyoproT op(KyoproT kyopro_a, KyoproT kyopro_b) noexcept { return kyopro_a *\
    \ kyopro_b; }\n    static constexpr KyoproT inv(KyoproT kyopro_a) noexcept {\n\
    \      static_assert(!std::is_integral_v<KyoproT>);\n      return 1 / kyopro_a;\n\
    \    }\n  };\n  template<class KyoproT, KyoproT kyopro_id = -inf>\n  struct Max\
    \ {\n    static constexpr KyoproT id = kyopro_id;\n    static constexpr KyoproT\
    \ op(KyoproT kyopro_a, KyoproT kyopro_b) noexcept { return kyopro_a > kyopro_b\
    \ ? kyopro_a : kyopro_b; }\n  };\n  template<class KyoproT, KyoproT kyopro_id\
    \ = inf>\n  struct Min {\n    static constexpr KyoproT id = kyopro_id;\n    static\
    \ constexpr KyoproT op(KyoproT kyopro_a, KyoproT kyopro_b) noexcept { return kyopro_a\
    \ < kyopro_b ? kyopro_a : kyopro_b; }\n  };\n}\n#line 3 \"math/is_prime.hpp\"\n\
    \nnamespace kyopro {\n  constexpr bool is_prime(std::uint64_t kyopro_n) noexcept\
    \ {\n    if (kyopro_n < 2) return false;\n    if (kyopro_n < 4) return true;\n\
    \    if ((kyopro_n & 1) == 0 || kyopro_n % 3 == 0) return false;\n    for (std::uint64_t\
    \ kyopro_i = 5; kyopro_i * kyopro_i <= kyopro_n; kyopro_i += 4) {\n      if (kyopro_n\
    \ % kyopro_i == 0) return false;\n      if (kyopro_n % (kyopro_i += 2) == 0) return\
    \ false;\n    }\n    return true;\n  }\n}\n#line 3 \"math/divisors.hpp\"\n#include\
    \ <vector>\n#line 5 \"math/divisors.hpp\"\n\nnamespace kyopro {\n  template<class\
    \ KyoproContainer = std::vector<KYOPRO_BASE_INT>>\n  KyoproContainer divisors(std::uint64_t\
    \ kyopro_n) {\n    KyoproContainer kyopro_lower, kyopro_upper;\n    std::uint64_t\
    \ kyopro_i;\n    for (kyopro_i = 1; kyopro_i * kyopro_i < kyopro_n; ++kyopro_i)\
    \ if (kyopro_n % kyopro_i == 0) {\n      kyopro_lower.emplace_back(kyopro_i);\n\
    \      kyopro_upper.emplace_back(kyopro_n / kyopro_i);\n    }\n    if (kyopro_i\
    \ * kyopro_i == kyopro_n) kyopro_lower.emplace_back(kyopro_i);\n    kyopro_lower.insert(end(kyopro_lower),\
    \ rall(kyopro_upper));\n    return kyopro_lower;\n  }\n}\n#line 6 \"math/factorize.hpp\"\
    \n\nnamespace kyopro {\n  template<class KyoproContainer = std::vector<KYOPRO_BASE_INT>>\n\
    \  KyoproContainer factorize(std::uint64_t kyopro_n) {\n    KyoproContainer kyopro_res;\n\
    \    while ((kyopro_n & 1) == 0) {\n      kyopro_res.emplace_back(2);\n      kyopro_n\
    \ >>= 1;\n    }\n    for (std::uint64_t kyopro_i = 3; kyopro_i * kyopro_i <= kyopro_n;\
    \ kyopro_i += 2) while (kyopro_n % kyopro_i == 0) {\n      kyopro_res.emplace_back(2);\n\
    \      kyopro_n /= kyopro_i;\n    }\n    if (kyopro_n != 1) kyopro_res.emplace_back(kyopro_n);\n\
    \    return kyopro_res;\n  }\n}\n#line 3 \"math/euler_phi.hpp\"\n\nnamespace kyopro\
    \ {\n  constexpr std::uint64_t euler_phi(std::uint64_t kyopro_n) noexcept {\n\
    \    std::uint64_t kyopro_res = kyopro_n;\n    if ((kyopro_n & 1) == 0) {\n  \
    \    kyopro_res -= kyopro_res >> 1;\n      kyopro_n >>= 1;\n      while ((kyopro_n\
    \ & 1) == 0) kyopro_n >>= 1;\n    }\n    for (std::uint64_t kyopro_i = 3; kyopro_i\
    \ * kyopro_i <= kyopro_n; kyopro_i += 2) {\n      if (kyopro_n % kyopro_i == 0)\
    \ {\n        kyopro_res -= kyopro_res / kyopro_i;\n        kyopro_n /= kyopro_i;\n\
    \        while (kyopro_n % kyopro_i == 0) kyopro_n /= kyopro_i;\n      }\n   \
    \ }\n    if (kyopro_n != 1) kyopro_res -= kyopro_res / kyopro_n;\n    return kyopro_res;\n\
    \  }\n}\n#line 11 \"math/all.hpp\"\n"
  code: '#pragma once

    #include "div.hpp"

    #include "mod.hpp"

    #include "power.hpp"

    #include "ModInt.hpp"

    #include "monoid.hpp"

    #include "is_prime.hpp"

    #include "divisors.hpp"

    #include "factorize.hpp"

    #include "euler_phi.hpp"'
  dependsOn:
  - math/div.hpp
  - math/mod.hpp
  - math/power.hpp
  - base/settings.hpp
  - math/ModInt.hpp
  - base/constant.hpp
  - base/Hash.hpp
  - base/trait.hpp
  - math/monoid.hpp
  - math/is_prime.hpp
  - math/divisors.hpp
  - math/factorize.hpp
  - math/euler_phi.hpp
  isVerificationFile: false
  path: math/all.hpp
  requiredBy:
  - all.hpp
  timestamp: '2022-01-10 22:56:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/all.hpp
layout: document
redirect_from:
- /library/math/all.hpp
- /library/math/all.hpp.html
title: math/all.hpp
---