#pragma once
#include "../io/out.hpp"

namespace kpr {
    [[maybe_unused]] inline constexpr struct {
        void operator ()(bool f) const noexcept {
            if (f) println('Y', 'e', 's');
            else println('N', 'o');
        }
    } YesNo;
} // namespace kpr
