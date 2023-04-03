#pragma once
#include <limits>
#include <type_traits>
#include "../meta/setting.hpp"
#include "../meta/trait.hpp"

namespace kpr {
    // 足し算のmonoid
    template<class T>
    struct Add {
        static_assert(is_arithmetic_v<T>, "T must be an arithmetic type");

        using value_type = T;

        static constexpr T id() noexcept {
            return T{};
        }

        constexpr T operator ()(const T& a, const T& b) const noexcept {
            return a + b;
        }

        static constexpr T inv(const T& a) noexcept {
            static_assert(std::is_signed_v<T>, "T must be a signed type");
            return -a;
        }
    };

    // 掛け算のmonoid
    template<class T>
    struct Mul {
        static_assert(is_arithmetic_v<T>, "T must be an arithmetic type");

        using value_type = T;

        static constexpr T id() noexcept {
            return 1;
        }

        constexpr T operator ()(const T& a, const T& b) const noexcept {
            return a * b;
        }

        static constexpr T inv(const T& a) noexcept {
            return 1 / a;
        }
    };

    // minのmonoid
    template<class T>
    struct Min {
        static_assert(is_arithmetic_v<T>, "T must be an arithmetic type");

        using value_type = T;

        static constexpr T id() noexcept {
            if constexpr (std::numeric_limits<T>::has_infinity) return std::numeric_limits<T>::infinity();
            return std::numeric_limits<T>::max() / KYOPRO_INF_DIV;
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

        static constexpr T id() noexcept {
            if constexpr (std::numeric_limits<T>::has_infinity) return -std::numeric_limits<T>::infinity();
            if constexpr (std::is_signed_v<T>) return -(std::numeric_limits<T>::max() / KYOPRO_INF_DIV);
            return 0;
        }

        constexpr  T operator ()(const T& a, const T& b) const noexcept {
            return a > b ? a : b;
        }
    };


    // invを持つか調べる
    template<class, class = void>
    struct has_inv {
        static constexpr bool value = false;
    };

    template<class T>
    struct has_inv<T, std::void_t<decltype(&T::inv)>> {
        static constexpr bool value = true;
    };

    // invを持つか調べる
    template<class T>
    inline constexpr bool has_inv_v = has_inv<T>::value;
} // namespace kpr
