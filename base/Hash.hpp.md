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
    path: base/all.hpp
    title: base/all.hpp
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
    \ << 12) + (kyopro_seed >> 4);\n      return kyopro_seed;\n    }\n  };\n}\n"
  code: "#pragma once\n#include <type_traits>\n#include <tuple>\n#include \"settings.hpp\"\
    \n#include \"trait.hpp\"\n\nnamespace kyopro {\n  template<class, class = void>\n\
    \  struct Hash;\n\n  template<class KyoproT>\n  struct Hash<KyoproT, std::enable_if_t<std::is_integral_v<KyoproT>>>\
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
    \ << 12) + (kyopro_seed >> 4);\n      return kyopro_seed;\n    }\n  };\n}"
  dependsOn:
  - base/settings.hpp
  - base/trait.hpp
  isVerificationFile: false
  path: base/Hash.hpp
  requiredBy:
  - base/all.hpp
  timestamp: '2022-01-10 20:19:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: base/Hash.hpp
layout: document
redirect_from:
- /library/base/Hash.hpp
- /library/base/Hash.hpp.html
title: base/Hash.hpp
---
