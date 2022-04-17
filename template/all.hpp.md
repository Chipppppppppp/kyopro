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
  - icon: ':heavy_check_mark:'
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
    #include <functional>\n#include <utility>\n#include <vector>\n#include <string>\n\
    #include <set>\n#include <type_traits>\n#include <map>\n#include <unordered_set>\n\
    #include <unordered_map>\n#include <queue>\n#include <stack>\n#line 2 \"algorithm/Hash.hpp\"\
    \n#include <cstddef>\n#line 5 \"algorithm/Hash.hpp\"\n#include <initializer_list>\n\
    #include <tuple>\n#line 3 \"meta/settings.hpp\"\n\n#ifndef KYOPRO_BASE_INT\n#define\
    \ KYOPRO_BASE_INT std::int64_t\n#endif\n\n#ifndef KYOPRO_BASE_UINT\n#define KYOPRO_BASE_UINT\
    \ std::uint64_t\n#endif\n\n#ifndef KYOPRO_BASE_FLOAT\n#define KYOPRO_BASE_FLOAT\
    \ double\n#endif\n\n#ifndef KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD static_cast<KYOPRO_BASE_UINT>(998244353)\n\
    #endif\n\n#ifndef KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n\
    #endif\n\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 2 \"meta/trait.hpp\"\n#include <iterator>\n#line 9 \"meta/trait.hpp\"\
    \n\ntemplate<>\nstruct std::is_integral<__int128_t>: std::true_type {};\ntemplate<>\n\
    struct std::is_signed<__int128_t>: std::true_type {};\ntemplate<>\nstruct std::is_integral<__uint128_t>:\
    \ std::true_type {};\ntemplate<>\nstruct std::is_unsigned<__uint128_t>: std::true_type\
    \ {};\n#ifdef __SIZEOF_FLOAT128__\ntemplate<>\nstruct std::is_floating_point<__float128>:\
    \ std::true_type {};\n#endif\n\nnamespace kyopro {\n  template<KYOPRO_BASE_UINT\
    \ _size>\n  struct int_least {\n  private:\n    static constexpr auto _get_type()\
    \ noexcept {\n      static_assert(_size <= 128, \"Integer size is too long\");\n\
    \      if constexpr (_size <= 8) return std::int_least8_t();\n      else if constexpr\
    \ (_size <= 16) return std::int_least16_t();\n      else if constexpr (_size <=\
    \ 32) return std::int_least32_t();\n      else if constexpr (_size <= 64) return\
    \ std::int_least64_t();\n      else return __int128_t();\n    }\n\n  public:\n\
    \    using type = decltype(_get_type());\n  };\n\n  template<KYOPRO_BASE_UINT\
    \ _size>\n  using int_least_t = typename int_least<_size>::type;\n\n  template<KYOPRO_BASE_UINT\
    \ _size>\n  struct uint_least {\n  private:\n    static constexpr auto _get_type()\
    \ noexcept {\n      static_assert(_size <= 128, \"Integer size is too long\");\n\
    \      if constexpr (_size <= 8) return std::uint_least8_t();\n      else if constexpr\
    \ (_size <= 16) return std::uint_least16_t();\n      else if constexpr (_size\
    \ <= 32) return std::uint_least32_t();\n      else if constexpr (_size <= 64)\
    \ return std::uint_least64_t();\n      else return __uint128_t();\n    }\n\n \
    \ public:\n    using type = decltype(_get_type());\n  };\n\n  template<KYOPRO_BASE_UINT\
    \ _size>\n  using uint_least_t = typename uint_least<_size>::type;\n\n  template<class,\
    \ class = void>\n  struct is_iterator: std::false_type {};\n  template<class _typeT>\n\
    \  struct is_iterator<_typeT, std::void_t<typename std::iterator_traits<_typeT>::iterator_category>>:\
    \ std::true_type {};\n\n  template<class _typeT>\n  constexpr bool is_iterator_v\
    \ = is_iterator<_typeT>::value;\n\n  template<class, class = void>\n  struct is_range:\
    \ std::false_type {};\n  template<class _typeT>\n  struct is_range<_typeT, std::enable_if_t<is_iterator_v<decltype(std::begin(std::declval<_typeT>()))>>>:\
    \ std::true_type {};\n\n  template<class _typeT>\n  constexpr bool is_range_v\
    \ = is_range<_typeT>::value;\n\n  template<class>\n  struct is_tuple: std::false_type\
    \ {};\n  template<class _typeT, class _typeU>\n  struct is_tuple<std::pair<_typeT,\
    \ _typeU>>: std::true_type {};\n  template<class... _typeArgs>\n  struct is_tuple<std::tuple<_typeArgs...>>:\
    \ std::true_type {};\n\n  template<class _typeT>\n  constexpr bool is_tuple_v\
    \ = is_tuple<_typeT>::value;\n\n  template<class, class = void>\n  struct is_container_adapter:\
    \ std::false_type {};\n  template<class _typeT>\n  struct is_container_adapter<_typeT,\
    \ std::void_t<decltype(std::empty(std::declval<_typeT>()))>>: std::negation<is_range<_typeT>>\
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
    \n  template<class _typeT>\n  struct Hash<_typeT, std::enable_if_t<is_range_v<_typeT>>>\
    \ {\n  private:\n    [[no_unique_address]] Hash<decltype(*std::begin(std::declval<_typeT>()))>\
    \ _hasher;\n\n  public:\n    constexpr std::size_t operator ()(const _typeT& _a)\
    \ const noexcept {\n      std::uint_fast64_t _seed = _a.size();\n      for (auto&\
    \ _i: _a) _seed ^= _hasher(_i) + 0x9e3779b97f4a7c15LU + (_seed << 12) + (_seed\
    \ >> 4);\n      return _seed;\n    }\n  };\n}\n#line 2 \"math/DynamicModInt.hpp\"\
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
    \  inline constexpr KYOPRO_BASE_FLOAT pi = PI<KYOPRO_BASE_FLOAT>;\n}\n#line 4\
    \ \"math/mod.hpp\"\n\nnamespace kyopro {\n  template<class _typeT, class _typeU>\n\
    \  constexpr std::common_type_t<_typeT, _typeU> floor_mod(_typeT _x, _typeU _m)\
    \ noexcept {\n    static_assert(std::is_integral_v<_typeT> && std::is_integral_v<_typeU>,\
    \ \"Integer is required\");\n    if constexpr (std::is_unsigned_v<_typeT> || std::is_unsigned_v<_typeU>)\
    \ return _x % _m;\n    return (_x %= _m) < 0 ? _x + _m : _x;\n  }\n\n  template<class\
    \ _typeT, class _typeU>\n  constexpr std::common_type_t<_typeT, _typeU> ceil_mod(_typeT\
    \ _x, _typeU _m) noexcept {\n    return _m - floor_mod(_x - 1, _m) - static_cast<_typeT>(1);\n\
    \  }\n}\n#line 6 \"math/Montgomery.hpp\"\n\nnamespace kyopro {\n  template<class\
    \ _typeT>\n  struct Montgomery {\n    static_assert(std::is_unsigned_v<_typeT>,\
    \ \"Unsigned integer is required\");\n\n    _typeT mod;\n\n  private:\n    using\
    \ _larger_type = uint_least_t<std::numeric_limits<_typeT>::digits * 2>;\n\n  \
    \  _typeT _r, _n2;\n\n  public:\n    constexpr void set_mod(_typeT _mod) noexcept\
    \ {\n      mod = _mod;\n      _n2 = -static_cast<_larger_type>(mod) % mod;\n \
    \     _typeT _t = 0;\n      _r = 0;\n      for (int _i = 0; _i < std::numeric_limits<_typeT>::digits;\
    \ ++_i) {\n        if (!(_t & 1)) {\n          _t += mod;\n          _r += static_cast<_typeT>(1)\
    \ << static_cast<_typeT>(_i);\n        }\n        _t >>= 1;\n      }\n    }\n\n\
    \    constexpr KYOPRO_BASE_INT get_mod() const noexcept {\n      return mod;\n\
    \    }\n\n    Montgomery() noexcept = default;\n    Montgomery(_typeT _mod) noexcept\
    \ {\n      set_mod(_mod);\n    }\n\n    constexpr _typeT transform(_typeT _x)\
    \ const noexcept {\n      return reduce(static_cast<_larger_type>(_x) * _n2);\n\
    \    }\n\n    constexpr _typeT inverse_transform(_typeT _x) const noexcept {\n\
    \      return reduce(_x);\n    }\n\n    constexpr _typeT reduce(_larger_type _x)\
    \ const noexcept {\n      _typeT _y = (_x + static_cast<_larger_type>(static_cast<_typeT>(_x)\
    \ * _r) * mod) >> std::numeric_limits<_typeT>::digits;\n      return _y >= mod\
    \ ? _y - mod : _y;\n    }\n  };\n}\n#line 11 \"math/DynamicModInt.hpp\"\n\nnamespace\
    \ kyopro {\n  template<class _typeT, KYOPRO_BASE_UINT = 0>\n  struct DynamicModInt\
    \ {\n    static_assert(std::is_unsigned_v<_typeT>, \"Unsigned integer is required\"\
    );\n\n  private:\n    using _larger_type = uint_least_t<std::numeric_limits<_typeT>::digits\
    \ * 2>;\n\n    inline static Montgomery<_typeT> _montgomery;\n\n  public:\n  \
    \  _typeT value;\n\n    static void set_mod(_typeT _mod) noexcept {\n      _montgomery.set_mod(_mod);\n\
    \    }\n\n    static KYOPRO_BASE_INT get_mod() noexcept {\n      return _montgomery.mod;\n\
    \    }\n\n    KYOPRO_BASE_INT get_val() noexcept {\n      return _montgomery.inverse_transform(value);\n\
    \    }\n\n    DynamicModInt() noexcept = default;\n    DynamicModInt(_typeT _value)\
    \ noexcept: value(_montgomery.transform(floor_mod(_value, _montgomery.mod))) {}\n\
    \n    template<class _typeU>\n    explicit operator _typeU() const noexcept {\
    \ return _montgomery.inverse_transform(value); }\n\n    static DynamicModInt raw(_typeT\
    \ _n) noexcept {\n      DynamicModInt _res;\n      _res.value = _n;\n      return\
    \ _res;\n    }\n\n    DynamicModInt power(_typeT _n) const noexcept {\n      DynamicModInt\
    \ _res = 1, _a = *this;\n      while (_n > 0) {\n        if (_n & 1) _res = _res\
    \ * _a;\n        _a = _a * _a;\n        _n >>= 1;\n      }\n      return _res;\n\
    \    }\n\n    DynamicModInt inv() const noexcept {\n      _typeT _a = value, _b\
    \ = _montgomery.mod;\n      std::make_signed_t<_typeT> _u = 1, _v = 0;\n     \
    \ while (_b > 0) {\n        _typeT _t = _a / _b;\n        _a -= _t * _b;\n   \
    \     std::swap(_a, _b);\n        _u -= _t * _v;\n        std::swap(_u, _v);\n\
    \      }\n      return static_cast<DynamicModInt>(_u);\n    }\n\n    DynamicModInt\
    \ operator +() const noexcept { return *this; }\n\n    DynamicModInt operator\
    \ -() const noexcept { return value == 0 ? 0 : _montgomery.mod - value; }\n\n\
    \    DynamicModInt& operator ++() noexcept {\n      if (++value >= _montgomery.mod)\
    \ value -= _montgomery.mod;\n      return *this;\n    }\n\n    DynamicModInt operator\
    \ ++(int) noexcept {\n      DynamicModInt _before = *this;\n      operator ++();\n\
    \      return _before;\n    }\n\n    DynamicModInt& operator --() noexcept {\n\
    \      if (value == 0) value = _montgomery.mod;\n      --value;\n      return\
    \ *this;\n    }\n\n    DynamicModInt operator --(int) noexcept {\n      DynamicModInt\
    \ _before = *this;\n      operator --();\n      return _before;\n    }\n\n   \
    \ DynamicModInt& operator +=(DynamicModInt _rhs) noexcept {\n      if ((value\
    \ += _rhs.value) >= mod) value -= mod;\n      return *this;\n    }\n\n    DynamicModInt&\
    \ operator -=(DynamicModInt _rhs) noexcept {\n      if (value < _rhs.value) value\
    \ += mod;\n      value -= _rhs.value;\n      return *this;\n    }\n\n    DynamicModInt&\
    \ operator *=(DynamicModInt _rhs) noexcept {\n      value = _montgomery.reduce(static_cast<_larger_type>(value)\
    \ * _rhs.value);\n      return *this;\n    }\n\n    DynamicModInt& operator /=(DynamicModInt\
    \ _rhs) noexcept {\n      value = _montgomery.reduce(static_cast<_larger_type>(value)\
    \ * _rhs.inv().value);\n      return *this;\n    }\n\n    friend DynamicModInt\
    \ operator +(DynamicModInt _lhs, DynamicModInt _rhs) noexcept { return _lhs +=\
    \ _rhs; }\n\n    friend DynamicModInt operator -(DynamicModInt _lhs, DynamicModInt\
    \ _rhs) noexcept { return _lhs -= _rhs; }\n\n    friend DynamicModInt operator\
    \ *(DynamicModInt _lhs, DynamicModInt _rhs) noexcept { return _lhs *= _rhs; }\n\
    \n    friend DynamicModInt operator /(DynamicModInt _lhs, DynamicModInt _rhs)\
    \ noexcept { return _lhs /= _rhs; }\n\n    friend bool operator ==(DynamicModInt\
    \ _lhs, DynamicModInt _rhs) noexcept { return _lhs.value == _rhs.value; }\n\n\
    \    friend bool operator !=(DynamicModInt _lhs, DynamicModInt _rhs) noexcept\
    \ { return _lhs.value != _rhs.value; }\n\n    template<class _typeScanner>\n \
    \   void scan(_typeScanner& _scanner) {\n      std::int_fast64_t _value;\n   \
    \   _scanner.scan(_value);\n      value = _montgomery.transform(floor_mod(_value,\
    \ _montgomery.mod));\n    }\n\n    template<class _typePrinter>\n    void print(_typePrinter&\
    \ _printer) const {\n      _printer.print(_montgomery.inverse_transform(value));\n\
    \    }\n  };\n\n  template<class _typeT, KYOPRO_BASE_UINT _kind>\n  struct Hash<DynamicModInt<_typeT,\
    \ _kind>> { std::size_t operator ()(DynamicModInt<_typeT, _kind> _a) const noexcept\
    \ { return static_cast<std::size_t>(_a); } };\n}\n#line 5 \"algorithm/bit.hpp\"\
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
    \  }\n}\n#line 13 \"math/ModInt.hpp\"\n\nnamespace kyopro {\n  template<KYOPRO_BASE_UINT\
    \ _m>\n  struct ModInt {\n    using value_type = uint_least_t<bit_len(_m * 2 -\
    \ 2)>;\n\n  private:\n    static constexpr value_type _mod = _m;\n\n  public:\n\
    \    value_type value;\n\n    static constexpr KYOPRO_BASE_INT get_mod() noexcept\
    \ {\n      return _mod;\n    }\n\n    constexpr ModInt() noexcept = default;\n\
    \    template<class _typeT>\n    constexpr ModInt(_typeT _value) noexcept: value(floor_mod(_value,\
    \ _mod)) {}\n\n    template<class _typeT>\n    explicit constexpr operator _typeT()\
    \ const noexcept { return value; }\n\n    static constexpr ModInt raw(KYOPRO_BASE_UINT\
    \ _n) noexcept {\n      ModInt _res;\n      _res.value = _n;\n      return _res;\n\
    \    }\n\n    constexpr ModInt power(KYOPRO_BASE_UINT _n) const noexcept {\n \
    \     std::uint_fast64_t _res = 1, _a = value;\n      while (_n > 0) {\n     \
    \   if (_n & 1) _res = _res * _a % _mod;\n        _a = _a * _a % _mod;\n     \
    \   _n >>= 1;\n      }\n      return _res;\n    }\n\n    constexpr ModInt inv()\
    \ const noexcept {\n      std::uint_fast64_t _a = value, _b = _mod;\n      std::int_fast64_t\
    \ _u = 1, _v = 0;\n      while (_b > 0) {\n        std::uint_fast64_t _t = _a\
    \ / _b;\n        _a -= _t * _b;\n        std::swap(_a, _b);\n        _u -= _t\
    \ * _v;\n        std::swap(_u, _v);\n      }\n      return floor_mod(_u, _mod);\n\
    \    }\n\n    constexpr ModInt operator +() const noexcept { return *this; }\n\
    \n    constexpr ModInt operator -() const noexcept { return value == 0 ? 0 : _mod\
    \ - value; }\n\n    constexpr ModInt& operator ++() noexcept {\n      if (++value\
    \ >= _mod) value -= _mod;\n      return *this;\n    }\n\n    constexpr ModInt\
    \ operator ++(int) noexcept {\n      ModInt _before = *this;\n      operator ++();\n\
    \      return _before;\n    }\n\n    constexpr ModInt& operator --() noexcept\
    \ {\n      if (value == 0) value = _mod;\n      --value;\n      return *this;\n\
    \    }\n\n    constexpr ModInt operator --(int) noexcept {\n      ModInt _before\
    \ = *this;\n      operator --();\n      return _before;\n    }\n\n    constexpr\
    \ ModInt& operator +=(ModInt _rhs) noexcept {\n      if ((value += _rhs.value)\
    \ >= _mod) value -= _mod;\n      return *this;\n    }\n\n    constexpr ModInt&\
    \ operator -=(ModInt _rhs) noexcept {\n      if (value < _rhs.value) value +=\
    \ _mod;\n      value -= _rhs.value;\n      return *this;\n    }\n\n    constexpr\
    \ ModInt& operator *=(ModInt _rhs) noexcept {\n      value = static_cast<uint_least_t<bit_len(_mod)\
    \ * 2>>(value) * _rhs.value % _mod;\n      return *this;\n    }\n\n    constexpr\
    \ ModInt& operator /=(ModInt _rhs) noexcept {\n      value = static_cast<uint_least_t<bit_len(_mod)\
    \ * 2>>(value) * _rhs.inv().value % _mod;\n      return *this;\n    }\n\n    friend\
    \ constexpr ModInt operator +(ModInt _lhs, ModInt _rhs) noexcept { return _lhs\
    \ += _rhs; }\n\n    friend constexpr ModInt operator -(ModInt _lhs, ModInt _rhs)\
    \ noexcept { return _lhs -= _rhs; }\n\n    friend constexpr ModInt operator *(ModInt\
    \ _lhs, ModInt _rhs) noexcept { return _lhs *= _rhs; }\n\n    friend constexpr\
    \ ModInt operator /(ModInt _lhs, ModInt _rhs) noexcept { return _lhs /= _rhs;\
    \ }\n\n    friend constexpr bool operator ==(ModInt _lhs, ModInt _rhs) noexcept\
    \ { return _lhs.value == _rhs.value; }\n\n    friend constexpr bool operator !=(ModInt\
    \ _lhs, ModInt _rhs) noexcept { return _lhs.value != _rhs.value; }\n\n    template<class\
    \ _typeScanner>\n    void scan(_typeScanner& _scanner) {\n      std::int_fast64_t\
    \ _value;\n      _scanner.scan(_value);\n      value = floor_mod(_value, _mod);\n\
    \    }\n\n    template<class _typePrinter>\n    void print(_typePrinter& _printer)\
    \ const {\n      _printer.print(value);\n    }\n  };\n\n  template<KYOPRO_BASE_UINT\
    \ _mod>\n  struct Hash<ModInt<_mod>> { constexpr std::size_t operator ()(ModInt<_mod>\
    \ _a) const noexcept { return static_cast<std::size_t>(_a); } };\n}\n#line 19\
    \ \"template/alias.hpp\"\n\nnamespace kyopro {\n  using ll = long long;\n  using\
    \ ull = unsigned long long;\n  using lf = double;\n\n  using i8 = std::int8_t;\n\
    \  using u8 = std::uint8_t;\n  using i16 = std::int16_t;\n  using u16 = std::uint16_t;\n\
    \  using i32 = std::int32_t;\n  using u32 = std::uint32_t;\n  using i64 = std::int64_t;\n\
    \  using u64 = std::uint64_t;\n  using i128 = __int128_t;\n  using u128 = __uint128_t;\n\
    \  #ifdef __SIZEOF_FLOAT128__\n  using f128 = __float128;\n  #endif\n\n  using\
    \ mint = ModInt<mod>;\n  using dmint = DynamicModInt<KYOPRO_BASE_UINT>;\n\n  template<class\
    \ _typeKey>\n  using hset = std::unordered_set<_typeKey, Hash<_typeKey>>;\n  template<class\
    \ _typeKey, class _typeT>\n  using hmap = std::unordered_map<_typeKey, _typeT,\
    \ Hash<_typeKey>>;\n  template<class _typeKey>\n  using hmultiset = std::unordered_multiset<_typeKey,\
    \ Hash<_typeKey>>;\n  template<class _typeKey, class _typeT>\n  using hmultimap\
    \ = std::unordered_multimap<_typeKey, _typeT, Hash<_typeKey>>;\n  template<class\
    \ _typeT, class _typeCompare = std::less<_typeT>, class _typeContainer = std::vector<_typeT>>\n\
    \  using priq = std::priority_queue<_typeT, _typeContainer, _typeCompare>;\n \
    \ template<class _typeT, class _typeCompare = std::greater<_typeT>, class _typeContainer\
    \ = std::vector<_typeT>>\n  using heapq = priq<_typeT, _typeCompare, _typeContainer>;\n\
    }\n\nusing namespace std;\nusing namespace kyopro;\n\ntemplate<class _typeT, class\
    \ _typeU, std::enable_if_t<!std::is_same_v<_typeT, _typeU>>* = nullptr>\nconstexpr\
    \ std::common_type_t<_typeT, _typeU> min(const _typeT& a, const _typeU& b) noexcept\
    \ {\n  return a < b ? a : b;\n}\n\ntemplate<class _typeT, class _typeU, std::enable_if_t<!std::is_same_v<_typeT,\
    \ _typeU>>* = nullptr>\nconstexpr std::common_type_t<_typeT, _typeU> max(const\
    \ _typeT& a, const _typeU& b) noexcept {\n  return a > b ? a : b;\n}\n#line 2\
    \ \"template/amin_amax.hpp\"\n\nnamespace kyopro {\n  template<class _typeT, class\
    \ _typeU>\n  constexpr bool amin(_typeT& a, _typeU&& b) noexcept {\n    if (b\
    \ < a) {\n      a = b;\n      return true;\n    }\n    return false;\n  }\n\n\
    \  template<class _typeT, class _typeU>\n  constexpr bool amax(_typeT& a, _typeU&&\
    \ b) noexcept {\n    if (a < b) {\n      a = b;\n      return true;\n    }\n \
    \   return false;\n  }\n}\n#line 4 \"template/constant.hpp\"\n\nnamespace kyopro\
    \ {\n  inline constexpr std::array<std::pair<KYOPRO_BASE_INT, KYOPRO_BASE_INT>,\
    \ 4> beside{{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}};\n  inline constexpr std::array<std::pair<KYOPRO_BASE_INT,\
    \ KYOPRO_BASE_INT>, 8> around{{{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1,\
    \ -1}, {0, -1}, {1, -1}}};\n}\n#line 4 \"template/len.hpp\"\n\nnamespace kyopro\
    \ {\n  template<class _typeT>\n  constexpr KYOPRO_BASE_INT len(_typeT&& _a) noexcept\
    \ {\n    return std::size(_a);\n  }\n}\n#line 5 \"template/macro.hpp\"\n\n#define\
    \ KYOPRO_OVERLOAD_MACRO(_1, _2, _3, _4, name, ...) name\n#define KYOPRO_REP0()\
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
    #line 5 \"template/make_array.hpp\"\n\nnamespace kyopro {\n  template<class _typeT>\n\
    \  constexpr auto make_array(const _typeT& _init = _typeT()) noexcept { return\
    \ _init; }\n\n  template<class _typeT, KYOPRO_BASE_UINT _length, KYOPRO_BASE_UINT...\
    \ _lengths>\n  constexpr auto make_array(const _typeT& _init = _typeT()) noexcept\
    \ {\n    auto _elm = make_array<_typeT, _lengths...>(_init);\n    std::array<decltype(_elm),\
    \ _length> _res;\n    for (auto& _i: _res) _i = _elm;\n    return std::move(_res);\n\
    \  }\n}\n#line 6 \"template/make_vector.hpp\"\n\nnamespace kyopro {\n  template<KYOPRO_BASE_UINT\
    \ _idx = 0, KYOPRO_BASE_UINT _n, class _typeT>\n  auto make_vector(const KYOPRO_BASE_UINT\
    \ (&_d)[_n], _typeT&& _init) noexcept {\n    if constexpr (_idx < _n) return std::vector(_d[_idx],\
    \ make_vector<_idx + 1>(_d, std::forward<_typeT>(_init)));\n    else return _init;\n\
    \  }\n\n  template<class _typeT, KYOPRO_BASE_UINT _idx = 0, KYOPRO_BASE_UINT _n>\n\
    \  auto make_vector(const KYOPRO_BASE_UINT (&_d)[_n], const _typeT& _init = _typeT())\
    \ noexcept {\n    if constexpr (_idx < _n) return std::vector(_d[_idx], make_vector<_idx\
    \ + 1>(_d, _init));\n    else return _init;\n  }\n}\n#line 9 \"template/all.hpp\"\
    \n"
  code: '#pragma once

    #include "alias.hpp"

    #include "amin_amax.hpp"

    #include "constant.hpp"

    #include "len.hpp"

    #include "macro.hpp"

    #include "make_array.hpp"

    #include "make_vector.hpp"'
  dependsOn:
  - template/alias.hpp
  - algorithm/Hash.hpp
  - meta/settings.hpp
  - meta/trait.hpp
  - math/DynamicModInt.hpp
  - meta/constant.hpp
  - math/power.hpp
  - math/mod.hpp
  - math/Montgomery.hpp
  - math/ModInt.hpp
  - algorithm/bit.hpp
  - template/amin_amax.hpp
  - template/constant.hpp
  - template/len.hpp
  - template/macro.hpp
  - template/make_array.hpp
  - template/make_vector.hpp
  isVerificationFile: false
  path: template/all.hpp
  requiredBy:
  - all/all.hpp
  timestamp: '2022-04-17 23:28:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/all.hpp
layout: document
redirect_from:
- /library/template/all.hpp
- /library/template/all.hpp.html
title: template/all.hpp
---
