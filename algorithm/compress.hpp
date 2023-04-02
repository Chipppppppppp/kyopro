#pragma once
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <vector>
#include "../function/compare.hpp"

namespace kpr {
    // 座標圧縮
    [[maybe_unused]] inline constexpr struct {
        template<class T, class Compare = Less, class Container = std::unordered_map<typename std::iterator_traits<T>::value_type, KYOPRO_BASE_INT>>
        auto operator ()(T first, T last, Compare comp = {}) const {
            std::vector<typename Container::key_type> a(first, last);
            std::sort(a.begin(), a.end(), comp);
            auto itr = unique(a.begin(), a.end());
            Container mem;
            int cnt = -1;
            for (auto i = std::begin(a); i != itr; ++i) mem[*i] = ++cnt;
            return mem;
        }
    } compress;
} // namespace kpr
