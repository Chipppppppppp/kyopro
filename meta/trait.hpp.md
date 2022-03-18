---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: meta/settings.hpp
    title: meta/settings.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: algorithm/Hash.hpp
    title: algorithm/Hash.hpp
  - icon: ':warning:'
    path: algorithm/all.hpp
    title: algorithm/all.hpp
  - icon: ':warning:'
    path: all/all.hpp
    title: all/all.hpp
  - icon: ':warning:'
    path: math/Barrett.hpp
    title: math/Barrett.hpp
  - icon: ':warning:'
    path: math/DynamicModInt.hpp
    title: math/DynamicModInt.hpp
  - icon: ':warning:'
    path: math/ModInt.hpp
    title: math/ModInt.hpp
  - icon: ':warning:'
    path: math/all.hpp
    title: math/all.hpp
  - icon: ':warning:'
    path: meta/all.hpp
    title: meta/all.hpp
  - icon: ':heavy_check_mark:'
    path: system/all.hpp
    title: system/all.hpp
  - icon: ':heavy_check_mark:'
    path: system/in.hpp
    title: system/in.hpp
  - icon: ':heavy_check_mark:'
    path: system/out.hpp
    title: system/out.hpp
  - icon: ':warning:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':warning:'
    path: template/all.hpp
    title: template/all.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: yosupo/UnionFind.test.cpp
    title: yosupo/UnionFind.test.cpp
  - icon: ':heavy_check_mark:'
    path: yosupo/many_aplusb.test.cpp
    title: yosupo/many_aplusb.test.cpp
  - icon: ':heavy_check_mark:'
    path: yosupo/point_add_range_sum.test.cpp
    title: yosupo/point_add_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"meta/trait.hpp\"\n#include <iterator>\n#include <queue>\n\
    #include <limits>\n#include <stack>\n#include <type_traits>\n#include <utility>\n\
    #line 2 \"meta/settings.hpp\"\n#include <cstdint>\n\n#ifndef KYOPRO_BASE_INT\n\
    #define KYOPRO_BASE_INT std::int64_t\n#endif\n\n#ifndef KYOPRO_BASE_UINT\n#define\
    \ KYOPRO_BASE_UINT std::uint64_t\n#endif\n\n#ifndef KYOPRO_BASE_FLOAT\n#define\
    \ KYOPRO_BASE_FLOAT double\n#endif\n\n#ifndef KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD\
    \ static_cast<KYOPRO_BASE_UINT>(998244353)\n#endif\n\n#ifndef KYOPRO_DECIMAL_PRECISION\n\
    #define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n#endif\n\n\
    #ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 9 \"meta/trait.hpp\"\n\ntemplate<>\nstruct std::is_integral<__int128_t>:\
    \ std::true_type {};\ntemplate<>\nstruct std::is_signed<__int128_t>: std::true_type\
    \ {};\ntemplate<>\nstruct std::is_integral<__uint128_t>: std::true_type {};\n\
    template<>\nstruct std::is_unsigned<__uint128_t>: std::true_type {};\n#ifdef __SIZEOF_FLOAT128__\n\
    template<>\nstruct std::is_floating_point<__float128>: std::true_type {};\n#endif\n\
    \nnamespace kyopro {\n  template<KYOPRO_BASE_UINT _size>\n  struct int_least {\n\
    \  private:\n    static constexpr auto _get_type() noexcept {\n      if constexpr\
    \ (_size <= 8) return std::declval<std::int_least8_t>();\n      if constexpr (_size\
    \ <= 16) return std::declval<std::int_least16_t>();\n      if constexpr (_size\
    \ <= 32) return std::declval<std::int_least32_t>();\n      if constexpr (_size\
    \ <= 64) return std::declval<std::int_least64_t>();\n      static_assert(_size\
    \ <= 128, \"Integer size is too long\");\n      return std::declval<__int128_t>();\n\
    \    }\n\n  public:\n    using type = decltype(_get_type());\n  };\n\n  template<KYOPRO_BASE_UINT\
    \ _size>\n  using int_least_t = typename int_least<_size>::type;\n\n  template<KYOPRO_BASE_UINT\
    \ _size>\n  struct uint_least {\n  private:\n    static constexpr auto _get_type()\
    \ noexcept {\n      if constexpr (_size <= 8) return std::declval<std::uint_least8_t>();\n\
    \      if constexpr (_size <= 16) return std::declval<std::uint_least16_t>();\n\
    \      if constexpr (_size <= 32) return std::declval<std::uint_least32_t>();\n\
    \      if constexpr (_size <= 64) return std::declval<std::uint_least64_t>();\n\
    \      static_assert(_size <= 128, \"Integer size is too long\");\n      return\
    \ std::declval<__uint128_t>();\n    }\n\n  public:\n    using type = decltype(_get_type());\n\
    \  };\n\n  template<KYOPRO_BASE_UINT _size>\n  using uint_least_t = typename uint_least<_size>::type;\n\
    \n  template<class, class = void>\n  struct is_iterator: std::false_type {};\n\
    \  template<class _typeT>\n  struct is_iterator<_typeT, std::void_t<typename std::iterator_traits<_typeT>::iterator_category>>:\
    \ std::true_type {};\n\n  template<class _typeT>\n  constexpr bool is_iterator_v\
    \ = is_iterator<_typeT>::value;\n\n  template<class, class = void>\n  struct is_iterable:\
    \ std::false_type {};\n  template<class _typeT>\n  struct is_iterable<_typeT,\
    \ std::enable_if_t<is_iterator_v<decltype(std::begin(std::declval<_typeT>()))>>>:\
    \ std::true_type {};\n\n  template<class _typeT>\n  constexpr bool is_iterable_v\
    \ = is_iterable<_typeT>::value;\n\n  template<class>\n  struct is_tuple: std::false_type\
    \ {};\n  template<class _typeT, class _typeU>\n  struct is_tuple<std::pair<_typeT,\
    \ _typeU>>: std::true_type {};\n  template<class... _typeArgs>\n  struct is_tuple<std::tuple<_typeArgs...>>:\
    \ std::true_type {};\n\n  template<class _typeT>\n  constexpr bool is_tuple_v\
    \ = is_tuple<_typeT>::value;\n\n  template<class, class = void>\n  struct is_container_adapter:\
    \ std::false_type {};\n  template<class _typeT>\n  struct is_container_adapter<_typeT,\
    \ std::void_t<decltype(std::empty(std::declval<_typeT>()))>>: std::negation<is_iterable<_typeT>>\
    \ {};\n\n  template<class _typeT>\n  constexpr bool is_container_adapter_v = is_container_adapter<_typeT>::value;\n\
    }\n"
  code: "#pragma once\n#include <iterator>\n#include <queue>\n#include <limits>\n\
    #include <stack>\n#include <type_traits>\n#include <utility>\n#include \"settings.hpp\"\
    \n\ntemplate<>\nstruct std::is_integral<__int128_t>: std::true_type {};\ntemplate<>\n\
    struct std::is_signed<__int128_t>: std::true_type {};\ntemplate<>\nstruct std::is_integral<__uint128_t>:\
    \ std::true_type {};\ntemplate<>\nstruct std::is_unsigned<__uint128_t>: std::true_type\
    \ {};\n#ifdef __SIZEOF_FLOAT128__\ntemplate<>\nstruct std::is_floating_point<__float128>:\
    \ std::true_type {};\n#endif\n\nnamespace kyopro {\n  template<KYOPRO_BASE_UINT\
    \ _size>\n  struct int_least {\n  private:\n    static constexpr auto _get_type()\
    \ noexcept {\n      if constexpr (_size <= 8) return std::declval<std::int_least8_t>();\n\
    \      if constexpr (_size <= 16) return std::declval<std::int_least16_t>();\n\
    \      if constexpr (_size <= 32) return std::declval<std::int_least32_t>();\n\
    \      if constexpr (_size <= 64) return std::declval<std::int_least64_t>();\n\
    \      static_assert(_size <= 128, \"Integer size is too long\");\n      return\
    \ std::declval<__int128_t>();\n    }\n\n  public:\n    using type = decltype(_get_type());\n\
    \  };\n\n  template<KYOPRO_BASE_UINT _size>\n  using int_least_t = typename int_least<_size>::type;\n\
    \n  template<KYOPRO_BASE_UINT _size>\n  struct uint_least {\n  private:\n    static\
    \ constexpr auto _get_type() noexcept {\n      if constexpr (_size <= 8) return\
    \ std::declval<std::uint_least8_t>();\n      if constexpr (_size <= 16) return\
    \ std::declval<std::uint_least16_t>();\n      if constexpr (_size <= 32) return\
    \ std::declval<std::uint_least32_t>();\n      if constexpr (_size <= 64) return\
    \ std::declval<std::uint_least64_t>();\n      static_assert(_size <= 128, \"Integer\
    \ size is too long\");\n      return std::declval<__uint128_t>();\n    }\n\n \
    \ public:\n    using type = decltype(_get_type());\n  };\n\n  template<KYOPRO_BASE_UINT\
    \ _size>\n  using uint_least_t = typename uint_least<_size>::type;\n\n  template<class,\
    \ class = void>\n  struct is_iterator: std::false_type {};\n  template<class _typeT>\n\
    \  struct is_iterator<_typeT, std::void_t<typename std::iterator_traits<_typeT>::iterator_category>>:\
    \ std::true_type {};\n\n  template<class _typeT>\n  constexpr bool is_iterator_v\
    \ = is_iterator<_typeT>::value;\n\n  template<class, class = void>\n  struct is_iterable:\
    \ std::false_type {};\n  template<class _typeT>\n  struct is_iterable<_typeT,\
    \ std::enable_if_t<is_iterator_v<decltype(std::begin(std::declval<_typeT>()))>>>:\
    \ std::true_type {};\n\n  template<class _typeT>\n  constexpr bool is_iterable_v\
    \ = is_iterable<_typeT>::value;\n\n  template<class>\n  struct is_tuple: std::false_type\
    \ {};\n  template<class _typeT, class _typeU>\n  struct is_tuple<std::pair<_typeT,\
    \ _typeU>>: std::true_type {};\n  template<class... _typeArgs>\n  struct is_tuple<std::tuple<_typeArgs...>>:\
    \ std::true_type {};\n\n  template<class _typeT>\n  constexpr bool is_tuple_v\
    \ = is_tuple<_typeT>::value;\n\n  template<class, class = void>\n  struct is_container_adapter:\
    \ std::false_type {};\n  template<class _typeT>\n  struct is_container_adapter<_typeT,\
    \ std::void_t<decltype(std::empty(std::declval<_typeT>()))>>: std::negation<is_iterable<_typeT>>\
    \ {};\n\n  template<class _typeT>\n  constexpr bool is_container_adapter_v = is_container_adapter<_typeT>::value;\n\
    }"
  dependsOn:
  - meta/settings.hpp
  isVerificationFile: false
  path: meta/trait.hpp
  requiredBy:
  - math/Barrett.hpp
  - math/ModInt.hpp
  - math/DynamicModInt.hpp
  - math/all.hpp
  - template/all.hpp
  - template/alias.hpp
  - algorithm/all.hpp
  - algorithm/Hash.hpp
  - all/all.hpp
  - meta/all.hpp
  - system/in.hpp
  - system/out.hpp
  - system/all.hpp
  timestamp: '2022-03-19 00:51:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - yosupo/UnionFind.test.cpp
  - yosupo/point_add_range_sum.test.cpp
  - yosupo/many_aplusb.test.cpp
documentation_of: meta/trait.hpp
layout: document
redirect_from:
- /library/meta/trait.hpp
- /library/meta/trait.hpp.html
title: meta/trait.hpp
---
