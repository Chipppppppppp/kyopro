#pragma once
#include <cstdint>
#include "../meta/setting.hpp"

namespace kpr
{
    // オイラーのφ関数
    [[maybe_unused]] inline constexpr struct
    {
        constexpr KYOPRO_BASE_INT operator()(std::uint_fast64_t n) const noexcept
        {
            std::uint_fast64_t res = n;
            if ((n & 1) == 0)
            {
                res -= res >> 1;
                n >>= 1;
                while ((n & 1) == 0)
                    n >>= 1;
            }
            for (std::uint_fast64_t i = 3; i * i <= n; i += 2)
            {
                if (n % i == 0)
                {
                    res -= res / i;
                    n /= i;
                    while (n % i == 0)
                        n /= i;
                }
            }
            if (n != 1)
                res -= res / n;
            return res;
        }
    } euler_phi;
} // namespace kpr
