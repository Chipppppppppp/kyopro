---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: kyopro/all.hpp
    title: kyopro/all.hpp
  - icon: ':warning:'
    path: kyopro/all/all.hpp
    title: kyopro/all/all.hpp
  - icon: ':heavy_check_mark:'
    path: kyopro/io/in.hpp
    title: kyopro/io/in.hpp
  - icon: ':heavy_check_mark:'
    path: kyopro/io/io.hpp
    title: kyopro/io/io.hpp
  - icon: ':heavy_check_mark:'
    path: kyopro/io/out.hpp
    title: kyopro/io/out.hpp
  - icon: ':warning:'
    path: kyopro/math/BinomMod.hpp
    title: kyopro/math/BinomMod.hpp
  - icon: ':heavy_check_mark:'
    path: kyopro/math/DynamicModInt.hpp
    title: kyopro/math/DynamicModInt.hpp
  - icon: ':warning:'
    path: kyopro/math/ModInt.hpp
    title: kyopro/math/ModInt.hpp
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
    path: kyopro/template/io_macro.hpp
    title: kyopro/template/io_macro.hpp
  - icon: ':warning:'
    path: kyopro/template/macro.hpp
    title: kyopro/template/macro.hpp
  - icon: ':warning:'
    path: kyopro/template/named_tuple_macro.hpp
    title: kyopro/template/named_tuple_macro.hpp
  - icon: ':warning:'
    path: kyopro/template/template.hpp
    title: kyopro/template/template.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/PrimeNumber.test.cpp
    title: verify/aoj/PrimeNumber.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj/WeightedUnionFind.test.cpp
    title: verify/aoj/WeightedUnionFind.test.cpp
  - icon: ':heavy_check_mark:'
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
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"kyopro/io/io_option.hpp\"\n#include <cstddef>\r\n#include\
    \ <tuple>\r\n#include <utility>\r\n\r\nnamespace kpr {\r\n    template<class Tuple,\
    \ std::size_t idx>\r\n    struct Indexed {\r\n        Tuple args_tuple;\r\n  \
    \      template<class... Args>\r\n        constexpr Indexed(Args&&... args) noexcept:\
    \ args_tuple{std::forward<Args>(args)...} {}\r\n    };\r\n\r\n    template<std::size_t\
    \ i, class... Args>\r\n    constexpr auto indexed(Args&&... args) noexcept {\r\
    \n        return Indexed<std::tuple<Args...>, i>{std::forward<Args>(args)...};\r\
    \n    }\r\n\r\n    template<class Tuple, bool... seps>\r\n    struct SepWith {\r\
    \n        Tuple args_tuple;\r\n        template<class... Args>\r\n        constexpr\
    \ SepWith(Args&&... args) noexcept: args_tuple{std::forward<Args>(args)...} {}\r\
    \n    };\r\n\r\n    template<bool... seps, class... Args>\r\n    constexpr auto\
    \ sep_with(Args&&... args) noexcept {\r\n        return SepWith<std::tuple<Args...>,\
    \ seps...>{std::forward<Args>(args)...};\r\n    }\r\n} // namespace kpr\r\n"
  code: "#pragma once\r\n#include <cstddef>\r\n#include <tuple>\r\n#include <utility>\r\
    \n\r\nnamespace kpr {\r\n    template<class Tuple, std::size_t idx>\r\n    struct\
    \ Indexed {\r\n        Tuple args_tuple;\r\n        template<class... Args>\r\n\
    \        constexpr Indexed(Args&&... args) noexcept: args_tuple{std::forward<Args>(args)...}\
    \ {}\r\n    };\r\n\r\n    template<std::size_t i, class... Args>\r\n    constexpr\
    \ auto indexed(Args&&... args) noexcept {\r\n        return Indexed<std::tuple<Args...>,\
    \ i>{std::forward<Args>(args)...};\r\n    }\r\n\r\n    template<class Tuple, bool...\
    \ seps>\r\n    struct SepWith {\r\n        Tuple args_tuple;\r\n        template<class...\
    \ Args>\r\n        constexpr SepWith(Args&&... args) noexcept: args_tuple{std::forward<Args>(args)...}\
    \ {}\r\n    };\r\n\r\n    template<bool... seps, class... Args>\r\n    constexpr\
    \ auto sep_with(Args&&... args) noexcept {\r\n        return SepWith<std::tuple<Args...>,\
    \ seps...>{std::forward<Args>(args)...};\r\n    }\r\n} // namespace kpr\r\n"
  dependsOn: []
  isVerificationFile: false
  path: kyopro/io/io_option.hpp
  requiredBy:
  - kyopro/io/in.hpp
  - kyopro/io/out.hpp
  - kyopro/io/io.hpp
  - kyopro/all/all.hpp
  - kyopro/all.hpp
  - kyopro/math/is_prime.hpp
  - kyopro/math/factorize.hpp
  - kyopro/math/ModInt.hpp
  - kyopro/math/math.hpp
  - kyopro/math/BinomMod.hpp
  - kyopro/math/DynamicModInt.hpp
  - kyopro/template/template.hpp
  - kyopro/template/macro.hpp
  - kyopro/template/io_macro.hpp
  - kyopro/template/named_tuple_macro.hpp
  - kyopro/template/alias.hpp
  timestamp: '2023-04-02 21:40:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/many_aplusb.test.cpp
  - verify/yosupo/factorize.test.cpp
  - verify/yosupo/point_add_range_sum.test.cpp
  - verify/yosupo/unionfind.test.cpp
  - verify/aoj/WeightedUnionFind.test.cpp
  - verify/aoj/PrimeNumber.test.cpp
documentation_of: kyopro/io/io_option.hpp
layout: document
redirect_from:
- /library/kyopro/io/io_option.hpp
- /library/kyopro/io/io_option.hpp.html
title: kyopro/io/io_option.hpp
---
