---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: meta/setting.hpp
    title: meta/setting.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: algorithm/algorithm.hpp
    title: algorithm/algorithm.hpp
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  - icon: ':warning:'
    path: all/all.hpp
    title: all/all.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algorithm/count_all.hpp\"\n#include <iterator>\n#include\
    \ <unordered_map>\n#line 2 \"meta/setting.hpp\"\n#include <cstdint>\r\n\r\n#ifndef\
    \ KYOPRO_BASE_INT\r\n// \u57FA\u672C\u7B26\u53F7\u4ED8\u304D\u6574\u6570\u578B\
    \r\n#define KYOPRO_BASE_INT std::int64_t\r\n#endif\r\n\r\n#ifndef KYOPRO_BASE_UINT\r\
    \n// \u57FA\u672C\u7B26\u53F7\u306A\u3057\u6574\u6570\u578B\r\n#define KYOPRO_BASE_UINT\
    \ std::uint64_t\r\n#endif\r\n\r\n#ifndef KYOPRO_BASE_FLOAT\r\n// \u57FA\u672C\u6D6E\
    \u52D5\u5C0F\u6570\u70B9\u6570\u578B\r\n#define KYOPRO_BASE_FLOAT double\r\n#endif\r\
    \n\r\n#ifndef KYOPRO_DEFAULT_MOD\r\n// \u554F\u984C\u3067\u8A2D\u5B9A\u3055\u308C\
    \u305Fmod\r\n#define KYOPRO_DEFAULT_MOD (static_cast<KYOPRO_BASE_UINT>(998244353))\r\
    \n#endif\r\n\r\n#ifndef KYOPRO_DECIMAL_PRECISION\r\n// \u5C0F\u6570\u7CBE\u5EA6\
    (\u6841)\r\n#define KYOPRO_DECIMAL_PRECISION (static_cast<KYOPRO_BASE_UINT>(12))\r\
    \n#endif\r\n\r\n#ifndef KYOPRO_INF_DIV\r\n// \u7121\u9650\u5927\u3092\u8868\u3059\
    \u6574\u6570\u304C\u6700\u5927\u5024\u306E\u4F55\u5206\u306E\u4E00\u304B\u3092\
    \u8868\u3059\r\n#define KYOPRO_INF_DIV (static_cast<KYOPRO_BASE_UINT>(3))\r\n\
    #endif\r\n\r\n#ifndef KYOPRO_BUFFER_SIZE\r\n// \u30C7\u30D5\u30A9\u30EB\u30C8\u306E\
    \u30D0\u30C3\u30D5\u30A1\u30B5\u30A4\u30BA\r\n#define KYOPRO_BUFFER_SIZE (static_cast<KYOPRO_BASE_UINT>(2048))\r\
    \n#endif\r\n#line 5 \"algorithm/count_all.hpp\"\n\nnamespace kpr {\n    inline\
    \ constexpr struct {\n        template<class T>\n        auto operator ()(T first,\
    \ T last) const {\n            std::unordered_map<typename std::iterator_traits<T>::value_type,\
    \ KYOPRO_BASE_INT> mem;\n            for (auto i = first; i != last; ++i) ++mem[*i];\n\
    \            return mem;\n        }\n    } count_all;\n} // namespace kpr\n"
  code: "#pragma once\n#include <iterator>\n#include <unordered_map>\n#include \"\
    ../meta/setting.hpp\"\n\nnamespace kpr {\n    inline constexpr struct {\n    \
    \    template<class T>\n        auto operator ()(T first, T last) const {\n  \
    \          std::unordered_map<typename std::iterator_traits<T>::value_type, KYOPRO_BASE_INT>\
    \ mem;\n            for (auto i = first; i != last; ++i) ++mem[*i];\n        \
    \    return mem;\n        }\n    } count_all;\n} // namespace kpr\n"
  dependsOn:
  - meta/setting.hpp
  isVerificationFile: false
  path: algorithm/count_all.hpp
  requiredBy:
  - all/all.hpp
  - all.hpp
  - algorithm/algorithm.hpp
  timestamp: '2023-03-28 19:27:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/count_all.hpp
layout: document
redirect_from:
- /library/algorithm/count_all.hpp
- /library/algorithm/count_all.hpp.html
title: algorithm/count_all.hpp
---
