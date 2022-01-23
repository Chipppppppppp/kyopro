---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: base/Hash.hpp
    title: base/Hash.hpp
  - icon: ':heavy_check_mark:'
    path: base/constant.hpp
    title: base/constant.hpp
  - icon: ':warning:'
    path: base/printer.hpp
    title: base/printer.hpp
  - icon: ':heavy_check_mark:'
    path: base/settings.hpp
    title: base/settings.hpp
  - icon: ':warning:'
    path: base/trait.hpp
    title: base/trait.hpp
  - icon: ':heavy_check_mark:'
    path: math/power.hpp
    title: math/power.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"base/constant.hpp\"\n#include <array>\n#include <cstdint>\n\
    #include <limits>\n#include <utility>\n#line 3 \"base/settings.hpp\"\n\n#ifndef\
    \ KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT std::int64_t\n#endif\n\n#ifndef KYOPRO_BASE_UINT\n\
    #define KYOPRO_BASE_UINT std::size_t\n#endif\n\n#ifndef KYOPRO_BASE_FLOAT\n#define\
    \ KYOPRO_BASE_FLOAT double\n#endif\n\n#ifndef KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD\
    \ static_cast<KYOPRO_BASE_UINT>(1000000007)\n#endif\n\n#ifndef KYOPRO_DECIMAL_PRECISION\n\
    #define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n#endif\n\n\
    #ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 4 \"math/power.hpp\"\nnamespace kyopro {\n  template<class _typeT>\n\
    \  constexpr _typeT power(_typeT _a, std::uint_fast64_t _n, _typeT _init = 1)\
    \ noexcept {\n    while (_n > 0) {\n      if (_n & 1) _init *= _a;\n      _a *=\
    \ _a;\n      _n >>= 1;\n    }\n    return _init;\n  }\n}\n#line 8 \"base/constant.hpp\"\
    \n\nnamespace kyopro {\n  inline constexpr std::uint_fast64_t _decimal_max = power(static_cast<std::uint_fast64_t>(10),\
    \ KYOPRO_DECIMAL_PRECISION);\n\n  template<class _typeT>\n  inline constexpr _typeT\
    \ MOD = KYOPRO_DEFAULT_MOD;\n  inline constexpr KYOPRO_BASE_INT mod = MOD<KYOPRO_BASE_INT>;\n\
    \n  template<class _typeT>\n  inline constexpr _typeT INF = std::numeric_limits<_typeT>::max()\
    \ / KYOPRO_INF_DIV;\n  inline constexpr KYOPRO_BASE_INT inf = INF<KYOPRO_BASE_INT>;\n\
    \n  template<class _typeT>\n  inline constexpr KYOPRO_BASE_FLOAT EPS = static_cast<_typeT>(1)\
    \ / _decimal_max;\n  inline constexpr KYOPRO_BASE_FLOAT eps = EPS<KYOPRO_BASE_FLOAT>;\n\
    \n  template<class _typeT>\n  inline constexpr _typeT PI = 3.14159265358979323846;\n\
    \  inline constexpr KYOPRO_BASE_FLOAT pi = PI<KYOPRO_BASE_FLOAT>;\n\n  inline\
    \ constexpr std::array<std::pair<KYOPRO_BASE_INT, KYOPRO_BASE_INT>, 4> beside{{{1,\
    \ 0}, {0, 1}, {-1, 0}, {0, -1}}};\n  inline constexpr std::array<std::pair<KYOPRO_BASE_INT,\
    \ KYOPRO_BASE_INT>, 8> around{{{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1,\
    \ -1}, {0, -1}, {1, -1}}};\n}\n#line 2 \"base/Hash.hpp\"\n#include <cstddef>\n\
    #include <tuple>\n#include <type_traits>\n#line 2 \"base/trait.hpp\"\n#include\
    \ <iterator>\n#include <queue>\n#include <stack>\n#line 7 \"base/trait.hpp\"\n\
    \n#ifdef __SIZEOF_INT128__\ntemplate<>\nstruct std::is_integral<__int128_t>: std::true_type\
    \ {};\ntemplate<>\nstruct std::is_signed<__int128_t>: std::true_type {};\ntemplate<>\n\
    struct std::is_integral<__uint128_t>: std::true_type {};\ntemplate<>\nstruct std::is_unsigned<__uint128_t>:\
    \ std::true_type {};\n#endif\n#ifdef __SIZEOF_FLOAT128__\ntemplate<>\nstruct std::is_floating_point<__float128>:\
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
    \ 7 \"base/Hash.hpp\"\n\nnamespace kyopro {\n  template<class, class = void>\n\
    \  struct Hash;\n\n  template<class _typeT>\n  struct Hash<_typeT, std::enable_if_t<std::is_integral_v<_typeT>>>\
    \ { constexpr KYOPRO_BASE_UINT operator ()(_typeT _a) const noexcept { return\
    \ _a; } };\n\n  template<class _typeT>\n  struct Hash<_typeT, std::enable_if_t<std::is_floating_point_v<_typeT>>>\
    \ { constexpr KYOPRO_BASE_UINT operator ()(_typeT _a) const noexcept { return\
    \ static_cast<KYOPRO_BASE_UINT>(_a) & 0xfffff000; } };\n\n  template<class _typeT>\n\
    \  struct Hash<_typeT*, void> { constexpr KYOPRO_BASE_UINT operator ()(_typeT*\
    \ _a) const noexcept { return reinterpret_cast<KYOPRO_BASE_UINT>(_a); } };\n\n\
    \  template<>\n  struct Hash<std::nullptr_t, void> { constexpr KYOPRO_BASE_UINT\
    \ operator ()(std::nullptr_t) const noexcept { return 0; } };\n\n  template<class\
    \ _typeT>\n  struct Hash<_typeT, std::enable_if_t<is_tuple_v<_typeT>>> {\n   \
    \ template<KYOPRO_BASE_UINT _i = 0>\n    constexpr KYOPRO_BASE_UINT operator ()(const\
    \ _typeT& _a) const noexcept {\n      if constexpr (_i == std::tuple_size_v<_typeT>)\
    \ return std::tuple_size_v<_typeT>;\n      else {\n        KYOPRO_BASE_UINT _seed\
    \ = operator()<_i + 1>(_a);\n        return _seed ^ (Hash<std::tuple_element_t<_i,\
    \ _typeT>>()(get<_i>(_a)) + 0x9e3779b97f4a7c15LU + (_seed << 12) + (_seed >> 4));\n\
    \      }\n    }\n  };\n\n  template<class _typeT>\n  struct Hash<_typeT, std::enable_if_t<is_iterable_v<_typeT>>>\
    \ {\n  private:\n    [[no_unique_address]] Hash<typename _typeT::value_type> make_hash;\n\
    \  public:\n    constexpr KYOPRO_BASE_UINT operator ()(const _typeT& _a) const\
    \ noexcept {\n      KYOPRO_BASE_UINT _seed = _a.size();\n      for (auto& _i:\
    \ _a) _seed ^= make_hash(_i) + 0x9e3779b97f4a7c15LU + (_seed << 12) + (_seed >>\
    \ 4);\n      return _seed;\n    }\n  };\n}\n#line 2 \"base/printer.hpp\"\n#include\
    \ <unistd.h>\n#line 6 \"base/printer.hpp\"\n#include <string>\n#line 12 \"base/printer.hpp\"\
    \n\nnamespace kyopro {\n  template<bool space = false, bool flush = false, size_t\
    \ buf_size = KYOPRO_BUFFER_SIZE>\n  struct Printer {\n  private:\n    int fd;\n\
    \    std::array<char, buf_size> buffer;\n    int idx;\n  public:\n    Printer(int\
    \ fd): fd(fd), idx() {}\n    ~Printer() { write(fd, buffer.begin(), idx); }\n\n\
    \    template<class, class = void>\n    struct impl;\n\n    template<>\n    struct\
    \ impl<char, void> {\n      static void print(char a) {\n        buffer[idx] =\
    \ c;\n        ++idx;\n        if (idx == buf_size) {\n          write(fd, buffer.begin(),\
    \ buf_size);\n          idx = 0;\n        }\n      }\n    };\n\n    template<>\n\
    \    struct impl<const char*, void> { static void print(const char* a) { for (int\
    \ i = 0; a[i]; ++i) impl<char>::print(a[i]); } };\n\n    template<>\n    struct\
    \ impl<std::string, void> { static void print(const std::string& a) { for (const\
    \ char& i: a) impl<char>::print(i); } };\n\n    template<class T>\n    struct\
    \ impl<T, std::enable_if_t<std::is_arithmetic_v<T>>> {\n      static void print(T\
    \ a) {\n        if (a < T()) {\n          impl<char>::print('-');\n          a\
    \ = -a;\n        }\n        std::uint_fast64_t p = a;\n        a -= p;\n     \
    \   std::string s;\n        do {\n          s += '0' + p % 10;\n          p /=\
    \ 10;\n        } while (p > 0);\n        for (auto i = s.rbegin(); i != s.rend();\
    \ ++i) impl<char>::print(*i);\n        if constexpr (std::is_integral_v<T>) return;\n\
    \        impl<char>::print('.');\n        for (int i = 0; i < static_cast<int>(KYOPRO_DECIMAL_PRECISION);\
    \ ++i) {\n          a *= 10;\n          impl<char>::print('0' + static_cast<std::uint_fast64_t>(a)\
    \ % 10);\n        }\n      }\n    };\n\n    template<>\n    struct impl<std::tuple<>,\
    \ void> { static void print(std::tuple<>) {} };\n\n    template<class T>\n   \
    \ struct impl<T, std::enable_if_t<std::is_tuple_v<T>>> {\n      template<>\n \
    \     static void print(const T& a) {\n        impl<std::tuple_element_t<i, T>>::print(get<i>(a));\n\
    \        if constexpr (i + 1 < std::tuple_size_v<T>) {\n          impl<char>::print('\
    \ ');\n          print<i + 1>(a);\n        }\n      }\n    };\n\n    template<class\
    \ T>\n    struct impl<T, std::enable_if_t<is_iterable_v<T>>> {\n      static void\
    \ print(const T& a) {\n        if (std::empty(a)) return;\n        for (auto i\
    \ = std::begin(a); ; ) {\n          impl<typename T::value_type>::print(*i);\n\
    \          if (++i != std::end(a)) {\n            if constexpr (is_iterable_v<typename\
    \ T::value_type>) impl<char>::print('\\n');\n            else impl<char>::print('\
    \ ');\n          } else break;\n        }\n      }\n    };\n\n    void operator\
    \ ()() {\n      if constexpr (space) impl<char>::print('\\n');\n      if constexpr\
    \ (flush) {\n        write(fd, buffer.begin(), idx);\n        idx = 0;\n     \
    \ }\n    }\n    template<class T>\n    void operator ()(T&& a) {\n      impl<std::remove_reference_t<T>>::print(a);\n\
    \      operator ()();\n    }\n    template<class Head, class... Args>\n    void\
    \ operator ()(Head&& head, Args&&... args) {\n      impl<std::remove_reference_t<Head>>::print(head);\n\
    \      if constexpr (space) impl<char>::print(' ');\n      operator ()(std::forward<Args>(args)...);\n\
    \    }\n  };\n\n  Printer print(1), eprint(2);\n  Printer<true> println(1), eprintln(2);\n\
    }\n#line 7 \"base/all.hpp\"\n"
  code: '#pragma once

    #include "constant.hpp"

    #include "Hash.hpp"

    #include "printer.hpp"

    #include "settings.hpp"

    #include "trait.hpp"'
  dependsOn:
  - base/constant.hpp
  - math/power.hpp
  - base/settings.hpp
  - base/Hash.hpp
  - base/trait.hpp
  - base/printer.hpp
  isVerificationFile: false
  path: base/all.hpp
  requiredBy:
  - all.hpp
  timestamp: '2022-01-23 18:51:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: base/all.hpp
layout: document
redirect_from:
- /library/base/all.hpp
- /library/base/all.hpp.html
title: base/all.hpp
---
