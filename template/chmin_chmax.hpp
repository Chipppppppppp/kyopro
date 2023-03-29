#pragma once

namespace kpr {
    // min assign
    template<class T, class U = T>
    constexpr bool chmin(T& a, const U& b) noexcept {
        if (b < a) {
            a = b;
            return true;
        }
        return false;
    }

    // max assign
    template<class T, class U = T>
    constexpr bool chmax(T& a, const U& b) noexcept {
        if (a < b) {
            a = b;
            return true;
        }
        return false;
    }
} // namespace kpr
