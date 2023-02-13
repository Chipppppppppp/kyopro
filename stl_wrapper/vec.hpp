#pragma once
#include <cstdint>
#include <vector>

namespace kpr {
    template<class T, std::size_t d>
    struct Vec: std::vector<Vec<T, d - 1>> {
        using std::vector<Vec<T, d - 1>>::vector, std::vector<Vec<T, d - 1>>::operator =;
        template<std::size_t i = 0>
        Vec(const std::array<T, d>& l, const T& init) {
            std::vector(l[i], Vec<T, d - 1>::Vec<i + 1>(l, init));
        }
    };
} // namespace kpr
