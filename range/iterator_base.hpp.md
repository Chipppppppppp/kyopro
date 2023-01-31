---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  - icon: ':warning:'
    path: all/all.hpp
    title: all/all.hpp
  - icon: ':warning:'
    path: range/irange.hpp
    title: range/irange.hpp
  - icon: ':warning:'
    path: range/range.hpp
    title: range/range.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"range/iterator_base.hpp\"\n#include <cstddef>\n#include\
    \ <iterator>\n#include <type_traits>\n\nnamespace kpr {\n    template<class, class,\
    \ class>\n    struct IteratorBase;\n\n    template<class Derived, class ValueType>\n\
    \    struct IteratorBase<Derived, ValueType, std::forward_iterator_tag> {\n  \
    \      using value_type = std::decay_t<ValueType>;\n        using pointer = value_type*;\n\
    \        using reference = value_type&;\n        using difference_type = std::ptrdiff_t;\n\
    \        using iterator_category = std::forward_iterator_tag;\n\n        virtual\
    \ constexpr ValueType operator *() const noexcept;\n        virtual constexpr\
    \ Derived& operator ++() noexcept;\n        virtual constexpr bool operator ==(const\
    \ Derived&) const noexcept;\n\n        constexpr Derived operator ++(int) noexcept\
    \ {\n            Derived before = *this;\n            ++*this;\n            return\
    \ before;\n        }\n\n        constexpr bool operator !=(const Derived& rhs)\
    \ const noexcept {\n            return !(*this == rhs);\n        }\n    };\n\n\
    \    template<class Derived, class ValueType>\n    struct IteratorBase<Derived,\
    \ ValueType, std::bidirectional_iterator_tag>: IteratorBase<Derived, ValueType,\
    \ std::forward_iterator_tag> {\n        using iterator_category = std::bidirectional_iterator_tag;\n\
    \n        virtual constexpr Derived& operator --() noexcept;\n\n        constexpr\
    \ Derived operator --(int) noexcept {\n            Derived before = *this;\n \
    \           --*this;\n            return before;\n        }\n    };\n\n    template<class\
    \ Derived, class ValueType>\n    struct IteratorBase<Derived, ValueType, std::random_access_iterator_tag>:\
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
    \ kpr\n"
  code: "#pragma once\n#include <cstddef>\n#include <iterator>\n#include <type_traits>\n\
    \nnamespace kpr {\n    template<class, class, class>\n    struct IteratorBase;\n\
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
    \ kpr\n"
  dependsOn: []
  isVerificationFile: false
  path: range/iterator_base.hpp
  requiredBy:
  - all/all.hpp
  - range/range.hpp
  - range/irange.hpp
  - all.hpp
  timestamp: '2023-02-01 00:00:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: range/iterator_base.hpp
layout: document
redirect_from:
- /library/range/iterator_base.hpp
- /library/range/iterator_base.hpp.html
title: range/iterator_base.hpp
---
