#pragma once

namespace kpr
{
    [[maybe_unused]] inline constexpr struct
    {
        template <class T, class U = T>
        constexpr bool operator()(T &a, const U &b) const noexcept
        {
            if (a > b)
            {
                a = b;
                return true;
            }
            return false;
        }
    } chmin;

    [[maybe_unused]] inline constexpr struct
    {
        template <class T, class U = T>
        constexpr bool operator()(T &a, const U &b) const noexcept
        {
            if (a < b)
            {
                a = b;
                return true;
            }
            return false;
        }
    } chmax;
} // namespace kpr
