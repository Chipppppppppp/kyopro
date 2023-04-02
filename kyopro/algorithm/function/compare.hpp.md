---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: kyopro/algorithm/function/function.hpp
    title: kyopro/algorithm/function/function.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"kyopro/algorithm/function/compare.hpp\"\n\r\nnamespace kpr\
    \ {\r\n    // operator =\u3067\u6BD4\u8F03\r\n    struct Equal {\r\n        template<class\
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
  path: kyopro/algorithm/function/compare.hpp
  requiredBy:
  - kyopro/algorithm/function/function.hpp
  timestamp: '2023-04-02 20:21:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kyopro/algorithm/function/compare.hpp
layout: document
redirect_from:
- /library/kyopro/algorithm/function/compare.hpp
- /library/kyopro/algorithm/function/compare.hpp.html
title: kyopro/algorithm/function/compare.hpp
---
