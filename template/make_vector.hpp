#pragma once
#include <cstddef>
#include <cstdint>
#include <utility>
#include <vector>

namespace kyopro {
    inline constexpr struct {
        template<std::size_t idx = 0, std::size_t n, class T>
        auto operator ()(const std::size_t (&d)[n], T&& init) noexcept {
            if constexpr (idx < n) return std::vector(d[idx], operator ()<idx + 1>(d, std::forward<T>(init)));
            else return init;
        }

        template<class T, std::size_t idx = 0, std::size_t n>
        auto operator ()(const std::size_t (&d)[n], const T& init = T()) noexcept {
            if constexpr (idx < n) return std::vector(d[idx], operator ()<idx + 1>(d, init));
            else return init;
        }
    } make_vector;
} // namespace kyopro