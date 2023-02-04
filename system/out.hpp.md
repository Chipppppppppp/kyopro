---
data:
  _extendedDependsOn:
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
  - icon: ':x:'
    path: system/system.hpp
    title: system/system.hpp
  - icon: ':warning:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':warning:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/aoj/PrimeNumber.test.cpp
    title: verify/aoj/PrimeNumber.test.cpp
  - icon: ':x:'
    path: verify/yosupo/factorize.test.cpp
    title: verify/yosupo/factorize.test.cpp
  - icon: ':x:'
    path: verify/yosupo/many_aplusb.test.cpp
    title: verify/yosupo/many_aplusb.test.cpp
  - icon: ':x:'
    path: verify/yosupo/point_add_range_sum.test.cpp
    title: verify/yosupo/point_add_range_sum.test.cpp
  - icon: ':x:'
    path: verify/yosupo/unionfind.test.cpp
    title: verify/yosupo/unionfind.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"system/out.hpp\"\n#include <unistd.h>\n#include <algorithm>\n\
    #include <array>\n#include <bitset>\n#include <cmath>\n#include <cstdint>\n#include\
    \ <cstdio>\n#include <iterator>\n#include <string>\n#include <tuple>\n#include\
    \ <type_traits>\n#include <utility>\n#line 3 \"meta/setting.hpp\"\n\n#ifndef KYOPRO_BASE_INT\n\
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
    #endif\n#line 2 \"meta/trait.hpp\"\n#include <cstddef>\n#line 7 \"meta/trait.hpp\"\
    \n\nnamespace kpr {\n    namespace helper {\n        template<class T>\n     \
    \   struct is_integer_helper {\n            static constexpr bool value = std::is_integral_v<T>;\n\
    \        };\n\n        #ifdef __SIZEOF_INT128__\n        template<>\n        struct\
    \ is_integer_helper<__int128_t> {\n            static constexpr bool value = true;\n\
    \        };\n        template<>\n        struct is_integer_helper<__uint128_t>\
    \ {\n            static constexpr bool value = true;\n        };\n        #endif\n\
    \    } // namespace helper\n\n    // \u578BT\u304C\u6574\u6570\u304B\u8ABF\u3079\
    \u308B\n    template<class T>\n    struct is_integer {\n        static constexpr\
    \ bool value = helper::is_integer_helper<std::remove_cv_t<T>>::value;\n    };\n\
    \    // \u578BT\u304C\u6574\u6570\u304B\u8ABF\u3079\u308B\n    template<class\
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
    } // namespace kpr\n#line 7 \"meta/tuple_like.hpp\"\n\nnamespace kpr {\n    namespace\
    \ helper {\n        struct CastableToAny {\n            template<class T>\n  \
    \          operator T() const noexcept;\n        };\n\n        template<class\
    \ T, std::size_t... idx, std::void_t<decltype(T{((void)idx, CastableToAny{})...})>*\
    \ = nullptr>\n        constexpr bool is_aggregate_initializable(std::index_sequence<idx...>,\
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
    } // namespace kpr\n#line 17 \"system/out.hpp\"\n\nnamespace kpr {\n    // \u30D0\
    \u30C3\u30D5\u30A1\u3092\u7528\u3044\u3066\u30D5\u30A1\u30A4\u30EB\u306B\u66F8\
    \u304D\u8FBC\u3080\u30AF\u30E9\u30B9\n    template<std::size_t buf_size = KYOPRO_BUFFER_SIZE>\n\
    \    struct Writer {\n    private:\n        int fd, idx;\n        std::array<char,\
    \ buf_size> buffer;\n\n    public:\n        // \u30D0\u30C3\u30D5\u30A1\u30B5\u30A4\
    \u30BA\u3092\u53D6\u5F97\n        static constexpr KYOPRO_BASE_INT get_buf_size()\
    \ noexcept {\n            return buf_size;\n        }\n\n        Writer() noexcept\
    \ = default;\n        Writer(int fd) noexcept: fd(fd), idx(0), buffer() {}\n \
    \       Writer(FILE* fp) noexcept: fd(std::fileno(fp)), idx(0), buffer() {}\n\n\
    \        ~Writer() {\n            write(fd, buffer.begin(), idx);\n        }\n\
    \n        // \u51FA\u529B\u30A4\u30C6\u30EC\u30FC\u30BF\n        struct iterator\
    \ {\n        private:\n            Writer& writer;\n\n        public:\n      \
    \      using difference_type = void;\n            using value_type = void;\n \
    \           using pointer = void;\n            using reference = void;\n     \
    \       using iterator_category = std::output_iterator_tag;\n\n            iterator()\
    \ noexcept = default;\n            iterator(Writer& writer) noexcept: writer(writer)\
    \ {}\n\n            iterator& operator ++() {\n                ++writer.idx;\n\
    \                if (writer.idx == buf_size) {\n                write(writer.fd,\
    \ writer.buffer.begin(), buf_size);\n                writer.idx = 0;\n       \
    \         }\n                return *this;\n            }\n\n            iterator\
    \ operator ++(int) {\n                iterator before = *this;\n             \
    \   operator ++();\n                return before;\n            }\n\n        \
    \    char& operator *() const {\n                return writer.buffer[writer.idx];\n\
    \            }\n\n            // \u30D0\u30C3\u30D5\u30A1\u3092\u5168\u3066\u51FA\
    \u529B\u3059\u308B\n            void flush() const {\n                write(writer.fd,\
    \ writer.buffer.begin(), writer.idx);\n            }\n        };\n\n        //\
    \ \u30D5\u30A1\u30A4\u30EB\u306E\u6700\u521D\u3092\u793A\u3059\u30A4\u30C6\u30EC\
    \u30FC\u30BF\u3092\u53D6\u5F97\n        iterator begin() noexcept {\n        \
    \    return iterator(*this);\n        }\n    };\n\n    // \u6A19\u6E96\u51FA\u529B\
    \u3001\u6A19\u6E96\u30A8\u30E9\u30FC\u51FA\u529B\n    Writer output(1), error(2);\n\
    \n    // \u51FA\u529B\u30A4\u30C6\u30EC\u30FC\u30BF\u3092\u7528\u3044\u3066\u5024\
    \u3092\u51FA\u529B\u3059\u308B\u30AF\u30E9\u30B9\n    template<class Iterator,\
    \ bool _sep = true, bool _sep_line = true, bool _end_line = true, bool _debug\
    \ = false, bool _comment = false, bool _flush = false, std::size_t decimal_precision\
    \ = KYOPRO_DECIMAL_PRECISION>\n    struct Printer {\n        using iterator_type\
    \ = Iterator;\n\n        // \u6307\u5B9A\u3055\u308C\u305F\u30AA\u30D7\u30B7\u30E7\
    \u30F3\u3092\u53D6\u5F97\n        static constexpr bool sep = _sep, end_line =\
    \ _end_line, sep_line = _sep_line, debug = _debug, comment = _comment, flush =\
    \ _flush;\n\n        // \u6307\u5B9A\u3055\u308C\u305F\u5C0F\u6570\u8AA4\u5DEE\
    \u3092\u53D6\u5F97\n        static constexpr KYOPRO_BASE_INT get_decimal_precision()\
    \ noexcept {\n            return decimal_precision;\n        }\n\n        // \u51FA\
    \u529B\u30A4\u30C6\u30EC\u30FC\u30BF\n        Iterator itr;\n\n        Printer()\
    \ noexcept = default;\n        Printer(Iterator itr) noexcept: itr(itr) {}\n\n\
    \        // \u4E00\u6587\u5B57\u51FA\u529B\u3059\u308B\n        void print_char(char\
    \ c) {\n            *itr = c;\n            ++itr;\n        }\n\n        // \u533A\
    \u5207\u308A\u6587\u5B57\u3092\u51FA\u529B\u3059\u308B\n        void print_sep()\
    \ {\n            if constexpr (sep) {\n                if constexpr (debug) print_char(',');\n\
    \                print_char(' ');\n            }\n        }\n\n        // \u5024\
    \u306E\u51FA\u529B\u306E\u95A2\u6570\u30AF\u30E9\u30B9\n        template<class,\
    \ class = void>\n        struct PrintFunction;\n\n        template<class T>\n\
    \        struct PrintFunction<char, T> {\n            static void print(Printer&\
    \ printer, char a) {\n                if constexpr (debug) printer.print_char('\\\
    '');\n                printer.print_char(a);\n                if constexpr (debug)\
    \ printer.print_char('\\'');\n            }\n        };\n\n        template<class\
    \ T>\n        struct PrintFunction<bool, T> {\n            static void print(Printer&\
    \ printer, bool a) {\n                printer.print_char(static_cast<char>('0'\
    \ + a));\n            }\n        };\n\n        template<class T>\n        struct\
    \ PrintFunction<T, std::enable_if_t<std::is_convertible_v<T, std::string_view>>>\
    \ {\n            static void print(Printer& printer, std::string_view a) {\n \
    \               if constexpr (debug) printer.print_char('\"');\n             \
    \   for (; *a != '\\0'; ++a) printer.print_char(*a);\n                if constexpr\
    \ (debug) printer.print_char('\"');\n            }\n        };\n\n        template<std::size_t\
    \ len>\n        struct PrintFunction<std::bitset<len>> {\n            static void\
    \ print(Printer& printer, const std::bitset<len>& a) {\n                for (int\
    \ i = len - 1; i >= 0; --i) PrintFunction<bool>::print(a[i]);\n            }\n\
    \        };\n\n        template<class T>\n        struct PrintFunction<T, std::enable_if_t<std::is_arithmetic_v<T>>>\
    \ {\n            static void print(Printer& printer, T a) {\n                if\
    \ constexpr (std::is_floating_point_v<T>) {\n                    if (a == std::numeric_limits<T>::infinity())\
    \ {\n                        PrintFunction<const char*>::print(\"inf\");\n   \
    \                     return;\n                    }\n                    if (a\
    \ == -std::numeric_limits<T>::infinity()) {\n                        PrintFunction<const\
    \ char*>::print(\"-inf\");\n                        return;\n                \
    \    }\n                    if (std::isnan(a)) {\n                        PrintFunction<const\
    \ char*>::print(\"nan\");\n                        return;\n                 \
    \   }\n                }\n                if constexpr (std::is_signed_v<T>) if\
    \ (a < 0) {\n                    printer.print_char('-');\n                  \
    \  a = -a;\n                }\n                std::uint_fast64_t p = a;\n   \
    \             std::string s;\n                do {\n                    s += '0'\
    \ + p % 10;\n                    p /= 10;\n                } while (p > 0);\n\
    \                for (auto i = s.rbegin(); i != s.rend(); ++i) printer.print_char(*i);\n\
    \                if constexpr (std::is_integral_v<T>) return;\n              \
    \  printer.print_char('.');\n                a -= p;\n                for (int\
    \ i = 0; i < static_cast<int>(decimal_precision); ++i) {\n                   \
    \ a *= 10;\n                    printer.print_char('0' + static_cast<std::uint_fast64_t>(a)\
    \ % 10);\n                }\n            }\n        };\n\n        template<class\
    \ T>\n        struct PrintFunction<T, std::enable_if_t<is_tuple_like_v<T> && !is_range_v<T>>>\
    \ {\n            template<std::size_t i = 0>\n            static void print(Printer&\
    \ printer, const T& a) {\n                if constexpr (debug && i == 0) printer.print_char('{');\n\
    \                if constexpr (tuple_like_size_v<T> != 0) print(get<i>(a));\n\
    \                if constexpr (i + 1 < tuple_like_size_v<T>) {\n             \
    \       printer.print_sep<max_rank_v<T>>();\n                    PrintFunction<>::print<i\
    \ + 1>(a);\n                } else if constexpr (debug) print_char('}');\n   \
    \         }\n        };\n\n        template<class T>\n        struct PrintFunction<T,\
    \ std::enable_if_t<is_range_v<T>>> {\n            static void print(Printer& printer,\
    \ const T& a) {\n                if constexpr (debug) print_char('{');\n     \
    \           if (std::empty(a)) return;\n                for (auto i = std::begin(a);\
    \ ; ) {\n                    print(*i);\n                    if (++i != std::end(a))\
    \ {\n                    print_sep<max_rank_v<T>>();\n                    } else\
    \ break;\n                }\n                if constexpr (debug) print_char('}');\n\
    \            }\n        };\n\n        // \u8907\u6570\u306E\u5024\u3092\u51FA\u529B\
    \n        template<bool first = true>\n        void operator ()() {\n        \
    \    if constexpr (comment && first) print_char('#');\n            if constexpr\
    \ (end_line) print_char('\\n');\n            if constexpr (flush) itr.flush();\n\
    \        }\n        template<bool first = true, class Head, class... Args>\n \
    \       void operator ()(Head&& head, Args&&... args) {\n            if constexpr\
    \ (comment && first) {\n                print_char('#');\n                print_char('\
    \ ');\n            }\n            if constexpr (sep && !first) print_sep<0>();\n\
    \            PrintFunction<std::decay_t<Head>>::print(std::forward<Head>(head));\n\
    \            operator ()<false>(std::forward<Args>(args)...);\n        }\n   \
    \ };\n\n    // \u6A19\u6E96\u51FA\u529B\u3001\u6A19\u6E96\u30A8\u30E9\u30FC\u51FA\
    \u529B\u306B\u5024\u3092\u51FA\u529B\u3059\u308B(\u6539\u884C\u3001\u533A\u5207\
    \u308A\u6587\u5B57\u306A\u3057)\n    Printer<Writer<>::iterator, false, false,\
    \ false> print(output.begin()), eprint(error.begin());\n\n    // \u6A19\u6E96\u51FA\
    \u529B\u3001\u6A19\u6E96\u30A8\u30E9\u30FC\u51FA\u529B\u306B\u5024\u3092\u51FA\
    \u529B\u3059\u308B(\u6539\u884C\u3001\u533A\u5207\u308A\u6587\u5B57\u3042\u308A\
    )\n    Printer<Writer<>::iterator> println(output.begin()), eprintln(error.begin());\n\
    } // namespace kpr\n"
  code: "#pragma once\n#include <unistd.h>\n#include <algorithm>\n#include <array>\n\
    #include <bitset>\n#include <cmath>\n#include <cstdint>\n#include <cstdio>\n#include\
    \ <iterator>\n#include <string>\n#include <tuple>\n#include <type_traits>\n#include\
    \ <utility>\n#include \"../meta/setting.hpp\"\n#include \"../meta/trait.hpp\"\n\
    #include \"../meta/tuple_like.hpp\"\n\nnamespace kpr {\n    // \u30D0\u30C3\u30D5\
    \u30A1\u3092\u7528\u3044\u3066\u30D5\u30A1\u30A4\u30EB\u306B\u66F8\u304D\u8FBC\
    \u3080\u30AF\u30E9\u30B9\n    template<std::size_t buf_size = KYOPRO_BUFFER_SIZE>\n\
    \    struct Writer {\n    private:\n        int fd, idx;\n        std::array<char,\
    \ buf_size> buffer;\n\n    public:\n        // \u30D0\u30C3\u30D5\u30A1\u30B5\u30A4\
    \u30BA\u3092\u53D6\u5F97\n        static constexpr KYOPRO_BASE_INT get_buf_size()\
    \ noexcept {\n            return buf_size;\n        }\n\n        Writer() noexcept\
    \ = default;\n        Writer(int fd) noexcept: fd(fd), idx(0), buffer() {}\n \
    \       Writer(FILE* fp) noexcept: fd(std::fileno(fp)), idx(0), buffer() {}\n\n\
    \        ~Writer() {\n            write(fd, buffer.begin(), idx);\n        }\n\
    \n        // \u51FA\u529B\u30A4\u30C6\u30EC\u30FC\u30BF\n        struct iterator\
    \ {\n        private:\n            Writer& writer;\n\n        public:\n      \
    \      using difference_type = void;\n            using value_type = void;\n \
    \           using pointer = void;\n            using reference = void;\n     \
    \       using iterator_category = std::output_iterator_tag;\n\n            iterator()\
    \ noexcept = default;\n            iterator(Writer& writer) noexcept: writer(writer)\
    \ {}\n\n            iterator& operator ++() {\n                ++writer.idx;\n\
    \                if (writer.idx == buf_size) {\n                write(writer.fd,\
    \ writer.buffer.begin(), buf_size);\n                writer.idx = 0;\n       \
    \         }\n                return *this;\n            }\n\n            iterator\
    \ operator ++(int) {\n                iterator before = *this;\n             \
    \   operator ++();\n                return before;\n            }\n\n        \
    \    char& operator *() const {\n                return writer.buffer[writer.idx];\n\
    \            }\n\n            // \u30D0\u30C3\u30D5\u30A1\u3092\u5168\u3066\u51FA\
    \u529B\u3059\u308B\n            void flush() const {\n                write(writer.fd,\
    \ writer.buffer.begin(), writer.idx);\n            }\n        };\n\n        //\
    \ \u30D5\u30A1\u30A4\u30EB\u306E\u6700\u521D\u3092\u793A\u3059\u30A4\u30C6\u30EC\
    \u30FC\u30BF\u3092\u53D6\u5F97\n        iterator begin() noexcept {\n        \
    \    return iterator(*this);\n        }\n    };\n\n    // \u6A19\u6E96\u51FA\u529B\
    \u3001\u6A19\u6E96\u30A8\u30E9\u30FC\u51FA\u529B\n    Writer output(1), error(2);\n\
    \n    // \u51FA\u529B\u30A4\u30C6\u30EC\u30FC\u30BF\u3092\u7528\u3044\u3066\u5024\
    \u3092\u51FA\u529B\u3059\u308B\u30AF\u30E9\u30B9\n    template<class Iterator,\
    \ bool _sep = true, bool _sep_line = true, bool _end_line = true, bool _debug\
    \ = false, bool _comment = false, bool _flush = false, std::size_t decimal_precision\
    \ = KYOPRO_DECIMAL_PRECISION>\n    struct Printer {\n        using iterator_type\
    \ = Iterator;\n\n        // \u6307\u5B9A\u3055\u308C\u305F\u30AA\u30D7\u30B7\u30E7\
    \u30F3\u3092\u53D6\u5F97\n        static constexpr bool sep = _sep, end_line =\
    \ _end_line, sep_line = _sep_line, debug = _debug, comment = _comment, flush =\
    \ _flush;\n\n        // \u6307\u5B9A\u3055\u308C\u305F\u5C0F\u6570\u8AA4\u5DEE\
    \u3092\u53D6\u5F97\n        static constexpr KYOPRO_BASE_INT get_decimal_precision()\
    \ noexcept {\n            return decimal_precision;\n        }\n\n        // \u51FA\
    \u529B\u30A4\u30C6\u30EC\u30FC\u30BF\n        Iterator itr;\n\n        Printer()\
    \ noexcept = default;\n        Printer(Iterator itr) noexcept: itr(itr) {}\n\n\
    \        // \u4E00\u6587\u5B57\u51FA\u529B\u3059\u308B\n        void print_char(char\
    \ c) {\n            *itr = c;\n            ++itr;\n        }\n\n        // \u533A\
    \u5207\u308A\u6587\u5B57\u3092\u51FA\u529B\u3059\u308B\n        void print_sep()\
    \ {\n            if constexpr (sep) {\n                if constexpr (debug) print_char(',');\n\
    \                print_char(' ');\n            }\n        }\n\n        // \u5024\
    \u306E\u51FA\u529B\u306E\u95A2\u6570\u30AF\u30E9\u30B9\n        template<class,\
    \ class = void>\n        struct PrintFunction;\n\n        template<class T>\n\
    \        struct PrintFunction<char, T> {\n            static void print(Printer&\
    \ printer, char a) {\n                if constexpr (debug) printer.print_char('\\\
    '');\n                printer.print_char(a);\n                if constexpr (debug)\
    \ printer.print_char('\\'');\n            }\n        };\n\n        template<class\
    \ T>\n        struct PrintFunction<bool, T> {\n            static void print(Printer&\
    \ printer, bool a) {\n                printer.print_char(static_cast<char>('0'\
    \ + a));\n            }\n        };\n\n        template<class T>\n        struct\
    \ PrintFunction<T, std::enable_if_t<std::is_convertible_v<T, std::string_view>>>\
    \ {\n            static void print(Printer& printer, std::string_view a) {\n \
    \               if constexpr (debug) printer.print_char('\"');\n             \
    \   for (; *a != '\\0'; ++a) printer.print_char(*a);\n                if constexpr\
    \ (debug) printer.print_char('\"');\n            }\n        };\n\n        template<std::size_t\
    \ len>\n        struct PrintFunction<std::bitset<len>> {\n            static void\
    \ print(Printer& printer, const std::bitset<len>& a) {\n                for (int\
    \ i = len - 1; i >= 0; --i) PrintFunction<bool>::print(a[i]);\n            }\n\
    \        };\n\n        template<class T>\n        struct PrintFunction<T, std::enable_if_t<std::is_arithmetic_v<T>>>\
    \ {\n            static void print(Printer& printer, T a) {\n                if\
    \ constexpr (std::is_floating_point_v<T>) {\n                    if (a == std::numeric_limits<T>::infinity())\
    \ {\n                        PrintFunction<const char*>::print(\"inf\");\n   \
    \                     return;\n                    }\n                    if (a\
    \ == -std::numeric_limits<T>::infinity()) {\n                        PrintFunction<const\
    \ char*>::print(\"-inf\");\n                        return;\n                \
    \    }\n                    if (std::isnan(a)) {\n                        PrintFunction<const\
    \ char*>::print(\"nan\");\n                        return;\n                 \
    \   }\n                }\n                if constexpr (std::is_signed_v<T>) if\
    \ (a < 0) {\n                    printer.print_char('-');\n                  \
    \  a = -a;\n                }\n                std::uint_fast64_t p = a;\n   \
    \             std::string s;\n                do {\n                    s += '0'\
    \ + p % 10;\n                    p /= 10;\n                } while (p > 0);\n\
    \                for (auto i = s.rbegin(); i != s.rend(); ++i) printer.print_char(*i);\n\
    \                if constexpr (std::is_integral_v<T>) return;\n              \
    \  printer.print_char('.');\n                a -= p;\n                for (int\
    \ i = 0; i < static_cast<int>(decimal_precision); ++i) {\n                   \
    \ a *= 10;\n                    printer.print_char('0' + static_cast<std::uint_fast64_t>(a)\
    \ % 10);\n                }\n            }\n        };\n\n        template<class\
    \ T>\n        struct PrintFunction<T, std::enable_if_t<is_tuple_like_v<T> && !is_range_v<T>>>\
    \ {\n            template<std::size_t i = 0>\n            static void print(Printer&\
    \ printer, const T& a) {\n                if constexpr (debug && i == 0) printer.print_char('{');\n\
    \                if constexpr (tuple_like_size_v<T> != 0) print(get<i>(a));\n\
    \                if constexpr (i + 1 < tuple_like_size_v<T>) {\n             \
    \       printer.print_sep<max_rank_v<T>>();\n                    PrintFunction<>::print<i\
    \ + 1>(a);\n                } else if constexpr (debug) print_char('}');\n   \
    \         }\n        };\n\n        template<class T>\n        struct PrintFunction<T,\
    \ std::enable_if_t<is_range_v<T>>> {\n            static void print(Printer& printer,\
    \ const T& a) {\n                if constexpr (debug) print_char('{');\n     \
    \           if (std::empty(a)) return;\n                for (auto i = std::begin(a);\
    \ ; ) {\n                    print(*i);\n                    if (++i != std::end(a))\
    \ {\n                    print_sep<max_rank_v<T>>();\n                    } else\
    \ break;\n                }\n                if constexpr (debug) print_char('}');\n\
    \            }\n        };\n\n        // \u8907\u6570\u306E\u5024\u3092\u51FA\u529B\
    \n        template<bool first = true>\n        void operator ()() {\n        \
    \    if constexpr (comment && first) print_char('#');\n            if constexpr\
    \ (end_line) print_char('\\n');\n            if constexpr (flush) itr.flush();\n\
    \        }\n        template<bool first = true, class Head, class... Args>\n \
    \       void operator ()(Head&& head, Args&&... args) {\n            if constexpr\
    \ (comment && first) {\n                print_char('#');\n                print_char('\
    \ ');\n            }\n            if constexpr (sep && !first) print_sep<0>();\n\
    \            PrintFunction<std::decay_t<Head>>::print(std::forward<Head>(head));\n\
    \            operator ()<false>(std::forward<Args>(args)...);\n        }\n   \
    \ };\n\n    // \u6A19\u6E96\u51FA\u529B\u3001\u6A19\u6E96\u30A8\u30E9\u30FC\u51FA\
    \u529B\u306B\u5024\u3092\u51FA\u529B\u3059\u308B(\u6539\u884C\u3001\u533A\u5207\
    \u308A\u6587\u5B57\u306A\u3057)\n    Printer<Writer<>::iterator, false, false,\
    \ false> print(output.begin()), eprint(error.begin());\n\n    // \u6A19\u6E96\u51FA\
    \u529B\u3001\u6A19\u6E96\u30A8\u30E9\u30FC\u51FA\u529B\u306B\u5024\u3092\u51FA\
    \u529B\u3059\u308B(\u6539\u884C\u3001\u533A\u5207\u308A\u6587\u5B57\u3042\u308A\
    )\n    Printer<Writer<>::iterator> println(output.begin()), eprintln(error.begin());\n\
    } // namespace kpr\n"
  dependsOn:
  - meta/setting.hpp
  - meta/trait.hpp
  - meta/tuple_like.hpp
  isVerificationFile: false
  path: system/out.hpp
  requiredBy:
  - all/all.hpp
  - system/system.hpp
  - template/template.hpp
  - template/macro.hpp
  - all.hpp
  timestamp: '2023-02-04 13:16:05+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/aoj/PrimeNumber.test.cpp
  - verify/yosupo/point_add_range_sum.test.cpp
  - verify/yosupo/unionfind.test.cpp
  - verify/yosupo/factorize.test.cpp
  - verify/yosupo/many_aplusb.test.cpp
documentation_of: system/out.hpp
layout: document
redirect_from:
- /library/system/out.hpp
- /library/system/out.hpp.html
title: system/out.hpp
---
