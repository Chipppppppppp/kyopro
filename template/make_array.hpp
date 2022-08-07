#pragma once
#include <cstddef>
#include <array>

namespace kyopro {
    inline constexpr struct {
        template<class T>
        constexpr auto operator ()(const T& init = T()) noexcept {
            return init;
        }

        template<class T, std::size_t length, std::size_t... lengths>
        constexpr auto operator ()(const T& init = T()) noexcept {
            auto elm = operator ()<T, lengths...>(init);
            std::array<decltype(elm), length> res;
            for (auto& i: res) i = elm;
            return res;
        }
    } make_array;
} // namespace kyopro