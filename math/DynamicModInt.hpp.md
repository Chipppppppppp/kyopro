---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: algorithm/Hash.hpp
    title: algorithm/Hash.hpp
  - icon: ':x:'
    path: math/Montgomery.hpp
    title: math/Montgomery.hpp
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
  - icon: ':x:'
    path: math/factorize.hpp
    title: math/factorize.hpp
  - icon: ':x:'
    path: math/is_prime.hpp
    title: math/is_prime.hpp
  - icon: ':warning:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':warning:'
    path: template/all.hpp
    title: template/all.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/aoj/PrimeNumber.test.cpp
    title: verify/aoj/PrimeNumber.test.cpp
  - icon: ':x:'
    path: verify/yosupo/factorize.test.cpp
    title: verify/yosupo/factorize.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/DynamicModInt.hpp\"\n#include <cassert>\n#include <cstddef>\n\
    #include <limits>\n#include <type_traits>\n#line 3 \"algorithm/Hash.hpp\"\n#include\
    \ <cstdint>\n#include <functional>\n#include <tuple>\n#line 7 \"algorithm/Hash.hpp\"\
    \n#include <utility>\n#line 2 \"meta/trait.hpp\"\n#include <iterator>\n#include\
    \ <queue>\n#line 5 \"meta/trait.hpp\"\n#include <stack>\n#line 3 \"meta/settings.hpp\"\
    \n\n#ifndef KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT std::int64_t\n#endif\n\n\
    #ifndef KYOPRO_BASE_UINT\n#define KYOPRO_BASE_UINT std::uint64_t\n#endif\n\n#ifndef\
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
    \ aggregate_element<idx, T>::type;\n\n  template<class, class = void>\n  struct\
    \ is_small_aggregate: std::false_type {};\n  template<class T>\n  struct is_small_aggregate<T,\
    \ std::enable_if_t<aggregate_size_v<T> <= 8>>: std::true_type {};\n\n  template<class\
    \ T>\n  inline constexpr bool is_small_aggregate_v = is_small_aggregate<T>::value;\n\
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
    \  };\n\n  template<class T>\n  struct Hash<T, std::enable_if_t<is_small_aggregate_v<T>>>\
    \ {\n    using value_type = T;\n\n    template<KYOPRO_BASE_UINT i = 0>\n    constexpr\
    \ std::size_t operator ()(const T& a) const noexcept {\n      if constexpr (i\
    \ == aggregate_size_v<T>) return aggregate_size_v<T>;\n      else {\n        std::uint_fast64_t\
    \ seed = operator()<i + 1>(a);\n        return seed ^ (Hash<aggregate_element_t<i,\
    \ T>>()(access<i>(a)) + 0x9e3779b97f4a7c15LU + (seed << 12) + (seed >> 4));\n\
    \      }\n    }\n  };\n\n  template<class T>\n  struct Hash<T, std::enable_if_t<is_iterable_v<T>>>:\
    \ Hash<iterable_value_t<T>> {\n    using value_type = T;\n\n    constexpr std::size_t\
    \ operator ()(const T& a) const noexcept {\n      std::uint_fast64_t seed = a.size();\n\
    \      for (auto&& i: a) seed ^= Hash<iterable_value_t<T>>(i) + 0x9e3779b97f4a7c15LU\
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
    \ pi = PI<KYOPRO_BASE_FLOAT>;\n}\n#line 6 \"math/Montgomery.hpp\"\n\nnamespace\
    \ kyopro {\n  template<class T>\n  struct Montgomery {\n    static_assert(std::is_unsigned_v<T>,\
    \ \"Unsigned integer is required\");\n    using value_type = T;\n\n    T mod;\n\
    \n  private:\n    using larger_type = uint_least_t<std::numeric_limits<T>::digits\
    \ * 2>;\n\n    T r, n2;\n\n  public:\n    constexpr void set_mod(T _mod) noexcept\
    \ {\n      mod = _mod;\n      n2 = -static_cast<larger_type>(mod) % mod;\n   \
    \   T t = 0;\n      r = 0;\n      for (int i = 0; i < std::numeric_limits<T>::digits;\
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
    \ }\n  };\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <cstddef>\n#include <limits>\n\
    #include <type_traits>\n#include \"../algorithm/Hash.hpp\"\n#include \"../meta/constant.hpp\"\
    \n#include \"../meta/settings.hpp\"\n#include \"Montgomery.hpp\"\n\nnamespace\
    \ kyopro {\n  template<class T, KYOPRO_BASE_UINT _kind = 0>\n  struct DynamicModInt\
    \ {\n    static_assert(std::is_unsigned_v<T>, \"T must be unsigned integer\");\n\
    \    using value_type = T;\n    static constexpr KYOPRO_BASE_INT kind = _kind;\n\
    \n  private:\n    using larger_type = uint_least_t<std::numeric_limits<T>::digits\
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
    \ }\n  };\n}\n"
  dependsOn:
  - algorithm/Hash.hpp
  - meta/aggregate.hpp
  - meta/trait.hpp
  - meta/settings.hpp
  - meta/constant.hpp
  - math/power.hpp
  - math/Montgomery.hpp
  isVerificationFile: false
  path: math/DynamicModInt.hpp
  requiredBy:
  - math/all.hpp
  - math/is_prime.hpp
  - math/factorize.hpp
  - all.hpp
  - template/all.hpp
  - template/alias.hpp
  - all/all.hpp
  timestamp: '2022-06-06 23:09:46+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/aoj/PrimeNumber.test.cpp
  - verify/yosupo/factorize.test.cpp
documentation_of: math/DynamicModInt.hpp
layout: document
redirect_from:
- /library/math/DynamicModInt.hpp
- /library/math/DynamicModInt.hpp.html
title: math/DynamicModInt.hpp
---
