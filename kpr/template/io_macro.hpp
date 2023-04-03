#pragma once
#include <unistd.h>
#include <cstddef>
#include <istream>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>
#include "../io/io.hpp"

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

    Printer<Writer<>::iterator, true, true, true, true> debug_impl(output.begin());

    template<bool flag>
    void print_if(std::string_view sv) {
        if constexpr (flag) print(' ', sv);
    }
} // namespace kpr::helper

/* C++20以降
#define read(type_or_init, ...) \
    auto [__VA_ARGS__] = (kpr::helper::read_impl(([]() { \
        using T = std::decay_t<decltype(*new type_or_init)>; \
        alignas(T) std::byte storage[sizeof(T)]; \
        T* p = new (storage) type_or_init; \
        kpr::scan(*p); \
        T res = std::move(*p); \
        p->~T(); \
        return res; \
    }), std::make_index_sequence<kpr::helper::va_args_size(#__VA_ARGS__)>()))
*/

#define BOOL(...) bool __VA_ARGS__; scan(__VA_ARGS__)
#define INT(...) int __VA_ARGS__; scan(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__; scan(__VA_ARGS__)
#define FLOAT(...) float __VA_ARGS__; scan(__VA_ARGS__)
#define LF(...) lf __VA_ARGS__; scan(__VA_ARGS__)
#define LLF(...) llf __VA_ARGS__; scan(__VA_ARGS__)
#define MINT(...) mint __VA_ARGS__; scan(__VA_ARGS__)
#define DMINT(...) dmint __VA_ARGS__; scan(__VA_ARGS__)
#define CHAR(...) char __VA_ARGS__; scan(__VA_ARGS__)
#define STR(...) str __VA_ARGS__; scan(__VA_ARGS__)
#define LI1(...) li1 __VA_ARGS__; scan(__VA_ARGS__)
#define LI2(...) li2 __VA_ARGS__; scan(__VA_ARGS__)
#define LI3(...) li3 __VA_ARGS__; scan(__VA_ARGS__)
#define LI4(...) li4 __VA_ARGS__; scan(__VA_ARGS__)
#define LI5(...) li5 __VA_ARGS__; scan(__VA_ARGS__)

#define KYOPRO_READ1(init, _1) auto _1 = init; scan(_1)
#define KYOPRO_READ2(init, _1, _2) auto _1 = init, _2 = init; scan(_1, _2)
#define KYOPRO_READ3(init, _1, _2, _3) auto _1 = init, _2 = init, _3 = init; scan(_1, _2, _3)
#define KYOPRO_READ4(init, _1, _2, _3, _4) auto _1 = init, _2 = init, _3 = init, _4 = init; scan(_1, _2, _3, _4)

#define KYOPRO_OVERLOAD_READ(_1, _2, _3, _4, _5, name, ...) name
#define read(...) KYOPRO_OVERLOAD_READ(__VA_ARGS__, KYOPRO_READ4, KYOPRO_READ3, KYOPRO_READ2, KYOPRO_READ1)(__VA_ARGS__)

#ifdef NDEBUG
#define debug(...) (void())
#else
#define debug(...) (kpr::print('#', ' ', 'l', 'i', 'n', 'e', ' ', __LINE__, ':'), kpr::helper::print_if<kpr::helper::va_args_size(#__VA_ARGS__) != 0>(#__VA_ARGS__), kpr::print('\n'), kpr::helper::debug_impl(__VA_ARGS__))
#endif
