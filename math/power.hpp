#pragma once
#include "../base/settings.hpp"

namespace kyopro {
  template<class _typeT>
  constexpr _typeT power(_typeT _a, KYOPRO_BASE_UINT _n, _typeT _init = 1) noexcept {
    while (_n > 0) {
      if (_n & 1) _init *= _a;
      _a *= _a;
      _n >>= 1;
    }
    return _init;
  }
}