#pragma once
#include <type_traits>
#include <cassert>

namespace kyopro {
  template<class KyoproT, class KyoproU>
  constexpr KyoproT floor_mod(KyoproT kyopro_x, KyoproU kyopro_m) noexcept {
    static_assert(std::is_integral_v<KyoproT> && std::is_integral_v<KyoproU>);
    if constexpr (std::is_unsigned_v<KyoproT>) return kyopro_x % kyopro_m;
    return (kyopro_x %= kyopro_m) < 0 ? kyopro_x + kyopro_m : kyopro_x;
  }

  template<class KyoproT, class KyoproU>
  constexpr KyoproT ceil_mod(KyoproT kyopro_x, KyoproU kyopro_m) noexcept { return kyopro_m - floor_mod(kyopro_x - 1, kyopro_m) - 1; }
}