#pragma once
#include <cstddef>
#include <cstdint>
#include <limits>
#include <type_traits>
#include "../algorithm/Hash.hpp"
#include "../meta/constant.hpp"
#include "../meta/setting.hpp"
#include "../meta/trait.hpp"
#include "../io/in.hpp"
#include "../io/out.hpp"
#include "Montgomery.hpp"

namespace kpr {
    template<class T, std::size_t kind = 0, bool = false>
    struct DynamicModInt {
        static_assert(std::is_unsigned_v<T>, "The given type must be an unsigned integer type");

        using value_type = T;

    private:
        using larger_type = next_integer_t<T>;

        inline static Montgomery<T> montgomery;

    public:
        T value;

        static constexpr KYOPRO_BASE_INT get_kind() noexcept {
            return kind;
        }

        static void set_mod(T mod) noexcept {
            montgomery.set_mod(mod);
        }

        static KYOPRO_BASE_INT get_mod() noexcept {
            return montgomery.mod;
        }

        KYOPRO_BASE_INT get_val() noexcept {
            return montgomery.inv_transform(value);
        }

        DynamicModInt() noexcept = default;
        DynamicModInt(T value) noexcept: value(montgomery.transform(value % montgomery.mod + montgomery.mod)) {}

        template<class U>
        explicit operator U() const noexcept {
            return montgomery.inv_transform(value);
        }

        static DynamicModInt raw(T value) noexcept {
            DynamicModInt res;
            res.value = montgomery.transform(value);
            return res;
        }

        DynamicModInt pow(std::uint_fast64_t n) const noexcept {
            DynamicModInt res = 1, a = *this;
            while (n > 0) {
                if (n & 1) res = res * a;
                a = a * a;
                n >>= 1;
            }
            return res;
        }

        DynamicModInt inv() const noexcept {
            return pow(montgomery.mod - 2);
        }

        DynamicModInt operator +() const noexcept {
            return *this;
        }

        DynamicModInt operator -() const noexcept {
            return value == 0 ? 0 : montgomery.mod - value;
        }

        DynamicModInt& operator ++() noexcept {
            *this += DynamicModInt::raw(1);
            return *this;
        }

        DynamicModInt operator ++(int) noexcept {
            DynamicModInt before = *this;
            ++*this;
            return before;
        }

        DynamicModInt& operator --() noexcept {
            *this -= DynamicModInt::raw(1);
            return *this;
        }

        DynamicModInt operator --(int) noexcept {
            DynamicModInt before = *this;
            --*this;
            return before;
        }

        DynamicModInt& operator +=(DynamicModInt rhs) noexcept {
            if ((value += rhs.value - (montgomery.mod << 1)) > std::numeric_limits<std::make_signed_t<T>>::max()) value += montgomery.mod << 1;
            return *this;
        }

        DynamicModInt& operator -=(DynamicModInt rhs) noexcept {
            if ((value -= rhs.value) > std::numeric_limits<std::make_signed_t<T>>::max()) value += montgomery.mod << 1;
            return *this;
        }

        DynamicModInt& operator *=(DynamicModInt rhs) noexcept {
            value = montgomery.reduce(static_cast<larger_type>(value) * rhs.value);
            return *this;
        }

        DynamicModInt& operator /=(DynamicModInt rhs) noexcept {
            value = montgomery.reduce(static_cast<larger_type>(value) * rhs.inv().value);
            return *this;
        }

        friend DynamicModInt operator +(DynamicModInt lhs, DynamicModInt rhs) noexcept {
            return lhs += rhs;
        }

        friend DynamicModInt operator -(DynamicModInt lhs, DynamicModInt rhs) noexcept {
            return lhs -= rhs;
        }

        friend DynamicModInt operator *(DynamicModInt lhs, DynamicModInt rhs) noexcept {
            return lhs *= rhs;
        }

        friend DynamicModInt operator /(DynamicModInt lhs, DynamicModInt rhs) noexcept {
            return lhs /= rhs;
        }

        friend bool operator ==(DynamicModInt lhs, DynamicModInt rhs) noexcept {
            return lhs.value == rhs.value;
        }

        friend bool operator !=(DynamicModInt lhs, DynamicModInt rhs) noexcept {
            return lhs.value != rhs.value;
        }

        friend struct ScanFunction<DynamicModInt>;

        friend struct PrintFunction<DynamicModInt>;
    };

    template<class T, std::size_t kind>
    struct ScanFunction<DynamicModInt<T, kind>> {
        template<class Scanner>
        static void scan(Scanner& scanner, DynamicModInt<T, kind>& a) {
            std::int_fast64_t value;
            ScanFunction<std::int_fast64_t>::scan(scanner, value);
            a.value = a.montgomery.transform(value % a.montgomery.mod + a.montgomery.mod);
        }
    };

    template<class T, std::size_t kind>
    struct PrintFunction<DynamicModInt<T, kind>> {
        template<class Printer>
        static void print(Printer& printer, const DynamicModInt<T, kind>& a) {
            PrintFunction<T>::print(printer, a.montgomery.inv_transform(a.value));
        }
    };

    template<class T, std::size_t kind>
    struct Hash<DynamicModInt<T, kind>> {
        using value_type = DynamicModInt<T, kind>;

        std::size_t operator ()(DynamicModInt<T, kind> a) const noexcept {
            return static_cast<std::size_t>(a);
        }
    };
} // namespace kpr
