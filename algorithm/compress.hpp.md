---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: meta/settings.hpp
    title: meta/settings.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: algorithm/all.hpp
    title: algorithm/all.hpp
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
  bundledCode: "#line 2 \"algorithm/compress.hpp\"\n#include <algorithm>\n#include\
    \ <functional>\n#include <iterator>\n#include <unordered_map>\n#include <vector>\n\
    #line 2 \"meta/settings.hpp\"\n#include <cstdint>\n\n#ifndef KYOPRO_BASE_INT\n\
    #define KYOPRO_BASE_INT std::int64_t\n#endif\n\n#ifndef KYOPRO_BASE_UINT\n#define\
    \ KYOPRO_BASE_UINT std::uint64_t\n#endif\n\n#ifndef KYOPRO_BASE_FLOAT\n#define\
    \ KYOPRO_BASE_FLOAT double\n#endif\n\n#ifndef KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD\
    \ static_cast<KYOPRO_BASE_UINT>(998244353)\n#endif\n\n#ifndef KYOPRO_DECIMAL_PRECISION\n\
    #define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n#endif\n\n\
    #ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 8 \"algorithm/compress.hpp\"\n\nnamespace kyopro {\n  inline constexpr\
    \ struct {\n    template<class T, class Container = std::unordered_map<typename\
    \ std::iterator_traits<T>::value_type, KYOPRO_BASE_INT>, class Compare>\n    constexpr\
    \ auto operator ()(T first, T last, Compare comp = std::less<typename std::iterator_traits<T>::value_type>())\
    \ {\n      std::vector<typename std::iterator_traits<T>::value_type> vec(first,\
    \ last);\n      std::sort(vec.begin(), vec.end(), comp);\n      auto end = std::unique(vec.begin(),\
    \ vec.end());\n      Container mem;\n      int cnt = -1;\n      for (auto i =\
    \ vec.begin(); i != end; ++i) mem[*i] = ++cnt;\n      return mem;\n    }\n  }\
    \ compress;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <functional>\n#include <iterator>\n\
    #include <unordered_map>\n#include <vector>\n#include \"../meta/settings.hpp\"\
    \n\nnamespace kyopro {\n  inline constexpr struct {\n    template<class T, class\
    \ Container = std::unordered_map<typename std::iterator_traits<T>::value_type,\
    \ KYOPRO_BASE_INT>, class Compare>\n    constexpr auto operator ()(T first, T\
    \ last, Compare comp = std::less<typename std::iterator_traits<T>::value_type>())\
    \ {\n      std::vector<typename std::iterator_traits<T>::value_type> vec(first,\
    \ last);\n      std::sort(vec.begin(), vec.end(), comp);\n      auto end = std::unique(vec.begin(),\
    \ vec.end());\n      Container mem;\n      int cnt = -1;\n      for (auto i =\
    \ vec.begin(); i != end; ++i) mem[*i] = ++cnt;\n      return mem;\n    }\n  }\
    \ compress;\n}"
  dependsOn:
  - meta/settings.hpp
  isVerificationFile: false
  path: algorithm/compress.hpp
  requiredBy:
  - all.hpp
  - algorithm/all.hpp
  - all/all.hpp
  timestamp: '2022-07-07 01:22:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/compress.hpp
layout: document
redirect_from:
- /library/algorithm/compress.hpp
- /library/algorithm/compress.hpp.html
title: algorithm/compress.hpp
---
