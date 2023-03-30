#pragma once
#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <numeric>
#include <random>
#include <type_traits>
#include "../algorithm/bit.hpp"
#include "../meta/setting.hpp"
#include "DynamicModInt.hpp"
#include "is_prime.hpp"

namespace kpr {
    // 素因数分解
    [[maybe_unused]] inline constexpr struct {
        template<class T>
        constexpr T operator ()(T p, KYOPRO_BASE_UINT c) const {
            using U = std::make_unsigned_t<T>;
            using dmint = DynamicModInt<U, 0, true>;
            U n = p;
            dmint::set_mod(n);
            dmint cc = c;
            auto f = [=](dmint x) noexcept {
                return x * x + cc;
            };
            auto x = dmint::raw(1), y = dmint::raw(2), z = dmint::raw(1), q = dmint::raw(1);
            U g = 1;
            const int m = 1 << (floor_bit(n) / 5);
            for (int r = 1; g == 1; r <<= 1) {
                x = y;
                for (int i = 0; i < r; ++i) y = f(y);
                for (int k = 0; k < r && g == 1; k += m) {
                z = y;
                int min = std::min(m, r - k);
                for (int i = 0; i < min; ++i) {
                    y = f(y);
                    q *= x - y;
                }
                g = std::gcd(static_cast<U>(q), n);
                }
            }
            if (g == n) {
                do {
                z = f(z);
                g = std::gcd(static_cast<U>(x - z), n);
                } while (g == 1);
            }
            return g;
        }
    } pollard_rho;

    [[maybe_unused]] inline constexpr struct {
        KYOPRO_BASE_UINT operator ()(KYOPRO_BASE_UINT n) const noexcept {
            static std::mt19937_64 mt(std::random_device{}());
            std::uniform_int_distribution<std::uint_fast64_t> rnd(0, n - 1);
            if (is_prime(n)) return n;
            for (int i = 0; i < 100; ++i) {
                std::uint_fast64_t m = pollard_rho(n, rnd(mt));
                if (is_prime(m)) return m;
                n = m;
            }
            return 1;
        }
    } find_factor;

    [[maybe_unused]] inline constexpr struct {
        template<bool sorted = true, class Container = std::vector<KYOPRO_BASE_INT>>
        Container operator ()(KYOPRO_BASE_UINT n) const {
            Container res;
            for (int p = 2; p < 100 && p * p <= n; ++p) {
                while (n % p == 0) {
                    n /= p;
                    res.emplace_back(p);
                }
            }
            while (n > 1) {
                std::uint_fast64_t p = find_factor(n);
                do {
                    n /= p;
                    res.emplace_back(p);
                } while (n % p == 0);
            }
            if constexpr (sorted) std::sort(res.begin(), res.end());
            return res;
        }
    } factorize;
} // namespace kpr
