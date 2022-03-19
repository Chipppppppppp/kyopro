#pragma once
#include <type_traits>

namespace kyopro {
  template<class _typeT, class _typeU>
  constexpr std::common_type_t<_typeT, _typeU> floor_div(_typeT _x, _typeU _m) noexcept {
    static_assert(std::is_integral_v<_typeT> && std::is_integral_v<_typeU>, "Integer is required");
    if constexpr (std::is_unsigned_v<_typeT> || std::is_unsigned_v<_typeU>) return _x / _m;
    auto _d = _x / _m;
    return _d * _m == _x ? _d : _d - ((_x < 0) ^ (_m < 0));
  }

  template<class _typeT, class _typeU>
  constexpr std::common_type_t<_typeT, _typeU> ceil_div(_typeT _x, _typeU _m) noexcept { return floor_div(_x + _m - static_cast<_typeT>(1), _m); }
}
