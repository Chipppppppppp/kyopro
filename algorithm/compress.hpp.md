---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: meta/settings.hpp
    title: meta/settings.hpp
  _extendedRequiredBy: []
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
    #endif\n#line 8 \"algorithm/compress.hpp\"\n\nnamespace kyopro {\n  template<class\
    \ _typeT, class _typeContainer = std::unordered_map<typename std::iterator_traits<_typeT>::value_type,\
    \ KYOPRO_BASE_INT>, class _typeCompare>\n  auto compress(_typeT _first, _typeT\
    \ _last, _typeCompare _comp = std::less<typename std::iterator_traits<_typeT>::value_type>())\
    \ {\n    std::vector<typename iterator_traits<T>::value_type> _vec(_first, _last);\n\
    \    std::sort(_vec.begin(), _vec.end(), _comp);\n    auto _end = std::unique(_vec.begin(),\
    \ _vec.end());\n    _typeContainer _mem;\n    int _cnt = -1;\n    for (auto _i\
    \ = _vec.begin(); _i != _end; ++_i) _mem[*_i] = ++_cnt;\n    return _mem;\n  }\n\
    }\n"
  code: "#pragma once\n#include <algorithm>\n#include <functional>\n#include <iterator>\n\
    #include <unordered_map>\n#include <vector>\n#include \"../meta/settings.hpp\"\
    \n\nnamespace kyopro {\n  template<class _typeT, class _typeContainer = std::unordered_map<typename\
    \ std::iterator_traits<_typeT>::value_type, KYOPRO_BASE_INT>, class _typeCompare>\n\
    \  auto compress(_typeT _first, _typeT _last, _typeCompare _comp = std::less<typename\
    \ std::iterator_traits<_typeT>::value_type>()) {\n    std::vector<typename iterator_traits<T>::value_type>\
    \ _vec(_first, _last);\n    std::sort(_vec.begin(), _vec.end(), _comp);\n    auto\
    \ _end = std::unique(_vec.begin(), _vec.end());\n    _typeContainer _mem;\n  \
    \  int _cnt = -1;\n    for (auto _i = _vec.begin(); _i != _end; ++_i) _mem[*_i]\
    \ = ++_cnt;\n    return _mem;\n  }\n}"
  dependsOn:
  - meta/settings.hpp
  isVerificationFile: false
  path: algorithm/compress.hpp
  requiredBy: []
  timestamp: '2022-04-07 18:08:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/compress.hpp
layout: document
redirect_from:
- /library/algorithm/compress.hpp
- /library/algorithm/compress.hpp.html
title: algorithm/compress.hpp
---
