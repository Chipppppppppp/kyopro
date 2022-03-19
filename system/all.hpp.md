---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/power.hpp
    title: math/power.hpp
  - icon: ':heavy_check_mark:'
    path: meta/settings.hpp
    title: meta/settings.hpp
  - icon: ':heavy_check_mark:'
    path: meta/trait.hpp
    title: meta/trait.hpp
  - icon: ':heavy_check_mark:'
    path: system/in.hpp
    title: system/in.hpp
  - icon: ':heavy_check_mark:'
    path: system/out.hpp
    title: system/out.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: yosupo/UnionFind.test.cpp
    title: yosupo/UnionFind.test.cpp
  - icon: ':heavy_check_mark:'
    path: yosupo/many_aplusb.test.cpp
    title: yosupo/many_aplusb.test.cpp
  - icon: ':heavy_check_mark:'
    path: yosupo/point_add_range_sum.test.cpp
    title: yosupo/point_add_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"system/in.hpp\"\n#include <unistd.h>\n#include <array>\n\
    #include <cstddef>\n#include <cstdint>\n#include <cstdio>\n#include <string>\n\
    #include <tuple>\n#include <type_traits>\n#include <utility>\n#line 3 \"meta/settings.hpp\"\
    \n\n#ifndef KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT std::int64_t\n#endif\n\n\
    #ifndef KYOPRO_BASE_UINT\n#define KYOPRO_BASE_UINT std::uint64_t\n#endif\n\n#ifndef\
    \ KYOPRO_BASE_FLOAT\n#define KYOPRO_BASE_FLOAT double\n#endif\n\n#ifndef KYOPRO_DEFAULT_MOD\n\
    #define KYOPRO_DEFAULT_MOD static_cast<KYOPRO_BASE_UINT>(998244353)\n#endif\n\n\
    #ifndef KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n\
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
    \ _size>\n  struct int_least {\n  private:\n    static constexpr auto _get_type()\
    \ noexcept {\n      if constexpr (_size <= 8) return std::declval<std::int_least8_t>();\n\
    \      if constexpr (_size <= 16) return std::declval<std::int_least16_t>();\n\
    \      if constexpr (_size <= 32) return std::declval<std::int_least32_t>();\n\
    \      if constexpr (_size <= 64) return std::declval<std::int_least64_t>();\n\
    \      static_assert(_size <= 128, \"Integer size is too long\");\n      return\
    \ std::declval<__int128_t>();\n    }\n\n  public:\n    using type = decltype(_get_type());\n\
    \  };\n\n  template<KYOPRO_BASE_UINT _size>\n  using int_least_t = typename int_least<_size>::type;\n\
    \n  template<KYOPRO_BASE_UINT _size>\n  struct uint_least {\n  private:\n    static\
    \ constexpr auto _get_type() noexcept {\n      if constexpr (_size <= 8) return\
    \ std::declval<std::uint_least8_t>();\n      if constexpr (_size <= 16) return\
    \ std::declval<std::uint_least16_t>();\n      if constexpr (_size <= 32) return\
    \ std::declval<std::uint_least32_t>();\n      if constexpr (_size <= 64) return\
    \ std::declval<std::uint_least64_t>();\n      static_assert(_size <= 128, \"Integer\
    \ size is too long\");\n      return std::declval<__uint128_t>();\n    }\n\n \
    \ public:\n    using type = decltype(_get_type());\n  };\n\n  template<KYOPRO_BASE_UINT\
    \ _size>\n  using uint_least_t = typename uint_least<_size>::type;\n\n  template<class,\
    \ class = void>\n  struct is_iterator: std::false_type {};\n  template<class _typeT>\n\
    \  struct is_iterator<_typeT, std::void_t<typename std::iterator_traits<_typeT>::iterator_category>>:\
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
    }\n#line 13 \"system/out.hpp\"\n\nnamespace kyopro {\n  template<KYOPRO_BASE_UINT\
    \ _buf_size = KYOPRO_BUFFER_SIZE>\n  struct Writer {\n  private:\n    int _fd,\
    \ _idx;\n    std::array<char, _buf_size> _buffer;\n\n  public:\n    Writer() noexcept\
    \ = default;\n    Writer(int _fd) noexcept: _fd(_fd), _idx(0), _buffer() {}\n\
    \    Writer(FILE* _fp) noexcept: _fd(fileno(_fp)), _idx(0), _buffer() {}\n\n \
    \   ~Writer() {\n      write(_fd, _buffer.begin(), _idx);\n    }\n\n    struct\
    \ iterator {\n    private:\n      Writer& _writer;\n\n    public:\n      using\
    \ difference_type = void;\n      using value_type = void;\n      using pointer\
    \ = void;\n      using reference = void;\n      using iterator_category = std::output_iterator_tag;\n\
    \n      iterator() noexcept = default;\n      iterator(Writer& _writer) noexcept:\
    \ _writer(_writer) {}\n\n      iterator& operator ++() {\n        ++_writer._idx;\n\
    \        if (_writer._idx == _buf_size) {\n          write(_writer._fd, _writer._buffer.begin(),\
    \ _buf_size);\n          _writer._idx = 0;\n        }\n        return *this;\n\
    \      }\n\n      iterator operator ++(int) {\n        iterator _before = *this;\n\
    \        operator ++();\n        return _before;\n      }\n\n      char& operator\
    \ *() const {\n        return _writer._buffer[_writer._idx];\n      }\n\n    \
    \  void flush() const {\n        write(_writer._fd, _writer._buffer.begin(), _writer._idx);\n\
    \      }\n    };\n\n    iterator begin() noexcept {\n      return iterator(*this);\n\
    \    }\n  };\n\n  Writer output(1), error(2);\n\n  template<class _typeIterator,\
    \ bool _sep = true, bool _end = true, bool _debug = false, bool _comment = false,\
    \ bool _flush = false, KYOPRO_BASE_UINT _decimal_precision = KYOPRO_DECIMAL_PRECISION>\n\
    \  struct Printer {\n  private:\n    template<class, class = void>\n    struct\
    \ _has_print: std::false_type {};\n    template<class _typeT>\n    struct _has_print<_typeT,\
    \ std::void_t<decltype(std::declval<_typeT>().print(std::declval<Printer&>()))>>:\
    \ std::true_type {};\n\n    void _print_sep() {\n      if constexpr (_debug) {\n\
    \        print(',');\n      }\n      print(' ');\n    }\n\n  public:\n    static\
    \ constexpr bool sep = _sep, end = _end, debug = _debug, flush = _flush;\n   \
    \ static constexpr KYOPRO_BASE_UINT decimal_precision = _decimal_precision;\n\n\
    \    _typeIterator itr;\n\n    Printer() noexcept = default;\n    Printer(_typeIterator\
    \ _itr) noexcept: itr(_itr) {}\n\n    void print(char _a) {\n      *itr = _a;\n\
    \      ++itr;\n    }\n    void print(const char* _a) {\n      for (; *_a; ++_a)\
    \ print(*_a);\n    }\n    void print(const std::string& _a) {\n      for (auto\
    \ _i: _a) print(_i);\n    }\n    void print(bool _a) {\n      print(static_cast<char>('0'\
    \ + _a));\n    }\n    template<class _typeT, std::enable_if_t<std::is_arithmetic_v<_typeT>\
    \ && !_has_print<_typeT>::value>* = nullptr>\n    void print(_typeT _a) {\n  \
    \    if constexpr (std::is_signed_v<_typeT>) if (_a < 0) {\n        print('-');\n\
    \        _a = -_a;\n      }\n      std::uint_fast64_t _p = _a;\n      _a -= _p;\n\
    \      std::string _s;\n      do {\n        _s += '0' + _p % 10;\n        _p /=\
    \ 10;\n      } while (_p > 0);\n      for (auto _i = _s.rbegin(); _i != _s.rend();\
    \ ++_i) print(*_i);\n      if constexpr (std::is_integral_v<_typeT>) return;\n\
    \      print('.');\n      for (int _i = 0; _i < static_cast<int>(_decimal_precision);\
    \ ++_i) {\n        _a *= 10;\n        print('0' + static_cast<std::uint_fast64_t>(_a)\
    \ % 10);\n      }\n    }\n    template<std::size_t _i = 0, class _typeT, std::enable_if_t<is_tuple_v<_typeT>\
    \ && !_has_print<_typeT>::value>* = nullptr>\n    void print(const _typeT& _a)\
    \ {\n      if constexpr (_debug && _i == 0) print('{');\n      if constexpr (std::tuple_size_v<_typeT>\
    \ != 0) print(std::get<_i>(_a));\n      if constexpr (_i + 1 < std::tuple_size_v<_typeT>)\
    \ {\n        if constexpr (_sep) _print_sep();\n        print<_i + 1>(_a);\n \
    \     } else if constexpr (_debug) print('}');\n    }\n    template<class _typeT,\
    \ std::enable_if_t<is_iterable_v<_typeT> && !_has_print<_typeT>::value>* = nullptr>\n\
    \    void print(const _typeT& _a) {\n      if constexpr (_debug) print('{');\n\
    \      if (std::empty(_a)) return;\n      for (auto _i = std::begin(_a); ; ) {\n\
    \        print(*_i);\n        if (++_i != std::end(_a)) {\n          if constexpr\
    \ (_sep) {\n            if constexpr (_debug) {\n              print(',');\n \
    \             print(' ');\n            } else if constexpr (std::is_arithmetic_v<std::decay_t<decltype(std::declval<_typeT>()[0])>>)\
    \ print(' ');\n            else print('\\n');\n          }\n        } else break;\n\
    \      }\n      if constexpr (_debug) print('}');\n    }\n    template<class _typeT,\
    \ std::enable_if_t<_has_print<_typeT>::value>* = nullptr>\n    void print(const\
    \ _typeT& _a) {\n      _a.print(*this);\n    }\n\n    template<bool _first = true>\n\
    \    void operator ()() {\n      if constexpr (_comment && _first) print('#');\n\
    \      if constexpr (_end) print('\\n');\n      if constexpr (_flush) itr._flush();\n\
    \    }\n    template<bool _first = true, class _typeHead, class... _typeArgs>\n\
    \    void operator ()(_typeHead&& _head, _typeArgs&&... _args) {\n      if constexpr\
    \ (_comment && _first) print('#');\n      if constexpr (_sep && !_first) _print_sep();\n\
    \      print(_head);\n      operator ()<false>(std::forward<_typeArgs>(_args)...);\n\
    \    }\n  };\n\n  Printer<Writer<>::iterator, false, false> print(output.begin()),\
    \ eprint(error.begin());\n  Printer<Writer<>::iterator> println(output.begin()),\
    \ eprintln(error.begin());\n  Printer<Writer<>::iterator, true, true, true, true>\
    \ debug(output.begin()), edebug(error.begin());\n}\n#line 4 \"system/all.hpp\"\
    \n"
  code: '#pragma once

    #include "in.hpp"

    #include "out.hpp"'
  dependsOn:
  - system/in.hpp
  - math/power.hpp
  - meta/settings.hpp
  - meta/trait.hpp
  - system/out.hpp
  isVerificationFile: false
  path: system/all.hpp
  requiredBy: []
  timestamp: '2022-03-19 00:51:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - yosupo/UnionFind.test.cpp
  - yosupo/point_add_range_sum.test.cpp
  - yosupo/many_aplusb.test.cpp
documentation_of: system/all.hpp
layout: document
redirect_from:
- /library/system/all.hpp
- /library/system/all.hpp.html
title: system/all.hpp
---
