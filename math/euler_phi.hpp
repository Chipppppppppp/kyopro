#pragma once
#include <cstdint>

namespace kyopro {
  constexpr std::uint64_t euler_phi(std::uint64_t _n) noexcept {
    std::uint64_t _res = _n;
    if ((_n & 1) == 0) {
      _res -= _res >> 1;
      _n >>= 1;
      while ((_n & 1) == 0) _n >>= 1;
    }
    for (std::uint64_t _i = 3; _i * _i <= _n; _i += 2) {
      if (_n % _i == 0) {
        _res -= _res / _i;
        _n /= _i;
        while (_n % _i == 0) _n /= _i;
      }
    }
    if (_n != 1) _res -= _res / _n;
    return _res;
  }
}