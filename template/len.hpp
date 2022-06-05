#pragma once
#include <iterator>
#include "../meta/settings.hpp"

namespace kyopro {
  template<class T>
  constexpr KYOPRO_BASE_INT len(T&& a) noexcept {
    return std::size(a);
  }
}