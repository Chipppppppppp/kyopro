#pragma once
#include <cstddef>
#include <cstdint>
#include <utility>
#include <vector>

namespace kpr
{
    // 多次元vectorを生成する
    template <class T, std::size_t n, std::size_t i = 0>
    auto make_vec(const std::size_t (&d)[n], const T &init = {}) noexcept
    {
        if constexpr (i < n)
            return std::vector(d[i], make_vec<T, n, i + 1>(d, init));
        else
            return init;
    }
} // namespace kpr
