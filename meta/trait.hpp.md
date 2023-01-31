---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
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
    path: all.hpp
    title: all.hpp
  - icon: ':warning:'
    path: all/all.hpp
    title: all/all.hpp
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
  - icon: ':warning:'
    path: math/div.hpp
    title: math/div.hpp
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
    path: meta/meta.hpp
    title: meta/meta.hpp
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
    path: range/range.hpp
    title: range/range.hpp
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
  - icon: ':warning:'
    path: template/alias.hpp
    title: template/alias.hpp
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
  bundledCode: "#line 2 \"meta/trait.hpp\"\n#include <cstddef>\n#include <iterator>\n\
    #include <tuple>\n#include <type_traits>\n#include <utility>\n\nnamespace kpr\
    \ {\n    namespace helper {\n        template<class T>\n        struct is_integer_helper\
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
    } // namespace kpr\n"
  code: "#pragma once\n#include <cstddef>\n#include <iterator>\n#include <tuple>\n\
    #include <type_traits>\n#include <utility>\n\nnamespace kpr {\n    namespace helper\
    \ {\n        template<class T>\n        struct is_integer_helper {\n         \
    \   static constexpr bool value = std::is_integral_v<T>;\n        };\n\n     \
    \   #ifdef __SIZEOF_INT128__\n        template<>\n        struct is_integer_helper<__int128_t>\
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
    } // namespace kpr\n"
  dependsOn: []
  isVerificationFile: false
  path: meta/trait.hpp
  requiredBy:
  - all/all.hpp
  - meta/tuple_like.hpp
  - meta/meta.hpp
  - system/in.hpp
  - system/out.hpp
  - system/system.hpp
  - function/monoid.hpp
  - function/function.hpp
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - structure/structure.hpp
  - structure/FenwickTree.hpp
  - structure/UnionFind.hpp
  - range/range.hpp
  - range/irange.hpp
  - range/imap.hpp
  - math/ModInt.hpp
  - math/Barrett.hpp
  - math/is_prime.hpp
  - math/math.hpp
  - math/factorize.hpp
  - math/div.hpp
  - math/DynamicModInt.hpp
  - algorithm/Hash.hpp
  - algorithm/algorithm.hpp
  - algorithm/bit.hpp
  - all.hpp
  timestamp: '2023-02-01 00:00:26+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/aoj/PrimeNumber.test.cpp
  - verify/yosupo/point_add_range_sum.test.cpp
  - verify/yosupo/unionfind.test.cpp
  - verify/yosupo/factorize.test.cpp
  - verify/yosupo/many_aplusb.test.cpp
documentation_of: meta/trait.hpp
layout: document
redirect_from:
- /library/meta/trait.hpp
- /library/meta/trait.hpp.html
title: meta/trait.hpp
---
