#pragma once
#include <type_traits>

namespace kyopro {
  template<class KyoproT, class KyoproU>
  constexpr KyoproT floor_div(KyoproT kyopro_x, KyoproU kyopro_m) noexcept {
    static_assert(std::is_integral_v<KyoproT> && std::is_integral_v<KyoproU>);
    if constexpr (std::is_unsigned_v<KyoproT>) return kyopro_x / kyopro_m;
    if (kyopro_m < 0) return -kyopro_x / -kyopro_m;
    if (kyopro_x < 0) return (kyopro_x + 1) / kyopro_m - 1;
    return kyopro_x / kyopro_m;
  }

  template<class KyoproT, class KyoproU>
  constexpr KyoproT ceil_div(KyoproT kyopro_x, KyoproU kyopro_m) noexcept { return floor_div(kyopro_x + kyopro_m - 1, kyopro_m); }
}