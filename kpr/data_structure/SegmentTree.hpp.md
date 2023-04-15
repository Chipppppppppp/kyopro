---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: kpr/algorithm/bit.hpp
    title: kpr/algorithm/bit.hpp
  - icon: ':question:'
    path: kpr/function/monoid.hpp
    title: kpr/function/monoid.hpp
  - icon: ':question:'
    path: kpr/meta/setting.hpp
    title: kpr/meta/setting.hpp
  - icon: ':question:'
    path: kpr/meta/trait.hpp
    title: kpr/meta/trait.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: kpr/all.hpp
    title: kpr/all.hpp
  - icon: ':warning:'
    path: kpr/data_structure/data_structure.hpp
    title: kpr/data_structure/data_structure.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/point_set_range_composite.test.cpp
    title: verify/yosupo/point_set_range_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"kpr/data_structure/SegmentTree.hpp\"\n#include <algorithm>\n\
    #include <cstdint>\n#include <utility>\n#include <vector>\n#line 2 \"kpr/algorithm/bit.hpp\"\
    \n#include <limits>\r\n#include <type_traits>\r\n#line 3 \"kpr/meta/setting.hpp\"\
    \n\r\n#ifndef KYOPRO_BASE_INT\r\n// \u57FA\u672C\u7B26\u53F7\u4ED8\u304D\u6574\
    \u6570\u578B\r\n#define KYOPRO_BASE_INT std::int64_t\r\n#endif\r\n\r\n#ifndef\
    \ KYOPRO_BASE_UINT\r\n// \u57FA\u672C\u7B26\u53F7\u306A\u3057\u6574\u6570\u578B\
    \r\n#define KYOPRO_BASE_UINT std::uint64_t\r\n#endif\r\n\r\n#ifndef KYOPRO_BASE_FLOAT\r\
    \n// \u57FA\u672C\u6D6E\u52D5\u5C0F\u6570\u70B9\u6570\u578B\r\n#define KYOPRO_BASE_FLOAT\
    \ double\r\n#endif\r\n\r\n#ifndef KYOPRO_BASE_MINT\r\n// \u57FA\u672Cmodint\r\n\
    #define KYOPRO_BASE_MINT kpr::ModInt<mod>\r\n#endif\r\n\r\n#ifndef KYOPRO_DEFAULT_MOD\r\
    \n// \u554F\u984C\u3067\u8A2D\u5B9A\u3055\u308C\u305Fmod\r\n#define KYOPRO_DEFAULT_MOD\
    \ (static_cast<KYOPRO_BASE_UINT>(998244353))\r\n#endif\r\n\r\n#ifndef KYOPRO_DECIMAL_PRECISION\r\
    \n// \u5C0F\u6570\u7CBE\u5EA6(\u6841)\r\n#define KYOPRO_DECIMAL_PRECISION (static_cast<KYOPRO_BASE_UINT>(12))\r\
    \n#endif\r\n\r\n#ifndef KYOPRO_INF_DIV\r\n// \u7121\u9650\u5927\u3092\u8868\u3059\
    \u6574\u6570\u304C\u6700\u5927\u5024\u306E\u4F55\u5206\u306E\u4E00\u304B\u3092\
    \u8868\u3059\r\n#define KYOPRO_INF_DIV (static_cast<KYOPRO_BASE_UINT>(3))\r\n\
    #endif\r\n\r\n#ifndef KYOPRO_BUFFER_SIZE\r\n// \u30C7\u30D5\u30A9\u30EB\u30C8\u306E\
    \u30D0\u30C3\u30D5\u30A1\u30B5\u30A4\u30BA\r\n#define KYOPRO_BUFFER_SIZE (static_cast<KYOPRO_BASE_UINT>(2048))\r\
    \n#endif\r\n\r\n#ifndef KYOPRO_BINOM_MOD_MAX\r\n// \u30C7\u30D5\u30A9\u30EB\u30C8\
    \u306EBinomMod\u306E\u8A08\u7B97\u4E0A\u9650\r\n#define KYOPRO_BINOM_MOD_MAX (static_cast<KYOPRO_BASE_UINT>(1000000))\r\
    \n#endif\r\n#line 2 \"kpr/meta/trait.hpp\"\n#include <cstddef>\r\n#include <iterator>\r\
    \n#include <tuple>\r\n#line 7 \"kpr/meta/trait.hpp\"\n\r\nnamespace kpr {\r\n\
    \    namespace helper {\r\n        template<class T>\r\n        struct is_integer_helper\
    \ {\r\n            static constexpr bool value = std::is_integral_v<T>;\r\n  \
    \      };\r\n\r\n        #ifdef __SIZEOF_INT128__\r\n        template<>\r\n  \
    \      struct is_integer_helper<__int128_t> {\r\n            static constexpr\
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
    \n} // namespace kpr\r\n#line 6 \"kpr/algorithm/bit.hpp\"\n\r\nnamespace kpr {\r\
    \n    // \u7ACB\u3063\u3066\u3044\u308Bbit\u306E\u500B\u6570\u3092\u8FD4\u3059\
    \r\n    [[maybe_unused]] inline constexpr struct {\r\n        template<class T>\r\
    \n        constexpr KYOPRO_BASE_INT operator ()(T x) const noexcept {\r\n    \
    \        static_assert(is_integer_v<T>, \"The argument must be an integer\");\r\
    \n            constexpr auto digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;\r\
    \n            static_assert(digits <= std::numeric_limits<unsigned long long>::digits,\
    \ \"The integer type of the argument is too large\");\r\n            if constexpr\
    \ (digits <= std::numeric_limits<unsigned int>::digits) return __builtin_popcount(x);\r\
    \n            else if constexpr (digits <= std::numeric_limits<unsigned long>::digits)\
    \ return __builtin_popcountl(x);\r\n            else return __builtin_popcountll(x);\r\
    \n        }\r\n    } pop_count;\r\n\r\n    // \u6700\u4E0A\u4F4Dbit\u3088\u308A\
    \u5DE6\u306E\u9023\u7D9A\u3057\u305F0\u30D3\u30C3\u30C8\u306E\u6570\u3092\u8FD4\
    \u3059\r\n    [[maybe_unused]] inline constexpr struct {\r\n        template<class\
    \ T>\r\n        constexpr KYOPRO_BASE_INT operator ()(T x) const noexcept {\r\n\
    \            static_assert(is_integer_v<T>, \"The argument must be an integer\"\
    );\r\n            constexpr auto digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;\r\
    \n            static_assert(digits <= std::numeric_limits<unsigned long long>::digits,\
    \ \"The integer type of the argument is too large\");\r\n            if (x ==\
    \ 0) return 0;\r\n            if constexpr (digits <= std::numeric_limits<unsigned\
    \ int>::digits) return __builtin_clz(x) + digits - std::numeric_limits<unsigned\
    \ int>::digits;\r\n            else if constexpr (digits <= std::numeric_limits<unsigned\
    \ long>::digits) return __builtin_clzl(x) + digits - std::numeric_limits<unsigned\
    \ long>::digits;\r\n            else return __builtin_clzll(x) + digits - std::numeric_limits<unsigned\
    \ long long>::digits;\r\n        }\r\n    } lzero_count;\r\n\r\n    // 1\u306E\
    \u4F4D\u304B\u3089\u9023\u7D9A\u3057\u305F0\u30D3\u30C3\u30C8\u306E\u6570\u3092\
    \u8FD4\u3059\r\n    [[maybe_unused]] inline constexpr struct {\r\n        template<class\
    \ T>\r\n        constexpr KYOPRO_BASE_INT operator ()(T x) const noexcept {\r\n\
    \            static_assert(is_integer_v<T>, \"The argument must be an integer\"\
    );\r\n            constexpr auto digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;\r\
    \n            if (x == 0) return digits;\r\n            static_assert(digits <=\
    \ std::numeric_limits<unsigned long long>::digits, \"The integer type of the argument\
    \ is too large\");\r\n            if constexpr (digits <= std::numeric_limits<unsigned\
    \ int>::digits) return __builtin_ctz(x);\r\n            else if constexpr (digits\
    \ <= std::numeric_limits<unsigned long>::digits) return __builtin_ctzl(x);\r\n\
    \            else return __builtin_ctzll(x);\r\n        }\r\n    } rzero_count;\r\
    \n\r\n    // \u30D3\u30C3\u30C8\u5E45\u3092\u8FD4\u3059\r\n    [[maybe_unused]]\
    \ inline constexpr struct {\r\n        template<class T>\r\n        constexpr\
    \ KYOPRO_BASE_INT operator ()(T x) const noexcept {\r\n            static_assert(is_integer_v<T>,\
    \ \"The argument must be an integer\");\r\n            constexpr auto digits =\
    \ std::numeric_limits<std::make_unsigned_t<T>>::digits;\r\n            static_assert(digits\
    \ <= std::numeric_limits<unsigned long long>::digits, \"The integer type of the\
    \ argument is too large\");\r\n            if (x == 0) return 0;\r\n         \
    \   if constexpr (digits <= std::numeric_limits<unsigned int>::digits) return\
    \ std::numeric_limits<unsigned int>::digits - __builtin_clz(x);\r\n          \
    \  else if constexpr (digits <= std::numeric_limits<unsigned long>::digits) return\
    \ std::numeric_limits<unsigned long>::digits - __builtin_clzl(x);\r\n        \
    \    else return std::numeric_limits<unsigned long long>::digits - __builtin_clzll(x);\r\
    \n        }\r\n    } bit_len;\r\n\r\n    // 1 << n \u304C\u4E0E\u3048\u3089\u308C\
    \u305F\u6570\u4EE5\u4E0B\u3067\u3042\u308B\u6700\u5927\u306E n \u3092\u8FD4\u3059\
    \ (0 \u306E\u5834\u5408\u30010\u3092\u8FD4\u3059)\r\n    [[maybe_unused]] inline\
    \ constexpr struct {\r\n        template<class T>\r\n        constexpr KYOPRO_BASE_INT\
    \ operator ()(T x) const noexcept {\r\n            return bit_len(x >> static_cast<T>(1));\r\
    \n        }\r\n    } floor_bit;\r\n\r\n    // 1 << n \u304C\u4E0E\u3048\u3089\u308C\
    \u305F\u6570\u4EE5\u4E0A\u3067\u3042\u308B\u6700\u5C0F\u306E n \u3092\u8FD4\u3059\
    \r\n    [[maybe_unused]] inline constexpr struct {\r\n        template<class T>\r\
    \n        constexpr KYOPRO_BASE_INT operator ()(T x) const noexcept {\r\n    \
    \        if (x == 0) return 0;\r\n            return bit_len(x - static_cast<T>(1));\r\
    \n        }\r\n    } ceil_bit;\r\n} // namespace kpr\r\n#line 6 \"kpr/function/monoid.hpp\"\
    \n\r\nnamespace kpr {\r\n    // \u8DB3\u3057\u7B97\u306Emonoid\r\n    template<class\
    \ T>\r\n    struct Add {\r\n        static_assert(is_arithmetic_v<T>, \"T must\
    \ be an arithmetic type\");\r\n\r\n        using value_type = T;\r\n\r\n     \
    \   static constexpr T id() noexcept {\r\n            return T{};\r\n        }\r\
    \n\r\n        constexpr T operator ()(const T& a, const T& b) const noexcept {\r\
    \n            return a + b;\r\n        }\r\n\r\n        static constexpr T inv(const\
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
    \ bool has_inv_v = has_inv<T>::value;\r\n} // namespace kpr\r\n#line 9 \"kpr/data_structure/SegmentTree.hpp\"\
    \n\nnamespace kpr {\n    template<class T, class Op = Add<T>>\n    struct SegmentTree\
    \ {\n        using value_type = T;\n        using num_type = std::size_t;\n  \
    \      using reference = T&;\n        using const_reference = const T&;\n    \
    \    using operator_type = Op;\n\n    private:\n        int n, log, num;\n   \
    \     std::vector<T> tree;\n        Op op;\n\n        void update(int k) {\n \
    \           tree[k] = op(tree[2 * k], tree[2 * k + 1]);\n        }\n\n    public:\n\
    \        SegmentTree() noexcept = default;\n        template<class... Args>\n\
    \        explicit SegmentTree(Args&&... args) {\n            std::vector<T> v(std::forward<Args>(args)...);\n\
    \            n = v.size();\n            log = ceil_bit(n);\n            num =\
    \ 1 << log;\n            tree = std::vector<T>(num * 2, op.id());\n          \
    \  std::move(v.begin(), v.end(), tree.begin() + num);\n            for (int i\
    \ = num - 1; i >= 1; --i) update(i);\n        }\n\n        std::size_t size()\
    \ const noexcept {\n            return n;\n        }\n\n        void set(int p,\
    \ const T& x) {\n            p += num;\n            tree[p] = x;\n           \
    \ for (int i = 1; i <= log; ++i) update(p >> i);\n        }\n\n        T get(int\
    \ p) const {\n            return tree[p + num];\n        }\n\n        T prod(int\
    \ r) const {\n            T sl = op.id(), sr = op.id();\n            int l = num;\n\
    \            r += num;\n            while (l < r) {\n                if (l & 1)\
    \ {\n                    sl = op(std::move(sl), tree[l]);\n                  \
    \  ++l;\n                }\n                if (r & 1) {\n                   \
    \ --r;\n                    sr = op(tree[r], std::move(sr));\n               \
    \ }\n                l >>= 1;\n                r >>= 1;\n            }\n     \
    \       return op(sl, sr);\n        }\n        T prod(int l, int r) const {\n\
    \            T sl = op.id(), sr = op.id();\n            l += num;\n          \
    \  r += num;\n            while (l < r) {\n                if (l & 1) {\n    \
    \                sl = op(std::move(sl), tree[l]);\n                    ++l;\n\
    \                }\n                if (r & 1) {\n                    --r;\n \
    \                   sr = op(tree[r], std::move(sr));\n                }\n    \
    \            l >>= 1;\n                r >>= 1;\n            }\n            return\
    \ op(sl, sr);\n        }\n\n        T all_prod() const {\n            return tree[1];\n\
    \        }\n\n        template<class F>\n        KYOPRO_BASE_INT max_right(int\
    \ l, F&& func) const {\n            if (l == n) return n;\n            l += num;\n\
    \            T s = op.id();\n            do {\n                while (!(l & 1))\
    \ l >>= 1;\n                if (!func(op(s, tree[l]))) {\n                   \
    \ while (l < num) {\n                        l *= 2;\n                       \
    \ if (func(op(s, tree[l]))) {\n                            s = op(std::move(s),\
    \ tree[l]);\n                            ++l;\n                        }\n   \
    \                 }\n                    return l - num;\n                }\n\
    \                s = op(std::move(s), tree[l]);\n                ++l;\n      \
    \      } while ((l & -l) != l);\n            return n;\n        }\n\n        template<class\
    \ F>\n        KYOPRO_BASE_INT min_left(int r, F&& func) const {\n            if\
    \ (r == 0) return 0;\n            r += num;\n            T s = op.id();\n    \
    \        do {\n                --r;\n                while (r > 1 && (r & 1))\
    \ r >>= 1;\n                if (!func(op(tree[r], s))) {\n                   \
    \ while (r < num) {\n                        r = r * 2 + 1;\n                \
    \        if (func(op(tree[r], s))) {\n                            s = op(tree[r],\
    \ std::move(s));\n                            --r;\n                        }\n\
    \                    }\n                    return r + 1 - num;\n            \
    \    }\n                s = op(tree[r], std::move(s));\n            } while ((r\
    \ & -r) != r);\n            return 0;\n        }\n    };\n} // namespace kpr\n"
  code: "#pragma once\n#include <algorithm>\n#include <cstdint>\n#include <utility>\n\
    #include <vector>\n#include \"../algorithm/bit.hpp\"\n#include \"../function/monoid.hpp\"\
    \n#include \"../meta/setting.hpp\"\n\nnamespace kpr {\n    template<class T, class\
    \ Op = Add<T>>\n    struct SegmentTree {\n        using value_type = T;\n    \
    \    using num_type = std::size_t;\n        using reference = T&;\n        using\
    \ const_reference = const T&;\n        using operator_type = Op;\n\n    private:\n\
    \        int n, log, num;\n        std::vector<T> tree;\n        Op op;\n\n  \
    \      void update(int k) {\n            tree[k] = op(tree[2 * k], tree[2 * k\
    \ + 1]);\n        }\n\n    public:\n        SegmentTree() noexcept = default;\n\
    \        template<class... Args>\n        explicit SegmentTree(Args&&... args)\
    \ {\n            std::vector<T> v(std::forward<Args>(args)...);\n            n\
    \ = v.size();\n            log = ceil_bit(n);\n            num = 1 << log;\n \
    \           tree = std::vector<T>(num * 2, op.id());\n            std::move(v.begin(),\
    \ v.end(), tree.begin() + num);\n            for (int i = num - 1; i >= 1; --i)\
    \ update(i);\n        }\n\n        std::size_t size() const noexcept {\n     \
    \       return n;\n        }\n\n        void set(int p, const T& x) {\n      \
    \      p += num;\n            tree[p] = x;\n            for (int i = 1; i <= log;\
    \ ++i) update(p >> i);\n        }\n\n        T get(int p) const {\n          \
    \  return tree[p + num];\n        }\n\n        T prod(int r) const {\n       \
    \     T sl = op.id(), sr = op.id();\n            int l = num;\n            r +=\
    \ num;\n            while (l < r) {\n                if (l & 1) {\n          \
    \          sl = op(std::move(sl), tree[l]);\n                    ++l;\n      \
    \          }\n                if (r & 1) {\n                    --r;\n       \
    \             sr = op(tree[r], std::move(sr));\n                }\n          \
    \      l >>= 1;\n                r >>= 1;\n            }\n            return op(sl,\
    \ sr);\n        }\n        T prod(int l, int r) const {\n            T sl = op.id(),\
    \ sr = op.id();\n            l += num;\n            r += num;\n            while\
    \ (l < r) {\n                if (l & 1) {\n                    sl = op(std::move(sl),\
    \ tree[l]);\n                    ++l;\n                }\n                if (r\
    \ & 1) {\n                    --r;\n                    sr = op(tree[r], std::move(sr));\n\
    \                }\n                l >>= 1;\n                r >>= 1;\n     \
    \       }\n            return op(sl, sr);\n        }\n\n        T all_prod() const\
    \ {\n            return tree[1];\n        }\n\n        template<class F>\n   \
    \     KYOPRO_BASE_INT max_right(int l, F&& func) const {\n            if (l ==\
    \ n) return n;\n            l += num;\n            T s = op.id();\n          \
    \  do {\n                while (!(l & 1)) l >>= 1;\n                if (!func(op(s,\
    \ tree[l]))) {\n                    while (l < num) {\n                      \
    \  l *= 2;\n                        if (func(op(s, tree[l]))) {\n            \
    \                s = op(std::move(s), tree[l]);\n                            ++l;\n\
    \                        }\n                    }\n                    return\
    \ l - num;\n                }\n                s = op(std::move(s), tree[l]);\n\
    \                ++l;\n            } while ((l & -l) != l);\n            return\
    \ n;\n        }\n\n        template<class F>\n        KYOPRO_BASE_INT min_left(int\
    \ r, F&& func) const {\n            if (r == 0) return 0;\n            r += num;\n\
    \            T s = op.id();\n            do {\n                --r;\n        \
    \        while (r > 1 && (r & 1)) r >>= 1;\n                if (!func(op(tree[r],\
    \ s))) {\n                    while (r < num) {\n                        r = r\
    \ * 2 + 1;\n                        if (func(op(tree[r], s))) {\n            \
    \                s = op(tree[r], std::move(s));\n                            --r;\n\
    \                        }\n                    }\n                    return\
    \ r + 1 - num;\n                }\n                s = op(tree[r], std::move(s));\n\
    \            } while ((r & -r) != r);\n            return 0;\n        }\n    };\n\
    } // namespace kpr\n"
  dependsOn:
  - kpr/algorithm/bit.hpp
  - kpr/meta/setting.hpp
  - kpr/meta/trait.hpp
  - kpr/function/monoid.hpp
  isVerificationFile: false
  path: kpr/data_structure/SegmentTree.hpp
  requiredBy:
  - kpr/data_structure/data_structure.hpp
  - kpr/all.hpp
  timestamp: '2023-04-16 03:46:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/point_set_range_composite.test.cpp
documentation_of: kpr/data_structure/SegmentTree.hpp
layout: document
redirect_from:
- /library/kpr/data_structure/SegmentTree.hpp
- /library/kpr/data_structure/SegmentTree.hpp.html
title: kpr/data_structure/SegmentTree.hpp
---
