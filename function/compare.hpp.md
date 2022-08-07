---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: algorithm/algorithm.hpp
    title: algorithm/algorithm.hpp
  - icon: ':warning:'
    path: algorithm/all.hpp
    title: algorithm/all.hpp
  - icon: ':warning:'
    path: function/all.hpp
    title: function/all.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"function/compare.hpp\"\n\nnamespace kyopro {\n    struct\
    \ Equal {\n        template<class T>\n        constexpr bool operator()(const\
    \ T& x, const T& y) const noexcept(noexcept(x == y)) {\n            return x ==\
    \ y;\n        }\n    };\n\n    struct NotEqual {\n        template<class T>\n\
    \        constexpr bool operator()(const T& x, const T& y) const noexcept(noexcept(x\
    \ != y)) {\n            return x != y;\n        }\n    };\n\n    struct Less {\n\
    \        template<class T>\n        constexpr bool operator()(const T& x, const\
    \ T& y) const noexcept(noexcept(x < y)) {\n            return x < y;\n       \
    \ }\n    };\n\n    struct LessEqual {\n        template<class T>\n        constexpr\
    \ bool operator()(const T& x, const T& y) const noexcept(noexcept(x <= y)) {\n\
    \            return x <= y;\n        }\n    };\n\n    struct Greater {\n     \
    \   template<class T>\n        constexpr bool operator()(const T& x, const T&\
    \ y) const noexcept(noexcept(x > y)) {\n            return x > y;\n        }\n\
    \    };\n\n    struct GreaterEqual {\n        template<class T>\n        constexpr\
    \ bool operator()(const T& x, const T& y) const noexcept(noexcept(x >= y)) {\n\
    \            return x >= y;\n        }\n    };\n} // namespace kyopro\n"
  code: "#pragma once\n\nnamespace kyopro {\n    struct Equal {\n        template<class\
    \ T>\n        constexpr bool operator()(const T& x, const T& y) const noexcept(noexcept(x\
    \ == y)) {\n            return x == y;\n        }\n    };\n\n    struct NotEqual\
    \ {\n        template<class T>\n        constexpr bool operator()(const T& x,\
    \ const T& y) const noexcept(noexcept(x != y)) {\n            return x != y;\n\
    \        }\n    };\n\n    struct Less {\n        template<class T>\n        constexpr\
    \ bool operator()(const T& x, const T& y) const noexcept(noexcept(x < y)) {\n\
    \            return x < y;\n        }\n    };\n\n    struct LessEqual {\n    \
    \    template<class T>\n        constexpr bool operator()(const T& x, const T&\
    \ y) const noexcept(noexcept(x <= y)) {\n            return x <= y;\n        }\n\
    \    };\n\n    struct Greater {\n        template<class T>\n        constexpr\
    \ bool operator()(const T& x, const T& y) const noexcept(noexcept(x > y)) {\n\
    \            return x > y;\n        }\n    };\n\n    struct GreaterEqual {\n \
    \       template<class T>\n        constexpr bool operator()(const T& x, const\
    \ T& y) const noexcept(noexcept(x >= y)) {\n            return x >= y;\n     \
    \   }\n    };\n} // namespace kyopro"
  dependsOn: []
  isVerificationFile: false
  path: function/compare.hpp
  requiredBy:
  - function/all.hpp
  - algorithm/algorithm.hpp
  - algorithm/all.hpp
  timestamp: '2022-07-28 17:38:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: function/compare.hpp
layout: document
redirect_from:
- /library/function/compare.hpp
- /library/function/compare.hpp.html
title: function/compare.hpp
---
