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
  template<class, class = void>
  struct is_iterator: std::false_type {};
  template<class _typeT>
  struct is_iterator<_typeT, std::void_t<typename std::iterator_traits<_typeT>::iterator_category>>: std::true_type {};
  template<class _typeT>
  constexpr bool is_iterator_v = is_iterator<_typeT>::value;

  template<class, class = void>
  struct is_iterable: std::false_type {};
  template<class _typeT>
  struct is_iterable<_typeT, std::void_t<typename _typeT::iterator>>: std::true_type {};
  template<class _typeT>
  constexpr bool is_iterable_v = is_iterable<_typeT>::value;

  template<class>
  struct is_tuple: std::false_type {};
  template<class _typeT, class U>
  struct is_tuple<std::pair<_typeT, U>>: std::true_type {};
  template<class... Args>
  struct is_tuple<std::tuple<Args...>>: std::true_type {};
  template<class _typeT>
  constexpr bool is_tuple_v = is_tuple<_typeT>::value;

  template<class, class = void>
  struct is_container_adapter: std::false_type {};
  template<class _typeT>
  struct is_container_adapter<_typeT, std::void_t<decltype(std::empty(std::declval<_typeT>()))>>: std::negation<is_iterable<_typeT>> {};
  template<class _typeT>
  constexpr bool is_container_adapter_v = is_container_adapter<_typeT>::value;
}