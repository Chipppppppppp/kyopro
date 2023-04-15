#pragma once
#include <cstddef>
#include <array>

namespace kpr {
    // 0次元arrayを生成する
    template<class T>
    constexpr auto make_array(const T& init = {}) noexcept {
        return init;
    }

    // 多次元arrayを生成する
    template<class T, std::size_t l, std::size_t... d>
    constexpr auto make_array(const T& init = {}) noexcept {
        std::array<decltype(make_array<T, d...>(init)), l> res{};
        res.fill(make_array<T, d...>(init));
        return res;
    }
} // namespace kpr
