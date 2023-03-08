---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: algorithm/Hash.hpp
    title: algorithm/Hash.hpp
  - icon: ':warning:'
    path: algorithm/algorithm.hpp
    title: algorithm/algorithm.hpp
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  - icon: ':warning:'
    path: all/all.hpp
    title: all/all.hpp
  - icon: ':heavy_check_mark:'
    path: io/in.hpp
    title: io/in.hpp
  - icon: ':heavy_check_mark:'
    path: io/io.hpp
    title: io/io.hpp
  - icon: ':heavy_check_mark:'
    path: io/out.hpp
    title: io/out.hpp
  - icon: ':heavy_check_mark:'
    path: math/DynamicModInt.hpp
    title: math/DynamicModInt.hpp
  - icon: ':warning:'
    path: math/ModInt.hpp
    title: math/ModInt.hpp
  - icon: ':heavy_check_mark:'
    path: math/factorize.hpp
    title: math/factorize.hpp
  - icon: ':heavy_check_mark:'
    path: math/is_prime.hpp
    title: math/is_prime.hpp
  - icon: ':warning:'
    path: math/math.hpp
    title: math/math.hpp
  - icon: ':warning:'
    path: meta/meta.hpp
    title: meta/meta.hpp
  - icon: ':warning:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':warning:'
    path: template/io.hpp
    title: template/io.hpp
  - icon: ':warning:'
    path: template/lambda.hpp
    title: template/lambda.hpp
  - icon: ':warning:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':warning:'
    path: template/named_tuple.hpp
    title: template/named_tuple.hpp
  - icon: ':warning:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':warning:'
    path: template/vals.hpp
    title: template/vals.hpp
  - icon: ':warning:'
    path: test.cpp
    title: test.cpp
  - icon: ':warning:'
    path: verify/hello_world.cpp
    title: verify/hello_world.cpp
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
  bundledCode: "#line 2 \"meta/tuple_like.hpp\"\n#include <cstddef>\r\n#include <type_traits>\r\
    \n#include <tuple>\r\n#include <utility>\r\n\r\nnamespace kpr {\r\n    namespace\
    \ helper {\r\n        struct CastableToAny {\r\n            template<class T>\r\
    \n            operator T() const noexcept;\r\n        };\r\n\r\n        template<class\
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
  path: meta/tuple_like.hpp
  requiredBy:
  - all/all.hpp
  - all.hpp
  - algorithm/algorithm.hpp
  - algorithm/Hash.hpp
  - test.cpp
  - math/factorize.hpp
  - math/is_prime.hpp
  - math/ModInt.hpp
  - math/math.hpp
  - math/DynamicModInt.hpp
  - verify/hello_world.cpp
  - template/named_tuple.hpp
  - template/alias.hpp
  - template/template.hpp
  - template/vals.hpp
  - template/lambda.hpp
  - template/macro.hpp
  - template/io.hpp
  - meta/meta.hpp
  - io/in.hpp
  - io/out.hpp
  - io/io.hpp
  timestamp: '2023-03-07 11:56:47+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/factorize.test.cpp
  - verify/yosupo/many_aplusb.test.cpp
  - verify/yosupo/point_add_range_sum.test.cpp
  - verify/yosupo/unionfind.test.cpp
  - verify/aoj/PrimeNumber.test.cpp
documentation_of: meta/tuple_like.hpp
layout: document
redirect_from:
- /library/meta/tuple_like.hpp
- /library/meta/tuple_like.hpp.html
title: meta/tuple_like.hpp
---
