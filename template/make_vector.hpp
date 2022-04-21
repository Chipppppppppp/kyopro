#pragma once
#include <cstdint>
#include <utility>
#include <vector>
#include "../meta/settings.hpp"

namespace kyopro {
  template<KYOPRO_BASE_UINT idx = 0, KYOPRO_BASE_UINT n, class T>
  auto make_vector(const KYOPRO_BASE_UINT (&d)[n], T&& init) noexcept {
    if constexpr (idx < n) return std::vector(d[idx], make_vector<idx + 1>(d, std::forward<T>(init)));
    else return init;
  }

  template<class T, KYOPRO_BASE_UINT idx = 0, KYOPRO_BASE_UINT n>
  auto make_vector(const KYOPRO_BASE_UINT (&d)[n], const T& init = T()) noexcept {
    if constexpr (idx < n) return std::vector(d[idx], make_vector<idx + 1>(d, init));
    else return init;
  }
}