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
  using ll = int64_t;
  using ull = uint64_t;
  using lf = double;
  #ifdef __SIZEOF_INT128__
  using i128 = __int128_t;
  using u128 = __uint128_t;
  #endif
  #ifdef __SIZEOF_FLOAT128__
  using f128 = __float128;
  #endif

  template<class T>
  using vec = std::vector<T>;
  using str = std::string;
  template<class Key>
  using hash_set = std::unordered_set<Key, Hash<Key>>;
  template<class Key, class T>
  using hash_map = std::unordered_map<Key, T, Hash<Key>>;
  template<class Key>
  using hash_multiset = std::unordered_multiset<Key, Hash<Key>>;
  template<class Key, class T>
  using hash_multimap = std::unordered_multimap<Key, T, Hash<Key>>;
  template<class T, class Compare = std::less<T>, class Container = vec<T>>
  using priq = std::priority_queue<T, Container, Compare>;
  template<class T, class Compare = std::greater<T>, class Container = vec<T>>
  using heapq = priq<T, Container, Compare>;

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