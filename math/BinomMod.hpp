#pragma once
#include <array>
#include <cstdint>
#include "../meta/constant.hpp"
#include "ModInt.hpp"

namespace kpr {
    // mod二項係数
    template<std::size_t max = 1000000, KYOPRO_BASE_UINT m = mod>
    struct BinomMod {
        std::array<std::uint_fast64_t, max> fact, factinv, inv;
        constexpr BinomMod() noexcept {
            fact[0] = fact[1] = 1;
            factinv[0] = factinv[1] = 1;
            inv[0] = 0;
            inv[1] = 1;
            for (int i = 2; i < (int)max; ++i) {
                fact[i] = fact[i - 1] * i % m;
                inv[i] = m - inv[m % i] * (m / i) % m;
                factinv[i] = factinv[i - 1] * inv[i] % m;
            }
        }

        constexpr ModInt<m> c(KYOPRO_BASE_UINT n, KYOPRO_BASE_UINT r) noexcept {
            if (n < r) return 0;
            return ModInt<m>(fact[n] * factinv[n - r] % m * factinv[r]);
        }
        constexpr ModInt<m> p(KYOPRO_BASE_UINT n) noexcept {
            return ModInt<m>::raw(fact[n]);
        }
        constexpr ModInt<m> p(KYOPRO_BASE_UINT n, KYOPRO_BASE_UINT r) noexcept {
            if (n < r) return 0;
            return ModInt<m>(fact[n] * factinv[n - r]);
        }
        constexpr ModInt<m> h(KYOPRO_BASE_UINT n, KYOPRO_BASE_UINT r) noexcept {
            return c(n + r - 1, r);
        }
    };
} // namespace kpr
