---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: base/Hash.hpp
    title: base/Hash.hpp
  - icon: ':warning:'
    path: base/all.hpp
    title: base/all.hpp
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
    \ kyopro {\n  template<class KyoproT, class = void>\n  struct is_iterator: std::false_type\
    \ {};\n  template<class KyoproT>\n  struct is_iterator<KyoproT, std::enable_if_t<!std::is_same_v<typename\
    \ std::iterator_traits<KyoproT>::value_type, void>>>: std::true_type {};\n  template<class\
    \ KyoproT>\n  constexpr bool is_iterator_v = is_iterator<KyoproT>::value;\n\n\
    \  template<class KyoproT, class = void>\n  struct is_container: std::false_type\
    \ {};\n  template<class KyoproT>\n  struct is_container<KyoproT, std::void_t<decltype(std::begin(std::declval<KyoproT>()),\
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
    \ bool is_iterable_v = is_iterable<KyoproT>::value;\n}\n"
  code: "#pragma once\n#include <utility>\n#include <type_traits>\n#include <iterator>\n\
    #include <stack>\n#include <queue>\n\n#ifdef __SIZEOF_INT128__\nstruct std::is_integral<__int128_t>:\
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
    \ bool is_iterable_v = is_iterable<KyoproT>::value;\n}"
  dependsOn: []
  isVerificationFile: false
  path: base/trait.hpp
  requiredBy:
  - base/Hash.hpp
  - base/all.hpp
  timestamp: '2022-01-10 20:19:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: base/trait.hpp
layout: document
redirect_from:
- /library/base/trait.hpp
- /library/base/trait.hpp.html
title: base/trait.hpp
---
