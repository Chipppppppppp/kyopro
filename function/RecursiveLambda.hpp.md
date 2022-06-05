---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  - icon: ':warning:'
    path: all/all.hpp
    title: all/all.hpp
  - icon: ':warning:'
    path: function/all.hpp
    title: function/all.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"function/RecursiveLambda.hpp\"\n#include <type_traits>\n\
    #include <utility>\n\nnamespace kyopro {\n  template<class F>\n  struct RecursiveLambda\
    \ {\n    using value_type = F;\n\n  private:\n    F func;\n\n  public:\n    template<class\
    \ G>\n    constexpr RecursiveLambda(G&& func) noexcept: func(std::forward<G>(func))\
    \ {}\n    template<class... Args>\n    constexpr decltype(auto) operator ()(Args&&...\
    \ args) const noexcept { return func(*this, std::forward<Args>(args)...); }\n\
    \  };\n\n  template<class F>\n  RecursiveLambda(F&&) -> RecursiveLambda<std::decay_t<F>>;\n\
    }\n"
  code: "#pragma once\n#include <type_traits>\n#include <utility>\n\nnamespace kyopro\
    \ {\n  template<class F>\n  struct RecursiveLambda {\n    using value_type = F;\n\
    \n  private:\n    F func;\n\n  public:\n    template<class G>\n    constexpr RecursiveLambda(G&&\
    \ func) noexcept: func(std::forward<G>(func)) {}\n    template<class... Args>\n\
    \    constexpr decltype(auto) operator ()(Args&&... args) const noexcept { return\
    \ func(*this, std::forward<Args>(args)...); }\n  };\n\n  template<class F>\n \
    \ RecursiveLambda(F&&) -> RecursiveLambda<std::decay_t<F>>;\n}"
  dependsOn: []
  isVerificationFile: false
  path: function/RecursiveLambda.hpp
  requiredBy:
  - all.hpp
  - function/all.hpp
  - all/all.hpp
  timestamp: '2022-06-05 22:20:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: function/RecursiveLambda.hpp
layout: document
redirect_from:
- /library/function/RecursiveLambda.hpp
- /library/function/RecursiveLambda.hpp.html
title: function/RecursiveLambda.hpp
---
