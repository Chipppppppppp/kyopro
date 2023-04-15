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
  bundledCode: "#line 2 \"kpr/function/RecLambda.hpp\"\n#include <type_traits>\r\n\
    #include <utility>\r\n\r\nnamespace kpr {\r\n    // \u518D\u5E30\u53EF\u80FD\u95A2\
    \u6570\u30AF\u30E9\u30B9\r\n    template<class F>\r\n    struct RecLambda {\r\n\
    \        using value_type = F;\r\n\r\n    private:\r\n        F func;\r\n\r\n\
    \    public:\r\n        template<class G>\r\n        constexpr RecLambda(G&& func)\
    \ noexcept: func(std::forward<G>(func)) {}\r\n\r\n        template<class... Args>\r\
    \n        constexpr decltype(auto) operator ()(Args&&... args) const noexcept(noexcept(func(*this,\
    \ std::forward<Args>(args)...))) {\r\n            return func(*this, std::forward<Args>(args)...);\r\
    \n        }\r\n    };\r\n\r\n    template<class F>\r\n    RecLambda(F&&) -> RecLambda<std::decay_t<F>>;\r\
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
  path: kpr/function/RecLambda.hpp
  requiredBy: []
  timestamp: '2023-04-04 01:42:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kpr/function/RecLambda.hpp
layout: document
redirect_from:
- /library/kpr/function/RecLambda.hpp
- /library/kpr/function/RecLambda.hpp.html
title: kpr/function/RecLambda.hpp
---
