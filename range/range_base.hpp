#pragma once
#include <cstddef>
#include <iterator>
#include <stdexcept>
#include <string>
#include "iterator_base.hpp"
#include "../system/out.hpp"

namespace kyopro {
    template<class Derived, class = typename Derived::iterator::iterator_category>
    struct RangeBase;

    template<class Derived>
    struct RangeBase<Derived, std::forward_iterator_tag> {
        using value_type = typename Derived::iterator::value_type;
        using size_type = std::size_t;
        using difference_type = std::ptrdiff_t;
        using reference = value_type&;
        using const_reference = const value_type&;
        using pointer = value_type*;
        using const_pointer = const value_type*;

        virtual constexpr Derived::iterator begin() const noexcept;
        virtual constexpr Derived::iterator end() const noexcept;
        virtual constexpr Derived::iterator cbegin() const noexcept;
        virtual constexpr Derived::iterator cend() const noexcept;

        virtual constexpr bool empty() const noexcept {
            return begin() == end();
        }

        constexpr decltype(auto) front() noexcept {
            return *begin();
        }
        constexpr decltype(auto) front() const noexcept {
            return *cbegin();
        }
    };

    template<class Derived>
    struct RangeBase<Derived, std::bidirectional_iterator_tag>: IteratorBase<Derived, std::forward_iterator_tag> {
    protected:
        using iterator_category = std::bidirectional_iterator_tag;
        using reverse_iterator = std::reverse_iterator<Derived::iterator>;
        using const_reverse_iterator = std::reverse_iterator<Derived::const_iterator>;

        virtual constexpr reverse_iterator rbegin() const noexcept {
            return reverse_iterator(end());
        }
        virtual constexpr reverse_iterator rend() const noexcept {
            return reverse_iterator(begin());
        }
        virtual constexpr const_reverse_iterator crbegin() const noexcept {
            return const_reverse_iterator(cend());
        }
        virtual constexpr const_reverse_iterator crend() const noexcept {
            return const_reverse_iterator(cbegin());
        }

        constexpr decltype(auto) back() noexcept {
            return *rbegin();
        }
        constexpr decltype(auto) back() const noexcept {
            return *crbegin();
        }
    };

    template<class Derived>
    struct RangeBase<Derived, std::random_access_iterator_tag>: IteratorBase<Derived, std::bidirectional_iterator_tag> {
        virtual constexpr std::size_t size() const noexcept {
            return end() - begin();
        }

        constexpr decltype(auto) operator [](std::size_t idx) {
            return *(begin() + idx);
        }
        constexpr decltype(auto) operator [](std::size_t idx) const {
            return *(cbegin() + idx);
        }
    };
} // namespace kyopro