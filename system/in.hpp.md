---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/power.hpp
    title: math/power.hpp
  - icon: ':x:'
    path: meta/setting.hpp
    title: meta/setting.hpp
  - icon: ':x:'
    path: meta/trait.hpp
    title: meta/trait.hpp
  - icon: ':x:'
    path: meta/tuple_like.hpp
    title: meta/tuple_like.hpp
  - icon: ':x:'
    path: system/io_option.hpp
    title: system/io_option.hpp
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
  bundledCode: "#line 2 \"system/in.hpp\"\n#include <unistd.h>\n#include <array>\n\
    #include <bitset>\n#include <cstddef>\n#include <cstdint>\n#include <cstdio>\n\
    #include <string>\n#include <type_traits>\n#include <utility>\n#line 3 \"system/io_option.hpp\"\
    \n#include <tuple>\n#line 5 \"system/io_option.hpp\"\n\nnamespace kpr {\n    template<class\
    \ Tuple, std::size_t idx>\n    struct Indexed {\n        Tuple args_tuple;\n \
    \       template<class... Args>\n        constexpr Indexed(Args&&... args) noexcept:\
    \ args_tuple{std::forward<Args>(args)...} {}\n    };\n\n    template<std::size_t\
    \ i, class... Args>\n    constexpr auto indexed(Args&&... args) noexcept {\n \
    \       return Indexed<std::tuple<Args>..., i>{std::forward<Args>(args)...};\n\
    \    }\n\n    template<class Tuple, bool... seps>\n    struct SepWith {\n    \
    \    Tuple args_tuple;\n        template<class... Args>\n        constexpr SepWith(Args&&...\
    \ args) noexcept: args_tuple{std::forward<Args>(args)...} {}\n    };\n\n    template<bool...\
    \ seps, class... Args>\n    constexpr auto sep_with(Args&&... args) noexcept {\n\
    \        return SepWith<std::tuple<Args...>, seps...>{std::forward<Args>(args)...};\n\
    \    }\n} // namespace kpr\n#line 3 \"math/power.hpp\"\n\nnamespace kpr {\n  \
    \  [[maybe_unused]] inline constexpr struct {\n        template<class T>\n   \
    \     constexpr T operator ()(T a, std::uint_fast64_t n, T init = 1) const noexcept\
    \ {\n            while (n > 0) {\n                if (n & 1) init *= a;\n    \
    \            a *= a;\n                n >>= 1;\n            }\n            return\
    \ init;\n        }\n    } power;\n} // namespace kpr\n#line 3 \"meta/setting.hpp\"\
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
    \ 3 \"meta/trait.hpp\"\n#include <iterator>\n#line 7 \"meta/trait.hpp\"\n\nnamespace\
    \ kpr {\n    namespace helper {\n        template<class T>\n        struct is_integer_helper\
    \ {\n            static constexpr bool value = std::is_integral_v<T>;\n      \
    \  };\n\n        #ifdef __SIZEOF_INT128__\n        template<>\n        struct\
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
    } // namespace kpr\n#line 16 \"system/in.hpp\"\n\nnamespace kpr {\n    // \u30D0\
    \u30C3\u30D5\u30A1\u3092\u7528\u3044\u3066\u30D5\u30A1\u30A4\u30EB\u3092\u8AAD\
    \u307F\u8FBC\u3080\u30AF\u30E9\u30B9\n    template<std::size_t buf_size = KYOPRO_BUFFER_SIZE>\n\
    \    struct Reader {\n    private:\n        int fd, idx;\n        std::array<char,\
    \ buf_size> buffer;\n\n    public:\n        // \u30D0\u30C3\u30D5\u30A1\u30B5\u30A4\
    \u30BA\u3092\u53D6\u5F97\n        static constexpr KYOPRO_BASE_INT get_buf_size()\
    \ noexcept {\n            return buf_size;\n        }\n\n        Reader() {\n\
    \            read(fd, buffer.begin(), buf_size);\n        }\n        Reader(int\
    \ fd): fd(fd), idx(0), buffer() {\n            read(fd, buffer.begin(), buf_size);\n\
    \        }\n        Reader(FILE* fp): fd(fileno(fp)), idx(0), buffer() {\n   \
    \         read(fd, buffer.begin(), buf_size);\n        }\n\n        // \u5165\u529B\
    \u30A4\u30C6\u30EC\u30FC\u30BF\n        struct iterator {\n        private:\n\
    \            Reader& reader;\n\n        public:\n            using difference_type\
    \ = void;\n            using value_type = void;\n            using pointer = void;\n\
    \            using reference = void;\n            using iterator_category = std::input_iterator_tag;\n\
    \n            iterator() noexcept = default;\n            iterator(Reader& reader)\
    \ noexcept: reader(reader) {}\n\n            iterator& operator ++() {\n     \
    \           ++reader.idx;\n                if (reader.idx == buf_size) {\n   \
    \                 read(reader.fd, reader.buffer.begin(), buf_size);\n        \
    \            reader.idx = 0;\n                }\n                return *this;\n\
    \            }\n\n            iterator operator ++(int) {\n                iterator\
    \ before = *this;\n                operator ++();\n                return before;\n\
    \            }\n\n            char& operator *() const {\n                return\
    \ reader.buffer[reader.idx];\n            }\n        };\n\n        // \u30D5\u30A1\
    \u30A4\u30EB\u306E\u6700\u521D\u3092\u793A\u3059\u30A4\u30C6\u30EC\u30FC\u30BF\
    \u3092\u53D6\u5F97\n        iterator begin() noexcept {\n            return iterator(*this);\n\
    \        }\n    };\n\n    // \u6A19\u6E96\u5165\u529B\n    Reader input{0};\n\n\
    \n    // \u5024\u306E\u5165\u529B\u306E\u95A2\u6570\u30AF\u30E9\u30B9\n    template<class,\
    \ class = void>\n    struct ScanFunction;\n\n    // \u5165\u529B\u30A4\u30C6\u30EC\
    \u30FC\u30BF\u3092\u7528\u3044\u3066\u5024\u3092\u5165\u529B\u3059\u308B\u30AF\
    \u30E9\u30B9\n    template<class Iterator, std::size_t decimal_precision = KYOPRO_DECIMAL_PRECISION>\n\
    \    struct Scanner {\n        using iterator_type = Iterator;\n\n        // \u5165\
    \u529B\u30A4\u30C6\u30EC\u30FC\u30BF\n        Iterator itr;\n\n        // \u6307\
    \u5B9A\u3055\u308C\u305F\u5C0F\u6570\u8AA4\u5DEE\u3092\u53D6\u5F97\n        static\
    \ constexpr KYOPRO_BASE_INT get_decimal_precision() noexcept {\n            return\
    \ decimal_precision;\n        }\n\n        Scanner() noexcept = default;\n   \
    \     Scanner(Iterator itr) noexcept: itr(itr) {}\n\n        // \u6B21\u306E\u6587\
    \u5B57\u307E\u3067\u306E\u7A7A\u767D\u3092\u7121\u8996\u3059\u308B\n        void\
    \ discard_space() {\n            while (('\\t' <= *itr && *itr <= '\\r') || *itr\
    \ == ' ') ++itr;\n        }\n\n        // \u6574\u6570\u3001\u5C0F\u6570\u3092\
    \u5165\u529B\n        template<class T>\n        void scan_arithmetic(T& a) {\n\
    \            discard_space();\n            bool sgn = false;\n            if constexpr\
    \ (!std::is_unsigned_v<T>) if (*itr == '-') {\n                sgn = true;\n \
    \               ++itr;\n            }\n            a = 0;\n            for (;\
    \ '0' <= *itr && *itr <= '9'; ++itr) a = a * 10 + *itr - '0';\n            if\
    \ (*itr == '.') {\n                ++itr;\n                if constexpr (is_floating_point_v<T>)\
    \ {\n                    constexpr std::uint_fast64_t power_decimal_precision\
    \ = power(10ULL, decimal_precision);\n                    T d = 0;\n         \
    \           std::uint_fast64_t i = 1;\n                    for (; '0' <= *itr\
    \ && *itr <= '9' && i < power_decimal_precision; i *= 10) {\n                \
    \        d = d * 10 + *itr - '0';\n                        ++itr;\n          \
    \          }\n                    a += d / i;\n                }\n           \
    \     while ('0' <= *itr && *itr <= '9') ++itr;\n            }\n            if\
    \ constexpr (!std::is_unsigned_v<T>) if (sgn) a = -a;\n        }\n\n        //\
    \ \u8907\u6570\u306E\u5024\u3092\u5165\u529B\n        void operator ()() {}\n\
    \        template<class Head, class... Args>\n        void operator ()(Head&&\
    \ head, Args&&... args) {\n            ScanFunction<Head>::scan(*this, std::forward<Head>(head));\n\
    \            operator ()(std::forward<Args>(args)...);\n        }\n    };\n\n\
    \    template<>\n    struct ScanFunction<char> {\n        template<class Scanner>\n\
    \        static void scan(Scanner& scanner, char& a) {\n            scanner.discard_space();\n\
    \            a = *scanner.itr;\n            ++scanner.itr;\n        }\n    };\n\
    \n    struct ScanFunction<bool> {\n        template<class Scanner>\n        static\
    \ void scan(Scanner& scanner, bool& a) {\n            scanner.discard_space();\n\
    \            a = *scanner.itr != '0';\n        }\n    };\n\n    struct ScanFunction<std::string>\
    \ {\n        template<class Scanner>\n        static void scan(Scanner& scanner,\
    \ std::string& a) {\n            scanner.discard_space();\n            a.clear();\n\
    \            while ((*scanner.itr < '\\t' || '\\r' < *scanner.itr) && *scanner.itr\
    \ != ' ') {\n                a += *scanner.itr;\n                ++scanner.itr;\n\
    \            }\n        }\n    };\n\n    template<std::size_t len>\n    struct\
    \ ScanFunction<std::bitset<len>> {\n        template<class Scanner>\n        static\
    \ void scan(Scanner& scanner, std::bitset<len>& a) {\n            scanner.discard_space();\n\
    \            for (int i = len - 1; i >= 0; ++i) {\n                a[i] = *scanner.itr\
    \ != '0';\n                ++scanner.itr;\n            }\n        }\n    };\n\n\
    \    template<class T>\n    struct ScanFunction<T, std::enable_if_t<is_arithmetic_v<T>>>\
    \ {\n        template<class Scanner>\n        static void scan(Scanner& scanner,\
    \ T& a) {\n            scanner.scan_arithmetic(a);\n        }\n    };\n\n    template<class\
    \ T>\n    struct ScanFunction<T, std::enable_if_t<is_tuple_like_v<T> && !is_range_v<T>>>\
    \ {\n        template<std::size_t i = 0, class Scanner>\n        static void scan(Scanner&\
    \ scanner, T& a) {\n            if constexpr (i < tuple_like_size_v<T>) {\n  \
    \              ScanFunction<std::decay_t<tuple_like_element_t<i, T>>>::scan(scanner,\
    \ get<i>(a));\n                scan<i + 1>(scanner, a);\n            }\n     \
    \   }\n    };\n\n    template<class T>\n    struct ScanFunction<T, std::enable_if_t<is_range_v<T>>>\
    \ {\n        template<class Scanner>\n        static void scan(Scanner& scanner,\
    \ T& a) {\n            for (auto&& i: a) ScanFunction<range_value_t<T>>::scan(scanner,\
    \ i);\n        }\n    };\n\n    template<class Tuple, std::size_t idx>\n    struct\
    \ ScanFunction<Indexed<Tuple, idx>> {\n        template<class Scanner>\n     \
    \   struct ScannerWrapper: Scanner {\n            template<class T>\n        \
    \    void scan_arithmetic(T& a) {\n                Scanner::scan_arithmetic(a);\n\
    \                --a;\n            }\n        }\n        template<class Scanner>\n\
    \        static void scan(Scanner& scanner, const Indexed<Tuple, idx>& a) {\n\
    \            ScannerWrapper<Scanner>& scanner_wrapper = static_cast<ScannerWrapper<Scanner>&>(scanner);\n\
    \            ScanFunction<Tuple>::scan(scanner_wrapper, a.args_tuple);\n     \
    \   }\n    };\n\n    // \u6A19\u6E96\u5165\u529B\u304B\u3089\u5024\u3092\u5165\
    \u529B\u3059\u308B\u95A2\u6570\n    Scanner<Reader<>::iterator> scan{input.begin()};\n\
    } // namespace kpr\n"
  code: "#pragma once\n#include <unistd.h>\n#include <array>\n#include <bitset>\n\
    #include <cstddef>\n#include <cstdint>\n#include <cstdio>\n#include <string>\n\
    #include <type_traits>\n#include <utility>\n#include \"io_option.hpp\"\n#include\
    \ \"../math/power.hpp\"\n#include \"../meta/setting.hpp\"\n#include \"../meta/trait.hpp\"\
    \n#include \"../meta/tuple_like.hpp\"\n\nnamespace kpr {\n    // \u30D0\u30C3\u30D5\
    \u30A1\u3092\u7528\u3044\u3066\u30D5\u30A1\u30A4\u30EB\u3092\u8AAD\u307F\u8FBC\
    \u3080\u30AF\u30E9\u30B9\n    template<std::size_t buf_size = KYOPRO_BUFFER_SIZE>\n\
    \    struct Reader {\n    private:\n        int fd, idx;\n        std::array<char,\
    \ buf_size> buffer;\n\n    public:\n        // \u30D0\u30C3\u30D5\u30A1\u30B5\u30A4\
    \u30BA\u3092\u53D6\u5F97\n        static constexpr KYOPRO_BASE_INT get_buf_size()\
    \ noexcept {\n            return buf_size;\n        }\n\n        Reader() {\n\
    \            read(fd, buffer.begin(), buf_size);\n        }\n        Reader(int\
    \ fd): fd(fd), idx(0), buffer() {\n            read(fd, buffer.begin(), buf_size);\n\
    \        }\n        Reader(FILE* fp): fd(fileno(fp)), idx(0), buffer() {\n   \
    \         read(fd, buffer.begin(), buf_size);\n        }\n\n        // \u5165\u529B\
    \u30A4\u30C6\u30EC\u30FC\u30BF\n        struct iterator {\n        private:\n\
    \            Reader& reader;\n\n        public:\n            using difference_type\
    \ = void;\n            using value_type = void;\n            using pointer = void;\n\
    \            using reference = void;\n            using iterator_category = std::input_iterator_tag;\n\
    \n            iterator() noexcept = default;\n            iterator(Reader& reader)\
    \ noexcept: reader(reader) {}\n\n            iterator& operator ++() {\n     \
    \           ++reader.idx;\n                if (reader.idx == buf_size) {\n   \
    \                 read(reader.fd, reader.buffer.begin(), buf_size);\n        \
    \            reader.idx = 0;\n                }\n                return *this;\n\
    \            }\n\n            iterator operator ++(int) {\n                iterator\
    \ before = *this;\n                operator ++();\n                return before;\n\
    \            }\n\n            char& operator *() const {\n                return\
    \ reader.buffer[reader.idx];\n            }\n        };\n\n        // \u30D5\u30A1\
    \u30A4\u30EB\u306E\u6700\u521D\u3092\u793A\u3059\u30A4\u30C6\u30EC\u30FC\u30BF\
    \u3092\u53D6\u5F97\n        iterator begin() noexcept {\n            return iterator(*this);\n\
    \        }\n    };\n\n    // \u6A19\u6E96\u5165\u529B\n    Reader input{0};\n\n\
    \n    // \u5024\u306E\u5165\u529B\u306E\u95A2\u6570\u30AF\u30E9\u30B9\n    template<class,\
    \ class = void>\n    struct ScanFunction;\n\n    // \u5165\u529B\u30A4\u30C6\u30EC\
    \u30FC\u30BF\u3092\u7528\u3044\u3066\u5024\u3092\u5165\u529B\u3059\u308B\u30AF\
    \u30E9\u30B9\n    template<class Iterator, std::size_t decimal_precision = KYOPRO_DECIMAL_PRECISION>\n\
    \    struct Scanner {\n        using iterator_type = Iterator;\n\n        // \u5165\
    \u529B\u30A4\u30C6\u30EC\u30FC\u30BF\n        Iterator itr;\n\n        // \u6307\
    \u5B9A\u3055\u308C\u305F\u5C0F\u6570\u8AA4\u5DEE\u3092\u53D6\u5F97\n        static\
    \ constexpr KYOPRO_BASE_INT get_decimal_precision() noexcept {\n            return\
    \ decimal_precision;\n        }\n\n        Scanner() noexcept = default;\n   \
    \     Scanner(Iterator itr) noexcept: itr(itr) {}\n\n        // \u6B21\u306E\u6587\
    \u5B57\u307E\u3067\u306E\u7A7A\u767D\u3092\u7121\u8996\u3059\u308B\n        void\
    \ discard_space() {\n            while (('\\t' <= *itr && *itr <= '\\r') || *itr\
    \ == ' ') ++itr;\n        }\n\n        // \u6574\u6570\u3001\u5C0F\u6570\u3092\
    \u5165\u529B\n        template<class T>\n        void scan_arithmetic(T& a) {\n\
    \            discard_space();\n            bool sgn = false;\n            if constexpr\
    \ (!std::is_unsigned_v<T>) if (*itr == '-') {\n                sgn = true;\n \
    \               ++itr;\n            }\n            a = 0;\n            for (;\
    \ '0' <= *itr && *itr <= '9'; ++itr) a = a * 10 + *itr - '0';\n            if\
    \ (*itr == '.') {\n                ++itr;\n                if constexpr (is_floating_point_v<T>)\
    \ {\n                    constexpr std::uint_fast64_t power_decimal_precision\
    \ = power(10ULL, decimal_precision);\n                    T d = 0;\n         \
    \           std::uint_fast64_t i = 1;\n                    for (; '0' <= *itr\
    \ && *itr <= '9' && i < power_decimal_precision; i *= 10) {\n                \
    \        d = d * 10 + *itr - '0';\n                        ++itr;\n          \
    \          }\n                    a += d / i;\n                }\n           \
    \     while ('0' <= *itr && *itr <= '9') ++itr;\n            }\n            if\
    \ constexpr (!std::is_unsigned_v<T>) if (sgn) a = -a;\n        }\n\n        //\
    \ \u8907\u6570\u306E\u5024\u3092\u5165\u529B\n        void operator ()() {}\n\
    \        template<class Head, class... Args>\n        void operator ()(Head&&\
    \ head, Args&&... args) {\n            ScanFunction<Head>::scan(*this, std::forward<Head>(head));\n\
    \            operator ()(std::forward<Args>(args)...);\n        }\n    };\n\n\
    \    template<>\n    struct ScanFunction<char> {\n        template<class Scanner>\n\
    \        static void scan(Scanner& scanner, char& a) {\n            scanner.discard_space();\n\
    \            a = *scanner.itr;\n            ++scanner.itr;\n        }\n    };\n\
    \n    struct ScanFunction<bool> {\n        template<class Scanner>\n        static\
    \ void scan(Scanner& scanner, bool& a) {\n            scanner.discard_space();\n\
    \            a = *scanner.itr != '0';\n        }\n    };\n\n    struct ScanFunction<std::string>\
    \ {\n        template<class Scanner>\n        static void scan(Scanner& scanner,\
    \ std::string& a) {\n            scanner.discard_space();\n            a.clear();\n\
    \            while ((*scanner.itr < '\\t' || '\\r' < *scanner.itr) && *scanner.itr\
    \ != ' ') {\n                a += *scanner.itr;\n                ++scanner.itr;\n\
    \            }\n        }\n    };\n\n    template<std::size_t len>\n    struct\
    \ ScanFunction<std::bitset<len>> {\n        template<class Scanner>\n        static\
    \ void scan(Scanner& scanner, std::bitset<len>& a) {\n            scanner.discard_space();\n\
    \            for (int i = len - 1; i >= 0; ++i) {\n                a[i] = *scanner.itr\
    \ != '0';\n                ++scanner.itr;\n            }\n        }\n    };\n\n\
    \    template<class T>\n    struct ScanFunction<T, std::enable_if_t<is_arithmetic_v<T>>>\
    \ {\n        template<class Scanner>\n        static void scan(Scanner& scanner,\
    \ T& a) {\n            scanner.scan_arithmetic(a);\n        }\n    };\n\n    template<class\
    \ T>\n    struct ScanFunction<T, std::enable_if_t<is_tuple_like_v<T> && !is_range_v<T>>>\
    \ {\n        template<std::size_t i = 0, class Scanner>\n        static void scan(Scanner&\
    \ scanner, T& a) {\n            if constexpr (i < tuple_like_size_v<T>) {\n  \
    \              ScanFunction<std::decay_t<tuple_like_element_t<i, T>>>::scan(scanner,\
    \ get<i>(a));\n                scan<i + 1>(scanner, a);\n            }\n     \
    \   }\n    };\n\n    template<class T>\n    struct ScanFunction<T, std::enable_if_t<is_range_v<T>>>\
    \ {\n        template<class Scanner>\n        static void scan(Scanner& scanner,\
    \ T& a) {\n            for (auto&& i: a) ScanFunction<range_value_t<T>>::scan(scanner,\
    \ i);\n        }\n    };\n\n    template<class Tuple, std::size_t idx>\n    struct\
    \ ScanFunction<Indexed<Tuple, idx>> {\n        template<class Scanner>\n     \
    \   struct ScannerWrapper: Scanner {\n            template<class T>\n        \
    \    void scan_arithmetic(T& a) {\n                Scanner::scan_arithmetic(a);\n\
    \                --a;\n            }\n        }\n        template<class Scanner>\n\
    \        static void scan(Scanner& scanner, const Indexed<Tuple, idx>& a) {\n\
    \            ScannerWrapper<Scanner>& scanner_wrapper = static_cast<ScannerWrapper<Scanner>&>(scanner);\n\
    \            ScanFunction<Tuple>::scan(scanner_wrapper, a.args_tuple);\n     \
    \   }\n    };\n\n    // \u6A19\u6E96\u5165\u529B\u304B\u3089\u5024\u3092\u5165\
    \u529B\u3059\u308B\u95A2\u6570\n    Scanner<Reader<>::iterator> scan{input.begin()};\n\
    } // namespace kpr\n"
  dependsOn:
  - system/io_option.hpp
  - math/power.hpp
  - meta/setting.hpp
  - meta/trait.hpp
  - meta/tuple_like.hpp
  isVerificationFile: false
  path: system/in.hpp
  requiredBy:
  - all/all.hpp
  - system/system.hpp
  - template/template.hpp
  - template/macro.hpp
  - all.hpp
  timestamp: '2023-02-10 23:05:45+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/aoj/PrimeNumber.test.cpp
  - verify/yosupo/point_add_range_sum.test.cpp
  - verify/yosupo/unionfind.test.cpp
  - verify/yosupo/factorize.test.cpp
  - verify/yosupo/many_aplusb.test.cpp
documentation_of: system/in.hpp
layout: document
redirect_from:
- /library/system/in.hpp
- /library/system/in.hpp.html
title: system/in.hpp
---
