#pragma once
#include <algorithm>
#include <iterator>
#include "../meta/tuple_like.hpp"
#include "../meta/trait.hpp"

namespace kpr {
    // 要素を含んでいるか調べる
    [[maybe_unused]] inline constexpr struct {
    private:
        template<class T>
        constexpr bool impl(const T& container, const typename T::key_type& value, char) const {
            return container.find(value) != container.end();
        }
        template<class T, std::enable_if_t<!is_tuple_like_v<T>>* = nullptr>
        constexpr bool impl(const T& container, const range_value_t<T>& value, bool) const {
            return std::find(std::begin(container), std::end(container), value) != std::end(container);
        }
        template<std::size_t i = 0, class T, class U, std::enable_if_t<is_tuple_like_v<T>>* = nullptr>
        constexpr bool impl(const T& tuple_like, const U& value, bool) const {
            if constexpr (i < tuple_like_size_v<T>) return get<i>(tuple_like) == value || impl<i + 1>(tuple_like, value, false);
            else return false;
        }

    public:
        template<class T, class U>
        constexpr bool operator ()(const T& a, const U& x) const {
            return impl(a, x, false);
        }
    } contains;
} // namespace kpr
