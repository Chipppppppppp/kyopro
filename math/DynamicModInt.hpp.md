---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: algorithm/Hash.hpp
    title: algorithm/Hash.hpp
  - icon: ':warning:'
    path: algorithm/bit.hpp
    title: algorithm/bit.hpp
  - icon: ':warning:'
    path: math/Barrett.hpp
    title: math/Barrett.hpp
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
  _extendedRequiredBy:
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
  bundledCode: "#line 2 \"math/DynamicModInt.hpp\"\n#include <cassert>\n#include <cstdint>\n\
    #include <type_traits>\n#line 2 \"algorithm/Hash.hpp\"\n#include <cstddef>\n#line\
    \ 4 \"algorithm/Hash.hpp\"\n#include <functional>\n#include <initializer_list>\n\
    #include <tuple>\n#line 8 \"algorithm/Hash.hpp\"\n#include <utility>\n#line 3\
    \ \"meta/settings.hpp\"\n\n#ifndef KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT std::int64_t\n\
    #endif\n\n#ifndef KYOPRO_BASE_UINT\n#define KYOPRO_BASE_UINT std::uint64_t\n#endif\n\
    \n#ifndef KYOPRO_BASE_FLOAT\n#define KYOPRO_BASE_FLOAT double\n#endif\n\n#ifndef\
    \ KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD static_cast<KYOPRO_BASE_UINT>(998244353)\n\
    #endif\n\n#ifndef KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n\
    #endif\n\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 2 \"meta/trait.hpp\"\n#include <iterator>\n#include <queue>\n#include\
    \ <limits>\n#include <stack>\n#line 9 \"meta/trait.hpp\"\n\ntemplate<>\nstruct\
    \ std::is_integral<__int128_t>: std::true_type {};\ntemplate<>\nstruct std::is_signed<__int128_t>:\
    \ std::true_type {};\ntemplate<>\nstruct std::is_integral<__uint128_t>: std::true_type\
    \ {};\ntemplate<>\nstruct std::is_unsigned<__uint128_t>: std::true_type {};\n\
    #ifdef __SIZEOF_FLOAT128__\ntemplate<>\nstruct std::is_floating_point<__float128>:\
    \ std::true_type {};\n#endif\n\nnamespace kyopro {\n  template<KYOPRO_BASE_UINT\
    \ _size>\n  struct int_least {\n  private:\n    static constexpr auto _get_type()\
    \ noexcept {\n      if constexpr (_size <= 8) return std::declval<std::int_least8_t>();\n\
    \      if constexpr (_size <= 16) return std::declval<std::int_least16_t>();\n\
    \      if constexpr (_size <= 32) return std::declval<std::int_least32_t>();\n\
    \      if constexpr (_size <= 64) return std::declval<std::int_least64_t>();\n\
    \      static_assert(_size <= 128, \"Integer size is too long\");\n      return\
    \ std::declval<__int128_t>();\n    }\n\n  public:\n    using type = decltype(_get_type());\n\
    \  };\n\n  template<KYOPRO_BASE_UINT _size>\n  using int_least_t = typename int_least<_size>::type;\n\
    \n  template<KYOPRO_BASE_UINT _size>\n  struct uint_least {\n  private:\n    static\
    \ constexpr auto _get_type() noexcept {\n      if constexpr (_size <= 8) return\
    \ std::declval<std::uint_least8_t>();\n      if constexpr (_size <= 16) return\
    \ std::declval<std::uint_least16_t>();\n      if constexpr (_size <= 32) return\
    \ std::declval<std::uint_least32_t>();\n      if constexpr (_size <= 64) return\
    \ std::declval<std::uint_least64_t>();\n      static_assert(_size <= 128, \"Integer\
    \ size is too long\");\n      return std::declval<__uint128_t>();\n    }\n\n \
    \ public:\n    using type = decltype(_get_type());\n  };\n\n  template<KYOPRO_BASE_UINT\
    \ _size>\n  using uint_least_t = typename uint_least<_size>::type;\n\n  template<class,\
    \ class = void>\n  struct is_iterator: std::false_type {};\n  template<class _typeT>\n\
    \  struct is_iterator<_typeT, std::void_t<typename std::iterator_traits<_typeT>::iterator_category>>:\
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
    \ >> 4);\n      return _seed;\n    }\n  };\n}\n#line 2 \"meta/constant.hpp\"\n\
    #include <array>\n#line 3 \"math/power.hpp\"\n\nnamespace kyopro {\n  template<class\
    \ _typeT>\n  constexpr _typeT power(_typeT _a, KYOPRO_BASE_UINT _n, _typeT _init\
    \ = 1) noexcept {\n    while (_n > 0) {\n      if (_n & 1) _init *= _a;\n    \
    \  _a *= _a;\n      _n >>= 1;\n    }\n    return _init;\n  }\n}\n#line 7 \"meta/constant.hpp\"\
    \n\nnamespace kyopro {\n  template<class _typeT>\n  inline constexpr _typeT MOD\
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
    \ -1}, {0, -1}, {1, -1}}};\n}\n#line 2 \"math/Barrett.hpp\"\n\n#line 5 \"algorithm/bit.hpp\"\
    \n\nnamespace kyopro {\n  template<class _typeT>\n  constexpr KYOPRO_BASE_INT\
    \ pop_count(_typeT _x) noexcept {\n    constexpr auto _digits = std::numeric_limits<std::make_unsigned_t<_typeT>>::digits;\n\
    \    static_assert(_digits <= std::numeric_limits<unsigned long long>::digits,\
    \ \"Integer size is too long\");\n    if constexpr (_digits <= std::numeric_limits<unsigned\
    \ int>::digits) return __builtin_popcount(_x);\n    else if constexpr (_digits\
    \ <= std::numeric_limits<unsigned long>::digits) return __builtin_popcountl(_x);\n\
    \    else return __builtin_popcountll(_x);\n  }\n\n  template<class _typeT>\n\
    \  constexpr KYOPRO_BASE_INT leading_zero(_typeT _x) noexcept {\n    constexpr\
    \ auto _digits = std::numeric_limits<std::make_unsigned_t<_typeT>>::digits;\n\
    \    static_assert(_digits <= std::numeric_limits<unsigned long long>::digits,\
    \ \"Integer size is too long\");\n    if (_x == 0) return 0;\n    if constexpr\
    \ (_digits <= std::numeric_limits<unsigned int>::digits) return __builtin_clz(_x)\
    \ + _digits - std::numeric_limits<unsigned int>::digits;\n    else if constexpr\
    \ (_digits <= std::numeric_limits<unsigned long>::digits) return __builtin_clzl(_x)\
    \ + _digits - std::numeric_limits<unsigned long>::digits;\n    else return __builtin_clzll(_x)\
    \ + _digits - std::numeric_limits<unsigned long long>::digits;\n  }\n\n  template<class\
    \ _typeT>\n  constexpr KYOPRO_BASE_INT trailing_zero(_typeT _x) noexcept {\n \
    \   constexpr auto _digits = std::numeric_limits<std::make_unsigned_t<_typeT>>::digits;\n\
    \    static_assert(_digits <= std::numeric_limits<unsigned long long>::digits,\
    \ \"Integer size is too long\");\n    if constexpr (_digits <= std::numeric_limits<unsigned\
    \ int>::digits) return __builtin_ctz(_x);\n    else if constexpr (_digits <= std::numeric_limits<unsigned\
    \ long>::digits) return __builtin_ctzl(_x);\n    else return __builtin_ctzll(_x);\n\
    \  }\n\n  template<class _typeT>\n  constexpr KYOPRO_BASE_INT bit_len(_typeT _x)\
    \ noexcept {\n    constexpr auto _digits = std::numeric_limits<std::make_unsigned_t<_typeT>>::digits;\n\
    \    static_assert(_digits <= std::numeric_limits<unsigned long long>::digits,\
    \ \"Integer size is too long\");\n    if (_x == 0) return 0;\n    if constexpr\
    \ (_digits <= std::numeric_limits<unsigned int>::digits) return std::numeric_limits<unsigned\
    \ int>::digits - __builtin_clz(_x);\n    else if constexpr (_digits <= std::numeric_limits<unsigned\
    \ long>::digits) return std::numeric_limits<unsigned long>::digits - __builtin_clzl(_x);\n\
    \    else return std::numeric_limits<unsigned long long>::digits - __builtin_clzll(_x);\n\
    \  }\n\n  template<class _typeT>\n  constexpr KYOPRO_BASE_INT floor_bit(_typeT\
    \ _x) noexcept {\n    return bit_len(_x >> static_cast<_typeT>(1));\n  }\n\n \
    \ template<class _typeT>\n  constexpr KYOPRO_BASE_INT ceil_bit(_typeT _x) noexcept\
    \ {\n    if (_x == 0) return 0;\n    return bit_len(_x - static_cast<_typeT>(1));\n\
    \  }\n}\n#line 9 \"math/Barrett.hpp\"\n\ntemplate<class _typeT>\nstruct Barrett\
    \ {\n  static_assert(std::is_unsigned_v<_typeT>, \"Unsigned integer is required\"\
    );\n\nprivate:\n  using _mul_value_type = uint_least_t<std::numeric_limits<std::make_unsigned_t<_typeT>>::digits\
    \ * 2>;\n  _typeT _mod;\n  _mul_value_type _m;\n\npublic:\n  using value_type\
    \ = _typeT;\n\n  constexpr void set_mod(_typeT _mod) noexcept {\n    this->_mod\
    \ = _mod;\n    _m = (static_cast<_mul_value_type>(1) << 64) / _mod;\n  }\n\n \
    \ constexpr KYOPRO_BASE_INT get_mod() const noexcept {\n    return _mod;\n  }\n\
    \n  Barrett() noexcept = default;\n  Barrett(KYOPRO_BASE_UINT _mod) noexcept:\
    \ _mod(_mod), _m((static_cast<_mul_value_type>(1) << 64) / _mod) {}\n\n  constexpr\
    \ KYOPRO_BASE_UINT operator ()(KYOPRO_BASE_UINT _x) const noexcept {\n\t  _x -=\
    \ static_cast<_typeT>((_x * _m) >> 64) * _mod;\n    return _x < _mod ? _x : _x\
    \ - _mod;\n  }\n};\n#line 4 \"math/mod.hpp\"\n\nnamespace kyopro {\n  template<class\
    \ _typeT, class _typeU>\n  constexpr std::common_type_t<_typeT, _typeU> floor_mod(_typeT\
    \ _x, _typeU _m) noexcept {\n    static_assert(std::is_integral_v<_typeT> && std::is_integral_v<_typeU>);\n\
    \    if constexpr (std::is_unsigned_v<_typeT> || std::is_unsigned_v<_typeU>) return\
    \ _x % _m;\n    return (_x %= _m) < 0 ? _x + _m : _x;\n  }\n\n  template<class\
    \ _typeT, class _typeU>\n  constexpr std::common_type_t<_typeT, _typeU> ceil_mod(_typeT\
    \ _x, _typeU _m) noexcept {\n    return _m - floor_mod(_x - 1, _m) - static_cast<_typeT>(1);\n\
    \  }\n}\n#line 10 \"math/DynamicModInt.hpp\"\n\nnamespace kyopro {\n  template<class\
    \ _typeT>\n  struct DynamicModInt {\n    static_assert(std::is_unsigned_v<_typeT>,\
    \ \"Unsigned integer is required\");\n\n  private:\n    inline static _typeT _mod;\n\
    \    inline static Barrett<_typeT> _barrett;\n\n  public:\n    _typeT value;\n\
    \n    static void set_mod(_typeT _m) noexcept {\n      _mod = _m;\n      _barrett.set_mod(_m);\n\
    \    }\n\n    static KYOPRO_BASE_INT get_mod() noexcept {\n      return _mod;\n\
    \    }\n\n    DynamicModInt() noexcept = default;\n    DynamicModInt(_typeT _value)\
    \ noexcept: value(floor_mod(_value, _mod)) {}\n\n    template<class _typeU>\n\
    \    explicit operator _typeU() const noexcept { return value; }\n\n    static\
    \ DynamicModInt raw(_typeT _n) noexcept {\n      DynamicModInt _res;\n      _res.value\
    \ = _n;\n      return _res;\n    }\n\n    DynamicModInt power(_typeT _n) const\
    \ noexcept {\n      _typeT _res = 1, _a = value;\n      while (_n > 0) {\n   \
    \     if (_n & 1) _res = _res * _a % _mod;\n        _a = _a * _a % _mod;\n   \
    \     _n >>= 1;\n      }\n      return _res;\n    }\n\n    DynamicModInt inv()\
    \ const noexcept {\n      _typeT _a = value, _b = _mod;\n      std::make_signed_t<_typeT>\
    \ _u = 1, _v = 0;\n      while (_b > 0) {\n        _typeT _t = _a / _b;\n    \
    \    _a -= _t * _b;\n        std::swap(_a, _b);\n        _u -= _t * _v;\n    \
    \    std::swap(_u, _v);\n      }\n      return floor_mod(_u, _mod);\n    }\n\n\
    \    DynamicModInt operator +() const noexcept { return *this; }\n\n    DynamicModInt\
    \ operator -() const noexcept { return _mod - value; }\n\n    DynamicModInt& operator\
    \ ++() noexcept {\n      if (++value >= _mod) value -= _mod;\n      return *this;\n\
    \    }\n\n    DynamicModInt operator ++(int) noexcept {\n      DynamicModInt _before\
    \ = *this;\n      operator ++();\n      return _before;\n    }\n\n    DynamicModInt&\
    \ operator --() noexcept {\n      if (value == 0) value = _mod;\n      --value;\n\
    \      return *this;\n    }\n\n    DynamicModInt operator --(int) noexcept {\n\
    \      DynamicModInt _before = *this;\n      operator --();\n      return _before;\n\
    \    }\n\n    DynamicModInt& operator +=(DynamicModInt _rhs) noexcept {\n    \
    \  if ((value += _rhs.value) >= _mod) value -= _mod;\n      return *this;\n  \
    \  }\n\n    DynamicModInt& operator -=(DynamicModInt _rhs) noexcept {\n      if\
    \ (value < _rhs.value) value += _mod;\n      value -= _rhs.value;\n      return\
    \ *this;\n    }\n\n    DynamicModInt& operator *=(DynamicModInt _rhs) noexcept\
    \ {\n      value = _barrett(value * _rhs.value);\n      return *this;\n    }\n\
    \n    DynamicModInt& operator /=(DynamicModInt _rhs) noexcept {\n      value =\
    \ _barrett(value * _rhs.inv().value);\n      return *this;\n    }\n\n    friend\
    \ DynamicModInt operator +(DynamicModInt _lhs, DynamicModInt _rhs) noexcept {\
    \ return _lhs += _rhs; }\n\n    friend DynamicModInt operator -(DynamicModInt\
    \ _lhs, DynamicModInt _rhs) noexcept { return _lhs -= _rhs; }\n\n    friend DynamicModInt\
    \ operator *(DynamicModInt _lhs, DynamicModInt _rhs) noexcept { return _lhs *=\
    \ _rhs; }\n\n    friend DynamicModInt operator /(DynamicModInt _lhs, DynamicModInt\
    \ _rhs) noexcept { return _lhs /= _rhs; }\n\n    friend bool operator ==(DynamicModInt\
    \ _lhs, DynamicModInt _rhs) noexcept { return _lhs.value == _rhs.value; }\n\n\
    \    friend bool operator !=(DynamicModInt _lhs, DynamicModInt _rhs) noexcept\
    \ { return _lhs.value != _rhs.value; }\n\n    template<class _typeScanner>\n \
    \   void scan(_typeScanner& _scanner) {\n      std::make_signed_t<_typeT> _value;\n\
    \      _scanner.scan(_value);\n      value = floor_mod(_value, _mod);\n    }\n\
    \n    template<class _typePrinter>\n    void print(_typePrinter& _printer) const\
    \ {\n      _printer.print(value);\n    }\n  };\n\n  template<class _typeT>\n \
    \ struct Hash<DynamicModInt<_typeT>> { std::size_t operator ()(DynamicModInt<_typeT>\
    \ _a) const noexcept { return static_cast<std::size_t>(_a); } };\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <cstdint>\n#include <type_traits>\n\
    #include \"../algorithm/Hash.hpp\"\n#include \"../meta/constant.hpp\"\n#include\
    \ \"../meta/settings.hpp\"\n#include \"Barrett.hpp\"\n#include \"mod.hpp\"\n\n\
    namespace kyopro {\n  template<class _typeT>\n  struct DynamicModInt {\n    static_assert(std::is_unsigned_v<_typeT>,\
    \ \"Unsigned integer is required\");\n\n  private:\n    inline static _typeT _mod;\n\
    \    inline static Barrett<_typeT> _barrett;\n\n  public:\n    _typeT value;\n\
    \n    static void set_mod(_typeT _m) noexcept {\n      _mod = _m;\n      _barrett.set_mod(_m);\n\
    \    }\n\n    static KYOPRO_BASE_INT get_mod() noexcept {\n      return _mod;\n\
    \    }\n\n    DynamicModInt() noexcept = default;\n    DynamicModInt(_typeT _value)\
    \ noexcept: value(floor_mod(_value, _mod)) {}\n\n    template<class _typeU>\n\
    \    explicit operator _typeU() const noexcept { return value; }\n\n    static\
    \ DynamicModInt raw(_typeT _n) noexcept {\n      DynamicModInt _res;\n      _res.value\
    \ = _n;\n      return _res;\n    }\n\n    DynamicModInt power(_typeT _n) const\
    \ noexcept {\n      _typeT _res = 1, _a = value;\n      while (_n > 0) {\n   \
    \     if (_n & 1) _res = _res * _a % _mod;\n        _a = _a * _a % _mod;\n   \
    \     _n >>= 1;\n      }\n      return _res;\n    }\n\n    DynamicModInt inv()\
    \ const noexcept {\n      _typeT _a = value, _b = _mod;\n      std::make_signed_t<_typeT>\
    \ _u = 1, _v = 0;\n      while (_b > 0) {\n        _typeT _t = _a / _b;\n    \
    \    _a -= _t * _b;\n        std::swap(_a, _b);\n        _u -= _t * _v;\n    \
    \    std::swap(_u, _v);\n      }\n      return floor_mod(_u, _mod);\n    }\n\n\
    \    DynamicModInt operator +() const noexcept { return *this; }\n\n    DynamicModInt\
    \ operator -() const noexcept { return _mod - value; }\n\n    DynamicModInt& operator\
    \ ++() noexcept {\n      if (++value >= _mod) value -= _mod;\n      return *this;\n\
    \    }\n\n    DynamicModInt operator ++(int) noexcept {\n      DynamicModInt _before\
    \ = *this;\n      operator ++();\n      return _before;\n    }\n\n    DynamicModInt&\
    \ operator --() noexcept {\n      if (value == 0) value = _mod;\n      --value;\n\
    \      return *this;\n    }\n\n    DynamicModInt operator --(int) noexcept {\n\
    \      DynamicModInt _before = *this;\n      operator --();\n      return _before;\n\
    \    }\n\n    DynamicModInt& operator +=(DynamicModInt _rhs) noexcept {\n    \
    \  if ((value += _rhs.value) >= _mod) value -= _mod;\n      return *this;\n  \
    \  }\n\n    DynamicModInt& operator -=(DynamicModInt _rhs) noexcept {\n      if\
    \ (value < _rhs.value) value += _mod;\n      value -= _rhs.value;\n      return\
    \ *this;\n    }\n\n    DynamicModInt& operator *=(DynamicModInt _rhs) noexcept\
    \ {\n      value = _barrett(value * _rhs.value);\n      return *this;\n    }\n\
    \n    DynamicModInt& operator /=(DynamicModInt _rhs) noexcept {\n      value =\
    \ _barrett(value * _rhs.inv().value);\n      return *this;\n    }\n\n    friend\
    \ DynamicModInt operator +(DynamicModInt _lhs, DynamicModInt _rhs) noexcept {\
    \ return _lhs += _rhs; }\n\n    friend DynamicModInt operator -(DynamicModInt\
    \ _lhs, DynamicModInt _rhs) noexcept { return _lhs -= _rhs; }\n\n    friend DynamicModInt\
    \ operator *(DynamicModInt _lhs, DynamicModInt _rhs) noexcept { return _lhs *=\
    \ _rhs; }\n\n    friend DynamicModInt operator /(DynamicModInt _lhs, DynamicModInt\
    \ _rhs) noexcept { return _lhs /= _rhs; }\n\n    friend bool operator ==(DynamicModInt\
    \ _lhs, DynamicModInt _rhs) noexcept { return _lhs.value == _rhs.value; }\n\n\
    \    friend bool operator !=(DynamicModInt _lhs, DynamicModInt _rhs) noexcept\
    \ { return _lhs.value != _rhs.value; }\n\n    template<class _typeScanner>\n \
    \   void scan(_typeScanner& _scanner) {\n      std::make_signed_t<_typeT> _value;\n\
    \      _scanner.scan(_value);\n      value = floor_mod(_value, _mod);\n    }\n\
    \n    template<class _typePrinter>\n    void print(_typePrinter& _printer) const\
    \ {\n      _printer.print(value);\n    }\n  };\n\n  template<class _typeT>\n \
    \ struct Hash<DynamicModInt<_typeT>> { std::size_t operator ()(DynamicModInt<_typeT>\
    \ _a) const noexcept { return static_cast<std::size_t>(_a); } };\n}"
  dependsOn:
  - algorithm/Hash.hpp
  - meta/settings.hpp
  - meta/trait.hpp
  - meta/constant.hpp
  - math/power.hpp
  - math/Barrett.hpp
  - algorithm/bit.hpp
  - math/mod.hpp
  isVerificationFile: false
  path: math/DynamicModInt.hpp
  requiredBy:
  - math/all.hpp
  - template/all.hpp
  - template/alias.hpp
  - all/all.hpp
  timestamp: '2022-03-19 01:10:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/DynamicModInt.hpp
layout: document
redirect_from:
- /library/math/DynamicModInt.hpp
- /library/math/DynamicModInt.hpp.html
title: math/DynamicModInt.hpp
---
