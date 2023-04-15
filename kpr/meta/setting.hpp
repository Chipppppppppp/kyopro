#pragma once
#include <cstdint>

#ifndef KYOPRO_BASE_INT
// 基本符号付き整数型
#define KYOPRO_BASE_INT std::int64_t
#endif

#ifndef KYOPRO_BASE_UINT
// 基本符号なし整数型
#define KYOPRO_BASE_UINT std::uint64_t
#endif

#ifndef KYOPRO_BASE_FLOAT
// 基本浮動小数点数型
#define KYOPRO_BASE_FLOAT double
#endif

#ifndef KYOPRO_BASE_MINT
// 基本modint
#define KYOPRO_BASE_MINT kpr::ModInt<mod>
#endif

#ifndef KYOPRO_DEFAULT_MOD
// 問題で設定されたmod
#define KYOPRO_DEFAULT_MOD (static_cast<KYOPRO_BASE_UINT>(998244353))
#endif

#ifndef KYOPRO_DECIMAL_PRECISION
// 小数精度(桁)
#define KYOPRO_DECIMAL_PRECISION (static_cast<KYOPRO_BASE_UINT>(12))
#endif

#ifndef KYOPRO_INF_DIV
// 無限大を表す整数が最大値の何分の一かを表す
#define KYOPRO_INF_DIV (static_cast<KYOPRO_BASE_UINT>(3))
#endif

#ifndef KYOPRO_BUFFER_SIZE
// デフォルトのバッファサイズ
#define KYOPRO_BUFFER_SIZE (static_cast<KYOPRO_BASE_UINT>(2048))
#endif

#ifndef KYOPRO_BINOM_MOD_MAX
// デフォルトのBinomModの計算上限
#define KYOPRO_BINOM_MOD_MAX (static_cast<KYOPRO_BASE_UINT>(1000000))
#endif
