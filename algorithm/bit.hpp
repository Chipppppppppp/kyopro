#pragma once
#include <limits>
#include <type_traits>
#include "../meta/settings.hpp"

namespace kyopro {
  template<class _typeT>
  constexpr KYOPRO_BASE_INT pop_count(_typeT _x) noexcept {
    constexpr auto _digits = std::numeric_limits<std::make_unsigned_t<_typeT>>::digits;
    static_assert(_digits <= std::numeric_limits<unsigned long long>::digits, "Integer size is too long");
    if constexpr (_digits <= std::numeric_limits<unsigned int>::digits) return __builtin_popcount(_x);
    else if constexpr (_digits <= std::numeric_limits<unsigned long>::digits) return __builtin_popcountl(_x);
    else return __builtin_popcountll(_x);
  }

  template<class _typeT>
  constexpr KYOPRO_BASE_INT leading_zero(_typeT _x) noexcept {
    constexpr auto _digits = std::numeric_limits<std::make_unsigned_t<_typeT>>::digits;
    static_assert(_digits <= std::numeric_limits<unsigned long long>::digits, "Integer size is too long");
    if (_x == 0) return 0;
    if constexpr (_digits <= std::numeric_limits<unsigned int>::digits) return __builtin_clz(_x) + _digits - std::numeric_limits<unsigned int>::digits;
    else if constexpr (_digits <= std::numeric_limits<unsigned long>::digits) return __builtin_clzl(_x) + _digits - std::numeric_limits<unsigned long>::digits;
    else return __builtin_clzll(_x) + _digits - std::numeric_limits<unsigned long long>::digits;
  }

  template<class _typeT>
  constexpr KYOPRO_BASE_INT trailing_zero(_typeT _x) noexcept {
    constexpr auto _digits = std::numeric_limits<std::make_unsigned_t<_typeT>>::digits;
    static_assert(_digits <= std::numeric_limits<unsigned long long>::digits, "Integer size is too long");
    if constexpr (_digits <= std::numeric_limits<unsigned int>::digits) return __builtin_ctz(_x);
    else if constexpr (_digits <= std::numeric_limits<unsigned long>::digits) return __builtin_ctzl(_x);
    else return __builtin_ctzll(_x);
  }

  template<class _typeT>
  constexpr KYOPRO_BASE_INT bit_len(_typeT _x) noexcept {
    constexpr auto _digits = std::numeric_limits<std::make_unsigned_t<_typeT>>::digits;
    static_assert(_digits <= std::numeric_limits<unsigned long long>::digits, "Integer size is too long");
    if (_x == 0) return 0;
    if constexpr (_digits <= std::numeric_limits<unsigned int>::digits) return std::numeric_limits<unsigned int>::digits - __builtin_clz(_x);
    else if constexpr (_digits <= std::numeric_limits<unsigned long>::digits) return std::numeric_limits<unsigned long>::digits - __builtin_clzl(_x);
    else return std::numeric_limits<unsigned long long>::digits - __builtin_clzll(_x);
  }

  template<class _typeT>
  constexpr KYOPRO_BASE_INT floor_bit(_typeT _x) noexcept {
    return bit_len(_x >> static_cast<_typeT>(1));
  }

  template<class _typeT>
  constexpr KYOPRO_BASE_INT ceil_bit(_typeT _x) noexcept {
    if (_x == 0) return 0;
    return bit_len(_x - static_cast<_typeT>(1));
  }
}