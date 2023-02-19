---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/Hash.hpp
    title: algorithm/Hash.hpp
  - icon: ':warning:'
    path: algorithm/algorithm.hpp
    title: algorithm/algorithm.hpp
  - icon: ':heavy_check_mark:'
    path: algorithm/bit.hpp
    title: algorithm/bit.hpp
  - icon: ':warning:'
    path: function/RecursiveLambda.hpp
    title: function/RecursiveLambda.hpp
  - icon: ':warning:'
    path: function/compare.hpp
    title: function/compare.hpp
  - icon: ':warning:'
    path: function/function.hpp
    title: function/function.hpp
  - icon: ':heavy_check_mark:'
    path: function/monoid.hpp
    title: function/monoid.hpp
  - icon: ':heavy_check_mark:'
    path: io/in.hpp
    title: io/in.hpp
  - icon: ':heavy_check_mark:'
    path: io/io.hpp
    title: io/io.hpp
  - icon: ':heavy_check_mark:'
    path: io/io_option.hpp
    title: io/io_option.hpp
  - icon: ':heavy_check_mark:'
    path: io/out.hpp
    title: io/out.hpp
  - icon: ':warning:'
    path: math/Barrett.hpp
    title: math/Barrett.hpp
  - icon: ':heavy_check_mark:'
    path: math/DynamicModInt.hpp
    title: math/DynamicModInt.hpp
  - icon: ':warning:'
    path: math/ModInt.hpp
    title: math/ModInt.hpp
  - icon: ':heavy_check_mark:'
    path: math/Montgomery.hpp
    title: math/Montgomery.hpp
  - icon: ':warning:'
    path: math/div.hpp
    title: math/div.hpp
  - icon: ':warning:'
    path: math/divisors.hpp
    title: math/divisors.hpp
  - icon: ':warning:'
    path: math/euler_phi.hpp
    title: math/euler_phi.hpp
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
    path: math/mod.hpp
    title: math/mod.hpp
  - icon: ':heavy_check_mark:'
    path: math/power.hpp
    title: math/power.hpp
  - icon: ':heavy_check_mark:'
    path: meta/constant.hpp
    title: meta/constant.hpp
  - icon: ':warning:'
    path: meta/meta.hpp
    title: meta/meta.hpp
  - icon: ':heavy_check_mark:'
    path: meta/setting.hpp
    title: meta/setting.hpp
  - icon: ':heavy_check_mark:'
    path: meta/trait.hpp
    title: meta/trait.hpp
  - icon: ':heavy_check_mark:'
    path: meta/tuple_like.hpp
    title: meta/tuple_like.hpp
  - icon: ':warning:'
    path: range/imap.hpp
    title: range/imap.hpp
  - icon: ':warning:'
    path: range/irange.hpp
    title: range/irange.hpp
  - icon: ':warning:'
    path: range/iterator_base.hpp
    title: range/iterator_base.hpp
  - icon: ':warning:'
    path: range/range.hpp
    title: range/range.hpp
  - icon: ':warning:'
    path: range/range_base.hpp
    title: range/range_base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  - icon: ':warning:'
    path: verify/hello_world.cpp
    title: verify/hello_world.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algorithm/bit.hpp\"\n#include <limits>\r\n#include <type_traits>\r\
    \n#line 2 \"meta/setting.hpp\"\n#include <cstdint>\r\n\r\n#ifndef KYOPRO_BASE_INT\r\
    \n// \u57FA\u672C\u7B26\u53F7\u4ED8\u304D\u6574\u6570\u578B\r\n#define KYOPRO_BASE_INT\
    \ std::int64_t\r\n#endif\r\n\r\n#ifndef KYOPRO_BASE_UINT\r\n// \u57FA\u672C\u7B26\
    \u53F7\u306A\u3057\u6574\u6570\u578B\r\n#define KYOPRO_BASE_UINT std::uint64_t\r\
    \n#endif\r\n\r\n#ifndef KYOPRO_BASE_FLOAT\r\n// \u57FA\u672C\u6D6E\u52D5\u5C0F\
    \u6570\u70B9\u6570\u578B\r\n#define KYOPRO_BASE_FLOAT double\r\n#endif\r\n\r\n\
    #ifndef KYOPRO_DEFAULT_MOD\r\n// \u554F\u984C\u3067\u8A2D\u5B9A\u3055\u308C\u305F\
    mod\r\n#define KYOPRO_DEFAULT_MOD (static_cast<KYOPRO_BASE_UINT>(998244353))\r\
    \n#endif\r\n\r\n#ifndef KYOPRO_DECIMAL_PRECISION\r\n// \u5C0F\u6570\u7CBE\u5EA6\
    (\u6841)\r\n#define KYOPRO_DECIMAL_PRECISION (static_cast<KYOPRO_BASE_UINT>(12))\r\
    \n#endif\r\n\r\n#ifndef KYOPRO_INF_DIV\r\n// \u7121\u9650\u5927\u3092\u8868\u3059\
    \u6574\u6570\u304C\u6700\u5927\u5024\u306E\u4F55\u5206\u306E\u4E00\u304B\u3092\
    \u8868\u3059\r\n#define KYOPRO_INF_DIV (static_cast<KYOPRO_BASE_UINT>(3))\r\n\
    #endif\r\n\r\n#ifndef KYOPRO_BUFFER_SIZE\r\n// \u30C7\u30D5\u30A9\u30EB\u30C8\u306E\
    \u30D0\u30C3\u30D5\u30A1\u30B5\u30A4\u30BA\r\n#define KYOPRO_BUFFER_SIZE (static_cast<KYOPRO_BASE_UINT>(2048))\r\
    \n#endif\r\n#line 2 \"meta/trait.hpp\"\n#include <cstddef>\r\n#include <iterator>\r\
    \n#include <tuple>\r\n#line 6 \"meta/trait.hpp\"\n#include <utility>\r\n\r\nnamespace\
    \ kpr {\r\n    namespace helper {\r\n        template<class T>\r\n        struct\
    \ is_integer_helper {\r\n            static constexpr bool value = std::is_integral_v<T>;\r\
    \n        };\r\n\r\n        #ifdef __SIZEOF_INT128__\r\n        template<>\r\n\
    \        struct is_integer_helper<__int128_t> {\r\n            static constexpr\
    \ bool value = true;\r\n        };\r\n        template<>\r\n        struct is_integer_helper<__uint128_t>\
    \ {\r\n            static constexpr bool value = true;\r\n        };\r\n     \
    \   #endif\r\n    } // namespace helper\r\n\r\n    // \u578BT\u304C\u6574\u6570\
    \u304B\u8ABF\u3079\u308B\r\n    template<class T>\r\n    struct is_integer {\r\
    \n        static constexpr bool value = helper::is_integer_helper<std::remove_cv_t<T>>::value;\r\
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
    \n} // namespace kpr\r\n#line 6 \"algorithm/bit.hpp\"\n\r\nnamespace kpr {\r\n\
    \    // \u7ACB\u3063\u3066\u3044\u308Bbit\u306E\u500B\u6570\u3092\u8FD4\u3059\r\
    \n    [[maybe_unused]] inline constexpr struct {\r\n        template<class T>\r\
    \n        constexpr KYOPRO_BASE_INT operator ()(T x) const noexcept {\r\n    \
    \        static_assert(is_integer_v<T>, \"The argument must be an integer\");\r\
    \n            constexpr auto digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;\r\
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
    } // namespace kpr\r\n#line 3 \"algorithm/Hash.hpp\"\n#include <functional>\r\n\
    #line 7 \"meta/tuple_like.hpp\"\n\r\nnamespace kpr {\r\n    namespace helper {\r\
    \n        struct CastableToAny {\r\n            template<class T>\r\n        \
    \    operator T() const noexcept;\r\n        };\r\n\r\n        template<class\
    \ T, std::size_t... idx, std::void_t<decltype(T{((void)idx, CastableToAny{})...})>*\
    \ = nullptr>\r\n        constexpr bool is_aggregate_initializable(std::index_sequence<idx...>,\
    \ bool) noexcept {\r\n            return true;\r\n        }\r\n        template<class\
    \ T, std::size_t... idx>\r\n        constexpr bool is_aggregate_initializable(std::index_sequence<idx...>,\
    \ char) noexcept {\r\n            return false;\r\n        }\r\n\r\n        template<class\
    \ T, std::size_t n = sizeof(T) * 8, std::enable_if_t<is_aggregate_initializable<T>(std::make_index_sequence<n>(),\
    \ false)>* = nullptr>\r\n        constexpr std::size_t aggregate_size() {\r\n\
    \            return n;\r\n        }\r\n        template<class T, std::size_t n\
    \ = sizeof(T) * 8, std::enable_if_t<!is_aggregate_initializable<T>(std::make_index_sequence<n>(),\
    \ false)>* = nullptr>\r\n        constexpr std::size_t aggregate_size() {\r\n\
    \            return aggregate_size<T, n - 1>();\r\n        }\r\n    } // namespace\
    \ helper\r\n\r\n    // tuple_like\u306A\u578BT\u306E\u5927\u304D\u3055\u3092\u8ABF\
    \u3079\u308B\r\n    template<class T, class = void>\r\n    struct tuple_like_size\
    \ {\r\n        static_assert(std::is_aggregate_v<T>, \"T must be tuple_like\"\
    );\r\n        static constexpr std::size_t value = helper::aggregate_size<T>();\r\
    \n    };\r\n\r\n    template<class T>\r\n    struct tuple_like_size<T, std::void_t<decltype(std::tuple_size<T>::value)>>\
    \ {\r\n        static constexpr std::size_t value = std::tuple_size_v<T>;\r\n\
    \    };\r\n\r\n    // tuple_like\u306A\u578BT\u306E\u5927\u304D\u3055\u3092\u8ABF\
    \u3079\u308B\r\n    template<class T>\r\n    inline constexpr std::size_t tuple_like_size_v\
    \ = tuple_like_size<T>::value;\r\n\r\n\r\n    // \u578BT\u304Ctuple_like\u304B\
    \u8ABF\u3079\u308B\r\n    template<class, class = void>\r\n    struct is_tuple_like\
    \ {\r\n        static constexpr bool value = false;\r\n    };\r\n\r\n    template<class\
    \ T>\r\n    struct is_tuple_like<T, std::enable_if_t<std::is_aggregate_v<T>>>\
    \ {\r\n        static constexpr bool value = true;\r\n    };\r\n\r\n    template<class\
    \ T>\r\n    struct is_tuple_like<T, std::void_t<decltype(std::tuple_size<T>::value)>>\
    \ {\r\n        static constexpr bool value = true;\r\n    };\r\n\r\n    // \u578B\
    T\u304Ctuple_like\u304B\u8ABF\u3079\u308B\r\n    template<class T>\r\n    inline\
    \ constexpr bool is_tuple_like_v = is_tuple_like<T>::value;\r\n\r\n\r\n    //\
    \ tuple-like\u306A\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u306Eidx(0 <= idx < 8)\u756A\
    \u76EE\u3092\u6C42\u3081\u308B\u95A2\u6570\u30AF\u30E9\u30B9\r\n    template<class\
    \ T, class = void>\r\n    struct GetFunction {\r\n        static_assert(is_tuple_like_v<T>,\
    \ \"T is not gettable\");\r\n        template<std::size_t idx>\r\n        static\
    \ constexpr decltype(auto) get(T&& tuple_like) {\r\n            return std::get<idx>(std::forward<T>(tuple_like));\r\
    \n        }\r\n    };\r\n\r\n    #define DEFINE_GET(n, ...)                  \
    \                           \\\r\n    template<class T>                      \
    \                                \\\r\n    struct GetFunction<T, std::enable_if_t<tuple_like_size_v<T>\
    \ == n>> {   \\\r\n        template<std::size_t idx, class U>                \
    \                 \\\r\n        static constexpr decltype(auto) get(U&& aggregate)\
    \ noexcept { \\\r\n            auto&& [__VA_ARGS__] = std::forward<U>(aggregate);\
    \             \\\r\n            return std::get<idx>(std::forward_as_tuple(__VA_ARGS__));\
    \      \\\r\n        }                                                       \
    \           \\\r\n    };\r\n\r\n    DEFINE_GET(1, a)\r\n    DEFINE_GET(2, a, b)\r\
    \n    DEFINE_GET(3, a, b, c)\r\n    DEFINE_GET(4, a, b, c, d)\r\n    DEFINE_GET(5,\
    \ a, b, c, d, e)\r\n    DEFINE_GET(6, a, b, c, d, e, f)\r\n    DEFINE_GET(7, a,\
    \ b, c, d, e, f, g)\r\n    DEFINE_GET(8, a, b, c, d, e, f, g, h)\r\n\r\n    #undef\
    \ DEFINE_GET\r\n\r\n    namespace helper {\r\n        template<std::size_t idx>\r\
    \n        struct GetHelper {\r\n            template<class T>\r\n            constexpr\
    \ decltype(auto) operator ()(T&& tuple_like) const noexcept {\r\n            \
    \    return GetFunction<std::decay_t<T>>::template get<idx>(std::forward<T>(tuple_like));\r\
    \n            }\r\n        };\r\n    }\r\n\r\n    // tuple-like\u306A\u30AA\u30D6\
    \u30B8\u30A7\u30AF\u30C8\u306Eidx(0 <= idx < 8)\u756A\u76EE\u3092\u6C42\u3081\u308B\
    \r\n    template<std::size_t idx>\r\n    inline constexpr helper::GetHelper<idx>\
    \ get;\r\n\r\n\r\n    // tuple-like\u306A\u578BT\u306Eidx(0 <= idx < 8)\u756A\u76EE\
    \u306E\u8981\u7D20\u306E\u578B\u3092\u8ABF\u3079\u308B\r\n    template<std::size_t\
    \ idx, class T>\r\n    struct tuple_like_element {\r\n        using type = decltype(get<idx>(std::declval<T>()));\r\
    \n    };\r\n\r\n    // tuple-like\u306A\u578BT\u306Eidx(0 <= idx < 8)\u756A\u76EE\
    \u306E\u8981\u7D20\u306E\u578B\u3092\u8ABF\u3079\u308B\r\n    template<std::size_t\
    \ idx, class T>\r\n    using tuple_like_element_t = typename tuple_like_element<idx,\
    \ T>::type;\r\n} // namespace kpr\r\n#line 9 \"algorithm/Hash.hpp\"\n\r\nnamespace\
    \ kpr {\r\n    // \u30CF\u30C3\u30B7\u30E5(tuple_like, range\u5BFE\u5FDC)\r\n\
    \    template<class, class = void>\r\n    struct Hash;\r\n\r\n    template<class\
    \ T>\r\n    struct Hash<T, std::enable_if_t<std::is_scalar_v<T>>> {\r\n      \
    \  using value_type = T;\r\n\r\n        constexpr std::size_t operator ()(T a)\
    \ const noexcept {\r\n            return std::hash<T>{}(a);\r\n        }\r\n \
    \   };\r\n\r\n    template<class T>\r\n    struct Hash<T, std::enable_if_t<is_tuple_like_v<T>\
    \ && !is_range_v<T>>> {\r\n        using value_type = T;\r\n\r\n        template<std::size_t\
    \ i = 0>\r\n        constexpr std::size_t operator ()(const T& a) const noexcept\
    \ {\r\n            if constexpr (i == tuple_like_size_v<T>) return tuple_like_size_v<T>;\r\
    \n            else {\r\n                std::size_t seed = operator()<i + 1>(a);\r\
    \n                return seed ^ (Hash<tuple_like_element_t<i, T>>{}(get<i>(a))\
    \ + 0x9e3779b97f4a7c15LU + (seed << 12) + (seed >> 4));\r\n            }\r\n \
    \       }\r\n    };\r\n\r\n    template<class T>\r\n    struct Hash<T, std::enable_if_t<is_range_v<T>>>:\
    \ Hash<range_value_t<T>> {\r\n        using value_type = T;\r\n\r\n        constexpr\
    \ std::size_t operator ()(const T& a) const {\r\n            std::size_t seed\
    \ = std::size(a);\r\n            for (auto&& i: a) seed ^= Hash<range_value_t<T>>{}(i)\
    \ + 0x9e3779b97f4a7c15LU + (seed << 12) + (seed >> 4);\r\n            return seed;\r\
    \n        }\r\n    };\r\n} // namespace kpr\r\n#line 2 \"function/compare.hpp\"\
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
    #line 3 \"math/power.hpp\"\n\r\nnamespace kpr {\r\n    [[maybe_unused]] inline\
    \ constexpr struct {\r\n        template<class T>\r\n        constexpr T operator\
    \ ()(T a, std::uint_fast64_t n, T init = 1) const noexcept {\r\n            while\
    \ (n > 0) {\r\n                if (n & 1) init *= a;\r\n                a *= a;\r\
    \n                n >>= 1;\r\n            }\r\n            return init;\r\n  \
    \      }\r\n    } power;\r\n} // namespace kpr\r\n#line 5 \"meta/constant.hpp\"\
    \n\r\nnamespace kpr {\r\n    // \u554F\u984C\u3067\u8A2D\u5B9A\u3055\u308C\u305F\
    mod\r\n    template<class T>\r\n    inline constexpr T MOD = KYOPRO_DEFAULT_MOD;\r\
    \n    // \u554F\u984C\u3067\u8A2D\u5B9A\u3055\u308C\u305Fmod\r\n    inline constexpr\
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
    \ 6 \"function/monoid.hpp\"\n\r\nnamespace kpr {\r\n    // \u8DB3\u3057\u7B97\u306E\
    monoid\r\n    template<class T>\r\n    struct Add {\r\n        static_assert(is_arithmetic_v<T>,\
    \ \"T must be an arithmetic type\");\r\n\r\n        using value_type = T;\r\n\r\
    \n        constexpr T id() const noexcept {\r\n            return T{};\r\n   \
    \     }\r\n\r\n        constexpr T operator ()(const T& a, const T& b) const noexcept\
    \ {\r\n            return a + b;\r\n        }\r\n\r\n        constexpr T inverse(const\
    \ T& a) const noexcept {\r\n            static_assert(std::is_signed_v<T>, \"\
    T must be a signed type\");\r\n            return -a;\r\n        }\r\n    };\r\
    \n\r\n    // \u639B\u3051\u7B97\u306Emonoid\r\n    template<class T>\r\n    struct\
    \ Mul {\r\n        static_assert(is_arithmetic_v<T>, \"T must be an arithmetic\
    \ type\");\r\n\r\n        using value_type = T;\r\n\r\n        constexpr T id()\
    \ const noexcept {\r\n            return 1;\r\n        }\r\n\r\n        constexpr\
    \ T operator ()(const T& a, const T& b) const noexcept {\r\n            return\
    \ a * b;\r\n        }\r\n\r\n        constexpr T inverse(const T& a) const noexcept\
    \ {\r\n            return 1 / a;\r\n        }\r\n    };\r\n\r\n    // min\u306E\
    monoid\r\n    template<class T>\r\n    struct Min {\r\n        static_assert(is_arithmetic_v<T>,\
    \ \"T must be an arithmetic type\");\r\n\r\n        using value_type = T;\r\n\r\
    \n        constexpr T id() const noexcept {\r\n            return std::numeric_limits<T>::has_infinity\
    \ ? -std::numeric_limits<T>::infinity() : INF<T>;\r\n        }\r\n\r\n       \
    \ constexpr T operator ()(const T& a, const T& b) const noexcept {\r\n       \
    \     return a < b ? a : b;\r\n        }\r\n    };\r\n\r\n    // max\u306Emonoid\r\
    \n    template<class T>\r\n    struct Max {\r\n        static_assert(is_arithmetic_v<T>,\
    \ \"T must be an arithmetic type\");\r\n\r\n        using value_type = T;\r\n\r\
    \n        constexpr T id() const noexcept {\r\n            return std::numeric_limits<T>::has_infinity\
    \ ? -std::numeric_limits<T>::infinity() : (std::is_signed_v<T> ? -INF<T> : 0);\r\
    \n        }\r\n\r\n        constexpr T operator ()(const T& a, const T& b) const\
    \ noexcept {\r\n            return a > b ? a : b;\r\n        }\r\n    };\r\n\r\
    \n\r\n    // inverse\u3092\u6301\u3064\u304B\u8ABF\u3079\u308B\r\n    template<class,\
    \ class = void>\r\n    struct has_inverse {\r\n        static constexpr bool value\
    \ = false;\r\n    };\r\n\r\n    template<class T>\r\n    struct has_inverse<T,\
    \ std::void_t<decltype(&T::inverse)>> {\r\n        static constexpr bool value\
    \ = true;\r\n    };\r\n\r\n    // inverse\u3092\u6301\u3064\u304B\u8ABF\u3079\u308B\
    \r\n    template<class T>\r\n    inline constexpr bool has_inverse_v = has_inverse<T>::value;\r\
    \n} // namespace kpr\r\n#line 4 \"function/RecursiveLambda.hpp\"\n\r\nnamespace\
    \ kpr {\r\n    // \u518D\u5E30\u53EF\u80FD\u95A2\u6570\u30AF\u30E9\u30B9\r\n \
    \   template<class F>\r\n    struct RecursiveLambda {\r\n        using value_type\
    \ = F;\r\n\r\n    private:\r\n        F func;\r\n\r\n    public:\r\n        template<class\
    \ G>\r\n        constexpr RecursiveLambda(G&& func) noexcept: func(std::forward<G>(func))\
    \ {}\r\n\r\n        template<class... Args>\r\n        constexpr decltype(auto)\
    \ operator ()(Args&&... args) const noexcept(noexcept(func(*this, std::forward<Args>(args)...)))\
    \ {\r\n            return func(*this, std::forward<Args>(args)...);\r\n      \
    \  }\r\n    };\r\n\r\n    template<class F>\r\n    RecursiveLambda(F&&) -> RecursiveLambda<std::decay_t<F>>;\r\
    \n} // namespace kpr\r\n#line 7 \"math/Barrett.hpp\"\n\r\nnamespace kpr {\r\n\
    \    // Barrett Reduction\r\n    template<class T>\r\n    struct Barrett {\r\n\
    \        static_assert(is_unsigned_integer_v<T>, \"The given type must be an unsigned\
    \ integer type\");\r\n\r\n        using value_type = T;\r\n\r\n        T mod;\r\
    \n\r\n    private:\r\n        using larger_type = next_integer_t<T>;\r\n\r\n \
    \       larger_type m;\r\n\r\n    public:\r\n        constexpr void set_mod(T\
    \ mod) noexcept {\r\n            this->mod = mod;\r\n            m = (static_cast<larger_type>(1)\
    \ << 64) / mod;\r\n        }\r\n\r\n        constexpr KYOPRO_BASE_INT get_mod()\
    \ const noexcept {\r\n            return mod;\r\n        }\r\n\r\n        Barrett()\
    \ noexcept = default;\r\n        Barrett(T mod) noexcept: mod(mod), m((static_cast<larger_type>(1)\
    \ << 64) / mod) {}\r\n\r\n        constexpr T reduce(T x) const noexcept {\r\n\
    \            x -= static_cast<T>((x * m) >> 64) * mod;\r\n            return x\
    \ < mod ? x : x - mod;\r\n        }\r\n    };\r\n} // namespace kpr\r\n#line 3\
    \ \"math/div.hpp\"\n\r\nnamespace kpr {\r\n    // floor(a \xF7 b)\u3092\u8FD4\u3059\
    \r\n    [[maybe_unused]] inline constexpr struct {\r\n        template<class T,\
    \ class U>\r\n        constexpr std::common_type_t<T, U> operator ()(T x, U m)\
    \ const noexcept {\r\n            static_assert(is_integer_v<T> && is_integer_v<U>,\
    \ \"Both of the arguments must be integers\");\r\n            if constexpr (is_unsigned_integer_v<T>\
    \ || is_unsigned_integer_v<U>) return x / m;\r\n            auto d = x / m;\r\n\
    \            return d * m == x ? d : d - ((x < 0) ^ (m < 0));\r\n        }\r\n\
    \    } floor_div;\r\n\r\n    // ceil(a \xF7 b)\u3092\u8FD4\u3059\r\n    [[maybe_unused]]\
    \ inline constexpr struct {\r\n        template<class T, class U>\r\n        constexpr\
    \ std::common_type_t<T, U> operator ()(T x, U m) const noexcept {\r\n        \
    \    return floor_div(x + m - static_cast<T>(1), m);\r\n        }\r\n    } ceil_div;\r\
    \n} // namespace kpr\r\n#line 3 \"math/divisors.hpp\"\n#include <vector>\r\n#line\
    \ 5 \"math/divisors.hpp\"\n\r\nnamespace kpr {\r\n    // \u5168\u3066\u306E\u6B63\
    \u306E\u7D04\u6570\u3092\u8FD4\u3059\r\n    [[maybe_unused]] inline constexpr\
    \ struct {\r\n        std::vector<KYOPRO_BASE_INT> operator ()(std::uint_fast64_t\
    \ n) const {\r\n            std::vector<KYOPRO_BASE_INT> lower, upper;\r\n   \
    \         std::uint_fast64_t i;\r\n            for (i = 1; i * i < n; ++i) if\
    \ (n % i == 0) {\r\n                lower.emplace_back(i);\r\n               \
    \ upper.emplace_back(n / i);\r\n            }\r\n            if (i * i == n) lower.emplace_back(i);\r\
    \n            lower.insert(end(lower), upper.rbegin(), upper.rend());\r\n    \
    \        return lower;\r\n        }\r\n    } divisors;\r\n} // namespace kpr\r\
    \n#line 2 \"io/in.hpp\"\n#include <unistd.h>\r\n#include <array>\r\n#include <bitset>\r\
    \n#line 7 \"io/in.hpp\"\n#include <cstdio>\r\n#include <string>\r\n#line 5 \"\
    io/io_option.hpp\"\n\r\nnamespace kpr {\r\n    template<class Tuple, std::size_t\
    \ idx>\r\n    struct Indexed {\r\n        Tuple args_tuple;\r\n        template<class...\
    \ Args>\r\n        constexpr Indexed(Args&&... args) noexcept: args_tuple{std::forward<Args>(args)...}\
    \ {}\r\n    };\r\n\r\n    template<std::size_t i, class... Args>\r\n    constexpr\
    \ auto indexed(Args&&... args) noexcept {\r\n        return Indexed<std::tuple<Args...>,\
    \ i>{std::forward<Args>(args)...};\r\n    }\r\n\r\n    template<class Tuple, bool...\
    \ seps>\r\n    struct SepWith {\r\n        Tuple args_tuple;\r\n        template<class...\
    \ Args>\r\n        constexpr SepWith(Args&&... args) noexcept: args_tuple{std::forward<Args>(args)...}\
    \ {}\r\n    };\r\n\r\n    template<bool... seps, class... Args>\r\n    constexpr\
    \ auto sep_with(Args&&... args) noexcept {\r\n        return SepWith<std::tuple<Args...>,\
    \ seps...>{std::forward<Args>(args)...};\r\n    }\r\n} // namespace kpr\r\n#line\
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
    \ scan{input.begin()};\r\n} // namespace kpr\r\n#line 3 \"io/out.hpp\"\n#include\
    \ <algorithm>\r\n#line 6 \"io/out.hpp\"\n#include <cmath>\r\n#line 11 \"io/out.hpp\"\
    \n#include <string_view>\r\n#line 19 \"io/out.hpp\"\n\r\nnamespace kpr {\r\n \
    \   // \u30D0\u30C3\u30D5\u30A1\u3092\u7528\u3044\u3066\u30D5\u30A1\u30A4\u30EB\
    \u306B\u66F8\u304D\u8FBC\u3080\u30AF\u30E9\u30B9\r\n    template<std::size_t buf_size\
    \ = KYOPRO_BUFFER_SIZE>\r\n    struct Writer {\r\n    private:\r\n        int\
    \ fd, idx;\r\n        std::array<char, buf_size> buffer;\r\n\r\n    public:\r\n\
    \        // \u30D0\u30C3\u30D5\u30A1\u30B5\u30A4\u30BA\u3092\u53D6\u5F97\r\n \
    \       static constexpr KYOPRO_BASE_INT get_buf_size() noexcept {\r\n       \
    \     return buf_size;\r\n        }\r\n\r\n        Writer() noexcept = default;\r\
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
    \n} // namespace kpr\r\n#line 6 \"math/Montgomery.hpp\"\n\r\nnamespace kpr {\r\
    \n    template<class T>\r\n    struct Montgomery {\r\n        static_assert(is_unsigned_integer_v<T>,\
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
    \ * n2);\r\n        }\r\n\r\n        constexpr T inverse_transform(T x) const\
    \ noexcept {\r\n            T y = reduce(x);\r\n            return y >= mod ?\
    \ y - mod : y;\r\n        }\r\n\r\n        constexpr T reduce(larger_type x) const\
    \ noexcept {\r\n            return (x + static_cast<larger_type>(static_cast<T>(x)\
    \ * r) * mod) >> std::numeric_limits<T>::digits;\r\n        }\r\n    };\r\n} //\
    \ namespace kpr\r\n#line 13 \"math/DynamicModInt.hpp\"\n\r\nnamespace kpr {\r\n\
    \    template<class T, std::size_t kind = 0, bool = false>\r\n    struct DynamicModInt\
    \ {\r\n        static_assert(std::is_unsigned_v<T>, \"The given type must be an\
    \ unsigned integer type\");\r\n\r\n        using value_type = T;\r\n\r\n    private:\r\
    \n        using larger_type = next_integer_t<T>;\r\n\r\n        inline static\
    \ Montgomery<T> montgomery;\r\n\r\n    public:\r\n        T value;\r\n\r\n   \
    \     static constexpr KYOPRO_BASE_INT get_kind() noexcept {\r\n            return\
    \ kind;\r\n        }\r\n\r\n        static void set_mod(T mod) noexcept {\r\n\
    \            montgomery.set_mod(mod);\r\n        }\r\n\r\n        static KYOPRO_BASE_INT\
    \ get_mod() noexcept {\r\n            return montgomery.mod;\r\n        }\r\n\r\
    \n        KYOPRO_BASE_INT get_val() noexcept {\r\n            return montgomery.inverse_transform(value);\r\
    \n        }\r\n\r\n        DynamicModInt() noexcept = default;\r\n        DynamicModInt(T\
    \ value) noexcept: value(montgomery.transform(value % montgomery.mod + montgomery.mod))\
    \ {}\r\n\r\n        template<class U>\r\n        explicit operator U() const noexcept\
    \ {\r\n            return montgomery.inverse_transform(value);\r\n        }\r\n\
    \r\n        static DynamicModInt raw(T value) noexcept {\r\n            DynamicModInt\
    \ res;\r\n            res.value = montgomery.transform(value);\r\n           \
    \ return res;\r\n        }\r\n\r\n        DynamicModInt power(std::uint_fast64_t\
    \ n) const noexcept {\r\n            DynamicModInt res = 1, a = *this;\r\n   \
    \         while (n > 0) {\r\n                if (n & 1) res = res * a;\r\n   \
    \             a = a * a;\r\n                n >>= 1;\r\n            }\r\n    \
    \        return res;\r\n        }\r\n\r\n        DynamicModInt inverse() const\
    \ noexcept {\r\n            return power(montgomery.mod - 2);\r\n        }\r\n\
    \r\n        DynamicModInt operator +() const noexcept {\r\n            return\
    \ *this;\r\n        }\r\n\r\n        DynamicModInt operator -() const noexcept\
    \ {\r\n            return value == 0 ? 0 : montgomery.mod - value;\r\n       \
    \ }\r\n\r\n        DynamicModInt& operator ++() noexcept {\r\n            *this\
    \ += DynamicModInt::raw(1);\r\n            return *this;\r\n        }\r\n\r\n\
    \        DynamicModInt operator ++(int) noexcept {\r\n            DynamicModInt\
    \ before = *this;\r\n            ++*this;\r\n            return before;\r\n  \
    \      }\r\n\r\n        DynamicModInt& operator --() noexcept {\r\n          \
    \  *this -= DynamicModInt::raw(1);\r\n            return *this;\r\n        }\r\
    \n\r\n        DynamicModInt operator --(int) noexcept {\r\n            DynamicModInt\
    \ before = *this;\r\n            --*this;\r\n            return before;\r\n  \
    \      }\r\n\r\n        DynamicModInt& operator +=(DynamicModInt rhs) noexcept\
    \ {\r\n            if ((value += rhs.value - (montgomery.mod << 1)) > std::numeric_limits<std::make_signed_t<T>>::max())\
    \ value += montgomery.mod << 1;\r\n            return *this;\r\n        }\r\n\r\
    \n        DynamicModInt& operator -=(DynamicModInt rhs) noexcept {\r\n       \
    \     if ((value -= rhs.value) > std::numeric_limits<std::make_signed_t<T>>::max())\
    \ value += montgomery.mod << 1;\r\n            return *this;\r\n        }\r\n\r\
    \n        DynamicModInt& operator *=(DynamicModInt rhs) noexcept {\r\n       \
    \     value = montgomery.reduce(static_cast<larger_type>(value) * rhs.value);\r\
    \n            return *this;\r\n        }\r\n\r\n        DynamicModInt& operator\
    \ /=(DynamicModInt rhs) noexcept {\r\n            value = montgomery.reduce(static_cast<larger_type>(value)\
    \ * rhs.inverse().value);\r\n            return *this;\r\n        }\r\n\r\n  \
    \      friend DynamicModInt operator +(DynamicModInt lhs, DynamicModInt rhs) noexcept\
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
    \ {\r\n            PrintFunction<T>::print(printer, a.montgomery.inverse_transform(a.value));\r\
    \n        }\r\n    };\r\n\r\n    template<class T, std::size_t kind>\r\n    struct\
    \ Hash<DynamicModInt<T, kind>> {\r\n        using value_type = DynamicModInt<T,\
    \ kind>;\r\n\r\n        std::size_t operator ()(DynamicModInt<T, kind> a) const\
    \ noexcept {\r\n            return static_cast<std::size_t>(a);\r\n        }\r\
    \n    };\r\n} // namespace kpr\r\n#line 4 \"math/euler_phi.hpp\"\n\r\nnamespace\
    \ kpr {\r\n    // \u30AA\u30A4\u30E9\u30FC\u306E\u03C6\u95A2\u6570\r\n    [[maybe_unused]]\
    \ inline constexpr struct {\r\n        constexpr KYOPRO_BASE_INT operator ()(std::uint_fast64_t\
    \ n) const noexcept {\r\n            std::uint_fast64_t res = n;\r\n         \
    \   if ((n & 1) == 0) {\r\n                res -= res >> 1;\r\n              \
    \  n >>= 1;\r\n                while ((n & 1) == 0) n >>= 1;\r\n            }\r\
    \n            for (std::uint_fast64_t i = 3; i * i <= n; i += 2) {\r\n       \
    \         if (n % i == 0) {\r\n                res -= res / i;\r\n           \
    \     n /= i;\r\n                while (n % i == 0) n /= i;\r\n              \
    \  }\r\n            }\r\n            if (n != 1) res -= res / n;\r\n         \
    \   return res;\r\n        }\r\n    } euler_phi;\r\n} // namespace kpr\r\n#line\
    \ 5 \"math/factorize.hpp\"\n#include <numeric>\r\n#include <random>\r\n#line 8\
    \ \"math/is_prime.hpp\"\n\r\nnamespace kpr {\r\n    [[maybe_unused]] inline constexpr\
    \ struct {\r\n        template<class T>\r\n        constexpr bool operator ()(T\
    \ x) const {\r\n            using U = std::make_unsigned_t<T>;\r\n           \
    \ using dmint = DynamicModInt<U, 0, true>;\r\n            U n = x;\r\n       \
    \     if (n <= 1) return false;\r\n            if (!(n & 1)) return n == 2;\r\n\
    \            dmint::set_mod(n);\r\n            std::uint_fast64_t d = (n - 1)\
    \ >> rzero_count(n - 1);\r\n            dmint one = 1, minus_one = n - 1;\r\n\
    \            auto ng = [&](std::uint_fast64_t a) noexcept {\r\n              \
    \  auto y = dmint(a).power(d);\r\n                std::uint_fast64_t t = d;\r\n\
    \                while (y != one and y != minus_one and t != n - 1) y *= y, t\
    \ <<= 1;\r\n                if (y != minus_one and !(t & 1)) return true;\r\n\
    \                return false;\r\n            };\r\n            if constexpr (std::numeric_limits<U>::digits\
    \ <= 32) {\r\n                for (auto i: (std::uint_fast64_t[3]){2, 7, 61})\
    \ {\r\n                    if (n <= i) return true;\r\n                    if\
    \ (ng(i)) return false;\r\n                }\r\n            } else if (n < (static_cast<U>(1)\
    \ << 32)) {\r\n                for (auto i: (std::uint_fast64_t[3]){2, 7, 61})\
    \ {\r\n                    if (n <= i) return true;\r\n                    if\
    \ (ng(i)) return false;\r\n                }\r\n            } else {\r\n     \
    \           for (auto i: (std::uint_fast64_t[7]){2, 325, 9375, 28178, 450775,\
    \ 9780504, 1795265022}) {\r\n                    if (n <= i) return true;\r\n\
    \                    if (ng(i)) return false;\r\n                }\r\n       \
    \     }\r\n            return true;\r\n        }\r\n    } is_prime;\r\n} // namespace\
    \ kpr\r\n#line 12 \"math/factorize.hpp\"\n\r\nnamespace kpr {\r\n    // \u7D20\
    \u56E0\u6570\u5206\u89E3\r\n    [[maybe_unused]] inline constexpr struct {\r\n\
    \        template<class T>\r\n        constexpr T operator ()(T p, std::uint_fast64_t\
    \ c) const {\r\n            using U = std::make_unsigned_t<T>;\r\n           \
    \ using dmint = DynamicModInt<U, 0, true>;\r\n            U n = p;\r\n       \
    \     dmint::set_mod(n);\r\n            dmint cc = c;\r\n            auto f =\
    \ [=](dmint x) noexcept {\r\n                return x * x + cc;\r\n          \
    \  };\r\n            auto x = dmint::raw(1), y = dmint::raw(2), z = dmint::raw(1),\
    \ q = dmint::raw(1);\r\n            U g = 1;\r\n            const int m = 1 <<\
    \ (floor_bit(n) / 5);\r\n            for (int r = 1; g == 1; r <<= 1) {\r\n  \
    \              x = y;\r\n                for (int i = 0; i < r; ++i) y = f(y);\r\
    \n                for (int k = 0; k < r && g == 1; k += m) {\r\n             \
    \   z = y;\r\n                int min = std::min(m, r - k);\r\n              \
    \  for (int i = 0; i < min; ++i) {\r\n                    y = f(y);\r\n      \
    \              q *= x - y;\r\n                }\r\n                g = std::gcd(static_cast<U>(q),\
    \ n);\r\n                }\r\n            }\r\n            if (g == n) {\r\n \
    \               do {\r\n                z = f(z);\r\n                g = std::gcd(static_cast<U>(x\
    \ - z), n);\r\n                } while (g == 1);\r\n            }\r\n        \
    \    return g;\r\n        }\r\n    } pollard_rho;\r\n\r\n    [[maybe_unused]]\
    \ inline constexpr struct {\r\n        KYOPRO_BASE_UINT operator ()(std::uint_fast64_t\
    \ n) const noexcept {\r\n            static std::mt19937_64 mt(std::random_device{}());\r\
    \n            std::uniform_int_distribution<std::uint_fast64_t> rnd(0, n - 1);\r\
    \n            if (is_prime(n)) return n;\r\n            for (int i = 0; i < 100;\
    \ ++i) {\r\n                std::uint_fast64_t m = pollard_rho(n, rnd(mt));\r\n\
    \                if (is_prime(m)) return m;\r\n                n = m;\r\n    \
    \        }\r\n            return 1;\r\n        }\r\n    } find_factor;\r\n\r\n\
    \    [[maybe_unused]] inline constexpr struct {\r\n        template<bool sorted\
    \ = true, class Container = std::vector<KYOPRO_BASE_INT>>\r\n        Container\
    \ operator ()(std::uint_fast64_t n) const {\r\n            Container res;\r\n\
    \            for (int p = 2; p < 100 && p * p <= n; ++p) {\r\n               \
    \ while (n % p == 0) {\r\n                n /= p;\r\n                res.emplace_back(p);\r\
    \n                }\r\n            }\r\n            while (n > 1) {\r\n      \
    \          std::uint_fast64_t p = find_factor(n);\r\n                do {\r\n\
    \                n /= p;\r\n                res.emplace_back(p);\r\n         \
    \       } while (n % p == 0);\r\n            }\r\n            if constexpr (sorted)\
    \ std::sort(res.begin(), res.end());\r\n            return res;\r\n        }\r\
    \n    } factorize;\r\n} // namespace kpr\r\n#line 2 \"math/mod.hpp\"\n#include\
    \ <cassert>\r\n#line 4 \"math/mod.hpp\"\n\r\nnamespace kpr {\r\n    [[maybe_unused]]\
    \ inline constexpr struct {\r\n        template<class T, class U>\r\n        constexpr\
    \ std::common_type_t<T, U> operator ()(T x, U m) const noexcept {\r\n        \
    \    static_assert(is_integer_v<T> && is_integer_v<U>, \"Both of the arguments\
    \ must be integers\");\r\n            if constexpr (is_unsigned_integer_v<T> ||\
    \ is_unsigned_integer_v<U>) return x % m;\r\n            return (x %= m) < 0 ?\
    \ x + m : x;\r\n        }\r\n    } floor_mod;\r\n\r\n    [[maybe_unused]] inline\
    \ constexpr struct {\r\n        template<class T, class U>\r\n        constexpr\
    \ std::common_type_t<T, U> operator ()(T x, U m) const noexcept {\r\n        \
    \    return m - floor_mod(x - 1, m) - static_cast<T>(1);\r\n        }\r\n    }\
    \ ceil_mod;\r\n} // namespace kpr\r\n#line 16 \"math/ModInt.hpp\"\n\r\nnamespace\
    \ kpr {\r\n    template<KYOPRO_BASE_UINT m>\r\n    struct ModInt {\r\n       \
    \ using value_type = uint_least_t<bit_len(m * 2 - 2)>;\r\n\r\n        static constexpr\
    \ value_type mod = m;\r\n        value_type value;\r\n\r\n        static constexpr\
    \ KYOPRO_BASE_INT get_mod() noexcept {\r\n            return mod;\r\n        }\r\
    \n\r\n        constexpr ModInt() noexcept = default;\r\n        template<class\
    \ T>\r\n        constexpr ModInt(T value) noexcept: value(floor_mod(value, mod))\
    \ {}\r\n\r\n        template<class T>\r\n        explicit constexpr operator T()\
    \ const noexcept {\r\n            return value;\r\n        }\r\n\r\n        static\
    \ constexpr ModInt raw(value_type value) noexcept {\r\n            ModInt res;\r\
    \n            res.value = value;\r\n            return res;\r\n        }\r\n\r\
    \n        constexpr ModInt power(KYOPRO_BASE_UINT n) const noexcept {\r\n    \
    \        std::uint_fast64_t res = 1, a = value;\r\n            while (n > 0) {\r\
    \n                if (n & 1) res = res * a % mod;\r\n                a = a * a\
    \ % mod;\r\n                n >>= 1;\r\n            }\r\n            return res;\r\
    \n        }\r\n\r\n        constexpr ModInt inverse() const noexcept {\r\n   \
    \         std::uint_fast64_t a = value, b = mod;\r\n            std::int_fast64_t\
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
    \   value = static_cast<uint_least_t<bit_len(mod) * 2>>(value) * rhs.inverse().value\
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
    \ ModInt<mod>& a) {\r\n            PrintFunction<typename ModInt<mod>::value_type>::print(printer,\
    \ a.value);\r\n        }\r\n    };\r\n\r\n    template<KYOPRO_BASE_UINT mod>\r\
    \n    struct Hash<ModInt<mod>> {\r\n        using value_type = ModInt<mod>;\r\n\
    \        constexpr std::size_t operator ()(ModInt<mod> a) const noexcept {\r\n\
    \            return static_cast<std::size_t>(a);\r\n        }\r\n    };\r\n} //\
    \ namespace kpr\r\n#line 5 \"range/range_base.hpp\"\n\r\nnamespace kpr {\r\n \
    \   template<class Derived, class ValueType>\r\n    struct RangeBase {\r\n   \
    \     using value_type = std::decay_t<ValueType>;\r\n        using size_type =\
    \ std::size_t;\r\n        using difference_type = std::ptrdiff_t;\r\n        using\
    \ reference = value_type&;\r\n        using const_reference = const value_type&;\r\
    \n        using pointer = value_type*;\r\n        using const_pointer = const\
    \ value_type*;\r\n\r\n        Derived& down_cast() noexcept {\r\n            return\
    \ static_cast<Derived&>(*this);\r\n        }\r\n        const Derived& down_cast()\
    \ const noexcept {\r\n            return static_cast<const Derived&>(*this);\r\
    \n        }\r\n\r\n        constexpr auto begin() const noexcept {\r\n       \
    \     return down_cast().begin();\r\n        }\r\n\r\n        constexpr auto end()\
    \ const noexcept {\r\n            return down_cast().end();\r\n        }\r\n\r\
    \n        constexpr auto cbegin() const noexcept {\r\n            return down_cast().cbegin();\r\
    \n        }\r\n\r\n        constexpr auto cend() const noexcept {\r\n        \
    \    return down_cast().cend();\r\n        }\r\n\r\n        constexpr bool empty()\
    \ const noexcept {\r\n            return begin() == end();\r\n        }\r\n\r\n\
    \        constexpr decltype(auto) front() noexcept {\r\n            return *begin();\r\
    \n        }\r\n        constexpr decltype(auto) front() const noexcept {\r\n \
    \           return *cbegin();\r\n        }\r\n\r\n        constexpr decltype(auto)\
    \ rbegin() const noexcept {\r\n            return std::reverse_iterator(end());\r\
    \n        }\r\n\r\n        constexpr decltype(auto) rend() const noexcept {\r\n\
    \            return std::reverse_iterator(begin());\r\n        }\r\n\r\n     \
    \   constexpr decltype(auto) crbegin() const noexcept {\r\n            return\
    \ std::reverse_iterator(cend());\r\n        }\r\n\r\n        constexpr decltype(auto)\
    \ crend() const noexcept {\r\n            return std::reverse_iterator(cbegin());\r\
    \n        }\r\n\r\n        constexpr decltype(auto) back() noexcept {\r\n    \
    \        return *rbegin();\r\n        }\r\n        constexpr decltype(auto) back()\
    \ const noexcept {\r\n            return *crbegin();\r\n        }\r\n\r\n    \
    \    constexpr std::size_t size() const noexcept {\r\n            return end()\
    \ - begin();\r\n        }\r\n\r\n        constexpr decltype(auto) operator [](std::size_t\
    \ idx) {\r\n            return *(begin() + idx);\r\n        }\r\n        constexpr\
    \ decltype(auto) operator [](std::size_t idx) const {\r\n            return *(cbegin()\
    \ + idx);\r\n        }\r\n    };\r\n} // namespace kpr\r\n#line 9 \"range/imap.hpp\"\
    \n\r\nnamespace kpr {\r\n    template<class Func, class Range>\r\n    struct imap:\
    \ RangeBase<imap<Func, Range>, std::invoke_result_t<Func, range_value_t<Range>>>\
    \ {\r\n    private:\r\n        using BaseIterator = range_iterator_t<Range>;\r\
    \n        using BaseConstIterator = range_const_iterator_t<Range>;\r\n\r\n   \
    \     Func func;\r\n        Range range;\r\n\r\n    public:\r\n        imap()\
    \ noexcept = default;\r\n        template<class F, class R>\r\n        imap(F&&\
    \ func, R&& range) noexcept: func(std::forward<F>(func)), range(std::forward<R>(range))\
    \ {}\r\n\r\n        struct iterator: BaseIterator {\r\n            using value_type\
    \ = std::decay_t<std::invoke_result_t<Func, decltype(*std::declval<BaseIterator>())>>;\r\
    \n            using pointer = value_type*;\r\n            using reference = value_type&;\r\
    \n\r\n        private:\r\n            Func func;\r\n\r\n        public:\r\n  \
    \          iterator() noexcept = default;\r\n            template<class F, class\
    \ Itr>\r\n            iterator(F&& func, Itr&& itr) noexcept: func(std::forward<F>(func)),\
    \ BaseIterator(std::forward<Itr>(itr)) {}\r\n\r\n            constexpr decltype(auto)\
    \ operator *() const noexcept {\r\n                return std::invoke(func, BaseIterator::operator\
    \ *());\r\n            }\r\n        };\r\n\r\n        struct const_iterator: BaseConstIterator\
    \ {\r\n            using value_type = const std::decay_t<std::invoke_result_t<Func,\
    \ decltype(*std::declval<BaseConstIterator>())>>;\r\n            using pointer\
    \ = value_type*;\r\n            using reference = value_type&;\r\n\r\n       \
    \ private:\r\n            Func func;\r\n\r\n        public:\r\n            const_iterator()\
    \ noexcept = default;\r\n            template<class F, class Itr>\r\n        \
    \    const_iterator(F&& func, Itr&& itr) noexcept: func(std::forward<F>(func)),\
    \ BaseConstIterator(std::forward<Itr>(itr)) {}\r\n\r\n            constexpr decltype(auto)\
    \ operator *() const noexcept {\r\n                return std::invoke(func, BaseConstIterator::operator\
    \ *());\r\n            }\r\n        };\r\n\r\n\r\n        using reverse_iterator\
    \ = std::reverse_iterator<iterator>;\r\n        using const_reverse_iterator =\
    \ std::reverse_iterator<const_iterator>;\r\n\r\n\r\n        constexpr iterator\
    \ begin() const noexcept {\r\n            return iterator{func, std::begin(range)};\r\
    \n        }\r\n\r\n        constexpr iterator end() const noexcept {\r\n     \
    \       return iterator{func, std::end(range)};\r\n        }\r\n\r\n        constexpr\
    \ const_iterator cbegin() const noexcept {\r\n            return const_iterator{func,\
    \ std::begin(range)};\r\n        }\r\n\r\n        constexpr const_iterator cend()\
    \ const noexcept {\r\n            return const_iterator{func, std::end(range)};\r\
    \n        }\r\n    };\r\n\r\n    template<class F, class R>\r\n    imap(F&&, R&&)\
    \ -> imap<std::decay_t<F>, std::decay_t<R>>;\r\n} // namespace kpr\r\n#line 5\
    \ \"range/iterator_base.hpp\"\n\r\nnamespace kpr {\r\n    template<class, class,\
    \ class>\r\n    struct IteratorBase;\r\n\r\n    template<class Derived, class\
    \ ValueType>\r\n    struct IteratorBase<Derived, ValueType, std::forward_iterator_tag>\
    \ {\r\n        using value_type = std::decay_t<ValueType>;\r\n        using pointer\
    \ = value_type*;\r\n        using reference = value_type&;\r\n        using difference_type\
    \ = std::ptrdiff_t;\r\n        using iterator_category = std::forward_iterator_tag;\r\
    \n\r\n        virtual constexpr ValueType operator *() const noexcept;\r\n   \
    \     virtual constexpr Derived& operator ++() noexcept;\r\n        virtual constexpr\
    \ bool operator ==(const Derived&) const noexcept;\r\n\r\n        constexpr Derived\
    \ operator ++(int) noexcept {\r\n            Derived before = *this;\r\n     \
    \       ++*this;\r\n            return before;\r\n        }\r\n\r\n        constexpr\
    \ bool operator !=(const Derived& rhs) const noexcept {\r\n            return\
    \ !(*this == rhs);\r\n        }\r\n    };\r\n\r\n    template<class Derived, class\
    \ ValueType>\r\n    struct IteratorBase<Derived, ValueType, std::bidirectional_iterator_tag>:\
    \ IteratorBase<Derived, ValueType, std::forward_iterator_tag> {\r\n        using\
    \ iterator_category = std::bidirectional_iterator_tag;\r\n\r\n        virtual\
    \ constexpr Derived& operator --() noexcept;\r\n\r\n        constexpr Derived\
    \ operator --(int) noexcept {\r\n            Derived before = *this;\r\n     \
    \       --*this;\r\n            return before;\r\n        }\r\n    };\r\n\r\n\
    \    template<class Derived, class ValueType>\r\n    struct IteratorBase<Derived,\
    \ ValueType, std::random_access_iterator_tag>: IteratorBase<Derived, ValueType,\
    \ std::bidirectional_iterator_tag> {\r\n        using iterator_category = std::random_access_iterator_tag;\r\
    \n\r\n        virtual constexpr Derived operator +(std::ptrdiff_t rhs) const noexcept;\r\
    \n        virtual constexpr std::ptrdiff_t operator -(const Derived&) const noexcept;\r\
    \n\r\n    private:\r\n        virtual constexpr int compare(const Derived&) const\
    \ noexcept;\r\n\r\n    public:\r\n\r\n        constexpr Derived& operator +=(std::ptrdiff_t\
    \ rhs) noexcept {\r\n            return *this = *this + rhs;\r\n        }\r\n\r\
    \n        constexpr Derived operator -(std::ptrdiff_t rhs) const noexcept {\r\n\
    \            return *this + -rhs;\r\n        }\r\n\r\n        constexpr Derived&\
    \ operator -=(std::ptrdiff_t rhs) noexcept {\r\n            return *this = *this\
    \ - rhs;\r\n        }\r\n\r\n        constexpr decltype(auto) operator [](std::size_t\
    \ idx) const noexcept {\r\n            return *(*this + idx);\r\n        }\r\n\
    \r\n        constexpr bool operator ==(const Derived& rhs) const noexcept {\r\n\
    \            return compare(rhs) == 0;\r\n        }\r\n        constexpr bool\
    \ operator !=(const Derived& rhs) const noexcept {\r\n            return compare(rhs)\
    \ != 0;\r\n        }\r\n        constexpr bool operator <(const Derived& rhs)\
    \ const noexcept {\r\n            return compare(rhs) < 0;\r\n        }\r\n  \
    \      constexpr bool operator <=(const Derived& rhs) const noexcept {\r\n   \
    \         return compare(rhs) <= 0;\r\n        }\r\n        constexpr bool operator\
    \ >(const Derived& rhs) const noexcept {\r\n            return compare(rhs) >\
    \ 0;\r\n        }\r\n        constexpr bool operator >=(const Derived& rhs) const\
    \ noexcept {\r\n            return compare(rhs) >= 0;\r\n        }\r\n    };\r\
    \n} // namespace kpr\r\n#line 10 \"range/irange.hpp\"\n\r\nnamespace kpr {\r\n\
    \    template<class T>\r\n    struct irange: RangeBase<irange<T>, T> {\r\n   \
    \ private:\r\n        T first, last;\r\n\r\n        template<class, class = void,\
    \ class = void, class = void>\r\n        struct get_iterator_category;\r\n   \
    \     template<class ValueType, class Void>\r\n        struct get_iterator_category<ValueType,\
    \ std::void_t<decltype(++std::declval<ValueType>())>, Void, Void> {\r\n      \
    \      using type = std::forward_iterator_tag;\r\n        };\r\n        template<class\
    \ ValueType, class Void>\r\n        struct get_iterator_category<ValueType, std::void_t<decltype(++std::declval<ValueType>())>,\
    \ std::void_t<decltype(--std::declval<ValueType>())>, Void> {\r\n            using\
    \ type = std::bidirectional_iterator_tag;\r\n        };\r\n        template<class\
    \ ValueType>\r\n        struct get_iterator_category<ValueType, std::void_t<decltype(++std::declval<ValueType>())>,\
    \ std::void_t<decltype(--std::declval<ValueType>())>, std::void_t<decltype(std::declval<T>()\
    \ < std::declval<ValueType>(), std::declval<ValueType>() > std::declval<ValueType>(),\
    \ std::declval<ValueType>() + std::declval<std::ptrdiff_t>(), std::declval<ValueType>()\
    \ - std::declval<ValueType>())>> {\r\n            using type = std::random_access_iterator_tag;\r\
    \n        };\r\n\r\n    public:\r\n        irange() noexcept = default;\r\n  \
    \      template<class F, class L>\r\n        irange(F&& first, L&& last) noexcept:\
    \ first(std::forward<F>(first)), last(std::forward<L>(last)) {}\r\n\r\n      \
    \  struct iterator: IteratorBase<iterator, const T&, typename get_iterator_category<T&>::type>\
    \ {\r\n        private:\r\n            T itr;\r\n\r\n            constexpr int\
    \ compare(const iterator& rhs) const noexcept {\r\n                if (itr < rhs.itr)\
    \ return -1;\r\n                else if (itr > rhs.itr) return 1;\r\n        \
    \        else return 0;\r\n            }\r\n\r\n        public:\r\n          \
    \  iterator() noexcept = default;\r\n            template<class Itr>\r\n     \
    \       iterator(Itr&& itr) noexcept: itr(std::forward<Itr>(itr)) {}\r\n\r\n \
    \           constexpr const T& operator *() const noexcept {\r\n             \
    \   return itr;\r\n            }\r\n\r\n            constexpr iterator& operator\
    \ ++() noexcept {\r\n                ++itr;\r\n                return *this;\r\
    \n            }\r\n\r\n            constexpr iterator& operator --() noexcept\
    \ {\r\n                --itr;\r\n                return *this;\r\n           \
    \ }\r\n\r\n            constexpr iterator operator +(std::ptrdiff_t rhs) const\
    \ noexcept {\r\n                return iterator{itr + rhs};\r\n            }\r\
    \n\r\n            constexpr std::ptrdiff_t operator -(const iterator& rhs) const\
    \ noexcept {\r\n                return itr - rhs.itr;\r\n            }\r\n   \
    \     };\r\n\r\n        struct const_iterator: IteratorBase<const_iterator, const\
    \ T&, typename get_iterator_category<T&>::type> {\r\n        private:\r\n    \
    \        T itr;\r\n\r\n            constexpr int compare(const const_iterator&\
    \ rhs) const noexcept {\r\n                if (itr < rhs.itr) return -1;\r\n \
    \               else if (itr > rhs.itr) return 1;\r\n                else return\
    \ 0;\r\n            }\r\n\r\n        public:\r\n            const_iterator() noexcept\
    \ = default;\r\n            template<class Itr>\r\n            const_iterator(Itr&&\
    \ itr) noexcept: itr(std::forward<Itr>(itr)) {}\r\n\r\n            constexpr const\
    \ T& operator *() const noexcept {\r\n                return itr;\r\n        \
    \    }\r\n\r\n            constexpr const_iterator& operator ++() noexcept {\r\
    \n                ++itr;\r\n                return *this;\r\n            }\r\n\
    \r\n            constexpr const_iterator& operator --() noexcept {\r\n       \
    \         --itr;\r\n                return *this;\r\n            }\r\n\r\n   \
    \         constexpr const_iterator operator +(std::ptrdiff_t rhs) const noexcept\
    \ {\r\n                return iterator{itr + rhs};\r\n            }\r\n\r\n  \
    \          constexpr std::ptrdiff_t operator -(const const_iterator& rhs) const\
    \ noexcept {\r\n                return itr - rhs.itr;\r\n            }\r\n   \
    \     };\r\n\r\n\r\n        using reverse_iterator = std::reverse_iterator<iterator>;\r\
    \n        using const_reverse_iterator = std::reverse_iterator<const_iterator>;\r\
    \n\r\n\r\n        constexpr iterator begin() const noexcept {\r\n            return\
    \ iterator{first};\r\n        }\r\n\r\n        constexpr iterator end() const\
    \ noexcept {\r\n            return iterator{last};\r\n        }\r\n\r\n      \
    \  constexpr const_iterator cbegin() const noexcept {\r\n            return const_iterator{first};\r\
    \n        }\r\n\r\n        constexpr const_iterator cend() const noexcept {\r\n\
    \            return const_iterator{last};\r\n        }\r\n    };\r\n\r\n    template<class\
    \ F, class L>\r\n    irange(F&&, L&&) -> irange<std::decay_t<F>>;\r\n} // namespace\
    \ kpr\r\n#line 8 \"all/all.hpp\"\n"
  code: "#pragma once\r\n#include \"../algorithm/algorithm.hpp\"\r\n#include \"../function/function.hpp\"\
    \r\n#include \"../math/math.hpp\"\r\n#include \"../meta/meta.hpp\"\r\n#include\
    \ \"../range/range.hpp\"\r\n#include \"../io/io.hpp\"\r\n"
  dependsOn:
  - algorithm/algorithm.hpp
  - algorithm/bit.hpp
  - meta/setting.hpp
  - meta/trait.hpp
  - algorithm/Hash.hpp
  - meta/tuple_like.hpp
  - function/function.hpp
  - function/compare.hpp
  - function/monoid.hpp
  - meta/constant.hpp
  - math/power.hpp
  - function/RecursiveLambda.hpp
  - math/math.hpp
  - math/Barrett.hpp
  - math/div.hpp
  - math/divisors.hpp
  - math/DynamicModInt.hpp
  - io/in.hpp
  - io/io_option.hpp
  - io/out.hpp
  - math/Montgomery.hpp
  - math/euler_phi.hpp
  - math/factorize.hpp
  - math/is_prime.hpp
  - math/mod.hpp
  - math/ModInt.hpp
  - meta/meta.hpp
  - range/range.hpp
  - range/imap.hpp
  - range/range_base.hpp
  - range/irange.hpp
  - range/iterator_base.hpp
  - io/io.hpp
  isVerificationFile: false
  path: all/all.hpp
  requiredBy:
  - verify/hello_world.cpp
  - all.hpp
  timestamp: '2023-02-19 20:41:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: all/all.hpp
layout: document
redirect_from:
- /library/all/all.hpp
- /library/all/all.hpp.html
title: all/all.hpp
---
