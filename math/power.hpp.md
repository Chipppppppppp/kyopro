---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  - icon: ':warning:'
    path: all/all.hpp
    title: all/all.hpp
  - icon: ':warning:'
    path: data_structure/FenwickTree.hpp
    title: data_structure/FenwickTree.hpp
  - icon: ':warning:'
    path: data_structure/data_structure.hpp
    title: data_structure/data_structure.hpp
  - icon: ':warning:'
    path: data_structure/structure.hpp
    title: data_structure/structure.hpp
  - icon: ':warning:'
    path: function/function.hpp
    title: function/function.hpp
  - icon: ':warning:'
    path: function/monoid.hpp
    title: function/monoid.hpp
  - icon: ':heavy_check_mark:'
    path: math/DynamicModInt.hpp
    title: math/DynamicModInt.hpp
  - icon: ':warning:'
    path: math/ModInt.hpp
    title: math/ModInt.hpp
  - icon: ':heavy_check_mark:'
    path: math/factorize.hpp
    title: math/factorize.hpp
  - icon: ':heavy_check_mark:'
    path: math/is_prime.hpp
    title: math/is_prime.hpp
  - icon: ':warning:'
    path: math/math.hpp
    title: math/math.hpp
  - icon: ':heavy_check_mark:'
    path: meta/constant.hpp
    title: meta/constant.hpp
  - icon: ':warning:'
    path: meta/meta.hpp
    title: meta/meta.hpp
  - icon: ':heavy_check_mark:'
    path: system/in.hpp
    title: system/in.hpp
  - icon: ':heavy_check_mark:'
    path: system/system.hpp
    title: system/system.hpp
  - icon: ':warning:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':warning:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':warning:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':warning:'
    path: verify/hello_world.cpp
    title: verify/hello_world.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/PrimeNumber.test.cpp
    title: verify/aoj/PrimeNumber.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/factorize.test.cpp
    title: verify/yosupo/factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/many_aplusb.test.cpp
    title: verify/yosupo/many_aplusb.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/power.hpp\"\n#include <cstdint>\r\n\r\nnamespace kpr\
    \ {\r\n    [[maybe_unused]] inline constexpr struct {\r\n        template<class\
    \ T>\r\n        constexpr T operator ()(T a, std::uint_fast64_t n, T init = 1)\
    \ const noexcept {\r\n            while (n > 0) {\r\n                if (n & 1)\
    \ init *= a;\r\n                a *= a;\r\n                n >>= 1;\r\n      \
    \      }\r\n            return init;\r\n        }\r\n    } power;\r\n} // namespace\
    \ kpr\r\n"
  code: "#pragma once\r\n#include <cstdint>\r\n\r\nnamespace kpr {\r\n    [[maybe_unused]]\
    \ inline constexpr struct {\r\n        template<class T>\r\n        constexpr\
    \ T operator ()(T a, std::uint_fast64_t n, T init = 1) const noexcept {\r\n  \
    \          while (n > 0) {\r\n                if (n & 1) init *= a;\r\n      \
    \          a *= a;\r\n                n >>= 1;\r\n            }\r\n          \
    \  return init;\r\n        }\r\n    } power;\r\n} // namespace kpr\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/power.hpp
  requiredBy:
  - all/all.hpp
  - verify/hello_world.cpp
  - meta/constant.hpp
  - meta/meta.hpp
  - system/in.hpp
  - system/system.hpp
  - data_structure/data_structure.hpp
  - data_structure/structure.hpp
  - data_structure/FenwickTree.hpp
  - function/monoid.hpp
  - function/function.hpp
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - math/ModInt.hpp
  - math/is_prime.hpp
  - math/math.hpp
  - math/factorize.hpp
  - math/DynamicModInt.hpp
  - all.hpp
  timestamp: '2023-02-11 02:36:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/PrimeNumber.test.cpp
  - verify/yosupo/factorize.test.cpp
  - verify/yosupo/many_aplusb.test.cpp
documentation_of: math/power.hpp
layout: document
redirect_from:
- /library/math/power.hpp
- /library/math/power.hpp.html
title: math/power.hpp
---
