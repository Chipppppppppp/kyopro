#pragma once
#include <type_traits>
#include <tuple>
#include "settings.hpp"
#include "trait.hpp"

namespace kyopro {
  template<class, class = void>
  struct Hash;

  template<class KyoproT>
  struct Hash<KyoproT, std::enable_if_t<std::is_integral_v<KyoproT>>> { constexpr KYOPRO_BASE_UINT operator ()(KyoproT kyopro_a) const noexcept { return kyopro_a; } };

  template<class KyoproT>
  struct Hash<KyoproT, std::enable_if_t<std::is_floating_point_v<KyoproT>>> { constexpr KYOPRO_BASE_UINT operator ()(KyoproT kyopro_a) const noexcept { return (KYOPRO_BASE_UINT)kyopro_a & 0xfffff000; } };

  template<class KyoproT>
  struct Hash<KyoproT, std::enable_if_t<is_tuple_v<KyoproT>>> {
    template<KYOPRO_BASE_UINT kyopro_i = 0>
    constexpr KYOPRO_BASE_UINT operator ()(const KyoproT& kyopro_a) const noexcept {
      if constexpr (kyopro_i == std::tuple_size_v<KyoproT>) return std::tuple_size_v<KyoproT>;
      else {
        KYOPRO_BASE_UINT kyopro_seed = operator()<kyopro_i + 1>(kyopro_a);
        return kyopro_seed ^ (Hash<std::tuple_element_t<kyopro_i, KyoproT>>()(get<kyopro_i>(kyopro_a)) + 0x9e3779b97f4a7c15LU + (kyopro_seed << 12) + (kyopro_seed >> 4));
      }
    }
  };

  template<class KyoproT>
  struct Hash<KyoproT, std::enable_if_t<is_container_v<KyoproT>>> {
  private:
    [[no_unique_address]] Hash<typename KyoproT::value_type> make_hash;
  public:
    constexpr KYOPRO_BASE_UINT operator ()(const KyoproT& kyopro_a) const noexcept {
      KYOPRO_BASE_UINT kyopro_seed = kyopro_a.size();
      for (auto& kyopro_i: kyopro_a) kyopro_seed ^= make_hash(kyopro_i) + 0x9e3779b97f4a7c15LU + (kyopro_seed << 12) + (kyopro_seed >> 4);
      return kyopro_seed;
    }
  };
}