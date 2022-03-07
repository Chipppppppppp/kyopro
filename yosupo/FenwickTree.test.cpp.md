---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base/constant.hpp
    title: base/constant.hpp
  - icon: ':heavy_check_mark:'
    path: base/out.hpp
    title: base/out.hpp
  - icon: ':heavy_check_mark:'
    path: base/settings.hpp
    title: base/settings.hpp
  - icon: ':heavy_check_mark:'
    path: base/trait.hpp
    title: base/trait.hpp
  - icon: ':heavy_check_mark:'
    path: math/monoid.hpp
    title: math/monoid.hpp
  - icon: ':heavy_check_mark:'
    path: math/power.hpp
    title: math/power.hpp
  - icon: ':heavy_check_mark:'
    path: structure/FenwickTree.hpp
    title: structure/FenwickTree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"yosupo/FenwickTree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\
    \n#include <iostream>\n#line 2 \"structure/FenwickTree.hpp\"\n/* FenwickTree */\n\
    #include <utility>\n#include <vector>\n#line 2 \"base/settings.hpp\"\n#include\
    \ <cstdint>\n\n#ifndef KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT std::int64_t\n\
    #endif\n\n#ifndef KYOPRO_BASE_UINT\n#define KYOPRO_BASE_UINT std::size_t\n#endif\n\
    \n#ifndef KYOPRO_BASE_FLOAT\n#define KYOPRO_BASE_FLOAT double\n#endif\n\n#ifndef\
    \ KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD static_cast<KYOPRO_BASE_UINT>(1000000007)\n\
    #endif\n\n#ifndef KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n\
    #endif\n\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 2 \"math/monoid.hpp\"\n#include <type_traits>\n#line 2 \"base/constant.hpp\"\
    \n#include <array>\n#line 4 \"base/constant.hpp\"\n#include <limits>\n#line 4\
    \ \"math/power.hpp\"\nnamespace kyopro {\n  template<class _typeT>\n  constexpr\
    \ _typeT power(_typeT _a, std::uint_fast64_t _n, _typeT _init = 1) noexcept {\n\
    \    while (_n > 0) {\n      if (_n & 1) _init *= _a;\n      _a *= _a;\n     \
    \ _n >>= 1;\n    }\n    return _init;\n  }\n}\n#line 8 \"base/constant.hpp\"\n\
    \nnamespace kyopro {\n  template<class _typeT>\n  inline constexpr _typeT MOD\
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
    \ -1}, {0, -1}, {1, -1}}};\n}\n#line 4 \"math/monoid.hpp\"\n\nnamespace kyopro\
    \ {\n  template<class _typeT, _typeT _id = 0>\n  struct Plus {\n    static constexpr\
    \ _typeT id = _id;\n    static constexpr _typeT op(_typeT _a, _typeT _b) noexcept\
    \ { return _a + _b; }\n    static constexpr _typeT inv(_typeT _a) noexcept { return\
    \ -_a; }\n  };\n  template<class _typeT, _typeT _id = 1>\n  struct Mul {\n   \
    \ static constexpr _typeT id = _id;\n    static constexpr _typeT op(_typeT _a,\
    \ _typeT _b) noexcept { return _a * _b; }\n    static constexpr _typeT inv(_typeT\
    \ _a) noexcept {\n      static_assert(!std::is_integral_v<_typeT>);\n      return\
    \ 1 / _a;\n    }\n  };\n  template<class _typeT, _typeT _id = -inf>\n  struct\
    \ Max {\n    static constexpr _typeT id = _id;\n    static constexpr _typeT op(_typeT\
    \ _a, _typeT _b) noexcept { return _a > _b ? _a : _b; }\n  };\n  template<class\
    \ _typeT, _typeT _id = inf>\n  struct Min {\n    static constexpr _typeT id =\
    \ _id;\n    static constexpr _typeT op(_typeT _a, _typeT _b) noexcept { return\
    \ _a < _b ? _a : _b; }\n  };\n}\n#line 7 \"structure/FenwickTree.hpp\"\n\nnamespace\
    \ kyopro {\n  template<class _typeT, class _typeOp = Plus<_typeT>>\n  struct FenwickTree\
    \ {\n  private:\n    std::vector<_typeT> _tree;\n\n  public:\n    using value_type\
    \ = _typeT;\n    using size_type = KYOPRO_BASE_UINT;\n    using reference = _typeT&;\n\
    \    using const_reference = const _typeT&;\n\n    FenwickTree() noexcept = default;\n\
    \    FenwickTree(KYOPRO_BASE_UINT _n) noexcept: _tree(_n, _typeOp::id) {}\n\n\
    \    KYOPRO_BASE_UINT size() noexcept { return _tree.size(); }\n\n    void apply(int\
    \ _p, const _typeT& _x) {\n      ++_p;\n      while (_p <= (int)size()) {\n  \
    \      _tree[_p - 1] = _typeOp::op(_tree[_p - 1], _x);\n        _p += _p & -_p;\n\
    \      }\n    }\n\n    _typeT prod(int _r) const {\n      _typeT _s = _typeOp::id;\n\
    \      while (_r > 0) {\n        _s = _typeOp::op(_s, _tree[_r - 1]);\n      \
    \  _r -= _r & -_r;\n      }\n      return _s;\n    }\n    _typeT prod(int _l,\
    \ int _r) const { return _typeOp::op(prod(_r), _typeOp::inv(prod(_l))); }\n\n\
    \    _typeT all_prod() { return prod(_tree.size()); }\n\n    _typeT get(int _p)\
    \ { return _typeOp::op(prod(_p + 1), _typeOp::inv(prod(_p))); }\n\n    void set(int\
    \ _p, const _typeT& _x) { apply(_p, _typeOp::op(_x, _typeOp::inv(get(_p)))); }\n\
    \  };\n}\n#line 2 \"base/out.hpp\"\n#include <unistd.h>\n#line 5 \"base/out.hpp\"\
    \n#include <cstdio>\n#include <iterator>\n#include <string>\n#include <tuple>\n\
    #line 3 \"base/trait.hpp\"\n#include <queue>\n#include <stack>\n#line 7 \"base/trait.hpp\"\
    \n\n#ifdef __SIZEOF_INT128__\ntemplate<>\nstruct std::is_integral<__int128_t>:\
    \ std::true_type {};\ntemplate<>\nstruct std::is_signed<__int128_t>: std::true_type\
    \ {};\ntemplate<>\nstruct std::is_integral<__uint128_t>: std::true_type {};\n\
    template<>\nstruct std::is_unsigned<__uint128_t>: std::true_type {};\n#endif\n\
    #ifdef __SIZEOF_FLOAT128__\ntemplate<>\nstruct std::is_floating_point<__float128>:\
    \ std::true_type {};\n#endif\n\nnamespace kyopro {\n  template<class, class =\
    \ void>\n  struct is_iterator: std::false_type {};\n  template<class _typeT>\n\
    \  struct is_iterator<_typeT, std::void_t<typename std::iterator_traits<_typeT>::iterator_category>>:\
    \ std::true_type {};\n  template<class _typeT>\n  constexpr bool is_iterator_v\
    \ = is_iterator<_typeT>::value;\n\n  template<class, class = void>\n  struct is_iterable:\
    \ std::false_type {};\n  template<class _typeT>\n  struct is_iterable<_typeT,\
    \ std::void_t<typename _typeT::iterator>>: std::true_type {};\n  template<class\
    \ _typeT>\n  constexpr bool is_iterable_v = is_iterable<_typeT>::value;\n\n  template<class>\n\
    \  struct is_tuple: std::false_type {};\n  template<class _typeT, class U>\n \
    \ struct is_tuple<std::pair<_typeT, U>>: std::true_type {};\n  template<class...\
    \ Args>\n  struct is_tuple<std::tuple<Args...>>: std::true_type {};\n  template<class\
    \ _typeT>\n  constexpr bool is_tuple_v = is_tuple<_typeT>::value;\n\n  template<class,\
    \ class = void>\n  struct is_container_adapter: std::false_type {};\n  template<class\
    \ _typeT>\n  struct is_container_adapter<_typeT, std::void_t<decltype(std::empty(std::declval<_typeT>()))>>:\
    \ std::negation<is_iterable<_typeT>> {};\n  template<class _typeT>\n  constexpr\
    \ bool is_container_adapter_v = is_container_adapter<_typeT>::value;\n}\n#line\
    \ 13 \"base/out.hpp\"\n\nnamespace kyopro {\n  template<KYOPRO_BASE_UINT _buf_size\
    \ = KYOPRO_BUFFER_SIZE>\n  struct Writer {\n  private:\n    int _fd, _idx;\n \
    \   std::array<char, _buf_size> _buffer;\n\n  public:\n    Writer() noexcept =\
    \ default;\n    Writer(int _fd) noexcept: _fd(_fd), _idx(0), _buffer() {}\n  \
    \  Writer(FILE* _fp) noexcept: _fd(fileno_unlocked(_fp)), _idx(0), _buffer() {}\n\
    \n    ~Writer() {\n      write(_fd, _buffer.begin(), _idx);\n    }\n\n    Writer&\
    \ operator =(int _fd) noexcept {\n      this->_fd = _fd;\n      return *this;\n\
    \    }\n    Writer& operator =(FILE* _fp) noexcept {\n      this->_fd = fileno_unlocked(_fp);\n\
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
    \    }\n  };\n\n  Writer output(1), error(2);\n\n  template<class _typeWriter,\
    \ bool _sep = true, bool _end = true, bool _debug = true, bool _flush = false,\
    \ KYOPRO_BASE_UINT _decimal_precision = KYOPRO_DECIMAL_PRECISION>\n  struct Printer\
    \ {\n  private:\n    template<class, class = void>\n    struct _has_print: std::false_type\
    \ {};\n    template<class _typeT>\n    struct _has_print<_typeT, std::void_t<decltype(std::declval<_typeT>().print(std::declval<Printer&>()))>>:\
    \ std::true_type {};\n\n    typename _typeWriter::iterator _itr;\n\n  public:\n\
    \    Printer() noexcept = default;\n    Printer(_typeWriter& _writer) noexcept:\
    \ _itr(_writer.begin()) {}\n\n    void _print_sep() {\n      if constexpr (_debug)\
    \ {\n        print(',');\n      }\n      print(' ');\n    }\n\n    void print(char\
    \ _a) {\n      *_itr = _a;\n      ++_itr;\n    }\n    void print(const char* _a)\
    \ {\n      for (; *_a; ++_a) print(*_a);\n    }\n    void print(const std::string&\
    \ _a) {\n      for (auto _i: _a) print(_i);\n    }\n    void print(bool _a) {\n\
    \      print(static_cast<char>('0' + _a));\n    }\n    template<class _typeT,\
    \ std::enable_if_t<std::is_arithmetic_v<_typeT> && !_has_print<_typeT>::value>*\
    \ = nullptr>\n    void print(_typeT _a) {\n      if constexpr (std::is_signed_v<_typeT>)\
    \ if (_a < 0) {\n        print('-');\n        _a = -_a;\n      }\n      std::uint_fast64_t\
    \ _p = _a;\n      _a -= _p;\n      std::string _s;\n      do {\n        _s +=\
    \ '0' + _p % 10;\n        _p /= 10;\n      } while (_p > 0);\n      for (auto\
    \ _i = _s.rbegin(); _i != _s.rend(); ++_i) print(*_i);\n      if constexpr (std::is_integral_v<_typeT>)\
    \ return;\n      print('.');\n      for (int _i = 0; _i < static_cast<int>(_decimal_precision);\
    \ ++_i) {\n        _a *= 10;\n        print('0' + static_cast<std::uint_fast64_t>(_a)\
    \ % 10);\n      }\n    }\n    template<size_t _i = 0, class _typeT, std::enable_if_t<is_tuple_v<_typeT>\
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
    \ (_flush) _itr._flush();\n    }\n    template<bool _first = true, class _typeHead,\
    \ class... _typeArgs>\n    void operator ()(_typeHead&& _head, _typeArgs&&...\
    \ _args) {\n      if constexpr (_debug && _first) {\n        print('#');\n   \
    \     print(' ');\n      }\n      if constexpr (_sep && !_first) _print_sep();\n\
    \      print(_head);\n      operator ()<false>(std::forward<_typeArgs>(_args)...);\n\
    \    }\n  };\n\n  Printer<Writer<>, false, false, false> print(output), eprint(error);\n\
    \  Printer<Writer<>, true, true, false> println(output), eprintln(error);\n  Printer<Writer<>>\
    \ debug(output), edebug(error);\n}\n#line 5 \"yosupo/FenwickTree.test.cpp\"\n\n\
    int main() {\n  int n, q;\n  std::cin >> n >> q;\n  kyopro::FenwickTree<long long>\
    \ ft(n);\n  for (int i = 0; i < n; ++i) {\n    int a;\n    std::cin >> a;\n  \
    \  ft.apply(i, a);\n  }\n  for (int i = 0; i < q; ++i) {\n    int t, x, y;\n \
    \   std::cin >> t >> x >> y;\n    if (t == 0) ft.apply(x, y);\n    else kyopro::println(ft.prod(x,\
    \ y));\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include <iostream>\n#include \"../structure/FenwickTree.hpp\"\n#include \"../base/out.hpp\"\
    \n\nint main() {\n  int n, q;\n  std::cin >> n >> q;\n  kyopro::FenwickTree<long\
    \ long> ft(n);\n  for (int i = 0; i < n; ++i) {\n    int a;\n    std::cin >> a;\n\
    \    ft.apply(i, a);\n  }\n  for (int i = 0; i < q; ++i) {\n    int t, x, y;\n\
    \    std::cin >> t >> x >> y;\n    if (t == 0) ft.apply(x, y);\n    else kyopro::println(ft.prod(x,\
    \ y));\n  }\n}\n"
  dependsOn:
  - structure/FenwickTree.hpp
  - base/settings.hpp
  - math/monoid.hpp
  - base/constant.hpp
  - math/power.hpp
  - base/out.hpp
  - base/trait.hpp
  isVerificationFile: true
  path: yosupo/FenwickTree.test.cpp
  requiredBy: []
  timestamp: '2022-03-07 16:31:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: yosupo/FenwickTree.test.cpp
layout: document
redirect_from:
- /verify/yosupo/FenwickTree.test.cpp
- /verify/yosupo/FenwickTree.test.cpp.html
title: yosupo/FenwickTree.test.cpp
---