#pragma once
#include <cstdint>
#include "../base/settings.hpp"
namespace kyopro {
  template<class _typeT>
  constexpr _typeT power(_typeT _a, std::uint_fast64_t _n, _typeT _init = 1) noexcept {
    while (_n > 0) {
      if (_n & 1) _init *= _a;
      _a *= _a;
      _n >>= 1;
    }
    return _init;
  }
}