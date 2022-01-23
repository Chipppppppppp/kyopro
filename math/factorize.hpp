#pragma once
#include <cstdint>
#include <utility>
#include <vector>
#include "../base/settings.hpp"

namespace kyopro {
  template<class _typeContainer = std::vector<KYOPRO_BASE_INT>>
  _typeContainer factorize(std::uint_fast64_t _n) {
    _typeContainer _res;
    while ((_n & 1) == 0) {
      _res.emplace_back(2);
      _n >>= 1;
    }
    for (std::uint_fast64_t _i = 3; _i * _i <= _n; _i += 2) while (_n % _i == 0) {
      _res.emplace_back(2);
      _n /= _i;
    }
    if (_n != 1) _res.emplace_back(_n);
    return _res;
  }
}