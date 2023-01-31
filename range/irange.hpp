#pragma once
#include <cstddef>
#include <functional>
#include <iterator>
#include <type_traits>
#include <utility>
#include "iterator_base.hpp"
#include "range_base.hpp"
#include "../meta/trait.hpp"

namespace kpr {
    template<class T>
    struct irange: RangeBase<irange<T>, T> {
    private:
        T first, last;

        template<class, class = void, class = void, class = void>
        struct get_iterator_category;
        template<class ValueType, class Void>
        struct get_iterator_category<ValueType, std::void_t<decltype(++std::declval<ValueType>())>, Void, Void> {
            using type = std::forward_iterator_tag;
        };
        template<class ValueType, class Void>
        struct get_iterator_category<ValueType, std::void_t<decltype(++std::declval<ValueType>())>, std::void_t<decltype(--std::declval<ValueType>())>, Void> {
            using type = std::bidirectional_iterator_tag;
        };
        template<class ValueType>
        struct get_iterator_category<ValueType, std::void_t<decltype(++std::declval<ValueType>())>, std::void_t<decltype(--std::declval<ValueType>())>, std::void_t<decltype(std::declval<T>() < std::declval<ValueType>(), std::declval<ValueType>() > std::declval<ValueType>(), std::declval<ValueType>() + std::declval<std::ptrdiff_t>(), std::declval<ValueType>() - std::declval<ValueType>())>> {
            using type = std::random_access_iterator_tag;
        };

    public:
        irange() noexcept = default;
        template<class F, class L>
        irange(F&& first, L&& last) noexcept: first(std::forward<F>(first)), last(std::forward<L>(last)) {}

        struct iterator: IteratorBase<iterator, const T&, typename get_iterator_category<T&>::type> {
        private:
            T itr;

            constexpr int compare(const iterator& rhs) const noexcept {
                if (itr < rhs.itr) return -1;
                else if (itr > rhs.itr) return 1;
                else return 0;
            }

        public:
            iterator() noexcept = default;
            template<class Itr>
            iterator(Itr&& itr) noexcept: itr(std::forward<Itr>(itr)) {}

            constexpr const T& operator *() const noexcept {
                return itr;
            }

            constexpr iterator& operator ++() noexcept {
                ++itr;
                return *this;
            }

            constexpr iterator& operator --() noexcept {
                --itr;
                return *this;
            }

            constexpr iterator operator +(std::ptrdiff_t rhs) const noexcept {
                return iterator{itr + rhs};
            }

            constexpr std::ptrdiff_t operator -(const iterator& rhs) const noexcept {
                return itr - rhs.itr;
            }
        };

        struct const_iterator: IteratorBase<const_iterator, const T&, typename get_iterator_category<T&>::type> {
        private:
            T itr;

            constexpr int compare(const const_iterator& rhs) const noexcept {
                if (itr < rhs.itr) return -1;
                else if (itr > rhs.itr) return 1;
                else return 0;
            }

        public:
            const_iterator() noexcept = default;
            template<class Itr>
            const_iterator(Itr&& itr) noexcept: itr(std::forward<Itr>(itr)) {}

            constexpr const T& operator *() const noexcept {
                return itr;
            }

            constexpr const_iterator& operator ++() noexcept {
                ++itr;
                return *this;
            }

            constexpr const_iterator& operator --() noexcept {
                --itr;
                return *this;
            }

            constexpr const_iterator operator +(std::ptrdiff_t rhs) const noexcept {
                return iterator{itr + rhs};
            }

            constexpr std::ptrdiff_t operator -(const const_iterator& rhs) const noexcept {
                return itr - rhs.itr;
            }
        };


        using reverse_iterator = std::reverse_iterator<iterator>;
        using const_reverse_iterator = std::reverse_iterator<const_iterator>;


        constexpr iterator begin() const noexcept {
            return iterator{first};
        }

        constexpr iterator end() const noexcept {
            return iterator{last};
        }

        constexpr const_iterator cbegin() const noexcept {
            return const_iterator{first};
        }

        constexpr const_iterator cend() const noexcept {
            return const_iterator{last};
        }
    };

    template<class F, class L>
    irange(F&&, L&&) -> irange<std::decay_t<F>>;
} // namespace kpr
