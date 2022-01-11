---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base/settings.hpp
    title: base/settings.hpp
  - icon: ':warning:'
    path: base/trait.hpp
    title: base/trait.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  - icon: ':warning:'
    path: base/all.hpp
    title: base/all.hpp
  - icon: ':warning:'
    path: math/ModInt.hpp
    title: math/ModInt.hpp
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
  bundledCode: "#line 2 \"base/Hash.hpp\"\n#include <type_traits>\n#include <tuple>\n\
    #line 2 \"base/settings.hpp\"\n#include <cstdint>\n\n#ifndef KYOPRO_BASE_INT\n\
    #define KYOPRO_BASE_INT std::int64_t\n#endif\n#ifndef KYOPRO_BASE_UINT\n#define\
    \ KYOPRO_BASE_UINT std::size_t\n#endif\n#ifndef KYOPRO_BASE_FLOAT\n#define KYOPRO_BASE_FLOAT\
    \ double\n#endif\n#ifndef KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD 1000000007\n\
    #endif\n#ifndef KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION 12\n\
    #endif\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV 3\n#endif\n#line 2 \"base/trait.hpp\"\
    \n#include <utility>\n#line 4 \"base/trait.hpp\"\n#include <iterator>\n#include\
    \ <stack>\n#include <queue>\n\n#ifdef __SIZEOF_INT128__\nstruct std::is_integral<__int128_t>:\
    \ std::true_type {};\nstruct std::is_signed<__int128_t>: std::true_type {};\n\
    struct std::is_integral<__uint128_t>: std::true_type {};\nstruct std::is_unsigned<__uint128_t>:\
    \ std::true_type {};\n#endif\n#ifdef __SIZEOF_FLOAT128__\nstruct std::is_floating_point<__float128>:\
    \ std::true_type {};\n#endif\n\nnamespace kyopro {\n  template<class _typeT, class\
    \ = void>\n  struct is_iterator: std::false_type {};\n  template<class _typeT>\n\
    \  struct is_iterator<_typeT, std::enable_if_t<!std::is_same_v<typename std::iterator_traits<_typeT>::value_type,\
    \ void>>>: std::true_type {};\n  template<class _typeT>\n  constexpr bool is_iterator_v\
    \ = is_iterator<_typeT>::value;\n\n  template<class _typeT, class = void>\n  struct\
    \ is_container: std::false_type {};\n  template<class _typeT>\n  struct is_container<_typeT,\
    \ std::void_t<decltype(std::begin(std::declval<_typeT>()), std::end(std::declval<_typeT>()),\
    \ std::empty(std::declval<_typeT>()))>>: std::true_type {};\n  template<class\
    \ _typeT>\n  constexpr bool is_container_v = is_container<_typeT>::value;\n\n\
    \  template<class _typeT>\n  struct is_tuple: std::false_type {};\n  template<class\
    \ _typeT, class U>\n  struct is_tuple<std::pair<_typeT, U>>: std::true_type {};\n\
    \  template<class... Args>\n  struct is_tuple<std::tuple<Args...>>: std::true_type\
    \ {};\n  template<class _typeT>\n  constexpr bool is_tuple_v = is_tuple<_typeT>::value;\n\
    \n  template<class _typeT>\n  struct is_iterable: is_container<_typeT> {};\n \
    \ template<class _typeT, class Container>\n  struct is_iterable<std::stack<_typeT,\
    \ Container>>: std::false_type {};\n  template<class _typeT, class Container>\n\
    \  struct is_iterable<std::queue<_typeT, Container>>: std::false_type {};\n  template<class\
    \ _typeT, class Container, class Compare>\n  struct is_iterable<std::priority_queue<_typeT,\
    \ Container, Compare>>: std::false_type {};\n  template<class _typeT>\n  constexpr\
    \ bool is_iterable_v = is_iterable<_typeT>::value;\n}\n#line 6 \"base/Hash.hpp\"\
    \n\nnamespace kyopro {\n  template<class, class = void>\n  struct Hash;\n\n  template<class\
    \ _typeT>\n  struct Hash<_typeT, std::enable_if_t<std::is_integral_v<_typeT>>>\
    \ { constexpr KYOPRO_BASE_UINT operator ()(_typeT _a) const noexcept { return\
    \ _a; } };\n\n  template<class _typeT>\n  struct Hash<_typeT, std::enable_if_t<std::is_floating_point_v<_typeT>>>\
    \ { constexpr KYOPRO_BASE_UINT operator ()(_typeT _a) const noexcept { return\
    \ (KYOPRO_BASE_UINT)_a & 0xfffff000; } };\n\n  template<class _typeT>\n  struct\
    \ Hash<_typeT, std::enable_if_t<is_tuple_v<_typeT>>> {\n    template<KYOPRO_BASE_UINT\
    \ _i = 0>\n    constexpr KYOPRO_BASE_UINT operator ()(const _typeT& _a) const\
    \ noexcept {\n      if constexpr (_i == std::tuple_size_v<_typeT>) return std::tuple_size_v<_typeT>;\n\
    \      else {\n        KYOPRO_BASE_UINT _seed = operator()<_i + 1>(_a);\n    \
    \    return _seed ^ (Hash<std::tuple_element_t<_i, _typeT>>()(get<_i>(_a)) + 0x9e3779b97f4a7c15LU\
    \ + (_seed << 12) + (_seed >> 4));\n      }\n    }\n  };\n\n  template<class _typeT>\n\
    \  struct Hash<_typeT, std::enable_if_t<is_container_v<_typeT>>> {\n  private:\n\
    \    [[no_unique_address]] Hash<typename _typeT::value_type> make_hash;\n  public:\n\
    \    constexpr KYOPRO_BASE_UINT operator ()(const _typeT& _a) const noexcept {\n\
    \      KYOPRO_BASE_UINT _seed = _a.size();\n      for (auto& _i: _a) _seed ^=\
    \ make_hash(_i) + 0x9e3779b97f4a7c15LU + (_seed << 12) + (_seed >> 4);\n     \
    \ return _seed;\n    }\n  };\n}\n"
  code: "#pragma once\n#include <type_traits>\n#include <tuple>\n#include \"settings.hpp\"\
    \n#include \"trait.hpp\"\n\nnamespace kyopro {\n  template<class, class = void>\n\
    \  struct Hash;\n\n  template<class _typeT>\n  struct Hash<_typeT, std::enable_if_t<std::is_integral_v<_typeT>>>\
    \ { constexpr KYOPRO_BASE_UINT operator ()(_typeT _a) const noexcept { return\
    \ _a; } };\n\n  template<class _typeT>\n  struct Hash<_typeT, std::enable_if_t<std::is_floating_point_v<_typeT>>>\
    \ { constexpr KYOPRO_BASE_UINT operator ()(_typeT _a) const noexcept { return\
    \ (KYOPRO_BASE_UINT)_a & 0xfffff000; } };\n\n  template<class _typeT>\n  struct\
    \ Hash<_typeT, std::enable_if_t<is_tuple_v<_typeT>>> {\n    template<KYOPRO_BASE_UINT\
    \ _i = 0>\n    constexpr KYOPRO_BASE_UINT operator ()(const _typeT& _a) const\
    \ noexcept {\n      if constexpr (_i == std::tuple_size_v<_typeT>) return std::tuple_size_v<_typeT>;\n\
    \      else {\n        KYOPRO_BASE_UINT _seed = operator()<_i + 1>(_a);\n    \
    \    return _seed ^ (Hash<std::tuple_element_t<_i, _typeT>>()(get<_i>(_a)) + 0x9e3779b97f4a7c15LU\
    \ + (_seed << 12) + (_seed >> 4));\n      }\n    }\n  };\n\n  template<class _typeT>\n\
    \  struct Hash<_typeT, std::enable_if_t<is_container_v<_typeT>>> {\n  private:\n\
    \    [[no_unique_address]] Hash<typename _typeT::value_type> make_hash;\n  public:\n\
    \    constexpr KYOPRO_BASE_UINT operator ()(const _typeT& _a) const noexcept {\n\
    \      KYOPRO_BASE_UINT _seed = _a.size();\n      for (auto& _i: _a) _seed ^=\
    \ make_hash(_i) + 0x9e3779b97f4a7c15LU + (_seed << 12) + (_seed >> 4);\n     \
    \ return _seed;\n    }\n  };\n}"
  dependsOn:
  - base/settings.hpp
  - base/trait.hpp
  isVerificationFile: false
  path: base/Hash.hpp
  requiredBy:
  - math/ModInt.hpp
  - math/all.hpp
  - template/alias.hpp
  - template/all.hpp
  - all.hpp
  - base/all.hpp
  timestamp: '2022-01-11 23:13:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: base/Hash.hpp
layout: document
redirect_from:
- /library/base/Hash.hpp
- /library/base/Hash.hpp.html
title: base/Hash.hpp
---
