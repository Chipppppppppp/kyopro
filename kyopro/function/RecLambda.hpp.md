---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: kyopro/all.hpp
    title: kyopro/all.hpp
  - icon: ':warning:'
    path: kyopro/all/all.hpp
    title: kyopro/all/all.hpp
  - icon: ':warning:'
    path: kyopro/function/function.hpp
    title: kyopro/function/function.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"kyopro/function/RecLambda.hpp\"\n#include <type_traits>\r\
    \n#include <utility>\r\n\r\nnamespace kpr {\r\n    // \u518D\u5E30\u53EF\u80FD\
    \u95A2\u6570\u30AF\u30E9\u30B9\r\n    template<class F>\r\n    struct RecLambda\
    \ {\r\n        using value_type = F;\r\n\r\n    private:\r\n        F func;\r\n\
    \r\n    public:\r\n        template<class G>\r\n        constexpr RecLambda(G&&\
    \ func) noexcept: func(std::forward<G>(func)) {}\r\n\r\n        template<class...\
    \ Args>\r\n        constexpr decltype(auto) operator ()(Args&&... args) const\
    \ noexcept(noexcept(func(*this, std::forward<Args>(args)...))) {\r\n         \
    \   return func(*this, std::forward<Args>(args)...);\r\n        }\r\n    };\r\n\
    \r\n    template<class F>\r\n    RecLambda(F&&) -> RecLambda<std::decay_t<F>>;\r\
    \n} // namespace kpr\r\n"
  code: "#pragma once\r\n#include <type_traits>\r\n#include <utility>\r\n\r\nnamespace\
    \ kpr {\r\n    // \u518D\u5E30\u53EF\u80FD\u95A2\u6570\u30AF\u30E9\u30B9\r\n \
    \   template<class F>\r\n    struct RecLambda {\r\n        using value_type =\
    \ F;\r\n\r\n    private:\r\n        F func;\r\n\r\n    public:\r\n        template<class\
    \ G>\r\n        constexpr RecLambda(G&& func) noexcept: func(std::forward<G>(func))\
    \ {}\r\n\r\n        template<class... Args>\r\n        constexpr decltype(auto)\
    \ operator ()(Args&&... args) const noexcept(noexcept(func(*this, std::forward<Args>(args)...)))\
    \ {\r\n            return func(*this, std::forward<Args>(args)...);\r\n      \
    \  }\r\n    };\r\n\r\n    template<class F>\r\n    RecLambda(F&&) -> RecLambda<std::decay_t<F>>;\r\
    \n} // namespace kpr\r\n"
  dependsOn: []
  isVerificationFile: false
  path: kyopro/function/RecLambda.hpp
  requiredBy:
  - kyopro/all/all.hpp
  - kyopro/function/function.hpp
  - kyopro/all.hpp
  timestamp: '2023-04-02 21:40:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kyopro/function/RecLambda.hpp
layout: document
redirect_from:
- /library/kyopro/function/RecLambda.hpp
- /library/kyopro/function/RecLambda.hpp.html
title: kyopro/function/RecLambda.hpp
---
