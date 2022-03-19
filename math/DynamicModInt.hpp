#pragma once
#include <cassert>
#include <cstdint>
#include <type_traits>
#include "../algorithm/Hash.hpp"
#include "../meta/constant.hpp"
#include "../meta/settings.hpp"
#include "mod.hpp"
#include "Montgomery.hpp"

namespace kyopro {
  template<class _typeT>
  struct DynamicModInt {
    static_assert(std::is_unsigned_v<_typeT>, "Unsigned integer is required");

  private:
    inline static _typeT _mod;
    inline static Montgomery _montgomery;

  public:
    _typeT value;

    static void set_mod(_typeT _m) noexcept {
      _mod = _m;
      _montgomery.set_mod(_m);
    }

    static KYOPRO_BASE_INT get_mod() noexcept {
      return _mod;
    }

    DynamicModInt() noexcept = default;
    DynamicModInt(_typeT _value) noexcept: value(floor_mod(_value, _mod)) {}

    template<class _typeU>
    explicit operator _typeU() const noexcept { return value; }

    static DynamicModInt raw(_typeT _n) noexcept {
      DynamicModInt _res;
      _res.value = _n;
      return _res;
    }

    DynamicModInt power(_typeT _n) const noexcept {
      _typeT _res = 1, _a = value;
      while (_n > 0) {
        if (_n & 1) _res = _res * _a % _mod;
        _a = _a * _a % _mod;
        _n >>= 1;
      }
      return _res;
    }

    DynamicModInt inv() const noexcept {
      _typeT _a = value, _b = _mod;
      std::make_signed_t<_typeT> _u = 1, _v = 0;
      while (_b > 0) {
        _typeT _t = _a / _b;
        _a -= _t * _b;
        std::swap(_a, _b);
        _u -= _t * _v;
        std::swap(_u, _v);
      }
      return floor_mod(_u, _mod);
    }

    DynamicModInt operator +() const noexcept { return *this; }

    DynamicModInt operator -() const noexcept { return value == 0 ? 0 : _mod - value; }

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
      value = _montgomery(value * _rhs.value);
      return *this;
    }

    DynamicModInt& operator /=(DynamicModInt _rhs) noexcept {
      value = _montgomery(value * _rhs.inv().value);
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
      std::make_signed_t<_typeT> _value;
      _scanner.scan(_value);
      value = floor_mod(_value, _mod);
    }

    template<class _typePrinter>
    void print(_typePrinter& _printer) const {
      _printer.print(value);
    }
  };

  template<class _typeT>
  struct Hash<DynamicModInt<_typeT>> { std::size_t operator ()(DynamicModInt<_typeT> _a) const noexcept { return static_cast<std::size_t>(_a); } };
}
