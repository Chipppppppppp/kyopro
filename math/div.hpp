#pragma once
#include <type_traits>

namespace kyopro {
  template<class _typeT, class _typeU>
  constexpr _typeT floor_div(_typeT _x, _typeU _m) noexcept {
    static_assert(std::is_integral_v<_typeT> && std::is_integral_v<_typeU>);
    if constexpr (std::is_unsigned_v<_typeT>) return _x / _m;
    if (_m < 0) return -_x / -_m;
    if (_x < 0) return (_x + 1) / _m - 1;
    return _x / _m;
  }

  template<class _typeT, class _typeU>
  constexpr _typeT ceil_div(_typeT _x, _typeU _m) noexcept { return floor_div(_x + _m - 1, _m); }
}