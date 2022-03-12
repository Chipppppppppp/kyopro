#pragma once
#include <cstdint>
#include <initializer_list>
#include "../base/settings.hpp"

namespace kyopro {
  constexpr bool is_prime(KYOPRO_BASE_UINT _n) {
    auto modpow = [](std::uint_fast64_t _a, std::uint_fast64_t _n, std::uint_fast64_t _mod) noexcept {
      std::uint_fast64_t _b = _a % _mod;
      std::uint_fast64_t _res = 1;
      while (_n > 0) {
        if (_n & 1) _res = static_cast<__uint128_t>(_res) * _b % _mod;
        _b = static_cast<__uint128_t>(_b) * _b % _mod;
        _n >>= 1;
      }
      return _res;
    };
    if (_n <= 1) return false;
    if (!(_n & 1)) return _n == 2;
    std::uint_fast64_t _d = _n - 1;
    while (!(_d & 1)) _d >>= 1;
    std::uint_fast64_t _e = 1, _rev = _n - 1;
    for (auto _a: (_n < (1ULL << 32) ? std::initializer_list<std::uint_fast64_t>{2, 7, 61} : std::initializer_list<std::uint_fast64_t>{2, 325, 9375, 28178, 450775, 9780504, 1795265022})) {
      if (_n <= _a) break;
      std::uint_fast64_t _t = _d, _y = modpow(_a, _d, _n);
      while (_t != _n - 1 && _y != _e && _y != _rev) {
        _y = static_cast<__uint128_t>(_y) * _y % _n;
        _t <<= 1;
      }
      if (_y != _rev && !(_t & 1)) return false;
    }
    return true;
  }
}