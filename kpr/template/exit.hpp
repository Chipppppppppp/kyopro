#pragma once
#include <cstdlib>

namespace kpr
{
    [[maybe_unused]] inline constexpr struct
    {
        [[noreturn]] constexpr void operator()() const noexcept
        {
            std::exit(0);
        }
    } exit;
} // namespace kpr
