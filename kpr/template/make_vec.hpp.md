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
  bundledCode: "#line 2 \"kpr/template/make_vec.hpp\"\n#include <cstddef>\r\n#include\
    \ <cstdint>\r\n#include <utility>\r\n#include <vector>\r\n\r\nnamespace kpr {\r\
    \n    // \u591A\u6B21\u5143vector\u3092\u751F\u6210\u3059\u308B\r\n    template<class\
    \ T, std::size_t n, std::size_t i = 0>\r\n    auto make_vec(const std::size_t\
    \ (&d)[n], const T& init = {}) noexcept {\r\n        if constexpr (i < n) return\
    \ std::vector(d[i], make_vec<T, n, i + 1>(d, init));\r\n        else return init;\r\
    \n    }\r\n} // namespace kpr\r\n"
  code: "#pragma once\r\n#include <cstddef>\r\n#include <cstdint>\r\n#include <utility>\r\
    \n#include <vector>\r\n\r\nnamespace kpr {\r\n    // \u591A\u6B21\u5143vector\u3092\
    \u751F\u6210\u3059\u308B\r\n    template<class T, std::size_t n, std::size_t i\
    \ = 0>\r\n    auto make_vec(const std::size_t (&d)[n], const T& init = {}) noexcept\
    \ {\r\n        if constexpr (i < n) return std::vector(d[i], make_vec<T, n, i\
    \ + 1>(d, init));\r\n        else return init;\r\n    }\r\n} // namespace kpr\r\
    \n"
  dependsOn: []
  isVerificationFile: false
  path: kpr/template/make_vec.hpp
  requiredBy: []
  timestamp: '2023-04-16 03:08:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kpr/template/make_vec.hpp
layout: document
redirect_from:
- /library/kpr/template/make_vec.hpp
- /library/kpr/template/make_vec.hpp.html
title: kpr/template/make_vec.hpp
---
