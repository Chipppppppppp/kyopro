---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: kpr/meta/trait.hpp
    title: kpr/meta/trait.hpp
  - icon: ':warning:'
    path: kpr/range/iterator_base.hpp
    title: kpr/range/iterator_base.hpp
  - icon: ':warning:'
    path: kpr/range/range_base.hpp
    title: kpr/range/range_base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: kpr/range/range.hpp
    title: kpr/range/range.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"kpr/range/irange.hpp\"\n#include <cstddef>\r\n#include <functional>\r\
    \n#include <iterator>\r\n#include <type_traits>\r\n#include <utility>\r\n#line\
    \ 5 \"kpr/range/iterator_base.hpp\"\n\r\nnamespace kpr {\r\n    template<class,\
    \ class, class>\r\n    struct IteratorBase;\r\n\r\n    template<class Derived,\
    \ class ValueType>\r\n    struct IteratorBase<Derived, ValueType, std::forward_iterator_tag>\
    \ {\r\n        using value_type = std::decay_t<ValueType>;\r\n        using pointer\
    \ = value_type*;\r\n        using reference = value_type&;\r\n        using difference_type\
    \ = std::ptrdiff_t;\r\n        using iterator_category = std::forward_iterator_tag;\r\
    \n\r\n        virtual constexpr ValueType operator *() const noexcept;\r\n   \
    \     virtual constexpr Derived& operator ++() noexcept;\r\n        virtual constexpr\
    \ bool operator ==(const Derived&) const noexcept;\r\n\r\n        constexpr Derived\
    \ operator ++(int) noexcept {\r\n            Derived before = *this;\r\n     \
    \       ++*this;\r\n            return before;\r\n        }\r\n\r\n        constexpr\
    \ bool operator !=(const Derived& rhs) const noexcept {\r\n            return\
    \ !(*this == rhs);\r\n        }\r\n    };\r\n\r\n    template<class Derived, class\
    \ ValueType>\r\n    struct IteratorBase<Derived, ValueType, std::bidirectional_iterator_tag>:\
    \ IteratorBase<Derived, ValueType, std::forward_iterator_tag> {\r\n        using\
    \ iterator_category = std::bidirectional_iterator_tag;\r\n\r\n        virtual\
    \ constexpr Derived& operator --() noexcept;\r\n\r\n        constexpr Derived\
    \ operator --(int) noexcept {\r\n            Derived before = *this;\r\n     \
    \       --*this;\r\n            return before;\r\n        }\r\n    };\r\n\r\n\
    \    template<class Derived, class ValueType>\r\n    struct IteratorBase<Derived,\
    \ ValueType, std::random_access_iterator_tag>: IteratorBase<Derived, ValueType,\
    \ std::bidirectional_iterator_tag> {\r\n        using iterator_category = std::random_access_iterator_tag;\r\
    \n\r\n        virtual constexpr Derived operator +(std::ptrdiff_t rhs) const noexcept;\r\
    \n        virtual constexpr std::ptrdiff_t operator -(const Derived&) const noexcept;\r\
    \n\r\n    private:\r\n        virtual constexpr int compare(const Derived&) const\
    \ noexcept;\r\n\r\n    public:\r\n\r\n        constexpr Derived& operator +=(std::ptrdiff_t\
    \ rhs) noexcept {\r\n            return *this = *this + rhs;\r\n        }\r\n\r\
    \n        constexpr Derived operator -(std::ptrdiff_t rhs) const noexcept {\r\n\
    \            return *this + -rhs;\r\n        }\r\n\r\n        constexpr Derived&\
    \ operator -=(std::ptrdiff_t rhs) noexcept {\r\n            return *this = *this\
    \ - rhs;\r\n        }\r\n\r\n        constexpr decltype(auto) operator [](std::size_t\
    \ idx) const noexcept {\r\n            return *(*this + idx);\r\n        }\r\n\
    \r\n        constexpr bool operator ==(const Derived& rhs) const noexcept {\r\n\
    \            return compare(rhs) == 0;\r\n        }\r\n        constexpr bool\
    \ operator !=(const Derived& rhs) const noexcept {\r\n            return compare(rhs)\
    \ != 0;\r\n        }\r\n        constexpr bool operator <(const Derived& rhs)\
    \ const noexcept {\r\n            return compare(rhs) < 0;\r\n        }\r\n  \
    \      constexpr bool operator <=(const Derived& rhs) const noexcept {\r\n   \
    \         return compare(rhs) <= 0;\r\n        }\r\n        constexpr bool operator\
    \ >(const Derived& rhs) const noexcept {\r\n            return compare(rhs) >\
    \ 0;\r\n        }\r\n        constexpr bool operator >=(const Derived& rhs) const\
    \ noexcept {\r\n            return compare(rhs) >= 0;\r\n        }\r\n    };\r\
    \n} // namespace kpr\r\n#line 5 \"kpr/range/range_base.hpp\"\n\r\nnamespace kpr\
    \ {\r\n    template<class Derived, class ValueType>\r\n    struct RangeBase {\r\
    \n        using value_type = std::decay_t<ValueType>;\r\n        using size_type\
    \ = std::size_t;\r\n        using difference_type = std::ptrdiff_t;\r\n      \
    \  using reference = value_type&;\r\n        using const_reference = const value_type&;\r\
    \n        using pointer = value_type*;\r\n        using const_pointer = const\
    \ value_type*;\r\n\r\n        Derived& down_cast() noexcept {\r\n            return\
    \ static_cast<Derived&>(*this);\r\n        }\r\n        const Derived& down_cast()\
    \ const noexcept {\r\n            return static_cast<const Derived&>(*this);\r\
    \n        }\r\n\r\n        constexpr auto begin() const noexcept {\r\n       \
    \     return down_cast().begin();\r\n        }\r\n\r\n        constexpr auto end()\
    \ const noexcept {\r\n            return down_cast().end();\r\n        }\r\n\r\
    \n        constexpr auto cbegin() const noexcept {\r\n            return down_cast().cbegin();\r\
    \n        }\r\n\r\n        constexpr auto cend() const noexcept {\r\n        \
    \    return down_cast().cend();\r\n        }\r\n\r\n        constexpr bool empty()\
    \ const noexcept {\r\n            return begin() == end();\r\n        }\r\n\r\n\
    \        constexpr decltype(auto) front() noexcept {\r\n            return *begin();\r\
    \n        }\r\n        constexpr decltype(auto) front() const noexcept {\r\n \
    \           return *cbegin();\r\n        }\r\n\r\n        constexpr decltype(auto)\
    \ rbegin() const noexcept {\r\n            return std::reverse_iterator(end());\r\
    \n        }\r\n\r\n        constexpr decltype(auto) rend() const noexcept {\r\n\
    \            return std::reverse_iterator(begin());\r\n        }\r\n\r\n     \
    \   constexpr decltype(auto) crbegin() const noexcept {\r\n            return\
    \ std::reverse_iterator(cend());\r\n        }\r\n\r\n        constexpr decltype(auto)\
    \ crend() const noexcept {\r\n            return std::reverse_iterator(cbegin());\r\
    \n        }\r\n\r\n        constexpr decltype(auto) back() noexcept {\r\n    \
    \        return *rbegin();\r\n        }\r\n        constexpr decltype(auto) back()\
    \ const noexcept {\r\n            return *crbegin();\r\n        }\r\n\r\n    \
    \    constexpr std::size_t size() const noexcept {\r\n            return end()\
    \ - begin();\r\n        }\r\n\r\n        constexpr decltype(auto) operator [](std::size_t\
    \ idx) {\r\n            return *(begin() + idx);\r\n        }\r\n        constexpr\
    \ decltype(auto) operator [](std::size_t idx) const {\r\n            return *(cbegin()\
    \ + idx);\r\n        }\r\n    };\r\n} // namespace kpr\r\n#line 4 \"kpr/meta/trait.hpp\"\
    \n#include <tuple>\r\n#line 7 \"kpr/meta/trait.hpp\"\n\r\nnamespace kpr {\r\n\
    \    namespace helper {\r\n        template<class T>\r\n        struct is_integer_helper\
    \ {\r\n            static constexpr bool value = std::is_integral_v<T>;\r\n  \
    \      };\r\n\r\n        #ifdef __SIZEOF_INT128__\r\n        template<>\r\n  \
    \      struct is_integer_helper<__int128_t> {\r\n            static constexpr\
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
    \n} // namespace kpr\r\n#line 10 \"kpr/range/irange.hpp\"\n\r\nnamespace kpr {\r\
    \n    template<class T>\r\n    struct irange: RangeBase<irange<T>, T> {\r\n  \
    \  private:\r\n        T first, last;\r\n\r\n        template<class, class = void,\
    \ class = void, class = void>\r\n        struct get_iterator_category;\r\n   \
    \     template<class ValueType, class Void>\r\n        struct get_iterator_category<ValueType,\
    \ std::void_t<decltype(++std::declval<ValueType>())>, Void, Void> {\r\n      \
    \      using type = std::forward_iterator_tag;\r\n        };\r\n        template<class\
    \ ValueType, class Void>\r\n        struct get_iterator_category<ValueType, std::void_t<decltype(++std::declval<ValueType>())>,\
    \ std::void_t<decltype(--std::declval<ValueType>())>, Void> {\r\n            using\
    \ type = std::bidirectional_iterator_tag;\r\n        };\r\n        template<class\
    \ ValueType>\r\n        struct get_iterator_category<ValueType, std::void_t<decltype(++std::declval<ValueType>())>,\
    \ std::void_t<decltype(--std::declval<ValueType>())>, std::void_t<decltype(std::declval<T>()\
    \ < std::declval<ValueType>(), std::declval<ValueType>() > std::declval<ValueType>(),\
    \ std::declval<ValueType>() + std::declval<std::ptrdiff_t>(), std::declval<ValueType>()\
    \ - std::declval<ValueType>())>> {\r\n            using type = std::random_access_iterator_tag;\r\
    \n        };\r\n\r\n    public:\r\n        irange() noexcept = default;\r\n  \
    \      template<class F, class L>\r\n        irange(F&& first, L&& last) noexcept:\
    \ first(std::forward<F>(first)), last(std::forward<L>(last)) {}\r\n\r\n      \
    \  struct iterator: IteratorBase<iterator, const T&, typename get_iterator_category<T&>::type>\
    \ {\r\n        private:\r\n            T itr;\r\n\r\n            constexpr int\
    \ compare(const iterator& rhs) const noexcept {\r\n                if (itr < rhs.itr)\
    \ return -1;\r\n                else if (itr > rhs.itr) return 1;\r\n        \
    \        else return 0;\r\n            }\r\n\r\n        public:\r\n          \
    \  iterator() noexcept = default;\r\n            template<class Itr>\r\n     \
    \       iterator(Itr&& itr) noexcept: itr(std::forward<Itr>(itr)) {}\r\n\r\n \
    \           constexpr const T& operator *() const noexcept {\r\n             \
    \   return itr;\r\n            }\r\n\r\n            constexpr iterator& operator\
    \ ++() noexcept {\r\n                ++itr;\r\n                return *this;\r\
    \n            }\r\n\r\n            constexpr iterator& operator --() noexcept\
    \ {\r\n                --itr;\r\n                return *this;\r\n           \
    \ }\r\n\r\n            constexpr iterator operator +(std::ptrdiff_t rhs) const\
    \ noexcept {\r\n                return iterator{itr + rhs};\r\n            }\r\
    \n\r\n            constexpr std::ptrdiff_t operator -(const iterator& rhs) const\
    \ noexcept {\r\n                return itr - rhs.itr;\r\n            }\r\n   \
    \     };\r\n\r\n        struct const_iterator: IteratorBase<const_iterator, const\
    \ T&, typename get_iterator_category<T&>::type> {\r\n        private:\r\n    \
    \        T itr;\r\n\r\n            constexpr int compare(const const_iterator&\
    \ rhs) const noexcept {\r\n                if (itr < rhs.itr) return -1;\r\n \
    \               else if (itr > rhs.itr) return 1;\r\n                else return\
    \ 0;\r\n            }\r\n\r\n        public:\r\n            const_iterator() noexcept\
    \ = default;\r\n            template<class Itr>\r\n            const_iterator(Itr&&\
    \ itr) noexcept: itr(std::forward<Itr>(itr)) {}\r\n\r\n            constexpr const\
    \ T& operator *() const noexcept {\r\n                return itr;\r\n        \
    \    }\r\n\r\n            constexpr const_iterator& operator ++() noexcept {\r\
    \n                ++itr;\r\n                return *this;\r\n            }\r\n\
    \r\n            constexpr const_iterator& operator --() noexcept {\r\n       \
    \         --itr;\r\n                return *this;\r\n            }\r\n\r\n   \
    \         constexpr const_iterator operator +(std::ptrdiff_t rhs) const noexcept\
    \ {\r\n                return iterator{itr + rhs};\r\n            }\r\n\r\n  \
    \          constexpr std::ptrdiff_t operator -(const const_iterator& rhs) const\
    \ noexcept {\r\n                return itr - rhs.itr;\r\n            }\r\n   \
    \     };\r\n\r\n\r\n        using reverse_iterator = std::reverse_iterator<iterator>;\r\
    \n        using const_reverse_iterator = std::reverse_iterator<const_iterator>;\r\
    \n\r\n\r\n        constexpr iterator begin() const noexcept {\r\n            return\
    \ iterator{first};\r\n        }\r\n\r\n        constexpr iterator end() const\
    \ noexcept {\r\n            return iterator{last};\r\n        }\r\n\r\n      \
    \  constexpr const_iterator cbegin() const noexcept {\r\n            return const_iterator{first};\r\
    \n        }\r\n\r\n        constexpr const_iterator cend() const noexcept {\r\n\
    \            return const_iterator{last};\r\n        }\r\n    };\r\n\r\n    template<class\
    \ F, class L>\r\n    irange(F&&, L&&) -> irange<std::decay_t<F>>;\r\n} // namespace\
    \ kpr\r\n"
  code: "#pragma once\r\n#include <cstddef>\r\n#include <functional>\r\n#include <iterator>\r\
    \n#include <type_traits>\r\n#include <utility>\r\n#include \"iterator_base.hpp\"\
    \r\n#include \"range_base.hpp\"\r\n#include \"../meta/trait.hpp\"\r\n\r\nnamespace\
    \ kpr {\r\n    template<class T>\r\n    struct irange: RangeBase<irange<T>, T>\
    \ {\r\n    private:\r\n        T first, last;\r\n\r\n        template<class, class\
    \ = void, class = void, class = void>\r\n        struct get_iterator_category;\r\
    \n        template<class ValueType, class Void>\r\n        struct get_iterator_category<ValueType,\
    \ std::void_t<decltype(++std::declval<ValueType>())>, Void, Void> {\r\n      \
    \      using type = std::forward_iterator_tag;\r\n        };\r\n        template<class\
    \ ValueType, class Void>\r\n        struct get_iterator_category<ValueType, std::void_t<decltype(++std::declval<ValueType>())>,\
    \ std::void_t<decltype(--std::declval<ValueType>())>, Void> {\r\n            using\
    \ type = std::bidirectional_iterator_tag;\r\n        };\r\n        template<class\
    \ ValueType>\r\n        struct get_iterator_category<ValueType, std::void_t<decltype(++std::declval<ValueType>())>,\
    \ std::void_t<decltype(--std::declval<ValueType>())>, std::void_t<decltype(std::declval<T>()\
    \ < std::declval<ValueType>(), std::declval<ValueType>() > std::declval<ValueType>(),\
    \ std::declval<ValueType>() + std::declval<std::ptrdiff_t>(), std::declval<ValueType>()\
    \ - std::declval<ValueType>())>> {\r\n            using type = std::random_access_iterator_tag;\r\
    \n        };\r\n\r\n    public:\r\n        irange() noexcept = default;\r\n  \
    \      template<class F, class L>\r\n        irange(F&& first, L&& last) noexcept:\
    \ first(std::forward<F>(first)), last(std::forward<L>(last)) {}\r\n\r\n      \
    \  struct iterator: IteratorBase<iterator, const T&, typename get_iterator_category<T&>::type>\
    \ {\r\n        private:\r\n            T itr;\r\n\r\n            constexpr int\
    \ compare(const iterator& rhs) const noexcept {\r\n                if (itr < rhs.itr)\
    \ return -1;\r\n                else if (itr > rhs.itr) return 1;\r\n        \
    \        else return 0;\r\n            }\r\n\r\n        public:\r\n          \
    \  iterator() noexcept = default;\r\n            template<class Itr>\r\n     \
    \       iterator(Itr&& itr) noexcept: itr(std::forward<Itr>(itr)) {}\r\n\r\n \
    \           constexpr const T& operator *() const noexcept {\r\n             \
    \   return itr;\r\n            }\r\n\r\n            constexpr iterator& operator\
    \ ++() noexcept {\r\n                ++itr;\r\n                return *this;\r\
    \n            }\r\n\r\n            constexpr iterator& operator --() noexcept\
    \ {\r\n                --itr;\r\n                return *this;\r\n           \
    \ }\r\n\r\n            constexpr iterator operator +(std::ptrdiff_t rhs) const\
    \ noexcept {\r\n                return iterator{itr + rhs};\r\n            }\r\
    \n\r\n            constexpr std::ptrdiff_t operator -(const iterator& rhs) const\
    \ noexcept {\r\n                return itr - rhs.itr;\r\n            }\r\n   \
    \     };\r\n\r\n        struct const_iterator: IteratorBase<const_iterator, const\
    \ T&, typename get_iterator_category<T&>::type> {\r\n        private:\r\n    \
    \        T itr;\r\n\r\n            constexpr int compare(const const_iterator&\
    \ rhs) const noexcept {\r\n                if (itr < rhs.itr) return -1;\r\n \
    \               else if (itr > rhs.itr) return 1;\r\n                else return\
    \ 0;\r\n            }\r\n\r\n        public:\r\n            const_iterator() noexcept\
    \ = default;\r\n            template<class Itr>\r\n            const_iterator(Itr&&\
    \ itr) noexcept: itr(std::forward<Itr>(itr)) {}\r\n\r\n            constexpr const\
    \ T& operator *() const noexcept {\r\n                return itr;\r\n        \
    \    }\r\n\r\n            constexpr const_iterator& operator ++() noexcept {\r\
    \n                ++itr;\r\n                return *this;\r\n            }\r\n\
    \r\n            constexpr const_iterator& operator --() noexcept {\r\n       \
    \         --itr;\r\n                return *this;\r\n            }\r\n\r\n   \
    \         constexpr const_iterator operator +(std::ptrdiff_t rhs) const noexcept\
    \ {\r\n                return iterator{itr + rhs};\r\n            }\r\n\r\n  \
    \          constexpr std::ptrdiff_t operator -(const const_iterator& rhs) const\
    \ noexcept {\r\n                return itr - rhs.itr;\r\n            }\r\n   \
    \     };\r\n\r\n\r\n        using reverse_iterator = std::reverse_iterator<iterator>;\r\
    \n        using const_reverse_iterator = std::reverse_iterator<const_iterator>;\r\
    \n\r\n\r\n        constexpr iterator begin() const noexcept {\r\n            return\
    \ iterator{first};\r\n        }\r\n\r\n        constexpr iterator end() const\
    \ noexcept {\r\n            return iterator{last};\r\n        }\r\n\r\n      \
    \  constexpr const_iterator cbegin() const noexcept {\r\n            return const_iterator{first};\r\
    \n        }\r\n\r\n        constexpr const_iterator cend() const noexcept {\r\n\
    \            return const_iterator{last};\r\n        }\r\n    };\r\n\r\n    template<class\
    \ F, class L>\r\n    irange(F&&, L&&) -> irange<std::decay_t<F>>;\r\n} // namespace\
    \ kpr\r\n"
  dependsOn:
  - kpr/range/iterator_base.hpp
  - kpr/range/range_base.hpp
  - kpr/meta/trait.hpp
  isVerificationFile: false
  path: kpr/range/irange.hpp
  requiredBy:
  - kpr/range/range.hpp
  timestamp: '2023-04-04 01:42:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kpr/range/irange.hpp
layout: document
redirect_from:
- /library/kpr/range/irange.hpp
- /library/kpr/range/irange.hpp.html
title: kpr/range/irange.hpp
---
