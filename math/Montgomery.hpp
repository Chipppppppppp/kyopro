#pragma once
#include <cstdint>
#include <limits>
#include <type_traits>
#include "../meta/settings.hpp"

namespace kyopro {
  template<class _typeT>
  struct Montgomery {
    static_assert(std::is_unsigned_v<_typeT>, "Unsigned integer is required");

    _typeT mod;

  private:
    using _larger_type = uint_least_t<std::numeric_limits<_typeT>::digits * 2>;

    _typeT _r, _n2;

  public:
    constexpr void set_mod(_typeT _mod) noexcept {
      mod = _mod;
      _n2 = -static_cast<_larger_type>(mod) % mod;
      _typeT _t = 0;
      for (int _i = 0; _i < std::numeric_limits<_typeT>::digits; ++_i) {
        if (!(_t & 1)) {
          _t += mod;
          _r += static_cast<_typeT>(1) << static_cast<_typeT>(_i);
        }
        _t >>= 1;
      }
    }

    constexpr KYOPRO_BASE_INT get_mod() const noexcept {
      return mod;
    }

    Montgomery() noexcept = default;
    Montgomery(_typeT _mod) noexcept {
      set_mod(_mod);
    }

    constexpr _typeT transform(_typeT _x) const noexcept {
      return reduce(static_cast<_larger_type>(_x) * _n2);
    }

    constexpr _typeT inverse_transform(_typeT _x) const noexcept {
      return reduce(_x);
    }

    constexpr _typeT reduce(_larger_type _x) const noexcept {
      _typeT _y = (_x + static_cast<_larger_type>(static_cast<_typeT>(_x) * _r) * mod) >> std::numeric_limits<_typeT>::digits;
      return _y >= mod ? _y - mod : _y;
    }
  };
}