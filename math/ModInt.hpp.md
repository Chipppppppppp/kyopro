---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: algorithm/Hash.hpp
    title: algorithm/Hash.hpp
  - icon: ':x:'
    path: algorithm/bit.hpp
    title: algorithm/bit.hpp
  - icon: ':warning:'
    path: math/mod.hpp
    title: math/mod.hpp
  - icon: ':x:'
    path: math/power.hpp
    title: math/power.hpp
  - icon: ':x:'
    path: meta/aggregate.hpp
    title: meta/aggregate.hpp
  - icon: ':x:'
    path: meta/constant.hpp
    title: meta/constant.hpp
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
  - icon: ':warning:'
    path: all/all.hpp
    title: all/all.hpp
  - icon: ':warning:'
    path: math/all.hpp
    title: math/all.hpp
  - icon: ':warning:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':warning:'
    path: template/all.hpp
    title: template/all.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/ModInt.hpp\"\n#include <cassert>\n#include <cstddef>\n\
    #include <cstdint>\n#include <limits>\n#include <type_traits>\n#include <utility>\n\
    #line 3 \"meta/settings.hpp\"\n\n#ifndef KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT\
    \ std::int64_t\n#endif\n\n#ifndef KYOPRO_BASE_UINT\n#define KYOPRO_BASE_UINT std::uint64_t\n\
    #endif\n\n#ifndef KYOPRO_BASE_FLOAT\n#define KYOPRO_BASE_FLOAT double\n#endif\n\
    \n#ifndef KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD static_cast<KYOPRO_BASE_UINT>(998244353)\n\
    #endif\n\n#ifndef KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n\
    #endif\n\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 5 \"algorithm/bit.hpp\"\n\nnamespace kyopro {\n  template<class\
    \ T>\n  constexpr KYOPRO_BASE_INT pop_count(T x) noexcept {\n    constexpr auto\
    \ digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;\n    static_assert(digits\
    \ <= std::numeric_limits<unsigned long long>::digits, \"Integer size is too large\"\
    );\n    if constexpr (digits <= std::numeric_limits<unsigned int>::digits) return\
    \ __builtin_popcount(x);\n    else if constexpr (digits <= std::numeric_limits<unsigned\
    \ long>::digits) return __builtin_popcountl(x);\n    else return __builtin_popcountll(x);\n\
    \  }\n\n  template<class T>\n  constexpr KYOPRO_BASE_INT leading_zero(T x) noexcept\
    \ {\n    constexpr auto digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;\n\
    \    static_assert(digits <= std::numeric_limits<unsigned long long>::digits,\
    \ \"Integer size is too large\");\n    if (x == 0) return 0;\n    if constexpr\
    \ (digits <= std::numeric_limits<unsigned int>::digits) return __builtin_clz(x)\
    \ + digits - std::numeric_limits<unsigned int>::digits;\n    else if constexpr\
    \ (digits <= std::numeric_limits<unsigned long>::digits) return __builtin_clzl(x)\
    \ + digits - std::numeric_limits<unsigned long>::digits;\n    else return __builtin_clzll(x)\
    \ + digits - std::numeric_limits<unsigned long long>::digits;\n  }\n\n  template<class\
    \ T>\n  constexpr KYOPRO_BASE_INT trailing_zero(T x) noexcept {\n    constexpr\
    \ auto digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;\n    static_assert(digits\
    \ <= std::numeric_limits<unsigned long long>::digits, \"Integer size is too large\"\
    );\n    if constexpr (digits <= std::numeric_limits<unsigned int>::digits) return\
    \ __builtin_ctz(x);\n    else if constexpr (digits <= std::numeric_limits<unsigned\
    \ long>::digits) return __builtin_ctzl(x);\n    else return __builtin_ctzll(x);\n\
    \  }\n\n  template<class T>\n  constexpr KYOPRO_BASE_INT bit_len(T x) noexcept\
    \ {\n    constexpr auto digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;\n\
    \    static_assert(digits <= std::numeric_limits<unsigned long long>::digits,\
    \ \"Integer size is too large\");\n    if (x == 0) return 0;\n    if constexpr\
    \ (digits <= std::numeric_limits<unsigned int>::digits) return std::numeric_limits<unsigned\
    \ int>::digits - __builtin_clz(x);\n    else if constexpr (digits <= std::numeric_limits<unsigned\
    \ long>::digits) return std::numeric_limits<unsigned long>::digits - __builtin_clzl(x);\n\
    \    else return std::numeric_limits<unsigned long long>::digits - __builtin_clzll(x);\n\
    \  }\n\n  template<class T>\n  constexpr KYOPRO_BASE_INT floor_bit(T x) noexcept\
    \ {\n    return bit_len(x >> static_cast<T>(1));\n  }\n\n  template<class T>\n\
    \  constexpr KYOPRO_BASE_INT ceil_bit(T x) noexcept {\n    if (x == 0) return\
    \ 0;\n    return bit_len(x - static_cast<T>(1));\n  }\n}\n#line 4 \"algorithm/Hash.hpp\"\
    \n#include <functional>\n#include <tuple>\n#line 2 \"meta/trait.hpp\"\n#include\
    \ <iterator>\n#include <queue>\n#line 5 \"meta/trait.hpp\"\n#include <stack>\n\
    #line 9 \"meta/trait.hpp\"\n\ntemplate<>\nstruct std::is_integral<__int128_t>:\
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
    \ std::false_type {};\n  template<class T>\n  struct is_iterable<T, std::void_t<decltype(std::begin(std::declval<T>()))>>:\
    \ std::true_type {};\n\n  template<class T>\n  constexpr bool is_iterable_v =\
    \ is_iterable<T>::value;\n\n  template<class T>\n  struct iterable_value {\n \
    \   using type = std::decay_t<decltype(*std::begin(std::declval<T>()))>;\n  };\n\
    \n  template<class T>\n  using iterable_value_t = typename iterable_value<T>::type;\n\
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
    \n  private:\n    template<class T>\n    struct Type {\n      using type = T;\n\
    \    };\n\n    template<std::size_t idx, class T, std::enable_if_t<aggregate_size_v<std::decay_t<T>>\
    \ == 1>* = nullptr>\n    constexpr auto get_type(T aggregate, char) noexcept {\n\
    \      auto&& [a] = aggregate;\n      static_assert(idx < 1, \"Tuple index out\
    \ of range\");\n      return Type<decltype(a)>();\n    }\n    template<std::size_t\
    \ idx, class T, std::enable_if_t<aggregate_size_v<std::decay_t<T>> == 2>* = nullptr>\n\
    \    constexpr auto get_type(T aggregate, char) noexcept {\n      auto&& [a, b]\
    \ = aggregate;\n      static_assert(idx < 2, \"Tuple index out of range\");\n\
    \      if constexpr (idx == 0) return Type<decltype(a)>();\n      else return\
    \ Type<decltype(b)>();\n    }\n    template<std::size_t idx, class T, std::enable_if_t<aggregate_size_v<std::decay_t<T>>\
    \ == 3>* = nullptr>\n    constexpr auto get_type(T aggregate, char) noexcept {\n\
    \      auto&& [a, b, c] = aggregate;\n      static_assert(idx < 3, \"Tuple index\
    \ out of range\");\n      if constexpr (idx == 0) return Type<decltype(a)>();\n\
    \      else if constexpr (idx == 1) return Type<decltype(b)>();\n      else return\
    \ Type<decltype(c)>();\n    }\n    template<std::size_t idx, class T, std::enable_if_t<aggregate_size_v<std::decay_t<T>>\
    \ == 4>* = nullptr>\n    constexpr auto access_impl(T aggregate, char) noexcept\
    \ {\n      auto&& [a, b, c, d] = aggregate;\n      static_assert(idx < 4, \"Tuple\
    \ index out of range\");\n      if constexpr (idx == 0) return Type<decltype(a)>();\n\
    \      else if constexpr (idx == 1) return Type<decltype(b)>();\n      else if\
    \ constexpr (idx == 2) return Type<decltype(c)>();\n      else return Type<decltype(d)>();\n\
    \    }\n    template<std::size_t idx, class T, std::enable_if_t<aggregate_size_v<std::decay_t<T>>\
    \ == 5>* = nullptr>\n    constexpr auto get_type(T aggregate, char) noexcept {\n\
    \      auto&& [a, b, c, d, e] = aggregate;\n      static_assert(idx < 5, \"Tuple\
    \ index out of range\");\n      if constexpr (idx == 0) return Type<decltype(a)>();\n\
    \      else if constexpr (idx == 1) return Type<decltype(b)>();\n      else if\
    \ constexpr (idx == 2) return Type<decltype(c)>();\n      else if constexpr (idx\
    \ == 3) return Type<decltype(d)>();\n      else return Type<decltype(e)>();\n\
    \    }\n    template<std::size_t idx, class T, std::enable_if_t<aggregate_size_v<std::decay_t<T>>\
    \ == 6>* = nullptr>\n    constexpr auto get_type(T aggregate, char) noexcept {\n\
    \      auto&& [a, b, c, d, e, f] = aggregate;\n      static_assert(idx < 6, \"\
    Tuple index out of range\");\n      if constexpr (idx == 0) return Type<decltype(a)>();\n\
    \      else if constexpr (idx == 1) return Type<decltype(b)>();\n      else if\
    \ constexpr (idx == 2) return Type<decltype(c)>();\n      else if constexpr (idx\
    \ == 3) return Type<decltype(d)>();\n      else if constexpr (idx == 4) return\
    \ Type<decltype(e)>();\n      else return Type<decltype(f)>();\n    }\n    template<std::size_t\
    \ idx, class T, std::enable_if_t<aggregate_size_v<std::decay_t<T>> == 7>* = nullptr>\n\
    \    constexpr auto get_type(T aggregate, char) noexcept {\n      auto&& [a, b,\
    \ c, d, e, f, g] = aggregate;\n      static_assert(idx < 7, \"Tuple index out\
    \ of range\");\n      if constexpr (idx == 0) return Type<decltype(a)>();\n  \
    \    else if constexpr (idx == 1) return Type<decltype(b)>();\n      else if constexpr\
    \ (idx == 2) return Type<decltype(c)>();\n      else if constexpr (idx == 3) return\
    \ Type<decltype(d)>();\n      else if constexpr (idx == 4) return Type<decltype(e)>();\n\
    \      else if constexpr (idx == 5) return Type<decltype(f)>();\n      else return\
    \ Type<decltype(g)>();\n    }\n    template<std::size_t idx, class T, std::enable_if_t<aggregate_size_v<std::decay_t<T>>\
    \ == 8>* = nullptr>\n    constexpr auto get_type(T aggregate, char) noexcept {\n\
    \      auto&& [a, b, c, d, e, f, g, h] = aggregate;\n      static_assert(idx <\
    \ 8, \"Tuple index out of range\");\n      if constexpr (idx == 0) return Type<decltype(a)>();\n\
    \      else if constexpr (idx == 1) return Type<decltype(b)>();\n      else if\
    \ constexpr (idx == 2) return Type<decltype(c)>();\n      else if constexpr (idx\
    \ == 3) return Type<decltype(d)>();\n      else if constexpr (idx == 4) return\
    \ Type<decltype(e)>();\n      else if constexpr (idx == 5) return Type<decltype(f)>();\n\
    \      else if constexpr (idx == 6) return Type<decltype(g)>();\n      else return\
    \ Type<decltype(h)>();\n    }\n    template<std::size_t idx, class T, std::enable_if_t<aggregate_size_v<std::decay_t<T>>\
    \ == 8>* = nullptr>\n    constexpr auto get_type(T aggregate, char) noexcept {\n\
    \      auto&& [a, b, c, d, e, f, g, h] = aggregate;\n      static_assert(idx <\
    \ 8, \"Tuple index out of range\");\n      if constexpr (idx == 0) return Type<decltype(a)>();\n\
    \      else if constexpr (idx == 1) return Type<decltype(b)>();\n      else if\
    \ constexpr (idx == 2) return Type<decltype(c)>();\n      else if constexpr (idx\
    \ == 3) return Type<decltype(d)>();\n      else if constexpr (idx == 4) return\
    \ Type<decltype(e)>();\n      else if constexpr (idx == 5) return Type<decltype(f)>();\n\
    \      else if constexpr (idx == 6) return Type<decltype(g)>();\n      else return\
    \ Type<decltype(h)>();\n    }\n    template<std::size_t idx, class T, std::void_t<std::tuple_element_t<T>>*\
    \ = nullptr>\n    constexpr auto get_type(T, bool) noexcept {\n      return Type<std::tuple_element_t<T>>();\n\
    \    }\n\n  public:\n    using type = typename decltype(get_type(std::declval<T>(),\
    \ false))::type;\n  };\n\n  template<std::size_t idx, class T>\n  using aggregate_element_t\
    \ = typename aggregate_element<idx, T>::type;\n\n  template<class T>\n  struct\
    \ is_agg: std::conjunction<std::is_aggregate<T>, std::negation<is_iterable<T>>>\
    \ {};\n\n  template<class T>\n  inline constexpr bool is_agg_v = is_agg<T>::value;\n\
    }\n#line 7 \"meta/aggregate.hpp\"\n\nnamespace kyopro {\n  namespace helper {\n\
    \    #define DEFINE_ACCESS(n, ...) \\\n    template<std::size_t idx, class T,\
    \ std::enable_if_t<aggregate_size_v<std::decay_t<T>> == n>* = nullptr>\\\n   \
    \ constexpr decltype(auto) access_impl(T&& aggregate, char) noexcept {\\\n   \
    \   auto&& [__VA_ARGS__] = std::forward<T>(aggregate);\\\n      return std::get<idx>(std::forward_as_tuple(__VA_ARGS__));\\\
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
    \ seed = operator()<i + 1>(a);\n        return seed ^ (Hash<std::aggregate_element_t<i,\
    \ T>>()(access<i>(a)) + 0x9e3779b97f4a7c15LU + (seed << 12) + (seed >> 4));\n\
    \      }\n    }\n  };\n\n  template<class T>\n  struct Hash<T, std::enable_if_t<is_iterable_v<T>>>:\
    \ Hash<iterable_value_t<T>> {\n    using value_type = T;\n\n    constexpr std::size_t\
    \ operator ()(const T& a) const noexcept {\n      std::uint_fast64_t seed = a.size();\n\
    \      for (auto& i: a) seed ^= Hash<iterable_value_t<T>>(i) + 0x9e3779b97f4a7c15LU\
    \ + (seed << 12) + (seed >> 4);\n      return seed;\n    }\n  };\n}\n#line 2 \"\
    meta/constant.hpp\"\n#include <array>\n#line 3 \"math/power.hpp\"\n\nnamespace\
    \ kyopro {\n  template<class T>\n  constexpr T power(T a, KYOPRO_BASE_UINT n,\
    \ T init = 1) noexcept {\n    while (n > 0) {\n      if (n & 1) init *= a;\n \
    \     a *= a;\n      n >>= 1;\n    }\n    return init;\n  }\n}\n#line 7 \"meta/constant.hpp\"\
    \n\nnamespace kyopro {\n  template<class T>\n  inline constexpr T MOD = KYOPRO_DEFAULT_MOD;\n\
    \  inline constexpr KYOPRO_BASE_INT mod = MOD<KYOPRO_BASE_INT>;\n\n  template<class\
    \ T>\n  inline constexpr T INF = std::numeric_limits<T>::max() / KYOPRO_INF_DIV;\n\
    \  inline constexpr KYOPRO_BASE_INT inf = INF<KYOPRO_BASE_INT>;\n\n  template<class\
    \ T, KYOPRO_BASE_UINT decimal_precision = KYOPRO_DECIMAL_PRECISION>\n  inline\
    \ constexpr KYOPRO_BASE_FLOAT EPS = static_cast<T>(1) / power(10ULL, decimal_precision);\n\
    \  inline constexpr KYOPRO_BASE_FLOAT eps = EPS<KYOPRO_BASE_FLOAT>;\n\n  template<class\
    \ T>\n  inline constexpr T PI = 3.14159265358979323846;\n  inline constexpr KYOPRO_BASE_FLOAT\
    \ pi = PI<KYOPRO_BASE_FLOAT>;\n}\n#line 4 \"math/mod.hpp\"\n\nnamespace kyopro\
    \ {\n  template<class T, class U>\n  constexpr std::common_type_t<T, U> floor_mod(T\
    \ x, U m) noexcept {\n    static_assert(std::is_integral_v<T> && std::is_integral_v<U>,\
    \ \"Integer is required\");\n    if constexpr (std::is_unsigned_v<T> || std::is_unsigned_v<U>)\
    \ return x % m;\n    return (x %= m) < 0 ? x + m : x;\n  }\n\n  template<class\
    \ T, class U>\n  constexpr std::common_type_t<T, U> ceil_mod(T x, U m) noexcept\
    \ {\n    return m - floor_mod(x - 1, m) - static_cast<T>(1);\n  }\n}\n#line 14\
    \ \"math/ModInt.hpp\"\n\nnamespace kyopro {\n  template<KYOPRO_BASE_UINT m>\n\
    \  struct ModInt {\n    using value_type = uint_least_t<bit_len(m * 2 - 2)>;\n\
    \    static constexpr KYOPRO_BASE_INT mod = m;\n\n  private:\n    static constexpr\
    \ value_type _mod = m;\n\n  public:\n    value_type value;\n\n    static constexpr\
    \ KYOPRO_BASE_INT get_mod() noexcept {\n      return mod;\n    }\n\n    constexpr\
    \ ModInt() noexcept = default;\n    template<class T>\n    constexpr ModInt(T\
    \ value) noexcept: value(floor_mod(value, _mod)) {}\n\n    template<class T>\n\
    \    explicit constexpr operator T() const noexcept { return value; }\n\n    static\
    \ constexpr ModInt raw(value_type value) noexcept {\n      ModInt res;\n     \
    \ res.value = value;\n      return res;\n    }\n\n    constexpr ModInt power(KYOPRO_BASE_UINT\
    \ n) const noexcept {\n      std::uint_fast64_t res = 1, a = value;\n      while\
    \ (n > 0) {\n        if (n & 1) res = res * a % _mod;\n        a = a * a % _mod;\n\
    \        n >>= 1;\n      }\n      return res;\n    }\n\n    constexpr ModInt inverse()\
    \ const noexcept {\n      std::uint_fast64_t a = value, b = _mod;\n      std::int_fast64_t\
    \ u = 1, v = 0;\n      while (b > 0) {\n        std::uint_fast64_t t = a / b;\n\
    \        a -= t * b;\n        std::swap(a, b);\n        u -= t * v;\n        std::swap(u,\
    \ v);\n      }\n      return floor_mod(u, _mod);\n    }\n\n    constexpr ModInt\
    \ operator +() const noexcept { return *this; }\n\n    constexpr ModInt operator\
    \ -() const noexcept { return value == 0 ? 0 : _mod - value; }\n\n    constexpr\
    \ ModInt& operator ++() noexcept {\n      if (++value >= _mod) value -= _mod;\n\
    \      return *this;\n    }\n\n    constexpr ModInt operator ++(int) noexcept\
    \ {\n      ModInt before = *this;\n      operator ++();\n      return before;\n\
    \    }\n\n    constexpr ModInt& operator --() noexcept {\n      if (value == 0)\
    \ value = _mod;\n      --value;\n      return *this;\n    }\n\n    constexpr ModInt\
    \ operator --(int) noexcept {\n      ModInt before = *this;\n      operator --();\n\
    \      return before;\n    }\n\n    constexpr ModInt& operator +=(ModInt rhs)\
    \ noexcept {\n      if ((value += rhs.value) >= _mod) value -= _mod;\n      return\
    \ *this;\n    }\n\n    constexpr ModInt& operator -=(ModInt rhs) noexcept {\n\
    \      if (value < rhs.value) value += _mod;\n      value -= rhs.value;\n    \
    \  return *this;\n    }\n\n    constexpr ModInt& operator *=(ModInt rhs) noexcept\
    \ {\n      value = static_cast<uint_least_t<bit_len(_mod) * 2>>(value) * rhs.value\
    \ % _mod;\n      return *this;\n    }\n\n    constexpr ModInt& operator /=(ModInt\
    \ rhs) noexcept {\n      value = static_cast<uint_least_t<bit_len(_mod) * 2>>(value)\
    \ * rhs.inverse().value % _mod;\n      return *this;\n    }\n\n    friend constexpr\
    \ ModInt operator +(ModInt lhs, ModInt rhs) noexcept { return lhs += rhs; }\n\n\
    \    friend constexpr ModInt operator -(ModInt lhs, ModInt rhs) noexcept { return\
    \ lhs -= rhs; }\n\n    friend constexpr ModInt operator *(ModInt lhs, ModInt rhs)\
    \ noexcept { return lhs *= rhs; }\n\n    friend constexpr ModInt operator /(ModInt\
    \ lhs, ModInt rhs) noexcept { return lhs /= rhs; }\n\n    friend constexpr bool\
    \ operator ==(ModInt lhs, ModInt rhs) noexcept { return lhs.value == rhs.value;\
    \ }\n\n    friend constexpr bool operator !=(ModInt lhs, ModInt rhs) noexcept\
    \ { return lhs.value != rhs.value; }\n\n    template<class Scanner>\n    void\
    \ scan(Scanner& scanner) {\n      std::int_fast64_t value;\n      scanner.scan(value);\n\
    \      value = floor_mod(value, _mod);\n    }\n\n    template<class Printer>\n\
    \    void print(Printer& printer) const {\n      printer.print(value);\n    }\n\
    \  };\n\n  template<KYOPRO_BASE_UINT _mod>\n  struct Hash<ModInt<_mod>> {\n  \
    \  using value_type = ModInt<_mod>;\n    constexpr std::size_t operator ()(ModInt<_mod>\
    \ a) const noexcept { return static_cast<std::size_t>(a); }\n  };\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <cstddef>\n#include <cstdint>\n\
    #include <limits>\n#include <type_traits>\n#include <utility>\n#include \"../algorithm/bit.hpp\"\
    \n#include \"../algorithm/Hash.hpp\"\n#include \"../meta/constant.hpp\"\n#include\
    \ \"../meta/settings.hpp\"\n#include \"../meta/trait.hpp\"\n#include \"mod.hpp\"\
    \n\nnamespace kyopro {\n  template<KYOPRO_BASE_UINT m>\n  struct ModInt {\n  \
    \  using value_type = uint_least_t<bit_len(m * 2 - 2)>;\n    static constexpr\
    \ KYOPRO_BASE_INT mod = m;\n\n  private:\n    static constexpr value_type _mod\
    \ = m;\n\n  public:\n    value_type value;\n\n    static constexpr KYOPRO_BASE_INT\
    \ get_mod() noexcept {\n      return mod;\n    }\n\n    constexpr ModInt() noexcept\
    \ = default;\n    template<class T>\n    constexpr ModInt(T value) noexcept: value(floor_mod(value,\
    \ _mod)) {}\n\n    template<class T>\n    explicit constexpr operator T() const\
    \ noexcept { return value; }\n\n    static constexpr ModInt raw(value_type value)\
    \ noexcept {\n      ModInt res;\n      res.value = value;\n      return res;\n\
    \    }\n\n    constexpr ModInt power(KYOPRO_BASE_UINT n) const noexcept {\n  \
    \    std::uint_fast64_t res = 1, a = value;\n      while (n > 0) {\n        if\
    \ (n & 1) res = res * a % _mod;\n        a = a * a % _mod;\n        n >>= 1;\n\
    \      }\n      return res;\n    }\n\n    constexpr ModInt inverse() const noexcept\
    \ {\n      std::uint_fast64_t a = value, b = _mod;\n      std::int_fast64_t u\
    \ = 1, v = 0;\n      while (b > 0) {\n        std::uint_fast64_t t = a / b;\n\
    \        a -= t * b;\n        std::swap(a, b);\n        u -= t * v;\n        std::swap(u,\
    \ v);\n      }\n      return floor_mod(u, _mod);\n    }\n\n    constexpr ModInt\
    \ operator +() const noexcept { return *this; }\n\n    constexpr ModInt operator\
    \ -() const noexcept { return value == 0 ? 0 : _mod - value; }\n\n    constexpr\
    \ ModInt& operator ++() noexcept {\n      if (++value >= _mod) value -= _mod;\n\
    \      return *this;\n    }\n\n    constexpr ModInt operator ++(int) noexcept\
    \ {\n      ModInt before = *this;\n      operator ++();\n      return before;\n\
    \    }\n\n    constexpr ModInt& operator --() noexcept {\n      if (value == 0)\
    \ value = _mod;\n      --value;\n      return *this;\n    }\n\n    constexpr ModInt\
    \ operator --(int) noexcept {\n      ModInt before = *this;\n      operator --();\n\
    \      return before;\n    }\n\n    constexpr ModInt& operator +=(ModInt rhs)\
    \ noexcept {\n      if ((value += rhs.value) >= _mod) value -= _mod;\n      return\
    \ *this;\n    }\n\n    constexpr ModInt& operator -=(ModInt rhs) noexcept {\n\
    \      if (value < rhs.value) value += _mod;\n      value -= rhs.value;\n    \
    \  return *this;\n    }\n\n    constexpr ModInt& operator *=(ModInt rhs) noexcept\
    \ {\n      value = static_cast<uint_least_t<bit_len(_mod) * 2>>(value) * rhs.value\
    \ % _mod;\n      return *this;\n    }\n\n    constexpr ModInt& operator /=(ModInt\
    \ rhs) noexcept {\n      value = static_cast<uint_least_t<bit_len(_mod) * 2>>(value)\
    \ * rhs.inverse().value % _mod;\n      return *this;\n    }\n\n    friend constexpr\
    \ ModInt operator +(ModInt lhs, ModInt rhs) noexcept { return lhs += rhs; }\n\n\
    \    friend constexpr ModInt operator -(ModInt lhs, ModInt rhs) noexcept { return\
    \ lhs -= rhs; }\n\n    friend constexpr ModInt operator *(ModInt lhs, ModInt rhs)\
    \ noexcept { return lhs *= rhs; }\n\n    friend constexpr ModInt operator /(ModInt\
    \ lhs, ModInt rhs) noexcept { return lhs /= rhs; }\n\n    friend constexpr bool\
    \ operator ==(ModInt lhs, ModInt rhs) noexcept { return lhs.value == rhs.value;\
    \ }\n\n    friend constexpr bool operator !=(ModInt lhs, ModInt rhs) noexcept\
    \ { return lhs.value != rhs.value; }\n\n    template<class Scanner>\n    void\
    \ scan(Scanner& scanner) {\n      std::int_fast64_t value;\n      scanner.scan(value);\n\
    \      value = floor_mod(value, _mod);\n    }\n\n    template<class Printer>\n\
    \    void print(Printer& printer) const {\n      printer.print(value);\n    }\n\
    \  };\n\n  template<KYOPRO_BASE_UINT _mod>\n  struct Hash<ModInt<_mod>> {\n  \
    \  using value_type = ModInt<_mod>;\n    constexpr std::size_t operator ()(ModInt<_mod>\
    \ a) const noexcept { return static_cast<std::size_t>(a); }\n  };\n}\n"
  dependsOn:
  - algorithm/bit.hpp
  - meta/settings.hpp
  - algorithm/Hash.hpp
  - meta/aggregate.hpp
  - meta/trait.hpp
  - meta/constant.hpp
  - math/power.hpp
  - math/mod.hpp
  isVerificationFile: false
  path: math/ModInt.hpp
  requiredBy:
  - math/all.hpp
  - all.hpp
  - template/all.hpp
  - template/alias.hpp
  - all/all.hpp
  timestamp: '2022-06-05 22:20:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/ModInt.hpp
layout: document
redirect_from:
- /library/math/ModInt.hpp
- /library/math/ModInt.hpp.html
title: math/ModInt.hpp
---
