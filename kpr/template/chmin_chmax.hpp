#pragma once

namespace kpr {
    // assign min
    [[maybe_unused]] inline constexpr struct {
        template<class T, class U = T>
        constexpr bool operator ()(T& a, const U& b) const noexcept {
            if (a > b) {
                a = b;
                return true;
            }
            return false;
        }
    } chmin;

    // assign max
    [[maybe_unused]] inline constexpr struct {
        template<class T, class U = T>
        constexpr bool operator ()(T& a, const U& b) const noexcept {
            if (a < b) {
                a = b;
                return true;
            }
            return false;
        }
    } chmax;
} // namespace kpr
