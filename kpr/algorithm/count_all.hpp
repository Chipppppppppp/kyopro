#pragma once
#include <iterator>
#include <unordered_map>
#include "Hash.hpp"
#include "../meta/setting.hpp"

namespace kpr {
    // 要素: 個数の辞書を返す
    [[maybe_unused]] inline constexpr struct {
        template<class T, class Container = std::unordered_map<typename std::iterator_traits<T>::value_type, KYOPRO_BASE_INT, Hash<typename std::iterator_traits<T>::value_type>>>
        auto operator ()(T first, T last) const {
            Container mem;
            for (auto i = first; i != last; ++i) ++mem[*i];
            return mem;
        }
    } count_all;
} // namespace kpr
