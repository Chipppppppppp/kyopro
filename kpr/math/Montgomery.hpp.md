---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: kpr/meta/setting.hpp
    title: kpr/meta/setting.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: kpr/all.hpp
    title: kpr/all.hpp
  - icon: ':warning:'
    path: kpr/all/all.hpp
    title: kpr/all/all.hpp
  - icon: ':heavy_check_mark:'
    path: kpr/math/DynamicModInt.hpp
    title: kpr/math/DynamicModInt.hpp
  - icon: ':heavy_check_mark:'
    path: kpr/math/factorize.hpp
    title: kpr/math/factorize.hpp
  - icon: ':heavy_check_mark:'
    path: kpr/math/is_prime.hpp
    title: kpr/math/is_prime.hpp
  - icon: ':warning:'
    path: kpr/math/math.hpp
    title: kpr/math/math.hpp
  - icon: ':warning:'
    path: kpr/template/alias.hpp
    title: kpr/template/alias.hpp
  - icon: ':warning:'
    path: kpr/template/template.hpp
    title: kpr/template/template.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/factorize.test.cpp
    title: verify/yosupo/factorize.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"kpr/math/Montgomery.hpp\"\n#include <cstdint>\r\n#include\
    \ <limits>\r\n#include <type_traits>\r\n#line 3 \"kpr/meta/setting.hpp\"\n\r\n\
    #ifndef KYOPRO_BASE_INT\r\n// \u57FA\u672C\u7B26\u53F7\u4ED8\u304D\u6574\u6570\
    \u578B\r\n#define KYOPRO_BASE_INT std::int64_t\r\n#endif\r\n\r\n#ifndef KYOPRO_BASE_UINT\r\
    \n// \u57FA\u672C\u7B26\u53F7\u306A\u3057\u6574\u6570\u578B\r\n#define KYOPRO_BASE_UINT\
    \ std::uint64_t\r\n#endif\r\n\r\n#ifndef KYOPRO_BASE_FLOAT\r\n// \u57FA\u672C\u6D6E\
    \u52D5\u5C0F\u6570\u70B9\u6570\u578B\r\n#define KYOPRO_BASE_FLOAT double\r\n#endif\r\
    \n\r\n#ifndef KYOPRO_LL\r\n// ll\r\n#define KYOPRO_LL long long\r\n#endif\r\n\r\
    \n#ifndef KYOPRO_LF\r\n// lf\r\n#define KYOPRO_LF double\r\n#endif\r\n\r\n#ifndef\
    \ KYOPRO_MINT\r\n// mint\r\n#define KYOPRO_MINT kpr::ModInt<mod>\r\n#endif\r\n\
    \r\n#ifndef KYOPRO_DEFAULT_MOD\r\n// \u554F\u984C\u3067\u8A2D\u5B9A\u3055\u308C\
    \u305Fmod\r\n#define KYOPRO_DEFAULT_MOD (static_cast<KYOPRO_BASE_UINT>(998244353))\r\
    \n#endif\r\n\r\n#ifndef KYOPRO_DECIMAL_PRECISION\r\n// \u5C0F\u6570\u7CBE\u5EA6\
    (\u6841)\r\n#define KYOPRO_DECIMAL_PRECISION (static_cast<KYOPRO_BASE_UINT>(12))\r\
    \n#endif\r\n\r\n#ifndef KYOPRO_INF_DIV\r\n// \u7121\u9650\u5927\u3092\u8868\u3059\
    \u6574\u6570\u304C\u6700\u5927\u5024\u306E\u4F55\u5206\u306E\u4E00\u304B\u3092\
    \u8868\u3059\r\n#define KYOPRO_INF_DIV (static_cast<KYOPRO_BASE_UINT>(3))\r\n\
    #endif\r\n\r\n#ifndef KYOPRO_BUFFER_SIZE\r\n// \u30C7\u30D5\u30A9\u30EB\u30C8\u306E\
    \u30D0\u30C3\u30D5\u30A1\u30B5\u30A4\u30BA\r\n#define KYOPRO_BUFFER_SIZE (static_cast<KYOPRO_BASE_UINT>(2048))\r\
    \n#endif\r\n\r\n#ifndef KYOPRO_BINOM_MOD_MAX\r\n// \u30C7\u30D5\u30A9\u30EB\u30C8\
    \u306EBinomMod\u306E\u8A08\u7B97\u4E0A\u9650\r\n#define KYOPRO_BINOM_MOD_MAX (static_cast<KYOPRO_BASE_UINT>(1000000))\r\
    \n#endif\r\n#line 6 \"kpr/math/Montgomery.hpp\"\n\r\nnamespace kpr {\r\n    template<class\
    \ T>\r\n    struct Montgomery {\r\n        static_assert(is_unsigned_integer_v<T>,\
    \ \"The given type must be an unsigned integer type\");\r\n\r\n        using value_type\
    \ = T;\r\n\r\n        T mod;\r\n\r\n    private:\r\n        using larger_type\
    \ = next_integer_t<T>;\r\n\r\n        T r, n2;\r\n\r\n    public:\r\n        constexpr\
    \ void set_mod(T mod) noexcept {\r\n            this->mod = mod;\r\n         \
    \   n2 = -static_cast<larger_type>(mod) % mod;\r\n            T t = 0;\r\n   \
    \         r = 0;\r\n            for (int i = 0; i < std::numeric_limits<T>::digits;\
    \ ++i) {\r\n                if (!(t & 1)) {\r\n                    t += mod;\r\
    \n                    r += static_cast<T>(1) << static_cast<T>(i);\r\n       \
    \         }\r\n                t >>= 1;\r\n            }\r\n        }\r\n\r\n\
    \        constexpr KYOPRO_BASE_INT get_mod() const noexcept {\r\n            return\
    \ mod;\r\n        }\r\n\r\n        Montgomery() noexcept = default;\r\n      \
    \  Montgomery(T mod) noexcept {\r\n            set_mod(mod);\r\n        }\r\n\r\
    \n        constexpr T transform(T x) const noexcept {\r\n            return reduce(static_cast<larger_type>(x)\
    \ * n2);\r\n        }\r\n\r\n        constexpr T inv_transform(T x) const noexcept\
    \ {\r\n            T y = reduce(x);\r\n            return y >= mod ? y - mod :\
    \ y;\r\n        }\r\n\r\n        constexpr T reduce(larger_type x) const noexcept\
    \ {\r\n            return (x + static_cast<larger_type>(static_cast<T>(x) * r)\
    \ * mod) >> std::numeric_limits<T>::digits;\r\n        }\r\n    };\r\n} // namespace\
    \ kpr\r\n"
  code: "#pragma once\r\n#include <cstdint>\r\n#include <limits>\r\n#include <type_traits>\r\
    \n#include \"../meta/setting.hpp\"\r\n\r\nnamespace kpr {\r\n    template<class\
    \ T>\r\n    struct Montgomery {\r\n        static_assert(is_unsigned_integer_v<T>,\
    \ \"The given type must be an unsigned integer type\");\r\n\r\n        using value_type\
    \ = T;\r\n\r\n        T mod;\r\n\r\n    private:\r\n        using larger_type\
    \ = next_integer_t<T>;\r\n\r\n        T r, n2;\r\n\r\n    public:\r\n        constexpr\
    \ void set_mod(T mod) noexcept {\r\n            this->mod = mod;\r\n         \
    \   n2 = -static_cast<larger_type>(mod) % mod;\r\n            T t = 0;\r\n   \
    \         r = 0;\r\n            for (int i = 0; i < std::numeric_limits<T>::digits;\
    \ ++i) {\r\n                if (!(t & 1)) {\r\n                    t += mod;\r\
    \n                    r += static_cast<T>(1) << static_cast<T>(i);\r\n       \
    \         }\r\n                t >>= 1;\r\n            }\r\n        }\r\n\r\n\
    \        constexpr KYOPRO_BASE_INT get_mod() const noexcept {\r\n            return\
    \ mod;\r\n        }\r\n\r\n        Montgomery() noexcept = default;\r\n      \
    \  Montgomery(T mod) noexcept {\r\n            set_mod(mod);\r\n        }\r\n\r\
    \n        constexpr T transform(T x) const noexcept {\r\n            return reduce(static_cast<larger_type>(x)\
    \ * n2);\r\n        }\r\n\r\n        constexpr T inv_transform(T x) const noexcept\
    \ {\r\n            T y = reduce(x);\r\n            return y >= mod ? y - mod :\
    \ y;\r\n        }\r\n\r\n        constexpr T reduce(larger_type x) const noexcept\
    \ {\r\n            return (x + static_cast<larger_type>(static_cast<T>(x) * r)\
    \ * mod) >> std::numeric_limits<T>::digits;\r\n        }\r\n    };\r\n} // namespace\
    \ kpr\r\n"
  dependsOn:
  - kpr/meta/setting.hpp
  isVerificationFile: false
  path: kpr/math/Montgomery.hpp
  requiredBy:
  - kpr/template/alias.hpp
  - kpr/template/template.hpp
  - kpr/math/is_prime.hpp
  - kpr/math/DynamicModInt.hpp
  - kpr/math/factorize.hpp
  - kpr/math/math.hpp
  - kpr/all/all.hpp
  - kpr/all.hpp
  timestamp: '2023-05-30 09:27:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/factorize.test.cpp
documentation_of: kpr/math/Montgomery.hpp
layout: document
redirect_from:
- /library/kpr/math/Montgomery.hpp
- /library/kpr/math/Montgomery.hpp.html
title: kpr/math/Montgomery.hpp
---