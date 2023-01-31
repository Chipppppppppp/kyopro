#pragma once
#include <cstddef>
#include <iterator>
#include <type_traits>

namespace kpr {
    template<class, class, class>
    struct IteratorBase;

    template<class Derived, class ValueType>
    struct IteratorBase<Derived, ValueType, std::forward_iterator_tag> {
        using value_type = std::decay_t<ValueType>;
        using pointer = value_type*;
        using reference = value_type&;
        using difference_type = std::ptrdiff_t;
        using iterator_category = std::forward_iterator_tag;

        virtual constexpr ValueType operator *() const noexcept;
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

    template<class Derived, class ValueType>
    struct IteratorBase<Derived, ValueType, std::bidirectional_iterator_tag>: IteratorBase<Derived, ValueType, std::forward_iterator_tag> {
        using iterator_category = std::bidirectional_iterator_tag;

        virtual constexpr Derived& operator --() noexcept;

        constexpr Derived operator --(int) noexcept {
            Derived before = *this;
            --*this;
            return before;
        }
    };

    template<class Derived, class ValueType>
    struct IteratorBase<Derived, ValueType, std::random_access_iterator_tag>: IteratorBase<Derived, ValueType, std::bidirectional_iterator_tag> {
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

        constexpr decltype(auto) operator [](std::size_t idx) const noexcept {
            return *(*this + idx);
        }

        constexpr bool operator ==(const Derived& rhs) const noexcept {
            return compare(rhs) == 0;
        }
        constexpr bool operator !=(const Derived& rhs) const noexcept {
            return compare(rhs) != 0;
        }
        constexpr bool operator <(const Derived& rhs) const noexcept {
            return compare(rhs) < 0;
        }
        constexpr bool operator <=(const Derived& rhs) const noexcept {
            return compare(rhs) <= 0;
        }
        constexpr bool operator >(const Derived& rhs) const noexcept {
            return compare(rhs) > 0;
        }
        constexpr bool operator >=(const Derived& rhs) const noexcept {
            return compare(rhs) >= 0;
        }
    };
} // namespace kpr
