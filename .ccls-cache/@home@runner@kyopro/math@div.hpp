#pragma once
#include "../meta/trait.hpp"

namespace kpr {
    // floor(a ÷ b)を返す
    [[maybe_unused]] inline constexpr struct {
        template<class T, class U>
        constexpr std::common_type_t<T, U> operator ()(T x, U m) const noexcept {
            static_assert(is_integer_v<T> && is_integer_v<U>, "Both of the arguments must be integers");
            if constexpr (is_unsigned_integer_v<T> || is_unsigned_integer_v<U>) return x / m;
            auto d = x / m;
            return d * m == x ? d : d - ((x < 0) ^ (m < 0));
        }
    } floor_div;

    // ceil(a ÷ b)を返す
    [[maybe_unused]] inline constexpr struct {
        template<class T, class U>
        constexpr std::common_type_t<T, U> operator ()(T x, U m) const noexcept {
            return floor_div(x + m - static_cast<T>(1), m);
        }
    } ceil_div;
} // namespace kpr
