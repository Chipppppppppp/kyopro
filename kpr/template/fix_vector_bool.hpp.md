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
  bundledCode: "#line 2 \"kpr/template/fix_vector_bool.hpp\"\n#include <string>\n\
    #include <vector>\n\ntemplate<>\nstruct std::vector<bool>: std::basic_string<bool>\
    \ {\n    using std::basic_string<bool>::basic_string, std::basic_string<bool>::operator\
    \ =;\n    explicit vector(size_t n): vector(n, false) {}\n};\n"
  code: "#pragma once\n#include <string>\n#include <vector>\n\ntemplate<>\nstruct\
    \ std::vector<bool>: std::basic_string<bool> {\n    using std::basic_string<bool>::basic_string,\
    \ std::basic_string<bool>::operator =;\n    explicit vector(size_t n): vector(n,\
    \ false) {}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: kpr/template/fix_vector_bool.hpp
  requiredBy:
  - kpr/template/template.hpp
  - kpr/all.hpp
  timestamp: '2023-06-15 19:03:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kpr/template/fix_vector_bool.hpp
layout: document
redirect_from:
- /library/kpr/template/fix_vector_bool.hpp
- /library/kpr/template/fix_vector_bool.hpp.html
title: kpr/template/fix_vector_bool.hpp
---
