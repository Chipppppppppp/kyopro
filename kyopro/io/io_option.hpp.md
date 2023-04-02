---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: kyopro/io/out.hpp
    title: kyopro/io/out.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
  - kyopro/io/out.hpp
  timestamp: '2023-04-02 20:21:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kyopro/io/io_option.hpp
layout: document
redirect_from:
- /library/kyopro/io/io_option.hpp
- /library/kyopro/io/io_option.hpp.html
title: kyopro/io/io_option.hpp
---
