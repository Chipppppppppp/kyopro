---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: kyopro/algorithm/Hash.hpp
    title: kyopro/algorithm/Hash.hpp
  - icon: ':warning:'
    path: kyopro/algorithm/algorithm.hpp
    title: kyopro/algorithm/algorithm.hpp
  - icon: ':warning:'
    path: kyopro/algorithm/contains.hpp
    title: kyopro/algorithm/contains.hpp
  - icon: ':warning:'
    path: kyopro/all.hpp
    title: kyopro/all.hpp
  - icon: ':warning:'
    path: kyopro/all/all.hpp
    title: kyopro/all/all.hpp
  - icon: ':heavy_check_mark:'
    path: kyopro/io/in.hpp
    title: kyopro/io/in.hpp
  - icon: ':heavy_check_mark:'
    path: kyopro/io/io.hpp
    title: kyopro/io/io.hpp
  - icon: ':heavy_check_mark:'
    path: kyopro/io/out.hpp
    title: kyopro/io/out.hpp
  - icon: ':warning:'
    path: kyopro/math/BinomMod.hpp
    title: kyopro/math/BinomMod.hpp
  - icon: ':heavy_check_mark:'
    path: kyopro/math/DynamicModInt.hpp
    title: kyopro/math/DynamicModInt.hpp
  - icon: ':warning:'
    path: kyopro/math/ModInt.hpp
    title: kyopro/math/ModInt.hpp
  - icon: ':heavy_check_mark:'
    path: kyopro/math/factorize.hpp
    title: kyopro/math/factorize.hpp
  - icon: ':heavy_check_mark:'
    path: kyopro/math/is_prime.hpp
    title: kyopro/math/is_prime.hpp
  - icon: ':warning:'
    path: kyopro/math/math.hpp
    title: kyopro/math/math.hpp
  - icon: ':warning:'
    path: kyopro/meta/meta.hpp
    title: kyopro/meta/meta.hpp
  - icon: ':warning:'
    path: kyopro/template/alias.hpp
    title: kyopro/template/alias.hpp
  - icon: ':warning:'
    path: kyopro/template/io_macro.hpp
    title: kyopro/template/io_macro.hpp
  - icon: ':warning:'
    path: kyopro/template/lambda_macro.hpp
    title: kyopro/template/lambda_macro.hpp
  - icon: ':warning:'
    path: kyopro/template/macro.hpp
    title: kyopro/template/macro.hpp
  - icon: ':warning:'
    path: kyopro/template/named_tuple_macro.hpp
    title: kyopro/template/named_tuple_macro.hpp
  - icon: ':warning:'
    path: kyopro/template/template.hpp
    title: kyopro/template/template.hpp
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
  bundledCode: "#line 2 \"kyopro/meta/tuple_like.hpp\"\n#include <cstddef>\r\n#include\
    \ <type_traits>\r\n#include <tuple>\r\n#include <utility>\r\n\r\nnamespace kpr\
    \ {\r\n    namespace helper {\r\n        struct CastableToAny {\r\n          \
    \  template<class T>\r\n            operator T() const noexcept;\r\n        };\r\
    \n\r\n        template<class T, std::size_t... idx, std::void_t<decltype(T{((void)idx,\
    \ CastableToAny{})...})>* = nullptr>\r\n        constexpr bool is_constructible_with(std::index_sequence<idx...>,\
    \ bool) noexcept {\r\n            return true;\r\n        }\r\n        template<class\
    \ T, std::size_t... idx>\r\n        constexpr bool is_constructible_with(std::index_sequence<idx...>,\
    \ char) noexcept {\r\n            return false;\r\n        }\n\n        template<class\
    \ T, std::size_t n = sizeof(T) * 8, class = void>\n        struct constructible_size\
    \ {\n            static_assert(n != 0, \"T is not constructible\");\n        \
    \    static constexpr std::size_t value = constructible_size<T, n - 1>::value;\n\
    \        };\n\n        template<class T, std::size_t n>\n        struct constructible_size<T,\
    \ n, std::enable_if_t<is_constructible_with<T>(std::make_index_sequence<n>(),\
    \ false)>> {\n            static constexpr std::size_t value = n;\n        };\r\
    \n    } // namespace helper\r\n\n\r\n    // tuple_like\u306A\u578BT\u306E\u5927\
    \u304D\u3055\u3092\u8ABF\u3079\u308B\r\n    template<class T, class = void>\r\n\
    \    struct tuple_like_size {\r\n        static constexpr std::size_t value =\
    \ helper::constructible_size<T>::value;\r\n    };\r\n\r\n    template<class T>\r\
    \n    struct tuple_like_size<T, std::void_t<decltype(std::tuple_size<T>::value)>>\
    \ {\r\n        static constexpr std::size_t value = std::tuple_size_v<T>;\r\n\
    \    };\r\n\r\n    // tuple_like\u306A\u578BT\u306E\u5927\u304D\u3055\u3092\u8ABF\
    \u3079\u308B\r\n    template<class T>\r\n    inline constexpr std::size_t tuple_like_size_v\
    \ = tuple_like_size<T>::value;\r\n\r\n\n    // tuple_like\u306A\u30AA\u30D6\u30B8\
    \u30A7\u30AF\u30C8\u306Eidx(0 <= idx < 8)\u756A\u76EE\u3092\u6C42\u3081\u308B\u95A2\
    \u6570\u30AF\u30E9\u30B9\n    template<class T, class = void>\n    struct GetFunction\
    \ {\n        #define GET(...) \\\n            { \\\n                auto&& [__VA_ARGS__]\
    \ = std::forward<U>(tuple_like); \\\n                return std::get<idx> (std::forward_as_tuple(__VA_ARGS__));\
    \ \\\n            }\n\n        template<std::size_t idx, class U>\n        static\
    \ constexpr decltype(auto) get(U&& tuple_like) noexcept {\n            constexpr\
    \ std::size_t size = tuple_like_size_v<T>;\n            static_assert(size !=\
    \ 0, \"The size must not be 0\");\n            static_assert(size < 9, \"The size\
    \ of tuple_like must be less than 9\");\n            if constexpr (size == 1)\
    \ GET(a)\n            else if constexpr (size == 2) GET(a, b)\n            else\
    \ if constexpr (size == 3) GET(a, b, c)\n            else if constexpr (size ==\
    \ 4) GET(a, b, c, d)\n            else if constexpr (size == 5) GET(a, b, c, d,\
    \ e)\n            else if constexpr (size == 6) GET(a, b, c, d, e, f)\n      \
    \      else if constexpr (size == 7) GET(a, b, c, d, e, f, g)\n            else\
    \ GET(a, b, c, d, e, f, g, h)\n        }\n\n        #undef GET\n    };\n\n   \
    \ template<class T>\n    struct GetFunction<T, std::void_t<decltype(std::tuple_size<T>::value)>>\
    \ {\n        template<std::size_t idx, class U>\n        static constexpr decltype(auto)\
    \ get(U&& tuple_like) noexcept {\n            return std::get<idx>(std::forward<U>(tuple_like));\n\
    \        }\n    };\r\n\r\n    namespace helper {\n        template<std::size_t\
    \ idx>\r\n        struct GetHelper {\r\n            template<class T>\r\n    \
    \        constexpr decltype(auto) operator ()(T&& tuple_like) const noexcept {\r\
    \n                return GetFunction<std::decay_t<T>>::template get<idx>(std::forward<T>(tuple_like));\r\
    \n            }\r\n        };\r\n    }\r\n\r\n    // tuple-like\u306A\u30AA\u30D6\
    \u30B8\u30A7\u30AF\u30C8\u306Eidx(0 <= idx < 8)\u756A\u76EE\u3092\u6C42\u3081\u308B\
    \r\n    template<std::size_t idx>\r\n    inline constexpr helper::GetHelper<idx>\
    \ get;\r\n\r\n\r\n    // tuple-like\u306A\u578BT\u306Eidx(0 <= idx < 8)\u756A\u76EE\
    \u306E\u8981\u7D20\u306E\u578B\u3092\u8ABF\u3079\u308B\r\n    template<std::size_t\
    \ idx, class T>\r\n    struct tuple_like_element {\r\n        using type = decltype(get<idx>(std::declval<T>()));\r\
    \n    };\r\n\r\n    // tuple-like\u306A\u578BT\u306Eidx(0 <= idx < 8)\u756A\u76EE\
    \u306E\u8981\u7D20\u306E\u578B\u3092\u8ABF\u3079\u308B\r\n    template<std::size_t\
    \ idx, class T>\r\n    using tuple_like_element_t = typename tuple_like_element<idx,\
    \ T>::type;\n\n\n    // \u578BT\u304Ctuple_like\u304B\u8ABF\u3079\u308B\n    template<class,\
    \ class = void>\n    struct is_tuple_like {\n        static constexpr bool value\
    \ = false;\n    };\n\n    template<class T>\n    struct is_tuple_like<T, std::enable_if_t<std::is_aggregate_v<T>>>\
    \ {\n        static constexpr bool value = true;\n    };\n\n    template<class\
    \ T>\n    struct is_tuple_like<T, std::void_t<decltype(std::tuple_size<T>::value)>>\
    \ {\n        static constexpr bool value = true;\n    };\n\n    // \u578BT\u304C\
    tuple_like\u304B\u8ABF\u3079\u308B\n    template<class T>\n    inline constexpr\
    \ bool is_tuple_like_v = is_tuple_like<T>::value;\r\n} // namespace kpr\r\n"
  code: "#pragma once\r\n#include <cstddef>\r\n#include <type_traits>\r\n#include\
    \ <tuple>\r\n#include <utility>\r\n\r\nnamespace kpr {\r\n    namespace helper\
    \ {\r\n        struct CastableToAny {\r\n            template<class T>\r\n   \
    \         operator T() const noexcept;\r\n        };\r\n\r\n        template<class\
    \ T, std::size_t... idx, std::void_t<decltype(T{((void)idx, CastableToAny{})...})>*\
    \ = nullptr>\r\n        constexpr bool is_constructible_with(std::index_sequence<idx...>,\
    \ bool) noexcept {\r\n            return true;\r\n        }\r\n        template<class\
    \ T, std::size_t... idx>\r\n        constexpr bool is_constructible_with(std::index_sequence<idx...>,\
    \ char) noexcept {\r\n            return false;\r\n        }\n\n        template<class\
    \ T, std::size_t n = sizeof(T) * 8, class = void>\n        struct constructible_size\
    \ {\n            static_assert(n != 0, \"T is not constructible\");\n        \
    \    static constexpr std::size_t value = constructible_size<T, n - 1>::value;\n\
    \        };\n\n        template<class T, std::size_t n>\n        struct constructible_size<T,\
    \ n, std::enable_if_t<is_constructible_with<T>(std::make_index_sequence<n>(),\
    \ false)>> {\n            static constexpr std::size_t value = n;\n        };\r\
    \n    } // namespace helper\r\n\n\r\n    // tuple_like\u306A\u578BT\u306E\u5927\
    \u304D\u3055\u3092\u8ABF\u3079\u308B\r\n    template<class T, class = void>\r\n\
    \    struct tuple_like_size {\r\n        static constexpr std::size_t value =\
    \ helper::constructible_size<T>::value;\r\n    };\r\n\r\n    template<class T>\r\
    \n    struct tuple_like_size<T, std::void_t<decltype(std::tuple_size<T>::value)>>\
    \ {\r\n        static constexpr std::size_t value = std::tuple_size_v<T>;\r\n\
    \    };\r\n\r\n    // tuple_like\u306A\u578BT\u306E\u5927\u304D\u3055\u3092\u8ABF\
    \u3079\u308B\r\n    template<class T>\r\n    inline constexpr std::size_t tuple_like_size_v\
    \ = tuple_like_size<T>::value;\r\n\r\n\n    // tuple_like\u306A\u30AA\u30D6\u30B8\
    \u30A7\u30AF\u30C8\u306Eidx(0 <= idx < 8)\u756A\u76EE\u3092\u6C42\u3081\u308B\u95A2\
    \u6570\u30AF\u30E9\u30B9\n    template<class T, class = void>\n    struct GetFunction\
    \ {\n        #define GET(...) \\\n            { \\\n                auto&& [__VA_ARGS__]\
    \ = std::forward<U>(tuple_like); \\\n                return std::get<idx> (std::forward_as_tuple(__VA_ARGS__));\
    \ \\\n            }\n\n        template<std::size_t idx, class U>\n        static\
    \ constexpr decltype(auto) get(U&& tuple_like) noexcept {\n            constexpr\
    \ std::size_t size = tuple_like_size_v<T>;\n            static_assert(size !=\
    \ 0, \"The size must not be 0\");\n            static_assert(size < 9, \"The size\
    \ of tuple_like must be less than 9\");\n            if constexpr (size == 1)\
    \ GET(a)\n            else if constexpr (size == 2) GET(a, b)\n            else\
    \ if constexpr (size == 3) GET(a, b, c)\n            else if constexpr (size ==\
    \ 4) GET(a, b, c, d)\n            else if constexpr (size == 5) GET(a, b, c, d,\
    \ e)\n            else if constexpr (size == 6) GET(a, b, c, d, e, f)\n      \
    \      else if constexpr (size == 7) GET(a, b, c, d, e, f, g)\n            else\
    \ GET(a, b, c, d, e, f, g, h)\n        }\n\n        #undef GET\n    };\n\n   \
    \ template<class T>\n    struct GetFunction<T, std::void_t<decltype(std::tuple_size<T>::value)>>\
    \ {\n        template<std::size_t idx, class U>\n        static constexpr decltype(auto)\
    \ get(U&& tuple_like) noexcept {\n            return std::get<idx>(std::forward<U>(tuple_like));\n\
    \        }\n    };\r\n\r\n    namespace helper {\n        template<std::size_t\
    \ idx>\r\n        struct GetHelper {\r\n            template<class T>\r\n    \
    \        constexpr decltype(auto) operator ()(T&& tuple_like) const noexcept {\r\
    \n                return GetFunction<std::decay_t<T>>::template get<idx>(std::forward<T>(tuple_like));\r\
    \n            }\r\n        };\r\n    }\r\n\r\n    // tuple-like\u306A\u30AA\u30D6\
    \u30B8\u30A7\u30AF\u30C8\u306Eidx(0 <= idx < 8)\u756A\u76EE\u3092\u6C42\u3081\u308B\
    \r\n    template<std::size_t idx>\r\n    inline constexpr helper::GetHelper<idx>\
    \ get;\r\n\r\n\r\n    // tuple-like\u306A\u578BT\u306Eidx(0 <= idx < 8)\u756A\u76EE\
    \u306E\u8981\u7D20\u306E\u578B\u3092\u8ABF\u3079\u308B\r\n    template<std::size_t\
    \ idx, class T>\r\n    struct tuple_like_element {\r\n        using type = decltype(get<idx>(std::declval<T>()));\r\
    \n    };\r\n\r\n    // tuple-like\u306A\u578BT\u306Eidx(0 <= idx < 8)\u756A\u76EE\
    \u306E\u8981\u7D20\u306E\u578B\u3092\u8ABF\u3079\u308B\r\n    template<std::size_t\
    \ idx, class T>\r\n    using tuple_like_element_t = typename tuple_like_element<idx,\
    \ T>::type;\n\n\n    // \u578BT\u304Ctuple_like\u304B\u8ABF\u3079\u308B\n    template<class,\
    \ class = void>\n    struct is_tuple_like {\n        static constexpr bool value\
    \ = false;\n    };\n\n    template<class T>\n    struct is_tuple_like<T, std::enable_if_t<std::is_aggregate_v<T>>>\
    \ {\n        static constexpr bool value = true;\n    };\n\n    template<class\
    \ T>\n    struct is_tuple_like<T, std::void_t<decltype(std::tuple_size<T>::value)>>\
    \ {\n        static constexpr bool value = true;\n    };\n\n    // \u578BT\u304C\
    tuple_like\u304B\u8ABF\u3079\u308B\n    template<class T>\n    inline constexpr\
    \ bool is_tuple_like_v = is_tuple_like<T>::value;\r\n} // namespace kpr\r\n"
  dependsOn: []
  isVerificationFile: false
  path: kyopro/meta/tuple_like.hpp
  requiredBy:
  - kyopro/io/in.hpp
  - kyopro/io/out.hpp
  - kyopro/io/io.hpp
  - kyopro/all/all.hpp
  - kyopro/meta/meta.hpp
  - kyopro/all.hpp
  - kyopro/math/is_prime.hpp
  - kyopro/math/factorize.hpp
  - kyopro/math/ModInt.hpp
  - kyopro/math/math.hpp
  - kyopro/math/BinomMod.hpp
  - kyopro/math/DynamicModInt.hpp
  - kyopro/algorithm/algorithm.hpp
  - kyopro/algorithm/contains.hpp
  - kyopro/algorithm/Hash.hpp
  - kyopro/template/template.hpp
  - kyopro/template/macro.hpp
  - kyopro/template/io_macro.hpp
  - kyopro/template/lambda_macro.hpp
  - kyopro/template/named_tuple_macro.hpp
  - kyopro/template/alias.hpp
  timestamp: '2023-04-02 21:40:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/many_aplusb.test.cpp
  - verify/yosupo/factorize.test.cpp
  - verify/yosupo/point_add_range_sum.test.cpp
  - verify/yosupo/unionfind.test.cpp
  - verify/aoj/PrimeNumber.test.cpp
documentation_of: kyopro/meta/tuple_like.hpp
layout: document
redirect_from:
- /library/kyopro/meta/tuple_like.hpp
- /library/kyopro/meta/tuple_like.hpp.html
title: kyopro/meta/tuple_like.hpp
---
