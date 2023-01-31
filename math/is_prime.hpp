#pragma once
#include <cstddef>
#include <cstdint>
#include <type_traits>
#include "../algorithm/bit.hpp"
#include "../meta/setting.hpp"
#include "DynamicModInt.hpp"

namespace kpr {
    [[maybe_unused]] inline constexpr struct {
        template<class T>
        constexpr bool operator ()(T x) const {
            using U = std::make_unsigned_t<T>;
            using dmint = DynamicModInt<U, 0, true>;
            U n = x;
            if (n <= 1) return false;
            if (!(n & 1)) return n == 2;
            dmint::set_mod(n);
            std::uint_fast64_t d = (n - 1) >> count_rzero(n - 1);
            dmint one = 1, minus_one = n - 1;
            auto ng = [&](std::uint_fast64_t a) noexcept {
                auto y = dmint(a).power(d);
                std::uint_fast64_t t = d;
                while (y != one and y != minus_one and t != n - 1) y *= y, t <<= 1;
                if (y != minus_one and !(t & 1)) return true;
                return false;
            };
            if constexpr (std::numeric_limits<U>::digits <= 32) {
                for (auto i: (std::uint_fast64_t[3]){2, 7, 61}) {
                    if (n <= i) return true;
                    if (ng(i)) return false;
                }
            } else if (n < (static_cast<U>(1) << 32)) {
                for (auto i: (std::uint_fast64_t[3]){2, 7, 61}) {
                    if (n <= i) return true;
                    if (ng(i)) return false;
                }
            } else {
                for (auto i: (std::uint_fast64_t[7]){2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
                    if (n <= i) return true;
                    if (ng(i)) return false;
                }
            }
            return true;
        }
    } is_prime;
} // namespace kpr
