#pragma once
#include <cstdint>
#include "../function/monoid.hpp"
#include "../meta/setting.hpp"

namespace kpr {
    [[maybe_unused]] inline constexpr struct {
        template<class T>
        constexpr T operator ()(T a, KYOPRO_BASE_UINT n, T init = Mul<T>::id()) const noexcept {
            while (n > 0) {
                if (n & 1) init *= a;
                a *= a;
                n >>= 1;
            }
            return init;
        }
    } power;
} // namespace kpr
