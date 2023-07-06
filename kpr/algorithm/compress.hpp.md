---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: kpr/function/compare.hpp
    title: kpr/function/compare.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: kpr/algorithm/algorithm.hpp
    title: kpr/algorithm/algorithm.hpp
  - icon: ':warning:'
    path: kpr/all.hpp
    title: kpr/all.hpp
  - icon: ':warning:'
    path: kpr/all/all.hpp
    title: kpr/all/all.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"kpr/algorithm/compress.hpp\"\n#include <algorithm>\n#include\
    \ <iterator>\n#include <unordered_map>\n#include <vector>\n#line 2 \"kpr/function/compare.hpp\"\
    \n\r\nnamespace kpr {\r\n    // operator =\u3067\u6BD4\u8F03\r\n    struct Equal\
    \ {\r\n        template<class T>\r\n        constexpr bool operator()(const T&\
    \ x, const T& y) const noexcept(noexcept(x == y)) {\r\n            return x ==\
    \ y;\r\n        }\r\n    };\r\n\r\n    // operator !=\u3067\u6BD4\u8F03\r\n  \
    \  struct NotEqual {\r\n        template<class T>\r\n        constexpr bool operator()(const\
    \ T& x, const T& y) const noexcept(noexcept(x != y)) {\r\n            return x\
    \ != y;\r\n        }\r\n    };\r\n\r\n    // operator <\u306E\u95A2\u6570\u30AF\
    \u30E9\u30B9\r\n    struct Less {\r\n        template<class T>\r\n        constexpr\
    \ bool operator()(const T& x, const T& y) const noexcept(noexcept(x < y)) {\r\n\
    \            return x < y;\r\n        }\r\n    };\r\n\r\n    // operator <=\u306E\
    \u95A2\u6570\u30AF\u30E9\u30B9\r\n    struct LessEqual {\r\n        template<class\
    \ T>\r\n        constexpr bool operator()(const T& x, const T& y) const noexcept(noexcept(x\
    \ <= y)) {\r\n            return x <= y;\r\n        }\r\n    };\r\n\r\n    //\
    \ operator >\u306E\u95A2\u6570\u30AF\u30E9\u30B9\r\n    struct Greater {\r\n \
    \       template<class T>\r\n        constexpr bool operator()(const T& x, const\
    \ T& y) const noexcept(noexcept(x > y)) {\r\n            return x > y;\r\n   \
    \     }\r\n    };\r\n\r\n    // operator >=\u306E\u95A2\u6570\u30AF\u30E9\u30B9\
    \r\n    struct GreaterEqual {\r\n        template<class T>\r\n        constexpr\
    \ bool operator()(const T& x, const T& y) const noexcept(noexcept(x >= y)) {\r\
    \n            return x >= y;\r\n        }\r\n    };\r\n} // namespace kpr\r\n\
    #line 7 \"kpr/algorithm/compress.hpp\"\n\nnamespace kpr {\n    // \u5EA7\u6A19\
    \u5727\u7E2E\n    [[maybe_unused]] inline constexpr struct {\n        template<class\
    \ T, class Compare = Less, class Container = std::unordered_map<typename std::iterator_traits<T>::value_type,\
    \ KYOPRO_BASE_INT>>\n        auto operator ()(T first, T last, Compare comp =\
    \ {}) const {\n            std::vector<typename Container::key_type> a(first,\
    \ last);\n            std::sort(a.begin(), a.end(), comp);\n            auto itr\
    \ = unique(a.begin(), a.end());\n            Container mem;\n            int cnt\
    \ = -1;\n            for (auto i = std::begin(a); i != itr; ++i) mem[*i] = ++cnt;\n\
    \            return mem;\n        }\n    } compress;\n} // namespace kpr\n"
  code: "#pragma once\n#include <algorithm>\n#include <iterator>\n#include <unordered_map>\n\
    #include <vector>\n#include \"../function/compare.hpp\"\n\nnamespace kpr {\n \
    \   // \u5EA7\u6A19\u5727\u7E2E\n    [[maybe_unused]] inline constexpr struct\
    \ {\n        template<class T, class Compare = Less, class Container = std::unordered_map<typename\
    \ std::iterator_traits<T>::value_type, KYOPRO_BASE_INT>>\n        auto operator\
    \ ()(T first, T last, Compare comp = {}) const {\n            std::vector<typename\
    \ Container::key_type> a(first, last);\n            std::sort(a.begin(), a.end(),\
    \ comp);\n            auto itr = unique(a.begin(), a.end());\n            Container\
    \ mem;\n            int cnt = -1;\n            for (auto i = std::begin(a); i\
    \ != itr; ++i) mem[*i] = ++cnt;\n            return mem;\n        }\n    } compress;\n\
    } // namespace kpr\n"
  dependsOn:
  - kpr/function/compare.hpp
  isVerificationFile: false
  path: kpr/algorithm/compress.hpp
  requiredBy:
  - kpr/all.hpp
  - kpr/algorithm/algorithm.hpp
  - kpr/all/all.hpp
  timestamp: '2023-04-04 01:42:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kpr/algorithm/compress.hpp
layout: document
redirect_from:
- /library/kpr/algorithm/compress.hpp
- /library/kpr/algorithm/compress.hpp.html
title: kpr/algorithm/compress.hpp
---
