---
data:
  _extendedDependsOn:
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
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  - icon: ':warning:'
    path: all/all.hpp
    title: all/all.hpp
  - icon: ':warning:'
    path: function/function.hpp
    title: function/function.hpp
  - icon: ':x:'
    path: structure/FenwickTree.hpp
    title: structure/FenwickTree.hpp
  - icon: ':warning:'
    path: structure/structure.hpp
    title: structure/structure.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo/point_add_range_sum.test.cpp
    title: verify/yosupo/point_add_range_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"function/monoid.hpp\"\n#include <limits>\n#include <type_traits>\n\
    #line 2 \"math/power.hpp\"\n#include <cstdint>\n\nnamespace kpr {\n    [[maybe_unused]]\
    \ inline constexpr struct {\n        template<class T>\n        constexpr T operator\
    \ ()(T a, std::uint_fast64_t n, T init = 1) const noexcept {\n            while\
    \ (n > 0) {\n                if (n & 1) init *= a;\n                a *= a;\n\
    \                n >>= 1;\n            }\n            return init;\n        }\n\
    \    } power;\n} // namespace kpr\n#line 3 \"meta/setting.hpp\"\n\n#ifndef KYOPRO_BASE_INT\n\
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
    #endif\n#line 5 \"meta/constant.hpp\"\n\nnamespace kpr {\n    // \u554F\u984C\u3067\
    \u8A2D\u5B9A\u3055\u308C\u305Fmod\n    template<class T>\n    inline constexpr\
    \ T MOD = KYOPRO_DEFAULT_MOD;\n    // \u554F\u984C\u3067\u8A2D\u5B9A\u3055\u308C\
    \u305Fmod\n    inline constexpr KYOPRO_BASE_INT mod = MOD<KYOPRO_BASE_INT>;\n\n\
    \    // \u7121\u9650\u5927\u3092\u8868\u3059\u6574\u6570\n    template<class T>\n\
    \    inline constexpr T INF = std::numeric_limits<T>::max() / KYOPRO_INF_DIV;\n\
    \    // \u7121\u9650\u5927\u3092\u8868\u3059\u6574\u6570\n    inline constexpr\
    \ KYOPRO_BASE_INT inf = INF<KYOPRO_BASE_INT>;\n\n    // \u8A31\u5BB9\u3055\u308C\
    \u308B\u5C0F\u6570\u8AA4\u5DEE\n    template<class T, KYOPRO_BASE_UINT decimal_precision\
    \ = KYOPRO_DECIMAL_PRECISION>\n    inline constexpr KYOPRO_BASE_FLOAT EPS = static_cast<T>(1)\
    \ / power(10ULL, decimal_precision);\n    // \u8A31\u5BB9\u3055\u308C\u308B\u5C0F\
    \u6570\u8AA4\u5DEE\n    inline constexpr KYOPRO_BASE_FLOAT eps = EPS<KYOPRO_BASE_FLOAT>;\n\
    \n    // \u5186\u5468\u7387\n    template<class T>\n    inline constexpr T PI\
    \ = 3.14159265358979323846;\n    // \u5186\u5468\u7387\n    inline constexpr KYOPRO_BASE_FLOAT\
    \ pi = PI<KYOPRO_BASE_FLOAT>;\n} // namespace kpr\n#line 2 \"meta/trait.hpp\"\n\
    #include <cstddef>\n#include <iterator>\n#include <tuple>\n#line 6 \"meta/trait.hpp\"\
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
    } // namespace kpr\n#line 6 \"function/monoid.hpp\"\n\nnamespace kpr {\n    //\
    \ \u8DB3\u3057\u7B97\u306Emonoid\n    template<class T>\n    struct Add {\n  \
    \      static_assert(is_arithmetic_v<T>, \"T must be an arithmetic type\");\n\n\
    \        using value_type = T;\n\n        constexpr T id() const noexcept {\n\
    \            return T{};\n        }\n\n        constexpr T operator ()(const T&\
    \ a, const T& b) const noexcept {\n            return a + b;\n        }\n\n  \
    \      constexpr T inverse(const T& a) const noexcept {\n            static_assert(std::is_signed_v<T>,\
    \ \"T must be a signed type\");\n            return -a;\n        }\n    };\n\n\
    \    // \u639B\u3051\u7B97\u306Emonoid\n    template<class T>\n    struct Mul\
    \ {\n        static_assert(is_arithmetic_v<T>, \"T must be an arithmetic type\"\
    );\n\n        using value_type = T;\n\n        constexpr T id() const noexcept\
    \ {\n            return 1;\n        }\n\n        constexpr T operator ()(const\
    \ T& a, const T& b) const noexcept {\n            return a * b;\n        }\n\n\
    \        constexpr T inverse(const T& a) const noexcept {\n            return\
    \ 1 / a;\n        }\n    };\n\n    // min\u306Emonoid\n    template<class T>\n\
    \    struct Min {\n        static_assert(is_arithmetic_v<T>, \"T must be an arithmetic\
    \ type\");\n\n        using value_type = T;\n\n        constexpr T id() const\
    \ noexcept {\n            return std::numeric_limits<T>::has_infinity ? -std::numeric_limits<T>::infinity()\
    \ : INF<T>;\n        }\n\n        constexpr T operator ()(const T& a, const T&\
    \ b) const noexcept {\n            return a < b ? a : b;\n        }\n    };\n\n\
    \    // max\u306Emonoid\n    template<class T>\n    struct Max {\n        static_assert(is_arithmetic_v<T>,\
    \ \"T must be an arithmetic type\");\n\n        using value_type = T;\n\n    \
    \    constexpr T id() const noexcept {\n            return std::numeric_limits<T>::has_infinity\
    \ ? -std::numeric_limits<T>::infinity() : (std::is_signed_v<T> ? -INF<T> : 0);\n\
    \        }\n\n        constexpr T operator ()(const T& a, const T& b) const noexcept\
    \ {\n            return a > b ? a : b;\n        }\n    };\n\n\n    // inverse\u3092\
    \u6301\u3064\u304B\u8ABF\u3079\u308B\n    template<class, class = void>\n    struct\
    \ has_inverse {\n        static constexpr bool value = false;\n    };\n\n    template<class\
    \ T>\n    struct has_inverse<T, std::void_t<decltype(&T::inverse)>> {\n      \
    \  static constexpr bool value = true;\n    };\n\n    // inverse\u3092\u6301\u3064\
    \u304B\u8ABF\u3079\u308B\n    template<class T>\n    inline constexpr bool has_inverse_v\
    \ = has_inverse<T>::value;\n} // namespace kpr\n"
  code: "#pragma once\n#include <limits>\n#include <type_traits>\n#include \"../meta/constant.hpp\"\
    \n#include \"../meta/trait.hpp\"\n\nnamespace kpr {\n    // \u8DB3\u3057\u7B97\
    \u306Emonoid\n    template<class T>\n    struct Add {\n        static_assert(is_arithmetic_v<T>,\
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
    \ ? -std::numeric_limits<T>::infinity() : INF<T>;\n        }\n\n        constexpr\
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
    \ = has_inverse<T>::value;\n} // namespace kpr\n"
  dependsOn:
  - meta/constant.hpp
  - math/power.hpp
  - meta/setting.hpp
  - meta/trait.hpp
  isVerificationFile: false
  path: function/monoid.hpp
  requiredBy:
  - all/all.hpp
  - function/function.hpp
  - structure/structure.hpp
  - structure/FenwickTree.hpp
  - all.hpp
  timestamp: '2023-02-04 13:16:05+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo/point_add_range_sum.test.cpp
documentation_of: function/monoid.hpp
layout: document
redirect_from:
- /library/function/monoid.hpp
- /library/function/monoid.hpp.html
title: function/monoid.hpp
---
