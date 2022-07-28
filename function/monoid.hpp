#pragma once
#include <limits>
#include <type_traits>
#include "../meta/constant.hpp"

namespace kyopro {
    template<class T, T _id = 0>
    struct Add {
        static_assert(std::is_arithmetic_v<T>);
        using value_type = T;

        constexpr T id() const noexcept {
            return _id;
        }

        constexpr T operator ()(T a, T b) const noexcept {
            return a + b;
        }

        constexpr T inverse(T a) const noexcept {
            return -a;
        }
    };

    template<class T, T _id = 1>
    struct Mul {
        static_assert(std::is_arithmetic_v<T>);
        using value_type = T;

        constexpr T id() const noexcept {
            return _id;
        }

        constexpr T operator ()(T a, T b) const noexcept {
            return a * b;
        }

        constexpr T inverse(T a) const noexcept {
        static_assert(!std::is_integral_v<T>);
            return 1 / a;
        }
    };

    template<class T, T _id = std::is_integral_v<T> ? INF<T> : std::numeric_limits<T>::infinity()>
    struct Min {
        static_assert(std::is_arithmetic_v<T>);
        using value_type = T;

        constexpr T id() const noexcept {
            return _id;
        }

        constexpr T operator ()(T a, T b) const noexcept {
            return a < b ? a : b;
        }
    };

    template<class T, T _id = std::is_integral_v<T> ? std::is_signed_v<T> ? -INF<T> : 0 : -std::numeric_limits<T>::infinity()>
    struct Max {
        static_assert(std::is_arithmetic_v<T>);
        using value_type = T;

        constexpr T id() const noexcept {
            return _id;
        }

        constexpr T operator ()(T a, T b) const noexcept {
            return a > b ? a : b;
        }
    };
} // namespace kyopro