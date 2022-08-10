---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: meta/trait.hpp
    title: meta/trait.hpp
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
    path: range/all.hpp
    title: range/all.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"range/imap.hpp\"\n#include <cstddef>\n#include <functional>\n\
    #include <iterator>\n#include <type_traits>\n#include <utility>\n#line 5 \"range/range_base.hpp\"\
    \n\nnamespace kyopro {\n    template<class Derived, class ValueType>\n    struct\
    \ RangeBase {\n        using value_type = ValueType;\n        using size_type\
    \ = std::size_t;\n        using difference_type = std::ptrdiff_t;\n        using\
    \ reference = value_type&;\n        using const_reference = const value_type&;\n\
    \        using pointer = value_type*;\n        using const_pointer = const value_type*;\n\
    \n        Derived& down_cast() noexcept {\n            return static_cast<Derived&>(*this);\n\
    \        }\n\n        constexpr auto begin() const noexcept {\n            return\
    \ down_cast().begin();\n        }\n\n        constexpr auto end() const noexcept\
    \ {\n            return down_cast().end();\n        }\n\n        constexpr auto\
    \ cbegin() const noexcept {\n            return down_cast().cbegin();\n      \
    \  }\n\n        constexpr auto cend() const noexcept {\n            return down_cast().cend();\n\
    \        }\n\n        constexpr bool empty() const noexcept {\n            return\
    \ begin() == end();\n        }\n\n        constexpr decltype(auto) front() noexcept\
    \ {\n            return *begin();\n        }\n        constexpr decltype(auto)\
    \ front() const noexcept {\n            return *cbegin();\n        }\n\n     \
    \   constexpr reverse_iterator rbegin() const noexcept {\n            return reverse_iterator(end());\n\
    \        }\n\n        constexpr reverse_iterator rend() const noexcept {\n   \
    \         return reverse_iterator(begin());\n        }\n\n        constexpr const_reverse_iterator\
    \ crbegin() const noexcept {\n            return const_reverse_iterator(cend());\n\
    \        }\n\n        constexpr const_reverse_iterator crend() const noexcept\
    \ {\n            return const_reverse_iterator(cbegin());\n        }\n\n     \
    \   constexpr decltype(auto) back() noexcept {\n            return *rbegin();\n\
    \        }\n        constexpr decltype(auto) back() const noexcept {\n       \
    \     return *crbegin();\n        }\n\n        constexpr std::size_t size() const\
    \ noexcept {\n            return end() - begin();\n        }\n\n        constexpr\
    \ decltype(auto) operator [](std::size_t idx) {\n            return *(begin()\
    \ + idx);\n        }\n        constexpr decltype(auto) operator [](std::size_t\
    \ idx) const {\n            return *(cbegin() + idx);\n        }\n    };\n} //\
    \ namespace kyopro\n#line 4 \"meta/trait.hpp\"\n#include <queue>\n#include <limits>\n\
    #include <stack>\n#line 9 \"meta/trait.hpp\"\n\n#if defined(__STRICT_ANSI__) &&\
    \ defined(__SIZEOF_INT128__)\ntemplate<>\nstruct std::is_integral<__int128_t>:\
    \ std::true_type {};\ntemplate<>\nstruct std::is_integral<__uint128_t>: std::true_type\
    \ {};\n#endif\n\n\nnamespace kyopro {\n    template<std::size_t size>\n    struct\
    \ int_least {\n    private:\n        static constexpr auto get_type() noexcept\
    \ {\n            static_assert(size <= 128, \"Integer size is too large\");\n\
    \            if constexpr (size <= 8) return std::int_least8_t{};\n          \
    \  else if constexpr (size <= 16) return std::int_least16_t{};\n            else\
    \ if constexpr (size <= 32) return std::int_least32_t{};\n            else if\
    \ constexpr (size <= 64) return std::int_least64_t{};\n            else return\
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
    } // namespace kyopro\n#line 9 \"range/imap.hpp\"\n\nnamespace kyopro {\n    template<class\
    \ Func, class Range>\n    struct imap: RangeBase<imap<Func, Range>, std::invoke_result_t<Func,\
    \ range_value_t<Range>>> {\n    private:\n        using BaseIterator = range_iterator_t<Range>;\n\
    \        using BaseConstIterator = range_const_iterator_t<Range>;\n\n        Func\
    \ func;\n        Range range;\n\n    public:\n        imap() noexcept = default;\n\
    \        template<class F, class R>\n        imap(F&& func, R&& range) noexcept:\
    \ func(std::forward<F>(func)), range(std::forward<R>(range)) {}\n\n        struct\
    \ iterator: BaseIterator {\n            using value_type = std::decay_t<std::invoke_result_t<Func,\
    \ decltype(*std::declval<BaseIterator>())>>;\n            using pointer = value_type*;\n\
    \            using reference = value_type&;\n\n        private:\n            Func\
    \ func;\n\n        public:\n            iterator() noexcept = default;\n     \
    \       template<class F, class Itr>\n            iterator(F&& func, Itr&& itr)\
    \ noexcept: func(std::forward<F>(func)), BaseIterator(std::forward<Itr>(itr))\
    \ {}\n\n            constexpr decltype(auto) operator *() const noexcept {\n \
    \               return std::invoke(func, BaseIterator::operator *());\n      \
    \      }\n        };\n\n        struct const_iterator: BaseConstIterator {\n \
    \           using value_type = const std::decay_t<std::invoke_result_t<Func, decltype(*std::declval<BaseIterator>())>>;\n\
    \            using pointer = value_type*;\n            using reference = value_type&;\n\
    \n        private:\n            Func func;\n\n        public:\n            const_iterator()\
    \ noexcept = default;\n            template<class F, class Itr>\n            const_iterator(F&&\
    \ func, Itr&& itr) noexcept: func(std::forward<F>(func)), BaseConstIterator(std::forward<Itr>(itr))\
    \ {}\n\n            constexpr const std::invoke_result_t<Func, decltype(*std::declval<BaseIterator>())>\
    \ operator *() const noexcept {\n                return std::invoke(func, BaseIterator::operator\
    \ *());\n            }\n        };\n\n        constexpr iterator begin() const\
    \ noexcept {\n            return iterator(func, std::begin(range));\n        }\n\
    \n        constexpr iterator end() const noexcept {\n            return iterator(func,\
    \ std::end(range));\n        }\n\n        constexpr const_iterator cbegin() const\
    \ noexcept {\n            return const_iterator(func, std::begin(range));\n  \
    \      }\n\n        constexpr const_iterator cend() const noexcept {\n       \
    \     return const_iterator(func, std::end(range));\n        }\n    };\n\n   \
    \ template<class F, class R>\n    imap(F&&, R&&) -> imap<std::decay_t<F>, std::decay_t<R>>;\n\
    } // namespace kyopro\n"
  code: "#pragma once\n#include <cstddef>\n#include <functional>\n#include <iterator>\n\
    #include <type_traits>\n#include <utility>\n#include \"range_base.hpp\"\n#include\
    \ \"../meta/trait.hpp\"\n\nnamespace kyopro {\n    template<class Func, class\
    \ Range>\n    struct imap: RangeBase<imap<Func, Range>, std::invoke_result_t<Func,\
    \ range_value_t<Range>>> {\n    private:\n        using BaseIterator = range_iterator_t<Range>;\n\
    \        using BaseConstIterator = range_const_iterator_t<Range>;\n\n        Func\
    \ func;\n        Range range;\n\n    public:\n        imap() noexcept = default;\n\
    \        template<class F, class R>\n        imap(F&& func, R&& range) noexcept:\
    \ func(std::forward<F>(func)), range(std::forward<R>(range)) {}\n\n        struct\
    \ iterator: BaseIterator {\n            using value_type = std::decay_t<std::invoke_result_t<Func,\
    \ decltype(*std::declval<BaseIterator>())>>;\n            using pointer = value_type*;\n\
    \            using reference = value_type&;\n\n        private:\n            Func\
    \ func;\n\n        public:\n            iterator() noexcept = default;\n     \
    \       template<class F, class Itr>\n            iterator(F&& func, Itr&& itr)\
    \ noexcept: func(std::forward<F>(func)), BaseIterator(std::forward<Itr>(itr))\
    \ {}\n\n            constexpr decltype(auto) operator *() const noexcept {\n \
    \               return std::invoke(func, BaseIterator::operator *());\n      \
    \      }\n        };\n\n        struct const_iterator: BaseConstIterator {\n \
    \           using value_type = const std::decay_t<std::invoke_result_t<Func, decltype(*std::declval<BaseIterator>())>>;\n\
    \            using pointer = value_type*;\n            using reference = value_type&;\n\
    \n        private:\n            Func func;\n\n        public:\n            const_iterator()\
    \ noexcept = default;\n            template<class F, class Itr>\n            const_iterator(F&&\
    \ func, Itr&& itr) noexcept: func(std::forward<F>(func)), BaseConstIterator(std::forward<Itr>(itr))\
    \ {}\n\n            constexpr const std::invoke_result_t<Func, decltype(*std::declval<BaseIterator>())>\
    \ operator *() const noexcept {\n                return std::invoke(func, BaseIterator::operator\
    \ *());\n            }\n        };\n\n        constexpr iterator begin() const\
    \ noexcept {\n            return iterator(func, std::begin(range));\n        }\n\
    \n        constexpr iterator end() const noexcept {\n            return iterator(func,\
    \ std::end(range));\n        }\n\n        constexpr const_iterator cbegin() const\
    \ noexcept {\n            return const_iterator(func, std::begin(range));\n  \
    \      }\n\n        constexpr const_iterator cend() const noexcept {\n       \
    \     return const_iterator(func, std::end(range));\n        }\n    };\n\n   \
    \ template<class F, class R>\n    imap(F&&, R&&) -> imap<std::decay_t<F>, std::decay_t<R>>;\n\
    } // namespace kyopro"
  dependsOn:
  - range/range_base.hpp
  - meta/trait.hpp
  isVerificationFile: false
  path: range/imap.hpp
  requiredBy:
  - all/all.hpp
  - all.hpp
  - range/all.hpp
  timestamp: '2022-08-10 15:47:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: range/imap.hpp
layout: document
redirect_from:
- /library/range/imap.hpp
- /library/range/imap.hpp.html
title: range/imap.hpp
---
