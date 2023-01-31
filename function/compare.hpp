#pragma once

namespace kpr {
    // operator =で比較
    struct Equal {
        template<class T>
        constexpr bool operator()(const T& x, const T& y) const noexcept(noexcept(x == y)) {
            return x == y;
        }
    };

    // operator !=で比較
    struct NotEqual {
        template<class T>
        constexpr bool operator()(const T& x, const T& y) const noexcept(noexcept(x != y)) {
            return x != y;
        }
    };

    // operator <の関数クラス
    struct Less {
        template<class T>
        constexpr bool operator()(const T& x, const T& y) const noexcept(noexcept(x < y)) {
            return x < y;
        }
    };

    // operator <=の関数クラス
    struct LessEqual {
        template<class T>
        constexpr bool operator()(const T& x, const T& y) const noexcept(noexcept(x <= y)) {
            return x <= y;
        }
    };

    // operator >の関数クラス
    struct Greater {
        template<class T>
        constexpr bool operator()(const T& x, const T& y) const noexcept(noexcept(x > y)) {
            return x > y;
        }
    };

    // operator >=の関数クラス
    struct GreaterEqual {
        template<class T>
        constexpr bool operator()(const T& x, const T& y) const noexcept(noexcept(x >= y)) {
            return x >= y;
        }
    };
} // namespace kpr
