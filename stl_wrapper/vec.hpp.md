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
  bundledCode: "#line 2 \"stl_wrapper/vec.hpp\"\n#include <cstdint>\n#include <vector>\n\
    \nnamespace kpr {\n    template<class T, std::size_t d>\n    struct Vec: std::vector<Vec<T,\
    \ d - 1>> {\n        using std::vector<Vec<T, d - 1>>::vector, std::vector<Vec<T,\
    \ d - 1>>::operator =;\n        template<std::size_t i = 0>\n        Vec(const\
    \ std::array<T, d>& l, const T& init) {\n            std::vector(l[i], Vec<T,\
    \ d - 1>::Vec<i + 1>(l, init));\n        }\n    };\n} // namespace kpr\n"
  code: "#pragma once\n#include <cstdint>\n#include <vector>\n\nnamespace kpr {\n\
    \    template<class T, std::size_t d>\n    struct Vec: std::vector<Vec<T, d -\
    \ 1>> {\n        using std::vector<Vec<T, d - 1>>::vector, std::vector<Vec<T,\
    \ d - 1>>::operator =;\n        template<std::size_t i = 0>\n        Vec(const\
    \ std::array<T, d>& l, const T& init) {\n            std::vector(l[i], Vec<T,\
    \ d - 1>::Vec<i + 1>(l, init));\n        }\n    };\n} // namespace kpr\n"
  dependsOn: []
  isVerificationFile: false
  path: stl_wrapper/vec.hpp
  requiredBy: []
  timestamp: '2023-02-14 01:39:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: stl_wrapper/vec.hpp
layout: document
redirect_from:
- /library/stl_wrapper/vec.hpp
- /library/stl_wrapper/vec.hpp.html
title: stl_wrapper/vec.hpp
---
