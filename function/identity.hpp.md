---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: algorithm/algorithm.hpp
    title: algorithm/algorithm.hpp
  - icon: ':warning:'
    path: algorithm/all.hpp
    title: algorithm/all.hpp
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  - icon: ':warning:'
    path: all/all.hpp
    title: all/all.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"function/identity.hpp\"\n#include <utility>\n\nnamespace\
    \ kyopro {\n    struct Identity {\n        template<class T>\n        T&& operator\
    \ ()(T&& a) const noexcept {\n            return std::forward<T>(a);\n       \
    \ }\n    };\n}\n"
  code: "#pragma once\n#include <utility>\n\nnamespace kyopro {\n    struct Identity\
    \ {\n        template<class T>\n        T&& operator ()(T&& a) const noexcept\
    \ {\n            return std::forward<T>(a);\n        }\n    };\n}"
  dependsOn: []
  isVerificationFile: false
  path: function/identity.hpp
  requiredBy:
  - all/all.hpp
  - all.hpp
  - algorithm/algorithm.hpp
  - algorithm/all.hpp
  timestamp: '2022-07-28 17:38:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: function/identity.hpp
layout: document
redirect_from:
- /library/function/identity.hpp
- /library/function/identity.hpp.html
title: function/identity.hpp
---
