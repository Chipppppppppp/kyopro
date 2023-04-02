---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: kyopro/algorithm/Hash.hpp
    title: kyopro/algorithm/Hash.hpp
  - icon: ':heavy_check_mark:'
    path: kyopro/algorithm/bit.hpp
    title: kyopro/algorithm/bit.hpp
  - icon: ':warning:'
    path: kyopro/function/compare.hpp
    title: kyopro/function/compare.hpp
  - icon: ':heavy_check_mark:'
    path: kyopro/function/monoid.hpp
    title: kyopro/function/monoid.hpp
  - icon: ':heavy_check_mark:'
    path: kyopro/io/in.hpp
    title: kyopro/io/in.hpp
  - icon: ':heavy_check_mark:'
    path: kyopro/io/io.hpp
    title: kyopro/io/io.hpp
  - icon: ':heavy_check_mark:'
    path: kyopro/io/io_option.hpp
    title: kyopro/io/io_option.hpp
  - icon: ':heavy_check_mark:'
    path: kyopro/io/out.hpp
    title: kyopro/io/out.hpp
  - icon: ':heavy_check_mark:'
    path: kyopro/math/DynamicModInt.hpp
    title: kyopro/math/DynamicModInt.hpp
  - icon: ':warning:'
    path: kyopro/math/ModInt.hpp
    title: kyopro/math/ModInt.hpp
  - icon: ':heavy_check_mark:'
    path: kyopro/math/Montgomery.hpp
    title: kyopro/math/Montgomery.hpp
  - icon: ':warning:'
    path: kyopro/math/mod.hpp
    title: kyopro/math/mod.hpp
  - icon: ':heavy_check_mark:'
    path: kyopro/math/power.hpp
    title: kyopro/math/power.hpp
  - icon: ':heavy_check_mark:'
    path: kyopro/meta/constant.hpp
    title: kyopro/meta/constant.hpp
  - icon: ':heavy_check_mark:'
    path: kyopro/meta/setting.hpp
    title: kyopro/meta/setting.hpp
  - icon: ':heavy_check_mark:'
    path: kyopro/meta/trait.hpp
    title: kyopro/meta/trait.hpp
  - icon: ':heavy_check_mark:'
    path: kyopro/meta/tuple_like.hpp
    title: kyopro/meta/tuple_like.hpp
  - icon: ':warning:'
    path: kyopro/template/alias.hpp
    title: kyopro/template/alias.hpp
  - icon: ':warning:'
    path: kyopro/template/all_rall_macro.hpp
    title: kyopro/template/all_rall_macro.hpp
  - icon: ':warning:'
    path: kyopro/template/chmin_chmax.hpp
    title: kyopro/template/chmin_chmax.hpp
  - icon: ':warning:'
    path: kyopro/template/constant.hpp
    title: kyopro/template/constant.hpp
  - icon: ':warning:'
    path: kyopro/template/io_macro.hpp
    title: kyopro/template/io_macro.hpp
  - icon: ':warning:'
    path: kyopro/template/lambda_macro.hpp
    title: kyopro/template/lambda_macro.hpp
  - icon: ':warning:'
    path: kyopro/template/len.hpp
    title: kyopro/template/len.hpp
  - icon: ':warning:'
    path: kyopro/template/macro.hpp
    title: kyopro/template/macro.hpp
  - icon: ':warning:'
    path: kyopro/template/main.hpp
    title: kyopro/template/main.hpp
  - icon: ':warning:'
    path: kyopro/template/make_array.hpp
    title: kyopro/template/make_array.hpp
  - icon: ':warning:'
    path: kyopro/template/make_vec.hpp
    title: kyopro/template/make_vec.hpp
  - icon: ':warning:'
    path: kyopro/template/match_macro.hpp
    title: kyopro/template/match_macro.hpp
  - icon: ':warning:'
    path: kyopro/template/named_tuple_macro.hpp
    title: kyopro/template/named_tuple_macro.hpp
  - icon: ':warning:'
    path: kyopro/template/push_pop_macro.hpp
    title: kyopro/template/push_pop_macro.hpp
  - icon: ':warning:'
    path: kyopro/template/range_cast.hpp
    title: kyopro/template/range_cast.hpp
  - icon: ':warning:'
    path: kyopro/template/rep_macro.hpp
    title: kyopro/template/rep_macro.hpp
  - icon: ':warning:'
    path: kyopro/template/stl.hpp
    title: kyopro/template/stl.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"kyopro/template/stl.hpp\"\n#include <cassert>\r\n#include\
    \ <cctype>\r\n#include <cerrno>\r\n#include <cfloat>\r\n#include <ciso646>\r\n\
    #include <climits>\r\n#include <clocale>\r\n#include <cmath>\r\n#include <csetjmp>\r\
    \n#include <csignal>\r\n#include <cstdarg>\r\n#include <cstddef>\r\n#include <cstdio>\r\
    \n#include <cstdlib>\r\n#include <cstring>\r\n#include <ctime>\r\n\r\n#include\
    \ <ccomplex>\r\n#include <cfenv>\r\n#include <cinttypes>\r\n#include <cstdbool>\r\
    \n#include <cstdint>\r\n#include <ctgmath>\r\n#include <cwchar>\r\n#include <cwctype>\r\
    \n\r\n#include <algorithm>\r\n#include <bitset>\r\n#include <complex>\r\n#include\
    \ <deque>\r\n#include <exception>\r\n#include <fstream>\r\n#include <functional>\r\
    \n#include <iomanip>\r\n#include <ios>\r\n#include <iosfwd>\r\n#include <iostream>\r\
    \n#include <istream>\r\n#include <iterator>\r\n#include <limits>\r\n#include <list>\r\
    \n#include <locale>\r\n#include <map>\r\n#include <memory>\r\n#include <new>\r\
    \n#include <numeric>\r\n#include <ostream>\r\n#include <queue>\r\n#include <set>\r\
    \n#include <sstream>\r\n#include <stack>\r\n#include <stdexcept>\r\n#include <streambuf>\r\
    \n#include <string>\r\n#include <typeinfo>\r\n#include <utility>\r\n#include <valarray>\r\
    \n#include <vector>\r\n\r\n#include <array>\r\n#include <atomic>\r\n#include <chrono>\r\
    \n#include <condition_variable>\r\n#include <forward_list>\r\n#include <future>\r\
    \n#include <initializer_list>\r\n#include <mutex>\r\n#include <random>\r\n#include\
    \ <ratio>\r\n#include <regex>\r\n#include <scoped_allocator>\r\n#include <system_error>\r\
    \n#include <thread>\r\n#include <tuple>\r\n#include <typeindex>\r\n#include <type_traits>\r\
    \n#include <unordered_map>\r\n#include <unordered_set>\r\n#line 6 \"kyopro/meta/tuple_like.hpp\"\
    \n\r\nnamespace kpr {\r\n    namespace helper {\r\n        struct CastableToAny\
    \ {\r\n            template<class T>\r\n            operator T() const noexcept;\r\
    \n        };\r\n\r\n        template<class T, std::size_t... idx, std::void_t<decltype(T{((void)idx,\
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
    \ bool is_tuple_like_v = is_tuple_like<T>::value;\r\n} // namespace kpr\r\n#line\
    \ 7 \"kyopro/meta/trait.hpp\"\n\r\nnamespace kpr {\r\n    namespace helper {\r\
    \n        template<class T>\r\n        struct is_integer_helper {\r\n        \
    \    static constexpr bool value = std::is_integral_v<T>;\r\n        };\r\n\r\n\
    \        #ifdef __SIZEOF_INT128__\r\n        template<>\r\n        struct is_integer_helper<__int128_t>\
    \ {\r\n            static constexpr bool value = true;\r\n        };\r\n     \
    \   template<>\r\n        struct is_integer_helper<__uint128_t> {\r\n        \
    \    static constexpr bool value = true;\r\n        };\r\n        #endif\r\n \
    \   } // namespace helper\r\n\r\n    // \u578BT\u304C\u6574\u6570\u304B\u8ABF\u3079\
    \u308B\r\n    template<class T>\r\n    struct is_integer {\r\n        static constexpr\
    \ bool value = helper::is_integer_helper<std::remove_cv_t<T>>::value;\r\n    };\r\
    \n    // \u578BT\u304C\u6574\u6570\u304B\u8ABF\u3079\u308B\r\n    template<class\
    \ T>\r\n    inline constexpr bool is_integer_v = is_integer<T>::value;\r\n\r\n\
    \    // \u578BT\u304C\u7B26\u53F7\u4ED8\u304D\u6574\u6570\u304B\u8ABF\u3079\u308B\
    \r\n    template<class T>\r\n    struct is_signed_integer {\r\n        static\
    \ constexpr bool value = is_integer_v<T> && std::is_signed_v<T>;\r\n    };\r\n\
    \    // \u578BT\u304C\u7B26\u53F7\u4ED8\u304D\u6574\u6570\u304B\u8ABF\u3079\u308B\
    \r\n    template<class T>\r\n    inline constexpr bool is_signed_integer_v = is_signed_integer<T>::value;\r\
    \n\r\n    // \u578BT\u304C\u7B26\u53F7\u7121\u3057\u6574\u6570\u304B\u8ABF\u3079\
    \u308B\r\n    template<class T>\r\n    struct is_unsigned_integer {\r\n      \
    \  static constexpr bool value = is_integer_v<T> && !std::is_signed_v<T>;\r\n\
    \    };\r\n    // \u578BT\u304C\u7B26\u53F7\u7121\u3057\u6574\u6570\u304B\u8ABF\
    \u3079\u308B\r\n    template<class T>\r\n    inline constexpr bool is_unsigned_integer_v\
    \ = is_unsigned_integer<T>::value;\r\n\r\n    namespace helper {\r\n        template<class\
    \ T>\r\n        struct is_floating_point_helper {\r\n            static constexpr\
    \ bool value = std::is_floating_point_v<T>;\r\n        };\r\n\r\n        #ifdef\
    \ __SIZEOF_FLOAT128__\r\n        template<>\r\n        struct is_floating_point_helper<__float128>\
    \ {\r\n            static constexpr bool value = true;\r\n        };\r\n     \
    \   #endif\r\n    } // namespace helper\r\n\r\n    // \u578BT\u304C\u6D6E\u52D5\
    \u5C0F\u6570\u70B9\u6570\u304B\u8ABF\u3079\u308B\r\n    template<class T>\r\n\
    \    struct is_floating_point {\r\n        static constexpr bool value = helper::is_floating_point_helper<std::remove_cv_t<T>>::value;\r\
    \n    };\r\n    // \u578BT\u304C\u6D6E\u52D5\u5C0F\u6570\u70B9\u6570\u304B\u8ABF\
    \u3079\u308B\r\n    template<class T>\r\n    inline constexpr bool is_floating_point_v\
    \ = is_floating_point<T>::value;\r\n\r\n    // \u578BT\u304C\u7B97\u8853\u578B\
    \u304B\u8ABF\u3079\u308B\r\n    template<class T>\r\n    struct is_arithmetic\
    \ {\r\n        static constexpr bool value = is_integer_v<T> || is_floating_point_v<T>;\r\
    \n    };\r\n    // \u578BT\u304C\u7B97\u8853\u578B\u304B\u8ABF\u3079\u308B\r\n\
    \    template<class T>\r\n    inline constexpr bool is_arithmetic_v = is_arithmetic<T>::value;\r\
    \n\r\n    // \u578BT\u304C\u30B9\u30AB\u30E9\u30FC\u304B\u8ABF\u3079\u308B\r\n\
    \    template<class T>\r\n    struct is_scalar {\r\n        static constexpr bool\
    \ value = is_arithmetic_v<T> || std::is_enum_v<T> || std::is_pointer_v<T> || std::is_member_pointer_v<T>\
    \ || std::is_null_pointer_v<T>;\r\n    };\r\n    // \u578BT\u304C\u30B9\u30AB\u30E9\
    \u30FC\u304B\u8ABF\u3079\u308B\r\n    template<class T>\r\n    inline constexpr\
    \ bool is_scalar_v = is_scalar<T>::value;\r\n\r\n    // size\u4EE5\u4E0A\u306E\
    \u5927\u304D\u3055\u3092\u6301\u3064\u6700\u5C0F\u306E\u7B26\u53F7\u4ED8\u304D\
    \u6574\u6570\u3092\u8ABF\u3079\u308B\r\n    template<std::size_t size>\r\n   \
    \ struct int_least {\r\n    private:\r\n        static constexpr auto get_type()\
    \ noexcept {\r\n            static_assert(size <= 128, \"The given integer type\
    \ is too large\");\r\n            if constexpr (size <= 8) return std::int_least8_t{};\r\
    \n            else if constexpr (size <= 16) return std::int_least16_t{};\r\n\
    \            else if constexpr (size <= 32) return std::int_least32_t{};\r\n \
    \           else if constexpr (size <= 64) return std::int_least64_t{};\r\n  \
    \          else return __int128_t{};\r\n        }\r\n\r\n    public:\r\n     \
    \   using type = decltype(get_type());\r\n    };\r\n    // size\u4EE5\u4E0A\u306E\
    \u5927\u304D\u3055\u3092\u6301\u3064\u6700\u5C0F\u306E\u7B26\u53F7\u4ED8\u304D\
    \u6574\u6570\u3092\u8ABF\u3079\u308B\r\n    template<std::size_t size>\r\n   \
    \ using int_least_t = typename int_least<size>::type;\r\n\r\n    // size\u4EE5\
    \u4E0A\u306E\u5927\u304D\u3055\u3092\u6301\u3064\u6700\u5C0F\u306E\u7B26\u53F7\
    \u7121\u3057\u6574\u6570\u3092\u8ABF\u3079\u308B\r\n    template<std::size_t size>\r\
    \n    struct uint_least {\r\n    private:\r\n        static constexpr auto get_type()\
    \ noexcept {\r\n            static_assert(size <= 128, \"The give integer type\
    \ is too large\");\r\n            if constexpr (size <= 8) return std::uint_least8_t{};\r\
    \n            else if constexpr (size <= 16) return std::uint_least16_t{};\r\n\
    \            else if constexpr (size <= 32) return std::uint_least32_t{};\r\n\
    \            else if constexpr (size <= 64) return std::uint_least64_t{};\r\n\
    \            else return __uint128_t{};\r\n        }\r\n\r\n    public:\r\n  \
    \      using type = decltype(get_type());\r\n    };\r\n    // size\u4EE5\u4E0A\
    \u306E\u5927\u304D\u3055\u3092\u6301\u3064\u6700\u5C0F\u306E\u7B26\u53F7\u7121\
    \u3057\u6574\u6570\u3092\u8ABF\u3079\u308B\r\n    template<std::size_t size>\r\
    \n    using uint_least_t = typename uint_least<size>::type;\r\n\r\n    // T\u306E\
    \u6B21\u306B\u5927\u304D\u3044\u6574\u6570\u578B\u3092\u8ABF\u3079\u308B\r\n \
    \   template<class T>\r\n    struct next_integer {\r\n        static_assert(is_integer_v<T>,\
    \ \"The given type must be an integer type\");\r\n        static_assert(sizeof(T)\
    \ <= 8, \"The given integer type is too large\");\r\n        using type = std::conditional_t<std::is_signed_v<T>,\
    \ int_least_t<sizeof(T) * 16>, uint_least_t<sizeof(T) * 16>>;\r\n    };\r\n  \
    \  // T\u306E\u6B21\u306B\u5927\u304D\u3044\u6574\u6570\u578B\u3092\u8ABF\u3079\
    \u308B\r\n    template<class T>\r\n    using next_integer_t = typename next_integer<T>::type;\r\
    \n\r\n    // T\u306E\u6B21\u306B\u5C0F\u3055\u3044\u6574\u6570\u578B\u3092\u8ABF\
    \u3079\u308B\r\n    template<class T>\r\n    struct prev_integer {\r\n       \
    \ static_assert(is_integer_v<T>, \"The given type must be an integer type\");\r\
    \n        static_assert(sizeof(T) >= 2, \"The given integer type is too large\"\
    );\r\n        using type = std::conditional_t<std::is_signed_v<T>, int_least_t<sizeof(T)\
    \ * 4>, uint_least_t<sizeof(T) * 4>>;\r\n    };\r\n    // T\u306E\u6B21\u306B\u5C0F\
    \u3055\u3044\u6574\u6570\u578B\u3092\u8ABF\u3079\u308B\r\n    template<class T>\r\
    \n    using prev_integer_t = typename prev_integer<T>::type;\r\n\r\n    // \u578B\
    T\u304C\u30A4\u30C6\u30EC\u30FC\u30BF\u304B\u8ABF\u3079\u308B\r\n    template<class\
    \ T, class = void>\r\n    struct is_iterator {\r\n        static constexpr bool\
    \ value = false;\r\n    };\r\n    template<class T>\r\n    struct is_iterator<T,\
    \ std::void_t<typename std::iterator_traits<T>::iterator_category>> {\r\n    \
    \    static constexpr bool value = true;\r\n    };\r\n    // \u578BT\u304C\u30A4\
    \u30C6\u30EC\u30FC\u30BF\u304B\u8ABF\u3079\u308B\r\n    template<class T>\r\n\
    \    inline constexpr bool is_iterator_v = is_iterator<T>::value;\r\n\r\n    //\
    \ \u578BT\u304CRange\u304B\u8ABF\u3079\u308B\r\n    template<class T, class =\
    \ void>\r\n    struct is_range {\r\n        static constexpr bool value = false;\r\
    \n    };\r\n    template<class T>\r\n    struct is_range<T, std::void_t<decltype(std::begin(std::declval<std::add_lvalue_reference_t<T>>()),\
    \ std::end(std::declval<std::add_lvalue_reference_t<T>>()))>> {\r\n        static\
    \ constexpr bool value = true;\r\n    };\r\n     // \u578BT\u304CRange\u304B\u8ABF\
    \u3079\u308B\r\n    template<class T>\r\n    inline constexpr bool is_range_v\
    \ = is_range<T>::value;\r\n\r\n    // Range\u578BT\u304B\u3089\u30A4\u30C6\u30EC\
    \u30FC\u30BF\u306E\u578B\u3092\u8ABF\u3079\u308B\r\n    template<class T>\r\n\
    \    struct range_iterator {\r\n        using type = std::decay_t<decltype(std::begin(std::declval<T>()))>;\r\
    \n    };\r\n    // Range\u578BT\u304B\u3089\u30A4\u30C6\u30EC\u30FC\u30BF\u306E\
    \u578B\u3092\u8ABF\u3079\u308B\r\n    template<class T>\r\n    using range_iterator_t\
    \ = typename range_iterator<T>::type;\r\n\r\n    // Range\u578BT\u304B\u3089\u8AAD\
    \u307F\u53D6\u308A\u5C02\u7528\u30A4\u30C6\u30EC\u30FC\u30BF\u306E\u578B\u3092\
    \u8ABF\u3079\u308B\r\n    template<class T>\r\n    struct range_const_iterator\
    \ {\r\n        using type = std::decay_t<decltype(std::cbegin(std::declval<T>()))>;\r\
    \n    };\r\n    // Range\u578BT\u304B\u3089\u8AAD\u307F\u53D6\u308A\u5C02\u7528\
    \u30A4\u30C6\u30EC\u30FC\u30BF\u306E\u578B\u3092\u8ABF\u3079\u308B\r\n    template<class\
    \ T>\r\n    using range_const_iterator_t = typename range_iterator<T>::type;\r\
    \n\r\n    // Range\u578BT\u304B\u3089\u8981\u7D20\u306E\u578B\u3092\u8ABF\u3079\
    \u308B\r\n    template<class T>\r\n    struct range_value {\r\n        using type\
    \ = std::decay_t<decltype(*std::begin(std::declval<T>()))>;\r\n    };\r\n    //\
    \ Range\u578BT\u304B\u3089\u8981\u7D20\u306E\u578B\u3092\u8ABF\u3079\u308B\r\n\
    \    template<class T>\r\n    using range_value_t = typename range_value<T>::type;\r\
    \n} // namespace kpr\r\n#line 9 \"kyopro/algorithm/Hash.hpp\"\n\r\nnamespace kpr\
    \ {\r\n    // \u30CF\u30C3\u30B7\u30E5(tuple_like, range\u5BFE\u5FDC)\r\n    template<class,\
    \ class = void>\r\n    struct Hash;\r\n\r\n    template<class T>\r\n    struct\
    \ Hash<T, std::enable_if_t<std::is_scalar_v<T>>> {\r\n        using value_type\
    \ = T;\r\n\r\n        constexpr std::size_t operator ()(T a) const noexcept {\r\
    \n            return std::hash<T>{}(a);\r\n        }\r\n    };\r\n\r\n    template<class\
    \ T>\r\n    struct Hash<T, std::enable_if_t<is_tuple_like_v<T> && !is_range_v<T>>>\
    \ {\r\n        using value_type = T;\r\n\r\n        template<std::size_t i = 0>\r\
    \n        constexpr std::size_t operator ()(const T& a) const noexcept {\r\n \
    \           if constexpr (i == tuple_like_size_v<T>) return tuple_like_size_v<T>;\r\
    \n            else {\r\n                std::size_t seed = operator()<i + 1>(a);\r\
    \n                return seed ^ (Hash<tuple_like_element_t<i, T>>{}(get<i>(a))\
    \ + 0x9e3779b97f4a7c15LU + (seed << 12) + (seed >> 4));\r\n            }\r\n \
    \       }\r\n    };\r\n\r\n    template<class T>\r\n    struct Hash<T, std::enable_if_t<is_range_v<T>>>:\
    \ Hash<range_value_t<T>> {\r\n        using value_type = T;\r\n\r\n        constexpr\
    \ std::size_t operator ()(const T& a) const {\r\n            std::size_t seed\
    \ = std::size(a);\r\n            for (auto&& i: a) seed ^= Hash<range_value_t<T>>{}(i)\
    \ + 0x9e3779b97f4a7c15LU + (seed << 12) + (seed >> 4);\r\n            return seed;\r\
    \n        }\r\n    };\r\n} // namespace kpr\r\n#line 2 \"kyopro/function/compare.hpp\"\
    \n\r\nnamespace kpr {\r\n    // operator =\u3067\u6BD4\u8F03\r\n    struct Equal\
    \ {\r\n        template<class T>\r\n        constexpr bool operator()(const T&\
    \ x, const T& y) const noexcept(noexcept(x == y)) {\r\n            return x ==\
    \ y;\r\n        }\r\n    };\r\n\r\n    // operator !=\u3067\u6BD4\u8F03\r\n  \
    \  struct NotEqual {\r\n        template<class T>\r\n        constexpr bool operator()(const\
    \ T& x, const T& y) const noexcept(noexcept(x != y)) {\r\n            return x\
    \ != y;\r\n        }\r\n    };\r\n\r\n    // operator <\u306E\u95A2\u6570\u30AF\
    \u30E9\u30B9\r\n    struct Less {\r\n        template<class T>\r\n        constexpr\
    \ bool operator()(const T& x, const T& y) const noexcept(noexcept(x < y)) {\r\n\
    \            return x < y;\r\n        }\r\n    };\r\n\r\n    // operator <=\u306E\
    \u95A2\u6570\u30AF\u30E9\u30B9\r\n    struct LessEqual {\r\n        template<class\
    \ T>\r\n        constexpr bool operator()(const T& x, const T& y) const noexcept(noexcept(x\
    \ <= y)) {\r\n            return x <= y;\r\n        }\r\n    };\r\n\r\n    //\
    \ operator >\u306E\u95A2\u6570\u30AF\u30E9\u30B9\r\n    struct Greater {\r\n \
    \       template<class T>\r\n        constexpr bool operator()(const T& x, const\
    \ T& y) const noexcept(noexcept(x > y)) {\r\n            return x > y;\r\n   \
    \     }\r\n    };\r\n\r\n    // operator >=\u306E\u95A2\u6570\u30AF\u30E9\u30B9\
    \r\n    struct GreaterEqual {\r\n        template<class T>\r\n        constexpr\
    \ bool operator()(const T& x, const T& y) const noexcept(noexcept(x >= y)) {\r\
    \n            return x >= y;\r\n        }\r\n    };\r\n} // namespace kpr\r\n\
    #line 3 \"kyopro/meta/setting.hpp\"\n\r\n#ifndef KYOPRO_BASE_INT\r\n// \u57FA\u672C\
    \u7B26\u53F7\u4ED8\u304D\u6574\u6570\u578B\r\n#define KYOPRO_BASE_INT std::int64_t\r\
    \n#endif\r\n\r\n#ifndef KYOPRO_BASE_UINT\r\n// \u57FA\u672C\u7B26\u53F7\u306A\u3057\
    \u6574\u6570\u578B\r\n#define KYOPRO_BASE_UINT std::uint64_t\r\n#endif\r\n\r\n\
    #ifndef KYOPRO_BASE_FLOAT\r\n// \u57FA\u672C\u6D6E\u52D5\u5C0F\u6570\u70B9\u6570\
    \u578B\r\n#define KYOPRO_BASE_FLOAT double\r\n#endif\r\n\r\n#ifndef KYOPRO_DEFAULT_MOD\r\
    \n// \u554F\u984C\u3067\u8A2D\u5B9A\u3055\u308C\u305Fmod\r\n#define KYOPRO_DEFAULT_MOD\
    \ (static_cast<KYOPRO_BASE_UINT>(998244353))\r\n#endif\r\n\r\n#ifndef KYOPRO_DECIMAL_PRECISION\r\
    \n// \u5C0F\u6570\u7CBE\u5EA6(\u6841)\r\n#define KYOPRO_DECIMAL_PRECISION (static_cast<KYOPRO_BASE_UINT>(12))\r\
    \n#endif\r\n\r\n#ifndef KYOPRO_INF_DIV\r\n// \u7121\u9650\u5927\u3092\u8868\u3059\
    \u6574\u6570\u304C\u6700\u5927\u5024\u306E\u4F55\u5206\u306E\u4E00\u304B\u3092\
    \u8868\u3059\r\n#define KYOPRO_INF_DIV (static_cast<KYOPRO_BASE_UINT>(3))\r\n\
    #endif\r\n\r\n#ifndef KYOPRO_BUFFER_SIZE\r\n// \u30C7\u30D5\u30A9\u30EB\u30C8\u306E\
    \u30D0\u30C3\u30D5\u30A1\u30B5\u30A4\u30BA\r\n#define KYOPRO_BUFFER_SIZE (static_cast<KYOPRO_BASE_UINT>(2048))\r\
    \n#endif\r\n#line 6 \"kyopro/function/monoid.hpp\"\n\r\nnamespace kpr {\r\n  \
    \  // \u8DB3\u3057\u7B97\u306Emonoid\r\n    template<class T>\r\n    struct Add\
    \ {\r\n        static_assert(is_arithmetic_v<T>, \"T must be an arithmetic type\"\
    );\r\n\r\n        using value_type = T;\r\n\r\n        static constexpr T id()\
    \ noexcept {\r\n            return T{};\r\n        }\r\n\r\n        constexpr\
    \ T operator ()(const T& a, const T& b) const noexcept {\r\n            return\
    \ a + b;\r\n        }\r\n\r\n        static constexpr T inv(const T& a) noexcept\
    \ {\r\n            static_assert(std::is_signed_v<T>, \"T must be a signed type\"\
    );\r\n            return -a;\r\n        }\r\n    };\r\n\r\n    // \u639B\u3051\
    \u7B97\u306Emonoid\r\n    template<class T>\r\n    struct Mul {\r\n        static_assert(is_arithmetic_v<T>,\
    \ \"T must be an arithmetic type\");\r\n\r\n        using value_type = T;\r\n\r\
    \n        static constexpr T id() noexcept {\r\n            return 1;\r\n    \
    \    }\r\n\r\n        constexpr T operator ()(const T& a, const T& b) const noexcept\
    \ {\r\n            return a * b;\r\n        }\r\n\r\n        static constexpr\
    \ T inv(const T& a) noexcept {\r\n            return 1 / a;\r\n        }\r\n \
    \   };\r\n\r\n    // min\u306Emonoid\r\n    template<class T>\r\n    struct Min\
    \ {\r\n        static_assert(is_arithmetic_v<T>, \"T must be an arithmetic type\"\
    );\r\n\r\n        using value_type = T;\r\n\r\n        static constexpr T id()\
    \ noexcept {\r\n            if constexpr (std::numeric_limits<T>::has_infinity)\
    \ return std::numeric_limits<T>::infinity();\r\n            return std::numeric_limits<T>::max()\
    \ / KYOPRO_INF_DIV;\r\n        }\r\n\r\n        constexpr T operator ()(const\
    \ T& a, const T& b) const noexcept {\r\n            return a < b ? a : b;\r\n\
    \        }\r\n    };\r\n\r\n    // max\u306Emonoid\r\n    template<class T>\r\n\
    \    struct Max {\r\n        static_assert(is_arithmetic_v<T>, \"T must be an\
    \ arithmetic type\");\r\n\r\n        using value_type = T;\r\n\r\n        static\
    \ constexpr T id() noexcept {\r\n            if constexpr (std::numeric_limits<T>::has_infinity)\
    \ return -std::numeric_limits<T>::infinity();\r\n            if constexpr (std::is_signed_v<T>)\
    \ return -(std::numeric_limits<T>::max() / KYOPRO_INF_DIV);\r\n            return\
    \ 0;\r\n        }\r\n\r\n        constexpr  T operator ()(const T& a, const T&\
    \ b) const noexcept {\r\n            return a > b ? a : b;\r\n        }\r\n  \
    \  };\r\n\r\n\r\n    // inv\u3092\u6301\u3064\u304B\u8ABF\u3079\u308B\r\n    template<class,\
    \ class = void>\r\n    struct has_inv {\r\n        static constexpr bool value\
    \ = false;\r\n    };\r\n\r\n    template<class T>\r\n    struct has_inv<T, std::void_t<decltype(&T::inv)>>\
    \ {\r\n        static constexpr bool value = true;\r\n    };\r\n\r\n    // inv\u3092\
    \u6301\u3064\u304B\u8ABF\u3079\u308B\r\n    template<class T>\r\n    inline constexpr\
    \ bool has_inv_v = has_inv<T>::value;\r\n} // namespace kpr\r\n#line 5 \"kyopro/math/power.hpp\"\
    \n\r\nnamespace kpr {\r\n    [[maybe_unused]] inline constexpr struct {\r\n  \
    \      template<class T>\r\n        constexpr T operator ()(T a, KYOPRO_BASE_UINT\
    \ n, T init = Mul<T>::id()) const noexcept {\r\n            while (n > 0) {\r\n\
    \                if (n & 1) init *= a;\r\n                a *= a;\r\n        \
    \        n >>= 1;\r\n            }\r\n            return init;\r\n        }\r\n\
    \    } power;\r\n} // namespace kpr\r\n#line 5 \"kyopro/meta/constant.hpp\"\n\r\
    \nnamespace kpr {\r\n    // \u554F\u984C\u3067\u8A2D\u5B9A\u3055\u308C\u305Fmod\r\
    \n    template<class T>\r\n    inline constexpr T MOD = KYOPRO_DEFAULT_MOD;\r\n\
    \    // \u554F\u984C\u3067\u8A2D\u5B9A\u3055\u308C\u305Fmod\r\n    inline constexpr\
    \ KYOPRO_BASE_INT mod = MOD<KYOPRO_BASE_INT>;\r\n\r\n    // \u7121\u9650\u5927\
    \u3092\u8868\u3059\u6574\u6570\r\n    template<class T>\r\n    inline constexpr\
    \ T INF = std::numeric_limits<T>::max() / KYOPRO_INF_DIV;\r\n    // \u7121\u9650\
    \u5927\u3092\u8868\u3059\u6574\u6570\r\n    inline constexpr KYOPRO_BASE_INT inf\
    \ = INF<KYOPRO_BASE_INT>;\r\n\r\n    // \u8A31\u5BB9\u3055\u308C\u308B\u5C0F\u6570\
    \u8AA4\u5DEE\r\n    template<class T, KYOPRO_BASE_UINT decimal_precision = KYOPRO_DECIMAL_PRECISION>\r\
    \n    inline constexpr KYOPRO_BASE_FLOAT EPS = static_cast<T>(1) / power(10ULL,\
    \ decimal_precision);\r\n    // \u8A31\u5BB9\u3055\u308C\u308B\u5C0F\u6570\u8AA4\
    \u5DEE\r\n    inline constexpr KYOPRO_BASE_FLOAT eps = EPS<KYOPRO_BASE_FLOAT>;\r\
    \n\r\n    // \u5186\u5468\u7387\r\n    template<class T>\r\n    inline constexpr\
    \ T PI = 3.14159265358979323846;\r\n    // \u5186\u5468\u7387\r\n    inline constexpr\
    \ KYOPRO_BASE_FLOAT pi = PI<KYOPRO_BASE_FLOAT>;\r\n} // namespace kpr\r\n#line\
    \ 2 \"kyopro/io/in.hpp\"\n#include <unistd.h>\r\n#line 5 \"kyopro/io/io_option.hpp\"\
    \n\r\nnamespace kpr {\r\n    template<class Tuple, std::size_t idx>\r\n    struct\
    \ Indexed {\r\n        Tuple args_tuple;\r\n        template<class... Args>\r\n\
    \        constexpr Indexed(Args&&... args) noexcept: args_tuple{std::forward<Args>(args)...}\
    \ {}\r\n    };\r\n\r\n    template<std::size_t i, class... Args>\r\n    constexpr\
    \ auto indexed(Args&&... args) noexcept {\r\n        return Indexed<std::tuple<Args...>,\
    \ i>{std::forward<Args>(args)...};\r\n    }\r\n\r\n    template<class Tuple, bool...\
    \ seps>\r\n    struct SepWith {\r\n        Tuple args_tuple;\r\n        template<class...\
    \ Args>\r\n        constexpr SepWith(Args&&... args) noexcept: args_tuple{std::forward<Args>(args)...}\
    \ {}\r\n    };\r\n\r\n    template<bool... seps, class... Args>\r\n    constexpr\
    \ auto sep_with(Args&&... args) noexcept {\r\n        return SepWith<std::tuple<Args...>,\
    \ seps...>{std::forward<Args>(args)...};\r\n    }\r\n} // namespace kpr\r\n#line\
    \ 16 \"kyopro/io/in.hpp\"\n\r\nnamespace kpr {\r\n    // \u30D0\u30C3\u30D5\u30A1\
    \u3092\u7528\u3044\u3066\u30D5\u30A1\u30A4\u30EB\u3092\u8AAD\u307F\u8FBC\u3080\
    \u30AF\u30E9\u30B9\r\n    template<std::size_t buf_size = KYOPRO_BUFFER_SIZE>\r\
    \n    struct Reader {\r\n    private:\r\n        int fd, idx;\r\n        std::array<char,\
    \ buf_size> buffer;\r\n\r\n    public:\r\n        // \u30D0\u30C3\u30D5\u30A1\u30B5\
    \u30A4\u30BA\u3092\u53D6\u5F97\r\n        static constexpr KYOPRO_BASE_INT get_buf_size()\
    \ noexcept {\r\n            return buf_size;\r\n        }\r\n\r\n        Reader()\
    \ {\r\n            [[maybe_unused]] ssize_t res = read(fd, buffer.begin(), buf_size);\r\
    \n        }\r\n        Reader(int fd): fd(fd), idx(0), buffer() {\r\n        \
    \    [[maybe_unused]] ssize_t res = read(fd, buffer.begin(), buf_size);\r\n  \
    \      }\r\n        Reader(FILE* fp): fd(fileno(fp)), idx(0), buffer() {\r\n \
    \           [[maybe_unused]] ssize_t res = read(fd, buffer.begin(), buf_size);\r\
    \n        }\r\n\r\n        // \u5165\u529B\u30A4\u30C6\u30EC\u30FC\u30BF\r\n \
    \       struct iterator {\r\n        private:\r\n            Reader& reader;\r\
    \n\r\n        public:\r\n            using difference_type = void;\r\n       \
    \     using value_type = void;\r\n            using pointer = void;\r\n      \
    \      using reference = void;\r\n            using iterator_category = std::input_iterator_tag;\r\
    \n\r\n            iterator() noexcept = default;\r\n            iterator(Reader&\
    \ reader) noexcept: reader(reader) {}\r\n\r\n            iterator& operator ++()\
    \ {\r\n                ++reader.idx;\r\n                if (reader.idx == buf_size)\
    \ {\r\n                    [[maybe_unused]] ssize_t res = read(reader.fd, reader.buffer.begin(),\
    \ buf_size);\r\n                    reader.idx = 0;\r\n                }\r\n \
    \               return *this;\r\n            }\r\n\r\n            iterator operator\
    \ ++(int) {\r\n                iterator before = *this;\r\n                operator\
    \ ++();\r\n                return before;\r\n            }\r\n\r\n           \
    \ char& operator *() const {\r\n                return reader.buffer[reader.idx];\r\
    \n            }\r\n        };\r\n\r\n        // \u30D5\u30A1\u30A4\u30EB\u306E\
    \u6700\u521D\u3092\u793A\u3059\u30A4\u30C6\u30EC\u30FC\u30BF\u3092\u53D6\u5F97\
    \r\n        iterator begin() noexcept {\r\n            return iterator(*this);\r\
    \n        }\r\n    };\r\n\r\n    // \u6A19\u6E96\u5165\u529B\r\n    Reader input{0};\r\
    \n\r\n\r\n    // \u5024\u306E\u5165\u529B\u306E\u95A2\u6570\u30AF\u30E9\u30B9\r\
    \n    template<class, class = void>\r\n    struct ScanFunction;\r\n\r\n    //\
    \ \u5165\u529B\u30A4\u30C6\u30EC\u30FC\u30BF\u3092\u7528\u3044\u3066\u5024\u3092\
    \u5165\u529B\u3059\u308B\u30AF\u30E9\u30B9\r\n    template<class Iterator, std::size_t\
    \ decimal_precision = KYOPRO_DECIMAL_PRECISION>\r\n    struct Scanner {\r\n  \
    \      using iterator_type = Iterator;\r\n\r\n        // \u5165\u529B\u30A4\u30C6\
    \u30EC\u30FC\u30BF\r\n        Iterator itr;\r\n\r\n        // \u6307\u5B9A\u3055\
    \u308C\u305F\u5C0F\u6570\u8AA4\u5DEE\u3092\u53D6\u5F97\r\n        static constexpr\
    \ KYOPRO_BASE_INT get_decimal_precision() noexcept {\r\n            return decimal_precision;\r\
    \n        }\r\n\r\n        Scanner() noexcept = default;\r\n        Scanner(Iterator\
    \ itr) noexcept: itr(itr) {}\r\n\r\n        // \u6B21\u306E\u6587\u5B57\u307E\u3067\
    \u306E\u7A7A\u767D\u3092\u7121\u8996\u3059\u308B\r\n        void discard_space()\
    \ {\r\n            while (('\\t' <= *itr && *itr <= '\\r') || *itr == ' ') ++itr;\r\
    \n        }\r\n\r\n        // \u6574\u6570\u3001\u5C0F\u6570\u3092\u5165\u529B\
    \r\n        template<class T>\r\n        void scan_arithmetic(T& a) {\r\n    \
    \        discard_space();\r\n            bool sgn = false;\r\n            if constexpr\
    \ (!std::is_unsigned_v<T>) if (*itr == '-') {\r\n                sgn = true;\r\
    \n                ++itr;\r\n            }\r\n            a = 0;\r\n          \
    \  for (; '0' <= *itr && *itr <= '9'; ++itr) a = a * 10 + *itr - '0';\r\n    \
    \        if (*itr == '.') {\r\n                ++itr;\r\n                if constexpr\
    \ (is_floating_point_v<T>) {\r\n                    constexpr std::uint_fast64_t\
    \ power_decimal_precision = power(10ULL, decimal_precision);\r\n             \
    \       T d = 0;\r\n                    std::uint_fast64_t i = 1;\r\n        \
    \            for (; '0' <= *itr && *itr <= '9' && i < power_decimal_precision;\
    \ i *= 10) {\r\n                        d = d * 10 + *itr - '0';\r\n         \
    \               ++itr;\r\n                    }\r\n                    a += d\
    \ / i;\r\n                }\r\n                while ('0' <= *itr && *itr <= '9')\
    \ ++itr;\r\n            }\r\n            if constexpr (!std::is_unsigned_v<T>)\
    \ if (sgn) a = -a;\r\n        }\r\n\r\n        // \u8907\u6570\u306E\u5024\u3092\
    \u5165\u529B\r\n        void operator ()() {}\r\n        template<class Head,\
    \ class... Args>\r\n        void operator ()(Head&& head, Args&&... args) {\r\n\
    \            ScanFunction<std::decay_t<Head>>::scan(*this, std::forward<Head>(head));\r\
    \n            operator ()(std::forward<Args>(args)...);\r\n        }\r\n    };\r\
    \n\r\n    template<>\r\n    struct ScanFunction<char> {\r\n        template<class\
    \ Scanner>\r\n        static void scan(Scanner& scanner, char& a) {\r\n      \
    \      scanner.discard_space();\r\n            a = *scanner.itr;\r\n         \
    \   ++scanner.itr;\r\n        }\r\n    };\r\n\r\n    template<>\r\n    struct\
    \ ScanFunction<bool> {\r\n        template<class Scanner>\r\n        static void\
    \ scan(Scanner& scanner, bool& a) {\r\n            scanner.discard_space();\r\n\
    \            a = *scanner.itr != '0';\r\n        }\r\n    };\r\n\r\n    template<>\r\
    \n    struct ScanFunction<std::string> {\r\n        template<class Scanner>\r\n\
    \        static void scan(Scanner& scanner, std::string& a) {\r\n            scanner.discard_space();\r\
    \n            a.clear();\r\n            while ((*scanner.itr < '\\t' || '\\r'\
    \ < *scanner.itr) && *scanner.itr != ' ') {\r\n                a += *scanner.itr;\r\
    \n                ++scanner.itr;\r\n            }\r\n        }\r\n    };\r\n\r\
    \n    template<std::size_t len>\r\n    struct ScanFunction<std::bitset<len>> {\r\
    \n        template<class Scanner>\r\n        static void scan(Scanner& scanner,\
    \ std::bitset<len>& a) {\r\n            scanner.discard_space();\r\n         \
    \   for (int i = len - 1; i >= 0; ++i) {\r\n                a[i] = *scanner.itr\
    \ != '0';\r\n                ++scanner.itr;\r\n            }\r\n        }\r\n\
    \    };\r\n\r\n    template<class T>\r\n    struct ScanFunction<T, std::enable_if_t<is_arithmetic_v<T>>>\
    \ {\r\n        template<class Scanner>\r\n        static void scan(Scanner& scanner,\
    \ T& a) {\r\n            scanner.scan_arithmetic(a);\r\n        }\r\n    };\r\n\
    \r\n    template<class T>\r\n    struct ScanFunction<T, std::enable_if_t<is_tuple_like_v<T>\
    \ && !is_range_v<T>>> {\r\n        template<std::size_t i = 0, class Scanner>\r\
    \n        static void scan(Scanner& scanner, T& a) {\r\n            if constexpr\
    \ (i < tuple_like_size_v<T>) {\r\n                ScanFunction<std::decay_t<tuple_like_element_t<i,\
    \ T>>>::scan(scanner, get<i>(a));\r\n                scan<i + 1>(scanner, a);\r\
    \n            }\r\n        }\r\n    };\r\n\r\n    template<class T>\r\n    struct\
    \ ScanFunction<T, std::enable_if_t<is_range_v<T>>> {\r\n        template<class\
    \ Scanner>\r\n        static void scan(Scanner& scanner, T& a) {\r\n         \
    \   for (auto&& i: a) ScanFunction<range_value_t<T>>::scan(scanner, i);\r\n  \
    \      }\r\n    };\r\n\r\n    template<class Tuple, std::size_t idx>\r\n    struct\
    \ ScanFunction<Indexed<Tuple, idx>> {\r\n        template<class Scanner>\r\n \
    \       struct ScannerWrapper: Scanner {\r\n            template<class T>\r\n\
    \            void scan_arithmetic(T& a) {\r\n                Scanner::scan_arithmetic(a);\r\
    \n                --a;\r\n            }\r\n        };\r\n        template<std::size_t\
    \ i = 0, class Scanner>\r\n        static void scan_impl(ScannerWrapper<Scanner>&\
    \ scanner_wrapper, const Tuple& args_tuple) {\r\n            if constexpr (i <\
    \ tuple_like_size_v<Tuple>) {\r\n                ScanFunction<std::decay_t<tuple_like_element_t<i,\
    \ Tuple>>>::scan(scanner_wrapper, get<i>(args_tuple));\r\n                scan_impl<i\
    \ + 1>(scanner_wrapper, args_tuple);\r\n            }\r\n        }\r\n       \
    \ template<class Scanner>\r\n        static void scan(Scanner& scanner, const\
    \ Indexed<Tuple, idx>& a) {\r\n            ScannerWrapper<Scanner>& scanner_wrapper\
    \ = static_cast<ScannerWrapper<Scanner>&>(scanner);\r\n            scan_impl(scanner_wrapper,\
    \ a.args_tuple);\r\n        }\r\n    };\r\n\r\n    // \u6A19\u6E96\u5165\u529B\
    \u304B\u3089\u5024\u3092\u5165\u529B\u3059\u308B\u95A2\u6570\r\n    Scanner<Reader<>::iterator>\
    \ scan{input.begin()};\r\n} // namespace kpr\r\n#line 11 \"kyopro/io/out.hpp\"\
    \n#include <string_view>\r\n#line 19 \"kyopro/io/out.hpp\"\n\r\nnamespace kpr\
    \ {\r\n    // \u30D0\u30C3\u30D5\u30A1\u3092\u7528\u3044\u3066\u30D5\u30A1\u30A4\
    \u30EB\u306B\u66F8\u304D\u8FBC\u3080\u30AF\u30E9\u30B9\r\n    template<std::size_t\
    \ buf_size = KYOPRO_BUFFER_SIZE>\r\n    struct Writer {\r\n    private:\r\n  \
    \      int fd, idx;\r\n        std::array<char, buf_size> buffer;\r\n\r\n    public:\r\
    \n        // \u30D0\u30C3\u30D5\u30A1\u30B5\u30A4\u30BA\u3092\u53D6\u5F97\r\n\
    \        static constexpr KYOPRO_BASE_INT get_buf_size() noexcept {\r\n      \
    \      return buf_size;\r\n        }\r\n\r\n        Writer() noexcept = default;\r\
    \n        Writer(int fd) noexcept: fd(fd), idx(0), buffer() {}\r\n        Writer(FILE*\
    \ fp) noexcept: fd(fileno(fp)), idx(0), buffer() {}\r\n\r\n        ~Writer() {\r\
    \n            [[maybe_unused]]ssize_t res = write(fd, buffer.begin(), idx);\r\n\
    \        }\r\n\r\n        // \u51FA\u529B\u30A4\u30C6\u30EC\u30FC\u30BF\r\n  \
    \      struct iterator {\r\n        private:\r\n            Writer& writer;\r\n\
    \r\n        public:\r\n            using difference_type = void;\r\n         \
    \   using value_type = void;\r\n            using pointer = void;\r\n        \
    \    using reference = void;\r\n            using iterator_category = std::output_iterator_tag;\r\
    \n\r\n            iterator() noexcept = default;\r\n            iterator(Writer&\
    \ writer) noexcept: writer(writer) {}\r\n\r\n            iterator& operator ++()\
    \ {\r\n                ++writer.idx;\r\n                if (writer.idx == buf_size)\
    \ {\r\n                [[maybe_unused]]ssize_t res = write(writer.fd, writer.buffer.begin(),\
    \ buf_size);\r\n                writer.idx = 0;\r\n                }\r\n     \
    \           return *this;\r\n            }\r\n\r\n            iterator operator\
    \ ++(int) {\r\n                iterator before = *this;\r\n                operator\
    \ ++();\r\n                return before;\r\n            }\r\n\r\n           \
    \ char& operator *() const {\r\n                return writer.buffer[writer.idx];\r\
    \n            }\r\n\r\n            // \u30D0\u30C3\u30D5\u30A1\u3092\u5168\u3066\
    \u51FA\u529B\u3059\u308B\r\n            void flush() const {\r\n             \
    \   [[maybe_unused]] ssize_t res = write(writer.fd, writer.buffer.begin(), writer.idx);\r\
    \n            }\r\n        };\r\n\r\n        // \u30D5\u30A1\u30A4\u30EB\u306E\
    \u6700\u521D\u3092\u793A\u3059\u30A4\u30C6\u30EC\u30FC\u30BF\u3092\u53D6\u5F97\
    \r\n        iterator begin() noexcept {\r\n            return iterator(*this);\r\
    \n        }\r\n    };\r\n\r\n    // \u6A19\u6E96\u51FA\u529B\u3001\u6A19\u6E96\
    \u30A8\u30E9\u30FC\u51FA\u529B\r\n    Writer output{1}, error{2};\r\n\r\n    //\
    \ \u5024\u306E\u51FA\u529B\u306E\u95A2\u6570\u30AF\u30E9\u30B9\r\n    template<class,\
    \ class = void>\r\n    struct PrintFunction;\r\n\r\n    // \u51FA\u529B\u30A4\u30C6\
    \u30EC\u30FC\u30BF\u3092\u7528\u3044\u3066\u5024\u3092\u51FA\u529B\u3059\u308B\
    \u30AF\u30E9\u30B9\r\n    template<class Iterator, bool _space = true, bool _line\
    \ = true, bool _debug = false, bool _comment = false, bool _flush = false, std::size_t\
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
    \n} // namespace kpr\r\n#line 6 \"kyopro/math/Montgomery.hpp\"\n\r\nnamespace\
    \ kpr {\r\n    template<class T>\r\n    struct Montgomery {\r\n        static_assert(is_unsigned_integer_v<T>,\
    \ \"The given type must be an unsigned integer type\");\r\n\r\n        using value_type\
    \ = T;\r\n\r\n        T mod;\r\n\r\n    private:\r\n        using larger_type\
    \ = next_integer_t<T>;\r\n\r\n        T r, n2;\r\n\r\n    public:\r\n        constexpr\
    \ void set_mod(T mod) noexcept {\r\n            this->mod = mod;\r\n         \
    \   n2 = -static_cast<larger_type>(mod) % mod;\r\n            T t = 0;\r\n   \
    \         r = 0;\r\n            for (int i = 0; i < std::numeric_limits<T>::digits;\
    \ ++i) {\r\n                if (!(t & 1)) {\r\n                    t += mod;\r\
    \n                    r += static_cast<T>(1) << static_cast<T>(i);\r\n       \
    \         }\r\n                t >>= 1;\r\n            }\r\n        }\r\n\r\n\
    \        constexpr KYOPRO_BASE_INT get_mod() const noexcept {\r\n            return\
    \ mod;\r\n        }\r\n\r\n        Montgomery() noexcept = default;\r\n      \
    \  Montgomery(T mod) noexcept {\r\n            set_mod(mod);\r\n        }\r\n\r\
    \n        constexpr T transform(T x) const noexcept {\r\n            return reduce(static_cast<larger_type>(x)\
    \ * n2);\r\n        }\r\n\r\n        constexpr T inv_transform(T x) const noexcept\
    \ {\r\n            T y = reduce(x);\r\n            return y >= mod ? y - mod :\
    \ y;\r\n        }\r\n\r\n        constexpr T reduce(larger_type x) const noexcept\
    \ {\r\n            return (x + static_cast<larger_type>(static_cast<T>(x) * r)\
    \ * mod) >> std::numeric_limits<T>::digits;\r\n        }\r\n    };\r\n} // namespace\
    \ kpr\r\n#line 13 \"kyopro/math/DynamicModInt.hpp\"\n\r\nnamespace kpr {\r\n \
    \   template<class T, std::size_t kind = 0, bool = false>\r\n    struct DynamicModInt\
    \ {\r\n        static_assert(std::is_unsigned_v<T>, \"The given type must be an\
    \ unsigned integer type\");\r\n\r\n        using value_type = T;\r\n\r\n    private:\r\
    \n        using larger_type = next_integer_t<T>;\r\n\r\n        inline static\
    \ Montgomery<T> montgomery;\r\n\r\n    public:\r\n        T value;\r\n\r\n   \
    \     static constexpr KYOPRO_BASE_INT get_kind() noexcept {\r\n            return\
    \ kind;\r\n        }\r\n\r\n        static void set_mod(T mod) noexcept {\r\n\
    \            montgomery.set_mod(mod);\r\n        }\r\n\r\n        static KYOPRO_BASE_INT\
    \ get_mod() noexcept {\r\n            return montgomery.mod;\r\n        }\r\n\r\
    \n        KYOPRO_BASE_INT get_val() noexcept {\r\n            return montgomery.inv_transform(value);\r\
    \n        }\r\n\r\n        DynamicModInt() noexcept = default;\r\n        DynamicModInt(T\
    \ value) noexcept: value(montgomery.transform(value % montgomery.mod + montgomery.mod))\
    \ {}\r\n\r\n        template<class U>\r\n        explicit operator U() const noexcept\
    \ {\r\n            return montgomery.inv_transform(value);\r\n        }\r\n\r\n\
    \        static DynamicModInt raw(T value) noexcept {\r\n            DynamicModInt\
    \ res;\r\n            res.value = montgomery.transform(value);\r\n           \
    \ return res;\r\n        }\r\n\r\n        DynamicModInt pow(std::uint_fast64_t\
    \ n) const noexcept {\r\n            DynamicModInt res = 1, a = *this;\r\n   \
    \         while (n > 0) {\r\n                if (n & 1) res = res * a;\r\n   \
    \             a = a * a;\r\n                n >>= 1;\r\n            }\r\n    \
    \        return res;\r\n        }\r\n\r\n        DynamicModInt inv() const noexcept\
    \ {\r\n            return pow(montgomery.mod - 2);\r\n        }\r\n\r\n      \
    \  DynamicModInt operator +() const noexcept {\r\n            return *this;\r\n\
    \        }\r\n\r\n        DynamicModInt operator -() const noexcept {\r\n    \
    \        return value == 0 ? 0 : montgomery.mod - value;\r\n        }\r\n\r\n\
    \        DynamicModInt& operator ++() noexcept {\r\n            *this += DynamicModInt::raw(1);\r\
    \n            return *this;\r\n        }\r\n\r\n        DynamicModInt operator\
    \ ++(int) noexcept {\r\n            DynamicModInt before = *this;\r\n        \
    \    ++*this;\r\n            return before;\r\n        }\r\n\r\n        DynamicModInt&\
    \ operator --() noexcept {\r\n            *this -= DynamicModInt::raw(1);\r\n\
    \            return *this;\r\n        }\r\n\r\n        DynamicModInt operator\
    \ --(int) noexcept {\r\n            DynamicModInt before = *this;\r\n        \
    \    --*this;\r\n            return before;\r\n        }\r\n\r\n        DynamicModInt&\
    \ operator +=(DynamicModInt rhs) noexcept {\r\n            if ((value += rhs.value\
    \ - (montgomery.mod << 1)) > std::numeric_limits<std::make_signed_t<T>>::max())\
    \ value += montgomery.mod << 1;\r\n            return *this;\r\n        }\r\n\r\
    \n        DynamicModInt& operator -=(DynamicModInt rhs) noexcept {\r\n       \
    \     if ((value -= rhs.value) > std::numeric_limits<std::make_signed_t<T>>::max())\
    \ value += montgomery.mod << 1;\r\n            return *this;\r\n        }\r\n\r\
    \n        DynamicModInt& operator *=(DynamicModInt rhs) noexcept {\r\n       \
    \     value = montgomery.reduce(static_cast<larger_type>(value) * rhs.value);\r\
    \n            return *this;\r\n        }\r\n\r\n        DynamicModInt& operator\
    \ /=(DynamicModInt rhs) noexcept {\r\n            value = montgomery.reduce(static_cast<larger_type>(value)\
    \ * rhs.inv().value);\r\n            return *this;\r\n        }\r\n\r\n      \
    \  friend DynamicModInt operator +(DynamicModInt lhs, DynamicModInt rhs) noexcept\
    \ {\r\n            return lhs += rhs;\r\n        }\r\n\r\n        friend DynamicModInt\
    \ operator -(DynamicModInt lhs, DynamicModInt rhs) noexcept {\r\n            return\
    \ lhs -= rhs;\r\n        }\r\n\r\n        friend DynamicModInt operator *(DynamicModInt\
    \ lhs, DynamicModInt rhs) noexcept {\r\n            return lhs *= rhs;\r\n   \
    \     }\r\n\r\n        friend DynamicModInt operator /(DynamicModInt lhs, DynamicModInt\
    \ rhs) noexcept {\r\n            return lhs /= rhs;\r\n        }\r\n\r\n     \
    \   friend bool operator ==(DynamicModInt lhs, DynamicModInt rhs) noexcept {\r\
    \n            return lhs.value == rhs.value;\r\n        }\r\n\r\n        friend\
    \ bool operator !=(DynamicModInt lhs, DynamicModInt rhs) noexcept {\r\n      \
    \      return lhs.value != rhs.value;\r\n        }\r\n\r\n        friend struct\
    \ ScanFunction<DynamicModInt>;\r\n\r\n        friend struct PrintFunction<DynamicModInt>;\r\
    \n    };\r\n\r\n    template<class T, std::size_t kind>\r\n    struct ScanFunction<DynamicModInt<T,\
    \ kind>> {\r\n        template<class Scanner>\r\n        static void scan(Scanner&\
    \ scanner, DynamicModInt<T, kind>& a) {\r\n            std::int_fast64_t value;\r\
    \n            ScanFunction<std::int_fast64_t>::scan(scanner, value);\r\n     \
    \       a.value = a.montgomery.transform(value % a.montgomery.mod + a.montgomery.mod);\r\
    \n        }\r\n    };\r\n\r\n    template<class T, std::size_t kind>\r\n    struct\
    \ PrintFunction<DynamicModInt<T, kind>> {\r\n        template<class Printer>\r\
    \n        static void print(Printer& printer, const DynamicModInt<T, kind>& a)\
    \ {\r\n            PrintFunction<T>::print(printer, a.montgomery.inv_transform(a.value));\r\
    \n        }\r\n    };\r\n\r\n    template<class T, std::size_t kind>\r\n    struct\
    \ Hash<DynamicModInt<T, kind>> {\r\n        using value_type = DynamicModInt<T,\
    \ kind>;\r\n\r\n        std::size_t operator ()(DynamicModInt<T, kind> a) const\
    \ noexcept {\r\n            return static_cast<std::size_t>(a);\r\n        }\r\
    \n    };\r\n} // namespace kpr\r\n#line 6 \"kyopro/algorithm/bit.hpp\"\n\r\nnamespace\
    \ kpr {\r\n    // \u7ACB\u3063\u3066\u3044\u308Bbit\u306E\u500B\u6570\u3092\u8FD4\
    \u3059\r\n    [[maybe_unused]] inline constexpr struct {\r\n        template<class\
    \ T>\r\n        constexpr KYOPRO_BASE_INT operator ()(T x) const noexcept {\r\n\
    \            static_assert(is_integer_v<T>, \"The argument must be an integer\"\
    );\r\n            constexpr auto digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;\r\
    \n            static_assert(digits <= std::numeric_limits<unsigned long long>::digits,\
    \ \"The integer type of the argument is too large\");\r\n            if constexpr\
    \ (digits <= std::numeric_limits<unsigned int>::digits) return __builtin_popcount(x);\r\
    \n            else if constexpr (digits <= std::numeric_limits<unsigned long>::digits)\
    \ return __builtin_popcountl(x);\r\n            else return __builtin_popcountll(x);\r\
    \n        }\r\n    } pop_count;\r\n\r\n    [[maybe_unused]] inline constexpr struct\
    \ {\r\n        template<class T>\r\n        constexpr KYOPRO_BASE_INT operator\
    \ ()(T x) const noexcept {\r\n            static_assert(is_integer_v<T>, \"The\
    \ argument must be an integer\");\r\n            constexpr auto digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;\r\
    \n            static_assert(digits <= std::numeric_limits<unsigned long long>::digits,\
    \ \"The integer type of the argument is too large\");\r\n            if (x ==\
    \ 0) return 0;\r\n            if constexpr (digits <= std::numeric_limits<unsigned\
    \ int>::digits) return __builtin_clz(x) + digits - std::numeric_limits<unsigned\
    \ int>::digits;\r\n            else if constexpr (digits <= std::numeric_limits<unsigned\
    \ long>::digits) return __builtin_clzl(x) + digits - std::numeric_limits<unsigned\
    \ long>::digits;\r\n            else return __builtin_clzll(x) + digits - std::numeric_limits<unsigned\
    \ long long>::digits;\r\n        }\r\n    } lzero_count;\r\n\r\n    [[maybe_unused]]\
    \ inline constexpr struct {\r\n        template<class T>\r\n        constexpr\
    \ KYOPRO_BASE_INT operator ()(T x) const noexcept {\r\n            static_assert(is_integer_v<T>,\
    \ \"The argument must be an integer\");\r\n            constexpr auto digits =\
    \ std::numeric_limits<std::make_unsigned_t<T>>::digits;\r\n            static_assert(digits\
    \ <= std::numeric_limits<unsigned long long>::digits, \"The integer type of the\
    \ argument is too large\");\r\n            if constexpr (digits <= std::numeric_limits<unsigned\
    \ int>::digits) return __builtin_ctz(x);\r\n            else if constexpr (digits\
    \ <= std::numeric_limits<unsigned long>::digits) return __builtin_ctzl(x);\r\n\
    \            else return __builtin_ctzll(x);\r\n        }\r\n    } rzero_count;\r\
    \n\r\n    [[maybe_unused]] inline constexpr struct {\r\n        template<class\
    \ T>\r\n        constexpr KYOPRO_BASE_INT operator ()(T x) const noexcept {\r\n\
    \            static_assert(is_integer_v<T>, \"The argument must be an integer\"\
    );\r\n            constexpr auto digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;\r\
    \n            static_assert(digits <= std::numeric_limits<unsigned long long>::digits,\
    \ \"The integer type of the argument is too large\");\r\n            if (x ==\
    \ 0) return 0;\r\n            if constexpr (digits <= std::numeric_limits<unsigned\
    \ int>::digits) return std::numeric_limits<unsigned int>::digits - __builtin_clz(x);\r\
    \n            else if constexpr (digits <= std::numeric_limits<unsigned long>::digits)\
    \ return std::numeric_limits<unsigned long>::digits - __builtin_clzl(x);\r\n \
    \           else return std::numeric_limits<unsigned long long>::digits - __builtin_clzll(x);\r\
    \n        }\r\n    } bit_len;\r\n\r\n    [[maybe_unused]] inline constexpr struct\
    \ {\r\n        template<class T>\r\n        constexpr KYOPRO_BASE_INT operator\
    \ ()(T x) const noexcept {\r\n            return bit_len(x >> static_cast<T>(1));\r\
    \n        }\r\n    } floor_bit;\r\n\r\n    [[maybe_unused]] inline constexpr struct\
    \ {\r\n        template<class T>\r\n        constexpr KYOPRO_BASE_INT operator\
    \ ()(T x) const noexcept {\r\n            if (x == 0) return 0;\r\n          \
    \  return bit_len(x - static_cast<T>(1));\r\n        }\r\n    } ceil_bit;\r\n\
    } // namespace kpr\r\n#line 4 \"kyopro/math/mod.hpp\"\n\r\nnamespace kpr {\r\n\
    \    [[maybe_unused]] inline constexpr struct {\r\n        template<class T, class\
    \ U>\r\n        constexpr std::common_type_t<T, U> operator ()(T x, U m) const\
    \ noexcept {\r\n            static_assert(is_integer_v<T> && is_integer_v<U>,\
    \ \"Both of the arguments must be integers\");\r\n            if constexpr (is_unsigned_integer_v<T>\
    \ || is_unsigned_integer_v<U>) return x % m;\r\n            return (x %= m) <\
    \ 0 ? x + m : x;\r\n        }\r\n    } floor_mod;\r\n\r\n    [[maybe_unused]]\
    \ inline constexpr struct {\r\n        template<class T, class U>\r\n        constexpr\
    \ std::common_type_t<T, U> operator ()(T x, U m) const noexcept {\r\n        \
    \    return m - floor_mod(x - 1, m) - static_cast<T>(1);\r\n        }\r\n    }\
    \ ceil_mod;\r\n} // namespace kpr\r\n#line 16 \"kyopro/math/ModInt.hpp\"\n\r\n\
    namespace kpr {\r\n    template<KYOPRO_BASE_UINT m>\r\n    struct ModInt {\r\n\
    \        using value_type = uint_least_t<bit_len(m * 2 - 2)>;\r\n\r\n        static\
    \ constexpr value_type mod = m;\r\n        value_type value;\r\n\r\n        static\
    \ constexpr KYOPRO_BASE_INT get_mod() noexcept {\r\n            return mod;\r\n\
    \        }\r\n\r\n        constexpr ModInt() noexcept = default;\r\n        template<class\
    \ T>\r\n        constexpr ModInt(T value) noexcept: value(floor_mod(value, mod))\
    \ {}\r\n\r\n        template<class T>\r\n        explicit constexpr operator T()\
    \ const noexcept {\r\n            return value;\r\n        }\r\n\r\n        static\
    \ constexpr ModInt raw(value_type value) noexcept {\r\n            ModInt res;\r\
    \n            res.value = value;\r\n            return res;\r\n        }\r\n\r\
    \n        constexpr ModInt pow(KYOPRO_BASE_UINT n) const noexcept {\r\n      \
    \      std::uint_fast64_t res = 1, a = value;\r\n            while (n > 0) {\r\
    \n                if (n & 1) res = res * a % mod;\r\n                a = a * a\
    \ % mod;\r\n                n >>= 1;\r\n            }\r\n            return res;\r\
    \n        }\r\n\r\n        constexpr ModInt inv() const noexcept {\r\n       \
    \     std::uint_fast64_t a = value, b = mod;\r\n            std::int_fast64_t\
    \ u = 1, v = 0;\r\n            while (b > 0) {\r\n                std::uint_fast64_t\
    \ t = a / b;\r\n                a -= t * b;\r\n                std::swap(a, b);\r\
    \n                u -= t * v;\r\n                std::swap(u, v);\r\n        \
    \    }\r\n            return floor_mod(u, mod);\r\n        }\r\n\r\n        constexpr\
    \ ModInt operator +() const noexcept {\r\n            return *this;\r\n      \
    \  }\r\n\r\n        constexpr ModInt operator -() const noexcept {\r\n       \
    \     return value == 0 ? 0 : mod - value;\r\n        }\r\n\r\n        constexpr\
    \ ModInt& operator ++() noexcept {\r\n            if (++value >= mod) value -=\
    \ mod;\r\n            return *this;\r\n        }\r\n\r\n        constexpr ModInt\
    \ operator ++(int) noexcept {\r\n            ModInt before = *this;\r\n      \
    \      ++*this;\r\n            return before;\r\n        }\r\n\r\n        constexpr\
    \ ModInt& operator --() noexcept {\r\n            if (value == 0) value = mod;\r\
    \n            --value;\r\n            return *this;\r\n        }\r\n\r\n     \
    \   constexpr ModInt operator --(int) noexcept {\r\n            ModInt before\
    \ = *this;\r\n            --*this;\r\n            return before;\r\n        }\r\
    \n\r\n        constexpr ModInt& operator +=(ModInt rhs) noexcept {\r\n       \
    \     if ((value += rhs.value) >= mod) value -= mod;\r\n            return *this;\r\
    \n        }\r\n\r\n        constexpr ModInt& operator -=(ModInt rhs) noexcept\
    \ {\r\n            if (value < rhs.value) value += mod;\r\n            value -=\
    \ rhs.value;\r\n            return *this;\r\n        }\r\n\r\n        constexpr\
    \ ModInt& operator *=(ModInt rhs) noexcept {\r\n            value = static_cast<uint_least_t<bit_len(mod)\
    \ * 2>>(value) * rhs.value % mod;\r\n            return *this;\r\n        }\r\n\
    \r\n        constexpr ModInt& operator /=(ModInt rhs) noexcept {\r\n         \
    \   value = static_cast<uint_least_t<bit_len(mod) * 2>>(value) * rhs.inv().value\
    \ % mod;\r\n            return *this;\r\n        }\r\n\r\n        friend constexpr\
    \ ModInt operator +(ModInt lhs, ModInt rhs) noexcept {\r\n            return lhs\
    \ += rhs;\r\n        }\r\n\r\n        friend constexpr ModInt operator -(ModInt\
    \ lhs, ModInt rhs) noexcept {\r\n            return lhs -= rhs;\r\n        }\r\
    \n\r\n        friend constexpr ModInt operator *(ModInt lhs, ModInt rhs) noexcept\
    \ {\r\n            return lhs *= rhs;\r\n        }\r\n\r\n        friend constexpr\
    \ ModInt operator /(ModInt lhs, ModInt rhs) noexcept {\r\n            return lhs\
    \ /= rhs;\r\n        }\r\n\r\n        friend constexpr bool operator ==(ModInt\
    \ lhs, ModInt rhs) noexcept {\r\n            return lhs.value == rhs.value;\r\n\
    \        }\r\n\r\n        friend constexpr bool operator !=(ModInt lhs, ModInt\
    \ rhs) noexcept {\r\n            return lhs.value != rhs.value;\r\n        }\r\
    \n\r\n        template<class Scanner>\r\n        void scan(Scanner& scanner) {\r\
    \n            std::int_fast64_t value;\r\n            scanner.scan(value);\r\n\
    \            value = floor_mod(value, mod);\r\n        }\r\n\r\n        template<class\
    \ Printer>\r\n        void print(Printer& printer) const {\r\n            printer.print(value);\r\
    \n        }\r\n    };\r\n\r\n    template<KYOPRO_BASE_UINT mod>\r\n    struct\
    \ ScanFunction<ModInt<mod>> {\r\n        template<class Scanner>\r\n        static\
    \ void scan(Scanner& scanner, ModInt<mod>& a) {\r\n            std::int_fast64_t\
    \ value;\r\n            ScanFunction<std::int_fast64_t>::scan(scanner, value);\r\
    \n            a.value = floor_mod(value, a.mod);\r\n        }\r\n    };\r\n\r\n\
    \    template<KYOPRO_BASE_UINT mod>\r\n    struct PrintFunction<ModInt<mod>> {\r\
    \n        template<class Printer>\r\n        static void print(Printer& printer,\
    \ ModInt<mod> a) {\r\n            PrintFunction<typename ModInt<mod>::value_type>::print(printer,\
    \ a.value);\r\n        }\r\n    };\r\n\r\n    template<KYOPRO_BASE_UINT mod>\r\
    \n    struct Hash<ModInt<mod>> {\r\n        using value_type = ModInt<mod>;\r\n\
    \        constexpr std::size_t operator ()(ModInt<mod> a) const noexcept {\r\n\
    \            return static_cast<std::size_t>(a);\r\n        }\r\n    };\r\n} //\
    \ namespace kpr\r\n#line 22 \"kyopro/template/alias.hpp\"\n\nnamespace kpr {\n\
    \    using ushort = unsigned short;\n    using ll = long long;\n    using ull\
    \ = unsigned long long;\n    using lf = double;\n    using llf = long double;\n\
    \n    using i8 = std::int8_t;\n    using u8 = std::uint8_t;\n    using i16 = std::int16_t;\n\
    \    using u16 = std::uint16_t;\n    using i32 = std::int32_t;\n    using u32\
    \ = std::uint32_t;\n    using i64 = std::int64_t;\n    using u64 = std::uint64_t;\n\
    \    #ifdef __SIZEOF_INT128__\n    using i128 = __int128_t;\n    using u128 =\
    \ __uint128_t;\n    #endif\n    #ifdef __SIZEOF_FLOAT128__\n    using f128 = __float128;\n\
    \    #endif\n\n    using mint = ModInt<mod>;\n    using dmint = DynamicModInt<KYOPRO_BASE_UINT>;\n\
    \n    using str = std::string;\n\n    template<class T, std::size_t idx, class...\
    \ Args>\n    struct agg_type {\n        using type = typename agg_type<T, idx\
    \ - 1, T, Args...>::type;\n    };\n    template<class T, class... Args>\n    struct\
    \ agg_type<T, 0, Args...> {\n        using type = std::tuple<Args...>;\n    };\n\
    \    template<class T>\n    struct agg_type<T, 0, T, T> {\n        using type\
    \ = std::pair<T, T>;\n    };\n\n    template<class T, std::size_t idx>\n    using\
    \ agg = typename agg_type<T, idx>::type;\n    using ll1 = agg<ll, 1>;\n    using\
    \ ll2 = agg<ll, 2>;\n    using ll3 = agg<ll, 3>;\n    using ll4 = agg<ll, 4>;\n\
    \    using ll5 = agg<ll, 5>;\n\n\n    #define DEFINE_ALIAS(name, short_name, value_name,\
    \ short_value_name) \\\n        using short_name ## short_value_name = name<value_name>;\
    \ \\\n        using short_name ## short_name ## short_value_name = name<name<value_name>>;\
    \ \\\n        using short_name ## short_name ## short_name ## short_value_name\
    \ = name<name<name<value_name>>>; \\\n        using short_name ## short_name ##\
    \ short_name ## short_name ## short_value_name = name<name<name<name<value_name>>>>;\
    \ \\\n        using short_name ## short_name ## short_name ## short_name ## short_name\
    \ ## short_value_name = name<name<name<name<name<value_name>>>>>;\n\n    #define\
    \ DEFINE_VEC_ALIAS(name, short_name, value_name, short_value_name) \\\n      \
    \  using V ## short_name ## short_value_name = Vec<name<value_name>>; \\\n   \
    \     using VV ## short_name ## short_value_name = VVec<name<value_name>>;\n\n\
    \    #define DEFINE_CONTAINER_ALIAS(define_alias, name, short_name) \\\n     \
    \   define_alias(name, short_name, bool, b); \\\n        define_alias(name, short_name,\
    \ int, i); \\\n        define_alias(name, short_name, ll, l); \\\n        define_alias(name,\
    \ short_name, float, f); \\\n        define_alias(name, short_name, lf, lf); \\\
    \n        define_alias(name, short_name, llf, llf); \\\n        define_alias(name,\
    \ short_name, mint, m); \\\n        define_alias(name, short_name, dmint, dm);\
    \ \\\n        define_alias(name, short_name, char, c); \\\n        define_alias(name,\
    \ short_name, str, s); \\\n        define_alias(name, short_name, ll1, ll1); \\\
    \n        define_alias(name, short_name, ll2, ll2); \\\n        define_alias(name,\
    \ short_name, ll3, ll3); \\\n        define_alias(name, short_name, ll4, ll4);\
    \ \\\n        define_alias(name, short_name, ll5, ll5);\n\n\n    template<class\
    \ T>\n    using Vec = std::vector<T>;\n    template<class T>\n    using VVec =\
    \ Vec<Vec<T>>;\n    template<class T>\n    using VVVec = Vec<VVec<T>>;\n    template<class\
    \ T>\n    using VVVVec = Vec<VVVec<T>>;\n    template<class T>\n    using VVVVVec\
    \ = Vec<VVVVec<T>>;\n\n    DEFINE_CONTAINER_ALIAS(DEFINE_ALIAS, Vec, V);\n\n \
    \   template<class T>\n    using Deque = std::deque<T>;\n\n    DEFINE_CONTAINER_ALIAS(DEFINE_ALIAS,\
    \ Deque, D);\n    DEFINE_CONTAINER_ALIAS(DEFINE_VEC_ALIAS, Deque, D);\n\n    template<class\
    \ T>\n    using List = std::list<T>;\n\n    DEFINE_CONTAINER_ALIAS(DEFINE_ALIAS,\
    \ List, L);\n    DEFINE_CONTAINER_ALIAS(DEFINE_VEC_ALIAS, List, L);\n\n    template<class\
    \ T>\n    using ForwardList = std::forward_list<T>;\n\n    DEFINE_CONTAINER_ALIAS(DEFINE_ALIAS,\
    \ ForwardList, FL);\n    DEFINE_CONTAINER_ALIAS(DEFINE_VEC_ALIAS, ForwardList,\
    \ FL);\n\n    template<class Key, class Compare = Less>\n    using Set = std::set<Key,\
    \ Compare>;\n    template<class Key, class Compare = Less>\n    using Map = std::map<Key,\
    \ Compare>;\n\n    DEFINE_CONTAINER_ALIAS(DEFINE_ALIAS, Set, S);\n    DEFINE_CONTAINER_ALIAS(DEFINE_VEC_ALIAS,\
    \ Set, S);\n    using Mll = Map<ll, ll>;\n    using VMll = Vec<Mll>;\n\n    template<class\
    \ Key, class H = Hash<Key>>\n    using HashSet = std::unordered_set<Key, H>;\n\
    \    template<class Key, class T, class H = Hash<Key>>\n    using HashMap = std::unordered_map<Key,\
    \ T, H>;\n\n    DEFINE_CONTAINER_ALIAS(DEFINE_ALIAS, HashSet, HS);\n    DEFINE_CONTAINER_ALIAS(DEFINE_VEC_ALIAS,\
    \ HashSet, HS);\n    using HMll = HashMap<ll, ll>;\n    using VHMll = Vec<HMll>;\n\
    \n    template<class Key, class Compare = Less>\n    using MultiSet = std::multiset<Key,\
    \ Compare>;\n    template<class Key, class T, class Compare = Less>\n    using\
    \ MultiMap = std::multimap<Key, T, Compare>;\n\n    DEFINE_CONTAINER_ALIAS(DEFINE_ALIAS,\
    \ MultiSet, MS);\n    DEFINE_CONTAINER_ALIAS(DEFINE_VEC_ALIAS, MultiSet, MS);\n\
    \    using MMll = MultiMap<ll, ll>;\n    using VMMll = Vec<MMll>;\n\n    template<class\
    \ Key, class H = Hash<Key>>\n    using HashMultiSet = std::unordered_multiset<Key,\
    \ H>;\n    template<class Key, class T, class H = Hash<Key>>\n    using HashMultiMap\
    \ = std::unordered_multimap<Key, T, H>;\n\n    DEFINE_CONTAINER_ALIAS(DEFINE_ALIAS,\
    \ HashMultiSet, HMS);\n    DEFINE_CONTAINER_ALIAS(DEFINE_VEC_ALIAS, HashMultiSet,\
    \ HMS);\n    using HMMli = HashMultiMap<ll, ll>;\n    using VHMMli = Vec<HMMli>;\n\
    \n    template<class T, class Container = std::deque<T>>\n    using Queue = std::queue<T,\
    \ Container>;\n\n    DEFINE_CONTAINER_ALIAS(DEFINE_ALIAS, Queue, Que);\n    DEFINE_CONTAINER_ALIAS(DEFINE_VEC_ALIAS,\
    \ Queue, Que);\n\n    template<class T, class Container = std::deque<T>>\n   \
    \ using Stack = std::stack<T, Container>;\n\n    DEFINE_CONTAINER_ALIAS(DEFINE_ALIAS,\
    \ Stack, Stk);\n    DEFINE_CONTAINER_ALIAS(DEFINE_VEC_ALIAS, Stack, Stk);\n\n\
    \    template<class T, class Compare = Less, class Container = Vec<T>>\n    using\
    \ PriQ = std::priority_queue<T, Container, Compare>;\n    template<class T, class\
    \ Compare = Greater, class Container = Vec<T>>\n    using HeapQ = PriQ<T, Compare,\
    \ Container>;\n\n    DEFINE_CONTAINER_ALIAS(DEFINE_ALIAS, PriQ, PQ);\n    DEFINE_CONTAINER_ALIAS(DEFINE_VEC_ALIAS,\
    \ PriQ, PQ);\n    DEFINE_CONTAINER_ALIAS(DEFINE_ALIAS, HeapQ, HQ);\n    DEFINE_CONTAINER_ALIAS(DEFINE_VEC_ALIAS,\
    \ HeapQ, HQ);\n\n    template<std::size_t size>\n    using BitSet = std::bitset<size>;\n\
    } // namespace kpr\n\nusing namespace std;\nusing namespace kpr;\n#line 2 \"kyopro/template/chmin_chmax.hpp\"\
    \n\r\nnamespace kpr {\r\n    // assign min\r\n    [[maybe_unused]] inline constexpr\
    \ struct {\r\n        template<class T, class U = T>\r\n        constexpr bool\
    \ operator ()(T& a, const U& b) noexcept {\r\n            if (a > b) {\r\n   \
    \             a = b;\r\n                return true;\r\n            }\r\n    \
    \        return false;\r\n        }\r\n    } chmin;\r\n\r\n    // assign max\r\
    \n    [[maybe_unused]] inline constexpr struct {\r\n        template<class T,\
    \ class U = T>\r\n        constexpr bool operator ()(T& a, const U& b) noexcept\
    \ {\r\n            if (a < b) {\r\n                a = b;\r\n                return\
    \ true;\r\n            }\r\n            return false;\r\n        }\r\n    } chmax;\r\
    \n} // namespace kpr\r\n#line 4 \"kyopro/template/constant.hpp\"\n\r\nnamespace\
    \ kpr {\r\n    inline constexpr std::array<std::pair<KYOPRO_BASE_INT, KYOPRO_BASE_INT>,\
    \ 4> beside{{{-1, 0}, {0, -1}, {1, 0}, {0, 1}}};\r\n    inline constexpr std::array<std::pair<KYOPRO_BASE_INT,\
    \ KYOPRO_BASE_INT>, 8> around{{{-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1,\
    \ 1}, {0, 1}, {-1, 1}}};\r\n} // namespace kpr\r\n#line 4 \"kyopro/template/len.hpp\"\
    \n\r\nnamespace kpr {\r\n    [[maybe_unused]] inline constexpr struct {\r\n  \
    \      template<class T>\r\n        constexpr KYOPRO_BASE_INT operator ()(T&&\
    \ a) const noexcept {\r\n            return std::size(a);\r\n        }\r\n   \
    \ } len;\r\n} // namespace kpr\r\n#line 3 \"kyopro/template/all_rall_macro.hpp\"\
    \n\n#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)\n#define rall(...)\
    \ std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)\n#line 10 \"kyopro/template/io_macro.hpp\"\
    \n\nnamespace kpr::helper {\n    template<std::size_t len>\n    constexpr std::size_t\
    \ va_args_size(const char (&s)[len]) noexcept {\n        if constexpr (len ==\
    \ 1) return 0;\n        std::size_t cnt = 1;\n        std::uint_fast64_t bracket\
    \ = 0;\n        for (auto i: s) {\n            if (i == '(') ++bracket;\n    \
    \        else if (i == ')') --bracket;\n            else if (i == ',' && bracket\
    \ == 0) ++cnt;\n        }\n        return cnt;\n    }\n\n    template<class F,\
    \ std::size_t... idx>\n    auto read_impl(F&& f, std::index_sequence<idx...>)\
    \ {\n        return std::tuple{(static_cast<void>(idx), f())...};\n    }\n\n \
    \   Printer<Writer<>::iterator, true, true, true, true> debug_impl(output.begin());\n\
    \n    template<bool flag>\n    void print_if(std::string_view sv) {\n        if\
    \ constexpr (flag) print(' ', sv);\n    }\n} // namespace kpr::helper\n\n/* C++20\u4EE5\
    \u964D\n#define read(type_or_init, ...) \\\n    auto [__VA_ARGS__] = (kpr::helper::read_impl(([]()\
    \ { \\\n        using T = std::decay_t<decltype(*new type_or_init)>; \\\n    \
    \    alignas(T) std::byte storage[sizeof(T)]; \\\n        T* p = new (storage)\
    \ type_or_init; \\\n        kpr::scan(*p); \\\n        T res = std::move(*p);\
    \ \\\n        p->~T(); \\\n        return res; \\\n    }), std::make_index_sequence<kpr::helper::va_args_size(#__VA_ARGS__)>()))\n\
    */\n\n#define BOOL(...) bool __VA_ARGS__; scan(__VA_ARGS__)\n#define INT(...)\
    \ int __VA_ARGS__; scan(__VA_ARGS__)\n#define LL(...) ll __VA_ARGS__; scan(__VA_ARGS__)\n\
    #define FLOAT(...) float __VA_ARGS__; scan(__VA_ARGS__)\n#define LF(...) lf __VA_ARGS__;\
    \ scan(__VA_ARGS__)\n#define LLF(...) llf __VA_ARGS__; scan(__VA_ARGS__)\n#define\
    \ MINT(...) mint __VA_ARGS__; scan(__VA_ARGS__)\n#define DMINT(...) dmint __VA_ARGS__;\
    \ scan(__VA_ARGS__)\n#define CHAR(...) char __VA_ARGS__; scan(__VA_ARGS__)\n#define\
    \ STR(...) str __VA_ARGS__; scan(__VA_ARGS__)\n#define LI1(...) li1 __VA_ARGS__;\
    \ scan(__VA_ARGS__)\n#define LI2(...) li2 __VA_ARGS__; scan(__VA_ARGS__)\n#define\
    \ LI3(...) li3 __VA_ARGS__; scan(__VA_ARGS__)\n#define LI4(...) li4 __VA_ARGS__;\
    \ scan(__VA_ARGS__)\n#define LI5(...) li5 __VA_ARGS__; scan(__VA_ARGS__)\n\n#define\
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
    #endif\n#line 5 \"kyopro/template/lambda_macro.hpp\"\n\r\n#define $(...) \\\r\n\
    ([&](auto&&... _args) { \\\r\n    auto _args_tuple = std::forward_as_tuple(_args...);\
    \ \\\r\n    if constexpr (sizeof...(_args) == 0) { \\\r\n        return ([&]()\
    \ { return (__VA_ARGS__); })(); \\\r\n    } else if constexpr (sizeof...(_args)\
    \ == 1) { \\\r\n        return ([&](auto&& $0) { return (__VA_ARGS__); })(get<0>(_args_tuple));\
    \ \\\r\n    } else if constexpr (sizeof...(_args) == 2) { \\\r\n        return\
    \ ([&](auto&& $0, auto&& $1) { return (__VA_ARGS__); })(get<0>(_args_tuple), get<1>(_args_tuple));\
    \ \\\r\n    } else if constexpr (sizeof...(_args) == 3) { \\\r\n        return\
    \ ([&](auto&& $0, auto&& $1, auto&& $2) { return (__VA_ARGS__); })(get<0>(_args_tuple),\
    \ get<1>(_args_tuple), get<2>(_args_tuple)); \\\r\n    } else if constexpr (sizeof...(_args)\
    \ == 4) { \\\r\n        return ([&](auto&& $0, auto&& $1, auto&& $2, auto&& $3)\
    \ { return (__VA_ARGS__); })(get<0>(_args_tuple), get<1>(_args_tuple), get<2>(_args_tuple),\
    \ get<3>(_args_tuple)); \\\r\n    } \\\r\n})\r\n#line 2 \"kyopro/template/push_pop_macro.hpp\"\
    \n\n#define pushf(...) emplace_front(__VA_ARGS__)\n#define popf(...) pop_front(__VA_ARGS__)\n\
    #define pushb(...) emplace_back(__VA_ARGS__)\n#define popb(...) pop_back(__VA_ARGS__)\n\
    #define push(...) emplace(__VA_ARGS__)\n#line 2 \"kyopro/template/match_macro.hpp\"\
    \n\n#define KYOPRO_MATCH1(_1) break; case _1:\n#define KYOPRO_MATCH2(_1, _2) break;\
    \ case _1: case _2:\n#define KYOPRO_MATCH3(_1, _2, _3) break; case _1: case _2:\
    \ case _3:\n#define KYOPRO_MATCH4(_1, _2, _3, _4) break; case _1: case _2: case\
    \ _3: case _4:\n\n#define KYOPRO_OVERLOAD_MATCH(_1, _2, _3, _4, name, ...) name\n\
    #define match(...) KYOPRO_OVERLOAD_MATCH(__VA_ARGS__, KYOPRO_MATCH4, KYOPRO_MATCH3,\
    \ KYOPRO_MATCH2, KYOPRO_MATCH1)(__VA_ARGS__)\n#define otherwise break; default:\n\
    #line 7 \"kyopro/template/named_tuple_macro.hpp\"\n\nnamespace kpr {\n    template<class\
    \ Derived, std::size_t _size>\n    struct NamedTupleBase {\n        using named_tuple_tag\
    \ = void;\n        static constexpr std::size_t size = _size;\n\n    private:\n\
    \        template<std::size_t i = 0, class T>\n        void assign(T&& named_tuple)\
    \ noexcept {\n            if constexpr (i < tuple_like_size_v<Derived>) {\n  \
    \              get<i>(static_cast<Derived&>(*this)) = get<i>(named_tuple);\n \
    \               assign<i + 1>(std::forward<T>(named_tuple));\n            }\n\
    \        }\n\n    public:\n        template<class T, typename std::decay_t<T>::named_tuple_tag*\
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
    \ nullptr, KYOPRO_NAMED_TUPLE2, nullptr, KYOPRO_NAMED_TUPLE1, nullptr, KYOPRO_NAMED_TUPLE0)(__VA_ARGS__)\n\
    #line 3 \"kyopro/template/rep_macro.hpp\"\n\n#define KYOPRO_OVERLOAD_REP(_1, _2,\
    \ _3, name, ...) name\n\n#define KYOPRO_REP0() for (; ; )\n#define KYOPRO_REP1(last)\
    \ KYOPRO_REP2(KYOPRO_COUNTER, last)\n#define KYOPRO_REP2(i, last) for (auto i\
    \ = std::decay_t<decltype(last)>(), KYOPRO_LAST = (last); (i) != (KYOPRO_LAST);\
    \ ++(i))\n#define KYOPRO_REP3(i, first, last) for (auto i = (first), KYOPRO_LAST\
    \ = last; (i) != (KYOPRO_LAST); ++(i))\n\n#define rep(...) KYOPRO_OVERLOAD_REP(__VA_ARGS__\
    \ __VA_OPT__(,) KYOPRO_REP3, KYOPRO_REP2, KYOPRO_REP1, KYOPRO_REP0)(__VA_ARGS__)\n\
    \nnamespace kpr::helper {\n    template<class T>\n    constexpr auto prev(T x)\
    \ noexcept {\n        return --x;\n    }\n} // namespace kpr::helper\n\n#define\
    \ KYOPRO_RREP0() for (; ; )\n#define KYOPRO_RREP1(last) KYOPRO_RREP2(KYOPRO_COUNTER,\
    \ last)\n#define KYOPRO_RREP2(i, last) for (auto i = kpr::helper::prev(last),\
    \ KYOPRO_FIRST = kpr::helper::prev(std::decay_t<decltype(last)>()); (i) != (KYOPRO_FIRST);\
    \ --(i))\n#define KYOPRO_RREP3(i, first, last) for (auto i = kpr::helper::prev(last),\
    \ KYOPRO_FIRST = kpr::helper::prev(first); (i) != (KYOPRO_FIRST); --(i))\n\n#define\
    \ rrep(...) KYOPRO_OVERLOAD_REP(__VA_ARGS__ __VA_OPT__(,) KYOPRO_RREP3, KYOPRO_RREP2,\
    \ KYOPRO_RREP1, KYOPRO_RREP0)(__VA_ARGS__)\n#line 2 \"kyopro/template/main.hpp\"\
    \n\nnamespace kpr {\n    void main();\n} // namespace kpr\n\nint main() {\n  \
    \  kpr::main();\n}\n#line 4 \"kyopro/template/make_array.hpp\"\n\r\nnamespace\
    \ kpr {\r\n    [[maybe_unused]] inline constexpr struct {\r\n        template<class\
    \ T>\r\n        constexpr auto operator ()(const T& init = {}) noexcept {\r\n\
    \            return init;\r\n        }\r\n\r\n        template<class T, std::size_t\
    \ length, std::size_t... lengths>\r\n        constexpr auto operator ()(const\
    \ T& init = {}) noexcept {\r\n            auto elm = operator ()<T, lengths...>(init);\r\
    \n            std::array<decltype(elm), length> res;\r\n            for (auto&\
    \ i: res) i = elm;\r\n            return res;\r\n        }\r\n    } make_array;\r\
    \n} // namespace kpr\r\n#line 6 \"kyopro/template/make_vec.hpp\"\n\r\nnamespace\
    \ kpr {\r\n    [[maybe_unused]] inline constexpr struct {\r\n        template<class\
    \ T, std::size_t n, std::size_t i = 0>\r\n        auto operator ()(const std::size_t\
    \ (&d)[n], const T& init = {}) noexcept {\r\n            if constexpr (i < n)\
    \ return std::vector(d[i], operator ()<T, n, i + 1>(d, init));\r\n           \
    \ else return init;\r\n        }\r\n\r\n        template<class T, std::size_t\
    \ n>\r\n        auto operator ()(const std::size_t (&d)[n]) noexcept {\r\n   \
    \         return operator ()(d, T{});\r\n        }\r\n    } make_vec;\r\n} //\
    \ namespace kpr\r\n#line 3 \"kyopro/template/range_cast.hpp\"\n\nnamespace kpr\
    \ {\n    // Range\u306E\u578B\u5909\u63DB\n    [[maybe_unused]] inline constexpr\
    \ struct {\n        template<class To, class From>\n        constexpr To operator\
    \ ()(From&& container) const noexcept {\n            return To(std::begin(container),\
    \ std::end(container));\n        }\n    } range_cast;\n} // namespace kpr\n#line\
    \ 12 \"kyopro/template/template.hpp\"\n"
  code: "#pragma once\r\n#include \"stl.hpp\"\r\n#include \"alias.hpp\"\r\n#include\
    \ \"chmin_chmax.hpp\"\r\n#include \"constant.hpp\"\r\n#include \"len.hpp\"\r\n\
    #include \"macro.hpp\"\r\n#include \"main.hpp\"\r\n#include \"make_array.hpp\"\
    \r\n#include \"make_vec.hpp\"\r\n#include \"range_cast.hpp\"\r\n"
  dependsOn:
  - kyopro/template/stl.hpp
  - kyopro/template/alias.hpp
  - kyopro/algorithm/Hash.hpp
  - kyopro/meta/tuple_like.hpp
  - kyopro/meta/trait.hpp
  - kyopro/function/compare.hpp
  - kyopro/math/DynamicModInt.hpp
  - kyopro/meta/constant.hpp
  - kyopro/math/power.hpp
  - kyopro/function/monoid.hpp
  - kyopro/meta/setting.hpp
  - kyopro/io/in.hpp
  - kyopro/io/io_option.hpp
  - kyopro/io/out.hpp
  - kyopro/math/Montgomery.hpp
  - kyopro/math/ModInt.hpp
  - kyopro/algorithm/bit.hpp
  - kyopro/math/mod.hpp
  - kyopro/template/chmin_chmax.hpp
  - kyopro/template/constant.hpp
  - kyopro/template/len.hpp
  - kyopro/template/macro.hpp
  - kyopro/template/all_rall_macro.hpp
  - kyopro/template/io_macro.hpp
  - kyopro/io/io.hpp
  - kyopro/template/lambda_macro.hpp
  - kyopro/template/push_pop_macro.hpp
  - kyopro/template/match_macro.hpp
  - kyopro/template/named_tuple_macro.hpp
  - kyopro/template/rep_macro.hpp
  - kyopro/template/main.hpp
  - kyopro/template/make_array.hpp
  - kyopro/template/make_vec.hpp
  - kyopro/template/range_cast.hpp
  isVerificationFile: false
  path: kyopro/template/template.hpp
  requiredBy: []
  timestamp: '2023-04-02 21:40:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kyopro/template/template.hpp
layout: document
redirect_from:
- /library/kyopro/template/template.hpp
- /library/kyopro/template/template.hpp.html
title: kyopro/template/template.hpp
---