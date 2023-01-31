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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../system/all.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include <cstddef>\n#include <iterator>\n#include <memory>\n\
    #include <tuple>\n#include <type_traits>\n#include <utility>\n#include \"../system/all.hpp\"\
    \n\nnamespace kpr::helper {\n    template<std::size_t len>\n    constexpr std::size_t\
    \ va_args_size(const char (&s)[len]) noexcept {\n        if constexpr (len ==\
    \ 1) return 0;\n        std::size_t cnt = 1;\n        std::uint_fast64_t bracket\
    \ = 0;\n        for (auto i: s) {\n            if (i == '(') ++bracket;\n    \
    \        else if (i == ')') --bracket;\n            else if (i == ',' && bracket\
    \ == 0) ++cnt;\n        }\n        return cnt;\n    }\n\n    template<class F,\
    \ std::size_t... idx>\n    auto read_impl(F&& f, std::index_sequence<idx...>)\
    \ {\n        return std::tuple{(static_cast<void>(idx), f())...};\n    }\n\n \
    \   Printer<Writer<>::iterator, true, true, true, true, true> debug_impl(output.begin());\n\
    \n    template<bool flag, std::size_t len>\n    void print_if(const char (&s)[len])\
    \ {\n        if constexpr (flag) print(' ', s);\n    }\n\n    struct LambdaArg\
    \ {};\n} // namespace kpr::helper\n\n#define read(type_or_init, ...)         \
    \                                                  \\\nauto [__VA_ARGS__] = (kpr::helper::read_impl(([]()\
    \ {                                   \\\n    using T = std::decay_t<decltype(*new\
    \ type_or_init)>;                                  \\\n    alignas(T) std::byte\
    \ storage[sizeof(T)];                                              \\\n    T*\
    \ p = new (storage) type_or_init;                                            \
    \        \\\n    kpr::scan(*p);                                              \
    \                       \\\n    T res = std::move(*p);                       \
    \                                         \\\n    p->~T();                   \
    \                                                           \\\n    return res;\
    \                                                                           \\\
    \n}), std::make_index_sequence<kpr::helper::va_args_size(#__VA_ARGS__)>()))\n\
    #define debug(...) (kpr::print('#', ' ', 'l', 'i', 'n', 'e', ' ', __LINE__, ':'),\
    \ kpr::helper::print_if<kpr::helper::va_args_size(#__VA_ARGS__) != 0>(#__VA_ARGS__),\
    \ kpr::print('\\n'), kpr::helper::debug_impl(__VA_ARGS__))\n\n#define KYOPRO_OVERLOAD_MACRO(_1,\
    \ _2, _3, _4, name, ...) name\n\n#define KYOPRO_REP0() for (; ; )\n#define KYOPRO_REP1(last)\
    \ KYOPRO_REP2(KYOPRO_COUNTER, last)\n#define KYOPRO_REP2(i, last) for (auto i\
    \ = std::decay_t<decltype(last)>(), KYOPRO_LAST = (last); (i) < (KYOPRO_LAST);\
    \ ++(i))\n#define KYOPRO_REP3(i, first, last) for (auto i = (first), KYOPRO_LAST\
    \ = last; (i) < (KYOPRO_LAST); ++(i))\n#define rep(...) KYOPRO_OVERLOAD_MACRO(__VA_ARGS__\
    \ __VA_OPT__(,) KYOPRO_REP4, KYOPRO_REP3, KYOPRO_REP2, KYOPRO_REP1, KYOPRO_REP0)(__VA_ARGS__)\n\
    \n#define KYOPRO_MATCH1(_1) break; case _1:\n#define KYOPRO_MATCH2(_1, _2) break;\
    \ case _1: case _2:\n#define KYOPRO_MATCH3(_1, _2, _3) break; case _1: case _2:\
    \ case _3:\n#define KYOPRO_MATCH4(_1, _2, _3, _4) break; case _1: case _2: case\
    \ _3: case _4:\n#define match(...) KYOPRO_OVERLOAD_MACRO(__VA_ARGS__, KYOPRO_MATCH4,\
    \ KYOPRO_MATCH3, KYOPRO_MATCH2, KYOPRO_MATCH1)(__VA_ARGS__)\n#define otherwise\
    \ break; default:\n\n#define $(...)                                          \
    \                                                                            \
    \                                                                            \
    \                                                                            \
    \                           \\\n([&](auto&&... args) {                       \
    \                                                                            \
    \                                                                            \
    \                                                                            \
    \                                           \\\n    [[maybe_unused]] auto&& $0\
    \ = std::forward<std::tuple_element_t<0, std::tuple<decltype(args)..., kpr::helper::LambdaArg>>>(std::get<0>(std::forward_as_tuple(args...,\
    \ kpr::helper::LambdaArg{})));                                               \
    \                                                                  \\\n    [[maybe_unused]]\
    \ auto&& $1 = std::forward<std::tuple_element_t<1, std::tuple<decltype(args)...,\
    \ kpr::helper::LambdaArg, kpr::helper::LambdaArg>>>(std::get<1>(std::forward_as_tuple(args...,\
    \ kpr::helper::LambdaArg{}, kpr::helper::LambdaArg{})));                     \
    \                                    \\\n    [[maybe_unused]] auto&& $2 = std::forward<std::tuple_element_t<2,\
    \ std::tuple<decltype(args)..., kpr::helper::LambdaArg, kpr::helper::LambdaArg,\
    \ kpr::helper::LambdaArg>>>(std::get<2>(std::forward_as_tuple(args..., kpr::helper::LambdaArg{},\
    \ kpr::helper::LambdaArg{}, kpr::helper::LambdaArg{}))); \\\n    return (__VA_ARGS__);\
    \                                                                            \
    \                                                                            \
    \                                                                            \
    \                                                               \\\n})\n\n#define\
    \ all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)\n#define rall(...) std::rbegin(__VA_ARGS__),\
    \ std::rend(__VA_ARGS__)\n"
  dependsOn: []
  isVerificationFile: false
  path: template/macro.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/macro.hpp
layout: document
redirect_from:
- /library/template/macro.hpp
- /library/template/macro.hpp.html
title: template/macro.hpp
---
