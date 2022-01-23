#pragma once
#include <cstddef>
#include <tuple>
#include <type_traits>
#include "settings.hpp"
#include "trait.hpp"

namespace kyopro {
  template<class, class = void>
  struct Hash;

  template<class _typeT>
  struct Hash<_typeT, std::enable_if_t<std::is_integral_v<_typeT>>> { constexpr KYOPRO_BASE_UINT operator ()(_typeT _a) const noexcept { return _a; } };

  template<class _typeT>
  struct Hash<_typeT, std::enable_if_t<std::is_floating_point_v<_typeT>>> { constexpr KYOPRO_BASE_UINT operator ()(_typeT _a) const noexcept { return static_cast<KYOPRO_BASE_UINT>(_a) & 0xfffff000; } };

  template<class _typeT>
  struct Hash<_typeT*, void> { constexpr KYOPRO_BASE_UINT operator ()(_typeT* _a) const noexcept { return reinterpret_cast<KYOPRO_BASE_UINT>(_a); } };

  template<>
  struct Hash<std::nullptr_t, void> { constexpr KYOPRO_BASE_UINT operator ()(std::nullptr_t) const noexcept { return 0; } };

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
    [[no_unique_address]] Hash<typename _typeT::value_type> make_hash;
  public:
    constexpr KYOPRO_BASE_UINT operator ()(const _typeT& _a) const noexcept {
      KYOPRO_BASE_UINT _seed = _a.size();
      for (auto& _i: _a) _seed ^= make_hash(_i) + 0x9e3779b97f4a7c15LU + (_seed << 12) + (_seed >> 4);
      return _seed;
    }
  };
}