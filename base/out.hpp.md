---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base/settings.hpp
    title: base/settings.hpp
  - icon: ':warning:'
    path: base/trait.hpp
    title: base/trait.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"base/out.hpp\"\n#include <unistd.h>\n#include <array>\n\
    #include <cstdint>\n#include <cstdio>\n#include <iterator>\n#include <string>\n\
    #include <tuple>\n#include <type_traits>\n#include <utility>\n#line 3 \"base/settings.hpp\"\
    \n\n#ifndef KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT std::int64_t\n#endif\n\n\
    #ifndef KYOPRO_BASE_UINT\n#define KYOPRO_BASE_UINT std::size_t\n#endif\n\n#ifndef\
    \ KYOPRO_BASE_FLOAT\n#define KYOPRO_BASE_FLOAT double\n#endif\n\n#ifndef KYOPRO_DEFAULT_MOD\n\
    #define KYOPRO_DEFAULT_MOD static_cast<KYOPRO_BASE_UINT>(1000000007)\n#endif\n\
    \n#ifndef KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n\
    #endif\n\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 3 \"base/trait.hpp\"\n#include <queue>\n#include <stack>\n#line\
    \ 7 \"base/trait.hpp\"\n\n#ifdef __SIZEOF_INT128__\ntemplate<>\nstruct std::is_integral<__int128_t>:\
    \ std::true_type {};\ntemplate<>\nstruct std::is_signed<__int128_t>: std::true_type\
    \ {};\ntemplate<>\nstruct std::is_integral<__uint128_t>: std::true_type {};\n\
    template<>\nstruct std::is_unsigned<__uint128_t>: std::true_type {};\n#endif\n\
    #ifdef __SIZEOF_FLOAT128__\ntemplate<>\nstruct std::is_floating_point<__float128>:\
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
    \ 13 \"base/out.hpp\"\n\nnamespace kyopro {\n  template<KYOPRO_BASE_UINT buf_size\
    \ = KYOPRO_BUFFER_SIZE>\n  struct Writer {\n  private:\n    int fd, idx;\n   \
    \ std::array<char, buf_size> buffer;\n\n  public:\n    Writer() noexcept = default;\n\
    \    Writer(int fd) noexcept: fd(fd), idx(0), buffer() {}\n    Writer(FILE* fp)\
    \ noexcept: fd(fileno_unlocked(fp)), idx(0), buffer() {}\n\n    ~Writer() {\n\
    \      write(fd, buffer.begin(), idx);\n    }\n\n    Writer& operator =(int fd)\
    \ noexcept {\n      this->fd = fd;\n      return *this;\n    }\n    Writer& operator\
    \ =(FILE* fp) noexcept {\n      this->fd = fileno_unlocked(fp);\n      return\
    \ *this;\n    }\n\n    struct iterator {\n    private:\n      Writer& writer;\n\
    \n    public:\n      using difference_type = void;\n      using value_type = void;\n\
    \      using pointer = void;\n      using reference = void;\n      using iterator_category\
    \ = std::output_iterator_tag;\n\n      iterator() noexcept = default;\n      iterator(Writer&\
    \ writer) noexcept: writer(writer) {}\n\n      iterator& operator ++() {\n   \
    \     ++writer.idx;\n        if (writer.idx == buf_size) {\n          write(writer.fd,\
    \ writer.buffer.begin(), buf_size);\n          writer.idx = 0;\n        }\n  \
    \      return *this;\n      }\n\n      iterator operator ++(int) {\n        iterator\
    \ before = *this;\n        operator ++();\n        return before;\n      }\n\n\
    \      char& operator *() const {\n        return writer.buffer[writer.idx];\n\
    \      }\n\n      void flush() const {\n        write(writer.fd, writer.buffer.begin(),\
    \ writer.idx);\n      }\n    };\n\n    iterator begin() noexcept {\n      return\
    \ iterator(*this);\n    }\n  };\n\n  Writer output(1), error(2);\n\n  template<class\
    \ Writer, bool sep = true, bool end = true, bool debug = true, bool flush = false,\
    \ KYOPRO_BASE_UINT decimal_precision = KYOPRO_DECIMAL_PRECISION>\n  struct Printer\
    \ {\n  private:\n    template<class, class = void>\n    struct has_print: std::false_type\
    \ {};\n    template<class T>\n    struct has_print<T, std::void_t<decltype(T::print)>>:\
    \ std::true_type {};\n\n    typename Writer::iterator itr;\n\n    void print_sep()\
    \ {\n      if constexpr (debug) {\n        print(',');\n      }\n      print('\
    \ ');\n    }\n\n    void print(char a) {\n      *itr = a;\n      ++itr;\n    }\n\
    \    void print(const char* a) {\n      for (; *a; ++a) print(*a);\n    }\n  \
    \  void print(const std::string& a) {\n      for (auto i: a) print(i);\n    }\n\
    \    void print(bool a) {\n      print('0' + a);\n    }\n    template<class T,\
    \ std::enable_if_t<std::is_arithmetic_v<T> && !has_print<T>::value>* = nullptr>\n\
    \    void print(T a) {\n      if constexpr (std::is_signed_v<T>) if (a < 0) {\n\
    \        print('-');\n        a = -a;\n      }\n      std::uint_fast64_t p = a;\n\
    \      a -= p;\n      std::string s;\n      do {\n        s += '0' + p % 10;\n\
    \        p /= 10;\n      } while (p > 0);\n      for (auto i = s.rbegin(); i !=\
    \ s.rend(); ++i) print(*i);\n      if constexpr (std::is_integral_v<T>) return;\n\
    \      print('.');\n      for (int i = 0; i < static_cast<int>(decimal_precision);\
    \ ++i) {\n        a *= 10;\n        print('0' + static_cast<std::uint_fast64_t>(a)\
    \ % 10);\n      }\n    }\n    template<size_t i = 0, class T, std::enable_if_t<is_tuple_v<T>\
    \ && !has_print<T>::value>* = nullptr>\n    void print(const T& a) {\n      if\
    \ constexpr (debug && i == 0) print('{');\n      if constexpr (std::tuple_size_v<T>\
    \ != 0) print(std::get<i>(a));\n      if constexpr (i + 1 < std::tuple_size_v<T>)\
    \ {\n        if constexpr (sep) print_sep();\n        print<i + 1>(a);\n     \
    \ } else if constexpr (debug) print('}');\n    }\n    template<class T, std::enable_if_t<is_iterable_v<T>\
    \ && !has_print<T>::value>* = nullptr>\n    void print(const T& a) {\n      if\
    \ constexpr (debug) print('{');\n      if (std::empty(a)) return;\n      for (auto\
    \ i = std::begin(a); ; ) {\n        print(*i);\n        if (++i != std::end(a))\
    \ {\n          if constexpr (sep) {\n            if constexpr (debug) {\n    \
    \          print(',');\n              print(' ');\n            } else if constexpr\
    \ (std::is_arithmetic_v<std::decay_t<decltype(std::declval<T>()[0])>>) print('\
    \ ');\n            else print('\\n');\n          }\n        } else break;\n  \
    \    }\n      if constexpr (debug) print('}');\n    }\n    template<class T, std::enable_if_t<has_print<T>::value>*\
    \ = nullptr>\n    void print(const T& a) {\n      a.print();\n    }\n\n  public:\n\
    \    Printer() noexcept = default;\n    Printer(Writer& writer) noexcept: itr(writer.begin())\
    \ {}\n\n    template<bool = true>\n    void operator ()() {\n      if constexpr\
    \ (end) print('\\n');\n      if constexpr (flush) itr.flush();\n    }\n    template<bool\
    \ first = true, class Head, class... Args>\n    void operator ()(Head&& head,\
    \ Args&&... args) {\n      if constexpr (debug && first) {\n        print('#');\n\
    \        print(' ');\n      }\n      if constexpr (sep && !first) print_sep();\n\
    \      print(head);\n      operator ()<false>(std::forward<Args>(args)...);\n\
    \    }\n  };\n\n  Printer<Writer<>, false, false, false> print(output), eprint(error);\n\
    \  Printer<Writer<>, true, true, false> println(output), eprintln(error);\n  Printer<Writer<>>\
    \ debug(output), edebug(error);\n}\n"
  code: "#pragma once\n#include <unistd.h>\n#include <array>\n#include <cstdint>\n\
    #include <cstdio>\n#include <iterator>\n#include <string>\n#include <tuple>\n\
    #include <type_traits>\n#include <utility>\n#include \"settings.hpp\"\n#include\
    \ \"trait.hpp\"\n\nnamespace kyopro {\n  template<KYOPRO_BASE_UINT buf_size =\
    \ KYOPRO_BUFFER_SIZE>\n  struct Writer {\n  private:\n    int fd, idx;\n    std::array<char,\
    \ buf_size> buffer;\n\n  public:\n    Writer() noexcept = default;\n    Writer(int\
    \ fd) noexcept: fd(fd), idx(0), buffer() {}\n    Writer(FILE* fp) noexcept: fd(fileno_unlocked(fp)),\
    \ idx(0), buffer() {}\n\n    ~Writer() {\n      write(fd, buffer.begin(), idx);\n\
    \    }\n\n    Writer& operator =(int fd) noexcept {\n      this->fd = fd;\n  \
    \    return *this;\n    }\n    Writer& operator =(FILE* fp) noexcept {\n     \
    \ this->fd = fileno_unlocked(fp);\n      return *this;\n    }\n\n    struct iterator\
    \ {\n    private:\n      Writer& writer;\n\n    public:\n      using difference_type\
    \ = void;\n      using value_type = void;\n      using pointer = void;\n     \
    \ using reference = void;\n      using iterator_category = std::output_iterator_tag;\n\
    \n      iterator() noexcept = default;\n      iterator(Writer& writer) noexcept:\
    \ writer(writer) {}\n\n      iterator& operator ++() {\n        ++writer.idx;\n\
    \        if (writer.idx == buf_size) {\n          write(writer.fd, writer.buffer.begin(),\
    \ buf_size);\n          writer.idx = 0;\n        }\n        return *this;\n  \
    \    }\n\n      iterator operator ++(int) {\n        iterator before = *this;\n\
    \        operator ++();\n        return before;\n      }\n\n      char& operator\
    \ *() const {\n        return writer.buffer[writer.idx];\n      }\n\n      void\
    \ flush() const {\n        write(writer.fd, writer.buffer.begin(), writer.idx);\n\
    \      }\n    };\n\n    iterator begin() noexcept {\n      return iterator(*this);\n\
    \    }\n  };\n\n  Writer output(1), error(2);\n\n  template<class Writer, bool\
    \ sep = true, bool end = true, bool debug = true, bool flush = false, KYOPRO_BASE_UINT\
    \ decimal_precision = KYOPRO_DECIMAL_PRECISION>\n  struct Printer {\n  private:\n\
    \    template<class, class = void>\n    struct has_print: std::false_type {};\n\
    \    template<class T>\n    struct has_print<T, std::void_t<decltype(T::print)>>:\
    \ std::true_type {};\n\n    typename Writer::iterator itr;\n\n    void print_sep()\
    \ {\n      if constexpr (debug) {\n        print(',');\n      }\n      print('\
    \ ');\n    }\n\n    void print(char a) {\n      *itr = a;\n      ++itr;\n    }\n\
    \    void print(const char* a) {\n      for (; *a; ++a) print(*a);\n    }\n  \
    \  void print(const std::string& a) {\n      for (auto i: a) print(i);\n    }\n\
    \    void print(bool a) {\n      print('0' + a);\n    }\n    template<class T,\
    \ std::enable_if_t<std::is_arithmetic_v<T> && !has_print<T>::value>* = nullptr>\n\
    \    void print(T a) {\n      if constexpr (std::is_signed_v<T>) if (a < 0) {\n\
    \        print('-');\n        a = -a;\n      }\n      std::uint_fast64_t p = a;\n\
    \      a -= p;\n      std::string s;\n      do {\n        s += '0' + p % 10;\n\
    \        p /= 10;\n      } while (p > 0);\n      for (auto i = s.rbegin(); i !=\
    \ s.rend(); ++i) print(*i);\n      if constexpr (std::is_integral_v<T>) return;\n\
    \      print('.');\n      for (int i = 0; i < static_cast<int>(decimal_precision);\
    \ ++i) {\n        a *= 10;\n        print('0' + static_cast<std::uint_fast64_t>(a)\
    \ % 10);\n      }\n    }\n    template<size_t i = 0, class T, std::enable_if_t<is_tuple_v<T>\
    \ && !has_print<T>::value>* = nullptr>\n    void print(const T& a) {\n      if\
    \ constexpr (debug && i == 0) print('{');\n      if constexpr (std::tuple_size_v<T>\
    \ != 0) print(std::get<i>(a));\n      if constexpr (i + 1 < std::tuple_size_v<T>)\
    \ {\n        if constexpr (sep) print_sep();\n        print<i + 1>(a);\n     \
    \ } else if constexpr (debug) print('}');\n    }\n    template<class T, std::enable_if_t<is_iterable_v<T>\
    \ && !has_print<T>::value>* = nullptr>\n    void print(const T& a) {\n      if\
    \ constexpr (debug) print('{');\n      if (std::empty(a)) return;\n      for (auto\
    \ i = std::begin(a); ; ) {\n        print(*i);\n        if (++i != std::end(a))\
    \ {\n          if constexpr (sep) {\n            if constexpr (debug) {\n    \
    \          print(',');\n              print(' ');\n            } else if constexpr\
    \ (std::is_arithmetic_v<std::decay_t<decltype(std::declval<T>()[0])>>) print('\
    \ ');\n            else print('\\n');\n          }\n        } else break;\n  \
    \    }\n      if constexpr (debug) print('}');\n    }\n    template<class T, std::enable_if_t<has_print<T>::value>*\
    \ = nullptr>\n    void print(const T& a) {\n      a.print();\n    }\n\n  public:\n\
    \    Printer() noexcept = default;\n    Printer(Writer& writer) noexcept: itr(writer.begin())\
    \ {}\n\n    template<bool = true>\n    void operator ()() {\n      if constexpr\
    \ (end) print('\\n');\n      if constexpr (flush) itr.flush();\n    }\n    template<bool\
    \ first = true, class Head, class... Args>\n    void operator ()(Head&& head,\
    \ Args&&... args) {\n      if constexpr (debug && first) {\n        print('#');\n\
    \        print(' ');\n      }\n      if constexpr (sep && !first) print_sep();\n\
    \      print(head);\n      operator ()<false>(std::forward<Args>(args)...);\n\
    \    }\n  };\n\n  Printer<Writer<>, false, false, false> print(output), eprint(error);\n\
    \  Printer<Writer<>, true, true, false> println(output), eprintln(error);\n  Printer<Writer<>>\
    \ debug(output), edebug(error);\n}"
  dependsOn:
  - base/settings.hpp
  - base/trait.hpp
  isVerificationFile: false
  path: base/out.hpp
  requiredBy: []
  timestamp: '2022-03-06 23:13:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: base/out.hpp
layout: document
redirect_from:
- /library/base/out.hpp
- /library/base/out.hpp.html
title: base/out.hpp
---
