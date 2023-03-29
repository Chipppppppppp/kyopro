#pragma once
#include <type_traits>

#define KYOPRO_REP0() for (; ; )
#define KYOPRO_REP1(last) KYOPRO_REP2(KYOPRO_COUNTER, last)
#define KYOPRO_REP2(i, last) for (auto i = std::decay_t<decltype(last)>(), KYOPRO_LAST = (last); (i) < (KYOPRO_LAST); ++(i))
#define KYOPRO_REP3(i, first, last) for (auto i = (first), KYOPRO_LAST = last; (i) < (KYOPRO_LAST); ++(i))

#define KYOPRO_OVERLOAD_REP(_1, _2, _3, name, ...) name
#define rep(...) KYOPRO_OVERLOAD_REP(__VA_ARGS__ __VA_OPT__(,) KYOPRO_REP3, KYOPRO_REP2, KYOPRO_REP1, KYOPRO_REP0)(__VA_ARGS__)
