#pragma once
#include <cstddef>
#include <cstdint>
#include <functional>
#include <tuple>
#include <type_traits>
#include <utility>
#include "../meta/aggregate.hpp"
#include "../meta/settings.hpp"
#include "../meta/trait.hpp"

namespace kyopro {
    template<class, class = void>
    struct Hash;

    template<class T>
    struct Hash<T, std::enable_if_t<std::is_scalar_v<T>>>: std::hash<T> {
        using value_type = T;

        constexpr std::size_t operator ()(T a) const noexcept {
            return std::hash<T>::operator ()(a);
        }
    };

    template<class T>
    struct Hash<T, std::enable_if_t<is_agg_v<T>>> {
        using value_type = T;

        template<KYOPRO_BASE_UINT i = 0>
        constexpr std::size_t operator ()(const T& a) const noexcept {
            if constexpr (i == aggregate_size_v<T>) return aggregate_size_v<T>;
            else {
                std::uint_fast64_t seed = operator()<i + 1>(a);
                return seed ^ (Hash<aggregate_element_t<i, T>>()(access<i>(a)) + 0x9e3779b97f4a7c15LU + (seed << 12) + (seed >> 4));
            }
        }
    };

    template<class T>
    struct Hash<T, std::enable_if_t<is_iterable_v<T>>>: Hash<iterable_value_t<T>> {
        using value_type = T;

        constexpr std::size_t operator ()(const T& a) const {
            std::uint_fast64_t seed = a.size();
            for (auto&& i: a) seed ^= Hash<iterable_value_t<T>>(i) + 0x9e3779b97f4a7c15LU + (seed << 12) + (seed >> 4);
            return seed;
        }
    };
} // namespace kyopro