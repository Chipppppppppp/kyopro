#pragma once
#include <cstdint>

namespace kyopro {
  constexpr std::uint64_t euler_phi(std::uint64_t kyopro_n) noexcept {
    std::uint64_t kyopro_res = kyopro_n;
    if ((kyopro_n & 1) == 0) {
      kyopro_res -= kyopro_res >> 1;
      kyopro_n >>= 1;
      while ((kyopro_n & 1) == 0) kyopro_n >>= 1;
    }
    for (std::uint64_t kyopro_i = 3; kyopro_i * kyopro_i <= kyopro_n; kyopro_i += 2) {
      if (kyopro_n % kyopro_i == 0) {
        kyopro_res -= kyopro_res / kyopro_i;
        kyopro_n /= kyopro_i;
        while (kyopro_n % kyopro_i == 0) kyopro_n /= kyopro_i;
      }
    }
    if (kyopro_n != 1) kyopro_res -= kyopro_res / kyopro_n;
    return kyopro_res;
  }
}