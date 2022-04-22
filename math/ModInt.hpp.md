---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/Hash.hpp
    title: algorithm/Hash.hpp
  - icon: ':heavy_check_mark:'
    path: algorithm/bit.hpp
    title: algorithm/bit.hpp
  - icon: ':heavy_check_mark:'
    path: math/mod.hpp
    title: math/mod.hpp
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
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all/all.hpp
    title: all/all.hpp
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
  bundledCode: "#line 2 \"math/ModInt.hpp\"\n#include <cassert>\n#include <cstddef>\n\
    #include <cstdint>\n#include <limits>\n#include <type_traits>\n#include <utility>\n\
    #line 3 \"meta/settings.hpp\"\n\n#ifndef KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT\
    \ std::int64_t\n#endif\n\n#ifndef KYOPRO_BASE_UINT\n#define KYOPRO_BASE_UINT std::uint64_t\n\
    #endif\n\n#ifndef KYOPRO_BASE_FLOAT\n#define KYOPRO_BASE_FLOAT double\n#endif\n\
    \n#ifndef KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD static_cast<KYOPRO_BASE_UINT>(998244353)\n\
    #endif\n\n#ifndef KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n\
    #endif\n\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 5 \"algorithm/bit.hpp\"\n\nnamespace kyopro {\n  template<class\
    \ T>\n  constexpr KYOPRO_BASE_INT pop_count(T x) noexcept {\n    constexpr auto\
    \ digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;\n    static_assert(digits\
    \ <= std::numeric_limits<unsigned long long>::digits, \"Integer size is too large\"\
    );\n    if constexpr (digits <= std::numeric_limits<unsigned int>::digits) return\
    \ __builtin_popcount(x);\n    else if constexpr (digits <= std::numeric_limits<unsigned\
    \ long>::digits) return __builtin_popcountl(x);\n    else return __builtin_popcountll(x);\n\
    \  }\n\n  template<class T>\n  constexpr KYOPRO_BASE_INT leading_zero(T x) noexcept\
    \ {\n    constexpr auto digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;\n\
    \    static_assert(digits <= std::numeric_limits<unsigned long long>::digits,\
    \ \"Integer size is too large\");\n    if (x == 0) return 0;\n    if constexpr\
    \ (digits <= std::numeric_limits<unsigned int>::digits) return __builtin_clz(x)\
    \ + digits - std::numeric_limits<unsigned int>::digits;\n    else if constexpr\
    \ (digits <= std::numeric_limits<unsigned long>::digits) return __builtin_clzl(x)\
    \ + digits - std::numeric_limits<unsigned long>::digits;\n    else return __builtin_clzll(x)\
    \ + digits - std::numeric_limits<unsigned long long>::digits;\n  }\n\n  template<class\
    \ T>\n  constexpr KYOPRO_BASE_INT trailing_zero(T x) noexcept {\n    constexpr\
    \ auto digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;\n    static_assert(digits\
    \ <= std::numeric_limits<unsigned long long>::digits, \"Integer size is too large\"\
    );\n    if constexpr (digits <= std::numeric_limits<unsigned int>::digits) return\
    \ __builtin_ctz(x);\n    else if constexpr (digits <= std::numeric_limits<unsigned\
    \ long>::digits) return __builtin_ctzl(x);\n    else return __builtin_ctzll(x);\n\
    \  }\n\n  template<class T>\n  constexpr KYOPRO_BASE_INT bit_len(T x) noexcept\
    \ {\n    constexpr auto digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;\n\
    \    static_assert(digits <= std::numeric_limits<unsigned long long>::digits,\
    \ \"Integer size is too large\");\n    if (x == 0) return 0;\n    if constexpr\
    \ (digits <= std::numeric_limits<unsigned int>::digits) return std::numeric_limits<unsigned\
    \ int>::digits - __builtin_clz(x);\n    else if constexpr (digits <= std::numeric_limits<unsigned\
    \ long>::digits) return std::numeric_limits<unsigned long>::digits - __builtin_clzl(x);\n\
    \    else return std::numeric_limits<unsigned long long>::digits - __builtin_clzll(x);\n\
    \  }\n\n  template<class T>\n  constexpr KYOPRO_BASE_INT floor_bit(T x) noexcept\
    \ {\n    return bit_len(x >> static_cast<T>(1));\n  }\n\n  template<class T>\n\
    \  constexpr KYOPRO_BASE_INT ceil_bit(T x) noexcept {\n    if (x == 0) return\
    \ 0;\n    return bit_len(x - static_cast<T>(1));\n  }\n}\n#line 4 \"algorithm/Hash.hpp\"\
    \n#include <functional>\n#include <tuple>\n#line 2 \"meta/trait.hpp\"\n#include\
    \ <iterator>\n#include <queue>\n#line 5 \"meta/trait.hpp\"\n#include <stack>\n\
    #line 9 \"meta/trait.hpp\"\n\nnamespace kyopro {\n  template<KYOPRO_BASE_UINT\
    \ size>\n  struct int_least {\n  private:\n    static constexpr auto get_type()\
    \ noexcept {\n      static_assert(size <= 128, \"Integer size is too large\");\n\
    \      if constexpr (size <= 8) return std::int_least8_t();\n      else if constexpr\
    \ (size <= 16) return std::int_least16_t();\n      else if constexpr (size <=\
    \ 32) return std::int_least32_t();\n      else if constexpr (size <= 64) return\
    \ std::int_least64_t();\n      else return __int128_t();\n    }\n\n  public:\n\
    \    using type = decltype(get_type());\n  };\n\n  template<KYOPRO_BASE_UINT size>\n\
    \  using int_least_t = typename int_least<size>::type;\n\n  template<KYOPRO_BASE_UINT\
    \ size>\n  struct uint_least {\n  private:\n    static constexpr auto get_type()\
    \ noexcept {\n      static_assert(size <= 128, \"Integer size is too large\");\n\
    \      if constexpr (size <= 8) return std::uint_least8_t();\n      else if constexpr\
    \ (size <= 16) return std::uint_least16_t();\n      else if constexpr (size <=\
    \ 32) return std::uint_least32_t();\n      else if constexpr (size <= 64) return\
    \ std::uint_least64_t();\n      else return __uint128_t();\n    }\n\n  public:\n\
    \    using type = decltype(get_type());\n  };\n\n  template<KYOPRO_BASE_UINT size>\n\
    \  using uint_least_t = typename uint_least<size>::type;\n\n  template<class,\
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
    \  };\n\n  template<class T>\n  using iterable_value_t = typename iterable_value<T>::value;\n\
    }\n#line 10 \"algorithm/Hash.hpp\"\n\nnamespace kyopro {\n  template<class, class\
    \ = void>\n  struct Hash;\n\n  template<class T>\n  struct Hash<T, std::enable_if_t<std::is_scalar_v<T>>>:\
    \ std::hash<T> {\n    constexpr std::size_t operator ()(T a) const noexcept {\n\
    \      return std::hash<T>::operator ()(a);\n    }\n  };\n\n  template<class T>\n\
    \  struct Hash<T, std::enable_if_t<is_tuple_v<T>>> {\n    template<KYOPRO_BASE_UINT\
    \ i = 0>\n    constexpr std::size_t operator ()(const T& a) const noexcept {\n\
    \      if constexpr (i == std::tuple_size_v<T>) return std::tuple_size_v<T>;\n\
    \      else {\n        std::uint_fast64_t seed = operator()<i + 1>(a);\n     \
    \   return seed ^ (Hash<std::tuple_element_t<i, T>>()(std::get<i>(a)) + 0x9e3779b97f4a7c15LU\
    \ + (seed << 12) + (seed >> 4));\n      }\n    }\n  };\n\n  template<class T>\n\
    \  struct Hash<T, std::enable_if_t<is_iterable_v<T>>>: Hash<iterable_value_t<T>>\
    \ {\n    constexpr std::size_t operator ()(const T& a) const noexcept {\n    \
    \  std::uint_fast64_t seed = a.size();\n      for (auto& i: a) seed ^= Hash<iterable_value_t<T>>(i)\
    \ + 0x9e3779b97f4a7c15LU + (seed << 12) + (seed >> 4);\n      return seed;\n \
    \   }\n  };\n}\n#line 2 \"meta/constant.hpp\"\n#include <array>\n#line 3 \"math/power.hpp\"\
    \n\nnamespace kyopro {\n  template<class T>\n  constexpr T power(T a, KYOPRO_BASE_UINT\
    \ n, T init = 1) noexcept {\n    while (n > 0) {\n      if (n & 1) init *= a;\n\
    \      a *= a;\n      n >>= 1;\n    }\n    return init;\n  }\n}\n#line 7 \"meta/constant.hpp\"\
    \n\nnamespace kyopro {\n  template<class T>\n  inline constexpr T MOD = KYOPRO_DEFAULT_MOD;\n\
    \  inline constexpr KYOPRO_BASE_INT mod = MOD<KYOPRO_BASE_INT>;\n\n  template<class\
    \ T>\n  inline constexpr T INF = std::numeric_limits<T>::max() / KYOPRO_INF_DIV;\n\
    \  inline constexpr KYOPRO_BASE_INT inf = INF<KYOPRO_BASE_INT>;\n\n  template<class\
    \ T, KYOPRO_BASE_UINT decimal_precision = KYOPRO_DECIMAL_PRECISION>\n  inline\
    \ constexpr KYOPRO_BASE_FLOAT EPS = static_cast<T>(1) / power(10ULL, decimal_precision);\n\
    \  inline constexpr KYOPRO_BASE_FLOAT eps = EPS<KYOPRO_BASE_FLOAT>;\n\n  template<class\
    \ T>\n  inline constexpr T PI = 3.14159265358979323846;\n  inline constexpr KYOPRO_BASE_FLOAT\
    \ pi = PI<KYOPRO_BASE_FLOAT>;\n}\n#line 4 \"math/mod.hpp\"\n\nnamespace kyopro\
    \ {\n  template<class T, class U>\n  constexpr std::common_type_t<T, U> floor_mod(T\
    \ x, U m) noexcept {\n    static_assert(std::is_integral_v<T> && std::is_integral_v<U>,\
    \ \"Integer is required\");\n    if constexpr (std::is_unsigned_v<T> || std::is_unsigned_v<U>)\
    \ return x % m;\n    return (x %= m) < 0 ? x + m : x;\n  }\n\n  template<class\
    \ T, class U>\n  constexpr std::common_type_t<T, U> ceil_mod(T x, U m) noexcept\
    \ {\n    return m - floor_mod(x - 1, m) - static_cast<T>(1);\n  }\n}\n#line 14\
    \ \"math/ModInt.hpp\"\n\nnamespace kyopro {\n  template<KYOPRO_BASE_UINT m>\n\
    \  struct ModInt {\n    using value_type = uint_least_t<bit_len(m * 2 - 2)>;\n\
    \n  private:\n    static constexpr value_type mod = m;\n\n  public:\n    value_type\
    \ value;\n\n    static constexpr KYOPRO_BASE_INT get_mod() noexcept {\n      return\
    \ mod;\n    }\n\n    constexpr ModInt() noexcept = default;\n    template<class\
    \ T>\n    constexpr ModInt(T value) noexcept: value(floor_mod(value, mod)) {}\n\
    \n    template<class T>\n    explicit constexpr operator T() const noexcept {\
    \ return value; }\n\n    static constexpr ModInt raw(KYOPRO_BASE_UINT n) noexcept\
    \ {\n      ModInt res;\n      res.value = n;\n      return res;\n    }\n\n   \
    \ constexpr ModInt power(KYOPRO_BASE_UINT n) const noexcept {\n      std::uint_fast64_t\
    \ res = 1, a = value;\n      while (n > 0) {\n        if (n & 1) res = res * a\
    \ % mod;\n        a = a * a % mod;\n        n >>= 1;\n      }\n      return res;\n\
    \    }\n\n    constexpr ModInt inv() const noexcept {\n      std::uint_fast64_t\
    \ a = value, b = mod;\n      std::int_fast64_t u = 1, v = 0;\n      while (b >\
    \ 0) {\n        std::uint_fast64_t t = a / b;\n        a -= t * b;\n        std::swap(a,\
    \ b);\n        u -= t * v;\n        std::swap(u, v);\n      }\n      return floor_mod(u,\
    \ mod);\n    }\n\n    constexpr ModInt operator +() const noexcept { return *this;\
    \ }\n\n    constexpr ModInt operator -() const noexcept { return value == 0 ?\
    \ 0 : mod - value; }\n\n    constexpr ModInt& operator ++() noexcept {\n     \
    \ if (++value >= mod) value -= mod;\n      return *this;\n    }\n\n    constexpr\
    \ ModInt operator ++(int) noexcept {\n      ModInt before = *this;\n      operator\
    \ ++();\n      return before;\n    }\n\n    constexpr ModInt& operator --() noexcept\
    \ {\n      if (value == 0) value = mod;\n      --value;\n      return *this;\n\
    \    }\n\n    constexpr ModInt operator --(int) noexcept {\n      ModInt before\
    \ = *this;\n      operator --();\n      return before;\n    }\n\n    constexpr\
    \ ModInt& operator +=(ModInt rhs) noexcept {\n      if ((value += rhs.value) >=\
    \ mod) value -= mod;\n      return *this;\n    }\n\n    constexpr ModInt& operator\
    \ -=(ModInt rhs) noexcept {\n      if (value < rhs.value) value += mod;\n    \
    \  value -= rhs.value;\n      return *this;\n    }\n\n    constexpr ModInt& operator\
    \ *=(ModInt rhs) noexcept {\n      value = static_cast<uint_least_t<bit_len(mod)\
    \ * 2>>(value) * rhs.value % mod;\n      return *this;\n    }\n\n    constexpr\
    \ ModInt& operator /=(ModInt rhs) noexcept {\n      value = static_cast<uint_least_t<bit_len(mod)\
    \ * 2>>(value) * rhs.inv().value % mod;\n      return *this;\n    }\n\n    friend\
    \ constexpr ModInt operator +(ModInt lhs, ModInt rhs) noexcept { return lhs +=\
    \ rhs; }\n\n    friend constexpr ModInt operator -(ModInt lhs, ModInt rhs) noexcept\
    \ { return lhs -= rhs; }\n\n    friend constexpr ModInt operator *(ModInt lhs,\
    \ ModInt rhs) noexcept { return lhs *= rhs; }\n\n    friend constexpr ModInt operator\
    \ /(ModInt lhs, ModInt rhs) noexcept { return lhs /= rhs; }\n\n    friend constexpr\
    \ bool operator ==(ModInt lhs, ModInt rhs) noexcept { return lhs.value == rhs.value;\
    \ }\n\n    friend constexpr bool operator !=(ModInt lhs, ModInt rhs) noexcept\
    \ { return lhs.value != rhs.value; }\n\n    template<class Scanner>\n    void\
    \ scan(Scanner& scanner) {\n      std::int_fast64_t value;\n      scanner.scan(value);\n\
    \      value = floor_mod(value, mod);\n    }\n\n    template<class Printer>\n\
    \    void print(Printer& printer) const {\n      printer.print(value);\n    }\n\
    \  };\n\n  template<KYOPRO_BASE_UINT mod>\n  struct Hash<ModInt<mod>> { constexpr\
    \ std::size_t operator ()(ModInt<mod> a) const noexcept { return static_cast<std::size_t>(a);\
    \ } };\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <cstddef>\n#include <cstdint>\n\
    #include <limits>\n#include <type_traits>\n#include <utility>\n#include \"../algorithm/bit.hpp\"\
    \n#include \"../algorithm/Hash.hpp\"\n#include \"../meta/constant.hpp\"\n#include\
    \ \"../meta/settings.hpp\"\n#include \"../meta/trait.hpp\"\n#include \"mod.hpp\"\
    \n\nnamespace kyopro {\n  template<KYOPRO_BASE_UINT m>\n  struct ModInt {\n  \
    \  using value_type = uint_least_t<bit_len(m * 2 - 2)>;\n\n  private:\n    static\
    \ constexpr value_type mod = m;\n\n  public:\n    value_type value;\n\n    static\
    \ constexpr KYOPRO_BASE_INT get_mod() noexcept {\n      return mod;\n    }\n\n\
    \    constexpr ModInt() noexcept = default;\n    template<class T>\n    constexpr\
    \ ModInt(T value) noexcept: value(floor_mod(value, mod)) {}\n\n    template<class\
    \ T>\n    explicit constexpr operator T() const noexcept { return value; }\n\n\
    \    static constexpr ModInt raw(KYOPRO_BASE_UINT n) noexcept {\n      ModInt\
    \ res;\n      res.value = n;\n      return res;\n    }\n\n    constexpr ModInt\
    \ power(KYOPRO_BASE_UINT n) const noexcept {\n      std::uint_fast64_t res = 1,\
    \ a = value;\n      while (n > 0) {\n        if (n & 1) res = res * a % mod;\n\
    \        a = a * a % mod;\n        n >>= 1;\n      }\n      return res;\n    }\n\
    \n    constexpr ModInt inv() const noexcept {\n      std::uint_fast64_t a = value,\
    \ b = mod;\n      std::int_fast64_t u = 1, v = 0;\n      while (b > 0) {\n   \
    \     std::uint_fast64_t t = a / b;\n        a -= t * b;\n        std::swap(a,\
    \ b);\n        u -= t * v;\n        std::swap(u, v);\n      }\n      return floor_mod(u,\
    \ mod);\n    }\n\n    constexpr ModInt operator +() const noexcept { return *this;\
    \ }\n\n    constexpr ModInt operator -() const noexcept { return value == 0 ?\
    \ 0 : mod - value; }\n\n    constexpr ModInt& operator ++() noexcept {\n     \
    \ if (++value >= mod) value -= mod;\n      return *this;\n    }\n\n    constexpr\
    \ ModInt operator ++(int) noexcept {\n      ModInt before = *this;\n      operator\
    \ ++();\n      return before;\n    }\n\n    constexpr ModInt& operator --() noexcept\
    \ {\n      if (value == 0) value = mod;\n      --value;\n      return *this;\n\
    \    }\n\n    constexpr ModInt operator --(int) noexcept {\n      ModInt before\
    \ = *this;\n      operator --();\n      return before;\n    }\n\n    constexpr\
    \ ModInt& operator +=(ModInt rhs) noexcept {\n      if ((value += rhs.value) >=\
    \ mod) value -= mod;\n      return *this;\n    }\n\n    constexpr ModInt& operator\
    \ -=(ModInt rhs) noexcept {\n      if (value < rhs.value) value += mod;\n    \
    \  value -= rhs.value;\n      return *this;\n    }\n\n    constexpr ModInt& operator\
    \ *=(ModInt rhs) noexcept {\n      value = static_cast<uint_least_t<bit_len(mod)\
    \ * 2>>(value) * rhs.value % mod;\n      return *this;\n    }\n\n    constexpr\
    \ ModInt& operator /=(ModInt rhs) noexcept {\n      value = static_cast<uint_least_t<bit_len(mod)\
    \ * 2>>(value) * rhs.inv().value % mod;\n      return *this;\n    }\n\n    friend\
    \ constexpr ModInt operator +(ModInt lhs, ModInt rhs) noexcept { return lhs +=\
    \ rhs; }\n\n    friend constexpr ModInt operator -(ModInt lhs, ModInt rhs) noexcept\
    \ { return lhs -= rhs; }\n\n    friend constexpr ModInt operator *(ModInt lhs,\
    \ ModInt rhs) noexcept { return lhs *= rhs; }\n\n    friend constexpr ModInt operator\
    \ /(ModInt lhs, ModInt rhs) noexcept { return lhs /= rhs; }\n\n    friend constexpr\
    \ bool operator ==(ModInt lhs, ModInt rhs) noexcept { return lhs.value == rhs.value;\
    \ }\n\n    friend constexpr bool operator !=(ModInt lhs, ModInt rhs) noexcept\
    \ { return lhs.value != rhs.value; }\n\n    template<class Scanner>\n    void\
    \ scan(Scanner& scanner) {\n      std::int_fast64_t value;\n      scanner.scan(value);\n\
    \      value = floor_mod(value, mod);\n    }\n\n    template<class Printer>\n\
    \    void print(Printer& printer) const {\n      printer.print(value);\n    }\n\
    \  };\n\n  template<KYOPRO_BASE_UINT mod>\n  struct Hash<ModInt<mod>> { constexpr\
    \ std::size_t operator ()(ModInt<mod> a) const noexcept { return static_cast<std::size_t>(a);\
    \ } };\n}\n"
  dependsOn:
  - algorithm/bit.hpp
  - meta/settings.hpp
  - algorithm/Hash.hpp
  - meta/trait.hpp
  - meta/constant.hpp
  - math/power.hpp
  - math/mod.hpp
  isVerificationFile: false
  path: math/ModInt.hpp
  requiredBy:
  - math/all.hpp
  - template/all.hpp
  - template/alias.hpp
  - all/all.hpp
  timestamp: '2022-04-22 10:55:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/ModInt.hpp
layout: document
redirect_from:
- /library/math/ModInt.hpp
- /library/math/ModInt.hpp.html
title: math/ModInt.hpp
---
