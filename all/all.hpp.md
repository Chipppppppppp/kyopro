---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: algorithm/Hash.hpp
    title: algorithm/Hash.hpp
  - icon: ':warning:'
    path: algorithm/all.hpp
    title: algorithm/all.hpp
  - icon: ':x:'
    path: algorithm/bit.hpp
    title: algorithm/bit.hpp
  - icon: ':warning:'
    path: algorithm/compress.hpp
    title: algorithm/compress.hpp
  - icon: ':warning:'
    path: function/RecursiveLambda.hpp
    title: function/RecursiveLambda.hpp
  - icon: ':warning:'
    path: function/all.hpp
    title: function/all.hpp
  - icon: ':x:'
    path: function/monoid.hpp
    title: function/monoid.hpp
  - icon: ':x:'
    path: math/DynamicModInt.hpp
    title: math/DynamicModInt.hpp
  - icon: ':warning:'
    path: math/ModInt.hpp
    title: math/ModInt.hpp
  - icon: ':x:'
    path: math/Montgomery.hpp
    title: math/Montgomery.hpp
  - icon: ':warning:'
    path: math/all.hpp
    title: math/all.hpp
  - icon: ':warning:'
    path: math/div.hpp
    title: math/div.hpp
  - icon: ':warning:'
    path: math/divisors.hpp
    title: math/divisors.hpp
  - icon: ':warning:'
    path: math/euler_phi.hpp
    title: math/euler_phi.hpp
  - icon: ':x:'
    path: math/factorize.hpp
    title: math/factorize.hpp
  - icon: ':x:'
    path: math/is_prime.hpp
    title: math/is_prime.hpp
  - icon: ':warning:'
    path: math/mod.hpp
    title: math/mod.hpp
  - icon: ':x:'
    path: math/power.hpp
    title: math/power.hpp
  - icon: ':warning:'
    path: meta/all.hpp
    title: meta/all.hpp
  - icon: ':x:'
    path: meta/constant.hpp
    title: meta/constant.hpp
  - icon: ':x:'
    path: meta/settings.hpp
    title: meta/settings.hpp
  - icon: ':x:'
    path: meta/trait.hpp
    title: meta/trait.hpp
  - icon: ':x:'
    path: structure/FenwickTree.hpp
    title: structure/FenwickTree.hpp
  - icon: ':x:'
    path: structure/UnionFind.hpp
    title: structure/UnionFind.hpp
  - icon: ':warning:'
    path: structure/all.hpp
    title: structure/all.hpp
  - icon: ':x:'
    path: system/all.hpp
    title: system/all.hpp
  - icon: ':x:'
    path: system/in.hpp
    title: system/in.hpp
  - icon: ':x:'
    path: system/out.hpp
    title: system/out.hpp
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
  bundledCode: "#line 2 \"algorithm/bit.hpp\"\n#include <limits>\n#include <type_traits>\n\
    #line 2 \"meta/settings.hpp\"\n#include <cstdint>\n\n#ifndef KYOPRO_BASE_INT\n\
    #define KYOPRO_BASE_INT std::int64_t\n#endif\n\n#ifndef KYOPRO_BASE_UINT\n#define\
    \ KYOPRO_BASE_UINT std::uint64_t\n#endif\n\n#ifndef KYOPRO_BASE_FLOAT\n#define\
    \ KYOPRO_BASE_FLOAT double\n#endif\n\n#ifndef KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD\
    \ static_cast<KYOPRO_BASE_UINT>(998244353)\n#endif\n\n#ifndef KYOPRO_DECIMAL_PRECISION\n\
    #define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n#endif\n\n\
    #ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 5 \"algorithm/bit.hpp\"\n\nnamespace kpr {\n  template<class T>\n\
    \  constexpr KYOPRO_BASE_INT pop_count(T x) noexcept {\n    constexpr auto digits\
    \ = std::numeric_limits<std::make_unsigned_t<T>>::digits;\n    static_assert(digits\
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
    \ 0;\n    return bit_len(x - static_cast<T>(1));\n  }\n}\n#line 2 \"algorithm/compress.hpp\"\
    \n#include <algorithm>\n#include <functional>\n#include <iterator>\n#include <unordered_map>\n\
    #include <vector>\n#line 8 \"algorithm/compress.hpp\"\n\nnamespace kpr {\n  template<class\
    \ T, class Container = std::unordered_map<typename std::iterator_traits<T>::value_type,\
    \ KYOPRO_BASE_INT>, class Compare>\n  auto compress(T first, T last, Compare comp\
    \ = std::less<typename std::iterator_traits<T>::value_type>()) {\n    std::vector<typename\
    \ std::iterator_traits<T>::value_type> vec(first, last);\n    std::sort(vec.begin(),\
    \ vec.end(), comp);\n    auto end = std::unique(vec.begin(), vec.end());\n   \
    \ Container mem;\n    int cnt = -1;\n    for (auto i = vec.begin(); i != end;\
    \ ++i) mem[*i] = ++cnt;\n    return mem;\n  }\n}\n#line 2 \"algorithm/Hash.hpp\"\
    \n#include <cstddef>\n#line 5 \"algorithm/Hash.hpp\"\n#include <tuple>\n#line\
    \ 7 \"algorithm/Hash.hpp\"\n#include <utility>\n#line 3 \"meta/trait.hpp\"\n#include\
    \ <queue>\n#line 5 \"meta/trait.hpp\"\n#include <stack>\n#line 9 \"meta/trait.hpp\"\
    \n\ntemplate<>\nstruct std::is_integral<__int128_t>: std::true_type {};\ntemplate<>\n\
    struct std::is_integral<__uint128_t>: std::true_type {};\ntemplate<>\nstruct std::is_floating_point<__float128>:\
    \ std::true_type {};\n\nnamespace kpr {\n  template<KYOPRO_BASE_UINT size>\n \
    \ struct int_least {\n  private:\n    static constexpr auto get_type() noexcept\
    \ {\n      static_assert(size <= 128, \"Integer size is too large\");\n      if\
    \ constexpr (size <= 8) return std::int_least8_t();\n      else if constexpr (size\
    \ <= 16) return std::int_least16_t();\n      else if constexpr (size <= 32) return\
    \ std::int_least32_t();\n      else if constexpr (size <= 64) return std::int_least64_t();\n\
    \      else return __int128_t();\n    }\n\n  public:\n    using type = decltype(get_type());\n\
    \  };\n\n  template<KYOPRO_BASE_UINT size>\n  using int_least_t = typename int_least<size>::type;\n\
    \n  template<KYOPRO_BASE_UINT size>\n  struct uint_least {\n  private:\n    static\
    \ constexpr auto get_type() noexcept {\n      static_assert(size <= 128, \"Integer\
    \ size is too large\");\n      if constexpr (size <= 8) return std::uint_least8_t();\n\
    \      else if constexpr (size <= 16) return std::uint_least16_t();\n      else\
    \ if constexpr (size <= 32) return std::uint_least32_t();\n      else if constexpr\
    \ (size <= 64) return std::uint_least64_t();\n      else return __uint128_t();\n\
    \    }\n\n  public:\n    using type = decltype(get_type());\n  };\n\n  template<KYOPRO_BASE_UINT\
    \ size>\n  using uint_least_t = typename uint_least<size>::type;\n\n  template<class,\
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
    }\n#line 10 \"algorithm/Hash.hpp\"\n\nnamespace kpr {\n  template<class, class\
    \ = void>\n  struct Hash;\n\n  template<class T>\n  struct Hash<T, std::enable_if_t<std::is_scalar_v<T>>>:\
    \ std::hash<T> {\n    using value_type = T;\n\n    constexpr std::size_t operator\
    \ ()(T a) const noexcept {\n      return std::hash<T>::operator ()(a);\n    }\n\
    \  };\n\n  template<class T>\n  struct Hash<T, std::enable_if_t<is_tuple_v<T>>>\
    \ {\n    using value_type = T;\n\n    template<KYOPRO_BASE_UINT i = 0>\n    constexpr\
    \ std::size_t operator ()(const T& a) const noexcept {\n      if constexpr (i\
    \ == std::tuple_size_v<T>) return std::tuple_size_v<T>;\n      else {\n      \
    \  std::uint_fast64_t seed = operator()<i + 1>(a);\n        return seed ^ (Hash<std::tuple_element_t<i,\
    \ T>>()(std::get<i>(a)) + 0x9e3779b97f4a7c15LU + (seed << 12) + (seed >> 4));\n\
    \      }\n    }\n  };\n\n  template<class T>\n  struct Hash<T, std::enable_if_t<is_iterable_v<T>>>:\
    \ Hash<iterable_value_t<T>> {\n    using value_type = T;\n\n    constexpr std::size_t\
    \ operator ()(const T& a) const noexcept {\n      std::uint_fast64_t seed = a.size();\n\
    \      for (auto& i: a) seed ^= Hash<iterable_value_t<T>>(i) + 0x9e3779b97f4a7c15LU\
    \ + (seed << 12) + (seed >> 4);\n      return seed;\n    }\n  };\n}\n#line 2 \"\
    meta/constant.hpp\"\n#include <array>\n#line 3 \"math/power.hpp\"\n\nnamespace\
    \ kpr {\n  template<class T>\n  constexpr T power(T a, KYOPRO_BASE_UINT n, T init\
    \ = 1) noexcept {\n    while (n > 0) {\n      if (n & 1) init *= a;\n      a *=\
    \ a;\n      n >>= 1;\n    }\n    return init;\n  }\n}\n#line 7 \"meta/constant.hpp\"\
    \n\nnamespace kpr {\n  template<class T>\n  inline constexpr T MOD = KYOPRO_DEFAULT_MOD;\n\
    \  inline constexpr KYOPRO_BASE_INT mod = MOD<KYOPRO_BASE_INT>;\n\n  template<class\
    \ T>\n  inline constexpr T INF = std::numeric_limits<T>::max() / KYOPRO_INF_DIV;\n\
    \  inline constexpr KYOPRO_BASE_INT inf = INF<KYOPRO_BASE_INT>;\n\n  template<class\
    \ T, KYOPRO_BASE_UINT decimal_precision = KYOPRO_DECIMAL_PRECISION>\n  inline\
    \ constexpr KYOPRO_BASE_FLOAT EPS = static_cast<T>(1) / power(10ULL, decimal_precision);\n\
    \  inline constexpr KYOPRO_BASE_FLOAT eps = EPS<KYOPRO_BASE_FLOAT>;\n\n  template<class\
    \ T>\n  inline constexpr T PI = 3.14159265358979323846;\n  inline constexpr KYOPRO_BASE_FLOAT\
    \ pi = PI<KYOPRO_BASE_FLOAT>;\n}\n#line 4 \"function/monoid.hpp\"\n\nnamespace\
    \ kpr {\n  template<class T, T _id = 0>\n  struct Plus {\n    static_assert(std::is_arithmetic_v<T>);\n\
    \    using value_type = T;\n    static constexpr T id = _id;\n\n    constexpr\
    \ T operator ()(T a, T b) const noexcept { return a + b; }\n    constexpr T inverse(T\
    \ a) const noexcept { return -a; }\n  };\n\n  template<class T, T _id = 1>\n \
    \ struct Mul {\n    static_assert(std::is_arithmetic_v<T>);\n    using value_type\
    \ = T;\n    static constexpr T id = _id;\n\n    constexpr T operator ()(T a, T\
    \ b) const noexcept { return a * b; }\n    constexpr T inverse(T a) const noexcept\
    \ {\n      static_assert(!std::is_integral_v<T>);\n      return 1 / a;\n    }\n\
    \  };\n\n  template<class T, T _id = std::is_integral_v<T> ? -INF<T> : -inf>\n\
    \  struct Max {\n    static_assert(std::is_arithmetic_v<T>);\n    using value_type\
    \ = T;\n    static constexpr T id = _id;\n\n    constexpr T operator ()(T a, T\
    \ b) const noexcept { return a > b ? a : b; }\n  };\n\n  template<class T, T _id\
    \ = std::is_integral_v<T> ? INF<T> : inf>\n  struct Min {\n    static_assert(std::is_arithmetic_v<T>);\n\
    \    using value_type = T;\n    static constexpr T id = _id;\n\n    constexpr\
    \ T operator ()(T a, T b) const noexcept { return a < b ? a : b; }\n  };\n}\n\
    #line 4 \"function/RecursiveLambda.hpp\"\n\nnamespace kpr {\n  template<class\
    \ F>\n  struct RecursiveLambda {\n    using value_type = F;\n\n  private:\n  \
    \  F func;\n\n  public:\n    template<class G>\n    constexpr RecursiveLambda(G&&\
    \ func) noexcept: func(std::forward<G>(func)) {}\n    template<class... Args>\n\
    \    constexpr decltype(auto) operator ()(Args&&... args) const noexcept { return\
    \ func(*this, std::forward<Args>(args)...); }\n  };\n\n  template<class F>\n \
    \ RecursiveLambda(F&&) -> RecursiveLambda<std::decay_t<F>>;\n}\n#line 3 \"math/div.hpp\"\
    \n\nnamespace kpr {\n  template<class T, class U>\n  constexpr std::common_type_t<T,\
    \ U> floor_div(T x, U m) noexcept {\n    static_assert(std::is_integral_v<T> &&\
    \ std::is_integral_v<U>, \"Integer is required\");\n    if constexpr (std::is_unsigned_v<T>\
    \ || std::is_unsigned_v<U>) return x / m;\n    auto d = x / m;\n    return d *\
    \ m == x ? d : d - ((x < 0) ^ (m < 0));\n  }\n\n  template<class T, class U>\n\
    \  constexpr std::common_type_t<T, U> ceil_div(T x, U m) noexcept { return floor_div(x\
    \ + m - static_cast<T>(1), m); }\n}\n#line 5 \"math/divisors.hpp\"\n\nnamespace\
    \ kpr {\n  template<class Container = std::vector<KYOPRO_BASE_INT>>\n  Container\
    \ divisors(KYOPRO_BASE_UINT n) {\n    Container lower, upper;\n    std::uint_fast64_t\
    \ i;\n    for (i = 1; i * i < n; ++i) if (n % i == 0) {\n      lower.emplace_back(i);\n\
    \      upper.emplace_back(n / i);\n    }\n    if (i * i == n) lower.emplace_back(i);\n\
    \    lower.insert(end(lower), rall(upper));\n    return lower;\n  }\n}\n#line\
    \ 2 \"math/DynamicModInt.hpp\"\n#include <cassert>\n#line 6 \"math/Montgomery.hpp\"\
    \n\nnamespace kpr {\n  template<class T>\n  struct Montgomery {\n    static_assert(std::is_unsigned_v<T>,\
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
    math/DynamicModInt.hpp\"\n\nnamespace kpr {\n  template<class T, KYOPRO_BASE_UINT\
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
    \ }\n  };\n}\n#line 4 \"math/euler_phi.hpp\"\n\nnamespace kpr {\n  constexpr KYOPRO_BASE_UINT\
    \ euler_phi(KYOPRO_BASE_UINT n) noexcept {\n    std::uint_fast64_t res = n;\n\
    \    if ((n & 1) == 0) {\n      res -= res >> 1;\n      n >>= 1;\n      while\
    \ ((n & 1) == 0) n >>= 1;\n    }\n    for (std::uint_fast64_t i = 3; i * i <=\
    \ n; i += 2) {\n      if (n % i == 0) {\n        res -= res / i;\n        n /=\
    \ i;\n        while (n % i == 0) n /= i;\n      }\n    }\n    if (n != 1) res\
    \ -= res / n;\n    return res;\n  }\n}\n#line 4 \"math/factorize.hpp\"\n#include\
    \ <numeric>\n#include <random>\n#line 7 \"math/is_prime.hpp\"\n\nnamespace kpr\
    \ {\n  template<class T>\n  constexpr bool is_prime(T x) {\n    using U = std::make_unsigned_t<T>;\n\
    \    using DynamicModInt = DynamicModInt<U, KYOPRO_BASE_UINT(-1)>;\n    U n =\
    \ x;\n    if (n <= 1) return false;\n    if (!(n & 1)) return n == 2;\n    DynamicModInt::set_mod(n);\n\
    \    std::uint_fast64_t d = (n - 1) >> trailing_zero(n - 1);\n    DynamicModInt\
    \ one = 1, minus_one = n - 1;\n    auto ng = [&](std::uint_fast64_t a) noexcept\
    \ {\n      auto y = DynamicModInt(a).power(d);\n      std::uint_fast64_t t = d;\n\
    \      while (y != one and y != minus_one and t != n - 1) y *= y, t <<= 1;\n \
    \     if (y != minus_one and !(t & 1)) return true;\n      return false;\n   \
    \ };\n    if (std::numeric_limits<U>::digits <= 32 || n < (static_cast<U>(1) <<\
    \ 32)) {\n      for (auto i: (std::uint_fast64_t[3]){2, 7, 61}) {\n        if\
    \ (n <= i) return true;\n        if (ng(i)) return false;\n      }\n    } else\
    \ {\n      for (auto i: (std::uint_fast64_t[7]){2, 325, 9375, 28178, 450775, 9780504,\
    \ 1795265022}) {\n        if (n <= i) return true;\n        if (ng(i)) return\
    \ false;\n      }\n    }\n    return true;\n  }\n}\n#line 11 \"math/factorize.hpp\"\
    \n\nnamespace kpr {\n  template<class T>\n  constexpr T pollard_rho(T p, KYOPRO_BASE_UINT\
    \ c) {\n    using U = std::make_unsigned_t<T>;\n    using DynamicModInt = DynamicModInt<U,\
    \ KYOPRO_BASE_UINT(-1)>;\n    U n = p;\n    DynamicModInt::set_mod(n);\n    DynamicModInt\
    \ cc = c;\n    auto f = [=](DynamicModInt x) noexcept { return x * x + cc; };\n\
    \    auto x = DynamicModInt::raw(1), y = DynamicModInt::raw(2), z = DynamicModInt::raw(1),\
    \ q = DynamicModInt::raw(1);\n    U g = 1;\n    const int m = 1 << (floor_bit(n)\
    \ / 5);\n    for (int r = 1; g == 1; r <<= 1) {\n      x = y;\n      for (int\
    \ i = 0; i < r; ++i) y = f(y);\n      for (int k = 0; k < r && g == 1; k += m)\
    \ {\n        z = y;\n        int min = std::min(m, r - k);\n        for (int i\
    \ = 0; i < min; ++i) {\n          y = f(y);\n          q *= x - y;\n        }\n\
    \        g = std::gcd(static_cast<U>(q), n);\n      }\n    }\n    if (g == n)\
    \ {\n      do {\n        z = f(z);\n        g = std::gcd(static_cast<U>(x - z),\
    \ n);\n      } while (g == 1);\n    }\n    return g;\n  }\n\n  KYOPRO_BASE_UINT\
    \ find_factor(KYOPRO_BASE_UINT n) noexcept {\n    static std::mt19937_64 mt(std::random_device{}());\n\
    \    std::uniform_int_distribution<std::uint_fast64_t> rnd(0, n - 1);\n    if\
    \ (is_prime(n)) return n;\n    for (int i = 0; i < 100; ++i) {\n      std::uint_fast64_t\
    \ m = pollard_rho(n, rnd(mt));\n      if (is_prime(m)) return m;\n      n = m;\n\
    \    }\n    return 1;\n  }\n\n  template<bool sorted = true, class Container =\
    \ std::vector<KYOPRO_BASE_INT>>\n  Container factorize(KYOPRO_BASE_UINT n) {\n\
    \    Container res;\n    for (int p = 2; p < 100 && p * p <= n; ++p) {\n     \
    \ while (n % p == 0) {\n        n /= p;\n        res.emplace_back(p);\n      }\n\
    \    }\n    while (n > 1) {\n      std::uint_fast64_t p = find_factor(n);\n  \
    \    do {\n        n /= p;\n        res.emplace_back(p);\n      } while (n % p\
    \ == 0);\n    }\n    if constexpr (sorted) std::sort(res.begin(), res.end());\n\
    \    return res;\n  }\n}\n#line 4 \"math/mod.hpp\"\n\nnamespace kpr {\n  template<class\
    \ T, class U>\n  constexpr std::common_type_t<T, U> floor_mod(T x, U m) noexcept\
    \ {\n    static_assert(std::is_integral_v<T> && std::is_integral_v<U>, \"Integer\
    \ is required\");\n    if constexpr (std::is_unsigned_v<T> || std::is_unsigned_v<U>)\
    \ return x % m;\n    return (x %= m) < 0 ? x + m : x;\n  }\n\n  template<class\
    \ T, class U>\n  constexpr std::common_type_t<T, U> ceil_mod(T x, U m) noexcept\
    \ {\n    return m - floor_mod(x - 1, m) - static_cast<T>(1);\n  }\n}\n#line 14\
    \ \"math/ModInt.hpp\"\n\nnamespace kpr {\n  template<KYOPRO_BASE_UINT m>\n  struct\
    \ ModInt {\n    using value_type = uint_least_t<bit_len(m * 2 - 2)>;\n    static\
    \ constexpr KYOPRO_BASE_INT mod = m;\n\n  private:\n    static constexpr value_type\
    \ _mod = m;\n\n  public:\n    value_type value;\n\n    static constexpr KYOPRO_BASE_INT\
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
    \ a) const noexcept { return static_cast<std::size_t>(a); }\n  };\n}\n#line 7\
    \ \"structure/FenwickTree.hpp\"\n\nnamespace kpr {\n  template<class T, class\
    \ Op = Plus<T>, class Container = std::vector<T>>\n  struct FenwickTree {\n  \
    \  using value_type = T;\n    using size_type = KYOPRO_BASE_UINT;\n    using reference\
    \ = T&;\n    using const_reference = const T&;\n    using operator_type = Op;\n\
    \    using container_type = Container;\n\n  private:\n    [[no_unique_address]]\
    \ Op op;\n    Container tree;\n\n  public:\n    FenwickTree() noexcept = default;\n\
    \    FenwickTree(KYOPRO_BASE_UINT n) noexcept: tree(n, op.id) {}\n    template<class\
    \ C, std::enable_if_t<std::is_same_v<Container, std::decay_t<C>>>>\n    FenwickTree(C&&\
    \ tree): tree(std::forward<C>(tree)) {}\n\n    KYOPRO_BASE_UINT size() noexcept\
    \ { return tree.size(); }\n\n    void apply(int p, const T& x) {\n      ++p;\n\
    \      while (p <= (int)size()) {\n        tree[p - 1] = op(tree[p - 1], x);\n\
    \        p += p & -p;\n      }\n    }\n\n    T prod(int r) const {\n      T s\
    \ = op.id;\n      while (r > 0) {\n        s = op(s, tree[r - 1]);\n        r\
    \ -= r & -r;\n      }\n      return s;\n    }\n    T prod(int l, int r) const\
    \ { return op(prod(r), op.inverse(prod(l))); }\n\n    T all_prod() { return prod(tree.size());\
    \ }\n\n    T get(int p) { return op(prod(p + 1), op.inverse(prod(p))); }\n\n \
    \   void set(int p, const T& x) { apply(p, op(x, op.inverse(get(p)))); }\n  };\n\
    }\n#line 9 \"structure/UnionFind.hpp\"\n\nnamespace kpr {\n  template<class Container\
    \ = std::vector<int>>\n  struct UnionFind {\n    using value_type = iterable_value_t<Container>;\n\
    \    using container_type = Container;\n\n  private:\n    Container par;\n\n \
    \ public:\n    UnionFind() noexcept = default;\n    UnionFind(KYOPRO_BASE_UINT\
    \ n) noexcept: par(n, -1) {}\n    template<class C, std::enable_if_t<std::is_same_v<Container,\
    \ std::decay_t<C>>>>\n    UnionFind(C&& par): par(std::forward<C>(par)) {}\n\n\
    \    void resize(KYOPRO_BASE_UINT x) { par.resize(x, -1); }\n    void assign(KYOPRO_BASE_UINT\
    \ x) { par.assign(x, -1); }\n    void reset() { std::fill(std::begin(par), std::end(par),\
    \ -1); }\n\n    KYOPRO_BASE_UINT size() const noexcept { return par.size(); }\n\
    \n    KYOPRO_BASE_INT find(int x) {\n      int p = x;\n      while (par[p] >=\
    \ 0) p = par[p];\n      while (x != p) {\n        int tmp = x;\n        x = par[x];\n\
    \        par[tmp] = p;\n      }\n      return p;\n    }\n\n    bool merge(int\
    \ x, int y) {\n      x = find(x), y = find(y);\n      if (x == y) return false;\n\
    \      if (par[x] > par[y]) {\n        int tmp = x;\n        x = y;\n        y\
    \ = tmp;\n      }\n      par[x] += par[y];\n      par[y] = x;\n      return true;\n\
    \    }\n\n    bool same(int x, int y) { return find(x) == find(y); }\n\n    KYOPRO_BASE_INT\
    \ group_size(int x) { return -par[find(x)]; }\n\n    std::vector<int> group_members(int\
    \ x) {\n      x = find(x);\n      std::vector<int> a;\n      for (int i = 0; i\
    \ < (int)(size()); ++i) if (find(i) == x) a.emplace_back(i);\n      return a;\n\
    \    }\n\n    template<class Vector = std::vector<KYOPRO_BASE_INT>>\n    Vector\
    \ roots() const {\n      Vector a;\n      for (int i = 0; i < (int)(size()); ++i)\
    \ if (par[i] < 0) a.emplace_back(i);\n      return a;\n    }\n\n    KYOPRO_BASE_INT\
    \ group_count() const {\n      KYOPRO_BASE_INT cnt = 0;\n      for (int i = 0;\
    \ i < (int)(size()); ++i) if (par[i] < 0) ++cnt;\n      return cnt;\n    }\n\n\
    \    template<class Map = std::unordered_map<KYOPRO_BASE_INT, std::vector<KYOPRO_BASE_INT>>>\n\
    \    Map all_group_members() {\n      Map group_members;\n      for (int member\
    \ = 0; member < (int)(size()); ++member) group_members[find(member)].emplace_back(member);\n\
    \      return group_members;\n    }\n  };\n}\n#line 2 \"system/in.hpp\"\n#include\
    \ <unistd.h>\n#line 6 \"system/in.hpp\"\n#include <cstdio>\n#include <string>\n\
    #line 14 \"system/in.hpp\"\n\nnamespace kpr {\n  template<KYOPRO_BASE_UINT _buf_size\
    \ = KYOPRO_BUFFER_SIZE>\n  struct Reader {\n    static constexpr KYOPRO_BASE_UINT\
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
    \    }\n    template<class T, class = std::enable_if_t<std::is_arithmetic_v<T>\
    \ && !has_scan<T>::value>>\n    void scan(T& a) {\n      discard_space();\n  \
    \    bool sgn = false;\n      if constexpr (!std::is_unsigned_v<T>) if (*itr ==\
    \ '-') {\n        sgn = true;\n        ++itr;\n      }\n      a = 0;\n      for\
    \ (; '0' <= *itr && *itr <= '9'; ++itr) a = a * 10 + *itr - '0';\n      if (*itr\
    \ == '.') {\n        ++itr;\n        if constexpr (std::is_floating_point_v<T>)\
    \ {\n          constexpr std::uint_fast64_t power_decimal_precision = power(10ULL,\
    \ decimal_precision);\n          T d = 0;\n          std::uint_fast64_t i = 1;\n\
    \          for (; '0' <= *itr && *itr <= '9' && i < power_decimal_precision; i\
    \ *= 10) {\n            d = d * 10 + *itr - '0';\n            ++itr;\n       \
    \   }\n          a += d / i;\n        }\n        while ('0' <= *itr && *itr <=\
    \ '9') ++itr;\n      }\n      if constexpr (!std::is_unsigned_v<T>) if (sgn) a\
    \ = -a;\n    }\n    template<KYOPRO_BASE_UINT i = 0, class T, class = std::enable_if_t<is_tuple_v<T>\
    \ && !has_scan<T>::value>>\n    void scan(T& a) {\n      if constexpr (i < std::tuple_size_v<T>)\
    \ {\n        scan(std::get<i>(a));\n        scan<i + 1>(a);\n      }\n    }\n\
    \    template<class T, class = std::enable_if_t<is_iterable_v<T> && !has_scan<T>::value>>\n\
    \    void scan(T& a) {\n      for (auto& i: a) scan(i);\n    }\n    template<class\
    \ T, class = std::enable_if_t<has_scan<T>::value>>\n    void scan(T& a) {\n  \
    \    a.scan(*this);\n    }\n\n    void operator ()() {}\n    template<class Head,\
    \ class... Args>\n    void operator ()(Head& head, Args&... args) {\n      scan(head);\n\
    \      operator ()(args...);\n    }\n  };\n\n  Scanner<Reader<>::iterator> scan(input.begin());\n\
    }\n#line 13 \"system/out.hpp\"\n\nnamespace kpr {\n  template<KYOPRO_BASE_UINT\
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
    \ std::true_type {};\n\n  public:\n\n    Iterator itr;\n\n    Printer() noexcept\
    \ = default;\n    Printer(Iterator itr) noexcept: itr(itr) {}\n\n    void print_char(char\
    \ c) {\n      *itr = c;\n      ++itr;\n    }\n\n    void print_sep() {\n     \
    \ if constexpr (debug) {\n        print_char(',');\n      }\n      print_char('\
    \ ');\n    }\n\n    void print(char a) {\n      if constexpr (debug) print_char('\\\
    '');\n      print_char(a);\n      if constexpr (debug) print_char('\\'');\n  \
    \  }\n    void print(const char* a) {\n      if constexpr (debug) print_char('\"\
    ');\n      for (; *a; ++a) print_char(*a);\n      if constexpr (debug) print_char('\"\
    ');\n    }\n    template<class CharT, class Traits>\n    void print(const std::basic_string<CharT,\
    \ Traits>& a) {\n      if constexpr (debug) print_char('\"');\n      for (auto\
    \ i: a) print_char(i);\n      if constexpr (debug) print_char('\"');\n    }\n\
    \    void print(bool a) {\n      print_char(static_cast<char>('0' + a));\n   \
    \ }\n    template<class T, class = std::enable_if_t<std::is_arithmetic_v<T> &&\
    \ !has_print<T>::value>>\n    void print(T a) {\n      if constexpr (std::is_signed_v<T>)\
    \ if (a < 0) {\n        print_char('-');\n        a = -a;\n      }\n      std::uint_fast64_t\
    \ p = a;\n      a -= p;\n      std::string s;\n      do {\n        s += '0' +\
    \ p % 10;\n        p /= 10;\n      } while (p > 0);\n      for (auto i = s.rbegin();\
    \ i != s.rend(); ++i) print_char(*i);\n      if constexpr (std::is_integral_v<T>)\
    \ return;\n      print_char('.');\n      for (int i = 0; i < static_cast<int>(decimal_precision);\
    \ ++i) {\n        a *= 10;\n        print_char('0' + static_cast<std::uint_fast64_t>(a)\
    \ % 10);\n      }\n    }\n    template<KYOPRO_BASE_UINT i = 0, class T, class\
    \ = std::enable_if_t<is_tuple_v<T> && !has_print<T>::value>>\n    void print(const\
    \ T& a) {\n      if constexpr (debug && i == 0) print_char('{');\n      if constexpr\
    \ (std::tuple_size_v<T> != 0) print(std::get<i>(a));\n      if constexpr (i +\
    \ 1 < std::tuple_size_v<T>) {\n        if constexpr (sep) print_sep();\n     \
    \   print<i + 1>(a);\n      } else if constexpr (debug) print_char('}');\n   \
    \ }\n    template<class T, class = std::enable_if_t<is_iterable_v<T> && !has_print<T>::value>>\n\
    \    void print(const T& a) {\n      if constexpr (debug) print_char('{');\n \
    \     if (std::empty(a)) return;\n      for (auto i = std::begin(a); ; ) {\n \
    \       print(*i);\n        if (++i != std::end(a)) {\n          if constexpr\
    \ (sep) {\n            if constexpr (debug) {\n              print_char(',');\n\
    \              print_char(' ');\n            } else if constexpr (std::is_arithmetic_v<std::decay_t<decltype(std::declval<T>()[0])>>)\
    \ print_char(' ');\n            else print_char('\\n');\n          }\n       \
    \ } else break;\n      }\n      if constexpr (debug) print_char('}');\n    }\n\
    \    template<class T, class = std::enable_if_t<has_print<T>::value>>\n    void\
    \ print(const T& a) {\n      a.print(*this);\n    }\n\n    template<bool first\
    \ = true>\n    void operator ()() {\n      if constexpr (comment && first) print_char('#');\n\
    \      if constexpr (end) print_char('\\n');\n      if constexpr (flush) itr.flush();\n\
    \    }\n    template<bool first = true, class Head, class... Args>\n    void operator\
    \ ()(Head&& head, Args&&... args) {\n      if constexpr (comment && first) {\n\
    \        print_char('#');\n        print_char(' ');\n      }\n      if constexpr\
    \ (sep && !first) print_sep();\n      print(head);\n      operator ()<false>(std::forward<Args>(args)...);\n\
    \    }\n  };\n\n  Printer<Writer<>::iterator, false, false> print(output.begin()),\
    \ eprint(error.begin());\n  Printer<Writer<>::iterator> println(output.begin()),\
    \ eprintln(error.begin());\n}\n#line 8 \"all/all.hpp\"\n"
  code: '#pragma once

    #include "../algorithm/all.hpp"

    #include "../function/all.hpp"

    #include "../math/all.hpp"

    #include "../meta/all.hpp"

    #include "../structure/all.hpp"

    #include "../system/all.hpp"'
  dependsOn:
  - algorithm/all.hpp
  - algorithm/bit.hpp
  - meta/settings.hpp
  - algorithm/compress.hpp
  - algorithm/Hash.hpp
  - meta/trait.hpp
  - function/all.hpp
  - function/monoid.hpp
  - meta/constant.hpp
  - math/power.hpp
  - function/RecursiveLambda.hpp
  - math/all.hpp
  - math/div.hpp
  - math/divisors.hpp
  - math/DynamicModInt.hpp
  - math/Montgomery.hpp
  - math/euler_phi.hpp
  - math/factorize.hpp
  - math/is_prime.hpp
  - math/mod.hpp
  - math/ModInt.hpp
  - meta/all.hpp
  - structure/all.hpp
  - structure/FenwickTree.hpp
  - structure/UnionFind.hpp
  - system/all.hpp
  - system/in.hpp
  - system/out.hpp
  isVerificationFile: false
  path: all/all.hpp
  requiredBy:
  - all.hpp
  timestamp: '2022-06-03 21:49:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: all/all.hpp
layout: document
redirect_from:
- /library/all/all.hpp
- /library/all/all.hpp.html
title: all/all.hpp
---
