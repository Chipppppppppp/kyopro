#pragma once
#include <iterator>

namespace kpr
{
    // Rangeの型変換
    template <class To>
    struct RangeCast
    {
        template <class From>
        constexpr To operator()(From &&container) const noexcept
        {
            return To(std::begin(container), std::end(container));
        }
    };

    template <class To>
    inline constexpr RangeCast<To> range_cast;
} // namespace kpr
