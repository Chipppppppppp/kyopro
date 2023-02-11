---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  - icon: ':warning:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':warning:'
    path: verify/hello_world.cpp
    title: verify/hello_world.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/fix_vector_bool.hpp\"\n#include <cstddef>\r\n#include\
    \ <string>\r\n#include <vector>\r\n\r\ntemplate<>\r\nstruct std::vector<bool>:\
    \ std::basic_string<bool> {\r\n    using std::basic_string<bool>::basic_string,\
    \ std::basic_string<bool>::operator =;\r\n    explicit vector(std::size_t n):\
    \ vector(n, false) {}\r\n};\r\n"
  code: "#pragma once\r\n#include <cstddef>\r\n#include <string>\r\n#include <vector>\r\
    \n\r\ntemplate<>\r\nstruct std::vector<bool>: std::basic_string<bool> {\r\n  \
    \  using std::basic_string<bool>::basic_string, std::basic_string<bool>::operator\
    \ =;\r\n    explicit vector(std::size_t n): vector(n, false) {}\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: template/fix_vector_bool.hpp
  requiredBy:
  - verify/hello_world.cpp
  - template/template.hpp
  - all.hpp
  timestamp: '2023-02-11 02:36:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/fix_vector_bool.hpp
layout: document
redirect_from:
- /library/template/fix_vector_bool.hpp
- /library/template/fix_vector_bool.hpp.html
title: template/fix_vector_bool.hpp
---
