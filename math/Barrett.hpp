#pragma once

#include <cstdint>
#include "../meta/settings.hpp"

struct Barrett {
private:
  std::uint_fast64_t _mod;
  __uint128_t _m;

public:
  constexpr void set_mod(KYOPRO_BASE_UINT _mod) noexcept {
    this->_mod = _mod;
    _m = (static_cast<__uint128_t>(1) << 64) / _mod;
  }

  constexpr KYOPRO_BASE_INT get_mod() const noexcept {
    return _mod;
  }

  Barrett() noexcept = default;
  Barrett(KYOPRO_BASE_UINT _mod) noexcept: _mod(_mod), _m((static_cast<__uint128_t>(1) << 64) / _mod) {}

  constexpr KYOPRO_BASE_UINT operator ()(KYOPRO_BASE_UINT _x) const noexcept {
	  _x -= static_cast<std::uint_fast64_t>((_x * _m) >> 64) * _mod;
    return _x < _mod ? _x : _x - _mod;
  }
};