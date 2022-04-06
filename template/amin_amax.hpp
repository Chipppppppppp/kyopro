#pragma once

namespace kyopro {
  template<class _typeT, class _typeU>
  constexpr bool amin(_typeT& a, _typeU&& b) noexcept {
    if (b < a) {
      a = b;
      return true;
    }
    return false;
  }

  template<class _typeT, class _typeU>
  constexpr bool amax(_typeT& a, _typeU&& b) noexcept {
    if (a < b) {
      a = b;
      return true;
    }
    return false;
  }
}