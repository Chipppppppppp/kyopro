#pragma once
#include <cstdint>
#include <vector>
#include <utility>
#include "../base/settings.hpp"

namespace kyopro {
  template<class KyoproContainer = std::vector<KYOPRO_BASE_INT>>
  KyoproContainer factorize(std::uint64_t kyopro_n) {
    KyoproContainer kyopro_res;
    while ((kyopro_n & 1) == 0) {
      kyopro_res.emplace_back(2);
      kyopro_n >>= 1;
    }
    for (std::uint64_t kyopro_i = 3; kyopro_i * kyopro_i <= kyopro_n; kyopro_i += 2) while (kyopro_n % kyopro_i == 0) {
      kyopro_res.emplace_back(2);
      kyopro_n /= kyopro_i;
    }
    if (kyopro_n != 1) kyopro_res.emplace_back(kyopro_n);
    return kyopro_res;
  }
}