#pragma once
#include <cstdint>
#include <limits>
#include <functional>
#include <tuple>
#include <utility>
#include <vector>
#include <string>
#include <set>
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

  template<class _typeT, KYOPRO_BASE_UINT _idx, class... _typeArgs>
  struct _agg_type {
    using type = _agg_type<_typeT, _idx - 1, _typeT, _typeArgs...>::type;
  };
  template<class _typeT, class... _typeArgs>
  struct _agg_type<_typeT, 0, _typeArgs...> {
    using type = std::tuple<_typeArgs...>;
  };
  template<class _typeT>
  struct _agg_type<_typeT, 0, _typeT, _typeT> {
    using type = std::pair<_typeT, _typeT>;
  };

  template<class _typeT, KYOPRO_BASE_UINT _idx>
  using agg = typename _agg_type<_typeT, _idx>::type;

  template<class _typeT>
  using vec = std::vector<_typeT>;
  template<class _typeT>
  using vvec = std::vector<vec<_typeT>>;
  template<class _typeT>
  using vvvec = std::vector<vvec<_typeT>>;
  template<class _typeT>
  using vvvvec = std::vector<vvvec<_typeT>>;
  template<class _typeT>
  using vvvvvec = std::vector<vvvvec<_typeT>>;

  template<class _typeKey, class _typeCompare = std::less<_typeKey>>
  using mset = std::unordered_set<_typeKey, _typeCompare>;
  template<class _typeKey, class _typeT, class _typeCompare = std::less<_typeKey>>
  using mmap = std::unordered_map<_typeKey, _typeT, _typeCompare>;
  template<class _typeKey>
  using hset = std::unordered_set<_typeKey, Hash<_typeKey>>;
  template<class _typeKey, class _typeT>
  using hmap = std::unordered_map<_typeKey, _typeT, Hash<_typeKey>>;
  template<class _typeKey>
  using hmiset = std::unordered_multiset<_typeKey, Hash<_typeKey>>;
  template<class _typeKey, class _typeT>
  using hmmap = std::unordered_multimap<_typeKey, _typeT, Hash<_typeKey>>;
  template<class _typeT, class _typeCompare = std::less<_typeT>, class _typeContainer = std::vector<_typeT>>
  using priq = std::priority_queue<_typeT, _typeContainer, _typeCompare>;
  template<class _typeT, class _typeCompare = std::greater<_typeT>, class _typeContainer = std::vector<_typeT>>
  using heapq = priq<_typeT, _typeCompare, _typeContainer>;
}

using namespace std;
using namespace kyopro;