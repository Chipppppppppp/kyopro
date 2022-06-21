---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: meta/settings.hpp
    title: meta/settings.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  - icon: ':warning:'
    path: all/all.hpp
    title: all/all.hpp
  - icon: ':heavy_check_mark:'
    path: math/DynamicModInt.hpp
    title: math/DynamicModInt.hpp
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
  bundledCode: "#line 2 \"math/Montgomery.hpp\"\n#include <cstdint>\n#include <limits>\n\
    #include <type_traits>\n#line 3 \"meta/settings.hpp\"\n\n#ifndef KYOPRO_BASE_INT\n\
    #define KYOPRO_BASE_INT std::int64_t\n#endif\n\n#ifndef KYOPRO_BASE_UINT\n#define\
    \ KYOPRO_BASE_UINT std::uint64_t\n#endif\n\n#ifndef KYOPRO_BASE_FLOAT\n#define\
    \ KYOPRO_BASE_FLOAT double\n#endif\n\n#ifndef KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD\
    \ static_cast<KYOPRO_BASE_UINT>(998244353)\n#endif\n\n#ifndef KYOPRO_DECIMAL_PRECISION\n\
    #define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n#endif\n\n\
    #ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 6 \"math/Montgomery.hpp\"\n\nnamespace kyopro {\n  template<class\
    \ T>\n  struct Montgomery {\n    static_assert(std::is_unsigned_v<T>, \"Unsigned\
    \ integer is required\");\n    using value_type = T;\n\n    T mod;\n\n  private:\n\
    \    using larger_type = uint_least_t<std::numeric_limits<T>::digits * 2>;\n\n\
    \    T r, n2;\n\n  public:\n    constexpr void set_mod(T _mod) noexcept {\n  \
    \    mod = _mod;\n      n2 = -static_cast<larger_type>(mod) % mod;\n      T t\
    \ = 0;\n      r = 0;\n      for (int i = 0; i < std::numeric_limits<T>::digits;\
    \ ++i) {\n        if (!(t & 1)) {\n          t += mod;\n          r += static_cast<T>(1)\
    \ << static_cast<T>(i);\n        }\n        t >>= 1;\n      }\n    }\n\n    constexpr\
    \ KYOPRO_BASE_INT get_mod() const noexcept {\n      return mod;\n    }\n\n   \
    \ Montgomery() noexcept = default;\n    Montgomery(T mod) noexcept {\n      set_mod(mod);\n\
    \    }\n\n    constexpr T transform(T x) const noexcept {\n      return reduce(static_cast<larger_type>(x)\
    \ * n2);\n    }\n\n    constexpr T inverse_transform(T x) const noexcept {\n \
    \     T y = reduce(x);\n      return y >= mod ? y - mod : y;\n    }\n\n    constexpr\
    \ T reduce(larger_type x) const noexcept {\n      return (x + static_cast<larger_type>(static_cast<T>(x)\
    \ * r) * mod) >> std::numeric_limits<T>::digits;\n    }\n  };\n}\n"
  code: "#pragma once\n#include <cstdint>\n#include <limits>\n#include <type_traits>\n\
    #include \"../meta/settings.hpp\"\n\nnamespace kyopro {\n  template<class T>\n\
    \  struct Montgomery {\n    static_assert(std::is_unsigned_v<T>, \"Unsigned integer\
    \ is required\");\n    using value_type = T;\n\n    T mod;\n\n  private:\n   \
    \ using larger_type = uint_least_t<std::numeric_limits<T>::digits * 2>;\n\n  \
    \  T r, n2;\n\n  public:\n    constexpr void set_mod(T _mod) noexcept {\n    \
    \  mod = _mod;\n      n2 = -static_cast<larger_type>(mod) % mod;\n      T t =\
    \ 0;\n      r = 0;\n      for (int i = 0; i < std::numeric_limits<T>::digits;\
    \ ++i) {\n        if (!(t & 1)) {\n          t += mod;\n          r += static_cast<T>(1)\
    \ << static_cast<T>(i);\n        }\n        t >>= 1;\n      }\n    }\n\n    constexpr\
    \ KYOPRO_BASE_INT get_mod() const noexcept {\n      return mod;\n    }\n\n   \
    \ Montgomery() noexcept = default;\n    Montgomery(T mod) noexcept {\n      set_mod(mod);\n\
    \    }\n\n    constexpr T transform(T x) const noexcept {\n      return reduce(static_cast<larger_type>(x)\
    \ * n2);\n    }\n\n    constexpr T inverse_transform(T x) const noexcept {\n \
    \     T y = reduce(x);\n      return y >= mod ? y - mod : y;\n    }\n\n    constexpr\
    \ T reduce(larger_type x) const noexcept {\n      return (x + static_cast<larger_type>(static_cast<T>(x)\
    \ * r) * mod) >> std::numeric_limits<T>::digits;\n    }\n  };\n}"
  dependsOn:
  - meta/settings.hpp
  isVerificationFile: false
  path: math/Montgomery.hpp
  requiredBy:
  - all/all.hpp
  - template/alias.hpp
  - template/all.hpp
  - math/DynamicModInt.hpp
  - math/is_prime.hpp
  - math/factorize.hpp
  - math/all.hpp
  - all.hpp
  timestamp: '2022-06-05 22:20:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/factorize.test.cpp
  - verify/aoj/PrimeNumber.test.cpp
documentation_of: math/Montgomery.hpp
layout: document
redirect_from:
- /library/math/Montgomery.hpp
- /library/math/Montgomery.hpp.html
title: math/Montgomery.hpp
---
