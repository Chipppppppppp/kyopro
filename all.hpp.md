---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: base/Hash.hpp
    title: base/Hash.hpp
  - icon: ':warning:'
    path: base/all.hpp
    title: base/all.hpp
  - icon: ':heavy_check_mark:'
    path: base/constant.hpp
    title: base/constant.hpp
  - icon: ':heavy_check_mark:'
    path: base/in.hpp
    title: base/in.hpp
  - icon: ':heavy_check_mark:'
    path: base/io.hpp
    title: base/io.hpp
  - icon: ':heavy_check_mark:'
    path: base/out.hpp
    title: base/out.hpp
  - icon: ':heavy_check_mark:'
    path: base/settings.hpp
    title: base/settings.hpp
  - icon: ':heavy_check_mark:'
    path: base/trait.hpp
    title: base/trait.hpp
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
  - icon: ':heavy_check_mark:'
    path: math/monoid.hpp
    title: math/monoid.hpp
  - icon: ':heavy_check_mark:'
    path: math/power.hpp
    title: math/power.hpp
  - icon: ':heavy_check_mark:'
    path: structure/FenwickTree.hpp
    title: structure/FenwickTree.hpp
  - icon: ':heavy_check_mark:'
    path: structure/UnionFind.hpp
    title: structure/UnionFind.hpp
  - icon: ':warning:'
    path: structure/all.hpp
    title: structure/all.hpp
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
  bundledCode: "#line 2 \"base/constant.hpp\"\n#include <array>\n#include <cstdint>\n\
    #include <limits>\n#include <utility>\n#line 3 \"base/settings.hpp\"\n\n#ifndef\
    \ KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT std::int64_t\n#endif\n\n#ifndef KYOPRO_BASE_UINT\n\
    #define KYOPRO_BASE_UINT std::uint64_t\n#endif\n\n#ifndef KYOPRO_BASE_FLOAT\n\
    #define KYOPRO_BASE_FLOAT double\n#endif\n\n#ifndef KYOPRO_DEFAULT_MOD\n#define\
    \ KYOPRO_DEFAULT_MOD static_cast<KYOPRO_BASE_UINT>(1000000007)\n#endif\n\n#ifndef\
    \ KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n\
    #endif\n\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 4 \"math/power.hpp\"\n\nnamespace kyopro {\n  template<class _typeT>\n\
    \  constexpr _typeT power(_typeT _a, std::uint_fast64_t _n, _typeT _init = 1)\
    \ noexcept {\n    while (_n > 0) {\n      if (_n & 1) _init *= _a;\n      _a *=\
    \ _a;\n      _n >>= 1;\n    }\n    return _init;\n  }\n}\n#line 8 \"base/constant.hpp\"\
    \n\nnamespace kyopro {\n  template<class _typeT>\n  inline constexpr _typeT MOD\
    \ = KYOPRO_DEFAULT_MOD;\n  inline constexpr KYOPRO_BASE_INT mod = MOD<KYOPRO_BASE_INT>;\n\
    \n  template<class _typeT>\n  inline constexpr _typeT INF = std::numeric_limits<_typeT>::max()\
    \ / KYOPRO_INF_DIV;\n  inline constexpr KYOPRO_BASE_INT inf = INF<KYOPRO_BASE_INT>;\n\
    \n  template<class _typeT, KYOPRO_BASE_UINT _decimal_precision = KYOPRO_DECIMAL_PRECISION>\n\
    \  inline constexpr KYOPRO_BASE_FLOAT EPS = static_cast<_typeT>(1) / power(static_cast<std::uint_fast64_t>(10),\
    \ _decimal_precision);\n  inline constexpr KYOPRO_BASE_FLOAT eps = EPS<KYOPRO_BASE_FLOAT>;\n\
    \n  template<class _typeT>\n  inline constexpr _typeT PI = 3.14159265358979323846;\n\
    \  inline constexpr KYOPRO_BASE_FLOAT pi = PI<KYOPRO_BASE_FLOAT>;\n\n  inline\
    \ constexpr std::array<std::pair<KYOPRO_BASE_INT, KYOPRO_BASE_INT>, 4> beside{{{1,\
    \ 0}, {0, 1}, {-1, 0}, {0, -1}}};\n  inline constexpr std::array<std::pair<KYOPRO_BASE_INT,\
    \ KYOPRO_BASE_INT>, 8> around{{{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1,\
    \ -1}, {0, -1}, {1, -1}}};\n}\n#line 2 \"base/Hash.hpp\"\n#include <cstddef>\n\
    #line 4 \"base/Hash.hpp\"\n#include <functional>\n#include <initializer_list>\n\
    #include <tuple>\n#include <type_traits>\n#line 2 \"base/trait.hpp\"\n#include\
    \ <iterator>\n#include <queue>\n#include <stack>\n#line 7 \"base/trait.hpp\"\n\
    \n#ifdef __SIZEOF_INT128__\ntemplate<>\nstruct std::is_integral<__int128_t>: std::true_type\
    \ {};\ntemplate<>\nstruct std::is_signed<__int128_t>: std::true_type {};\ntemplate<>\n\
    struct std::is_integral<__uint128_t>: std::true_type {};\ntemplate<>\nstruct std::is_unsigned<__uint128_t>:\
    \ std::true_type {};\n#endif\n#ifdef __SIZEOF_FLOAT128__\ntemplate<>\nstruct std::is_floating_point<__float128>:\
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
    \ >> 4);\n      return _seed;\n    }\n  };\n}\n#line 2 \"base/in.hpp\"\n#include\
    \ <unistd.h>\n#line 6 \"base/in.hpp\"\n#include <cstdio>\n#include <string>\n\
    #line 14 \"base/in.hpp\"\n\nnamespace kyopro {\n  template<KYOPRO_BASE_UINT _buf_size\
    \ = KYOPRO_BUFFER_SIZE>\n  struct Reader {\n  private:\n    int _fd, _idx;\n \
    \   std::array<char, _buf_size> _buffer;\n\n  public:\n    Reader() {\n      read(_fd,\
    \ _buffer.begin(), _buf_size);\n    }\n    Reader(int _fd): _fd(_fd), _idx(0),\
    \ _buffer() {\n      read(_fd, _buffer.begin(), _buf_size);\n    }\n    Reader(FILE*\
    \ _fp): _fd(fileno(_fp)), _idx(0), _buffer() {\n      read(_fd, _buffer.begin(),\
    \ _buf_size);\n    }\n\n    Reader& operator =(int _fd) noexcept {\n      this->_fd\
    \ = _fd;\n      return *this;\n    }\n    Reader& operator =(FILE* _fp) noexcept\
    \ {\n      this->_fd = fileno(_fp);\n      return *this;\n    }\n\n    struct\
    \ iterator {\n    private:\n      Reader& _reader;\n\n    public:\n      using\
    \ difference_type = void;\n      using value_type = void;\n      using pointer\
    \ = void;\n      using reference = void;\n      using iterator_category = std::input_iterator_tag;\n\
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
    \ if (_sgn) _a = -_a;\n    }\n    template<std::size_t _i = 0, class _typeT, std::enable_if_t<is_tuple_v<_typeT>\
    \ && !_has_scan<_typeT>::value>* = nullptr>\n    void scan(_typeT& _a) {\n   \
    \   if constexpr (_i < std::tuple_size_v<_typeT>) {\n        scan(std::get<_i>(_a));\n\
    \        scan<_i + 1>(_a);\n      }\n    }\n    template<class _typeT, std::enable_if_t<is_iterable_v<_typeT>\
    \ && !_has_scan<_typeT>::value>* = nullptr>\n    void scan(_typeT& _a) {\n   \
    \   for (auto& _i: _a) scan(_i);\n    }\n    template<class _typeT, std::enable_if_t<_has_scan<_typeT>::value>*\
    \ = nullptr>\n    void scan(const _typeT& _a) {\n      _a.scan(*this);\n    }\n\
    \n    void operator ()() {}\n    template<class _typeHead, class... _typeArgs>\n\
    \    void operator ()(_typeHead& _head, _typeArgs&... _args) {\n      scan(_head);\n\
    \      operator ()(_args...);\n    }\n  };\n\n  Scanner<Reader<>::iterator> scan(input.begin());\n\
    }\n#line 13 \"base/out.hpp\"\n\nnamespace kyopro {\n  template<KYOPRO_BASE_UINT\
    \ _buf_size = KYOPRO_BUFFER_SIZE>\n  struct Writer {\n  private:\n    int _fd,\
    \ _idx;\n    std::array<char, _buf_size> _buffer;\n\n  public:\n    Writer() noexcept\
    \ = default;\n    Writer(int _fd) noexcept: _fd(_fd), _idx(0), _buffer() {}\n\
    \    Writer(FILE* _fp) noexcept: _fd(fileno(_fp)), _idx(0), _buffer() {}\n\n \
    \   ~Writer() {\n      write(_fd, _buffer.begin(), _idx);\n    }\n\n    Writer&\
    \ operator =(int _fd) noexcept {\n      this->_fd = _fd;\n      return *this;\n\
    \    }\n    Writer& operator =(FILE* _fp) noexcept {\n      this->_fd = fileno(_fp);\n\
    \      return *this;\n    }\n\n    struct iterator {\n    private:\n      Writer&\
    \ _writer;\n\n    public:\n      using difference_type = void;\n      using value_type\
    \ = void;\n      using pointer = void;\n      using reference = void;\n      using\
    \ iterator_category = std::output_iterator_tag;\n\n      iterator() noexcept =\
    \ default;\n      iterator(Writer& _writer) noexcept: _writer(_writer) {}\n\n\
    \      iterator& operator ++() {\n        ++_writer._idx;\n        if (_writer._idx\
    \ == _buf_size) {\n          write(_writer._fd, _writer._buffer.begin(), _buf_size);\n\
    \          _writer._idx = 0;\n        }\n        return *this;\n      }\n\n  \
    \    iterator operator ++(int) {\n        iterator _before = *this;\n        operator\
    \ ++();\n        return _before;\n      }\n\n      char& operator *() const {\n\
    \        return _writer._buffer[_writer._idx];\n      }\n\n      void flush()\
    \ const {\n        write(_writer._fd, _writer._buffer.begin(), _writer._idx);\n\
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
    \ _typeT& _a) {\n      _a.print(*this);\n    }\n\n    template<bool = true>\n\
    \    void operator ()() {\n      if constexpr (_end) print('\\n');\n      if constexpr\
    \ (_flush) itr._flush();\n    }\n    template<bool _first = true, class _typeHead,\
    \ class... _typeArgs>\n    void operator ()(_typeHead&& _head, _typeArgs&&...\
    \ _args) {\n      if constexpr (_comment && _first) {\n        print('#');\n \
    \       print(' ');\n      }\n      if constexpr (_sep && !_first) _print_sep();\n\
    \      print(_head);\n      operator ()<false>(std::forward<_typeArgs>(_args)...);\n\
    \    }\n  };\n\n  Printer<Writer<>::iterator, false, false> print(output.begin()),\
    \ eprint(error.begin());\n  Printer<Writer<>::iterator> println(output.begin()),\
    \ eprintln(error.begin());\n  Printer<Writer<>::iterator, true, true, true, true>\
    \ debug(output.begin()), edebug(error.begin());\n}\n#line 3 \"math/div.hpp\"\n\
    \nnamespace kyopro {\n  template<class _typeT, class _typeU>\n  constexpr std::common_type_t<_typeT,\
    \ _typeU> floor_div(_typeT _x, _typeU _m) noexcept {\n    static_assert(std::is_integral_v<_typeT>\
    \ && std::is_integral_v<_typeU>);\n    if constexpr (std::is_unsigned_v<_typeT>\
    \ || std::is_unsigned_v<_typeU>) return _x / _m;\n    auto _d = _x / _m;\n   \
    \ return _d * _m == _x ? _d : _d - ((_x < 0) ^ (_m < 0));\n  }\n\n  template<class\
    \ _typeT, class _typeU>\n  constexpr std::common_type_t<_typeT, _typeU> ceil_div(_typeT\
    \ _x, _typeU _m) noexcept { return floor_div(_x + _m - static_cast<_typeT>(1),\
    \ _m); }\n}\n#line 3 \"math/divisors.hpp\"\n#include <vector>\n#line 5 \"math/divisors.hpp\"\
    \n\nnamespace kyopro {\n  template<class _typeContainer = std::vector<KYOPRO_BASE_INT>>\n\
    \  _typeContainer divisors(std::uint_fast64_t _n) {\n    _typeContainer _lower,\
    \ _upper;\n    std::uint_fast64_t _i;\n    for (_i = 1; _i * _i < _n; ++_i) if\
    \ (_n % _i == 0) {\n      _lower.emplace_back(_i);\n      _upper.emplace_back(_n\
    \ / _i);\n    }\n    if (_i * _i == _n) _lower.emplace_back(_i);\n    _lower.insert(end(_lower),\
    \ rall(_upper));\n    return _lower;\n  }\n}\n#line 3 \"math/euler_phi.hpp\"\n\
    \nnamespace kyopro {\n  constexpr std::uint_fast64_t euler_phi(std::uint_fast64_t\
    \ _n) noexcept {\n    std::uint_fast64_t _res = _n;\n    if ((_n & 1) == 0) {\n\
    \      _res -= _res >> 1;\n      _n >>= 1;\n      while ((_n & 1) == 0) _n >>=\
    \ 1;\n    }\n    for (std::uint_fast64_t _i = 3; _i * _i <= _n; _i += 2) {\n \
    \     if (_n % _i == 0) {\n        _res -= _res / _i;\n        _n /= _i;\n   \
    \     while (_n % _i == 0) _n /= _i;\n      }\n    }\n    if (_n != 1) _res -=\
    \ _res / _n;\n    return _res;\n  }\n}\n#line 6 \"math/factorize.hpp\"\n\nnamespace\
    \ kyopro {\n  template<class _typeContainer = std::vector<KYOPRO_BASE_INT>>\n\
    \  _typeContainer factorize(std::uint_fast64_t _n) {\n    _typeContainer _res;\n\
    \    while ((_n & 1) == 0) {\n      _res.emplace_back(2);\n      _n >>= 1;\n \
    \   }\n    for (std::uint_fast64_t _i = 3; _i * _i <= _n; _i += 2) while (_n %\
    \ _i == 0) {\n      _res.emplace_back(2);\n      _n /= _i;\n    }\n    if (_n\
    \ != 1) _res.emplace_back(_n);\n    return _res;\n  }\n}\n#line 3 \"math/is_prime.hpp\"\
    \n\nnamespace kyopro {\n  constexpr bool is_prime(std::uint_fast64_t _n) noexcept\
    \ {\n    if (_n < 2) return false;\n    if (_n < 4) return true;\n    if ((_n\
    \ & 1) == 0 || _n % 3 == 0) return false;\n    for (std::uint_fast64_t _i = 5;\
    \ _i * _i <= _n; _i += 4) {\n      if (_n % _i == 0) return false;\n      if (_n\
    \ % (_i += 2) == 0) return false;\n    }\n    return true;\n  }\n}\n#line 2 \"\
    math/mod.hpp\"\n#include <cassert>\n#line 4 \"math/mod.hpp\"\n\nnamespace kyopro\
    \ {\n  template<class _typeT, class _typeU>\n  constexpr std::common_type_t<_typeT,\
    \ _typeU> floor_mod(_typeT _x, _typeU _m) noexcept {\n    static_assert(std::is_integral_v<_typeT>\
    \ && std::is_integral_v<_typeU>);\n    if constexpr (std::is_unsigned_v<_typeT>\
    \ || std::is_unsigned_v<_typeU>) return _x % _m;\n    return (_x %= _m) < 0 ?\
    \ _x + _m : _x;\n  }\n\n  template<class _typeT, class _typeU>\n  constexpr std::common_type_t<_typeT,\
    \ _typeU> ceil_mod(_typeT _x, _typeU _m) noexcept {\n    return _m - floor_mod(_x\
    \ - 1, _m) - static_cast<_typeT>(1);\n  }\n}\n#line 9 \"math/ModInt.hpp\"\n\n\
    namespace kyopro {\n  template<KYOPRO_BASE_UINT _m>\n  struct ModInt {\n    static\
    \ constexpr KYOPRO_BASE_UINT mod = _m;\n    KYOPRO_BASE_UINT value;\n\n    constexpr\
    \ ModInt() noexcept = default;\n    template<class _typeT>\n    constexpr ModInt(_typeT\
    \ value) noexcept: value(floor_mod(value, _m)) { static_assert(std::is_integral_v<_typeT>);\
    \ }\n\n    template<class _typeT>\n    explicit constexpr operator _typeT() const\
    \ noexcept { return value; }\n\n    static constexpr ModInt raw(std::uint_fast64_t\
    \ _n) noexcept {\n      ModInt _res;\n      _res.value = _n;\n      return _res;\n\
    \    }\n\n    constexpr ModInt power(std::uint_fast64_t _n) const noexcept {\n\
    \      std::uint_fast64_t _res = 1, _a = value;\n      while (_n > 0) {\n    \
    \    if (_n & 1) _res = _res * _a % _m;\n        _a = _a * _a % _m;\n        _n\
    \ >>= 1;\n      }\n      return _res;\n    }\n\n    constexpr ModInt inv() const\
    \ noexcept {\n      std::uint_fast64_t _a = value, _b = _m;\n      std::int_fast64_t\
    \ _u = 1, _v = 0;\n      while (_b > 0) {\n        std::uint_fast64_t _t = _a\
    \ / _b;\n        _a -= _t * _b;\n        std::swap(_a, _b);\n        _u -= _t\
    \ * _v;\n        std::swap(_u, _v);\n      }\n      return floor_mod(_u, _m);\n\
    \    }\n\n    constexpr ModInt operator +() const noexcept { return *this; }\n\
    \n    constexpr ModInt operator -() const noexcept { return _m - value; }\n\n\
    \    constexpr ModInt& operator ++() noexcept {\n      if (++value >= _m) value\
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
    \ _typeScanner>\n    void scan(_typeScanner& _scanner) const {\n      std::int_fast64_t\
    \ _value;\n      _scanner.scan(_value);\n      operator =(_value);\n    }\n  \
    \  template<class _typePrinter>\n    void print(_typePrinter& _printer) const\
    \ {\n      _printer.print(value);\n    }\n  };\n\n  template<KYOPRO_BASE_UINT\
    \ _m>\n  struct Hash<ModInt<_m>> { constexpr std::size_t operator ()(ModInt<_m>\
    \ _a) const noexcept { return _a; } };\n}\n#line 4 \"math/monoid.hpp\"\n\nnamespace\
    \ kyopro {\n  template<class _typeT, _typeT _id = 0>\n  struct Plus {\n    static_assert(std::is_arithmetic_v<_typeT>);\n\
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
    \ noexcept { return _a < _b ? _a : _b; }\n  };\n}\n#line 2 \"structure/FenwickTree.hpp\"\
    \n/* FenwickTree */\n#line 7 \"structure/FenwickTree.hpp\"\n\nnamespace kyopro\
    \ {\n  template<class _typeT, class _typeOp = Plus<_typeT>>\n  struct FenwickTree\
    \ {\n  private:\n    [[no_unique_address]] _typeOp _op;\n    std::vector<_typeT>\
    \ _tree;\n\n  public:\n    using value_type = _typeT;\n    using size_type = KYOPRO_BASE_UINT;\n\
    \    using reference = _typeT&;\n    using const_reference = const _typeT&;\n\n\
    \    FenwickTree() noexcept = default;\n    FenwickTree(KYOPRO_BASE_UINT _n) noexcept:\
    \ _op(), _tree(_n, _op.id) {}\n\n    KYOPRO_BASE_UINT size() noexcept { return\
    \ _tree.size(); }\n\n    void apply(int _p, const _typeT& _x) {\n      ++_p;\n\
    \      while (_p <= (int)size()) {\n        _tree[_p - 1] = _op(_tree[_p - 1],\
    \ _x);\n        _p += _p & -_p;\n      }\n    }\n\n    _typeT prod(int _r) const\
    \ {\n      _typeT _s = _op.id;\n      while (_r > 0) {\n        _s = _op(_s, _tree[_r\
    \ - 1]);\n        _r -= _r & -_r;\n      }\n      return _s;\n    }\n    _typeT\
    \ prod(int _l, int _r) const { return _op(prod(_r), _op.inv(prod(_l))); }\n\n\
    \    _typeT all_prod() { return prod(_tree.size()); }\n\n    _typeT get(int _p)\
    \ { return _op(prod(_p + 1), _op.inv(prod(_p))); }\n\n    void set(int _p, const\
    \ _typeT& _x) { apply(_p, _op(_x, _op.inv(get(_p)))); }\n  };\n}\n#line 2 \"structure/UnionFind.hpp\"\
    \n/* UnionFind */\n#include <algorithm>\n#include <unordered_map>\n#line 7 \"\
    structure/UnionFind.hpp\"\n\nnamespace kyopro {\n  struct UnionFind {\n  private:\n\
    \    std::vector<int> _par;\n\n  public:\n    UnionFind() noexcept = default;\n\
    \    UnionFind(KYOPRO_BASE_UINT _n) noexcept: _par(_n, -1) {}\n\n    void resize(KYOPRO_BASE_UINT\
    \ _x) { _par.resize(_x, -1); }\n    void assign(KYOPRO_BASE_UINT _x) { _par.assign(_x,\
    \ -1); }\n    void reset() { std::fill(std::begin(_par), std::end(_par), -1);\
    \ }\n\n    KYOPRO_BASE_UINT size() const noexcept { return _par.size(); }\n\n\
    \    KYOPRO_BASE_INT find(int _x) {\n      int _p = _x;\n      while (_par[_p]\
    \ >= 0) _p = _par[_p];\n      while (_x != _p) {\n        int _tmp = _x;\n   \
    \     _x = _par[_x];\n        _par[_tmp] = _p;\n      }\n      return _p;\n  \
    \  }\n\n    bool merge(int _x, int _y) {\n      _x = find(_x), _y = find(_y);\n\
    \      if (_x == _y) return false;\n      if (_par[_x] > _par[_y]) {\n       \
    \ int _tmp = _x;\n        _x = _y;\n        _y = _tmp;\n      }\n      _par[_x]\
    \ += _par[_y];\n      _par[_y] = _x;\n      return true;\n    }\n\n    bool same(int\
    \ _x, int _y) { return find(_x) == find(_y); }\n\n    KYOPRO_BASE_INT group_size(int\
    \ _x) { return -_par[find(_x)]; }\n\n    std::vector<int> group_members(int _x)\
    \ {\n      _x = find(_x);\n      std::vector<int> _a;\n      for (int _i = 0;\
    \ _i < (int)(size()); ++_i) if (find(_i) == _x) _a.emplace_back(_i);\n      return\
    \ _a;\n    }\n\n    template<class _typeVector = std::vector<KYOPRO_BASE_INT>>\n\
    \    _typeVector roots() const {\n      _typeVector _a;\n      for (int _i = 0;\
    \ _i < (int)(size()); ++_i) if (_par[_i] < 0) _a.emplace_back(_i);\n      return\
    \ _a;\n    }\n\n    KYOPRO_BASE_INT group_count() const {\n      KYOPRO_BASE_INT\
    \ _cnt = 0;\n      for (int _i = 0; _i < (int)(size()); ++_i) if (_par[_i] < 0)\
    \ ++_cnt;\n      return _cnt;\n    }\n\n    template<class _typeMap = std::unordered_map<KYOPRO_BASE_INT,\
    \ std::vector<KYOPRO_BASE_INT>>>\n    _typeMap all_group_members() {\n      _typeMap\
    \ _group_members;\n      for (int _member = 0; _member < (int)(size()); ++_member)\
    \ _group_members[find(_member)].emplace_back(_member);\n      return _group_members;\n\
    \    }\n  };\n}\n#line 8 \"template/alias.hpp\"\n#include <set>\n#include <map>\n\
    #include <unordered_set>\n#line 16 \"template/alias.hpp\"\n\nnamespace kyopro\
    \ {\n  using ll = long long;\n  using ull = unsigned long long;\n  using lf =\
    \ double;\n\n  using i8 = std::int8_t;\n  using u8 = std::uint8_t;\n  using i16\
    \ = std::int16_t;\n  using u16 = std::uint16_t;\n  using i32 = std::int32_t;\n\
    \  using u32 = std::uint32_t;\n  using i64 = std::int64_t;\n  using u64 = std::uint64_t;\n\
    \  #ifdef __SIZEOF_INT128__\n  using i128 = __int128_t;\n  using u128 = __uint128_t;\n\
    \  #endif\n  #ifdef __SIZEOF_FLOAT128__\n  using f128 = __float128;\n  #endif\n\
    \n  template<class _typeT>\n  using vec = std::vector<_typeT>;\n  using str =\
    \ std::string;\n  template<class Key>\n  using hash_set = std::unordered_set<Key,\
    \ Hash<Key>>;\n  template<class Key, class _typeT>\n  using hash_map = std::unordered_map<Key,\
    \ _typeT, Hash<Key>>;\n  template<class Key>\n  using hash_multiset = std::unordered_multiset<Key,\
    \ Hash<Key>>;\n  template<class Key, class _typeT>\n  using hash_multimap = std::unordered_multimap<Key,\
    \ _typeT, Hash<Key>>;\n  template<class _typeT, class Compare = std::less<_typeT>,\
    \ class Container = vec<_typeT>>\n  using priq = std::priority_queue<_typeT, Container,\
    \ Compare>;\n  template<class _typeT, class Compare = std::greater<_typeT>, class\
    \ Container = vec<_typeT>>\n  using heapq = priq<_typeT, Container, Compare>;\n\
    \n  using pll = std::pair<ll, ll>;\n  using l3 = std::tuple<ll, ll, ll>;\n  using\
    \ l4 = std::tuple<ll, ll, ll, ll>;\n  using l5 = std::tuple<ll, ll, ll, ll, ll>;\n\
    \  using mll = std::map<ll, ll>;\n  using hmll = hash_map<ll, ll>;\n  using mmll\
    \ = std::multimap<ll, ll>;\n  using hmmll = std::multimap<ll, ll>;\n  using sl\
    \ = std::set<ll>;\n  using spll = std::set<pll>;\n  using hsl = hash_set<ll>;\n\
    \  using hspll = hash_set<pll>;\n  using msl = std::multiset<ll>;\n  using mspll\
    \ = std::multiset<pll>;\n  using hmsl = hash_multiset<ll>;\n  using hmspll = hash_multiset<pll>;\n\
    \  using dql = std::deque<ll>;\n  using dqpll = std::deque<pll>;\n  using quel\
    \ = std::queue<ll>;\n  using quepll = std::queue<pll>;\n  using stkl = std::stack<ll>;\n\
    \  using stkpll = std::stack<pll>;\n  using pql = priq<ll>;\n  using pqpll = priq<pll>;\n\
    \  using hql = heapq<ll>;\n  using hqpll = heapq<pll>;\n  using vl = vec<ll>;\n\
    \  using vvl = vec<vl>;\n  using vvvl = vec<vvl>;\n  using vi = vec<int>;\n  using\
    \ vvi = vec<vi>;\n  using vvvi = vec<vvi>;\n  using vf = vec<lf>;\n  using vvf\
    \ = vec<vf>;\n  using vvvf = vec<vvf>;\n  using vb = vec<char>;\n  using vvb =\
    \ vec<vb>;\n  using vvvb = vec<vvb>;\n  using vc = vec<char>;\n  using vvc = vec<vc>;\n\
    \  using vvvc = vec<vvc>;\n  using vs = vec<str>;\n  using vvs = vec<vs>;\n  using\
    \ vvvs = vec<vvs>;\n  using vpll = vec<pll>;\n  using vvpll = vec<vpll>;\n  using\
    \ vvvpll = vec<vvpll>;\n  using vsl = vec<sl>;\n  using vhsl = vec<hsl>;\n  using\
    \ vmll = vec<mll>;\n  using vhmll = vec<hmll>;\n  using mint = ModInt<mod>;\n\
    \  using vm = vec<mint>;\n  using vvm = vec<vm>;\n  using vvvm = vec<vvm>;\n}\n\
    \nusing namespace std;\nusing namespace kyopro;\n#line 6 \"all.hpp\"\n"
  code: '#pragma once

    #include "base/all.hpp"

    #include "math/all.hpp"

    #include "structure/all.hpp"

    #include "template/all.hpp"'
  dependsOn:
  - base/all.hpp
  - base/constant.hpp
  - math/power.hpp
  - base/settings.hpp
  - base/Hash.hpp
  - base/trait.hpp
  - base/io.hpp
  - base/in.hpp
  - base/out.hpp
  - math/all.hpp
  - math/div.hpp
  - math/divisors.hpp
  - math/euler_phi.hpp
  - math/factorize.hpp
  - math/is_prime.hpp
  - math/mod.hpp
  - math/ModInt.hpp
  - math/monoid.hpp
  - structure/all.hpp
  - structure/FenwickTree.hpp
  - structure/UnionFind.hpp
  - template/all.hpp
  - template/alias.hpp
  isVerificationFile: false
  path: all.hpp
  requiredBy: []
  timestamp: '2022-03-11 23:13:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: all.hpp
layout: document
redirect_from:
- /library/all.hpp
- /library/all.hpp.html
title: all.hpp
---
