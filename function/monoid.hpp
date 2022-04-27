#pragma once
#include <type_traits>
#include "../meta/constant.hpp"

namespace kpr {
  template<class T, T _id = 0>
  struct Plus {
    static_assert(std::is_arithmetic_v<T>);
    using value_type = T;
    static constexpr T id = _id;

    constexpr T operator ()(T a, T b) const noexcept { return a + b; }
    constexpr T inverse(T a) const noexcept { return -a; }
  };

  template<class T, T _id = 1>
  struct Mul {
    static_assert(std::is_arithmetic_v<T>);
    using value_type = T;
    static constexpr T id = _id;

    constexpr T operator ()(T a, T b) const noexcept { return a * b; }
    constexpr T inverse(T a) const noexcept {
      static_assert(!std::is_integral_v<T>);
      return 1 / a;
    }
  };

  template<class T, T _id = std::is_integral_v<T> ? -INF<T> : -inf>
  struct Max {
    static_assert(std::is_arithmetic_v<T>);
    using value_type = T;
    static constexpr T id = _id;

    constexpr T operator ()(T a, T b) const noexcept { return a > b ? a : b; }
  };

  template<class T, T _id = std::is_integral_v<T> ? INF<T> : inf>
  struct Min {
    static_assert(std::is_arithmetic_v<T>);
    using value_type = T;
    static constexpr T id = _id;

    constexpr T operator ()(T a, T b) const noexcept { return a < b ? a : b; }
  };
}