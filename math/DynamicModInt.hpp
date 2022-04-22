#pragma once
#include <cassert>
#include <cstddef>
#include <limits>
#include <type_traits>
#include "../algorithm/Hash.hpp"
#include "../meta/constant.hpp"
#include "../meta/settings.hpp"
#include "Montgomery.hpp"

namespace kyopro {
  template<class T, KYOPRO_BASE_UINT _kind = 0>
  struct DynamicModInt {
    static_assert(std::is_unsigned_v<T>, "T must be unsigned integer");
    using value_type = T;
    static constexpr KYOPRO_BASE_INT kind = _kind;

  private:
    using larger_type = uint_least_t<std::numeric_limits<T>::digits * 2>;

    inline static Montgomery<T> montgomery;

  public:
    T value;

    static void set_mod(T mod) noexcept {
      montgomery.set_mod(mod);
    }

    static KYOPRO_BASE_INT get_mod() noexcept {
      return montgomery.mod;
    }

    KYOPRO_BASE_INT get_val() noexcept {
      return montgomery.inverse_transform(value);
    }

    DynamicModInt() noexcept = default;
    DynamicModInt(T value) noexcept: value(montgomery.transform(value)) {}

    template<class U>
    explicit operator U() const noexcept { return montgomery.inverse_transform(value); }

    static DynamicModInt raw(T n) noexcept {
      DynamicModInt res;
      res.value = n;
      return res;
    }

    DynamicModInt power(KYOPRO_BASE_UINT n) const noexcept {
      DynamicModInt res = 1, a = *this;
      while (n > 0) {
        if (n & 1) res = res * a;
        a = a * a;
        n >>= 1;
      }
      return res;
    }

    DynamicModInt inverse() const noexcept {
      return power(montgomery.mod - 2);
    }

    DynamicModInt operator +() const noexcept { return *this; }

    DynamicModInt operator -() const noexcept { return value == 0 ? 0 : montgomery.mod - value; }

    DynamicModInt& operator ++() noexcept {
      if (++value >= montgomery.mod) value -= montgomery.mod;
      return *this;
    }

    DynamicModInt operator ++(int) noexcept {
      DynamicModInt before = *this;
      operator ++();
      return before;
    }

    DynamicModInt& operator --() noexcept {
      if (value == 0) value = montgomery.mod;
      --value;
      return *this;
    }

    DynamicModInt operator --(int) noexcept {
      DynamicModInt before = *this;
      operator --();
      return before;
    }

    DynamicModInt& operator +=(DynamicModInt rhs) noexcept {
      value += rhs.value - (mod << 1);
      if (static_cast<std::make_signed_t<T>>(value) < 0) value += mod << 1;
      return *this;
    }

    DynamicModInt& operator -=(DynamicModInt rhs) noexcept {
      value -= rhs.value;
      if (static_cast<std::make_signed_t<T>>(value) < 0) value += mod << 1;
      return *this;
    }

    DynamicModInt& operator *=(DynamicModInt rhs) noexcept {
      value = montgomery.reduce(static_cast<larger_type>(value) * rhs.value);
      return *this;
    }

    DynamicModInt& operator /=(DynamicModInt rhs) noexcept {
      value = montgomery.reduce(static_cast<larger_type>(value) * rhs.inverse().value);
      return *this;
    }

    friend DynamicModInt operator +(DynamicModInt lhs, DynamicModInt rhs) noexcept { return lhs += rhs; }

    friend DynamicModInt operator -(DynamicModInt lhs, DynamicModInt rhs) noexcept { return lhs -= rhs; }

    friend DynamicModInt operator *(DynamicModInt lhs, DynamicModInt rhs) noexcept { return lhs *= rhs; }

    friend DynamicModInt operator /(DynamicModInt lhs, DynamicModInt rhs) noexcept { return lhs /= rhs; }

    friend bool operator ==(DynamicModInt lhs, DynamicModInt rhs) noexcept { return lhs.value == rhs.value; }

    friend bool operator !=(DynamicModInt lhs, DynamicModInt rhs) noexcept { return lhs.value != rhs.value; }

    template<class Scanner>
    void scan(Scanner& scanner) {
      std::int_fast64_t value;
      scanner.scan(value);
      value = montgomery.transform(value);
    }

    template<class Printer>
    void print(Printer& printer) const {
      printer.print(montgomery.inverse_transform(value));
    }
  };

  template<class T, KYOPRO_BASE_UINT kind>
  struct Hash<DynamicModInt<T, kind>> {
    using value_type = DynamicModInt<T, kind>;

    std::size_t operator ()(DynamicModInt<T, kind> a) const noexcept { return static_cast<std::size_t>(a); }
  };
}
