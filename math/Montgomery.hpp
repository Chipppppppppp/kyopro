#pragma once
#include <cstdint>
#include "../meta/settings.hpp"

namespace kyopro {
  struct Montgomery {
  private:
    std::uint_fast64_t _m, _r, _n2;

  public:
    constexpr void set_mod(KYOPRO_BASE_UINT _mod) noexcept {
      _m = _mod;
      _n2 = -static_cast<__uint128_t>(_m) % _m;
      _r = _m;
      _r *= 2 - _m * _r;
      _r *= 2 - _m * _r;
      _r *= 2 - _m * _r;
      _r *= 2 - _m * _r;
      _r *= 2 - _m * _r;
      _r = -_r;
    }

    constexpr KYOPRO_BASE_INT get_mod() const noexcept {
      return _m;
    }

    Montgomery() noexcept = default;
    Montgomery(KYOPRO_BASE_UINT _mod) noexcept {
      set_mod(_mod);
    }

    constexpr KYOPRO_BASE_UINT operator ()(__uint128_t _x) const noexcept {
      return (_x + static_cast<__uint128_t>(static_cast<std::uint_fast64_t>(_x) * _r) * _m) >> 64;
    }
  };
}