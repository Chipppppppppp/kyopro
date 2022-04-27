#pragma once
#include "../meta/settings.hpp"

namespace kpr {
  template<class T>
  constexpr T power(T a, KYOPRO_BASE_UINT n, T init = 1) noexcept {
    while (n > 0) {
      if (n & 1) init *= a;
      a *= a;
      n >>= 1;
    }
    return init;
  }
}