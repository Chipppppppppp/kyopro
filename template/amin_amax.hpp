#pragma once

namespace kyopro {
  template<class T, class U>
  constexpr bool amin(T& a, U&& b) noexcept {
    if (b < a) {
      a = b;
      return true;
    }
    return false;
  }

  template<class T, class U>
  constexpr bool amax(T& a, U&& b) noexcept {
    if (a < b) {
      a = b;
      return true;
    }
    return false;
  }
}