#pragma once
#include <cstdint>
#include <limits>
#include <type_traits>
#include "../meta/settings.hpp"

namespace kyopro {
  template<class T>
  struct Montgomery {
    static_assert(std::is_unsigned_v<T>, "Unsigned integer is required");

    T mod;

  private:
    using larger_type = uint_least_t<std::numeric_limits<T>::digits * 2>;

    T r, n2;

  public:
    constexpr void set_mod(T _mod) noexcept {
      mod = _mod;
      n2 = -static_cast<larger_type>(mod) % mod;
      T t = 0;
      r = 0;
      for (int i = 0; i < std::numeric_limits<T>::digits; ++i) {
        if (!(t & 1)) {
          t += mod;
          r += static_cast<T>(1) << static_cast<T>(i);
        }
        t >>= 1;
      }
    }

    constexpr KYOPRO_BASE_INT get_mod() const noexcept {
      return mod;
    }

    Montgomery() noexcept = default;
    Montgomery(T mod) noexcept {
      set_mod(mod);
    }

    constexpr T transform(T x) const noexcept {
      return reduce(static_cast<larger_type>(x) * n2);
    }

    constexpr T inverse_transform(T x) const noexcept {
      return reduce(x);
    }

    constexpr T reduce(larger_type x) const noexcept {
      T y = (x + static_cast<larger_type>(static_cast<T>(x) * r) * mod) >> std::numeric_limits<T>::digits;
      return y >= mod ? y - mod : y;
    }
  };
}