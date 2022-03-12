#pragma once
#include <array>
#include <cstdint>
#include "../base/settings.hpp"
#include "miller_rabin.hpp"

namespace kyopro {
  constexpr bool is_prime(KYOPRO_BASE_UINT _n) noexcept {
    if (_n <= 1) return false;
    if (~_n & 1) return _n == 2;
    return miller_rabin(_n, std::array<KYOPRO_BASE_UINT, 7>{2, 325, 9375, 28178, 450775, 9780504, 1795265022});
  }
}