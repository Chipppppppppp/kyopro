---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: algorithm/Hash.hpp
    title: algorithm/Hash.hpp
  - icon: ':warning:'
    path: algorithm/algorithm.hpp
    title: algorithm/algorithm.hpp
  - icon: ':x:'
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
  - icon: ':x:'
    path: function/monoid.hpp
    title: function/monoid.hpp
  - icon: ':warning:'
    path: math/Barrett.hpp
    title: math/Barrett.hpp
  - icon: ':x:'
    path: math/DynamicModInt.hpp
    title: math/DynamicModInt.hpp
  - icon: ':warning:'
    path: math/ModInt.hpp
    title: math/ModInt.hpp
  - icon: ':x:'
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
  - icon: ':x:'
    path: math/factorize.hpp
    title: math/factorize.hpp
  - icon: ':x:'
    path: math/is_prime.hpp
    title: math/is_prime.hpp
  - icon: ':warning:'
    path: math/math.hpp
    title: math/math.hpp
  - icon: ':warning:'
    path: math/mod.hpp
    title: math/mod.hpp
  - icon: ':x:'
    path: math/power.hpp
    title: math/power.hpp
  - icon: ':x:'
    path: meta/constant.hpp
    title: meta/constant.hpp
  - icon: ':warning:'
    path: meta/meta.hpp
    title: meta/meta.hpp
  - icon: ':x:'
    path: meta/setting.hpp
    title: meta/setting.hpp
  - icon: ':x:'
    path: meta/trait.hpp
    title: meta/trait.hpp
  - icon: ':x:'
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
  - icon: ':x:'
    path: structure/FenwickTree.hpp
    title: structure/FenwickTree.hpp
  - icon: ':x:'
    path: structure/UnionFind.hpp
    title: structure/UnionFind.hpp
  - icon: ':warning:'
    path: structure/structure.hpp
    title: structure/structure.hpp
  - icon: ':x:'
    path: system/in.hpp
    title: system/in.hpp
  - icon: ':x:'
    path: system/out.hpp
    title: system/out.hpp
  - icon: ':x:'
    path: system/system.hpp
    title: system/system.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algorithm/bit.hpp\"\n#include <limits>\n#include <type_traits>\n\
    #line 2 \"meta/setting.hpp\"\n#include <cstdint>\n\n#ifndef KYOPRO_BASE_INT\n\
    // \u57FA\u672C\u7B26\u53F7\u4ED8\u304D\u6574\u6570\u578B\n#define KYOPRO_BASE_INT\
    \ std::int64_t\n#endif\n\n#ifndef KYOPRO_BASE_UINT\n// \u57FA\u672C\u7B26\u53F7\
    \u306A\u3057\u6574\u6570\u578B\n#define KYOPRO_BASE_UINT std::uint64_t\n#endif\n\
    \n#ifndef KYOPRO_BASE_FLOAT\n// \u57FA\u672C\u6D6E\u52D5\u5C0F\u6570\u70B9\u6570\
    \u578B\n#define KYOPRO_BASE_FLOAT double\n#endif\n\n#ifndef KYOPRO_DEFAULT_MOD\n\
    // \u554F\u984C\u3067\u8A2D\u5B9A\u3055\u308C\u305Fmod\n#define KYOPRO_DEFAULT_MOD\
    \ (static_cast<KYOPRO_BASE_UINT>(998244353))\n#endif\n\n#ifndef KYOPRO_DECIMAL_PRECISION\n\
    // \u5C0F\u6570\u7CBE\u5EA6(\u6841)\n#define KYOPRO_DECIMAL_PRECISION (static_cast<KYOPRO_BASE_UINT>(12))\n\
    #endif\n\n#ifndef KYOPRO_INF_DIV\n// \u7121\u9650\u5927\u3092\u8868\u3059\u6574\
    \u6570\u304C\u6700\u5927\u5024\u306E\u4F55\u5206\u306E\u4E00\u304B\u3092\u8868\
    \u3059\n#define KYOPRO_INF_DIV (static_cast<KYOPRO_BASE_UINT>(3))\n#endif\n\n\
    #ifndef KYOPRO_BUFFER_SIZE\n// \u30C7\u30D5\u30A9\u30EB\u30C8\u306E\u30D0\u30C3\
    \u30D5\u30A1\u30B5\u30A4\u30BA\n#define KYOPRO_BUFFER_SIZE (static_cast<KYOPRO_BASE_UINT>(2048))\n\
    #endif\n#line 2 \"meta/trait.hpp\"\n#include <cstddef>\n#include <iterator>\n\
    #include <tuple>\n#line 6 \"meta/trait.hpp\"\n#include <utility>\n\nnamespace\
    \ kpr {\n    namespace helper {\n        template<class T>\n        struct is_integer_helper\
    \ {\n            static constexpr bool value = std::is_integral_v<T>;\n      \
    \  };\n\n        #ifdef __SIZEOF_INT128__\n        template<>\n        struct\
    \ is_integer_helper<__int128_t> {\n            static constexpr bool value = true;\n\
    \        };\n\n        template<>\n        struct is_integer_helper<__uint128_t>\
    \ {\n            static constexpr bool value = true;\n        };\n        #endif\n\
    \    } // namespace helper\n\n    // \u578BT\u304C\u6574\u6570\u304B\u8ABF\u3079\
    \u308B\n    template<class T>\n    struct is_integer {\n        static constexpr\
    \ bool value = helper::is_integer_helper<std::remove_cv_t<T>>::value;\n    };\n\
    \n    // \u578BT\u304C\u6574\u6570\u304B\u8ABF\u3079\u308B\n    template<class\
    \ T>\n    inline constexpr bool is_integer_v = is_integer<T>::value;\n\n\n   \
    \ // \u578BT\u304C\u7B26\u53F7\u4ED8\u304D\u6574\u6570\u304B\u8ABF\u3079\u308B\
    \n    template<class T>\n    struct is_signed_integer {\n        static constexpr\
    \ bool value = is_integer_v<T> && std::is_signed_v<T>;\n    };\n\n    // \u578B\
    T\u304C\u7B26\u53F7\u4ED8\u304D\u6574\u6570\u304B\u8ABF\u3079\u308B\n    template<class\
    \ T>\n    inline constexpr bool is_signed_integer_v = is_signed_integer<T>::value;\n\
    \n\n    // \u578BT\u304C\u7B26\u53F7\u7121\u3057\u6574\u6570\u304B\u8ABF\u3079\
    \u308B\n    template<class T>\n    struct is_unsigned_integer {\n        static\
    \ constexpr bool value = is_integer_v<T> && !std::is_signed_v<T>;\n    };\n\n\
    \    // \u578BT\u304C\u7B26\u53F7\u7121\u3057\u6574\u6570\u304B\u8ABF\u3079\u308B\
    \n    template<class T>\n    inline constexpr bool is_unsigned_integer_v = is_unsigned_integer<T>::value;\n\
    \n\n    namespace helper {\n        template<class T>\n        struct is_floating_point_helper\
    \ {\n            static constexpr bool value = std::is_floating_point_v<T>;\n\
    \        };\n\n        #ifdef __SIZEOF_FLOAT128__\n        template<>\n      \
    \  struct is_floating_point_helper<__float128> {\n            static constexpr\
    \ bool value = true;\n        };\n        #endif\n    } // namespace helper\n\n\
    \    // \u578BT\u304C\u6D6E\u52D5\u5C0F\u6570\u70B9\u6570\u304B\u8ABF\u3079\u308B\
    \n    template<class T>\n    struct is_floating_point {\n        static constexpr\
    \ bool value = helper::is_floating_point_helper<std::remove_cv_t<T>>::value;\n\
    \    };\n\n    // \u578BT\u304C\u6D6E\u52D5\u5C0F\u6570\u70B9\u6570\u304B\u8ABF\
    \u3079\u308B\n    template<class T>\n    inline constexpr bool is_floating_point_v\
    \ = is_floating_point<T>::value;\n\n\n    // \u578BT\u304C\u7B97\u8853\u578B\u304B\
    \u8ABF\u3079\u308B\n    template<class T>\n    struct is_arithmetic {\n      \
    \  static constexpr bool value = is_integer_v<T> || is_floating_point_v<T>;\n\
    \    };\n\n    // \u578BT\u304C\u7B97\u8853\u578B\u304B\u8ABF\u3079\u308B\n  \
    \  template<class T>\n    inline constexpr bool is_arithmetic_v = is_arithmetic<T>::value;\n\
    \n\n    // \u578BT\u304C\u30B9\u30AB\u30E9\u30FC\u304B\u8ABF\u3079\u308B\n   \
    \ template<class T>\n    struct is_scalar {\n        static constexpr bool value\
    \ = is_arithmetic_v<T> || std::is_enum_v<T> || std::is_pointer_v<T> || std::is_member_pointer_v<T>\
    \ || std::is_null_pointer_v<T>;\n    };\n\n    // \u578BT\u304C\u30B9\u30AB\u30E9\
    \u30FC\u304B\u8ABF\u3079\u308B\n    template<class T>\n    inline constexpr bool\
    \ is_scalar_v = is_scalar<T>::value;\n\n\n    // size\u4EE5\u4E0A\u306E\u5927\u304D\
    \u3055\u3092\u6301\u3064\u6700\u5C0F\u306E\u7B26\u53F7\u4ED8\u304D\u6574\u6570\
    \u3092\u8ABF\u3079\u308B\n    template<std::size_t size>\n    struct int_least\
    \ {\n    private:\n        static constexpr auto get_type() noexcept {\n     \
    \       static_assert(size <= 128, \"The given integer type is too large\");\n\
    \            if constexpr (size <= 8) return std::int_least8_t{};\n          \
    \  else if constexpr (size <= 16) return std::int_least16_t{};\n            else\
    \ if constexpr (size <= 32) return std::int_least32_t{};\n            else if\
    \ constexpr (size <= 64) return std::int_least64_t{};\n            else return\
    \ __int128_t{};\n        }\n\n    public:\n        using type = decltype(get_type());\n\
    \    };\n\n    // size\u4EE5\u4E0A\u306E\u5927\u304D\u3055\u3092\u6301\u3064\u6700\
    \u5C0F\u306E\u7B26\u53F7\u4ED8\u304D\u6574\u6570\u3092\u8ABF\u3079\u308B\n   \
    \ template<std::size_t size>\n    using int_least_t = typename int_least<size>::type;\n\
    \n\n    // size\u4EE5\u4E0A\u306E\u5927\u304D\u3055\u3092\u6301\u3064\u6700\u5C0F\
    \u306E\u7B26\u53F7\u7121\u3057\u6574\u6570\u3092\u8ABF\u3079\u308B\n    template<std::size_t\
    \ size>\n    struct uint_least {\n    private:\n        static constexpr auto\
    \ get_type() noexcept {\n            static_assert(size <= 128, \"The give integer\
    \ type is too large\");\n            if constexpr (size <= 8) return std::uint_least8_t{};\n\
    \            else if constexpr (size <= 16) return std::uint_least16_t{};\n  \
    \          else if constexpr (size <= 32) return std::uint_least32_t{};\n    \
    \        else if constexpr (size <= 64) return std::uint_least64_t{};\n      \
    \      else return __uint128_t{};\n        }\n\n    public:\n        using type\
    \ = decltype(get_type());\n    };\n\n    // size\u4EE5\u4E0A\u306E\u5927\u304D\
    \u3055\u3092\u6301\u3064\u6700\u5C0F\u306E\u7B26\u53F7\u7121\u3057\u6574\u6570\
    \u3092\u8ABF\u3079\u308B\n    template<std::size_t size>\n    using uint_least_t\
    \ = typename uint_least<size>::type;\n\n\n    // T\u306E\u6B21\u306B\u5927\u304D\
    \u3044\u6574\u6570\u578B\u3092\u8ABF\u3079\u308B\n    template<class T>\n    struct\
    \ next_integer {\n        static_assert(is_integer_v<T>, \"The given type must\
    \ be an integer type\");\n        static_assert(sizeof(T) <= 8, \"The given integer\
    \ type is too large\");\n        using type = std::conditional_t<std::is_signed_v<T>,\
    \ int_least_t<sizeof(T) * 16>, uint_least_t<sizeof(T) * 16>>;\n    };\n\n    //\
    \ T\u306E\u6B21\u306B\u5927\u304D\u3044\u6574\u6570\u578B\u3092\u8ABF\u3079\u308B\
    \n    template<class T>\n    using next_integer_t = typename next_integer<T>::type;\n\
    \n    // T\u306E\u6B21\u306B\u5C0F\u3055\u3044\u6574\u6570\u578B\u3092\u8ABF\u3079\
    \u308B\n    template<class T>\n    struct prev_integer {\n        static_assert(is_integer_v<T>,\
    \ \"The given type must be an integer type\");\n        static_assert(sizeof(T)\
    \ >= 2, \"The given integer type is too large\");\n        using type = std::conditional_t<std::is_signed_v<T>,\
    \ int_least_t<sizeof(T) * 4>, uint_least_t<sizeof(T) * 4>>;\n    };\n\n    //\
    \ T\u306E\u6B21\u306B\u5C0F\u3055\u3044\u6574\u6570\u578B\u3092\u8ABF\u3079\u308B\
    \n    template<class T>\n    using prev_integer_t = typename prev_integer<T>::type;\n\
    \n    // \u578BT\u304C\u30A4\u30C6\u30EC\u30FC\u30BF\u304B\u8ABF\u3079\u308B\n\
    \    template<class T, class = void>\n    struct is_iterator {\n        static\
    \ constexpr bool value = false;\n    };\n    template<class T>\n    struct is_iterator<T,\
    \ std::void_t<typename std::iterator_traits<T>::iterator_category>> {\n      \
    \  static constexpr bool value = true;\n    };\n\n    // \u578BT\u304C\u30A4\u30C6\
    \u30EC\u30FC\u30BF\u304B\u8ABF\u3079\u308B\n    template<class T>\n    inline\
    \ constexpr bool is_iterator_v = is_iterator<T>::value;\n\n\n    // \u578BT\u304C\
    Range\u304B\u8ABF\u3079\u308B\n    template<class T, class = void>\n    struct\
    \ is_range {\n        static constexpr bool value = false;\n    };\n    template<class\
    \ T>\n    struct is_range<T, std::void_t<decltype(std::begin(std::declval<std::add_lvalue_reference_t<T>>()),\
    \ std::end(std::declval<std::add_lvalue_reference_t<T>>()))>> {\n        static\
    \ constexpr bool value = true;\n    };\n\n     // \u578BT\u304CRange\u304B\u8ABF\
    \u3079\u308B\n    template<class T>\n    inline constexpr bool is_range_v = is_range<T>::value;\n\
    \n\n    // Range\u578BT\u304B\u3089\u30A4\u30C6\u30EC\u30FC\u30BF\u306E\u578B\u3092\
    \u8ABF\u3079\u308B\n    template<class T>\n    struct range_iterator {\n     \
    \   using type = std::decay_t<decltype(std::begin(std::declval<T>()))>;\n    };\n\
    \n    // Range\u578BT\u304B\u3089\u30A4\u30C6\u30EC\u30FC\u30BF\u306E\u578B\u3092\
    \u8ABF\u3079\u308B\n    template<class T>\n    using range_iterator_t = typename\
    \ range_iterator<T>::type;\n\n\n    // Range\u578BT\u304B\u3089\u8AAD\u307F\u53D6\
    \u308A\u5C02\u7528\u30A4\u30C6\u30EC\u30FC\u30BF\u306E\u578B\u3092\u8ABF\u3079\
    \u308B\n    template<class T>\n    struct range_const_iterator {\n        using\
    \ type = std::decay_t<decltype(std::cbegin(std::declval<T>()))>;\n    };\n\n \
    \   // Range\u578BT\u304B\u3089\u8AAD\u307F\u53D6\u308A\u5C02\u7528\u30A4\u30C6\
    \u30EC\u30FC\u30BF\u306E\u578B\u3092\u8ABF\u3079\u308B\n    template<class T>\n\
    \    using range_const_iterator_t = typename range_iterator<T>::type;\n\n\n  \
    \  // Range\u578BT\u304B\u3089\u8981\u7D20\u306E\u578B\u3092\u8ABF\u3079\u308B\
    \n    template<class T>\n    struct range_value {\n        using type = std::decay_t<decltype(*std::begin(std::declval<T>()))>;\n\
    \    };\n\n    // Range\u578BT\u304B\u3089\u8981\u7D20\u306E\u578B\u3092\u8ABF\
    \u3079\u308B\n    template<class T>\n    using range_value_t = typename range_value<T>::type;\n\
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
    \ struct is_tuple_like<T, std::void_t<decltype(tuple_like_size<T>::value)>> {\n\
    \        static constexpr bool value = true;\n    };\n\n    // \u578BT\u304Ctuple_like\u304B\
    \u8ABF\u3079\u308B\n    template<class T>\n    inline constexpr bool is_tuple_like_v\
    \ = is_tuple_like<T>::value;\n\n\n    // tuple-like\u306A\u30AA\u30D6\u30B8\u30A7\
    \u30AF\u30C8\u306Eidx(0 <= idx < 8)\u756A\u76EE\u3092\u6C42\u3081\u308B\u95A2\u6570\
    \u30AF\u30E9\u30B9\n    template<class T, class = void>\n    struct GetFunction\
    \ {\n        static_assert(std::is_aggregate_v<T>, \"T is not gettable\");\n \
    \       template<std::size_t idx>\n        static constexpr decltype(auto) get(T&&\
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
    \ function<idx>(std::forward<T>(tuple_like));\n            }\n        };\n   \
    \ }\n\n    // tuple-like\u306A\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u306Eidx(0\
    \ <= idx < 8)\u756A\u76EE\u3092\u6C42\u3081\u308B\n    template<std::size_t idx>\n\
    \    inline constexpr helper::GetHelper<idx> get;\n\n\n    // tuple-like\u306A\
    \u578BT\u306Eidx(0 <= idx < 8)\u756A\u76EE\u306E\u8981\u7D20\u306E\u578B\u3092\
    \u8ABF\u3079\u308B\n    template<std::size_t idx, class T>\n    struct tuple_like_element\
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
    \        }\n    };\n} // namespace kpr\n#line 2 \"function/compare.hpp\"\n\nnamespace\
    \ kpr {\n    // operator =\u3067\u6BD4\u8F03\n    struct Equal {\n        template<class\
    \ T>\n        constexpr bool operator()(const T& x, const T& y) const noexcept(noexcept(x\
    \ == y)) {\n            return x == y;\n        }\n    };\n\n    // operator !=\u3067\
    \u6BD4\u8F03\n    struct NotEqual {\n        template<class T>\n        constexpr\
    \ bool operator()(const T& x, const T& y) const noexcept(noexcept(x != y)) {\n\
    \            return x != y;\n        }\n    };\n\n    // operator <\u306E\u95A2\
    \u6570\u30AF\u30E9\u30B9\n    struct Less {\n        template<class T>\n     \
    \   constexpr bool operator()(const T& x, const T& y) const noexcept(noexcept(x\
    \ < y)) {\n            return x < y;\n        }\n    };\n\n    // operator <=\u306E\
    \u95A2\u6570\u30AF\u30E9\u30B9\n    struct LessEqual {\n        template<class\
    \ T>\n        constexpr bool operator()(const T& x, const T& y) const noexcept(noexcept(x\
    \ <= y)) {\n            return x <= y;\n        }\n    };\n\n    // operator >\u306E\
    \u95A2\u6570\u30AF\u30E9\u30B9\n    struct Greater {\n        template<class T>\n\
    \        constexpr bool operator()(const T& x, const T& y) const noexcept(noexcept(x\
    \ > y)) {\n            return x > y;\n        }\n    };\n\n    // operator >=\u306E\
    \u95A2\u6570\u30AF\u30E9\u30B9\n    struct GreaterEqual {\n        template<class\
    \ T>\n        constexpr bool operator()(const T& x, const T& y) const noexcept(noexcept(x\
    \ >= y)) {\n            return x >= y;\n        }\n    };\n} // namespace kpr\n\
    #line 3 \"math/power.hpp\"\n\nnamespace kpr {\n    [[maybe_unused]] inline constexpr\
    \ struct {\n        template<class T>\n        constexpr T operator ()(T a, std::uint_fast64_t\
    \ n, T init = 1) const noexcept {\n            while (n > 0) {\n             \
    \   if (n & 1) init *= a;\n                a *= a;\n                n >>= 1;\n\
    \            }\n            return init;\n        }\n    } power;\n} // namespace\
    \ kpr\n#line 5 \"meta/constant.hpp\"\n\nnamespace kpr {\n    // \u554F\u984C\u3067\
    \u8A2D\u5B9A\u3055\u308C\u305Fmod\n    template<class T>\n    inline constexpr\
    \ T MOD = KYOPRO_DEFAULT_MOD;\n\n    // \u554F\u984C\u3067\u8A2D\u5B9A\u3055\u308C\
    \u305Fmod\n    inline constexpr KYOPRO_BASE_INT mod = MOD<KYOPRO_BASE_INT>;\n\n\
    \n    // \u7121\u9650\u5927\u3092\u8868\u3059\u6574\u6570\n    template<class\
    \ T>\n    inline constexpr T INF = std::numeric_limits<T>::max() / KYOPRO_INF_DIV;\n\
    \n    // \u7121\u9650\u5927\u3092\u8868\u3059\u6574\u6570\n    inline constexpr\
    \ KYOPRO_BASE_INT inf = INF<KYOPRO_BASE_INT>;\n\n\n    // \u8A31\u5BB9\u3055\u308C\
    \u308B\u5C0F\u6570\u8AA4\u5DEE\n    template<class T, KYOPRO_BASE_UINT decimal_precision\
    \ = KYOPRO_DECIMAL_PRECISION>\n    inline constexpr KYOPRO_BASE_FLOAT EPS = static_cast<T>(1)\
    \ / power(10ULL, decimal_precision);\n\n    // \u8A31\u5BB9\u3055\u308C\u308B\u5C0F\
    \u6570\u8AA4\u5DEE\n    inline constexpr KYOPRO_BASE_FLOAT eps = EPS<KYOPRO_BASE_FLOAT>;\n\
    \n\n    // \u5186\u5468\u7387\n    template<class T>\n    inline constexpr T PI\
    \ = 3.14159265358979323846;\n\n    // \u5186\u5468\u7387\n    inline constexpr\
    \ KYOPRO_BASE_FLOAT pi = PI<KYOPRO_BASE_FLOAT>;\n} // namespace kpr\n#line 6 \"\
    function/monoid.hpp\"\n\nnamespace kpr {\n    // \u8DB3\u3057\u7B97\u306Emonoid\n\
    \    template<class T>\n    struct Add {\n        static_assert(is_arithmetic_v<T>,\
    \ \"T must be an arithmetic type\");\n\n        using value_type = T;\n\n    \
    \    constexpr T id() const noexcept {\n            return T{};\n        }\n\n\
    \        constexpr T operator ()(const T& a, const T& b) const noexcept {\n  \
    \          return a + b;\n        }\n\n        constexpr T inverse(const T& a)\
    \ const noexcept {\n            static_assert(std::is_signed_v<T>, \"T must be\
    \ a signed type\");\n            return -a;\n        }\n    };\n\n    // \u639B\
    \u3051\u7B97\u306Emonoid\n    template<class T>\n    struct Mul {\n        static_assert(is_arithmetic_v<T>,\
    \ \"T must be an arithmetic type\");\n\n        using value_type = T;\n\n    \
    \    constexpr T id() const noexcept {\n            return 1;\n        }\n\n \
    \       constexpr T operator ()(const T& a, const T& b) const noexcept {\n   \
    \         return a * b;\n        }\n\n        constexpr T inverse(const T& a)\
    \ const noexcept {\n            return 1 / a;\n        }\n    };\n\n    // min\u306E\
    monoid\n    template<class T>\n    struct Min {\n        static_assert(is_arithmetic_v<T>,\
    \ \"T must be an arithmetic type\");\n\n        using value_type = T;\n\n    \
    \    constexpr T id() const noexcept {\n            return std::numeric_limits<T>::has_infinity\
    \ ? std::numeric_limits<T>::infinity() : INF<T>;\n        }\n\n        constexpr\
    \ T operator ()(const T& a, const T& b) const noexcept {\n            return a\
    \ < b ? a : b;\n        }\n    };\n\n    // max\u306Emonoid\n    template<class\
    \ T>\n    struct Max {\n        static_assert(is_arithmetic_v<T>, \"T must be\
    \ an arithmetic type\");\n\n        using value_type = T;\n\n        constexpr\
    \ T id() const noexcept {\n            return std::numeric_limits<T>::has_infinity\
    \ ? -std::numeric_limits<T>::infinity() : (std::is_signed_v<T> ? -INF<T> : 0);\n\
    \        }\n\n        constexpr T operator ()(const T& a, const T& b) const noexcept\
    \ {\n            return a > b ? a : b;\n        }\n    };\n\n\n    // inverse\u3092\
    \u6301\u3064\u304B\u8ABF\u3079\u308B\n    template<class, class = void>\n    struct\
    \ has_inverse {\n        static constexpr bool value = false;\n    };\n\n    template<class\
    \ T>\n    struct has_inverse<T, std::void_t<decltype(&T::inverse)>> {\n      \
    \  static constexpr bool value = true;\n    };\n\n    // inverse\u3092\u6301\u3064\
    \u304B\u8ABF\u3079\u308B\n    template<class T>\n    inline constexpr bool has_inverse_v\
    \ = has_inverse<T>::value;\n} // namespace kpr\n#line 4 \"function/RecursiveLambda.hpp\"\
    \n\nnamespace kpr {\n    // \u518D\u5E30\u53EF\u80FD\u95A2\u6570\u30AF\u30E9\u30B9\
    \n    template<class F>\n    struct RecursiveLambda {\n        using value_type\
    \ = F;\n\n    private:\n        F func;\n\n    public:\n        template<class\
    \ G>\n        constexpr RecursiveLambda(G&& func) noexcept: func(std::forward<G>(func))\
    \ {}\n        template<class... Args>\n        constexpr decltype(auto) operator\
    \ ()(Args&&... args) const noexcept(noexcept(func(*this, std::forward<Args>(args)...)))\
    \ {\n            return func(*this, std::forward<Args>(args)...);\n        }\n\
    \    };\n\n    template<class F>\n    RecursiveLambda(F&&) -> RecursiveLambda<std::decay_t<F>>;\n\
    } // namespace kpr\n#line 7 \"math/Barrett.hpp\"\n\nnamespace kpr {\n    // Barrett\
    \ Reduction\n    template<class T>\n    struct Barrett {\n        static_assert(is_unsigned_integer_v<T>,\
    \ \"The given type must be an unsigned integer type\");\n\n        using value_type\
    \ = T;\n\n        T mod;\n\n    private:\n        using larger_type = next_integer_t<T>;\n\
    \n        larger_type m;\n\n    public:\n        constexpr void set_mod(T mod)\
    \ noexcept {\n            this->mod = mod;\n            m = (static_cast<larger_type>(1)\
    \ << 64) / mod;\n        }\n\n        constexpr KYOPRO_BASE_INT get_mod() const\
    \ noexcept {\n            return mod;\n        }\n\n        Barrett() noexcept\
    \ = default;\n        Barrett(T mod) noexcept: mod(mod), m((static_cast<larger_type>(1)\
    \ << 64) / mod) {}\n\n        constexpr T reduce(T x) const noexcept {\n     \
    \       x -= static_cast<T>((x * m) >> 64) * mod;\n            return x < mod\
    \ ? x : x - mod;\n        }\n    };\n} // namespace kpr\n#line 3 \"math/div.hpp\"\
    \n\nnamespace kpr {\n    // floor(a \xF7 b)\u3092\u8FD4\u3059\n    [[maybe_unused]]\
    \ inline constexpr struct {\n        template<class T, class U>\n        constexpr\
    \ std::common_type_t<T, U> operator ()(T x, U m) const noexcept {\n          \
    \  static_assert(is_integer_v<T> && is_integer_v<U>, \"Both of the arguments must\
    \ be integers\");\n            if constexpr (is_unsigned_integer_v<T> || is_unsigned_integer_v<U>)\
    \ return x / m;\n            auto d = x / m;\n            return d * m == x ?\
    \ d : d - ((x < 0) ^ (m < 0));\n        }\n    } floor_div;\n\n    // ceil(a \xF7\
    \ b)\u3092\u8FD4\u3059\n    [[maybe_unused]] inline constexpr struct {\n     \
    \   template<class T, class U>\n        constexpr std::common_type_t<T, U> operator\
    \ ()(T x, U m) const noexcept {\n            return floor_div(x + m - static_cast<T>(1),\
    \ m);\n        }\n    } ceil_div;\n} // namespace kpr\n#line 3 \"math/divisors.hpp\"\
    \n#include <vector>\n#line 5 \"math/divisors.hpp\"\n\nnamespace kpr {\n    //\
    \ \u5168\u3066\u306E\u6B63\u306E\u7D04\u6570\u3092\u8FD4\u3059\n    [[maybe_unused]]\
    \ inline constexpr struct {\n        std::vector<KYOPRO_BASE_INT> operator ()(std::uint_fast64_t\
    \ n) const {\n            std::vector<KYOPRO_BASE_INT> lower, upper;\n       \
    \     std::uint_fast64_t i;\n            for (i = 1; i * i < n; ++i) if (n % i\
    \ == 0) {\n                lower.emplace_back(i);\n                upper.emplace_back(n\
    \ / i);\n            }\n            if (i * i == n) lower.emplace_back(i);\n \
    \           lower.insert(end(lower), upper.rbegin(), upper.rend());\n        \
    \    return lower;\n        }\n    } divisors;\n} // namespace kpr\n#line 6 \"\
    math/Montgomery.hpp\"\n\nnamespace kpr {\n    template<class T>\n    struct Montgomery\
    \ {\n        static_assert(is_unsigned_integer_v<T>, \"The given type must be\
    \ an unsigned integer type\");\n\n        using value_type = T;\n\n        T mod;\n\
    \n    private:\n        using larger_type = next_integer_t<T>;\n\n        T r,\
    \ n2;\n\n    public:\n        constexpr void set_mod(T mod) noexcept {\n     \
    \       this->mod = mod;\n            n2 = -static_cast<larger_type>(mod) % mod;\n\
    \            T t = 0;\n            r = 0;\n            for (int i = 0; i < std::numeric_limits<T>::digits;\
    \ ++i) {\n                if (!(t & 1)) {\n                    t += mod;\n   \
    \                 r += static_cast<T>(1) << static_cast<T>(i);\n             \
    \   }\n                t >>= 1;\n            }\n        }\n\n        constexpr\
    \ KYOPRO_BASE_INT get_mod() const noexcept {\n            return mod;\n      \
    \  }\n\n        Montgomery() noexcept = default;\n        Montgomery(T mod) noexcept\
    \ {\n            set_mod(mod);\n        }\n\n        constexpr T transform(T x)\
    \ const noexcept {\n            return reduce(static_cast<larger_type>(x) * n2);\n\
    \        }\n\n        constexpr T inverse_transform(T x) const noexcept {\n  \
    \          T y = reduce(x);\n            return y >= mod ? y - mod : y;\n    \
    \    }\n\n        constexpr T reduce(larger_type x) const noexcept {\n       \
    \     return (x + static_cast<larger_type>(static_cast<T>(x) * r) * mod) >> std::numeric_limits<T>::digits;\n\
    \        }\n    };\n} // namespace kpr\n#line 11 \"math/DynamicModInt.hpp\"\n\n\
    namespace kpr {\n    template<class T, std::size_t kind = 0, bool = false>\n \
    \   struct DynamicModInt {\n        static_assert(std::is_unsigned_v<T>, \"The\
    \ given type must be an unsigned integer type\");\n        using value_type =\
    \ T;\n\n    private:\n        using larger_type = next_integer_t<T>;\n\n     \
    \   inline static Montgomery<T> montgomery;\n\n    public:\n        T value;\n\
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
    \        }\n    };\n} // namespace kpr\n#line 4 \"math/euler_phi.hpp\"\n\nnamespace\
    \ kpr {\n    // \u30AA\u30A4\u30E9\u30FC\u306E\u03C6\u95A2\u6570\n    [[maybe_unused]]\
    \ inline constexpr struct {\n        constexpr KYOPRO_BASE_INT operator ()(std::uint_fast64_t\
    \ n) const noexcept {\n            std::uint_fast64_t res = n;\n            if\
    \ ((n & 1) == 0) {\n                res -= res >> 1;\n                n >>= 1;\n\
    \                while ((n & 1) == 0) n >>= 1;\n            }\n            for\
    \ (std::uint_fast64_t i = 3; i * i <= n; i += 2) {\n                if (n % i\
    \ == 0) {\n                res -= res / i;\n                n /= i;\n        \
    \        while (n % i == 0) n /= i;\n                }\n            }\n      \
    \      if (n != 1) res -= res / n;\n            return res;\n        }\n    }\
    \ euler_phi;\n} // namespace kpr\n#line 2 \"math/factorize.hpp\"\n#include <algorithm>\n\
    #line 5 \"math/factorize.hpp\"\n#include <numeric>\n#include <random>\n#line 8\
    \ \"math/is_prime.hpp\"\n\nnamespace kpr {\n    [[maybe_unused]] inline constexpr\
    \ struct {\n        template<class T>\n        constexpr bool operator ()(T x)\
    \ const {\n            using U = std::make_unsigned_t<T>;\n            using dmint\
    \ = DynamicModInt<U, 0, true>;\n            U n = x;\n            if (n <= 1)\
    \ return false;\n            if (!(n & 1)) return n == 2;\n            dmint::set_mod(n);\n\
    \            std::uint_fast64_t d = (n - 1) >> rzero_count(n - 1);\n         \
    \   dmint one = 1, minus_one = n - 1;\n            auto ng = [&](std::uint_fast64_t\
    \ a) noexcept {\n                auto y = dmint(a).power(d);\n               \
    \ std::uint_fast64_t t = d;\n                while (y != one and y != minus_one\
    \ and t != n - 1) y *= y, t <<= 1;\n                if (y != minus_one and !(t\
    \ & 1)) return true;\n                return false;\n            };\n        \
    \    if constexpr (std::numeric_limits<U>::digits <= 32) {\n                for\
    \ (auto i: (std::uint_fast64_t[3]){2, 7, 61}) {\n                    if (n <=\
    \ i) return true;\n                    if (ng(i)) return false;\n            \
    \    }\n            } else if (n < (static_cast<U>(1) << 32)) {\n            \
    \    for (auto i: (std::uint_fast64_t[3]){2, 7, 61}) {\n                    if\
    \ (n <= i) return true;\n                    if (ng(i)) return false;\n      \
    \          }\n            } else {\n                for (auto i: (std::uint_fast64_t[7]){2,\
    \ 325, 9375, 28178, 450775, 9780504, 1795265022}) {\n                    if (n\
    \ <= i) return true;\n                    if (ng(i)) return false;\n         \
    \       }\n            }\n            return true;\n        }\n    } is_prime;\n\
    } // namespace kpr\n#line 12 \"math/factorize.hpp\"\n\nnamespace kpr {\n    //\
    \ \u7D20\u56E0\u6570\u5206\u89E3\n    [[maybe_unused]] inline constexpr struct\
    \ {\n        template<class T>\n        constexpr T operator ()(T p, std::uint_fast64_t\
    \ c) const {\n            using U = std::make_unsigned_t<T>;\n            using\
    \ dmint = DynamicModInt<U, 0, true>;\n            U n = p;\n            dmint::set_mod(n);\n\
    \            dmint cc = c;\n            auto f = [=](dmint x) noexcept {\n   \
    \             return x * x + cc;\n            };\n            auto x = dmint::raw(1),\
    \ y = dmint::raw(2), z = dmint::raw(1), q = dmint::raw(1);\n            U g =\
    \ 1;\n            const int m = 1 << (floor_bit(n) / 5);\n            for (int\
    \ r = 1; g == 1; r <<= 1) {\n                x = y;\n                for (int\
    \ i = 0; i < r; ++i) y = f(y);\n                for (int k = 0; k < r && g ==\
    \ 1; k += m) {\n                z = y;\n                int min = std::min(m,\
    \ r - k);\n                for (int i = 0; i < min; ++i) {\n                 \
    \   y = f(y);\n                    q *= x - y;\n                }\n          \
    \      g = std::gcd(static_cast<U>(q), n);\n                }\n            }\n\
    \            if (g == n) {\n                do {\n                z = f(z);\n\
    \                g = std::gcd(static_cast<U>(x - z), n);\n                } while\
    \ (g == 1);\n            }\n            return g;\n        }\n    } pollard_rho;\n\
    \n    [[maybe_unused]] inline constexpr struct {\n        KYOPRO_BASE_UINT operator\
    \ ()(std::uint_fast64_t n) const noexcept {\n            static std::mt19937_64\
    \ mt(std::random_device{}());\n            std::uniform_int_distribution<std::uint_fast64_t>\
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
    \   }\n    } factorize;\n} // namespace kpr\n#line 2 \"math/mod.hpp\"\n#include\
    \ <cassert>\n#line 4 \"math/mod.hpp\"\n\nnamespace kpr {\n    [[maybe_unused]]\
    \ inline constexpr struct {\n        template<class T, class U>\n        constexpr\
    \ std::common_type_t<T, U> operator ()(T x, U m) const noexcept {\n          \
    \  static_assert(is_integer_v<T> && is_integer_v<U>, \"Both of the arguments must\
    \ be integers\");\n            if constexpr (is_unsigned_integer_v<T> || is_unsigned_integer_v<U>)\
    \ return x % m;\n            return (x %= m) < 0 ? x + m : x;\n        }\n   \
    \ } floor_mod;\n\n    [[maybe_unused]] inline constexpr struct {\n        template<class\
    \ T, class U>\n        constexpr std::common_type_t<T, U> operator ()(T x, U m)\
    \ const noexcept {\n            return m - floor_mod(x - 1, m) - static_cast<T>(1);\n\
    \        }\n    } ceil_mod;\n} // namespace kpr\n#line 14 \"math/ModInt.hpp\"\n\
    \nnamespace kpr {\n    template<KYOPRO_BASE_UINT m>\n    struct ModInt {\n   \
    \     using value_type = uint_least_t<bit_len(m * 2 - 2)>;\n\n        static constexpr\
    \ value_type mod = m;\n        value_type value;\n\n        static constexpr KYOPRO_BASE_INT\
    \ get_mod() noexcept {\n            return mod;\n        }\n\n        constexpr\
    \ ModInt() noexcept = default;\n        template<class T>\n        constexpr ModInt(T\
    \ value) noexcept: value(floor_mod(value, mod)) {}\n\n        template<class T>\n\
    \        explicit constexpr operator T() const noexcept {\n            return\
    \ value;\n        }\n\n        static constexpr ModInt raw(value_type value) noexcept\
    \ {\n            ModInt res;\n            res.value = value;\n            return\
    \ res;\n        }\n\n        constexpr ModInt power(KYOPRO_BASE_UINT n) const\
    \ noexcept {\n            std::uint_fast64_t res = 1, a = value;\n           \
    \ while (n > 0) {\n                if (n & 1) res = res * a % mod;\n         \
    \       a = a * a % mod;\n                n >>= 1;\n            }\n          \
    \  return res;\n        }\n\n        constexpr ModInt inverse() const noexcept\
    \ {\n            std::uint_fast64_t a = value, b = mod;\n            std::int_fast64_t\
    \ u = 1, v = 0;\n            while (b > 0) {\n                std::uint_fast64_t\
    \ t = a / b;\n                a -= t * b;\n                std::swap(a, b);\n\
    \                u -= t * v;\n                std::swap(u, v);\n            }\n\
    \            return floor_mod(u, mod);\n        }\n\n        constexpr ModInt\
    \ operator +() const noexcept {\n            return *this;\n        }\n\n    \
    \    constexpr ModInt operator -() const noexcept {\n            return value\
    \ == 0 ? 0 : mod - value;\n        }\n\n        constexpr ModInt& operator ++()\
    \ noexcept {\n            if (++value >= mod) value -= mod;\n            return\
    \ *this;\n        }\n\n        constexpr ModInt operator ++(int) noexcept {\n\
    \            ModInt before = *this;\n            ++*this;\n            return\
    \ before;\n        }\n\n        constexpr ModInt& operator --() noexcept {\n \
    \           if (value == 0) value = mod;\n            --value;\n            return\
    \ *this;\n        }\n\n        constexpr ModInt operator --(int) noexcept {\n\
    \            ModInt before = *this;\n            --*this;\n            return\
    \ before;\n        }\n\n        constexpr ModInt& operator +=(ModInt rhs) noexcept\
    \ {\n            if ((value += rhs.value) >= mod) value -= mod;\n            return\
    \ *this;\n        }\n\n        constexpr ModInt& operator -=(ModInt rhs) noexcept\
    \ {\n            if (value < rhs.value) value += mod;\n            value -= rhs.value;\n\
    \            return *this;\n        }\n\n        constexpr ModInt& operator *=(ModInt\
    \ rhs) noexcept {\n            value = static_cast<uint_least_t<bit_len(mod) *\
    \ 2>>(value) * rhs.value % mod;\n            return *this;\n        }\n\n    \
    \    constexpr ModInt& operator /=(ModInt rhs) noexcept {\n            value =\
    \ static_cast<uint_least_t<bit_len(mod) * 2>>(value) * rhs.inverse().value % mod;\n\
    \            return *this;\n        }\n\n        friend constexpr ModInt operator\
    \ +(ModInt lhs, ModInt rhs) noexcept {\n            return lhs += rhs;\n     \
    \   }\n\n        friend constexpr ModInt operator -(ModInt lhs, ModInt rhs) noexcept\
    \ {\n            return lhs -= rhs;\n        }\n\n        friend constexpr ModInt\
    \ operator *(ModInt lhs, ModInt rhs) noexcept {\n            return lhs *= rhs;\n\
    \        }\n\n        friend constexpr ModInt operator /(ModInt lhs, ModInt rhs)\
    \ noexcept {\n            return lhs /= rhs;\n        }\n\n        friend constexpr\
    \ bool operator ==(ModInt lhs, ModInt rhs) noexcept {\n            return lhs.value\
    \ == rhs.value;\n        }\n\n        friend constexpr bool operator !=(ModInt\
    \ lhs, ModInt rhs) noexcept {\n            return lhs.value != rhs.value;\n  \
    \      }\n\n        template<class Scanner>\n        void scan(Scanner& scanner)\
    \ {\n            std::int_fast64_t value;\n            scanner.scan(value);\n\
    \            value = floor_mod(value, mod);\n        }\n\n        template<class\
    \ Printer>\n        void print(Printer& printer) const {\n            printer.print(value);\n\
    \        }\n    };\n\n    template<KYOPRO_BASE_UINT mod>\n    struct Hash<ModInt<mod>>\
    \ {\n        using value_type = ModInt<mod>;\n        constexpr std::size_t operator\
    \ ()(ModInt<mod> a) const noexcept {\n            return static_cast<std::size_t>(a);\n\
    \        }\n    };\n} // namespace kpr\n#line 5 \"range/range_base.hpp\"\n\nnamespace\
    \ kpr {\n    template<class Derived, class ValueType>\n    struct RangeBase {\n\
    \        using value_type = std::decay_t<ValueType>;\n        using size_type\
    \ = std::size_t;\n        using difference_type = std::ptrdiff_t;\n        using\
    \ reference = value_type&;\n        using const_reference = const value_type&;\n\
    \        using pointer = value_type*;\n        using const_pointer = const value_type*;\n\
    \n        Derived& down_cast() noexcept {\n            return static_cast<Derived&>(*this);\n\
    \        }\n        const Derived& down_cast() const noexcept {\n            return\
    \ static_cast<const Derived&>(*this);\n        }\n\n        constexpr auto begin()\
    \ const noexcept {\n            return down_cast().begin();\n        }\n\n   \
    \     constexpr auto end() const noexcept {\n            return down_cast().end();\n\
    \        }\n\n        constexpr auto cbegin() const noexcept {\n            return\
    \ down_cast().cbegin();\n        }\n\n        constexpr auto cend() const noexcept\
    \ {\n            return down_cast().cend();\n        }\n\n        constexpr bool\
    \ empty() const noexcept {\n            return begin() == end();\n        }\n\n\
    \        constexpr decltype(auto) front() noexcept {\n            return *begin();\n\
    \        }\n        constexpr decltype(auto) front() const noexcept {\n      \
    \      return *cbegin();\n        }\n\n        constexpr decltype(auto) rbegin()\
    \ const noexcept {\n            return std::reverse_iterator(end());\n       \
    \ }\n\n        constexpr decltype(auto) rend() const noexcept {\n            return\
    \ std::reverse_iterator(begin());\n        }\n\n        constexpr decltype(auto)\
    \ crbegin() const noexcept {\n            return std::reverse_iterator(cend());\n\
    \        }\n\n        constexpr decltype(auto) crend() const noexcept {\n    \
    \        return std::reverse_iterator(cbegin());\n        }\n\n        constexpr\
    \ decltype(auto) back() noexcept {\n            return *rbegin();\n        }\n\
    \        constexpr decltype(auto) back() const noexcept {\n            return\
    \ *crbegin();\n        }\n\n        constexpr std::size_t size() const noexcept\
    \ {\n            return end() - begin();\n        }\n\n        constexpr decltype(auto)\
    \ operator [](std::size_t idx) {\n            return *(begin() + idx);\n     \
    \   }\n        constexpr decltype(auto) operator [](std::size_t idx) const {\n\
    \            return *(cbegin() + idx);\n        }\n    };\n} // namespace kpr\n\
    #line 9 \"range/imap.hpp\"\n\nnamespace kpr {\n    template<class Func, class\
    \ Range>\n    struct imap: RangeBase<imap<Func, Range>, std::invoke_result_t<Func,\
    \ range_value_t<Range>>> {\n    private:\n        using BaseIterator = range_iterator_t<Range>;\n\
    \        using BaseConstIterator = range_const_iterator_t<Range>;\n\n        Func\
    \ func;\n        Range range;\n\n    public:\n        imap() noexcept = default;\n\
    \        template<class F, class R>\n        imap(F&& func, R&& range) noexcept:\
    \ func(std::forward<F>(func)), range(std::forward<R>(range)) {}\n\n        struct\
    \ iterator: BaseIterator {\n            using value_type = std::decay_t<std::invoke_result_t<Func,\
    \ decltype(*std::declval<BaseIterator>())>>;\n            using pointer = value_type*;\n\
    \            using reference = value_type&;\n\n        private:\n            Func\
    \ func;\n\n        public:\n            iterator() noexcept = default;\n     \
    \       template<class F, class Itr>\n            iterator(F&& func, Itr&& itr)\
    \ noexcept: func(std::forward<F>(func)), BaseIterator(std::forward<Itr>(itr))\
    \ {}\n\n            constexpr decltype(auto) operator *() const noexcept {\n \
    \               return std::invoke(func, BaseIterator::operator *());\n      \
    \      }\n        };\n\n        struct const_iterator: BaseConstIterator {\n \
    \           using value_type = const std::decay_t<std::invoke_result_t<Func, decltype(*std::declval<BaseConstIterator>())>>;\n\
    \            using pointer = value_type*;\n            using reference = value_type&;\n\
    \n        private:\n            Func func;\n\n        public:\n            const_iterator()\
    \ noexcept = default;\n            template<class F, class Itr>\n            const_iterator(F&&\
    \ func, Itr&& itr) noexcept: func(std::forward<F>(func)), BaseConstIterator(std::forward<Itr>(itr))\
    \ {}\n\n            constexpr decltype(auto) operator *() const noexcept {\n \
    \               return std::invoke(func, BaseConstIterator::operator *());\n \
    \           }\n        };\n\n\n        using reverse_iterator = std::reverse_iterator<iterator>;\n\
    \        using const_reverse_iterator = std::reverse_iterator<const_iterator>;\n\
    \n\n        constexpr iterator begin() const noexcept {\n            return iterator{func,\
    \ std::begin(range)};\n        }\n\n        constexpr iterator end() const noexcept\
    \ {\n            return iterator{func, std::end(range)};\n        }\n\n      \
    \  constexpr const_iterator cbegin() const noexcept {\n            return const_iterator{func,\
    \ std::begin(range)};\n        }\n\n        constexpr const_iterator cend() const\
    \ noexcept {\n            return const_iterator{func, std::end(range)};\n    \
    \    }\n    };\n\n    template<class F, class R>\n    imap(F&&, R&&) -> imap<std::decay_t<F>,\
    \ std::decay_t<R>>;\n} // namespace kpr\n#line 5 \"range/iterator_base.hpp\"\n\
    \nnamespace kpr {\n    template<class, class, class>\n    struct IteratorBase;\n\
    \n    template<class Derived, class ValueType>\n    struct IteratorBase<Derived,\
    \ ValueType, std::forward_iterator_tag> {\n        using value_type = std::decay_t<ValueType>;\n\
    \        using pointer = value_type*;\n        using reference = value_type&;\n\
    \        using difference_type = std::ptrdiff_t;\n        using iterator_category\
    \ = std::forward_iterator_tag;\n\n        virtual constexpr ValueType operator\
    \ *() const noexcept;\n        virtual constexpr Derived& operator ++() noexcept;\n\
    \        virtual constexpr bool operator ==(const Derived&) const noexcept;\n\n\
    \        constexpr Derived operator ++(int) noexcept {\n            Derived before\
    \ = *this;\n            ++*this;\n            return before;\n        }\n\n  \
    \      constexpr bool operator !=(const Derived& rhs) const noexcept {\n     \
    \       return !(*this == rhs);\n        }\n    };\n\n    template<class Derived,\
    \ class ValueType>\n    struct IteratorBase<Derived, ValueType, std::bidirectional_iterator_tag>:\
    \ IteratorBase<Derived, ValueType, std::forward_iterator_tag> {\n        using\
    \ iterator_category = std::bidirectional_iterator_tag;\n\n        virtual constexpr\
    \ Derived& operator --() noexcept;\n\n        constexpr Derived operator --(int)\
    \ noexcept {\n            Derived before = *this;\n            --*this;\n    \
    \        return before;\n        }\n    };\n\n    template<class Derived, class\
    \ ValueType>\n    struct IteratorBase<Derived, ValueType, std::random_access_iterator_tag>:\
    \ IteratorBase<Derived, ValueType, std::bidirectional_iterator_tag> {\n      \
    \  using iterator_category = std::random_access_iterator_tag;\n\n        virtual\
    \ constexpr Derived operator +(std::ptrdiff_t rhs) const noexcept;\n        virtual\
    \ constexpr std::ptrdiff_t operator -(const Derived&) const noexcept;\n\n    private:\n\
    \        virtual constexpr int compare(const Derived&) const noexcept;\n\n   \
    \ public:\n\n        constexpr Derived& operator +=(std::ptrdiff_t rhs) noexcept\
    \ {\n            return *this = *this + rhs;\n        }\n\n        constexpr Derived\
    \ operator -(std::ptrdiff_t rhs) const noexcept {\n            return *this +\
    \ -rhs;\n        }\n\n        constexpr Derived& operator -=(std::ptrdiff_t rhs)\
    \ noexcept {\n            return *this = *this - rhs;\n        }\n\n        constexpr\
    \ decltype(auto) operator [](std::size_t idx) const noexcept {\n            return\
    \ *(*this + idx);\n        }\n\n        constexpr bool operator ==(const Derived&\
    \ rhs) const noexcept {\n            return compare(rhs) == 0;\n        }\n  \
    \      constexpr bool operator !=(const Derived& rhs) const noexcept {\n     \
    \       return compare(rhs) != 0;\n        }\n        constexpr bool operator\
    \ <(const Derived& rhs) const noexcept {\n            return compare(rhs) < 0;\n\
    \        }\n        constexpr bool operator <=(const Derived& rhs) const noexcept\
    \ {\n            return compare(rhs) <= 0;\n        }\n        constexpr bool\
    \ operator >(const Derived& rhs) const noexcept {\n            return compare(rhs)\
    \ > 0;\n        }\n        constexpr bool operator >=(const Derived& rhs) const\
    \ noexcept {\n            return compare(rhs) >= 0;\n        }\n    };\n} // namespace\
    \ kpr\n#line 10 \"range/irange.hpp\"\n\nnamespace kpr {\n    template<class T>\n\
    \    struct irange: RangeBase<irange<T>, T> {\n    private:\n        T first,\
    \ last;\n\n        template<class, class = void, class = void, class = void>\n\
    \        struct get_iterator_category;\n        template<class ValueType, class\
    \ Void>\n        struct get_iterator_category<ValueType, std::void_t<decltype(++std::declval<ValueType>())>,\
    \ Void, Void> {\n            using type = std::forward_iterator_tag;\n       \
    \ };\n        template<class ValueType, class Void>\n        struct get_iterator_category<ValueType,\
    \ std::void_t<decltype(++std::declval<ValueType>())>, std::void_t<decltype(--std::declval<ValueType>())>,\
    \ Void> {\n            using type = std::bidirectional_iterator_tag;\n       \
    \ };\n        template<class ValueType>\n        struct get_iterator_category<ValueType,\
    \ std::void_t<decltype(++std::declval<ValueType>())>, std::void_t<decltype(--std::declval<ValueType>())>,\
    \ std::void_t<decltype(std::declval<T>() < std::declval<ValueType>(), std::declval<ValueType>()\
    \ > std::declval<ValueType>(), std::declval<ValueType>() + std::declval<std::ptrdiff_t>(),\
    \ std::declval<ValueType>() - std::declval<ValueType>())>> {\n            using\
    \ type = std::random_access_iterator_tag;\n        };\n\n    public:\n       \
    \ irange() noexcept = default;\n        template<class F, class L>\n        irange(F&&\
    \ first, L&& last) noexcept: first(std::forward<F>(first)), last(std::forward<L>(last))\
    \ {}\n\n        struct iterator: IteratorBase<iterator, const T&, typename get_iterator_category<T&>::type>\
    \ {\n        private:\n            T itr;\n\n            constexpr int compare(const\
    \ iterator& rhs) const noexcept {\n                if (itr < rhs.itr) return -1;\n\
    \                else if (itr > rhs.itr) return 1;\n                else return\
    \ 0;\n            }\n\n        public:\n            iterator() noexcept = default;\n\
    \            template<class Itr>\n            iterator(Itr&& itr) noexcept: itr(std::forward<Itr>(itr))\
    \ {}\n\n            constexpr const T& operator *() const noexcept {\n       \
    \         return itr;\n            }\n\n            constexpr iterator& operator\
    \ ++() noexcept {\n                ++itr;\n                return *this;\n   \
    \         }\n\n            constexpr iterator& operator --() noexcept {\n    \
    \            --itr;\n                return *this;\n            }\n\n        \
    \    constexpr iterator operator +(std::ptrdiff_t rhs) const noexcept {\n    \
    \            return iterator{itr + rhs};\n            }\n\n            constexpr\
    \ std::ptrdiff_t operator -(const iterator& rhs) const noexcept {\n          \
    \      return itr - rhs.itr;\n            }\n        };\n\n        struct const_iterator:\
    \ IteratorBase<const_iterator, const T&, typename get_iterator_category<T&>::type>\
    \ {\n        private:\n            T itr;\n\n            constexpr int compare(const\
    \ const_iterator& rhs) const noexcept {\n                if (itr < rhs.itr) return\
    \ -1;\n                else if (itr > rhs.itr) return 1;\n                else\
    \ return 0;\n            }\n\n        public:\n            const_iterator() noexcept\
    \ = default;\n            template<class Itr>\n            const_iterator(Itr&&\
    \ itr) noexcept: itr(std::forward<Itr>(itr)) {}\n\n            constexpr const\
    \ T& operator *() const noexcept {\n                return itr;\n            }\n\
    \n            constexpr const_iterator& operator ++() noexcept {\n           \
    \     ++itr;\n                return *this;\n            }\n\n            constexpr\
    \ const_iterator& operator --() noexcept {\n                --itr;\n         \
    \       return *this;\n            }\n\n            constexpr const_iterator operator\
    \ +(std::ptrdiff_t rhs) const noexcept {\n                return iterator{itr\
    \ + rhs};\n            }\n\n            constexpr std::ptrdiff_t operator -(const\
    \ const_iterator& rhs) const noexcept {\n                return itr - rhs.itr;\n\
    \            }\n        };\n\n\n        using reverse_iterator = std::reverse_iterator<iterator>;\n\
    \        using const_reverse_iterator = std::reverse_iterator<const_iterator>;\n\
    \n\n        constexpr iterator begin() const noexcept {\n            return iterator{first};\n\
    \        }\n\n        constexpr iterator end() const noexcept {\n            return\
    \ iterator{last};\n        }\n\n        constexpr const_iterator cbegin() const\
    \ noexcept {\n            return const_iterator{first};\n        }\n\n       \
    \ constexpr const_iterator cend() const noexcept {\n            return const_iterator{last};\n\
    \        }\n    };\n\n    template<class F, class L>\n    irange(F&&, L&&) ->\
    \ irange<std::decay_t<F>>;\n} // namespace kpr\n#line 6 \"structure/FenwickTree.hpp\"\
    \n\nnamespace kpr {\n    template<class T, class Op = Add<T>, class Container\
    \ = std::vector<T>>\n    struct FenwickTree: private Op {\n        using value_type\
    \ = T;\n        using size_type = std::size_t;\n        using reference = T&;\n\
    \        using const_reference = const T&;\n        using operator_type = Op;\n\
    \        using container_type = Container;\n\n    private:\n        Container\
    \ tree;\n\n    public:\n        FenwickTree() noexcept = default;\n        FenwickTree(std::size_t\
    \ n) noexcept: tree(n, Op::id()) {}\n\n        std::size_t size() noexcept {\n\
    \            return tree.size();\n        }\n\n        void apply(int p, const\
    \ T& x) {\n            ++p;\n            while (p <= (int)size()) {\n        \
    \        tree[p - 1] = Op::operator ()(tree[p - 1], x);\n                p +=\
    \ p & -p;\n            }\n        }\n\n        T prod(int r) const {\n       \
    \     T s = Op::id();\n            while (r > 0) {\n                s = Op::operator\
    \ ()(s, tree[r - 1]);\n                r -= r & -r;\n            }\n         \
    \   return s;\n        }\n        T prod(int l, int r) const {\n            static_assert(has_inverse_v<Op>,\
    \ \"Operator doesn't have an inverse\");\n            return Op::operator ()(prod(r),\
    \ Op::inverse(prod(l)));\n        }\n\n        T all_prod() {\n            return\
    \ prod(tree.size());\n        }\n\n        T get(int p) {\n            static_assert(has_inverse_v<Op>,\
    \ \"Operator doesn't have an inverse\");\n            return Op::operator ()(prod(p\
    \ + 1), Op::inverse(prod(p)));\n        }\n\n        void set(int p, const T&\
    \ x) {\n            static_assert(has_inverse_v<Op>, \"Operator doesn't have an\
    \ inverse\");\n            apply(p, Op::operator ()(x, Op::inverse(get(p))));\n\
    \        }\n    };\n} // namespace kpr\n#line 4 \"structure/UnionFind.hpp\"\n\
    #include <unordered_map>\n#line 9 \"structure/UnionFind.hpp\"\n\nnamespace kpr\
    \ {\n    template<class Container = std::vector<int>>\n    struct UnionFind {\n\
    \        using value_type = range_value_t<Container>;\n        using container_type\
    \ = Container;\n\n    private:\n        Container par;\n\n    public:\n      \
    \  UnionFind() noexcept = default;\n        UnionFind(std::size_t n) noexcept:\
    \ par(n, -1) {}\n        template<class C, std::enable_if_t<std::is_same_v<Container,\
    \ std::decay_t<C>>>>\n        UnionFind(C&& par): par(std::forward<C>(par)) {}\n\
    \n        void resize(std::size_t x) { par.resize(x, -1); }\n        void assign(std::size_t\
    \ x) { par.assign(x, -1); }\n        void reset() { std::fill(std::begin(par),\
    \ std::end(par), -1); }\n\n        std::size_t size() const noexcept {\n     \
    \       return par.size();\n        }\n\n        KYOPRO_BASE_INT find(int x) {\n\
    \            int p = x;\n            while (par[p] >= 0) p = par[p];\n       \
    \     while (x != p) {\n                int tmp = x;\n                x = par[x];\n\
    \                par[tmp] = p;\n            }\n            return p;\n       \
    \ }\n\n        bool merge(int x, int y) {\n            x = find(x), y = find(y);\n\
    \            if (x == y) return false;\n            if (par[x] > par[y]) {\n \
    \               int tmp = x;\n                x = y;\n                y = tmp;\n\
    \            }\n            par[x] += par[y];\n            par[y] = x;\n     \
    \       return true;\n        }\n\n        bool same(int x, int y) {\n       \
    \     return find(x) == find(y);\n        }\n\n        KYOPRO_BASE_INT group_size(int\
    \ x) {\n            return -par[find(x)];\n        }\n\n        std::vector<int>\
    \ group_members(int x) {\n            x = find(x);\n            std::vector<int>\
    \ a;\n            for (int i = 0; i < (int)(size()); ++i) if (find(i) == x) a.emplace_back(i);\n\
    \            return a;\n        }\n\n        template<class Vector = std::vector<KYOPRO_BASE_INT>>\n\
    \        Vector roots() const {\n            Vector a;\n            for (int i\
    \ = 0; i < (int)(size()); ++i) if (par[i] < 0) a.emplace_back(i);\n          \
    \  return a;\n        }\n\n        KYOPRO_BASE_INT group_count() const {\n   \
    \         KYOPRO_BASE_INT cnt = 0;\n            for (int i = 0; i < (int)(size());\
    \ ++i) if (par[i] < 0) ++cnt;\n            return cnt;\n        }\n\n        template<class\
    \ Map = std::unordered_map<KYOPRO_BASE_INT, std::vector<KYOPRO_BASE_INT>>>\n \
    \       Map all_group_members() {\n            Map group_members;\n          \
    \  for (int member = 0; member < (int)(size()); ++member) group_members[find(member)].emplace_back(member);\n\
    \            return group_members;\n        }\n    };\n} // namespace kpr\n#line\
    \ 2 \"system/in.hpp\"\n#include <unistd.h>\n#include <array>\n#include <bitset>\n\
    #line 7 \"system/in.hpp\"\n#include <cstdio>\n#include <string>\n#line 16 \"system/in.hpp\"\
    \n\nnamespace kpr {\n    template<std::size_t buf_size = KYOPRO_BUFFER_SIZE>\n\
    \    struct Reader {\n    private:\n        int fd, idx;\n        std::array<char,\
    \ buf_size> buffer;\n\n    public:\n        static constexpr KYOPRO_BASE_INT get_buf_size()\
    \ noexcept {\n            return buf_size;\n        }\n\n        Reader() {\n\
    \            read(fd, buffer.begin(), buf_size);\n        }\n        Reader(int\
    \ fd): fd(fd), idx(0), buffer() {\n            read(fd, buffer.begin(), buf_size);\n\
    \        }\n        Reader(FILE* fp): fd(fileno(fp)), idx(0), buffer() {\n   \
    \         read(fd, buffer.begin(), buf_size);\n        }\n\n        struct iterator\
    \ {\n        private:\n            Reader& reader;\n\n        public:\n      \
    \      using difference_type = void;\n            using value_type = void;\n \
    \           using pointer = void;\n            using reference = void;\n     \
    \       using iterator_category = std::input_iterator_tag;\n\n            iterator()\
    \ noexcept = default;\n            iterator(Reader& reader) noexcept: reader(reader)\
    \ {}\n\n            iterator& operator ++() {\n                ++reader.idx;\n\
    \                if (reader.idx == buf_size) {\n                    read(reader.fd,\
    \ reader.buffer.begin(), buf_size);\n                    reader.idx = 0;\n   \
    \             }\n                return *this;\n            }\n\n            iterator\
    \ operator ++(int) {\n                iterator before = *this;\n             \
    \   operator ++();\n                return before;\n            }\n\n        \
    \    char& operator *() const {\n                return reader.buffer[reader.idx];\n\
    \            }\n        };\n\n        iterator begin() noexcept {\n          \
    \  return iterator(*this);\n        }\n    };\n\n    Reader input(0);\n\n    template<class\
    \ Iterator, std::size_t decimal_precision = KYOPRO_DECIMAL_PRECISION>\n    struct\
    \ Scanner {\n        using iterator_type = Iterator;\n    private:\n        template<class,\
    \ class = void>\n        struct has_scan: std::false_type {};\n        template<class\
    \ T>\n        struct has_scan<T, std::void_t<decltype(std::declval<T>().scan(std::declval<Scanner&>()))>>:\
    \ std::true_type {};\n\n    public:\n        Iterator itr;\n\n        static constexpr\
    \ KYOPRO_BASE_INT get_decimal_precision() noexcept {\n            return decimal_precision;\n\
    \        }\n\n        Scanner() noexcept = default;\n        Scanner(Iterator\
    \ itr) noexcept: itr(itr) {}\n\n        void discard_space() {\n            while\
    \ (('\\t' <= *itr && *itr <= '\\r') || *itr == ' ') ++itr;\n        }\n\n    \
    \    void scan(char& a) {\n            discard_space();\n            a = *itr;\n\
    \            ++itr;\n        }\n        void scan(bool& a) {\n            discard_space();\n\
    \            a = *itr != '0';\n        }\n        void scan(std::string& a) {\n\
    \            discard_space();\n            while ((*itr < '\\t' || '\\r' < *itr)\
    \ && *itr != ' ') {\n                a += *itr;\n                ++itr;\n    \
    \        }\n        }\n        template<std::size_t len>\n        void scan(std::bitset<len>&\
    \ a) {\n            discard_space();\n            for (int i = len - 1; i >= 0;\
    \ ++i) {\n                a[i] = *itr != '0';\n                ++itr;\n      \
    \      }\n        }\n        template<class T, std::enable_if_t<std::is_arithmetic_v<T>\
    \ && !has_scan<T>::value>* = nullptr>\n        void scan(T& a) {\n           \
    \ discard_space();\n            bool sgn = false;\n            if constexpr (!std::is_unsigned_v<T>)\
    \ if (*itr == '-') {\n                sgn = true;\n                ++itr;\n  \
    \          }\n            a = 0;\n            for (; '0' <= *itr && *itr <= '9';\
    \ ++itr) a = a * 10 + *itr - '0';\n            if (*itr == '.') {\n          \
    \      ++itr;\n                if constexpr (std::is_floating_point_v<T>) {\n\
    \                    constexpr std::uint_fast64_t power_decimal_precision = power(10ULL,\
    \ decimal_precision);\n                    T d = 0;\n                    std::uint_fast64_t\
    \ i = 1;\n                    for (; '0' <= *itr && *itr <= '9' && i < power_decimal_precision;\
    \ i *= 10) {\n                        d = d * 10 + *itr - '0';\n             \
    \           ++itr;\n                    }\n                    a += d / i;\n \
    \               }\n                while ('0' <= *itr && *itr <= '9') ++itr;\n\
    \            }\n            if constexpr (!std::is_unsigned_v<T>) if (sgn) a =\
    \ -a;\n        }\n        template<std::size_t i = 0, class T, std::enable_if_t<is_tuple_like_v<T>\
    \ && !is_range_v<T> && !has_scan<T>::value>* = nullptr>\n        void scan(T&\
    \ a) {\n            if constexpr (i < std::tuple_size_v<T>) {\n              \
    \  scan(std::get<i>(a));\n                scan<i + 1>(a);\n            }\n   \
    \     }\n        template<class T, std::enable_if_t<is_range_v<T> && !has_scan<T>::value>*\
    \ = nullptr>\n        void scan(T& a) {\n            for (auto&& i: a) scan(i);\n\
    \        }\n        template<class T, std::enable_if_t<has_scan<T>::value>* =\
    \ nullptr>\n        void scan(T& a) {\n            a.scan(*this);\n        }\n\
    \n        void operator ()() {}\n        template<class Head, class... Args>\n\
    \        void operator ()(Head& head, Args&... args) {\n            scan(head);\n\
    \            operator ()(args...);\n        }\n    };\n\n    Scanner<Reader<>::iterator>\
    \ scan(input.begin());\n} // namespace kpr\n#line 6 \"system/out.hpp\"\n#include\
    \ <cmath>\n#line 17 \"system/out.hpp\"\n\nnamespace kpr {\n    template<std::size_t\
    \ buf_size = KYOPRO_BUFFER_SIZE>\n    struct Writer {\n    private:\n        int\
    \ fd, idx;\n        std::array<char, buf_size> buffer;\n\n    public:\n      \
    \  static constexpr KYOPRO_BASE_INT get_buf_size() noexcept {\n            return\
    \ buf_size;\n        }\n\n        Writer() noexcept = default;\n        Writer(int\
    \ fd) noexcept: fd(fd), idx(0), buffer() {}\n        Writer(FILE* fp) noexcept:\
    \ fd(fileno(fp)), idx(0), buffer() {}\n\n        ~Writer() {\n            write(fd,\
    \ buffer.begin(), idx);\n        }\n\n        struct iterator {\n        private:\n\
    \            Writer& writer;\n\n        public:\n            using difference_type\
    \ = void;\n            using value_type = void;\n            using pointer = void;\n\
    \            using reference = void;\n            using iterator_category = std::output_iterator_tag;\n\
    \n            iterator() noexcept = default;\n            iterator(Writer& writer)\
    \ noexcept: writer(writer) {}\n\n            iterator& operator ++() {\n     \
    \           ++writer.idx;\n                if (writer.idx == buf_size) {\n   \
    \             write(writer.fd, writer.buffer.begin(), buf_size);\n           \
    \     writer.idx = 0;\n                }\n                return *this;\n    \
    \        }\n\n            iterator operator ++(int) {\n                iterator\
    \ before = *this;\n                operator ++();\n                return before;\n\
    \            }\n\n            char& operator *() const {\n                return\
    \ writer.buffer[writer.idx];\n            }\n\n            void flush() const\
    \ {\n                write(writer.fd, writer.buffer.begin(), writer.idx);\n  \
    \          }\n        };\n\n        iterator begin() noexcept {\n            return\
    \ iterator(*this);\n        }\n    };\n\n    Writer output(1), error(2);\n\n \
    \   template<class Iterator, bool _sep = true, bool _sep_line = true, bool _end_line\
    \ = true, bool _debug = false, bool _comment = false, bool _flush = false, std::size_t\
    \ decimal_precision = KYOPRO_DECIMAL_PRECISION>\n    struct Printer {\n      \
    \  using iterator_type = Iterator;\n        static constexpr bool sep = _sep,\
    \ end_line = _end_line, sep_line = _sep_line, debug = _debug, comment = _comment,\
    \ flush = _flush;\n\n    private:\n        template<class, class = void>\n   \
    \     struct has_print: std::false_type {};\n        template<class T>\n     \
    \   struct has_print<T, std::void_t<decltype(std::declval<T>().print(std::declval<Printer&>()))>>:\
    \ std::true_type {};\n\n    public:\n        static constexpr KYOPRO_BASE_INT\
    \ get_decimal_precision() noexcept {\n            return decimal_precision;\n\
    \        }\n\n        template<class, class = void>\n        struct max_rank {\n\
    \            static constexpr std::size_t value = 0;\n        };\n        template<class\
    \ T>\n        struct max_rank<T, std::enable_if_t<is_tuple_like_v<T> && !is_range_v<T>>>\
    \ {\n            template<std::size_t... idx>\n            static constexpr bool\
    \ get_value_rank(std::index_sequence<idx...>) {\n                return std::max({max_rank<tuple_like_element_t<idx,\
    \ T>>::value...});\n            }\n            static constexpr std::size_t value\
    \ = get_value_rank(std::make_index_sequence<tuple_like_size_v<T>>()) + 1;\n  \
    \      };\n        template<class T>\n        struct max_rank<T, std::enable_if_t<is_range_v<T>>>\
    \ {\n            static constexpr std::size_t value = max_rank<range_value_t<T>>::value\
    \ + 1;\n        };\n\n        template<class T>\n        static constexpr KYOPRO_BASE_UINT\
    \ max_rank_v = max_rank<T>::value;\n\n        Iterator itr;\n\n        Printer()\
    \ noexcept = default;\n        Printer(Iterator itr) noexcept: itr(itr) {}\n\n\
    \        void print_char(char c) {\n            *itr = c;\n            ++itr;\n\
    \        }\n\n        template<std::size_t rank>\n        void print_sep() {\n\
    \            if constexpr (sep) {\n                if constexpr (debug) print_char(',');\n\
    \                if constexpr (sep_line && rank >= 2) {\n                    print_char('\\\
    n');\n                    if constexpr (comment) {\n                        print_char('#');\n\
    \                        print_char(' ');\n                    }\n           \
    \     } else print_char(' ');\n            }\n        }\n\n        void print(char\
    \ a) {\n            if constexpr (debug) print_char('\\'');\n            print_char(a);\n\
    \            if constexpr (debug) print_char('\\'');\n        }\n        void\
    \ print(bool a) {\n            print_char(static_cast<char>('0' + a));\n     \
    \   }\n        void print(const char* a) {\n            if constexpr (debug) print_char('\"\
    ');\n            for (; *a != '\\0'; ++a) print_char(*a);\n            if constexpr\
    \ (debug) print_char('\"');\n        }\n        template<std::size_t len>\n  \
    \      void print(const char (&a)[len]) {\n            if constexpr (debug) print_char('\"\
    ');\n            for (auto i: a) print_char(i);\n            if constexpr (debug)\
    \ print_char('\"');\n        }\n        void print(const std::string& a) {\n \
    \           if constexpr (debug) print_char('\"');\n            for (auto i: a)\
    \ print_char(i);\n            if constexpr (debug) print_char('\"');\n       \
    \ }\n        template<std::size_t len>\n        void print(const std::bitset<len>&\
    \ a) {\n            for (int i = len - 1; i >= 0; --i) print(a[i]);\n        }\n\
    \        template<class T, std::enable_if_t<std::is_arithmetic_v<T> && !has_print<T>::value>*\
    \ = nullptr>\n        void print(T a) {\n            if constexpr (std::is_floating_point_v<T>)\
    \ {\n                if (a == std::numeric_limits<T>::infinity()) {\n        \
    \        print(\"inf\");\n                return;\n                }\n       \
    \         if (a == -std::numeric_limits<T>::infinity()) {\n                print(\"\
    -inf\");\n                return;\n                }\n                if (std::isnan(a))\
    \ {\n                print(\"nan\");\n                return;\n              \
    \  }\n            }\n            if constexpr (std::is_signed_v<T>) if (a < 0)\
    \ {\n                print_char('-');\n                a = -a;\n            }\n\
    \            std::uint_fast64_t p = a;\n            std::string s;\n         \
    \   do {\n                s += '0' + p % 10;\n                p /= 10;\n     \
    \       } while (p > 0);\n            for (auto i = s.rbegin(); i != s.rend();\
    \ ++i) print_char(*i);\n            if constexpr (std::is_integral_v<T>) return;\n\
    \            print_char('.');\n            a -= p;\n            for (int i = 0;\
    \ i < static_cast<int>(decimal_precision); ++i) {\n                a *= 10;\n\
    \                print_char('0' + static_cast<std::uint_fast64_t>(a) % 10);\n\
    \            }\n        }\n        template<std::size_t i = 0, class T, std::enable_if_t<is_tuple_like_v<T>\
    \ && !is_range_v<T> && !has_print<T>::value>* = nullptr>\n        void print(const\
    \ T& a) {\n            if constexpr (debug && i == 0) print_char('{');\n     \
    \       if constexpr (tuple_like_size_v<T> != 0) print(get<i>(a));\n         \
    \   if constexpr (i + 1 < tuple_like_size_v<T>) {\n                print_sep<max_rank_v<T>>();\n\
    \                print<i + 1>(a);\n            } else if constexpr (debug) print_char('}');\n\
    \        }\n        template<class T, std::enable_if_t<is_range_v<T> && !has_print<T>::value>*\
    \ = nullptr>\n        void print(const T& a) {\n            if constexpr (debug)\
    \ print_char('{');\n            if (std::empty(a)) return;\n            for (auto\
    \ i = std::begin(a); ; ) {\n                print(*i);\n                if (++i\
    \ != std::end(a)) {\n                print_sep<max_rank_v<T>>();\n           \
    \     } else break;\n            }\n            if constexpr (debug) print_char('}');\n\
    \        }\n        template<class T, std::enable_if_t<has_print<T>::value>* =\
    \ nullptr>\n        void print(const T& a) {\n            a.print(*this);\n  \
    \      }\n\n        template<bool first = true>\n        void operator ()() {\n\
    \            if constexpr (comment && first) print_char('#');\n            if\
    \ constexpr (end_line) print_char('\\n');\n            if constexpr (flush) itr.flush();\n\
    \        }\n        template<bool first = true, class Head, class... Args>\n \
    \       void operator ()(Head&& head, Args&&... args) {\n            if constexpr\
    \ (comment && first) {\n                print_char('#');\n                print_char('\
    \ ');\n            }\n            if constexpr (sep && !first) print_sep<0>();\n\
    \            print(std::forward<Head>(head));\n            operator ()<false>(std::forward<Args>(args)...);\n\
    \        }\n    };\n\n    Printer<Writer<>::iterator, false, false, false> print(output.begin()),\
    \ eprint(error.begin());\n    Printer<Writer<>::iterator> println(output.begin()),\
    \ eprintln(error.begin());\n} // namespace kpr\n#line 9 \"all/all.hpp\"\n"
  code: '#pragma once

    #include "../algorithm/algorithm.hpp"

    #include "../function/function.hpp"

    #include "../math/math.hpp"

    #include "../meta/meta.hpp"

    #include "../range/range.hpp"

    #include "../structure/structure.hpp"

    #include "../system/system.hpp"

    '
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
  - structure/structure.hpp
  - structure/FenwickTree.hpp
  - structure/UnionFind.hpp
  - system/system.hpp
  - system/in.hpp
  - system/out.hpp
  isVerificationFile: false
  path: all/all.hpp
  requiredBy:
  - all.hpp
  timestamp: '2023-02-01 01:57:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: all/all.hpp
layout: document
redirect_from:
- /library/all/all.hpp
- /library/all/all.hpp.html
title: all/all.hpp
---
