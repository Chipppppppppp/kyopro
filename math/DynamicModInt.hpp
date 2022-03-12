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

    static void set_mod(KYOPRO_BASE_UINT _mod) noexcept {
      mod = _mod;
    }

    static KYOPRO_BASE_INT get_mod() noexcept {
      return static_cast<KYOPRO_BASE_UINT>(mod);
    }

    DynamicModInt() noexcept = default;
    template<class _typeT>
    DynamicModInt(_typeT _value) noexcept: value(floor_mod(_value, mod)) { static_assert(std::is_integral_v<_typeT>); }

    template<class _typeT>
    explicit operator _typeT() const noexcept { return static_cast<_typeT>(value); }

    static DynamicModInt raw(KYOPRO_BASE_UINT _n) noexcept {
      DynamicModInt _res;
      _res.value = _n;
      return _res;
    }

    DynamicModInt power(KYOPRO_BASE_UINT _n) const noexcept {
      std::uint_fast64_t _res = 1, _a = value;
      while (_n > 0) {
        if (_n & 1) _res = _res * _a % mod;
        _a = _a * _a % mod;
        _n >>= 1;
      }
      return _res;
    }

    DynamicModInt inv() const noexcept {
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

    DynamicModInt operator +() const noexcept { return *this; }

    DynamicModInt operator -() const noexcept { return mod - value; }

    DynamicModInt& operator ++() noexcept {
      if (++value >= mod) value -= mod;
      return *this;
    }

    DynamicModInt operator ++(int) noexcept {
      DynamicModInt _before = *this;
      operator ++();
      return _before;
    }

    DynamicModInt& operator --() noexcept {
      if (value == 0) value = mod;
      --value;
      return *this;
    }

    DynamicModInt operator --(int) noexcept {
      DynamicModInt _before = *this;
      operator --();
      return _before;
    }

    DynamicModInt& operator +=(DynamicModInt _rhs) noexcept {
      if ((value += _rhs.value) >= mod) value -= mod;
      return *this;
    }

    DynamicModInt& operator -=(DynamicModInt _rhs) noexcept {
      if (value < _rhs.value) value += mod;
      value -= _rhs.value;
      return *this;
    }

    DynamicModInt& operator *=(DynamicModInt _rhs) noexcept {
      value = value * _rhs.value % mod;
      return *this;
    }

    DynamicModInt& operator /=(DynamicModInt _rhs) noexcept {
      value = value * _rhs.inv().value % mod;
      return *this;
    }

    friend DynamicModInt operator +(DynamicModInt _lhs, DynamicModInt _rhs) noexcept { return _lhs += _rhs; }

    friend DynamicModInt operator -(DynamicModInt _lhs, DynamicModInt _rhs) noexcept { return _lhs -= _rhs; }

    friend DynamicModInt operator *(DynamicModInt _lhs, DynamicModInt _rhs) noexcept { return _lhs *= _rhs; }

    friend DynamicModInt operator /(DynamicModInt _lhs, DynamicModInt _rhs) noexcept { return _lhs /= _rhs; }

    friend bool operator ==(DynamicModInt _lhs, DynamicModInt _rhs) noexcept { return _lhs.value == _rhs.value; }

    friend bool operator !=(DynamicModInt _lhs, DynamicModInt _rhs) noexcept { return _lhs.value != _rhs.value; }

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

  template<>
  struct Hash<DynamicModInt> { std::size_t operator ()(DynamicModInt _a) const noexcept { return static_cast<std::size_t>(_a); } };
}