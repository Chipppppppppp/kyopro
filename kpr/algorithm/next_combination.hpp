#pragma once
#include <algorithm>

namespace kpr {
    // 先頭k個を次の組み合わせにして、次の組み合わせが存在するかを返す
    [[maybe_unused]] inline constexpr struct {
        template<class T>
        bool operator ()(T first, T last, int k) {
            T subset = first + k;
            if (first == last || first == subset || last == subset) return false;
            T src = subset;
            while (first != src) {
                --src;
                if (*src < *(last - 1)) {
                    T dest = subset;
                    while (*src >= *dest) ++dest;
                    std::iter_swap(src, dest);
                    std::rotate(src + 1, dest + 1, last);
                    std::rotate(subset, subset + (last - dest) - 1, last);
                    return true;
                }
            }
            std::rotate(first, subset, last);
            return false;
        }
    } next_combination;
} // namespace kpr
