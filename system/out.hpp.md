---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: meta/aggregate.hpp
    title: meta/aggregate.hpp
  - icon: ':heavy_check_mark:'
    path: meta/settings.hpp
    title: meta/settings.hpp
  - icon: ':heavy_check_mark:'
    path: meta/trait.hpp
    title: meta/trait.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  - icon: ':warning:'
    path: all/all.hpp
    title: all/all.hpp
  - icon: ':heavy_check_mark:'
    path: system/all.hpp
    title: system/all.hpp
  - icon: ':warning:'
    path: template/all.hpp
    title: template/all.hpp
  - icon: ':warning:'
    path: template/macro.hpp
    title: template/macro.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/PrimeNumber.test.cpp
    title: verify/aoj/PrimeNumber.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/factorize.test.cpp
    title: verify/yosupo/factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/many_aplusb.test.cpp
    title: verify/yosupo/many_aplusb.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/point_add_range_sum.test.cpp
    title: verify/yosupo/point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/unionfind.test.cpp
    title: verify/yosupo/unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"system/out.hpp\"\n#include <unistd.h>\n#include <algorithm>\n\
    #include <array>\n#include <cmath>\n#include <cstdint>\n#include <cstdio>\n#include\
    \ <iterator>\n#include <string>\n#include <tuple>\n#include <type_traits>\n#include\
    \ <utility>\n#line 3 \"meta/trait.hpp\"\n#include <queue>\n#include <limits>\n\
    #include <stack>\n#line 3 \"meta/settings.hpp\"\n\n#ifndef KYOPRO_BASE_INT\n#define\
    \ KYOPRO_BASE_INT std::int64_t\n#endif\n\n#ifndef KYOPRO_BASE_UINT\n#define KYOPRO_BASE_UINT\
    \ std::uint64_t\n#endif\n\n#ifndef KYOPRO_BASE_FLOAT\n#define KYOPRO_BASE_FLOAT\
    \ double\n#endif\n\n#ifndef KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD static_cast<KYOPRO_BASE_UINT>(998244353)\n\
    #endif\n\n#ifndef KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n\
    #endif\n\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 9 \"meta/trait.hpp\"\n\ntemplate<>\nstruct std::is_integral<__int128_t>:\
    \ std::true_type {};\ntemplate<>\nstruct std::is_integral<__uint128_t>: std::true_type\
    \ {};\ntemplate<>\nstruct std::is_floating_point<__float128>: std::true_type {};\n\
    \nnamespace kyopro {\n  template<KYOPRO_BASE_UINT size>\n  struct int_least {\n\
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
    \ std::false_type {};\n  template<class T>\n  struct is_iterable<T, std::void_t<decltype(std::begin(std::declval<std::add_lvalue_reference_t<T>>()),\
    \ std::end(std::declval<std::add_lvalue_reference_t<T>>()))>>: std::true_type\
    \ {};\n\n  template<class T>\n  constexpr bool is_iterable_v = is_iterable<T>::value;\n\
    \n  template<class T>\n  struct iterable_value {\n    using type = std::decay_t<decltype(*std::begin(std::declval<T>()))>;\n\
    \  };\n\n  template<class T>\n  using iterable_value_t = typename iterable_value<T>::type;\n\
    \n  namespace helper {\n    struct CastableToAny {\n      template<class T>\n\
    \      operator T() const noexcept;\n    };\n\n    template<class T, std::size_t...\
    \ idx, std::void_t<decltype(T{((void)idx, CastableToAny{})...})>* = nullptr>\n\
    \    constexpr bool is_aggregate_initializable(std::index_sequence<idx...>, bool)\
    \ noexcept {\n      return true;\n    }\n    template<class T, std::size_t...\
    \ idx>\n    constexpr bool is_aggregate_initializable(std::index_sequence<idx...>,\
    \ char) noexcept {\n      return false;\n    }\n\n    template<class T, std::size_t\
    \ n, std::enable_if_t<is_aggregate_initializable<T>(std::make_index_sequence<n>(),\
    \ false)>* = nullptr>\n    constexpr std::size_t aggregate_size_impl() {\n   \
    \   return n;\n    }\n    template<class T, std::size_t n, std::enable_if_t<!is_aggregate_initializable<T>(std::make_index_sequence<n>(),\
    \ false)>* = nullptr>\n    constexpr std::size_t aggregate_size_impl() {\n   \
    \   static_assert(n != 0, \"Aggregate is required\");\n      return aggregate_size_impl<T,\
    \ n - 1>();\n    }\n  }\n\n  template<class T, class = void>\n  struct aggregate_size\
    \ {\n    static_assert(std::is_aggregate_v<T>, \"Aggregate is required\");\n \
    \   static constexpr std::size_t value = helper::aggregate_size_impl<T, std::numeric_limits<unsigned\
    \ char>::digits * sizeof(T)>();\n  };\n  template<class T>\n  struct aggregate_size<T,\
    \ std::void_t<decltype(std::tuple_size<T>::value)>> {\n    static_assert(std::is_aggregate_v<T>,\
    \ \"Aggregate is required\");\n    static constexpr std::size_t value = std::tuple_size_v<T>;\n\
    \  };\n  template<class T>\n  constexpr std::size_t aggregate_size_v = aggregate_size<T>::value;\n\
    \n  template<std::size_t idx, class T>\n  struct aggregate_element {\n    static_assert(std::is_aggregate_v<T>);\n\
    \n  private:\n    template<class U>\n    struct Type {\n      using type = U;\n\
    \    };\n\n    template<class U, std::enable_if_t<aggregate_size_v<std::decay_t<U>>\
    \ == 1>* = nullptr>\n    static constexpr auto get_type(U aggregate, char) noexcept\
    \ {\n      auto&& [a] = aggregate;\n      static_assert(idx < 1, \"Tuple index\
    \ out of range\");\n      return Type<decltype(a)>();\n    }\n    template<class\
    \ U, std::enable_if_t<aggregate_size_v<std::decay_t<U>> == 2>* = nullptr>\n  \
    \  static constexpr auto get_type(U aggregate, char) noexcept {\n      auto&&\
    \ [a, b] = aggregate;\n      static_assert(idx < 2, \"Tuple index out of range\"\
    );\n      if constexpr (idx == 0) return Type<decltype(a)>();\n      else return\
    \ Type<decltype(b)>();\n    }\n    template<class U, std::enable_if_t<aggregate_size_v<std::decay_t<U>>\
    \ == 3>* = nullptr>\n    static constexpr auto get_type(U aggregate, char) noexcept\
    \ {\n      auto&& [a, b, c] = aggregate;\n      static_assert(idx < 3, \"Tuple\
    \ index out of range\");\n      if constexpr (idx == 0) return Type<decltype(a)>();\n\
    \      else if constexpr (idx == 1) return Type<decltype(b)>();\n      else return\
    \ Type<decltype(c)>();\n    }\n    template<class U, std::enable_if_t<aggregate_size_v<std::decay_t<U>>\
    \ == 4>* = nullptr>\n    static constexpr auto access_impl(U aggregate, char)\
    \ noexcept {\n      auto&& [a, b, c, d] = aggregate;\n      static_assert(idx\
    \ < 4, \"Tuple index out of range\");\n      if constexpr (idx == 0) return Type<decltype(a)>();\n\
    \      else if constexpr (idx == 1) return Type<decltype(b)>();\n      else if\
    \ constexpr (idx == 2) return Type<decltype(c)>();\n      else return Type<decltype(d)>();\n\
    \    }\n    template<class U, std::enable_if_t<aggregate_size_v<std::decay_t<U>>\
    \ == 5>* = nullptr>\n    static constexpr auto get_type(U aggregate, char) noexcept\
    \ {\n      auto&& [a, b, c, d, e] = aggregate;\n      static_assert(idx < 5, \"\
    Tuple index out of range\");\n      if constexpr (idx == 0) return Type<decltype(a)>();\n\
    \      else if constexpr (idx == 1) return Type<decltype(b)>();\n      else if\
    \ constexpr (idx == 2) return Type<decltype(c)>();\n      else if constexpr (idx\
    \ == 3) return Type<decltype(d)>();\n      else return Type<decltype(e)>();\n\
    \    }\n    template<class U, std::enable_if_t<aggregate_size_v<std::decay_t<U>>\
    \ == 6>* = nullptr>\n    static constexpr auto get_type(U aggregate, char) noexcept\
    \ {\n      auto&& [a, b, c, d, e, f] = aggregate;\n      static_assert(idx < 6,\
    \ \"Tuple index out of range\");\n      if constexpr (idx == 0) return Type<decltype(a)>();\n\
    \      else if constexpr (idx == 1) return Type<decltype(b)>();\n      else if\
    \ constexpr (idx == 2) return Type<decltype(c)>();\n      else if constexpr (idx\
    \ == 3) return Type<decltype(d)>();\n      else if constexpr (idx == 4) return\
    \ Type<decltype(e)>();\n      else return Type<decltype(f)>();\n    }\n    template<class\
    \ U, std::enable_if_t<aggregate_size_v<std::decay_t<U>> == 7>* = nullptr>\n  \
    \  static constexpr auto get_type(U aggregate, char) noexcept {\n      auto&&\
    \ [a, b, c, d, e, f, g] = aggregate;\n      static_assert(idx < 7, \"Tuple index\
    \ out of range\");\n      if constexpr (idx == 0) return Type<decltype(a)>();\n\
    \      else if constexpr (idx == 1) return Type<decltype(b)>();\n      else if\
    \ constexpr (idx == 2) return Type<decltype(c)>();\n      else if constexpr (idx\
    \ == 3) return Type<decltype(d)>();\n      else if constexpr (idx == 4) return\
    \ Type<decltype(e)>();\n      else if constexpr (idx == 5) return Type<decltype(f)>();\n\
    \      else return Type<decltype(g)>();\n    }\n    template<class U, std::enable_if_t<aggregate_size_v<std::decay_t<U>>\
    \ == 8>* = nullptr>\n    static constexpr auto get_type(U aggregate, char) noexcept\
    \ {\n      auto&& [a, b, c, d, e, f, g, h] = aggregate;\n      static_assert(idx\
    \ < 8, \"Tuple index out of range\");\n      if constexpr (idx == 0) return Type<decltype(a)>();\n\
    \      else if constexpr (idx == 1) return Type<decltype(b)>();\n      else if\
    \ constexpr (idx == 2) return Type<decltype(c)>();\n      else if constexpr (idx\
    \ == 3) return Type<decltype(d)>();\n      else if constexpr (idx == 4) return\
    \ Type<decltype(e)>();\n      else if constexpr (idx == 5) return Type<decltype(f)>();\n\
    \      else if constexpr (idx == 6) return Type<decltype(g)>();\n      else return\
    \ Type<decltype(h)>();\n    }\n    template<class U, std::void_t<std::tuple_element_t<idx,\
    \ U>>* = nullptr>\n    static constexpr auto get_type(U, bool) noexcept {\n  \
    \    return Type<std::tuple_element_t<idx, U>>();\n    }\n\n  public:\n    using\
    \ type = typename decltype(get_type(std::declval<T>(), false))::type;\n  };\n\n\
    \  template<std::size_t idx, class T>\n  using aggregate_element_t = typename\
    \ aggregate_element<idx, T>::type;\n\n  template<class T>\n  struct is_agg: std::conjunction<std::is_aggregate<T>,\
    \ std::negation<is_iterable<T>>> {};\n\n  template<class T>\n  inline constexpr\
    \ bool is_agg_v = is_agg<T>::value;\n}\n#line 7 \"meta/aggregate.hpp\"\n\nnamespace\
    \ kyopro {\n  namespace helper {\n    #define DEFINE_ACCESS(n, ...) \\\n    template<std::size_t\
    \ idx, class T, std::enable_if_t<aggregate_size_v<std::decay_t<T>> == n>* = nullptr>\\\
    \n    constexpr decltype(auto) access_impl(T&& aggregate, char) noexcept {\\\n\
    \      auto&& [__VA_ARGS__] = std::forward<T>(aggregate);\\\n      return std::get<idx>(std::forward_as_tuple(__VA_ARGS__));\\\
    \n    }\n\n    DEFINE_ACCESS(1, a)\n    DEFINE_ACCESS(2, a, b)\n    DEFINE_ACCESS(3,\
    \ a, b, c)\n    DEFINE_ACCESS(4, a, b, c, d)\n    DEFINE_ACCESS(5, a, b, c, d,\
    \ e)\n    DEFINE_ACCESS(6, a, b, c, d, e, f)\n    DEFINE_ACCESS(7, a, b, c, d,\
    \ e, f, g)\n    DEFINE_ACCESS(8, a, b, c, d, e, f, g, h)\n\n    template<std::size_t\
    \ idx, class T, std::void_t<decltype(std::get<idx>(std::declval<std::decay_t<T>>()))>*\
    \ = nullptr>\n    constexpr decltype(auto) access_impl(T&& aggregate, bool) noexcept\
    \ {\n      return std::get<idx>(std::forward<T>(aggregate));\n    }\n\n    #undef\
    \ DEFINE_ACCESS\n  }\n\n  template<std::size_t idx, class T>\n  constexpr decltype(auto)\
    \ access(T&& aggregate) noexcept {\n    return helper::access_impl<idx>(std::forward<T>(aggregate),\
    \ false);\n  }\n}\n#line 16 \"system/out.hpp\"\n\nnamespace kyopro {\n  template<std::size_t\
    \ _buf_size = KYOPRO_BUFFER_SIZE>\n  struct Writer {\n    static constexpr KYOPRO_BASE_UINT\
    \ buf_size = _buf_size;\n\n  private:\n    int fd, idx;\n    std::array<char,\
    \ buf_size> buffer;\n\n  public:\n    Writer() noexcept = default;\n    Writer(int\
    \ fd) noexcept: fd(fd), idx(0), buffer() {}\n    Writer(FILE* fp) noexcept: fd(fileno(fp)),\
    \ idx(0), buffer() {}\n\n    ~Writer() {\n      write(fd, buffer.begin(), idx);\n\
    \    }\n\n    struct iterator {\n    private:\n      Writer& writer;\n\n    public:\n\
    \      using difference_type = void;\n      using value_type = void;\n      using\
    \ pointer = void;\n      using reference = void;\n      using iterator_category\
    \ = std::output_iterator_tag;\n\n      iterator() noexcept = default;\n      iterator(Writer&\
    \ writer) noexcept: writer(writer) {}\n\n      iterator& operator ++() {\n   \
    \     ++writer.idx;\n        if (writer.idx == buf_size) {\n          write(writer.fd,\
    \ writer.buffer.begin(), buf_size);\n          writer.idx = 0;\n        }\n  \
    \      return *this;\n      }\n\n      iterator operator ++(int) {\n        iterator\
    \ before = *this;\n        operator ++();\n        return before;\n      }\n\n\
    \      char& operator *() const {\n        return writer.buffer[writer.idx];\n\
    \      }\n\n      void flush() const {\n        write(writer.fd, writer.buffer.begin(),\
    \ writer.idx);\n      }\n    };\n\n    iterator begin() noexcept {\n      return\
    \ iterator(*this);\n    }\n  };\n\n  Writer output(1), error(2);\n\n  template<class\
    \ Iterator, bool _sep = true, bool _sep_line = true, bool _end_line = true, bool\
    \ _debug = false, bool _comment = false, bool _flush = false, std::size_t _decimal_precision\
    \ = KYOPRO_DECIMAL_PRECISION>\n  struct Printer {\n    using iterator_type = Iterator;\n\
    \    static constexpr bool sep = _sep, end_line = _end_line, sep_line = _sep_line,\
    \ debug = _debug, comment = _comment, flush = _flush;\n    static constexpr KYOPRO_BASE_UINT\
    \ decimal_precision = _decimal_precision;\n\n  private:\n    template<class, class\
    \ = void>\n    struct has_print: std::false_type {};\n    template<class T>\n\
    \    struct has_print<T, std::void_t<decltype(std::declval<T>().print(std::declval<Printer&>()))>>:\
    \ std::true_type {};\n\n  public:\n\n    template<class, class = void>\n    struct\
    \ max_rank {\n      static constexpr std::size_t value = 0;\n    };\n    template<class\
    \ T>\n    struct max_rank<T, std::enable_if_t<is_agg_v<T>>> {\n      template<std::size_t...\
    \ idx>\n      static constexpr bool get_value_rank(std::index_sequence<idx...>)\
    \ {\n        return std::max({max_rank<aggregate_element_t<idx, T>>::value...});\n\
    \      }\n      static constexpr std::size_t value = get_value_rank(std::make_index_sequence<aggregate_size_v<T>>())\
    \ + 1;\n    };\n    template<class T>\n    struct max_rank<T, std::enable_if_t<is_iterable_v<T>>>\
    \ {\n      static constexpr std::size_t value = max_rank<iterable_value_t<T>>::value\
    \ + 1;\n    };\n\n    template<class T>\n    static constexpr KYOPRO_BASE_UINT\
    \ max_rank_v = max_rank<T>::value;\n\n    Iterator itr;\n\n    Printer() noexcept\
    \ = default;\n    Printer(Iterator itr) noexcept: itr(itr) {}\n\n    void print_char(char\
    \ c) {\n      *itr = c;\n      ++itr;\n    }\n\n    template<std::size_t rank>\n\
    \    void print_sep() {\n      if constexpr (sep) {\n        if constexpr (debug)\
    \ print_char(',');\n        if constexpr (sep_line && rank >= 2) {\n         \
    \ print_char('\\n');\n          if constexpr (comment) {\n            print_char('#');\n\
    \            print_char(' ');\n          }\n        } else print_char(' ');\n\
    \      }\n    }\n\n    void print(char a) {\n      if constexpr (debug) print_char('\\\
    '');\n      print_char(a);\n      if constexpr (debug) print_char('\\'');\n  \
    \  }\n    void print(const char* a) {\n      if constexpr (debug) print_char('\"\
    ');\n      for (; *a != '\\0'; ++a) print_char(*a);\n      if constexpr (debug)\
    \ print_char('\"');\n    }\n    template<std::size_t len>\n    void print(const\
    \ char (&a)[len]) {\n      if constexpr (debug) print_char('\"');\n      for (auto\
    \ i: a) print_char(i);\n      if constexpr (debug) print_char('\"');\n    }\n\
    \    void print(const std::string& a) {\n      if constexpr (debug) print_char('\"\
    ');\n      for (auto i: a) print_char(i);\n      if constexpr (debug) print_char('\"\
    ');\n    }\n    void print(bool a) {\n      print_char(static_cast<char>('0' +\
    \ a));\n    }\n    template<class T, std::enable_if_t<std::is_arithmetic_v<T>\
    \ && !has_print<T>::value>* = nullptr>\n    void print(T a) {\n      if constexpr\
    \ (std::is_floating_point_v<T>) {\n        if (a == std::numeric_limits<T>::infinity())\
    \ {\n          print(\"inf\");\n          return;\n        }\n        if (a ==\
    \ -std::numeric_limits<T>::infinity()) {\n          print(\"-inf\");\n       \
    \   return;\n        }\n        if (std::isnan(a)) {\n          print(\"nan\"\
    );\n          return;\n        }\n      }\n      if constexpr (std::is_signed_v<T>)\
    \ if (a < 0) {\n        print_char('-');\n        a = -a;\n      }\n      std::uint_fast64_t\
    \ p = a;\n      std::string s;\n      do {\n        s += '0' + p % 10;\n     \
    \   p /= 10;\n      } while (p > 0);\n      for (auto i = s.rbegin(); i != s.rend();\
    \ ++i) print_char(*i);\n      if constexpr (std::is_integral_v<T>) return;\n \
    \     print_char('.');\n      a -= p;\n      for (int i = 0; i < static_cast<int>(decimal_precision);\
    \ ++i) {\n        a *= 10;\n        print_char('0' + static_cast<std::uint_fast64_t>(a)\
    \ % 10);\n      }\n    }\n    template<KYOPRO_BASE_UINT i = 0, class T, std::enable_if_t<is_agg_v<T>\
    \ && !has_print<T>::value>* = nullptr>\n    void print(const T& a) {\n      if\
    \ constexpr (debug && i == 0) print_char('{');\n      if constexpr (aggregate_size_v<T>\
    \ != 0) print(access<i>(a));\n      if constexpr (i + 1 < aggregate_size_v<T>)\
    \ {\n        print_sep<max_rank_v<T>>();\n        print<i + 1>(a);\n      } else\
    \ if constexpr (debug) print_char('}');\n    }\n    template<class T, std::enable_if_t<is_iterable_v<T>\
    \ && !has_print<T>::value>* = nullptr>\n    void print(const T& a) {\n      if\
    \ constexpr (debug) print_char('{');\n      if (std::empty(a)) return;\n     \
    \ for (auto i = std::begin(a); ; ) {\n        print(*i);\n        if (++i != std::end(a))\
    \ {\n          print_sep<max_rank_v<T>>();\n        } else break;\n      }\n \
    \     if constexpr (debug) print_char('}');\n    }\n    template<class T, std::enable_if_t<has_print<T>::value>*\
    \ = nullptr>\n    void print(const T& a) {\n      a.print(*this);\n    }\n\n \
    \   template<bool first = true>\n    void operator ()() {\n      if constexpr\
    \ (comment && first) print_char('#');\n      if constexpr (end_line) print_char('\\\
    n');\n      if constexpr (flush) itr.flush();\n    }\n    template<bool first\
    \ = true, class Head, class... Args>\n    void operator ()(Head&& head, Args&&...\
    \ args) {\n      if constexpr (comment && first) {\n        print_char('#');\n\
    \        print_char(' ');\n      }\n      if constexpr (sep && !first) print_sep<0>();\n\
    \      print(std::forward<Head>(head));\n      operator ()<false>(std::forward<Args>(args)...);\n\
    \    }\n  };\n\n  Printer<Writer<>::iterator, false, false, false> print(output.begin()),\
    \ eprint(error.begin());\n  Printer<Writer<>::iterator> println(output.begin()),\
    \ eprintln(error.begin());\n}\n"
  code: "#pragma once\n#include <unistd.h>\n#include <algorithm>\n#include <array>\n\
    #include <cmath>\n#include <cstdint>\n#include <cstdio>\n#include <iterator>\n\
    #include <string>\n#include <tuple>\n#include <type_traits>\n#include <utility>\n\
    #include \"../meta/aggregate.hpp\"\n#include \"../meta/settings.hpp\"\n#include\
    \ \"../meta/trait.hpp\"\n\nnamespace kyopro {\n  template<std::size_t _buf_size\
    \ = KYOPRO_BUFFER_SIZE>\n  struct Writer {\n    static constexpr KYOPRO_BASE_UINT\
    \ buf_size = _buf_size;\n\n  private:\n    int fd, idx;\n    std::array<char,\
    \ buf_size> buffer;\n\n  public:\n    Writer() noexcept = default;\n    Writer(int\
    \ fd) noexcept: fd(fd), idx(0), buffer() {}\n    Writer(FILE* fp) noexcept: fd(fileno(fp)),\
    \ idx(0), buffer() {}\n\n    ~Writer() {\n      write(fd, buffer.begin(), idx);\n\
    \    }\n\n    struct iterator {\n    private:\n      Writer& writer;\n\n    public:\n\
    \      using difference_type = void;\n      using value_type = void;\n      using\
    \ pointer = void;\n      using reference = void;\n      using iterator_category\
    \ = std::output_iterator_tag;\n\n      iterator() noexcept = default;\n      iterator(Writer&\
    \ writer) noexcept: writer(writer) {}\n\n      iterator& operator ++() {\n   \
    \     ++writer.idx;\n        if (writer.idx == buf_size) {\n          write(writer.fd,\
    \ writer.buffer.begin(), buf_size);\n          writer.idx = 0;\n        }\n  \
    \      return *this;\n      }\n\n      iterator operator ++(int) {\n        iterator\
    \ before = *this;\n        operator ++();\n        return before;\n      }\n\n\
    \      char& operator *() const {\n        return writer.buffer[writer.idx];\n\
    \      }\n\n      void flush() const {\n        write(writer.fd, writer.buffer.begin(),\
    \ writer.idx);\n      }\n    };\n\n    iterator begin() noexcept {\n      return\
    \ iterator(*this);\n    }\n  };\n\n  Writer output(1), error(2);\n\n  template<class\
    \ Iterator, bool _sep = true, bool _sep_line = true, bool _end_line = true, bool\
    \ _debug = false, bool _comment = false, bool _flush = false, std::size_t _decimal_precision\
    \ = KYOPRO_DECIMAL_PRECISION>\n  struct Printer {\n    using iterator_type = Iterator;\n\
    \    static constexpr bool sep = _sep, end_line = _end_line, sep_line = _sep_line,\
    \ debug = _debug, comment = _comment, flush = _flush;\n    static constexpr KYOPRO_BASE_UINT\
    \ decimal_precision = _decimal_precision;\n\n  private:\n    template<class, class\
    \ = void>\n    struct has_print: std::false_type {};\n    template<class T>\n\
    \    struct has_print<T, std::void_t<decltype(std::declval<T>().print(std::declval<Printer&>()))>>:\
    \ std::true_type {};\n\n  public:\n\n    template<class, class = void>\n    struct\
    \ max_rank {\n      static constexpr std::size_t value = 0;\n    };\n    template<class\
    \ T>\n    struct max_rank<T, std::enable_if_t<is_agg_v<T>>> {\n      template<std::size_t...\
    \ idx>\n      static constexpr bool get_value_rank(std::index_sequence<idx...>)\
    \ {\n        return std::max({max_rank<aggregate_element_t<idx, T>>::value...});\n\
    \      }\n      static constexpr std::size_t value = get_value_rank(std::make_index_sequence<aggregate_size_v<T>>())\
    \ + 1;\n    };\n    template<class T>\n    struct max_rank<T, std::enable_if_t<is_iterable_v<T>>>\
    \ {\n      static constexpr std::size_t value = max_rank<iterable_value_t<T>>::value\
    \ + 1;\n    };\n\n    template<class T>\n    static constexpr KYOPRO_BASE_UINT\
    \ max_rank_v = max_rank<T>::value;\n\n    Iterator itr;\n\n    Printer() noexcept\
    \ = default;\n    Printer(Iterator itr) noexcept: itr(itr) {}\n\n    void print_char(char\
    \ c) {\n      *itr = c;\n      ++itr;\n    }\n\n    template<std::size_t rank>\n\
    \    void print_sep() {\n      if constexpr (sep) {\n        if constexpr (debug)\
    \ print_char(',');\n        if constexpr (sep_line && rank >= 2) {\n         \
    \ print_char('\\n');\n          if constexpr (comment) {\n            print_char('#');\n\
    \            print_char(' ');\n          }\n        } else print_char(' ');\n\
    \      }\n    }\n\n    void print(char a) {\n      if constexpr (debug) print_char('\\\
    '');\n      print_char(a);\n      if constexpr (debug) print_char('\\'');\n  \
    \  }\n    void print(const char* a) {\n      if constexpr (debug) print_char('\"\
    ');\n      for (; *a != '\\0'; ++a) print_char(*a);\n      if constexpr (debug)\
    \ print_char('\"');\n    }\n    template<std::size_t len>\n    void print(const\
    \ char (&a)[len]) {\n      if constexpr (debug) print_char('\"');\n      for (auto\
    \ i: a) print_char(i);\n      if constexpr (debug) print_char('\"');\n    }\n\
    \    void print(const std::string& a) {\n      if constexpr (debug) print_char('\"\
    ');\n      for (auto i: a) print_char(i);\n      if constexpr (debug) print_char('\"\
    ');\n    }\n    void print(bool a) {\n      print_char(static_cast<char>('0' +\
    \ a));\n    }\n    template<class T, std::enable_if_t<std::is_arithmetic_v<T>\
    \ && !has_print<T>::value>* = nullptr>\n    void print(T a) {\n      if constexpr\
    \ (std::is_floating_point_v<T>) {\n        if (a == std::numeric_limits<T>::infinity())\
    \ {\n          print(\"inf\");\n          return;\n        }\n        if (a ==\
    \ -std::numeric_limits<T>::infinity()) {\n          print(\"-inf\");\n       \
    \   return;\n        }\n        if (std::isnan(a)) {\n          print(\"nan\"\
    );\n          return;\n        }\n      }\n      if constexpr (std::is_signed_v<T>)\
    \ if (a < 0) {\n        print_char('-');\n        a = -a;\n      }\n      std::uint_fast64_t\
    \ p = a;\n      std::string s;\n      do {\n        s += '0' + p % 10;\n     \
    \   p /= 10;\n      } while (p > 0);\n      for (auto i = s.rbegin(); i != s.rend();\
    \ ++i) print_char(*i);\n      if constexpr (std::is_integral_v<T>) return;\n \
    \     print_char('.');\n      a -= p;\n      for (int i = 0; i < static_cast<int>(decimal_precision);\
    \ ++i) {\n        a *= 10;\n        print_char('0' + static_cast<std::uint_fast64_t>(a)\
    \ % 10);\n      }\n    }\n    template<KYOPRO_BASE_UINT i = 0, class T, std::enable_if_t<is_agg_v<T>\
    \ && !has_print<T>::value>* = nullptr>\n    void print(const T& a) {\n      if\
    \ constexpr (debug && i == 0) print_char('{');\n      if constexpr (aggregate_size_v<T>\
    \ != 0) print(access<i>(a));\n      if constexpr (i + 1 < aggregate_size_v<T>)\
    \ {\n        print_sep<max_rank_v<T>>();\n        print<i + 1>(a);\n      } else\
    \ if constexpr (debug) print_char('}');\n    }\n    template<class T, std::enable_if_t<is_iterable_v<T>\
    \ && !has_print<T>::value>* = nullptr>\n    void print(const T& a) {\n      if\
    \ constexpr (debug) print_char('{');\n      if (std::empty(a)) return;\n     \
    \ for (auto i = std::begin(a); ; ) {\n        print(*i);\n        if (++i != std::end(a))\
    \ {\n          print_sep<max_rank_v<T>>();\n        } else break;\n      }\n \
    \     if constexpr (debug) print_char('}');\n    }\n    template<class T, std::enable_if_t<has_print<T>::value>*\
    \ = nullptr>\n    void print(const T& a) {\n      a.print(*this);\n    }\n\n \
    \   template<bool first = true>\n    void operator ()() {\n      if constexpr\
    \ (comment && first) print_char('#');\n      if constexpr (end_line) print_char('\\\
    n');\n      if constexpr (flush) itr.flush();\n    }\n    template<bool first\
    \ = true, class Head, class... Args>\n    void operator ()(Head&& head, Args&&...\
    \ args) {\n      if constexpr (comment && first) {\n        print_char('#');\n\
    \        print_char(' ');\n      }\n      if constexpr (sep && !first) print_sep<0>();\n\
    \      print(std::forward<Head>(head));\n      operator ()<false>(std::forward<Args>(args)...);\n\
    \    }\n  };\n\n  Printer<Writer<>::iterator, false, false, false> print(output.begin()),\
    \ eprint(error.begin());\n  Printer<Writer<>::iterator> println(output.begin()),\
    \ eprintln(error.begin());\n}"
  dependsOn:
  - meta/aggregate.hpp
  - meta/trait.hpp
  - meta/settings.hpp
  isVerificationFile: false
  path: system/out.hpp
  requiredBy:
  - all/all.hpp
  - system/all.hpp
  - all.hpp
  - template/macro.hpp
  - template/all.hpp
  timestamp: '2022-07-21 21:43:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/PrimeNumber.test.cpp
  - verify/yosupo/point_add_range_sum.test.cpp
  - verify/yosupo/factorize.test.cpp
  - verify/yosupo/unionfind.test.cpp
  - verify/yosupo/many_aplusb.test.cpp
documentation_of: system/out.hpp
layout: document
redirect_from:
- /library/system/out.hpp
- /library/system/out.hpp.html
title: system/out.hpp
---
