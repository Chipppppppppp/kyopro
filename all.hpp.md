---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: algorithm/Hash.hpp
    title: algorithm/Hash.hpp
  - icon: ':warning:'
    path: algorithm/all.hpp
    title: algorithm/all.hpp
  - icon: ':warning:'
    path: math/Barrett.hpp
    title: math/Barrett.hpp
  - icon: ':warning:'
    path: math/DynamicModInt.hpp
    title: math/DynamicModInt.hpp
  - icon: ':warning:'
    path: math/ModInt.hpp
    title: math/ModInt.hpp
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
  - icon: ':warning:'
    path: math/monoid.hpp
    title: math/monoid.hpp
  - icon: ':warning:'
    path: math/power.hpp
    title: math/power.hpp
  - icon: ':warning:'
    path: meta/all.hpp
    title: meta/all.hpp
  - icon: ':warning:'
    path: meta/constant.hpp
    title: meta/constant.hpp
  - icon: ':warning:'
    path: meta/settings.hpp
    title: meta/settings.hpp
  - icon: ':warning:'
    path: meta/trait.hpp
    title: meta/trait.hpp
  - icon: ':warning:'
    path: system/all.hpp
    title: system/all.hpp
  - icon: ':warning:'
    path: system/in.hpp
    title: system/in.hpp
  - icon: ':warning:'
    path: system/out.hpp
    title: system/out.hpp
  - icon: ':warning:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':warning:'
    path: template/all.hpp
    title: template/all.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algorithm/Hash.hpp\"\n#include <cstddef>\n#include <cstdint>\n\
    #include <functional>\n#include <initializer_list>\n#include <tuple>\n#include\
    \ <type_traits>\n#include <utility>\n#line 3 \"meta/settings.hpp\"\n\n#ifndef\
    \ KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT std::int64_t\n#endif\n\n#ifndef KYOPRO_BASE_UINT\n\
    #define KYOPRO_BASE_UINT std::uint64_t\n#endif\n\n#ifndef KYOPRO_BASE_FLOAT\n\
    #define KYOPRO_BASE_FLOAT double\n#endif\n\n#ifndef KYOPRO_DEFAULT_MOD\n#define\
    \ KYOPRO_DEFAULT_MOD static_cast<KYOPRO_BASE_UINT>(1000000007)\n#endif\n\n#ifndef\
    \ KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n\
    #endif\n\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 2 \"meta/trait.hpp\"\n#include <iterator>\n#include <queue>\n#include\
    \ <limits>\n#include <stack>\n#line 9 \"meta/trait.hpp\"\n\ntemplate<>\nstruct\
    \ std::is_integral<__int128_t>: std::true_type {};\ntemplate<>\nstruct std::is_signed<__int128_t>:\
    \ std::true_type {};\ntemplate<>\nstruct std::is_integral<__uint128_t>: std::true_type\
    \ {};\ntemplate<>\nstruct std::is_unsigned<__uint128_t>: std::true_type {};\n\
    #ifdef __SIZEOF_FLOAT128__\ntemplate<>\nstruct std::is_floating_point<__float128>:\
    \ std::true_type {};\n#endif\n\nnamespace kyopro {\n  template<KYOPRO_BASE_UINT\
    \ _size>\n  struct int_least {\n  private:\n    auto _get_type() const noexcept\
    \ {\n      if constexpr (_size <= 8) return std::declval<std::int_least8_t>();\n\
    \      if constexpr (_size <= 16) return std::declval<std::int_least16_t>();\n\
    \      if constexpr (_size <= 32) return std::declval<std::int_least32_t>();\n\
    \      if constexpr (_size <= 64) return std::declval<std::int_least64_t>();\n\
    \      static_assert(_size <= 128, \"Integer size is too long\");\n      return\
    \ std::declval<__int128_t>();\n    }\n\n  public:\n    using type = decltype(_get_type());\n\
    \  };\n\n  template<KYOPRO_BASE_UINT _size>\n  using int_least_t = int_least<_size>::type;\n\
    \n  template<KYOPRO_BASE_UINT _size>\n  struct uint_least {\n  private:\n    auto\
    \ _get_type() const noexcept {\n      if constexpr (_size <= 8) return std::declval<std::uint_least8_t>();\n\
    \      if constexpr (_size <= 16) return std::declval<std::uint_least16_t>();\n\
    \      if constexpr (_size <= 32) return std::declval<std::uint_least32_t>();\n\
    \      if constexpr (_size <= 64) return std::declval<std::uint_least64_t>();\n\
    \      static_assert(_size <= 128, \"Integer size is too long\");\n      return\
    \ std::declval<__uint128_t>();\n    }\n\n  public:\n    using type = decltype(_get_type());\n\
    \  };\n\n  template<KYOPRO_BASE_UINT _size>\n  using uint_least_t = uint_least<_size>::type;\n\
    \n  template<class, class = void>\n  struct is_iterator: std::false_type {};\n\
    \  template<class _typeT>\n  struct is_iterator<_typeT, std::void_t<typename std::iterator_traits<_typeT>::iterator_category>>:\
    \ std::true_type {};\n\n  template<class _typeT>\n  constexpr bool is_iterator_v\
    \ = is_iterator<_typeT>::value;\n\n  template<class, class = void>\n  struct is_iterable:\
    \ std::false_type {};\n  template<class _typeT>\n  struct is_iterable<_typeT,\
    \ std::enable_if_t<is_iterator_v<decltype(std::begin(std::declval<_typeT>()))>>>:\
    \ std::true_type {};\n\n  template<class _typeT>\n  constexpr bool is_iterable_v\
    \ = is_iterable<_typeT>::value;\n\n  template<class>\n  struct is_tuple: std::false_type\
    \ {};\n  template<class _typeT, class _typeU>\n  struct is_tuple<std::pair<_typeT,\
    \ _typeU>>: std::true_type {};\n  template<class... _typeArgs>\n  struct is_tuple<std::tuple<_typeArgs...>>:\
    \ std::true_type {};\n\n  template<class _typeT>\n  constexpr bool is_tuple_v\
    \ = is_tuple<_typeT>::value;\n\n  template<class, class = void>\n  struct is_container_adapter:\
    \ std::false_type {};\n  template<class _typeT>\n  struct is_container_adapter<_typeT,\
    \ std::void_t<decltype(std::empty(std::declval<_typeT>()))>>: std::negation<is_iterable<_typeT>>\
    \ {};\n\n  template<class _typeT>\n  constexpr bool is_container_adapter_v = is_container_adapter<_typeT>::value;\n\
    }\n#line 11 \"algorithm/Hash.hpp\"\n\nnamespace kyopro {\n  template<class, class\
    \ = void>\n  struct Hash;\n\n  template<class _typeT>\n  struct Hash<_typeT, std::enable_if_t<std::is_scalar_v<_typeT>>>\
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
    \ >> 4);\n      return _seed;\n    }\n  };\n}\n#line 2 \"math/Barrett.hpp\"\n\n\
    #line 5 \"math/Barrett.hpp\"\n\nstruct Barrett {\nprivate:\n  std::uint_fast64_t\
    \ _mod;\n  __uint128_t _m;\n\npublic:\n  constexpr void set_mod(KYOPRO_BASE_UINT\
    \ _mod) noexcept {\n    this->_mod = _mod;\n    _m = (static_cast<__uint128_t>(1)\
    \ << 64) / _mod;\n  }\n\n  constexpr KYOPRO_BASE_INT get_mod() const noexcept\
    \ {\n    return static_cast<KYOPRO_BASE_INT>(_mod);\n  }\n\n  Barrett() noexcept\
    \ = default;\n  Barrett(KYOPRO_BASE_UINT _mod) noexcept: _mod(_mod), _m((static_cast<__uint128_t>(1)\
    \ << 64) / _mod) {}\n\n  constexpr KYOPRO_BASE_UINT operator ()(KYOPRO_BASE_UINT\
    \ _x) const noexcept {\n\t  _x -= static_cast<std::uint_fast64_t>((_x * _m) >>\
    \ 64) * _mod;\n    return _x < _mod ? _x : _x - _mod;\n  }\n};\n#line 3 \"math/div.hpp\"\
    \n\nnamespace kyopro {\n  template<class _typeT, class _typeU>\n  constexpr std::common_type_t<_typeT,\
    \ _typeU> floor_div(_typeT _x, _typeU _m) noexcept {\n    static_assert(std::is_integral_v<_typeT>\
    \ && std::is_integral_v<_typeU>);\n    if constexpr (std::is_unsigned_v<_typeT>\
    \ || std::is_unsigned_v<_typeU>) return _x / _m;\n    auto _d = _x / _m;\n   \
    \ return _d * _m == _x ? _d : _d - ((_x < 0) ^ (_m < 0));\n  }\n\n  template<class\
    \ _typeT, class _typeU>\n  constexpr std::common_type_t<_typeT, _typeU> ceil_div(_typeT\
    \ _x, _typeU _m) noexcept { return floor_div(_x + _m - static_cast<_typeT>(1),\
    \ _m); }\n}\n#line 3 \"math/divisors.hpp\"\n#include <vector>\n#line 5 \"math/divisors.hpp\"\
    \n\nnamespace kyopro {\n  template<class _typeContainer = std::vector<KYOPRO_BASE_INT>>\n\
    \  _typeContainer divisors(KYOPRO_BASE_UINT _n) {\n    _typeContainer _lower,\
    \ _upper;\n    std::uint_fast64_t _i;\n    for (_i = 1; _i * _i < _n; ++_i) if\
    \ (_n % _i == 0) {\n      _lower.emplace_back(_i);\n      _upper.emplace_back(_n\
    \ / _i);\n    }\n    if (_i * _i == _n) _lower.emplace_back(_i);\n    _lower.insert(end(_lower),\
    \ rall(_upper));\n    return _lower;\n  }\n}\n#line 2 \"math/DynamicModInt.hpp\"\
    \n#include <cassert>\n#line 2 \"meta/constant.hpp\"\n#include <array>\n#line 3\
    \ \"math/power.hpp\"\n\nnamespace kyopro {\n  template<class _typeT>\n  constexpr\
    \ _typeT power(_typeT _a, KYOPRO_BASE_UINT _n, _typeT _init = 1) noexcept {\n\
    \    while (_n > 0) {\n      if (_n & 1) _init *= _a;\n      _a *= _a;\n     \
    \ _n >>= 1;\n    }\n    return _init;\n  }\n}\n#line 7 \"meta/constant.hpp\"\n\
    \nnamespace kyopro {\n  template<class _typeT>\n  inline constexpr _typeT MOD\
    \ = KYOPRO_DEFAULT_MOD;\n  inline constexpr KYOPRO_BASE_INT mod = MOD<KYOPRO_BASE_INT>;\n\
    \n  template<class _typeT>\n  inline constexpr _typeT INF = std::numeric_limits<_typeT>::max()\
    \ / KYOPRO_INF_DIV;\n  inline constexpr KYOPRO_BASE_INT inf = INF<KYOPRO_BASE_INT>;\n\
    \n  template<class _typeT, KYOPRO_BASE_UINT _decimal_precision = KYOPRO_DECIMAL_PRECISION>\n\
    \  inline constexpr KYOPRO_BASE_FLOAT EPS = static_cast<_typeT>(1) / power(10ULL,\
    \ _decimal_precision);\n  inline constexpr KYOPRO_BASE_FLOAT eps = EPS<KYOPRO_BASE_FLOAT>;\n\
    \n  template<class _typeT>\n  inline constexpr _typeT PI = 3.14159265358979323846;\n\
    \  inline constexpr KYOPRO_BASE_FLOAT pi = PI<KYOPRO_BASE_FLOAT>;\n\n  inline\
    \ constexpr std::array<std::pair<KYOPRO_BASE_INT, KYOPRO_BASE_INT>, 4> beside{{{1,\
    \ 0}, {0, 1}, {-1, 0}, {0, -1}}};\n  inline constexpr std::array<std::pair<KYOPRO_BASE_INT,\
    \ KYOPRO_BASE_INT>, 8> around{{{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1,\
    \ -1}, {0, -1}, {1, -1}}};\n}\n#line 4 \"math/mod.hpp\"\n\nnamespace kyopro {\n\
    \  template<class _typeT, class _typeU>\n  constexpr std::common_type_t<_typeT,\
    \ _typeU> floor_mod(_typeT _x, _typeU _m) noexcept {\n    static_assert(std::is_integral_v<_typeT>\
    \ && std::is_integral_v<_typeU>);\n    if constexpr (std::is_unsigned_v<_typeT>\
    \ || std::is_unsigned_v<_typeU>) return _x % _m;\n    return (_x %= _m) < 0 ?\
    \ _x + _m : _x;\n  }\n\n  template<class _typeT, class _typeU>\n  constexpr std::common_type_t<_typeT,\
    \ _typeU> ceil_mod(_typeT _x, _typeU _m) noexcept {\n    return _m - floor_mod(_x\
    \ - 1, _m) - static_cast<_typeT>(1);\n  }\n}\n#line 10 \"math/DynamicModInt.hpp\"\
    \n\nnamespace kyopro {\n  struct DynamicModInt {\n  private:\n    inline static\
    \ std::uint_fast64_t _mod;\n    inline static Barrett _barrett;\n\n  public:\n\
    \    KYOPRO_BASE_UINT value;\n\n    static void set_mod(KYOPRO_BASE_UINT _m) noexcept\
    \ {\n      _mod = _m;\n      _barrett.set_mod(_m);\n    }\n\n    static KYOPRO_BASE_INT\
    \ get_mod() noexcept {\n      return static_cast<KYOPRO_BASE_INT>(_mod);\n   \
    \ }\n\n    DynamicModInt() noexcept = default;\n    template<class _typeT>\n \
    \   DynamicModInt(_typeT _value) noexcept: value(floor_mod(_value, _mod)) { static_assert(std::is_integral_v<_typeT>);\
    \ }\n\n    template<class _typeT>\n    explicit operator _typeT() const noexcept\
    \ { return static_cast<_typeT>(value); }\n\n    static DynamicModInt raw(KYOPRO_BASE_UINT\
    \ _n) noexcept {\n      DynamicModInt _res;\n      _res.value = _n;\n      return\
    \ _res;\n    }\n\n    DynamicModInt power(KYOPRO_BASE_UINT _n) const noexcept\
    \ {\n      std::uint_fast64_t _res = 1, _a = value;\n      while (_n > 0) {\n\
    \        if (_n & 1) _res = _res * _a % _mod;\n        _a = _a * _a % _mod;\n\
    \        _n >>= 1;\n      }\n      return _res;\n    }\n\n    DynamicModInt inv()\
    \ const noexcept {\n      std::uint_fast64_t _a = value, _b = _mod;\n      std::int_fast64_t\
    \ _u = 1, _v = 0;\n      while (_b > 0) {\n        std::uint_fast64_t _t = _a\
    \ / _b;\n        _a -= _t * _b;\n        std::swap(_a, _b);\n        _u -= _t\
    \ * _v;\n        std::swap(_u, _v);\n      }\n      return floor_mod(_u, _mod);\n\
    \    }\n\n    DynamicModInt operator +() const noexcept { return *this; }\n\n\
    \    DynamicModInt operator -() const noexcept { return _mod - value; }\n\n  \
    \  DynamicModInt& operator ++() noexcept {\n      if (++value >= _mod) value -=\
    \ _mod;\n      return *this;\n    }\n\n    DynamicModInt operator ++(int) noexcept\
    \ {\n      DynamicModInt _before = *this;\n      operator ++();\n      return\
    \ _before;\n    }\n\n    DynamicModInt& operator --() noexcept {\n      if (value\
    \ == 0) value = _mod;\n      --value;\n      return *this;\n    }\n\n    DynamicModInt\
    \ operator --(int) noexcept {\n      DynamicModInt _before = *this;\n      operator\
    \ --();\n      return _before;\n    }\n\n    DynamicModInt& operator +=(DynamicModInt\
    \ _rhs) noexcept {\n      if ((value += _rhs.value) >= _mod) value -= _mod;\n\
    \      return *this;\n    }\n\n    DynamicModInt& operator -=(DynamicModInt _rhs)\
    \ noexcept {\n      if (value < _rhs.value) value += _mod;\n      value -= _rhs.value;\n\
    \      return *this;\n    }\n\n    DynamicModInt& operator *=(DynamicModInt _rhs)\
    \ noexcept {\n      value = _barrett(value * _rhs.value);\n      return *this;\n\
    \    }\n\n    DynamicModInt& operator /=(DynamicModInt _rhs) noexcept {\n    \
    \  value = _barrett(value * _rhs.inv().value);\n      return *this;\n    }\n\n\
    \    friend DynamicModInt operator +(DynamicModInt _lhs, DynamicModInt _rhs) noexcept\
    \ { return _lhs += _rhs; }\n\n    friend DynamicModInt operator -(DynamicModInt\
    \ _lhs, DynamicModInt _rhs) noexcept { return _lhs -= _rhs; }\n\n    friend DynamicModInt\
    \ operator *(DynamicModInt _lhs, DynamicModInt _rhs) noexcept { return _lhs *=\
    \ _rhs; }\n\n    friend DynamicModInt operator /(DynamicModInt _lhs, DynamicModInt\
    \ _rhs) noexcept { return _lhs /= _rhs; }\n\n    friend bool operator ==(DynamicModInt\
    \ _lhs, DynamicModInt _rhs) noexcept { return _lhs.value == _rhs.value; }\n\n\
    \    friend bool operator !=(DynamicModInt _lhs, DynamicModInt _rhs) noexcept\
    \ { return _lhs.value != _rhs.value; }\n\n    template<class _typeScanner>\n \
    \   void scan(_typeScanner& _scanner) {\n      std::int_fast64_t _value;\n   \
    \   _scanner.scan(_value);\n      value = floor_mod(_value, _mod);\n    }\n\n\
    \    template<class _typePrinter>\n    void print(_typePrinter& _printer) const\
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
    \ <random>\n#line 5 \"math/is_prime.hpp\"\n\nnamespace kyopro {\n  constexpr bool\
    \ is_prime(KYOPRO_BASE_UINT _n) {\n    auto modpow = [](std::uint_fast64_t _a,\
    \ std::uint_fast64_t _n, std::uint_fast64_t _mod) noexcept {\n      std::uint_fast64_t\
    \ _b = _a % _mod;\n      std::uint_fast64_t _res = 1;\n      while (_n > 0) {\n\
    \        if (_n & 1) _res = static_cast<__uint128_t>(_res) * _b % _mod;\n    \
    \    _b = static_cast<__uint128_t>(_b) * _b % _mod;\n        _n >>= 1;\n     \
    \ }\n      return _res;\n    };\n    if (_n <= 1) return false;\n    if (!(_n\
    \ & 1)) return _n == 2;\n    std::uint_fast64_t _d = _n - 1;\n    while (!(_d\
    \ & 1)) _d >>= 1;\n    std::uint_fast64_t _e = 1, _rev = _n - 1;\n    for (auto\
    \ _a: (_n < (1ULL << 32) ? std::initializer_list<std::uint_fast64_t>{2, 7, 61}\
    \ : std::initializer_list<std::uint_fast64_t>{2, 325, 9375, 28178, 450775, 9780504,\
    \ 1795265022})) {\n      if (_n <= _a) break;\n      std::uint_fast64_t _t = _d,\
    \ _y = modpow(_a, _d, _n);\n      while (_t != _n - 1 && _y != _e && _y != _rev)\
    \ {\n        _y = static_cast<__uint128_t>(_y) * _y % _n;\n        _t <<= 1;\n\
    \      }\n      if (_y != _rev && !(_t & 1)) return false;\n    }\n    return\
    \ true;\n  }\n}\n#line 8 \"math/factorize.hpp\"\n\nnamespace kyopro {\n  template<class\
    \ T>\n  constexpr T pollard_rho(T _n, KYOPRO_BASE_UINT _c) {\n    std::uint_fast64_t\
    \ _cc = _c % _n;\n    auto _f = [=](std::uint_fast64_t _x) noexcept { return (_x\
    \ * _x + _cc) % _n; };\n    std::uint_fast64_t _x = 1, _y = 2, _z = 1, _q = 1;\n\
    \    T _g = 1;\n    for (int _r = 1; _g == 1; _r <<= 1) {\n      _x = _y;\n  \
    \    for (int _i = 0; _i < _r; ++_i) _y = _f(_y);\n      for (int _k = 0; _k <\
    \ _r && _g == 1; _k += 128) {\n        _z = _y;\n        int _min = std::min(128,\
    \ _r - _k);\n        for (int _i = 0; _i < _min; ++_i) {\n          _y = _f(_y);\n\
    \          _q = _q * (_x + _n - _y) % _n;\n        }\n        _g = std::gcd(_q,\
    \ _n);\n      }\n    }\n    if (_g == _n) {\n      do {\n        _z = _f(_z);\n\
    \        _g = std::gcd((_x + _n - _z) % _n, _n);\n      } while (_g == 1);\n \
    \   }\n    return _g;\n  }\n\n  KYOPRO_BASE_UINT find_prime_factor(KYOPRO_BASE_UINT\
    \ _n) noexcept {\n    static std::mt19937_64 _mt(std::random_device{}());\n  \
    \  std::uniform_int_distribution<std::uint_fast64_t> _rnd(0, _n - 1);\n    if\
    \ (is_prime(_n)) return _n;\n    for (int _i = 0; _i < 100; ++_i) {\n      std::uint_fast64_t\
    \ _m = pollard_rho(_n, _rnd(_mt));\n      if (is_prime(_m)) return _m;\n     \
    \ _n = _m;\n    }\n    return 1;\n  }\n\n  template<bool _sorted = true, class\
    \ _typeContainer = std::vector<KYOPRO_BASE_INT>>\n  _typeContainer factorize(KYOPRO_BASE_UINT\
    \ _n) {\n    _typeContainer _res;\n    for (int _p = 2; _p < 100 && _p * _p <=\
    \ _n; ++_p) {\n      while (_n % _p == 0) {\n        _n /= _p;\n        _res.emplace_back(_p);\n\
    \      }\n    }\n    while (_n > 1) {\n      std::uint_fast64_t _p = find_prime_factor(_n);\n\
    \      while (_n % _p == 0) {\n        _n /= _p;\n        _res.emplace_back(_p);\n\
    \      }\n    }\n    if constexpr (_sorted) std::sort(_res.begin(), _res.end());\n\
    \    return _res;\n  }\n}\n#line 11 \"math/ModInt.hpp\"\n\nnamespace kyopro {\n\
    \  template<KYOPRO_BASE_UINT _mod>\n  struct ModInt {\n  private:\n    static\
    \ constexpr value_type _mod = static_cast<value_type>(_mod);\n\n  public:\n  \
    \  using value_type = uint_least_t<>;\n\n    value_type value;\n\n    static constexpr\
    \ KYOPRO_BASE_INT get_mod() noexcept {\n      return static_cast<KYOPRO_BASE_INT>(_mod);\n\
    \    }\n\n    constexpr ModInt() noexcept = default;\n    template<class _typeT>\n\
    \    constexpr ModInt(_typeT _value) noexcept: value(floor_mod(_value, _mod))\
    \ { static_assert(std::is_integral_v<_typeT>); }\n\n    template<class _typeT>\n\
    \    explicit constexpr operator _typeT() const noexcept { return static_cast<_typeT>(value);\
    \ }\n\n    static constexpr ModInt raw(KYOPRO_BASE_UINT _n) noexcept {\n     \
    \ ModInt _res;\n      _res.value = _n;\n      return _res;\n    }\n\n    constexpr\
    \ ModInt power(KYOPRO_BASE_UINT _n) const noexcept {\n      std::uint_fast64_t\
    \ _res = 1, _a = value;\n      while (_n > 0) {\n        if (_n & 1) _res = _res\
    \ * _a % _mod;\n        _a = _a * _a % _mod;\n        _n >>= 1;\n      }\n   \
    \   return _res;\n    }\n\n    constexpr ModInt inv() const noexcept {\n     \
    \ std::uint_fast64_t _a = value, _b = _mod;\n      std::int_fast64_t _u = 1, _v\
    \ = 0;\n      while (_b > 0) {\n        std::uint_fast64_t _t = _a / _b;\n   \
    \     _a -= _t * _b;\n        std::swap(_a, _b);\n        _u -= _t * _v;\n   \
    \     std::swap(_u, _v);\n      }\n      return floor_mod(_u, _mod);\n    }\n\n\
    \    constexpr ModInt operator +() const noexcept { return *this; }\n\n    constexpr\
    \ ModInt operator -() const noexcept { return _mod - value; }\n\n    constexpr\
    \ ModInt& operator ++() noexcept {\n      if (++value >= _mod) value -= _mod;\n\
    \      return *this;\n    }\n\n    constexpr ModInt operator ++(int) noexcept\
    \ {\n      ModInt _before = *this;\n      operator ++();\n      return _before;\n\
    \    }\n\n    constexpr ModInt& operator --() noexcept {\n      if (value == 0)\
    \ value = _mod;\n      --value;\n      return *this;\n    }\n\n    constexpr ModInt\
    \ operator --(int) noexcept {\n      ModInt _before = *this;\n      operator --();\n\
    \      return _before;\n    }\n\n    constexpr ModInt& operator +=(ModInt _rhs)\
    \ noexcept {\n      if ((value += _rhs.value) >= _mod) value -= _mod;\n      return\
    \ *this;\n    }\n\n    constexpr ModInt& operator -=(ModInt _rhs) noexcept {\n\
    \      if (value < _rhs.value) value += _mod;\n      value -= _rhs.value;\n  \
    \    return *this;\n    }\n\n    constexpr ModInt& operator *=(ModInt _rhs) noexcept\
    \ {\n      value = static_cast<decltype(_get_value_type().second)>(value) * _rhs.value\
    \ % _mod;\n      return *this;\n    }\n\n    constexpr ModInt& operator /=(ModInt\
    \ _rhs) noexcept {\n      value = static_cast<decltype(_get_value_type().second)>(value)\
    \ * _rhs.inv().value % _mod;\n      return *this;\n    }\n\n    friend constexpr\
    \ ModInt operator +(ModInt _lhs, ModInt _rhs) noexcept { return _lhs += _rhs;\
    \ }\n\n    friend constexpr ModInt operator -(ModInt _lhs, ModInt _rhs) noexcept\
    \ { return _lhs -= _rhs; }\n\n    friend constexpr ModInt operator *(ModInt _lhs,\
    \ ModInt _rhs) noexcept { return _lhs *= _rhs; }\n\n    friend constexpr ModInt\
    \ operator /(ModInt _lhs, ModInt _rhs) noexcept { return _lhs /= _rhs; }\n\n \
    \   friend constexpr bool operator ==(ModInt _lhs, ModInt _rhs) noexcept { return\
    \ _lhs.value == _rhs.value; }\n\n    friend constexpr bool operator !=(ModInt\
    \ _lhs, ModInt _rhs) noexcept { return _lhs.value != _rhs.value; }\n\n    template<class\
    \ _typeScanner>\n    void scan(_typeScanner& _scanner) {\n      std::int_fast64_t\
    \ _value;\n      _scanner.scan(_value);\n      value = floor_mod(_value, _mod);\n\
    \    }\n\n    template<class _typePrinter>\n    void print(_typePrinter& _printer)\
    \ const {\n      _printer.print(value);\n    }\n  };\n\n  template<KYOPRO_BASE_UINT\
    \ _mod>\n  struct Hash<ModInt<_mod>> { constexpr std::size_t operator ()(ModInt<_mod>\
    \ _a) const noexcept { return static_cast<std::size_t>(_a); } };\n}\n#line 6 \"\
    math/modpow.hpp\"\n\nnamespace kyopro {\n  template<class _typeT>\n  constexpr\
    \ _typeT modpow(_typeT _a, KYOPRO_BASE_UINT _n, KYOPRO_BASE_UINT _mod) noexcept\
    \ {\n    static_assert(std::is_integral_v<_typeT>);\n    std::uint_fast64_t _b\
    \ = floor_mod(_a, static_cast<_typeT>(_mod));\n    std::uint_fast64_t _res = 1;\n\
    \    while (_n > 0) {\n      if (_n & 1) _res = _res * _b % _mod;\n      _b =\
    \ _b * _b % _mod;\n      _n >>= 1;\n    }\n    return static_cast<_typeT>(_res);\n\
    \  }\n}\n#line 4 \"math/monoid.hpp\"\n\nnamespace kyopro {\n  template<class _typeT,\
    \ _typeT _id = 0>\n  struct Plus {\n    static_assert(std::is_arithmetic_v<_typeT>);\n\
    \    static constexpr _typeT id = _id;\n    constexpr _typeT operator ()(_typeT\
    \ _a, _typeT _b) const noexcept { return _a + _b; }\n    constexpr _typeT inv(_typeT\
    \ _a) const noexcept { return -_a; }\n  };\n  template<class _typeT, _typeT _id\
    \ = 1>\n  struct Mul {\n    static_assert(std::is_arithmetic_v<_typeT>);\n   \
    \ static constexpr _typeT id = _id;\n    constexpr _typeT operator ()(_typeT _a,\
    \ _typeT _b) const noexcept { return _a * _b; }\n    constexpr _typeT inv(_typeT\
    \ _a) const noexcept {\n      static_assert(!std::is_integral_v<_typeT>);\n  \
    \    return 1 / _a;\n    }\n  };\n  template<class _typeT, _typeT _id = std::is_integral_v<_typeT>\
    \ ? -INF<_typeT> : -inf>\n  struct Max {\n    static_assert(std::is_arithmetic_v<_typeT>);\n\
    \    static constexpr _typeT id = _id;\n    constexpr _typeT operator ()(_typeT\
    \ _a, _typeT _b) const noexcept { return _a > _b ? _a : _b; }\n  };\n  template<class\
    \ _typeT, _typeT _id = std::is_integral_v<_typeT> ? INF<_typeT> : inf>\n  struct\
    \ Min {\n    static_assert(std::is_arithmetic_v<_typeT>);\n    static constexpr\
    \ _typeT id = _id;\n    constexpr _typeT operator ()(_typeT _a, _typeT _b) const\
    \ noexcept { return _a < _b ? _a : _b; }\n  };\n}\n#line 2 \"system/in.hpp\"\n\
    #include <unistd.h>\n#line 6 \"system/in.hpp\"\n#include <cstdio>\n#include <string>\n\
    #line 14 \"system/in.hpp\"\n\nnamespace kyopro {\n  template<KYOPRO_BASE_UINT\
    \ _buf_size = KYOPRO_BUFFER_SIZE>\n  struct Reader {\n  private:\n    int _fd,\
    \ _idx;\n    std::array<char, _buf_size> _buffer;\n\n  public:\n    Reader() {\n\
    \      read(_fd, _buffer.begin(), _buf_size);\n    }\n    Reader(int _fd): _fd(_fd),\
    \ _idx(0), _buffer() {\n      read(_fd, _buffer.begin(), _buf_size);\n    }\n\
    \    Reader(FILE* _fp): _fd(fileno(_fp)), _idx(0), _buffer() {\n      read(_fd,\
    \ _buffer.begin(), _buf_size);\n    }\n\n    struct iterator {\n    private:\n\
    \      Reader& _reader;\n\n    public:\n      using difference_type = void;\n\
    \      using value_type = void;\n      using pointer = void;\n      using reference\
    \ = void;\n      using iterator_category = std::input_iterator_tag;\n\n      iterator()\
    \ noexcept = default;\n      iterator(Reader& _reader) noexcept: _reader(_reader)\
    \ {}\n\n      iterator& operator ++() {\n        ++_reader._idx;\n        if (_reader._idx\
    \ == _buf_size) {\n          read(_reader._fd, _reader._buffer.begin(), _buf_size);\n\
    \          _reader._idx = 0;\n        }\n        return *this;\n      }\n\n  \
    \    iterator operator ++(int) {\n        iterator _before = *this;\n        operator\
    \ ++();\n        return _before;\n      }\n\n      char& operator *() const {\n\
    \        return _reader._buffer[_reader._idx];\n      }\n    };\n\n    iterator\
    \ begin() noexcept {\n      return iterator(*this);\n    }\n  };\n\n  Reader input(0);\n\
    \n  template<class _typeIterator, KYOPRO_BASE_UINT _decimal_precision = KYOPRO_DECIMAL_PRECISION>\n\
    \  struct Scanner {\n  private:\n    template<class, class = void>\n    struct\
    \ _has_scan: std::false_type {};\n    template<class _typeT>\n    struct _has_scan<_typeT,\
    \ std::void_t<decltype(std::declval<_typeT>().scan(std::declval<Scanner&>()))>>:\
    \ std::true_type {};\n\n  public:\n    static constexpr KYOPRO_BASE_UINT decimal_precision\
    \ = _decimal_precision;\n    _typeIterator itr;\n\n    Scanner() noexcept = default;\n\
    \    Scanner(_typeIterator _itr) noexcept: itr(_itr) {}\n\n    void discard_space()\
    \ {\n      while (('\\t' <= *itr && *itr <= '\\r') || *itr == ' ') ++itr;\n  \
    \  }\n\n    void scan(char& _a) {\n      discard_space();\n      _a = *itr;\n\
    \      ++itr;\n    }\n    void scan(std::string& _a) {\n      discard_space();\n\
    \      for (auto& _i: _a) {\n        _i = *itr;\n        ++itr;\n      }\n   \
    \ }\n    void scan(bool& _a) {\n      discard_space();\n      while ('0' <= *itr\
    \ && *itr <= '9') {\n        if (*itr != '0') _a = true;\n        ++itr;\n   \
    \   }\n    }\n    template<class _typeT, std::enable_if_t<std::is_arithmetic_v<_typeT>\
    \ && !_has_scan<_typeT>::value>* = nullptr>\n    void scan(_typeT& _a) {\n   \
    \   discard_space();\n      bool _sgn = false;\n      if constexpr (!std::is_unsigned_v<_typeT>)\
    \ if (*itr == '-') {\n        _sgn = true;\n        ++itr;\n      }\n      _a\
    \ = 0;\n      for (; '0' <= *itr && *itr <= '9'; ++itr) _a = _a * 10 + *itr -\
    \ '0';\n      if (*itr == '.') {\n        ++itr;\n        if constexpr (std::is_floating_point_v<_typeT>)\
    \ {\n          constexpr std::uint_fast64_t _power_decimal_precision = power(10ULL,\
    \ _decimal_precision);\n          _typeT _d = 0;\n          std::uint_fast64_t\
    \ _i = 1;\n          for (; '0' <= *itr && *itr <= '9' && _i < _power_decimal_precision;\
    \ _i *= 10) {\n            _d = _d * 10 + *itr - '0';\n            ++itr;\n  \
    \        }\n          _a += _d / _i;\n        }\n        while ('0' <= *itr &&\
    \ *itr <= '9') ++itr;\n      }\n      if constexpr (!std::is_unsigned_v<_typeT>)\
    \ if (_sgn) _a = -_a;\n    }\n    template<std::size_t _i = 0, class _typeT, std::enable_if_t<is_tuple_v<_typeT>\
    \ && !_has_scan<_typeT>::value>* = nullptr>\n    void scan(_typeT& _a) {\n   \
    \   if constexpr (_i < std::tuple_size_v<_typeT>) {\n        scan(std::get<_i>(_a));\n\
    \        scan<_i + 1>(_a);\n      }\n    }\n    template<class _typeT, std::enable_if_t<is_iterable_v<_typeT>\
    \ && !_has_scan<_typeT>::value>* = nullptr>\n    void scan(_typeT& _a) {\n   \
    \   for (auto& _i: _a) scan(_i);\n    }\n    template<class _typeT, std::enable_if_t<_has_scan<_typeT>::value>*\
    \ = nullptr>\n    void scan(_typeT& _a) {\n      _a.scan(*this);\n    }\n\n  \
    \  void operator ()() {}\n    template<class _typeHead, class... _typeArgs>\n\
    \    void operator ()(_typeHead& _head, _typeArgs&... _args) {\n      scan(_head);\n\
    \      operator ()(_args...);\n    }\n  };\n\n  Scanner<Reader<>::iterator> scan(input.begin());\n\
    }\n#line 13 \"system/out.hpp\"\n\nnamespace kyopro {\n  template<KYOPRO_BASE_UINT\
    \ _buf_size = KYOPRO_BUFFER_SIZE>\n  struct Writer {\n  private:\n    int _fd,\
    \ _idx;\n    std::array<char, _buf_size> _buffer;\n\n  public:\n    Writer() noexcept\
    \ = default;\n    Writer(int _fd) noexcept: _fd(_fd), _idx(0), _buffer() {}\n\
    \    Writer(FILE* _fp) noexcept: _fd(fileno(_fp)), _idx(0), _buffer() {}\n\n \
    \   ~Writer() {\n      write(_fd, _buffer.begin(), _idx);\n    }\n\n    struct\
    \ iterator {\n    private:\n      Writer& _writer;\n\n    public:\n      using\
    \ difference_type = void;\n      using value_type = void;\n      using pointer\
    \ = void;\n      using reference = void;\n      using iterator_category = std::output_iterator_tag;\n\
    \n      iterator() noexcept = default;\n      iterator(Writer& _writer) noexcept:\
    \ _writer(_writer) {}\n\n      iterator& operator ++() {\n        ++_writer._idx;\n\
    \        if (_writer._idx == _buf_size) {\n          write(_writer._fd, _writer._buffer.begin(),\
    \ _buf_size);\n          _writer._idx = 0;\n        }\n        return *this;\n\
    \      }\n\n      iterator operator ++(int) {\n        iterator _before = *this;\n\
    \        operator ++();\n        return _before;\n      }\n\n      char& operator\
    \ *() const {\n        return _writer._buffer[_writer._idx];\n      }\n\n    \
    \  void flush() const {\n        write(_writer._fd, _writer._buffer.begin(), _writer._idx);\n\
    \      }\n    };\n\n    iterator begin() noexcept {\n      return iterator(*this);\n\
    \    }\n  };\n\n  Writer output(1), error(2);\n\n  template<class _typeIterator,\
    \ bool _sep = true, bool _end = true, bool _debug = false, bool _comment = false,\
    \ bool _flush = false, KYOPRO_BASE_UINT _decimal_precision = KYOPRO_DECIMAL_PRECISION>\n\
    \  struct Printer {\n  private:\n    template<class, class = void>\n    struct\
    \ _has_print: std::false_type {};\n    template<class _typeT>\n    struct _has_print<_typeT,\
    \ std::void_t<decltype(std::declval<_typeT>().print(std::declval<Printer&>()))>>:\
    \ std::true_type {};\n\n    void _print_sep() {\n      if constexpr (_debug) {\n\
    \        print(',');\n      }\n      print(' ');\n    }\n\n  public:\n    static\
    \ constexpr bool sep = _sep, end = _end, debug = _debug, flush = _flush;\n   \
    \ static constexpr KYOPRO_BASE_UINT decimal_precision = _decimal_precision;\n\n\
    \    _typeIterator itr;\n\n    Printer() noexcept = default;\n    Printer(_typeIterator\
    \ _itr) noexcept: itr(_itr) {}\n\n    void print(char _a) {\n      *itr = _a;\n\
    \      ++itr;\n    }\n    void print(const char* _a) {\n      for (; *_a; ++_a)\
    \ print(*_a);\n    }\n    void print(const std::string& _a) {\n      for (auto\
    \ _i: _a) print(_i);\n    }\n    void print(bool _a) {\n      print(static_cast<char>('0'\
    \ + _a));\n    }\n    template<class _typeT, std::enable_if_t<std::is_arithmetic_v<_typeT>\
    \ && !_has_print<_typeT>::value>* = nullptr>\n    void print(_typeT _a) {\n  \
    \    if constexpr (std::is_signed_v<_typeT>) if (_a < 0) {\n        print('-');\n\
    \        _a = -_a;\n      }\n      std::uint_fast64_t _p = _a;\n      _a -= _p;\n\
    \      std::string _s;\n      do {\n        _s += '0' + _p % 10;\n        _p /=\
    \ 10;\n      } while (_p > 0);\n      for (auto _i = _s.rbegin(); _i != _s.rend();\
    \ ++_i) print(*_i);\n      if constexpr (std::is_integral_v<_typeT>) return;\n\
    \      print('.');\n      for (int _i = 0; _i < static_cast<int>(_decimal_precision);\
    \ ++_i) {\n        _a *= 10;\n        print('0' + static_cast<std::uint_fast64_t>(_a)\
    \ % 10);\n      }\n    }\n    template<std::size_t _i = 0, class _typeT, std::enable_if_t<is_tuple_v<_typeT>\
    \ && !_has_print<_typeT>::value>* = nullptr>\n    void print(const _typeT& _a)\
    \ {\n      if constexpr (_debug && _i == 0) print('{');\n      if constexpr (std::tuple_size_v<_typeT>\
    \ != 0) print(std::get<_i>(_a));\n      if constexpr (_i + 1 < std::tuple_size_v<_typeT>)\
    \ {\n        if constexpr (_sep) _print_sep();\n        print<_i + 1>(_a);\n \
    \     } else if constexpr (_debug) print('}');\n    }\n    template<class _typeT,\
    \ std::enable_if_t<is_iterable_v<_typeT> && !_has_print<_typeT>::value>* = nullptr>\n\
    \    void print(const _typeT& _a) {\n      if constexpr (_debug) print('{');\n\
    \      if (std::empty(_a)) return;\n      for (auto _i = std::begin(_a); ; ) {\n\
    \        print(*_i);\n        if (++_i != std::end(_a)) {\n          if constexpr\
    \ (_sep) {\n            if constexpr (_debug) {\n              print(',');\n \
    \             print(' ');\n            } else if constexpr (std::is_arithmetic_v<std::decay_t<decltype(std::declval<_typeT>()[0])>>)\
    \ print(' ');\n            else print('\\n');\n          }\n        } else break;\n\
    \      }\n      if constexpr (_debug) print('}');\n    }\n    template<class _typeT,\
    \ std::enable_if_t<_has_print<_typeT>::value>* = nullptr>\n    void print(const\
    \ _typeT& _a) {\n      _a.print(*this);\n    }\n\n    template<bool _first = true>\n\
    \    void operator ()() {\n      if constexpr (_comment && _first) print('#');\n\
    \      if constexpr (_end) print('\\n');\n      if constexpr (_flush) itr._flush();\n\
    \    }\n    template<bool _first = true, class _typeHead, class... _typeArgs>\n\
    \    void operator ()(_typeHead&& _head, _typeArgs&&... _args) {\n      if constexpr\
    \ (_comment && _first) print('#');\n      if constexpr (_sep && !_first) _print_sep();\n\
    \      print(_head);\n      operator ()<false>(std::forward<_typeArgs>(_args)...);\n\
    \    }\n  };\n\n  Printer<Writer<>::iterator, false, false> print(output.begin()),\
    \ eprint(error.begin());\n  Printer<Writer<>::iterator> println(output.begin()),\
    \ eprintln(error.begin());\n  Printer<Writer<>::iterator, true, true, true, true>\
    \ debug(output.begin()), edebug(error.begin());\n}\n#line 8 \"template/alias.hpp\"\
    \n#include <set>\n#include <map>\n#include <unordered_set>\n#include <unordered_map>\n\
    #line 17 \"template/alias.hpp\"\n\nnamespace kyopro {\n  using ll = long long;\n\
    \  using ull = unsigned long long;\n  using lf = double;\n\n  using i8 = std::int8_t;\n\
    \  using u8 = std::uint8_t;\n  using i16 = std::int16_t;\n  using u16 = std::uint16_t;\n\
    \  using i32 = std::int32_t;\n  using u32 = std::uint32_t;\n  using i64 = std::int64_t;\n\
    \  using u64 = std::uint64_t;\n  using i128 = __int128_t;\n  using u128 = __uint128_t;\n\
    \  #ifdef __SIZEOF_FLOAT128__\n  using f128 = __float128;\n  #endif\n\n  using\
    \ mint = ModInt<mod>;\n  using dmint = DynamicModInt;\n\n  template<class _typeKey>\n\
    \  using hset = std::unordered_set<_typeKey, Hash<_typeKey>>;\n  template<class\
    \ _typeKey, class _typeT>\n  using hmap = std::unordered_map<_typeKey, _typeT,\
    \ Hash<_typeKey>>;\n  template<class _typeKey>\n  using hmultiset = std::unordered_multiset<_typeKey,\
    \ Hash<_typeKey>>;\n  template<class _typeKey, class _typeT>\n  using hmultimap\
    \ = std::unordered_multimap<_typeKey, _typeT, Hash<_typeKey>>;\n  template<class\
    \ _typeT, class _typeCompare = std::less<_typeT>, class _typeContainer = std::vector<_typeT>>\n\
    \  using priq = std::priority_queue<_typeT, _typeContainer, _typeCompare>;\n \
    \ template<class _typeT, class _typeCompare = std::greater<_typeT>, class _typeContainer\
    \ = std::vector<_typeT>>\n  using heapq = priq<_typeT, _typeContainer, _typeCompare>;\n\
    }\n\nusing namespace std;\nusing namespace kyopro;\n#line 7 \"all.hpp\"\n"
  code: '#pragma once

    #include "algorithm/all.hpp"

    #include "math/all.hpp"

    #include "meta/all.hpp"

    #include "system/all.hpp"

    #include "template/all.hpp"'
  dependsOn:
  - algorithm/all.hpp
  - algorithm/Hash.hpp
  - meta/settings.hpp
  - meta/trait.hpp
  - math/all.hpp
  - math/Barrett.hpp
  - math/div.hpp
  - math/divisors.hpp
  - math/DynamicModInt.hpp
  - meta/constant.hpp
  - math/power.hpp
  - math/mod.hpp
  - math/euler_phi.hpp
  - math/factorize.hpp
  - math/is_prime.hpp
  - math/ModInt.hpp
  - math/modpow.hpp
  - math/monoid.hpp
  - meta/all.hpp
  - system/all.hpp
  - system/in.hpp
  - system/out.hpp
  - template/all.hpp
  - template/alias.hpp
  isVerificationFile: false
  path: all.hpp
  requiredBy: []
  timestamp: '2022-03-17 14:38:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: all.hpp
layout: document
redirect_from:
- /library/all.hpp
- /library/all.hpp.html
title: all.hpp
---
