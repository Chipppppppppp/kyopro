#pragma once
#include <cstdint>
#include <limits>
#include <type_traits>
#include "../meta/setting.hpp"

namespace kpr
{
    template <class T>
    struct Montgomery
    {
        static_assert(is_unsigned_integer_v<T>, "The given type must be an unsigned integer type");

        using value_type = T;

        T mod;

    private:
        using larger_type = next_integer_t<T>;

        T r, n2;

    public:
        constexpr void set_mod(T mod) noexcept
        {
            this->mod = mod;
            n2 = -static_cast<larger_type>(mod) % mod;
            T t = 0;
            r = 0;
            for (int i = 0; i < std::numeric_limits<T>::digits; ++i)
            {
                if (!(t & 1))
                {
                    t += mod;
                    r += static_cast<T>(1) << static_cast<T>(i);
                }
                t >>= 1;
            }
        }

        constexpr KYOPRO_BASE_INT get_mod() const noexcept
        {
            return mod;
        }

        Montgomery() noexcept = default;
        Montgomery(T mod) noexcept
        {
            set_mod(mod);
        }

        constexpr T transform(T x) const noexcept
        {
            return reduce(static_cast<larger_type>(x) * n2);
        }

        constexpr T inv_transform(T x) const noexcept
        {
            T y = reduce(x);
            return y >= mod ? y - mod : y;
        }

        constexpr T reduce(larger_type x) const noexcept
        {
            return (x + static_cast<larger_type>(static_cast<T>(x) * r) * mod) >> std::numeric_limits<T>::digits;
        }
    };
} // namespace kpr
