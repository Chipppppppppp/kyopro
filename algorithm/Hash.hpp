#pragma once
#include <cstddef>
#include <cstdint>
#include <functional>
#include <tuple>
#include <type_traits>
#include <utility>
#include "../meta/settings.hpp"
#include "../meta/trait.hpp"

namespace kpr {
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
  struct Hash<T, std::enable_if_t<is_tuple_v<T>>> {
    using value_type = T;

    template<KYOPRO_BASE_UINT i = 0>
    constexpr std::size_t operator ()(const T& a) const noexcept {
      if constexpr (i == std::tuple_size_v<T>) return std::tuple_size_v<T>;
      else {
        std::uint_fast64_t seed = operator()<i + 1>(a);
        return seed ^ (Hash<std::tuple_element_t<i, T>>()(std::get<i>(a)) + 0x9e3779b97f4a7c15LU + (seed << 12) + (seed >> 4));
      }
    }
  };

  template<class T>
  struct Hash<T, std::enable_if_t<is_iterable_v<T>>>: Hash<iterable_value_t<T>> {
    using value_type = T;

    constexpr std::size_t operator ()(const T& a) const noexcept {
      std::uint_fast64_t seed = a.size();
      for (auto& i: a) seed ^= Hash<iterable_value_t<T>>(i) + 0x9e3779b97f4a7c15LU + (seed << 12) + (seed >> 4);
      return seed;
    }
  };
}