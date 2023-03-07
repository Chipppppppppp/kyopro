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
    using li = long long;
    using uli = unsigned long long;
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

    using mint = ModInt<mod>;
    using dmint = DynamicModInt<KYOPRO_BASE_UINT>;

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
    using li1 = agg<li, 1>;
    using li2 = agg<li, 2>;
    using li3 = agg<li, 3>;
    using li4 = agg<li, 4>;
    using li5 = agg<li, 5>;


    #define DEFINE_ALIAS(name, short_name, value) \
        using short_name ## value = name<value>; \
        using short_name ## short_name ## value = name<value>; \
        using short_name ## short_name ## short_name ## value = name<value>; \
        using short_name ## short_name ## short_name ## short_name ## value = name<value>; \
        using V ## short_name ## short_name ## short_name ## short_name ## value = Vec<name<value>>; \
        using VV ## short_name ## short_name ## short_name ## short_name ## value = VVec<name<value>>;

    #define DEFINE_CONTAINER_ALIAS(name, short_name) \
        DEFINE_ALIAS(name, short_name, int); \
        DEFINE_ALIAS(name, short_name, li); \
        DEFINE_ALIAS(name, short_name, float); \
        DEFINE_ALIAS(name, short_name, lf); \
        DEFINE_ALIAS(name, short_name, llf); \
        DEFINE_ALIAS(name, short_name, mint); \
        DEFINE_ALIAS(name, short_name, dmint); \
        DEFINE_ALIAS(name, short_name, li1); \
        DEFINE_ALIAS(name, short_name, li2); \
        DEFINE_ALIAS(name, short_name, li3); \
        DEFINE_ALIAS(name, short_name, li4); \
        DEFINE_ALIAS(name, short_name, li5);


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

    DEFINE_CONTAINER_ALIAS(Vec, V);

    template<class T>
    using Deque = std::deque<T>;

    DEFINE_CONTAINER_ALIAS(Deque, D);

    template<class T>
    using List = std::list<T>;

    DEFINE_CONTAINER_ALIAS(List, L);

    template<class T>
    using ForwardList = std::forward_list<T>;

    DEFINE_CONTAINER_ALIAS(ForwardList, FL);

    template<class Key, class Compare = Less>
    using Set = std::set<Key, Compare>;
    template<class Key, class Compare = Less>
    using Map = std::map<Key, Compare>;

    DEFINE_CONTAINER_ALIAS(Set, S);
    using Mlili = Map<li, li>;
    using VMlili = Vec<Mlili>;

    template<class Key, class Compare = Less>
    using HashSet = std::unordered_set<Key, Compare>;
    template<class Key, class T, class Compare = Less>
    using HashMap = std::unordered_map<Key, T, Compare>;

    DEFINE_CONTAINER_ALIAS(HashSet, HS);
    using HMlili = HashMap<li, li>;
    using VHMlili = Vec<HMlili>;

    template<class Key>
    using MultiSet = std::multiset<Key, Hash<Key>>;
    template<class Key, class T>
    using MultiMap = std::multimap<Key, T, Hash<Key>>;

    DEFINE_CONTAINER_ALIAS(MultiSet, MS);
    using MMlili = MultiMap<li, li>;
    using VMMlili = Vec<MMlili>;

    template<class Key>
    using HashMultiSet = std::unordered_multiset<Key, Hash<Key>>;
    template<class Key, class T>
    using HashMultiMap = std::unordered_multimap<Key, T, Hash<Key>>;

    DEFINE_CONTAINER_ALIAS(HashMultiSet, HMS);
    using VHMSli = Vec<HMSli>;
    using HMMli = HashMultiMap<li, li>;
    using VHMMli = Vec<HMMli>;

    template<class T, class Container = std::deque<T>>
    using Queue = std::queue<T, Container>;

    DEFINE_CONTAINER_ALIAS(Queue, Que);

    template<class T, class Container = std::deque<T>>
    using Stack = std::stack<T, Container>;

    DEFINE_CONTAINER_ALIAS(Stack, Stk);

    template<class T, class Compare = Less, class Container = Vec<T>>
    using PriQ = std::priority_queue<T, Container, Compare>;
    template<class T, class Compare = Greater, class Container = Vec<T>>
    using HeapQ = PriQ<T, Compare, Container>;

    DEFINE_CONTAINER_ALIAS(PriQ, PQ);
    DEFINE_CONTAINER_ALIAS(HeapQ, HQ);

    template<std::size_t size>
    using BitSet = std::bitset<size>;
} // namespace kpr

using namespace std;
using namespace kpr;
