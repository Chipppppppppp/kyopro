---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: kyopro/algorithm/algorithm.hpp
    title: kyopro/algorithm/algorithm.hpp
  - icon: ':warning:'
    path: kyopro/algorithm/compress.hpp
    title: kyopro/algorithm/compress.hpp
  - icon: ':warning:'
    path: kyopro/all.hpp
    title: kyopro/all.hpp
  - icon: ':warning:'
    path: kyopro/all/all.hpp
    title: kyopro/all/all.hpp
  - icon: ':warning:'
    path: kyopro/function/function.hpp
    title: kyopro/function/function.hpp
  - icon: ':warning:'
    path: kyopro/template/alias.hpp
    title: kyopro/template/alias.hpp
  - icon: ':warning:'
    path: kyopro/template/template.hpp
    title: kyopro/template/template.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"kyopro/function/compare.hpp\"\n\r\nnamespace kpr {\r\n \
    \   // operator =\u3067\u6BD4\u8F03\r\n    struct Equal {\r\n        template<class\
    \ T>\r\n        constexpr bool operator()(const T& x, const T& y) const noexcept(noexcept(x\
    \ == y)) {\r\n            return x == y;\r\n        }\r\n    };\r\n\r\n    //\
    \ operator !=\u3067\u6BD4\u8F03\r\n    struct NotEqual {\r\n        template<class\
    \ T>\r\n        constexpr bool operator()(const T& x, const T& y) const noexcept(noexcept(x\
    \ != y)) {\r\n            return x != y;\r\n        }\r\n    };\r\n\r\n    //\
    \ operator <\u306E\u95A2\u6570\u30AF\u30E9\u30B9\r\n    struct Less {\r\n    \
    \    template<class T>\r\n        constexpr bool operator()(const T& x, const\
    \ T& y) const noexcept(noexcept(x < y)) {\r\n            return x < y;\r\n   \
    \     }\r\n    };\r\n\r\n    // operator <=\u306E\u95A2\u6570\u30AF\u30E9\u30B9\
    \r\n    struct LessEqual {\r\n        template<class T>\r\n        constexpr bool\
    \ operator()(const T& x, const T& y) const noexcept(noexcept(x <= y)) {\r\n  \
    \          return x <= y;\r\n        }\r\n    };\r\n\r\n    // operator >\u306E\
    \u95A2\u6570\u30AF\u30E9\u30B9\r\n    struct Greater {\r\n        template<class\
    \ T>\r\n        constexpr bool operator()(const T& x, const T& y) const noexcept(noexcept(x\
    \ > y)) {\r\n            return x > y;\r\n        }\r\n    };\r\n\r\n    // operator\
    \ >=\u306E\u95A2\u6570\u30AF\u30E9\u30B9\r\n    struct GreaterEqual {\r\n    \
    \    template<class T>\r\n        constexpr bool operator()(const T& x, const\
    \ T& y) const noexcept(noexcept(x >= y)) {\r\n            return x >= y;\r\n \
    \       }\r\n    };\r\n} // namespace kpr\r\n"
  code: "#pragma once\r\n\r\nnamespace kpr {\r\n    // operator =\u3067\u6BD4\u8F03\
    \r\n    struct Equal {\r\n        template<class T>\r\n        constexpr bool\
    \ operator()(const T& x, const T& y) const noexcept(noexcept(x == y)) {\r\n  \
    \          return x == y;\r\n        }\r\n    };\r\n\r\n    // operator !=\u3067\
    \u6BD4\u8F03\r\n    struct NotEqual {\r\n        template<class T>\r\n       \
    \ constexpr bool operator()(const T& x, const T& y) const noexcept(noexcept(x\
    \ != y)) {\r\n            return x != y;\r\n        }\r\n    };\r\n\r\n    //\
    \ operator <\u306E\u95A2\u6570\u30AF\u30E9\u30B9\r\n    struct Less {\r\n    \
    \    template<class T>\r\n        constexpr bool operator()(const T& x, const\
    \ T& y) const noexcept(noexcept(x < y)) {\r\n            return x < y;\r\n   \
    \     }\r\n    };\r\n\r\n    // operator <=\u306E\u95A2\u6570\u30AF\u30E9\u30B9\
    \r\n    struct LessEqual {\r\n        template<class T>\r\n        constexpr bool\
    \ operator()(const T& x, const T& y) const noexcept(noexcept(x <= y)) {\r\n  \
    \          return x <= y;\r\n        }\r\n    };\r\n\r\n    // operator >\u306E\
    \u95A2\u6570\u30AF\u30E9\u30B9\r\n    struct Greater {\r\n        template<class\
    \ T>\r\n        constexpr bool operator()(const T& x, const T& y) const noexcept(noexcept(x\
    \ > y)) {\r\n            return x > y;\r\n        }\r\n    };\r\n\r\n    // operator\
    \ >=\u306E\u95A2\u6570\u30AF\u30E9\u30B9\r\n    struct GreaterEqual {\r\n    \
    \    template<class T>\r\n        constexpr bool operator()(const T& x, const\
    \ T& y) const noexcept(noexcept(x >= y)) {\r\n            return x >= y;\r\n \
    \       }\r\n    };\r\n} // namespace kpr\r\n"
  dependsOn: []
  isVerificationFile: false
  path: kyopro/function/compare.hpp
  requiredBy:
  - kyopro/all/all.hpp
  - kyopro/function/function.hpp
  - kyopro/all.hpp
  - kyopro/algorithm/compress.hpp
  - kyopro/algorithm/algorithm.hpp
  - kyopro/template/template.hpp
  - kyopro/template/alias.hpp
  timestamp: '2023-04-02 21:40:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kyopro/function/compare.hpp
layout: document
redirect_from:
- /library/kyopro/function/compare.hpp
- /library/kyopro/function/compare.hpp.html
title: kyopro/function/compare.hpp
---
