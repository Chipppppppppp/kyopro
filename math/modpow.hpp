#pragma once
#include <cstdint>
#include <type_traits>
#include "../base/settings.hpp"
#include "mod.hpp"

namespace kyopro {
  template<class _typeT>
  constexpr _typeT modpow(_typeT _a, KYOPRO_BASE_UINT _n, KYOPRO_BASE_UINT _mod) noexcept {
    static_assert(std::is_integral_v<_typeT>);
    std::uint_fast64_t _b = floor_mod(_a, static_cast<_typeT>(_mod));
    std::uint_fast64_t _res = 1;
    while (_n > 0) {
      if (_n & 1) _res = _res * _b % _mod;
      _b = _b * _b % _mod;
      _n >>= 1;
    }
    return static_cast<_typeT>(_res);
  }
}