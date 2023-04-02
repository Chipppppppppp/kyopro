#pragma once
#include <type_traits>

#define KYOPRO_OVERLOAD_REP(_1, _2, _3, name, ...) name

#define KYOPRO_REP0() for (; ; )
#define KYOPRO_REP1(last) KYOPRO_REP2(KYOPRO_COUNTER, last)
#define KYOPRO_REP2(i, last) for (auto i = std::decay_t<decltype(last)>(), KYOPRO_LAST = (last); (i) != (KYOPRO_LAST); ++(i))
#define KYOPRO_REP3(i, first, last) for (auto i = (first), KYOPRO_LAST = last; (i) != (KYOPRO_LAST); ++(i))

#define rep(...) KYOPRO_OVERLOAD_REP(__VA_ARGS__ __VA_OPT__(,) KYOPRO_REP3, KYOPRO_REP2, KYOPRO_REP1, KYOPRO_REP0)(__VA_ARGS__)

namespace kpr::helper {
    template<class T>
    constexpr auto prev(T x) noexcept {
        return --x;
    }
} // namespace kpr::helper

#define KYOPRO_RREP0() for (; ; )
#define KYOPRO_RREP1(last) KYOPRO_RREP2(KYOPRO_COUNTER, last)
#define KYOPRO_RREP2(i, last) for (auto i = kpr::helper::prev(last), KYOPRO_FIRST = kpr::helper::prev(std::decay_t<decltype(last)>()); (i) != (KYOPRO_FIRST); --(i))
#define KYOPRO_RREP3(i, first, last) for (auto i = kpr::helper::prev(last), KYOPRO_FIRST = kpr::helper::prev(first); (i) != (KYOPRO_FIRST); --(i))

#define rrep(...) KYOPRO_OVERLOAD_REP(__VA_ARGS__ __VA_OPT__(,) KYOPRO_RREP3, KYOPRO_RREP2, KYOPRO_RREP1, KYOPRO_RREP0)(__VA_ARGS__)
