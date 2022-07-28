#pragma once
#include <cassert>
#include <type_traits>

namespace kyopro {
    inline constexpr struct {
        template<class T, class U>
        constexpr std::common_type_t<T, U> operator ()(T x, U m) const noexcept {
            static_assert(std::is_integral_v<T> && std::is_integral_v<U>, "Integer is required");
            if constexpr (std::is_unsigned_v<T> || std::is_unsigned_v<U>) return x % m;
            return (x %= m) < 0 ? x + m : x;
        }
    } floor_mod;

    inline constexpr struct {
        template<class T, class U>
        constexpr std::common_type_t<T, U> operator ()(T x, U m) const noexcept {
            return m - floor_mod(x - 1, m) - static_cast<T>(1);
        }
    } ceil_mod;
} // namespace kyopro