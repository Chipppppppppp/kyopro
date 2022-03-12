#include <array>
#include <cstdint>
#include "../base/settings.hpp"
#include "../math/modpow.hpp"

namespace kyopro {
  template<KYOPRO_BASE_UINT _size>
  bool miller_rabin(KYOPRO_BASE_UINT _n, const std::array<KYOPRO_BASE_UINT, _size>& _as) {
    std::uint_fast64_t _d = _n - 1;
    while (~_d & 1) _d >>= 1;
    std::uint_fast64_t _e = 1, _rev = _n - 1;
    for (auto _a: _as) {
      if (_n <= _a) break;
      std::uint_fast64_t _t = _d, _y = modpow(_a, _t, _n);
      while (_t != _n - 1 && _y != _e && _y != _rev) {
        _y *= _y;
        _t *= 2;
      }
      if (_y != _rev && _t % 2 == 0) return false;
    }
    return true;
  }
}
