#pragma once
#include <limits>
#include <array>
#include <utility>
#include "settings.hpp"

namespace kyopro {
  template<class KyoproT>
  inline constexpr KyoproT MOD = KYOPRO_DEFAULT_MOD;
  inline constexpr KYOPRO_BASE_INT mod = MOD<KYOPRO_BASE_INT>;
  template<class KyoproT>
  inline constexpr KyoproT INF = std::numeric_limits<KyoproT>::max() / KYOPRO_INF_DIV;
  inline constexpr KYOPRO_BASE_INT inf = INF<KYOPRO_BASE_INT>;
  template<class KyoproT>
  inline constexpr KyoproT PI = 3.14159265358979323846;
  inline constexpr KYOPRO_BASE_FLOAT pi = PI<KYOPRO_BASE_FLOAT>;
  using KyoproPair = std::pair<KYOPRO_BASE_INT, KYOPRO_BASE_INT>;
  inline constexpr std::array<KyoproPair, 4> beside{KyoproPair{1, 0}, KyoproPair{0, 1}, KyoproPair{-1, 0}, KyoproPair{0, -1}};
  inline constexpr std::array<KyoproPair, 8> around{KyoproPair{1, 0}, KyoproPair{1, 1}, KyoproPair{0, 1}, KyoproPair{-1, 1}, KyoproPair{-1, 0}, KyoproPair{-1, -1}, KyoproPair{0, -1}, KyoproPair{1, -1}};
}