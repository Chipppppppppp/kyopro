---
data:
  _extendedDependsOn:
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
    path: structure/UnionFind.hpp
    title: structure/UnionFind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"yosupo/UnionFind.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n#include <iostream>\n#line 2 \"structure/UnionFind.hpp\"\n/* UnionFind */\n\
    #include <algorithm>\n#include <unordered_map>\n#include <vector>\n#line 2 \"\
    base/settings.hpp\"\n#include <cstdint>\n\n#ifndef KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT\
    \ std::int64_t\n#endif\n\n#ifndef KYOPRO_BASE_UINT\n#define KYOPRO_BASE_UINT std::size_t\n\
    #endif\n\n#ifndef KYOPRO_BASE_FLOAT\n#define KYOPRO_BASE_FLOAT double\n#endif\n\
    \n#ifndef KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD static_cast<KYOPRO_BASE_UINT>(1000000007)\n\
    #endif\n\n#ifndef KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n\
    #endif\n\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 7 \"structure/UnionFind.hpp\"\n\nnamespace kyopro {\n  struct UnionFind\
    \ {\n  private:\n    std::vector<int> _par;\n\n  public:\n    UnionFind() noexcept\
    \ = default;\n    UnionFind(KYOPRO_BASE_UINT _n) noexcept: _par(_n, -1) {}\n\n\
    \    void resize(KYOPRO_BASE_UINT _x) { _par.resize(_x, -1); }\n    void assign(KYOPRO_BASE_UINT\
    \ _x) { _par.assign(_x, -1); }\n    void reset() { std::fill(std::begin(_par),\
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
    \    }\n  };\n}\n#line 2 \"base/out.hpp\"\n#include <unistd.h>\n#include <array>\n\
    #line 5 \"base/out.hpp\"\n#include <cstdio>\n#include <iterator>\n#include <string>\n\
    #include <tuple>\n#include <type_traits>\n#include <utility>\n#line 3 \"base/trait.hpp\"\
    \n#include <queue>\n#include <stack>\n#line 7 \"base/trait.hpp\"\n\n#ifdef __SIZEOF_INT128__\n\
    template<>\nstruct std::is_integral<__int128_t>: std::true_type {};\ntemplate<>\n\
    struct std::is_signed<__int128_t>: std::true_type {};\ntemplate<>\nstruct std::is_integral<__uint128_t>:\
    \ std::true_type {};\ntemplate<>\nstruct std::is_unsigned<__uint128_t>: std::true_type\
    \ {};\n#endif\n#ifdef __SIZEOF_FLOAT128__\ntemplate<>\nstruct std::is_floating_point<__float128>:\
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
    \ std::true_type {};\n\n    void _print_sep() {\n      if constexpr (_debug) {\n\
    \        print(',');\n      }\n      print(' ');\n    }\n\n  public:\n    static\
    \ constexpr bool sep = _sep, end = _end, debug = _debug, flush = _flush;\n   \
    \ static constexpr KYOPRO_BASE_UINT decimal_precision = _decimal_precision;\n\n\
    \    typename _typeWriter::iterator itr;\n\n    Printer() noexcept = default;\n\
    \    Printer(_typeWriter& _writer) noexcept: itr(_writer.begin()) {}\n\n    void\
    \ print(char _a) {\n      *itr = _a;\n      ++itr;\n    }\n    void print(const\
    \ char* _a) {\n      for (; *_a; ++_a) print(*_a);\n    }\n    void print(const\
    \ std::string& _a) {\n      for (auto _i: _a) print(_i);\n    }\n    void print(bool\
    \ _a) {\n      print(static_cast<char>('0' + _a));\n    }\n    template<class\
    \ _typeT, std::enable_if_t<std::is_arithmetic_v<_typeT> && !_has_print<_typeT>::value>*\
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
    \ (_flush) itr._flush();\n    }\n    template<bool _first = true, class _typeHead,\
    \ class... _typeArgs>\n    void operator ()(_typeHead&& _head, _typeArgs&&...\
    \ _args) {\n      if constexpr (_debug && _first) {\n        print('#');\n   \
    \     print(' ');\n      }\n      if constexpr (_sep && !_first) _print_sep();\n\
    \      print(_head);\n      operator ()<false>(std::forward<_typeArgs>(_args)...);\n\
    \    }\n  };\n\n  Printer<Writer<>, false, false, false> print(output), eprint(error);\n\
    \  Printer<Writer<>, true, true, false> println(output), eprintln(error);\n  Printer<Writer<>>\
    \ debug(output), edebug(error);\n}\n#line 5 \"yosupo/UnionFind.test.cpp\"\n\n\
    int main() {\n  int n, q;\n  std::cin >> n >> q;\n  kyopro::UnionFind uf(n);\n\
    \  for (int i = 0; i < q; ++i) {\n    int t, u, v;\n    std::cin >> t >> u >>\
    \ v;\n    if (t == 0) uf.merge(u, v);\n    else kyopro::println(uf.same(u, v));\n\
    \  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#include <iostream>\n\
    #include \"../structure/UnionFind.hpp\"\n#include \"../base/out.hpp\"\n\nint main()\
    \ {\n  int n, q;\n  std::cin >> n >> q;\n  kyopro::UnionFind uf(n);\n  for (int\
    \ i = 0; i < q; ++i) {\n    int t, u, v;\n    std::cin >> t >> u >> v;\n    if\
    \ (t == 0) uf.merge(u, v);\n    else kyopro::println(uf.same(u, v));\n  }\n}\n"
  dependsOn:
  - structure/UnionFind.hpp
  - base/settings.hpp
  - base/out.hpp
  - base/trait.hpp
  isVerificationFile: true
  path: yosupo/UnionFind.test.cpp
  requiredBy: []
  timestamp: '2022-03-09 23:05:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: yosupo/UnionFind.test.cpp
layout: document
redirect_from:
- /verify/yosupo/UnionFind.test.cpp
- /verify/yosupo/UnionFind.test.cpp.html
title: yosupo/UnionFind.test.cpp
---
