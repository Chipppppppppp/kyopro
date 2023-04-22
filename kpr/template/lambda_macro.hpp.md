---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: kpr/all.hpp
    title: kpr/all.hpp
  - icon: ':warning:'
    path: kpr/template/macro.hpp
    title: kpr/template/macro.hpp
  - icon: ':warning:'
    path: kpr/template/template.hpp
    title: kpr/template/template.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"kpr/template/lambda_macro.hpp\"\n#include <cstddef>\r\n\
    #include <tuple>\r\n\r\n#define $(...) \\\r\n([&](auto&&... _args) { \\\r\n  \
    \  return ([&]([[maybe_unused]] auto&& $0, [[maybe_unused]] auto&& $1, [[maybe_unused]]\
    \ auto&& $2, [[maybe_unused]] auto&& $3, [[maybe_unused]] auto&& $4, std::nullptr_t\
    \ = nullptr, std::nullptr_t = nullptr, std::nullptr_t = nullptr, std::nullptr_t\
    \ = nullptr, std::nullptr_t = nullptr) noexcept { return (__VA_ARGS__); })(std::forward<decltype(_args)>(_args)...,\
    \ nullptr, nullptr, nullptr, nullptr, nullptr); \\\r\n})\r\n"
  code: "#pragma once\r\n#include <cstddef>\r\n#include <tuple>\r\n\r\n#define $(...)\
    \ \\\r\n([&](auto&&... _args) { \\\r\n    return ([&]([[maybe_unused]] auto&&\
    \ $0, [[maybe_unused]] auto&& $1, [[maybe_unused]] auto&& $2, [[maybe_unused]]\
    \ auto&& $3, [[maybe_unused]] auto&& $4, std::nullptr_t = nullptr, std::nullptr_t\
    \ = nullptr, std::nullptr_t = nullptr, std::nullptr_t = nullptr, std::nullptr_t\
    \ = nullptr) noexcept { return (__VA_ARGS__); })(std::forward<decltype(_args)>(_args)...,\
    \ nullptr, nullptr, nullptr, nullptr, nullptr); \\\r\n})\r\n"
  dependsOn: []
  isVerificationFile: false
  path: kpr/template/lambda_macro.hpp
  requiredBy:
  - kpr/template/macro.hpp
  - kpr/template/template.hpp
  - kpr/all.hpp
  timestamp: '2023-04-23 01:38:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kpr/template/lambda_macro.hpp
layout: document
redirect_from:
- /library/kpr/template/lambda_macro.hpp
- /library/kpr/template/lambda_macro.hpp.html
title: kpr/template/lambda_macro.hpp
---
