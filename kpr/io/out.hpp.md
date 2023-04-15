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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 412, in update\n    raise BundleErrorAt(path, i + 1, \"unmatched #if /\
    \ #ifdef / #ifndef\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ kpr/meta/setting.hpp: line 41: unmatched #if / #ifdef / #ifndef\n"
  code: "#pragma once\r\n#include <unistd.h>\r\n#include <algorithm>\r\n#include <array>\r\
    \n#include <bitset>\r\n#include <cmath>\r\n#include <cstdint>\r\n#include <cstdio>\r\
    \n#include <iterator>\r\n#include <string>\r\n#include <string_view>\r\n#include\
    \ <tuple>\r\n#include <type_traits>\r\n#include <utility>\r\n#include \"io_option.hpp\"\
    \r\n#include \"../meta/setting.hpp\"\r\n#include \"../meta/trait.hpp\"\r\n#include\
    \ \"../meta/tuple_like.hpp\"\r\n\r\nnamespace kpr {\r\n    // \u30D0\u30C3\u30D5\
    \u30A1\u3092\u7528\u3044\u3066\u30D5\u30A1\u30A4\u30EB\u306B\u66F8\u304D\u8FBC\
    \u3080\u30AF\u30E9\u30B9\r\n    template<std::size_t buf_size = KYOPRO_BUFFER_SIZE>\r\
    \n    struct Writer {\r\n    private:\r\n        int fd, idx;\r\n        std::array<char,\
    \ buf_size> buffer;\r\n\r\n    public:\r\n        // \u30D0\u30C3\u30D5\u30A1\u30B5\
    \u30A4\u30BA\u3092\u53D6\u5F97\r\n        static constexpr KYOPRO_BASE_INT get_buf_size()\
    \ noexcept {\r\n            return buf_size;\r\n        }\r\n\r\n        Writer()\
    \ noexcept = default;\r\n        Writer(int fd) noexcept: fd(fd), idx(0), buffer()\
    \ {}\r\n        Writer(FILE* fp) noexcept: fd(fileno(fp)), idx(0), buffer() {}\r\
    \n\r\n        ~Writer() {\r\n            [[maybe_unused]]ssize_t res = write(fd,\
    \ buffer.begin(), idx);\r\n        }\r\n\r\n        // \u51FA\u529B\u30A4\u30C6\
    \u30EC\u30FC\u30BF\r\n        struct iterator {\r\n        private:\r\n      \
    \      Writer& writer;\r\n\r\n        public:\r\n            using difference_type\
    \ = void;\r\n            using value_type = void;\r\n            using pointer\
    \ = void;\r\n            using reference = void;\r\n            using iterator_category\
    \ = std::output_iterator_tag;\r\n\r\n            iterator() noexcept = default;\r\
    \n            iterator(Writer& writer) noexcept: writer(writer) {}\r\n\r\n   \
    \         iterator& operator ++() {\r\n                ++writer.idx;\r\n     \
    \           if (writer.idx == buf_size) {\r\n                [[maybe_unused]]ssize_t\
    \ res = write(writer.fd, writer.buffer.begin(), buf_size);\r\n               \
    \ writer.idx = 0;\r\n                }\r\n                return *this;\r\n  \
    \          }\r\n\r\n            iterator operator ++(int) {\r\n              \
    \  iterator before = *this;\r\n                operator ++();\r\n            \
    \    return before;\r\n            }\r\n\r\n            char& operator *() const\
    \ {\r\n                return writer.buffer[writer.idx];\r\n            }\r\n\r\
    \n            // \u30D0\u30C3\u30D5\u30A1\u3092\u5168\u3066\u51FA\u529B\u3059\u308B\
    \r\n            void flush() const {\r\n                [[maybe_unused]] ssize_t\
    \ res = write(writer.fd, writer.buffer.begin(), writer.idx);\r\n            }\r\
    \n        };\r\n\r\n        // \u30D5\u30A1\u30A4\u30EB\u306E\u6700\u521D\u3092\
    \u793A\u3059\u30A4\u30C6\u30EC\u30FC\u30BF\u3092\u53D6\u5F97\r\n        iterator\
    \ begin() noexcept {\r\n            return iterator(*this);\r\n        }\r\n \
    \   };\r\n\r\n    // \u6A19\u6E96\u51FA\u529B\u3001\u6A19\u6E96\u30A8\u30E9\u30FC\
    \u51FA\u529B\r\n    Writer output{1}, error{2};\r\n\r\n    // \u5024\u306E\u51FA\
    \u529B\u306E\u95A2\u6570\u30AF\u30E9\u30B9\r\n    template<class, class = void>\r\
    \n    struct PrintFunction;\r\n\r\n    // \u51FA\u529B\u30A4\u30C6\u30EC\u30FC\
    \u30BF\u3092\u7528\u3044\u3066\u5024\u3092\u51FA\u529B\u3059\u308B\u30AF\u30E9\
    \u30B9\r\n    template<class Iterator, bool _space = true, bool _line = true,\
    \ bool _debug = false, bool _comment = false, bool _flush = false, std::size_t\
    \ decimal_precision = KYOPRO_DECIMAL_PRECISION>\r\n    struct Printer {\r\n  \
    \      using iterator_type = Iterator;\r\n\r\n        // \u6307\u5B9A\u3055\u308C\
    \u305F\u30AA\u30D7\u30B7\u30E7\u30F3\r\n        static constexpr bool space =\
    \ _space, line = _line, debug = _debug, comment = _comment, flush = _flush;\r\n\
    \r\n        // \u6307\u5B9A\u3055\u308C\u305F\u5C0F\u6570\u8AA4\u5DEE\u3092\u53D6\
    \u5F97\r\n        static constexpr KYOPRO_BASE_INT get_decimal_precision() noexcept\
    \ {\r\n            return decimal_precision;\r\n        }\r\n\r\n        // \u51FA\
    \u529B\u30A4\u30C6\u30EC\u30FC\u30BF\r\n        Iterator itr;\r\n\r\n        Printer()\
    \ noexcept = default;\r\n        Printer(Iterator itr) noexcept: itr(itr) {}\r\
    \n\r\n        // \u4E00\u6587\u5B57\u51FA\u529B\u3059\u308B\r\n        void print_char(char\
    \ c) {\r\n            *itr = c;\r\n            ++itr;\r\n        }\r\n\r\n   \
    \     // \u6574\u6570\u3001\u5C0F\u6570\u3092\u51FA\u529B\r\n        template<class\
    \ T>\r\n        void print_arithmetic(T a) {\r\n            if constexpr (is_floating_point_v<T>)\
    \ {\r\n                if (a == std::numeric_limits<T>::infinity()) {\r\n    \
    \                print_char('i');\r\n                    print_char('n');\r\n\
    \                    print_char('f');\r\n                    return;\r\n     \
    \           }\r\n                if (a == -std::numeric_limits<T>::infinity())\
    \ {\r\n                    print_char('-');\r\n                    print_char('i');\r\
    \n                    print_char('n');\r\n                    print_char('f');\r\
    \n                    return;\r\n                }\r\n                if (std::isnan(a))\
    \ {\r\n                    print_char('n');\r\n                    print_char('a');\r\
    \n                    print_char('n');\r\n                    return;\r\n    \
    \            }\r\n            }\r\n            if constexpr (std::is_signed_v<T>)\
    \ if (a < 0) {\r\n                print_char('-');\r\n                a = -a;\r\
    \n            }\r\n            std::uint_fast64_t p = a;\r\n            std::string\
    \ s;\r\n            do {\r\n                s += '0' + p % 10;\r\n           \
    \     p /= 10;\r\n            } while (p > 0);\r\n            for (auto i = s.rbegin();\
    \ i != s.rend(); ++i) print_char(*i);\r\n            if constexpr (is_integer_v<T>)\
    \ return;\r\n            print_char('.');\r\n            a -= p;\r\n         \
    \   for (int i = 0; i < static_cast<int>(decimal_precision); ++i) {\r\n      \
    \          a *= 10;\r\n                print_char('0' + static_cast<std::uint_fast64_t>(a)\
    \ % 10);\r\n            }\r\n        }\r\n\r\n        // \u533A\u5207\u308A\u6587\
    \u5B57\u3092\u51FA\u529B\u3059\u308B\r\n        void print_sep() {\r\n       \
    \     if constexpr (debug) print_char(',');\r\n            if constexpr (space)\
    \ print_char(' ');\r\n        }\r\n\r\n        // \u533A\u5207\u308A\u6587\u5B57\
    \u3092\u51FA\u529B\u3059\u308B(\u578B\u306B\u3088\u3063\u3066\u5909\u66F4)\r\n\
    \        template<class type>\r\n        void print_sep_by_type() {\r\n      \
    \      if constexpr (is_tuple_like_v<type> || is_range_v<type>) {\r\n        \
    \        print_end();\r\n                if constexpr (comment) print_comment();\r\
    \n            } else print_sep();\r\n        }\r\n\r\n        // \u6700\u5F8C\u306E\
    \u6587\u5B57\u3092\u51FA\u529B\u3059\u308B\r\n        void print_end() {\r\n \
    \           if constexpr (debug) print_char(',');\r\n            if constexpr\
    \ (line) print_char('\\n');\r\n        }\r\n\r\n        // \u30B3\u30E1\u30F3\u30C8\
    \u8A18\u53F7\u3092\u51FA\u529B\u3059\u308B\r\n        void print_comment() {\r\
    \n            if constexpr (comment) {\r\n                print_char('#');\r\n\
    \                print_char(' ');\r\n            }\r\n        }\r\n\r\n      \
    \  // \u8907\u6570\u306E\u5024\u3092\u51FA\u529B\r\n        template<bool first\
    \ = true>\r\n        void operator ()() {\r\n            if constexpr (first)\
    \ print_comment();\r\n            print_end();\r\n            if constexpr (flush)\
    \ itr.flush();\r\n        }\r\n        template<bool first = true, class Head,\
    \ class... Args>\r\n        void operator ()(Head&& head, Args&&... args) {\r\n\
    \            if constexpr (first) print_comment();\r\n            else print_sep();\r\
    \n            PrintFunction<std::decay_t<Head>>::print(*this, std::forward<Head>(head));\r\
    \n            operator ()<false>(std::forward<Args>(args)...);\r\n        }\r\n\
    \    };\r\n\r\n    template<>\r\n    struct PrintFunction<char> {\r\n        template<class\
    \ Printer>\r\n        static void print(Printer& printer, char a) {\r\n      \
    \      if constexpr (Printer::debug) printer.print_char('\\'');\r\n          \
    \  printer.print_char(a);\r\n            if constexpr (Printer::debug) printer.print_char('\\\
    '');\r\n        }\r\n    };\r\n\r\n    template<>\r\n    struct PrintFunction<bool>\
    \ {\r\n        template<class Printer>\r\n        static void print(Printer& printer,\
    \ bool a) {\r\n            printer.print_char(static_cast<char>('0' + a));\r\n\
    \        }\r\n    };\r\n\r\n    template<class T>\r\n    struct PrintFunction<T,\
    \ std::enable_if_t<std::is_convertible_v<T, std::string_view>>> {\r\n        template<class\
    \ Printer>\r\n        static void print(Printer& printer, std::string_view a)\
    \ {\r\n            if constexpr (Printer::debug) printer.print_char('\"');\r\n\
    \            for (char i: a) printer.print_char(i);\r\n            if constexpr\
    \ (Printer::debug) printer.print_char('\"');\r\n        }\r\n    };\r\n\r\n  \
    \  template<std::size_t len>\r\n    struct PrintFunction<std::bitset<len>> {\r\
    \n        template<class Printer>\r\n        static void print(Printer& printer,\
    \ const std::bitset<len>& a) {\r\n            for (int i = len - 1; i >= 0; --i)\
    \ PrintFunction<bool>::print(printer, a[i]);\r\n        }\r\n    };\r\n\r\n  \
    \  template<class T>\r\n    struct PrintFunction<T, std::enable_if_t<std::is_arithmetic_v<T>>>\
    \ {\r\n        template<class Printer>\r\n        static void print(Printer& printer,\
    \ T a) {\r\n            printer.print_arithmetic(a);\r\n        }\r\n    };\r\n\
    \r\n    template<class T>\r\n    struct PrintFunction<T, std::enable_if_t<is_tuple_like_v<T>\
    \ && !is_range_v<T>>> {\r\n        template<std::size_t i = 0, class Printer>\r\
    \n        static void print(Printer& printer, const T& a) {\r\n            using\
    \ element_type = std::decay_t<tuple_like_element_t<i, T>>;\r\n            if constexpr\
    \ (Printer::debug && i == 0) printer.print_char('{');\r\n            if constexpr\
    \ (tuple_like_size_v<T> != 0) PrintFunction<element_type>::print(printer, get<i>(a));\r\
    \n            if constexpr (i + 1 < tuple_like_size_v<T>) {\r\n              \
    \  printer.template print_sep_by_type<element_type>();\r\n                print<i\
    \ + 1>(printer, a);\r\n            } else if constexpr (Printer::debug) printer.print_char('}');\r\
    \n        }\r\n    };\r\n\r\n    template<class T>\r\n    struct PrintFunction<T,\
    \ std::enable_if_t<is_range_v<T> && !std::is_convertible_v<T, std::string_view>>>\
    \ {\r\n        template<class Printer>\r\n        static void print(Printer& printer,\
    \ const T& a) {\r\n            using value_type = range_value_t<T>;\r\n      \
    \      if constexpr (Printer::debug) printer.print_char('{');\r\n            if\
    \ (!std::empty(a)) {\r\n                for (auto i = std::begin(a); ; ) {\r\n\
    \                    PrintFunction<value_type>::print(printer, *i);\r\n      \
    \              if (++i != std::end(a)) printer.template print_sep_by_type<value_type>();\r\
    \n                    else break;\r\n                }\r\n            }\r\n  \
    \          if constexpr (Printer::debug) printer.print_char('}');\r\n        }\r\
    \n    };\r\n\r\n    template<class Tuple, std::size_t idx>\r\n    struct PrintFunction<Indexed<Tuple,\
    \ idx>> {\r\n        template<class Printer>\r\n        struct PrinterWrapper:\
    \ Printer {\r\n            template<class T>\r\n            void print_arithmetic(T\
    \ a) {\r\n                Printer::print_arithmetic(a + 1);\r\n            }\r\
    \n        };\r\n        template<class Printer>\r\n        static void print(Printer&\
    \ printer, const Indexed<Tuple, idx>& a) {\r\n            PrinterWrapper<Printer>&\
    \ printer_wrapper = static_cast<PrinterWrapper<Printer>&>(printer);\r\n      \
    \      PrintFunction<Tuple>::print(printer_wrapper, a.args_tuple);\r\n       \
    \ }\r\n    };\r\n\r\n    // \u6A19\u6E96\u51FA\u529B\u3001\u6A19\u6E96\u30A8\u30E9\
    \u30FC\u51FA\u529B\u306B\u5024\u3092\u51FA\u529B\u3059\u308B(\u6539\u884C\u3001\
    \u533A\u5207\u308A\u6587\u5B57\u306A\u3057)\r\n    Printer<Writer<>::iterator,\
    \ false, false> print{output.begin()}, eprint{error.begin()};\r\n    // \u6A19\
    \u6E96\u51FA\u529B\u3001\u6A19\u6E96\u30A8\u30E9\u30FC\u51FA\u529B\u306B\u5024\
    \u3092\u51FA\u529B\u3059\u308B(\u6539\u884C\u3001\u533A\u5207\u308A\u6587\u5B57\
    \u3042\u308A)\r\n    Printer<Writer<>::iterator> println{output.begin()}, eprintln{error.begin()};\r\
    \n} // namespace kpr\r\n"
  dependsOn: []
  isVerificationFile: false
  path: kpr/io/out.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kpr/io/out.hpp
layout: document
redirect_from:
- /library/kpr/io/out.hpp
- /library/kpr/io/out.hpp.html
title: kpr/io/out.hpp
---
