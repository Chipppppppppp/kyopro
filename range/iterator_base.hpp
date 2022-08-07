#pragma once
#include <cstddef>
#include <iterator>
#include <type_traits>

namespace kyopro {
    template<class, class, bool = false>
    struct IteratorBase;

    template<class Derived, bool Const>
    struct IteratorBase<Derived, std::forward_iterator_tag, Const> {
        using value_type = std::decay_t<decltype(*std::declval<Derived>())>;
        using pointer = value_type*;
        using reference = value_type&;
        using difference_type = std::ptrdiff_t;
        using iterator_category = std::forward_iterator_tag;

        virtual constexpr std::conditional_t<Const, const decltype(*std::declval<Derived>()), decltype(*std::declval<Derived>())> operator *() const noexcept;
        virtual constexpr Derived& operator ++() noexcept;
        virtual constexpr bool operator ==(const Derived&) const noexcept;

        constexpr Derived operator ++(int) noexcept {
            Derived before = *this;
            ++*this;
            return before;
        }

        constexpr bool operator !=(const Derived& rhs) const noexcept {
            return !(*this == rhs);
        }
    };

    template<class Derived, bool Const>
    struct IteratorBase<Derived, std::bidirectional_iterator_tag, Const>: IteratorBase<Derived, std::forward_iterator_tag, Const> {
        using iterator_category = std::bidirectional_iterator_tag;

        virtual constexpr Derived& operator --() noexcept;

        constexpr Derived operator --(int) noexcept {
            Derived before = *this;
            --*this;
            return before;
        }
    };

    template<class Derived, bool Const>
    struct IteratorBase<Derived, std::random_access_iterator_tag, Const>: IteratorBase<Derived, std::bidirectional_iterator_tag, Const> {
        using iterator_category = std::random_access_iterator_tag;

        virtual constexpr Derived operator +(std::ptrdiff_t rhs) const noexcept;
        virtual constexpr std::ptrdiff_t operator -(const Derived&) const noexcept;

    private:
        virtual constexpr int compare(const Derived&) const noexcept;

    public:

        constexpr Derived& operator +=(std::ptrdiff_t rhs) noexcept {
            return *this = *this + rhs;
        }

        constexpr Derived operator -(std::ptrdiff_t rhs) const noexcept {
            return *this + -rhs;
        }

        constexpr Derived& operator -=(std::ptrdiff_t rhs) noexcept {
            return *this = *this - rhs;
        }

        virtual constexpr std::conditional_t<Const, const decltype(*std::declval<Derived>()), decltype(*std::declval<Derived>())> operator [](std::size_t idx) const noexcept {
            return *(*this + idx);
        }

        virtual constexpr bool operator ==(const Derived& rhs) const noexcept {
            return compare(rhs) == 0;
        }
        virtual constexpr bool operator !=(const Derived& rhs) const noexcept {
            return compare(rhs) != 0;
        }
        virtual constexpr bool operator <(const Derived& rhs) const noexcept {
            return compare(rhs) < 0;
        }
        virtual constexpr bool operator <=(const Derived& rhs) const noexcept {
            return compare(rhs) <= 0;
        }
        virtual constexpr bool operator >(const Derived& rhs) const noexcept {
            return compare(rhs) > 0;
        }
        virtual constexpr bool operator >=(const Derived& rhs) const noexcept {
            return compare(rhs) >= 0;
        }
    };
} // namespace kyopro