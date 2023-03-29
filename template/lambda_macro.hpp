#pragma once
#include <iterator>
#include <tuple>
#include "../meta/tuple_like.hpp"

#define $(...) \
([&](auto&&... _args) { \
    auto _args_tuple = std::forward_as_tuple(_args...); \
    if constexpr (sizeof...(_args) == 0) { \
        return ([&]() { return (__VA_ARGS__); })(); \
    } else if constexpr (sizeof...(_args) == 1) { \
        return ([&](auto&& $0) { return (__VA_ARGS__); })(get<0>(_args_tuple)); \
    } else if constexpr (sizeof...(_args) == 2) { \
        return ([&](auto&& $0, auto&& $1) { return (__VA_ARGS__); })(get<0>(_args_tuple), get<1>(_args_tuple)); \
    } else if constexpr (sizeof...(_args) == 3) { \
        return ([&](auto&& $0, auto&& $1, auto&& $2) { return (__VA_ARGS__); })(get<0>(_args_tuple), get<1>(_args_tuple), get<2>(_args_tuple)); \
    } else if constexpr (sizeof...(_args) == 4) { \
        return ([&](auto&& $0, auto&& $1, auto&& $2, auto&& $3) { return (__VA_ARGS__); })(get<0>(_args_tuple), get<1>(_args_tuple), get<2>(_args_tuple), get<3>(_args_tuple)); \
    } \
})
