#pragma once
#include <iterator>
#include <type_traits>
#include "../meta/settings.hpp"

#define KYOPRO_OVERLOAD_MACRO(_1, _2, _3, _4, name, ...) name
#define KYOPRO_REP0() for (; ; )
#define KYOPRO_REP1(i) for (KYOPRO_BASE_INT i = 0; ; ++(i))
#define KYOPRO_REP2(i, last) for (KYOPRO_BASE_INT i = 0, KYOPRO_LAST_ ## i = (last); (i) < (KYOPRO_LAST_ ## i); ++(i))
#define KYOPRO_REP3(i, first, last) for (KYOPRO_BASE_INT i = (first), KYOPRO_LAST_ ## i = last; (i) < (KYOPRO_LAST_ ## i); ++(i))
#define KYOPRO_REP4(i, first, last, step) for (KYOPRO_BASE_INT i = (first), KYOPRO_LAST_ ## i = (last), KYOPRO_STEP_ ## i = (step); (KYOPRO_STEP_ ## i) > 0 ? (i) < (KYOPRO_LAST_ ## i) : (i) > (KYOPRO_LAST_ ## i); (i) += (KYOPRO_BASE_INT)(step))
#define rep(...) KYOPRO_OVERLOAD_MACRO(__VA_ARGS__ __VA_OPT__(,) KYOPRO_REP3, KYOPRO_REP2, KYOPRO_REP1, KYOPRO_REP0)(__VA_ARGS__)
#define KYOPRO_ITER2(i, last) for (auto i = std::decay_t<decltype(last)>(), KYOPRO_LAST_ ## i = (last); (i) != (KYOPRO_LAST_ ## i); ++(i))
#define KYOPRO_ITER3(i, first, last) for (auto i = (first), KYOPRO_LAST_ ## i = (last); (i) != (KYOPRO_LAST_ ## i); ++(i))
#define KYOPRO_ITER4(i, first, last, step) for (auto i = (first), KYOPRO_LAST_ ## i = (last); (step) > 0 ? (i) < (KYOPRO_LAST_ ## i) : (i) > (KYOPRO_LAST_ ## i); (i) += (step))
#define iter(...) KYOPRO_OVERLOAD_MACRO(__VA_ARGS__, KYOPRO_ITER4, KYOPRO_ITER3, KYOPRO_ITER2)(__VA_ARGS__)
#define KYOPRO_LAMBDA1(value) ([&]() noexcept { return (value);})
#define KYOPRO_LAMBDA2(_1, value) ([&](auto&& _1) noexcept { return (value); })
#define KYOPRO_LAMBDA3(_1, _2, value) ([&](auto&& _1, auto&& _2) noexcept { return (value); })
#define KYOPRO_LAMBDA4(_1, _2, _3, value) ([&](auto&& _1, auto&& _2, auto&& _3) noexcept { return (value); })
#define lambda(...) KYOPRO_OVERLOAD_MACRO(__VA_ARGS__, KYOPRO_LAMBDA4, KYOPRO_LAMBDA3, KYOPRO_LAMBDA2, KYOPRO_LAMBDA1)(__VA_ARGS__)
#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)