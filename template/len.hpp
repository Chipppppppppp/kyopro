#pragma once
#include <iterator>
#include "../meta/settings.hpp"

namespace kpr {
  template<class T>
  constexpr KYOPRO_BASE_INT len(T&& a) noexcept {
    return std::size(a);
  }
}