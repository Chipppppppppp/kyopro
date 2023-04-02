---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: kyopro/function/monoid.hpp
    title: kyopro/function/monoid.hpp
  - icon: ':question:'
    path: kyopro/meta/setting.hpp
    title: kyopro/meta/setting.hpp
  - icon: ':question:'
    path: kyopro/meta/trait.hpp
    title: kyopro/meta/trait.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/aoj/WeightedUnionFind.test.cpp
    title: verify/aoj/WeightedUnionFind.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"kyopro/data_structure/WeightedUnionFind.hpp\"\n#include\
    \ <algorithm>\n#include <type_traits>\n#include <unordered_map>\n#include <utility>\n\
    #include <vector>\n#line 2 \"kyopro/function/monoid.hpp\"\n#include <limits>\r\
    \n#line 2 \"kyopro/meta/setting.hpp\"\n#include <cstdint>\r\n\r\n#ifndef KYOPRO_BASE_INT\r\
    \n// \u57FA\u672C\u7B26\u53F7\u4ED8\u304D\u6574\u6570\u578B\r\n#define KYOPRO_BASE_INT\
    \ std::int64_t\r\n#endif\r\n\r\n#ifndef KYOPRO_BASE_UINT\r\n// \u57FA\u672C\u7B26\
    \u53F7\u306A\u3057\u6574\u6570\u578B\r\n#define KYOPRO_BASE_UINT std::uint64_t\r\
    \n#endif\r\n\r\n#ifndef KYOPRO_BASE_FLOAT\r\n// \u57FA\u672C\u6D6E\u52D5\u5C0F\
    \u6570\u70B9\u6570\u578B\r\n#define KYOPRO_BASE_FLOAT double\r\n#endif\r\n\r\n\
    #ifndef KYOPRO_DEFAULT_MOD\r\n// \u554F\u984C\u3067\u8A2D\u5B9A\u3055\u308C\u305F\
    mod\r\n#define KYOPRO_DEFAULT_MOD (static_cast<KYOPRO_BASE_UINT>(998244353))\r\
    \n#endif\r\n\r\n#ifndef KYOPRO_DECIMAL_PRECISION\r\n// \u5C0F\u6570\u7CBE\u5EA6\
    (\u6841)\r\n#define KYOPRO_DECIMAL_PRECISION (static_cast<KYOPRO_BASE_UINT>(12))\r\
    \n#endif\r\n\r\n#ifndef KYOPRO_INF_DIV\r\n// \u7121\u9650\u5927\u3092\u8868\u3059\
    \u6574\u6570\u304C\u6700\u5927\u5024\u306E\u4F55\u5206\u306E\u4E00\u304B\u3092\
    \u8868\u3059\r\n#define KYOPRO_INF_DIV (static_cast<KYOPRO_BASE_UINT>(3))\r\n\
    #endif\r\n\r\n#ifndef KYOPRO_BUFFER_SIZE\r\n// \u30C7\u30D5\u30A9\u30EB\u30C8\u306E\
    \u30D0\u30C3\u30D5\u30A1\u30B5\u30A4\u30BA\r\n#define KYOPRO_BUFFER_SIZE (static_cast<KYOPRO_BASE_UINT>(2048))\r\
    \n#endif\r\n#line 2 \"kyopro/meta/trait.hpp\"\n#include <cstddef>\r\n#include\
    \ <iterator>\r\n#include <tuple>\r\n#line 7 \"kyopro/meta/trait.hpp\"\n\r\nnamespace\
    \ kpr {\r\n    namespace helper {\r\n        template<class T>\r\n        struct\
    \ is_integer_helper {\r\n            static constexpr bool value = std::is_integral_v<T>;\r\
    \n        };\r\n\r\n        #ifdef __SIZEOF_INT128__\r\n        template<>\r\n\
    \        struct is_integer_helper<__int128_t> {\r\n            static constexpr\
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
    \n} // namespace kpr\r\n#line 6 \"kyopro/function/monoid.hpp\"\n\r\nnamespace\
    \ kpr {\r\n    // \u8DB3\u3057\u7B97\u306Emonoid\r\n    template<class T>\r\n\
    \    struct Add {\r\n        static_assert(is_arithmetic_v<T>, \"T must be an\
    \ arithmetic type\");\r\n\r\n        using value_type = T;\r\n\r\n        static\
    \ constexpr T id() noexcept {\r\n            return T{};\r\n        }\r\n\r\n\
    \        constexpr T operator ()(const T& a, const T& b) const noexcept {\r\n\
    \            return a + b;\r\n        }\r\n\r\n        static constexpr T inv(const\
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
    \ bool has_inv_v = has_inv<T>::value;\r\n} // namespace kpr\r\n#line 10 \"kyopro/data_structure/WeightedUnionFind.hpp\"\
    \n\nnamespace kpr {\n    template<class T, class Op = Add<T>>\n    struct WeightedUnionFind\
    \ {\n    private:\n        std::vector<int> par;\n        std::vector<T> diff_weight;\n\
    \        Op op;\n\n    public:\n        WeightedUnionFind() noexcept = default;\n\
    \        WeightedUnionFind(std::size_t n) noexcept: par(n, -1), diff_weight(n,\
    \ op.id()) {}\n\n        void resize(std::size_t n) {\n            par.resize(n,\
    \ -1);\n            diff_weight.resize(n, op.id());\n        }\n        void assign(std::size_t\
    \ n) {\n            par.assign(n, -1);\n            diff_weight.assign(n, op.id());\n\
    \        }\n        void clear() {\n            std::fill(par.begin(), par.end(),\
    \ -1);\n            std::fill(diff_weight.begin(), diff_weight.end(), op.id());\n\
    \        }\n\n        std::size_t size() const noexcept {\n            return\
    \ par.size();\n        }\n\n        KYOPRO_BASE_INT find(int x) {\n          \
    \  if (par[x] == x) return x;\n            int r = find(par[x]);\n           \
    \ diff_weight[x] = op(std::move(diff_weight[x]), diff_weight[par[x]]);\n     \
    \       return par[x] = r;\n        }\n\n        T weight(int x) {\n         \
    \   static_cast<void>(find(x));\n            return diff_weight[x];\n        }\n\
    \n        T diff(int x, int y) {\n            op(weight(y), op.inv(weight(x)));\n\
    \        }\n\n        bool merge(int x, int y, T w) {\n            x = find(x),\
    \ y = find(y);\n            w = op(std::move(w), op(diff_weight[x], op.inv(diff_weight[y])));\n\
    \            if (x == y) return false;\n            if (par[x] > par[y]) {\n \
    \               par[y] += par[x];\n                par[x] = y;\n             \
    \   diff_weight[x] = w;\n            } else {\n                par[x] += par[y];\n\
    \                par[y] = x;\n                diff_weight[y] = w;\n          \
    \  }\n            return true;\n        }\n\n        bool same(int x, int y) {\n\
    \            return find(x) == find(y);\n        }\n\n        KYOPRO_BASE_INT\
    \ group_size(int x) {\n            return -par[find(x)];\n        }\n\n      \
    \  std::vector<int> group_members(int x) {\n            x = find(x);\n       \
    \     std::vector<int> a;\n            for (int i = 0; i < (int)(size()); ++i)\
    \ if (find(i) == x) a.emplace_back(i);\n            return a;\n        }\n\n \
    \       template<class Vector = std::vector<KYOPRO_BASE_INT>>\n        Vector\
    \ roots() const {\n            Vector a;\n            for (int i = 0; i < (int)(size());\
    \ ++i) if (par[i] < 0) a.emplace_back(i);\n            return a;\n        }\n\n\
    \        KYOPRO_BASE_INT group_count() const {\n            KYOPRO_BASE_INT cnt\
    \ = 0;\n            for (int i = 0; i < (int)(size()); ++i) if (par[i] < 0) ++cnt;\n\
    \            return cnt;\n        }\n\n        template<class Map = std::unordered_map<KYOPRO_BASE_INT,\
    \ std::vector<KYOPRO_BASE_INT>>>\n        Map all_group_members() {\n        \
    \    Map group_members;\n            for (int member = 0; member < (int)(size());\
    \ ++member) group_members[find(member)].emplace_back(member);\n            return\
    \ group_members;\n        }\n    };\n} // namespace kpr\n"
  code: "#pragma once\n#include <algorithm>\n#include <type_traits>\n#include <unordered_map>\n\
    #include <utility>\n#include <vector>\n#include \"../function/monoid.hpp\"\n#include\
    \ \"../meta/setting.hpp\"\n#include \"../meta/trait.hpp\"\n\nnamespace kpr {\n\
    \    template<class T, class Op = Add<T>>\n    struct WeightedUnionFind {\n  \
    \  private:\n        std::vector<int> par;\n        std::vector<T> diff_weight;\n\
    \        Op op;\n\n    public:\n        WeightedUnionFind() noexcept = default;\n\
    \        WeightedUnionFind(std::size_t n) noexcept: par(n, -1), diff_weight(n,\
    \ op.id()) {}\n\n        void resize(std::size_t n) {\n            par.resize(n,\
    \ -1);\n            diff_weight.resize(n, op.id());\n        }\n        void assign(std::size_t\
    \ n) {\n            par.assign(n, -1);\n            diff_weight.assign(n, op.id());\n\
    \        }\n        void clear() {\n            std::fill(par.begin(), par.end(),\
    \ -1);\n            std::fill(diff_weight.begin(), diff_weight.end(), op.id());\n\
    \        }\n\n        std::size_t size() const noexcept {\n            return\
    \ par.size();\n        }\n\n        KYOPRO_BASE_INT find(int x) {\n          \
    \  if (par[x] == x) return x;\n            int r = find(par[x]);\n           \
    \ diff_weight[x] = op(std::move(diff_weight[x]), diff_weight[par[x]]);\n     \
    \       return par[x] = r;\n        }\n\n        T weight(int x) {\n         \
    \   static_cast<void>(find(x));\n            return diff_weight[x];\n        }\n\
    \n        T diff(int x, int y) {\n            op(weight(y), op.inv(weight(x)));\n\
    \        }\n\n        bool merge(int x, int y, T w) {\n            x = find(x),\
    \ y = find(y);\n            w = op(std::move(w), op(diff_weight[x], op.inv(diff_weight[y])));\n\
    \            if (x == y) return false;\n            if (par[x] > par[y]) {\n \
    \               par[y] += par[x];\n                par[x] = y;\n             \
    \   diff_weight[x] = w;\n            } else {\n                par[x] += par[y];\n\
    \                par[y] = x;\n                diff_weight[y] = w;\n          \
    \  }\n            return true;\n        }\n\n        bool same(int x, int y) {\n\
    \            return find(x) == find(y);\n        }\n\n        KYOPRO_BASE_INT\
    \ group_size(int x) {\n            return -par[find(x)];\n        }\n\n      \
    \  std::vector<int> group_members(int x) {\n            x = find(x);\n       \
    \     std::vector<int> a;\n            for (int i = 0; i < (int)(size()); ++i)\
    \ if (find(i) == x) a.emplace_back(i);\n            return a;\n        }\n\n \
    \       template<class Vector = std::vector<KYOPRO_BASE_INT>>\n        Vector\
    \ roots() const {\n            Vector a;\n            for (int i = 0; i < (int)(size());\
    \ ++i) if (par[i] < 0) a.emplace_back(i);\n            return a;\n        }\n\n\
    \        KYOPRO_BASE_INT group_count() const {\n            KYOPRO_BASE_INT cnt\
    \ = 0;\n            for (int i = 0; i < (int)(size()); ++i) if (par[i] < 0) ++cnt;\n\
    \            return cnt;\n        }\n\n        template<class Map = std::unordered_map<KYOPRO_BASE_INT,\
    \ std::vector<KYOPRO_BASE_INT>>>\n        Map all_group_members() {\n        \
    \    Map group_members;\n            for (int member = 0; member < (int)(size());\
    \ ++member) group_members[find(member)].emplace_back(member);\n            return\
    \ group_members;\n        }\n    };\n} // namespace kpr\n"
  dependsOn:
  - kyopro/function/monoid.hpp
  - kyopro/meta/setting.hpp
  - kyopro/meta/trait.hpp
  isVerificationFile: false
  path: kyopro/data_structure/WeightedUnionFind.hpp
  requiredBy: []
  timestamp: '2023-04-03 01:27:56+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/aoj/WeightedUnionFind.test.cpp
documentation_of: kyopro/data_structure/WeightedUnionFind.hpp
layout: document
redirect_from:
- /library/kyopro/data_structure/WeightedUnionFind.hpp
- /library/kyopro/data_structure/WeightedUnionFind.hpp.html
title: kyopro/data_structure/WeightedUnionFind.hpp
---
