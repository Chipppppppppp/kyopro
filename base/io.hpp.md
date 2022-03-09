---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: base/in.hpp
    title: base/in.hpp
  - icon: ':heavy_check_mark:'
    path: base/out.hpp
    title: base/out.hpp
  - icon: ':heavy_check_mark:'
    path: base/settings.hpp
    title: base/settings.hpp
  - icon: ':heavy_check_mark:'
    path: base/trait.hpp
    title: base/trait.hpp
  - icon: ':heavy_check_mark:'
    path: math/power.hpp
    title: math/power.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  - icon: ':warning:'
    path: base/all.hpp
    title: base/all.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"base/in.hpp\"\n#include <unistd.h>\n#include <array>\n#include\
    \ <cstdint>\n#include <cstdio>\n#include <iterator>\n#include <string>\n#include\
    \ <tuple>\n#include <type_traits>\n#include <utility>\n#line 3 \"base/settings.hpp\"\
    \n\n#ifndef KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT std::int64_t\n#endif\n\n\
    #ifndef KYOPRO_BASE_UINT\n#define KYOPRO_BASE_UINT std::size_t\n#endif\n\n#ifndef\
    \ KYOPRO_BASE_FLOAT\n#define KYOPRO_BASE_FLOAT double\n#endif\n\n#ifndef KYOPRO_DEFAULT_MOD\n\
    #define KYOPRO_DEFAULT_MOD static_cast<KYOPRO_BASE_UINT>(1000000007)\n#endif\n\
    \n#ifndef KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n\
    #endif\n\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 4 \"math/power.hpp\"\nnamespace kyopro {\n  template<class _typeT>\n\
    \  constexpr _typeT power(_typeT _a, std::uint_fast64_t _n, _typeT _init = 1)\
    \ noexcept {\n    while (_n > 0) {\n      if (_n & 1) _init *= _a;\n      _a *=\
    \ _a;\n      _n >>= 1;\n    }\n    return _init;\n  }\n}\n#line 3 \"base/trait.hpp\"\
    \n#include <queue>\n#include <stack>\n#line 7 \"base/trait.hpp\"\n\n#ifdef __SIZEOF_INT128__\n\
    template<>\nstruct std::is_integral<__int128_t>: std::true_type {};\ntemplate<>\n\
    struct std::is_signed<__int128_t>: std::true_type {};\ntemplate<>\nstruct std::is_integral<__uint128_t>:\
    \ std::true_type {};\ntemplate<>\nstruct std::is_unsigned<__uint128_t>: std::true_type\
    \ {};\n#endif\n#ifdef __SIZEOF_FLOAT128__\ntemplate<>\nstruct std::is_floating_point<__float128>:\
    \ std::true_type {};\n#endif\n\nnamespace kyopro {\n  template<class, class =\
    \ void>\n  struct is_iterator: std::false_type {};\n  template<class _typeT>\n\
    \  struct is_iterator<_typeT, std::void_t<typename std::iterator_traits<_typeT>::iterator_category>>:\
    \ std::true_type {};\n  template<class _typeT>\n  constexpr bool is_iterator_v\
    \ = is_iterator<_typeT>::value;\n\n  template<class, class = void>\n  struct is_iterable:\
    \ std::false_type {};\n  template<class _typeT>\n  struct is_iterable<_typeT,\
    \ std::void_t<typename _typeT::iterator>>: std::true_type {};\n  template<class\
    \ _typeT>\n  constexpr bool is_iterable_v = is_iterable<_typeT>::value;\n\n  template<class>\n\
    \  struct is_tuple: std::false_type {};\n  template<class _typeT, class U>\n \
    \ struct is_tuple<std::pair<_typeT, U>>: std::true_type {};\n  template<class...\
    \ Args>\n  struct is_tuple<std::tuple<Args...>>: std::true_type {};\n  template<class\
    \ _typeT>\n  constexpr bool is_tuple_v = is_tuple<_typeT>::value;\n\n  template<class,\
    \ class = void>\n  struct is_container_adapter: std::false_type {};\n  template<class\
    \ _typeT>\n  struct is_container_adapter<_typeT, std::void_t<decltype(std::empty(std::declval<_typeT>()))>>:\
    \ std::negation<is_iterable<_typeT>> {};\n  template<class _typeT>\n  constexpr\
    \ bool is_container_adapter_v = is_container_adapter<_typeT>::value;\n}\n#line\
    \ 14 \"base/in.hpp\"\n\nnamespace kyopro {\n  template<KYOPRO_BASE_UINT _buf_size\
    \ = KYOPRO_BUFFER_SIZE>\n  struct Reader {\n  private:\n    int _fd, _idx;\n \
    \   std::array<char, _buf_size> _buffer;\n\n  public:\n    Reader() {\n      read(_fd,\
    \ _buffer.begin(), _buf_size);\n    }\n    Reader(int _fd) noexcept: _fd(_fd),\
    \ _idx(0), _buffer() {\n      read(_fd, _buffer.begin(), _buf_size);\n    }\n\
    \    Reader(FILE* _fp) noexcept: _fd(fileno_unlocked(_fp)), _idx(0), _buffer()\
    \ {\n      read(_fd, _buffer.begin(), _buf_size);\n    }\n\n    Reader& operator\
    \ =(int _fd) noexcept {\n      this->_fd = _fd;\n      return *this;\n    }\n\
    \    Reader& operator =(FILE* _fp) noexcept {\n      this->_fd = fileno_unlocked(_fp);\n\
    \      return *this;\n    }\n\n    struct iterator {\n    private:\n      Reader&\
    \ _reader;\n\n    public:\n      using difference_type = void;\n      using value_type\
    \ = void;\n      using pointer = void;\n      using reference = void;\n      using\
    \ iterator_category = std::input_iterator_tag;\n\n      iterator() noexcept =\
    \ default;\n      iterator(Reader& _reader) noexcept: _reader(_reader) {}\n\n\
    \      iterator& operator ++() {\n        ++_reader._idx;\n        if (_reader._idx\
    \ == _buf_size) {\n          read(_reader._fd, _reader._buffer.begin(), _buf_size);\n\
    \          _reader._idx = 0;\n        }\n        return *this;\n      }\n\n  \
    \    iterator operator ++(int) {\n        iterator _before = *this;\n        operator\
    \ ++();\n        return _before;\n      }\n\n      char& operator *() const {\n\
    \        return _reader._buffer[_reader._idx];\n      }\n    };\n\n    iterator\
    \ begin() noexcept {\n      return iterator(*this);\n    }\n  };\n\n  Reader input(0);\n\
    \n  template<class _typeReader, KYOPRO_BASE_UINT _decimal_precision = KYOPRO_DECIMAL_PRECISION>\n\
    \  struct Scanner {\n  private:\n    template<class, class = void>\n    struct\
    \ _has_scan: std::false_type {};\n    template<class _typeT>\n    struct _has_scan<_typeT,\
    \ std::void_t<decltype(std::declval<_typeT>().scan(std::declval<Scanner&>()))>>:\
    \ std::true_type {};\n\n  public:\n    static constexpr KYOPRO_BASE_UINT decimal_precision\
    \ = _decimal_precision;\n    typename _typeReader::iterator itr;\n\n    Scanner()\
    \ noexcept = default;\n    Scanner(_typeReader& _reader) noexcept: itr(_reader.begin())\
    \ {}\n\n    void scan(char& _a) {\n      while (('\\t' <= *itr && *itr <= '\\\
    r') || *itr == ' ') ++itr;\n      _a = *itr;\n      ++itr;\n    }\n    void scan(std::string&\
    \ _a) {\n      while (('\\t' <= *itr && *itr <= '\\r') || *itr == ' ') ++itr;\n\
    \      for (auto& _i: _a) {\n        _i = *itr;\n        ++itr;\n      }\n   \
    \ }\n    void scan(bool& _a) {\n      while (('\\t' <= *itr && *itr <= '\\r')\
    \ || *itr == ' ') ++itr;\n      while ('0' <= *itr && *itr <= '9') {\n       \
    \ if (*itr != '0') _a = true;\n        ++itr;\n      }\n    }\n    template<class\
    \ _typeT, std::enable_if_t<std::is_arithmetic_v<_typeT> && !_has_scan<_typeT>::value>*\
    \ = nullptr>\n    void scan(_typeT& _a) {\n      while (('\\t' <= *itr && *itr\
    \ <= '\\r') || *itr == ' ') ++itr;\n      bool sgn = false;\n      if constexpr\
    \ (!std::is_unsigned_v<_typeT>) if (*itr == '-') {\n        sgn = true;\n    \
    \    ++itr;\n      }\n      _a = 0;\n      for (; '0' <= *itr && *itr <= '9';\
    \ ++itr) _a = _a * 10 + *itr - '0';\n      if (*itr == '.') {\n        ++itr;\n\
    \        if constexpr (std::is_floating_point_v<_typeT>) {\n          constexpr\
    \ std::uint_fast64_t _power_decimal_precision = power(10ULL, _decimal_precision);\n\
    \          _typeT _d = 0;\n          std::uint_fast64_t _i = 1;\n          for\
    \ (; '0' <= *itr && *itr <= '9' && _i < _power_decimal_precision; _i *= 10) {\n\
    \            _d = _d * 10 + *itr - '0';\n            ++itr;\n          }\n   \
    \       _a += _d / _i;\n        }\n        while ('0' <= *itr && *itr <= '9')\
    \ ++itr;\n      }\n      if constexpr (!std::is_unsigned_v<_typeT>) if (sgn) _a\
    \ = -_a;\n    }\n    template<std::size_t _i = 0, class _typeT, std::enable_if_t<is_tuple_v<_typeT>\
    \ && !_has_scan<_typeT>::value>* = nullptr>\n    void scan(_typeT& _a) {\n   \
    \   if constexpr (_i < std::tuple_size_v<_typeT>) {\n        scan(std::get<_i>(_a));\n\
    \        scan<_i + 1>(_a);\n      }\n    }\n    template<class _typeT, std::enable_if_t<is_iterable_v<_typeT>\
    \ && !_has_scan<_typeT>::value>* = nullptr>\n    void scan(_typeT& _a) {\n   \
    \   for (auto& _i: _a) scan(_i);\n    }\n    template<class _typeT, std::enable_if_t<_has_scan<_typeT>::value>*\
    \ = nullptr>\n    void scan(const _typeT& _a) {\n      _a.scan(*this);\n    }\n\
    \n    void operator ()() {}\n    template<class _typeHead, class... _typeArgs>\n\
    \    void operator ()(_typeHead& _head, _typeArgs&... _args) {\n      scan(_head);\n\
    \      operator ()(_args...);\n    }\n  };\n\n  Scanner<Reader<>> scan(input);\n\
    }\n#line 13 \"base/out.hpp\"\n\nnamespace kyopro {\n  template<KYOPRO_BASE_UINT\
    \ _buf_size = KYOPRO_BUFFER_SIZE>\n  struct Writer {\n  private:\n    int _fd,\
    \ _idx;\n    std::array<char, _buf_size> _buffer;\n\n  public:\n    Writer() noexcept\
    \ = default;\n    Writer(int _fd) noexcept: _fd(_fd), _idx(0), _buffer() {}\n\
    \    Writer(FILE* _fp) noexcept: _fd(fileno_unlocked(_fp)), _idx(0), _buffer()\
    \ {}\n\n    ~Writer() {\n      write(_fd, _buffer.begin(), _idx);\n    }\n\n \
    \   Writer& operator =(int _fd) noexcept {\n      this->_fd = _fd;\n      return\
    \ *this;\n    }\n    Writer& operator =(FILE* _fp) noexcept {\n      this->_fd\
    \ = fileno_unlocked(_fp);\n      return *this;\n    }\n\n    struct iterator {\n\
    \    private:\n      Writer& _writer;\n\n    public:\n      using difference_type\
    \ = void;\n      using value_type = void;\n      using pointer = void;\n     \
    \ using reference = void;\n      using iterator_category = std::output_iterator_tag;\n\
    \n      iterator() noexcept = default;\n      iterator(Writer& _writer) noexcept:\
    \ _writer(_writer) {}\n\n      iterator& operator ++() {\n        ++_writer._idx;\n\
    \        if (_writer._idx == _buf_size) {\n          write(_writer._fd, _writer._buffer.begin(),\
    \ _buf_size);\n          _writer._idx = 0;\n        }\n        return *this;\n\
    \      }\n\n      iterator operator ++(int) {\n        iterator _before = *this;\n\
    \        operator ++();\n        return _before;\n      }\n\n      char& operator\
    \ *() const {\n        return _writer._buffer[_writer._idx];\n      }\n\n    \
    \  void flush() const {\n        write(_writer._fd, _writer._buffer.begin(), _writer._idx);\n\
    \      }\n    };\n\n    iterator begin() noexcept {\n      return iterator(*this);\n\
    \    }\n  };\n\n  Writer output(1), error(2);\n\n  template<class _typeWriter,\
    \ bool _sep = true, bool _end = true, bool _debug = true, bool _flush = false,\
    \ KYOPRO_BASE_UINT _decimal_precision = KYOPRO_DECIMAL_PRECISION>\n  struct Printer\
    \ {\n  private:\n    template<class, class = void>\n    struct _has_print: std::false_type\
    \ {};\n    template<class _typeT>\n    struct _has_print<_typeT, std::void_t<decltype(std::declval<_typeT>().print(std::declval<Printer&>()))>>:\
    \ std::true_type {};\n\n    void _print_sep() {\n      if constexpr (_debug) {\n\
    \        print(',');\n      }\n      print(' ');\n    }\n\n  public:\n    static\
    \ constexpr bool sep = _sep, end = _end, debug = _debug, flush = _flush;\n   \
    \ static constexpr KYOPRO_BASE_UINT decimal_precision = _decimal_precision;\n\n\
    \    typename _typeWriter::iterator itr;\n\n    Printer() noexcept = default;\n\
    \    Printer(_typeWriter& _writer) noexcept: itr(_writer.begin()) {}\n\n    void\
    \ print(char _a) {\n      *itr = _a;\n      ++itr;\n    }\n    void print(const\
    \ char* _a) {\n      for (; *_a; ++_a) print(*_a);\n    }\n    void print(const\
    \ std::string& _a) {\n      for (auto _i: _a) print(_i);\n    }\n    void print(bool\
    \ _a) {\n      print(static_cast<char>('0' + _a));\n    }\n    template<class\
    \ _typeT, std::enable_if_t<std::is_arithmetic_v<_typeT> && !_has_print<_typeT>::value>*\
    \ = nullptr>\n    void print(_typeT _a) {\n      if constexpr (std::is_signed_v<_typeT>)\
    \ if (_a < 0) {\n        print('-');\n        _a = -_a;\n      }\n      std::uint_fast64_t\
    \ _p = _a;\n      _a -= _p;\n      std::string _s;\n      do {\n        _s +=\
    \ '0' + _p % 10;\n        _p /= 10;\n      } while (_p > 0);\n      for (auto\
    \ _i = _s.rbegin(); _i != _s.rend(); ++_i) print(*_i);\n      if constexpr (std::is_integral_v<_typeT>)\
    \ return;\n      print('.');\n      for (int _i = 0; _i < static_cast<int>(_decimal_precision);\
    \ ++_i) {\n        _a *= 10;\n        print('0' + static_cast<std::uint_fast64_t>(_a)\
    \ % 10);\n      }\n    }\n    template<size_t _i = 0, class _typeT, std::enable_if_t<is_tuple_v<_typeT>\
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
    \ _typeT& _a) {\n      _a.print(*this);\n    }\n\n    template<bool = true>\n\
    \    void operator ()() {\n      if constexpr (_end) print('\\n');\n      if constexpr\
    \ (_flush) itr._flush();\n    }\n    template<bool _first = true, class _typeHead,\
    \ class... _typeArgs>\n    void operator ()(_typeHead&& _head, _typeArgs&&...\
    \ _args) {\n      if constexpr (_debug && _first) {\n        print('#');\n   \
    \     print(' ');\n      }\n      if constexpr (_sep && !_first) _print_sep();\n\
    \      print(_head);\n      operator ()<false>(std::forward<_typeArgs>(_args)...);\n\
    \    }\n  };\n\n  Printer<Writer<>, false, false, false> print(output), eprint(error);\n\
    \  Printer<Writer<>, true, true, false> println(output), eprintln(error);\n  Printer<Writer<>>\
    \ debug(output), edebug(error);\n}\n#line 4 \"base/io.hpp\"\n"
  code: '#pragma once

    #include "in.hpp"

    #include "out.hpp"'
  dependsOn:
  - base/in.hpp
  - math/power.hpp
  - base/settings.hpp
  - base/trait.hpp
  - base/out.hpp
  isVerificationFile: false
  path: base/io.hpp
  requiredBy:
  - base/all.hpp
  - all.hpp
  timestamp: '2022-03-09 23:07:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: base/io.hpp
layout: document
redirect_from:
- /library/base/io.hpp
- /library/base/io.hpp.html
title: base/io.hpp
---