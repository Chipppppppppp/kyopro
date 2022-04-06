#pragma once
#include <cstdint>
#include <limits>
#include <functional>
#include <utility>
#include <vector>
#include <string>
#include <set>
#include <type_traits>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include "../algorithm/Hash.hpp"
#include "../math/DynamicModInt.hpp"
#include "../math/ModInt.hpp"
#include "../meta/settings.hpp"

namespace kyopro {
  using ll = long long;
  using ull = unsigned long long;
  using lf = double;

  using i8 = std::int8_t;
  using u8 = std::uint8_t;
  using i16 = std::int16_t;
  using u16 = std::uint16_t;
  using i32 = std::int32_t;
  using u32 = std::uint32_t;
  using i64 = std::int64_t;
  using u64 = std::uint64_t;
  using i128 = __int128_t;
  using u128 = __uint128_t;
  #ifdef __SIZEOF_FLOAT128__
  using f128 = __float128;
  #endif

  using mint = ModInt<mod>;
  using dmint = DynamicModInt<KYOPRO_BASE_UINT>;

  template<class _typeKey>
  using hset = std::unordered_set<_typeKey, Hash<_typeKey>>;
  template<class _typeKey, class _typeT>
  using hmap = std::unordered_map<_typeKey, _typeT, Hash<_typeKey>>;
  template<class _typeKey>
  using hmultiset = std::unordered_multiset<_typeKey, Hash<_typeKey>>;
  template<class _typeKey, class _typeT>
  using hmultimap = std::unordered_multimap<_typeKey, _typeT, Hash<_typeKey>>;
  template<class _typeT, class _typeCompare = std::less<_typeT>, class _typeContainer = std::vector<_typeT>>
  using priq = std::priority_queue<_typeT, _typeContainer, _typeCompare>;
  template<class _typeT, class _typeCompare = std::greater<_typeT>, class _typeContainer = std::vector<_typeT>>
  using heapq = priq<_typeT, _typeCompare, _typeContainer>;
}

using namespace std;
using namespace kyopro;

template<class _typeT, class _typeU, std::enable_if_t<!std::is_same_v<_typeT, _typeU>>* = nullptr>
constexpr std::common_type_t<_typeT, _typeU> min(const _typeT& a, const _typeU& b) noexcept {
  return a < b ? a : b;
}

template<class _typeT, class _typeU, std::enable_if_t<!std::is_same_v<_typeT, _typeU>>* = nullptr>
constexpr std::common_type_t<_typeT, _typeU> max(const _typeT& a, const _typeU& b) noexcept {
  return a > b ? a : b;
}