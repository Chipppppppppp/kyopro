---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: kpr/algorithm/algorithm.hpp
    title: kpr/algorithm/algorithm.hpp
  - icon: ':warning:'
    path: kpr/algorithm/compress.hpp
    title: kpr/algorithm/compress.hpp
  - icon: ':warning:'
    path: kpr/all.hpp
    title: kpr/all.hpp
  - icon: ':warning:'
    path: kpr/all/all.hpp
    title: kpr/all/all.hpp
  - icon: ':warning:'
    path: kpr/function/function.hpp
    title: kpr/function/function.hpp
  - icon: ':warning:'
    path: kpr/template/alias.hpp
    title: kpr/template/alias.hpp
  - icon: ':warning:'
    path: kpr/template/template.hpp
    title: kpr/template/template.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"kpr/function/compare.hpp\"\n\r\nnamespace kpr {\r\n    //\
    \ operator =\u3067\u6BD4\u8F03\r\n    struct Equal {\r\n        template<class\
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
  path: kpr/function/compare.hpp
  requiredBy:
  - kpr/template/alias.hpp
  - kpr/template/template.hpp
  - kpr/all/all.hpp
  - kpr/algorithm/algorithm.hpp
  - kpr/algorithm/compress.hpp
  - kpr/function/function.hpp
  - kpr/all.hpp
  timestamp: '2023-04-04 01:42:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kpr/function/compare.hpp
layout: document
redirect_from:
- /library/kpr/function/compare.hpp
- /library/kpr/function/compare.hpp.html
title: kpr/function/compare.hpp
---
