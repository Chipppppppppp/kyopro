---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: meta/settings.hpp
    title: meta/settings.hpp
  - icon: ':heavy_check_mark:'
    path: meta/trait.hpp
    title: meta/trait.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all/all.hpp
    title: all/all.hpp
  - icon: ':heavy_check_mark:'
    path: system/all.hpp
    title: system/all.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/PrimeNumber.test.cpp
    title: verify/aoj/PrimeNumber.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/factorize.test.cpp
    title: verify/yosupo/factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/many_aplusb.test.cpp
    title: verify/yosupo/many_aplusb.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/point_add_range_sum.test.cpp
    title: verify/yosupo/point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/unionfind.test.cpp
    title: verify/yosupo/unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"system/out.hpp\"\n#include <unistd.h>\n#include <array>\n\
    #include <cstdint>\n#include <cstdio>\n#include <iterator>\n#include <string>\n\
    #include <tuple>\n#include <type_traits>\n#include <utility>\n#line 3 \"meta/settings.hpp\"\
    \n\n#ifndef KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT std::int64_t\n#endif\n\n\
    #ifndef KYOPRO_BASE_UINT\n#define KYOPRO_BASE_UINT std::uint64_t\n#endif\n\n#ifndef\
    \ KYOPRO_BASE_FLOAT\n#define KYOPRO_BASE_FLOAT double\n#endif\n\n#ifndef KYOPRO_DEFAULT_MOD\n\
    #define KYOPRO_DEFAULT_MOD static_cast<KYOPRO_BASE_UINT>(998244353)\n#endif\n\n\
    #ifndef KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n\
    #endif\n\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 3 \"meta/trait.hpp\"\n#include <queue>\n#include <limits>\n#include\
    \ <stack>\n#line 9 \"meta/trait.hpp\"\n\nnamespace kyopro {\n  template<KYOPRO_BASE_UINT\
    \ size>\n  struct int_least {\n  private:\n    static constexpr auto get_type()\
    \ noexcept {\n      static_assert(size <= 128, \"Integer size is too large\");\n\
    \      if constexpr (size <= 8) return std::int_least8_t();\n      else if constexpr\
    \ (size <= 16) return std::int_least16_t();\n      else if constexpr (size <=\
    \ 32) return std::int_least32_t();\n      else if constexpr (size <= 64) return\
    \ std::int_least64_t();\n      else return __int128_t();\n    }\n\n  public:\n\
    \    using type = decltype(get_type());\n  };\n\n  template<KYOPRO_BASE_UINT size>\n\
    \  using int_least_t = typename int_least<size>::type;\n\n  template<KYOPRO_BASE_UINT\
    \ size>\n  struct uint_least {\n  private:\n    static constexpr auto get_type()\
    \ noexcept {\n      static_assert(size <= 128, \"Integer size is too large\");\n\
    \      if constexpr (size <= 8) return std::uint_least8_t();\n      else if constexpr\
    \ (size <= 16) return std::uint_least16_t();\n      else if constexpr (size <=\
    \ 32) return std::uint_least32_t();\n      else if constexpr (size <= 64) return\
    \ std::uint_least64_t();\n      else return __uint128_t();\n    }\n\n  public:\n\
    \    using type = decltype(get_type());\n  };\n\n  template<KYOPRO_BASE_UINT size>\n\
    \  using uint_least_t = typename uint_least<size>::type;\n\n  template<class,\
    \ class = void>\n  struct is_iterator: std::false_type {};\n  template<class T>\n\
    \  struct is_iterator<T, std::void_t<typename std::iterator_traits<T>::iterator_category>>:\
    \ std::true_type {};\n\n  template<class T>\n  constexpr bool is_iterator_v =\
    \ is_iterator<T>::value;\n\n  template<class, class = void>\n  struct is_iterable:\
    \ std::false_type {};\n  template<class T>\n  struct is_iterable<T, std::void_t<decltype(std::begin(std::declval<T>()))>>:\
    \ std::true_type {};\n\n  template<class T>\n  constexpr bool is_iterable_v =\
    \ is_iterable<T>::value;\n\n  template<class>\n  struct is_tuple: std::false_type\
    \ {};\n  template<class T, class U>\n  struct is_tuple<std::pair<T, U>>: std::true_type\
    \ {};\n  template<class... Args>\n  struct is_tuple<std::tuple<Args...>>: std::true_type\
    \ {};\n\n  template<class T>\n  constexpr bool is_tuple_v = is_tuple<T>::value;\n\
    \n  template<class T>\n  struct iterable_value {\n    using type = std::decay_t<decltype(*std::begin(std::declval<T>()))>;\n\
    \  };\n\n  template<class T>\n  using iterable_value_t = typename iterable_value<T>::type;\n\
    }\n#line 13 \"system/out.hpp\"\n\nnamespace kyopro {\n  template<KYOPRO_BASE_UINT\
    \ _buf_size = KYOPRO_BUFFER_SIZE>\n  struct Writer {\n    static constexpr KYOPRO_BASE_UINT\
    \ buf_size = _buf_size;\n\n  private:\n    int fd, idx;\n    std::array<char,\
    \ buf_size> buffer;\n\n  public:\n    Writer() noexcept = default;\n    Writer(int\
    \ fd) noexcept: fd(fd), idx(0), buffer() {}\n    Writer(FILE* fp) noexcept: fd(fileno(fp)),\
    \ idx(0), buffer() {}\n\n    ~Writer() {\n      write(fd, buffer.begin(), idx);\n\
    \    }\n\n    struct iterator {\n    private:\n      Writer& writer;\n\n    public:\n\
    \      using difference_type = void;\n      using value_type = void;\n      using\
    \ pointer = void;\n      using reference = void;\n      using iterator_category\
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
    \ Iterator, bool _sep = true, bool _end = true, bool _debug = false, bool _comment\
    \ = false, bool _flush = false, KYOPRO_BASE_UINT _decimal_precision = KYOPRO_DECIMAL_PRECISION>\n\
    \  struct Printer {\n    using iterator_type = Iterator;\n    static constexpr\
    \ bool sep = _sep, end = _end, debug = _debug, comment = _comment, flush = _flush;\n\
    \    static constexpr KYOPRO_BASE_UINT decimal_precision = _decimal_precision;\n\
    \n  private:\n    template<class, class = void>\n    struct has_print: std::false_type\
    \ {};\n    template<class T>\n    struct has_print<T, std::void_t<decltype(std::declval<T>().print(std::declval<Printer&>()))>>:\
    \ std::true_type {};\n\n    void print_sep() {\n      if constexpr (debug) {\n\
    \        print(',');\n      }\n      print(' ');\n    }\n\n  public:\n\n    Iterator\
    \ itr;\n\n    Printer() noexcept = default;\n    Printer(Iterator itr) noexcept:\
    \ itr(itr) {}\n\n    void print(char a) {\n      *itr = a;\n      ++itr;\n   \
    \ }\n    void print(const char* a) {\n      for (; *a; ++a) print(*a);\n    }\n\
    \    template<class CharT, class Traits>\n    void print(const std::basic_string<CharT,\
    \ Traits>& a) {\n      for (auto i: a) print(i);\n    }\n    void print(bool a)\
    \ {\n      print(static_cast<char>('0' + a));\n    }\n    template<class T, std::enable_if_t<std::is_arithmetic_v<T>\
    \ && !has_print<T>::value>* = nullptr>\n    void print(T a) {\n      if constexpr\
    \ (std::is_signed_v<T>) if (a < 0) {\n        print('-');\n        a = -a;\n \
    \     }\n      std::uint_fast64_t p = a;\n      a -= p;\n      std::string s;\n\
    \      do {\n        s += '0' + p % 10;\n        p /= 10;\n      } while (p >\
    \ 0);\n      for (auto i = s.rbegin(); i != s.rend(); ++i) print(*i);\n      if\
    \ constexpr (std::is_integral_v<T>) return;\n      print('.');\n      for (int\
    \ i = 0; i < static_cast<int>(decimal_precision); ++i) {\n        a *= 10;\n \
    \       print('0' + static_cast<std::uint_fast64_t>(a) % 10);\n      }\n    }\n\
    \    template<KYOPRO_BASE_UINT i = 0, class T, std::enable_if_t<is_tuple_v<T>\
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
    \ = nullptr>\n    void print(const T& a) {\n      a.print(*this);\n    }\n\n \
    \   template<bool first = true>\n    void operator ()() {\n      if constexpr\
    \ (comment && first) print('#');\n      if constexpr (end) print('\\n');\n   \
    \   if constexpr (flush) itr.flush();\n    }\n    template<bool first = true,\
    \ class Head, class... Args>\n    void operator ()(Head&& head, Args&&... args)\
    \ {\n      if constexpr (comment && first) {\n        print('#');\n        print('\
    \ ');\n      }\n      if constexpr (sep && !first) print_sep();\n      print(head);\n\
    \      operator ()<false>(std::forward<Args>(args)...);\n    }\n  };\n\n  Printer<Writer<>::iterator,\
    \ false, false> print(output.begin()), eprint(error.begin());\n  Printer<Writer<>::iterator>\
    \ println(output.begin()), eprintln(error.begin());\n  Printer<Writer<>::iterator,\
    \ true, true, true, true> debug(output.begin()), edebug(error.begin());\n}\n"
  code: "#pragma once\n#include <unistd.h>\n#include <array>\n#include <cstdint>\n\
    #include <cstdio>\n#include <iterator>\n#include <string>\n#include <tuple>\n\
    #include <type_traits>\n#include <utility>\n#include \"../meta/settings.hpp\"\n\
    #include \"../meta/trait.hpp\"\n\nnamespace kyopro {\n  template<KYOPRO_BASE_UINT\
    \ _buf_size = KYOPRO_BUFFER_SIZE>\n  struct Writer {\n    static constexpr KYOPRO_BASE_UINT\
    \ buf_size = _buf_size;\n\n  private:\n    int fd, idx;\n    std::array<char,\
    \ buf_size> buffer;\n\n  public:\n    Writer() noexcept = default;\n    Writer(int\
    \ fd) noexcept: fd(fd), idx(0), buffer() {}\n    Writer(FILE* fp) noexcept: fd(fileno(fp)),\
    \ idx(0), buffer() {}\n\n    ~Writer() {\n      write(fd, buffer.begin(), idx);\n\
    \    }\n\n    struct iterator {\n    private:\n      Writer& writer;\n\n    public:\n\
    \      using difference_type = void;\n      using value_type = void;\n      using\
    \ pointer = void;\n      using reference = void;\n      using iterator_category\
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
    \ Iterator, bool _sep = true, bool _end = true, bool _debug = false, bool _comment\
    \ = false, bool _flush = false, KYOPRO_BASE_UINT _decimal_precision = KYOPRO_DECIMAL_PRECISION>\n\
    \  struct Printer {\n    using iterator_type = Iterator;\n    static constexpr\
    \ bool sep = _sep, end = _end, debug = _debug, comment = _comment, flush = _flush;\n\
    \    static constexpr KYOPRO_BASE_UINT decimal_precision = _decimal_precision;\n\
    \n  private:\n    template<class, class = void>\n    struct has_print: std::false_type\
    \ {};\n    template<class T>\n    struct has_print<T, std::void_t<decltype(std::declval<T>().print(std::declval<Printer&>()))>>:\
    \ std::true_type {};\n\n    void print_sep() {\n      if constexpr (debug) {\n\
    \        print(',');\n      }\n      print(' ');\n    }\n\n  public:\n\n    Iterator\
    \ itr;\n\n    Printer() noexcept = default;\n    Printer(Iterator itr) noexcept:\
    \ itr(itr) {}\n\n    void print(char a) {\n      *itr = a;\n      ++itr;\n   \
    \ }\n    void print(const char* a) {\n      for (; *a; ++a) print(*a);\n    }\n\
    \    template<class CharT, class Traits>\n    void print(const std::basic_string<CharT,\
    \ Traits>& a) {\n      for (auto i: a) print(i);\n    }\n    void print(bool a)\
    \ {\n      print(static_cast<char>('0' + a));\n    }\n    template<class T, std::enable_if_t<std::is_arithmetic_v<T>\
    \ && !has_print<T>::value>* = nullptr>\n    void print(T a) {\n      if constexpr\
    \ (std::is_signed_v<T>) if (a < 0) {\n        print('-');\n        a = -a;\n \
    \     }\n      std::uint_fast64_t p = a;\n      a -= p;\n      std::string s;\n\
    \      do {\n        s += '0' + p % 10;\n        p /= 10;\n      } while (p >\
    \ 0);\n      for (auto i = s.rbegin(); i != s.rend(); ++i) print(*i);\n      if\
    \ constexpr (std::is_integral_v<T>) return;\n      print('.');\n      for (int\
    \ i = 0; i < static_cast<int>(decimal_precision); ++i) {\n        a *= 10;\n \
    \       print('0' + static_cast<std::uint_fast64_t>(a) % 10);\n      }\n    }\n\
    \    template<KYOPRO_BASE_UINT i = 0, class T, std::enable_if_t<is_tuple_v<T>\
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
    \ = nullptr>\n    void print(const T& a) {\n      a.print(*this);\n    }\n\n \
    \   template<bool first = true>\n    void operator ()() {\n      if constexpr\
    \ (comment && first) print('#');\n      if constexpr (end) print('\\n');\n   \
    \   if constexpr (flush) itr.flush();\n    }\n    template<bool first = true,\
    \ class Head, class... Args>\n    void operator ()(Head&& head, Args&&... args)\
    \ {\n      if constexpr (comment && first) {\n        print('#');\n        print('\
    \ ');\n      }\n      if constexpr (sep && !first) print_sep();\n      print(head);\n\
    \      operator ()<false>(std::forward<Args>(args)...);\n    }\n  };\n\n  Printer<Writer<>::iterator,\
    \ false, false> print(output.begin()), eprint(error.begin());\n  Printer<Writer<>::iterator>\
    \ println(output.begin()), eprintln(error.begin());\n  Printer<Writer<>::iterator,\
    \ true, true, true, true> debug(output.begin()), edebug(error.begin());\n}"
  dependsOn:
  - meta/settings.hpp
  - meta/trait.hpp
  isVerificationFile: false
  path: system/out.hpp
  requiredBy:
  - system/all.hpp
  - all/all.hpp
  timestamp: '2022-04-24 20:57:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/PrimeNumber.test.cpp
  - verify/yosupo/many_aplusb.test.cpp
  - verify/yosupo/unionfind.test.cpp
  - verify/yosupo/factorize.test.cpp
  - verify/yosupo/point_add_range_sum.test.cpp
documentation_of: system/out.hpp
layout: document
redirect_from:
- /library/system/out.hpp
- /library/system/out.hpp.html
title: system/out.hpp
---
