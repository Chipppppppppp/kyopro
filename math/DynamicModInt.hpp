#pragma once
#include <cassert>
#include <cstdint>
#include <type_traits>
#include "../algorithm/Hash.hpp"
#include "../meta/constant.hpp"
#include "../meta/settings.hpp"
#include "Barrett.hpp"
#include "mod.hpp"

namespace kyopro {
  struct DynamicModInt {
  private:
    inline static std::uint_fast64_t _mod;
    inline static Barrett _barrett;

  public:
    KYOPRO_BASE_UINT value;

    static void set_mod(KYOPRO_BASE_UINT _m) noexcept {
      _mod = _m;
      _barrett.set_mod(_m);
    }

    static KYOPRO_BASE_INT get_mod() noexcept {
      return static_cast<KYOPRO_BASE_INT>(_mod);
    }

    DynamicModInt() noexcept = default;
    template<class _typeT>
    DynamicModInt(_typeT _value) noexcept: value(floor_mod(_value, _mod)) { static_assert(std::is_integral_v<_typeT>); }

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
        if (_n & 1) _res = _res * _a % _mod;
        _a = _a * _a % _mod;
        _n >>= 1;
      }
      return _res;
    }

    DynamicModInt inv() const noexcept {
      std::uint_fast64_t _a = value, _b = _mod;
      std::int_fast64_t _u = 1, _v = 0;
      while (_b > 0) {
        std::uint_fast64_t _t = _a / _b;
        _a -= _t * _b;
        std::swap(_a, _b);
        _u -= _t * _v;
        std::swap(_u, _v);
      }
      return floor_mod(_u, _mod);
    }

    DynamicModInt operator +() const noexcept { return *this; }

    DynamicModInt operator -() const noexcept { return _mod - value; }

    DynamicModInt& operator ++() noexcept {
      if (++value >= _mod) value -= _mod;
      return *this;
    }

    DynamicModInt operator ++(int) noexcept {
      DynamicModInt _before = *this;
      operator ++();
      return _before;
    }

    DynamicModInt& operator --() noexcept {
      if (value == 0) value = _mod;
      --value;
      return *this;
    }

    DynamicModInt operator --(int) noexcept {
      DynamicModInt _before = *this;
      operator --();
      return _before;
    }

    DynamicModInt& operator +=(DynamicModInt _rhs) noexcept {
      if ((value += _rhs.value) >= _mod) value -= _mod;
      return *this;
    }

    DynamicModInt& operator -=(DynamicModInt _rhs) noexcept {
      if (value < _rhs.value) value += _mod;
      value -= _rhs.value;
      return *this;
    }

    DynamicModInt& operator *=(DynamicModInt _rhs) noexcept {
      value = _barrett(value * _rhs.value);
      return *this;
    }

    DynamicModInt& operator /=(DynamicModInt _rhs) noexcept {
      value = _barrett(value * _rhs.inv().value);
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
      value = floor_mod(_value, _mod);
    }

    template<class _typePrinter>
    void print(_typePrinter& _printer) const {
      _printer.print(value);
    }
  };

  template<>
  struct Hash<DynamicModInt> { std::size_t operator ()(DynamicModInt _a) const noexcept { return static_cast<std::size_t>(_a); } };
}