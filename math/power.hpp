#pragma once
#include "../meta/settings.hpp"

namespace kyopro {
  inline constexpr struct {
    template<class T>
    constexpr T operator ()(T a, KYOPRO_BASE_UINT n, T init = 1) const noexcept {
      while (n > 0) {
        if (n & 1) init *= a;
        a *= a;
        n >>= 1;
      }
      return init;
    }
  } power;
}