#pragma once
#include <algorithm>
#include <cstdint>
#include <numeric>
#include <random>
#include "../base/settings.hpp"
#include "is_prime.hpp"

namespace kyopro {
  template<class T>
  constexpr T pollard_rho(T n, KYOPRO_BASE_UINT c) {
    std::uint_fast64_t cc = c % n;
    auto f = [=](std::uint_fast64_t x) noexcept { return (x * x + cc) % n; };
    std::uint_fast64_t x = 1, y = 2, z = 1, q = 1;
    T g = 1;
    for (int r = 1; g == 1; r <<= 1) {
      x = y;
      for (int i = 0; i < r; ++i) y = f(y);
      for (int k = 0; k < r and g == 1; k += 128) {
        z = y;
        int min = std::min(128, r - k);
        for (int i = 0; i < min; ++i) {
          y = f(y);
          q = q * abs(x - y) % n;
        }
        g = std::gcd(q, n);
      }
    }
    if (g == n) {
      do {
        z = f(z);
        g = std::gcd(abs(x - z), n);
      } while (g == 1);
    }
    return g;
  }

  KYOPRO_BASE_UINT find_prime_factor(KYOPRO_BASE_UINT n) noexcept {
    static std::mt19937_64 mt(std::random_device{}());
    std::uniform_int_distribution<std::uint_fast64_t> rnd(0, n - 1);
    if (is_prime(n)) return n;
    for (int i = 0; i < 100; ++i) {
      std::uint_fast64_t m = pollard_rho(n, rnd(mt));
      if (is_prime(m)) return m;
      n = m;
    }
    return 1;
  }

  template<bool sorted = true, class _typeContainer = std::vector<KYOPRO_BASE_INT>>
  _typeContainer factorize(KYOPRO_BASE_UINT n) {
    _typeContainer res;
    for (int p = 2; p < 100 && p * p <= n; ++p) {
      while (n % p == 0) {
        n /= p;
        res.eb(p);
      }
    }
    while (n > 1) {
      std::uint_fast64_t p = find_prime_factor(n);
      while (n % p == 0) {
        n /= p;
        res.eb(p);
      }
    }
    if constexpr (sorted) std::sort(res.begin(), res.end());
    return res;
  }
}