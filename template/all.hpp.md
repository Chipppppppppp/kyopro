---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/Hash.hpp
    title: algorithm/Hash.hpp
  - icon: ':heavy_check_mark:'
    path: algorithm/bit.hpp
    title: algorithm/bit.hpp
  - icon: ':heavy_check_mark:'
    path: math/DynamicModInt.hpp
    title: math/DynamicModInt.hpp
  - icon: ':warning:'
    path: math/ModInt.hpp
    title: math/ModInt.hpp
  - icon: ':heavy_check_mark:'
    path: math/Montgomery.hpp
    title: math/Montgomery.hpp
  - icon: ':warning:'
    path: math/mod.hpp
    title: math/mod.hpp
  - icon: ':heavy_check_mark:'
    path: math/power.hpp
    title: math/power.hpp
  - icon: ':heavy_check_mark:'
    path: meta/aggregate.hpp
    title: meta/aggregate.hpp
  - icon: ':heavy_check_mark:'
    path: meta/constant.hpp
    title: meta/constant.hpp
  - icon: ':heavy_check_mark:'
    path: meta/settings.hpp
    title: meta/settings.hpp
  - icon: ':heavy_check_mark:'
    path: meta/trait.hpp
    title: meta/trait.hpp
  - icon: ':heavy_check_mark:'
    path: system/all.hpp
    title: system/all.hpp
  - icon: ':heavy_check_mark:'
    path: system/in.hpp
    title: system/in.hpp
  - icon: ':heavy_check_mark:'
    path: system/out.hpp
    title: system/out.hpp
  - icon: ':warning:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':warning:'
    path: template/amin_amax.hpp
    title: template/amin_amax.hpp
  - icon: ':warning:'
    path: template/constant.hpp
    title: template/constant.hpp
  - icon: ':warning:'
    path: template/len.hpp
    title: template/len.hpp
  - icon: ':warning:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':warning:'
    path: template/make_array.hpp
    title: template/make_array.hpp
  - icon: ':warning:'
    path: template/make_vector.hpp
    title: template/make_vector.hpp
  - icon: ':warning:'
    path: template/min_max_different_types.hpp
    title: template/min_max_different_types.hpp
  - icon: ':warning:'
    path: template/stl.hpp
    title: template/stl.hpp
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
  bundledCode: "#line 2 \"template/stl.hpp\"\n#include <cassert>\n#include <cctype>\n\
    #include <cerrno>\n#include <cfloat>\n#include <ciso646>\n#include <climits>\n\
    #include <clocale>\n#include <cmath>\n#include <csetjmp>\n#include <csignal>\n\
    #include <cstdarg>\n#include <cstddef>\n#include <cstdio>\n#include <cstdlib>\n\
    #include <cstring>\n#include <ctime>\n\n#include <ccomplex>\n#include <cfenv>\n\
    #include <cinttypes>\n#include <cstdalign>\n#include <cstdbool>\n#include <cstdint>\n\
    #include <ctgmath>\n#include <cwchar>\n#include <cwctype>\n\n#include <algorithm>\n\
    #include <bitset>\n#include <complex>\n#include <deque>\n#include <exception>\n\
    #include <fstream>\n#include <functional>\n#include <iomanip>\n#include <ios>\n\
    #include <iosfwd>\n#include <iostream>\n#include <istream>\n#include <iterator>\n\
    #include <limits>\n#include <list>\n#include <locale>\n#include <map>\n#include\
    \ <memory>\n#include <new>\n#include <numeric>\n#include <ostream>\n#include <queue>\n\
    #include <set>\n#include <sstream>\n#include <stack>\n#include <stdexcept>\n#include\
    \ <streambuf>\n#include <string>\n#include <typeinfo>\n#include <utility>\n#include\
    \ <valarray>\n#include <vector>\n\n#include <array>\n#include <atomic>\n#include\
    \ <chrono>\n#include <condition_variable>\n#include <forward_list>\n#include <future>\n\
    #include <initializer_list>\n#include <mutex>\n#include <random>\n#include <ratio>\n\
    #include <regex>\n#include <scoped_allocator>\n#include <system_error>\n#include\
    \ <thread>\n#include <tuple>\n#include <typeindex>\n#include <type_traits>\n#include\
    \ <unordered_map>\n#include <unordered_set>\n#line 3 \"meta/settings.hpp\"\n\n\
    #ifndef KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT std::int64_t\n#endif\n\n#ifndef\
    \ KYOPRO_BASE_UINT\n#define KYOPRO_BASE_UINT std::uint64_t\n#endif\n\n#ifndef\
    \ KYOPRO_BASE_FLOAT\n#define KYOPRO_BASE_FLOAT double\n#endif\n\n#ifndef KYOPRO_DEFAULT_MOD\n\
    #define KYOPRO_DEFAULT_MOD static_cast<KYOPRO_BASE_UINT>(998244353)\n#endif\n\n\
    #ifndef KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n\
    #endif\n\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 9 \"meta/trait.hpp\"\n\ntemplate<>\nstruct std::is_integral<__int128_t>:\
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
    \ + (seed << 12) + (seed >> 4);\n      return seed;\n    }\n  };\n}\n#line 3 \"\
    math/power.hpp\"\n\nnamespace kyopro {\n  template<class T>\n  constexpr T power(T\
    \ a, KYOPRO_BASE_UINT n, T init = 1) noexcept {\n    while (n > 0) {\n      if\
    \ (n & 1) init *= a;\n      a *= a;\n      n >>= 1;\n    }\n    return init;\n\
    \  }\n}\n#line 7 \"meta/constant.hpp\"\n\nnamespace kyopro {\n  template<class\
    \ T>\n  inline constexpr T MOD = KYOPRO_DEFAULT_MOD;\n  inline constexpr KYOPRO_BASE_INT\
    \ mod = MOD<KYOPRO_BASE_INT>;\n\n  template<class T>\n  inline constexpr T INF\
    \ = std::numeric_limits<T>::max() / KYOPRO_INF_DIV;\n  inline constexpr KYOPRO_BASE_INT\
    \ inf = INF<KYOPRO_BASE_INT>;\n\n  template<class T, KYOPRO_BASE_UINT decimal_precision\
    \ = KYOPRO_DECIMAL_PRECISION>\n  inline constexpr KYOPRO_BASE_FLOAT EPS = static_cast<T>(1)\
    \ / power(10ULL, decimal_precision);\n  inline constexpr KYOPRO_BASE_FLOAT eps\
    \ = EPS<KYOPRO_BASE_FLOAT>;\n\n  template<class T>\n  inline constexpr T PI =\
    \ 3.14159265358979323846;\n  inline constexpr KYOPRO_BASE_FLOAT pi = PI<KYOPRO_BASE_FLOAT>;\n\
    }\n#line 6 \"math/Montgomery.hpp\"\n\nnamespace kyopro {\n  template<class T>\n\
    \  struct Montgomery {\n    static_assert(std::is_unsigned_v<T>, \"Unsigned integer\
    \ is required\");\n    using value_type = T;\n\n    T mod;\n\n  private:\n   \
    \ using larger_type = uint_least_t<std::numeric_limits<T>::digits * 2>;\n\n  \
    \  T r, n2;\n\n  public:\n    constexpr void set_mod(T _mod) noexcept {\n    \
    \  mod = _mod;\n      n2 = -static_cast<larger_type>(mod) % mod;\n      T t =\
    \ 0;\n      r = 0;\n      for (int i = 0; i < std::numeric_limits<T>::digits;\
    \ ++i) {\n        if (!(t & 1)) {\n          t += mod;\n          r += static_cast<T>(1)\
    \ << static_cast<T>(i);\n        }\n        t >>= 1;\n      }\n    }\n\n    constexpr\
    \ KYOPRO_BASE_INT get_mod() const noexcept {\n      return mod;\n    }\n\n   \
    \ Montgomery() noexcept = default;\n    Montgomery(T mod) noexcept {\n      set_mod(mod);\n\
    \    }\n\n    constexpr T transform(T x) const noexcept {\n      return reduce(static_cast<larger_type>(x)\
    \ * n2);\n    }\n\n    constexpr T inverse_transform(T x) const noexcept {\n \
    \     T y = reduce(x);\n      return y >= mod ? y - mod : y;\n    }\n\n    constexpr\
    \ T reduce(larger_type x) const noexcept {\n      return (x + static_cast<larger_type>(static_cast<T>(x)\
    \ * r) * mod) >> std::numeric_limits<T>::digits;\n    }\n  };\n}\n#line 10 \"\
    math/DynamicModInt.hpp\"\n\nnamespace kyopro {\n  template<class T, KYOPRO_BASE_UINT\
    \ _kind = 0>\n  struct DynamicModInt {\n    static_assert(std::is_unsigned_v<T>,\
    \ \"T must be unsigned integer\");\n    using value_type = T;\n    static constexpr\
    \ KYOPRO_BASE_INT kind = _kind;\n\n  private:\n    using larger_type = uint_least_t<std::numeric_limits<T>::digits\
    \ * 2>;\n\n    inline static Montgomery<T> montgomery;\n\n  public:\n    T value;\n\
    \n    static void set_mod(T mod) noexcept {\n      montgomery.set_mod(mod);\n\
    \    }\n\n    static KYOPRO_BASE_INT get_mod() noexcept {\n      return montgomery.mod;\n\
    \    }\n\n    KYOPRO_BASE_INT get_val() noexcept {\n      return montgomery.inverse_transform(value);\n\
    \    }\n\n    DynamicModInt() noexcept = default;\n    DynamicModInt(T value)\
    \ noexcept: value(montgomery.transform(value % montgomery.mod + montgomery.mod))\
    \ {}\n\n    template<class U>\n    explicit operator U() const noexcept { return\
    \ montgomery.inverse_transform(value); }\n\n    static DynamicModInt raw(T value)\
    \ noexcept {\n      DynamicModInt res;\n      res.value = montgomery.transform(value);\n\
    \      return res;\n    }\n\n    DynamicModInt power(KYOPRO_BASE_UINT n) const\
    \ noexcept {\n      DynamicModInt res = 1, a = *this;\n      while (n > 0) {\n\
    \        if (n & 1) res = res * a;\n        a = a * a;\n        n >>= 1;\n   \
    \   }\n      return res;\n    }\n\n    DynamicModInt inverse() const noexcept\
    \ {\n      return power(montgomery.mod - 2);\n    }\n\n    DynamicModInt operator\
    \ +() const noexcept { return *this; }\n\n    DynamicModInt operator -() const\
    \ noexcept { return value == 0 ? 0 : montgomery.mod - value; }\n\n    DynamicModInt&\
    \ operator ++() noexcept {\n      operator +=(DynamicModInt::raw(1));\n      return\
    \ *this;\n    }\n\n    DynamicModInt operator ++(int) noexcept {\n      DynamicModInt\
    \ before = *this;\n      operator ++();\n      return before;\n    }\n\n    DynamicModInt&\
    \ operator --() noexcept {\n      operator -=(DynamicModInt::raw(1));\n      return\
    \ *this;\n    }\n\n    DynamicModInt operator --(int) noexcept {\n      DynamicModInt\
    \ before = *this;\n      operator --();\n      return before;\n    }\n\n    DynamicModInt&\
    \ operator +=(DynamicModInt rhs) noexcept {\n      if ((value += rhs.value - (montgomery.mod\
    \ << 1)) > std::numeric_limits<std::make_signed_t<T>>::max()) value += montgomery.mod\
    \ << 1;\n      return *this;\n    }\n\n    DynamicModInt& operator -=(DynamicModInt\
    \ rhs) noexcept {\n      if ((value -= rhs.value) > std::numeric_limits<std::make_signed_t<T>>::max())\
    \ value += montgomery.mod << 1;\n      return *this;\n    }\n\n    DynamicModInt&\
    \ operator *=(DynamicModInt rhs) noexcept {\n      value = montgomery.reduce(static_cast<larger_type>(value)\
    \ * rhs.value);\n      return *this;\n    }\n\n    DynamicModInt& operator /=(DynamicModInt\
    \ rhs) noexcept {\n      value = montgomery.reduce(static_cast<larger_type>(value)\
    \ * rhs.inverse().value);\n      return *this;\n    }\n\n    friend DynamicModInt\
    \ operator +(DynamicModInt lhs, DynamicModInt rhs) noexcept { return lhs += rhs;\
    \ }\n\n    friend DynamicModInt operator -(DynamicModInt lhs, DynamicModInt rhs)\
    \ noexcept { return lhs -= rhs; }\n\n    friend DynamicModInt operator *(DynamicModInt\
    \ lhs, DynamicModInt rhs) noexcept { return lhs *= rhs; }\n\n    friend DynamicModInt\
    \ operator /(DynamicModInt lhs, DynamicModInt rhs) noexcept { return lhs /= rhs;\
    \ }\n\n    friend bool operator ==(DynamicModInt lhs, DynamicModInt rhs) noexcept\
    \ { return lhs.value == rhs.value; }\n\n    friend bool operator !=(DynamicModInt\
    \ lhs, DynamicModInt rhs) noexcept { return lhs.value != rhs.value; }\n\n    template<class\
    \ Scanner>\n    void scan(Scanner& scanner) {\n      std::int_fast64_t value;\n\
    \      scanner.scan(value);\n      value = montgomery.transform(value % montgomery.mod\
    \ + montgomery.mod);\n    }\n\n    template<class Printer>\n    void print(Printer&\
    \ printer) const {\n      printer.print(montgomery.inverse_transform(value));\n\
    \    }\n  };\n\n  template<class T, KYOPRO_BASE_UINT kind>\n  struct Hash<DynamicModInt<T,\
    \ kind>> {\n    using value_type = DynamicModInt<T, kind>;\n\n    std::size_t\
    \ operator ()(DynamicModInt<T, kind> a) const noexcept { return static_cast<std::size_t>(a);\
    \ }\n  };\n}\n#line 5 \"algorithm/bit.hpp\"\n\nnamespace kyopro {\n  template<class\
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
    \ 0;\n    return bit_len(x - static_cast<T>(1));\n  }\n}\n#line 4 \"math/mod.hpp\"\
    \n\nnamespace kyopro {\n  template<class T, class U>\n  constexpr std::common_type_t<T,\
    \ U> floor_mod(T x, U m) noexcept {\n    static_assert(std::is_integral_v<T> &&\
    \ std::is_integral_v<U>, \"Integer is required\");\n    if constexpr (std::is_unsigned_v<T>\
    \ || std::is_unsigned_v<U>) return x % m;\n    return (x %= m) < 0 ? x + m : x;\n\
    \  }\n\n  template<class T, class U>\n  constexpr std::common_type_t<T, U> ceil_mod(T\
    \ x, U m) noexcept {\n    return m - floor_mod(x - 1, m) - static_cast<T>(1);\n\
    \  }\n}\n#line 14 \"math/ModInt.hpp\"\n\nnamespace kyopro {\n  template<KYOPRO_BASE_UINT\
    \ m>\n  struct ModInt {\n    using value_type = uint_least_t<bit_len(m * 2 - 2)>;\n\
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
    \ a) const noexcept { return static_cast<std::size_t>(a); }\n  };\n}\n#line 19\
    \ \"template/alias.hpp\"\n\nnamespace kyopro {\n  using ll = long long;\n  using\
    \ ull = unsigned long long;\n  using lf = double;\n\n  using i8 = std::int8_t;\n\
    \  using u8 = std::uint8_t;\n  using i16 = std::int16_t;\n  using u16 = std::uint16_t;\n\
    \  using i32 = std::int32_t;\n  using u32 = std::uint32_t;\n  using i64 = std::int64_t;\n\
    \  using u64 = std::uint64_t;\n  using i128 = __int128_t;\n  using u128 = __uint128_t;\n\
    \  using f128 = __float128;\n\n  using mint = ModInt<mod>;\n  using dmint = DynamicModInt<KYOPRO_BASE_UINT>;\n\
    \n  template<class T, KYOPRO_BASE_UINT idx, class... Args>\n  struct agg_type\
    \ {\n    using type = typename agg_type<T, idx - 1, T, Args...>::type;\n  };\n\
    \  template<class T, class... Args>\n  struct agg_type<T, 0, Args...> {\n    using\
    \ type = std::tuple<Args...>;\n  };\n  template<class T>\n  struct agg_type<T,\
    \ 0, T, T> {\n    using type = std::pair<T, T>;\n  };\n\n  template<class T, KYOPRO_BASE_UINT\
    \ idx>\n  using agg = typename agg_type<T, idx>::type;\n  using ll1 = agg<ll,\
    \ 1>;\n  using ll2 = agg<ll, 2>;\n  using ll3 = agg<ll, 3>;\n  using ll4 = agg<ll,\
    \ 4>;\n  using ll5 = agg<ll, 5>;\n\n  template<class T>\n  using vec = std::vector<T>;\n\
    \  template<class T>\n  using vec1 = vec<T>;\n  template<class T>\n  using vec2\
    \ = std::vector<vec1<T>>;\n  template<class T>\n  using vec3 = std::vector<vec2<T>>;\n\
    \  template<class T>\n  using vec4 = std::vector<vec3<T>>;\n  template<class T>\n\
    \  using vec5 = std::vector<vec4<T>>;\n\n  template<class Key, class Compare =\
    \ std::less<Key>>\n  using mset = std::unordered_set<Key, Compare>;\n  template<class\
    \ Key, class T, class Compare = std::less<Key>>\n  using mmap = std::unordered_map<Key,\
    \ T, Compare>;\n  template<class Key>\n  using hset = std::unordered_set<Key,\
    \ Hash<Key>>;\n  template<class Key, class T>\n  using hmap = std::unordered_map<Key,\
    \ T, Hash<Key>>;\n  template<class Key>\n  using hmiset = std::unordered_multiset<Key,\
    \ Hash<Key>>;\n  template<class Key, class T>\n  using hmmap = std::unordered_multimap<Key,\
    \ T, Hash<Key>>;\n  template<class T, class Compare = std::less<T>, class Container\
    \ = std::vector<T>>\n  using priq = std::priority_queue<T, Container, Compare>;\n\
    \  template<class T, class Compare = std::greater<T>, class Container = std::vector<T>>\n\
    \  using heapq = priq<T, Compare, Container>;\n}\n\nusing namespace std;\nusing\
    \ namespace kyopro;\n#line 2 \"template/amin_amax.hpp\"\n\nnamespace kyopro {\n\
    \  template<class T, class U>\n  constexpr bool amin(T& a, U&& b) noexcept {\n\
    \    if (b < a) {\n      a = b;\n      return true;\n    }\n    return false;\n\
    \  }\n\n  template<class T, class U>\n  constexpr bool amax(T& a, U&& b) noexcept\
    \ {\n    if (a < b) {\n      a = b;\n      return true;\n    }\n    return false;\n\
    \  }\n}\n#line 4 \"template/constant.hpp\"\n\nnamespace kyopro {\n  inline constexpr\
    \ std::array<std::pair<KYOPRO_BASE_INT, KYOPRO_BASE_INT>, 4> beside{{{-1, 0},\
    \ {0, -1}, {1, 0}, {0, 1}}};\n  inline constexpr std::array<std::pair<KYOPRO_BASE_INT,\
    \ KYOPRO_BASE_INT>, 8> around{{{-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1,\
    \ 1}, {0, 1}, {-1, 1}}};\n}\n#line 4 \"template/len.hpp\"\n\nnamespace kyopro\
    \ {\n  template<class T>\n  constexpr KYOPRO_BASE_INT len(T&& a) noexcept {\n\
    \    return std::size(a);\n  }\n}\n#line 2 \"system/in.hpp\"\n#include <unistd.h>\n\
    #line 14 \"system/in.hpp\"\n\nnamespace kyopro {\n  template<KYOPRO_BASE_UINT\
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
    \    ++itr;\n    }\n    void scan(std::string& a) {\n      discard_space();\n\
    \      while ((*itr < '\\t' || '\\r' < *itr) && *itr != ' ') {\n        a += *itr;\n\
    \        ++itr;\n      }\n    }\n    void scan(bool& a) {\n      discard_space();\n\
    \      while ('0' <= *itr && *itr <= '9') {\n        if (*itr != '0') a = true;\n\
    \        ++itr;\n      }\n    }\n    template<class T, std::enable_if_t<std::is_arithmetic_v<T>\
    \ && !has_scan<T>::value>* = nullptr>\n    void scan(T& a) {\n      discard_space();\n\
    \      bool sgn = false;\n      if constexpr (!std::is_unsigned_v<T>) if (*itr\
    \ == '-') {\n        sgn = true;\n        ++itr;\n      }\n      a = 0;\n    \
    \  for (; '0' <= *itr && *itr <= '9'; ++itr) a = a * 10 + *itr - '0';\n      if\
    \ (*itr == '.') {\n        ++itr;\n        if constexpr (std::is_floating_point_v<T>)\
    \ {\n          constexpr std::uint_fast64_t power_decimal_precision = power(10ULL,\
    \ decimal_precision);\n          T d = 0;\n          std::uint_fast64_t i = 1;\n\
    \          for (; '0' <= *itr && *itr <= '9' && i < power_decimal_precision; i\
    \ *= 10) {\n            d = d * 10 + *itr - '0';\n            ++itr;\n       \
    \   }\n          a += d / i;\n        }\n        while ('0' <= *itr && *itr <=\
    \ '9') ++itr;\n      }\n      if constexpr (!std::is_unsigned_v<T>) if (sgn) a\
    \ = -a;\n    }\n    template<KYOPRO_BASE_UINT i = 0, class T, std::enable_if_t<is_agg_v<T>\
    \ && !has_scan<T>::value>* = nullptr>\n    void scan(T& a) {\n      if constexpr\
    \ (i < std::tuple_size_v<T>) {\n        scan(std::get<i>(a));\n        scan<i\
    \ + 1>(a);\n      }\n    }\n    template<class T, std::enable_if_t<is_iterable_v<T>\
    \ && !has_scan<T>::value>* = nullptr>\n    void scan(T& a) {\n      for (auto&&\
    \ i: a) scan(i);\n    }\n    template<class T, std::enable_if_t<has_scan<T>::value>*\
    \ = nullptr>\n    void scan(T& a) {\n      a.scan(*this);\n    }\n\n    void operator\
    \ ()() {}\n    template<class Head, class... Args>\n    void operator ()(Head&\
    \ head, Args&... args) {\n      scan(head);\n      operator ()(args...);\n   \
    \ }\n  };\n\n  Scanner<Reader<>::iterator> scan(input.begin());\n}\n#line 14 \"\
    system/out.hpp\"\n\nnamespace kyopro {\n  template<KYOPRO_BASE_UINT _buf_size\
    \ = KYOPRO_BUFFER_SIZE>\n  struct Writer {\n    static constexpr KYOPRO_BASE_UINT\
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
    \ std::true_type {};\n\n  public:\n\n    Iterator itr;\n\n    Printer() noexcept\
    \ = default;\n    Printer(Iterator itr) noexcept: itr(itr) {}\n\n    void print_char(char\
    \ c) {\n      *itr = c;\n      ++itr;\n    }\n\n    void print_sep() {\n     \
    \ if constexpr (debug) {\n        print_char(',');\n      }\n      print_char('\
    \ ');\n    }\n\n    void print(char a) {\n      if constexpr (debug) print_char('\\\
    '');\n      print_char(a);\n      if constexpr (debug) print_char('\\'');\n  \
    \  }\n    void print(const char* a) {\n      if constexpr (debug) print_char('\"\
    ');\n      for (; *a != '\\0'; ++a) print_char(*a);\n      if constexpr (debug)\
    \ print_char('\"');\n    }\n    template<std::size_t len>\n    void print(const\
    \ char (&a)[len]) {\n      if constexpr (debug) print_char('\"');\n      for (auto\
    \ i: a) print_char(i);\n      if constexpr (debug) print_char('\"');\n    }\n\
    \    void print(const std::string& a) {\n      if constexpr (debug) print_char('\"\
    ');\n      for (auto i: a) print_char(i);\n      if constexpr (debug) print_char('\"\
    ');\n    }\n    void print(bool a) {\n      print_char(static_cast<char>('0' +\
    \ a));\n    }\n    template<class T, std::enable_if_t<std::is_arithmetic_v<T>\
    \ && !has_print<T>::value>* = nullptr>\n    void print(T a) {\n      if constexpr\
    \ (std::is_signed_v<T>) if (a < 0) {\n        print_char('-');\n        a = -a;\n\
    \      }\n      std::uint_fast64_t p = a;\n      a -= p;\n      std::string s;\n\
    \      do {\n        s += '0' + p % 10;\n        p /= 10;\n      } while (p >\
    \ 0);\n      for (auto i = s.rbegin(); i != s.rend(); ++i) print_char(*i);\n \
    \     if constexpr (std::is_integral_v<T>) return;\n      print_char('.');\n \
    \     for (int i = 0; i < static_cast<int>(decimal_precision); ++i) {\n      \
    \  a *= 10;\n        print_char('0' + static_cast<std::uint_fast64_t>(a) % 10);\n\
    \      }\n    }\n    template<KYOPRO_BASE_UINT i = 0, class T, std::enable_if_t<is_agg_v<T>\
    \ && !has_print<T>::value>* = nullptr>\n    void print(const T& a) {\n      if\
    \ constexpr (debug && i == 0) print_char('{');\n      if constexpr (aggregate_size_v<T>\
    \ != 0) print(access<i>(a));\n      if constexpr (i + 1 < aggregate_size_v<T>)\
    \ {\n        if constexpr (sep) print_sep();\n        print<i + 1>(a);\n     \
    \ } else if constexpr (debug) print_char('}');\n    }\n    template<class T, std::enable_if_t<is_iterable_v<T>\
    \ && !has_print<T>::value>* = nullptr>\n    void print(const T& a) {\n      if\
    \ constexpr (debug) print_char('{');\n      if (std::empty(a)) return;\n     \
    \ for (auto i = std::begin(a); ; ) {\n        print(*i);\n        if (++i != std::end(a))\
    \ {\n          if constexpr (sep) {\n            if constexpr (debug) {\n    \
    \          print_char(',');\n              print_char(' ');\n            } else\
    \ if constexpr (std::is_arithmetic_v<std::decay_t<decltype(std::declval<T>()[0])>>)\
    \ print_char(' ');\n            else print_char('\\n');\n          }\n       \
    \ } else break;\n      }\n      if constexpr (debug) print_char('}');\n    }\n\
    \    template<class T, std::enable_if_t<has_print<T>::value>* = nullptr>\n   \
    \ void print(const T& a) {\n      a.print(*this);\n    }\n\n    template<bool\
    \ first = true>\n    void operator ()() {\n      if constexpr (comment && first)\
    \ print_char('#');\n      if constexpr (end) print_char('\\n');\n      if constexpr\
    \ (flush) itr.flush();\n    }\n    template<bool first = true, class Head, class...\
    \ Args>\n    void operator ()(Head&& head, Args&&... args) {\n      if constexpr\
    \ (comment && first) {\n        print_char('#');\n        print_char(' ');\n \
    \     }\n      if constexpr (sep && !first) print_sep();\n      print(head);\n\
    \      operator ()<false>(std::forward<Args>(args)...);\n    }\n  };\n\n  Printer<Writer<>::iterator,\
    \ false, false> print(output.begin()), eprint(error.begin());\n  Printer<Writer<>::iterator>\
    \ println(output.begin()), eprintln(error.begin());\n}\n#line 8 \"template/macro.hpp\"\
    \n\nnamespace kyopro::helper {\n  template<KYOPRO_BASE_UINT len>\n  constexpr\
    \ KYOPRO_BASE_UINT va_args_size(const char (&s)[len]) noexcept {\n    if constexpr\
    \ (len == 1) return 0;\n    KYOPRO_BASE_UINT cnt = 1;\n    for (auto i: s) if\
    \ (i == ',') ++cnt;\n    return cnt;\n  }\n\n  template<class F, KYOPRO_BASE_UINT...\
    \ idx>\n  auto read_impl(F&& f, std::integer_sequence<KYOPRO_BASE_UINT, idx...>)\
    \ {\n    auto res = std::tuple{(static_cast<void>(idx), f())...};\n    scan(res);\n\
    \    return res;\n  }\n\n  Printer<Writer<>::iterator, true, true, true> debug_impl(output.begin());\n\
    \n  template<bool>\n  void print_if(const char* s) {\n    print(' ', s, ' ', '=',\
    \ ' ');\n  }\n  template<>\n  void print_if<false>(const char*) {}\n}\n\n#define\
    \ read(init, ...) auto [__VA_ARGS__] = kyopro::helper::read_impl([&] { return\
    \ init; }, std::make_integer_sequence<KYOPRO_BASE_UINT, kyopro::helper::va_args_size(#__VA_ARGS__)>())\n\
    #define debug(...) (kyopro::print('#', 'l', 'i', 'n', 'e', ' ', __LINE__, ':'),\
    \ kyopro::helper::print_if<kyopro::helper::va_args_size(#__VA_ARGS__) != 0>(#__VA_ARGS__),\
    \ kyopro::helper::debug_impl(__VA_ARGS__))\n\n#define KYOPRO_OVERLOAD_MACRO(_1,\
    \ _2, _3, _4, name, ...) name\n\n#define KYOPRO_REP0() for (; ; )\n#define KYOPRO_REP1(last)\
    \ KYOPRO_REP2(KYOPRO_COUNTER, last)\n#define KYOPRO_REP2(i, last) for (auto i\
    \ = std::decay_t<decltype(last)>(), KYOPRO_LAST = (last); (i) < (KYOPRO_LAST);\
    \ ++(i))\n#define KYOPRO_REP3(i, first, last) for (auto i = (first), KYOPRO_LAST\
    \ = last; (i) < (KYOPRO_LAST); ++(i))\n#define rep(...) KYOPRO_OVERLOAD_MACRO(__VA_ARGS__\
    \ __VA_OPT__(,) KYOPRO_REP4, KYOPRO_REP3, KYOPRO_REP2, KYOPRO_REP1, KYOPRO_REP0)(__VA_ARGS__)\n\
    \n#define KYOPRO_MATCH1(_1) break; case _1:\n#define KYOPRO_MATCH2(_1, _2) break;\
    \ case _1: case _2:\n#define KYOPRO_MATCH3(_1, _2, _3) break; case _1: case _2:\
    \ case _3:\n#define KYOPRO_MATCH4(_1, _2, _3, _4) break; case _1: case _2: case\
    \ _3: case _4:\n#define match(...) KYOPRO_OVERLOAD_MACRO(__VA_ARGS__, KYOPRO_MATCH4,\
    \ KYOPRO_MATCH3, KYOPRO_MATCH2, KYOPRO_MATCH1)(__VA_ARGS__)\n#define otherwise\
    \ break; default:\n\n#define KYOPRO_LAMBDA1(value) ([&]() noexcept { return (value);})\n\
    #define KYOPRO_LAMBDA2(_1, value) ([&](auto&& _1) noexcept { return (value); })\n\
    #define KYOPRO_LAMBDA3(_1, _2, value) ([&](auto&& _1, auto&& _2) noexcept { return\
    \ (value); })\n#define KYOPRO_LAMBDA4(_1, _2, _3, value) ([&](auto&& _1, auto&&\
    \ _2, auto&& _3) noexcept { return (value); })\n#define lambda(...) KYOPRO_OVERLOAD_MACRO(__VA_ARGS__,\
    \ KYOPRO_LAMBDA4, KYOPRO_LAMBDA3, KYOPRO_LAMBDA2, KYOPRO_LAMBDA1)(__VA_ARGS__)\n\
    \n#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)\n#define rall(...)\
    \ std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)\n#line 4 \"template/make_array.hpp\"\
    \n\nnamespace kyopro {\n  template<class T>\n  constexpr auto make_array(const\
    \ T& init = T()) noexcept { return init; }\n\n  template<class T, KYOPRO_BASE_UINT\
    \ length, KYOPRO_BASE_UINT... lengths>\n  constexpr auto make_array(const T& init\
    \ = T()) noexcept {\n    auto elm = make_array<T, lengths...>(init);\n    std::array<decltype(elm),\
    \ length> res;\n    for (auto& i: res) i = elm;\n    return res;\n  }\n}\n#line\
    \ 6 \"template/make_vector.hpp\"\n\nnamespace kyopro {\n  template<KYOPRO_BASE_UINT\
    \ idx = 0, KYOPRO_BASE_UINT n, class T>\n  auto make_vector(const KYOPRO_BASE_UINT\
    \ (&d)[n], T&& init) noexcept {\n    if constexpr (idx < n) return std::vector(d[idx],\
    \ make_vector<idx + 1>(d, std::forward<T>(init)));\n    else return init;\n  }\n\
    \n  template<class T, KYOPRO_BASE_UINT idx = 0, KYOPRO_BASE_UINT n>\n  auto make_vector(const\
    \ KYOPRO_BASE_UINT (&d)[n], const T& init = T()) noexcept {\n    if constexpr\
    \ (idx < n) return std::vector(d[idx], make_vector<idx + 1>(d, init));\n    else\
    \ return init;\n  }\n}\n#line 4 \"template/min_max_different_types.hpp\"\n\nusing\
    \ std::min, std::max;\n\ntemplate<class T, class U, std::enable_if_t<!std::is_same_v<T,\
    \ U>>* = nullptr>\nconstexpr std::common_type_t<T, U> min(const T& a, const U&\
    \ b) noexcept {\n  return a < b ? a : b;\n}\n\ntemplate<class T, class U, std::enable_if_t<!std::is_same_v<T,\
    \ U>>* = nullptr>\nconstexpr std::common_type_t<T, U> max(const T& a, const U&\
    \ b) noexcept {\n  return a > b ? a : b;\n}\n#line 11 \"template/all.hpp\"\n"
  code: '#pragma once

    #include "stl.hpp"

    #include "alias.hpp"

    #include "amin_amax.hpp"

    #include "constant.hpp"

    #include "len.hpp"

    #include "macro.hpp"

    #include "make_array.hpp"

    #include "make_vector.hpp"

    #include "min_max_different_types.hpp"'
  dependsOn:
  - template/stl.hpp
  - template/alias.hpp
  - algorithm/Hash.hpp
  - meta/aggregate.hpp
  - meta/trait.hpp
  - meta/settings.hpp
  - math/DynamicModInt.hpp
  - meta/constant.hpp
  - math/power.hpp
  - math/Montgomery.hpp
  - math/ModInt.hpp
  - algorithm/bit.hpp
  - math/mod.hpp
  - template/amin_amax.hpp
  - template/constant.hpp
  - template/len.hpp
  - template/macro.hpp
  - system/all.hpp
  - system/in.hpp
  - system/out.hpp
  - template/make_array.hpp
  - template/make_vector.hpp
  - template/min_max_different_types.hpp
  isVerificationFile: false
  path: template/all.hpp
  requiredBy:
  - all.hpp
  timestamp: '2022-06-05 23:53:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/all.hpp
layout: document
redirect_from:
- /library/template/all.hpp
- /library/template/all.hpp.html
title: template/all.hpp
---
