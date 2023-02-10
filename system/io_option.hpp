#pragma once
#include <cstddef>
#include <tuple>
#include <utility>

namespace kpr {
    template<class Tuple, std::size_t idx>
    struct Indexed {
        Tuple args_tuple;
        template<class... Args>
        constexpr Indexed(Args&&... args) noexcept: args_tuple{std::forward<Args>(args)...} {}
    };

    template<std::size_t i, class... Args>
    constexpr auto indexed(Args&&... args) noexcept {
        return Indexed<std::tuple<Args>..., i>{std::forward<Args>(args)...};
    }

    template<class Tuple, bool... seps>
    struct SepWith {
        Tuple args_tuple;
        template<class... Args>
        constexpr SepWith(Args&&... args) noexcept: args_tuple{std::forward<Args>(args)...} {}
    };

    template<bool... seps, class... Args>
    constexpr auto sep_with(Args&&... args) noexcept {
        return SepWith<std::tuple<Args...>, seps...>{std::forward<Args>(args)...};
    }
} // namespace kpr
