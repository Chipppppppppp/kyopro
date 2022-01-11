#pragma once
#include <cstdint>
#include "../base/settings.hpp"
namespace kyopro {
  template<class _typeT>
  constexpr _typeT power(_typeT a, std::uint64_t n, _typeT init = 1) noexcept {
    while (n > 0) {
      if (n & 1) init *= a;
      a *= a;
      n >>= 1;
    }
    return init;
  }
}