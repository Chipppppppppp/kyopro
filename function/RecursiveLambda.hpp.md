---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
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
    #include <utility>\n\nnamespace kyopro {\n  template<class _typeF>\n  struct RecursiveLambda\
    \ {\n  private:\n    _typeF _func;\n\n  public:\n    template<class _typeG>\n\
    \    constexpr RecursiveLambda(_typeG&& _func) noexcept: _func(std::forward<_typeG>(_func))\
    \ {}\n    template<class... _typeArgs>\n    constexpr decltype(auto) operator\
    \ ()(_typeArgs&&... _args) const noexcept { return _func(*this, std::forward<_typeArgs>(_args)...);\
    \ }\n  };\n\n  template<class _typeF>\n  RecursiveLambda(_typeF&&) -> RecursiveLambda<std::decay_t<_typeF>>;\n\
    }\n"
  code: "#pragma once\n#include <type_traits>\n#include <utility>\n\nnamespace kyopro\
    \ {\n  template<class _typeF>\n  struct RecursiveLambda {\n  private:\n    _typeF\
    \ _func;\n\n  public:\n    template<class _typeG>\n    constexpr RecursiveLambda(_typeG&&\
    \ _func) noexcept: _func(std::forward<_typeG>(_func)) {}\n    template<class...\
    \ _typeArgs>\n    constexpr decltype(auto) operator ()(_typeArgs&&... _args) const\
    \ noexcept { return _func(*this, std::forward<_typeArgs>(_args)...); }\n  };\n\
    \n  template<class _typeF>\n  RecursiveLambda(_typeF&&) -> RecursiveLambda<std::decay_t<_typeF>>;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: function/RecursiveLambda.hpp
  requiredBy:
  - function/all.hpp
  timestamp: '2022-04-17 11:59:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: function/RecursiveLambda.hpp
layout: document
redirect_from:
- /library/function/RecursiveLambda.hpp
- /library/function/RecursiveLambda.hpp.html
title: function/RecursiveLambda.hpp
---
