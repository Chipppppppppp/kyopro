---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../base/hash.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include <cstdint>\n#include <limits>\n#include <functional>\n\
    #include <utility>\n#include <vector>\n#include <string>\n#include <set>\n#include\
    \ <map>\n#include <unordered_set>\n#include <unordered_map>\n#include <queue>\n\
    #include <stack>\n#include \"../base/Hash.hpp\"\n#include \"../math/ModInt.hpp\"\
    \n\nnamespace kyopro {\n  using ll = int64_t;\n  using ull = uint64_t;\n  using\
    \ lf = double;\n  #ifdef __SIZEOF_INT128__\n  using i128 = __int128_t;\n  using\
    \ u128 = __uint128_t;\n  #endif\n  #ifdef __SIZEOF_FLOAT128__\n  using f128 =\
    \ __float128;\n  #endif\n\n  template<class T>\n  using vec = std::vector<T>;\n\
    \  using str = std::string;\n  template<class Key>\n  using hash_set = std::unordered_set<Key,\
    \ Hash<Key>>;\n  template<class Key, class T>\n  using hash_map = std::unordered_map<Key,\
    \ T, Hash<Key>>;\n  template<class Key>\n  using hash_multiset = std::unordered_multiset<Key,\
    \ Hash<Key>>;\n  template<class Key, class T>\n  using hash_multimap = std::unordered_multimap<Key,\
    \ T, Hash<Key>>;\n  template<class T, class Compare = std::less<T>, class Container\
    \ = vec<T>>\n  using priq = std::priority_queue<T, Container, Compare>;\n  template<class\
    \ T, class Compare = std::greater<T>, class Container = vec<T>>\n  using heapq\
    \ = priq<T, Container, Compare>;\n\n  using pll = std::pair<ll, ll>;\n  using\
    \ l3 = std::tuple<ll, ll, ll>;\n  using l4 = std::tuple<ll, ll, ll, ll>;\n  using\
    \ l5 = std::tuple<ll, ll, ll, ll, ll>;\n  using mll = std::map<ll, ll>;\n  using\
    \ hmll = hash_map<ll, ll>;\n  using mmll = std::multimap<ll, ll>;\n  using hmmll\
    \ = std::multimap<ll, ll>;\n  using sl = std::set<ll>;\n  using spll = std::set<pll>;\n\
    \  using hsl = hash_set<ll>;\n  using hspll = hash_set<pll>;\n  using msl = std::multiset<ll>;\n\
    \  using mspll = std::multiset<pll>;\n  using hmsl = hash_multiset<ll>;\n  using\
    \ hmspll = hash_multiset<pll>;\n  using dql = std::deque<ll>;\n  using dqpll =\
    \ std::deque<pll>;\n  using quel = std::queue<ll>;\n  using quepll = std::queue<pll>;\n\
    \  using stkl = std::stack<ll>;\n  using stkpll = std::stack<pll>;\n  using pql\
    \ = priq<ll>;\n  using pqpll = priq<pll>;\n  using hql = heapq<ll>;\n  using hqpll\
    \ = heapq<pll>;\n  using vl = vec<ll>;\n  using vvl = vec<vl>;\n  using vvvl =\
    \ vec<vvl>;\n  using vi = vec<int>;\n  using vvi = vec<vi>;\n  using vvvi = vec<vvi>;\n\
    \  using vf = vec<lf>;\n  using vvf = vec<vf>;\n  using vvvf = vec<vvf>;\n  using\
    \ vb = vec<char>;\n  using vvb = vec<vb>;\n  using vvvb = vec<vvb>;\n  using vc\
    \ = vec<char>;\n  using vvc = vec<vc>;\n  using vvvc = vec<vvc>;\n  using vs =\
    \ vec<str>;\n  using vvs = vec<vs>;\n  using vvvs = vec<vvs>;\n  using vpll =\
    \ vec<pll>;\n  using vvpll = vec<vpll>;\n  using vvvpll = vec<vvpll>;\n  using\
    \ vsl = vec<sl>;\n  using vhsl = vec<hsl>;\n  using vmll = vec<mll>;\n  using\
    \ vhmll = vec<hmll>;\n  using mint = ModInt<mod>;\n  using vm = vec<mint>;\n \
    \ using vvm = vec<vm>;\n  using vvvm = vec<vvm>;\n}\n\nusing namespace std;\n\
    using namespace kyopro;"
  dependsOn: []
  isVerificationFile: false
  path: template/alias.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/alias.hpp
layout: document
redirect_from:
- /library/template/alias.hpp
- /library/template/alias.hpp.html
title: template/alias.hpp
---
