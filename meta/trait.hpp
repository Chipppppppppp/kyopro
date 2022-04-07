#pragma once
#include <iterator>
#include <queue>
#include <limits>
#include <stack>
#include <type_traits>
#include <utility>
#include "settings.hpp"

template<>
struct std::is_integral<__int128_t>: std::true_type {};
template<>
struct std::is_signed<__int128_t>: std::true_type {};
template<>
struct std::is_integral<__uint128_t>: std::true_type {};
template<>
struct std::is_unsigned<__uint128_t>: std::true_type {};
#ifdef __SIZEOF_FLOAT128__
template<>
struct std::is_floating_point<__float128>: std::true_type {};
#endif

namespace kyopro {
  template<KYOPRO_BASE_UINT _size>
  struct int_least {
  private:
    static constexpr auto _get_type() noexcept {
      static_assert(_size <= 128, "Integer size is too long");
      if constexpr (_size <= 8) return std::int_least8_t();
      else if constexpr (_size <= 16) return std::int_least16_t();
      else if constexpr (_size <= 32) return std::int_least32_t();
      else if constexpr (_size <= 64) return std::int_least64_t();
      else return __int128_t();
    }

  public:
    using type = decltype(_get_type());
  };

  template<KYOPRO_BASE_UINT _size>
  using int_least_t = typename int_least<_size>::type;

  template<KYOPRO_BASE_UINT _size>
  struct uint_least {
  private:
    static constexpr auto _get_type() noexcept {
      static_assert(_size <= 128, "Integer size is too long");
      if constexpr (_size <= 8) return std::uint_least8_t();
      else if constexpr (_size <= 16) return std::uint_least16_t();
      else if constexpr (_size <= 32) return std::uint_least32_t();
      else if constexpr (_size <= 64) return std::uint_least64_t();
      else return __uint128_t();
    }

  public:
    using type = decltype(_get_type());
  };

  template<KYOPRO_BASE_UINT _size>
  using uint_least_t = typename uint_least<_size>::type;

  template<class, class = void>
  struct is_iterator: std::false_type {};
  template<class _typeT>
  struct is_iterator<_typeT, std::void_t<typename std::iterator_traits<_typeT>::iterator_category>>: std::true_type {};

  template<class _typeT>
  constexpr bool is_iterator_v = is_iterator<_typeT>::value;

  template<class, class = void>
  struct is_iterable: std::false_type {};
  template<class _typeT>
  struct is_iterable<_typeT, std::enable_if_t<is_iterator_v<decltype(std::begin(std::declval<_typeT>()))>>>: std::true_type {};

  template<class _typeT>
  constexpr bool is_iterable_v = is_iterable<_typeT>::value;

  template<class>
  struct is_tuple: std::false_type {};
  template<class _typeT, class _typeU>
  struct is_tuple<std::pair<_typeT, _typeU>>: std::true_type {};
  template<class... _typeArgs>
  struct is_tuple<std::tuple<_typeArgs...>>: std::true_type {};

  template<class _typeT>
  constexpr bool is_tuple_v = is_tuple<_typeT>::value;

  template<class, class = void>
  struct is_container_adapter: std::false_type {};
  template<class _typeT>
  struct is_container_adapter<_typeT, std::void_t<decltype(std::empty(std::declval<_typeT>()))>>: std::negation<is_iterable<_typeT>> {};

  template<class _typeT>
  constexpr bool is_container_adapter_v = is_container_adapter<_typeT>::value;
}