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
  - icon: ':warning:'
    path: kpr/io/in.hpp
    title: kpr/io/in.hpp
  - icon: ':warning:'
    path: kpr/io/io.hpp
    title: kpr/io/io.hpp
  - icon: ':warning:'
    path: kpr/io/out.hpp
    title: kpr/io/out.hpp
  - icon: ':warning:'
    path: kpr/math/BinomMod.hpp
    title: kpr/math/BinomMod.hpp
  - icon: ':warning:'
    path: kpr/math/DynamicModInt.hpp
    title: kpr/math/DynamicModInt.hpp
  - icon: ':warning:'
    path: kpr/math/ModInt.hpp
    title: kpr/math/ModInt.hpp
  - icon: ':warning:'
    path: kpr/math/factorize.hpp
    title: kpr/math/factorize.hpp
  - icon: ':warning:'
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
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
  - kpr/io/in.hpp
  - kpr/io/out.hpp
  - kpr/io/io.hpp
  - kpr/all/all.hpp
  - kpr/all.hpp
  - kpr/math/is_prime.hpp
  - kpr/math/factorize.hpp
  - kpr/math/ModInt.hpp
  - kpr/math/math.hpp
  - kpr/math/BinomMod.hpp
  - kpr/math/DynamicModInt.hpp
  - kpr/template/template.hpp
  - kpr/template/macro.hpp
  - kpr/template/io_macro.hpp
  - kpr/template/named_tuple_macro.hpp
  - kpr/template/alias.hpp
  timestamp: '2023-04-04 01:42:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kpr/io/io_option.hpp
layout: document
redirect_from:
- /library/kpr/io/io_option.hpp
- /library/kpr/io/io_option.hpp.html
title: kpr/io/io_option.hpp
---
