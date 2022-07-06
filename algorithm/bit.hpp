#pragma once
#include <limits>
#include <type_traits>
#include "../meta/settings.hpp"

namespace kyopro {
  inline constexpr struct {
    template<class T>
    constexpr KYOPRO_BASE_INT operator ()(T x) noexcept {
      constexpr auto digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;
      static_assert(digits <= std::numeric_limits<unsigned long long>::digits, "Integer size is too large");
      if constexpr (digits <= std::numeric_limits<unsigned int>::digits) return __builtin_popcount(x);
      else if constexpr (digits <= std::numeric_limits<unsigned long>::digits) return __builtin_popcountl(x);
      else return __builtin_popcountll(x);
    }
  } pop_count;

  inline constexpr struct {
    template<class T>
    constexpr KYOPRO_BASE_INT operator ()(T x) noexcept {
      constexpr auto digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;
      static_assert(digits <= std::numeric_limits<unsigned long long>::digits, "Integer size is too large");
      if (x == 0) return 0;
      if constexpr (digits <= std::numeric_limits<unsigned int>::digits) return __builtin_clz(x) + digits - std::numeric_limits<unsigned int>::digits;
      else if constexpr (digits <= std::numeric_limits<unsigned long>::digits) return __builtin_clzl(x) + digits - std::numeric_limits<unsigned long>::digits;
      else return __builtin_clzll(x) + digits - std::numeric_limits<unsigned long long>::digits;
    }
  } leading_zero;

  inline constexpr struct {
    template<class T>
    constexpr KYOPRO_BASE_INT operator ()(T x) noexcept {
      constexpr auto digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;
      static_assert(digits <= std::numeric_limits<unsigned long long>::digits, "Integer size is too large");
      if constexpr (digits <= std::numeric_limits<unsigned int>::digits) return __builtin_ctz(x);
      else if constexpr (digits <= std::numeric_limits<unsigned long>::digits) return __builtin_ctzl(x);
      else return __builtin_ctzll(x);
    }
  } trailing_zero;

  inline constexpr struct {
    template<class T>
    constexpr KYOPRO_BASE_INT operator ()(T x) noexcept {
      constexpr auto digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;
      static_assert(digits <= std::numeric_limits<unsigned long long>::digits, "Integer size is too large");
      if (x == 0) return 0;
      if constexpr (digits <= std::numeric_limits<unsigned int>::digits) return std::numeric_limits<unsigned int>::digits - __builtin_clz(x);
      else if constexpr (digits <= std::numeric_limits<unsigned long>::digits) return std::numeric_limits<unsigned long>::digits - __builtin_clzl(x);
      else return std::numeric_limits<unsigned long long>::digits - __builtin_clzll(x);
    }
  } bit_len;

  inline constexpr struct {
    template<class T>
    constexpr KYOPRO_BASE_INT operator ()(T x) noexcept {
      return bit_len(x >> static_cast<T>(1));
    }
  } floor_bit;

  inline constexpr struct {
    template<class T>
    constexpr KYOPRO_BASE_INT operator ()(T x) noexcept {
      if (x == 0) return 0;
      return bit_len(x - static_cast<T>(1));
    }
  } ceil_bit;
}