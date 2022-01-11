#pragma once
#include <cstdint>

namespace kyopro {
  constexpr bool is_prime(std::uint64_t _n) noexcept {
    if (_n < 2) return false;
    if (_n < 4) return true;
    if ((_n & 1) == 0 || _n % 3 == 0) return false;
    for (std::uint64_t _i = 5; _i * _i <= _n; _i += 4) {
      if (_n % _i == 0) return false;
      if (_n % (_i += 2) == 0) return false;
    }
    return true;
  }
}