#pragma once
#include <cassert>
#include <type_traits>

namespace kpr
{
    [[maybe_unused]] inline constexpr struct
    {
        template <class T, class U>
        constexpr std::common_type_t<T, U> operator()(T x, U m) const noexcept
        {
            static_assert(is_integer_v<T> && is_integer_v<U>, "Both of the arguments must be integers");
            if constexpr (is_unsigned_integer_v<T> || is_unsigned_integer_v<U>)
                return x % m;
            return (x %= m) < 0 ? x + m : x;
        }
    } floor_mod;

    [[maybe_unused]] inline constexpr struct
    {
        template <class T, class U>
        constexpr std::common_type_t<T, U> operator()(T x, U m) const noexcept
        {
            return m - floor_mod(x - 1, m) - static_cast<T>(1);
        }
    } ceil_mod;
} // namespace kpr
