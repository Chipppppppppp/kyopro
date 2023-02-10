---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: algorithm/Hash.hpp
    title: algorithm/Hash.hpp
  - icon: ':question:'
    path: algorithm/bit.hpp
    title: algorithm/bit.hpp
  - icon: ':question:'
    path: math/DynamicModInt.hpp
    title: math/DynamicModInt.hpp
  - icon: ':warning:'
    path: math/ModInt.hpp
    title: math/ModInt.hpp
  - icon: ':question:'
    path: math/Montgomery.hpp
    title: math/Montgomery.hpp
  - icon: ':warning:'
    path: math/mod.hpp
    title: math/mod.hpp
  - icon: ':question:'
    path: math/power.hpp
    title: math/power.hpp
  - icon: ':question:'
    path: meta/constant.hpp
    title: meta/constant.hpp
  - icon: ':question:'
    path: meta/setting.hpp
    title: meta/setting.hpp
  - icon: ':question:'
    path: meta/trait.hpp
    title: meta/trait.hpp
  - icon: ':question:'
    path: meta/tuple_like.hpp
    title: meta/tuple_like.hpp
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
  bundledCode: "#line 2 \"template/alias.hpp\"\n#include <cstdint>\r\n#include <limits>\r\
    \n#include <functional>\r\n#include <tuple>\r\n#include <utility>\r\n#include\
    \ <vector>\r\n#include <string>\r\n#include <set>\r\n#include <map>\r\n#include\
    \ <unordered_set>\r\n#include <unordered_map>\r\n#include <queue>\r\n#include\
    \ <stack>\r\n#line 2 \"algorithm/Hash.hpp\"\n#include <cstddef>\r\n#line 4 \"\
    algorithm/Hash.hpp\"\n#include <iterator>\r\n#include <type_traits>\r\n#line 7\
    \ \"meta/trait.hpp\"\n\r\nnamespace kpr {\r\n    namespace helper {\r\n      \
    \  template<class T>\r\n        struct is_integer_helper {\r\n            static\
    \ constexpr bool value = std::is_integral_v<T>;\r\n        };\r\n\r\n        #ifdef\
    \ __SIZEOF_INT128__\r\n        template<>\r\n        struct is_integer_helper<__int128_t>\
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
    \n} // namespace kpr\r\n#line 7 \"meta/tuple_like.hpp\"\n\r\nnamespace kpr {\r\
    \n    namespace helper {\r\n        struct CastableToAny {\r\n            template<class\
    \ T>\r\n            operator T() const noexcept;\r\n        };\r\n\r\n       \
    \ template<class T, std::size_t... idx, std::void_t<decltype(T{((void)idx, CastableToAny{})...})>*\
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
    \n        }\r\n    };\r\n} // namespace kpr\r\n#line 3 \"math/power.hpp\"\n\r\n\
    namespace kpr {\r\n    [[maybe_unused]] inline constexpr struct {\r\n        template<class\
    \ T>\r\n        constexpr T operator ()(T a, std::uint_fast64_t n, T init = 1)\
    \ const noexcept {\r\n            while (n > 0) {\r\n                if (n & 1)\
    \ init *= a;\r\n                a *= a;\r\n                n >>= 1;\r\n      \
    \      }\r\n            return init;\r\n        }\r\n    } power;\r\n} // namespace\
    \ kpr\r\n#line 3 \"meta/setting.hpp\"\n\r\n#ifndef KYOPRO_BASE_INT\r\n// \u57FA\
    \u672C\u7B26\u53F7\u4ED8\u304D\u6574\u6570\u578B\r\n#define KYOPRO_BASE_INT std::int64_t\r\
    \n#endif\r\n\r\n#ifndef KYOPRO_BASE_UINT\r\n// \u57FA\u672C\u7B26\u53F7\u306A\u3057\
    \u6574\u6570\u578B\r\n#define KYOPRO_BASE_UINT std::uint64_t\r\n#endif\r\n\r\n\
    #ifndef KYOPRO_BASE_FLOAT\r\n// \u57FA\u672C\u6D6E\u52D5\u5C0F\u6570\u70B9\u6570\
    \u578B\r\n#define KYOPRO_BASE_FLOAT double\r\n#endif\r\n\r\n#ifndef KYOPRO_DEFAULT_MOD\r\
    \n// \u554F\u984C\u3067\u8A2D\u5B9A\u3055\u308C\u305Fmod\r\n#define KYOPRO_DEFAULT_MOD\
    \ (static_cast<KYOPRO_BASE_UINT>(998244353))\r\n#endif\r\n\r\n#ifndef KYOPRO_DECIMAL_PRECISION\r\
    \n// \u5C0F\u6570\u7CBE\u5EA6(\u6841)\r\n#define KYOPRO_DECIMAL_PRECISION (static_cast<KYOPRO_BASE_UINT>(12))\r\
    \n#endif\r\n\r\n#ifndef KYOPRO_INF_DIV\r\n// \u7121\u9650\u5927\u3092\u8868\u3059\
    \u6574\u6570\u304C\u6700\u5927\u5024\u306E\u4F55\u5206\u306E\u4E00\u304B\u3092\
    \u8868\u3059\r\n#define KYOPRO_INF_DIV (static_cast<KYOPRO_BASE_UINT>(3))\r\n\
    #endif\r\n\r\n#ifndef KYOPRO_BUFFER_SIZE\r\n// \u30C7\u30D5\u30A9\u30EB\u30C8\u306E\
    \u30D0\u30C3\u30D5\u30A1\u30B5\u30A4\u30BA\r\n#define KYOPRO_BUFFER_SIZE (static_cast<KYOPRO_BASE_UINT>(2048))\r\
    \n#endif\r\n#line 5 \"meta/constant.hpp\"\n\r\nnamespace kpr {\r\n    // \u554F\
    \u984C\u3067\u8A2D\u5B9A\u3055\u308C\u305Fmod\r\n    template<class T>\r\n   \
    \ inline constexpr T MOD = KYOPRO_DEFAULT_MOD;\r\n    // \u554F\u984C\u3067\u8A2D\
    \u5B9A\u3055\u308C\u305Fmod\r\n    inline constexpr KYOPRO_BASE_INT mod = MOD<KYOPRO_BASE_INT>;\r\
    \n\r\n    // \u7121\u9650\u5927\u3092\u8868\u3059\u6574\u6570\r\n    template<class\
    \ T>\r\n    inline constexpr T INF = std::numeric_limits<T>::max() / KYOPRO_INF_DIV;\r\
    \n    // \u7121\u9650\u5927\u3092\u8868\u3059\u6574\u6570\r\n    inline constexpr\
    \ KYOPRO_BASE_INT inf = INF<KYOPRO_BASE_INT>;\r\n\r\n    // \u8A31\u5BB9\u3055\
    \u308C\u308B\u5C0F\u6570\u8AA4\u5DEE\r\n    template<class T, KYOPRO_BASE_UINT\
    \ decimal_precision = KYOPRO_DECIMAL_PRECISION>\r\n    inline constexpr KYOPRO_BASE_FLOAT\
    \ EPS = static_cast<T>(1) / power(10ULL, decimal_precision);\r\n    // \u8A31\u5BB9\
    \u3055\u308C\u308B\u5C0F\u6570\u8AA4\u5DEE\r\n    inline constexpr KYOPRO_BASE_FLOAT\
    \ eps = EPS<KYOPRO_BASE_FLOAT>;\r\n\r\n    // \u5186\u5468\u7387\r\n    template<class\
    \ T>\r\n    inline constexpr T PI = 3.14159265358979323846;\r\n    // \u5186\u5468\
    \u7387\r\n    inline constexpr KYOPRO_BASE_FLOAT pi = PI<KYOPRO_BASE_FLOAT>;\r\
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
    \ namespace kpr\r\n#line 11 \"math/DynamicModInt.hpp\"\n\r\nnamespace kpr {\r\n\
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
    \      return lhs.value != rhs.value;\r\n        }\r\n\r\n        template<class\
    \ Scanner>\r\n        void scan(Scanner& scanner) {\r\n            std::int_fast64_t\
    \ value;\r\n            scanner.scan(value);\r\n            value = montgomery.transform(value\
    \ % montgomery.mod + montgomery.mod);\r\n        }\r\n\r\n        template<class\
    \ Printer>\r\n        void print(Printer& printer) const {\r\n            printer.print(montgomery.inverse_transform(value));\r\
    \n        }\r\n    };\r\n\r\n    template<class T, std::size_t kind>\r\n    struct\
    \ Hash<DynamicModInt<T, kind>> {\r\n        using value_type = DynamicModInt<T,\
    \ kind>;\r\n\r\n        std::size_t operator ()(DynamicModInt<T, kind> a) const\
    \ noexcept {\r\n            return static_cast<std::size_t>(a);\r\n        }\r\
    \n    };\r\n} // namespace kpr\r\n#line 2 \"math/ModInt.hpp\"\n#include <cassert>\r\
    \n#line 6 \"algorithm/bit.hpp\"\n\r\nnamespace kpr {\r\n    // \u7ACB\u3063\u3066\
    \u3044\u308Bbit\u306E\u500B\u6570\u3092\u8FD4\u3059\r\n    [[maybe_unused]] inline\
    \ constexpr struct {\r\n        template<class T>\r\n        constexpr KYOPRO_BASE_INT\
    \ operator ()(T x) const noexcept {\r\n            static_assert(is_integer_v<T>,\
    \ \"The argument must be an integer\");\r\n            constexpr auto digits =\
    \ std::numeric_limits<std::make_unsigned_t<T>>::digits;\r\n            static_assert(digits\
    \ <= std::numeric_limits<unsigned long long>::digits, \"The integer type of the\
    \ argument is too large\");\r\n            if constexpr (digits <= std::numeric_limits<unsigned\
    \ int>::digits) return __builtin_popcount(x);\r\n            else if constexpr\
    \ (digits <= std::numeric_limits<unsigned long>::digits) return __builtin_popcountl(x);\r\
    \n            else return __builtin_popcountll(x);\r\n        }\r\n    } pop_count;\r\
    \n\r\n    [[maybe_unused]] inline constexpr struct {\r\n        template<class\
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
    } // namespace kpr\r\n#line 4 \"math/mod.hpp\"\n\r\nnamespace kpr {\r\n    [[maybe_unused]]\
    \ inline constexpr struct {\r\n        template<class T, class U>\r\n        constexpr\
    \ std::common_type_t<T, U> operator ()(T x, U m) const noexcept {\r\n        \
    \    static_assert(is_integer_v<T> && is_integer_v<U>, \"Both of the arguments\
    \ must be integers\");\r\n            if constexpr (is_unsigned_integer_v<T> ||\
    \ is_unsigned_integer_v<U>) return x % m;\r\n            return (x %= m) < 0 ?\
    \ x + m : x;\r\n        }\r\n    } floor_mod;\r\n\r\n    [[maybe_unused]] inline\
    \ constexpr struct {\r\n        template<class T, class U>\r\n        constexpr\
    \ std::common_type_t<T, U> operator ()(T x, U m) const noexcept {\r\n        \
    \    return m - floor_mod(x - 1, m) - static_cast<T>(1);\r\n        }\r\n    }\
    \ ceil_mod;\r\n} // namespace kpr\r\n#line 14 \"math/ModInt.hpp\"\n\r\nnamespace\
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
    \ Hash<ModInt<mod>> {\r\n        using value_type = ModInt<mod>;\r\n        constexpr\
    \ std::size_t operator ()(ModInt<mod> a) const noexcept {\r\n            return\
    \ static_cast<std::size_t>(a);\r\n        }\r\n    };\r\n} // namespace kpr\r\n\
    #line 19 \"template/alias.hpp\"\n\r\nnamespace kpr {\r\n    using ll = long long;\r\
    \n    using ull = unsigned long long;\r\n    using lf = double;\r\n\r\n    using\
    \ i8 = std::int8_t;\r\n    using u8 = std::uint8_t;\r\n    using i16 = std::int16_t;\r\
    \n    using u16 = std::uint16_t;\r\n    using i32 = std::int32_t;\r\n    using\
    \ u32 = std::uint32_t;\r\n    using i64 = std::int64_t;\r\n    using u64 = std::uint64_t;\r\
    \n    #ifdef __SIZEOF_INT128__\r\n    using i128 = __int128_t;\r\n    using u128\
    \ = __uint128_t;\r\n    #endif\r\n    #ifdef __SIZEOF_FLOAT128__\r\n    using\
    \ f128 = __float128;\r\n    #endif\r\n\r\n    using mint = ModInt<mod>;\r\n  \
    \  using dmint = DynamicModInt<KYOPRO_BASE_UINT>;\r\n\r\n    template<class T,\
    \ std::size_t idx, class... Args>\r\n    struct agg_type {\r\n        using type\
    \ = typename agg_type<T, idx - 1, T, Args...>::type;\r\n    };\r\n    template<class\
    \ T, class... Args>\r\n    struct agg_type<T, 0, Args...> {\r\n        using type\
    \ = std::tuple<Args...>;\r\n    };\r\n    template<class T>\r\n    struct agg_type<T,\
    \ 0, T, T> {\r\n        using type = std::pair<T, T>;\r\n    };\r\n\r\n    template<class\
    \ T, std::size_t idx>\r\n    using agg = typename agg_type<T, idx>::type;\r\n\
    \    using ll1 = agg<ll, 1>;\r\n    using ll2 = agg<ll, 2>;\r\n    using ll3 =\
    \ agg<ll, 3>;\r\n    using ll4 = agg<ll, 4>;\r\n    using ll5 = agg<ll, 5>;\r\n\
    \r\n    template<class T>\r\n    using vec = std::vector<T>;\r\n    template<class\
    \ T>\r\n    using vec1 = vec<T>;\r\n    template<class T>\r\n    using vec2 =\
    \ std::vector<vec1<T>>;\r\n    template<class T>\r\n    using vec3 = std::vector<vec2<T>>;\r\
    \n    template<class T>\r\n    using vec4 = std::vector<vec3<T>>;\r\n    template<class\
    \ T>\r\n    using vec5 = std::vector<vec4<T>>;\r\n\r\n    template<class Key,\
    \ class Compare = std::less<Key>>\r\n    using mset = std::unordered_set<Key,\
    \ Compare>;\r\n    template<class Key, class T, class Compare = std::less<Key>>\r\
    \n    using mmap = std::unordered_map<Key, T, Compare>;\r\n    template<class\
    \ Key>\r\n    using hset = std::unordered_set<Key, Hash<Key>>;\r\n    template<class\
    \ Key, class T>\r\n    using hmap = std::unordered_map<Key, T, Hash<Key>>;\r\n\
    \    template<class Key>\r\n    using hmiset = std::unordered_multiset<Key, Hash<Key>>;\r\
    \n    template<class Key, class T>\r\n    using hmmap = std::unordered_multimap<Key,\
    \ T, Hash<Key>>;\r\n    template<class T, class Compare = std::less<T>, class\
    \ Container = std::vector<T>>\r\n    using priq = std::priority_queue<T, Container,\
    \ Compare>;\r\n    template<class T, class Compare = std::greater<T>, class Container\
    \ = std::vector<T>>\r\n    using heapq = priq<T, Compare, Container>;\r\n} //\
    \ namespace kpr\r\n\r\nusing namespace std;\r\nusing namespace kpr;\r\n"
  code: "#pragma once\r\n#include <cstdint>\r\n#include <limits>\r\n#include <functional>\r\
    \n#include <tuple>\r\n#include <utility>\r\n#include <vector>\r\n#include <string>\r\
    \n#include <set>\r\n#include <map>\r\n#include <unordered_set>\r\n#include <unordered_map>\r\
    \n#include <queue>\r\n#include <stack>\r\n#include \"../algorithm/Hash.hpp\"\r\
    \n#include \"../math/DynamicModInt.hpp\"\r\n#include \"../math/ModInt.hpp\"\r\n\
    #include \"../meta/setting.hpp\"\r\n\r\nnamespace kpr {\r\n    using ll = long\
    \ long;\r\n    using ull = unsigned long long;\r\n    using lf = double;\r\n\r\
    \n    using i8 = std::int8_t;\r\n    using u8 = std::uint8_t;\r\n    using i16\
    \ = std::int16_t;\r\n    using u16 = std::uint16_t;\r\n    using i32 = std::int32_t;\r\
    \n    using u32 = std::uint32_t;\r\n    using i64 = std::int64_t;\r\n    using\
    \ u64 = std::uint64_t;\r\n    #ifdef __SIZEOF_INT128__\r\n    using i128 = __int128_t;\r\
    \n    using u128 = __uint128_t;\r\n    #endif\r\n    #ifdef __SIZEOF_FLOAT128__\r\
    \n    using f128 = __float128;\r\n    #endif\r\n\r\n    using mint = ModInt<mod>;\r\
    \n    using dmint = DynamicModInt<KYOPRO_BASE_UINT>;\r\n\r\n    template<class\
    \ T, std::size_t idx, class... Args>\r\n    struct agg_type {\r\n        using\
    \ type = typename agg_type<T, idx - 1, T, Args...>::type;\r\n    };\r\n    template<class\
    \ T, class... Args>\r\n    struct agg_type<T, 0, Args...> {\r\n        using type\
    \ = std::tuple<Args...>;\r\n    };\r\n    template<class T>\r\n    struct agg_type<T,\
    \ 0, T, T> {\r\n        using type = std::pair<T, T>;\r\n    };\r\n\r\n    template<class\
    \ T, std::size_t idx>\r\n    using agg = typename agg_type<T, idx>::type;\r\n\
    \    using ll1 = agg<ll, 1>;\r\n    using ll2 = agg<ll, 2>;\r\n    using ll3 =\
    \ agg<ll, 3>;\r\n    using ll4 = agg<ll, 4>;\r\n    using ll5 = agg<ll, 5>;\r\n\
    \r\n    template<class T>\r\n    using vec = std::vector<T>;\r\n    template<class\
    \ T>\r\n    using vec1 = vec<T>;\r\n    template<class T>\r\n    using vec2 =\
    \ std::vector<vec1<T>>;\r\n    template<class T>\r\n    using vec3 = std::vector<vec2<T>>;\r\
    \n    template<class T>\r\n    using vec4 = std::vector<vec3<T>>;\r\n    template<class\
    \ T>\r\n    using vec5 = std::vector<vec4<T>>;\r\n\r\n    template<class Key,\
    \ class Compare = std::less<Key>>\r\n    using mset = std::unordered_set<Key,\
    \ Compare>;\r\n    template<class Key, class T, class Compare = std::less<Key>>\r\
    \n    using mmap = std::unordered_map<Key, T, Compare>;\r\n    template<class\
    \ Key>\r\n    using hset = std::unordered_set<Key, Hash<Key>>;\r\n    template<class\
    \ Key, class T>\r\n    using hmap = std::unordered_map<Key, T, Hash<Key>>;\r\n\
    \    template<class Key>\r\n    using hmiset = std::unordered_multiset<Key, Hash<Key>>;\r\
    \n    template<class Key, class T>\r\n    using hmmap = std::unordered_multimap<Key,\
    \ T, Hash<Key>>;\r\n    template<class T, class Compare = std::less<T>, class\
    \ Container = std::vector<T>>\r\n    using priq = std::priority_queue<T, Container,\
    \ Compare>;\r\n    template<class T, class Compare = std::greater<T>, class Container\
    \ = std::vector<T>>\r\n    using heapq = priq<T, Compare, Container>;\r\n} //\
    \ namespace kpr\r\n\r\nusing namespace std;\r\nusing namespace kpr;\r\n"
  dependsOn:
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
  isVerificationFile: false
  path: template/alias.hpp
  requiredBy:
  - template/template.hpp
  - all.hpp
  timestamp: '2023-02-11 02:36:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/alias.hpp
layout: document
redirect_from:
- /library/template/alias.hpp
- /library/template/alias.hpp.html
title: template/alias.hpp
---
