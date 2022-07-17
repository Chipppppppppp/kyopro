#pragma once
#include <cstddef>
#include <iterator>
#include <memory>
#include <tuple>
#include <type_traits>
#include <utility>
#include "../meta/settings.hpp"
#include "../system/all.hpp"

namespace kyopro::helper {
  template<std::size_t len>
  constexpr KYOPRO_BASE_UINT va_args_size(const char (&s)[len]) noexcept {
    if constexpr (len == 1) return 0;
    KYOPRO_BASE_UINT cnt = 1;
    std::uint_fast64_t bracket = 0;
    for (auto i: s) {
      if (i == '(') ++bracket;
      else if (i == ')') --bracket;
      else if (i == ',' && bracket == 0) ++cnt;
    }
    return cnt;
  }

  template<class F, std::size_t... idx>
  auto read_impl(F&& f, std::index_sequence<idx...>) {
    return std::tuple{(static_cast<void>(idx), f())...};
  }

  Printer<Writer<>::iterator, true, true, true, true, true> debug_impl(output.begin());

  template<bool flag, std::size_t len>
  void print_if(const char (&s)[len]) {
    if constexpr (flag) print(' ', s);
  }
}

#define read(type_or_init, ...) auto [__VA_ARGS__] = kyopro::helper::read_impl(([]() {\
  using T = std::decay_t<decltype(*new type_or_init)>;\
  alignas(T) std::byte storage[sizeof(T)];\
  T* p = new (storage) type_or_init;\
  kyopro::scan(*p);\
  return std::move(*p);\
}), std::make_index_sequence<kyopro::helper::va_args_size(#__VA_ARGS__)>())
#define debug(...) (kyopro::print('#', ' ', 'l', 'i', 'n', 'e', ' ', __LINE__, ':'), kyopro::helper::print_if<kyopro::helper::va_args_size(#__VA_ARGS__) != 0>(#__VA_ARGS__), kyopro::print('\n'), kyopro::helper::debug_impl(__VA_ARGS__))

#define KYOPRO_OVERLOAD_MACRO(_1, _2, _3, _4, name, ...) name

#define KYOPRO_REP0() for (; ; )
#define KYOPRO_REP1(last) KYOPRO_REP2(KYOPRO_COUNTER, last)
#define KYOPRO_REP2(i, last) for (auto i = std::decay_t<decltype(last)>(), KYOPRO_LAST = (last); (i) < (KYOPRO_LAST); ++(i))
#define KYOPRO_REP3(i, first, last) for (auto i = (first), KYOPRO_LAST = last; (i) < (KYOPRO_LAST); ++(i))
#define rep(...) KYOPRO_OVERLOAD_MACRO(__VA_ARGS__ __VA_OPT__(,) KYOPRO_REP4, KYOPRO_REP3, KYOPRO_REP2, KYOPRO_REP1, KYOPRO_REP0)(__VA_ARGS__)

#define KYOPRO_MATCH1(_1) break; case _1:
#define KYOPRO_MATCH2(_1, _2) break; case _1: case _2:
#define KYOPRO_MATCH3(_1, _2, _3) break; case _1: case _2: case _3:
#define KYOPRO_MATCH4(_1, _2, _3, _4) break; case _1: case _2: case _3: case _4:
#define match(...) KYOPRO_OVERLOAD_MACRO(__VA_ARGS__, KYOPRO_MATCH4, KYOPRO_MATCH3, KYOPRO_MATCH2, KYOPRO_MATCH1)(__VA_ARGS__)
#define otherwise break; default:

#define KYOPRO_LAMBDA1(value) ([&]() noexcept { return (value);})
#define KYOPRO_LAMBDA2(_1, value) ([&](auto&& _1) noexcept { return (value); })
#define KYOPRO_LAMBDA3(_1, _2, value) ([&](auto&& _1, auto&& _2) noexcept { return (value); })
#define KYOPRO_LAMBDA4(_1, _2, _3, value) ([&](auto&& _1, auto&& _2, auto&& _3) noexcept { return (value); })
#define lambda(...) KYOPRO_OVERLOAD_MACRO(__VA_ARGS__, KYOPRO_LAMBDA4, KYOPRO_LAMBDA3, KYOPRO_LAMBDA2, KYOPRO_LAMBDA1)(__VA_ARGS__)

#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)