---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: kpr/all.hpp
    title: kpr/all.hpp
  - icon: ':warning:'
    path: kpr/all/all.hpp
    title: kpr/all/all.hpp
  - icon: ':heavy_check_mark:'
    path: kpr/io/in.hpp
    title: kpr/io/in.hpp
  - icon: ':heavy_check_mark:'
    path: kpr/io/io.hpp
    title: kpr/io/io.hpp
  - icon: ':heavy_check_mark:'
    path: kpr/io/out.hpp
    title: kpr/io/out.hpp
  - icon: ':warning:'
    path: kpr/math/BinomMod.hpp
    title: kpr/math/BinomMod.hpp
  - icon: ':heavy_check_mark:'
    path: kpr/math/DynamicModInt.hpp
    title: kpr/math/DynamicModInt.hpp
  - icon: ':heavy_check_mark:'
    path: kpr/math/ModInt.hpp
    title: kpr/math/ModInt.hpp
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
    path: kpr/template/io_macro.hpp
    title: kpr/template/io_macro.hpp
  - icon: ':warning:'
    path: kpr/template/macro.hpp
    title: kpr/template/macro.hpp
  - icon: ':warning:'
    path: kpr/template/named_tuple_macro.hpp
    title: kpr/template/named_tuple_macro.hpp
  - icon: ':warning:'
    path: kpr/template/template.hpp
    title: kpr/template/template.hpp
  _extendedVerifiedWith:
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
    path: verify/yosupo/point_set_range_composite.test.cpp
    title: verify/yosupo/point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/unionfind.test.cpp
    title: verify/yosupo/unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"kpr/io/io_option.hpp\"\n#include <cstddef>\r\n#include <tuple>\r\
    \n#include <utility>\r\n\r\nnamespace kpr {\r\n    template<class Tuple, std::size_t\
    \ idx>\r\n    struct Indexed {\r\n        Tuple args_tuple;\r\n        template<class...\
    \ Args>\r\n        constexpr Indexed(Args&&... args) noexcept: args_tuple{std::forward<Args>(args)...}\
    \ {}\r\n    };\r\n\r\n    template<std::size_t i, class... Args>\r\n    constexpr\
    \ auto indexed(Args&&... args) noexcept {\r\n        return Indexed<std::tuple<Args...>,\
    \ i>{std::forward<Args>(args)...};\r\n    }\r\n\r\n    template<class Tuple, bool...\
    \ seps>\r\n    struct SepWith {\r\n        Tuple args_tuple;\r\n        template<class...\
    \ Args>\r\n        constexpr SepWith(Args&&... args) noexcept: args_tuple{std::forward<Args>(args)...}\
    \ {}\r\n    };\r\n\r\n    template<bool... seps, class... Args>\r\n    constexpr\
    \ auto sep_with(Args&&... args) noexcept {\r\n        return SepWith<std::tuple<Args...>,\
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
  path: kpr/io/io_option.hpp
  requiredBy:
  - kpr/io/io.hpp
  - kpr/io/in.hpp
  - kpr/io/out.hpp
  - kpr/template/io_macro.hpp
  - kpr/template/template.hpp
  - kpr/template/alias.hpp
  - kpr/template/named_tuple_macro.hpp
  - kpr/template/macro.hpp
  - kpr/all.hpp
  - kpr/math/is_prime.hpp
  - kpr/math/BinomMod.hpp
  - kpr/math/factorize.hpp
  - kpr/math/ModInt.hpp
  - kpr/math/math.hpp
  - kpr/math/DynamicModInt.hpp
  - kpr/all/all.hpp
  timestamp: '2023-04-04 01:42:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/point_set_range_composite.test.cpp
  - verify/yosupo/unionfind.test.cpp
  - verify/yosupo/factorize.test.cpp
  - verify/yosupo/point_add_range_sum.test.cpp
  - verify/yosupo/many_aplusb.test.cpp
  - verify/aoj/WeightedUnionFind.test.cpp
documentation_of: kpr/io/io_option.hpp
layout: document
redirect_from:
- /library/kpr/io/io_option.hpp
- /library/kpr/io/io_option.hpp.html
title: kpr/io/io_option.hpp
---
