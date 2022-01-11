---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  - icon: ':warning:'
    path: base/Hash.hpp
    title: base/Hash.hpp
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
  bundledCode: "#line 2 \"base/trait.hpp\"\n#include <utility>\n#include <type_traits>\n\
    #include <iterator>\n#include <stack>\n#include <queue>\n\n#ifdef __SIZEOF_INT128__\n\
    struct std::is_integral<__int128_t>: std::true_type {};\nstruct std::is_signed<__int128_t>:\
    \ std::true_type {};\nstruct std::is_integral<__uint128_t>: std::true_type {};\n\
    struct std::is_unsigned<__uint128_t>: std::true_type {};\n#endif\n#ifdef __SIZEOF_FLOAT128__\n\
    struct std::is_floating_point<__float128>: std::true_type {};\n#endif\n\nnamespace\
    \ kyopro {\n  template<class _typeT, class = void>\n  struct is_iterator: std::false_type\
    \ {};\n  template<class _typeT>\n  struct is_iterator<_typeT, std::enable_if_t<!std::is_same_v<typename\
    \ std::iterator_traits<_typeT>::value_type, void>>>: std::true_type {};\n  template<class\
    \ _typeT>\n  constexpr bool is_iterator_v = is_iterator<_typeT>::value;\n\n  template<class\
    \ _typeT, class = void>\n  struct is_container: std::false_type {};\n  template<class\
    \ _typeT>\n  struct is_container<_typeT, std::void_t<decltype(std::begin(std::declval<_typeT>()),\
    \ std::end(std::declval<_typeT>()), std::empty(std::declval<_typeT>()))>>: std::true_type\
    \ {};\n  template<class _typeT>\n  constexpr bool is_container_v = is_container<_typeT>::value;\n\
    \n  template<class _typeT>\n  struct is_tuple: std::false_type {};\n  template<class\
    \ _typeT, class U>\n  struct is_tuple<std::pair<_typeT, U>>: std::true_type {};\n\
    \  template<class... Args>\n  struct is_tuple<std::tuple<Args...>>: std::true_type\
    \ {};\n  template<class _typeT>\n  constexpr bool is_tuple_v = is_tuple<_typeT>::value;\n\
    \n  template<class _typeT>\n  struct is_iterable: is_container<_typeT> {};\n \
    \ template<class _typeT, class Container>\n  struct is_iterable<std::stack<_typeT,\
    \ Container>>: std::false_type {};\n  template<class _typeT, class Container>\n\
    \  struct is_iterable<std::queue<_typeT, Container>>: std::false_type {};\n  template<class\
    \ _typeT, class Container, class Compare>\n  struct is_iterable<std::priority_queue<_typeT,\
    \ Container, Compare>>: std::false_type {};\n  template<class _typeT>\n  constexpr\
    \ bool is_iterable_v = is_iterable<_typeT>::value;\n}\n"
  code: "#pragma once\n#include <utility>\n#include <type_traits>\n#include <iterator>\n\
    #include <stack>\n#include <queue>\n\n#ifdef __SIZEOF_INT128__\nstruct std::is_integral<__int128_t>:\
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
    \ bool is_iterable_v = is_iterable<_typeT>::value;\n}"
  dependsOn: []
  isVerificationFile: false
  path: base/trait.hpp
  requiredBy:
  - math/ModInt.hpp
  - math/all.hpp
  - template/alias.hpp
  - template/all.hpp
  - all.hpp
  - base/Hash.hpp
  - base/all.hpp
  timestamp: '2022-01-11 23:13:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: base/trait.hpp
layout: document
redirect_from:
- /library/base/trait.hpp
- /library/base/trait.hpp.html
title: base/trait.hpp
---
