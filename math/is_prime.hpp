#pragma once
#include <cstdint>
#include <type_traits>
#include "../algorithm/bit.hpp"
#include "../meta/settings.hpp"
#include "DynamicModInt.hpp"

namespace kyopro {
  template<class _typeT>
  constexpr bool is_prime(_typeT _x) {
    using _typeU = std::make_unsigned_t<_typeT>;
    using _typeModInt = DynamicModInt<_typeU, -1>;
    _typeU _n = _x;
    if (_n <= 1) return false;
    if (!(_n & 1)) return _n == 2;
    _typeModInt::set_mod(_n);
    std::uint_fast64_t _d = (_n - 1) >> trailing_zero(_n - 1);
    _typeModInt _one = 1, _minus_one = _n - 1;
    auto ok = [&](std::uint_fast64_t _a) noexcept {
      auto _y = _typeModInt(_a).power(_d);
      std::uint_fast64_t _t = _d;
      while (_y != _one and _y != _minus_one and _t != _x - 1) _y *= _y, _t <<= 1;
      if (_y != _minus_one and !(_t & 1)) return false;
      return true;
    };
    if (std::numeric_limits<_typeU>::digits <= 32 || _n < (static_cast<_typeU>(1) << 32)) {
      for (auto _i: (std::uint_fast64_t[]){2, 7, 61}) if (!ok(_i)) return false;
    } else {
      for (auto _i: (std::uint_fast64_t[]){2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
        if (x <= a) return true;
        if (!ok(a)) return false;
      }
    }
    return true;
  }
}