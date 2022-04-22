---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/Hash.hpp
    title: algorithm/Hash.hpp
  - icon: ':heavy_check_mark:'
    path: math/Montgomery.hpp
    title: math/Montgomery.hpp
  - icon: ':question:'
    path: math/power.hpp
    title: math/power.hpp
  - icon: ':heavy_check_mark:'
    path: meta/constant.hpp
    title: meta/constant.hpp
  - icon: ':question:'
    path: meta/settings.hpp
    title: meta/settings.hpp
  - icon: ':question:'
    path: meta/trait.hpp
    title: meta/trait.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all/all.hpp
    title: all/all.hpp
  - icon: ':warning:'
    path: math/all.hpp
    title: math/all.hpp
  - icon: ':heavy_check_mark:'
    path: math/factorize.hpp
    title: math/factorize.hpp
  - icon: ':heavy_check_mark:'
    path: math/is_prime.hpp
    title: math/is_prime.hpp
  - icon: ':warning:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':warning:'
    path: template/all.hpp
    title: template/all.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: aoj/PrimeNumber.test.cpp
    title: aoj/PrimeNumber.test.cpp
  - icon: ':heavy_check_mark:'
    path: yosupo/factorize.test.cpp
    title: yosupo/factorize.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/DynamicModInt.hpp\"\n#include <cassert>\n#include <cstddef>\n\
    #include <limits>\n#include <type_traits>\n#line 3 \"algorithm/Hash.hpp\"\n#include\
    \ <cstdint>\n#include <functional>\n#include <tuple>\n#line 7 \"algorithm/Hash.hpp\"\
    \n#include <utility>\n#line 3 \"meta/settings.hpp\"\n\n#ifndef KYOPRO_BASE_INT\n\
    #define KYOPRO_BASE_INT std::int64_t\n#endif\n\n#ifndef KYOPRO_BASE_UINT\n#define\
    \ KYOPRO_BASE_UINT std::uint64_t\n#endif\n\n#ifndef KYOPRO_BASE_FLOAT\n#define\
    \ KYOPRO_BASE_FLOAT double\n#endif\n\n#ifndef KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD\
    \ static_cast<KYOPRO_BASE_UINT>(998244353)\n#endif\n\n#ifndef KYOPRO_DECIMAL_PRECISION\n\
    #define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n#endif\n\n\
    #ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 2 \"meta/trait.hpp\"\n#include <iterator>\n#include <queue>\n#line\
    \ 5 \"meta/trait.hpp\"\n#include <stack>\n#line 9 \"meta/trait.hpp\"\n\nnamespace\
    \ kyopro {\n  template<KYOPRO_BASE_UINT size>\n  struct int_least {\n  private:\n\
    \    static constexpr auto get_type() noexcept {\n      static_assert(size <=\
    \ 128, \"Integer size is too large\");\n      if constexpr (size <= 8) return\
    \ std::int_least8_t();\n      else if constexpr (size <= 16) return std::int_least16_t();\n\
    \      else if constexpr (size <= 32) return std::int_least32_t();\n      else\
    \ if constexpr (size <= 64) return std::int_least64_t();\n      else return __int128_t();\n\
    \    }\n\n  public:\n    using type = decltype(get_type());\n  };\n\n  template<KYOPRO_BASE_UINT\
    \ size>\n  using int_least_t = typename int_least<size>::type;\n\n  template<KYOPRO_BASE_UINT\
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
    \ std::hash<T> {\n    using value_type = T;\n\n    constexpr std::size_t operator\
    \ ()(T a) const noexcept {\n      return std::hash<T>::operator ()(a);\n    }\n\
    \  };\n\n  template<class T>\n  struct Hash<T, std::enable_if_t<is_tuple_v<T>>>\
    \ {\n    using value_type = T;\n\n    template<KYOPRO_BASE_UINT i = 0>\n    constexpr\
    \ std::size_t operator ()(const T& a) const noexcept {\n      if constexpr (i\
    \ == std::tuple_size_v<T>) return std::tuple_size_v<T>;\n      else {\n      \
    \  std::uint_fast64_t seed = operator()<i + 1>(a);\n        return seed ^ (Hash<std::tuple_element_t<i,\
    \ T>>()(std::get<i>(a)) + 0x9e3779b97f4a7c15LU + (seed << 12) + (seed >> 4));\n\
    \      }\n    }\n  };\n\n  template<class T>\n  struct Hash<T, std::enable_if_t<is_iterable_v<T>>>:\
    \ Hash<iterable_value_t<T>> {\n    using value_type = T;\n\n    constexpr std::size_t\
    \ operator ()(const T& a) const noexcept {\n      std::uint_fast64_t seed = a.size();\n\
    \      for (auto& i: a) seed ^= Hash<iterable_value_t<T>>(i) + 0x9e3779b97f4a7c15LU\
    \ + (seed << 12) + (seed >> 4);\n      return seed;\n    }\n  };\n}\n#line 2 \"\
    meta/constant.hpp\"\n#include <array>\n#line 3 \"math/power.hpp\"\n\nnamespace\
    \ kyopro {\n  template<class T>\n  constexpr T power(T a, KYOPRO_BASE_UINT n,\
    \ T init = 1) noexcept {\n    while (n > 0) {\n      if (n & 1) init *= a;\n \
    \     a *= a;\n      n >>= 1;\n    }\n    return init;\n  }\n}\n#line 7 \"meta/constant.hpp\"\
    \n\nnamespace kyopro {\n  template<class T>\n  inline constexpr T MOD = KYOPRO_DEFAULT_MOD;\n\
    \  inline constexpr KYOPRO_BASE_INT mod = MOD<KYOPRO_BASE_INT>;\n\n  template<class\
    \ T>\n  inline constexpr T INF = std::numeric_limits<T>::max() / KYOPRO_INF_DIV;\n\
    \  inline constexpr KYOPRO_BASE_INT inf = INF<KYOPRO_BASE_INT>;\n\n  template<class\
    \ T, KYOPRO_BASE_UINT decimal_precision = KYOPRO_DECIMAL_PRECISION>\n  inline\
    \ constexpr KYOPRO_BASE_FLOAT EPS = static_cast<T>(1) / power(10ULL, decimal_precision);\n\
    \  inline constexpr KYOPRO_BASE_FLOAT eps = EPS<KYOPRO_BASE_FLOAT>;\n\n  template<class\
    \ T>\n  inline constexpr T PI = 3.14159265358979323846;\n  inline constexpr KYOPRO_BASE_FLOAT\
    \ pi = PI<KYOPRO_BASE_FLOAT>;\n}\n#line 6 \"math/Montgomery.hpp\"\n\nnamespace\
    \ kyopro {\n  template<class T>\n  struct Montgomery {\n    static_assert(std::is_unsigned_v<T>,\
    \ \"Unsigned integer is required\");\n    using value_type = T;\n\n    T mod;\n\
    \n  private:\n    using larger_type = uint_least_t<std::numeric_limits<T>::digits\
    \ * 2>;\n\n    T r, n2;\n\n  public:\n    constexpr void set_mod(T _mod) noexcept\
    \ {\n      mod = _mod;\n      n2 = -static_cast<larger_type>(mod) % mod;\n   \
    \   T t = 0;\n      r = 0;\n      for (int i = 0; i < std::numeric_limits<T>::digits;\
    \ ++i) {\n        if (!(t & 1)) {\n          t += mod;\n          r += static_cast<T>(1)\
    \ << static_cast<T>(i);\n        }\n        t >>= 1;\n      }\n    }\n\n    constexpr\
    \ KYOPRO_BASE_INT get_mod() const noexcept {\n      return mod;\n    }\n\n   \
    \ Montgomery() noexcept = default;\n    Montgomery(T mod) noexcept {\n      set_mod(mod);\n\
    \    }\n\n    constexpr T transform(T x) const noexcept {\n      return reduce(static_cast<larger_type>(x)\
    \ * n2);\n    }\n\n    constexpr T inverse_transform(T x) const noexcept {\n \
    \     T y = reduce(x);\n      return y >= mod ? y - mod : y;\n    }\n\n    constexpr\
    \ T reduce(larger_type x) const noexcept {\n      return (x + static_cast<larger_type>(static_cast<T>(x)\
    \ * r) * mod) >> std::numeric_limits<T>::digits;\n    }\n  };\n}\n#line 10 \"\
    math/DynamicModInt.hpp\"\n\nnamespace kyopro {\n  template<class T, KYOPRO_BASE_UINT\
    \ _kind = 0>\n  struct DynamicModInt {\n    static_assert(std::is_unsigned_v<T>,\
    \ \"T must be unsigned integer\");\n    using value_type = T;\n    static constexpr\
    \ KYOPRO_BASE_INT kind = _kind;\n\n  private:\n    using larger_type = uint_least_t<std::numeric_limits<T>::digits\
    \ * 2>;\n\n    inline static Montgomery<T> montgomery;\n\n  public:\n    T value;\n\
    \n    static void set_mod(T mod) noexcept {\n      montgomery.set_mod(mod);\n\
    \    }\n\n    static KYOPRO_BASE_INT get_mod() noexcept {\n      return montgomery.mod;\n\
    \    }\n\n    KYOPRO_BASE_INT get_val() noexcept {\n      return montgomery.inverse_transform(value);\n\
    \    }\n\n    DynamicModInt() noexcept = default;\n    DynamicModInt(T value)\
    \ noexcept: value(montgomery.transform(value % montgomery.mod + montgomery.mod))\
    \ {}\n\n    template<class U>\n    explicit operator U() const noexcept { return\
    \ montgomery.inverse_transform(value); }\n\n    static DynamicModInt raw(T value)\
    \ noexcept {\n      DynamicModInt res;\n      res.value = montgomery.transform(value);\n\
    \      return res;\n    }\n\n    DynamicModInt power(KYOPRO_BASE_UINT n) const\
    \ noexcept {\n      DynamicModInt res = 1, a = *this;\n      while (n > 0) {\n\
    \        if (n & 1) res = res * a;\n        a = a * a;\n        n >>= 1;\n   \
    \   }\n      return res;\n    }\n\n    DynamicModInt inverse() const noexcept\
    \ {\n      return power(montgomery.mod - 2);\n    }\n\n    DynamicModInt operator\
    \ +() const noexcept { return *this; }\n\n    DynamicModInt operator -() const\
    \ noexcept { return value == 0 ? 0 : montgomery.mod - value; }\n\n    DynamicModInt&\
    \ operator ++() noexcept {\n      operator +=(DynamicModInt::raw(1));\n      return\
    \ *this;\n    }\n\n    DynamicModInt operator ++(int) noexcept {\n      DynamicModInt\
    \ before = *this;\n      operator ++();\n      return before;\n    }\n\n    DynamicModInt&\
    \ operator --() noexcept {\n      operator -=(DynamicModInt::raw(1));\n      return\
    \ *this;\n    }\n\n    DynamicModInt operator --(int) noexcept {\n      DynamicModInt\
    \ before = *this;\n      operator --();\n      return before;\n    }\n\n    DynamicModInt&\
    \ operator +=(DynamicModInt rhs) noexcept {\n      if ((value += rhs.value - (montgomery.mod\
    \ << 1)) > std::numeric_limits<std::make_signed_t<T>>::max()) value += montgomery.mod\
    \ << 1;\n      return *this;\n    }\n\n    DynamicModInt& operator -=(DynamicModInt\
    \ rhs) noexcept {\n      if ((value -= rhs.value) > std::numeric_limits<std::make_signed_t<T>>::max())\
    \ value += montgomery.mod << 1;\n      return *this;\n    }\n\n    DynamicModInt&\
    \ operator *=(DynamicModInt rhs) noexcept {\n      value = montgomery.reduce(static_cast<larger_type>(value)\
    \ * rhs.value);\n      return *this;\n    }\n\n    DynamicModInt& operator /=(DynamicModInt\
    \ rhs) noexcept {\n      value = montgomery.reduce(static_cast<larger_type>(value)\
    \ * rhs.inverse().value);\n      return *this;\n    }\n\n    friend DynamicModInt\
    \ operator +(DynamicModInt lhs, DynamicModInt rhs) noexcept { return lhs += rhs;\
    \ }\n\n    friend DynamicModInt operator -(DynamicModInt lhs, DynamicModInt rhs)\
    \ noexcept { return lhs -= rhs; }\n\n    friend DynamicModInt operator *(DynamicModInt\
    \ lhs, DynamicModInt rhs) noexcept { return lhs *= rhs; }\n\n    friend DynamicModInt\
    \ operator /(DynamicModInt lhs, DynamicModInt rhs) noexcept { return lhs /= rhs;\
    \ }\n\n    friend bool operator ==(DynamicModInt lhs, DynamicModInt rhs) noexcept\
    \ { return lhs.value == rhs.value; }\n\n    friend bool operator !=(DynamicModInt\
    \ lhs, DynamicModInt rhs) noexcept { return lhs.value != rhs.value; }\n\n    template<class\
    \ Scanner>\n    void scan(Scanner& scanner) {\n      std::int_fast64_t value;\n\
    \      scanner.scan(value);\n      value = montgomery.transform(value % montgomery.mod\
    \ + montgomery.mod);\n    }\n\n    template<class Printer>\n    void print(Printer&\
    \ printer) const {\n      printer.print(montgomery.inverse_transform(value));\n\
    \    }\n  };\n\n  template<class T, KYOPRO_BASE_UINT kind>\n  struct Hash<DynamicModInt<T,\
    \ kind>> {\n    using value_type = DynamicModInt<T, kind>;\n\n    std::size_t\
    \ operator ()(DynamicModInt<T, kind> a) const noexcept { return static_cast<std::size_t>(a);\
    \ }\n  };\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <cstddef>\n#include <limits>\n\
    #include <type_traits>\n#include \"../algorithm/Hash.hpp\"\n#include \"../meta/constant.hpp\"\
    \n#include \"../meta/settings.hpp\"\n#include \"Montgomery.hpp\"\n\nnamespace\
    \ kyopro {\n  template<class T, KYOPRO_BASE_UINT _kind = 0>\n  struct DynamicModInt\
    \ {\n    static_assert(std::is_unsigned_v<T>, \"T must be unsigned integer\");\n\
    \    using value_type = T;\n    static constexpr KYOPRO_BASE_INT kind = _kind;\n\
    \n  private:\n    using larger_type = uint_least_t<std::numeric_limits<T>::digits\
    \ * 2>;\n\n    inline static Montgomery<T> montgomery;\n\n  public:\n    T value;\n\
    \n    static void set_mod(T mod) noexcept {\n      montgomery.set_mod(mod);\n\
    \    }\n\n    static KYOPRO_BASE_INT get_mod() noexcept {\n      return montgomery.mod;\n\
    \    }\n\n    KYOPRO_BASE_INT get_val() noexcept {\n      return montgomery.inverse_transform(value);\n\
    \    }\n\n    DynamicModInt() noexcept = default;\n    DynamicModInt(T value)\
    \ noexcept: value(montgomery.transform(value % montgomery.mod + montgomery.mod))\
    \ {}\n\n    template<class U>\n    explicit operator U() const noexcept { return\
    \ montgomery.inverse_transform(value); }\n\n    static DynamicModInt raw(T value)\
    \ noexcept {\n      DynamicModInt res;\n      res.value = montgomery.transform(value);\n\
    \      return res;\n    }\n\n    DynamicModInt power(KYOPRO_BASE_UINT n) const\
    \ noexcept {\n      DynamicModInt res = 1, a = *this;\n      while (n > 0) {\n\
    \        if (n & 1) res = res * a;\n        a = a * a;\n        n >>= 1;\n   \
    \   }\n      return res;\n    }\n\n    DynamicModInt inverse() const noexcept\
    \ {\n      return power(montgomery.mod - 2);\n    }\n\n    DynamicModInt operator\
    \ +() const noexcept { return *this; }\n\n    DynamicModInt operator -() const\
    \ noexcept { return value == 0 ? 0 : montgomery.mod - value; }\n\n    DynamicModInt&\
    \ operator ++() noexcept {\n      operator +=(DynamicModInt::raw(1));\n      return\
    \ *this;\n    }\n\n    DynamicModInt operator ++(int) noexcept {\n      DynamicModInt\
    \ before = *this;\n      operator ++();\n      return before;\n    }\n\n    DynamicModInt&\
    \ operator --() noexcept {\n      operator -=(DynamicModInt::raw(1));\n      return\
    \ *this;\n    }\n\n    DynamicModInt operator --(int) noexcept {\n      DynamicModInt\
    \ before = *this;\n      operator --();\n      return before;\n    }\n\n    DynamicModInt&\
    \ operator +=(DynamicModInt rhs) noexcept {\n      if ((value += rhs.value - (montgomery.mod\
    \ << 1)) > std::numeric_limits<std::make_signed_t<T>>::max()) value += montgomery.mod\
    \ << 1;\n      return *this;\n    }\n\n    DynamicModInt& operator -=(DynamicModInt\
    \ rhs) noexcept {\n      if ((value -= rhs.value) > std::numeric_limits<std::make_signed_t<T>>::max())\
    \ value += montgomery.mod << 1;\n      return *this;\n    }\n\n    DynamicModInt&\
    \ operator *=(DynamicModInt rhs) noexcept {\n      value = montgomery.reduce(static_cast<larger_type>(value)\
    \ * rhs.value);\n      return *this;\n    }\n\n    DynamicModInt& operator /=(DynamicModInt\
    \ rhs) noexcept {\n      value = montgomery.reduce(static_cast<larger_type>(value)\
    \ * rhs.inverse().value);\n      return *this;\n    }\n\n    friend DynamicModInt\
    \ operator +(DynamicModInt lhs, DynamicModInt rhs) noexcept { return lhs += rhs;\
    \ }\n\n    friend DynamicModInt operator -(DynamicModInt lhs, DynamicModInt rhs)\
    \ noexcept { return lhs -= rhs; }\n\n    friend DynamicModInt operator *(DynamicModInt\
    \ lhs, DynamicModInt rhs) noexcept { return lhs *= rhs; }\n\n    friend DynamicModInt\
    \ operator /(DynamicModInt lhs, DynamicModInt rhs) noexcept { return lhs /= rhs;\
    \ }\n\n    friend bool operator ==(DynamicModInt lhs, DynamicModInt rhs) noexcept\
    \ { return lhs.value == rhs.value; }\n\n    friend bool operator !=(DynamicModInt\
    \ lhs, DynamicModInt rhs) noexcept { return lhs.value != rhs.value; }\n\n    template<class\
    \ Scanner>\n    void scan(Scanner& scanner) {\n      std::int_fast64_t value;\n\
    \      scanner.scan(value);\n      value = montgomery.transform(value % montgomery.mod\
    \ + montgomery.mod);\n    }\n\n    template<class Printer>\n    void print(Printer&\
    \ printer) const {\n      printer.print(montgomery.inverse_transform(value));\n\
    \    }\n  };\n\n  template<class T, KYOPRO_BASE_UINT kind>\n  struct Hash<DynamicModInt<T,\
    \ kind>> {\n    using value_type = DynamicModInt<T, kind>;\n\n    std::size_t\
    \ operator ()(DynamicModInt<T, kind> a) const noexcept { return static_cast<std::size_t>(a);\
    \ }\n  };\n}\n"
  dependsOn:
  - algorithm/Hash.hpp
  - meta/settings.hpp
  - meta/trait.hpp
  - meta/constant.hpp
  - math/power.hpp
  - math/Montgomery.hpp
  isVerificationFile: false
  path: math/DynamicModInt.hpp
  requiredBy:
  - math/factorize.hpp
  - math/is_prime.hpp
  - math/all.hpp
  - template/all.hpp
  - template/alias.hpp
  - all/all.hpp
  timestamp: '2022-04-22 21:51:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - aoj/PrimeNumber.test.cpp
  - yosupo/factorize.test.cpp
documentation_of: math/DynamicModInt.hpp
layout: document
redirect_from:
- /library/math/DynamicModInt.hpp
- /library/math/DynamicModInt.hpp.html
title: math/DynamicModInt.hpp
---
