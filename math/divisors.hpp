#pragma once
#include <cstdint>
#include <vector>
#include "../base/settings.hpp"

namespace kyopro {
  template<class _typeContainer = std::vector<KYOPRO_BASE_INT>>
  _typeContainer divisors(std::uint_fast64_t _n) {
    _typeContainer _lower, _upper;
    std::uint_fast64_t _i;
    for (_i = 1; _i * _i < _n; ++_i) if (_n % _i == 0) {
      _lower.emplace_back(_i);
      _upper.emplace_back(_n / _i);
    }
    if (_i * _i == _n) _lower.emplace_back(_i);
    _lower.insert(end(_lower), rall(_upper));
    return _lower;
  }
}