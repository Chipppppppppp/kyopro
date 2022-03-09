#pragma once
#include <cstdint>
#include <limits>
#include <functional>
#include <utility>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include "../base/Hash.hpp"
#include "../math/ModInt.hpp"

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
  #ifdef __SIZEOF_INT128__
  using i128 = __int128_t;
  using u128 = __uint128_t;
  #endif
  #ifdef __SIZEOF_FLOAT128__
  using f128 = __float128;
  #endif

  template<class _typeT>
  using vec = std::vector<_typeT>;
  using str = std::string;
  template<class Key>
  using hash_set = std::unordered_set<Key, Hash<Key>>;
  template<class Key, class _typeT>
  using hash_map = std::unordered_map<Key, _typeT, Hash<Key>>;
  template<class Key>
  using hash_multiset = std::unordered_multiset<Key, Hash<Key>>;
  template<class Key, class _typeT>
  using hash_multimap = std::unordered_multimap<Key, _typeT, Hash<Key>>;
  template<class _typeT, class Compare = std::less<_typeT>, class Container = vec<_typeT>>
  using priq = std::priority_queue<_typeT, Container, Compare>;
  template<class _typeT, class Compare = std::greater<_typeT>, class Container = vec<_typeT>>
  using heapq = priq<_typeT, Container, Compare>;

  using pll = std::pair<ll, ll>;
  using l3 = std::tuple<ll, ll, ll>;
  using l4 = std::tuple<ll, ll, ll, ll>;
  using l5 = std::tuple<ll, ll, ll, ll, ll>;
  using mll = std::map<ll, ll>;
  using hmll = hash_map<ll, ll>;
  using mmll = std::multimap<ll, ll>;
  using hmmll = std::multimap<ll, ll>;
  using sl = std::set<ll>;
  using spll = std::set<pll>;
  using hsl = hash_set<ll>;
  using hspll = hash_set<pll>;
  using msl = std::multiset<ll>;
  using mspll = std::multiset<pll>;
  using hmsl = hash_multiset<ll>;
  using hmspll = hash_multiset<pll>;
  using dql = std::deque<ll>;
  using dqpll = std::deque<pll>;
  using quel = std::queue<ll>;
  using quepll = std::queue<pll>;
  using stkl = std::stack<ll>;
  using stkpll = std::stack<pll>;
  using pql = priq<ll>;
  using pqpll = priq<pll>;
  using hql = heapq<ll>;
  using hqpll = heapq<pll>;
  using vl = vec<ll>;
  using vvl = vec<vl>;
  using vvvl = vec<vvl>;
  using vi = vec<int>;
  using vvi = vec<vi>;
  using vvvi = vec<vvi>;
  using vf = vec<lf>;
  using vvf = vec<vf>;
  using vvvf = vec<vvf>;
  using vb = vec<char>;
  using vvb = vec<vb>;
  using vvvb = vec<vvb>;
  using vc = vec<char>;
  using vvc = vec<vc>;
  using vvvc = vec<vvc>;
  using vs = vec<str>;
  using vvs = vec<vs>;
  using vvvs = vec<vvs>;
  using vpll = vec<pll>;
  using vvpll = vec<vpll>;
  using vvvpll = vec<vvpll>;
  using vsl = vec<sl>;
  using vhsl = vec<hsl>;
  using vmll = vec<mll>;
  using vhmll = vec<hmll>;
  using mint = ModInt<mod>;
  using vm = vec<mint>;
  using vvm = vec<vm>;
  using vvvm = vec<vvm>;
}

using namespace std;
using namespace kyopro;