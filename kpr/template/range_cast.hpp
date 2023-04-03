#pragma once
#include <iterator>

namespace kpr {
    // Rangeの型変換
    [[maybe_unused]] inline constexpr struct {
        template<class To, class From>
        constexpr To operator ()(From&& container) const noexcept {
            return To(std::begin(container), std::end(container));
        }
    } range_cast;
} // namespace kpr
