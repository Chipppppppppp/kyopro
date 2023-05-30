---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: kpr/all.hpp
    title: kpr/all.hpp
  - icon: ':warning:'
    path: kpr/template/template.hpp
    title: kpr/template/template.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"kpr/template/make_array.hpp\"\n#include <cstddef>\r\n#include\
    \ <array>\r\n\r\nnamespace kpr {\r\n    // 0\u6B21\u5143array\u3092\u751F\u6210\
    \u3059\u308B\r\n    template<class T>\r\n    constexpr auto make_array(const T&\
    \ init = {}) noexcept {\r\n        return init;\r\n    }\r\n\r\n    // \u591A\u6B21\
    \u5143array\u3092\u751F\u6210\u3059\u308B\r\n    template<class T, std::size_t\
    \ l, std::size_t... d>\r\n    constexpr auto make_array(const T& init = {}) noexcept\
    \ {\r\n        std::array<decltype(make_array<T, d...>(init)), l> res{};\r\n \
    \       res.fill(make_array<T, d...>(init));\r\n        return res;\r\n    }\r\
    \n} // namespace kpr\r\n"
  code: "#pragma once\r\n#include <cstddef>\r\n#include <array>\r\n\r\nnamespace kpr\
    \ {\r\n    // 0\u6B21\u5143array\u3092\u751F\u6210\u3059\u308B\r\n    template<class\
    \ T>\r\n    constexpr auto make_array(const T& init = {}) noexcept {\r\n     \
    \   return init;\r\n    }\r\n\r\n    // \u591A\u6B21\u5143array\u3092\u751F\u6210\
    \u3059\u308B\r\n    template<class T, std::size_t l, std::size_t... d>\r\n   \
    \ constexpr auto make_array(const T& init = {}) noexcept {\r\n        std::array<decltype(make_array<T,\
    \ d...>(init)), l> res{};\r\n        res.fill(make_array<T, d...>(init));\r\n\
    \        return res;\r\n    }\r\n} // namespace kpr\r\n"
  dependsOn: []
  isVerificationFile: false
  path: kpr/template/make_array.hpp
  requiredBy:
  - kpr/all.hpp
  - kpr/template/template.hpp
  timestamp: '2023-04-16 03:08:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kpr/template/make_array.hpp
layout: document
redirect_from:
- /library/kpr/template/make_array.hpp
- /library/kpr/template/make_array.hpp.html
title: kpr/template/make_array.hpp
---
