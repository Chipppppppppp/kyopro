#pragma once
#include <cstddef>
#include <iterator>
#include <memory>
#include <tuple>
#include <type_traits>
#include <utility>
#include "../system/system.hpp"

namespace kpr::helper {
    template<std::size_t len>
    constexpr std::size_t va_args_size(const char (&s)[len]) noexcept {
        if constexpr (len == 1) return 0;
        std::size_t cnt = 1;
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

    struct LambdaArg {};
} // namespace kpr::helper

#define read(type_or_init, ...)                                                           \
auto [__VA_ARGS__] = (kpr::helper::read_impl(([]() {                                   \
    using T = std::decay_t<decltype(*new type_or_init)>;                                  \
    alignas(T) std::byte storage[sizeof(T)];                                              \
    T* p = new (storage) type_or_init;                                                    \
    kpr::scan(*p);                                                                     \
    T res = std::move(*p);                                                                \
    p->~T();                                                                              \
    return res;                                                                           \
}), std::make_index_sequence<kpr::helper::va_args_size(#__VA_ARGS__)>()))
#define debug(...) (kpr::print('#', ' ', 'l', 'i', 'n', 'e', ' ', __LINE__, ':'), kpr::helper::print_if<kpr::helper::va_args_size(#__VA_ARGS__) != 0>(#__VA_ARGS__), kpr::print('\n'), kpr::helper::debug_impl(__VA_ARGS__))

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

#define $(...)\
([&](auto&&... _args) {\
    auto _args_tuple = std::forward_as_tuple(_args...);\
    if constexpr (sizeof...(_args) == 0) {\
        return ([&]() { return (__VA_ARGS__); })();\
    } else if constexpr (sizeof...(_args) == 1) {\
        return ([&](auto&& $0) { return (__VA_ARGS__); })(get<0>(_args_tuple));\
    } else if constexpr (sizeof...(_args) == 2) {\
        return ([&](auto&& $0, auto&& $1) { return (__VA_ARGS__); })(get<0>(_args_tuple), get<1>(_args_tuple));\
    } else if constexpr (sizeof...(_args) == 3) {\
        return ([&](auto&& $0, auto&& $1, auto&& $2) { return (__VA_ARGS__); })(get<0>(_args_tuple), get<1>(_args_tuple), get<2>(_args_tuple));\
    } else if constexpr (sizeof...(_args) == 4) {\
        return ([&](auto&& $0, auto&& $1, auto&& $2, auto&& $3) { return (__VA_ARGS__); })(get<0>(_args_tuple), get<1>(_args_tuple), get<2>(_args_tuple), get<3>(_args_tuple));\
    }\
})

#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)
