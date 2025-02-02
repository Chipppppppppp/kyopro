#pragma once
#include "../io/out.hpp"

namespace kpr {
    [[maybe_unused]] inline constexpr struct {
        void operator ()(bool f) const noexcept {
            if (f) print('Y', 'e', 's', '\n');
            else print('N', 'o', '\n');
        }
    } YesNo;
} // namespace kpr
