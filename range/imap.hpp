#pragma once
#include <cstddef>
#include <functional>
#include <iterator>
#include <type_traits>
#include <utility>
#include "range_base.hpp"
#include "../meta/trait.hpp"

namespace kpr {
    template<class Func, class Range>
    struct imap: RangeBase<imap<Func, Range>, std::invoke_result_t<Func, range_value_t<Range>>> {
    private:
        using BaseIterator = range_iterator_t<Range>;
        using BaseConstIterator = range_const_iterator_t<Range>;

        Func func;
        Range range;

    public:
        imap() noexcept = default;
        template<class F, class R>
        imap(F&& func, R&& range) noexcept: func(std::forward<F>(func)), range(std::forward<R>(range)) {}

        struct iterator: BaseIterator {
            using value_type = std::decay_t<std::invoke_result_t<Func, decltype(*std::declval<BaseIterator>())>>;
            using pointer = value_type*;
            using reference = value_type&;

        private:
            Func func;

        public:
            iterator() noexcept = default;
            template<class F, class Itr>
            iterator(F&& func, Itr&& itr) noexcept: func(std::forward<F>(func)), BaseIterator(std::forward<Itr>(itr)) {}

            constexpr decltype(auto) operator *() const noexcept {
                return std::invoke(func, BaseIterator::operator *());
            }
        };

        struct const_iterator: BaseConstIterator {
            using value_type = const std::decay_t<std::invoke_result_t<Func, decltype(*std::declval<BaseConstIterator>())>>;
            using pointer = value_type*;
            using reference = value_type&;

        private:
            Func func;

        public:
            const_iterator() noexcept = default;
            template<class F, class Itr>
            const_iterator(F&& func, Itr&& itr) noexcept: func(std::forward<F>(func)), BaseConstIterator(std::forward<Itr>(itr)) {}

            constexpr decltype(auto) operator *() const noexcept {
                return std::invoke(func, BaseConstIterator::operator *());
            }
        };


        using reverse_iterator = std::reverse_iterator<iterator>;
        using const_reverse_iterator = std::reverse_iterator<const_iterator>;


        constexpr iterator begin() const noexcept {
            return iterator{func, std::begin(range)};
        }

        constexpr iterator end() const noexcept {
            return iterator{func, std::end(range)};
        }

        constexpr const_iterator cbegin() const noexcept {
            return const_iterator{func, std::begin(range)};
        }

        constexpr const_iterator cend() const noexcept {
            return const_iterator{func, std::end(range)};
        }
    };

    template<class F, class R>
    imap(F&&, R&&) -> imap<std::decay_t<F>, std::decay_t<R>>;
} // namespace kpr
