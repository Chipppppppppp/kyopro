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
    path: test.cpp
    title: test.cpp
  - icon: ':warning:'
    path: verify/hello_world.cpp
    title: verify/hello_world.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/main.hpp\"\n\nnamespace kpr {\n    void main();\n\
    } // namespace kpr\n\nint main() {\n    kpr::main();\n}\n"
  code: "#pragma once\n\nnamespace kpr {\n    void main();\n} // namespace kpr\n\n\
    int main() {\n    kpr::main();\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: template/main.hpp
  requiredBy:
  - all.hpp
  - test.cpp
  - verify/hello_world.cpp
  - template/template.hpp
  timestamp: '2023-02-12 02:54:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/main.hpp
layout: document
redirect_from:
- /library/template/main.hpp
- /library/template/main.hpp.html
title: template/main.hpp
---
