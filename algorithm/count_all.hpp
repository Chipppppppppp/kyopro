#pragma once
#include <iterator>
#include <unordered_map>
#include "../meta/setting.hpp"

namespace kpr {
    inline constexpr struct {
        template<class T>
        auto operator ()(T first, T last) const {
            std::unordered_map<typename std::iterator_traits<T>::value_type, KYOPRO_BASE_INT> mem;
            for (auto i = first; i != last; ++i) ++mem[*i];
            return mem;
        }
    } count_all;
} // namespace kpr
