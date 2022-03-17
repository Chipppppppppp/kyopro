#pragma once
#include <cstddef>
#include <cstdint>
#include <functional>
#include <initializer_list>
#include <tuple>
#include <type_traits>
#include <utility>
#include "../meta/settings.hpp"
#include "../meta/trait.hpp"

namespace kyopro {
  template<class, class = void>
  struct Hash;

  template<class _typeT>
  struct Hash<_typeT, std::enable_if_t<std::is_scalar_v<_typeT>>> {
  private:
    [[no_unique_address]] std::hash<_typeT> _hashser;

  public:
    constexpr std::size_t operator ()(_typeT a) const noexcept {
      return _hasher(a);
    }
  };

  template<class _typeT>
  struct Hash<_typeT, std::enable_if_t<is_tuple_v<_typeT>>> {
    template<std::size_t _i = 0>
    constexpr std::size_t operator ()(const _typeT& _a) const noexcept {
      if constexpr (_i == std::tuple_size_v<_typeT>) return std::tuple_size_v<_typeT>;
      else {
        std::uint_fast64_t _seed = operator()<_i + 1>(_a);
        return _seed ^ (Hash<std::tuple_element_t<_i, _typeT>>()(std::get<_i>(_a)) + 0x9e3779b97f4a7c15LU + (_seed << 12) + (_seed >> 4));
      }
    }
  };

  template<class _typeT>
  struct Hash<_typeT, std::enable_if_t<is_iterable_v<_typeT>>> {
  private:
    [[no_unique_address]] Hash<decltype(*std::begin(std::declval<_typeT>()))> _hasher;

  public:
    constexpr std::size_t operator ()(const _typeT& _a) const noexcept {
      std::uint_fast64_t _seed = _a.size();
      for (auto& _i: _a) _seed ^= _hasher(_i) + 0x9e3779b97f4a7c15LU + (_seed << 12) + (_seed >> 4);
      return _seed;
    }
  };
}