---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: function/function.hpp
    title: function/function.hpp
  - icon: ':warning:'
    path: function/monoid.hpp
    title: function/monoid.hpp
  - icon: ':warning:'
    path: math/DynamicModInt.hpp
    title: math/DynamicModInt.hpp
  - icon: ':warning:'
    path: math/ModInt.hpp
    title: math/ModInt.hpp
  - icon: ':warning:'
    path: math/factorize.hpp
    title: math/factorize.hpp
  - icon: ':warning:'
    path: math/is_prime.hpp
    title: math/is_prime.hpp
  - icon: ':warning:'
    path: math/math.hpp
    title: math/math.hpp
  - icon: ':warning:'
    path: meta/constant.hpp
    title: meta/constant.hpp
  - icon: ':warning:'
    path: meta/meta.hpp
    title: meta/meta.hpp
  - icon: ':warning:'
    path: structure/FenwickTree.hpp
    title: structure/FenwickTree.hpp
  - icon: ':warning:'
    path: structure/structure.hpp
    title: structure/structure.hpp
  - icon: ':warning:'
    path: system/in.hpp
    title: system/in.hpp
  - icon: ':warning:'
    path: template/alias.hpp
    title: template/alias.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/power.hpp\"\n#include <cstdint>\n\nnamespace kpr {\n\
    \    [[maybe_unused]] inline constexpr struct {\n        template<class T>\n \
    \       constexpr T operator ()(T a, std::uint_fast64_t n, T init = 1) const noexcept\
    \ {\n            while (n > 0) {\n                if (n & 1) init *= a;\n    \
    \            a *= a;\n                n >>= 1;\n            }\n            return\
    \ init;\n        }\n    } power;\n} // namespace kpr\n"
  code: "#pragma once\n#include <cstdint>\n\nnamespace kpr {\n    [[maybe_unused]]\
    \ inline constexpr struct {\n        template<class T>\n        constexpr T operator\
    \ ()(T a, std::uint_fast64_t n, T init = 1) const noexcept {\n            while\
    \ (n > 0) {\n                if (n & 1) init *= a;\n                a *= a;\n\
    \                n >>= 1;\n            }\n            return init;\n        }\n\
    \    } power;\n} // namespace kpr\n"
  dependsOn: []
  isVerificationFile: false
  path: math/power.hpp
  requiredBy:
  - meta/constant.hpp
  - meta/meta.hpp
  - system/in.hpp
  - function/monoid.hpp
  - function/function.hpp
  - template/alias.hpp
  - structure/structure.hpp
  - structure/FenwickTree.hpp
  - math/ModInt.hpp
  - math/is_prime.hpp
  - math/math.hpp
  - math/factorize.hpp
  - math/DynamicModInt.hpp
  timestamp: '2023-02-01 00:00:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/power.hpp
layout: document
redirect_from:
- /library/math/power.hpp
- /library/math/power.hpp.html
title: math/power.hpp
---
