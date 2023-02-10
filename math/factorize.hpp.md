---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: algorithm/Hash.hpp
    title: algorithm/Hash.hpp
  - icon: ':x:'
    path: algorithm/bit.hpp
    title: algorithm/bit.hpp
  - icon: ':x:'
    path: math/DynamicModInt.hpp
    title: math/DynamicModInt.hpp
  - icon: ':x:'
    path: math/Montgomery.hpp
    title: math/Montgomery.hpp
  - icon: ':x:'
    path: math/is_prime.hpp
    title: math/is_prime.hpp
  - icon: ':x:'
    path: math/power.hpp
    title: math/power.hpp
  - icon: ':x:'
    path: meta/constant.hpp
    title: meta/constant.hpp
  - icon: ':x:'
    path: meta/setting.hpp
    title: meta/setting.hpp
  - icon: ':x:'
    path: meta/trait.hpp
    title: meta/trait.hpp
  - icon: ':x:'
    path: meta/tuple_like.hpp
    title: meta/tuple_like.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  - icon: ':warning:'
    path: all/all.hpp
    title: all/all.hpp
  - icon: ':warning:'
    path: math/math.hpp
    title: math/math.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo/factorize.test.cpp
    title: verify/yosupo/factorize.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/factorize.hpp\"\n#include <algorithm>\n#include <cstddef>\n\
    #include <cstdint>\n#include <numeric>\n#include <random>\n#include <type_traits>\n\
    #line 2 \"algorithm/bit.hpp\"\n#include <limits>\n#line 3 \"meta/setting.hpp\"\
    \n\n#ifndef KYOPRO_BASE_INT\n// \u57FA\u672C\u7B26\u53F7\u4ED8\u304D\u6574\u6570\
    \u578B\n#define KYOPRO_BASE_INT std::int64_t\n#endif\n\n#ifndef KYOPRO_BASE_UINT\n\
    // \u57FA\u672C\u7B26\u53F7\u306A\u3057\u6574\u6570\u578B\n#define KYOPRO_BASE_UINT\
    \ std::uint64_t\n#endif\n\n#ifndef KYOPRO_BASE_FLOAT\n// \u57FA\u672C\u6D6E\u52D5\
    \u5C0F\u6570\u70B9\u6570\u578B\n#define KYOPRO_BASE_FLOAT double\n#endif\n\n#ifndef\
    \ KYOPRO_DEFAULT_MOD\n// \u554F\u984C\u3067\u8A2D\u5B9A\u3055\u308C\u305Fmod\n\
    #define KYOPRO_DEFAULT_MOD (static_cast<KYOPRO_BASE_UINT>(998244353))\n#endif\n\
    \n#ifndef KYOPRO_DECIMAL_PRECISION\n// \u5C0F\u6570\u7CBE\u5EA6(\u6841)\n#define\
    \ KYOPRO_DECIMAL_PRECISION (static_cast<KYOPRO_BASE_UINT>(12))\n#endif\n\n#ifndef\
    \ KYOPRO_INF_DIV\n// \u7121\u9650\u5927\u3092\u8868\u3059\u6574\u6570\u304C\u6700\
    \u5927\u5024\u306E\u4F55\u5206\u306E\u4E00\u304B\u3092\u8868\u3059\n#define KYOPRO_INF_DIV\
    \ (static_cast<KYOPRO_BASE_UINT>(3))\n#endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n//\
    \ \u30C7\u30D5\u30A9\u30EB\u30C8\u306E\u30D0\u30C3\u30D5\u30A1\u30B5\u30A4\u30BA\
    \n#define KYOPRO_BUFFER_SIZE (static_cast<KYOPRO_BASE_UINT>(2048))\n#endif\n#line\
    \ 3 \"meta/trait.hpp\"\n#include <iterator>\n#include <tuple>\n#line 6 \"meta/trait.hpp\"\
    \n#include <utility>\n\nnamespace kpr {\n    namespace helper {\n        template<class\
    \ T>\n        struct is_integer_helper {\n            static constexpr bool value\
    \ = std::is_integral_v<T>;\n        };\n\n        #ifdef __SIZEOF_INT128__\n \
    \       template<>\n        struct is_integer_helper<__int128_t> {\n         \
    \   static constexpr bool value = true;\n        };\n        template<>\n    \
    \    struct is_integer_helper<__uint128_t> {\n            static constexpr bool\
    \ value = true;\n        };\n        #endif\n    } // namespace helper\n\n   \
    \ // \u578BT\u304C\u6574\u6570\u304B\u8ABF\u3079\u308B\n    template<class T>\n\
    \    struct is_integer {\n        static constexpr bool value = helper::is_integer_helper<std::remove_cv_t<T>>::value;\n\
    \    };\n    // \u578BT\u304C\u6574\u6570\u304B\u8ABF\u3079\u308B\n    template<class\
    \ T>\n    inline constexpr bool is_integer_v = is_integer<T>::value;\n\n    //\
    \ \u578BT\u304C\u7B26\u53F7\u4ED8\u304D\u6574\u6570\u304B\u8ABF\u3079\u308B\n\
    \    template<class T>\n    struct is_signed_integer {\n        static constexpr\
    \ bool value = is_integer_v<T> && std::is_signed_v<T>;\n    };\n    // \u578B\
    T\u304C\u7B26\u53F7\u4ED8\u304D\u6574\u6570\u304B\u8ABF\u3079\u308B\n    template<class\
    \ T>\n    inline constexpr bool is_signed_integer_v = is_signed_integer<T>::value;\n\
    \n    // \u578BT\u304C\u7B26\u53F7\u7121\u3057\u6574\u6570\u304B\u8ABF\u3079\u308B\
    \n    template<class T>\n    struct is_unsigned_integer {\n        static constexpr\
    \ bool value = is_integer_v<T> && !std::is_signed_v<T>;\n    };\n    // \u578B\
    T\u304C\u7B26\u53F7\u7121\u3057\u6574\u6570\u304B\u8ABF\u3079\u308B\n    template<class\
    \ T>\n    inline constexpr bool is_unsigned_integer_v = is_unsigned_integer<T>::value;\n\
    \n    namespace helper {\n        template<class T>\n        struct is_floating_point_helper\
    \ {\n            static constexpr bool value = std::is_floating_point_v<T>;\n\
    \        };\n\n        #ifdef __SIZEOF_FLOAT128__\n        template<>\n      \
    \  struct is_floating_point_helper<__float128> {\n            static constexpr\
    \ bool value = true;\n        };\n        #endif\n    } // namespace helper\n\n\
    \    // \u578BT\u304C\u6D6E\u52D5\u5C0F\u6570\u70B9\u6570\u304B\u8ABF\u3079\u308B\
    \n    template<class T>\n    struct is_floating_point {\n        static constexpr\
    \ bool value = helper::is_floating_point_helper<std::remove_cv_t<T>>::value;\n\
    \    };\n    // \u578BT\u304C\u6D6E\u52D5\u5C0F\u6570\u70B9\u6570\u304B\u8ABF\u3079\
    \u308B\n    template<class T>\n    inline constexpr bool is_floating_point_v =\
    \ is_floating_point<T>::value;\n\n    // \u578BT\u304C\u7B97\u8853\u578B\u304B\
    \u8ABF\u3079\u308B\n    template<class T>\n    struct is_arithmetic {\n      \
    \  static constexpr bool value = is_integer_v<T> || is_floating_point_v<T>;\n\
    \    };\n    // \u578BT\u304C\u7B97\u8853\u578B\u304B\u8ABF\u3079\u308B\n    template<class\
    \ T>\n    inline constexpr bool is_arithmetic_v = is_arithmetic<T>::value;\n\n\
    \    // \u578BT\u304C\u30B9\u30AB\u30E9\u30FC\u304B\u8ABF\u3079\u308B\n    template<class\
    \ T>\n    struct is_scalar {\n        static constexpr bool value = is_arithmetic_v<T>\
    \ || std::is_enum_v<T> || std::is_pointer_v<T> || std::is_member_pointer_v<T>\
    \ || std::is_null_pointer_v<T>;\n    };\n    // \u578BT\u304C\u30B9\u30AB\u30E9\
    \u30FC\u304B\u8ABF\u3079\u308B\n    template<class T>\n    inline constexpr bool\
    \ is_scalar_v = is_scalar<T>::value;\n\n    // size\u4EE5\u4E0A\u306E\u5927\u304D\
    \u3055\u3092\u6301\u3064\u6700\u5C0F\u306E\u7B26\u53F7\u4ED8\u304D\u6574\u6570\
    \u3092\u8ABF\u3079\u308B\n    template<std::size_t size>\n    struct int_least\
    \ {\n    private:\n        static constexpr auto get_type() noexcept {\n     \
    \       static_assert(size <= 128, \"The given integer type is too large\");\n\
    \            if constexpr (size <= 8) return std::int_least8_t{};\n          \
    \  else if constexpr (size <= 16) return std::int_least16_t{};\n            else\
    \ if constexpr (size <= 32) return std::int_least32_t{};\n            else if\
    \ constexpr (size <= 64) return std::int_least64_t{};\n            else return\
    \ __int128_t{};\n        }\n\n    public:\n        using type = decltype(get_type());\n\
    \    };\n    // size\u4EE5\u4E0A\u306E\u5927\u304D\u3055\u3092\u6301\u3064\u6700\
    \u5C0F\u306E\u7B26\u53F7\u4ED8\u304D\u6574\u6570\u3092\u8ABF\u3079\u308B\n   \
    \ template<std::size_t size>\n    using int_least_t = typename int_least<size>::type;\n\
    \n    // size\u4EE5\u4E0A\u306E\u5927\u304D\u3055\u3092\u6301\u3064\u6700\u5C0F\
    \u306E\u7B26\u53F7\u7121\u3057\u6574\u6570\u3092\u8ABF\u3079\u308B\n    template<std::size_t\
    \ size>\n    struct uint_least {\n    private:\n        static constexpr auto\
    \ get_type() noexcept {\n            static_assert(size <= 128, \"The give integer\
    \ type is too large\");\n            if constexpr (size <= 8) return std::uint_least8_t{};\n\
    \            else if constexpr (size <= 16) return std::uint_least16_t{};\n  \
    \          else if constexpr (size <= 32) return std::uint_least32_t{};\n    \
    \        else if constexpr (size <= 64) return std::uint_least64_t{};\n      \
    \      else return __uint128_t{};\n        }\n\n    public:\n        using type\
    \ = decltype(get_type());\n    };\n    // size\u4EE5\u4E0A\u306E\u5927\u304D\u3055\
    \u3092\u6301\u3064\u6700\u5C0F\u306E\u7B26\u53F7\u7121\u3057\u6574\u6570\u3092\
    \u8ABF\u3079\u308B\n    template<std::size_t size>\n    using uint_least_t = typename\
    \ uint_least<size>::type;\n\n    // T\u306E\u6B21\u306B\u5927\u304D\u3044\u6574\
    \u6570\u578B\u3092\u8ABF\u3079\u308B\n    template<class T>\n    struct next_integer\
    \ {\n        static_assert(is_integer_v<T>, \"The given type must be an integer\
    \ type\");\n        static_assert(sizeof(T) <= 8, \"The given integer type is\
    \ too large\");\n        using type = std::conditional_t<std::is_signed_v<T>,\
    \ int_least_t<sizeof(T) * 16>, uint_least_t<sizeof(T) * 16>>;\n    };\n    //\
    \ T\u306E\u6B21\u306B\u5927\u304D\u3044\u6574\u6570\u578B\u3092\u8ABF\u3079\u308B\
    \n    template<class T>\n    using next_integer_t = typename next_integer<T>::type;\n\
    \n    // T\u306E\u6B21\u306B\u5C0F\u3055\u3044\u6574\u6570\u578B\u3092\u8ABF\u3079\
    \u308B\n    template<class T>\n    struct prev_integer {\n        static_assert(is_integer_v<T>,\
    \ \"The given type must be an integer type\");\n        static_assert(sizeof(T)\
    \ >= 2, \"The given integer type is too large\");\n        using type = std::conditional_t<std::is_signed_v<T>,\
    \ int_least_t<sizeof(T) * 4>, uint_least_t<sizeof(T) * 4>>;\n    };\n    // T\u306E\
    \u6B21\u306B\u5C0F\u3055\u3044\u6574\u6570\u578B\u3092\u8ABF\u3079\u308B\n   \
    \ template<class T>\n    using prev_integer_t = typename prev_integer<T>::type;\n\
    \n    // \u578BT\u304C\u30A4\u30C6\u30EC\u30FC\u30BF\u304B\u8ABF\u3079\u308B\n\
    \    template<class T, class = void>\n    struct is_iterator {\n        static\
    \ constexpr bool value = false;\n    };\n    template<class T>\n    struct is_iterator<T,\
    \ std::void_t<typename std::iterator_traits<T>::iterator_category>> {\n      \
    \  static constexpr bool value = true;\n    };\n    // \u578BT\u304C\u30A4\u30C6\
    \u30EC\u30FC\u30BF\u304B\u8ABF\u3079\u308B\n    template<class T>\n    inline\
    \ constexpr bool is_iterator_v = is_iterator<T>::value;\n\n    // \u578BT\u304C\
    Range\u304B\u8ABF\u3079\u308B\n    template<class T, class = void>\n    struct\
    \ is_range {\n        static constexpr bool value = false;\n    };\n    template<class\
    \ T>\n    struct is_range<T, std::void_t<decltype(std::begin(std::declval<std::add_lvalue_reference_t<T>>()),\
    \ std::end(std::declval<std::add_lvalue_reference_t<T>>()))>> {\n        static\
    \ constexpr bool value = true;\n    };\n     // \u578BT\u304CRange\u304B\u8ABF\
    \u3079\u308B\n    template<class T>\n    inline constexpr bool is_range_v = is_range<T>::value;\n\
    \n    // Range\u578BT\u304B\u3089\u30A4\u30C6\u30EC\u30FC\u30BF\u306E\u578B\u3092\
    \u8ABF\u3079\u308B\n    template<class T>\n    struct range_iterator {\n     \
    \   using type = std::decay_t<decltype(std::begin(std::declval<T>()))>;\n    };\n\
    \    // Range\u578BT\u304B\u3089\u30A4\u30C6\u30EC\u30FC\u30BF\u306E\u578B\u3092\
    \u8ABF\u3079\u308B\n    template<class T>\n    using range_iterator_t = typename\
    \ range_iterator<T>::type;\n\n    // Range\u578BT\u304B\u3089\u8AAD\u307F\u53D6\
    \u308A\u5C02\u7528\u30A4\u30C6\u30EC\u30FC\u30BF\u306E\u578B\u3092\u8ABF\u3079\
    \u308B\n    template<class T>\n    struct range_const_iterator {\n        using\
    \ type = std::decay_t<decltype(std::cbegin(std::declval<T>()))>;\n    };\n   \
    \ // Range\u578BT\u304B\u3089\u8AAD\u307F\u53D6\u308A\u5C02\u7528\u30A4\u30C6\u30EC\
    \u30FC\u30BF\u306E\u578B\u3092\u8ABF\u3079\u308B\n    template<class T>\n    using\
    \ range_const_iterator_t = typename range_iterator<T>::type;\n\n    // Range\u578B\
    T\u304B\u3089\u8981\u7D20\u306E\u578B\u3092\u8ABF\u3079\u308B\n    template<class\
    \ T>\n    struct range_value {\n        using type = std::decay_t<decltype(*std::begin(std::declval<T>()))>;\n\
    \    };\n    // Range\u578BT\u304B\u3089\u8981\u7D20\u306E\u578B\u3092\u8ABF\u3079\
    \u308B\n    template<class T>\n    using range_value_t = typename range_value<T>::type;\n\
    } // namespace kpr\n#line 6 \"algorithm/bit.hpp\"\n\nnamespace kpr {\n    // \u7ACB\
    \u3063\u3066\u3044\u308Bbit\u306E\u500B\u6570\u3092\u8FD4\u3059\n    [[maybe_unused]]\
    \ inline constexpr struct {\n        template<class T>\n        constexpr KYOPRO_BASE_INT\
    \ operator ()(T x) const noexcept {\n            static_assert(is_integer_v<T>,\
    \ \"The argument must be an integer\");\n            constexpr auto digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;\n\
    \            static_assert(digits <= std::numeric_limits<unsigned long long>::digits,\
    \ \"The integer type of the argument is too large\");\n            if constexpr\
    \ (digits <= std::numeric_limits<unsigned int>::digits) return __builtin_popcount(x);\n\
    \            else if constexpr (digits <= std::numeric_limits<unsigned long>::digits)\
    \ return __builtin_popcountl(x);\n            else return __builtin_popcountll(x);\n\
    \        }\n    } pop_count;\n\n    [[maybe_unused]] inline constexpr struct {\n\
    \        template<class T>\n        constexpr KYOPRO_BASE_INT operator ()(T x)\
    \ const noexcept {\n            static_assert(is_integer_v<T>, \"The argument\
    \ must be an integer\");\n            constexpr auto digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;\n\
    \            static_assert(digits <= std::numeric_limits<unsigned long long>::digits,\
    \ \"The integer type of the argument is too large\");\n            if (x == 0)\
    \ return 0;\n            if constexpr (digits <= std::numeric_limits<unsigned\
    \ int>::digits) return __builtin_clz(x) + digits - std::numeric_limits<unsigned\
    \ int>::digits;\n            else if constexpr (digits <= std::numeric_limits<unsigned\
    \ long>::digits) return __builtin_clzl(x) + digits - std::numeric_limits<unsigned\
    \ long>::digits;\n            else return __builtin_clzll(x) + digits - std::numeric_limits<unsigned\
    \ long long>::digits;\n        }\n    } lzero_count;\n\n    [[maybe_unused]] inline\
    \ constexpr struct {\n        template<class T>\n        constexpr KYOPRO_BASE_INT\
    \ operator ()(T x) const noexcept {\n            static_assert(is_integer_v<T>,\
    \ \"The argument must be an integer\");\n            constexpr auto digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;\n\
    \            static_assert(digits <= std::numeric_limits<unsigned long long>::digits,\
    \ \"The integer type of the argument is too large\");\n            if constexpr\
    \ (digits <= std::numeric_limits<unsigned int>::digits) return __builtin_ctz(x);\n\
    \            else if constexpr (digits <= std::numeric_limits<unsigned long>::digits)\
    \ return __builtin_ctzl(x);\n            else return __builtin_ctzll(x);\n   \
    \     }\n    } rzero_count;\n\n    [[maybe_unused]] inline constexpr struct {\n\
    \        template<class T>\n        constexpr KYOPRO_BASE_INT operator ()(T x)\
    \ const noexcept {\n            static_assert(is_integer_v<T>, \"The argument\
    \ must be an integer\");\n            constexpr auto digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;\n\
    \            static_assert(digits <= std::numeric_limits<unsigned long long>::digits,\
    \ \"The integer type of the argument is too large\");\n            if (x == 0)\
    \ return 0;\n            if constexpr (digits <= std::numeric_limits<unsigned\
    \ int>::digits) return std::numeric_limits<unsigned int>::digits - __builtin_clz(x);\n\
    \            else if constexpr (digits <= std::numeric_limits<unsigned long>::digits)\
    \ return std::numeric_limits<unsigned long>::digits - __builtin_clzl(x);\n   \
    \         else return std::numeric_limits<unsigned long long>::digits - __builtin_clzll(x);\n\
    \        }\n    } bit_len;\n\n    [[maybe_unused]] inline constexpr struct {\n\
    \        template<class T>\n        constexpr KYOPRO_BASE_INT operator ()(T x)\
    \ const noexcept {\n            return bit_len(x >> static_cast<T>(1));\n    \
    \    }\n    } floor_bit;\n\n    [[maybe_unused]] inline constexpr struct {\n \
    \       template<class T>\n        constexpr KYOPRO_BASE_INT operator ()(T x)\
    \ const noexcept {\n            if (x == 0) return 0;\n            return bit_len(x\
    \ - static_cast<T>(1));\n        }\n    } ceil_bit;\n} // namespace kpr\n#line\
    \ 3 \"algorithm/Hash.hpp\"\n#include <functional>\n#line 7 \"meta/tuple_like.hpp\"\
    \n\nnamespace kpr {\n    namespace helper {\n        struct CastableToAny {\n\
    \            template<class T>\n            operator T() const noexcept;\n   \
    \     };\n\n        template<class T, std::size_t... idx, std::void_t<decltype(T{((void)idx,\
    \ CastableToAny{})...})>* = nullptr>\n        constexpr bool is_aggregate_initializable(std::index_sequence<idx...>,\
    \ bool) noexcept {\n            return true;\n        }\n        template<class\
    \ T, std::size_t... idx>\n        constexpr bool is_aggregate_initializable(std::index_sequence<idx...>,\
    \ char) noexcept {\n            return false;\n        }\n\n        template<class\
    \ T, std::size_t n = sizeof(T) * 8, std::enable_if_t<is_aggregate_initializable<T>(std::make_index_sequence<n>(),\
    \ false)>* = nullptr>\n        constexpr std::size_t aggregate_size() {\n    \
    \        return n;\n        }\n        template<class T, std::size_t n = sizeof(T)\
    \ * 8, std::enable_if_t<!is_aggregate_initializable<T>(std::make_index_sequence<n>(),\
    \ false)>* = nullptr>\n        constexpr std::size_t aggregate_size() {\n    \
    \        return aggregate_size<T, n - 1>();\n        }\n    } // namespace helper\n\
    \n    // tuple_like\u306A\u578BT\u306E\u5927\u304D\u3055\u3092\u8ABF\u3079\u308B\
    \n    template<class T, class = void>\n    struct tuple_like_size {\n        static_assert(std::is_aggregate_v<T>,\
    \ \"T must be tuple_like\");\n        static constexpr std::size_t value = helper::aggregate_size<T>();\n\
    \    };\n\n    template<class T>\n    struct tuple_like_size<T, std::void_t<decltype(std::tuple_size<T>::value)>>\
    \ {\n        static constexpr std::size_t value = std::tuple_size_v<T>;\n    };\n\
    \n    // tuple_like\u306A\u578BT\u306E\u5927\u304D\u3055\u3092\u8ABF\u3079\u308B\
    \n    template<class T>\n    inline constexpr std::size_t tuple_like_size_v =\
    \ tuple_like_size<T>::value;\n\n\n    // \u578BT\u304Ctuple_like\u304B\u8ABF\u3079\
    \u308B\n    template<class, class = void>\n    struct is_tuple_like {\n      \
    \  static constexpr bool value = false;\n    };\n\n    template<class T>\n   \
    \ struct is_tuple_like<T, std::enable_if_t<std::is_aggregate_v<T>>> {\n      \
    \  static constexpr bool value = true;\n    };\n\n    template<class T>\n    struct\
    \ is_tuple_like<T, std::void_t<decltype(std::tuple_size<T>::value)>> {\n     \
    \   static constexpr bool value = true;\n    };\n\n    // \u578BT\u304Ctuple_like\u304B\
    \u8ABF\u3079\u308B\n    template<class T>\n    inline constexpr bool is_tuple_like_v\
    \ = is_tuple_like<T>::value;\n\n\n    // tuple-like\u306A\u30AA\u30D6\u30B8\u30A7\
    \u30AF\u30C8\u306Eidx(0 <= idx < 8)\u756A\u76EE\u3092\u6C42\u3081\u308B\u95A2\u6570\
    \u30AF\u30E9\u30B9\n    template<class T, class = void>\n    struct GetFunction\
    \ {\n        static_assert(is_tuple_like_v<T>, \"T is not gettable\");\n     \
    \   template<std::size_t idx>\n        static constexpr decltype(auto) get(T&&\
    \ tuple_like) {\n            return std::get<idx>(std::forward<T>(tuple_like));\n\
    \        }\n    };\n\n    #define DEFINE_GET(n, ...)                         \
    \                    \\\n    template<class T>                               \
    \                       \\\n    struct GetFunction<T, std::enable_if_t<tuple_like_size_v<T>\
    \ == n>> {   \\\n        template<std::size_t idx, class U>                  \
    \               \\\n        static constexpr decltype(auto) get(U&& aggregate)\
    \ noexcept { \\\n            auto&& [__VA_ARGS__] = std::forward<U>(aggregate);\
    \             \\\n            return std::get<idx>(std::forward_as_tuple(__VA_ARGS__));\
    \      \\\n        }                                                         \
    \         \\\n    };\n\n    DEFINE_GET(1, a)\n    DEFINE_GET(2, a, b)\n    DEFINE_GET(3,\
    \ a, b, c)\n    DEFINE_GET(4, a, b, c, d)\n    DEFINE_GET(5, a, b, c, d, e)\n\
    \    DEFINE_GET(6, a, b, c, d, e, f)\n    DEFINE_GET(7, a, b, c, d, e, f, g)\n\
    \    DEFINE_GET(8, a, b, c, d, e, f, g, h)\n\n    #undef DEFINE_GET\n\n    namespace\
    \ helper {\n        template<std::size_t idx>\n        struct GetHelper {\n  \
    \          template<class T>\n            constexpr decltype(auto) operator ()(T&&\
    \ tuple_like) const noexcept {\n                return GetFunction<std::decay_t<T>>::template\
    \ get<idx>(std::forward<T>(tuple_like));\n            }\n        };\n    }\n\n\
    \    // tuple-like\u306A\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u306Eidx(0 <= idx\
    \ < 8)\u756A\u76EE\u3092\u6C42\u3081\u308B\n    template<std::size_t idx>\n  \
    \  inline constexpr helper::GetHelper<idx> get;\n\n\n    // tuple-like\u306A\u578B\
    T\u306Eidx(0 <= idx < 8)\u756A\u76EE\u306E\u8981\u7D20\u306E\u578B\u3092\u8ABF\
    \u3079\u308B\n    template<std::size_t idx, class T>\n    struct tuple_like_element\
    \ {\n        using type = decltype(get<idx>(std::declval<T>()));\n    };\n\n \
    \   // tuple-like\u306A\u578BT\u306Eidx(0 <= idx < 8)\u756A\u76EE\u306E\u8981\u7D20\
    \u306E\u578B\u3092\u8ABF\u3079\u308B\n    template<std::size_t idx, class T>\n\
    \    using tuple_like_element_t = typename tuple_like_element<idx, T>::type;\n\
    } // namespace kpr\n#line 9 \"algorithm/Hash.hpp\"\n\nnamespace kpr {\n    //\
    \ \u30CF\u30C3\u30B7\u30E5(tuple_like, range\u5BFE\u5FDC)\n    template<class,\
    \ class = void>\n    struct Hash;\n\n    template<class T>\n    struct Hash<T,\
    \ std::enable_if_t<std::is_scalar_v<T>>> {\n        using value_type = T;\n\n\
    \        constexpr std::size_t operator ()(T a) const noexcept {\n           \
    \ return std::hash<T>{}(a);\n        }\n    };\n\n    template<class T>\n    struct\
    \ Hash<T, std::enable_if_t<is_tuple_like_v<T> && !is_range_v<T>>> {\n        using\
    \ value_type = T;\n\n        template<std::size_t i = 0>\n        constexpr std::size_t\
    \ operator ()(const T& a) const noexcept {\n            if constexpr (i == tuple_like_size_v<T>)\
    \ return tuple_like_size_v<T>;\n            else {\n                std::size_t\
    \ seed = operator()<i + 1>(a);\n                return seed ^ (Hash<tuple_like_element_t<i,\
    \ T>>{}(get<i>(a)) + 0x9e3779b97f4a7c15LU + (seed << 12) + (seed >> 4));\n   \
    \         }\n        }\n    };\n\n    template<class T>\n    struct Hash<T, std::enable_if_t<is_range_v<T>>>:\
    \ Hash<range_value_t<T>> {\n        using value_type = T;\n\n        constexpr\
    \ std::size_t operator ()(const T& a) const {\n            std::size_t seed =\
    \ std::size(a);\n            for (auto&& i: a) seed ^= Hash<range_value_t<T>>{}(i)\
    \ + 0x9e3779b97f4a7c15LU + (seed << 12) + (seed >> 4);\n            return seed;\n\
    \        }\n    };\n} // namespace kpr\n#line 3 \"math/power.hpp\"\n\nnamespace\
    \ kpr {\n    [[maybe_unused]] inline constexpr struct {\n        template<class\
    \ T>\n        constexpr T operator ()(T a, std::uint_fast64_t n, T init = 1) const\
    \ noexcept {\n            while (n > 0) {\n                if (n & 1) init *=\
    \ a;\n                a *= a;\n                n >>= 1;\n            }\n     \
    \       return init;\n        }\n    } power;\n} // namespace kpr\n#line 5 \"\
    meta/constant.hpp\"\n\nnamespace kpr {\n    // \u554F\u984C\u3067\u8A2D\u5B9A\u3055\
    \u308C\u305Fmod\n    template<class T>\n    inline constexpr T MOD = KYOPRO_DEFAULT_MOD;\n\
    \    // \u554F\u984C\u3067\u8A2D\u5B9A\u3055\u308C\u305Fmod\n    inline constexpr\
    \ KYOPRO_BASE_INT mod = MOD<KYOPRO_BASE_INT>;\n\n    // \u7121\u9650\u5927\u3092\
    \u8868\u3059\u6574\u6570\n    template<class T>\n    inline constexpr T INF =\
    \ std::numeric_limits<T>::max() / KYOPRO_INF_DIV;\n    // \u7121\u9650\u5927\u3092\
    \u8868\u3059\u6574\u6570\n    inline constexpr KYOPRO_BASE_INT inf = INF<KYOPRO_BASE_INT>;\n\
    \n    // \u8A31\u5BB9\u3055\u308C\u308B\u5C0F\u6570\u8AA4\u5DEE\n    template<class\
    \ T, KYOPRO_BASE_UINT decimal_precision = KYOPRO_DECIMAL_PRECISION>\n    inline\
    \ constexpr KYOPRO_BASE_FLOAT EPS = static_cast<T>(1) / power(10ULL, decimal_precision);\n\
    \    // \u8A31\u5BB9\u3055\u308C\u308B\u5C0F\u6570\u8AA4\u5DEE\n    inline constexpr\
    \ KYOPRO_BASE_FLOAT eps = EPS<KYOPRO_BASE_FLOAT>;\n\n    // \u5186\u5468\u7387\
    \n    template<class T>\n    inline constexpr T PI = 3.14159265358979323846;\n\
    \    // \u5186\u5468\u7387\n    inline constexpr KYOPRO_BASE_FLOAT pi = PI<KYOPRO_BASE_FLOAT>;\n\
    } // namespace kpr\n#line 6 \"math/Montgomery.hpp\"\n\nnamespace kpr {\n    template<class\
    \ T>\n    struct Montgomery {\n        static_assert(is_unsigned_integer_v<T>,\
    \ \"The given type must be an unsigned integer type\");\n\n        using value_type\
    \ = T;\n\n        T mod;\n\n    private:\n        using larger_type = next_integer_t<T>;\n\
    \n        T r, n2;\n\n    public:\n        constexpr void set_mod(T mod) noexcept\
    \ {\n            this->mod = mod;\n            n2 = -static_cast<larger_type>(mod)\
    \ % mod;\n            T t = 0;\n            r = 0;\n            for (int i = 0;\
    \ i < std::numeric_limits<T>::digits; ++i) {\n                if (!(t & 1)) {\n\
    \                    t += mod;\n                    r += static_cast<T>(1) <<\
    \ static_cast<T>(i);\n                }\n                t >>= 1;\n          \
    \  }\n        }\n\n        constexpr KYOPRO_BASE_INT get_mod() const noexcept\
    \ {\n            return mod;\n        }\n\n        Montgomery() noexcept = default;\n\
    \        Montgomery(T mod) noexcept {\n            set_mod(mod);\n        }\n\n\
    \        constexpr T transform(T x) const noexcept {\n            return reduce(static_cast<larger_type>(x)\
    \ * n2);\n        }\n\n        constexpr T inverse_transform(T x) const noexcept\
    \ {\n            T y = reduce(x);\n            return y >= mod ? y - mod : y;\n\
    \        }\n\n        constexpr T reduce(larger_type x) const noexcept {\n   \
    \         return (x + static_cast<larger_type>(static_cast<T>(x) * r) * mod) >>\
    \ std::numeric_limits<T>::digits;\n        }\n    };\n} // namespace kpr\n#line\
    \ 11 \"math/DynamicModInt.hpp\"\n\nnamespace kpr {\n    template<class T, std::size_t\
    \ kind = 0, bool = false>\n    struct DynamicModInt {\n        static_assert(std::is_unsigned_v<T>,\
    \ \"The given type must be an unsigned integer type\");\n\n        using value_type\
    \ = T;\n\n    private:\n        using larger_type = next_integer_t<T>;\n\n   \
    \     inline static Montgomery<T> montgomery;\n\n    public:\n        T value;\n\
    \n        static constexpr KYOPRO_BASE_INT get_kind() noexcept {\n           \
    \ return kind;\n        }\n\n        static void set_mod(T mod) noexcept {\n \
    \           montgomery.set_mod(mod);\n        }\n\n        static KYOPRO_BASE_INT\
    \ get_mod() noexcept {\n            return montgomery.mod;\n        }\n\n    \
    \    KYOPRO_BASE_INT get_val() noexcept {\n            return montgomery.inverse_transform(value);\n\
    \        }\n\n        DynamicModInt() noexcept = default;\n        DynamicModInt(T\
    \ value) noexcept: value(montgomery.transform(value % montgomery.mod + montgomery.mod))\
    \ {}\n\n        template<class U>\n        explicit operator U() const noexcept\
    \ {\n            return montgomery.inverse_transform(value);\n        }\n\n  \
    \      static DynamicModInt raw(T value) noexcept {\n            DynamicModInt\
    \ res;\n            res.value = montgomery.transform(value);\n            return\
    \ res;\n        }\n\n        DynamicModInt power(std::uint_fast64_t n) const noexcept\
    \ {\n            DynamicModInt res = 1, a = *this;\n            while (n > 0)\
    \ {\n                if (n & 1) res = res * a;\n                a = a * a;\n \
    \               n >>= 1;\n            }\n            return res;\n        }\n\n\
    \        DynamicModInt inverse() const noexcept {\n            return power(montgomery.mod\
    \ - 2);\n        }\n\n        DynamicModInt operator +() const noexcept {\n  \
    \          return *this;\n        }\n\n        DynamicModInt operator -() const\
    \ noexcept {\n            return value == 0 ? 0 : montgomery.mod - value;\n  \
    \      }\n\n        DynamicModInt& operator ++() noexcept {\n            *this\
    \ += DynamicModInt::raw(1);\n            return *this;\n        }\n\n        DynamicModInt\
    \ operator ++(int) noexcept {\n            DynamicModInt before = *this;\n   \
    \         ++*this;\n            return before;\n        }\n\n        DynamicModInt&\
    \ operator --() noexcept {\n            *this -= DynamicModInt::raw(1);\n    \
    \        return *this;\n        }\n\n        DynamicModInt operator --(int) noexcept\
    \ {\n            DynamicModInt before = *this;\n            --*this;\n       \
    \     return before;\n        }\n\n        DynamicModInt& operator +=(DynamicModInt\
    \ rhs) noexcept {\n            if ((value += rhs.value - (montgomery.mod << 1))\
    \ > std::numeric_limits<std::make_signed_t<T>>::max()) value += montgomery.mod\
    \ << 1;\n            return *this;\n        }\n\n        DynamicModInt& operator\
    \ -=(DynamicModInt rhs) noexcept {\n            if ((value -= rhs.value) > std::numeric_limits<std::make_signed_t<T>>::max())\
    \ value += montgomery.mod << 1;\n            return *this;\n        }\n\n    \
    \    DynamicModInt& operator *=(DynamicModInt rhs) noexcept {\n            value\
    \ = montgomery.reduce(static_cast<larger_type>(value) * rhs.value);\n        \
    \    return *this;\n        }\n\n        DynamicModInt& operator /=(DynamicModInt\
    \ rhs) noexcept {\n            value = montgomery.reduce(static_cast<larger_type>(value)\
    \ * rhs.inverse().value);\n            return *this;\n        }\n\n        friend\
    \ DynamicModInt operator +(DynamicModInt lhs, DynamicModInt rhs) noexcept {\n\
    \            return lhs += rhs;\n        }\n\n        friend DynamicModInt operator\
    \ -(DynamicModInt lhs, DynamicModInt rhs) noexcept {\n            return lhs -=\
    \ rhs;\n        }\n\n        friend DynamicModInt operator *(DynamicModInt lhs,\
    \ DynamicModInt rhs) noexcept {\n            return lhs *= rhs;\n        }\n\n\
    \        friend DynamicModInt operator /(DynamicModInt lhs, DynamicModInt rhs)\
    \ noexcept {\n            return lhs /= rhs;\n        }\n\n        friend bool\
    \ operator ==(DynamicModInt lhs, DynamicModInt rhs) noexcept {\n            return\
    \ lhs.value == rhs.value;\n        }\n\n        friend bool operator !=(DynamicModInt\
    \ lhs, DynamicModInt rhs) noexcept {\n            return lhs.value != rhs.value;\n\
    \        }\n\n        template<class Scanner>\n        void scan(Scanner& scanner)\
    \ {\n            std::int_fast64_t value;\n            scanner.scan(value);\n\
    \            value = montgomery.transform(value % montgomery.mod + montgomery.mod);\n\
    \        }\n\n        template<class Printer>\n        void print(Printer& printer)\
    \ const {\n            printer.print(montgomery.inverse_transform(value));\n \
    \       }\n    };\n\n    template<class T, std::size_t kind>\n    struct Hash<DynamicModInt<T,\
    \ kind>> {\n        using value_type = DynamicModInt<T, kind>;\n\n        std::size_t\
    \ operator ()(DynamicModInt<T, kind> a) const noexcept {\n            return static_cast<std::size_t>(a);\n\
    \        }\n    };\n} // namespace kpr\n#line 8 \"math/is_prime.hpp\"\n\nnamespace\
    \ kpr {\n    [[maybe_unused]] inline constexpr struct {\n        template<class\
    \ T>\n        constexpr bool operator ()(T x) const {\n            using U = std::make_unsigned_t<T>;\n\
    \            using dmint = DynamicModInt<U, 0, true>;\n            U n = x;\n\
    \            if (n <= 1) return false;\n            if (!(n & 1)) return n ==\
    \ 2;\n            dmint::set_mod(n);\n            std::uint_fast64_t d = (n -\
    \ 1) >> rzero_count(n - 1);\n            dmint one = 1, minus_one = n - 1;\n \
    \           auto ng = [&](std::uint_fast64_t a) noexcept {\n                auto\
    \ y = dmint(a).power(d);\n                std::uint_fast64_t t = d;\n        \
    \        while (y != one and y != minus_one and t != n - 1) y *= y, t <<= 1;\n\
    \                if (y != minus_one and !(t & 1)) return true;\n             \
    \   return false;\n            };\n            if constexpr (std::numeric_limits<U>::digits\
    \ <= 32) {\n                for (auto i: (std::uint_fast64_t[3]){2, 7, 61}) {\n\
    \                    if (n <= i) return true;\n                    if (ng(i))\
    \ return false;\n                }\n            } else if (n < (static_cast<U>(1)\
    \ << 32)) {\n                for (auto i: (std::uint_fast64_t[3]){2, 7, 61}) {\n\
    \                    if (n <= i) return true;\n                    if (ng(i))\
    \ return false;\n                }\n            } else {\n                for\
    \ (auto i: (std::uint_fast64_t[7]){2, 325, 9375, 28178, 450775, 9780504, 1795265022})\
    \ {\n                    if (n <= i) return true;\n                    if (ng(i))\
    \ return false;\n                }\n            }\n            return true;\n\
    \        }\n    } is_prime;\n} // namespace kpr\n#line 12 \"math/factorize.hpp\"\
    \n\nnamespace kpr {\n    // \u7D20\u56E0\u6570\u5206\u89E3\n    [[maybe_unused]]\
    \ inline constexpr struct {\n        template<class T>\n        constexpr T operator\
    \ ()(T p, std::uint_fast64_t c) const {\n            using U = std::make_unsigned_t<T>;\n\
    \            using dmint = DynamicModInt<U, 0, true>;\n            U n = p;\n\
    \            dmint::set_mod(n);\n            dmint cc = c;\n            auto f\
    \ = [=](dmint x) noexcept {\n                return x * x + cc;\n            };\n\
    \            auto x = dmint::raw(1), y = dmint::raw(2), z = dmint::raw(1), q =\
    \ dmint::raw(1);\n            U g = 1;\n            const int m = 1 << (floor_bit(n)\
    \ / 5);\n            for (int r = 1; g == 1; r <<= 1) {\n                x = y;\n\
    \                for (int i = 0; i < r; ++i) y = f(y);\n                for (int\
    \ k = 0; k < r && g == 1; k += m) {\n                z = y;\n                int\
    \ min = std::min(m, r - k);\n                for (int i = 0; i < min; ++i) {\n\
    \                    y = f(y);\n                    q *= x - y;\n            \
    \    }\n                g = std::gcd(static_cast<U>(q), n);\n                }\n\
    \            }\n            if (g == n) {\n                do {\n            \
    \    z = f(z);\n                g = std::gcd(static_cast<U>(x - z), n);\n    \
    \            } while (g == 1);\n            }\n            return g;\n       \
    \ }\n    } pollard_rho;\n\n    [[maybe_unused]] inline constexpr struct {\n  \
    \      KYOPRO_BASE_UINT operator ()(std::uint_fast64_t n) const noexcept {\n \
    \           static std::mt19937_64 mt(std::random_device{}());\n            std::uniform_int_distribution<std::uint_fast64_t>\
    \ rnd(0, n - 1);\n            if (is_prime(n)) return n;\n            for (int\
    \ i = 0; i < 100; ++i) {\n                std::uint_fast64_t m = pollard_rho(n,\
    \ rnd(mt));\n                if (is_prime(m)) return m;\n                n = m;\n\
    \            }\n            return 1;\n        }\n    } find_factor;\n\n    [[maybe_unused]]\
    \ inline constexpr struct {\n        template<bool sorted = true, class Container\
    \ = std::vector<KYOPRO_BASE_INT>>\n        Container operator ()(std::uint_fast64_t\
    \ n) const {\n            Container res;\n            for (int p = 2; p < 100\
    \ && p * p <= n; ++p) {\n                while (n % p == 0) {\n              \
    \  n /= p;\n                res.emplace_back(p);\n                }\n        \
    \    }\n            while (n > 1) {\n                std::uint_fast64_t p = find_factor(n);\n\
    \                do {\n                n /= p;\n                res.emplace_back(p);\n\
    \                } while (n % p == 0);\n            }\n            if constexpr\
    \ (sorted) std::sort(res.begin(), res.end());\n            return res;\n     \
    \   }\n    } factorize;\n} // namespace kpr\n"
  code: "#pragma once\n#include <algorithm>\n#include <cstddef>\n#include <cstdint>\n\
    #include <numeric>\n#include <random>\n#include <type_traits>\n#include \"../algorithm/bit.hpp\"\
    \n#include \"../meta/setting.hpp\"\n#include \"DynamicModInt.hpp\"\n#include \"\
    is_prime.hpp\"\n\nnamespace kpr {\n    // \u7D20\u56E0\u6570\u5206\u89E3\n   \
    \ [[maybe_unused]] inline constexpr struct {\n        template<class T>\n    \
    \    constexpr T operator ()(T p, std::uint_fast64_t c) const {\n            using\
    \ U = std::make_unsigned_t<T>;\n            using dmint = DynamicModInt<U, 0,\
    \ true>;\n            U n = p;\n            dmint::set_mod(n);\n            dmint\
    \ cc = c;\n            auto f = [=](dmint x) noexcept {\n                return\
    \ x * x + cc;\n            };\n            auto x = dmint::raw(1), y = dmint::raw(2),\
    \ z = dmint::raw(1), q = dmint::raw(1);\n            U g = 1;\n            const\
    \ int m = 1 << (floor_bit(n) / 5);\n            for (int r = 1; g == 1; r <<=\
    \ 1) {\n                x = y;\n                for (int i = 0; i < r; ++i) y\
    \ = f(y);\n                for (int k = 0; k < r && g == 1; k += m) {\n      \
    \          z = y;\n                int min = std::min(m, r - k);\n           \
    \     for (int i = 0; i < min; ++i) {\n                    y = f(y);\n       \
    \             q *= x - y;\n                }\n                g = std::gcd(static_cast<U>(q),\
    \ n);\n                }\n            }\n            if (g == n) {\n         \
    \       do {\n                z = f(z);\n                g = std::gcd(static_cast<U>(x\
    \ - z), n);\n                } while (g == 1);\n            }\n            return\
    \ g;\n        }\n    } pollard_rho;\n\n    [[maybe_unused]] inline constexpr struct\
    \ {\n        KYOPRO_BASE_UINT operator ()(std::uint_fast64_t n) const noexcept\
    \ {\n            static std::mt19937_64 mt(std::random_device{}());\n        \
    \    std::uniform_int_distribution<std::uint_fast64_t> rnd(0, n - 1);\n      \
    \      if (is_prime(n)) return n;\n            for (int i = 0; i < 100; ++i) {\n\
    \                std::uint_fast64_t m = pollard_rho(n, rnd(mt));\n           \
    \     if (is_prime(m)) return m;\n                n = m;\n            }\n    \
    \        return 1;\n        }\n    } find_factor;\n\n    [[maybe_unused]] inline\
    \ constexpr struct {\n        template<bool sorted = true, class Container = std::vector<KYOPRO_BASE_INT>>\n\
    \        Container operator ()(std::uint_fast64_t n) const {\n            Container\
    \ res;\n            for (int p = 2; p < 100 && p * p <= n; ++p) {\n          \
    \      while (n % p == 0) {\n                n /= p;\n                res.emplace_back(p);\n\
    \                }\n            }\n            while (n > 1) {\n             \
    \   std::uint_fast64_t p = find_factor(n);\n                do {\n           \
    \     n /= p;\n                res.emplace_back(p);\n                } while (n\
    \ % p == 0);\n            }\n            if constexpr (sorted) std::sort(res.begin(),\
    \ res.end());\n            return res;\n        }\n    } factorize;\n} // namespace\
    \ kpr\n"
  dependsOn:
  - algorithm/bit.hpp
  - meta/setting.hpp
  - meta/trait.hpp
  - math/DynamicModInt.hpp
  - algorithm/Hash.hpp
  - meta/tuple_like.hpp
  - meta/constant.hpp
  - math/power.hpp
  - math/Montgomery.hpp
  - math/is_prime.hpp
  isVerificationFile: false
  path: math/factorize.hpp
  requiredBy:
  - all/all.hpp
  - math/math.hpp
  - all.hpp
  timestamp: '2023-02-10 23:05:45+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo/factorize.test.cpp
documentation_of: math/factorize.hpp
layout: document
redirect_from:
- /library/math/factorize.hpp
- /library/math/factorize.hpp.html
title: math/factorize.hpp
---
