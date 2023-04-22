#pragma once
#include <cstddef>
#include <tuple>

#define $(...) \
([&](auto&&... _args) { \
    return ([&]([[maybe_unused]] auto&& $0, [[maybe_unused]] auto&& $1, [[maybe_unused]] auto&& $2, [[maybe_unused]] auto&& $3, [[maybe_unused]] auto&& $4, std::nullptr_t = nullptr, std::nullptr_t = nullptr, std::nullptr_t = nullptr, std::nullptr_t = nullptr, std::nullptr_t = nullptr) noexcept { return (__VA_ARGS__); })(std::forward<decltype(_args)>(_args)..., nullptr, nullptr, nullptr, nullptr, nullptr); \
})
