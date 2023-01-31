#pragma once
#include <cstdint>

#ifndef KYOPRO_BASE_INT
/// @brief 基本符号付き整数型
#define KYOPRO_BASE_INT std::int64_t
#endif

#ifndef KYOPRO_BASE_UINT
/// @brief 基本符号なし整数型
#define KYOPRO_BASE_UINT std::uint64_t
#endif

#ifndef KYOPRO_BASE_FLOAT
/// @brief 基本浮動小数点数型
#define KYOPRO_BASE_FLOAT double
#endif

#ifndef KYOPRO_DEFAULT_MOD
/// @brief 問題で設定されたmod
#define KYOPRO_DEFAULT_MOD (static_cast<KYOPRO_BASE_UINT>(998244353))
#endif

#ifndef KYOPRO_DECIMAL_PRECISION
/// @brief 小数精度(桁)
#define KYOPRO_DECIMAL_PRECISION (static_cast<KYOPRO_BASE_UINT>(12))
#endif

#ifndef KYOPRO_INF_DIV
/// @brief 無限大を表す整数が最大値の何分の一かを表す
#define KYOPRO_INF_DIV (static_cast<KYOPRO_BASE_UINT>(3))
#endif

#ifndef KYOPRO_BUFFER_SIZE
/// @brief デフォルトのバッファサイズ
#define KYOPRO_BUFFER_SIZE (static_cast<KYOPRO_BASE_UINT>(2048))
#endif
