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
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  [Previous line repeated 2 more times]\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 412, in update\n    raise BundleErrorAt(path, i + 1, \"unmatched #if /\
    \ #ifdef / #ifndef\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ kpr/meta/setting.hpp: line 41: unmatched #if / #ifdef / #ifndef\n"
  code: "#pragma once\n#include <unistd.h>\n#include <cstddef>\n#include <istream>\n\
    #include <string_view>\n#include <tuple>\n#include <type_traits>\n#include <utility>\n\
    #include \"../io/io.hpp\"\n\nnamespace kpr::helper {\n    template<std::size_t\
    \ len>\n    constexpr std::size_t va_args_size(const char (&s)[len]) noexcept\
    \ {\n        if constexpr (len == 1) return 0;\n        std::size_t cnt = 1;\n\
    \        std::uint_fast64_t bracket = 0;\n        for (auto i: s) {\n        \
    \    if (i == '(') ++bracket;\n            else if (i == ')') --bracket;\n   \
    \         else if (i == ',' && bracket == 0) ++cnt;\n        }\n        return\
    \ cnt;\n    }\n\n    template<class F, std::size_t... idx>\n    auto read_impl(F&&\
    \ f, std::index_sequence<idx...>) {\n        return std::tuple{(static_cast<void>(idx),\
    \ f())...};\n    }\n\n    Printer<Writer<>::iterator, true, true, true, true>\
    \ debug_impl(output.begin());\n\n    template<bool flag>\n    void print_if(std::string_view\
    \ sv) {\n        if constexpr (flag) print(' ', sv);\n    }\n} // namespace kpr::helper\n\
    \n/* C++20\u4EE5\u964D\n#define read(type_or_init, ...) \\\n    auto [__VA_ARGS__]\
    \ = (kpr::helper::read_impl(([]() { \\\n        using T = std::decay_t<decltype(*new\
    \ type_or_init)>; \\\n        alignas(T) std::byte storage[sizeof(T)]; \\\n  \
    \      T* p = new (storage) type_or_init; \\\n        kpr::scan(*p); \\\n    \
    \    T res = std::move(*p); \\\n        p->~T(); \\\n        return res; \\\n\
    \    }), std::make_index_sequence<kpr::helper::va_args_size(#__VA_ARGS__)>()))\n\
    */\n\n#define BOOL(...) bool __VA_ARGS__; scan(__VA_ARGS__)\n#define INT(...)\
    \ int __VA_ARGS__; scan(__VA_ARGS__)\n#define LL(...) ll __VA_ARGS__; scan(__VA_ARGS__)\n\
    #define FLOAT(...) float __VA_ARGS__; scan(__VA_ARGS__)\n#define LF(...) lf __VA_ARGS__;\
    \ scan(__VA_ARGS__)\n#define LLF(...) llf __VA_ARGS__; scan(__VA_ARGS__)\n#define\
    \ MINT(...) mint __VA_ARGS__; scan(__VA_ARGS__)\n#define DMINT(...) dmint __VA_ARGS__;\
    \ scan(__VA_ARGS__)\n#define CHAR(...) char __VA_ARGS__; scan(__VA_ARGS__)\n#define\
    \ STR(...) str __VA_ARGS__; scan(__VA_ARGS__)\n#define LL1(...) ll1 __VA_ARGS__;\
    \ scan(__VA_ARGS__)\n#define LL2(...) ll2 __VA_ARGS__; scan(__VA_ARGS__)\n#define\
    \ LL3(...) ll3 __VA_ARGS__; scan(__VA_ARGS__)\n#define LL4(...) ll4 __VA_ARGS__;\
    \ scan(__VA_ARGS__)\n#define LL5(...) ll5 __VA_ARGS__; scan(__VA_ARGS__)\n\n#define\
    \ KYOPRO_READ1(init, _1) auto _1 = init; scan(_1)\n#define KYOPRO_READ2(init,\
    \ _1, _2) auto _1 = init, _2 = init; scan(_1, _2)\n#define KYOPRO_READ3(init,\
    \ _1, _2, _3) auto _1 = init, _2 = init, _3 = init; scan(_1, _2, _3)\n#define\
    \ KYOPRO_READ4(init, _1, _2, _3, _4) auto _1 = init, _2 = init, _3 = init, _4\
    \ = init; scan(_1, _2, _3, _4)\n\n#define KYOPRO_OVERLOAD_READ(_1, _2, _3, _4,\
    \ _5, name, ...) name\n#define read(...) KYOPRO_OVERLOAD_READ(__VA_ARGS__, KYOPRO_READ4,\
    \ KYOPRO_READ3, KYOPRO_READ2, KYOPRO_READ1)(__VA_ARGS__)\n\n#ifdef NDEBUG\n#define\
    \ debug(...) (void())\n#else\n#define debug(...) (kpr::print('#', ' ', 'l', 'i',\
    \ 'n', 'e', ' ', __LINE__, ':'), kpr::helper::print_if<kpr::helper::va_args_size(#__VA_ARGS__)\
    \ != 0>(#__VA_ARGS__), kpr::print('\\n'), kpr::helper::debug_impl(__VA_ARGS__))\n\
    #endif\n"
  dependsOn: []
  isVerificationFile: false
  path: kpr/template/io_macro.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kpr/template/io_macro.hpp
layout: document
redirect_from:
- /library/kpr/template/io_macro.hpp
- /library/kpr/template/io_macro.hpp.html
title: kpr/template/io_macro.hpp
---
