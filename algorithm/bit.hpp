#pragma once
#include <limits>
#include <type_traits>
#include "../meta/setting.hpp"
#include "../meta/trait.hpp"

namespace kpr {
    // 立っているbitの個数を返す
    [[maybe_unused]] inline constexpr struct {
        template<class T>
        constexpr KYOPRO_BASE_INT operator ()(T x) const noexcept {
            static_assert(is_integer_v<T>, "The argument must be an integer");
            constexpr auto digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;
            static_assert(digits <= std::numeric_limits<unsigned long long>::digits, "The integer type of the argument is too large");
            if constexpr (digits <= std::numeric_limits<unsigned int>::digits) return __builtin_popcount(x);
            else if constexpr (digits <= std::numeric_limits<unsigned long>::digits) return __builtin_popcountl(x);
            else return __builtin_popcountll(x);
        }
    } pop_count;

    [[maybe_unused]] inline constexpr struct {
        template<class T>
        constexpr KYOPRO_BASE_INT operator ()(T x) const noexcept {
            static_assert(is_integer_v<T>, "The argument must be an integer");
            constexpr auto digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;
            static_assert(digits <= std::numeric_limits<unsigned long long>::digits, "The integer type of the argument is too large");
            if (x == 0) return 0;
            if constexpr (digits <= std::numeric_limits<unsigned int>::digits) return __builtin_clz(x) + digits - std::numeric_limits<unsigned int>::digits;
            else if constexpr (digits <= std::numeric_limits<unsigned long>::digits) return __builtin_clzl(x) + digits - std::numeric_limits<unsigned long>::digits;
            else return __builtin_clzll(x) + digits - std::numeric_limits<unsigned long long>::digits;
        }
    } lzero_count;

    [[maybe_unused]] inline constexpr struct {
        template<class T>
        constexpr KYOPRO_BASE_INT operator ()(T x) const noexcept {
            static_assert(is_integer_v<T>, "The argument must be an integer");
            constexpr auto digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;
            static_assert(digits <= std::numeric_limits<unsigned long long>::digits, "The integer type of the argument is too large");
            if constexpr (digits <= std::numeric_limits<unsigned int>::digits) return __builtin_ctz(x);
            else if constexpr (digits <= std::numeric_limits<unsigned long>::digits) return __builtin_ctzl(x);
            else return __builtin_ctzll(x);
        }
    } rzero_count;

    [[maybe_unused]] inline constexpr struct {
        template<class T>
        constexpr KYOPRO_BASE_INT operator ()(T x) const noexcept {
            static_assert(is_integer_v<T>, "The argument must be an integer");
            constexpr auto digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;
            static_assert(digits <= std::numeric_limits<unsigned long long>::digits, "The integer type of the argument is too large");
            if (x == 0) return 0;
            if constexpr (digits <= std::numeric_limits<unsigned int>::digits) return std::numeric_limits<unsigned int>::digits - __builtin_clz(x);
            else if constexpr (digits <= std::numeric_limits<unsigned long>::digits) return std::numeric_limits<unsigned long>::digits - __builtin_clzl(x);
            else return std::numeric_limits<unsigned long long>::digits - __builtin_clzll(x);
        }
    } bit_len;

    [[maybe_unused]] inline constexpr struct {
        template<class T>
        constexpr KYOPRO_BASE_INT operator ()(T x) const noexcept {
            return bit_len(x >> static_cast<T>(1));
        }
    } floor_bit;

    [[maybe_unused]] inline constexpr struct {
        template<class T>
        constexpr KYOPRO_BASE_INT operator ()(T x) const noexcept {
            if (x == 0) return 0;
            return bit_len(x - static_cast<T>(1));
        }
    } ceil_bit;
} // namespace kpr
