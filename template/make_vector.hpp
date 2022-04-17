#pragma once
#include <cstdint>
#include <utility>
#include <vector>
#include "../meta/settings.hpp"

namespace kyopro {
  template<KYOPRO_BASE_UINT _idx = 0, KYOPRO_BASE_UINT _n, class _typeT>
  auto make_vector(const KYOPRO_BASE_UINT (&_d)[_n], _typeT&& _init) noexcept {
    if constexpr (_idx < _n) return std::vector(_d[_idx], make_vector<_idx + 1>(_d, std::forward<_typeT>(_init)));
    else return _init;
  }

  template<class _typeT, KYOPRO_BASE_UINT _idx = 0, KYOPRO_BASE_UINT _n>
  auto make_vector(const KYOPRO_BASE_UINT (&_d)[_n], const _typeT& _init = _typeT()) noexcept {
    if constexpr (_idx < _n) return std::vector(_d[_idx], make_vector<_idx + 1>(_d, _init));
    else return _init;
  }
}