#pragma once
#include <array>
#include <cstdint>
#include "../meta/constant.hpp"
#include "ModInt.hpp"

namespace kpr
{
    // mod二項係数
    template <std::size_t max = KYOPRO_BINOM_MOD_MAX, class T = ModInt<mod>>
    struct BinomMod
    {
    private:
        static constexpr auto m = T::m;

    public:
        using value_type = T;
        inline static std::array<typename T::value_type, max> fact, factinv, inv;

        constexpr BinomMod() noexcept
        {
            fact[0] = fact[1] = 1;
            factinv[0] = factinv[1] = 1;
            inv[1] = 1;
            for (int i = 2; i < (int)max; ++i)
            {
                fact[i] = static_cast<typename T::multiplies_type>(fact[i - 1]) * i % m;
                inv[i] = m - static_cast<typename T::value_type>(static_cast<typename T::multiplies_type>(inv[m % i]) * (m / i) % m);
                factinv[i] = static_cast<typename T::multiplies_type>(factinv[i - 1]) * inv[i] % m;
            }
        }

        constexpr T c(KYOPRO_BASE_UINT n, KYOPRO_BASE_UINT r) noexcept
        {
            if (n < r)
                return 0;
            return T(fact[n] * factinv[n - r] % m * factinv[r]);
        }
        constexpr T p(KYOPRO_BASE_UINT n) noexcept
        {
            return T::raw(fact[n]);
        }
        constexpr T p(KYOPRO_BASE_UINT n, KYOPRO_BASE_UINT r) noexcept
        {
            if (n < r)
                return 0;
            return T(fact[n] * factinv[n - r]);
        }
        constexpr T h(KYOPRO_BASE_UINT n, KYOPRO_BASE_UINT r) noexcept
        {
            return c(n + r - 1, r);
        }
    };
} // namespace kpr
