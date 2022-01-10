#pragma once
#include <cstdint>
#include <type_traits>
#include <cassert>
#include "../base/settings.hpp"
#include "../base/constant.hpp"
#include "../base/hash.hpp"
#include "mod.hpp"

namespace kyopro {
  template<std::uint64_t m>
  struct ModInt {
    static constexpr std::uint64_t mod = m;
    std::uint64_t value;
    constexpr ModInt() noexcept = default;
    template<class T>
    constexpr ModInt(T value) noexcept: value(floor_mod(value, m)) { static_assert(std::is_integral_v<T>); }
    template<class T>
    explicit constexpr operator T() const noexcept { return value; }
    static constexpr ModInt raw(std::uint64_t n) noexcept {
      ModInt res;
      res.value = n;
      return res;
    }
    constexpr ModInt power(std::uint64_t n) const noexcept {
      std::uint64_t res = 1, a = value;
      while (n > 0) {
        if (n & 1) res = res * a % m;
        a = a * a % m;
        n >>= 1;
      }
      return res;
    }
    constexpr ModInt inv() const noexcept {
      std::uint64_t a = value, b = m;
      std::int64_t u = 1, v = 0;
      while (b > 0) {
        std::uint64_t t = a / b;
        a -= t * b;
        std::swap(a, b);
        u -= t * v;
        std::swap(u, v);
      }
      return floor_mod(u, m);
    }
    constexpr ModInt operator +() const noexcept { return *this; }
    constexpr ModInt operator -() const noexcept { return m - value; }
    constexpr ModInt& operator ++() noexcept {
      if (++value >= m) value -= m;
      return *this;
    }
    constexpr ModInt operator ++(int) noexcept {
      ModInt before = *this;
      operator ++();
      return before;
    }
    constexpr ModInt& operator --() noexcept {
      if (value == 0) value = m;
      --value;
      return *this;
    }
    constexpr ModInt operator --(int) noexcept {
      ModInt before = *this;
      operator --();
      return before;
    }
    constexpr ModInt& operator +=(ModInt rhs) noexcept {
      if ((value += rhs.value) >= m) value -= m;
      return *this;
    }
    constexpr ModInt& operator -=(ModInt rhs) noexcept {
      if (value < rhs.value) value += m;
      value -= rhs.value;
      return *this;
    }
    constexpr ModInt& operator *=(ModInt rhs) noexcept {
      value = value * rhs.value % m;
      return *this;
    }
    constexpr ModInt& operator /=(ModInt rhs) noexcept {
      value = value * rhs.inv().value % m;
      return *this;
    }
    friend constexpr ModInt operator +(ModInt lhs, ModInt rhs) noexcept { return lhs += rhs; }
    friend constexpr ModInt operator -(ModInt lhs, ModInt rhs) noexcept { return lhs -= rhs; }
    friend constexpr ModInt operator *(ModInt lhs, ModInt rhs) noexcept { return lhs *= rhs; }
    friend constexpr ModInt operator /(ModInt lhs, ModInt rhs) noexcept { return lhs /= rhs; }
    friend constexpr bool operator ==(ModInt lhs, ModInt rhs) noexcept { return lhs.value == rhs.value; }
    friend constexpr bool operator !=(ModInt lhs, ModInt rhs) noexcept { return lhs.value != rhs.value; }
  };

  template<KYOPRO_BASE_UINT m>
  struct Hash<ModInt<m>> { constexpr KYOPRO_BASE_UINT operator ()(ModInt<m> kyopro_a) const noexcept { return kyopro_a; } };

  constexpr ModInt<mod> operator "" _m(unsigned long long a) noexcept { return a; }
}