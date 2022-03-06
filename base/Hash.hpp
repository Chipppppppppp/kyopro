#pragma once
#include <cstddef>
#include <functional>
#include <initializer_list>
#include <tuple>
#include <type_traits>
#include <utility>
#include "settings.hpp"
#include "trait.hpp"

namespace kyopro {
  template<class, class = void>
  struct Hash;

  template<class _typeT>
  struct Hash<_typeT, std::enable_if_t<std::is_scalar_v<_typeT>>> {
  private:
    [[no_unique_address]] std::hash<_typeT> _hashser;
  public:
    constexpr KYOPRO_BASE_UINT operator ()(_typeT a) const noexcept {
      return _hasher(a);
    }
  };

  template<class _typeT>
  struct Hash<_typeT, std::enable_if_t<is_tuple_v<_typeT>>> {
    template<KYOPRO_BASE_UINT _i = 0>
    constexpr KYOPRO_BASE_UINT operator ()(const _typeT& _a) const noexcept {
      if constexpr (_i == std::tuple_size_v<_typeT>) return std::tuple_size_v<_typeT>;
      else {
        KYOPRO_BASE_UINT _seed = operator()<_i + 1>(_a);
        return _seed ^ (Hash<std::tuple_element_t<_i, _typeT>>()(get<_i>(_a)) + 0x9e3779b97f4a7c15LU + (_seed << 12) + (_seed >> 4));
      }
    }
  };

  template<class _typeT>
  struct Hash<_typeT, std::enable_if_t<is_iterable_v<_typeT>>> {
  private:
    [[no_unique_address]] Hash<decltype(*std::begin(std::declval<_typeT>()))> _hasher;
  public:
    constexpr KYOPRO_BASE_UINT operator ()(const _typeT& _a) const noexcept {
      KYOPRO_BASE_UINT _seed = _a.size();
      for (auto& _i: _a) _seed ^= _hasher(_i) + 0x9e3779b97f4a7c15LU + (_seed << 12) + (_seed >> 4);
      return _seed;
    }
  };
}