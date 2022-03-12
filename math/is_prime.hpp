#pragma once
#include <array>
#include <cstdint>
#include "../base/settings.hpp"
#include "modpow.hpp"

namespace kyopro {
  constexpr bool is_prime(KYOPRO_BASE_UINT _n) {
    if (_n <= 1) return false;
    if (~_n & 1) return _n == 2;
    std::uint_fast64_t _d = _n - 1;
    while (~_d & 1) _d >>= 1;
    std::uint_fast64_t _e = 1, _rev = _n - 1;
    for (auto _a: std::array<std::uint_fast64_t, 7>{2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
      if (_n <= _a) break;
      std::uint_fast64_t _t = _d, _y = modpow(_a, _t, _n);
      while (_t != _n - 1 && _y != _e && _y != _rev) {
        _y = _y * _y % _n;
        _t <<= 1;
      }
      if (_y != _rev && !(_t & 1)) return false;
    }
    return true;
  }
}