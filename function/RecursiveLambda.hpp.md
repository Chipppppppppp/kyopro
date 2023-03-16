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
    path: function/function.hpp
    title: function/function.hpp
  - icon: ':warning:'
    path: verify/hello_world.cpp
    title: verify/hello_world.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"function/RecursiveLambda.hpp\"\n#include <type_traits>\r\
    \n#include <utility>\r\n\r\nnamespace kpr {\r\n    // \u518D\u5E30\u53EF\u80FD\
    \u95A2\u6570\u30AF\u30E9\u30B9\r\n    template<class F>\r\n    struct RecursiveLambda\
    \ {\r\n        using value_type = F;\r\n\r\n    private:\r\n        F func;\r\n\
    \r\n    public:\r\n        template<class G>\r\n        constexpr RecursiveLambda(G&&\
    \ func) noexcept: func(std::forward<G>(func)) {}\r\n\r\n        template<class...\
    \ Args>\r\n        constexpr decltype(auto) operator ()(Args&&... args) const\
    \ noexcept(noexcept(func(*this, std::forward<Args>(args)...))) {\r\n         \
    \   return func(*this, std::forward<Args>(args)...);\r\n        }\r\n    };\r\n\
    \r\n    template<class F>\r\n    RecursiveLambda(F&&) -> RecursiveLambda<std::decay_t<F>>;\r\
    \n} // namespace kpr\r\n"
  code: "#pragma once\r\n#include <type_traits>\r\n#include <utility>\r\n\r\nnamespace\
    \ kpr {\r\n    // \u518D\u5E30\u53EF\u80FD\u95A2\u6570\u30AF\u30E9\u30B9\r\n \
    \   template<class F>\r\n    struct RecursiveLambda {\r\n        using value_type\
    \ = F;\r\n\r\n    private:\r\n        F func;\r\n\r\n    public:\r\n        template<class\
    \ G>\r\n        constexpr RecursiveLambda(G&& func) noexcept: func(std::forward<G>(func))\
    \ {}\r\n\r\n        template<class... Args>\r\n        constexpr decltype(auto)\
    \ operator ()(Args&&... args) const noexcept(noexcept(func(*this, std::forward<Args>(args)...)))\
    \ {\r\n            return func(*this, std::forward<Args>(args)...);\r\n      \
    \  }\r\n    };\r\n\r\n    template<class F>\r\n    RecursiveLambda(F&&) -> RecursiveLambda<std::decay_t<F>>;\r\
    \n} // namespace kpr\r\n"
  dependsOn: []
  isVerificationFile: false
  path: function/RecursiveLambda.hpp
  requiredBy:
  - all/all.hpp
  - function/function.hpp
  - all.hpp
  - verify/hello_world.cpp
  timestamp: '2023-02-11 02:36:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: function/RecursiveLambda.hpp
layout: document
redirect_from:
- /library/function/RecursiveLambda.hpp
- /library/function/RecursiveLambda.hpp.html
title: function/RecursiveLambda.hpp
---
