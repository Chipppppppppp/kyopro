#pragma once
#include <limits>
#include <type_traits>
#include "../meta/constant.hpp"

namespace kyopro {
    template<class T>
    struct Add {
        using value_type = T;

        constexpr T id() const noexcept {
            return T{};
        }

        constexpr T operator ()(const T& a, const T& b) const noexcept {
            return a + b;
        }

        constexpr T inverse(const T& a) const noexcept {
            return -a;
        }
    };

    template<class T>
    struct Mul {
        using value_type = T;

        constexpr T id() const noexcept {
            return 1;
        }

        constexpr T operator ()(const T& a, const T& b) const noexcept {
            return a * b;
        }

        constexpr T inverse(const T& a) const noexcept {
            return 1 / a;
        }
    };

    template<class T>
    struct Min {
        using value_type = T;

        constexpr T id() const noexcept {
            return std::is_integral_v<T> ? INF<T> : std::numeric_limits<T>::infinity();
        }

        constexpr T operator ()(const T& a, const T& b) const noexcept {
            return a < b ? a : b;
        }
    };

    template<class T>
    struct Max {
        using value_type = T;

        constexpr T id() const noexcept {
            return std::is_integral_v<T> ? std::is_signed_v<T> ? -INF<T> : 0 : -std::numeric_limits<T>::infinity();
        }

        constexpr T operator ()(const T& a, const T& b) const noexcept {
            return a > b ? a : b;
        }
    };

    template<class, class = void>
    struct has_inverse: std::false_type {};
    template<class T>
    struct has_inverse<T, std::void_t<decltype(&T::inverse)>>: std::true_type {};

    template<class T>
    inline constexpr bool has_inverse_v = has_inverse<T>::value;
} // namespace kyopro