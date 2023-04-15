#pragma once
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <limits>
#include <type_traits>
#include <utility>
#include "../algorithm/bit.hpp"
#include "../algorithm/Hash.hpp"
#include "../meta/constant.hpp"
#include "../meta/setting.hpp"
#include "../meta/trait.hpp"
#include "../io/in.hpp"
#include "../io/out.hpp"
#include "mod.hpp"

namespace kpr {
    template<KYOPRO_BASE_UINT m>
    struct ModInt {
        using value_type = uint_least_t<bit_len(m * 2 - 2)>;

        static constexpr value_type mod = m;
        value_type value;

        static constexpr KYOPRO_BASE_INT get_mod() noexcept {
            return mod;
        }

        constexpr ModInt() noexcept = default;
        template<class T>
        constexpr ModInt(T value) noexcept: value(floor_mod(value, mod)) {}

        template<class T>
        explicit constexpr operator T() const noexcept {
            return value;
        }

        static constexpr ModInt raw(value_type value) noexcept {
            ModInt res;
            res.value = value;
            return res;
        }

        constexpr ModInt pow(KYOPRO_BASE_UINT n) const noexcept {
            std::uint_fast64_t res = 1, a = value;
            while (n > 0) {
                if (n & 1) res = res * a % mod;
                a = a * a % mod;
                n >>= 1;
            }
            return res;
        }

        constexpr ModInt inv() const noexcept {
            std::uint_fast64_t a = value, b = mod;
            std::int_fast64_t u = 1, v = 0;
            while (b > 0) {
                std::uint_fast64_t t = a / b;
                a -= t * b;
                std::swap(a, b);
                u -= t * v;
                std::swap(u, v);
            }
            return floor_mod(u, mod);
        }

        constexpr ModInt operator +() const noexcept {
            return *this;
        }

        constexpr ModInt operator -() const noexcept {
            return value == 0 ? 0 : mod - value;
        }

        constexpr ModInt& operator ++() noexcept {
            if (++value >= mod) value -= mod;
            return *this;
        }

        constexpr ModInt operator ++(int) noexcept {
            ModInt before = *this;
            ++*this;
            return before;
        }

        constexpr ModInt& operator --() noexcept {
            if (value == 0) value = mod;
            --value;
            return *this;
        }

        constexpr ModInt operator --(int) noexcept {
            ModInt before = *this;
            --*this;
            return before;
        }

        constexpr ModInt& operator +=(ModInt rhs) noexcept {
            if ((value += rhs.value) >= mod) value -= mod;
            return *this;
        }

        constexpr ModInt& operator -=(ModInt rhs) noexcept {
            if (value < rhs.value) value += mod;
            value -= rhs.value;
            return *this;
        }

        constexpr ModInt& operator *=(ModInt rhs) noexcept {
            value = static_cast<uint_least_t<bit_len(mod) * 2>>(value) * rhs.value % mod;
            return *this;
        }

        constexpr ModInt& operator /=(ModInt rhs) noexcept {
            value = static_cast<uint_least_t<bit_len(mod) * 2>>(value) * rhs.inv().value % mod;
            return *this;
        }

        friend constexpr ModInt operator +(ModInt lhs, ModInt rhs) noexcept {
            return lhs += rhs;
        }

        friend constexpr ModInt operator -(ModInt lhs, ModInt rhs) noexcept {
            return lhs -= rhs;
        }

        friend constexpr ModInt operator *(ModInt lhs, ModInt rhs) noexcept {
            return lhs *= rhs;
        }

        friend constexpr ModInt operator /(ModInt lhs, ModInt rhs) noexcept {
            return lhs /= rhs;
        }

        friend constexpr bool operator ==(ModInt lhs, ModInt rhs) noexcept {
            return lhs.value == rhs.value;
        }

        friend constexpr bool operator !=(ModInt lhs, ModInt rhs) noexcept {
            return lhs.value != rhs.value;
        }

        template<class Scanner>
        void scan(Scanner& scanner) {
            std::int_fast64_t value;
            scanner.scan(value);
            value = floor_mod(value, mod);
        }

        template<class Printer>
        void print(Printer& printer) const {
            printer.print(value);
        }
    };

    template<KYOPRO_BASE_UINT mod>
    struct ScanFunction<ModInt<mod>> {
        template<class Scanner>
        static void scan(Scanner& scanner, ModInt<mod>& a) {
            std::int_fast64_t value;
            ScanFunction<std::int_fast64_t>::scan(scanner, value);
            a.value = floor_mod(value, a.mod);
        }
    };

    template<KYOPRO_BASE_UINT mod>
    struct PrintFunction<ModInt<mod>> {
        template<class Printer>
        static void print(Printer& printer, ModInt<mod> a) {
            PrintFunction<typename ModInt<mod>::value_type>::print(printer, a.value);
        }
    };

    template<KYOPRO_BASE_UINT mod>
    struct Hash<ModInt<mod>> {
        using value_type = ModInt<mod>;
        constexpr std::size_t operator ()(ModInt<mod> a) const noexcept {
            return static_cast<std::size_t>(a);
        }
    };
} // namespace kpr