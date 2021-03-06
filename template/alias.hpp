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
    using f128 = __float128;

    using mint = ModInt<mod>;
    using dmint = DynamicModInt<KYOPRO_BASE_UINT>;

    template<class T, KYOPRO_BASE_UINT idx, class... Args>
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

    template<class T, KYOPRO_BASE_UINT idx>
    using agg = typename agg_type<T, idx>::type;
    using ll1 = agg<ll, 1>;
    using ll2 = agg<ll, 2>;
    using ll3 = agg<ll, 3>;
    using ll4 = agg<ll, 4>;
    using ll5 = agg<ll, 5>;

    template<class T>
    using vec = std::vector<T>;
    template<class T>
    using vec1 = vec<T>;
    template<class T>
    using vec2 = std::vector<vec1<T>>;
    template<class T>
    using vec3 = std::vector<vec2<T>>;
    template<class T>
    using vec4 = std::vector<vec3<T>>;
    template<class T>
    using vec5 = std::vector<vec4<T>>;

    template<class Key, class Compare = std::less<Key>>
    using mset = std::unordered_set<Key, Compare>;
    template<class Key, class T, class Compare = std::less<Key>>
    using mmap = std::unordered_map<Key, T, Compare>;
    template<class Key>
    using hset = std::unordered_set<Key, Hash<Key>>;
    template<class Key, class T>
    using hmap = std::unordered_map<Key, T, Hash<Key>>;
    template<class Key>
    using hmiset = std::unordered_multiset<Key, Hash<Key>>;
    template<class Key, class T>
    using hmmap = std::unordered_multimap<Key, T, Hash<Key>>;
    template<class T, class Compare = std::less<T>, class Container = std::vector<T>>
    using priq = std::priority_queue<T, Container, Compare>;
    template<class T, class Compare = std::greater<T>, class Container = std::vector<T>>
    using heapq = priq<T, Compare, Container>;
} // namespace kyopro

using namespace std;
using namespace kyopro;