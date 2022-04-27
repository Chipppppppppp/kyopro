#pragma once
#include <array>
#include "../meta/settings.hpp"

namespace kpr {
  inline constexpr std::array<std::pair<KYOPRO_BASE_INT, KYOPRO_BASE_INT>, 4> beside{{{-1, 0}, {0, -1}, {1, 0}, {0, 1}}};
  inline constexpr std::array<std::pair<KYOPRO_BASE_INT, KYOPRO_BASE_INT>, 8> around{{{-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}}};
}