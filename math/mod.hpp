#pragma once
#include <type_traits>
#include <cassert>

namespace kyopro {
  template<class _typeT, class _typeU>
  constexpr _typeT floor_mod(_typeT _x, _typeU _m) noexcept {
    static_assert(std::is_integral_v<_typeT> && std::is_integral_v<_typeU>);
    if constexpr (std::is_unsigned_v<_typeT>) return _x % _m;
    return (_x %= _m) < 0 ? _x + _m : _x;
  }

  template<class _typeT, class _typeU>
  constexpr _typeT ceil_mod(_typeT _x, _typeU _m) noexcept { return _m - floor_mod(_x - 1, _m) - 1; }
}