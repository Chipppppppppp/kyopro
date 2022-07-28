#pragma once
#include <utility>

namespace kyopro {
    struct Identity {
        template<class T>
        T&& operator ()(T&& a) const noexcept {
            return std::forward<T>(a);
        }
    };
}