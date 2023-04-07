---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: kpr/range/irange.hpp
    title: kpr/range/irange.hpp
  - icon: ':warning:'
    path: kpr/range/range.hpp
    title: kpr/range/range.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"kpr/range/iterator_base.hpp\"\n#include <cstddef>\r\n#include\
    \ <iterator>\r\n#include <type_traits>\r\n\r\nnamespace kpr {\r\n    template<class,\
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
    \n} // namespace kpr\r\n"
  code: "#pragma once\r\n#include <cstddef>\r\n#include <iterator>\r\n#include <type_traits>\r\
    \n\r\nnamespace kpr {\r\n    template<class, class, class>\r\n    struct IteratorBase;\r\
    \n\r\n    template<class Derived, class ValueType>\r\n    struct IteratorBase<Derived,\
    \ ValueType, std::forward_iterator_tag> {\r\n        using value_type = std::decay_t<ValueType>;\r\
    \n        using pointer = value_type*;\r\n        using reference = value_type&;\r\
    \n        using difference_type = std::ptrdiff_t;\r\n        using iterator_category\
    \ = std::forward_iterator_tag;\r\n\r\n        virtual constexpr ValueType operator\
    \ *() const noexcept;\r\n        virtual constexpr Derived& operator ++() noexcept;\r\
    \n        virtual constexpr bool operator ==(const Derived&) const noexcept;\r\
    \n\r\n        constexpr Derived operator ++(int) noexcept {\r\n            Derived\
    \ before = *this;\r\n            ++*this;\r\n            return before;\r\n  \
    \      }\r\n\r\n        constexpr bool operator !=(const Derived& rhs) const noexcept\
    \ {\r\n            return !(*this == rhs);\r\n        }\r\n    };\r\n\r\n    template<class\
    \ Derived, class ValueType>\r\n    struct IteratorBase<Derived, ValueType, std::bidirectional_iterator_tag>:\
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
    \n} // namespace kpr\r\n"
  dependsOn: []
  isVerificationFile: false
  path: kpr/range/iterator_base.hpp
  requiredBy:
  - kpr/range/irange.hpp
  - kpr/range/range.hpp
  timestamp: '2023-04-04 01:42:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kpr/range/iterator_base.hpp
layout: document
redirect_from:
- /library/kpr/range/iterator_base.hpp
- /library/kpr/range/iterator_base.hpp.html
title: kpr/range/iterator_base.hpp
---
