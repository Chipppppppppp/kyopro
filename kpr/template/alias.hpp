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
    using ll = KYOPRO_LL;
    using ull = unsigned long long;
    using lf = KYOPRO_LF;
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

    using mint = KYOPRO_MINT;
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


    #define DEFINE_TEMPLATE_ALIAS(short_name, type, ...) \
        template<__VA_ARGS__> \
        using short_name = type; \
        template<__VA_ARGS__> \
        using V ## short_name = Vec<type>; \
        template<__VA_ARGS__> \
        using VV ## short_name = VVec<type>;

    #define DEFINE_ALIAS(short_name, name, short_value_type, value_type) \
        using short_name ## short_value_type = name<value_type>; \
        using V ## short_name ## short_value_type = V ## name<value_type>; \
        using VV ## short_name ## short_value_type = VV ## name<value_type>; \
        using short_name ## V ## short_value_type = name<Vec<value_type>>; \
        using V ## short_name ## V ## short_value_type = V ## name<Vec<value_type>>;

    #define DEFINE_ALIAS_FOR_VEC(short_name, name, short_value_type, value_type) \
        using V ## short_value_type = Vec<value_type>; \
        using VV ## short_value_type = VVec<value_type>; \
        using VVV ## short_value_type = VVVec<value_type>; \
        using VVVV ## short_value_type = VVVVec<value_type>; \
        using VVVVV ## short_value_type = VVVVVec<value_type>;

    #define DEFINE_MAP_ALIAS_IMPL(short_name, name, short_value_type1, value_type1, short_value_type2, value_type2) \
        using short_name ## short_value_type1 ## short_value_type2 = name<value_type1, value_type2>; \
        using V ## short_name ## short_value_type1 ## short_value_type2 = V ## name<value_type1, value_type2>; \
        using VV ## short_name ## short_value_type1 ## short_value_type2 = VV ## name<value_type1, value_type2>; \
        using short_name ## V ## short_value_type1 ## short_value_type2 = name<Vec<value_type1>, value_type2>; \
        using short_name ## short_value_type1 ## V ## short_value_type2 = name<value_type1, Vec<value_type2>>; \
        using short_name ## V ## short_value_type1 ## V ## short_value_type2 = name<Vec<value_type1>, Vec<value_type2>>; \
        using V ## short_name ## V ## short_value_type1 ## short_value_type2 = V ## name<Vec<value_type1>, value_type2>; \
        using V ## short_name ## short_value_type1 ## V ## short_value_type2 = V ## name<value_type1, Vec<value_type2>>; \
        using V ## short_name ## V ## short_value_type1 ## V ## short_value_type2 = V ## name<Vec<value_type1>, Vec<value_type2>>;

    #define DEFINE_MAP_ALIAS(...) \
        DEFINE_MAP_ALIAS_IMPL(__VA_ARGS__, b, bool); \
        DEFINE_MAP_ALIAS_IMPL(__VA_ARGS__, i, int); \
        DEFINE_MAP_ALIAS_IMPL(__VA_ARGS__, l, ll); \
        DEFINE_MAP_ALIAS_IMPL(__VA_ARGS__, f, float); \
        DEFINE_MAP_ALIAS_IMPL(__VA_ARGS__, lf, lf); \
        DEFINE_MAP_ALIAS_IMPL(__VA_ARGS__, llf, llf); \
        DEFINE_MAP_ALIAS_IMPL(__VA_ARGS__, m, mint); \
        DEFINE_MAP_ALIAS_IMPL(__VA_ARGS__, dm, dmint); \
        DEFINE_MAP_ALIAS_IMPL(__VA_ARGS__, c, char); \
        DEFINE_MAP_ALIAS_IMPL(__VA_ARGS__, s, str); \
        DEFINE_MAP_ALIAS_IMPL(__VA_ARGS__, ll1, ll1); \
        DEFINE_MAP_ALIAS_IMPL(__VA_ARGS__, ll2, ll2); \
        DEFINE_MAP_ALIAS_IMPL(__VA_ARGS__, ll3, ll3); \
        DEFINE_MAP_ALIAS_IMPL(__VA_ARGS__, ll4, ll4); \
        DEFINE_MAP_ALIAS_IMPL(__VA_ARGS__, ll5, ll5);

    #define DEFINE_CONTAINER_ALIAS(define_alias, short_name, name) \
        define_alias(short_name, name, b, bool); \
        define_alias(short_name, name, i, int); \
        define_alias(short_name, name, l, ll); \
        define_alias(short_name, name, f, float); \
        define_alias(short_name, name, lf, lf); \
        define_alias(short_name, name, llf, llf); \
        define_alias(short_name, name, m, mint); \
        define_alias(short_name, name, dm, dmint); \
        define_alias(short_name, name, c, char); \
        define_alias(short_name, name, s, str); \
        define_alias(short_name, name, ll1, ll1); \
        define_alias(short_name, name, ll2, ll2); \
        define_alias(short_name, name, ll3, ll3); \
        define_alias(short_name, name, ll4, ll4); \
        define_alias(short_name, name, ll5, ll5);

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
    DEFINE_CONTAINER_ALIAS(DEFINE_ALIAS_FOR_VEC, V, Vec)

    DEFINE_TEMPLATE_ALIAS(Deque, std::deque<T>, class T)
    DEFINE_CONTAINER_ALIAS(DEFINE_ALIAS, DQ, Deque)

    DEFINE_TEMPLATE_ALIAS(List, std::list<T>, class T)
    DEFINE_CONTAINER_ALIAS(DEFINE_ALIAS, L, List)
    DEFINE_TEMPLATE_ALIAS(ForwardList, std::forward_list<T>, class T)
    DEFINE_CONTAINER_ALIAS(DEFINE_ALIAS, FL, ForwardList)

    DEFINE_TEMPLATE_ALIAS(Set, std::decay_t<decltype(std::declval<std::set<Key, Compare>>())>, class Key, class Compare = Less)
    DEFINE_CONTAINER_ALIAS(DEFINE_ALIAS, S, Set)
    DEFINE_TEMPLATE_ALIAS(Map, std::decay_t<decltype(std::declval<std::map<Key, T, Compare>>())>, class Key, class T, class Compare = Less)
    DEFINE_CONTAINER_ALIAS(DEFINE_MAP_ALIAS, M, Map)

    DEFINE_TEMPLATE_ALIAS(HashSet, std::decay_t<decltype(std::declval<std::unordered_set<Key, H>>())>, class Key, class H = Hash<Key>)
    DEFINE_CONTAINER_ALIAS(DEFINE_ALIAS, HS, HashSet)
    DEFINE_TEMPLATE_ALIAS(HashMap, std::decay_t<decltype(std::declval<std::unordered_map<Key, T, H>>())>, class Key, class T, class H = Hash<Key>)
    DEFINE_CONTAINER_ALIAS(DEFINE_MAP_ALIAS, HM, HashMap)

    DEFINE_TEMPLATE_ALIAS(MultiSet, std::decay_t<decltype(std::declval<std::multiset<Key, Compare>>())>, class Key, class Compare = Less)
    DEFINE_CONTAINER_ALIAS(DEFINE_ALIAS, MS, MultiSet)
    DEFINE_TEMPLATE_ALIAS(MultiMap, std::decay_t<decltype(std::declval<std::multimap<Key, T, Compare>>())>, class Key, class T, class Compare = Less)
    DEFINE_CONTAINER_ALIAS(DEFINE_MAP_ALIAS, MM, MultiMap)

    DEFINE_TEMPLATE_ALIAS(HashMultiSet, std::decay_t<decltype(std::declval<std::unordered_multiset<Key, H>>())>, class Key, class H = Hash<Key>)
    DEFINE_CONTAINER_ALIAS(DEFINE_ALIAS, HMS, HashMultiSet)
    DEFINE_TEMPLATE_ALIAS(HashMultiMap, std::decay_t<decltype(std::declval<std::unordered_multimap<Key, T, H>>())>, class Key, class T, class H = Hash<Key>)
    DEFINE_CONTAINER_ALIAS(DEFINE_MAP_ALIAS, HMM, HashMultiMap)

    DEFINE_TEMPLATE_ALIAS(Queue, std::decay_t<decltype(std::declval<std::queue<T, Container>>())>, class T, class Container = std::deque<T>)
    DEFINE_CONTAINER_ALIAS(DEFINE_ALIAS, Que, Queue)

    DEFINE_TEMPLATE_ALIAS(Stack, std::decay_t<decltype(std::declval<std::stack<T, Container>>())>, class T, class Container = std::deque<T>)
    DEFINE_CONTAINER_ALIAS(DEFINE_ALIAS, Stk, Stack)

    DEFINE_TEMPLATE_ALIAS(PriQ, std::decay_t<decltype(std::declval<std::priority_queue<T, Container, Compare>>())>, class T, class Compare = Less, class Container = Vec<T>)
    DEFINE_CONTAINER_ALIAS(DEFINE_ALIAS, PQ, PriQ)
    DEFINE_TEMPLATE_ALIAS(HeapQ, std::decay_t<decltype(std::declval<std::priority_queue<T, Container, Compare>>())>, class T, class Compare = Greater, class Container = Vec<T>)
    DEFINE_CONTAINER_ALIAS(DEFINE_ALIAS, HQ, HeapQ)

    DEFINE_TEMPLATE_ALIAS(BitSet, std::bitset<size>, std::size_t size)
} // namespace kpr

using namespace std;
using namespace kpr;
