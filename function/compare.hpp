#pragma once

namespace kyopro {
    struct Equal {
        template<class T>
        constexpr bool operator()(const T& x, const T& y) const noexcept(noexcept(x == y)) {
            return x == y;
        }
    };

    struct NotEqual {
        template<class T>
        constexpr bool operator()(const T& x, const T& y) const noexcept(noexcept(x != y)) {
            return x != y;
        }
    };

    struct Less {
        template<class T>
        constexpr bool operator()(const T& x, const T& y) const noexcept(noexcept(x < y)) {
            return x < y;
        }
    };

    struct LessEqual {
        template<class T>
        constexpr bool operator()(const T& x, const T& y) const noexcept(noexcept(x <= y)) {
            return x <= y;
        }
    };

    struct Greater {
        template<class T>
        constexpr bool operator()(const T& x, const T& y) const noexcept(noexcept(x > y)) {
            return x > y;
        }
    };

    struct GreaterEqual {
        template<class T>
        constexpr bool operator()(const T& x, const T& y) const noexcept(noexcept(x >= y)) {
            return x >= y;
        }
    };
} // namespace kyopro