---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: function/monoid.hpp
    title: function/monoid.hpp
  - icon: ':heavy_check_mark:'
    path: io/io_option.hpp
    title: io/io_option.hpp
  - icon: ':heavy_check_mark:'
    path: math/power.hpp
    title: math/power.hpp
  - icon: ':heavy_check_mark:'
    path: meta/setting.hpp
    title: meta/setting.hpp
  - icon: ':heavy_check_mark:'
    path: meta/trait.hpp
    title: meta/trait.hpp
  - icon: ':heavy_check_mark:'
    path: meta/tuple_like.hpp
    title: meta/tuple_like.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  - icon: ':warning:'
    path: all/all.hpp
    title: all/all.hpp
  - icon: ':heavy_check_mark:'
    path: io/io.hpp
    title: io/io.hpp
  - icon: ':warning:'
    path: math/BinomMod.hpp
    title: math/BinomMod.hpp
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
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':warning:'
    path: template/io_macro.hpp
    title: template/io_macro.hpp
  - icon: ':warning:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':warning:'
    path: template/named_tuple_macro.hpp
    title: template/named_tuple_macro.hpp
  - icon: ':warning:'
    path: template/template.hpp
    title: template/template.hpp
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
  bundledCode: "#line 2 \"io/in.hpp\"\n#include <unistd.h>\r\n#include <array>\r\n\
    #include <bitset>\r\n#include <cstddef>\r\n#include <cstdint>\r\n#include <cstdio>\r\
    \n#include <string>\r\n#include <type_traits>\r\n#include <utility>\r\n#line 3\
    \ \"io/io_option.hpp\"\n#include <tuple>\r\n#line 5 \"io/io_option.hpp\"\n\r\n\
    namespace kpr {\r\n    template<class Tuple, std::size_t idx>\r\n    struct Indexed\
    \ {\r\n        Tuple args_tuple;\r\n        template<class... Args>\r\n      \
    \  constexpr Indexed(Args&&... args) noexcept: args_tuple{std::forward<Args>(args)...}\
    \ {}\r\n    };\r\n\r\n    template<std::size_t i, class... Args>\r\n    constexpr\
    \ auto indexed(Args&&... args) noexcept {\r\n        return Indexed<std::tuple<Args...>,\
    \ i>{std::forward<Args>(args)...};\r\n    }\r\n\r\n    template<class Tuple, bool...\
    \ seps>\r\n    struct SepWith {\r\n        Tuple args_tuple;\r\n        template<class...\
    \ Args>\r\n        constexpr SepWith(Args&&... args) noexcept: args_tuple{std::forward<Args>(args)...}\
    \ {}\r\n    };\r\n\r\n    template<bool... seps, class... Args>\r\n    constexpr\
    \ auto sep_with(Args&&... args) noexcept {\r\n        return SepWith<std::tuple<Args...>,\
    \ seps...>{std::forward<Args>(args)...};\r\n    }\r\n} // namespace kpr\r\n#line\
    \ 2 \"function/monoid.hpp\"\n#include <limits>\r\n#line 3 \"meta/setting.hpp\"\
    \n\r\n#ifndef KYOPRO_BASE_INT\r\n// \u57FA\u672C\u7B26\u53F7\u4ED8\u304D\u6574\
    \u6570\u578B\r\n#define KYOPRO_BASE_INT std::int64_t\r\n#endif\r\n\r\n#ifndef\
    \ KYOPRO_BASE_UINT\r\n// \u57FA\u672C\u7B26\u53F7\u306A\u3057\u6574\u6570\u578B\
    \r\n#define KYOPRO_BASE_UINT std::uint64_t\r\n#endif\r\n\r\n#ifndef KYOPRO_BASE_FLOAT\r\
    \n// \u57FA\u672C\u6D6E\u52D5\u5C0F\u6570\u70B9\u6570\u578B\r\n#define KYOPRO_BASE_FLOAT\
    \ double\r\n#endif\r\n\r\n#ifndef KYOPRO_DEFAULT_MOD\r\n// \u554F\u984C\u3067\u8A2D\
    \u5B9A\u3055\u308C\u305Fmod\r\n#define KYOPRO_DEFAULT_MOD (static_cast<KYOPRO_BASE_UINT>(998244353))\r\
    \n#endif\r\n\r\n#ifndef KYOPRO_DECIMAL_PRECISION\r\n// \u5C0F\u6570\u7CBE\u5EA6\
    (\u6841)\r\n#define KYOPRO_DECIMAL_PRECISION (static_cast<KYOPRO_BASE_UINT>(12))\r\
    \n#endif\r\n\r\n#ifndef KYOPRO_INF_DIV\r\n// \u7121\u9650\u5927\u3092\u8868\u3059\
    \u6574\u6570\u304C\u6700\u5927\u5024\u306E\u4F55\u5206\u306E\u4E00\u304B\u3092\
    \u8868\u3059\r\n#define KYOPRO_INF_DIV (static_cast<KYOPRO_BASE_UINT>(3))\r\n\
    #endif\r\n\r\n#ifndef KYOPRO_BUFFER_SIZE\r\n// \u30C7\u30D5\u30A9\u30EB\u30C8\u306E\
    \u30D0\u30C3\u30D5\u30A1\u30B5\u30A4\u30BA\r\n#define KYOPRO_BUFFER_SIZE (static_cast<KYOPRO_BASE_UINT>(2048))\r\
    \n#endif\r\n#line 3 \"meta/trait.hpp\"\n#include <iterator>\r\n#line 7 \"meta/trait.hpp\"\
    \n\r\nnamespace kpr {\r\n    namespace helper {\r\n        template<class T>\r\
    \n        struct is_integer_helper {\r\n            static constexpr bool value\
    \ = std::is_integral_v<T>;\r\n        };\r\n\r\n        #ifdef __SIZEOF_INT128__\r\
    \n        template<>\r\n        struct is_integer_helper<__int128_t> {\r\n   \
    \         static constexpr bool value = true;\r\n        };\r\n        template<>\r\
    \n        struct is_integer_helper<__uint128_t> {\r\n            static constexpr\
    \ bool value = true;\r\n        };\r\n        #endif\r\n    } // namespace helper\r\
    \n\r\n    // \u578BT\u304C\u6574\u6570\u304B\u8ABF\u3079\u308B\r\n    template<class\
    \ T>\r\n    struct is_integer {\r\n        static constexpr bool value = helper::is_integer_helper<std::remove_cv_t<T>>::value;\r\
    \n    };\r\n    // \u578BT\u304C\u6574\u6570\u304B\u8ABF\u3079\u308B\r\n    template<class\
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
    \n} // namespace kpr\r\n#line 6 \"function/monoid.hpp\"\n\r\nnamespace kpr {\r\
    \n    // \u8DB3\u3057\u7B97\u306Emonoid\r\n    template<class T>\r\n    struct\
    \ Add {\r\n        static_assert(is_arithmetic_v<T>, \"T must be an arithmetic\
    \ type\");\r\n\r\n        using value_type = T;\r\n\r\n        static constexpr\
    \ T id() noexcept {\r\n            return T{};\r\n        }\r\n\r\n        constexpr\
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
    \ bool has_inv_v = has_inv<T>::value;\r\n} // namespace kpr\r\n#line 5 \"math/power.hpp\"\
    \n\r\nnamespace kpr {\r\n    [[maybe_unused]] inline constexpr struct {\r\n  \
    \      template<class T>\r\n        constexpr T operator ()(T a, KYOPRO_BASE_UINT\
    \ n, T init = Mul<T>::id()) const noexcept {\r\n            while (n > 0) {\r\n\
    \                if (n & 1) init *= a;\r\n                a *= a;\r\n        \
    \        n >>= 1;\r\n            }\r\n            return init;\r\n        }\r\n\
    \    } power;\r\n} // namespace kpr\r\n#line 6 \"meta/tuple_like.hpp\"\n\r\nnamespace\
    \ kpr {\r\n    namespace helper {\r\n        struct CastableToAny {\r\n      \
    \      template<class T>\r\n            operator T() const noexcept;\r\n     \
    \   };\r\n\r\n        template<class T, std::size_t... idx, std::void_t<decltype(T{((void)idx,\
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
    \ 16 \"io/in.hpp\"\n\r\nnamespace kpr {\r\n    // \u30D0\u30C3\u30D5\u30A1\u3092\
    \u7528\u3044\u3066\u30D5\u30A1\u30A4\u30EB\u3092\u8AAD\u307F\u8FBC\u3080\u30AF\
    \u30E9\u30B9\r\n    template<std::size_t buf_size = KYOPRO_BUFFER_SIZE>\r\n  \
    \  struct Reader {\r\n    private:\r\n        int fd, idx;\r\n        std::array<char,\
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
    \ scan{input.begin()};\r\n} // namespace kpr\r\n"
  code: "#pragma once\r\n#include <unistd.h>\r\n#include <array>\r\n#include <bitset>\r\
    \n#include <cstddef>\r\n#include <cstdint>\r\n#include <cstdio>\r\n#include <string>\r\
    \n#include <type_traits>\r\n#include <utility>\r\n#include \"io_option.hpp\"\r\
    \n#include \"../math/power.hpp\"\r\n#include \"../meta/setting.hpp\"\r\n#include\
    \ \"../meta/trait.hpp\"\r\n#include \"../meta/tuple_like.hpp\"\r\n\r\nnamespace\
    \ kpr {\r\n    // \u30D0\u30C3\u30D5\u30A1\u3092\u7528\u3044\u3066\u30D5\u30A1\
    \u30A4\u30EB\u3092\u8AAD\u307F\u8FBC\u3080\u30AF\u30E9\u30B9\r\n    template<std::size_t\
    \ buf_size = KYOPRO_BUFFER_SIZE>\r\n    struct Reader {\r\n    private:\r\n  \
    \      int fd, idx;\r\n        std::array<char, buf_size> buffer;\r\n\r\n    public:\r\
    \n        // \u30D0\u30C3\u30D5\u30A1\u30B5\u30A4\u30BA\u3092\u53D6\u5F97\r\n\
    \        static constexpr KYOPRO_BASE_INT get_buf_size() noexcept {\r\n      \
    \      return buf_size;\r\n        }\r\n\r\n        Reader() {\r\n           \
    \ [[maybe_unused]] ssize_t res = read(fd, buffer.begin(), buf_size);\r\n     \
    \   }\r\n        Reader(int fd): fd(fd), idx(0), buffer() {\r\n            [[maybe_unused]]\
    \ ssize_t res = read(fd, buffer.begin(), buf_size);\r\n        }\r\n        Reader(FILE*\
    \ fp): fd(fileno(fp)), idx(0), buffer() {\r\n            [[maybe_unused]] ssize_t\
    \ res = read(fd, buffer.begin(), buf_size);\r\n        }\r\n\r\n        // \u5165\
    \u529B\u30A4\u30C6\u30EC\u30FC\u30BF\r\n        struct iterator {\r\n        private:\r\
    \n            Reader& reader;\r\n\r\n        public:\r\n            using difference_type\
    \ = void;\r\n            using value_type = void;\r\n            using pointer\
    \ = void;\r\n            using reference = void;\r\n            using iterator_category\
    \ = std::input_iterator_tag;\r\n\r\n            iterator() noexcept = default;\r\
    \n            iterator(Reader& reader) noexcept: reader(reader) {}\r\n\r\n   \
    \         iterator& operator ++() {\r\n                ++reader.idx;\r\n     \
    \           if (reader.idx == buf_size) {\r\n                    [[maybe_unused]]\
    \ ssize_t res = read(reader.fd, reader.buffer.begin(), buf_size);\r\n        \
    \            reader.idx = 0;\r\n                }\r\n                return *this;\r\
    \n            }\r\n\r\n            iterator operator ++(int) {\r\n           \
    \     iterator before = *this;\r\n                operator ++();\r\n         \
    \       return before;\r\n            }\r\n\r\n            char& operator *()\
    \ const {\r\n                return reader.buffer[reader.idx];\r\n           \
    \ }\r\n        };\r\n\r\n        // \u30D5\u30A1\u30A4\u30EB\u306E\u6700\u521D\
    \u3092\u793A\u3059\u30A4\u30C6\u30EC\u30FC\u30BF\u3092\u53D6\u5F97\r\n       \
    \ iterator begin() noexcept {\r\n            return iterator(*this);\r\n     \
    \   }\r\n    };\r\n\r\n    // \u6A19\u6E96\u5165\u529B\r\n    Reader input{0};\r\
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
    \ scan{input.begin()};\r\n} // namespace kpr\r\n"
  dependsOn:
  - io/io_option.hpp
  - math/power.hpp
  - function/monoid.hpp
  - meta/setting.hpp
  - meta/trait.hpp
  - meta/tuple_like.hpp
  isVerificationFile: false
  path: io/in.hpp
  requiredBy:
  - io/io.hpp
  - all/all.hpp
  - all.hpp
  - math/is_prime.hpp
  - math/factorize.hpp
  - math/ModInt.hpp
  - math/math.hpp
  - math/BinomMod.hpp
  - math/DynamicModInt.hpp
  - template/template.hpp
  - template/macro.hpp
  - template/io_macro.hpp
  - template/named_tuple_macro.hpp
  - template/alias.hpp
  timestamp: '2023-04-02 19:15:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/many_aplusb.test.cpp
  - verify/yosupo/factorize.test.cpp
  - verify/yosupo/point_add_range_sum.test.cpp
  - verify/yosupo/unionfind.test.cpp
  - verify/aoj/PrimeNumber.test.cpp
documentation_of: io/in.hpp
layout: document
redirect_from:
- /library/io/in.hpp
- /library/io/in.hpp.html
title: io/in.hpp
---
