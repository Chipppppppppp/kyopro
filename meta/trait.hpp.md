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
  - icon: ':warning:'
    path: algorithm/all.hpp
    title: algorithm/all.hpp
  - icon: ':x:'
    path: math/DynamicModInt.hpp
    title: math/DynamicModInt.hpp
  - icon: ':warning:'
    path: math/ModInt.hpp
    title: math/ModInt.hpp
  - icon: ':warning:'
    path: math/all.hpp
    title: math/all.hpp
  - icon: ':x:'
    path: math/factorize.hpp
    title: math/factorize.hpp
  - icon: ':x:'
    path: math/is_prime.hpp
    title: math/is_prime.hpp
  - icon: ':question:'
    path: meta/aggregate.hpp
    title: meta/aggregate.hpp
  - icon: ':warning:'
    path: meta/all.hpp
    title: meta/all.hpp
  - icon: ':warning:'
    path: range/all.hpp
    title: range/all.hpp
  - icon: ':warning:'
    path: range/imap.hpp
    title: range/imap.hpp
  - icon: ':warning:'
    path: range/range_base.hpp
    title: range/range_base.hpp
  - icon: ':heavy_check_mark:'
    path: structure/UnionFind.hpp
    title: structure/UnionFind.hpp
  - icon: ':warning:'
    path: structure/all.hpp
    title: structure/all.hpp
  - icon: ':question:'
    path: system/all.hpp
    title: system/all.hpp
  - icon: ':question:'
    path: system/in.hpp
    title: system/in.hpp
  - icon: ':question:'
    path: system/out.hpp
    title: system/out.hpp
  - icon: ':warning:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':warning:'
    path: template/all.hpp
    title: template/all.hpp
  - icon: ':warning:'
    path: template/macro.hpp
    title: template/macro.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/aoj/PrimeNumber.test.cpp
    title: verify/aoj/PrimeNumber.test.cpp
  - icon: ':x:'
    path: verify/yosupo/factorize.test.cpp
    title: verify/yosupo/factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/many_aplusb.test.cpp
    title: verify/yosupo/many_aplusb.test.cpp
  - icon: ':x:'
    path: verify/yosupo/point_add_range_sum.test.cpp
    title: verify/yosupo/point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/unionfind.test.cpp
    title: verify/yosupo/unionfind.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"meta/trait.hpp\"\n#include <cstddef>\n#include <iterator>\n\
    #include <queue>\n#include <limits>\n#include <stack>\n#include <type_traits>\n\
    #include <utility>\n\ntemplate<>\nstruct std::is_integral<__int128_t>: std::true_type\
    \ {};\ntemplate<>\nstruct std::is_integral<__uint128_t>: std::true_type {};\n\
    template<>\nstruct std::is_floating_point<__float128>: std::true_type {};\n\n\
    namespace kyopro {\n    template<std::size_t size>\n    struct int_least {\n \
    \   private:\n        static constexpr auto get_type() noexcept {\n          \
    \  static_assert(size <= 128, \"Integer size is too large\");\n            if\
    \ constexpr (size <= 8) return std::int_least8_t{};\n            else if constexpr\
    \ (size <= 16) return std::int_least16_t{};\n            else if constexpr (size\
    \ <= 32) return std::int_least32_t{};\n            else if constexpr (size <=\
    \ 64) return std::int_least64_t{};\n            else return __int128_t{};\n  \
    \      }\n\n    public:\n        using type = decltype(get_type());\n    };\n\n\
    \    template<std::size_t size>\n    using int_least_t = typename int_least<size>::type;\n\
    \n    template<std::size_t size>\n    struct uint_least {\n    private:\n    \
    \    static constexpr auto get_type() noexcept {\n            static_assert(size\
    \ <= 128, \"Integer size is too large\");\n            if constexpr (size <= 8)\
    \ return std::uint_least8_t{};\n            else if constexpr (size <= 16) return\
    \ std::uint_least16_t{};\n            else if constexpr (size <= 32) return std::uint_least32_t{};\n\
    \            else if constexpr (size <= 64) return std::uint_least64_t{};\n  \
    \          else return __uint128_t{};\n        }\n\n    public:\n        using\
    \ type = decltype(get_type());\n    };\n\n    template<std::size_t size>\n   \
    \ using uint_least_t = typename uint_least<size>::type;\n\n    template<class,\
    \ class = void>\n    struct is_iterator: std::false_type {};\n    template<class\
    \ T>\n    struct is_iterator<T, std::void_t<typename std::iterator_traits<T>::iterator_category>>:\
    \ std::true_type {};\n\n    template<class T>\n    constexpr bool is_iterator_v\
    \ = is_iterator<T>::value;\n\n    template<class, class = void>\n    struct is_range:\
    \ std::false_type {};\n    template<class T>\n    struct is_range<T, std::void_t<decltype(std::begin(std::declval<std::add_lvalue_reference_t<T>>()),\
    \ std::end(std::declval<std::add_lvalue_reference_t<T>>()))>>: std::true_type\
    \ {};\n\n    template<class T>\n    constexpr bool is_range_v = is_range<T>::value;\n\
    \n    template<class T>\n    struct range_iterator {\n        using type = std::decay_t<decltype(std::begin(std::declval<T>()))>;\n\
    \    };\n\n    template<class T>\n    using range_iterator_t = typename range_iterator<T>::type;\n\
    \n    template<class T>\n    struct range_const_iterator {\n        using type\
    \ = std::decay_t<decltype(std::cbegin(std::declval<T>()))>;\n    };\n\n    template<class\
    \ T>\n    using range_const_iterator_t = typename range_iterator<T>::type;\n\n\
    \    template<class T>\n    struct range_value {\n        using type = std::decay_t<decltype(*std::begin(std::declval<T>()))>;\n\
    \    };\n\n    template<class T>\n    using range_value_t = typename range_value<T>::type;\n\
    \n    namespace helper {\n        struct CastableToAny {\n            template<class\
    \ T>\n            operator T() const noexcept;\n        };\n\n        template<class\
    \ T, std::size_t... idx, std::void_t<decltype(T{((void)idx, CastableToAny{})...})>*\
    \ = nullptr>\n        constexpr bool is_aggregate_initializable(std::index_sequence<idx...>,\
    \ bool) noexcept {\n            return true;\n        }\n        template<class\
    \ T, std::size_t... idx>\n        constexpr bool is_aggregate_initializable(std::index_sequence<idx...>,\
    \ char) noexcept {\n            return false;\n        }\n\n        template<class\
    \ T, std::size_t n, std::enable_if_t<is_aggregate_initializable<T>(std::make_index_sequence<n>(),\
    \ false)>* = nullptr>\n        constexpr std::size_t aggregate_size_impl() {\n\
    \            return n;\n        }\n        template<class T, std::size_t n, std::enable_if_t<!is_aggregate_initializable<T>(std::make_index_sequence<n>(),\
    \ false)>* = nullptr>\n        constexpr std::size_t aggregate_size_impl() {\n\
    \            static_assert(n != 0, \"Aggregate is required\");\n            return\
    \ aggregate_size_impl<T, n - 1>();\n        }\n    } // namespace helper\n\n \
    \   template<class T, class = void>\n    struct aggregate_size {\n        static_assert(std::is_aggregate_v<T>,\
    \ \"Aggregate is required\");\n        static constexpr std::size_t value = helper::aggregate_size_impl<T,\
    \ std::numeric_limits<unsigned char>::digits * sizeof(T)>();\n    };\n    template<class\
    \ T>\n    struct aggregate_size<T, std::void_t<decltype(std::tuple_size<T>::value)>>\
    \ {\n        static_assert(std::is_aggregate_v<T>, \"Aggregate is required\");\n\
    \        static constexpr std::size_t value = std::tuple_size_v<T>;\n    };\n\
    \    template<class T>\n    constexpr std::size_t aggregate_size_v = aggregate_size<T>::value;\n\
    \n    template<std::size_t idx, class T>\n    struct aggregate_element {\n   \
    \     static_assert(std::is_aggregate_v<T>);\n\n    private:\n        template<class\
    \ U>\n        struct Type {\n            using type = U;\n        };\n\n     \
    \   template<class U, std::enable_if_t<aggregate_size_v<std::decay_t<U>> == 1>*\
    \ = nullptr>\n        static constexpr auto get_type(U aggregate, char) noexcept\
    \ {\n            auto&& [a] = aggregate;\n            static_assert(idx < 1, \"\
    Tuple index out of range\");\n            return Type<decltype(a)>{};\n      \
    \  }\n        template<class U, std::enable_if_t<aggregate_size_v<std::decay_t<U>>\
    \ == 2>* = nullptr>\n        static constexpr auto get_type(U aggregate, char)\
    \ noexcept {\n            auto&& [a, b] = aggregate;\n            static_assert(idx\
    \ < 2, \"Tuple index out of range\");\n            if constexpr (idx == 0) return\
    \ Type<decltype(a)>{};\n            else return Type<decltype(b)>{};\n       \
    \ }\n        template<class U, std::enable_if_t<aggregate_size_v<std::decay_t<U>>\
    \ == 3>* = nullptr>\n        static constexpr auto get_type(U aggregate, char)\
    \ noexcept {\n            auto&& [a, b, c] = aggregate;\n            static_assert(idx\
    \ < 3, \"Tuple index out of range\");\n            if constexpr (idx == 0) return\
    \ Type<decltype(a)>{};\n            else if constexpr (idx == 1) return Type<decltype(b)>{};\n\
    \            else return Type<decltype(c)>{};\n        }\n        template<class\
    \ U, std::enable_if_t<aggregate_size_v<std::decay_t<U>> == 4>* = nullptr>\n  \
    \      static constexpr auto access_impl(U aggregate, char) noexcept {\n     \
    \       auto&& [a, b, c, d] = aggregate;\n            static_assert(idx < 4, \"\
    Tuple index out of range\");\n            if constexpr (idx == 0) return Type<decltype(a)>{};\n\
    \            else if constexpr (idx == 1) return Type<decltype(b)>{};\n      \
    \      else if constexpr (idx == 2) return Type<decltype(c)>{};\n            else\
    \ return Type<decltype(d)>{};\n        }\n        template<class U, std::enable_if_t<aggregate_size_v<std::decay_t<U>>\
    \ == 5>* = nullptr>\n        static constexpr auto get_type(U aggregate, char)\
    \ noexcept {\n            auto&& [a, b, c, d, e] = aggregate;\n            static_assert(idx\
    \ < 5, \"Tuple index out of range\");\n            if constexpr (idx == 0) return\
    \ Type<decltype(a)>{};\n            else if constexpr (idx == 1) return Type<decltype(b)>{};\n\
    \            else if constexpr (idx == 2) return Type<decltype(c)>{};\n      \
    \      else if constexpr (idx == 3) return Type<decltype(d)>{};\n            else\
    \ return Type<decltype(e)>{};\n        }\n        template<class U, std::enable_if_t<aggregate_size_v<std::decay_t<U>>\
    \ == 6>* = nullptr>\n        static constexpr auto get_type(U aggregate, char)\
    \ noexcept {\n            auto&& [a, b, c, d, e, f] = aggregate;\n           \
    \ static_assert(idx < 6, \"Tuple index out of range\");\n            if constexpr\
    \ (idx == 0) return Type<decltype(a)>{};\n            else if constexpr (idx ==\
    \ 1) return Type<decltype(b)>{};\n            else if constexpr (idx == 2) return\
    \ Type<decltype(c)>{};\n            else if constexpr (idx == 3) return Type<decltype(d)>{};\n\
    \            else if constexpr (idx == 4) return Type<decltype(e)>{};\n      \
    \      else return Type<decltype(f)>{};\n        }\n        template<class U,\
    \ std::enable_if_t<aggregate_size_v<std::decay_t<U>> == 7>* = nullptr>\n     \
    \   static constexpr auto get_type(U aggregate, char) noexcept {\n           \
    \ auto&& [a, b, c, d, e, f, g] = aggregate;\n            static_assert(idx < 7,\
    \ \"Tuple index out of range\");\n            if constexpr (idx == 0) return Type<decltype(a)>{};\n\
    \            else if constexpr (idx == 1) return Type<decltype(b)>{};\n      \
    \      else if constexpr (idx == 2) return Type<decltype(c)>{};\n            else\
    \ if constexpr (idx == 3) return Type<decltype(d)>{};\n            else if constexpr\
    \ (idx == 4) return Type<decltype(e)>{};\n            else if constexpr (idx ==\
    \ 5) return Type<decltype(f)>{};\n            else return Type<decltype(g)>{};\n\
    \        }\n        template<class U, std::enable_if_t<aggregate_size_v<std::decay_t<U>>\
    \ == 8>* = nullptr>\n        static constexpr auto get_type(U aggregate, char)\
    \ noexcept {\n            auto&& [a, b, c, d, e, f, g, h] = aggregate;\n     \
    \       static_assert(idx < 8, \"Tuple index out of range\");\n            if\
    \ constexpr (idx == 0) return Type<decltype(a)>{};\n            else if constexpr\
    \ (idx == 1) return Type<decltype(b)>{};\n            else if constexpr (idx ==\
    \ 2) return Type<decltype(c)>{};\n            else if constexpr (idx == 3) return\
    \ Type<decltype(d)>{};\n            else if constexpr (idx == 4) return Type<decltype(e)>{};\n\
    \            else if constexpr (idx == 5) return Type<decltype(f)>{};\n      \
    \      else if constexpr (idx == 6) return Type<decltype(g)>{};\n            else\
    \ return Type<decltype(h)>{};\n        }\n        template<class U, std::void_t<std::tuple_element_t<idx,\
    \ U>>* = nullptr>\n        static constexpr auto get_type(U, bool) noexcept {\n\
    \            return Type<std::tuple_element_t<idx, U>>{};\n        }\n\n    public:\n\
    \        using type = typename decltype(get_type(std::declval<T>(), false))::type;\n\
    \    };\n\n    template<std::size_t idx, class T>\n    using aggregate_element_t\
    \ = typename aggregate_element<idx, T>::type;\n\n    template<class T>\n    struct\
    \ is_agg: std::conjunction<std::is_aggregate<T>, std::negation<is_range<T>>> {};\n\
    \n    template<class T>\n    inline constexpr bool is_agg_v = is_agg<T>::value;\n\
    } // namespace kyopro\n"
  code: "#pragma once\n#include <cstddef>\n#include <iterator>\n#include <queue>\n\
    #include <limits>\n#include <stack>\n#include <type_traits>\n#include <utility>\n\
    \ntemplate<>\nstruct std::is_integral<__int128_t>: std::true_type {};\ntemplate<>\n\
    struct std::is_integral<__uint128_t>: std::true_type {};\ntemplate<>\nstruct std::is_floating_point<__float128>:\
    \ std::true_type {};\n\nnamespace kyopro {\n    template<std::size_t size>\n \
    \   struct int_least {\n    private:\n        static constexpr auto get_type()\
    \ noexcept {\n            static_assert(size <= 128, \"Integer size is too large\"\
    );\n            if constexpr (size <= 8) return std::int_least8_t{};\n       \
    \     else if constexpr (size <= 16) return std::int_least16_t{};\n          \
    \  else if constexpr (size <= 32) return std::int_least32_t{};\n            else\
    \ if constexpr (size <= 64) return std::int_least64_t{};\n            else return\
    \ __int128_t{};\n        }\n\n    public:\n        using type = decltype(get_type());\n\
    \    };\n\n    template<std::size_t size>\n    using int_least_t = typename int_least<size>::type;\n\
    \n    template<std::size_t size>\n    struct uint_least {\n    private:\n    \
    \    static constexpr auto get_type() noexcept {\n            static_assert(size\
    \ <= 128, \"Integer size is too large\");\n            if constexpr (size <= 8)\
    \ return std::uint_least8_t{};\n            else if constexpr (size <= 16) return\
    \ std::uint_least16_t{};\n            else if constexpr (size <= 32) return std::uint_least32_t{};\n\
    \            else if constexpr (size <= 64) return std::uint_least64_t{};\n  \
    \          else return __uint128_t{};\n        }\n\n    public:\n        using\
    \ type = decltype(get_type());\n    };\n\n    template<std::size_t size>\n   \
    \ using uint_least_t = typename uint_least<size>::type;\n\n    template<class,\
    \ class = void>\n    struct is_iterator: std::false_type {};\n    template<class\
    \ T>\n    struct is_iterator<T, std::void_t<typename std::iterator_traits<T>::iterator_category>>:\
    \ std::true_type {};\n\n    template<class T>\n    constexpr bool is_iterator_v\
    \ = is_iterator<T>::value;\n\n    template<class, class = void>\n    struct is_range:\
    \ std::false_type {};\n    template<class T>\n    struct is_range<T, std::void_t<decltype(std::begin(std::declval<std::add_lvalue_reference_t<T>>()),\
    \ std::end(std::declval<std::add_lvalue_reference_t<T>>()))>>: std::true_type\
    \ {};\n\n    template<class T>\n    constexpr bool is_range_v = is_range<T>::value;\n\
    \n    template<class T>\n    struct range_iterator {\n        using type = std::decay_t<decltype(std::begin(std::declval<T>()))>;\n\
    \    };\n\n    template<class T>\n    using range_iterator_t = typename range_iterator<T>::type;\n\
    \n    template<class T>\n    struct range_const_iterator {\n        using type\
    \ = std::decay_t<decltype(std::cbegin(std::declval<T>()))>;\n    };\n\n    template<class\
    \ T>\n    using range_const_iterator_t = typename range_iterator<T>::type;\n\n\
    \    template<class T>\n    struct range_value {\n        using type = std::decay_t<decltype(*std::begin(std::declval<T>()))>;\n\
    \    };\n\n    template<class T>\n    using range_value_t = typename range_value<T>::type;\n\
    \n    namespace helper {\n        struct CastableToAny {\n            template<class\
    \ T>\n            operator T() const noexcept;\n        };\n\n        template<class\
    \ T, std::size_t... idx, std::void_t<decltype(T{((void)idx, CastableToAny{})...})>*\
    \ = nullptr>\n        constexpr bool is_aggregate_initializable(std::index_sequence<idx...>,\
    \ bool) noexcept {\n            return true;\n        }\n        template<class\
    \ T, std::size_t... idx>\n        constexpr bool is_aggregate_initializable(std::index_sequence<idx...>,\
    \ char) noexcept {\n            return false;\n        }\n\n        template<class\
    \ T, std::size_t n, std::enable_if_t<is_aggregate_initializable<T>(std::make_index_sequence<n>(),\
    \ false)>* = nullptr>\n        constexpr std::size_t aggregate_size_impl() {\n\
    \            return n;\n        }\n        template<class T, std::size_t n, std::enable_if_t<!is_aggregate_initializable<T>(std::make_index_sequence<n>(),\
    \ false)>* = nullptr>\n        constexpr std::size_t aggregate_size_impl() {\n\
    \            static_assert(n != 0, \"Aggregate is required\");\n            return\
    \ aggregate_size_impl<T, n - 1>();\n        }\n    } // namespace helper\n\n \
    \   template<class T, class = void>\n    struct aggregate_size {\n        static_assert(std::is_aggregate_v<T>,\
    \ \"Aggregate is required\");\n        static constexpr std::size_t value = helper::aggregate_size_impl<T,\
    \ std::numeric_limits<unsigned char>::digits * sizeof(T)>();\n    };\n    template<class\
    \ T>\n    struct aggregate_size<T, std::void_t<decltype(std::tuple_size<T>::value)>>\
    \ {\n        static_assert(std::is_aggregate_v<T>, \"Aggregate is required\");\n\
    \        static constexpr std::size_t value = std::tuple_size_v<T>;\n    };\n\
    \    template<class T>\n    constexpr std::size_t aggregate_size_v = aggregate_size<T>::value;\n\
    \n    template<std::size_t idx, class T>\n    struct aggregate_element {\n   \
    \     static_assert(std::is_aggregate_v<T>);\n\n    private:\n        template<class\
    \ U>\n        struct Type {\n            using type = U;\n        };\n\n     \
    \   template<class U, std::enable_if_t<aggregate_size_v<std::decay_t<U>> == 1>*\
    \ = nullptr>\n        static constexpr auto get_type(U aggregate, char) noexcept\
    \ {\n            auto&& [a] = aggregate;\n            static_assert(idx < 1, \"\
    Tuple index out of range\");\n            return Type<decltype(a)>{};\n      \
    \  }\n        template<class U, std::enable_if_t<aggregate_size_v<std::decay_t<U>>\
    \ == 2>* = nullptr>\n        static constexpr auto get_type(U aggregate, char)\
    \ noexcept {\n            auto&& [a, b] = aggregate;\n            static_assert(idx\
    \ < 2, \"Tuple index out of range\");\n            if constexpr (idx == 0) return\
    \ Type<decltype(a)>{};\n            else return Type<decltype(b)>{};\n       \
    \ }\n        template<class U, std::enable_if_t<aggregate_size_v<std::decay_t<U>>\
    \ == 3>* = nullptr>\n        static constexpr auto get_type(U aggregate, char)\
    \ noexcept {\n            auto&& [a, b, c] = aggregate;\n            static_assert(idx\
    \ < 3, \"Tuple index out of range\");\n            if constexpr (idx == 0) return\
    \ Type<decltype(a)>{};\n            else if constexpr (idx == 1) return Type<decltype(b)>{};\n\
    \            else return Type<decltype(c)>{};\n        }\n        template<class\
    \ U, std::enable_if_t<aggregate_size_v<std::decay_t<U>> == 4>* = nullptr>\n  \
    \      static constexpr auto access_impl(U aggregate, char) noexcept {\n     \
    \       auto&& [a, b, c, d] = aggregate;\n            static_assert(idx < 4, \"\
    Tuple index out of range\");\n            if constexpr (idx == 0) return Type<decltype(a)>{};\n\
    \            else if constexpr (idx == 1) return Type<decltype(b)>{};\n      \
    \      else if constexpr (idx == 2) return Type<decltype(c)>{};\n            else\
    \ return Type<decltype(d)>{};\n        }\n        template<class U, std::enable_if_t<aggregate_size_v<std::decay_t<U>>\
    \ == 5>* = nullptr>\n        static constexpr auto get_type(U aggregate, char)\
    \ noexcept {\n            auto&& [a, b, c, d, e] = aggregate;\n            static_assert(idx\
    \ < 5, \"Tuple index out of range\");\n            if constexpr (idx == 0) return\
    \ Type<decltype(a)>{};\n            else if constexpr (idx == 1) return Type<decltype(b)>{};\n\
    \            else if constexpr (idx == 2) return Type<decltype(c)>{};\n      \
    \      else if constexpr (idx == 3) return Type<decltype(d)>{};\n            else\
    \ return Type<decltype(e)>{};\n        }\n        template<class U, std::enable_if_t<aggregate_size_v<std::decay_t<U>>\
    \ == 6>* = nullptr>\n        static constexpr auto get_type(U aggregate, char)\
    \ noexcept {\n            auto&& [a, b, c, d, e, f] = aggregate;\n           \
    \ static_assert(idx < 6, \"Tuple index out of range\");\n            if constexpr\
    \ (idx == 0) return Type<decltype(a)>{};\n            else if constexpr (idx ==\
    \ 1) return Type<decltype(b)>{};\n            else if constexpr (idx == 2) return\
    \ Type<decltype(c)>{};\n            else if constexpr (idx == 3) return Type<decltype(d)>{};\n\
    \            else if constexpr (idx == 4) return Type<decltype(e)>{};\n      \
    \      else return Type<decltype(f)>{};\n        }\n        template<class U,\
    \ std::enable_if_t<aggregate_size_v<std::decay_t<U>> == 7>* = nullptr>\n     \
    \   static constexpr auto get_type(U aggregate, char) noexcept {\n           \
    \ auto&& [a, b, c, d, e, f, g] = aggregate;\n            static_assert(idx < 7,\
    \ \"Tuple index out of range\");\n            if constexpr (idx == 0) return Type<decltype(a)>{};\n\
    \            else if constexpr (idx == 1) return Type<decltype(b)>{};\n      \
    \      else if constexpr (idx == 2) return Type<decltype(c)>{};\n            else\
    \ if constexpr (idx == 3) return Type<decltype(d)>{};\n            else if constexpr\
    \ (idx == 4) return Type<decltype(e)>{};\n            else if constexpr (idx ==\
    \ 5) return Type<decltype(f)>{};\n            else return Type<decltype(g)>{};\n\
    \        }\n        template<class U, std::enable_if_t<aggregate_size_v<std::decay_t<U>>\
    \ == 8>* = nullptr>\n        static constexpr auto get_type(U aggregate, char)\
    \ noexcept {\n            auto&& [a, b, c, d, e, f, g, h] = aggregate;\n     \
    \       static_assert(idx < 8, \"Tuple index out of range\");\n            if\
    \ constexpr (idx == 0) return Type<decltype(a)>{};\n            else if constexpr\
    \ (idx == 1) return Type<decltype(b)>{};\n            else if constexpr (idx ==\
    \ 2) return Type<decltype(c)>{};\n            else if constexpr (idx == 3) return\
    \ Type<decltype(d)>{};\n            else if constexpr (idx == 4) return Type<decltype(e)>{};\n\
    \            else if constexpr (idx == 5) return Type<decltype(f)>{};\n      \
    \      else if constexpr (idx == 6) return Type<decltype(g)>{};\n            else\
    \ return Type<decltype(h)>{};\n        }\n        template<class U, std::void_t<std::tuple_element_t<idx,\
    \ U>>* = nullptr>\n        static constexpr auto get_type(U, bool) noexcept {\n\
    \            return Type<std::tuple_element_t<idx, U>>{};\n        }\n\n    public:\n\
    \        using type = typename decltype(get_type(std::declval<T>(), false))::type;\n\
    \    };\n\n    template<std::size_t idx, class T>\n    using aggregate_element_t\
    \ = typename aggregate_element<idx, T>::type;\n\n    template<class T>\n    struct\
    \ is_agg: std::conjunction<std::is_aggregate<T>, std::negation<is_range<T>>> {};\n\
    \n    template<class T>\n    inline constexpr bool is_agg_v = is_agg<T>::value;\n\
    } // namespace kyopro"
  dependsOn: []
  isVerificationFile: false
  path: meta/trait.hpp
  requiredBy:
  - system/all.hpp
  - system/in.hpp
  - system/out.hpp
  - math/ModInt.hpp
  - math/all.hpp
  - math/factorize.hpp
  - math/is_prime.hpp
  - math/DynamicModInt.hpp
  - structure/all.hpp
  - structure/UnionFind.hpp
  - range/all.hpp
  - range/range_base.hpp
  - range/imap.hpp
  - algorithm/algorithm.hpp
  - algorithm/Hash.hpp
  - algorithm/all.hpp
  - template/macro.hpp
  - template/all.hpp
  - template/alias.hpp
  - meta/aggregate.hpp
  - meta/all.hpp
  timestamp: '2022-08-08 07:54:18+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/aoj/PrimeNumber.test.cpp
  - verify/yosupo/point_add_range_sum.test.cpp
  - verify/yosupo/factorize.test.cpp
  - verify/yosupo/unionfind.test.cpp
  - verify/yosupo/many_aplusb.test.cpp
documentation_of: meta/trait.hpp
layout: document
redirect_from:
- /library/meta/trait.hpp
- /library/meta/trait.hpp.html
title: meta/trait.hpp
---
