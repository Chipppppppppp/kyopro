---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: meta/trait.hpp
    title: meta/trait.hpp
  - icon: ':warning:'
    path: range/iterator_base.hpp
    title: range/iterator_base.hpp
  - icon: ':warning:'
    path: range/range_base.hpp
    title: range/range_base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  - icon: ':warning:'
    path: all/all.hpp
    title: all/all.hpp
  - icon: ':warning:'
    path: range/range.hpp
    title: range/range.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"range/irange.hpp\"\n#include <cstddef>\n#include <functional>\n\
    #include <iterator>\n#include <type_traits>\n#include <utility>\n#line 5 \"range/iterator_base.hpp\"\
    \n\nnamespace kpr {\n    template<class, class, class>\n    struct IteratorBase;\n\
    \n    template<class Derived, class ValueType>\n    struct IteratorBase<Derived,\
    \ ValueType, std::forward_iterator_tag> {\n        using value_type = std::decay_t<ValueType>;\n\
    \        using pointer = value_type*;\n        using reference = value_type&;\n\
    \        using difference_type = std::ptrdiff_t;\n        using iterator_category\
    \ = std::forward_iterator_tag;\n\n        virtual constexpr ValueType operator\
    \ *() const noexcept;\n        virtual constexpr Derived& operator ++() noexcept;\n\
    \        virtual constexpr bool operator ==(const Derived&) const noexcept;\n\n\
    \        constexpr Derived operator ++(int) noexcept {\n            Derived before\
    \ = *this;\n            ++*this;\n            return before;\n        }\n\n  \
    \      constexpr bool operator !=(const Derived& rhs) const noexcept {\n     \
    \       return !(*this == rhs);\n        }\n    };\n\n    template<class Derived,\
    \ class ValueType>\n    struct IteratorBase<Derived, ValueType, std::bidirectional_iterator_tag>:\
    \ IteratorBase<Derived, ValueType, std::forward_iterator_tag> {\n        using\
    \ iterator_category = std::bidirectional_iterator_tag;\n\n        virtual constexpr\
    \ Derived& operator --() noexcept;\n\n        constexpr Derived operator --(int)\
    \ noexcept {\n            Derived before = *this;\n            --*this;\n    \
    \        return before;\n        }\n    };\n\n    template<class Derived, class\
    \ ValueType>\n    struct IteratorBase<Derived, ValueType, std::random_access_iterator_tag>:\
    \ IteratorBase<Derived, ValueType, std::bidirectional_iterator_tag> {\n      \
    \  using iterator_category = std::random_access_iterator_tag;\n\n        virtual\
    \ constexpr Derived operator +(std::ptrdiff_t rhs) const noexcept;\n        virtual\
    \ constexpr std::ptrdiff_t operator -(const Derived&) const noexcept;\n\n    private:\n\
    \        virtual constexpr int compare(const Derived&) const noexcept;\n\n   \
    \ public:\n\n        constexpr Derived& operator +=(std::ptrdiff_t rhs) noexcept\
    \ {\n            return *this = *this + rhs;\n        }\n\n        constexpr Derived\
    \ operator -(std::ptrdiff_t rhs) const noexcept {\n            return *this +\
    \ -rhs;\n        }\n\n        constexpr Derived& operator -=(std::ptrdiff_t rhs)\
    \ noexcept {\n            return *this = *this - rhs;\n        }\n\n        constexpr\
    \ decltype(auto) operator [](std::size_t idx) const noexcept {\n            return\
    \ *(*this + idx);\n        }\n\n        constexpr bool operator ==(const Derived&\
    \ rhs) const noexcept {\n            return compare(rhs) == 0;\n        }\n  \
    \      constexpr bool operator !=(const Derived& rhs) const noexcept {\n     \
    \       return compare(rhs) != 0;\n        }\n        constexpr bool operator\
    \ <(const Derived& rhs) const noexcept {\n            return compare(rhs) < 0;\n\
    \        }\n        constexpr bool operator <=(const Derived& rhs) const noexcept\
    \ {\n            return compare(rhs) <= 0;\n        }\n        constexpr bool\
    \ operator >(const Derived& rhs) const noexcept {\n            return compare(rhs)\
    \ > 0;\n        }\n        constexpr bool operator >=(const Derived& rhs) const\
    \ noexcept {\n            return compare(rhs) >= 0;\n        }\n    };\n} // namespace\
    \ kpr\n#line 5 \"range/range_base.hpp\"\n\nnamespace kpr {\n    template<class\
    \ Derived, class ValueType>\n    struct RangeBase {\n        using value_type\
    \ = std::decay_t<ValueType>;\n        using size_type = std::size_t;\n       \
    \ using difference_type = std::ptrdiff_t;\n        using reference = value_type&;\n\
    \        using const_reference = const value_type&;\n        using pointer = value_type*;\n\
    \        using const_pointer = const value_type*;\n\n        Derived& down_cast()\
    \ noexcept {\n            return static_cast<Derived&>(*this);\n        }\n  \
    \      const Derived& down_cast() const noexcept {\n            return static_cast<const\
    \ Derived&>(*this);\n        }\n\n        constexpr auto begin() const noexcept\
    \ {\n            return down_cast().begin();\n        }\n\n        constexpr auto\
    \ end() const noexcept {\n            return down_cast().end();\n        }\n\n\
    \        constexpr auto cbegin() const noexcept {\n            return down_cast().cbegin();\n\
    \        }\n\n        constexpr auto cend() const noexcept {\n            return\
    \ down_cast().cend();\n        }\n\n        constexpr bool empty() const noexcept\
    \ {\n            return begin() == end();\n        }\n\n        constexpr decltype(auto)\
    \ front() noexcept {\n            return *begin();\n        }\n        constexpr\
    \ decltype(auto) front() const noexcept {\n            return *cbegin();\n   \
    \     }\n\n        constexpr decltype(auto) rbegin() const noexcept {\n      \
    \      return std::reverse_iterator(end());\n        }\n\n        constexpr decltype(auto)\
    \ rend() const noexcept {\n            return std::reverse_iterator(begin());\n\
    \        }\n\n        constexpr decltype(auto) crbegin() const noexcept {\n  \
    \          return std::reverse_iterator(cend());\n        }\n\n        constexpr\
    \ decltype(auto) crend() const noexcept {\n            return std::reverse_iterator(cbegin());\n\
    \        }\n\n        constexpr decltype(auto) back() noexcept {\n           \
    \ return *rbegin();\n        }\n        constexpr decltype(auto) back() const\
    \ noexcept {\n            return *crbegin();\n        }\n\n        constexpr std::size_t\
    \ size() const noexcept {\n            return end() - begin();\n        }\n\n\
    \        constexpr decltype(auto) operator [](std::size_t idx) {\n           \
    \ return *(begin() + idx);\n        }\n        constexpr decltype(auto) operator\
    \ [](std::size_t idx) const {\n            return *(cbegin() + idx);\n       \
    \ }\n    };\n} // namespace kpr\n#line 4 \"meta/trait.hpp\"\n#include <tuple>\n\
    #line 7 \"meta/trait.hpp\"\n\nnamespace kpr {\n    namespace helper {\n      \
    \  template<class T>\n        struct is_integer_helper {\n            static constexpr\
    \ bool value = std::is_integral_v<T>;\n        };\n\n        #ifdef __SIZEOF_INT128__\n\
    \        template<>\n        struct is_integer_helper<__int128_t> {\n        \
    \    static constexpr bool value = true;\n        };\n\n        template<>\n \
    \       struct is_integer_helper<__uint128_t> {\n            static constexpr\
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
    } // namespace kpr\n#line 10 \"range/irange.hpp\"\n\nnamespace kpr {\n    template<class\
    \ T>\n    struct irange: RangeBase<irange<T>, T> {\n    private:\n        T first,\
    \ last;\n\n        template<class, class = void, class = void, class = void>\n\
    \        struct get_iterator_category;\n        template<class ValueType, class\
    \ Void>\n        struct get_iterator_category<ValueType, std::void_t<decltype(++std::declval<ValueType>())>,\
    \ Void, Void> {\n            using type = std::forward_iterator_tag;\n       \
    \ };\n        template<class ValueType, class Void>\n        struct get_iterator_category<ValueType,\
    \ std::void_t<decltype(++std::declval<ValueType>())>, std::void_t<decltype(--std::declval<ValueType>())>,\
    \ Void> {\n            using type = std::bidirectional_iterator_tag;\n       \
    \ };\n        template<class ValueType>\n        struct get_iterator_category<ValueType,\
    \ std::void_t<decltype(++std::declval<ValueType>())>, std::void_t<decltype(--std::declval<ValueType>())>,\
    \ std::void_t<decltype(std::declval<T>() < std::declval<ValueType>(), std::declval<ValueType>()\
    \ > std::declval<ValueType>(), std::declval<ValueType>() + std::declval<std::ptrdiff_t>(),\
    \ std::declval<ValueType>() - std::declval<ValueType>())>> {\n            using\
    \ type = std::random_access_iterator_tag;\n        };\n\n    public:\n       \
    \ irange() noexcept = default;\n        template<class F, class L>\n        irange(F&&\
    \ first, L&& last) noexcept: first(std::forward<F>(first)), last(std::forward<L>(last))\
    \ {}\n\n        struct iterator: IteratorBase<iterator, const T&, typename get_iterator_category<T&>::type>\
    \ {\n        private:\n            T itr;\n\n            constexpr int compare(const\
    \ iterator& rhs) const noexcept {\n                if (itr < rhs.itr) return -1;\n\
    \                else if (itr > rhs.itr) return 1;\n                else return\
    \ 0;\n            }\n\n        public:\n            iterator() noexcept = default;\n\
    \            template<class Itr>\n            iterator(Itr&& itr) noexcept: itr(std::forward<Itr>(itr))\
    \ {}\n\n            constexpr const T& operator *() const noexcept {\n       \
    \         return itr;\n            }\n\n            constexpr iterator& operator\
    \ ++() noexcept {\n                ++itr;\n                return *this;\n   \
    \         }\n\n            constexpr iterator& operator --() noexcept {\n    \
    \            --itr;\n                return *this;\n            }\n\n        \
    \    constexpr iterator operator +(std::ptrdiff_t rhs) const noexcept {\n    \
    \            return iterator{itr + rhs};\n            }\n\n            constexpr\
    \ std::ptrdiff_t operator -(const iterator& rhs) const noexcept {\n          \
    \      return itr - rhs.itr;\n            }\n        };\n\n        struct const_iterator:\
    \ IteratorBase<const_iterator, const T&, typename get_iterator_category<T&>::type>\
    \ {\n        private:\n            T itr;\n\n            constexpr int compare(const\
    \ const_iterator& rhs) const noexcept {\n                if (itr < rhs.itr) return\
    \ -1;\n                else if (itr > rhs.itr) return 1;\n                else\
    \ return 0;\n            }\n\n        public:\n            const_iterator() noexcept\
    \ = default;\n            template<class Itr>\n            const_iterator(Itr&&\
    \ itr) noexcept: itr(std::forward<Itr>(itr)) {}\n\n            constexpr const\
    \ T& operator *() const noexcept {\n                return itr;\n            }\n\
    \n            constexpr const_iterator& operator ++() noexcept {\n           \
    \     ++itr;\n                return *this;\n            }\n\n            constexpr\
    \ const_iterator& operator --() noexcept {\n                --itr;\n         \
    \       return *this;\n            }\n\n            constexpr const_iterator operator\
    \ +(std::ptrdiff_t rhs) const noexcept {\n                return iterator{itr\
    \ + rhs};\n            }\n\n            constexpr std::ptrdiff_t operator -(const\
    \ const_iterator& rhs) const noexcept {\n                return itr - rhs.itr;\n\
    \            }\n        };\n\n\n        using reverse_iterator = std::reverse_iterator<iterator>;\n\
    \        using const_reverse_iterator = std::reverse_iterator<const_iterator>;\n\
    \n\n        constexpr iterator begin() const noexcept {\n            return iterator{first};\n\
    \        }\n\n        constexpr iterator end() const noexcept {\n            return\
    \ iterator{last};\n        }\n\n        constexpr const_iterator cbegin() const\
    \ noexcept {\n            return const_iterator{first};\n        }\n\n       \
    \ constexpr const_iterator cend() const noexcept {\n            return const_iterator{last};\n\
    \        }\n    };\n\n    template<class F, class L>\n    irange(F&&, L&&) ->\
    \ irange<std::decay_t<F>>;\n} // namespace kpr\n"
  code: "#pragma once\n#include <cstddef>\n#include <functional>\n#include <iterator>\n\
    #include <type_traits>\n#include <utility>\n#include \"iterator_base.hpp\"\n#include\
    \ \"range_base.hpp\"\n#include \"../meta/trait.hpp\"\n\nnamespace kpr {\n    template<class\
    \ T>\n    struct irange: RangeBase<irange<T>, T> {\n    private:\n        T first,\
    \ last;\n\n        template<class, class = void, class = void, class = void>\n\
    \        struct get_iterator_category;\n        template<class ValueType, class\
    \ Void>\n        struct get_iterator_category<ValueType, std::void_t<decltype(++std::declval<ValueType>())>,\
    \ Void, Void> {\n            using type = std::forward_iterator_tag;\n       \
    \ };\n        template<class ValueType, class Void>\n        struct get_iterator_category<ValueType,\
    \ std::void_t<decltype(++std::declval<ValueType>())>, std::void_t<decltype(--std::declval<ValueType>())>,\
    \ Void> {\n            using type = std::bidirectional_iterator_tag;\n       \
    \ };\n        template<class ValueType>\n        struct get_iterator_category<ValueType,\
    \ std::void_t<decltype(++std::declval<ValueType>())>, std::void_t<decltype(--std::declval<ValueType>())>,\
    \ std::void_t<decltype(std::declval<T>() < std::declval<ValueType>(), std::declval<ValueType>()\
    \ > std::declval<ValueType>(), std::declval<ValueType>() + std::declval<std::ptrdiff_t>(),\
    \ std::declval<ValueType>() - std::declval<ValueType>())>> {\n            using\
    \ type = std::random_access_iterator_tag;\n        };\n\n    public:\n       \
    \ irange() noexcept = default;\n        template<class F, class L>\n        irange(F&&\
    \ first, L&& last) noexcept: first(std::forward<F>(first)), last(std::forward<L>(last))\
    \ {}\n\n        struct iterator: IteratorBase<iterator, const T&, typename get_iterator_category<T&>::type>\
    \ {\n        private:\n            T itr;\n\n            constexpr int compare(const\
    \ iterator& rhs) const noexcept {\n                if (itr < rhs.itr) return -1;\n\
    \                else if (itr > rhs.itr) return 1;\n                else return\
    \ 0;\n            }\n\n        public:\n            iterator() noexcept = default;\n\
    \            template<class Itr>\n            iterator(Itr&& itr) noexcept: itr(std::forward<Itr>(itr))\
    \ {}\n\n            constexpr const T& operator *() const noexcept {\n       \
    \         return itr;\n            }\n\n            constexpr iterator& operator\
    \ ++() noexcept {\n                ++itr;\n                return *this;\n   \
    \         }\n\n            constexpr iterator& operator --() noexcept {\n    \
    \            --itr;\n                return *this;\n            }\n\n        \
    \    constexpr iterator operator +(std::ptrdiff_t rhs) const noexcept {\n    \
    \            return iterator{itr + rhs};\n            }\n\n            constexpr\
    \ std::ptrdiff_t operator -(const iterator& rhs) const noexcept {\n          \
    \      return itr - rhs.itr;\n            }\n        };\n\n        struct const_iterator:\
    \ IteratorBase<const_iterator, const T&, typename get_iterator_category<T&>::type>\
    \ {\n        private:\n            T itr;\n\n            constexpr int compare(const\
    \ const_iterator& rhs) const noexcept {\n                if (itr < rhs.itr) return\
    \ -1;\n                else if (itr > rhs.itr) return 1;\n                else\
    \ return 0;\n            }\n\n        public:\n            const_iterator() noexcept\
    \ = default;\n            template<class Itr>\n            const_iterator(Itr&&\
    \ itr) noexcept: itr(std::forward<Itr>(itr)) {}\n\n            constexpr const\
    \ T& operator *() const noexcept {\n                return itr;\n            }\n\
    \n            constexpr const_iterator& operator ++() noexcept {\n           \
    \     ++itr;\n                return *this;\n            }\n\n            constexpr\
    \ const_iterator& operator --() noexcept {\n                --itr;\n         \
    \       return *this;\n            }\n\n            constexpr const_iterator operator\
    \ +(std::ptrdiff_t rhs) const noexcept {\n                return iterator{itr\
    \ + rhs};\n            }\n\n            constexpr std::ptrdiff_t operator -(const\
    \ const_iterator& rhs) const noexcept {\n                return itr - rhs.itr;\n\
    \            }\n        };\n\n\n        using reverse_iterator = std::reverse_iterator<iterator>;\n\
    \        using const_reverse_iterator = std::reverse_iterator<const_iterator>;\n\
    \n\n        constexpr iterator begin() const noexcept {\n            return iterator{first};\n\
    \        }\n\n        constexpr iterator end() const noexcept {\n            return\
    \ iterator{last};\n        }\n\n        constexpr const_iterator cbegin() const\
    \ noexcept {\n            return const_iterator{first};\n        }\n\n       \
    \ constexpr const_iterator cend() const noexcept {\n            return const_iterator{last};\n\
    \        }\n    };\n\n    template<class F, class L>\n    irange(F&&, L&&) ->\
    \ irange<std::decay_t<F>>;\n} // namespace kpr\n"
  dependsOn:
  - range/iterator_base.hpp
  - range/range_base.hpp
  - meta/trait.hpp
  isVerificationFile: false
  path: range/irange.hpp
  requiredBy:
  - all/all.hpp
  - range/range.hpp
  - all.hpp
  timestamp: '2023-02-01 00:00:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: range/irange.hpp
layout: document
redirect_from:
- /library/range/irange.hpp
- /library/range/irange.hpp.html
title: range/irange.hpp
---