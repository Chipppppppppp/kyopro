---
data:
  _extendedDependsOn:
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
    path: kyopro/math/power.hpp
    title: kyopro/math/power.hpp
  - icon: ':heavy_check_mark:'
    path: kyopro/meta/setting.hpp
    title: kyopro/meta/setting.hpp
  - icon: ':heavy_check_mark:'
    path: kyopro/meta/trait.hpp
    title: kyopro/meta/trait.hpp
  - icon: ':heavy_check_mark:'
    path: kyopro/meta/tuple_like.hpp
    title: kyopro/meta/tuple_like.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: kyopro/all.hpp
    title: kyopro/all.hpp
  - icon: ':warning:'
    path: kyopro/template/macro.hpp
    title: kyopro/template/macro.hpp
  - icon: ':warning:'
    path: kyopro/template/template.hpp
    title: kyopro/template/template.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"kyopro/template/io_macro.hpp\"\n#include <unistd.h>\n#include\
    \ <cstddef>\n#include <istream>\n#include <string_view>\n#include <tuple>\n#include\
    \ <type_traits>\n#include <utility>\n#line 3 \"kyopro/io/in.hpp\"\n#include <array>\r\
    \n#include <bitset>\r\n#line 6 \"kyopro/io/in.hpp\"\n#include <cstdint>\r\n#include\
    \ <cstdio>\r\n#include <string>\r\n#line 5 \"kyopro/io/io_option.hpp\"\n\r\nnamespace\
    \ kpr {\r\n    template<class Tuple, std::size_t idx>\r\n    struct Indexed {\r\
    \n        Tuple args_tuple;\r\n        template<class... Args>\r\n        constexpr\
    \ Indexed(Args&&... args) noexcept: args_tuple{std::forward<Args>(args)...} {}\r\
    \n    };\r\n\r\n    template<std::size_t i, class... Args>\r\n    constexpr auto\
    \ indexed(Args&&... args) noexcept {\r\n        return Indexed<std::tuple<Args...>,\
    \ i>{std::forward<Args>(args)...};\r\n    }\r\n\r\n    template<class Tuple, bool...\
    \ seps>\r\n    struct SepWith {\r\n        Tuple args_tuple;\r\n        template<class...\
    \ Args>\r\n        constexpr SepWith(Args&&... args) noexcept: args_tuple{std::forward<Args>(args)...}\
    \ {}\r\n    };\r\n\r\n    template<bool... seps, class... Args>\r\n    constexpr\
    \ auto sep_with(Args&&... args) noexcept {\r\n        return SepWith<std::tuple<Args...>,\
    \ seps...>{std::forward<Args>(args)...};\r\n    }\r\n} // namespace kpr\r\n#line\
    \ 2 \"kyopro/function/monoid.hpp\"\n#include <limits>\r\n#line 3 \"kyopro/meta/setting.hpp\"\
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
    \n#endif\r\n#line 3 \"kyopro/meta/trait.hpp\"\n#include <iterator>\r\n#line 7\
    \ \"kyopro/meta/trait.hpp\"\n\r\nnamespace kpr {\r\n    namespace helper {\r\n\
    \        template<class T>\r\n        struct is_integer_helper {\r\n         \
    \   static constexpr bool value = std::is_integral_v<T>;\r\n        };\r\n\r\n\
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
    \n} // namespace kpr\r\n#line 6 \"kyopro/function/monoid.hpp\"\n\r\nnamespace\
    \ kpr {\r\n    // \u8DB3\u3057\u7B97\u306Emonoid\r\n    template<class T>\r\n\
    \    struct Add {\r\n        static_assert(is_arithmetic_v<T>, \"T must be an\
    \ arithmetic type\");\r\n\r\n        using value_type = T;\r\n\r\n        static\
    \ constexpr T id() noexcept {\r\n            return T{};\r\n        }\r\n\r\n\
    \        constexpr T operator ()(const T& a, const T& b) const noexcept {\r\n\
    \            return a + b;\r\n        }\r\n\r\n        static constexpr T inv(const\
    \ T& a) noexcept {\r\n            static_assert(std::is_signed_v<T>, \"T must\
    \ be a signed type\");\r\n            return -a;\r\n        }\r\n    };\r\n\r\n\
    \    // \u639B\u3051\u7B97\u306Emonoid\r\n    template<class T>\r\n    struct\
    \ Mul {\r\n        static_assert(is_arithmetic_v<T>, \"T must be an arithmetic\
    \ type\");\r\n\r\n        using value_type = T;\r\n\r\n        static constexpr\
    \ T id() noexcept {\r\n            return 1;\r\n        }\r\n\r\n        constexpr\
    \ T operator ()(const T& a, const T& b) const noexcept {\r\n            return\
    \ a * b;\r\n        }\r\n\r\n        static constexpr T inv(const T& a) noexcept\
    \ {\r\n            return 1 / a;\r\n        }\r\n    };\r\n\r\n    // min\u306E\
    monoid\r\n    template<class T>\r\n    struct Min {\r\n        static_assert(is_arithmetic_v<T>,\
    \ \"T must be an arithmetic type\");\r\n\r\n        using value_type = T;\r\n\r\
    \n        static constexpr T id() noexcept {\r\n            if constexpr (std::numeric_limits<T>::has_infinity)\
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
    \    } power;\r\n} // namespace kpr\r\n#line 6 \"kyopro/meta/tuple_like.hpp\"\n\
    \r\nnamespace kpr {\r\n    namespace helper {\r\n        struct CastableToAny\
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
    \ scan{input.begin()};\r\n} // namespace kpr\r\n#line 3 \"kyopro/io/out.hpp\"\n\
    #include <algorithm>\r\n#line 6 \"kyopro/io/out.hpp\"\n#include <cmath>\r\n#line\
    \ 19 \"kyopro/io/out.hpp\"\n\r\nnamespace kpr {\r\n    // \u30D0\u30C3\u30D5\u30A1\
    \u3092\u7528\u3044\u3066\u30D5\u30A1\u30A4\u30EB\u306B\u66F8\u304D\u8FBC\u3080\
    \u30AF\u30E9\u30B9\r\n    template<std::size_t buf_size = KYOPRO_BUFFER_SIZE>\r\
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
    \n} // namespace kpr\r\n#line 10 \"kyopro/template/io_macro.hpp\"\n\nnamespace\
    \ kpr::helper {\n    template<std::size_t len>\n    constexpr std::size_t va_args_size(const\
    \ char (&s)[len]) noexcept {\n        if constexpr (len == 1) return 0;\n    \
    \    std::size_t cnt = 1;\n        std::uint_fast64_t bracket = 0;\n        for\
    \ (auto i: s) {\n            if (i == '(') ++bracket;\n            else if (i\
    \ == ')') --bracket;\n            else if (i == ',' && bracket == 0) ++cnt;\n\
    \        }\n        return cnt;\n    }\n\n    template<class F, std::size_t...\
    \ idx>\n    auto read_impl(F&& f, std::index_sequence<idx...>) {\n        return\
    \ std::tuple{(static_cast<void>(idx), f())...};\n    }\n\n    Printer<Writer<>::iterator,\
    \ true, true, true, true> debug_impl(output.begin());\n\n    template<bool flag>\n\
    \    void print_if(std::string_view sv) {\n        if constexpr (flag) print('\
    \ ', sv);\n    }\n} // namespace kpr::helper\n\n/* C++20\u4EE5\u964D\n#define\
    \ read(type_or_init, ...) \\\n    auto [__VA_ARGS__] = (kpr::helper::read_impl(([]()\
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
    #endif\n"
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
    #endif\n"
  dependsOn:
  - kyopro/io/io.hpp
  - kyopro/io/in.hpp
  - kyopro/io/io_option.hpp
  - kyopro/math/power.hpp
  - kyopro/function/monoid.hpp
  - kyopro/meta/setting.hpp
  - kyopro/meta/trait.hpp
  - kyopro/meta/tuple_like.hpp
  - kyopro/io/out.hpp
  isVerificationFile: false
  path: kyopro/template/io_macro.hpp
  requiredBy:
  - kyopro/all.hpp
  - kyopro/template/template.hpp
  - kyopro/template/macro.hpp
  timestamp: '2023-04-02 21:40:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kyopro/template/io_macro.hpp
layout: document
redirect_from:
- /library/kyopro/template/io_macro.hpp
- /library/kyopro/template/io_macro.hpp.html
title: kyopro/template/io_macro.hpp
---