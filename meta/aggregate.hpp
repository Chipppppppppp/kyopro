#pragma once
#include <cstdint>
#include <tuple>
#include <type_traits>
#include <utility>
#include "trait.hpp"

namespace kyopro {
  namespace helper {
    #define DEFINE_ACCESS(n, ...) \
    template<std::size_t idx, class T, std::enable_if_t<aggregate_size_v<std::decay_t<T>> == n>* = nullptr>\
    constexpr decltype(auto) access_impl(T&& aggregate, char) noexcept {\
      auto&& [__VA_ARGS__] = std::forward<T>(aggregate);\
      return std::get<idx>(std::forward_as_tuple(__VA_ARGS__));\
    }

    DEFINE_ACCESS(1, a)
    DEFINE_ACCESS(2, a, b)
    DEFINE_ACCESS(3, a, b, c)
    DEFINE_ACCESS(4, a, b, c, d)
    DEFINE_ACCESS(5, a, b, c, d, e)
    DEFINE_ACCESS(6, a, b, c, d, e, f)
    DEFINE_ACCESS(7, a, b, c, d, e, f, g)
    DEFINE_ACCESS(8, a, b, c, d, e, f, g, h)

    template<std::size_t idx, class T, std::void_t<decltype(std::get<idx>(std::declval<std::decay_t<T>>()))>* = nullptr>
    constexpr decltype(auto) access_impl(T&& aggregate, bool) noexcept {
      return std::get<idx>(std::forward<T>(aggregate));
    }

    #undef DEFINE_ACCESS
  }

  template<std::size_t idx, class T>
  constexpr decltype(auto) access(T&& aggregate) noexcept {
    return helper::access_impl<idx>(std::forward<T>(aggregate), false);
  }
}