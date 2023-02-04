---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: meta/setting.hpp
    title: meta/setting.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  - icon: ':warning:'
    path: all/all.hpp
    title: all/all.hpp
  - icon: ':x:'
    path: math/DynamicModInt.hpp
    title: math/DynamicModInt.hpp
  - icon: ':x:'
    path: math/factorize.hpp
    title: math/factorize.hpp
  - icon: ':x:'
    path: math/is_prime.hpp
    title: math/is_prime.hpp
  - icon: ':warning:'
    path: math/math.hpp
    title: math/math.hpp
  - icon: ':warning:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':warning:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/aoj/PrimeNumber.test.cpp
    title: verify/aoj/PrimeNumber.test.cpp
  - icon: ':x:'
    path: verify/yosupo/factorize.test.cpp
    title: verify/yosupo/factorize.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/Montgomery.hpp\"\n#include <cstdint>\n#include <limits>\n\
    #include <type_traits>\n#line 3 \"meta/setting.hpp\"\n\n#ifndef KYOPRO_BASE_INT\n\
    // \u57FA\u672C\u7B26\u53F7\u4ED8\u304D\u6574\u6570\u578B\n#define KYOPRO_BASE_INT\
    \ std::int64_t\n#endif\n\n#ifndef KYOPRO_BASE_UINT\n// \u57FA\u672C\u7B26\u53F7\
    \u306A\u3057\u6574\u6570\u578B\n#define KYOPRO_BASE_UINT std::uint64_t\n#endif\n\
    \n#ifndef KYOPRO_BASE_FLOAT\n// \u57FA\u672C\u6D6E\u52D5\u5C0F\u6570\u70B9\u6570\
    \u578B\n#define KYOPRO_BASE_FLOAT double\n#endif\n\n#ifndef KYOPRO_DEFAULT_MOD\n\
    // \u554F\u984C\u3067\u8A2D\u5B9A\u3055\u308C\u305Fmod\n#define KYOPRO_DEFAULT_MOD\
    \ (static_cast<KYOPRO_BASE_UINT>(998244353))\n#endif\n\n#ifndef KYOPRO_DECIMAL_PRECISION\n\
    // \u5C0F\u6570\u7CBE\u5EA6(\u6841)\n#define KYOPRO_DECIMAL_PRECISION (static_cast<KYOPRO_BASE_UINT>(12))\n\
    #endif\n\n#ifndef KYOPRO_INF_DIV\n// \u7121\u9650\u5927\u3092\u8868\u3059\u6574\
    \u6570\u304C\u6700\u5927\u5024\u306E\u4F55\u5206\u306E\u4E00\u304B\u3092\u8868\
    \u3059\n#define KYOPRO_INF_DIV (static_cast<KYOPRO_BASE_UINT>(3))\n#endif\n\n\
    #ifndef KYOPRO_BUFFER_SIZE\n// \u30C7\u30D5\u30A9\u30EB\u30C8\u306E\u30D0\u30C3\
    \u30D5\u30A1\u30B5\u30A4\u30BA\n#define KYOPRO_BUFFER_SIZE (static_cast<KYOPRO_BASE_UINT>(2048))\n\
    #endif\n#line 6 \"math/Montgomery.hpp\"\n\nnamespace kpr {\n    template<class\
    \ T>\n    struct Montgomery {\n        static_assert(is_unsigned_integer_v<T>,\
    \ \"The given type must be an unsigned integer type\");\n\n        using value_type\
    \ = T;\n\n        T mod;\n\n    private:\n        using larger_type = next_integer_t<T>;\n\
    \n        T r, n2;\n\n    public:\n        constexpr void set_mod(T mod) noexcept\
    \ {\n            this->mod = mod;\n            n2 = -static_cast<larger_type>(mod)\
    \ % mod;\n            T t = 0;\n            r = 0;\n            for (int i = 0;\
    \ i < std::numeric_limits<T>::digits; ++i) {\n                if (!(t & 1)) {\n\
    \                    t += mod;\n                    r += static_cast<T>(1) <<\
    \ static_cast<T>(i);\n                }\n                t >>= 1;\n          \
    \  }\n        }\n\n        constexpr KYOPRO_BASE_INT get_mod() const noexcept\
    \ {\n            return mod;\n        }\n\n        Montgomery() noexcept = default;\n\
    \        Montgomery(T mod) noexcept {\n            set_mod(mod);\n        }\n\n\
    \        constexpr T transform(T x) const noexcept {\n            return reduce(static_cast<larger_type>(x)\
    \ * n2);\n        }\n\n        constexpr T inverse_transform(T x) const noexcept\
    \ {\n            T y = reduce(x);\n            return y >= mod ? y - mod : y;\n\
    \        }\n\n        constexpr T reduce(larger_type x) const noexcept {\n   \
    \         return (x + static_cast<larger_type>(static_cast<T>(x) * r) * mod) >>\
    \ std::numeric_limits<T>::digits;\n        }\n    };\n} // namespace kpr\n"
  code: "#pragma once\n#include <cstdint>\n#include <limits>\n#include <type_traits>\n\
    #include \"../meta/setting.hpp\"\n\nnamespace kpr {\n    template<class T>\n \
    \   struct Montgomery {\n        static_assert(is_unsigned_integer_v<T>, \"The\
    \ given type must be an unsigned integer type\");\n\n        using value_type\
    \ = T;\n\n        T mod;\n\n    private:\n        using larger_type = next_integer_t<T>;\n\
    \n        T r, n2;\n\n    public:\n        constexpr void set_mod(T mod) noexcept\
    \ {\n            this->mod = mod;\n            n2 = -static_cast<larger_type>(mod)\
    \ % mod;\n            T t = 0;\n            r = 0;\n            for (int i = 0;\
    \ i < std::numeric_limits<T>::digits; ++i) {\n                if (!(t & 1)) {\n\
    \                    t += mod;\n                    r += static_cast<T>(1) <<\
    \ static_cast<T>(i);\n                }\n                t >>= 1;\n          \
    \  }\n        }\n\n        constexpr KYOPRO_BASE_INT get_mod() const noexcept\
    \ {\n            return mod;\n        }\n\n        Montgomery() noexcept = default;\n\
    \        Montgomery(T mod) noexcept {\n            set_mod(mod);\n        }\n\n\
    \        constexpr T transform(T x) const noexcept {\n            return reduce(static_cast<larger_type>(x)\
    \ * n2);\n        }\n\n        constexpr T inverse_transform(T x) const noexcept\
    \ {\n            T y = reduce(x);\n            return y >= mod ? y - mod : y;\n\
    \        }\n\n        constexpr T reduce(larger_type x) const noexcept {\n   \
    \         return (x + static_cast<larger_type>(static_cast<T>(x) * r) * mod) >>\
    \ std::numeric_limits<T>::digits;\n        }\n    };\n} // namespace kpr\n"
  dependsOn:
  - meta/setting.hpp
  isVerificationFile: false
  path: math/Montgomery.hpp
  requiredBy:
  - all/all.hpp
  - template/template.hpp
  - template/alias.hpp
  - math/is_prime.hpp
  - math/math.hpp
  - math/factorize.hpp
  - math/DynamicModInt.hpp
  - all.hpp
  timestamp: '2023-02-01 01:57:29+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/aoj/PrimeNumber.test.cpp
  - verify/yosupo/factorize.test.cpp
documentation_of: math/Montgomery.hpp
layout: document
redirect_from:
- /library/math/Montgomery.hpp
- /library/math/Montgomery.hpp.html
title: math/Montgomery.hpp
---
