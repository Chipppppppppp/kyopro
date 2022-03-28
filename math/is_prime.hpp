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
    using _typeDynamicModInt = DynamicModInt<_typeU, KYOPRO_BASE_UINT(-1)>;
    _typeU _n = _x;
    if (_n <= 1) return false;
    if (_n == 2 or _n == 3 or _n == 5 or _n == 7) return true;
    if (_n % 2 == 0 or _n % 3 == 0 or _n % 5 == 0 or _n % 7 == 0) return false;
    if (_n < 121) return _n > 1;
    _typeDynamicModInt::set_mod(_n);
    std::uint_fast64_t _d = (_n - 1) >> trailing_zero(_n - 1);
    _typeDynamicModInt _one = 1, _minus_one = _n - 1;
    auto ng = [&](std::uint_fast64_t _a) noexcept {
      auto _y = _typeDynamicModInt(_a).power(_d);
      std::uint_fast64_t _t = _d;
      while (_y != _one and _y != _minus_one and _t != _n - 1) _y *= _y, _t <<= 1;
      if (_y != _minus_one and !(_t & 1)) return true;
      return false;
    };
    if (std::numeric_limits<_typeU>::digits <= 32 || _n < (static_cast<_typeU>(1) << 32)) {
      for (auto _i: (std::uint_fast64_t[]){2, 7, 61}) {
        if (ng(_i)) return false;
      }
    } else {
      for (auto _i: (std::uint_fast64_t[]){2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
        if (_n <= _i) return true;
        if (ng(_i)) return false;
      }
    }
    return true;
  }
}