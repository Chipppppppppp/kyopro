---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: base/Hash.hpp
    title: base/Hash.hpp
  - icon: ':heavy_check_mark:'
    path: base/constant.hpp
    title: base/constant.hpp
  - icon: ':heavy_check_mark:'
    path: base/settings.hpp
    title: base/settings.hpp
  - icon: ':heavy_check_mark:'
    path: base/trait.hpp
    title: base/trait.hpp
  - icon: ':warning:'
    path: math/DynamicModInt.hpp
    title: math/DynamicModInt.hpp
  - icon: ':warning:'
    path: math/ModInt.hpp
    title: math/ModInt.hpp
  - icon: ':warning:'
    path: math/div.hpp
    title: math/div.hpp
  - icon: ':warning:'
    path: math/divisors.hpp
    title: math/divisors.hpp
  - icon: ':warning:'
    path: math/euler_phi.hpp
    title: math/euler_phi.hpp
  - icon: ':warning:'
    path: math/factorize.hpp
    title: math/factorize.hpp
  - icon: ':warning:'
    path: math/is_prime.hpp
    title: math/is_prime.hpp
  - icon: ':warning:'
    path: math/mod.hpp
    title: math/mod.hpp
  - icon: ':warning:'
    path: math/modpow.hpp
    title: math/modpow.hpp
  - icon: ':heavy_check_mark:'
    path: math/monoid.hpp
    title: math/monoid.hpp
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
  bundledCode: "#line 2 \"math/div.hpp\"\n#include <type_traits>\n\nnamespace kyopro\
    \ {\n  template<class _typeT, class _typeU>\n  constexpr std::common_type_t<_typeT,\
    \ _typeU> floor_div(_typeT _x, _typeU _m) noexcept {\n    static_assert(std::is_integral_v<_typeT>\
    \ && std::is_integral_v<_typeU>);\n    if constexpr (std::is_unsigned_v<_typeT>\
    \ || std::is_unsigned_v<_typeU>) return _x / _m;\n    auto _d = _x / _m;\n   \
    \ return _d * _m == _x ? _d : _d - ((_x < 0) ^ (_m < 0));\n  }\n\n  template<class\
    \ _typeT, class _typeU>\n  constexpr std::common_type_t<_typeT, _typeU> ceil_div(_typeT\
    \ _x, _typeU _m) noexcept { return floor_div(_x + _m - static_cast<_typeT>(1),\
    \ _m); }\n}\n#line 2 \"math/divisors.hpp\"\n#include <cstdint>\n#include <vector>\n\
    #line 3 \"base/settings.hpp\"\n\n#ifndef KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT\
    \ std::int64_t\n#endif\n\n#ifndef KYOPRO_BASE_UINT\n#define KYOPRO_BASE_UINT std::uint64_t\n\
    #endif\n\n#ifndef KYOPRO_BASE_FLOAT\n#define KYOPRO_BASE_FLOAT double\n#endif\n\
    \n#ifndef KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD static_cast<KYOPRO_BASE_UINT>(1000000007)\n\
    #endif\n\n#ifndef KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n\
    #endif\n\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 5 \"math/divisors.hpp\"\n\nnamespace kyopro {\n  template<class\
    \ _typeContainer = std::vector<KYOPRO_BASE_INT>>\n  _typeContainer divisors(KYOPRO_BASE_UINT\
    \ _n) {\n    _typeContainer _lower, _upper;\n    std::uint_fast64_t _i;\n    for\
    \ (_i = 1; _i * _i < _n; ++_i) if (_n % _i == 0) {\n      _lower.emplace_back(_i);\n\
    \      _upper.emplace_back(_n / _i);\n    }\n    if (_i * _i == _n) _lower.emplace_back(_i);\n\
    \    _lower.insert(end(_lower), rall(_upper));\n    return _lower;\n  }\n}\n#line\
    \ 2 \"math/DynamicModInt.hpp\"\n#include <cassert>\n#line 2 \"base/constant.hpp\"\
    \n#include <array>\n#include <limits>\n#include <utility>\n#line 3 \"math/power.hpp\"\
    \n\nnamespace kyopro {\n  template<class _typeT>\n  constexpr _typeT power(_typeT\
    \ _a, KYOPRO_BASE_UINT _n, _typeT _init = 1) noexcept {\n    while (_n > 0) {\n\
    \      if (_n & 1) _init *= _a;\n      _a *= _a;\n      _n >>= 1;\n    }\n   \
    \ return _init;\n  }\n}\n#line 7 \"base/constant.hpp\"\n\nnamespace kyopro {\n\
    \  template<class _typeT>\n  inline constexpr _typeT MOD = KYOPRO_DEFAULT_MOD;\n\
    \  inline constexpr KYOPRO_BASE_INT mod = MOD<KYOPRO_BASE_INT>;\n\n  template<class\
    \ _typeT>\n  inline constexpr _typeT INF = std::numeric_limits<_typeT>::max()\
    \ / KYOPRO_INF_DIV;\n  inline constexpr KYOPRO_BASE_INT inf = INF<KYOPRO_BASE_INT>;\n\
    \n  template<class _typeT, KYOPRO_BASE_UINT _decimal_precision = KYOPRO_DECIMAL_PRECISION>\n\
    \  inline constexpr KYOPRO_BASE_FLOAT EPS = static_cast<_typeT>(1) / power(10ULL,\
    \ _decimal_precision);\n  inline constexpr KYOPRO_BASE_FLOAT eps = EPS<KYOPRO_BASE_FLOAT>;\n\
    \n  template<class _typeT>\n  inline constexpr _typeT PI = 3.14159265358979323846;\n\
    \  inline constexpr KYOPRO_BASE_FLOAT pi = PI<KYOPRO_BASE_FLOAT>;\n\n  inline\
    \ constexpr std::array<std::pair<KYOPRO_BASE_INT, KYOPRO_BASE_INT>, 4> beside{{{1,\
    \ 0}, {0, 1}, {-1, 0}, {0, -1}}};\n  inline constexpr std::array<std::pair<KYOPRO_BASE_INT,\
    \ KYOPRO_BASE_INT>, 8> around{{{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1,\
    \ -1}, {0, -1}, {1, -1}}};\n}\n#line 2 \"base/Hash.hpp\"\n#include <cstddef>\n\
    #line 4 \"base/Hash.hpp\"\n#include <functional>\n#include <initializer_list>\n\
    #include <tuple>\n#line 2 \"base/trait.hpp\"\n#include <iterator>\n#include <queue>\n\
    #include <stack>\n#line 7 \"base/trait.hpp\"\n\n#ifdef __SIZEOF_INT128__\ntemplate<>\n\
    struct std::is_integral<__int128_t>: std::true_type {};\ntemplate<>\nstruct std::is_signed<__int128_t>:\
    \ std::true_type {};\ntemplate<>\nstruct std::is_integral<__uint128_t>: std::true_type\
    \ {};\ntemplate<>\nstruct std::is_unsigned<__uint128_t>: std::true_type {};\n\
    #endif\n#ifdef __SIZEOF_FLOAT128__\ntemplate<>\nstruct std::is_floating_point<__float128>:\
    \ std::true_type {};\n#endif\n\nnamespace kyopro {\n  template<class, class =\
    \ void>\n  struct is_iterator: std::false_type {};\n  template<class _typeT>\n\
    \  struct is_iterator<_typeT, std::void_t<typename std::iterator_traits<_typeT>::iterator_category>>:\
    \ std::true_type {};\n  template<class _typeT>\n  constexpr bool is_iterator_v\
    \ = is_iterator<_typeT>::value;\n\n  template<class, class = void>\n  struct is_iterable:\
    \ std::false_type {};\n  template<class _typeT>\n  struct is_iterable<_typeT,\
    \ std::enable_if_t<is_iterator_v<decltype(std::begin(std::declval<_typeT>()))>>>:\
    \ std::true_type {};\n  template<class _typeT>\n  constexpr bool is_iterable_v\
    \ = is_iterable<_typeT>::value;\n\n  template<class>\n  struct is_tuple: std::false_type\
    \ {};\n  template<class _typeT, class _typeU>\n  struct is_tuple<std::pair<_typeT,\
    \ _typeU>>: std::true_type {};\n  template<class... _typeArgs>\n  struct is_tuple<std::tuple<_typeArgs...>>:\
    \ std::true_type {};\n  template<class _typeT>\n  constexpr bool is_tuple_v =\
    \ is_tuple<_typeT>::value;\n\n  template<class, class = void>\n  struct is_container_adapter:\
    \ std::false_type {};\n  template<class _typeT>\n  struct is_container_adapter<_typeT,\
    \ std::void_t<decltype(std::empty(std::declval<_typeT>()))>>: std::negation<is_iterable<_typeT>>\
    \ {};\n  template<class _typeT>\n  constexpr bool is_container_adapter_v = is_container_adapter<_typeT>::value;\n\
    }\n#line 11 \"base/Hash.hpp\"\n\nnamespace kyopro {\n  template<class, class =\
    \ void>\n  struct Hash;\n\n  template<class _typeT>\n  struct Hash<_typeT, std::enable_if_t<std::is_scalar_v<_typeT>>>\
    \ {\n  private:\n    [[no_unique_address]] std::hash<_typeT> _hashser;\n\n  public:\n\
    \    constexpr std::size_t operator ()(_typeT a) const noexcept {\n      return\
    \ _hasher(a);\n    }\n  };\n\n  template<class _typeT>\n  struct Hash<_typeT,\
    \ std::enable_if_t<is_tuple_v<_typeT>>> {\n    template<std::size_t _i = 0>\n\
    \    constexpr std::size_t operator ()(const _typeT& _a) const noexcept {\n  \
    \    if constexpr (_i == std::tuple_size_v<_typeT>) return std::tuple_size_v<_typeT>;\n\
    \      else {\n        std::uint_fast64_t _seed = operator()<_i + 1>(_a);\n  \
    \      return _seed ^ (Hash<std::tuple_element_t<_i, _typeT>>()(std::get<_i>(_a))\
    \ + 0x9e3779b97f4a7c15LU + (_seed << 12) + (_seed >> 4));\n      }\n    }\n  };\n\
    \n  template<class _typeT>\n  struct Hash<_typeT, std::enable_if_t<is_iterable_v<_typeT>>>\
    \ {\n  private:\n    [[no_unique_address]] Hash<decltype(*std::begin(std::declval<_typeT>()))>\
    \ _hasher;\n\n  public:\n    constexpr std::size_t operator ()(const _typeT& _a)\
    \ const noexcept {\n      std::uint_fast64_t _seed = _a.size();\n      for (auto&\
    \ _i: _a) _seed ^= _hasher(_i) + 0x9e3779b97f4a7c15LU + (_seed << 12) + (_seed\
    \ >> 4);\n      return _seed;\n    }\n  };\n}\n#line 4 \"math/mod.hpp\"\n\nnamespace\
    \ kyopro {\n  template<class _typeT, class _typeU>\n  constexpr std::common_type_t<_typeT,\
    \ _typeU> floor_mod(_typeT _x, _typeU _m) noexcept {\n    static_assert(std::is_integral_v<_typeT>\
    \ && std::is_integral_v<_typeU>);\n    if constexpr (std::is_unsigned_v<_typeT>\
    \ || std::is_unsigned_v<_typeU>) return _x % _m;\n    return (_x %= _m) < 0 ?\
    \ _x + _m : _x;\n  }\n\n  template<class _typeT, class _typeU>\n  constexpr std::common_type_t<_typeT,\
    \ _typeU> ceil_mod(_typeT _x, _typeU _m) noexcept {\n    return _m - floor_mod(_x\
    \ - 1, _m) - static_cast<_typeT>(1);\n  }\n}\n#line 9 \"math/DynamicModInt.hpp\"\
    \n\nnamespace kyopro {\n  struct DynamicModInt {\n    inline static KYOPRO_BASE_UINT\
    \ mod;\n    KYOPRO_BASE_UINT value;\n\n    static void set_mod(KYOPRO_BASE_UINT\
    \ _mod) noexcept {\n      mod = _mod;\n    }\n\n    static KYOPRO_BASE_INT get_mod()\
    \ noexcept {\n      return static_cast<KYOPRO_BASE_UINT>(mod);\n    }\n\n    DynamicModInt()\
    \ noexcept = default;\n    template<class _typeT>\n    DynamicModInt(_typeT _value)\
    \ noexcept: value(floor_mod(_value, mod)) { static_assert(std::is_integral_v<_typeT>);\
    \ }\n\n    template<class _typeT>\n    explicit operator _typeT() const noexcept\
    \ { return static_cast<_typeT>(value); }\n\n    static DynamicModInt raw(KYOPRO_BASE_UINT\
    \ _n) noexcept {\n      DynamicModInt _res;\n      _res.value = _n;\n      return\
    \ _res;\n    }\n\n    DynamicModInt power(KYOPRO_BASE_UINT _n) const noexcept\
    \ {\n      std::uint_fast64_t _res = 1, _a = value;\n      while (_n > 0) {\n\
    \        if (_n & 1) _res = _res * _a % mod;\n        _a = _a * _a % mod;\n  \
    \      _n >>= 1;\n      }\n      return _res;\n    }\n\n    DynamicModInt inv()\
    \ const noexcept {\n      std::uint_fast64_t _a = value, _b = mod;\n      std::int_fast64_t\
    \ _u = 1, _v = 0;\n      while (_b > 0) {\n        std::uint_fast64_t _t = _a\
    \ / _b;\n        _a -= _t * _b;\n        std::swap(_a, _b);\n        _u -= _t\
    \ * _v;\n        std::swap(_u, _v);\n      }\n      return floor_mod(_u, mod);\n\
    \    }\n\n    DynamicModInt operator +() const noexcept { return *this; }\n\n\
    \    DynamicModInt operator -() const noexcept { return mod - value; }\n\n   \
    \ DynamicModInt& operator ++() noexcept {\n      if (++value >= mod) value -=\
    \ mod;\n      return *this;\n    }\n\n    DynamicModInt operator ++(int) noexcept\
    \ {\n      DynamicModInt _before = *this;\n      operator ++();\n      return\
    \ _before;\n    }\n\n    DynamicModInt& operator --() noexcept {\n      if (value\
    \ == 0) value = mod;\n      --value;\n      return *this;\n    }\n\n    DynamicModInt\
    \ operator --(int) noexcept {\n      DynamicModInt _before = *this;\n      operator\
    \ --();\n      return _before;\n    }\n\n    DynamicModInt& operator +=(DynamicModInt\
    \ _rhs) noexcept {\n      if ((value += _rhs.value) >= mod) value -= mod;\n  \
    \    return *this;\n    }\n\n    DynamicModInt& operator -=(DynamicModInt _rhs)\
    \ noexcept {\n      if (value < _rhs.value) value += mod;\n      value -= _rhs.value;\n\
    \      return *this;\n    }\n\n    DynamicModInt& operator *=(DynamicModInt _rhs)\
    \ noexcept {\n      value = value * _rhs.value % mod;\n      return *this;\n \
    \   }\n\n    DynamicModInt& operator /=(DynamicModInt _rhs) noexcept {\n     \
    \ value = value * _rhs.inv().value % mod;\n      return *this;\n    }\n\n    friend\
    \ DynamicModInt operator +(DynamicModInt _lhs, DynamicModInt _rhs) noexcept {\
    \ return _lhs += _rhs; }\n\n    friend DynamicModInt operator -(DynamicModInt\
    \ _lhs, DynamicModInt _rhs) noexcept { return _lhs -= _rhs; }\n\n    friend DynamicModInt\
    \ operator *(DynamicModInt _lhs, DynamicModInt _rhs) noexcept { return _lhs *=\
    \ _rhs; }\n\n    friend DynamicModInt operator /(DynamicModInt _lhs, DynamicModInt\
    \ _rhs) noexcept { return _lhs /= _rhs; }\n\n    friend bool operator ==(DynamicModInt\
    \ _lhs, DynamicModInt _rhs) noexcept { return _lhs.value == _rhs.value; }\n\n\
    \    friend bool operator !=(DynamicModInt _lhs, DynamicModInt _rhs) noexcept\
    \ { return _lhs.value != _rhs.value; }\n\n    template<class _typeScanner>\n \
    \   void scan(_typeScanner& _scanner) {\n      std::int_fast64_t _value;\n   \
    \   _scanner.scan(_value);\n      value = floor_mod(_value, mod);\n    }\n\n \
    \   template<class _typePrinter>\n    void print(_typePrinter& _printer) const\
    \ {\n      _printer.print(value);\n    }\n  };\n\n  template<>\n  struct Hash<DynamicModInt>\
    \ { std::size_t operator ()(DynamicModInt _a) const noexcept { return static_cast<std::size_t>(_a);\
    \ } };\n}\n#line 4 \"math/euler_phi.hpp\"\n\nnamespace kyopro {\n  constexpr KYOPRO_BASE_UINT\
    \ euler_phi(KYOPRO_BASE_UINT _n) noexcept {\n    std::uint_fast64_t _res = _n;\n\
    \    if ((_n & 1) == 0) {\n      _res -= _res >> 1;\n      _n >>= 1;\n      while\
    \ ((_n & 1) == 0) _n >>= 1;\n    }\n    for (std::uint_fast64_t _i = 3; _i * _i\
    \ <= _n; _i += 2) {\n      if (_n % _i == 0) {\n        _res -= _res / _i;\n \
    \       _n /= _i;\n        while (_n % _i == 0) _n /= _i;\n      }\n    }\n  \
    \  if (_n != 1) _res -= _res / _n;\n    return _res;\n  }\n}\n#line 2 \"math/factorize.hpp\"\
    \n#include <algorithm>\n#line 4 \"math/factorize.hpp\"\n#include <numeric>\n#include\
    \ <random>\n#line 6 \"math/modpow.hpp\"\n\nnamespace kyopro {\n  template<class\
    \ _typeT>\n  constexpr _typeT modpow(_typeT _a, KYOPRO_BASE_UINT _n, KYOPRO_BASE_UINT\
    \ _mod) noexcept {\n    static_assert(std::is_integral_v<_typeT>);\n    std::uint_fast64_t\
    \ _b = floor_mod(_a, static_cast<_typeT>(_mod));\n    std::uint_fast64_t _res\
    \ = 1;\n    while (_n > 0) {\n      if (_n & 1) _res = _res * _b % _mod;\n   \
    \   _b *= _b;\n      _n >>= 1;\n    }\n    return static_cast<_typeT>(_res);\n\
    \  }\n}\n#line 6 \"math/is_prime.hpp\"\n\nnamespace kyopro {\n  constexpr bool\
    \ is_prime(KYOPRO_BASE_UINT _n) {\n    if (_n <= 1) return false;\n    if (~_n\
    \ & 1) return _n == 2;\n    std::uint_fast64_t _d = _n - 1;\n    while (~_d &\
    \ 1) _d >>= 1;\n    std::uint_fast64_t _e = 1, _rev = _n - 1;\n    for (auto _a:\
    \ std::array<std::uint_fast64_t, 7>{2, 325, 9375, 28178, 450775, 9780504, 1795265022})\
    \ {\n      if (_n <= _a) break;\n      std::uint_fast64_t _t = _d, _y = modpow(_a,\
    \ _t, _n);\n      while (_t != _n - 1 && _y != _e && _y != _rev) {\n        _y\
    \ = _y * _y % _n;\n        _t <<= 1;\n      }\n      if (_y != _rev && !(_t &\
    \ 1)) return false;\n    }\n    return true;\n  }\n}\n#line 8 \"math/factorize.hpp\"\
    \n\nnamespace kyopro {\n  template<class T>\n  constexpr T pollard_rho(T n, KYOPRO_BASE_UINT\
    \ c) {\n    std::uint_fast64_t cc = c % n;\n    auto f = [=](std::uint_fast64_t\
    \ x) noexcept { return (x * x + cc) % n; };\n    std::uint_fast64_t x = 1, y =\
    \ 2, z = 1, q = 1;\n    T g = 1;\n    for (std::uint_fast64_t r = 1; g == 1; r\
    \ <<= 1) {\n      x = y;\n      for (int i = 0; i < r; ++i) y = f(y);\n      for\
    \ (int k = 0; k < r and g == 1; k += 128) {\n        z = y;\n        int min =\
    \ std::min(128, r - k);\n        for (int i = 0; i < min; ++i) {\n          y\
    \ = f(y);\n          q = q * abs(x - y) % n;\n        }\n        g = std::gcd(q,\
    \ n);\n      }\n    }\n    if (g == n) {\n      do {\n        z = f(z);\n    \
    \    g = std::gcd(abs(x - z), n);\n      } while (g == 1);\n    }\n    return\
    \ g;\n  }\n\n  KYOPRO_BASE_UINT find_prime_factor(KYOPRO_BASE_UINT n) noexcept\
    \ {\n    static std::mt19937_64 mt(std::random_device{}());\n    std::uniform_int_distribution<std::uint_fast64_t>\
    \ rnd(0, n - 1);\n    if (is_prime(n)) return n;\n    for (int i = 0; i < 100;\
    \ ++i) {\n      std::uint_fast64_t m = pollard_rho(n, rnd(mt));\n      if (is_prime(m))\
    \ return m;\n      n = m;\n    }\n    return 1;\n  }\n\n  template<bool sorted\
    \ = true, class _typeContainer = std::vector<KYOPRO_BASE_INT>>\n  _typeContainer\
    \ factorize(KYOPRO_BASE_UINT n) {\n    _typeContainer res;\n    for (int p = 2;\
    \ p < 100 && p * p <= n; ++p) {\n      while (n % p == 0) {\n        n /= p;\n\
    \        res.eb(p);\n      }\n    }\n    while (n > 1) {\n      std::uint_fast64_t\
    \ p = find_prime_factor(n);\n      while (n % p == 0) {\n        n /= p;\n   \
    \     res.eb(p);\n      }\n    }\n    if constexpr (sorted) std::sort(res.begin(),\
    \ res.end());\n    return res;\n  }\n}\n#line 9 \"math/ModInt.hpp\"\n\nnamespace\
    \ kyopro {\n  template<KYOPRO_BASE_UINT _m>\n  struct ModInt {\n    static constexpr\
    \ KYOPRO_BASE_UINT mod = _m;\n    KYOPRO_BASE_UINT value;\n\n    static KYOPRO_BASE_INT\
    \ get_mod() noexcept {\n      return static_cast<KYOPRO_BASE_INT>(_m);\n    }\n\
    \n    constexpr ModInt() noexcept = default;\n    template<class _typeT>\n   \
    \ constexpr ModInt(_typeT _value) noexcept: value(floor_mod(_value, _m)) { static_assert(std::is_integral_v<_typeT>);\
    \ }\n\n    template<class _typeT>\n    explicit constexpr operator _typeT() const\
    \ noexcept { return static_cast<_typeT>(value); }\n\n    static constexpr ModInt\
    \ raw(KYOPRO_BASE_UINT _n) noexcept {\n      ModInt _res;\n      _res.value =\
    \ _n;\n      return _res;\n    }\n\n    constexpr ModInt power(KYOPRO_BASE_UINT\
    \ _n) const noexcept {\n      std::uint_fast64_t _res = 1, _a = value;\n     \
    \ while (_n > 0) {\n        if (_n & 1) _res = _res * _a % _m;\n        _a = _a\
    \ * _a % _m;\n        _n >>= 1;\n      }\n      return _res;\n    }\n\n    constexpr\
    \ ModInt inv() const noexcept {\n      std::uint_fast64_t _a = value, _b = _m;\n\
    \      std::int_fast64_t _u = 1, _v = 0;\n      while (_b > 0) {\n        std::uint_fast64_t\
    \ _t = _a / _b;\n        _a -= _t * _b;\n        std::swap(_a, _b);\n        _u\
    \ -= _t * _v;\n        std::swap(_u, _v);\n      }\n      return floor_mod(_u,\
    \ _m);\n    }\n\n    constexpr ModInt operator +() const noexcept { return *this;\
    \ }\n\n    constexpr ModInt operator -() const noexcept { return _m - value; }\n\
    \n    constexpr ModInt& operator ++() noexcept {\n      if (++value >= _m) value\
    \ -= _m;\n      return *this;\n    }\n\n    constexpr ModInt operator ++(int)\
    \ noexcept {\n      ModInt _before = *this;\n      operator ++();\n      return\
    \ _before;\n    }\n\n    constexpr ModInt& operator --() noexcept {\n      if\
    \ (value == 0) value = _m;\n      --value;\n      return *this;\n    }\n\n   \
    \ constexpr ModInt operator --(int) noexcept {\n      ModInt _before = *this;\n\
    \      operator --();\n      return _before;\n    }\n\n    constexpr ModInt& operator\
    \ +=(ModInt _rhs) noexcept {\n      if ((value += _rhs.value) >= _m) value -=\
    \ _m;\n      return *this;\n    }\n\n    constexpr ModInt& operator -=(ModInt\
    \ _rhs) noexcept {\n      if (value < _rhs.value) value += _m;\n      value -=\
    \ _rhs.value;\n      return *this;\n    }\n\n    constexpr ModInt& operator *=(ModInt\
    \ _rhs) noexcept {\n      value = value * _rhs.value % _m;\n      return *this;\n\
    \    }\n\n    constexpr ModInt& operator /=(ModInt _rhs) noexcept {\n      value\
    \ = value * _rhs.inv().value % _m;\n      return *this;\n    }\n\n    friend constexpr\
    \ ModInt operator +(ModInt _lhs, ModInt _rhs) noexcept { return _lhs += _rhs;\
    \ }\n\n    friend constexpr ModInt operator -(ModInt _lhs, ModInt _rhs) noexcept\
    \ { return _lhs -= _rhs; }\n\n    friend constexpr ModInt operator *(ModInt _lhs,\
    \ ModInt _rhs) noexcept { return _lhs *= _rhs; }\n\n    friend constexpr ModInt\
    \ operator /(ModInt _lhs, ModInt _rhs) noexcept { return _lhs /= _rhs; }\n\n \
    \   friend constexpr bool operator ==(ModInt _lhs, ModInt _rhs) noexcept { return\
    \ _lhs.value == _rhs.value; }\n\n    friend constexpr bool operator !=(ModInt\
    \ _lhs, ModInt _rhs) noexcept { return _lhs.value != _rhs.value; }\n\n    template<class\
    \ _typeScanner>\n    void scan(_typeScanner& _scanner) {\n      std::int_fast64_t\
    \ _value;\n      _scanner.scan(_value);\n      value = floor_mod(_value, _m);\n\
    \    }\n\n    template<class _typePrinter>\n    void print(_typePrinter& _printer)\
    \ const {\n      _printer.print(value);\n    }\n  };\n\n  template<KYOPRO_BASE_UINT\
    \ _m>\n  struct Hash<ModInt<_m>> { constexpr std::size_t operator ()(ModInt<_m>\
    \ _a) const noexcept { return static_cast<std::size_t>(_a); } };\n}\n#line 4 \"\
    math/monoid.hpp\"\n\nnamespace kyopro {\n  template<class _typeT, _typeT _id =\
    \ 0>\n  struct Plus {\n    static_assert(std::is_arithmetic_v<_typeT>);\n    static\
    \ constexpr _typeT id = _id;\n    constexpr _typeT operator ()(_typeT _a, _typeT\
    \ _b) const noexcept { return _a + _b; }\n    constexpr _typeT inv(_typeT _a)\
    \ const noexcept { return -_a; }\n  };\n  template<class _typeT, _typeT _id =\
    \ 1>\n  struct Mul {\n    static_assert(std::is_arithmetic_v<_typeT>);\n    static\
    \ constexpr _typeT id = _id;\n    constexpr _typeT operator ()(_typeT _a, _typeT\
    \ _b) const noexcept { return _a * _b; }\n    constexpr _typeT inv(_typeT _a)\
    \ const noexcept {\n      static_assert(!std::is_integral_v<_typeT>);\n      return\
    \ 1 / _a;\n    }\n  };\n  template<class _typeT, _typeT _id = std::is_integral_v<_typeT>\
    \ ? -INF<_typeT> : -inf>\n  struct Max {\n    static_assert(std::is_arithmetic_v<_typeT>);\n\
    \    static constexpr _typeT id = _id;\n    constexpr _typeT operator ()(_typeT\
    \ _a, _typeT _b) const noexcept { return _a > _b ? _a : _b; }\n  };\n  template<class\
    \ _typeT, _typeT _id = std::is_integral_v<_typeT> ? INF<_typeT> : inf>\n  struct\
    \ Min {\n    static_assert(std::is_arithmetic_v<_typeT>);\n    static constexpr\
    \ _typeT id = _id;\n    constexpr _typeT operator ()(_typeT _a, _typeT _b) const\
    \ noexcept { return _a < _b ? _a : _b; }\n  };\n}\n#line 13 \"math/all.hpp\"\n"
  code: '#pragma once

    #include "div.hpp"

    #include "divisors.hpp"

    #include "DynamicModInt.hpp"

    #include "euler_phi.hpp"

    #include "factorize.hpp"

    #include "is_prime.hpp"

    #include "mod.hpp"

    #include "ModInt.hpp"

    #include "modpow.hpp"

    #include "monoid.hpp"

    #include "power.hpp"'
  dependsOn:
  - math/div.hpp
  - math/divisors.hpp
  - base/settings.hpp
  - math/DynamicModInt.hpp
  - base/constant.hpp
  - math/power.hpp
  - base/Hash.hpp
  - base/trait.hpp
  - math/mod.hpp
  - math/euler_phi.hpp
  - math/factorize.hpp
  - math/is_prime.hpp
  - math/modpow.hpp
  - math/ModInt.hpp
  - math/monoid.hpp
  isVerificationFile: false
  path: math/all.hpp
  requiredBy:
  - all.hpp
  timestamp: '2022-03-12 18:34:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/all.hpp
layout: document
redirect_from:
- /library/math/all.hpp
- /library/math/all.hpp.html
title: math/all.hpp
---
