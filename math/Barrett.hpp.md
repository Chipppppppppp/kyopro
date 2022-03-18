---
data:
  _extendedDependsOn:
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
  - icon: ':warning:'
    path: math/DynamicModInt.hpp
    title: math/DynamicModInt.hpp
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
  bundledCode: "#line 2 \"math/Barrett.hpp\"\n\n#include <cstdint>\n#include <limits>\n\
    #include <type_traits>\n#line 3 \"meta/settings.hpp\"\n\n#ifndef KYOPRO_BASE_INT\n\
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
    \  }\n}\n#line 2 \"meta/trait.hpp\"\n#include <iterator>\n#include <queue>\n#line\
    \ 5 \"meta/trait.hpp\"\n#include <stack>\n#line 7 \"meta/trait.hpp\"\n#include\
    \ <utility>\n#line 9 \"meta/trait.hpp\"\n\ntemplate<>\nstruct std::is_integral<__int128_t>:\
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
    }\n#line 9 \"math/Barrett.hpp\"\n\ntemplate<class _typeT>\nstruct Barrett {\n\
    \  static_assert(std::is_unsigned_v<_typeT>, \"Unsigned integer is required\"\
    );\n\nprivate:\n  using _mul_value_type = uint_least_t<std::numeric_limits<std::make_unsigned_t<_typeT>>::digits\
    \ * 2>;\n  _typeT _mod;\n  _mul_value_type _m;\n\npublic:\n  using value_type\
    \ = _typeT;\n\n  constexpr void set_mod(_typeT _mod) noexcept {\n    this->_mod\
    \ = _mod;\n    _m = (static_cast<_mul_value_type>(1) << 64) / _mod;\n  }\n\n \
    \ constexpr KYOPRO_BASE_INT get_mod() const noexcept {\n    return _mod;\n  }\n\
    \n  Barrett() noexcept = default;\n  Barrett(KYOPRO_BASE_UINT _mod) noexcept:\
    \ _mod(_mod), _m((static_cast<_mul_value_type>(1) << 64) / _mod) {}\n\n  constexpr\
    \ KYOPRO_BASE_UINT operator ()(KYOPRO_BASE_UINT _x) const noexcept {\n\t  _x -=\
    \ static_cast<_typeT>((_x * _m) >> 64) * _mod;\n    return _x < _mod ? _x : _x\
    \ - _mod;\n  }\n};\n"
  code: "#pragma once\n\n#include <cstdint>\n#include <limits>\n#include <type_traits>\n\
    #include \"../algorithm/bit.hpp\"\n#include \"../meta/settings.hpp\"\n#include\
    \ \"../meta/trait.hpp\"\n\ntemplate<class _typeT>\nstruct Barrett {\n  static_assert(std::is_unsigned_v<_typeT>,\
    \ \"Unsigned integer is required\");\n\nprivate:\n  using _mul_value_type = uint_least_t<std::numeric_limits<std::make_unsigned_t<_typeT>>::digits\
    \ * 2>;\n  _typeT _mod;\n  _mul_value_type _m;\n\npublic:\n  using value_type\
    \ = _typeT;\n\n  constexpr void set_mod(_typeT _mod) noexcept {\n    this->_mod\
    \ = _mod;\n    _m = (static_cast<_mul_value_type>(1) << 64) / _mod;\n  }\n\n \
    \ constexpr KYOPRO_BASE_INT get_mod() const noexcept {\n    return _mod;\n  }\n\
    \n  Barrett() noexcept = default;\n  Barrett(KYOPRO_BASE_UINT _mod) noexcept:\
    \ _mod(_mod), _m((static_cast<_mul_value_type>(1) << 64) / _mod) {}\n\n  constexpr\
    \ KYOPRO_BASE_UINT operator ()(KYOPRO_BASE_UINT _x) const noexcept {\n\t  _x -=\
    \ static_cast<_typeT>((_x * _m) >> 64) * _mod;\n    return _x < _mod ? _x : _x\
    \ - _mod;\n  }\n};"
  dependsOn:
  - algorithm/bit.hpp
  - meta/settings.hpp
  - meta/trait.hpp
  isVerificationFile: false
  path: math/Barrett.hpp
  requiredBy:
  - math/DynamicModInt.hpp
  - math/all.hpp
  - template/all.hpp
  - template/alias.hpp
  - all/all.hpp
  timestamp: '2022-03-19 01:10:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/Barrett.hpp
layout: document
redirect_from:
- /library/math/Barrett.hpp
- /library/math/Barrett.hpp.html
title: math/Barrett.hpp
---
