#pragma once
#include <algorithm>
#include <functional>
#include <iterator>
#include <type_traits>
#include <unordered_map>
#include <utility>
#include <vector>
#include "../function/compare.hpp"
#include "../function/identity.hpp"
#include "../meta/settings.hpp"
#include "../meta/trait.hpp"

namespace kyopro::range {
    inline constexpr struct {
        template<class Container = void, class T, class Proj = Identity, class Compare = Less>
        constexpr auto operator ()(T range, const Proj& proj = {}, const Compare& comp = {}) const {
            sort(std::begin(range), std::end(range), proj, comp);
            auto end = std::unique(std::begin(range), std::end(range));
            std::conditional_t<std::is_same_v<Container, void>, std::unordered_map<typename std::iterator_traits<Iterator>::value_type, KYOPRO_BASE_INT>, Container> mem;
            int cnt = 0;
            for (auto i = std::begin(range); i != end; ++i) mem[*i] = cnt++;
            return mem;
        }
    } compress;

    inline constexpr struct {
        template<class T, class Proj = Identity>
        constexpr bool operator ()(T&& range, const Proj& proj = {}) const {
            return std::all_of(std::begin(range), std::end(range), proj);
        }
    } all_of;

    inline constexpr struct {
        template<class T, class Proj = Identity>
        constexpr bool operator ()(T&& range, const Proj& proj = {}) const {
            return std::any_of(std::begin(range), std::end(range), proj);
        }
    } any_of;

    inline constexpr struct {
        template<class T, class Proj = Identity>
        constexpr bool operator ()(T&& range, const Proj& proj = {}) const {
            return std::none_of(std::begin(range), std::end(range), proj);
        }
    } none_of;

    inline constexpr struct {
        template<class T, class Func, class Proj = Identity>
        constexpr auto operator ()(T&& range, const Func& func, const Proj& proj = {}) const {
            return std::for_each(std::begin(range), std::end(range), func);
        }
    } for_each;
} // namespace kyopro::range