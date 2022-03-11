#pragma once
#include <array>
#include <cstdint>
#include <limits>
#include <utility>
#include "../math/power.hpp"
#include "settings.hpp"

namespace kyopro {
  template<class _typeT>
  inline constexpr _typeT MOD = KYOPRO_DEFAULT_MOD;
  inline constexpr KYOPRO_BASE_INT mod = MOD<KYOPRO_BASE_INT>;

  template<class _typeT>
  inline constexpr _typeT INF = std::numeric_limits<_typeT>::max() / KYOPRO_INF_DIV;
  inline constexpr KYOPRO_BASE_INT inf = INF<KYOPRO_BASE_INT>;

  template<class _typeT, fileno _decimal_precision = KYOPRO_DECIMAL_PRECISION>
  inline constexpr KYOPRO_BASE_FLOAT EPS = static_cast<_typeT>(1) / power(static_cast<std::uint_fast64_t>(10), _decimal_precision);
  inline constexpr KYOPRO_BASE_FLOAT eps = EPS<KYOPRO_BASE_FLOAT>;

  template<class _typeT>
  inline constexpr _typeT PI = 3.14159265358979323846;
  inline constexpr KYOPRO_BASE_FLOAT pi = PI<KYOPRO_BASE_FLOAT>;

  inline constexpr std::array<std::pair<KYOPRO_BASE_INT, KYOPRO_BASE_INT>, 4> beside{{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}};
  inline constexpr std::array<std::pair<KYOPRO_BASE_INT, KYOPRO_BASE_INT>, 8> around{{{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}}};
}