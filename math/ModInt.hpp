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
    std::uint_fast64_t value;

    constexpr ModInt() noexcept = default;
    template<class T>
    constexpr ModInt(T value) noexcept: value(floor_mod(value, _m)) { static_assert(std::is_integral_v<T>); }

    template<class T>
    explicit constexpr operator T() const noexcept { return value; }

    static constexpr ModInt raw(std::uint_fast64_t _n) noexcept {
      ModInt _res;
      _res.value = _n;
      return _res;
    }

    constexpr ModInt power(std::uint_fast64_t _n) const noexcept {
      std::uint_fast64_t _res = 1, _a = value;
      while (_n > 0) {
        if (_n & 1) _res = _res * _a % _m;
        _a = _a * _a % _m;
        _n >>= 1;
      }
      return _res;
    }

    constexpr ModInt inv() const noexcept {
      std::uint_fast64_t _a = value, _b = _m;
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

    constexpr ModInt operator -() const noexcept { return _m - value; }

    constexpr ModInt& operator ++() noexcept {
      if (++value >= _m) value -= _m;
      return *this;
    }

    constexpr ModInt operator ++(int) noexcept {
      ModInt _before = *this;
      operator ++();
      return _before;
    }

    constexpr ModInt& operator --() noexcept {
      if (value == 0) value = _m;
      --value;
      return *this;
    }

    constexpr ModInt operator --(int) noexcept {
      ModInt _before = *this;
      operator --();
      return _before;
    }

    constexpr ModInt& operator +=(ModInt _rhs) noexcept {
      if ((value += _rhs.value) >= _m) value -= _m;
      return *this;
    }

    constexpr ModInt& operator -=(ModInt _rhs) noexcept {
      if (value < _rhs.value) value += _m;
      value -= _rhs.value;
      return *this;
    }

    constexpr ModInt& operator *=(ModInt _rhs) noexcept {
      value = value * _rhs.value % _m;
      return *this;
    }

    constexpr ModInt& operator /=(ModInt _rhs) noexcept {
      value = value * _rhs.inv().value % _m;
      return *this;
    }

    friend constexpr ModInt operator +(ModInt _lhs, ModInt _rhs) noexcept { return _lhs += _rhs; }

    friend constexpr ModInt operator -(ModInt _lhs, ModInt _rhs) noexcept { return _lhs -= _rhs; }

    friend constexpr ModInt operator *(ModInt _lhs, ModInt _rhs) noexcept { return _lhs *= _rhs; }

    friend constexpr ModInt operator /(ModInt _lhs, ModInt _rhs) noexcept { return _lhs /= _rhs; }

    friend constexpr bool operator ==(ModInt _lhs, ModInt _rhs) noexcept { return _lhs.value == _rhs.value; }

    friend constexpr bool operator !=(ModInt _lhs, ModInt _rhs) noexcept { return _lhs.value != _rhs.value; }

    template<class _typePrinter>
    void print(_typePrinter& _printer) const {
      _printer.print(value);
    }
  };

  template<KYOPRO_BASE_UINT _m>
  struct Hash<ModInt<_m>> { constexpr KYOPRO_BASE_UINT operator ()(ModInt<_m> _a) const noexcept { return _a; } };
}