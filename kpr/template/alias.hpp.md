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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  [Previous line repeated 2 more times]\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 412, in update\n    raise BundleErrorAt(path, i + 1, \"unmatched #if /\
    \ #ifdef / #ifndef\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ kpr/meta/setting.hpp: line 41: unmatched #if / #ifdef / #ifndef\n"
  code: "#pragma once\n#include <cstdint>\n#include <forward_list>\n#include <functional>\n\
    #include <limits>\n#include <list>\n#include <map>\n#include <queue>\n#include\
    \ <set>\n#include <stack>\n#include <string>\n#include <tuple>\n#include <unordered_map>\n\
    #include <unordered_set>\n#include <utility>\n#include <vector>\n#include \"../algorithm/Hash.hpp\"\
    \n#include \"../function/compare.hpp\"\n#include \"../math/DynamicModInt.hpp\"\
    \n#include \"../math/ModInt.hpp\"\n#include \"../meta/setting.hpp\"\n\nnamespace\
    \ kpr {\n    using ushort = unsigned short;\n    using ll = long long;\n    using\
    \ ull = unsigned long long;\n    using lf = double;\n    using llf = long double;\n\
    \n    using i8 = std::int8_t;\n    using u8 = std::uint8_t;\n    using i16 = std::int16_t;\n\
    \    using u16 = std::uint16_t;\n    using i32 = std::int32_t;\n    using u32\
    \ = std::uint32_t;\n    using i64 = std::int64_t;\n    using u64 = std::uint64_t;\n\
    \    #ifdef __SIZEOF_INT128__\n    using i128 = __int128_t;\n    using u128 =\
    \ __uint128_t;\n    #endif\n    #ifdef __SIZEOF_FLOAT128__\n    using f128 = __float128;\n\
    \    #endif\n\n    using mint = ModInt<mod>;\n    using dmint = DynamicModInt<KYOPRO_BASE_UINT>;\n\
    \n    using str = std::string;\n\n    template<class T, std::size_t idx, class...\
    \ Args>\n    struct agg_type {\n        using type = typename agg_type<T, idx\
    \ - 1, T, Args...>::type;\n    };\n    template<class T, class... Args>\n    struct\
    \ agg_type<T, 0, Args...> {\n        using type = std::tuple<Args...>;\n    };\n\
    \    template<class T>\n    struct agg_type<T, 0, T, T> {\n        using type\
    \ = std::pair<T, T>;\n    };\n\n    template<class T, std::size_t idx>\n    using\
    \ agg = typename agg_type<T, idx>::type;\n    using ll1 = agg<ll, 1>;\n    using\
    \ ll2 = agg<ll, 2>;\n    using ll3 = agg<ll, 3>;\n    using ll4 = agg<ll, 4>;\n\
    \    using ll5 = agg<ll, 5>;\n\n\n    #define DEFINE_ALIAS(name, short_name, value_name,\
    \ short_value_name) \\\n        using short_name ## short_value_name = name<value_name>;\
    \ \\\n        using short_name ## short_name ## short_value_name = name<name<value_name>>;\
    \ \\\n        using short_name ## short_name ## short_name ## short_value_name\
    \ = name<name<name<value_name>>>; \\\n        using short_name ## short_name ##\
    \ short_name ## short_name ## short_value_name = name<name<name<name<value_name>>>>;\
    \ \\\n        using short_name ## short_name ## short_name ## short_name ## short_name\
    \ ## short_value_name = name<name<name<name<name<value_name>>>>>;\n\n    #define\
    \ DEFINE_VEC_ALIAS(name, short_name, value_name, short_value_name) \\\n      \
    \  using V ## short_name ## short_value_name = Vec<name<value_name>>; \\\n   \
    \     using VV ## short_name ## short_value_name = VVec<name<value_name>>;\n\n\
    \    #define DEFINE_CONTAINER_ALIAS(define_alias, name, short_name) \\\n     \
    \   define_alias(name, short_name, bool, b); \\\n        define_alias(name, short_name,\
    \ int, i); \\\n        define_alias(name, short_name, ll, l); \\\n        define_alias(name,\
    \ short_name, float, f); \\\n        define_alias(name, short_name, lf, lf); \\\
    \n        define_alias(name, short_name, llf, llf); \\\n        define_alias(name,\
    \ short_name, mint, m); \\\n        define_alias(name, short_name, dmint, dm);\
    \ \\\n        define_alias(name, short_name, char, c); \\\n        define_alias(name,\
    \ short_name, str, s); \\\n        define_alias(name, short_name, ll1, ll1); \\\
    \n        define_alias(name, short_name, ll2, ll2); \\\n        define_alias(name,\
    \ short_name, ll3, ll3); \\\n        define_alias(name, short_name, ll4, ll4);\
    \ \\\n        define_alias(name, short_name, ll5, ll5);\n\n\n    template<class\
    \ T>\n    using Vec = std::vector<T>;\n    template<class T>\n    using VVec =\
    \ Vec<Vec<T>>;\n    template<class T>\n    using VVVec = Vec<VVec<T>>;\n    template<class\
    \ T>\n    using VVVVec = Vec<VVVec<T>>;\n    template<class T>\n    using VVVVVec\
    \ = Vec<VVVVec<T>>;\n\n    DEFINE_CONTAINER_ALIAS(DEFINE_ALIAS, Vec, V);\n\n \
    \   template<class T>\n    using Deque = std::deque<T>;\n\n    DEFINE_CONTAINER_ALIAS(DEFINE_ALIAS,\
    \ Deque, D);\n    DEFINE_CONTAINER_ALIAS(DEFINE_VEC_ALIAS, Deque, D);\n\n    template<class\
    \ T>\n    using List = std::list<T>;\n\n    DEFINE_CONTAINER_ALIAS(DEFINE_ALIAS,\
    \ List, L);\n    DEFINE_CONTAINER_ALIAS(DEFINE_VEC_ALIAS, List, L);\n\n    template<class\
    \ T>\n    using ForwardList = std::forward_list<T>;\n\n    DEFINE_CONTAINER_ALIAS(DEFINE_ALIAS,\
    \ ForwardList, FL);\n    DEFINE_CONTAINER_ALIAS(DEFINE_VEC_ALIAS, ForwardList,\
    \ FL);\n\n    template<class Key, class Compare = Less>\n    using Set = std::set<Key,\
    \ Compare>;\n    template<class Key, class Compare = Less>\n    using Map = std::map<Key,\
    \ Compare>;\n\n    DEFINE_CONTAINER_ALIAS(DEFINE_ALIAS, Set, S);\n    DEFINE_CONTAINER_ALIAS(DEFINE_VEC_ALIAS,\
    \ Set, S);\n    using Mll = Map<ll, ll>;\n    using VMll = Vec<Mll>;\n\n    template<class\
    \ Key, class H = Hash<Key>>\n    using HashSet = std::unordered_set<Key, H>;\n\
    \    template<class Key, class T, class H = Hash<Key>>\n    using HashMap = std::unordered_map<Key,\
    \ T, H>;\n\n    DEFINE_CONTAINER_ALIAS(DEFINE_ALIAS, HashSet, HS);\n    DEFINE_CONTAINER_ALIAS(DEFINE_VEC_ALIAS,\
    \ HashSet, HS);\n    using HMll = HashMap<ll, ll>;\n    using VHMll = Vec<HMll>;\n\
    \n    template<class Key, class Compare = Less>\n    using MultiSet = std::multiset<Key,\
    \ Compare>;\n    template<class Key, class T, class Compare = Less>\n    using\
    \ MultiMap = std::multimap<Key, T, Compare>;\n\n    DEFINE_CONTAINER_ALIAS(DEFINE_ALIAS,\
    \ MultiSet, MS);\n    DEFINE_CONTAINER_ALIAS(DEFINE_VEC_ALIAS, MultiSet, MS);\n\
    \    using MMll = MultiMap<ll, ll>;\n    using VMMll = Vec<MMll>;\n\n    template<class\
    \ Key, class H = Hash<Key>>\n    using HashMultiSet = std::unordered_multiset<Key,\
    \ H>;\n    template<class Key, class T, class H = Hash<Key>>\n    using HashMultiMap\
    \ = std::unordered_multimap<Key, T, H>;\n\n    DEFINE_CONTAINER_ALIAS(DEFINE_ALIAS,\
    \ HashMultiSet, HMS);\n    DEFINE_CONTAINER_ALIAS(DEFINE_VEC_ALIAS, HashMultiSet,\
    \ HMS);\n    using HMMli = HashMultiMap<ll, ll>;\n    using VHMMli = Vec<HMMli>;\n\
    \n    template<class T, class Container = std::deque<T>>\n    using Queue = std::queue<T,\
    \ Container>;\n\n    DEFINE_CONTAINER_ALIAS(DEFINE_ALIAS, Queue, Que);\n    DEFINE_CONTAINER_ALIAS(DEFINE_VEC_ALIAS,\
    \ Queue, Que);\n\n    template<class T, class Container = std::deque<T>>\n   \
    \ using Stack = std::stack<T, Container>;\n\n    DEFINE_CONTAINER_ALIAS(DEFINE_ALIAS,\
    \ Stack, Stk);\n    DEFINE_CONTAINER_ALIAS(DEFINE_VEC_ALIAS, Stack, Stk);\n\n\
    \    template<class T, class Compare = Less, class Container = Vec<T>>\n    using\
    \ PriQ = std::priority_queue<T, Container, Compare>;\n    template<class T, class\
    \ Compare = Greater, class Container = Vec<T>>\n    using HeapQ = PriQ<T, Compare,\
    \ Container>;\n\n    DEFINE_CONTAINER_ALIAS(DEFINE_ALIAS, PriQ, PQ);\n    DEFINE_CONTAINER_ALIAS(DEFINE_VEC_ALIAS,\
    \ PriQ, PQ);\n    DEFINE_CONTAINER_ALIAS(DEFINE_ALIAS, HeapQ, HQ);\n    DEFINE_CONTAINER_ALIAS(DEFINE_VEC_ALIAS,\
    \ HeapQ, HQ);\n\n    template<std::size_t size>\n    using BitSet = std::bitset<size>;\n\
    } // namespace kpr\n\nusing namespace std;\nusing namespace kpr;\n"
  dependsOn: []
  isVerificationFile: false
  path: kpr/template/alias.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kpr/template/alias.hpp
layout: document
redirect_from:
- /library/kpr/template/alias.hpp
- /library/kpr/template/alias.hpp.html
title: kpr/template/alias.hpp
---
