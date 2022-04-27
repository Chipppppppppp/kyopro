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
    path: meta/constant.hpp
    title: meta/constant.hpp
  - icon: ':heavy_check_mark:'
    path: meta/settings.hpp
    title: meta/settings.hpp
  - icon: ':heavy_check_mark:'
    path: meta/trait.hpp
    title: meta/trait.hpp
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
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all/all.hpp
    title: all/all.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/alias.hpp\"\n#include <cstdint>\n#include <limits>\n\
    #include <functional>\n#include <tuple>\n#include <utility>\n#include <vector>\n\
    #include <string>\n#include <set>\n#include <map>\n#include <unordered_set>\n\
    #include <unordered_map>\n#include <queue>\n#include <stack>\n#line 2 \"algorithm/Hash.hpp\"\
    \n#include <cstddef>\n#line 6 \"algorithm/Hash.hpp\"\n#include <type_traits>\n\
    #line 3 \"meta/settings.hpp\"\n\n#ifndef KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT\
    \ std::int64_t\n#endif\n\n#ifndef KYOPRO_BASE_UINT\n#define KYOPRO_BASE_UINT std::uint64_t\n\
    #endif\n\n#ifndef KYOPRO_BASE_FLOAT\n#define KYOPRO_BASE_FLOAT double\n#endif\n\
    \n#ifndef KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD static_cast<KYOPRO_BASE_UINT>(998244353)\n\
    #endif\n\n#ifndef KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n\
    #endif\n\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 2 \"meta/trait.hpp\"\n#include <iterator>\n#line 9 \"meta/trait.hpp\"\
    \n\nnamespace kpr {\n  template<KYOPRO_BASE_UINT size>\n  struct int_least {\n\
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
    math/DynamicModInt.hpp\"\n#include <cassert>\n#line 2 \"meta/constant.hpp\"\n\
    #include <array>\n#line 3 \"math/power.hpp\"\n\nnamespace kpr {\n  template<class\
    \ T>\n  constexpr T power(T a, KYOPRO_BASE_UINT n, T init = 1) noexcept {\n  \
    \  while (n > 0) {\n      if (n & 1) init *= a;\n      a *= a;\n      n >>= 1;\n\
    \    }\n    return init;\n  }\n}\n#line 7 \"meta/constant.hpp\"\n\nnamespace kpr\
    \ {\n  template<class T>\n  inline constexpr T MOD = KYOPRO_DEFAULT_MOD;\n  inline\
    \ constexpr KYOPRO_BASE_INT mod = MOD<KYOPRO_BASE_INT>;\n\n  template<class T>\n\
    \  inline constexpr T INF = std::numeric_limits<T>::max() / KYOPRO_INF_DIV;\n\
    \  inline constexpr KYOPRO_BASE_INT inf = INF<KYOPRO_BASE_INT>;\n\n  template<class\
    \ T, KYOPRO_BASE_UINT decimal_precision = KYOPRO_DECIMAL_PRECISION>\n  inline\
    \ constexpr KYOPRO_BASE_FLOAT EPS = static_cast<T>(1) / power(10ULL, decimal_precision);\n\
    \  inline constexpr KYOPRO_BASE_FLOAT eps = EPS<KYOPRO_BASE_FLOAT>;\n\n  template<class\
    \ T>\n  inline constexpr T PI = 3.14159265358979323846;\n  inline constexpr KYOPRO_BASE_FLOAT\
    \ pi = PI<KYOPRO_BASE_FLOAT>;\n}\n#line 6 \"math/Montgomery.hpp\"\n\nnamespace\
    \ kpr {\n  template<class T>\n  struct Montgomery {\n    static_assert(std::is_unsigned_v<T>,\
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
    \ }\n  };\n}\n#line 5 \"algorithm/bit.hpp\"\n\nnamespace kpr {\n  template<class\
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
    \n\nnamespace kpr {\n  template<class T, class U>\n  constexpr std::common_type_t<T,\
    \ U> floor_mod(T x, U m) noexcept {\n    static_assert(std::is_integral_v<T> &&\
    \ std::is_integral_v<U>, \"Integer is required\");\n    if constexpr (std::is_unsigned_v<T>\
    \ || std::is_unsigned_v<U>) return x % m;\n    return (x %= m) < 0 ? x + m : x;\n\
    \  }\n\n  template<class T, class U>\n  constexpr std::common_type_t<T, U> ceil_mod(T\
    \ x, U m) noexcept {\n    return m - floor_mod(x - 1, m) - static_cast<T>(1);\n\
    \  }\n}\n#line 14 \"math/ModInt.hpp\"\n\nnamespace kpr {\n  template<KYOPRO_BASE_UINT\
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
    \ \"template/alias.hpp\"\n\nnamespace kpr {\n  using ll = long long;\n  using\
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
    \ idx>\n  using agg = typename agg_type<T, idx>::type;\n\n  template<class T>\n\
    \  using vec = std::vector<T>;\n  template<class T>\n  using vvec = std::vector<vec<T>>;\n\
    \  template<class T>\n  using vvvec = std::vector<vvec<T>>;\n  template<class\
    \ T>\n  using vvvvec = std::vector<vvvec<T>>;\n  template<class T>\n  using vvvvvec\
    \ = std::vector<vvvvec<T>>;\n\n  template<class Key, class Compare = std::less<Key>>\n\
    \  using mset = std::unordered_set<Key, Compare>;\n  template<class Key, class\
    \ T, class Compare = std::less<Key>>\n  using mmap = std::unordered_map<Key, T,\
    \ Compare>;\n  template<class Key>\n  using hset = std::unordered_set<Key, Hash<Key>>;\n\
    \  template<class Key, class T>\n  using hmap = std::unordered_map<Key, T, Hash<Key>>;\n\
    \  template<class Key>\n  using hmiset = std::unordered_multiset<Key, Hash<Key>>;\n\
    \  template<class Key, class T>\n  using hmmap = std::unordered_multimap<Key,\
    \ T, Hash<Key>>;\n  template<class T, class Compare = std::less<T>, class Container\
    \ = std::vector<T>>\n  using priq = std::priority_queue<T, Container, Compare>;\n\
    \  template<class T, class Compare = std::greater<T>, class Container = std::vector<T>>\n\
    \  using heapq = priq<T, Compare, Container>;\n}\n\nusing namespace std;\nusing\
    \ namespace kpr;\n#line 2 \"template/amin_amax.hpp\"\n\nnamespace kpr {\n  template<class\
    \ T, class U>\n  constexpr bool amin(T& a, U&& b) noexcept {\n    if (b < a) {\n\
    \      a = b;\n      return true;\n    }\n    return false;\n  }\n\n  template<class\
    \ T, class U>\n  constexpr bool amax(T& a, U&& b) noexcept {\n    if (a < b) {\n\
    \      a = b;\n      return true;\n    }\n    return false;\n  }\n}\n#line 4 \"\
    template/constant.hpp\"\n\nnamespace kpr {\n  inline constexpr std::array<std::pair<KYOPRO_BASE_INT,\
    \ KYOPRO_BASE_INT>, 4> beside{{{-1, 0}, {0, -1}, {1, 0}, {0, 1}}};\n  inline constexpr\
    \ std::array<std::pair<KYOPRO_BASE_INT, KYOPRO_BASE_INT>, 8> around{{{-1, 0},\
    \ {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}}};\n}\n#line 4 \"\
    template/len.hpp\"\n\nnamespace kpr {\n  template<class T>\n  constexpr KYOPRO_BASE_INT\
    \ len(T&& a) noexcept {\n    return std::size(a);\n  }\n}\n#line 5 \"template/macro.hpp\"\
    \n\n#define KYOPRO_OVERLOAD_MACRO(_1, _2, _3, _4, name, ...) name\n#define KYOPRO_REP0()\
    \ for (; ; )\n#define KYOPRO_REP1(i) for (KYOPRO_BASE_INT i = 0; ; ++(i))\n#define\
    \ KYOPRO_REP2(i, last) for (KYOPRO_BASE_INT i = 0, KYOPRO_LAST_ ## i = (last);\
    \ (i) < (KYOPRO_LAST_ ## i); ++(i))\n#define KYOPRO_REP3(i, first, last) for (KYOPRO_BASE_INT\
    \ i = (first), KYOPRO_LAST_ ## i = last; (i) < (KYOPRO_LAST_ ## i); ++(i))\n#define\
    \ KYOPRO_REP4(i, first, last, step) for (KYOPRO_BASE_INT i = (first), KYOPRO_LAST_\
    \ ## i = (last), KYOPRO_STEP_ ## i = (step); (KYOPRO_STEP_ ## i) > 0 ? (i) < (KYOPRO_LAST_\
    \ ## i) : (i) > (KYOPRO_LAST_ ## i); (i) += (KYOPRO_BASE_INT)(step))\n#define\
    \ rep(...) KYOPRO_OVERLOAD_MACRO(__VA_ARGS__ __VA_OPT__(,) KYOPRO_REP4, KYOPRO_REP3,\
    \ KYOPRO_REP2, KYOPRO_REP1, KYOPRO_REP0)(__VA_ARGS__)\n#define KYOPRO_ITER2(i,\
    \ last) for (auto i = std::decay_t<decltype(last)>(), KYOPRO_LAST_ ## i = (last);\
    \ (i) != (KYOPRO_LAST_ ## i); ++(i))\n#define KYOPRO_ITER3(i, first, last) for\
    \ (auto i = (first), KYOPRO_LAST_ ## i = (last); (i) != (KYOPRO_LAST_ ## i); ++(i))\n\
    #define KYOPRO_ITER4(i, first, last, step) for (auto i = (first), KYOPRO_LAST_\
    \ ## i = (last); (step) > 0 ? (i) < (KYOPRO_LAST_ ## i) : (i) > (KYOPRO_LAST_\
    \ ## i); (i) += (step))\n#define iter(...) KYOPRO_OVERLOAD_MACRO(__VA_ARGS__,\
    \ KYOPRO_ITER4, KYOPRO_ITER3, KYOPRO_ITER2)(__VA_ARGS__)\n#define KYOPRO_LAMBDA1(value)\
    \ ([&]() noexcept { return (value);})\n#define KYOPRO_LAMBDA2(_1, value) ([&](auto&&\
    \ _1) noexcept { return (value); })\n#define KYOPRO_LAMBDA3(_1, _2, value) ([&](auto&&\
    \ _1, auto&& _2) noexcept { return (value); })\n#define KYOPRO_LAMBDA4(_1, _2,\
    \ _3, value) ([&](auto&& _1, auto&& _2, auto&& _3) noexcept { return (value);\
    \ })\n#define lambda(...) KYOPRO_OVERLOAD_MACRO(__VA_ARGS__, KYOPRO_LAMBDA4, KYOPRO_LAMBDA3,\
    \ KYOPRO_LAMBDA2, KYOPRO_LAMBDA1)(__VA_ARGS__)\n#define all(...) std::begin(__VA_ARGS__),\
    \ std::end(__VA_ARGS__)\n#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)\n\
    #line 4 \"template/make_array.hpp\"\n\nnamespace kpr {\n  template<class T>\n\
    \  constexpr auto make_array(const T& init = T()) noexcept { return init; }\n\n\
    \  template<class T, KYOPRO_BASE_UINT length, KYOPRO_BASE_UINT... lengths>\n \
    \ constexpr auto make_array(const T& init = T()) noexcept {\n    auto elm = make_array<T,\
    \ lengths...>(init);\n    std::array<decltype(elm), length> res;\n    for (auto&\
    \ i: res) i = elm;\n    return res;\n  }\n}\n#line 6 \"template/make_vector.hpp\"\
    \n\nnamespace kpr {\n  template<KYOPRO_BASE_UINT idx = 0, KYOPRO_BASE_UINT n,\
    \ class T>\n  auto make_vector(const KYOPRO_BASE_UINT (&d)[n], T&& init) noexcept\
    \ {\n    if constexpr (idx < n) return std::vector(d[idx], make_vector<idx + 1>(d,\
    \ std::forward<T>(init)));\n    else return init;\n  }\n\n  template<class T,\
    \ KYOPRO_BASE_UINT idx = 0, KYOPRO_BASE_UINT n>\n  auto make_vector(const KYOPRO_BASE_UINT\
    \ (&d)[n], const T& init = T()) noexcept {\n    if constexpr (idx < n) return\
    \ std::vector(d[idx], make_vector<idx + 1>(d, init));\n    else return init;\n\
    \  }\n}\n#line 2 \"template/min_max_different_types.hpp\"\n#include <algorithm>\n\
    #line 4 \"template/min_max_different_types.hpp\"\n\nusing std::min, std::max;\n\
    \ntemplate<class T, class U, std::enable_if_t<!std::is_same_v<T, U>>* = nullptr>\n\
    constexpr std::common_type_t<T, U> min(const T& a, const U& b) noexcept {\n  return\
    \ a < b ? a : b;\n}\n\ntemplate<class T, class U, std::enable_if_t<!std::is_same_v<T,\
    \ U>>* = nullptr>\nconstexpr std::common_type_t<T, U> max(const T& a, const U&\
    \ b) noexcept {\n  return a > b ? a : b;\n}\n#line 10 \"template/all.hpp\"\n"
  code: '#pragma once

    #include "alias.hpp"

    #include "amin_amax.hpp"

    #include "constant.hpp"

    #include "len.hpp"

    #include "macro.hpp"

    #include "make_array.hpp"

    #include "make_vector.hpp"

    #include "min_max_different_types.hpp"'
  dependsOn:
  - template/alias.hpp
  - algorithm/Hash.hpp
  - meta/settings.hpp
  - meta/trait.hpp
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
  - template/make_array.hpp
  - template/make_vector.hpp
  - template/min_max_different_types.hpp
  isVerificationFile: false
  path: template/all.hpp
  requiredBy:
  - all/all.hpp
  timestamp: '2022-04-27 22:05:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/all.hpp
layout: document
redirect_from:
- /library/template/all.hpp
- /library/template/all.hpp.html
title: template/all.hpp
---
