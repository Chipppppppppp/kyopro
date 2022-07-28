#pragma once
#include <cstdint>
#include <vector>
#include "../meta/settings.hpp"

namespace kyopro {
    inline constexpr struct {
        template<class Container = std::vector<KYOPRO_BASE_INT>>
        Container operator ()(KYOPRO_BASE_UINT n) const {
            Container lower, upper;
            std::uint_fast64_t i;
            for (i = 1; i * i < n; ++i) if (n % i == 0) {
                lower.emplace_back(i);
                upper.emplace_back(n / i);
            }
            if (i * i == n) lower.emplace_back(i);
            lower.insert(end(lower), rall(upper));
            return lower;
        }
    } divisors;
} // namespace kyopro