---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/power.hpp
    title: math/power.hpp
  - icon: ':x:'
    path: meta/setting.hpp
    title: "\u57FA\u672C\u7B26\u53F7\u4ED8\u304D\u6574\u6570\u578B"
  - icon: ':x:'
    path: meta/trait.hpp
    title: meta/trait.hpp
  - icon: ':x:'
    path: meta/tuple_like.hpp
    title: meta/tuple_like.hpp
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
  - icon: ':warning:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/macro.hpp\"\n#include <cstddef>\n#include <iterator>\n\
    #include <memory>\n#include <tuple>\n#include <type_traits>\n#include <utility>\n\
    #line 2 \"system/in.hpp\"\n#include <unistd.h>\n#include <array>\n#include <bitset>\n\
    #line 6 \"system/in.hpp\"\n#include <cstdint>\n#include <cstdio>\n#include <string>\n\
    #line 3 \"math/power.hpp\"\n\nnamespace kpr {\n    [[maybe_unused]] inline constexpr\
    \ struct {\n        template<class T>\n        constexpr T operator ()(T a, std::uint_fast64_t\
    \ n, T init = 1) const noexcept {\n            while (n > 0) {\n             \
    \   if (n & 1) init *= a;\n                a *= a;\n                n >>= 1;\n\
    \            }\n            return init;\n        }\n    } power;\n} // namespace\
    \ kpr\n#line 3 \"meta/setting.hpp\"\n\n#ifndef KYOPRO_BASE_INT\n/// @brief \u57FA\
    \u672C\u7B26\u53F7\u4ED8\u304D\u6574\u6570\u578B\n#define KYOPRO_BASE_INT std::int64_t\n\
    #endif\n\n#ifndef KYOPRO_BASE_UINT\n/// @brief \u57FA\u672C\u7B26\u53F7\u306A\u3057\
    \u6574\u6570\u578B\n#define KYOPRO_BASE_UINT std::uint64_t\n#endif\n\n#ifndef\
    \ KYOPRO_BASE_FLOAT\n/// @brief \u57FA\u672C\u6D6E\u52D5\u5C0F\u6570\u70B9\u6570\
    \u578B\n#define KYOPRO_BASE_FLOAT double\n#endif\n\n#ifndef KYOPRO_DEFAULT_MOD\n\
    /// @brief \u554F\u984C\u3067\u8A2D\u5B9A\u3055\u308C\u305Fmod\n#define KYOPRO_DEFAULT_MOD\
    \ (static_cast<KYOPRO_BASE_UINT>(998244353))\n#endif\n\n#ifndef KYOPRO_DECIMAL_PRECISION\n\
    /// @brief \u5C0F\u6570\u7CBE\u5EA6(\u6841)\n#define KYOPRO_DECIMAL_PRECISION\
    \ (static_cast<KYOPRO_BASE_UINT>(12))\n#endif\n\n#ifndef KYOPRO_INF_DIV\n/// @brief\
    \ \u7121\u9650\u5927\u3092\u8868\u3059\u6574\u6570\u304C\u6700\u5927\u5024\u306E\
    \u4F55\u5206\u306E\u4E00\u304B\u3092\u8868\u3059\n#define KYOPRO_INF_DIV (static_cast<KYOPRO_BASE_UINT>(3))\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n/// @brief \u30C7\u30D5\u30A9\u30EB\u30C8\
    \u306E\u30D0\u30C3\u30D5\u30A1\u30B5\u30A4\u30BA\n#define KYOPRO_BUFFER_SIZE (static_cast<KYOPRO_BASE_UINT>(2048))\n\
    #endif\n#line 7 \"meta/trait.hpp\"\n\nnamespace kpr {\n    namespace helper {\n\
    \        template<class T>\n        struct is_integer_helper {\n            static\
    \ constexpr bool value = std::is_integral_v<T>;\n        };\n\n        #ifdef\
    \ __SIZEOF_INT128__\n        template<>\n        struct is_integer_helper<__int128_t>\
    \ {\n            static constexpr bool value = true;\n        };\n\n        template<>\n\
    \        struct is_integer_helper<__uint128_t> {\n            static constexpr\
    \ bool value = true;\n        };\n        #endif\n    } // namespace helper\n\n\
    \    // \u578BT\u304C\u6574\u6570\u304B\u8ABF\u3079\u308B\n    template<class\
    \ T>\n    struct is_integer {\n        static constexpr bool value = helper::is_integer_helper<std::remove_cv_t<T>>::value;\n\
    \    };\n\n    // \u578BT\u304C\u6574\u6570\u304B\u8ABF\u3079\u308B\n    template<class\
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
    } // namespace kpr\n#line 16 \"system/in.hpp\"\n\nnamespace kpr {\n    template<std::size_t\
    \ buf_size = KYOPRO_BUFFER_SIZE>\n    struct Reader {\n    private:\n        int\
    \ fd, idx;\n        std::array<char, buf_size> buffer;\n\n    public:\n      \
    \  static constexpr KYOPRO_BASE_INT get_buf_size() noexcept {\n            return\
    \ buf_size;\n        }\n\n        Reader() {\n            read(fd, buffer.begin(),\
    \ buf_size);\n        }\n        Reader(int fd): fd(fd), idx(0), buffer() {\n\
    \            read(fd, buffer.begin(), buf_size);\n        }\n        Reader(FILE*\
    \ fp): fd(fileno(fp)), idx(0), buffer() {\n            read(fd, buffer.begin(),\
    \ buf_size);\n        }\n\n        struct iterator {\n        private:\n     \
    \       Reader& reader;\n\n        public:\n            using difference_type\
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
    \ reader.buffer[reader.idx];\n            }\n        };\n\n        iterator begin()\
    \ noexcept {\n            return iterator(*this);\n        }\n    };\n\n    Reader\
    \ input(0);\n\n    template<class Iterator, std::size_t decimal_precision = KYOPRO_DECIMAL_PRECISION>\n\
    \    struct Scanner {\n        using iterator_type = Iterator;\n    private:\n\
    \        template<class, class = void>\n        struct has_scan: std::false_type\
    \ {};\n        template<class T>\n        struct has_scan<T, std::void_t<decltype(std::declval<T>().scan(std::declval<Scanner&>()))>>:\
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
    \ scan(input.begin());\n} // namespace kpr\n#line 3 \"system/out.hpp\"\n#include\
    \ <algorithm>\n#line 6 \"system/out.hpp\"\n#include <cmath>\n#line 17 \"system/out.hpp\"\
    \n\nnamespace kpr {\n    template<std::size_t buf_size = KYOPRO_BUFFER_SIZE>\n\
    \    struct Writer {\n    private:\n        int fd, idx;\n        std::array<char,\
    \ buf_size> buffer;\n\n    public:\n        static constexpr KYOPRO_BASE_INT get_buf_size()\
    \ noexcept {\n            return buf_size;\n        }\n\n        Writer() noexcept\
    \ = default;\n        Writer(int fd) noexcept: fd(fd), idx(0), buffer() {}\n \
    \       Writer(FILE* fp) noexcept: fd(fileno(fp)), idx(0), buffer() {}\n\n   \
    \     ~Writer() {\n            write(fd, buffer.begin(), idx);\n        }\n\n\
    \        struct iterator {\n        private:\n            Writer& writer;\n\n\
    \        public:\n            using difference_type = void;\n            using\
    \ value_type = void;\n            using pointer = void;\n            using reference\
    \ = void;\n            using iterator_category = std::output_iterator_tag;\n\n\
    \            iterator() noexcept = default;\n            iterator(Writer& writer)\
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
    \ eprintln(error.begin());\n} // namespace kpr\n#line 9 \"template/macro.hpp\"\
    \n\nnamespace kpr::helper {\n    template<std::size_t len>\n    constexpr std::size_t\
    \ va_args_size(const char (&s)[len]) noexcept {\n        if constexpr (len ==\
    \ 1) return 0;\n        std::size_t cnt = 1;\n        std::uint_fast64_t bracket\
    \ = 0;\n        for (auto i: s) {\n            if (i == '(') ++bracket;\n    \
    \        else if (i == ')') --bracket;\n            else if (i == ',' && bracket\
    \ == 0) ++cnt;\n        }\n        return cnt;\n    }\n\n    template<class F,\
    \ std::size_t... idx>\n    auto read_impl(F&& f, std::index_sequence<idx...>)\
    \ {\n        return std::tuple{(static_cast<void>(idx), f())...};\n    }\n\n \
    \   Printer<Writer<>::iterator, true, true, true, true, true> debug_impl(output.begin());\n\
    \n    template<bool flag, std::size_t len>\n    void print_if(const char (&s)[len])\
    \ {\n        if constexpr (flag) print(' ', s);\n    }\n\n    struct LambdaArg\
    \ {};\n} // namespace kpr::helper\n\n#define read(type_or_init, ...)         \
    \                                                  \\\nauto [__VA_ARGS__] = (kpr::helper::read_impl(([]()\
    \ {                                   \\\n    using T = std::decay_t<decltype(*new\
    \ type_or_init)>;                                  \\\n    alignas(T) std::byte\
    \ storage[sizeof(T)];                                              \\\n    T*\
    \ p = new (storage) type_or_init;                                            \
    \        \\\n    kpr::scan(*p);                                              \
    \                       \\\n    T res = std::move(*p);                       \
    \                                         \\\n    p->~T();                   \
    \                                                           \\\n    return res;\
    \                                                                           \\\
    \n}), std::make_index_sequence<kpr::helper::va_args_size(#__VA_ARGS__)>()))\n\
    #define debug(...) (kpr::print('#', ' ', 'l', 'i', 'n', 'e', ' ', __LINE__, ':'),\
    \ kpr::helper::print_if<kpr::helper::va_args_size(#__VA_ARGS__) != 0>(#__VA_ARGS__),\
    \ kpr::print('\\n'), kpr::helper::debug_impl(__VA_ARGS__))\n\n#define KYOPRO_OVERLOAD_MACRO(_1,\
    \ _2, _3, _4, name, ...) name\n\n#define KYOPRO_REP0() for (; ; )\n#define KYOPRO_REP1(last)\
    \ KYOPRO_REP2(KYOPRO_COUNTER, last)\n#define KYOPRO_REP2(i, last) for (auto i\
    \ = std::decay_t<decltype(last)>(), KYOPRO_LAST = (last); (i) < (KYOPRO_LAST);\
    \ ++(i))\n#define KYOPRO_REP3(i, first, last) for (auto i = (first), KYOPRO_LAST\
    \ = last; (i) < (KYOPRO_LAST); ++(i))\n#define rep(...) KYOPRO_OVERLOAD_MACRO(__VA_ARGS__\
    \ __VA_OPT__(,) KYOPRO_REP4, KYOPRO_REP3, KYOPRO_REP2, KYOPRO_REP1, KYOPRO_REP0)(__VA_ARGS__)\n\
    \n#define KYOPRO_MATCH1(_1) break; case _1:\n#define KYOPRO_MATCH2(_1, _2) break;\
    \ case _1: case _2:\n#define KYOPRO_MATCH3(_1, _2, _3) break; case _1: case _2:\
    \ case _3:\n#define KYOPRO_MATCH4(_1, _2, _3, _4) break; case _1: case _2: case\
    \ _3: case _4:\n#define match(...) KYOPRO_OVERLOAD_MACRO(__VA_ARGS__, KYOPRO_MATCH4,\
    \ KYOPRO_MATCH3, KYOPRO_MATCH2, KYOPRO_MATCH1)(__VA_ARGS__)\n#define otherwise\
    \ break; default:\n\n#define $(...)                                          \
    \                                                                            \
    \                                                                            \
    \                                                                            \
    \                           \\\n([&](auto&&... args) {                       \
    \                                                                            \
    \                                                                            \
    \                                                                            \
    \                                           \\\n    [[maybe_unused]] auto&& $0\
    \ = std::forward<std::tuple_element_t<0, std::tuple<decltype(args)..., kpr::helper::LambdaArg>>>(std::get<0>(std::forward_as_tuple(args...,\
    \ kpr::helper::LambdaArg{})));                                               \
    \                                                                  \\\n    [[maybe_unused]]\
    \ auto&& $1 = std::forward<std::tuple_element_t<1, std::tuple<decltype(args)...,\
    \ kpr::helper::LambdaArg, kpr::helper::LambdaArg>>>(std::get<1>(std::forward_as_tuple(args...,\
    \ kpr::helper::LambdaArg{}, kpr::helper::LambdaArg{})));                     \
    \                                    \\\n    [[maybe_unused]] auto&& $2 = std::forward<std::tuple_element_t<2,\
    \ std::tuple<decltype(args)..., kpr::helper::LambdaArg, kpr::helper::LambdaArg,\
    \ kpr::helper::LambdaArg>>>(std::get<2>(std::forward_as_tuple(args..., kpr::helper::LambdaArg{},\
    \ kpr::helper::LambdaArg{}, kpr::helper::LambdaArg{}))); \\\n    return (__VA_ARGS__);\
    \                                                                            \
    \                                                                            \
    \                                                                            \
    \                                                               \\\n})\n\n#define\
    \ all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)\n#define rall(...) std::rbegin(__VA_ARGS__),\
    \ std::rend(__VA_ARGS__)\n"
  code: "#pragma once\n#include <cstddef>\n#include <iterator>\n#include <memory>\n\
    #include <tuple>\n#include <type_traits>\n#include <utility>\n#include \"../system/system.hpp\"\
    \n\nnamespace kpr::helper {\n    template<std::size_t len>\n    constexpr std::size_t\
    \ va_args_size(const char (&s)[len]) noexcept {\n        if constexpr (len ==\
    \ 1) return 0;\n        std::size_t cnt = 1;\n        std::uint_fast64_t bracket\
    \ = 0;\n        for (auto i: s) {\n            if (i == '(') ++bracket;\n    \
    \        else if (i == ')') --bracket;\n            else if (i == ',' && bracket\
    \ == 0) ++cnt;\n        }\n        return cnt;\n    }\n\n    template<class F,\
    \ std::size_t... idx>\n    auto read_impl(F&& f, std::index_sequence<idx...>)\
    \ {\n        return std::tuple{(static_cast<void>(idx), f())...};\n    }\n\n \
    \   Printer<Writer<>::iterator, true, true, true, true, true> debug_impl(output.begin());\n\
    \n    template<bool flag, std::size_t len>\n    void print_if(const char (&s)[len])\
    \ {\n        if constexpr (flag) print(' ', s);\n    }\n\n    struct LambdaArg\
    \ {};\n} // namespace kpr::helper\n\n#define read(type_or_init, ...)         \
    \                                                  \\\nauto [__VA_ARGS__] = (kpr::helper::read_impl(([]()\
    \ {                                   \\\n    using T = std::decay_t<decltype(*new\
    \ type_or_init)>;                                  \\\n    alignas(T) std::byte\
    \ storage[sizeof(T)];                                              \\\n    T*\
    \ p = new (storage) type_or_init;                                            \
    \        \\\n    kpr::scan(*p);                                              \
    \                       \\\n    T res = std::move(*p);                       \
    \                                         \\\n    p->~T();                   \
    \                                                           \\\n    return res;\
    \                                                                           \\\
    \n}), std::make_index_sequence<kpr::helper::va_args_size(#__VA_ARGS__)>()))\n\
    #define debug(...) (kpr::print('#', ' ', 'l', 'i', 'n', 'e', ' ', __LINE__, ':'),\
    \ kpr::helper::print_if<kpr::helper::va_args_size(#__VA_ARGS__) != 0>(#__VA_ARGS__),\
    \ kpr::print('\\n'), kpr::helper::debug_impl(__VA_ARGS__))\n\n#define KYOPRO_OVERLOAD_MACRO(_1,\
    \ _2, _3, _4, name, ...) name\n\n#define KYOPRO_REP0() for (; ; )\n#define KYOPRO_REP1(last)\
    \ KYOPRO_REP2(KYOPRO_COUNTER, last)\n#define KYOPRO_REP2(i, last) for (auto i\
    \ = std::decay_t<decltype(last)>(), KYOPRO_LAST = (last); (i) < (KYOPRO_LAST);\
    \ ++(i))\n#define KYOPRO_REP3(i, first, last) for (auto i = (first), KYOPRO_LAST\
    \ = last; (i) < (KYOPRO_LAST); ++(i))\n#define rep(...) KYOPRO_OVERLOAD_MACRO(__VA_ARGS__\
    \ __VA_OPT__(,) KYOPRO_REP4, KYOPRO_REP3, KYOPRO_REP2, KYOPRO_REP1, KYOPRO_REP0)(__VA_ARGS__)\n\
    \n#define KYOPRO_MATCH1(_1) break; case _1:\n#define KYOPRO_MATCH2(_1, _2) break;\
    \ case _1: case _2:\n#define KYOPRO_MATCH3(_1, _2, _3) break; case _1: case _2:\
    \ case _3:\n#define KYOPRO_MATCH4(_1, _2, _3, _4) break; case _1: case _2: case\
    \ _3: case _4:\n#define match(...) KYOPRO_OVERLOAD_MACRO(__VA_ARGS__, KYOPRO_MATCH4,\
    \ KYOPRO_MATCH3, KYOPRO_MATCH2, KYOPRO_MATCH1)(__VA_ARGS__)\n#define otherwise\
    \ break; default:\n\n#define $(...)                                          \
    \                                                                            \
    \                                                                            \
    \                                                                            \
    \                           \\\n([&](auto&&... args) {                       \
    \                                                                            \
    \                                                                            \
    \                                                                            \
    \                                           \\\n    [[maybe_unused]] auto&& $0\
    \ = std::forward<std::tuple_element_t<0, std::tuple<decltype(args)..., kpr::helper::LambdaArg>>>(std::get<0>(std::forward_as_tuple(args...,\
    \ kpr::helper::LambdaArg{})));                                               \
    \                                                                  \\\n    [[maybe_unused]]\
    \ auto&& $1 = std::forward<std::tuple_element_t<1, std::tuple<decltype(args)...,\
    \ kpr::helper::LambdaArg, kpr::helper::LambdaArg>>>(std::get<1>(std::forward_as_tuple(args...,\
    \ kpr::helper::LambdaArg{}, kpr::helper::LambdaArg{})));                     \
    \                                    \\\n    [[maybe_unused]] auto&& $2 = std::forward<std::tuple_element_t<2,\
    \ std::tuple<decltype(args)..., kpr::helper::LambdaArg, kpr::helper::LambdaArg,\
    \ kpr::helper::LambdaArg>>>(std::get<2>(std::forward_as_tuple(args..., kpr::helper::LambdaArg{},\
    \ kpr::helper::LambdaArg{}, kpr::helper::LambdaArg{}))); \\\n    return (__VA_ARGS__);\
    \                                                                            \
    \                                                                            \
    \                                                                            \
    \                                                               \\\n})\n\n#define\
    \ all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)\n#define rall(...) std::rbegin(__VA_ARGS__),\
    \ std::rend(__VA_ARGS__)\n"
  dependsOn:
  - system/system.hpp
  - system/in.hpp
  - math/power.hpp
  - meta/setting.hpp
  - meta/trait.hpp
  - meta/tuple_like.hpp
  - system/out.hpp
  isVerificationFile: false
  path: template/macro.hpp
  requiredBy:
  - template/template.hpp
  - all.hpp
  timestamp: '2023-02-01 01:52:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/macro.hpp
layout: document
redirect_from:
- /library/template/macro.hpp
- /library/template/macro.hpp.html
title: template/macro.hpp
---
