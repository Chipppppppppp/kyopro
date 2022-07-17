---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/Hash.hpp
    title: algorithm/Hash.hpp
  - icon: ':heavy_check_mark:'
    path: algorithm/bit.hpp
    title: algorithm/bit.hpp
  - icon: ':warning:'
    path: algorithm/compress.hpp
    title: algorithm/compress.hpp
  - icon: ':heavy_check_mark:'
    path: meta/aggregate.hpp
    title: meta/aggregate.hpp
  - icon: ':heavy_check_mark:'
    path: meta/settings.hpp
    title: meta/settings.hpp
  - icon: ':heavy_check_mark:'
    path: meta/trait.hpp
    title: meta/trait.hpp
  _extendedRequiredBy:
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
  bundledCode: "#line 2 \"algorithm/bit.hpp\"\n#include <limits>\n#include <type_traits>\n\
    #line 2 \"meta/settings.hpp\"\n#include <cstdint>\n\n#ifndef KYOPRO_BASE_INT\n\
    #define KYOPRO_BASE_INT std::int64_t\n#endif\n\n#ifndef KYOPRO_BASE_UINT\n#define\
    \ KYOPRO_BASE_UINT std::uint64_t\n#endif\n\n#ifndef KYOPRO_BASE_FLOAT\n#define\
    \ KYOPRO_BASE_FLOAT double\n#endif\n\n#ifndef KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD\
    \ static_cast<KYOPRO_BASE_UINT>(998244353)\n#endif\n\n#ifndef KYOPRO_DECIMAL_PRECISION\n\
    #define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n#endif\n\n\
    #ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 5 \"algorithm/bit.hpp\"\n\nnamespace kyopro {\n  inline constexpr\
    \ struct {\n    template<class T>\n    constexpr KYOPRO_BASE_INT operator ()(T\
    \ x) const noexcept {\n      constexpr auto digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;\n\
    \      static_assert(digits <= std::numeric_limits<unsigned long long>::digits,\
    \ \"Integer size is too large\");\n      if constexpr (digits <= std::numeric_limits<unsigned\
    \ int>::digits) return __builtin_popcount(x);\n      else if constexpr (digits\
    \ <= std::numeric_limits<unsigned long>::digits) return __builtin_popcountl(x);\n\
    \      else return __builtin_popcountll(x);\n    }\n  } pop_count;\n\n  inline\
    \ constexpr struct {\n    template<class T>\n    constexpr KYOPRO_BASE_INT operator\
    \ ()(T x) const noexcept {\n      constexpr auto digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;\n\
    \      static_assert(digits <= std::numeric_limits<unsigned long long>::digits,\
    \ \"Integer size is too large\");\n      if (x == 0) return 0;\n      if constexpr\
    \ (digits <= std::numeric_limits<unsigned int>::digits) return __builtin_clz(x)\
    \ + digits - std::numeric_limits<unsigned int>::digits;\n      else if constexpr\
    \ (digits <= std::numeric_limits<unsigned long>::digits) return __builtin_clzl(x)\
    \ + digits - std::numeric_limits<unsigned long>::digits;\n      else return __builtin_clzll(x)\
    \ + digits - std::numeric_limits<unsigned long long>::digits;\n    }\n  } leading_zero;\n\
    \n  inline constexpr struct {\n    template<class T>\n    constexpr KYOPRO_BASE_INT\
    \ operator ()(T x) const noexcept {\n      constexpr auto digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;\n\
    \      static_assert(digits <= std::numeric_limits<unsigned long long>::digits,\
    \ \"Integer size is too large\");\n      if constexpr (digits <= std::numeric_limits<unsigned\
    \ int>::digits) return __builtin_ctz(x);\n      else if constexpr (digits <= std::numeric_limits<unsigned\
    \ long>::digits) return __builtin_ctzl(x);\n      else return __builtin_ctzll(x);\n\
    \    }\n  } trailing_zero;\n\n  inline constexpr struct {\n    template<class\
    \ T>\n    constexpr KYOPRO_BASE_INT operator ()(T x) const noexcept {\n      constexpr\
    \ auto digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;\n      static_assert(digits\
    \ <= std::numeric_limits<unsigned long long>::digits, \"Integer size is too large\"\
    );\n      if (x == 0) return 0;\n      if constexpr (digits <= std::numeric_limits<unsigned\
    \ int>::digits) return std::numeric_limits<unsigned int>::digits - __builtin_clz(x);\n\
    \      else if constexpr (digits <= std::numeric_limits<unsigned long>::digits)\
    \ return std::numeric_limits<unsigned long>::digits - __builtin_clzl(x);\n   \
    \   else return std::numeric_limits<unsigned long long>::digits - __builtin_clzll(x);\n\
    \    }\n  } bit_len;\n\n  inline constexpr struct {\n    template<class T>\n \
    \   constexpr KYOPRO_BASE_INT operator ()(T x) const noexcept {\n      return\
    \ bit_len(x >> static_cast<T>(1));\n    }\n  } floor_bit;\n\n  inline constexpr\
    \ struct {\n    template<class T>\n    constexpr KYOPRO_BASE_INT operator ()(T\
    \ x) const noexcept {\n      if (x == 0) return 0;\n      return bit_len(x - static_cast<T>(1));\n\
    \    }\n  } ceil_bit;\n}\n#line 2 \"algorithm/compress.hpp\"\n#include <algorithm>\n\
    #include <functional>\n#include <iterator>\n#include <unordered_map>\n#include\
    \ <vector>\n#line 8 \"algorithm/compress.hpp\"\n\nnamespace kyopro {\n  inline\
    \ constexpr struct {\n    template<class T, class Container = std::unordered_map<typename\
    \ std::iterator_traits<T>::value_type, KYOPRO_BASE_INT>, class Compare>\n    constexpr\
    \ auto operator ()(T first, T last, Compare comp = std::less<typename std::iterator_traits<T>::value_type>())\
    \ const {\n      std::vector<typename std::iterator_traits<T>::value_type> vec(first,\
    \ last);\n      std::sort(vec.begin(), vec.end(), comp);\n      auto end = std::unique(vec.begin(),\
    \ vec.end());\n      Container mem;\n      int cnt = -1;\n      for (auto i =\
    \ vec.begin(); i != end; ++i) mem[*i] = ++cnt;\n      return mem;\n    }\n  }\
    \ compress;\n}\n#line 2 \"algorithm/Hash.hpp\"\n#include <cstddef>\n#line 5 \"\
    algorithm/Hash.hpp\"\n#include <tuple>\n#line 7 \"algorithm/Hash.hpp\"\n#include\
    \ <utility>\n#line 3 \"meta/trait.hpp\"\n#include <queue>\n#line 5 \"meta/trait.hpp\"\
    \n#include <stack>\n#line 9 \"meta/trait.hpp\"\n\ntemplate<>\nstruct std::is_integral<__int128_t>:\
    \ std::true_type {};\ntemplate<>\nstruct std::is_integral<__uint128_t>: std::true_type\
    \ {};\ntemplate<>\nstruct std::is_floating_point<__float128>: std::true_type {};\n\
    \nnamespace kyopro {\n  template<KYOPRO_BASE_UINT size>\n  struct int_least {\n\
    \  private:\n    static constexpr auto get_type() noexcept {\n      static_assert(size\
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
    \ std::false_type {};\n  template<class T>\n  struct is_iterable<T, std::void_t<decltype(std::begin(std::declval<std::add_lvalue_reference_t<T>>()),\
    \ std::end(std::declval<std::add_lvalue_reference_t<T>>()))>>: std::true_type\
    \ {};\n\n  template<class T>\n  constexpr bool is_iterable_v = is_iterable<T>::value;\n\
    \n  template<class T>\n  struct iterable_value {\n    using type = std::decay_t<decltype(*std::begin(std::declval<T>()))>;\n\
    \  };\n\n  template<class T>\n  using iterable_value_t = typename iterable_value<T>::type;\n\
    \n  namespace helper {\n    struct CastableToAny {\n      template<class T>\n\
    \      operator T() const noexcept;\n    };\n\n    template<class T, std::size_t...\
    \ idx, std::void_t<decltype(T{((void)idx, CastableToAny{})...})>* = nullptr>\n\
    \    constexpr bool is_aggregate_initializable(std::index_sequence<idx...>, bool)\
    \ noexcept {\n      return true;\n    }\n    template<class T, std::size_t...\
    \ idx>\n    constexpr bool is_aggregate_initializable(std::index_sequence<idx...>,\
    \ char) noexcept {\n      return false;\n    }\n\n    template<class T, std::size_t\
    \ n, std::enable_if_t<is_aggregate_initializable<T>(std::make_index_sequence<n>(),\
    \ false)>* = nullptr>\n    constexpr std::size_t aggregate_size_impl() {\n   \
    \   return n;\n    }\n    template<class T, std::size_t n, std::enable_if_t<!is_aggregate_initializable<T>(std::make_index_sequence<n>(),\
    \ false)>* = nullptr>\n    constexpr std::size_t aggregate_size_impl() {\n   \
    \   static_assert(n != 0, \"Aggregate is required\");\n      return aggregate_size_impl<T,\
    \ n - 1>();\n    }\n  }\n\n  template<class T, class = void>\n  struct aggregate_size\
    \ {\n    static_assert(std::is_aggregate_v<T>, \"Aggregate is required\");\n \
    \   static constexpr std::size_t value = helper::aggregate_size_impl<T, std::numeric_limits<unsigned\
    \ char>::digits * sizeof(T)>();\n  };\n  template<class T>\n  struct aggregate_size<T,\
    \ std::void_t<decltype(std::tuple_size<T>::value)>> {\n    static_assert(std::is_aggregate_v<T>,\
    \ \"Aggregate is required\");\n    static constexpr std::size_t value = std::tuple_size_v<T>;\n\
    \  };\n  template<class T>\n  constexpr std::size_t aggregate_size_v = aggregate_size<T>::value;\n\
    \n  template<std::size_t idx, class T>\n  struct aggregate_element {\n    static_assert(std::is_aggregate_v<T>);\n\
    \n  private:\n    template<class U>\n    struct Type {\n      using type = U;\n\
    \    };\n\n    template<class U, std::enable_if_t<aggregate_size_v<std::decay_t<U>>\
    \ == 1>* = nullptr>\n    static constexpr auto get_type(U aggregate, char) noexcept\
    \ {\n      auto&& [a] = aggregate;\n      static_assert(idx < 1, \"Tuple index\
    \ out of range\");\n      return Type<decltype(a)>();\n    }\n    template<class\
    \ U, std::enable_if_t<aggregate_size_v<std::decay_t<U>> == 2>* = nullptr>\n  \
    \  static constexpr auto get_type(U aggregate, char) noexcept {\n      auto&&\
    \ [a, b] = aggregate;\n      static_assert(idx < 2, \"Tuple index out of range\"\
    );\n      if constexpr (idx == 0) return Type<decltype(a)>();\n      else return\
    \ Type<decltype(b)>();\n    }\n    template<class U, std::enable_if_t<aggregate_size_v<std::decay_t<U>>\
    \ == 3>* = nullptr>\n    static constexpr auto get_type(U aggregate, char) noexcept\
    \ {\n      auto&& [a, b, c] = aggregate;\n      static_assert(idx < 3, \"Tuple\
    \ index out of range\");\n      if constexpr (idx == 0) return Type<decltype(a)>();\n\
    \      else if constexpr (idx == 1) return Type<decltype(b)>();\n      else return\
    \ Type<decltype(c)>();\n    }\n    template<class U, std::enable_if_t<aggregate_size_v<std::decay_t<U>>\
    \ == 4>* = nullptr>\n    static constexpr auto access_impl(U aggregate, char)\
    \ noexcept {\n      auto&& [a, b, c, d] = aggregate;\n      static_assert(idx\
    \ < 4, \"Tuple index out of range\");\n      if constexpr (idx == 0) return Type<decltype(a)>();\n\
    \      else if constexpr (idx == 1) return Type<decltype(b)>();\n      else if\
    \ constexpr (idx == 2) return Type<decltype(c)>();\n      else return Type<decltype(d)>();\n\
    \    }\n    template<class U, std::enable_if_t<aggregate_size_v<std::decay_t<U>>\
    \ == 5>* = nullptr>\n    static constexpr auto get_type(U aggregate, char) noexcept\
    \ {\n      auto&& [a, b, c, d, e] = aggregate;\n      static_assert(idx < 5, \"\
    Tuple index out of range\");\n      if constexpr (idx == 0) return Type<decltype(a)>();\n\
    \      else if constexpr (idx == 1) return Type<decltype(b)>();\n      else if\
    \ constexpr (idx == 2) return Type<decltype(c)>();\n      else if constexpr (idx\
    \ == 3) return Type<decltype(d)>();\n      else return Type<decltype(e)>();\n\
    \    }\n    template<class U, std::enable_if_t<aggregate_size_v<std::decay_t<U>>\
    \ == 6>* = nullptr>\n    static constexpr auto get_type(U aggregate, char) noexcept\
    \ {\n      auto&& [a, b, c, d, e, f] = aggregate;\n      static_assert(idx < 6,\
    \ \"Tuple index out of range\");\n      if constexpr (idx == 0) return Type<decltype(a)>();\n\
    \      else if constexpr (idx == 1) return Type<decltype(b)>();\n      else if\
    \ constexpr (idx == 2) return Type<decltype(c)>();\n      else if constexpr (idx\
    \ == 3) return Type<decltype(d)>();\n      else if constexpr (idx == 4) return\
    \ Type<decltype(e)>();\n      else return Type<decltype(f)>();\n    }\n    template<class\
    \ U, std::enable_if_t<aggregate_size_v<std::decay_t<U>> == 7>* = nullptr>\n  \
    \  static constexpr auto get_type(U aggregate, char) noexcept {\n      auto&&\
    \ [a, b, c, d, e, f, g] = aggregate;\n      static_assert(idx < 7, \"Tuple index\
    \ out of range\");\n      if constexpr (idx == 0) return Type<decltype(a)>();\n\
    \      else if constexpr (idx == 1) return Type<decltype(b)>();\n      else if\
    \ constexpr (idx == 2) return Type<decltype(c)>();\n      else if constexpr (idx\
    \ == 3) return Type<decltype(d)>();\n      else if constexpr (idx == 4) return\
    \ Type<decltype(e)>();\n      else if constexpr (idx == 5) return Type<decltype(f)>();\n\
    \      else return Type<decltype(g)>();\n    }\n    template<class U, std::enable_if_t<aggregate_size_v<std::decay_t<U>>\
    \ == 8>* = nullptr>\n    static constexpr auto get_type(U aggregate, char) noexcept\
    \ {\n      auto&& [a, b, c, d, e, f, g, h] = aggregate;\n      static_assert(idx\
    \ < 8, \"Tuple index out of range\");\n      if constexpr (idx == 0) return Type<decltype(a)>();\n\
    \      else if constexpr (idx == 1) return Type<decltype(b)>();\n      else if\
    \ constexpr (idx == 2) return Type<decltype(c)>();\n      else if constexpr (idx\
    \ == 3) return Type<decltype(d)>();\n      else if constexpr (idx == 4) return\
    \ Type<decltype(e)>();\n      else if constexpr (idx == 5) return Type<decltype(f)>();\n\
    \      else if constexpr (idx == 6) return Type<decltype(g)>();\n      else return\
    \ Type<decltype(h)>();\n    }\n    template<class U, std::void_t<std::tuple_element_t<idx,\
    \ U>>* = nullptr>\n    static constexpr auto get_type(U, bool) noexcept {\n  \
    \    return Type<std::tuple_element_t<idx, U>>();\n    }\n\n  public:\n    using\
    \ type = typename decltype(get_type(std::declval<T>(), false))::type;\n  };\n\n\
    \  template<std::size_t idx, class T>\n  using aggregate_element_t = typename\
    \ aggregate_element<idx, T>::type;\n\n  template<class T>\n  struct is_agg: std::conjunction<std::is_aggregate<T>,\
    \ std::negation<is_iterable<T>>> {};\n\n  template<class T>\n  inline constexpr\
    \ bool is_agg_v = is_agg<T>::value;\n}\n#line 7 \"meta/aggregate.hpp\"\n\nnamespace\
    \ kyopro {\n  namespace helper {\n    #define DEFINE_ACCESS(n, ...) \\\n    template<std::size_t\
    \ idx, class T, std::enable_if_t<aggregate_size_v<std::decay_t<T>> == n>* = nullptr>\\\
    \n    constexpr decltype(auto) access_impl(T&& aggregate, char) noexcept {\\\n\
    \      auto&& [__VA_ARGS__] = std::forward<T>(aggregate);\\\n      return std::get<idx>(std::forward_as_tuple(__VA_ARGS__));\\\
    \n    }\n\n    DEFINE_ACCESS(1, a)\n    DEFINE_ACCESS(2, a, b)\n    DEFINE_ACCESS(3,\
    \ a, b, c)\n    DEFINE_ACCESS(4, a, b, c, d)\n    DEFINE_ACCESS(5, a, b, c, d,\
    \ e)\n    DEFINE_ACCESS(6, a, b, c, d, e, f)\n    DEFINE_ACCESS(7, a, b, c, d,\
    \ e, f, g)\n    DEFINE_ACCESS(8, a, b, c, d, e, f, g, h)\n\n    template<std::size_t\
    \ idx, class T, std::void_t<decltype(std::get<idx>(std::declval<std::decay_t<T>>()))>*\
    \ = nullptr>\n    constexpr decltype(auto) access_impl(T&& aggregate, bool) noexcept\
    \ {\n      return std::get<idx>(std::forward<T>(aggregate));\n    }\n\n    #undef\
    \ DEFINE_ACCESS\n  }\n\n  template<std::size_t idx, class T>\n  constexpr decltype(auto)\
    \ access(T&& aggregate) noexcept {\n    return helper::access_impl<idx>(std::forward<T>(aggregate),\
    \ false);\n  }\n}\n#line 11 \"algorithm/Hash.hpp\"\n\nnamespace kyopro {\n  template<class,\
    \ class = void>\n  struct Hash;\n\n  template<class T>\n  struct Hash<T, std::enable_if_t<std::is_scalar_v<T>>>:\
    \ std::hash<T> {\n    using value_type = T;\n\n    constexpr std::size_t operator\
    \ ()(T a) const noexcept {\n      return std::hash<T>::operator ()(a);\n    }\n\
    \  };\n\n  template<class T>\n  struct Hash<T, std::enable_if_t<is_agg_v<T>>>\
    \ {\n    using value_type = T;\n\n    template<KYOPRO_BASE_UINT i = 0>\n    constexpr\
    \ std::size_t operator ()(const T& a) const noexcept {\n      if constexpr (i\
    \ == aggregate_size_v<T>) return aggregate_size_v<T>;\n      else {\n        std::uint_fast64_t\
    \ seed = operator()<i + 1>(a);\n        return seed ^ (Hash<aggregate_element_t<i,\
    \ T>>()(access<i>(a)) + 0x9e3779b97f4a7c15LU + (seed << 12) + (seed >> 4));\n\
    \      }\n    }\n  };\n\n  template<class T>\n  struct Hash<T, std::enable_if_t<is_iterable_v<T>>>:\
    \ Hash<iterable_value_t<T>> {\n    using value_type = T;\n\n    constexpr std::size_t\
    \ operator ()(const T& a) const noexcept {\n      std::uint_fast64_t seed = a.size();\n\
    \      for (auto&& i: a) seed ^= Hash<iterable_value_t<T>>(i) + 0x9e3779b97f4a7c15LU\
    \ + (seed << 12) + (seed >> 4);\n      return seed;\n    }\n  };\n}\n#line 5 \"\
    algorithm/all.hpp\"\n"
  code: '#pragma once

    #include "bit.hpp"

    #include "compress.hpp"

    #include "Hash.hpp"'
  dependsOn:
  - algorithm/bit.hpp
  - meta/settings.hpp
  - algorithm/compress.hpp
  - algorithm/Hash.hpp
  - meta/aggregate.hpp
  - meta/trait.hpp
  isVerificationFile: false
  path: algorithm/all.hpp
  requiredBy:
  - all/all.hpp
  - all.hpp
  timestamp: '2022-07-07 16:11:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/all.hpp
layout: document
redirect_from:
- /library/algorithm/all.hpp
- /library/algorithm/all.hpp.html
title: algorithm/all.hpp
---
