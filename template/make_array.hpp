#pragma once
#include <array>
#include <utility>
#include "../meta/settings.hpp"

namespace kyopro {
  template<class _typeT>
  constexpr auto make_array(const _typeT& _init = _typeT()) noexcept { return _init; }

  template<class _typeT, KYOPRO_BASE_UINT _length, KYOPRO_BASE_UINT... _lengths>
  constexpr auto make_array(const _typeT& _init = _typeT()) noexcept {
    auto _elm = make_array<_typeT, _lengths...>(_init);
    std::array<decltype(_elm), _length> _res;
    for (auto& _i: _res) _i = _elm;
    return std::move(_res);
  }
}