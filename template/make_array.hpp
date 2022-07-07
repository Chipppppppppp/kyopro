#pragma once
#include <array>
#include "../meta/settings.hpp"

namespace kyopro {
  inline constexpr struct {
    template<class T>
    constexpr auto operator ()(const T& init = T()) noexcept { return init; }

    template<class T, KYOPRO_BASE_UINT length, KYOPRO_BASE_UINT... lengths>
    constexpr auto operator ()(const T& init = T()) noexcept {
      auto elm = operator ()<T, lengths...>(init);
      std::array<decltype(elm), length> res;
      for (auto& i: res) i = elm;
      return res;
    }
  } make_array;
}