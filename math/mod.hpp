#pragma once
#include <cassert>
#include <type_traits>

namespace kyopro {
  template<class _typeT, class _typeU>
  constexpr std::common_type_t<_typeT, _typeU> floor_mod(_typeT _x, _typeU _m) noexcept {
    static_assert(std::is_integral_v<_typeT> && std::is_integral_v<_typeU>, "Integer is required");
    if constexpr (std::is_unsigned_v<_typeT> || std::is_unsigned_v<_typeU>) return _x % _m;
    return (_x %= _m) < 0 ? _x + _m : _x;
  }

  template<class _typeT, class _typeU>
  constexpr std::common_type_t<_typeT, _typeU> ceil_mod(_typeT _x, _typeU _m) noexcept {
    return _m - floor_mod(_x - 1, _m) - static_cast<_typeT>(1);
  }
}
