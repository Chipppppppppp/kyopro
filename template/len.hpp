#pragma once
#include <iterator>
#include "../meta/setting.hpp"

namespace kpr {
    [[maybe_unused]] inline constexpr struct {
        template<class T>
        constexpr KYOPRO_BASE_INT operator ()(T&& a) const noexcept {
            return std::size(a);
        }
    } len;
} // namespace kpr
