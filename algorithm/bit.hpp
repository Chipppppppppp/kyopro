#pragma once
#include <limits>
#include <type_traits>
#include "../meta/settings.hpp"

namespace kpr {
  template<class T>
  constexpr KYOPRO_BASE_INT pop_count(T x) noexcept {
    constexpr auto digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;
    static_assert(digits <= std::numeric_limits<unsigned long long>::digits, "Integer size is too large");
    if constexpr (digits <= std::numeric_limits<unsigned int>::digits) return __builtin_popcount(x);
    else if constexpr (digits <= std::numeric_limits<unsigned long>::digits) return __builtin_popcountl(x);
    else return __builtin_popcountll(x);
  }

  template<class T>
  constexpr KYOPRO_BASE_INT leading_zero(T x) noexcept {
    constexpr auto digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;
    static_assert(digits <= std::numeric_limits<unsigned long long>::digits, "Integer size is too large");
    if (x == 0) return 0;
    if constexpr (digits <= std::numeric_limits<unsigned int>::digits) return __builtin_clz(x) + digits - std::numeric_limits<unsigned int>::digits;
    else if constexpr (digits <= std::numeric_limits<unsigned long>::digits) return __builtin_clzl(x) + digits - std::numeric_limits<unsigned long>::digits;
    else return __builtin_clzll(x) + digits - std::numeric_limits<unsigned long long>::digits;
  }

  template<class T>
  constexpr KYOPRO_BASE_INT trailing_zero(T x) noexcept {
    constexpr auto digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;
    static_assert(digits <= std::numeric_limits<unsigned long long>::digits, "Integer size is too large");
    if constexpr (digits <= std::numeric_limits<unsigned int>::digits) return __builtin_ctz(x);
    else if constexpr (digits <= std::numeric_limits<unsigned long>::digits) return __builtin_ctzl(x);
    else return __builtin_ctzll(x);
  }

  template<class T>
  constexpr KYOPRO_BASE_INT bit_len(T x) noexcept {
    constexpr auto digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;
    static_assert(digits <= std::numeric_limits<unsigned long long>::digits, "Integer size is too large");
    if (x == 0) return 0;
    if constexpr (digits <= std::numeric_limits<unsigned int>::digits) return std::numeric_limits<unsigned int>::digits - __builtin_clz(x);
    else if constexpr (digits <= std::numeric_limits<unsigned long>::digits) return std::numeric_limits<unsigned long>::digits - __builtin_clzl(x);
    else return std::numeric_limits<unsigned long long>::digits - __builtin_clzll(x);
  }

  template<class T>
  constexpr KYOPRO_BASE_INT floor_bit(T x) noexcept {
    return bit_len(x >> static_cast<T>(1));
  }

  template<class T>
  constexpr KYOPRO_BASE_INT ceil_bit(T x) noexcept {
    if (x == 0) return 0;
    return bit_len(x - static_cast<T>(1));
  }
}