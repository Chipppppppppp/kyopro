#pragma once
#include <cassert>
#include <cstdint>
#include <type_traits>
#include "../base/constant.hpp"
#include "../base/Hash.hpp"
#include "../base/settings.hpp"
#include "mod.hpp"

namespace kyopro {
  template<std::uint_fast64_t _m>
  struct ModInt {
    static constexpr KYOPRO_BASE_INT mod = _m;
    std::uint_fast64_t _value;

    constexpr ModInt() noexcept = default;
    template<class T>
    constexpr ModInt(T _value) noexcept: _value(floor_mod(_value, _m)) { static_assert(std::is_integral_v<T>); }

    template<class T>
    explicit constexpr operator T() const noexcept { return _value; }

    static constexpr ModInt raw(std::uint_fast64_t _n) noexcept {
      ModInt _res;
      _res._value = _n;
      return _res;
    }

    constexpr ModInt power(std::uint_fast64_t _n) const noexcept {
      std::uint_fast64_t _res = 1, _a = _value;
      while (_n > 0) {
        if (_n & 1) _res = _res * _a % _m;
        _a = _a * _a % _m;
        _n >>= 1;
      }
      return _res;
    }

    constexpr ModInt inv() const noexcept {
      std::uint_fast64_t _a = _value, _b = _m;
      std::int64_t _u = 1, _v = 0;
      while (_b > 0) {
        std::uint_fast64_t _t = _a / _b;
        _a -= _t * _b;
        std::swap(_a, _b);
        _u -= _t * _v;
        std::swap(_u, _v);
      }
      return floor_mod(_u, _m);
    }

    constexpr ModInt operator +() const noexcept { return *this; }
    constexpr ModInt operator -() const noexcept { return _m - _value; }

    constexpr ModInt& operator ++() noexcept {
      if (++_value >= _m) _value -= _m;
      return *this;
    }
    constexpr ModInt operator ++(int) noexcept {
      ModInt _before = *this;
      operator ++();
      return _before;
    }
    constexpr ModInt& operator --() noexcept {
      if (_value == 0) _value = _m;
      --_value;
      return *this;
    }
    constexpr ModInt operator --(int) noexcept {
      ModInt _before = *this;
      operator --();
      return _before;
    }

    constexpr ModInt& operator +=(ModInt _rhs) noexcept {
      if ((_value += _rhs._value) >= _m) _value -= _m;
      return *this;
    }
    constexpr ModInt& operator -=(ModInt _rhs) noexcept {
      if (_value < _rhs._value) _value += _m;
      _value -= _rhs._value;
      return *this;
    }
    constexpr ModInt& operator *=(ModInt _rhs) noexcept {
      _value = _value * _rhs._value % _m;
      return *this;
    }
    constexpr ModInt& operator /=(ModInt _rhs) noexcept {
      _value = _value * _rhs.inv()._value % _m;
      return *this;
    }

    friend constexpr ModInt operator +(ModInt _lhs, ModInt _rhs) noexcept { return _lhs += _rhs; }
    friend constexpr ModInt operator -(ModInt _lhs, ModInt _rhs) noexcept { return _lhs -= _rhs; }
    friend constexpr ModInt operator *(ModInt _lhs, ModInt _rhs) noexcept { return _lhs *= _rhs; }
    friend constexpr ModInt operator /(ModInt _lhs, ModInt _rhs) noexcept { return _lhs /= _rhs; }
    friend constexpr bool operator ==(ModInt _lhs, ModInt _rhs) noexcept { return _lhs._value == _rhs._value; }
    friend constexpr bool operator !=(ModInt _lhs, ModInt _rhs) noexcept { return _lhs._value != _rhs._value; }
  };

  template<KYOPRO_BASE_UINT _m>
  struct Hash<ModInt<_m>> { constexpr KYOPRO_BASE_UINT operator ()(ModInt<_m> _a) const noexcept { return _a; } };

  constexpr ModInt<mod> operator "" _m(unsigned long long _a) noexcept { return _a; }
}