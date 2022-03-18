#pragma once

#include <cstdint>
#include <limits>
#include <type_traits>
#include "../algorithm/bit.hpp"
#include "../meta/settings.hpp"
#include "../meta/trait.hpp"

template<class _typeT>
struct Barrett {
  static_assert(std::is_unsigned_v<_typeT>, "Unsigned integer is required");

private:
  using _mul_value_type = uint_least_t<std::numeric_limits<std::make_unsigned_t<_typeT>>::digits * 2>;
  _typeT _mod;
  _mul_value_type _m;

public:
  using value_type = _typeT;

  constexpr void set_mod(_typeT _mod) noexcept {
    this->_mod = _mod;
    _m = (static_cast<_mul_value_type>(1) << 64) / _mod;
  }

  constexpr KYOPRO_BASE_INT get_mod() const noexcept {
    return _mod;
  }

  Barrett() noexcept = default;
  Barrett(KYOPRO_BASE_UINT _mod) noexcept: _mod(_mod), _m((static_cast<_mul_value_type>(1) << 64) / _mod) {}

  constexpr KYOPRO_BASE_UINT operator ()(KYOPRO_BASE_UINT _x) const noexcept {
	  _x -= static_cast<_typeT>((_x * _m) >> 64) * _mod;
    return _x < _mod ? _x : _x - _mod;
  }
};