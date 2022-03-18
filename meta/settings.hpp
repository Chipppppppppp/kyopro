#pragma once
#include <cstdint>

#ifndef KYOPRO_BASE_INT
#define KYOPRO_BASE_INT std::int64_t
#endif

#ifndef KYOPRO_BASE_UINT
#define KYOPRO_BASE_UINT std::uint64_t
#endif

#ifndef KYOPRO_BASE_FLOAT
#define KYOPRO_BASE_FLOAT double
#endif

#ifndef KYOPRO_DEFAULT_MOD
#define KYOPRO_DEFAULT_MOD static_cast<KYOPRO_BASE_UINT>(998244353)
#endif

#ifndef KYOPRO_DECIMAL_PRECISION
#define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)
#endif

#ifndef KYOPRO_INF_DIV
#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)
#endif

#ifndef KYOPRO_BUFFER_SIZE
#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)
#endif