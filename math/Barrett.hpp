#pragma once
#include <cstdint>
#include <limits>
#include <type_traits>
#include "../meta/setting.hpp"
#include "../meta/trait.hpp"

namespace kyopro {
    // Barrett Reduction
    template<class T>
    struct Barrett {
        static_assert(is_unsigned_integer_v<T>, "The given type must be an unsigned integer type");

        using value_type = T;

        T mod;

    private:
        using larger_type = next_integer_t<T>;

        larger_type m;

    public:
        constexpr void set_mod(T mod) noexcept {
            this->mod = mod;
            m = (static_cast<larger_type>(1) << 64) / mod;
        }

        constexpr KYOPRO_BASE_INT get_mod() const noexcept {
            return mod;
        }

        Barrett() noexcept = default;
        Barrett(T mod) noexcept: mod(mod), m((static_cast<larger_type>(1) << 64) / mod) {}

        constexpr T reduce(T x) const noexcept {
            x -= static_cast<T>((x * m) >> 64) * mod;
            return x < mod ? x : x - mod;
        }
    };
} // namespace kpr
