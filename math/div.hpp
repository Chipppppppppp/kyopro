#pragma once
#include <type_traits>

namespace kyopro {
    inline constexpr struct {
        template<class T, class U>
        constexpr std::common_type_t<T, U> operator ()(T x, U m) const noexcept {
            static_assert(std::is_integral_v<T> && std::is_integral_v<U>, "Integer is required");
            if constexpr (std::is_unsigned_v<T> || std::is_unsigned_v<U>) return x / m;
            auto d = x / m;
            return d * m == x ? d : d - ((x < 0) ^ (m < 0));
        }
    } floor_div;

    inline constexpr struct {
        template<class T, class U>
        constexpr std::common_type_t<T, U> operator ()(T x, U m) const noexcept {
            return floor_div(x + m - static_cast<T>(1), m);
        }
    } ceil_div;
} // namespace kyopro