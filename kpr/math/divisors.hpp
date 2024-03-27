#pragma once
#include <cstdint>
#include <vector>
#include "../meta/setting.hpp"

namespace kpr {
    // 全ての正の約数を返す
    [[maybe_unused]] inline constexpr struct {
        std::vector<KYOPRO_BASE_INT> operator ()(std::uint_fast64_t n) const {
            std::vector<KYOPRO_BASE_INT> lower, upper;
            std::uint_fast64_t i;
            for (i = 1; i * i < n; ++i) if (n % i == 0) {
                lower.emplace_back(i);
                upper.emplace_back(n / i);
            }
            if (i * i == n) lower.emplace_back(i);
            lower.insert(lower.end(), upper.rbegin(), upper.rend());
            return lower;
        }
    } divisors;
} // namespace kpr
