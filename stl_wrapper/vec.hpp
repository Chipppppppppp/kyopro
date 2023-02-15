#pragma once
#include <cstdint>
#include <vector>

namespace kpr {
    namespace helper {
        template<std::size_t i = 0, std::size_t n, class T>
        auto make_vec(const std::size_t (&d)[n], const T& init) noexcept {
            if constexpr (i < n) return std::vector(d[i], make_vec<i + 1>(d, init));
            else return init;
        }
    }
    template<class T, std::size_t n>
    struct Vec: decltype(helper::make_vec(std::declval<const std::size_t (&)[n]>(), std::declval<const T&>())) {
        using super = decltype(helper::make_vec(std::declval<const std::size_t (&)[n]>(), std::declval<const T&>()));
        using super::vector, super::operator =;

        Vec(const std::size_t (&d)[n], const T& init) noexcept: super{helper::make_vec(d, init)} {}
    };
} // namespace kpr
