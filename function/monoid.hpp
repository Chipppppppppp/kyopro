#pragma once
#include <limits>
#include <type_traits>
#include "../meta/constant.hpp"
#include "../meta/trait.hpp"

namespace kpr {
    // 足し算のmonoid
    template<class T>
    struct Add {
        static_assert(is_arithmetic_v<T>, "T must be an arithmetic type");

        using value_type = T;

        constexpr T id() const noexcept {
            return T{};
        }

        constexpr T operator ()(const T& a, const T& b) const noexcept {
            return a + b;
        }

        constexpr T inverse(const T& a) const noexcept {
            static_assert(std::is_signed_v<T>, "T must be a signed type");
            return -a;
        }
    };

    // 掛け算のmonoid
    template<class T>
    struct Mul {
        static_assert(is_arithmetic_v<T>, "T must be an arithmetic type");

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

    // minのmonoid
    template<class T>
    struct Min {
        static_assert(is_arithmetic_v<T>, "T must be an arithmetic type");

        using value_type = T;

        constexpr T id() const noexcept {
            return std::numeric_limits<T>::has_infinity ? std::numeric_limits<T>::infinity() : INF<T>;
        }

        constexpr T operator ()(const T& a, const T& b) const noexcept {
            return a < b ? a : b;
        }
    };

    // maxのmonoid
    template<class T>
    struct Max {
        static_assert(is_arithmetic_v<T>, "T must be an arithmetic type");

        using value_type = T;

        constexpr T id() const noexcept {
            return std::numeric_limits<T>::has_infinity ? -std::numeric_limits<T>::infinity() : (std::is_signed_v<T> ? -INF<T> : 0);
        }

        constexpr T operator ()(const T& a, const T& b) const noexcept {
            return a > b ? a : b;
        }
    };


    // inverseを持つか調べる
    template<class, class = void>
    struct has_inverse {
        static constexpr bool value = false;
    };

    template<class T>
    struct has_inverse<T, std::void_t<decltype(&T::inverse)>> {
        static constexpr bool value = true;
    };

    // inverseを持つか調べる
    template<class T>
    inline constexpr bool has_inverse_v = has_inverse<T>::value;
} // namespace kpr
