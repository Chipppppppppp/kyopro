---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: function/function.hpp
    title: function/function.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"function/compare.hpp\"\n\nnamespace kpr {\n    // operator\
    \ =\u3067\u6BD4\u8F03\n    struct Equal {\n        template<class T>\n       \
    \ constexpr bool operator()(const T& x, const T& y) const noexcept(noexcept(x\
    \ == y)) {\n            return x == y;\n        }\n    };\n\n    // operator !=\u3067\
    \u6BD4\u8F03\n    struct NotEqual {\n        template<class T>\n        constexpr\
    \ bool operator()(const T& x, const T& y) const noexcept(noexcept(x != y)) {\n\
    \            return x != y;\n        }\n    };\n\n    // operator <\u306E\u95A2\
    \u6570\u30AF\u30E9\u30B9\n    struct Less {\n        template<class T>\n     \
    \   constexpr bool operator()(const T& x, const T& y) const noexcept(noexcept(x\
    \ < y)) {\n            return x < y;\n        }\n    };\n\n    // operator <=\u306E\
    \u95A2\u6570\u30AF\u30E9\u30B9\n    struct LessEqual {\n        template<class\
    \ T>\n        constexpr bool operator()(const T& x, const T& y) const noexcept(noexcept(x\
    \ <= y)) {\n            return x <= y;\n        }\n    };\n\n    // operator >\u306E\
    \u95A2\u6570\u30AF\u30E9\u30B9\n    struct Greater {\n        template<class T>\n\
    \        constexpr bool operator()(const T& x, const T& y) const noexcept(noexcept(x\
    \ > y)) {\n            return x > y;\n        }\n    };\n\n    // operator >=\u306E\
    \u95A2\u6570\u30AF\u30E9\u30B9\n    struct GreaterEqual {\n        template<class\
    \ T>\n        constexpr bool operator()(const T& x, const T& y) const noexcept(noexcept(x\
    \ >= y)) {\n            return x >= y;\n        }\n    };\n} // namespace kpr\n"
  code: "#pragma once\n\nnamespace kpr {\n    // operator =\u3067\u6BD4\u8F03\n  \
    \  struct Equal {\n        template<class T>\n        constexpr bool operator()(const\
    \ T& x, const T& y) const noexcept(noexcept(x == y)) {\n            return x ==\
    \ y;\n        }\n    };\n\n    // operator !=\u3067\u6BD4\u8F03\n    struct NotEqual\
    \ {\n        template<class T>\n        constexpr bool operator()(const T& x,\
    \ const T& y) const noexcept(noexcept(x != y)) {\n            return x != y;\n\
    \        }\n    };\n\n    // operator <\u306E\u95A2\u6570\u30AF\u30E9\u30B9\n\
    \    struct Less {\n        template<class T>\n        constexpr bool operator()(const\
    \ T& x, const T& y) const noexcept(noexcept(x < y)) {\n            return x <\
    \ y;\n        }\n    };\n\n    // operator <=\u306E\u95A2\u6570\u30AF\u30E9\u30B9\
    \n    struct LessEqual {\n        template<class T>\n        constexpr bool operator()(const\
    \ T& x, const T& y) const noexcept(noexcept(x <= y)) {\n            return x <=\
    \ y;\n        }\n    };\n\n    // operator >\u306E\u95A2\u6570\u30AF\u30E9\u30B9\
    \n    struct Greater {\n        template<class T>\n        constexpr bool operator()(const\
    \ T& x, const T& y) const noexcept(noexcept(x > y)) {\n            return x >\
    \ y;\n        }\n    };\n\n    // operator >=\u306E\u95A2\u6570\u30AF\u30E9\u30B9\
    \n    struct GreaterEqual {\n        template<class T>\n        constexpr bool\
    \ operator()(const T& x, const T& y) const noexcept(noexcept(x >= y)) {\n    \
    \        return x >= y;\n        }\n    };\n} // namespace kpr\n"
  dependsOn: []
  isVerificationFile: false
  path: function/compare.hpp
  requiredBy:
  - function/function.hpp
  timestamp: '2023-02-01 00:00:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: function/compare.hpp
layout: document
redirect_from:
- /library/function/compare.hpp
- /library/function/compare.hpp.html
title: function/compare.hpp
---
