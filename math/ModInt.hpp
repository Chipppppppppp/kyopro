#pragma once
#include <cassert>
#include <cstdint>
#include <limits>
#include <type_traits>
#include "../algorithm/bit.hpp"
#include "../algorithm/Hash.hpp"
#include "../meta/constant.hpp"
#include "../meta/settings.hpp"
#include "../meta/trait.hpp"
#include "mod.hpp"

namespace kyopro {
  template<KYOPRO_BASE_UINT _mod>
  struct ModInt {
  private:
    static constexpr value_type _mod = static_cast<value_type>(_mod);

  public:
    using value_type = uint_least_t<bit_len(_mod)>;

    value_type value;

    static constexpr KYOPRO_BASE_INT get_mod() noexcept {
      return static_cast<KYOPRO_BASE_INT>(_mod);
    }

    constexpr ModInt() noexcept = default;
    template<class _typeT>
    constexpr ModInt(_typeT _value) noexcept: value(floor_mod(_value, _mod)) { static_assert(std::is_integral_v<_typeT>); }

    template<class _typeT>
    explicit constexpr operator _typeT() const noexcept { return static_cast<_typeT>(value); }

    static constexpr ModInt raw(KYOPRO_BASE_UINT _n) noexcept {
      ModInt _res;
      _res.value = _n;
      return _res;
    }

    constexpr ModInt power(KYOPRO_BASE_UINT _n) const noexcept {
      std::uint_fast64_t _res = 1, _a = value;
      while (_n > 0) {
        if (_n & 1) _res = _res * _a % _mod;
        _a = _a * _a % _mod;
        _n >>= 1;
      }
      return _res;
    }

    constexpr ModInt inv() const noexcept {
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

    constexpr ModInt operator +() const noexcept { return *this; }

    constexpr ModInt operator -() const noexcept { return _mod - value; }

    constexpr ModInt& operator ++() noexcept {
      if (++value >= _mod) value -= _mod;
      return *this;
    }

    constexpr ModInt operator ++(int) noexcept {
      ModInt _before = *this;
      operator ++();
      return _before;
    }

    constexpr ModInt& operator --() noexcept {
      if (value == 0) value = _mod;
      --value;
      return *this;
    }

    constexpr ModInt operator --(int) noexcept {
      ModInt _before = *this;
      operator --();
      return _before;
    }

    constexpr ModInt& operator +=(ModInt _rhs) noexcept {
      if ((value += _rhs.value) >= _mod) value -= _mod;
      return *this;
    }

    constexpr ModInt& operator -=(ModInt _rhs) noexcept {
      if (value < _rhs.value) value += _mod;
      value -= _rhs.value;
      return *this;
    }

    constexpr ModInt& operator *=(ModInt _rhs) noexcept {
      value = static_cast<uint_least_t<bit_len(_mod) * 2>>(value) * _rhs.value % _mod;
      return *this;
    }

    constexpr ModInt& operator /=(ModInt _rhs) noexcept {
      value = static_cast<uint_least_t<bit_len(_mod) * 2>>(value) * _rhs.inv().value % _mod;
      return *this;
    }

    friend constexpr ModInt operator +(ModInt _lhs, ModInt _rhs) noexcept { return _lhs += _rhs; }

    friend constexpr ModInt operator -(ModInt _lhs, ModInt _rhs) noexcept { return _lhs -= _rhs; }

    friend constexpr ModInt operator *(ModInt _lhs, ModInt _rhs) noexcept { return _lhs *= _rhs; }

    friend constexpr ModInt operator /(ModInt _lhs, ModInt _rhs) noexcept { return _lhs /= _rhs; }

    friend constexpr bool operator ==(ModInt _lhs, ModInt _rhs) noexcept { return _lhs.value == _rhs.value; }

    friend constexpr bool operator !=(ModInt _lhs, ModInt _rhs) noexcept { return _lhs.value != _rhs.value; }

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

  template<KYOPRO_BASE_UINT _mod>
  struct Hash<ModInt<_mod>> { constexpr std::size_t operator ()(ModInt<_mod> _a) const noexcept { return static_cast<std::size_t>(_a); } };
}