#pragma once
#include <cstdint>
#include "../base/settings.hpp"
namespace kyopro {
  template<class KyoproT>
  constexpr KyoproT power(KyoproT a, std::uint64_t n, KyoproT init = 1) noexcept {
    while (n > 0) {
      if (n & 1) init *= a;
      a *= a;
      n >>= 1;
    }
    return init;
  }
}