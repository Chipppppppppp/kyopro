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

#define read(type_or_init, ...) \
    auto [__VA_ARGS__] = (kpr::helper::read_impl(([&]() { \
        using T = std::decay_t<decltype(*new type_or_init)>; \
        alignas(T) std::byte storage[sizeof(T)]; \
        T* p = new (storage) type_or_init; \
        kpr::scan(*p); \
        T res = std::move(*p); \
        p->~T(); \
        return res; \
    }), std::make_index_sequence<kpr::helper::va_args_size(#__VA_ARGS__)>()))

#define BOOL(...) read(bool, __VA_ARGS__);
#define INT(...) read(int, __VA_ARGS__);
#define LL(...) read(ll, __VA_ARGS__);
#define FLOAT(...) read(float, __VA_ARGS__);
#define LF(...) read(lf, __VA_ARGS__);
#define LLF(...) read(llf, __VA_ARGS__);
#define MINT(...) read(mint, __VA_ARGS__);
#define DMINT(...) read(dmint, __VA_ARGS__);
#define CHAR(...) read(char, __VA_ARGS__);
#define STR(...) read(str, __VA_ARGS__);
#define LL1(...) read(ll1, __VA_ARGS__);
#define LL2(...) read(ll2, __VA_ARGS__);
#define LL3(...) read(ll3, __VA_ARGS__);
#define LL4(...) read(ll4, __VA_ARGS__);
#define LL5(...) read(ll5, __VA_ARGS__);

#ifdef NDEBUG
#define debug(...) (void())
#else
#define debug(...) (kpr::print('#', ' ', __LINE__, ':'), kpr::helper::print_if<kpr::helper::va_args_size(#__VA_ARGS__) != 0>(#__VA_ARGS__), kpr::print('\n'), kpr::helper::debug_impl(__VA_ARGS__))
#endif
