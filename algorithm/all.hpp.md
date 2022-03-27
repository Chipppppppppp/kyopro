---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: algorithm/Hash.hpp
    title: algorithm/Hash.hpp
  - icon: ':warning:'
    path: algorithm/bit.hpp
    title: algorithm/bit.hpp
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
    #endif\n#line 5 \"algorithm/bit.hpp\"\n\nnamespace kyopro {\n  template<class\
    \ _typeT>\n  constexpr KYOPRO_BASE_INT pop_count(_typeT _x) noexcept {\n    constexpr\
    \ auto _digits = std::numeric_limits<std::make_unsigned_t<_typeT>>::digits;\n\
    \    static_assert(_digits <= std::numeric_limits<unsigned long long>::digits,\
    \ \"Integer size is too long\");\n    if constexpr (_digits <= std::numeric_limits<unsigned\
    \ int>::digits) return __builtin_popcount(_x);\n    else if constexpr (_digits\
    \ <= std::numeric_limits<unsigned long>::digits) return __builtin_popcountl(_x);\n\
    \    else return __builtin_popcountll(_x);\n  }\n\n  template<class _typeT>\n\
    \  constexpr KYOPRO_BASE_INT leading_zero(_typeT _x) noexcept {\n    constexpr\
    \ auto _digits = std::numeric_limits<std::make_unsigned_t<_typeT>>::digits;\n\
    \    static_assert(_digits <= std::numeric_limits<unsigned long long>::digits,\
    \ \"Integer size is too long\");\n    if (_x == 0) return 0;\n    if constexpr\
    \ (_digits <= std::numeric_limits<unsigned int>::digits) return __builtin_clz(_x)\
    \ + _digits - std::numeric_limits<unsigned int>::digits;\n    else if constexpr\
    \ (_digits <= std::numeric_limits<unsigned long>::digits) return __builtin_clzl(_x)\
    \ + _digits - std::numeric_limits<unsigned long>::digits;\n    else return __builtin_clzll(_x)\
    \ + _digits - std::numeric_limits<unsigned long long>::digits;\n  }\n\n  template<class\
    \ _typeT>\n  constexpr KYOPRO_BASE_INT trailing_zero(_typeT _x) noexcept {\n \
    \   constexpr auto _digits = std::numeric_limits<std::make_unsigned_t<_typeT>>::digits;\n\
    \    static_assert(_digits <= std::numeric_limits<unsigned long long>::digits,\
    \ \"Integer size is too long\");\n    if constexpr (_digits <= std::numeric_limits<unsigned\
    \ int>::digits) return __builtin_ctz(_x);\n    else if constexpr (_digits <= std::numeric_limits<unsigned\
    \ long>::digits) return __builtin_ctzl(_x);\n    else return __builtin_ctzll(_x);\n\
    \  }\n\n  template<class _typeT>\n  constexpr KYOPRO_BASE_INT bit_len(_typeT _x)\
    \ noexcept {\n    constexpr auto _digits = std::numeric_limits<std::make_unsigned_t<_typeT>>::digits;\n\
    \    static_assert(_digits <= std::numeric_limits<unsigned long long>::digits,\
    \ \"Integer size is too long\");\n    if (_x == 0) return 0;\n    if constexpr\
    \ (_digits <= std::numeric_limits<unsigned int>::digits) return std::numeric_limits<unsigned\
    \ int>::digits - __builtin_clz(_x);\n    else if constexpr (_digits <= std::numeric_limits<unsigned\
    \ long>::digits) return std::numeric_limits<unsigned long>::digits - __builtin_clzl(_x);\n\
    \    else return std::numeric_limits<unsigned long long>::digits - __builtin_clzll(_x);\n\
    \  }\n\n  template<class _typeT>\n  constexpr KYOPRO_BASE_INT floor_bit(_typeT\
    \ _x) noexcept {\n    return bit_len(_x >> static_cast<_typeT>(1));\n  }\n\n \
    \ template<class _typeT>\n  constexpr KYOPRO_BASE_INT ceil_bit(_typeT _x) noexcept\
    \ {\n    if (_x == 0) return 0;\n    return bit_len(_x - static_cast<_typeT>(1));\n\
    \  }\n}\n#line 2 \"algorithm/Hash.hpp\"\n#include <cstddef>\n#line 4 \"algorithm/Hash.hpp\"\
    \n#include <functional>\n#include <initializer_list>\n#include <tuple>\n#line\
    \ 8 \"algorithm/Hash.hpp\"\n#include <utility>\n#line 2 \"meta/trait.hpp\"\n#include\
    \ <iterator>\n#include <queue>\n#line 5 \"meta/trait.hpp\"\n#include <stack>\n\
    #line 9 \"meta/trait.hpp\"\n\ntemplate<>\nstruct std::is_integral<__int128_t>:\
    \ std::true_type {};\ntemplate<>\nstruct std::is_signed<__int128_t>: std::true_type\
    \ {};\ntemplate<>\nstruct std::is_integral<__uint128_t>: std::true_type {};\n\
    template<>\nstruct std::is_unsigned<__uint128_t>: std::true_type {};\n#ifdef __SIZEOF_FLOAT128__\n\
    template<>\nstruct std::is_floating_point<__float128>: std::true_type {};\n#endif\n\
    \nnamespace kyopro {\n  template<KYOPRO_BASE_UINT _size>\n  struct int_least {\n\
    \  private:\n    static constexpr auto _get_type() noexcept {\n      if constexpr\
    \ (_size <= 8) return std::int_least8_t();\n      if constexpr (_size <= 16) return\
    \ std::int_least16_t();\n      if constexpr (_size <= 32) return std::int_least32_t();\n\
    \      if constexpr (_size <= 64) return std::int_least64_t();\n      static_assert(_size\
    \ <= 128, \"Integer size is too long\");\n      return __int128_t();\n    }\n\n\
    \  public:\n    using type = decltype(_get_type());\n  };\n\n  template<KYOPRO_BASE_UINT\
    \ _size>\n  using int_least_t = typename int_least<_size>::type;\n\n  template<KYOPRO_BASE_UINT\
    \ _size>\n  struct uint_least {\n  private:\n    static constexpr auto _get_type()\
    \ noexcept {\n      if constexpr (_size <= 8) return std::uint_least8_t();\n \
    \     if constexpr (_size <= 16) return std::uint_least16_t();\n      if constexpr\
    \ (_size <= 32) return std::uint_least32_t();\n      if constexpr (_size <= 64)\
    \ return std::uint_least64_t();\n      static_assert(_size <= 128, \"Integer size\
    \ is too long\");\n      return __uint128_t();\n    }\n\n  public:\n    using\
    \ type = decltype(_get_type());\n  };\n\n  template<KYOPRO_BASE_UINT _size>\n\
    \  using uint_least_t = typename uint_least<_size>::type;\n\n  template<class,\
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
    }\n#line 11 \"algorithm/Hash.hpp\"\n\nnamespace kyopro {\n  template<class, class\
    \ = void>\n  struct Hash;\n\n  template<class _typeT>\n  struct Hash<_typeT, std::enable_if_t<std::is_scalar_v<_typeT>>>\
    \ {\n  private:\n    [[no_unique_address]] std::hash<_typeT> _hashser;\n\n  public:\n\
    \    constexpr std::size_t operator ()(_typeT a) const noexcept {\n      return\
    \ _hasher(a);\n    }\n  };\n\n  template<class _typeT>\n  struct Hash<_typeT,\
    \ std::enable_if_t<is_tuple_v<_typeT>>> {\n    template<std::size_t _i = 0>\n\
    \    constexpr std::size_t operator ()(const _typeT& _a) const noexcept {\n  \
    \    if constexpr (_i == std::tuple_size_v<_typeT>) return std::tuple_size_v<_typeT>;\n\
    \      else {\n        std::uint_fast64_t _seed = operator()<_i + 1>(_a);\n  \
    \      return _seed ^ (Hash<std::tuple_element_t<_i, _typeT>>()(std::get<_i>(_a))\
    \ + 0x9e3779b97f4a7c15LU + (_seed << 12) + (_seed >> 4));\n      }\n    }\n  };\n\
    \n  template<class _typeT>\n  struct Hash<_typeT, std::enable_if_t<is_iterable_v<_typeT>>>\
    \ {\n  private:\n    [[no_unique_address]] Hash<decltype(*std::begin(std::declval<_typeT>()))>\
    \ _hasher;\n\n  public:\n    constexpr std::size_t operator ()(const _typeT& _a)\
    \ const noexcept {\n      std::uint_fast64_t _seed = _a.size();\n      for (auto&\
    \ _i: _a) _seed ^= _hasher(_i) + 0x9e3779b97f4a7c15LU + (_seed << 12) + (_seed\
    \ >> 4);\n      return _seed;\n    }\n  };\n}\n#line 4 \"algorithm/all.hpp\"\n"
  code: '#pragma once

    #include "bit.hpp"

    #include "Hash.hpp"'
  dependsOn:
  - algorithm/bit.hpp
  - meta/settings.hpp
  - algorithm/Hash.hpp
  - meta/trait.hpp
  isVerificationFile: false
  path: algorithm/all.hpp
  requiredBy:
  - all/all.hpp
  timestamp: '2022-03-28 07:02:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/all.hpp
layout: document
redirect_from:
- /library/algorithm/all.hpp
- /library/algorithm/all.hpp.html
title: algorithm/all.hpp
---
