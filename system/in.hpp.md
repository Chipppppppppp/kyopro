---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/power.hpp
    title: math/power.hpp
  - icon: ':x:'
    path: meta/settings.hpp
    title: meta/settings.hpp
  - icon: ':x:'
    path: meta/trait.hpp
    title: meta/trait.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  - icon: ':x:'
    path: system/all.hpp
    title: system/all.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: yosupo/UnionFind.test.cpp
    title: yosupo/UnionFind.test.cpp
  - icon: ':x:'
    path: yosupo/many_aplusb.test.cpp
    title: yosupo/many_aplusb.test.cpp
  - icon: ':x:'
    path: yosupo/point_add_range_sum.test.cpp
    title: yosupo/point_add_range_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"system/in.hpp\"\n#include <unistd.h>\n#include <array>\n\
    #include <cstddef>\n#include <cstdint>\n#include <cstdio>\n#include <string>\n\
    #include <tuple>\n#include <type_traits>\n#include <utility>\n#line 3 \"meta/settings.hpp\"\
    \n\n#ifndef KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT std::int64_t\n#endif\n\n\
    #ifndef KYOPRO_BASE_UINT\n#define KYOPRO_BASE_UINT std::uint64_t\n#endif\n\n#ifndef\
    \ KYOPRO_BASE_FLOAT\n#define KYOPRO_BASE_FLOAT double\n#endif\n\n#ifndef KYOPRO_DEFAULT_MOD\n\
    #define KYOPRO_DEFAULT_MOD static_cast<KYOPRO_BASE_UINT>(1000000007)\n#endif\n\
    \n#ifndef KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n\
    #endif\n\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 3 \"math/power.hpp\"\n\nnamespace kyopro {\n  template<class _typeT>\n\
    \  constexpr _typeT power(_typeT _a, KYOPRO_BASE_UINT _n, _typeT _init = 1) noexcept\
    \ {\n    while (_n > 0) {\n      if (_n & 1) _init *= _a;\n      _a *= _a;\n \
    \     _n >>= 1;\n    }\n    return _init;\n  }\n}\n#line 2 \"meta/trait.hpp\"\n\
    #include <iterator>\n#include <queue>\n#include <limits>\n#include <stack>\n#line\
    \ 9 \"meta/trait.hpp\"\n\ntemplate<>\nstruct std::is_integral<__int128_t>: std::true_type\
    \ {};\ntemplate<>\nstruct std::is_signed<__int128_t>: std::true_type {};\ntemplate<>\n\
    struct std::is_integral<__uint128_t>: std::true_type {};\ntemplate<>\nstruct std::is_unsigned<__uint128_t>:\
    \ std::true_type {};\n#ifdef __SIZEOF_FLOAT128__\ntemplate<>\nstruct std::is_floating_point<__float128>:\
    \ std::true_type {};\n#endif\n\nnamespace kyopro {\n  template<KYOPRO_BASE_UINT\
    \ _size>\n  struct int_least {\n  private:\n    auto _get_type() const noexcept\
    \ {\n      if constexpr (_size <= 8) return std::declval<std::int_least8_t>();\n\
    \      if constexpr (_size <= 16) return std::declval<std::int_least16_t>();\n\
    \      if constexpr (_size <= 32) return std::declval<std::int_least32_t>();\n\
    \      if constexpr (_size <= 64) return std::declval<std::int_least64_t>();\n\
    \      static_assert(_size <= 128, \"Integer size is too long\");\n      return\
    \ std::declval<__int128_t>();\n    }\n\n  public:\n    using type = decltype(_get_type());\n\
    \  };\n\n  template<KYOPRO_BASE_UINT _size>\n  using int_least_t = int_least<_size>::type;\n\
    \n  template<KYOPRO_BASE_UINT _size>\n  struct uint_least {\n  private:\n    auto\
    \ _get_type() const noexcept {\n      if constexpr (_size <= 8) return std::declval<std::uint_least8_t>();\n\
    \      if constexpr (_size <= 16) return std::declval<std::uint_least16_t>();\n\
    \      if constexpr (_size <= 32) return std::declval<std::uint_least32_t>();\n\
    \      if constexpr (_size <= 64) return std::declval<std::uint_least64_t>();\n\
    \      static_assert(_size <= 128, \"Integer size is too long\");\n      return\
    \ std::declval<__uint128_t>();\n    }\n\n  public:\n    using type = decltype(_get_type());\n\
    \  };\n\n  template<KYOPRO_BASE_UINT _size>\n  using uint_least_t = uint_least<_size>::type;\n\
    \n  template<class, class = void>\n  struct is_iterator: std::false_type {};\n\
    \  template<class _typeT>\n  struct is_iterator<_typeT, std::void_t<typename std::iterator_traits<_typeT>::iterator_category>>:\
    \ std::true_type {};\n\n  template<class _typeT>\n  constexpr bool is_iterator_v\
    \ = is_iterator<_typeT>::value;\n\n  template<class, class = void>\n  struct is_iterable:\
    \ std::false_type {};\n  template<class _typeT>\n  struct is_iterable<_typeT,\
    \ std::enable_if_t<is_iterator_v<decltype(std::begin(std::declval<_typeT>()))>>>:\
    \ std::true_type {};\n\n  template<class _typeT>\n  constexpr bool is_iterable_v\
    \ = is_iterable<_typeT>::value;\n\n  template<class>\n  struct is_tuple: std::false_type\
    \ {};\n  template<class _typeT, class _typeU>\n  struct is_tuple<std::pair<_typeT,\
    \ _typeU>>: std::true_type {};\n  template<class... _typeArgs>\n  struct is_tuple<std::tuple<_typeArgs...>>:\
    \ std::true_type {};\n\n  template<class _typeT>\n  constexpr bool is_tuple_v\
    \ = is_tuple<_typeT>::value;\n\n  template<class, class = void>\n  struct is_container_adapter:\
    \ std::false_type {};\n  template<class _typeT>\n  struct is_container_adapter<_typeT,\
    \ std::void_t<decltype(std::empty(std::declval<_typeT>()))>>: std::negation<is_iterable<_typeT>>\
    \ {};\n\n  template<class _typeT>\n  constexpr bool is_container_adapter_v = is_container_adapter<_typeT>::value;\n\
    }\n#line 14 \"system/in.hpp\"\n\nnamespace kyopro {\n  template<KYOPRO_BASE_UINT\
    \ _buf_size = KYOPRO_BUFFER_SIZE>\n  struct Reader {\n  private:\n    int _fd,\
    \ _idx;\n    std::array<char, _buf_size> _buffer;\n\n  public:\n    Reader() {\n\
    \      read(_fd, _buffer.begin(), _buf_size);\n    }\n    Reader(int _fd): _fd(_fd),\
    \ _idx(0), _buffer() {\n      read(_fd, _buffer.begin(), _buf_size);\n    }\n\
    \    Reader(FILE* _fp): _fd(fileno(_fp)), _idx(0), _buffer() {\n      read(_fd,\
    \ _buffer.begin(), _buf_size);\n    }\n\n    struct iterator {\n    private:\n\
    \      Reader& _reader;\n\n    public:\n      using difference_type = void;\n\
    \      using value_type = void;\n      using pointer = void;\n      using reference\
    \ = void;\n      using iterator_category = std::input_iterator_tag;\n\n      iterator()\
    \ noexcept = default;\n      iterator(Reader& _reader) noexcept: _reader(_reader)\
    \ {}\n\n      iterator& operator ++() {\n        ++_reader._idx;\n        if (_reader._idx\
    \ == _buf_size) {\n          read(_reader._fd, _reader._buffer.begin(), _buf_size);\n\
    \          _reader._idx = 0;\n        }\n        return *this;\n      }\n\n  \
    \    iterator operator ++(int) {\n        iterator _before = *this;\n        operator\
    \ ++();\n        return _before;\n      }\n\n      char& operator *() const {\n\
    \        return _reader._buffer[_reader._idx];\n      }\n    };\n\n    iterator\
    \ begin() noexcept {\n      return iterator(*this);\n    }\n  };\n\n  Reader input(0);\n\
    \n  template<class _typeIterator, KYOPRO_BASE_UINT _decimal_precision = KYOPRO_DECIMAL_PRECISION>\n\
    \  struct Scanner {\n  private:\n    template<class, class = void>\n    struct\
    \ _has_scan: std::false_type {};\n    template<class _typeT>\n    struct _has_scan<_typeT,\
    \ std::void_t<decltype(std::declval<_typeT>().scan(std::declval<Scanner&>()))>>:\
    \ std::true_type {};\n\n  public:\n    static constexpr KYOPRO_BASE_UINT decimal_precision\
    \ = _decimal_precision;\n    _typeIterator itr;\n\n    Scanner() noexcept = default;\n\
    \    Scanner(_typeIterator _itr) noexcept: itr(_itr) {}\n\n    void discard_space()\
    \ {\n      while (('\\t' <= *itr && *itr <= '\\r') || *itr == ' ') ++itr;\n  \
    \  }\n\n    void scan(char& _a) {\n      discard_space();\n      _a = *itr;\n\
    \      ++itr;\n    }\n    void scan(std::string& _a) {\n      discard_space();\n\
    \      for (auto& _i: _a) {\n        _i = *itr;\n        ++itr;\n      }\n   \
    \ }\n    void scan(bool& _a) {\n      discard_space();\n      while ('0' <= *itr\
    \ && *itr <= '9') {\n        if (*itr != '0') _a = true;\n        ++itr;\n   \
    \   }\n    }\n    template<class _typeT, std::enable_if_t<std::is_arithmetic_v<_typeT>\
    \ && !_has_scan<_typeT>::value>* = nullptr>\n    void scan(_typeT& _a) {\n   \
    \   discard_space();\n      bool _sgn = false;\n      if constexpr (!std::is_unsigned_v<_typeT>)\
    \ if (*itr == '-') {\n        _sgn = true;\n        ++itr;\n      }\n      _a\
    \ = 0;\n      for (; '0' <= *itr && *itr <= '9'; ++itr) _a = _a * 10 + *itr -\
    \ '0';\n      if (*itr == '.') {\n        ++itr;\n        if constexpr (std::is_floating_point_v<_typeT>)\
    \ {\n          constexpr std::uint_fast64_t _power_decimal_precision = power(10ULL,\
    \ _decimal_precision);\n          _typeT _d = 0;\n          std::uint_fast64_t\
    \ _i = 1;\n          for (; '0' <= *itr && *itr <= '9' && _i < _power_decimal_precision;\
    \ _i *= 10) {\n            _d = _d * 10 + *itr - '0';\n            ++itr;\n  \
    \        }\n          _a += _d / _i;\n        }\n        while ('0' <= *itr &&\
    \ *itr <= '9') ++itr;\n      }\n      if constexpr (!std::is_unsigned_v<_typeT>)\
    \ if (_sgn) _a = -_a;\n    }\n    template<std::size_t _i = 0, class _typeT, std::enable_if_t<is_tuple_v<_typeT>\
    \ && !_has_scan<_typeT>::value>* = nullptr>\n    void scan(_typeT& _a) {\n   \
    \   if constexpr (_i < std::tuple_size_v<_typeT>) {\n        scan(std::get<_i>(_a));\n\
    \        scan<_i + 1>(_a);\n      }\n    }\n    template<class _typeT, std::enable_if_t<is_iterable_v<_typeT>\
    \ && !_has_scan<_typeT>::value>* = nullptr>\n    void scan(_typeT& _a) {\n   \
    \   for (auto& _i: _a) scan(_i);\n    }\n    template<class _typeT, std::enable_if_t<_has_scan<_typeT>::value>*\
    \ = nullptr>\n    void scan(_typeT& _a) {\n      _a.scan(*this);\n    }\n\n  \
    \  void operator ()() {}\n    template<class _typeHead, class... _typeArgs>\n\
    \    void operator ()(_typeHead& _head, _typeArgs&... _args) {\n      scan(_head);\n\
    \      operator ()(_args...);\n    }\n  };\n\n  Scanner<Reader<>::iterator> scan(input.begin());\n\
    }\n"
  code: "#pragma once\n#include <unistd.h>\n#include <array>\n#include <cstddef>\n\
    #include <cstdint>\n#include <cstdio>\n#include <string>\n#include <tuple>\n#include\
    \ <type_traits>\n#include <utility>\n#include \"../math/power.hpp\"\n#include\
    \ \"../meta/settings.hpp\"\n#include \"../meta/trait.hpp\"\n\nnamespace kyopro\
    \ {\n  template<KYOPRO_BASE_UINT _buf_size = KYOPRO_BUFFER_SIZE>\n  struct Reader\
    \ {\n  private:\n    int _fd, _idx;\n    std::array<char, _buf_size> _buffer;\n\
    \n  public:\n    Reader() {\n      read(_fd, _buffer.begin(), _buf_size);\n  \
    \  }\n    Reader(int _fd): _fd(_fd), _idx(0), _buffer() {\n      read(_fd, _buffer.begin(),\
    \ _buf_size);\n    }\n    Reader(FILE* _fp): _fd(fileno(_fp)), _idx(0), _buffer()\
    \ {\n      read(_fd, _buffer.begin(), _buf_size);\n    }\n\n    struct iterator\
    \ {\n    private:\n      Reader& _reader;\n\n    public:\n      using difference_type\
    \ = void;\n      using value_type = void;\n      using pointer = void;\n     \
    \ using reference = void;\n      using iterator_category = std::input_iterator_tag;\n\
    \n      iterator() noexcept = default;\n      iterator(Reader& _reader) noexcept:\
    \ _reader(_reader) {}\n\n      iterator& operator ++() {\n        ++_reader._idx;\n\
    \        if (_reader._idx == _buf_size) {\n          read(_reader._fd, _reader._buffer.begin(),\
    \ _buf_size);\n          _reader._idx = 0;\n        }\n        return *this;\n\
    \      }\n\n      iterator operator ++(int) {\n        iterator _before = *this;\n\
    \        operator ++();\n        return _before;\n      }\n\n      char& operator\
    \ *() const {\n        return _reader._buffer[_reader._idx];\n      }\n    };\n\
    \n    iterator begin() noexcept {\n      return iterator(*this);\n    }\n  };\n\
    \n  Reader input(0);\n\n  template<class _typeIterator, KYOPRO_BASE_UINT _decimal_precision\
    \ = KYOPRO_DECIMAL_PRECISION>\n  struct Scanner {\n  private:\n    template<class,\
    \ class = void>\n    struct _has_scan: std::false_type {};\n    template<class\
    \ _typeT>\n    struct _has_scan<_typeT, std::void_t<decltype(std::declval<_typeT>().scan(std::declval<Scanner&>()))>>:\
    \ std::true_type {};\n\n  public:\n    static constexpr KYOPRO_BASE_UINT decimal_precision\
    \ = _decimal_precision;\n    _typeIterator itr;\n\n    Scanner() noexcept = default;\n\
    \    Scanner(_typeIterator _itr) noexcept: itr(_itr) {}\n\n    void discard_space()\
    \ {\n      while (('\\t' <= *itr && *itr <= '\\r') || *itr == ' ') ++itr;\n  \
    \  }\n\n    void scan(char& _a) {\n      discard_space();\n      _a = *itr;\n\
    \      ++itr;\n    }\n    void scan(std::string& _a) {\n      discard_space();\n\
    \      for (auto& _i: _a) {\n        _i = *itr;\n        ++itr;\n      }\n   \
    \ }\n    void scan(bool& _a) {\n      discard_space();\n      while ('0' <= *itr\
    \ && *itr <= '9') {\n        if (*itr != '0') _a = true;\n        ++itr;\n   \
    \   }\n    }\n    template<class _typeT, std::enable_if_t<std::is_arithmetic_v<_typeT>\
    \ && !_has_scan<_typeT>::value>* = nullptr>\n    void scan(_typeT& _a) {\n   \
    \   discard_space();\n      bool _sgn = false;\n      if constexpr (!std::is_unsigned_v<_typeT>)\
    \ if (*itr == '-') {\n        _sgn = true;\n        ++itr;\n      }\n      _a\
    \ = 0;\n      for (; '0' <= *itr && *itr <= '9'; ++itr) _a = _a * 10 + *itr -\
    \ '0';\n      if (*itr == '.') {\n        ++itr;\n        if constexpr (std::is_floating_point_v<_typeT>)\
    \ {\n          constexpr std::uint_fast64_t _power_decimal_precision = power(10ULL,\
    \ _decimal_precision);\n          _typeT _d = 0;\n          std::uint_fast64_t\
    \ _i = 1;\n          for (; '0' <= *itr && *itr <= '9' && _i < _power_decimal_precision;\
    \ _i *= 10) {\n            _d = _d * 10 + *itr - '0';\n            ++itr;\n  \
    \        }\n          _a += _d / _i;\n        }\n        while ('0' <= *itr &&\
    \ *itr <= '9') ++itr;\n      }\n      if constexpr (!std::is_unsigned_v<_typeT>)\
    \ if (_sgn) _a = -_a;\n    }\n    template<std::size_t _i = 0, class _typeT, std::enable_if_t<is_tuple_v<_typeT>\
    \ && !_has_scan<_typeT>::value>* = nullptr>\n    void scan(_typeT& _a) {\n   \
    \   if constexpr (_i < std::tuple_size_v<_typeT>) {\n        scan(std::get<_i>(_a));\n\
    \        scan<_i + 1>(_a);\n      }\n    }\n    template<class _typeT, std::enable_if_t<is_iterable_v<_typeT>\
    \ && !_has_scan<_typeT>::value>* = nullptr>\n    void scan(_typeT& _a) {\n   \
    \   for (auto& _i: _a) scan(_i);\n    }\n    template<class _typeT, std::enable_if_t<_has_scan<_typeT>::value>*\
    \ = nullptr>\n    void scan(_typeT& _a) {\n      _a.scan(*this);\n    }\n\n  \
    \  void operator ()() {}\n    template<class _typeHead, class... _typeArgs>\n\
    \    void operator ()(_typeHead& _head, _typeArgs&... _args) {\n      scan(_head);\n\
    \      operator ()(_args...);\n    }\n  };\n\n  Scanner<Reader<>::iterator> scan(input.begin());\n\
    }"
  dependsOn:
  - math/power.hpp
  - meta/settings.hpp
  - meta/trait.hpp
  isVerificationFile: false
  path: system/in.hpp
  requiredBy:
  - all.hpp
  - system/all.hpp
  timestamp: '2022-03-17 14:38:24+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - yosupo/UnionFind.test.cpp
  - yosupo/point_add_range_sum.test.cpp
  - yosupo/many_aplusb.test.cpp
documentation_of: system/in.hpp
layout: document
redirect_from:
- /library/system/in.hpp
- /library/system/in.hpp.html
title: system/in.hpp
---
