#pragma once
#include "../meta/settings.hpp"

namespace kyopro {
  constexpr KYOPRO_BASE_INT popcount(KYOPRO_BASE_INT _x) noexcept {
    _x = _x - ((_x >> 1) & 0x5555555555555555);
    _x = (_x & 0x3333333333333333) + ((_x >> 2) & 0x3333333333333333);
    _x = (_x + (_x >> 4)) & 0x0f0f0f0f0f0f0f0f;
    _x = _x + (_x >> 8);
    _x = _x + (_x >> 16);
    _x = _x + (_x >> 32);
    return _x & 0x0000007f;
  }
}