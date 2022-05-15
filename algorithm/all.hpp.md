---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/Hash.hpp
    title: algorithm/Hash.hpp
  - icon: ':heavy_check_mark:'
    path: algorithm/bit.hpp
    title: algorithm/bit.hpp
  - icon: ':warning:'
    path: algorithm/compress.hpp
    title: algorithm/compress.hpp
  - icon: ':heavy_check_mark:'
    path: meta/settings.hpp
    title: meta/settings.hpp
  - icon: ':heavy_check_mark:'
    path: meta/trait.hpp
    title: meta/trait.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  - icon: ':warning:'
    path: all/all.hpp
    title: all/all.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algorithm/bit.hpp\"\n#include <limits>\n#include <type_traits>\n\
    #line 2 \"meta/settings.hpp\"\n#include <cstdint>\n\n#ifndef KYOPRO_BASE_INT\n\
    #define KYOPRO_BASE_INT std::int64_t\n#endif\n\n#ifndef KYOPRO_BASE_UINT\n#define\
    \ KYOPRO_BASE_UINT std::uint64_t\n#endif\n\n#ifndef KYOPRO_BASE_FLOAT\n#define\
    \ KYOPRO_BASE_FLOAT double\n#endif\n\n#ifndef KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD\
    \ static_cast<KYOPRO_BASE_UINT>(998244353)\n#endif\n\n#ifndef KYOPRO_DECIMAL_PRECISION\n\
    #define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n#endif\n\n\
    #ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 5 \"algorithm/bit.hpp\"\n\nnamespace kpr {\n  template<class T>\n\
    \  constexpr KYOPRO_BASE_INT pop_count(T x) noexcept {\n    constexpr auto digits\
    \ = std::numeric_limits<std::make_unsigned_t<T>>::digits;\n    static_assert(digits\
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
    \ 0;\n    return bit_len(x - static_cast<T>(1));\n  }\n}\n#line 2 \"algorithm/compress.hpp\"\
    \n#include <algorithm>\n#include <functional>\n#include <iterator>\n#include <unordered_map>\n\
    #include <vector>\n#line 8 \"algorithm/compress.hpp\"\n\nnamespace kpr {\n  template<class\
    \ T, class Container = std::unordered_map<typename std::iterator_traits<T>::value_type,\
    \ KYOPRO_BASE_INT>, class Compare>\n  auto compress(T first, T last, Compare comp\
    \ = std::less<typename std::iterator_traits<T>::value_type>()) {\n    std::vector<typename\
    \ std::iterator_traits<T>::value_type> vec(first, last);\n    std::sort(vec.begin(),\
    \ vec.end(), comp);\n    auto end = std::unique(vec.begin(), vec.end());\n   \
    \ Container mem;\n    int cnt = -1;\n    for (auto i = vec.begin(); i != end;\
    \ ++i) mem[*i] = ++cnt;\n    return mem;\n  }\n}\n#line 2 \"algorithm/Hash.hpp\"\
    \n#include <cstddef>\n#line 5 \"algorithm/Hash.hpp\"\n#include <tuple>\n#line\
    \ 7 \"algorithm/Hash.hpp\"\n#include <utility>\n#line 3 \"meta/trait.hpp\"\n#include\
    \ <queue>\n#line 5 \"meta/trait.hpp\"\n#include <stack>\n#line 9 \"meta/trait.hpp\"\
    \n\ntemplate<>\nstruct std::is_integral<__int128_t>: std::true_type {};\ntemplate<>\n\
    struct std::is_integral<__uint128_t>: std::true_type {};\ntemplate<>\nstruct std::is_floating_point<__float128>:\
    \ std::true_type {};\n\nnamespace kpr {\n  template<KYOPRO_BASE_UINT size>\n \
    \ struct int_least {\n  private:\n    static constexpr auto get_type() noexcept\
    \ {\n      static_assert(size <= 128, \"Integer size is too large\");\n      if\
    \ constexpr (size <= 8) return std::int_least8_t();\n      else if constexpr (size\
    \ <= 16) return std::int_least16_t();\n      else if constexpr (size <= 32) return\
    \ std::int_least32_t();\n      else if constexpr (size <= 64) return std::int_least64_t();\n\
    \      else return __int128_t();\n    }\n\n  public:\n    using type = decltype(get_type());\n\
    \  };\n\n  template<KYOPRO_BASE_UINT size>\n  using int_least_t = typename int_least<size>::type;\n\
    \n  template<KYOPRO_BASE_UINT size>\n  struct uint_least {\n  private:\n    static\
    \ constexpr auto get_type() noexcept {\n      static_assert(size <= 128, \"Integer\
    \ size is too large\");\n      if constexpr (size <= 8) return std::uint_least8_t();\n\
    \      else if constexpr (size <= 16) return std::uint_least16_t();\n      else\
    \ if constexpr (size <= 32) return std::uint_least32_t();\n      else if constexpr\
    \ (size <= 64) return std::uint_least64_t();\n      else return __uint128_t();\n\
    \    }\n\n  public:\n    using type = decltype(get_type());\n  };\n\n  template<KYOPRO_BASE_UINT\
    \ size>\n  using uint_least_t = typename uint_least<size>::type;\n\n  template<class,\
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
    \ + (seed << 12) + (seed >> 4);\n      return seed;\n    }\n  };\n}\n#line 5 \"\
    algorithm/all.hpp\"\n"
  code: '#pragma once

    #include "bit.hpp"

    #include "compress.hpp"

    #include "Hash.hpp"'
  dependsOn:
  - algorithm/bit.hpp
  - meta/settings.hpp
  - algorithm/compress.hpp
  - algorithm/Hash.hpp
  - meta/trait.hpp
  isVerificationFile: false
  path: algorithm/all.hpp
  requiredBy:
  - all/all.hpp
  - all.hpp
  timestamp: '2022-05-08 20:22:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/all.hpp
layout: document
redirect_from:
- /library/algorithm/all.hpp
- /library/algorithm/all.hpp.html
title: algorithm/all.hpp
---
