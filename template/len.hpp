#pragma once
#include <iterator>
#include "../meta/settings.hpp"

namespace kyopro {
  template<class _typeT>
  constexpr KYOPRO_BASE_INT len(_typeT&& _a) noexcept {
    return std::size(_a);
  }
}