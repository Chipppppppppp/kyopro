#pragma once

namespace kpr {
    template<class T, class U = T>
    constexpr bool amin(T& a, const U& b) noexcept {
        if (b < a) {
            a = b;
            return true;
        }
        return false;
    }

    template<class T, class U = T>
    constexpr bool amax(T& a, const U& b) noexcept {
        if (a < b) {
            a = b;
            return true;
        }
        return false;
    }
} // namespace kpr
