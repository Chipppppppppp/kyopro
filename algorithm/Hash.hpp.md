---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: meta/settings.hpp
    title: meta/settings.hpp
  - icon: ':heavy_check_mark:'
    path: meta/trait.hpp
    title: meta/trait.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: algorithm/all.hpp
    title: algorithm/all.hpp
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  - icon: ':warning:'
    path: all/all.hpp
    title: all/all.hpp
  - icon: ':heavy_check_mark:'
    path: math/DynamicModInt.hpp
    title: math/DynamicModInt.hpp
  - icon: ':warning:'
    path: math/ModInt.hpp
    title: math/ModInt.hpp
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
    path: verify/aoj/PrimeNumber.test.cpp
    title: verify/aoj/PrimeNumber.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/factorize.test.cpp
    title: verify/yosupo/factorize.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algorithm/Hash.hpp\"\n#include <cstddef>\n#include <cstdint>\n\
    #include <functional>\n#include <tuple>\n#include <type_traits>\n#include <utility>\n\
    #line 3 \"meta/settings.hpp\"\n\n#ifndef KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT\
    \ std::int64_t\n#endif\n\n#ifndef KYOPRO_BASE_UINT\n#define KYOPRO_BASE_UINT std::uint64_t\n\
    #endif\n\n#ifndef KYOPRO_BASE_FLOAT\n#define KYOPRO_BASE_FLOAT double\n#endif\n\
    \n#ifndef KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD static_cast<KYOPRO_BASE_UINT>(998244353)\n\
    #endif\n\n#ifndef KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n\
    #endif\n\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 2 \"meta/trait.hpp\"\n#include <iterator>\n#include <queue>\n#include\
    \ <limits>\n#include <stack>\n#line 9 \"meta/trait.hpp\"\n\ntemplate<>\nstruct\
    \ std::is_integral<__int128_t>: std::true_type {};\ntemplate<>\nstruct std::is_integral<__uint128_t>:\
    \ std::true_type {};\ntemplate<>\nstruct std::is_floating_point<__float128>: std::true_type\
    \ {};\n\nnamespace kpr {\n  template<KYOPRO_BASE_UINT size>\n  struct int_least\
    \ {\n  private:\n    static constexpr auto get_type() noexcept {\n      static_assert(size\
    \ <= 128, \"Integer size is too large\");\n      if constexpr (size <= 8) return\
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
    \  };\n\n  template<class T>\n  using iterable_value_t = typename iterable_value<T>::type;\n\
    }\n#line 10 \"algorithm/Hash.hpp\"\n\nnamespace kpr {\n  template<class, class\
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
    \ + (seed << 12) + (seed >> 4);\n      return seed;\n    }\n  };\n}\n"
  code: "#pragma once\n#include <cstddef>\n#include <cstdint>\n#include <functional>\n\
    #include <tuple>\n#include <type_traits>\n#include <utility>\n#include \"../meta/settings.hpp\"\
    \n#include \"../meta/trait.hpp\"\n\nnamespace kpr {\n  template<class, class =\
    \ void>\n  struct Hash;\n\n  template<class T>\n  struct Hash<T, std::enable_if_t<std::is_scalar_v<T>>>:\
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
    \ + (seed << 12) + (seed >> 4);\n      return seed;\n    }\n  };\n}"
  dependsOn:
  - meta/settings.hpp
  - meta/trait.hpp
  isVerificationFile: false
  path: algorithm/Hash.hpp
  requiredBy:
  - algorithm/all.hpp
  - math/DynamicModInt.hpp
  - math/ModInt.hpp
  - math/all.hpp
  - math/is_prime.hpp
  - math/factorize.hpp
  - all.hpp
  - template/all.hpp
  - template/alias.hpp
  - all/all.hpp
  timestamp: '2022-05-08 20:22:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/PrimeNumber.test.cpp
  - verify/yosupo/factorize.test.cpp
documentation_of: algorithm/Hash.hpp
layout: document
redirect_from:
- /library/algorithm/Hash.hpp
- /library/algorithm/Hash.hpp.html
title: algorithm/Hash.hpp
---
