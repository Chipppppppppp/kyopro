#pragma once
#include <utility>
#include <type_traits>
#include <iterator>
#include <stack>
#include <queue>

#ifdef __SIZEOF_INT128__
struct std::is_integral<__int128_t>: std::true_type {};
struct std::is_signed<__int128_t>: std::true_type {};
struct std::is_integral<__uint128_t>: std::true_type {};
struct std::is_unsigned<__uint128_t>: std::true_type {};
#endif
#ifdef __SIZEOF_FLOAT128__
struct std::is_floating_point<__float128>: std::true_type {};
#endif

namespace kyopro {
  template<class KyoproT, class = void>
  struct is_iterator: std::false_type {};
  template<class KyoproT>
  struct is_iterator<KyoproT, std::enable_if_t<!std::is_same_v<typename std::iterator_traits<KyoproT>::value_type, void>>>: std::true_type {};
  template<class KyoproT>
  constexpr bool is_iterator_v = is_iterator<KyoproT>::value;

  template<class KyoproT, class = void>
  struct is_container: std::false_type {};
  template<class KyoproT>
  struct is_container<KyoproT, std::void_t<decltype(std::begin(std::declval<KyoproT>()), std::end(std::declval<KyoproT>()), std::empty(std::declval<KyoproT>()))>>: std::true_type {};
  template<class KyoproT>
  constexpr bool is_container_v = is_container<KyoproT>::value;

  template<class KyoproT>
  struct is_tuple: std::false_type {};
  template<class KyoproT, class U>
  struct is_tuple<std::pair<KyoproT, U>>: std::true_type {};
  template<class... Args>
  struct is_tuple<std::tuple<Args...>>: std::true_type {};
  template<class KyoproT>
  constexpr bool is_tuple_v = is_tuple<KyoproT>::value;

  template<class KyoproT>
  struct is_iterable: is_container<KyoproT> {};
  template<class KyoproT, class Container>
  struct is_iterable<std::stack<KyoproT, Container>>: std::false_type {};
  template<class KyoproT, class Container>
  struct is_iterable<std::queue<KyoproT, Container>>: std::false_type {};
  template<class KyoproT, class Container, class Compare>
  struct is_iterable<std::priority_queue<KyoproT, Container, Compare>>: std::false_type {};
  template<class KyoproT>
  constexpr bool is_iterable_v = is_iterable<KyoproT>::value;
}