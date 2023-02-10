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
  - icon: ':x:'
    path: system/in.hpp
    title: system/in.hpp
  - icon: ':x:'
    path: system/out.hpp
    title: system/out.hpp
  - icon: ':x:'
    path: system/system.hpp
    title: system/system.hpp
  - icon: ':warning:'
    path: template/macro.hpp
    title: template/macro.hpp
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
  - icon: ':x:'
    path: verify/yosupo/many_aplusb.test.cpp
    title: verify/yosupo/many_aplusb.test.cpp
  - icon: ':x:'
    path: verify/yosupo/point_add_range_sum.test.cpp
    title: verify/yosupo/point_add_range_sum.test.cpp
  - icon: ':x:'
    path: verify/yosupo/unionfind.test.cpp
    title: verify/yosupo/unionfind.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"system/io_option.hpp\"\n#include <cstddef>\n#include <tuple>\n\
    #include <utility>\n\nnamespace kpr {\n    template<class Tuple, std::size_t idx>\n\
    \    struct Indexed {\n        Tuple args_tuple;\n        template<class... Args>\n\
    \        constexpr Indexed(Args&&... args) noexcept: args_tuple{std::forward<Args>(args)...}\
    \ {}\n    };\n\n    template<std::size_t i, class... Args>\n    constexpr auto\
    \ indexed(Args&&... args) noexcept {\n        return Indexed<std::tuple<Args>...,\
    \ i>{std::forward<Args>(args)...};\n    }\n\n    template<class Tuple, bool...\
    \ seps>\n    struct SepWith {\n        Tuple args_tuple;\n        template<class...\
    \ Args>\n        constexpr SepWith(Args&&... args) noexcept: args_tuple{std::forward<Args>(args)...}\
    \ {}\n    };\n\n    template<bool... seps, class... Args>\n    constexpr auto\
    \ sep_with(Args&&... args) noexcept {\n        return SepWith<std::tuple<Args...>,\
    \ seps...>{std::forward<Args>(args)...};\n    }\n} // namespace kpr\n"
  code: "#pragma once\n#include <cstddef>\n#include <tuple>\n#include <utility>\n\n\
    namespace kpr {\n    template<class Tuple, std::size_t idx>\n    struct Indexed\
    \ {\n        Tuple args_tuple;\n        template<class... Args>\n        constexpr\
    \ Indexed(Args&&... args) noexcept: args_tuple{std::forward<Args>(args)...} {}\n\
    \    };\n\n    template<std::size_t i, class... Args>\n    constexpr auto indexed(Args&&...\
    \ args) noexcept {\n        return Indexed<std::tuple<Args>..., i>{std::forward<Args>(args)...};\n\
    \    }\n\n    template<class Tuple, bool... seps>\n    struct SepWith {\n    \
    \    Tuple args_tuple;\n        template<class... Args>\n        constexpr SepWith(Args&&...\
    \ args) noexcept: args_tuple{std::forward<Args>(args)...} {}\n    };\n\n    template<bool...\
    \ seps, class... Args>\n    constexpr auto sep_with(Args&&... args) noexcept {\n\
    \        return SepWith<std::tuple<Args...>, seps...>{std::forward<Args>(args)...};\n\
    \    }\n} // namespace kpr\n"
  dependsOn: []
  isVerificationFile: false
  path: system/io_option.hpp
  requiredBy:
  - all/all.hpp
  - system/in.hpp
  - system/out.hpp
  - system/system.hpp
  - template/template.hpp
  - template/macro.hpp
  - all.hpp
  timestamp: '2023-02-10 23:05:45+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/aoj/PrimeNumber.test.cpp
  - verify/yosupo/point_add_range_sum.test.cpp
  - verify/yosupo/unionfind.test.cpp
  - verify/yosupo/factorize.test.cpp
  - verify/yosupo/many_aplusb.test.cpp
documentation_of: system/io_option.hpp
layout: document
redirect_from:
- /library/system/io_option.hpp
- /library/system/io_option.hpp.html
title: system/io_option.hpp
---
