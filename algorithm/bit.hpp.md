---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: meta/settings.hpp
    title: meta/settings.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: algorithm/all.hpp
    title: algorithm/all.hpp
  - icon: ':warning:'
    path: math/ModInt.hpp
    title: math/ModInt.hpp
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
    \  }\n}\n"
  code: "#pragma once\n#include <limits>\n#include <type_traits>\n#include \"../meta/settings.hpp\"\
    \n\nnamespace kyopro {\n  template<class _typeT>\n  constexpr KYOPRO_BASE_INT\
    \ pop_count(_typeT _x) noexcept {\n    constexpr auto _digits = std::numeric_limits<std::make_unsigned_t<_typeT>>::digits;\n\
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
    \  }\n}"
  dependsOn:
  - meta/settings.hpp
  isVerificationFile: false
  path: algorithm/bit.hpp
  requiredBy:
  - math/ModInt.hpp
  - template/all.hpp
  - template/alias.hpp
  - algorithm/all.hpp
  timestamp: '2022-03-19 00:51:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/bit.hpp
layout: document
redirect_from:
- /library/algorithm/bit.hpp
- /library/algorithm/bit.hpp.html
title: algorithm/bit.hpp
---
