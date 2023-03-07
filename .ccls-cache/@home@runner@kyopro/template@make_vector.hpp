#pragma once
#include <cstddef>
#include <cstdint>
#include <utility>
#include <vector>

namespace kpr {
    [[maybe_unused]] inline constexpr struct {
        template<class T, std::size_t n, std::size_t i = 0>
        auto operator ()(const std::size_t (&d)[n], const T& init = {}) noexcept {
            if constexpr (i < n) return std::vector(d[i], operator ()<T, n, i + 1>(d, init));
            else return init;
        }

        template<class T, std::size_t n>
        auto operator ()(const std::size_t (&d)[n]) noexcept {
            return operator ()(d, T{});
        }
    } make_vector;
} // namespace kpr
