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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: kyopro/function/monoid.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include <type_traits>\n#include <utility>\n#include \"kyopro/io/in.hpp\"\
    \n#include \"kyopro/io/out.hpp\"\n#include \"kyopro/meta/tuple_like.hpp\"\n\n\
    namespace kpr {\n    template<class Derived, std::size_t _size>\n    struct NamedTupleBase\
    \ {\n        using named_tuple_tag = void;\n        static constexpr std::size_t\
    \ size = _size;\n\n    private:\n        template<std::size_t i = 0, class T>\n\
    \        void assign(T&& named_tuple) noexcept {\n            if constexpr (i\
    \ < tuple_like_size_v<Derived>) {\n                get<i>(static_cast<Derived&>(*this))\
    \ = get<i>(named_tuple);\n                assign<i + 1>(std::forward<T>(named_tuple));\n\
    \            }\n        }\n\n    public:\n        template<class T, typename std::decay_t<T>::named_tuple_tag*\
    \ = nullptr>\n        NamedTupleBase(T&& named_tuple) noexcept {\n           \
    \ assign(std::forward<T>(named_tuple));\n        }\n\n        template<class...\
    \ Args>\n        NamedTupleBase(Args&&... args) noexcept {\n            assign(std::forward_as_tuple(std::forward<Args>(args)...));\n\
    \        }\n    };\n\n    template<class T>\n    struct tuple_like_size<T, typename\
    \ T::named_tuple_tag> {\n        static constexpr std::size_t value = T::size;\n\
    \    };\n\n    template<class T>\n    struct GetFunction<T, typename T::named_tuple_tag>\
    \ {\n        #define GET(...) \\\n            { \\\n                auto&& [__VA_ARGS__]\
    \ = std::forward<U>(tuple_like); \\\n                return std::get<idx>(std::forward_as_tuple(__VA_ARGS__));\
    \ \\\n            }\n        template<std::size_t idx, class U>\n        static\
    \ constexpr decltype(auto) get(U&& tuple_like) noexcept {\n            static_assert(T::size\
    \ != 0, \"The size must not be 0\");\n            if constexpr (T::size == 1)\
    \ GET(a)\n            else if constexpr (T::size == 2) GET(a, b)\n           \
    \ else if constexpr (T::size == 3) GET(a, b, c)\n            else if constexpr\
    \ (T::size == 4) GET(a, b, c, d)\n            else if constexpr (T::size == 5)\
    \ GET(a, b, c, d, e)\n        }\n    };\n\n    template<class T>\n    struct is_tuple_like<T,\
    \ typename T::named_tuple_tag> {\n        static constexpr bool value = true;\n\
    \    };\n}\n\n#define KYOPRO_NAMED_TUPLE0() \\\n    ([] { \\\n        struct NamedTuple:\
    \ kpr::NamedTupleBase<NamedTuple, 0> { \\\n            using kpr::NamedTupleBase<NamedTuple,\
    \ 0>::NamedTupleBase; \\\n        }; \\\n        return NamedTuple{}; \\\n   \
    \ })()\n#define KYOPRO_NAMED_TUPLE1(name0, value0) \\\n    ([] { \\\n        struct\
    \ NamedTuple: kpr::NamedTupleBase<NamedTuple, 1> { \\\n            using kpr::NamedTupleBase<NamedTuple,\
    \ 1>::NamedTupleBase; \\\n            std::decay_t<decltype(value0)> name0; \\\
    \n        }; \\\n        return NamedTuple{value0}; \\\n    })()\n#define KYOPRO_NAMED_TUPLE2(name0,\
    \ value0, name1, value1) \\\n    ([] { \\\n        struct NamedTuple: kpr::NamedTupleBase<NamedTuple,\
    \ 2> { \\\n            using kpr::NamedTupleBase<NamedTuple, 2>::NamedTupleBase;\
    \ \\\n            std::decay_t<decltype(value0)> name0; \\\n            std::decay_t<decltype(value1)>\
    \ name1; \\\n        }; \\\n        return NamedTuple{value0, value1}; \\\n  \
    \  })()\n#define KYOPRO_NAMED_TUPLE3(name0, value0, name1, value1, name2, value2)\
    \ \\\n    ([] { \\\n        struct NamedTuple: kpr::NamedTupleBase<NamedTuple,\
    \ 3> { \\\n            using kpr::NamedTupleBase<NamedTuple, 3>::NamedTupleBase;\
    \ \\\n            std::decay_t<decltype(value0)> name0; \\\n            std::decay_t<decltype(value1)>\
    \ name1; \\\n            std::decay_t<decltype(value2)> name2; \\\n        };\
    \ \\\n        return NamedTuple{value0, value1, value2}; \\\n    })()\n#define\
    \ KYOPRO_NAMED_TUPLE4(name0, value0, name1, value1, name2, value2, name3, value3)\
    \ \\\n    ([] { \\\n        struct NamedTuple: kpr::NamedTupleBase<NamedTuple,\
    \ 4> { \\\n            using kpr::NamedTupleBase<NamedTuple, 4>::NamedTupleBase;\
    \ \\\n            std::decay_t<decltype(value0)> name0; \\\n            std::decay_t<decltype(value1)>\
    \ name1; \\\n            std::decay_t<decltype(value2)> name2; \\\n          \
    \  std::decay_t<decltype(value3)> name3; \\\n        }; \\\n        return NamedTuple{value0,\
    \ value1, value2, value3}; \\\n    })()\n#define KYOPRO_NAMED_TUPLE5(name0, value0,\
    \ name1, value1, name2, value2, name3, value3, name4, value4) \\\n    ([] { \\\
    \n        struct NamedTuple: kpr::NamedTupleBase<NamedTuple, 5> { \\\n       \
    \     using kpr::NamedTupleBase<NamedTuple, 5>::NamedTupleBase; \\\n         \
    \   std::decay_t<decltype(value0)> name0; \\\n            std::decay_t<decltype(value1)>\
    \ name1; \\\n            std::decay_t<decltype(value2)> name2; \\\n          \
    \  std::decay_t<decltype(value3)> name3; \\\n            std::decay_t<decltype(value4)>\
    \ name4; \\\n        }; \\\n        return NamedTuple{value0, value1, value2,\
    \ value3, value4}; \\\n    })()\n\n#define KYOPRO_OVERLOAD_NAMED_TUPLE(_1, _2,\
    \ _3, _4, _5, _6, _7, _8, _9, _10, name, ...) name\n\n#define $$(...) KYOPRO_OVERLOAD_NAMED_TUPLE(__VA_ARGS__\
    \ __VA_OPT__(,) KYOPRO_NAMED_TUPLE5, nullptr, KYOPRO_NAMED_TUPLE4, nullptr, KYOPRO_NAMED_TUPLE3,\
    \ nullptr, KYOPRO_NAMED_TUPLE2, nullptr, KYOPRO_NAMED_TUPLE1, nullptr, KYOPRO_NAMED_TUPLE0)(__VA_ARGS__)\n"
  dependsOn: []
  isVerificationFile: false
  path: kyopro/template/named_tuple_macro.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kyopro/template/named_tuple_macro.hpp
layout: document
redirect_from:
- /library/kyopro/template/named_tuple_macro.hpp
- /library/kyopro/template/named_tuple_macro.hpp.html
title: kyopro/template/named_tuple_macro.hpp
---
