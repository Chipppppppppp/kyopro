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
  - icon: ':warning:'
    path: math/ModInt.hpp
    title: math/ModInt.hpp
  - icon: ':x:'
    path: math/Montgomery.hpp
    title: math/Montgomery.hpp
  - icon: ':warning:'
    path: math/mod.hpp
    title: math/mod.hpp
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
  - icon: ':x:'
    path: system/in.hpp
    title: system/in.hpp
  - icon: ':x:'
    path: system/io_option.hpp
    title: system/io_option.hpp
  - icon: ':x:'
    path: system/out.hpp
    title: system/out.hpp
  - icon: ':x:'
    path: system/system.hpp
    title: system/system.hpp
  - icon: ':warning:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':warning:'
    path: template/amin_amax.hpp
    title: template/amin_amax.hpp
  - icon: ':warning:'
    path: template/constant.hpp
    title: template/constant.hpp
  - icon: ':warning:'
    path: template/fix_vector_bool.hpp
    title: template/fix_vector_bool.hpp
  - icon: ':warning:'
    path: template/len.hpp
    title: template/len.hpp
  - icon: ':warning:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':warning:'
    path: template/make_array.hpp
    title: template/make_array.hpp
  - icon: ':warning:'
    path: template/make_vector.hpp
    title: template/make_vector.hpp
  - icon: ':warning:'
    path: template/stl.hpp
    title: template/stl.hpp
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
  bundledCode: "#line 2 \"template/alias.hpp\"\n#include <cstdint>\n#include <limits>\n\
    #include <functional>\n#include <tuple>\n#include <utility>\n#include <vector>\n\
    #include <string>\n#include <set>\n#include <map>\n#include <unordered_set>\n\
    #include <unordered_map>\n#include <queue>\n#include <stack>\n#line 2 \"algorithm/Hash.hpp\"\
    \n#include <cstddef>\n#line 4 \"algorithm/Hash.hpp\"\n#include <iterator>\n#include\
    \ <type_traits>\n#line 7 \"meta/trait.hpp\"\n\nnamespace kpr {\n    namespace\
    \ helper {\n        template<class T>\n        struct is_integer_helper {\n  \
    \          static constexpr bool value = std::is_integral_v<T>;\n        };\n\n\
    \        #ifdef __SIZEOF_INT128__\n        template<>\n        struct is_integer_helper<__int128_t>\
    \ {\n            static constexpr bool value = true;\n        };\n        template<>\n\
    \        struct is_integer_helper<__uint128_t> {\n            static constexpr\
    \ bool value = true;\n        };\n        #endif\n    } // namespace helper\n\n\
    \    // \u578BT\u304C\u6574\u6570\u304B\u8ABF\u3079\u308B\n    template<class\
    \ T>\n    struct is_integer {\n        static constexpr bool value = helper::is_integer_helper<std::remove_cv_t<T>>::value;\n\
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
    \       return init;\n        }\n    } power;\n} // namespace kpr\n#line 3 \"\
    meta/setting.hpp\"\n\n#ifndef KYOPRO_BASE_INT\n// \u57FA\u672C\u7B26\u53F7\u4ED8\
    \u304D\u6574\u6570\u578B\n#define KYOPRO_BASE_INT std::int64_t\n#endif\n\n#ifndef\
    \ KYOPRO_BASE_UINT\n// \u57FA\u672C\u7B26\u53F7\u306A\u3057\u6574\u6570\u578B\n\
    #define KYOPRO_BASE_UINT std::uint64_t\n#endif\n\n#ifndef KYOPRO_BASE_FLOAT\n\
    // \u57FA\u672C\u6D6E\u52D5\u5C0F\u6570\u70B9\u6570\u578B\n#define KYOPRO_BASE_FLOAT\
    \ double\n#endif\n\n#ifndef KYOPRO_DEFAULT_MOD\n// \u554F\u984C\u3067\u8A2D\u5B9A\
    \u3055\u308C\u305Fmod\n#define KYOPRO_DEFAULT_MOD (static_cast<KYOPRO_BASE_UINT>(998244353))\n\
    #endif\n\n#ifndef KYOPRO_DECIMAL_PRECISION\n// \u5C0F\u6570\u7CBE\u5EA6(\u6841\
    )\n#define KYOPRO_DECIMAL_PRECISION (static_cast<KYOPRO_BASE_UINT>(12))\n#endif\n\
    \n#ifndef KYOPRO_INF_DIV\n// \u7121\u9650\u5927\u3092\u8868\u3059\u6574\u6570\u304C\
    \u6700\u5927\u5024\u306E\u4F55\u5206\u306E\u4E00\u304B\u3092\u8868\u3059\n#define\
    \ KYOPRO_INF_DIV (static_cast<KYOPRO_BASE_UINT>(3))\n#endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n\
    // \u30C7\u30D5\u30A9\u30EB\u30C8\u306E\u30D0\u30C3\u30D5\u30A1\u30B5\u30A4\u30BA\
    \n#define KYOPRO_BUFFER_SIZE (static_cast<KYOPRO_BASE_UINT>(2048))\n#endif\n#line\
    \ 5 \"meta/constant.hpp\"\n\nnamespace kpr {\n    // \u554F\u984C\u3067\u8A2D\u5B9A\
    \u3055\u308C\u305Fmod\n    template<class T>\n    inline constexpr T MOD = KYOPRO_DEFAULT_MOD;\n\
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
    \        }\n    };\n} // namespace kpr\n#line 2 \"math/ModInt.hpp\"\n#include\
    \ <cassert>\n#line 6 \"algorithm/bit.hpp\"\n\nnamespace kpr {\n    // \u7ACB\u3063\
    \u3066\u3044\u308Bbit\u306E\u500B\u6570\u3092\u8FD4\u3059\n    [[maybe_unused]]\
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
    \ 4 \"math/mod.hpp\"\n\nnamespace kpr {\n    [[maybe_unused]] inline constexpr\
    \ struct {\n        template<class T, class U>\n        constexpr std::common_type_t<T,\
    \ U> operator ()(T x, U m) const noexcept {\n            static_assert(is_integer_v<T>\
    \ && is_integer_v<U>, \"Both of the arguments must be integers\");\n         \
    \   if constexpr (is_unsigned_integer_v<T> || is_unsigned_integer_v<U>) return\
    \ x % m;\n            return (x %= m) < 0 ? x + m : x;\n        }\n    } floor_mod;\n\
    \n    [[maybe_unused]] inline constexpr struct {\n        template<class T, class\
    \ U>\n        constexpr std::common_type_t<T, U> operator ()(T x, U m) const noexcept\
    \ {\n            return m - floor_mod(x - 1, m) - static_cast<T>(1);\n       \
    \ }\n    } ceil_mod;\n} // namespace kpr\n#line 14 \"math/ModInt.hpp\"\n\nnamespace\
    \ kpr {\n    template<KYOPRO_BASE_UINT m>\n    struct ModInt {\n        using\
    \ value_type = uint_least_t<bit_len(m * 2 - 2)>;\n\n        static constexpr value_type\
    \ mod = m;\n        value_type value;\n\n        static constexpr KYOPRO_BASE_INT\
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
    \        }\n    };\n} // namespace kpr\n#line 19 \"template/alias.hpp\"\n\nnamespace\
    \ kpr {\n    using ll = long long;\n    using ull = unsigned long long;\n    using\
    \ lf = double;\n\n    using i8 = std::int8_t;\n    using u8 = std::uint8_t;\n\
    \    using i16 = std::int16_t;\n    using u16 = std::uint16_t;\n    using i32\
    \ = std::int32_t;\n    using u32 = std::uint32_t;\n    using i64 = std::int64_t;\n\
    \    using u64 = std::uint64_t;\n    #ifdef __SIZEOF_INT128__\n    using i128\
    \ = __int128_t;\n    using u128 = __uint128_t;\n    #endif\n    #ifdef __SIZEOF_FLOAT128__\n\
    \    using f128 = __float128;\n    #endif\n\n    using mint = ModInt<mod>;\n \
    \   using dmint = DynamicModInt<KYOPRO_BASE_UINT>;\n\n    template<class T, std::size_t\
    \ idx, class... Args>\n    struct agg_type {\n        using type = typename agg_type<T,\
    \ idx - 1, T, Args...>::type;\n    };\n    template<class T, class... Args>\n\
    \    struct agg_type<T, 0, Args...> {\n        using type = std::tuple<Args...>;\n\
    \    };\n    template<class T>\n    struct agg_type<T, 0, T, T> {\n        using\
    \ type = std::pair<T, T>;\n    };\n\n    template<class T, std::size_t idx>\n\
    \    using agg = typename agg_type<T, idx>::type;\n    using ll1 = agg<ll, 1>;\n\
    \    using ll2 = agg<ll, 2>;\n    using ll3 = agg<ll, 3>;\n    using ll4 = agg<ll,\
    \ 4>;\n    using ll5 = agg<ll, 5>;\n\n    template<class T>\n    using vec = std::vector<T>;\n\
    \    template<class T>\n    using vec1 = vec<T>;\n    template<class T>\n    using\
    \ vec2 = std::vector<vec1<T>>;\n    template<class T>\n    using vec3 = std::vector<vec2<T>>;\n\
    \    template<class T>\n    using vec4 = std::vector<vec3<T>>;\n    template<class\
    \ T>\n    using vec5 = std::vector<vec4<T>>;\n\n    template<class Key, class\
    \ Compare = std::less<Key>>\n    using mset = std::unordered_set<Key, Compare>;\n\
    \    template<class Key, class T, class Compare = std::less<Key>>\n    using mmap\
    \ = std::unordered_map<Key, T, Compare>;\n    template<class Key>\n    using hset\
    \ = std::unordered_set<Key, Hash<Key>>;\n    template<class Key, class T>\n  \
    \  using hmap = std::unordered_map<Key, T, Hash<Key>>;\n    template<class Key>\n\
    \    using hmiset = std::unordered_multiset<Key, Hash<Key>>;\n    template<class\
    \ Key, class T>\n    using hmmap = std::unordered_multimap<Key, T, Hash<Key>>;\n\
    \    template<class T, class Compare = std::less<T>, class Container = std::vector<T>>\n\
    \    using priq = std::priority_queue<T, Container, Compare>;\n    template<class\
    \ T, class Compare = std::greater<T>, class Container = std::vector<T>>\n    using\
    \ heapq = priq<T, Compare, Container>;\n} // namespace kpr\n\nusing namespace\
    \ std;\nusing namespace kpr;\n#line 2 \"template/amin_amax.hpp\"\n\nnamespace\
    \ kpr {\n    template<class T, class U = T>\n    constexpr bool amin(T& a, const\
    \ U& b) noexcept {\n        if (b < a) {\n            a = b;\n            return\
    \ true;\n        }\n        return false;\n    }\n\n    template<class T, class\
    \ U = T>\n    constexpr bool amax(T& a, const U& b) noexcept {\n        if (a\
    \ < b) {\n            a = b;\n            return true;\n        }\n        return\
    \ false;\n    }\n} // namespace kpr\n#line 2 \"template/constant.hpp\"\n#include\
    \ <array>\n#line 4 \"template/constant.hpp\"\n\nnamespace kpr {\n    inline constexpr\
    \ std::array<std::pair<KYOPRO_BASE_INT, KYOPRO_BASE_INT>, 4> beside{{{-1, 0},\
    \ {0, -1}, {1, 0}, {0, 1}}};\n    inline constexpr std::array<std::pair<KYOPRO_BASE_INT,\
    \ KYOPRO_BASE_INT>, 8> around{{{-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1,\
    \ 1}, {0, 1}, {-1, 1}}};\n} // namespace kpr\n#line 5 \"template/fix_vector_bool.hpp\"\
    \n\ntemplate<>\nstruct std::vector<bool>: std::basic_string<bool> {\n    using\
    \ std::basic_string<bool>::basic_string, std::basic_string<bool>::operator =;\n\
    \    explicit vector(std::size_t n): vector(n, false) {}\n};\n#line 4 \"template/len.hpp\"\
    \n\nnamespace kpr {\n    [[maybe_unused]] inline constexpr struct {\n        template<class\
    \ T>\n        constexpr KYOPRO_BASE_INT operator ()(T&& a) const noexcept {\n\
    \            return std::size(a);\n        }\n    } len;\n} // namespace kpr\n\
    #line 4 \"template/macro.hpp\"\n#include <memory>\n#line 2 \"system/in.hpp\"\n\
    #include <unistd.h>\n#line 4 \"system/in.hpp\"\n#include <bitset>\n#line 7 \"\
    system/in.hpp\"\n#include <cstdio>\n#line 5 \"system/io_option.hpp\"\n\nnamespace\
    \ kpr {\n    template<class Tuple, std::size_t idx>\n    struct Indexed {\n  \
    \      Tuple args_tuple;\n        template<class... Args>\n        constexpr Indexed(Args&&...\
    \ args) noexcept: args_tuple{std::forward<Args>(args)...} {}\n    };\n\n    template<std::size_t\
    \ i, class... Args>\n    constexpr auto indexed(Args&&... args) noexcept {\n \
    \       return Indexed<std::tuple<Args>..., i>{std::forward<Args>(args)...};\n\
    \    }\n\n    template<class Tuple, bool... seps>\n    struct SepWith {\n    \
    \    Tuple args_tuple;\n        template<class... Args>\n        constexpr SepWith(Args&&...\
    \ args) noexcept: args_tuple{std::forward<Args>(args)...} {}\n    };\n\n    template<bool...\
    \ seps, class... Args>\n    constexpr auto sep_with(Args&&... args) noexcept {\n\
    \        return SepWith<std::tuple<Args...>, seps...>{std::forward<Args>(args)...};\n\
    \    }\n} // namespace kpr\n#line 16 \"system/in.hpp\"\n\nnamespace kpr {\n  \
    \  // \u30D0\u30C3\u30D5\u30A1\u3092\u7528\u3044\u3066\u30D5\u30A1\u30A4\u30EB\
    \u3092\u8AAD\u307F\u8FBC\u3080\u30AF\u30E9\u30B9\n    template<std::size_t buf_size\
    \ = KYOPRO_BUFFER_SIZE>\n    struct Reader {\n    private:\n        int fd, idx;\n\
    \        std::array<char, buf_size> buffer;\n\n    public:\n        // \u30D0\u30C3\
    \u30D5\u30A1\u30B5\u30A4\u30BA\u3092\u53D6\u5F97\n        static constexpr KYOPRO_BASE_INT\
    \ get_buf_size() noexcept {\n            return buf_size;\n        }\n\n     \
    \   Reader() {\n            read(fd, buffer.begin(), buf_size);\n        }\n \
    \       Reader(int fd): fd(fd), idx(0), buffer() {\n            read(fd, buffer.begin(),\
    \ buf_size);\n        }\n        Reader(FILE* fp): fd(fileno(fp)), idx(0), buffer()\
    \ {\n            read(fd, buffer.begin(), buf_size);\n        }\n\n        //\
    \ \u5165\u529B\u30A4\u30C6\u30EC\u30FC\u30BF\n        struct iterator {\n    \
    \    private:\n            Reader& reader;\n\n        public:\n            using\
    \ difference_type = void;\n            using value_type = void;\n            using\
    \ pointer = void;\n            using reference = void;\n            using iterator_category\
    \ = std::input_iterator_tag;\n\n            iterator() noexcept = default;\n \
    \           iterator(Reader& reader) noexcept: reader(reader) {}\n\n         \
    \   iterator& operator ++() {\n                ++reader.idx;\n               \
    \ if (reader.idx == buf_size) {\n                    read(reader.fd, reader.buffer.begin(),\
    \ buf_size);\n                    reader.idx = 0;\n                }\n       \
    \         return *this;\n            }\n\n            iterator operator ++(int)\
    \ {\n                iterator before = *this;\n                operator ++();\n\
    \                return before;\n            }\n\n            char& operator *()\
    \ const {\n                return reader.buffer[reader.idx];\n            }\n\
    \        };\n\n        // \u30D5\u30A1\u30A4\u30EB\u306E\u6700\u521D\u3092\u793A\
    \u3059\u30A4\u30C6\u30EC\u30FC\u30BF\u3092\u53D6\u5F97\n        iterator begin()\
    \ noexcept {\n            return iterator(*this);\n        }\n    };\n\n    //\
    \ \u6A19\u6E96\u5165\u529B\n    Reader input{0};\n\n\n    // \u5024\u306E\u5165\
    \u529B\u306E\u95A2\u6570\u30AF\u30E9\u30B9\n    template<class, class = void>\n\
    \    struct ScanFunction;\n\n    // \u5165\u529B\u30A4\u30C6\u30EC\u30FC\u30BF\
    \u3092\u7528\u3044\u3066\u5024\u3092\u5165\u529B\u3059\u308B\u30AF\u30E9\u30B9\
    \n    template<class Iterator, std::size_t decimal_precision = KYOPRO_DECIMAL_PRECISION>\n\
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
    } // namespace kpr\n#line 3 \"system/out.hpp\"\n#include <algorithm>\n#line 6\
    \ \"system/out.hpp\"\n#include <cmath>\n#line 11 \"system/out.hpp\"\n#include\
    \ <string_view>\n#line 19 \"system/out.hpp\"\n\nnamespace kpr {\n    // \u30D0\
    \u30C3\u30D5\u30A1\u3092\u7528\u3044\u3066\u30D5\u30A1\u30A4\u30EB\u306B\u66F8\
    \u304D\u8FBC\u3080\u30AF\u30E9\u30B9\n    template<std::size_t buf_size = KYOPRO_BUFFER_SIZE>\n\
    \    struct Writer {\n    private:\n        int fd, idx;\n        std::array<char,\
    \ buf_size> buffer;\n\n    public:\n        // \u30D0\u30C3\u30D5\u30A1\u30B5\u30A4\
    \u30BA\u3092\u53D6\u5F97\n        static constexpr KYOPRO_BASE_INT get_buf_size()\
    \ noexcept {\n            return buf_size;\n        }\n\n        Writer() noexcept\
    \ = default;\n        Writer(int fd) noexcept: fd(fd), idx(0), buffer() {}\n \
    \       Writer(FILE* fp) noexcept: fd(fileno(fp)), idx(0), buffer() {}\n\n   \
    \     ~Writer() {\n            write(fd, buffer.begin(), idx);\n        }\n\n\
    \        // \u51FA\u529B\u30A4\u30C6\u30EC\u30FC\u30BF\n        struct iterator\
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
    \u3001\u6A19\u6E96\u30A8\u30E9\u30FC\u51FA\u529B\n    Writer output{1}, error{2};\n\
    \n    // \u5024\u306E\u51FA\u529B\u306E\u95A2\u6570\u30AF\u30E9\u30B9\n    template<class,\
    \ class = void>\n    struct PrintFunction;\n\n    // \u51FA\u529B\u30A4\u30C6\u30EC\
    \u30FC\u30BF\u3092\u7528\u3044\u3066\u5024\u3092\u51FA\u529B\u3059\u308B\u30AF\
    \u30E9\u30B9\n    template<class Iterator, bool _space = true, bool _line = true,\
    \ bool _debug = false, bool _comment = false, bool _flush = false, std::size_t\
    \ decimal_precision = KYOPRO_DECIMAL_PRECISION>\n    struct Printer {\n      \
    \  using iterator_type = Iterator;\n\n        // \u6307\u5B9A\u3055\u308C\u305F\
    \u30AA\u30D7\u30B7\u30E7\u30F3\n        static constexpr bool space = _space,\
    \ line = _line, debug = _debug, comment = _comment, flush = _flush;\n\n      \
    \  // \u6307\u5B9A\u3055\u308C\u305F\u5C0F\u6570\u8AA4\u5DEE\u3092\u53D6\u5F97\
    \n        static constexpr KYOPRO_BASE_INT get_decimal_precision() noexcept {\n\
    \            return decimal_precision;\n        }\n\n        // \u51FA\u529B\u30A4\
    \u30C6\u30EC\u30FC\u30BF\n        Iterator itr;\n\n        Printer() noexcept\
    \ = default;\n        Printer(Iterator itr) noexcept: itr(itr) {}\n\n        //\
    \ \u4E00\u6587\u5B57\u51FA\u529B\u3059\u308B\n        void print_char(char c)\
    \ {\n            *itr = c;\n            ++itr;\n        }\n\n        // \u6574\
    \u6570\u3001\u5C0F\u6570\u3092\u51FA\u529B\n        template<class T>\n      \
    \  void print_arithmetic(T a) {\n            if constexpr (is_floating_point_v<T>)\
    \ {\n                if (a == std::numeric_limits<T>::infinity()) {\n        \
    \            PrintFunction<const char[4]>::print(printer, \"inf\");\n        \
    \            return;\n                }\n                if (a == -std::numeric_limits<T>::infinity())\
    \ {\n                    PrintFunction<const char[5]>::print(printer, \"-inf\"\
    );\n                    return;\n                }\n                if (std::isnan(a))\
    \ {\n                    PrintFunction<const char[4]>::print(printer, \"nan\"\
    );\n                    return;\n                }\n            }\n          \
    \  if constexpr (std::is_signed_v<T>) if (a < 0) {\n                printer.print_char('-');\n\
    \                a = -a;\n            }\n            std::uint_fast64_t p = a;\n\
    \            std::string s;\n            do {\n                s += '0' + p %\
    \ 10;\n                p /= 10;\n            } while (p > 0);\n            for\
    \ (auto i = s.rbegin(); i != s.rend(); ++i) printer.print_char(*i);\n        \
    \    if constexpr (is_integer_v<T>) return;\n            printer.print_char('.');\n\
    \            a -= p;\n            for (int i = 0; i < static_cast<int>(decimal_precision);\
    \ ++i) {\n                a *= 10;\n                printer.print_char('0' + static_cast<std::uint_fast64_t>(a)\
    \ % 10);\n            }\n        }\n\n        // \u533A\u5207\u308A\u3092\u51FA\
    \u529B\u3059\u308B\n        void print_sep() {\n            if constexpr (debug)\
    \ print_char(',');\n            if constexpr (space) print_char(' ');\n      \
    \  }\n\n        // \u6700\u5F8C\u306E\u6587\u5B57\u3092\u51FA\u529B\u3059\u308B\
    \n        void print_end() {\n            if constexpr (debug) print_char(',');\n\
    \            if constexpr (line) print_char('\\n');\n        }\n\n        // \u30B3\
    \u30E1\u30F3\u30C8\u8A18\u53F7\u3092\u51FA\u529B\u3059\u308B\n        void print_comment()\
    \ {\n            if constexpr (comment) {\n                print_char('#');\n\
    \                print_char(' ');\n            }\n        }\n\n        // \u8907\
    \u6570\u306E\u5024\u3092\u51FA\u529B\n        template<bool first = true>\n  \
    \      void operator ()() {\n            if constexpr (first) print_comment();\n\
    \            print_end();\n            if constexpr (flush) itr.flush();\n   \
    \     }\n        template<bool first = true, class Head, class... Args>\n    \
    \    void operator ()(Head&& head, Args&&... args) {\n            if constexpr\
    \ (first) print_comment();\n            else {\n                if constexpr (debug)\
    \ print_char(',');\n                print_sep();\n            }\n            PrintFunction<std::decay_t<Head>>::print(*this,\
    \ std::forward<Head>(head));\n            operator ()<false>(std::forward<Args>(args)...);\n\
    \        }\n    };\n\n    template<>\n    struct PrintFunction<char> {\n     \
    \   template<class Printer>\n        static void print(Printer& printer, char\
    \ a) {\n            if constexpr (debug) printer.print_char('\\'');\n        \
    \    printer.print_char(a);\n            if constexpr (debug) printer.print_char('\\\
    '');\n        }\n    };\n\n    template<>\n    struct PrintFunction<bool> {\n\
    \        template<class Printer>\n        static void print(Printer& printer,\
    \ bool a) {\n            printer.print_char(static_cast<char>('0' + a));\n   \
    \     }\n    };\n\n    template<class T>\n    struct PrintFunction<T, std::enable_if_t<std::is_convertible_v<T,\
    \ std::string_view>>> {\n        template<class Printer>\n        static void\
    \ print(Printer& printer, std::string_view a) {\n            if constexpr (debug)\
    \ printer.print_char('\"');\n            for (char i: a) printer.print_char(i);\n\
    \            if constexpr (debug) printer.print_char('\"');\n        }\n    };\n\
    \n    template<std::size_t len>\n    struct PrintFunction<std::bitset<len>> {\n\
    \        template<class Printer>\n        static void print(Printer& printer,\
    \ const std::bitset<len>& a) {\n            for (int i = len - 1; i >= 0; --i)\
    \ PrintFunction<bool>::print(printer, a[i]);\n        }\n    };\n\n    template<class\
    \ T>\n    struct PrintFunction<T, std::enable_if_t<std::is_arithmetic_v<T>>> {\n\
    \        template<class Printer>\n        static void print(Printer& printer,\
    \ T a) {\n\n        }\n    };\n\n    template<class T>\n    struct PrintFunction<T,\
    \ std::enable_if_t<is_tuple_like_v<T> && !is_range_v<T>>> {\n        template<class\
    \ Printer, std::size_t i = 0>\n        static void print(Printer& printer, const\
    \ T& a) {\n            if constexpr (debug && i == 0) printer.print_char('{');\n\
    \            if constexpr (tuple_like_size_v<T> != 0) PrintFunction<std::decay_t<tuple_like_element_t<i,\
    \ T>>>::print(printer, get<i>(a));\n            if constexpr (i + 1 < tuple_like_size_v<T>)\
    \ {\n                printer.print_sep();\n                print<i + 1>(printer,\
    \ a);\n            } else if constexpr (debug) printer.print_char('}');\n    \
    \    }\n    };\n\n    template<class T>\n    struct PrintFunction<T, std::enable_if_t<is_range_v<T>>>\
    \ {\n        template<class Printer>\n        static void print(Printer& printer,\
    \ const T& a) {\n            if constexpr (debug) print_char('{');\n         \
    \   if (std::empty(a)) return;\n            for (auto i = std::begin(a); ; ) {\n\
    \                PrintFunction<range_value_t<T>>::print(printer, *i);\n      \
    \          if (++i != std::end(a)) printer.print_sep();\n                else\
    \ break;\n            }\n            if constexpr (debug) print_char('}');\n \
    \       }\n    };\n\n    template<class Tuple, std::size_t idx>\n    struct PrintFunction<Indexed<Tuple,\
    \ idx>> {\n        template<class Printer>\n        struct PrinterWrapper: Printer\
    \ {\n            template<class T>\n            void printer_arithmetic(T a) {\n\
    \                print_arithmetic(a - 1);\n            }\n        };\n       \
    \ template<class Printer>\n        static void scan(Printer& printer, const Indexed<Tuple,\
    \ idx>& a) {\n            PrinterWrapper<Printer>& printer_wrapper = static_cast<PrinterWrapper<Printer>&>(printer);\n\
    \            PrintFunction<Tuple>::print(printer_wrapper, a.args_tuple);\n   \
    \     }\n    };\n\n    // \u6A19\u6E96\u51FA\u529B\u3001\u6A19\u6E96\u30A8\u30E9\
    \u30FC\u51FA\u529B\u306B\u5024\u3092\u51FA\u529B\u3059\u308B(\u6539\u884C\u3001\
    \u533A\u5207\u308A\u6587\u5B57\u306A\u3057)\n    Printer<Writer<>::iterator, false,\
    \ false> print{output.begin()}, eprint{error.begin()};\n    // \u6A19\u6E96\u51FA\
    \u529B\u3001\u6A19\u6E96\u30A8\u30E9\u30FC\u51FA\u529B\u306B\u5024\u3092\u51FA\
    \u529B\u3059\u308B(\u6539\u884C\u3001\u533A\u5207\u308A\u6587\u5B57\u3042\u308A\
    )\n    Printer<Writer<>::iterator> println{output.begin()}, eprintln{error.begin()};\n\
    } // namespace kpr\n#line 9 \"template/macro.hpp\"\n\nnamespace kpr::helper {\n\
    \    template<std::size_t len>\n    constexpr std::size_t va_args_size(const char\
    \ (&s)[len]) noexcept {\n        if constexpr (len == 1) return 0;\n        std::size_t\
    \ cnt = 1;\n        std::uint_fast64_t bracket = 0;\n        for (auto i: s) {\n\
    \            if (i == '(') ++bracket;\n            else if (i == ')') --bracket;\n\
    \            else if (i == ',' && bracket == 0) ++cnt;\n        }\n        return\
    \ cnt;\n    }\n\n    template<class F, std::size_t... idx>\n    auto read_impl(F&&\
    \ f, std::index_sequence<idx...>) {\n        return std::tuple{(static_cast<void>(idx),\
    \ f())...};\n    }\n\n    Printer<Writer<>::iterator, true, true, true, true,\
    \ true> debug_impl(output.begin());\n\n    template<bool flag, std::size_t len>\n\
    \    void print_if(const char (&s)[len]) {\n        if constexpr (flag) print('\
    \ ', s);\n    }\n\n    struct LambdaArg {};\n} // namespace kpr::helper\n\n#define\
    \ read(type_or_init, ...)                                                    \
    \       \\\nauto [__VA_ARGS__] = (kpr::helper::read_impl(([]() {             \
    \                      \\\n    using T = std::decay_t<decltype(*new type_or_init)>;\
    \                                  \\\n    alignas(T) std::byte storage[sizeof(T)];\
    \                                              \\\n    T* p = new (storage) type_or_init;\
    \                                                    \\\n    kpr::scan(*p);  \
    \                                                                   \\\n    T\
    \ res = std::move(*p);                                                       \
    \         \\\n    p->~T();                                                   \
    \                           \\\n    return res;                              \
    \                                             \\\n}), std::make_index_sequence<kpr::helper::va_args_size(#__VA_ARGS__)>()))\n\
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
    \ std::rend(__VA_ARGS__)\n#line 4 \"template/make_array.hpp\"\n\nnamespace kpr\
    \ {\n    [[maybe_unused]] inline constexpr struct {\n        template<class T>\n\
    \        constexpr auto operator ()(const T& init = {}) noexcept {\n         \
    \   return init;\n        }\n\n        template<class T, std::size_t length, std::size_t...\
    \ lengths>\n        constexpr auto operator ()(const T& init = {}) noexcept {\n\
    \            auto elm = operator ()<T, lengths...>(init);\n            std::array<decltype(elm),\
    \ length> res;\n            for (auto& i: res) i = elm;\n            return res;\n\
    \        }\n    } make_array;\n} // namespace kpr\n#line 6 \"template/make_vector.hpp\"\
    \n\nnamespace kpr {\n    [[maybe_unused]] inline constexpr struct {\n        template<std::size_t\
    \ idx = 0, std::size_t n, class T>\n        auto operator ()(const std::size_t\
    \ (&d)[n], T&& init) noexcept {\n            if constexpr (idx < n) return std::vector(d[idx],\
    \ operator ()<idx + 1>(d, std::forward<T>(init)));\n            else return init;\n\
    \        }\n\n        template<class T, std::size_t idx = 0, std::size_t n>\n\
    \        auto operator ()(const std::size_t (&d)[n], const T& init = {}) noexcept\
    \ {\n            if constexpr (idx < n) return std::vector(d[idx], operator ()<idx\
    \ + 1>(d, init));\n            else return init;\n        }\n    } make_vector;\n\
    } // namespace kpr\n#line 3 \"template/stl.hpp\"\n#include <cctype>\n#include\
    \ <cerrno>\n#include <cfloat>\n#include <ciso646>\n#include <climits>\n#include\
    \ <clocale>\n#line 10 \"template/stl.hpp\"\n#include <csetjmp>\n#include <csignal>\n\
    #include <cstdarg>\n#line 15 \"template/stl.hpp\"\n#include <cstdlib>\n#include\
    \ <cstring>\n#include <ctime>\n\n#include <ccomplex>\n#include <cfenv>\n#include\
    \ <cinttypes>\n#include <cstdalign>\n#include <cstdbool>\n#line 25 \"template/stl.hpp\"\
    \n#include <ctgmath>\n#include <cwchar>\n#include <cwctype>\n\n#line 31 \"template/stl.hpp\"\
    \n#include <complex>\n#include <deque>\n#include <exception>\n#include <fstream>\n\
    #line 36 \"template/stl.hpp\"\n#include <iomanip>\n#include <ios>\n#include <iosfwd>\n\
    #include <iostream>\n#include <istream>\n#line 43 \"template/stl.hpp\"\n#include\
    \ <list>\n#include <locale>\n#line 47 \"template/stl.hpp\"\n#include <new>\n#include\
    \ <numeric>\n#include <ostream>\n#line 52 \"template/stl.hpp\"\n#include <sstream>\n\
    #line 54 \"template/stl.hpp\"\n#include <stdexcept>\n#include <streambuf>\n#line\
    \ 57 \"template/stl.hpp\"\n#include <typeinfo>\n#line 59 \"template/stl.hpp\"\n\
    #include <valarray>\n#line 61 \"template/stl.hpp\"\n\n#line 63 \"template/stl.hpp\"\
    \n#include <atomic>\n#include <chrono>\n#include <condition_variable>\n#include\
    \ <forward_list>\n#include <future>\n#include <initializer_list>\n#include <mutex>\n\
    #include <random>\n#include <ratio>\n#include <regex>\n#include <scoped_allocator>\n\
    #include <system_error>\n#include <thread>\n#line 77 \"template/stl.hpp\"\n#include\
    \ <typeindex>\n#line 11 \"template/template.hpp\"\n"
  code: '#pragma once

    #include "alias.hpp"

    #include "amin_amax.hpp"

    #include "constant.hpp"

    #include "fix_vector_bool.hpp"

    #include "len.hpp"

    #include "macro.hpp"

    #include "make_array.hpp"

    #include "make_vector.hpp"

    #include "stl.hpp"

    '
  dependsOn:
  - template/alias.hpp
  - algorithm/Hash.hpp
  - meta/tuple_like.hpp
  - meta/trait.hpp
  - math/DynamicModInt.hpp
  - meta/constant.hpp
  - math/power.hpp
  - meta/setting.hpp
  - math/Montgomery.hpp
  - math/ModInt.hpp
  - algorithm/bit.hpp
  - math/mod.hpp
  - template/amin_amax.hpp
  - template/constant.hpp
  - template/fix_vector_bool.hpp
  - template/len.hpp
  - template/macro.hpp
  - system/system.hpp
  - system/in.hpp
  - system/io_option.hpp
  - system/out.hpp
  - template/make_array.hpp
  - template/make_vector.hpp
  - template/stl.hpp
  isVerificationFile: false
  path: template/template.hpp
  requiredBy:
  - all.hpp
  timestamp: '2023-02-10 23:05:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/template.hpp
layout: document
redirect_from:
- /library/template/template.hpp
- /library/template/template.hpp.html
title: template/template.hpp
---
