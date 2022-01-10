#pragma once
#include <cstdint>

namespace kyopro {
  constexpr bool is_prime(std::uint64_t kyopro_n) noexcept {
    if (kyopro_n < 2) return false;
    if (kyopro_n < 4) return true;
    if ((kyopro_n & 1) == 0 || kyopro_n % 3 == 0) return false;
    for (std::uint64_t kyopro_i = 5; kyopro_i * kyopro_i <= kyopro_n; kyopro_i += 4) {
      if (kyopro_n % kyopro_i == 0) return false;
      if (kyopro_n % (kyopro_i += 2) == 0) return false;
    }
    return true;
  }
}