#pragma once
#include <cstdint>
#include <forward_list>
#include <functional>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include "../algorithm/Hash.hpp"
#include "../function/compare.hpp"
#include "../math/DynamicModInt.hpp"
#include "../math/ModInt.hpp"
#include "../meta/setting.hpp"

namespace kpr {
    using ushort = unsigned short;
    using ll = long long;
    using ull = unsigned long long;
    using lf = double;
    using llf = long double;

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

    using mint = KYOPRO_BASE_MINT;
    using dmint = DynamicModInt<KYOPRO_BASE_UINT>;

    using str = std::string;

    template<class T, std::size_t idx, class... Args>
    struct agg_type {
        using type = typename agg_type<T, idx - 1, T, Args...>::type;
    };
    template<class T, class... Args>
    struct agg_type<T, 0, Args...> {
        using type = std::tuple<Args...>;
    };
    template<class T>
    struct agg_type<T, 0, T, T> {
        using type = std::pair<T, T>;
    };

    template<class T, std::size_t idx>
    using agg = typename agg_type<T, idx>::type;
    using ll1 = agg<ll, 1>;
    using ll2 = agg<ll, 2>;
    using ll3 = agg<ll, 3>;
    using ll4 = agg<ll, 4>;
    using ll5 = agg<ll, 5>;


    #define DEFINE_ALIAS(name, short_name, value_name, short_value_name) \
        using short_name ## short_value_name = name<value_name>; \
        using short_name ## short_name ## short_value_name = name<name<value_name>>; \
        using short_name ## short_name ## short_name ## short_value_name = name<name<name<value_name>>>; \
        using short_name ## short_name ## short_name ## short_name ## short_value_name = name<name<name<name<value_name>>>>; \
        using short_name ## short_name ## short_name ## short_name ## short_name ## short_value_name = name<name<name<name<name<value_name>>>>>;

    #define DEFINE_VEC_ALIAS(name, short_name, value_name, short_value_name) \
        using V ## short_name ## short_value_name = Vec<name<value_name>>; \
        using VV ## short_name ## short_value_name = VVec<name<value_name>>;

    #define DEFINE_CONTAINER_ALIAS(define_alias, name, short_name) \
        define_alias(name, short_name, bool, b); \
        define_alias(name, short_name, int, i); \
        define_alias(name, short_name, ll, l); \
        define_alias(name, short_name, float, f); \
        define_alias(name, short_name, lf, lf); \
        define_alias(name, short_name, llf, llf); \
        define_alias(name, short_name, mint, m); \
        define_alias(name, short_name, dmint, dm); \
        define_alias(name, short_name, char, c); \
        define_alias(name, short_name, str, s); \
        define_alias(name, short_name, ll1, ll1); \
        define_alias(name, short_name, ll2, ll2); \
        define_alias(name, short_name, ll3, ll3); \
        define_alias(name, short_name, ll4, ll4); \
        define_alias(name, short_name, ll5, ll5);


    template<class T>
    using Vec = std::vector<T>;
    template<class T>
    using VVec = Vec<Vec<T>>;
    template<class T>
    using VVVec = Vec<VVec<T>>;
    template<class T>
    using VVVVec = Vec<VVVec<T>>;
    template<class T>
    using VVVVVec = Vec<VVVVec<T>>;

    DEFINE_CONTAINER_ALIAS(DEFINE_ALIAS, Vec, V);

    template<class T>
    using Deque = std::deque<T>;

    DEFINE_CONTAINER_ALIAS(DEFINE_ALIAS, Deque, D);
    DEFINE_CONTAINER_ALIAS(DEFINE_VEC_ALIAS, Deque, D);

    template<class T>
    using List = std::list<T>;

    DEFINE_CONTAINER_ALIAS(DEFINE_ALIAS, List, L);
    DEFINE_CONTAINER_ALIAS(DEFINE_VEC_ALIAS, List, L);

    template<class T>
    using ForwardList = std::forward_list<T>;

    DEFINE_CONTAINER_ALIAS(DEFINE_ALIAS, ForwardList, FL);
    DEFINE_CONTAINER_ALIAS(DEFINE_VEC_ALIAS, ForwardList, FL);

    template<class Key, class Compare = Less>
    using Set = std::set<Key, Compare>;
    template<class Key, class Compare = Less>
    using Map = std::map<Key, Compare>;

    DEFINE_CONTAINER_ALIAS(DEFINE_ALIAS, Set, S);
    DEFINE_CONTAINER_ALIAS(DEFINE_VEC_ALIAS, Set, S);
    using Mll = Map<ll, ll>;
    using VMll = Vec<Mll>;

    template<class Key, class H = Hash<Key>>
    using HashSet = std::unordered_set<Key, H>;
    template<class Key, class T, class H = Hash<Key>>
    using HashMap = std::unordered_map<Key, T, H>;

    DEFINE_CONTAINER_ALIAS(DEFINE_ALIAS, HashSet, HS);
    DEFINE_CONTAINER_ALIAS(DEFINE_VEC_ALIAS, HashSet, HS);
    using HMll = HashMap<ll, ll>;
    using VHMll = Vec<HMll>;

    template<class Key, class Compare = Less>
    using MultiSet = std::multiset<Key, Compare>;
    template<class Key, class T, class Compare = Less>
    using MultiMap = std::multimap<Key, T, Compare>;

    DEFINE_CONTAINER_ALIAS(DEFINE_ALIAS, MultiSet, MS);
    DEFINE_CONTAINER_ALIAS(DEFINE_VEC_ALIAS, MultiSet, MS);
    using MMll = MultiMap<ll, ll>;
    using VMMll = Vec<MMll>;

    template<class Key, class H = Hash<Key>>
    using HashMultiSet = std::unordered_multiset<Key, H>;
    template<class Key, class T, class H = Hash<Key>>
    using HashMultiMap = std::unordered_multimap<Key, T, H>;

    DEFINE_CONTAINER_ALIAS(DEFINE_ALIAS, HashMultiSet, HMS);
    DEFINE_CONTAINER_ALIAS(DEFINE_VEC_ALIAS, HashMultiSet, HMS);
    using HMMli = HashMultiMap<ll, ll>;
    using VHMMli = Vec<HMMli>;

    template<class T, class Container = std::deque<T>>
    using Queue = std::queue<T, Container>;

    DEFINE_CONTAINER_ALIAS(DEFINE_ALIAS, Queue, Que);
    DEFINE_CONTAINER_ALIAS(DEFINE_VEC_ALIAS, Queue, Que);

    template<class T, class Container = std::deque<T>>
    using Stack = std::stack<T, Container>;

    DEFINE_CONTAINER_ALIAS(DEFINE_ALIAS, Stack, Stk);
    DEFINE_CONTAINER_ALIAS(DEFINE_VEC_ALIAS, Stack, Stk);

    template<class T, class Compare = Less, class Container = Vec<T>>
    using PriQ = std::priority_queue<T, Container, Compare>;
    template<class T, class Compare = Greater, class Container = Vec<T>>
    using HeapQ = PriQ<T, Compare, Container>;

    DEFINE_CONTAINER_ALIAS(DEFINE_ALIAS, PriQ, PQ);
    DEFINE_CONTAINER_ALIAS(DEFINE_VEC_ALIAS, PriQ, PQ);
    DEFINE_CONTAINER_ALIAS(DEFINE_ALIAS, HeapQ, HQ);
    DEFINE_CONTAINER_ALIAS(DEFINE_VEC_ALIAS, HeapQ, HQ);

    template<std::size_t size>
    using BitSet = std::bitset<size>;
} // namespace kpr

using namespace std;
using namespace kpr;
