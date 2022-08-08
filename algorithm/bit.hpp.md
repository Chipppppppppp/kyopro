---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: meta/settings.hpp
    title: meta/settings.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: algorithm/all.hpp
    title: algorithm/all.hpp
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  - icon: ':warning:'
    path: all/all.hpp
    title: all/all.hpp
  - icon: ':warning:'
    path: math/ModInt.hpp
    title: math/ModInt.hpp
  - icon: ':warning:'
    path: math/all.hpp
    title: math/all.hpp
  - icon: ':heavy_check_mark:'
    path: math/factorize.hpp
    title: math/factorize.hpp
  - icon: ':heavy_check_mark:'
    path: math/is_prime.hpp
    title: math/is_prime.hpp
  - icon: ':warning:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':warning:'
    path: template/all.hpp
    title: template/all.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/PrimeNumber.test.cpp
    title: verify/aoj/PrimeNumber.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/factorize.test.cpp
    title: verify/yosupo/factorize.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algorithm/bit.hpp\"\n#include <limits>\n#include <type_traits>\n\
    #line 2 \"meta/settings.hpp\"\n#include <cstdint>\n\n#ifndef KYOPRO_BASE_INT\n\
    #define KYOPRO_BASE_INT std::int64_t\n#endif\n\n#ifndef KYOPRO_BASE_UINT\n#define\
    \ KYOPRO_BASE_UINT std::uint64_t\n#endif\n\n#ifndef KYOPRO_BASE_FLOAT\n#define\
    \ KYOPRO_BASE_FLOAT double\n#endif\n\n#ifndef KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD\
    \ static_cast<KYOPRO_BASE_UINT>(998244353)\n#endif\n\n#ifndef KYOPRO_DECIMAL_PRECISION\n\
    #define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n#endif\n\n\
    #ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 5 \"algorithm/bit.hpp\"\n\nnamespace kyopro {\n    inline constexpr\
    \ struct {\n        template<class T>\n        constexpr KYOPRO_BASE_INT operator\
    \ ()(T x) const noexcept {\n            constexpr auto digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;\n\
    \            static_assert(digits <= std::numeric_limits<unsigned long long>::digits,\
    \ \"Integer size is too large\");\n            if constexpr (digits <= std::numeric_limits<unsigned\
    \ int>::digits) return __builtin_popcount(x);\n            else if constexpr (digits\
    \ <= std::numeric_limits<unsigned long>::digits) return __builtin_popcountl(x);\n\
    \            else return __builtin_popcountll(x);\n        }\n    } pop_count;\n\
    \n    inline constexpr struct {\n        template<class T>\n        constexpr\
    \ KYOPRO_BASE_INT operator ()(T x) const noexcept {\n            constexpr auto\
    \ digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;\n           \
    \ static_assert(digits <= std::numeric_limits<unsigned long long>::digits, \"\
    Integer size is too large\");\n            if (x == 0) return 0;\n           \
    \ if constexpr (digits <= std::numeric_limits<unsigned int>::digits) return __builtin_clz(x)\
    \ + digits - std::numeric_limits<unsigned int>::digits;\n            else if constexpr\
    \ (digits <= std::numeric_limits<unsigned long>::digits) return __builtin_clzl(x)\
    \ + digits - std::numeric_limits<unsigned long>::digits;\n            else return\
    \ __builtin_clzll(x) + digits - std::numeric_limits<unsigned long long>::digits;\n\
    \        }\n    } leading_zero;\n\n    inline constexpr struct {\n        template<class\
    \ T>\n        constexpr KYOPRO_BASE_INT operator ()(T x) const noexcept {\n  \
    \          constexpr auto digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;\n\
    \            static_assert(digits <= std::numeric_limits<unsigned long long>::digits,\
    \ \"Integer size is too large\");\n            if constexpr (digits <= std::numeric_limits<unsigned\
    \ int>::digits) return __builtin_ctz(x);\n            else if constexpr (digits\
    \ <= std::numeric_limits<unsigned long>::digits) return __builtin_ctzl(x);\n \
    \           else return __builtin_ctzll(x);\n        }\n    } trailing_zero;\n\
    \n    inline constexpr struct {\n        template<class T>\n        constexpr\
    \ KYOPRO_BASE_INT operator ()(T x) const noexcept {\n            constexpr auto\
    \ digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;\n           \
    \ static_assert(digits <= std::numeric_limits<unsigned long long>::digits, \"\
    Integer size is too large\");\n            if (x == 0) return 0;\n           \
    \ if constexpr (digits <= std::numeric_limits<unsigned int>::digits) return std::numeric_limits<unsigned\
    \ int>::digits - __builtin_clz(x);\n            else if constexpr (digits <= std::numeric_limits<unsigned\
    \ long>::digits) return std::numeric_limits<unsigned long>::digits - __builtin_clzl(x);\n\
    \            else return std::numeric_limits<unsigned long long>::digits - __builtin_clzll(x);\n\
    \        }\n    } bit_len;\n\n    inline constexpr struct {\n        template<class\
    \ T>\n        constexpr KYOPRO_BASE_INT operator ()(T x) const noexcept {\n  \
    \          return bit_len(x >> static_cast<T>(1));\n        }\n    } floor_bit;\n\
    \n    inline constexpr struct {\n        template<class T>\n        constexpr\
    \ KYOPRO_BASE_INT operator ()(T x) const noexcept {\n            if (x == 0) return\
    \ 0;\n            return bit_len(x - static_cast<T>(1));\n        }\n    } ceil_bit;\n\
    } // namespace kyopro\n"
  code: "#pragma once\n#include <limits>\n#include <type_traits>\n#include \"../meta/settings.hpp\"\
    \n\nnamespace kyopro {\n    inline constexpr struct {\n        template<class\
    \ T>\n        constexpr KYOPRO_BASE_INT operator ()(T x) const noexcept {\n  \
    \          constexpr auto digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;\n\
    \            static_assert(digits <= std::numeric_limits<unsigned long long>::digits,\
    \ \"Integer size is too large\");\n            if constexpr (digits <= std::numeric_limits<unsigned\
    \ int>::digits) return __builtin_popcount(x);\n            else if constexpr (digits\
    \ <= std::numeric_limits<unsigned long>::digits) return __builtin_popcountl(x);\n\
    \            else return __builtin_popcountll(x);\n        }\n    } pop_count;\n\
    \n    inline constexpr struct {\n        template<class T>\n        constexpr\
    \ KYOPRO_BASE_INT operator ()(T x) const noexcept {\n            constexpr auto\
    \ digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;\n           \
    \ static_assert(digits <= std::numeric_limits<unsigned long long>::digits, \"\
    Integer size is too large\");\n            if (x == 0) return 0;\n           \
    \ if constexpr (digits <= std::numeric_limits<unsigned int>::digits) return __builtin_clz(x)\
    \ + digits - std::numeric_limits<unsigned int>::digits;\n            else if constexpr\
    \ (digits <= std::numeric_limits<unsigned long>::digits) return __builtin_clzl(x)\
    \ + digits - std::numeric_limits<unsigned long>::digits;\n            else return\
    \ __builtin_clzll(x) + digits - std::numeric_limits<unsigned long long>::digits;\n\
    \        }\n    } leading_zero;\n\n    inline constexpr struct {\n        template<class\
    \ T>\n        constexpr KYOPRO_BASE_INT operator ()(T x) const noexcept {\n  \
    \          constexpr auto digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;\n\
    \            static_assert(digits <= std::numeric_limits<unsigned long long>::digits,\
    \ \"Integer size is too large\");\n            if constexpr (digits <= std::numeric_limits<unsigned\
    \ int>::digits) return __builtin_ctz(x);\n            else if constexpr (digits\
    \ <= std::numeric_limits<unsigned long>::digits) return __builtin_ctzl(x);\n \
    \           else return __builtin_ctzll(x);\n        }\n    } trailing_zero;\n\
    \n    inline constexpr struct {\n        template<class T>\n        constexpr\
    \ KYOPRO_BASE_INT operator ()(T x) const noexcept {\n            constexpr auto\
    \ digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;\n           \
    \ static_assert(digits <= std::numeric_limits<unsigned long long>::digits, \"\
    Integer size is too large\");\n            if (x == 0) return 0;\n           \
    \ if constexpr (digits <= std::numeric_limits<unsigned int>::digits) return std::numeric_limits<unsigned\
    \ int>::digits - __builtin_clz(x);\n            else if constexpr (digits <= std::numeric_limits<unsigned\
    \ long>::digits) return std::numeric_limits<unsigned long>::digits - __builtin_clzl(x);\n\
    \            else return std::numeric_limits<unsigned long long>::digits - __builtin_clzll(x);\n\
    \        }\n    } bit_len;\n\n    inline constexpr struct {\n        template<class\
    \ T>\n        constexpr KYOPRO_BASE_INT operator ()(T x) const noexcept {\n  \
    \          return bit_len(x >> static_cast<T>(1));\n        }\n    } floor_bit;\n\
    \n    inline constexpr struct {\n        template<class T>\n        constexpr\
    \ KYOPRO_BASE_INT operator ()(T x) const noexcept {\n            if (x == 0) return\
    \ 0;\n            return bit_len(x - static_cast<T>(1));\n        }\n    } ceil_bit;\n\
    } // namespace kyopro"
  dependsOn:
  - meta/settings.hpp
  isVerificationFile: false
  path: algorithm/bit.hpp
  requiredBy:
  - all/all.hpp
  - math/ModInt.hpp
  - math/all.hpp
  - math/factorize.hpp
  - math/is_prime.hpp
  - all.hpp
  - algorithm/all.hpp
  - template/all.hpp
  - template/alias.hpp
  timestamp: '2022-07-28 17:38:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/PrimeNumber.test.cpp
  - verify/yosupo/factorize.test.cpp
documentation_of: algorithm/bit.hpp
layout: document
redirect_from:
- /library/algorithm/bit.hpp
- /library/algorithm/bit.hpp.html
title: algorithm/bit.hpp
---
