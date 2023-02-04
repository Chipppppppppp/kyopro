---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"system/option.hpp\"\n#include <cstddef>\n#include <tuple>\n\
    \nnamespace kpr {\n    template<std::size_t i, class... Args>\n    struct indexed\
    \ {\n        std::tuple<Args...> args_tuple;\n        indexed(Args&&... args)\
    \ noexcept: args_tuple(std::forward_as_tuple(forward<Args>(args)...)) {}\n   \
    \ }\n} // namespace kpr\n"
  code: "#pragma once\n#include <cstddef>\n#include <tuple>\n\nnamespace kpr {\n \
    \   template<std::size_t i, class... Args>\n    struct indexed {\n        std::tuple<Args...>\
    \ args_tuple;\n        indexed(Args&&... args) noexcept: args_tuple(std::forward_as_tuple(forward<Args>(args)...))\
    \ {}\n    }\n} // namespace kpr\n"
  dependsOn: []
  isVerificationFile: false
  path: system/option.hpp
  requiredBy: []
  timestamp: '2023-02-04 13:16:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: system/option.hpp
layout: document
redirect_from:
- /library/system/option.hpp
- /library/system/option.hpp.html
title: system/option.hpp
---
