#pragma once
#include <cstdint>
#include <vector>
#include <utility>
#include "../base/settings.hpp"

namespace kyopro {
  template<class KyoproContainer = std::vector<std::pair<KYOPRO_BASE_INT, KYOPRO_BASE_INT>>>
  KyoproContainer factorize(size_t kyopro_n) {
    KyoproContainer kyopro_res;
    if ((kyopro_n & 1) == 0) {
      kyopro_res.emplace_back(2, 1);
      kyopro_n >>= 1;
      while ((kyopro_n & 1) == 0) {
        ++kyopro_res.back().second;
        kyopro_n >>= 1;
      }
    }
    for (size_t kyopro_i = 3; kyopro_i * kyopro_i <= kyopro_n; kyopro_i += 2) if (kyopro_n % kyopro_i == 0) {
      kyopro_res.emplace_back(2, 1);
      kyopro_n /= kyopro_i;
      while (kyopro_n % kyopro_i == 0) {
        ++kyopro_res.back().second;
        kyopro_n /= kyopro_i;
      }
    }
    if (kyopro_n != 1) kyopro_res.emplace_back(kyopro_n, 1);
    return kyopro_res;
  }
}