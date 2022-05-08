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
struct std::is_integral<__uint128_t>: std::true_type {};
template<>
struct std::is_floating_point<__float128>: std::true_type {};

namespace kpr {
  template<KYOPRO_BASE_UINT size>
  struct int_least {
  private:
    static constexpr auto get_type() noexcept {
      static_assert(size <= 128, "Integer size is too large");
      if constexpr (size <= 8) return std::int_least8_t();
      else if constexpr (size <= 16) return std::int_least16_t();
      else if constexpr (size <= 32) return std::int_least32_t();
      else if constexpr (size <= 64) return std::int_least64_t();
      else return __int128_t();
    }

  public:
    using type = decltype(get_type());
  };

  template<KYOPRO_BASE_UINT size>
  using int_least_t = typename int_least<size>::type;

  template<KYOPRO_BASE_UINT size>
  struct uint_least {
  private:
    static constexpr auto get_type() noexcept {
      static_assert(size <= 128, "Integer size is too large");
      if constexpr (size <= 8) return std::uint_least8_t();
      else if constexpr (size <= 16) return std::uint_least16_t();
      else if constexpr (size <= 32) return std::uint_least32_t();
      else if constexpr (size <= 64) return std::uint_least64_t();
      else return __uint128_t();
    }

  public:
    using type = decltype(get_type());
  };

  template<KYOPRO_BASE_UINT size>
  using uint_least_t = typename uint_least<size>::type;

  template<class, class = void>
  struct is_iterator: std::false_type {};
  template<class T>
  struct is_iterator<T, std::void_t<typename std::iterator_traits<T>::iterator_category>>: std::true_type {};

  template<class T>
  constexpr bool is_iterator_v = is_iterator<T>::value;

  template<class, class = void>
  struct is_iterable: std::false_type {};
  template<class T>
  struct is_iterable<T, std::void_t<decltype(std::begin(std::declval<T>()))>>: std::true_type {};

  template<class T>
  constexpr bool is_iterable_v = is_iterable<T>::value;

  template<class>
  struct is_tuple: std::false_type {};
  template<class T, class U>
  struct is_tuple<std::pair<T, U>>: std::true_type {};
  template<class... Args>
  struct is_tuple<std::tuple<Args...>>: std::true_type {};

  template<class T>
  constexpr bool is_tuple_v = is_tuple<T>::value;

  template<class T>
  struct iterable_value {
    using type = std::decay_t<decltype(*std::begin(std::declval<T>()))>;
  };

  template<class T>
  using iterable_value_t = typename iterable_value<T>::type;
}