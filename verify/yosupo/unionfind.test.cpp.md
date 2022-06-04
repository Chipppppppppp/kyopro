---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/power.hpp
    title: math/power.hpp
  - icon: ':heavy_check_mark:'
    path: meta/settings.hpp
    title: meta/settings.hpp
  - icon: ':heavy_check_mark:'
    path: meta/trait.hpp
    title: meta/trait.hpp
  - icon: ':heavy_check_mark:'
    path: structure/UnionFind.hpp
    title: structure/UnionFind.hpp
  - icon: ':heavy_check_mark:'
    path: system/all.hpp
    title: system/all.hpp
  - icon: ':heavy_check_mark:'
    path: system/in.hpp
    title: system/in.hpp
  - icon: ':heavy_check_mark:'
    path: system/out.hpp
    title: system/out.hpp
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
  bundledCode: "#line 1 \"verify/yosupo/unionfind.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n#line 2 \"structure/UnionFind.hpp\"\n#include <algorithm>\n#include <type_traits>\n\
    #include <unordered_map>\n#include <utility>\n#include <vector>\n#line 2 \"meta/settings.hpp\"\
    \n#include <cstdint>\n\n#ifndef KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT std::int64_t\n\
    #endif\n\n#ifndef KYOPRO_BASE_UINT\n#define KYOPRO_BASE_UINT std::uint64_t\n#endif\n\
    \n#ifndef KYOPRO_BASE_FLOAT\n#define KYOPRO_BASE_FLOAT double\n#endif\n\n#ifndef\
    \ KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD static_cast<KYOPRO_BASE_UINT>(998244353)\n\
    #endif\n\n#ifndef KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n\
    #endif\n\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 2 \"meta/trait.hpp\"\n#include <iterator>\n#include <queue>\n#include\
    \ <limits>\n#include <stack>\n#line 9 \"meta/trait.hpp\"\n\ntemplate<>\nstruct\
    \ std::is_integral<__int128_t>: std::true_type {};\ntemplate<>\nstruct std::is_integral<__uint128_t>:\
    \ std::true_type {};\ntemplate<>\nstruct std::is_floating_point<__float128>: std::true_type\
    \ {};\n\nnamespace kpr {\n  template<KYOPRO_BASE_UINT size>\n  struct int_least\
    \ {\n  private:\n    static constexpr auto get_type() noexcept {\n      static_assert(size\
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
    \ <unistd.h>\n#include <array>\n#include <cstddef>\n#line 6 \"system/in.hpp\"\n\
    #include <cstdio>\n#include <string>\n#include <tuple>\n#line 3 \"math/power.hpp\"\
    \n\nnamespace kpr {\n  template<class T>\n  constexpr T power(T a, KYOPRO_BASE_UINT\
    \ n, T init = 1) noexcept {\n    while (n > 0) {\n      if (n & 1) init *= a;\n\
    \      a *= a;\n      n >>= 1;\n    }\n    return init;\n  }\n}\n#line 14 \"system/in.hpp\"\
    \n\nnamespace kpr {\n  template<KYOPRO_BASE_UINT _buf_size = KYOPRO_BUFFER_SIZE>\n\
    \  struct Reader {\n    static constexpr KYOPRO_BASE_UINT buf_size = _buf_size;\n\
    \n  private:\n    int fd, idx;\n    std::array<char, buf_size> buffer;\n\n  public:\n\
    \    Reader() {\n      read(fd, buffer.begin(), buf_size);\n    }\n    Reader(int\
    \ fd): fd(fd), idx(0), buffer() {\n      read(fd, buffer.begin(), buf_size);\n\
    \    }\n    Reader(FILE* fp): fd(fileno(fp)), idx(0), buffer() {\n      read(fd,\
    \ buffer.begin(), buf_size);\n    }\n\n    struct iterator {\n    private:\n \
    \     Reader& reader;\n\n    public:\n      using difference_type = void;\n  \
    \    using value_type = void;\n      using pointer = void;\n      using reference\
    \ = void;\n      using iterator_category = std::input_iterator_tag;\n\n      iterator()\
    \ noexcept = default;\n      iterator(Reader& reader) noexcept: reader(reader)\
    \ {}\n\n      iterator& operator ++() {\n        ++reader.idx;\n        if (reader.idx\
    \ == buf_size) {\n          read(reader.fd, reader.buffer.begin(), buf_size);\n\
    \          reader.idx = 0;\n        }\n        return *this;\n      }\n\n    \
    \  iterator operator ++(int) {\n        iterator before = *this;\n        operator\
    \ ++();\n        return before;\n      }\n\n      char& operator *() const {\n\
    \        return reader.buffer[reader.idx];\n      }\n    };\n\n    iterator begin()\
    \ noexcept {\n      return iterator(*this);\n    }\n  };\n\n  Reader input(0);\n\
    \n  template<class Iterator, KYOPRO_BASE_UINT _decimal_precision = KYOPRO_DECIMAL_PRECISION>\n\
    \  struct Scanner {\n    using iterator_type = Iterator;\n    static constexpr\
    \ KYOPRO_BASE_UINT decimal_precision = _decimal_precision;\n\n  private:\n   \
    \ template<class, class = void>\n    struct has_scan: std::false_type {};\n  \
    \  template<class T>\n    struct has_scan<T, std::void_t<decltype(std::declval<T>().scan(std::declval<Scanner&>()))>>:\
    \ std::true_type {};\n\n  public:\n    Iterator itr;\n\n    Scanner() noexcept\
    \ = default;\n    Scanner(Iterator itr) noexcept: itr(itr) {}\n\n    void discard_space()\
    \ {\n      while (('\\t' <= *itr && *itr <= '\\r') || *itr == ' ') ++itr;\n  \
    \  }\n\n    void scan(char& a) {\n      discard_space();\n      a = *itr;\n  \
    \    ++itr;\n    }\n    template<class CharT, class Traits>\n    void scan(std::basic_string<CharT,\
    \ Traits>& a) {\n      discard_space();\n      while ((*itr < '\\t' || '\\r' <\
    \ *itr) && *itr != ' ') {\n        a += *itr;\n        ++itr;\n      }\n    }\n\
    \    void scan(bool& a) {\n      discard_space();\n      while ('0' <= *itr &&\
    \ *itr <= '9') {\n        if (*itr != '0') a = true;\n        ++itr;\n      }\n\
    \    }\n    template<class T, std::enable_if_t<std::is_arithmetic_v<T> && !has_scan<T>::value>*\
    \ = nullptr>\n    void scan(T& a) {\n      discard_space();\n      bool sgn =\
    \ false;\n      if constexpr (!std::is_unsigned_v<T>) if (*itr == '-') {\n   \
    \     sgn = true;\n        ++itr;\n      }\n      a = 0;\n      for (; '0' <=\
    \ *itr && *itr <= '9'; ++itr) a = a * 10 + *itr - '0';\n      if (*itr == '.')\
    \ {\n        ++itr;\n        if constexpr (std::is_floating_point_v<T>) {\n  \
    \        constexpr std::uint_fast64_t power_decimal_precision = power(10ULL, decimal_precision);\n\
    \          T d = 0;\n          std::uint_fast64_t i = 1;\n          for (; '0'\
    \ <= *itr && *itr <= '9' && i < power_decimal_precision; i *= 10) {\n        \
    \    d = d * 10 + *itr - '0';\n            ++itr;\n          }\n          a +=\
    \ d / i;\n        }\n        while ('0' <= *itr && *itr <= '9') ++itr;\n     \
    \ }\n      if constexpr (!std::is_unsigned_v<T>) if (sgn) a = -a;\n    }\n   \
    \ template<KYOPRO_BASE_UINT i = 0, class T, std::enable_if_t<is_tuple_v<T> &&\
    \ !has_scan<T>::value>* = nullptr>\n    void scan(T& a) {\n      if constexpr\
    \ (i < std::tuple_size_v<T>) {\n        scan(std::get<i>(a));\n        scan<i\
    \ + 1>(a);\n      }\n    }\n    template<class T, std::enable_if_t<is_iterable_v<T>\
    \ && !has_scan<T>::value>* = nullptr>\n    void scan(T& a) {\n      for (auto&\
    \ i: a) scan(i);\n    }\n    template<class T, std::enable_if_t<has_scan<T>::value>*\
    \ = nullptr>\n    void scan(T& a) {\n      a.scan(*this);\n    }\n\n    void operator\
    \ ()() {}\n    template<class Head, class... Args>\n    void operator ()(Head&\
    \ head, Args&... args) {\n      scan(head);\n      operator ()(args...);\n   \
    \ }\n  };\n\n  Scanner<Reader<>::iterator> scan(input.begin());\n}\n#line 13 \"\
    system/out.hpp\"\n\nnamespace kpr {\n  template<KYOPRO_BASE_UINT _buf_size = KYOPRO_BUFFER_SIZE>\n\
    \  struct Writer {\n    static constexpr KYOPRO_BASE_UINT buf_size = _buf_size;\n\
    \n  private:\n    int fd, idx;\n    std::array<char, buf_size> buffer;\n\n  public:\n\
    \    Writer() noexcept = default;\n    Writer(int fd) noexcept: fd(fd), idx(0),\
    \ buffer() {}\n    Writer(FILE* fp) noexcept: fd(fileno(fp)), idx(0), buffer()\
    \ {}\n\n    ~Writer() {\n      write(fd, buffer.begin(), idx);\n    }\n\n    struct\
    \ iterator {\n    private:\n      Writer& writer;\n\n    public:\n      using\
    \ difference_type = void;\n      using value_type = void;\n      using pointer\
    \ = void;\n      using reference = void;\n      using iterator_category = std::output_iterator_tag;\n\
    \n      iterator() noexcept = default;\n      iterator(Writer& writer) noexcept:\
    \ writer(writer) {}\n\n      iterator& operator ++() {\n        ++writer.idx;\n\
    \        if (writer.idx == buf_size) {\n          write(writer.fd, writer.buffer.begin(),\
    \ buf_size);\n          writer.idx = 0;\n        }\n        return *this;\n  \
    \    }\n\n      iterator operator ++(int) {\n        iterator before = *this;\n\
    \        operator ++();\n        return before;\n      }\n\n      char& operator\
    \ *() const {\n        return writer.buffer[writer.idx];\n      }\n\n      void\
    \ flush() const {\n        write(writer.fd, writer.buffer.begin(), writer.idx);\n\
    \      }\n    };\n\n    iterator begin() noexcept {\n      return iterator(*this);\n\
    \    }\n  };\n\n  Writer output(1), error(2);\n\n  template<class Iterator, bool\
    \ _sep = true, bool _end = true, bool _debug = false, bool _comment = false, bool\
    \ _flush = false, KYOPRO_BASE_UINT _decimal_precision = KYOPRO_DECIMAL_PRECISION>\n\
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
    \ }\n    template<class T, std::enable_if_t<std::is_arithmetic_v<T> && !has_print<T>::value>*\
    \ = nullptr>\n    void print(T a) {\n      if constexpr (std::is_signed_v<T>)\
    \ if (a < 0) {\n        print_char('-');\n        a = -a;\n      }\n      std::uint_fast64_t\
    \ p = a;\n      a -= p;\n      std::string s;\n      do {\n        s += '0' +\
    \ p % 10;\n        p /= 10;\n      } while (p > 0);\n      for (auto i = s.rbegin();\
    \ i != s.rend(); ++i) print_char(*i);\n      if constexpr (std::is_integral_v<T>)\
    \ return;\n      print_char('.');\n      for (int i = 0; i < static_cast<int>(decimal_precision);\
    \ ++i) {\n        a *= 10;\n        print_char('0' + static_cast<std::uint_fast64_t>(a)\
    \ % 10);\n      }\n    }\n    template<KYOPRO_BASE_UINT i = 0, class T, std::enable_if_t<is_tuple_v<T>\
    \ && !has_print<T>::value>* = nullptr>\n    void print(const T& a) {\n      if\
    \ constexpr (debug && i == 0) print_char('{');\n      if constexpr (std::tuple_size_v<T>\
    \ != 0) print(std::get<i>(a));\n      if constexpr (i + 1 < std::tuple_size_v<T>)\
    \ {\n        if constexpr (sep) print_sep();\n        print<i + 1>(a);\n     \
    \ } else if constexpr (debug) print_char('}');\n    }\n    template<class T, std::enable_if_t<is_iterable_v<T>\
    \ && !has_print<T>::value>* = nullptr>\n    void print(const T& a) {\n      if\
    \ constexpr (debug) print_char('{');\n      if (std::empty(a)) return;\n     \
    \ for (auto i = std::begin(a); ; ) {\n        print(*i);\n        if (++i != std::end(a))\
    \ {\n          if constexpr (sep) {\n            if constexpr (debug) {\n    \
    \          print_char(',');\n              print_char(' ');\n            } else\
    \ if constexpr (std::is_arithmetic_v<std::decay_t<decltype(std::declval<T>()[0])>>)\
    \ print_char(' ');\n            else print_char('\\n');\n          }\n       \
    \ } else break;\n      }\n      if constexpr (debug) print_char('}');\n    }\n\
    \    template<class T, std::enable_if_t<has_print<T>::value>* = nullptr>\n   \
    \ void print(const T& a) {\n      a.print(*this);\n    }\n\n    template<bool\
    \ first = true>\n    void operator ()() {\n      if constexpr (comment && first)\
    \ print_char('#');\n      if constexpr (end) print_char('\\n');\n      if constexpr\
    \ (flush) itr.flush();\n    }\n    template<bool first = true, class Head, class...\
    \ Args>\n    void operator ()(Head&& head, Args&&... args) {\n      if constexpr\
    \ (comment && first) {\n        print_char('#');\n        print_char(' ');\n \
    \     }\n      if constexpr (sep && !first) print_sep();\n      print(head);\n\
    \      operator ()<false>(std::forward<Args>(args)...);\n    }\n  };\n\n  Printer<Writer<>::iterator,\
    \ false, false> print(output.begin()), eprint(error.begin());\n  Printer<Writer<>::iterator>\
    \ println(output.begin()), eprintln(error.begin());\n}\n#line 4 \"verify/yosupo/unionfind.test.cpp\"\
    \n\nint main() {\n  int n, q;\n  kpr::scan(n, q);\n  kpr::UnionFind uf(n);\n \
    \ for (int i = 0; i < q; ++i) {\n    int t, u, v;\n    kpr::scan(t, u, v);\n \
    \   if (t == 0) uf.merge(u, v);\n    else kpr::println(uf.same(u, v));\n  }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#include \"\
    ../../structure/UnionFind.hpp\"\n#include \"../../system/all.hpp\"\n\nint main()\
    \ {\n  int n, q;\n  kpr::scan(n, q);\n  kpr::UnionFind uf(n);\n  for (int i =\
    \ 0; i < q; ++i) {\n    int t, u, v;\n    kpr::scan(t, u, v);\n    if (t == 0)\
    \ uf.merge(u, v);\n    else kpr::println(uf.same(u, v));\n  }\n}"
  dependsOn:
  - structure/UnionFind.hpp
  - meta/settings.hpp
  - meta/trait.hpp
  - system/all.hpp
  - system/in.hpp
  - math/power.hpp
  - system/out.hpp
  isVerificationFile: true
  path: verify/yosupo/unionfind.test.cpp
  requiredBy: []
  timestamp: '2022-05-15 16:50:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/unionfind.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/unionfind.test.cpp
- /verify/verify/yosupo/unionfind.test.cpp.html
title: verify/yosupo/unionfind.test.cpp
---
