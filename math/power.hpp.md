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
  - icon: ':heavy_check_mark:'
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
  - icon: ':heavy_check_mark:'
    path: function/monoid.hpp
    title: function/monoid.hpp
  - icon: ':question:'
    path: io/in.hpp
    title: io/in.hpp
  - icon: ':question:'
    path: io/io.hpp
    title: io/io.hpp
  - icon: ':question:'
    path: math/DynamicModInt.hpp
    title: math/DynamicModInt.hpp
  - icon: ':warning:'
    path: math/ModInt.hpp
    title: math/ModInt.hpp
  - icon: ':x:'
    path: math/factorize.hpp
    title: math/factorize.hpp
  - icon: ':question:'
    path: math/is_prime.hpp
    title: math/is_prime.hpp
  - icon: ':warning:'
    path: math/math.hpp
    title: math/math.hpp
  - icon: ':question:'
    path: meta/constant.hpp
    title: meta/constant.hpp
  - icon: ':warning:'
    path: meta/meta.hpp
    title: meta/meta.hpp
  - icon: ':warning:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':warning:'
    path: template/io.hpp
    title: template/io.hpp
  - icon: ':warning:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':warning:'
    path: template/named_tuple.hpp
    title: template/named_tuple.hpp
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
  - icon: ':x:'
    path: verify/yosupo/factorize.test.cpp
    title: verify/yosupo/factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/many_aplusb.test.cpp
    title: verify/yosupo/many_aplusb.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/point_add_range_sum.test.cpp
    title: verify/yosupo/point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/unionfind.test.cpp
    title: verify/yosupo/unionfind.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
  - all.hpp
  - data_structure/structure.hpp
  - data_structure/data_structure.hpp
  - data_structure/FenwickTree.hpp
  - function/function.hpp
  - function/monoid.hpp
  - math/factorize.hpp
  - math/is_prime.hpp
  - math/ModInt.hpp
  - math/math.hpp
  - math/DynamicModInt.hpp
  - verify/hello_world.cpp
  - template/named_tuple.hpp
  - template/alias.hpp
  - template/template.hpp
  - template/macro.hpp
  - template/io.hpp
  - meta/meta.hpp
  - meta/constant.hpp
  - io/in.hpp
  - io/io.hpp
  timestamp: '2023-02-11 02:36:17+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/yosupo/factorize.test.cpp
  - verify/yosupo/many_aplusb.test.cpp
  - verify/yosupo/point_add_range_sum.test.cpp
  - verify/yosupo/unionfind.test.cpp
  - verify/aoj/PrimeNumber.test.cpp
documentation_of: math/power.hpp
layout: document
redirect_from:
- /library/math/power.hpp
- /library/math/power.hpp.html
title: math/power.hpp
---
