#pragma once
#include <iterator>
#include "../meta/settings.hpp"

namespace kyopro {
    inline constexpr struct {
        template<class T>
        constexpr KYOPRO_BASE_INT operator ()(T&& a) const noexcept {
        return std::size(a);
        }
    } len;
} // namespace kyopro