---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../meta/aggregate.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include <unistd.h>\n#include <algorithm>\n#include <array>\n\
    #include <bitset>\n#include <cmath>\n#include <cstdint>\n#include <cstdio>\n#include\
    \ <iterator>\n#include <string>\n#include <tuple>\n#include <type_traits>\n#include\
    \ <utility>\n#include \"../meta/aggregate.hpp\"\n#include \"../meta/setting.hpp\"\
    \n#include \"../meta/trait.hpp\"\n\nnamespace kpr {\n    template<std::size_t\
    \ buf_size = KYOPRO_BUFFER_SIZE>\n    struct Writer {\n    private:\n        int\
    \ fd, idx;\n        std::array<char, buf_size> buffer;\n\n    public:\n      \
    \  static constexpr KYOPRO_BASE_INT get_buf_size() noexcept {\n            return\
    \ buf_size;\n        }\n\n        Writer() noexcept = default;\n        Writer(int\
    \ fd) noexcept: fd(fd), idx(0), buffer() {}\n        Writer(FILE* fp) noexcept:\
    \ fd(fileno(fp)), idx(0), buffer() {}\n\n        ~Writer() {\n            write(fd,\
    \ buffer.begin(), idx);\n        }\n\n        struct iterator {\n        private:\n\
    \            Writer& writer;\n\n        public:\n            using difference_type\
    \ = void;\n            using value_type = void;\n            using pointer = void;\n\
    \            using reference = void;\n            using iterator_category = std::output_iterator_tag;\n\
    \n            iterator() noexcept = default;\n            iterator(Writer& writer)\
    \ noexcept: writer(writer) {}\n\n            iterator& operator ++() {\n     \
    \           ++writer.idx;\n                if (writer.idx == buf_size) {\n   \
    \             write(writer.fd, writer.buffer.begin(), buf_size);\n           \
    \     writer.idx = 0;\n                }\n                return *this;\n    \
    \        }\n\n            iterator operator ++(int) {\n                iterator\
    \ before = *this;\n                operator ++();\n                return before;\n\
    \            }\n\n            char& operator *() const {\n                return\
    \ writer.buffer[writer.idx];\n            }\n\n            void flush() const\
    \ {\n                write(writer.fd, writer.buffer.begin(), writer.idx);\n  \
    \          }\n        };\n\n        iterator begin() noexcept {\n            return\
    \ iterator(*this);\n        }\n    };\n\n    Writer output(1), error(2);\n\n \
    \   template<class Iterator, bool _sep = true, bool _sep_line = true, bool _end_line\
    \ = true, bool _debug = false, bool _comment = false, bool _flush = false, std::size_t\
    \ decimal_precision = KYOPRO_DECIMAL_PRECISION>\n    struct Printer {\n      \
    \  using iterator_type = Iterator;\n        static constexpr bool sep = _sep,\
    \ end_line = _end_line, sep_line = _sep_line, debug = _debug, comment = _comment,\
    \ flush = _flush;\n\n    private:\n        template<class, class = void>\n   \
    \     struct has_print: std::false_type {};\n        template<class T>\n     \
    \   struct has_print<T, std::void_t<decltype(std::declval<T>().print(std::declval<Printer&>()))>>:\
    \ std::true_type {};\n\n    public:\n        static constexpr KYOPRO_BASE_INT\
    \ get_decimal_precision() noexcept {\n            return decimal_precision;\n\
    \        }\n\n        template<class, class = void>\n        struct max_rank {\n\
    \            static constexpr std::size_t value = 0;\n        };\n        template<class\
    \ T>\n        struct max_rank<T, std::enable_if_t<is_agg_v<T>>> {\n          \
    \  template<std::size_t... idx>\n            static constexpr bool get_value_rank(std::index_sequence<idx...>)\
    \ {\n                return std::max({max_rank<aggregate_element_t<idx, T>>::value...});\n\
    \            }\n            static constexpr std::size_t value = get_value_rank(std::make_index_sequence<aggregate_size_v<T>>())\
    \ + 1;\n        };\n        template<class T>\n        struct max_rank<T, std::enable_if_t<is_range_v<T>>>\
    \ {\n            static constexpr std::size_t value = max_rank<range_value_t<T>>::value\
    \ + 1;\n        };\n\n        template<class T>\n        static constexpr KYOPRO_BASE_UINT\
    \ max_rank_v = max_rank<T>::value;\n\n        Iterator itr;\n\n        Printer()\
    \ noexcept = default;\n        Printer(Iterator itr) noexcept: itr(itr) {}\n\n\
    \        void print_char(char c) {\n            *itr = c;\n            ++itr;\n\
    \        }\n\n        template<std::size_t rank>\n        void print_sep() {\n\
    \            if constexpr (sep) {\n                if constexpr (debug) print_char(',');\n\
    \                if constexpr (sep_line && rank >= 2) {\n                    print_char('\\\
    n');\n                    if constexpr (comment) {\n                        print_char('#');\n\
    \                        print_char(' ');\n                    }\n           \
    \     } else print_char(' ');\n            }\n        }\n\n        void print(char\
    \ a) {\n            if constexpr (debug) print_char('\\'');\n            print_char(a);\n\
    \            if constexpr (debug) print_char('\\'');\n        }\n        void\
    \ print(bool a) {\n            print_char(static_cast<char>('0' + a));\n     \
    \   }\n        void print(const char* a) {\n            if constexpr (debug) print_char('\"\
    ');\n            for (; *a != '\\0'; ++a) print_char(*a);\n            if constexpr\
    \ (debug) print_char('\"');\n        }\n        template<std::size_t len>\n  \
    \      void print(const char (&a)[len]) {\n            if constexpr (debug) print_char('\"\
    ');\n            for (auto i: a) print_char(i);\n            if constexpr (debug)\
    \ print_char('\"');\n        }\n        void print(const std::string& a) {\n \
    \           if constexpr (debug) print_char('\"');\n            for (auto i: a)\
    \ print_char(i);\n            if constexpr (debug) print_char('\"');\n       \
    \ }\n        template<std::size_t len>\n        void print(const std::bitset<len>&\
    \ a) {\n            for (int i = len - 1; i >= 0; --i) print(a[i]);\n        }\n\
    \        template<class T, std::enable_if_t<std::is_arithmetic_v<T> && !has_print<T>::value>*\
    \ = nullptr>\n        void print(T a) {\n            if constexpr (std::is_floating_point_v<T>)\
    \ {\n                if (a == std::numeric_limits<T>::infinity()) {\n        \
    \        print(\"inf\");\n                return;\n                }\n       \
    \         if (a == -std::numeric_limits<T>::infinity()) {\n                print(\"\
    -inf\");\n                return;\n                }\n                if (std::isnan(a))\
    \ {\n                print(\"nan\");\n                return;\n              \
    \  }\n            }\n            if constexpr (std::is_signed_v<T>) if (a < 0)\
    \ {\n                print_char('-');\n                a = -a;\n            }\n\
    \            std::uint_fast64_t p = a;\n            std::string s;\n         \
    \   do {\n                s += '0' + p % 10;\n                p /= 10;\n     \
    \       } while (p > 0);\n            for (auto i = s.rbegin(); i != s.rend();\
    \ ++i) print_char(*i);\n            if constexpr (std::is_integral_v<T>) return;\n\
    \            print_char('.');\n            a -= p;\n            for (int i = 0;\
    \ i < static_cast<int>(decimal_precision); ++i) {\n                a *= 10;\n\
    \                print_char('0' + static_cast<std::uint_fast64_t>(a) % 10);\n\
    \            }\n        }\n        template<std::size_t i = 0, class T, std::enable_if_t<is_agg_v<T>\
    \ && !has_print<T>::value>* = nullptr>\n        void print(const T& a) {\n   \
    \         if constexpr (debug && i == 0) print_char('{');\n            if constexpr\
    \ (aggregate_size_v<T> != 0) print(access<i>(a));\n            if constexpr (i\
    \ + 1 < aggregate_size_v<T>) {\n                print_sep<max_rank_v<T>>();\n\
    \                print<i + 1>(a);\n            } else if constexpr (debug) print_char('}');\n\
    \        }\n        template<class T, std::enable_if_t<is_range_v<T> && !has_print<T>::value>*\
    \ = nullptr>\n        void print(const T& a) {\n            if constexpr (debug)\
    \ print_char('{');\n            if (std::empty(a)) return;\n            for (auto\
    \ i = std::begin(a); ; ) {\n                print(*i);\n                if (++i\
    \ != std::end(a)) {\n                print_sep<max_rank_v<T>>();\n           \
    \     } else break;\n            }\n            if constexpr (debug) print_char('}');\n\
    \        }\n        template<class T, std::enable_if_t<has_print<T>::value>* =\
    \ nullptr>\n        void print(const T& a) {\n            a.print(*this);\n  \
    \      }\n\n        template<bool first = true>\n        void operator ()() {\n\
    \            if constexpr (comment && first) print_char('#');\n            if\
    \ constexpr (end_line) print_char('\\n');\n            if constexpr (flush) itr.flush();\n\
    \        }\n        template<bool first = true, class Head, class... Args>\n \
    \       void operator ()(Head&& head, Args&&... args) {\n            if constexpr\
    \ (comment && first) {\n                print_char('#');\n                print_char('\
    \ ');\n            }\n            if constexpr (sep && !first) print_sep<0>();\n\
    \            print(std::forward<Head>(head));\n            operator ()<false>(std::forward<Args>(args)...);\n\
    \        }\n    };\n\n    Printer<Writer<>::iterator, false, false, false> print(output.begin()),\
    \ eprint(error.begin());\n    Printer<Writer<>::iterator> println(output.begin()),\
    \ eprintln(error.begin());\n} // namespace kpr\n"
  dependsOn: []
  isVerificationFile: false
  path: system/out.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: system/out.hpp
layout: document
redirect_from:
- /library/system/out.hpp
- /library/system/out.hpp.html
title: system/out.hpp
---
