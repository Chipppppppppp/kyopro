#pragma once
#include <cstddef>
#include <iterator>
#include <type_traits>

namespace kpr {
    template<class Derived, class ValueType>
    struct RangeBase {
        using value_type = std::decay_t<ValueType>;
        using size_type = std::size_t;
        using difference_type = std::ptrdiff_t;
        using reference = value_type&;
        using const_reference = const value_type&;
        using pointer = value_type*;
        using const_pointer = const value_type*;

        Derived& down_cast() noexcept {
            return static_cast<Derived&>(*this);
        }
        const Derived& down_cast() const noexcept {
            return static_cast<const Derived&>(*this);
        }

        constexpr auto begin() const noexcept {
            return down_cast().begin();
        }

        constexpr auto end() const noexcept {
            return down_cast().end();
        }

        constexpr auto cbegin() const noexcept {
            return down_cast().cbegin();
        }

        constexpr auto cend() const noexcept {
            return down_cast().cend();
        }

        constexpr bool empty() const noexcept {
            return begin() == end();
        }

        constexpr decltype(auto) front() noexcept {
            return *begin();
        }
        constexpr decltype(auto) front() const noexcept {
            return *cbegin();
        }

        constexpr decltype(auto) rbegin() const noexcept {
            return std::reverse_iterator(end());
        }

        constexpr decltype(auto) rend() const noexcept {
            return std::reverse_iterator(begin());
        }

        constexpr decltype(auto) crbegin() const noexcept {
            return std::reverse_iterator(cend());
        }

        constexpr decltype(auto) crend() const noexcept {
            return std::reverse_iterator(cbegin());
        }

        constexpr decltype(auto) back() noexcept {
            return *rbegin();
        }
        constexpr decltype(auto) back() const noexcept {
            return *crbegin();
        }

        constexpr std::size_t size() const noexcept {
            return end() - begin();
        }

        constexpr decltype(auto) operator [](std::size_t idx) {
            return *(begin() + idx);
        }
        constexpr decltype(auto) operator [](std::size_t idx) const {
            return *(cbegin() + idx);
        }
    };
} // namespace kpr
