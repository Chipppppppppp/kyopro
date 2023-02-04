#pragma once
#include <cstddef>
#include <tuple>

namespace kpr {
    template<std::size_t i, class... Args>
    struct indexed {
        std::tuple<Args...> args_tuple;
        indexed(Args&&... args) noexcept: args_tuple(std::forward_as_tuple(forward<Args>(args)...)) {}
    }
} // namespace kpr
