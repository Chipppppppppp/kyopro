#pragma once
#include <type_traits>
#include "../base/constant.hpp"

namespace kyopro {
  template<class KyoproT, KyoproT kyopro_id = 0>
  struct Plus {
    static constexpr KyoproT id = kyopro_id;
    static constexpr KyoproT op(KyoproT kyopro_a, KyoproT kyopro_b) noexcept { return kyopro_a + kyopro_b; }
    static constexpr KyoproT inv(KyoproT kyopro_a) noexcept { return -kyopro_a; }
  };
  template<class KyoproT, KyoproT kyopro_id = 1>
  struct Mul {
    static constexpr KyoproT id = kyopro_id;
    static constexpr KyoproT op(KyoproT kyopro_a, KyoproT kyopro_b) noexcept { return kyopro_a * kyopro_b; }
    static constexpr KyoproT inv(KyoproT kyopro_a) noexcept {
      static_assert(!std::is_integral_v<KyoproT>);
      return 1 / kyopro_a;
    }
  };
  template<class KyoproT, KyoproT kyopro_id = -inf>
  struct Max {
    static constexpr KyoproT id = kyopro_id;
    static constexpr KyoproT op(KyoproT kyopro_a, KyoproT kyopro_b) noexcept { return kyopro_a > kyopro_b ? kyopro_a : kyopro_b; }
  };
  template<class KyoproT, KyoproT kyopro_id = inf>
  struct Min {
    static constexpr KyoproT id = kyopro_id;
    static constexpr KyoproT op(KyoproT kyopro_a, KyoproT kyopro_b) noexcept { return kyopro_a < kyopro_b ? kyopro_a : kyopro_b; }
  };
}