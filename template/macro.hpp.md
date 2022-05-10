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
  _extendedRequiredBy:
  - icon: ':warning:'
    path: kyopro.hpp
    title: kyopro.hpp
  - icon: ':warning:'
    path: template/all.hpp
    title: template/all.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/macro.hpp\"\n#include <iterator>\n#include <tuple>\n\
    #include <type_traits>\n#include <utility>\n#line 2 \"meta/settings.hpp\"\n#include\
    \ <cstdint>\n\n#ifndef KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT std::int64_t\n\
    #endif\n\n#ifndef KYOPRO_BASE_UINT\n#define KYOPRO_BASE_UINT std::uint64_t\n#endif\n\
    \n#ifndef KYOPRO_BASE_FLOAT\n#define KYOPRO_BASE_FLOAT double\n#endif\n\n#ifndef\
    \ KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD static_cast<KYOPRO_BASE_UINT>(998244353)\n\
    #endif\n\n#ifndef KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n\
    #endif\n\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 2 \"system/in.hpp\"\n#include <unistd.h>\n#include <array>\n#include\
    \ <cstddef>\n#line 6 \"system/in.hpp\"\n#include <cstdio>\n#include <string>\n\
    #line 3 \"math/power.hpp\"\n\nnamespace kpr {\n  template<class T>\n  constexpr\
    \ T power(T a, KYOPRO_BASE_UINT n, T init = 1) noexcept {\n    while (n > 0) {\n\
    \      if (n & 1) init *= a;\n      a *= a;\n      n >>= 1;\n    }\n    return\
    \ init;\n  }\n}\n#line 3 \"meta/trait.hpp\"\n#include <queue>\n#include <limits>\n\
    #include <stack>\n#line 9 \"meta/trait.hpp\"\n\ntemplate<>\nstruct std::is_integral<__int128_t>:\
    \ std::true_type {};\ntemplate<>\nstruct std::is_integral<__uint128_t>: std::true_type\
    \ {};\ntemplate<>\nstruct std::is_floating_point<__float128>: std::true_type {};\n\
    \nnamespace kpr {\n  template<KYOPRO_BASE_UINT size>\n  struct int_least {\n \
    \ private:\n    static constexpr auto get_type() noexcept {\n      static_assert(size\
    \ <= 128, \"Integer size is too large\");\n      if constexpr (size <= 8) return\
    \ std::int_least8_t();\n      else if constexpr (size <= 16) return std::int_least16_t();\n\
    \      else if constexpr (size <= 32) return std::int_least32_t();\n      else\
    \ if constexpr (size <= 64) return std::int_least64_t();\n      else return __int128_t();\n\
    \    }\n\n  public:\n    using type = decltype(get_type());\n  };\n\n  template<KYOPRO_BASE_UINT\
    \ size>\n  using int_least_t = typename int_least<size>::type;\n\n  template<KYOPRO_BASE_UINT\
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
    }\n#line 14 \"system/in.hpp\"\n\nnamespace kpr {\n  template<KYOPRO_BASE_UINT\
    \ _buf_size = KYOPRO_BUFFER_SIZE>\n  struct Reader {\n    static constexpr KYOPRO_BASE_UINT\
    \ buf_size = _buf_size;\n\n  private:\n    int fd, idx;\n    std::array<char,\
    \ buf_size> buffer;\n\n  public:\n    Reader() {\n      read(fd, buffer.begin(),\
    \ buf_size);\n    }\n    Reader(int fd): fd(fd), idx(0), buffer() {\n      read(fd,\
    \ buffer.begin(), buf_size);\n    }\n    Reader(FILE* fp): fd(fileno(fp)), idx(0),\
    \ buffer() {\n      read(fd, buffer.begin(), buf_size);\n    }\n\n    struct iterator\
    \ {\n    private:\n      Reader& reader;\n\n    public:\n      using difference_type\
    \ = void;\n      using value_type = void;\n      using pointer = void;\n     \
    \ using reference = void;\n      using iterator_category = std::input_iterator_tag;\n\
    \n      iterator() noexcept = default;\n      iterator(Reader& reader) noexcept:\
    \ reader(reader) {}\n\n      iterator& operator ++() {\n        ++reader.idx;\n\
    \        if (reader.idx == buf_size) {\n          read(reader.fd, reader.buffer.begin(),\
    \ buf_size);\n          reader.idx = 0;\n        }\n        return *this;\n  \
    \    }\n\n      iterator operator ++(int) {\n        iterator before = *this;\n\
    \        operator ++();\n        return before;\n      }\n\n      char& operator\
    \ *() const {\n        return reader.buffer[reader.idx];\n      }\n    };\n\n\
    \    iterator begin() noexcept {\n      return iterator(*this);\n    }\n  };\n\
    \n  Reader input(0);\n\n  template<class Iterator, KYOPRO_BASE_UINT _decimal_precision\
    \ = KYOPRO_DECIMAL_PRECISION>\n  struct Scanner {\n    using iterator_type = Iterator;\n\
    \    static constexpr KYOPRO_BASE_UINT decimal_precision = _decimal_precision;\n\
    \n  private:\n    template<class, class = void>\n    struct has_scan: std::false_type\
    \ {};\n    template<class T>\n    struct has_scan<T, std::void_t<decltype(std::declval<T>().scan(std::declval<Scanner&>()))>>:\
    \ std::true_type {};\n\n  public:\n    Iterator itr;\n\n    Scanner() noexcept\
    \ = default;\n    Scanner(Iterator itr) noexcept: itr(itr) {}\n\n    void discard_space()\
    \ {\n      while (('\\t' <= *itr && *itr <= '\\r') || *itr == ' ') ++itr;\n  \
    \  }\n\n    void scan(char& a) {\n      discard_space();\n      a = *itr;\n  \
    \    ++itr;\n    }\n    template<class CharT, class Traits>\n    void scan(std::basic_string<CharT,\
    \ Traits>& a) {\n      discard_space();\n      while ((*itr < '\\t' || '\\r' <\
    \ *itr) && *itr != ' ') {\n        a += *itr;\n        ++itr;\n      }\n    }\n\
    \    void scan(bool& a) {\n      discard_space();\n      while ('0' <= *itr &&\
    \ *itr <= '9') {\n        if (*itr != '0') a = true;\n        ++itr;\n      }\n\
    \    }\n    template<class T, std::enable_if_t<std::is_arithmetic_v<T> && !has_scan<T>::value>*\
    \ = nullptr>\n    void scan(T& a) {\n      discard_space();\n      bool sgn =\
    \ false;\n      if constexpr (!std::is_unsigned_v<T>) if (*itr == '-') {\n   \
    \     sgn = true;\n        ++itr;\n      }\n      a = 0;\n      for (; '0' <=\
    \ *itr && *itr <= '9'; ++itr) a = a * 10 + *itr - '0';\n      if (*itr == '.')\
    \ {\n        ++itr;\n        if constexpr (std::is_floating_point_v<T>) {\n  \
    \        constexpr std::uint_fast64_t power_decimal_precision = power(10ULL, decimal_precision);\n\
    \          T d = 0;\n          std::uint_fast64_t i = 1;\n          for (; '0'\
    \ <= *itr && *itr <= '9' && i < power_decimal_precision; i *= 10) {\n        \
    \    d = d * 10 + *itr - '0';\n            ++itr;\n          }\n          a +=\
    \ d / i;\n        }\n        while ('0' <= *itr && *itr <= '9') ++itr;\n     \
    \ }\n      if constexpr (!std::is_unsigned_v<T>) if (sgn) a = -a;\n    }\n   \
    \ template<KYOPRO_BASE_UINT i = 0, class T, std::enable_if_t<is_tuple_v<T> &&\
    \ !has_scan<T>::value>* = nullptr>\n    void scan(T& a) {\n      if constexpr\
    \ (i < std::tuple_size_v<T>) {\n        scan(std::get<i>(a));\n        scan<i\
    \ + 1>(a);\n      }\n    }\n    template<class T, std::enable_if_t<is_iterable_v<T>\
    \ && !has_scan<T>::value>* = nullptr>\n    void scan(T& a) {\n      for (auto&\
    \ i: a) scan(i);\n    }\n    template<class T, std::enable_if_t<has_scan<T>::value>*\
    \ = nullptr>\n    void scan(T& a) {\n      a.scan(*this);\n    }\n\n    void operator\
    \ ()() {}\n    template<class Head, class... Args>\n    void operator ()(Head&\
    \ head, Args&... args) {\n      scan(head);\n      operator ()(args...);\n   \
    \ }\n  };\n\n  Scanner<Reader<>::iterator> scan(input.begin());\n}\n#line 8 \"\
    template/macro.hpp\"\n\nnamespace kyopro::helper {\n  template<KYOPRO_BASE_UINT\
    \ len>\n  constexpr KYOPRO_BASE_UINT va_args_size(const char (&s)[len]) noexcept\
    \ {\n    if constexpr (len == 0) return 0;\n    KYOPRO_BASE_UINT cnt = 1;\n  \
    \  for (auto i: s) if (i == ',') ++cnt;\n    return cnt;\n  }\n\n  template<class\
    \ F, KYOPRO_BASE_UINT... idx>\n  auto read_impl(F&& f, std::integer_sequence<KYOPRO_BASE_UINT,\
    \ idx...>) {\n    auto res = std::tuple{(static_cast<void>(idx), f())...};\n \
    \   scan(res);\n    return res;\n  }\n}\n#define read(init, ...) auto [__VA_ARGS__]\
    \ = kyopro::helper::read_impl([&] { return init; }, std::make_integer_sequence<KYOPRO_BASE_UINT,\
    \ kyopro::helper::va_args_size(#__VA_ARGS__)>())\n#define KYOPRO_OVERLOAD_MACRO(_1,\
    \ _2, _3, _4, name, ...) name\n#define KYOPRO_REP0() for (; ; )\n#define KYOPRO_REP1(last)\
    \ KYOPRO_REP2(KYOPRO_COUNTER, last)\n#define KYOPRO_REP2(i, last) for (auto i\
    \ = std::decay_t<decltype(last)>(), KYOPRO_LAST = (last); (i) < (KYOPRO_LAST);\
    \ ++(i))\n#define KYOPRO_REP3(i, first, last) for (auto i = (first), KYOPRO_LAST\
    \ = last; (i) < (KYOPRO_LAST); ++(i))\n#define rep(...) KYOPRO_OVERLOAD_MACRO(__VA_ARGS__\
    \ __VA_OPT__(,) KYOPRO_REP4, KYOPRO_REP3, KYOPRO_REP2, KYOPRO_REP1, KYOPRO_REP0)(__VA_ARGS__)\n\
    #define KYOPRO_LAMBDA1(value) ([&]() noexcept { return (value);})\n#define KYOPRO_LAMBDA2(_1,\
    \ value) ([&](auto&& _1) noexcept { return (value); })\n#define KYOPRO_LAMBDA3(_1,\
    \ _2, value) ([&](auto&& _1, auto&& _2) noexcept { return (value); })\n#define\
    \ KYOPRO_LAMBDA4(_1, _2, _3, value) ([&](auto&& _1, auto&& _2, auto&& _3) noexcept\
    \ { return (value); })\n#define lambda(...) KYOPRO_OVERLOAD_MACRO(__VA_ARGS__,\
    \ KYOPRO_LAMBDA4, KYOPRO_LAMBDA3, KYOPRO_LAMBDA2, KYOPRO_LAMBDA1)(__VA_ARGS__)\n\
    #define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)\n#define rall(...)\
    \ std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)\n"
  code: "#pragma once\n#include <iterator>\n#include <tuple>\n#include <type_traits>\n\
    #include <utility>\n#include \"../meta/settings.hpp\"\n#include \"../system/in.hpp\"\
    \n\nnamespace kyopro::helper {\n  template<KYOPRO_BASE_UINT len>\n  constexpr\
    \ KYOPRO_BASE_UINT va_args_size(const char (&s)[len]) noexcept {\n    if constexpr\
    \ (len == 0) return 0;\n    KYOPRO_BASE_UINT cnt = 1;\n    for (auto i: s) if\
    \ (i == ',') ++cnt;\n    return cnt;\n  }\n\n  template<class F, KYOPRO_BASE_UINT...\
    \ idx>\n  auto read_impl(F&& f, std::integer_sequence<KYOPRO_BASE_UINT, idx...>)\
    \ {\n    auto res = std::tuple{(static_cast<void>(idx), f())...};\n    scan(res);\n\
    \    return res;\n  }\n}\n#define read(init, ...) auto [__VA_ARGS__] = kyopro::helper::read_impl([&]\
    \ { return init; }, std::make_integer_sequence<KYOPRO_BASE_UINT, kyopro::helper::va_args_size(#__VA_ARGS__)>())\n\
    #define KYOPRO_OVERLOAD_MACRO(_1, _2, _3, _4, name, ...) name\n#define KYOPRO_REP0()\
    \ for (; ; )\n#define KYOPRO_REP1(last) KYOPRO_REP2(KYOPRO_COUNTER, last)\n#define\
    \ KYOPRO_REP2(i, last) for (auto i = std::decay_t<decltype(last)>(), KYOPRO_LAST\
    \ = (last); (i) < (KYOPRO_LAST); ++(i))\n#define KYOPRO_REP3(i, first, last) for\
    \ (auto i = (first), KYOPRO_LAST = last; (i) < (KYOPRO_LAST); ++(i))\n#define\
    \ rep(...) KYOPRO_OVERLOAD_MACRO(__VA_ARGS__ __VA_OPT__(,) KYOPRO_REP4, KYOPRO_REP3,\
    \ KYOPRO_REP2, KYOPRO_REP1, KYOPRO_REP0)(__VA_ARGS__)\n#define KYOPRO_LAMBDA1(value)\
    \ ([&]() noexcept { return (value);})\n#define KYOPRO_LAMBDA2(_1, value) ([&](auto&&\
    \ _1) noexcept { return (value); })\n#define KYOPRO_LAMBDA3(_1, _2, value) ([&](auto&&\
    \ _1, auto&& _2) noexcept { return (value); })\n#define KYOPRO_LAMBDA4(_1, _2,\
    \ _3, value) ([&](auto&& _1, auto&& _2, auto&& _3) noexcept { return (value);\
    \ })\n#define lambda(...) KYOPRO_OVERLOAD_MACRO(__VA_ARGS__, KYOPRO_LAMBDA4, KYOPRO_LAMBDA3,\
    \ KYOPRO_LAMBDA2, KYOPRO_LAMBDA1)(__VA_ARGS__)\n#define all(...) std::begin(__VA_ARGS__),\
    \ std::end(__VA_ARGS__)\n#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)"
  dependsOn:
  - meta/settings.hpp
  - system/in.hpp
  - math/power.hpp
  - meta/trait.hpp
  isVerificationFile: false
  path: template/macro.hpp
  requiredBy:
  - kyopro.hpp
  - template/all.hpp
  timestamp: '2022-05-08 20:22:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/macro.hpp
layout: document
redirect_from:
- /library/template/macro.hpp
- /library/template/macro.hpp.html
title: template/macro.hpp
---