#pragma once
#include <algorithm>
#include <type_traits>

using std::min, std::max;

template<class T, class U, std::enable_if_t<!std::is_same_v<T, U>>* = nullptr>
constexpr std::common_type_t<T, U> min(const T& a, const U& b) noexcept {
  return a < b ? a : b;
}

template<class T, class U, std::enable_if_t<!std::is_same_v<T, U>>* = nullptr>
constexpr std::common_type_t<T, U> max(const T& a, const U& b) noexcept {
  return a > b ? a : b;
}