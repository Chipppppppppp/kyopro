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
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"function/RecursiveLambda.hpp\"\n#include <type_traits>\n\
    #include <utility>\n\nnamespace kpr {\n    // \u518D\u5E30\u53EF\u80FD\u95A2\u6570\
    \u30AF\u30E9\u30B9\n    template<class F>\n    struct RecursiveLambda {\n    \
    \    using value_type = F;\n\n    private:\n        F func;\n\n    public:\n \
    \       template<class G>\n        constexpr RecursiveLambda(G&& func) noexcept:\
    \ func(std::forward<G>(func)) {}\n        template<class... Args>\n        constexpr\
    \ decltype(auto) operator ()(Args&&... args) const noexcept(noexcept(func(*this,\
    \ std::forward<Args>(args)...))) {\n            return func(*this, std::forward<Args>(args)...);\n\
    \        }\n    };\n\n    template<class F>\n    RecursiveLambda(F&&) -> RecursiveLambda<std::decay_t<F>>;\n\
    } // namespace kpr\n"
  code: "#pragma once\n#include <type_traits>\n#include <utility>\n\nnamespace kpr\
    \ {\n    // \u518D\u5E30\u53EF\u80FD\u95A2\u6570\u30AF\u30E9\u30B9\n    template<class\
    \ F>\n    struct RecursiveLambda {\n        using value_type = F;\n\n    private:\n\
    \        F func;\n\n    public:\n        template<class G>\n        constexpr\
    \ RecursiveLambda(G&& func) noexcept: func(std::forward<G>(func)) {}\n       \
    \ template<class... Args>\n        constexpr decltype(auto) operator ()(Args&&...\
    \ args) const noexcept(noexcept(func(*this, std::forward<Args>(args)...))) {\n\
    \            return func(*this, std::forward<Args>(args)...);\n        }\n   \
    \ };\n\n    template<class F>\n    RecursiveLambda(F&&) -> RecursiveLambda<std::decay_t<F>>;\n\
    } // namespace kpr\n"
  dependsOn: []
  isVerificationFile: false
  path: function/RecursiveLambda.hpp
  requiredBy:
  - all/all.hpp
  - function/function.hpp
  - all.hpp
  timestamp: '2023-02-01 00:00:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: function/RecursiveLambda.hpp
layout: document
redirect_from:
- /library/function/RecursiveLambda.hpp
- /library/function/RecursiveLambda.hpp.html
title: function/RecursiveLambda.hpp
---
