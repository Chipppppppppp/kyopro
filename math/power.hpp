#pragma once
#include <cstddef>

namespace kyopro {
    inline constexpr struct {
        template<class T>
        constexpr T operator ()(T a, std::uint_fast64_t n, T init = 1) const noexcept {
            while (n > 0) {
                if (n & 1) init *= a;
                a *= a;
                n >>= 1;
            }
            return init;
        }
    } power;
} // namespace kyopro