#pragma once
#include <cstddef>
#include <functional>
#include <iterator>
#include <type_traits>
#include <utility>
#include "../meta/tuple_like.hpp"
#include "../meta/trait.hpp"

namespace kpr
{
    // ハッシュ(tuple_like, range対応)
    template <class, class = void>
    struct Hash;

    template <class T>
    struct Hash<T, std::enable_if_t<std::is_scalar_v<T>>>
    {
        using value_type = T;

        constexpr std::size_t operator()(T a) const noexcept
        {
            return std::hash<T>{}(a);
        }
    };

    template <class T>
    struct Hash<T, std::enable_if_t<is_tuple_like_v<T> && !is_range_v<T>>>
    {
        using value_type = T;

        template <std::size_t i = 0>
        constexpr std::size_t operator()(const T &a) const noexcept
        {
            if constexpr (i == tuple_like_size_v<T>)
                return tuple_like_size_v<T>;
            else
            {
                std::size_t seed = operator()<i + 1>(a);
                return seed ^ (Hash<tuple_like_element_t<i, T>>{}(get<i>(a)) + 0x9e3779b97f4a7c15LU + (seed << 12) + (seed >> 4));
            }
        }
    };

    template <class T>
    struct Hash<T, std::enable_if_t<is_range_v<T>>> : Hash<range_value_t<T>>
    {
        using value_type = T;

        constexpr std::size_t operator()(const T &a) const
        {
            std::size_t seed = std::size(a);
            for (auto &&i : a)
                seed ^= Hash<range_value_t<T>>{}(i) + 0x9e3779b97f4a7c15LU + (seed << 12) + (seed >> 4);
            return seed;
        }
    };
} // namespace kpr
