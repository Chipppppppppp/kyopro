#pragma once
#include <iterator>
#include <tuple>
#include <type_traits>
#include <utility>
#include "../meta/settings.hpp"
#include "../system/all.hpp"

namespace kpr::helper {
  template<KYOPRO_BASE_UINT len>
  constexpr KYOPRO_BASE_UINT va_args_size(const char (&s)[len]) noexcept {
    if constexpr (len == 1) return 0;
    KYOPRO_BASE_UINT cnt = 1;
    for (auto i: s) if (i == ',') ++cnt;
    return cnt;
  }

  template<class F, KYOPRO_BASE_UINT... idx>
  auto read_impl(F&& f, std::integer_sequence<KYOPRO_BASE_UINT, idx...>) {
    auto res = std::tuple{(static_cast<void>(idx), f())...};
    scan(res);
    return res;
  }

  Printer<Writer<>::iterator, true, true, true> debug_impl(output.begin());

  template<bool>
  void print_if(const char* s) {
    print(' ', s, ' ', '=', ' ');
  }
  template<>
  void print_if<false>(const char*) {}
}

#define read(init, ...) auto [__VA_ARGS__] = kpr::helper::read_impl([&] { return init; }, std::make_integer_sequence<KYOPRO_BASE_UINT, kpr::helper::va_args_size(#__VA_ARGS__)>())
#define debug(...) (kpr::print('#', 'l', 'i', 'n', 'e', ' ', __LINE__, ':'), kpr::helper::print_if<kpr::helper::va_args_size(#__VA_ARGS__) != 0>(#__VA_ARGS__), kpr::helper::debug_impl(__VA_ARGS__))
#define KYOPRO_OVERLOAD_MACRO(_1, _2, _3, _4, name, ...) name
#define KYOPRO_REP0() for (; ; )
#define KYOPRO_REP1(last) KYOPRO_REP2(KYOPRO_COUNTER, last)
#define KYOPRO_REP2(i, last) for (auto i = std::decay_t<decltype(last)>(), KYOPRO_LAST = (last); (i) < (KYOPRO_LAST); ++(i))
#define KYOPRO_REP3(i, first, last) for (auto i = (first), KYOPRO_LAST = last; (i) < (KYOPRO_LAST); ++(i))
#define rep(...) KYOPRO_OVERLOAD_MACRO(__VA_ARGS__ __VA_OPT__(,) KYOPRO_REP4, KYOPRO_REP3, KYOPRO_REP2, KYOPRO_REP1, KYOPRO_REP0)(__VA_ARGS__)
#define KYOPRO_LAMBDA1(value) ([&]() noexcept { return (value);})
#define KYOPRO_LAMBDA2(_1, value) ([&](auto&& _1) noexcept { return (value); })
#define KYOPRO_LAMBDA3(_1, _2, value) ([&](auto&& _1, auto&& _2) noexcept { return (value); })
#define KYOPRO_LAMBDA4(_1, _2, _3, value) ([&](auto&& _1, auto&& _2, auto&& _3) noexcept { return (value); })
#define lambda(...) KYOPRO_OVERLOAD_MACRO(__VA_ARGS__, KYOPRO_LAMBDA4, KYOPRO_LAMBDA3, KYOPRO_LAMBDA2, KYOPRO_LAMBDA1)(__VA_ARGS__)
#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)