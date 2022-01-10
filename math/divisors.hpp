#pragma once
#include <cstdint>
#include <vector>
#include "../base/settings.hpp"

namespace kyopro {
  template<class KyoproContainer = std::vector<KYOPRO_BASE_INT>>
  KyoproContainer divisors(std::uint64_t kyopro_n) {
    KyoproContainer kyopro_lower, kyopro_upper;
    std::uint64_t kyopro_i;
    for (kyopro_i = 1; kyopro_i * kyopro_i < kyopro_n; ++kyopro_i) if (kyopro_n % kyopro_i == 0) {
      kyopro_lower.emplace_back(kyopro_i);
      kyopro_upper.emplace_back(kyopro_n / kyopro_i);
    }
    if (kyopro_i * kyopro_i == kyopro_n) kyopro_lower.emplace_back(kyopro_i);
    kyopro_lower.insert(end(kyopro_lower), rall(kyopro_upper));
    return kyopro_lower;
  }
}