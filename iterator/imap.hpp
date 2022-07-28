#pragma once
#include <cstddef>
#include <iterator>
#include <type_traits>
#include <utility>
#include "iterator_base.hpp"
#include "../meta/trait.hpp"

namespace kyopro {
    template<class Func, class Range>
    struct imap {
        using value_type = std::decay_t<decltype(std::declval<Func>()(std::declval<iterable_value_t<Range>>()))>;
        using size_type = std::size_t;
        using difference_type = std::ptrdiff_t;
        using reference = value_type&;
        using const_reference = const value_type&;
        using pointer = value_type*;
        using const_pointer = const value_type*;

    private:
        using BaseIterator = std::decay_t<decltype(std::begin(std::declval<Range>()))>;

        Func func;
        Range range;

    public:

        template<class F, class R>
        imap(F&& func, R&& range): func(std::forward<F>(func)), range(std::forward<R>(range)) {}

        struct iterator: BaseIterator {
        private:
            Func func;

        public:
            iterator() noexcept = default;
            template<class F>
            iterator(F&& func, BaseIterator itr) noexcept: func(std::forward<F>(func)), BaseIterator(itr) {}

            constexpr decltype(auto) operator *() const noexcept {
                return func(**this);
            }
        };

        using reverse_iterator = std::reverse_iterator<iterator>;

        constexpr iterator begin() {
            return iterator(func, range.begin());
        }

        constexpr iterator end() {
            return iterator(func, range.end());
        }

        constexpr iterator rbegin() {
            return reverse_iterator(func, range.rbegin());
        }

        constexpr iterator rend() {
            return reverse_iterator(func, range.rend());
        }
    };

    template<class F, class R>
    imap(F&&, R&&) -> imap<std::decay_t<F>, std::decay_t<R>>;
}