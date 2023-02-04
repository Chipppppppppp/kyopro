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
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/fix_vector_bool.hpp\"\n#include <cstddef>\n#include\
    \ <string>\n#include <vector>\n\ntemplate<>\nstruct std::vector<bool>: std::basic_string<bool>\
    \ {\n    using std::basic_string<bool>::basic_string, std::basic_string<bool>::operator\
    \ =;\n    explicit vector(std::size_t n): vector(n, false) {}\n};\n"
  code: "#pragma once\n#include <cstddef>\n#include <string>\n#include <vector>\n\n\
    template<>\nstruct std::vector<bool>: std::basic_string<bool> {\n    using std::basic_string<bool>::basic_string,\
    \ std::basic_string<bool>::operator =;\n    explicit vector(std::size_t n): vector(n,\
    \ false) {}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: template/fix_vector_bool.hpp
  requiredBy:
  - template/template.hpp
  - all.hpp
  timestamp: '2023-02-04 13:16:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/fix_vector_bool.hpp
layout: document
redirect_from:
- /library/template/fix_vector_bool.hpp
- /library/template/fix_vector_bool.hpp.html
title: template/fix_vector_bool.hpp
---
