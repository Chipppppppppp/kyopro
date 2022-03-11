#pragma once
#include <cassert>
#include <cstdint>
#include <type_traits>
#include "../base/constant.hpp"
#include "../base/Hash.hpp"
#include "../base/settings.hpp"
#include "mod.hpp"

namespace kyopro {
  struct DynamicModInt {
    inline static KYOPRO_BASE_UINT mod;
    KYOPRO_BASE_UINT value;

    static constexpr void set_mod(KYOPRO_BASE_UINT _mod) noexcept {
      mod = _mod;
    }

    constexpr DynamicModInt() noexcept = default;
    template<class _typeT>
    constexpr DynamicModInt(_typeT _value) noexcept: value(floor_mod(_value, mod)) { static_assert(std::is_integral_v<_typeT>); }

    template<class _typeT>
    explicit constexpr operator _typeT() const noexcept { return value; }

    static constexpr DynamicModInt raw(std::uint_fast64_t _n) noexcept {
      DynamicModInt _res;
      _res.value = _n;
      return _res;
    }

    constexpr DynamicModInt power(std::uint_fast64_t _n) const noexcept {
      std::uint_fast64_t _res = 1, _a = value;
      while (_n > 0) {
        if (_n & 1) _res = _res * _a % mod;
        _a = _a * _a % mod;
        _n >>= 1;
      }
      return _res;
    }

    constexpr DynamicModInt inv() const noexcept {
      std::uint_fast64_t _a = value, _b = mod;
      std::int_fast64_t _u = 1, _v = 0;
      while (_b > 0) {
        std::uint_fast64_t _t = _a / _b;
        _a -= _t * _b;
        std::swap(_a, _b);
        _u -= _t * _v;
        std::swap(_u, _v);
      }
      return floor_mod(_u, mod);
    }

    constexpr DynamicModInt operator +() const noexcept { return *this; }

    constexpr DynamicModInt operator -() const noexcept { return mod - value; }

    constexpr DynamicModInt& operator ++() noexcept {
      if (++value >= mod) value -= mod;
      return *this;
    }

    constexpr DynamicModInt operator ++(int) noexcept {
      DynamicModInt _before = *this;
      operator ++();
      return _before;
    }

    constexpr DynamicModInt& operator --() noexcept {
      if (value == 0) value = mod;
      --value;
      return *this;
    }

    constexpr DynamicModInt operator --(int) noexcept {
      DynamicModInt _before = *this;
      operator --();
      return _before;
    }

    constexpr DynamicModInt& operator +=(DynamicModInt _rhs) noexcept {
      if ((value += _rhs.value) >= mod) value -= mod;
      return *this;
    }

    constexpr DynamicModInt& operator -=(DynamicModInt _rhs) noexcept {
      if (value < _rhs.value) value += mod;
      value -= _rhs.value;
      return *this;
    }

    constexpr DynamicModInt& operator *=(DynamicModInt _rhs) noexcept {
      value = value * _rhs.value % mod;
      return *this;
    }

    constexpr DynamicModInt& operator /=(DynamicModInt _rhs) noexcept {
      value = value * _rhs.inv().value % mod;
      return *this;
    }

    friend constexpr DynamicModInt operator +(DynamicModInt _lhs, DynamicModInt _rhs) noexcept { return _lhs += _rhs; }

    friend constexpr DynamicModInt operator -(DynamicModInt _lhs, DynamicModInt _rhs) noexcept { return _lhs -= _rhs; }

    friend constexpr DynamicModInt operator *(DynamicModInt _lhs, DynamicModInt _rhs) noexcept { return _lhs *= _rhs; }

    friend constexpr DynamicModInt operator /(DynamicModInt _lhs, DynamicModInt _rhs) noexcept { return _lhs /= _rhs; }

    friend constexpr bool operator ==(DynamicModInt _lhs, DynamicModInt _rhs) noexcept { return _lhs.value == _rhs.value; }

    friend constexpr bool operator !=(DynamicModInt _lhs, DynamicModInt _rhs) noexcept { return _lhs.value != _rhs.value; }

    template<class _typeScanner>
    void scan(_typeScanner& _scanner) {
      std::int_fast64_t _value;
      _scanner.scan(_value);
      value = floor_mod(_value, mod);
    }

    template<class _typePrinter>
    void print(_typePrinter& _printer) const {
      _printer.print(value);
    }
  };

  struct Hash<DynamicModInt> { constexpr std::size_t operator ()(DynamicModInt _a) const noexcept { return _a; } };
}