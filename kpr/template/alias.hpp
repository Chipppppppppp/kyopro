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

namespace kpr
{
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

    template <class T, std::size_t idx, class... Args>
    struct agg_type
    {
        using type = typename agg_type<T, idx - 1, T, Args...>::type;
    };
    template <class T, class... Args>
    struct agg_type<T, 0, Args...>
    {
        using type = std::tuple<Args...>;
    };
    template <class T>
    struct agg_type<T, 0, T, T>
    {
        using type = std::pair<T, T>;
    };

    template <class T, std::size_t idx>
    using agg = typename agg_type<T, idx>::type;
    using ll2 = agg<ll, 2>;
    using ll3 = agg<ll, 3>;
    using ll4 = agg<ll, 4>;
    using ll5 = agg<ll, 5>;

#define DEFINE_CONTAINER_ALIAS(short_name, name) \
    using short_name##b = name<bool>;            \
    using short_name##i = name<int>;             \
    using short_name##l = name<ll>;              \
    using short_name##f = name<float>;           \
    using short_name##lf = name<lf>;             \
    using short_name##llf = name<llf>;           \
    using short_name##m = name<mint>;            \
    using short_name##dm = name<dmint>;          \
    using short_name##c = name<char>;            \
    using short_name##s = name<str>;             \
    using short_name##ll2 = name<ll2>;           \
    using short_name##ll3 = name<ll3>;           \
    using short_name##ll4 = name<ll4>;           \
    using short_name##ll5 = name<ll5>;

#define DEFINE_MAP_ALIAS(short_name, name)    \
    using short_name##lb = name<ll, bool>;    \
    using short_name##li = name<ll, int>;     \
    using short_name##ll = name<ll, ll>;      \
    using short_name##lf = name<ll, float>;   \
    using short_name##llf = name<ll, lf>;     \
    using short_name##lllf = name<ll, llf>;   \
    using short_name##lm = name<ll, mint>;    \
    using short_name##ldm = name<ll, dmint>;  \
    using short_name##lc = name<ll, char>;    \
    using short_name##ls = name<ll, str>;     \
    using short_name##lll2 = name<ll, ll2>;   \
    using short_name##lll3 = name<ll, ll3>;   \
    using short_name##lll4 = name<ll, ll4>;   \
    using short_name##lll5 = name<ll, ll5>;   \
    using short_name##sb = name<str, bool>;   \
    using short_name##si = name<str, int>;    \
    using short_name##sl = name<str, ll>;     \
    using short_name##sf = name<str, float>;  \
    using short_name##slf = name<str, lf>;    \
    using short_name##sllf = name<str, llf>;  \
    using short_name##sm = name<str, mint>;   \
    using short_name##sdm = name<str, dmint>; \
    using short_name##sc = name<str, char>;   \
    using short_name##ss = name<str, str>;    \
    using short_name##sll2 = name<str, ll2>;  \
    using short_name##sll3 = name<str, ll3>;  \
    using short_name##sll4 = name<str, ll4>;  \
    using short_name##sll5 = name<str, ll5>;

    template <class T>
    using Vec = std::vector<T>;
    template <class T>
    using VVec = Vec<Vec<T>>;
    template <class T>
    using VVVec = Vec<VVec<T>>;
    template <class T>
    using VVVVec = Vec<VVVec<T>>;
    template <class T>
    using VVVVVec = Vec<VVVVec<T>>;
    DEFINE_CONTAINER_ALIAS(V, Vec)
    DEFINE_CONTAINER_ALIAS(VV, VVec)
    DEFINE_CONTAINER_ALIAS(VVV, VVVec)
    DEFINE_CONTAINER_ALIAS(VVVV, VVVVec)
    DEFINE_CONTAINER_ALIAS(VVVVV, VVVVVec)

    template <class T>
    using Deque = std::deque<T>;
    DEFINE_CONTAINER_ALIAS(DQ, Deque)

    template <class T>
    using List = std::list<T>;
    DEFINE_CONTAINER_ALIAS(L, List)
    template <class T>
    using ForwardList = std::forward_list<T>;
    DEFINE_CONTAINER_ALIAS(FL, ForwardList)

    template <class Key, class Compare = Less>
    using Set = std::set<Key, Compare>;
    DEFINE_CONTAINER_ALIAS(S, Set)
    template <class Key, class T, class Compare = Less>
    using Map = std::map<Key, T, Compare>;
    DEFINE_MAP_ALIAS(M, Map)

    template <class Key, class H = Hash<Key>>
    using HashSet = std::unordered_set<Key, H>;
    DEFINE_CONTAINER_ALIAS(HS, HashSet)
    template <class Key, class T, class H = Hash<Key>>
    using HashMap = std::unordered_map<Key, T, H>;
    DEFINE_MAP_ALIAS(HM, HashMap)

    template <class Key, class Compare = Less>
    using MultiSet = std::multiset<Key, Compare>;
    DEFINE_CONTAINER_ALIAS(MS, MultiSet)
    template <class Key, class T, class Compare = Less>
    using MultiMap = std::multimap<Key, T, Compare>;
    DEFINE_MAP_ALIAS(MM, MultiMap)

    template <class Key, class H = Hash<Key>>
    using HashMultiSet = std::unordered_multiset<Key, H>;
    DEFINE_CONTAINER_ALIAS(HMS, HashMultiSet)
    template <class Key, class T, class H = Hash<Key>>
    using HashMultiMap = std::unordered_multimap<Key, T, H>;
    DEFINE_MAP_ALIAS(HMM, HashMultiMap)

    template <class T, class Container = std::deque<T>>
    using Queue = std::queue<T, Container>;
    DEFINE_CONTAINER_ALIAS(Que, Queue)

    template <class T, class Container = std::deque<T>>
    using Stack = std::stack<T, Container>;
    DEFINE_CONTAINER_ALIAS(Stk, Stack)

    template <class T, class Compare = Less, class Container = Vec<T>>
    using PriQue = std::priority_queue<T, Container, Compare>;
    DEFINE_CONTAINER_ALIAS(PQ, PriQue)
    template <class T, class Compare = Greater, class Container = Vec<T>>
    using HeapQue = std::priority_queue<T, Container, Compare>;
    DEFINE_CONTAINER_ALIAS(HQ, HeapQue)

    template <std::size_t size>
    using BitSet = std::bitset<size>;

#undef DEFINE_TEMPLATE_ALIAS
#undef DEFINE_ALIAS
#undef DEFINE_ALIAS_FOR_VEC
#undef DEFINE_MAP_ALIAS_IMPL
#undef DEFINE_MAP_ALIAS
#undef DEFINE_CONTAINER_ALIAS
} // namespace kpr

using namespace std;
using namespace kpr;
