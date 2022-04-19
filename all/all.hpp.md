---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/Hash.hpp
    title: algorithm/Hash.hpp
  - icon: ':warning:'
    path: algorithm/all.hpp
    title: algorithm/all.hpp
  - icon: ':heavy_check_mark:'
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
  - icon: ':heavy_check_mark:'
    path: function/monoid.hpp
    title: function/monoid.hpp
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
  - icon: ':heavy_check_mark:'
    path: math/factorize.hpp
    title: math/factorize.hpp
  - icon: ':heavy_check_mark:'
    path: math/is_prime.hpp
    title: math/is_prime.hpp
  - icon: ':heavy_check_mark:'
    path: math/mod.hpp
    title: math/mod.hpp
  - icon: ':heavy_check_mark:'
    path: math/power.hpp
    title: math/power.hpp
  - icon: ':warning:'
    path: meta/all.hpp
    title: meta/all.hpp
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
    path: structure/FenwickTree.hpp
    title: structure/FenwickTree.hpp
  - icon: ':heavy_check_mark:'
    path: structure/UnionFind.hpp
    title: structure/UnionFind.hpp
  - icon: ':warning:'
    path: structure/all.hpp
    title: structure/all.hpp
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
    path: template/all.hpp
    title: template/all.hpp
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
  _extendedRequiredBy: []
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
    #endif\n#line 5 \"algorithm/bit.hpp\"\n\nnamespace kyopro {\n  template<class\
    \ _typeT>\n  constexpr KYOPRO_BASE_INT pop_count(_typeT _x) noexcept {\n    constexpr\
    \ auto _digits = std::numeric_limits<std::make_unsigned_t<_typeT>>::digits;\n\
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
    \  }\n}\n#line 2 \"algorithm/compress.hpp\"\n#include <algorithm>\n#include <functional>\n\
    #include <iterator>\n#include <unordered_map>\n#include <vector>\n#line 8 \"algorithm/compress.hpp\"\
    \n\nnamespace kyopro {\n  template<class _typeT, class _typeContainer = std::unordered_map<typename\
    \ std::iterator_traits<_typeT>::value_type, KYOPRO_BASE_INT>, class _typeCompare>\n\
    \  auto compress(_typeT _first, _typeT _last, _typeCompare _comp = std::less<typename\
    \ std::iterator_traits<_typeT>::value_type>()) {\n    std::vector<typename std::iterator_traits<_typeT>::value_type>\
    \ _vec(_first, _last);\n    std::sort(_vec.begin(), _vec.end(), _comp);\n    auto\
    \ _end = std::unique(_vec.begin(), _vec.end());\n    _typeContainer _mem;\n  \
    \  int _cnt = -1;\n    for (auto _i = _vec.begin(); _i != _end; ++_i) _mem[*_i]\
    \ = ++_cnt;\n    return _mem;\n  }\n}\n#line 2 \"algorithm/Hash.hpp\"\n#include\
    \ <cstddef>\n#line 5 \"algorithm/Hash.hpp\"\n#include <initializer_list>\n#include\
    \ <tuple>\n#line 8 \"algorithm/Hash.hpp\"\n#include <utility>\n#line 3 \"meta/trait.hpp\"\
    \n#include <queue>\n#line 5 \"meta/trait.hpp\"\n#include <stack>\n#line 9 \"meta/trait.hpp\"\
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
    \  inline constexpr KYOPRO_BASE_FLOAT pi = PI<KYOPRO_BASE_FLOAT>;\n}\n#line 4\
    \ \"function/monoid.hpp\"\n\nnamespace kyopro {\n  template<class _typeT, _typeT\
    \ _id = 0>\n  struct Plus {\n    static_assert(std::is_arithmetic_v<_typeT>);\n\
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
    \ noexcept { return _a < _b ? _a : _b; }\n  };\n}\n#line 4 \"function/RecursiveLambda.hpp\"\
    \n\nnamespace kyopro {\n  template<class _typeF>\n  struct RecursiveLambda {\n\
    \  private:\n    _typeF _func;\n\n  public:\n    template<class _typeG>\n    constexpr\
    \ RecursiveLambda(_typeG&& _func) noexcept: _func(std::forward<_typeG>(_func))\
    \ {}\n    template<class... _typeArgs>\n    constexpr decltype(auto) operator\
    \ ()(_typeArgs&&... _args) const noexcept { return _func(*this, std::forward<_typeArgs>(_args)...);\
    \ }\n  };\n\n  template<class _typeF>\n  RecursiveLambda(_typeF&&) -> RecursiveLambda<std::decay_t<_typeF>>;\n\
    }\n#line 3 \"math/div.hpp\"\n\nnamespace kyopro {\n  template<class _typeT, class\
    \ _typeU>\n  constexpr std::common_type_t<_typeT, _typeU> floor_div(_typeT _x,\
    \ _typeU _m) noexcept {\n    static_assert(std::is_integral_v<_typeT> && std::is_integral_v<_typeU>,\
    \ \"Integer is required\");\n    if constexpr (std::is_unsigned_v<_typeT> || std::is_unsigned_v<_typeU>)\
    \ return _x / _m;\n    auto _d = _x / _m;\n    return _d * _m == _x ? _d : _d\
    \ - ((_x < 0) ^ (_m < 0));\n  }\n\n  template<class _typeT, class _typeU>\n  constexpr\
    \ std::common_type_t<_typeT, _typeU> ceil_div(_typeT _x, _typeU _m) noexcept {\
    \ return floor_div(_x + _m - static_cast<_typeT>(1), _m); }\n}\n#line 5 \"math/divisors.hpp\"\
    \n\nnamespace kyopro {\n  template<class _typeContainer = std::vector<KYOPRO_BASE_INT>>\n\
    \  _typeContainer divisors(KYOPRO_BASE_UINT _n) {\n    _typeContainer _lower,\
    \ _upper;\n    std::uint_fast64_t _i;\n    for (_i = 1; _i * _i < _n; ++_i) if\
    \ (_n % _i == 0) {\n      _lower.emplace_back(_i);\n      _upper.emplace_back(_n\
    \ / _i);\n    }\n    if (_i * _i == _n) _lower.emplace_back(_i);\n    _lower.insert(end(_lower),\
    \ rall(_upper));\n    return _lower;\n  }\n}\n#line 2 \"math/DynamicModInt.hpp\"\
    \n#include <cassert>\n#line 4 \"math/mod.hpp\"\n\nnamespace kyopro {\n  template<class\
    \ _typeT, class _typeU>\n  constexpr std::common_type_t<_typeT, _typeU> floor_mod(_typeT\
    \ _x, _typeU _m) noexcept {\n    static_assert(std::is_integral_v<_typeT> && std::is_integral_v<_typeU>,\
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
    \ { return static_cast<std::size_t>(_a); } };\n}\n#line 4 \"math/euler_phi.hpp\"\
    \n\nnamespace kyopro {\n  constexpr KYOPRO_BASE_UINT euler_phi(KYOPRO_BASE_UINT\
    \ _n) noexcept {\n    std::uint_fast64_t _res = _n;\n    if ((_n & 1) == 0) {\n\
    \      _res -= _res >> 1;\n      _n >>= 1;\n      while ((_n & 1) == 0) _n >>=\
    \ 1;\n    }\n    for (std::uint_fast64_t _i = 3; _i * _i <= _n; _i += 2) {\n \
    \     if (_n % _i == 0) {\n        _res -= _res / _i;\n        _n /= _i;\n   \
    \     while (_n % _i == 0) _n /= _i;\n      }\n    }\n    if (_n != 1) _res -=\
    \ _res / _n;\n    return _res;\n  }\n}\n#line 4 \"math/factorize.hpp\"\n#include\
    \ <numeric>\n#include <random>\n#line 7 \"math/is_prime.hpp\"\n\nnamespace kyopro\
    \ {\n  template<class _typeT>\n  constexpr bool is_prime(_typeT _x) {\n    using\
    \ _typeU = std::make_unsigned_t<_typeT>;\n    using _typeDynamicModInt = DynamicModInt<_typeU,\
    \ KYOPRO_BASE_UINT(-1)>;\n    _typeU _n = _x;\n    if (_n <= 1) return false;\n\
    \    if (!(_n & 1)) return _n == 2;\n    _typeDynamicModInt::set_mod(_n);\n  \
    \  std::uint_fast64_t _d = (_n - 1) >> trailing_zero(_n - 1);\n    _typeDynamicModInt\
    \ _one = 1, _minus_one = _n - 1;\n    auto _ng = [&](std::uint_fast64_t _a) noexcept\
    \ {\n      auto _y = _typeDynamicModInt(_a).power(_d);\n      std::uint_fast64_t\
    \ _t = _d;\n      while (_y != _one and _y != _minus_one and _t != _n - 1) _y\
    \ *= _y, _t <<= 1;\n      if (_y != _minus_one and !(_t & 1)) return true;\n \
    \     return false;\n    };\n    if (std::numeric_limits<_typeU>::digits <= 32\
    \ || _n < (static_cast<_typeU>(1) << 32)) {\n      for (auto _i: (std::uint_fast64_t[3]){2,\
    \ 7, 61}) {\n        if (_n <= _i) return true;\n        if (_ng(_i)) return false;\n\
    \      }\n    } else {\n      for (auto _i: (std::uint_fast64_t[7]){2, 325, 9375,\
    \ 28178, 450775, 9780504, 1795265022}) {\n        if (_n <= _i) return true;\n\
    \        if (_ng(_i)) return false;\n      }\n    }\n    return true;\n  }\n}\n\
    #line 10 \"math/factorize.hpp\"\n\nnamespace kyopro {\n  template<class _typeT>\n\
    \  constexpr _typeT pollard_rho(_typeT _p, KYOPRO_BASE_UINT _c) {\n    using _typeU\
    \ = std::make_unsigned_t<_typeT>;\n    using _typeDynamicModInt = DynamicModInt<_typeU,\
    \ KYOPRO_BASE_UINT(-1)>;\n    _typeU _n = _p;\n    _typeDynamicModInt::set_mod(_n);\n\
    \    _typeDynamicModInt _cc = _c;\n    auto _f = [=](_typeDynamicModInt _x) noexcept\
    \ { return _x * _x + _cc; };\n    _typeDynamicModInt _x = 1, _y = 2, _z = 1, _q\
    \ = 1;\n    _typeU _g = 1;\n    const int _m = 1 << (std::__lg(_n) / 5);\n   \
    \ for (int _r = 1; _g == 1; _r <<= 1) {\n      _x = _y;\n      for (int _i = 0;\
    \ _i < _r; ++_i) _y = _f(_y);\n      for (int _k = 0; _k < _r && _g == 1; _k +=\
    \ _m) {\n        _z = _y;\n        int _min = std::min(_m, _r - _k);\n       \
    \ for (int _i = 0; _i < _min; ++_i) {\n          _y = _f(_y);\n          _q *=\
    \ _x - _y;\n        }\n        _g = std::gcd(static_cast<_typeU>(_q), _n);\n \
    \     }\n    }\n    if (_g == _n) {\n      do {\n        _z = _f(_z);\n      \
    \  _g = std::gcd(static_cast<_typeU>(_x - _z), _n);\n      } while (_g == 1);\n\
    \    }\n    return _g;\n  }\n\n  KYOPRO_BASE_UINT find_factor(KYOPRO_BASE_UINT\
    \ _n) noexcept {\n    static std::mt19937_64 _mt(std::random_device{}());\n  \
    \  std::uniform_int_distribution<std::uint_fast64_t> _rnd(0, _n - 1);\n    if\
    \ (is_prime(_n)) return _n;\n    for (int _i = 0; _i < 100; ++_i) {\n      std::uint_fast64_t\
    \ _m = pollard_rho(_n, _rnd(_mt));\n      if (is_prime(_m)) return _m;\n     \
    \ _n = _m;\n    }\n    return 1;\n  }\n\n  template<bool _sorted = true, class\
    \ _typeContainer = std::vector<KYOPRO_BASE_INT>>\n  _typeContainer factorize(KYOPRO_BASE_UINT\
    \ _n) {\n    _typeContainer _res;\n    for (int _p = 2; _p < 100 && _p * _p <=\
    \ _n; ++_p) {\n      while (_n % _p == 0) {\n        _n /= _p;\n        _res.emplace_back(_p);\n\
    \      }\n    }\n    while (_n > 1) {\n      std::uint_fast64_t _p = find_factor(_n);\n\
    \      do {\n        _n /= _p;\n        _res.emplace_back(_p);\n      } while\
    \ (_n % _p == 0);\n    }\n    if constexpr (_sorted) std::sort(_res.begin(), _res.end());\n\
    \    return _res;\n  }\n}\n#line 13 \"math/ModInt.hpp\"\n\nnamespace kyopro {\n\
    \  template<KYOPRO_BASE_UINT _m>\n  struct ModInt {\n    using value_type = uint_least_t<bit_len(_m\
    \ * 2 - 2)>;\n\n  private:\n    static constexpr value_type _mod = _m;\n\n  public:\n\
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
    \ _a) const noexcept { return static_cast<std::size_t>(_a); } };\n}\n#line 7 \"\
    structure/FenwickTree.hpp\"\n\nnamespace kyopro {\n  template<class _typeT, class\
    \ _typeOp = Plus<_typeT>, class _typeContainer = std::vector<_typeT>>\n  struct\
    \ FenwickTree {\n  private:\n    [[no_unique_address]] _typeOp _op;\n    _typeContainer\
    \ _tree;\n\n  public:\n    using value_type = _typeT;\n    using size_type = KYOPRO_BASE_UINT;\n\
    \    using reference = _typeT&;\n    using const_reference = const _typeT&;\n\n\
    \    FenwickTree() noexcept = default;\n    FenwickTree(KYOPRO_BASE_UINT _n) noexcept:\
    \ _tree(_n, _op.id) {}\n    template<class _typeC, std::enable_if_t<std::is_same_v<_typeContainer,\
    \ std::decay_t<_typeC>>>>\n    FenwickTree(_typeC&& _tree): _tree(std::forward<_typeC>(_tree))\
    \ {}\n\n    KYOPRO_BASE_UINT size() noexcept { return _tree.size(); }\n\n    void\
    \ apply(int _p, const _typeT& _x) {\n      ++_p;\n      while (_p <= (int)size())\
    \ {\n        _tree[_p - 1] = _op(_tree[_p - 1], _x);\n        _p += _p & -_p;\n\
    \      }\n    }\n\n    _typeT prod(int _r) const {\n      _typeT _s = _op.id;\n\
    \      while (_r > 0) {\n        _s = _op(_s, _tree[_r - 1]);\n        _r -= _r\
    \ & -_r;\n      }\n      return _s;\n    }\n    _typeT prod(int _l, int _r) const\
    \ { return _op(prod(_r), _op.inv(prod(_l))); }\n\n    _typeT all_prod() { return\
    \ prod(_tree.size()); }\n\n    _typeT get(int _p) { return _op(prod(_p + 1), _op.inv(prod(_p)));\
    \ }\n\n    void set(int _p, const _typeT& _x) { apply(_p, _op(_x, _op.inv(get(_p))));\
    \ }\n  };\n}\n#line 8 \"structure/UnionFind.hpp\"\n\nnamespace kyopro {\n  template<class\
    \ _typeContainer = std::vector<int>>\n  struct UnionFind {\n  private:\n    _typeContainer\
    \ _par;\n\n  public:\n    UnionFind() noexcept = default;\n    UnionFind(KYOPRO_BASE_UINT\
    \ _n) noexcept: _par(_n, -1) {}\n    template<class _typeC, std::enable_if_t<std::is_same_v<_typeContainer,\
    \ std::decay_t<_typeC>>>>\n    UnionFind(_typeC&& _par): _par(std::forward<_typeC>(_par))\
    \ {}\n\n    void resize(KYOPRO_BASE_UINT _x) { _par.resize(_x, -1); }\n    void\
    \ assign(KYOPRO_BASE_UINT _x) { _par.assign(_x, -1); }\n    void reset() { std::fill(std::begin(_par),\
    \ std::end(_par), -1); }\n\n    KYOPRO_BASE_UINT size() const noexcept { return\
    \ _par.size(); }\n\n    KYOPRO_BASE_INT find(int _x) {\n      int _p = _x;\n \
    \     while (_par[_p] >= 0) _p = _par[_p];\n      while (_x != _p) {\n       \
    \ int _tmp = _x;\n        _x = _par[_x];\n        _par[_tmp] = _p;\n      }\n\
    \      return _p;\n    }\n\n    bool merge(int _x, int _y) {\n      _x = find(_x),\
    \ _y = find(_y);\n      if (_x == _y) return false;\n      if (_par[_x] > _par[_y])\
    \ {\n        int _tmp = _x;\n        _x = _y;\n        _y = _tmp;\n      }\n \
    \     _par[_x] += _par[_y];\n      _par[_y] = _x;\n      return true;\n    }\n\
    \n    bool same(int _x, int _y) { return find(_x) == find(_y); }\n\n    KYOPRO_BASE_INT\
    \ group_size(int _x) { return -_par[find(_x)]; }\n\n    std::vector<int> group_members(int\
    \ _x) {\n      _x = find(_x);\n      std::vector<int> _a;\n      for (int _i =\
    \ 0; _i < (int)(size()); ++_i) if (find(_i) == _x) _a.emplace_back(_i);\n    \
    \  return _a;\n    }\n\n    template<class _typeVector = std::vector<KYOPRO_BASE_INT>>\n\
    \    _typeVector roots() const {\n      _typeVector _a;\n      for (int _i = 0;\
    \ _i < (int)(size()); ++_i) if (_par[_i] < 0) _a.emplace_back(_i);\n      return\
    \ _a;\n    }\n\n    KYOPRO_BASE_INT group_count() const {\n      KYOPRO_BASE_INT\
    \ _cnt = 0;\n      for (int _i = 0; _i < (int)(size()); ++_i) if (_par[_i] < 0)\
    \ ++_cnt;\n      return _cnt;\n    }\n\n    template<class _typeMap = std::unordered_map<KYOPRO_BASE_INT,\
    \ std::vector<KYOPRO_BASE_INT>>>\n    _typeMap all_group_members() {\n      _typeMap\
    \ _group_members;\n      for (int _member = 0; _member < (int)(size()); ++_member)\
    \ _group_members[find(_member)].emplace_back(_member);\n      return _group_members;\n\
    \    }\n  };\n}\n#line 2 \"system/in.hpp\"\n#include <unistd.h>\n#line 6 \"system/in.hpp\"\
    \n#include <cstdio>\n#include <string>\n#line 14 \"system/in.hpp\"\n\nnamespace\
    \ kyopro {\n  template<KYOPRO_BASE_UINT _buf_size = KYOPRO_BUFFER_SIZE>\n  struct\
    \ Reader {\n  private:\n    int _fd, _idx;\n    std::array<char, _buf_size> _buffer;\n\
    \n  public:\n    Reader() {\n      read(_fd, _buffer.begin(), _buf_size);\n  \
    \  }\n    Reader(int _fd): _fd(_fd), _idx(0), _buffer() {\n      read(_fd, _buffer.begin(),\
    \ _buf_size);\n    }\n    Reader(FILE* _fp): _fd(fileno(_fp)), _idx(0), _buffer()\
    \ {\n      read(_fd, _buffer.begin(), _buf_size);\n    }\n\n    struct iterator\
    \ {\n    private:\n      Reader& _reader;\n\n    public:\n      using difference_type\
    \ = void;\n      using value_type = void;\n      using pointer = void;\n     \
    \ using reference = void;\n      using iterator_category = std::input_iterator_tag;\n\
    \n      iterator() noexcept = default;\n      iterator(Reader& _reader) noexcept:\
    \ _reader(_reader) {}\n\n      iterator& operator ++() {\n        ++_reader._idx;\n\
    \        if (_reader._idx == _buf_size) {\n          read(_reader._fd, _reader._buffer.begin(),\
    \ _buf_size);\n          _reader._idx = 0;\n        }\n        return *this;\n\
    \      }\n\n      iterator operator ++(int) {\n        iterator _before = *this;\n\
    \        operator ++();\n        return _before;\n      }\n\n      char& operator\
    \ *() const {\n        return _reader._buffer[_reader._idx];\n      }\n    };\n\
    \n    iterator begin() noexcept {\n      return iterator(*this);\n    }\n  };\n\
    \n  Reader input(0);\n\n  template<class _typeIterator, KYOPRO_BASE_UINT _decimal_precision\
    \ = KYOPRO_DECIMAL_PRECISION>\n  struct Scanner {\n  private:\n    template<class,\
    \ class = void>\n    struct _has_scan: std::false_type {};\n    template<class\
    \ _typeT>\n    struct _has_scan<_typeT, std::void_t<decltype(std::declval<_typeT>().scan(std::declval<Scanner&>()))>>:\
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
    \ if (_sgn) _a = -_a;\n    }\n    template<KYOPRO_BASE_UINT _i = 0, class _typeT,\
    \ std::enable_if_t<is_tuple_v<_typeT> && !_has_scan<_typeT>::value>* = nullptr>\n\
    \    void scan(_typeT& _a) {\n      if constexpr (_i < std::tuple_size_v<_typeT>)\
    \ {\n        scan(std::get<_i>(_a));\n        scan<_i + 1>(_a);\n      }\n   \
    \ }\n    template<class _typeT, std::enable_if_t<is_range_v<_typeT> && !_has_scan<_typeT>::value>*\
    \ = nullptr>\n    void scan(_typeT& _a) {\n      for (auto& _i: _a) scan(_i);\n\
    \    }\n    template<class _typeT, std::enable_if_t<_has_scan<_typeT>::value>*\
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
    \ % 10);\n      }\n    }\n    template<KYOPRO_BASE_UINT _i = 0, class _typeT,\
    \ std::enable_if_t<is_tuple_v<_typeT> && !_has_print<_typeT>::value>* = nullptr>\n\
    \    void print(const _typeT& _a) {\n      if constexpr (_debug && _i == 0) print('{');\n\
    \      if constexpr (std::tuple_size_v<_typeT> != 0) print(std::get<_i>(_a));\n\
    \      if constexpr (_i + 1 < std::tuple_size_v<_typeT>) {\n        if constexpr\
    \ (_sep) _print_sep();\n        print<_i + 1>(_a);\n      } else if constexpr\
    \ (_debug) print('}');\n    }\n    template<class _typeT, std::enable_if_t<is_range_v<_typeT>\
    \ && !_has_print<_typeT>::value>* = nullptr>\n    void print(const _typeT& _a)\
    \ {\n      if constexpr (_debug) print('{');\n      if (std::empty(_a)) return;\n\
    \      for (auto _i = std::begin(_a); ; ) {\n        print(*_i);\n        if (++_i\
    \ != std::end(_a)) {\n          if constexpr (_sep) {\n            if constexpr\
    \ (_debug) {\n              print(',');\n              print(' ');\n         \
    \   } else if constexpr (std::is_arithmetic_v<std::decay_t<decltype(std::declval<_typeT>()[0])>>)\
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
    \ debug(output.begin()), edebug(error.begin());\n}\n#line 9 \"template/alias.hpp\"\
    \n#include <set>\n#include <map>\n#include <unordered_set>\n#line 19 \"template/alias.hpp\"\
    \n\nnamespace kyopro {\n  using ll = long long;\n  using ull = unsigned long long;\n\
    \  using lf = double;\n\n  using i8 = std::int8_t;\n  using u8 = std::uint8_t;\n\
    \  using i16 = std::int16_t;\n  using u16 = std::uint16_t;\n  using i32 = std::int32_t;\n\
    \  using u32 = std::uint32_t;\n  using i64 = std::int64_t;\n  using u64 = std::uint64_t;\n\
    \  using i128 = __int128_t;\n  using u128 = __uint128_t;\n  #ifdef __SIZEOF_FLOAT128__\n\
    \  using f128 = __float128;\n  #endif\n\n  using mint = ModInt<mod>;\n  using\
    \ dmint = DynamicModInt<KYOPRO_BASE_UINT>;\n\n  template<class _typeT, KYOPRO_BASE_UINT\
    \ _idx, class... _typeArgs>\n  struct _agg_type {\n    using type = typename _agg_type<_typeT,\
    \ _idx - 1, _typeT, _typeArgs...>::type;\n  };\n  template<class _typeT, class...\
    \ _typeArgs>\n  struct _agg_type<_typeT, 0, _typeArgs...> {\n    using type =\
    \ std::tuple<_typeArgs...>;\n  };\n  template<class _typeT>\n  struct _agg_type<_typeT,\
    \ 0, _typeT, _typeT> {\n    using type = std::pair<_typeT, _typeT>;\n  };\n\n\
    \  template<class _typeT, KYOPRO_BASE_UINT _idx>\n  using agg = typename _agg_type<_typeT,\
    \ _idx>::type;\n\n  template<class _typeT>\n  using vec = std::vector<_typeT>;\n\
    \  template<class _typeT>\n  using vvec = std::vector<vec<_typeT>>;\n  template<class\
    \ _typeT>\n  using vvvec = std::vector<vvec<_typeT>>;\n  template<class _typeT>\n\
    \  using vvvvec = std::vector<vvvec<_typeT>>;\n  template<class _typeT>\n  using\
    \ vvvvvec = std::vector<vvvvec<_typeT>>;\n\n  template<class _typeKey, class _typeCompare\
    \ = std::less<_typeKey>>\n  using mset = std::unordered_set<_typeKey, _typeCompare>;\n\
    \  template<class _typeKey, class _typeT, class _typeCompare = std::less<_typeKey>>\n\
    \  using mmap = std::unordered_map<_typeKey, _typeT, _typeCompare>;\n  template<class\
    \ _typeKey>\n  using hset = std::unordered_set<_typeKey, Hash<_typeKey>>;\n  template<class\
    \ _typeKey, class _typeT>\n  using hmap = std::unordered_map<_typeKey, _typeT,\
    \ Hash<_typeKey>>;\n  template<class _typeKey>\n  using hmiset = std::unordered_multiset<_typeKey,\
    \ Hash<_typeKey>>;\n  template<class _typeKey, class _typeT>\n  using hmmap =\
    \ std::unordered_multimap<_typeKey, _typeT, Hash<_typeKey>>;\n  template<class\
    \ _typeT, class _typeCompare = std::less<_typeT>, class _typeContainer = std::vector<_typeT>>\n\
    \  using priq = std::priority_queue<_typeT, _typeContainer, _typeCompare>;\n \
    \ template<class _typeT, class _typeCompare = std::greater<_typeT>, class _typeContainer\
    \ = std::vector<_typeT>>\n  using heapq = priq<_typeT, _typeCompare, _typeContainer>;\n\
    }\n\nusing namespace std;\nusing namespace kyopro;\n#line 2 \"template/amin_amax.hpp\"\
    \n\nnamespace kyopro {\n  template<class _typeT, class _typeU>\n  constexpr bool\
    \ amin(_typeT& a, _typeU&& b) noexcept {\n    if (b < a) {\n      a = b;\n   \
    \   return true;\n    }\n    return false;\n  }\n\n  template<class _typeT, class\
    \ _typeU>\n  constexpr bool amax(_typeT& a, _typeU&& b) noexcept {\n    if (a\
    \ < b) {\n      a = b;\n      return true;\n    }\n    return false;\n  }\n}\n\
    #line 4 \"template/constant.hpp\"\n\nnamespace kyopro {\n  inline constexpr std::array<std::pair<KYOPRO_BASE_INT,\
    \ KYOPRO_BASE_INT>, 4> beside{{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}};\n  inline constexpr\
    \ std::array<std::pair<KYOPRO_BASE_INT, KYOPRO_BASE_INT>, 8> around{{{1, 0}, {1,\
    \ 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}}};\n}\n#line 4 \"template/len.hpp\"\
    \n\nnamespace kyopro {\n  template<class _typeT>\n  constexpr KYOPRO_BASE_INT\
    \ len(_typeT&& _a) noexcept {\n    return std::size(_a);\n  }\n}\n#line 5 \"template/macro.hpp\"\
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
    \ + 1>(_d, _init));\n    else return _init;\n  }\n}\n#line 4 \"template/min_max_different_types.hpp\"\
    \n\nusing std::min, std::max;\n\ntemplate<class _typeT, class _typeU, std::enable_if_t<!std::is_same_v<_typeT,\
    \ _typeU>>* = nullptr>\nconstexpr std::common_type_t<_typeT, _typeU> min(const\
    \ _typeT& a, const _typeU& b) noexcept {\n  return a < b ? a : b;\n}\n\ntemplate<class\
    \ _typeT, class _typeU, std::enable_if_t<!std::is_same_v<_typeT, _typeU>>* = nullptr>\n\
    constexpr std::common_type_t<_typeT, _typeU> max(const _typeT& a, const _typeU&\
    \ b) noexcept {\n  return a > b ? a : b;\n}\n#line 9 \"all/all.hpp\"\n"
  code: '#pragma once

    #include "../algorithm/all.hpp"

    #include "../function/all.hpp"

    #include "../math/all.hpp"

    #include "../meta/all.hpp"

    #include "../structure/all.hpp"

    #include "../system/all.hpp"

    #include "../template/all.hpp"'
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
  - math/mod.hpp
  - math/Montgomery.hpp
  - math/euler_phi.hpp
  - math/factorize.hpp
  - math/is_prime.hpp
  - math/ModInt.hpp
  - meta/all.hpp
  - structure/all.hpp
  - structure/FenwickTree.hpp
  - structure/UnionFind.hpp
  - system/all.hpp
  - system/in.hpp
  - system/out.hpp
  - template/all.hpp
  - template/alias.hpp
  - template/amin_amax.hpp
  - template/constant.hpp
  - template/len.hpp
  - template/macro.hpp
  - template/make_array.hpp
  - template/make_vector.hpp
  - template/min_max_different_types.hpp
  isVerificationFile: false
  path: all/all.hpp
  requiredBy: []
  timestamp: '2022-04-19 15:37:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: all/all.hpp
layout: document
redirect_from:
- /library/all/all.hpp
- /library/all/all.hpp.html
title: all/all.hpp
---
