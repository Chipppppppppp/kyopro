#pragma once
#include <cstdint>
#include <type_traits>
#include <utility>
#include "../meta/tuple_like.hpp"

namespace kpr {
    template<class Derived>
    struct BaseVals {
        template<std::size_t i = 0, class T>
        BaseVals(T&& vals) noexcept {
            if constexpr (i < 1) {
                get<i>(static_cast<Derived&>(*this)) = get<i>(vals);
                BaseVals<Derived>::BaseVals<i + 1>(std::forward<T>(vals));
            }
        }
    };
}

#define KYOPRO_VALS0(name0, value0) \
    ([&] { \
        struct NamedTuple: kpr::BaseVals<NamedTuple> { \
            decltype(value0) name0; \
            using BaseVals<NamedTuple>::BaseVals; \
        }; \
        return NamedTuple{value0}; \
    })()
