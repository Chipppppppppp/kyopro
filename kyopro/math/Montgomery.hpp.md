---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: kyopro/meta/setting.hpp
    title: kyopro/meta/setting.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: kyopro/all.hpp
    title: kyopro/all.hpp
  - icon: ':warning:'
    path: kyopro/all/all.hpp
    title: kyopro/all/all.hpp
  - icon: ':heavy_check_mark:'
    path: kyopro/math/DynamicModInt.hpp
    title: kyopro/math/DynamicModInt.hpp
  - icon: ':heavy_check_mark:'
    path: kyopro/math/factorize.hpp
    title: kyopro/math/factorize.hpp
  - icon: ':heavy_check_mark:'
    path: kyopro/math/is_prime.hpp
    title: kyopro/math/is_prime.hpp
  - icon: ':warning:'
    path: kyopro/math/math.hpp
    title: kyopro/math/math.hpp
  - icon: ':warning:'
    path: kyopro/template/alias.hpp
    title: kyopro/template/alias.hpp
  - icon: ':warning:'
    path: kyopro/template/template.hpp
    title: kyopro/template/template.hpp
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
  bundledCode: "#line 2 \"kyopro/math/Montgomery.hpp\"\n#include <cstdint>\r\n#include\
    \ <limits>\r\n#include <type_traits>\r\n#line 3 \"kyopro/meta/setting.hpp\"\n\r\
    \n#ifndef KYOPRO_BASE_INT\r\n// \u57FA\u672C\u7B26\u53F7\u4ED8\u304D\u6574\u6570\
    \u578B\r\n#define KYOPRO_BASE_INT std::int64_t\r\n#endif\r\n\r\n#ifndef KYOPRO_BASE_UINT\r\
    \n// \u57FA\u672C\u7B26\u53F7\u306A\u3057\u6574\u6570\u578B\r\n#define KYOPRO_BASE_UINT\
    \ std::uint64_t\r\n#endif\r\n\r\n#ifndef KYOPRO_BASE_FLOAT\r\n// \u57FA\u672C\u6D6E\
    \u52D5\u5C0F\u6570\u70B9\u6570\u578B\r\n#define KYOPRO_BASE_FLOAT double\r\n#endif\r\
    \n\r\n#ifndef KYOPRO_DEFAULT_MOD\r\n// \u554F\u984C\u3067\u8A2D\u5B9A\u3055\u308C\
    \u305Fmod\r\n#define KYOPRO_DEFAULT_MOD (static_cast<KYOPRO_BASE_UINT>(998244353))\r\
    \n#endif\r\n\r\n#ifndef KYOPRO_DECIMAL_PRECISION\r\n// \u5C0F\u6570\u7CBE\u5EA6\
    (\u6841)\r\n#define KYOPRO_DECIMAL_PRECISION (static_cast<KYOPRO_BASE_UINT>(12))\r\
    \n#endif\r\n\r\n#ifndef KYOPRO_INF_DIV\r\n// \u7121\u9650\u5927\u3092\u8868\u3059\
    \u6574\u6570\u304C\u6700\u5927\u5024\u306E\u4F55\u5206\u306E\u4E00\u304B\u3092\
    \u8868\u3059\r\n#define KYOPRO_INF_DIV (static_cast<KYOPRO_BASE_UINT>(3))\r\n\
    #endif\r\n\r\n#ifndef KYOPRO_BUFFER_SIZE\r\n// \u30C7\u30D5\u30A9\u30EB\u30C8\u306E\
    \u30D0\u30C3\u30D5\u30A1\u30B5\u30A4\u30BA\r\n#define KYOPRO_BUFFER_SIZE (static_cast<KYOPRO_BASE_UINT>(2048))\r\
    \n#endif\r\n#line 6 \"kyopro/math/Montgomery.hpp\"\n\r\nnamespace kpr {\r\n  \
    \  template<class T>\r\n    struct Montgomery {\r\n        static_assert(is_unsigned_integer_v<T>,\
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
  - kyopro/meta/setting.hpp
  isVerificationFile: false
  path: kyopro/math/Montgomery.hpp
  requiredBy:
  - kyopro/all/all.hpp
  - kyopro/all.hpp
  - kyopro/math/is_prime.hpp
  - kyopro/math/factorize.hpp
  - kyopro/math/math.hpp
  - kyopro/math/DynamicModInt.hpp
  - kyopro/template/template.hpp
  - kyopro/template/alias.hpp
  timestamp: '2023-04-02 21:40:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/factorize.test.cpp
  - verify/aoj/PrimeNumber.test.cpp
documentation_of: kyopro/math/Montgomery.hpp
layout: document
redirect_from:
- /library/kyopro/math/Montgomery.hpp
- /library/kyopro/math/Montgomery.hpp.html
title: kyopro/math/Montgomery.hpp
---