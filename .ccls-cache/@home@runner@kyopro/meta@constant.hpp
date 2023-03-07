#pragma once
#include <limits>
#include "../math/power.hpp"
#include "setting.hpp"

namespace kpr {
    // 問題で設定されたmod
    template<class T>
    inline constexpr T MOD = KYOPRO_DEFAULT_MOD;
    // 問題で設定されたmod
    inline constexpr KYOPRO_BASE_INT mod = MOD<KYOPRO_BASE_INT>;

    // 無限大を表す整数
    template<class T>
    inline constexpr T INF = std::numeric_limits<T>::max() / KYOPRO_INF_DIV;
    // 無限大を表す整数
    inline constexpr KYOPRO_BASE_INT inf = INF<KYOPRO_BASE_INT>;

    // 許容される小数誤差
    template<class T, KYOPRO_BASE_UINT decimal_precision = KYOPRO_DECIMAL_PRECISION>
    inline constexpr KYOPRO_BASE_FLOAT EPS = static_cast<T>(1) / power(10ULL, decimal_precision);
    // 許容される小数誤差
    inline constexpr KYOPRO_BASE_FLOAT eps = EPS<KYOPRO_BASE_FLOAT>;

    // 円周率
    template<class T>
    inline constexpr T PI = 3.14159265358979323846;
    // 円周率
    inline constexpr KYOPRO_BASE_FLOAT pi = PI<KYOPRO_BASE_FLOAT>;
} // namespace kpr
