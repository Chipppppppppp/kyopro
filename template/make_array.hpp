#pragma once
#include <array>
#include <utility>
#include "../meta/settings.hpp"

namespace kyopro {
  template<class T>
  constexpr auto make_array(const T& init = T()) noexcept { return init; }

  template<class T, KYOPRO_BASE_UINT length, KYOPRO_BASE_UINT... lengths>
  constexpr auto make_array(const T& init = T()) noexcept {
    auto elm = make_array<T, lengths...>(init);
    std::array<decltype(elm), length> res;
    for (auto& i: res) i = elm;
    return std::move(res);
  }
}