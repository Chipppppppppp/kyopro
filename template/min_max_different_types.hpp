#pragma once
#include <algorithm>
#include <type_traits>

using std::min, std::max;

template<class _typeT, class _typeU, std::enable_if_t<!std::is_same_v<_typeT, _typeU>>* = nullptr>
constexpr std::common_type_t<_typeT, _typeU> min(const _typeT& a, const _typeU& b) noexcept {
  return a < b ? a : b;
}

template<class _typeT, class _typeU, std::enable_if_t<!std::is_same_v<_typeT, _typeU>>* = nullptr>
constexpr std::common_type_t<_typeT, _typeU> max(const _typeT& a, const _typeU& b) noexcept {
  return a > b ? a : b;
}