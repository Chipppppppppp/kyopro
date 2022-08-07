---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: range/all.hpp
    title: range/all.hpp
  - icon: ':warning:'
    path: range/imap.hpp
    title: range/imap.hpp
  - icon: ':warning:'
    path: range/range_base.hpp
    title: range/range_base.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"range/iterator_base.hpp\"\n#include <cstddef>\n#include\
    \ <iterator>\n#include <type_traits>\n\nnamespace kyopro {\n    template<class,\
    \ class, bool = false>\n    struct IteratorBase;\n\n    template<class Derived,\
    \ bool Const>\n    struct IteratorBase<Derived, std::forward_iterator_tag, Const>\
    \ {\n        using value_type = std::decay_t<decltype(*std::declval<Derived>())>;\n\
    \        using pointer = value_type*;\n        using reference = value_type&;\n\
    \        using difference_type = std::ptrdiff_t;\n        using iterator_category\
    \ = std::forward_iterator_tag;\n\n        virtual constexpr std::conditional_t<Const,\
    \ const decltype(*std::declval<Derived>()), decltype(*std::declval<Derived>())>\
    \ operator *() const noexcept;\n        virtual constexpr Derived& operator ++()\
    \ noexcept;\n        virtual constexpr bool operator ==(const Derived&) const\
    \ noexcept;\n\n        constexpr Derived operator ++(int) noexcept {\n       \
    \     Derived before = *this;\n            ++*this;\n            return before;\n\
    \        }\n\n        constexpr bool operator !=(const Derived& rhs) const noexcept\
    \ {\n            return !(*this == rhs);\n        }\n    };\n\n    template<class\
    \ Derived, bool Const>\n    struct IteratorBase<Derived, std::bidirectional_iterator_tag,\
    \ Const>: IteratorBase<Derived, std::forward_iterator_tag, Const> {\n        using\
    \ iterator_category = std::bidirectional_iterator_tag;\n\n        virtual constexpr\
    \ Derived& operator --() noexcept;\n\n        constexpr Derived operator --(int)\
    \ noexcept {\n            Derived before = *this;\n            --*this;\n    \
    \        return before;\n        }\n    };\n\n    template<class Derived, bool\
    \ Const>\n    struct IteratorBase<Derived, std::random_access_iterator_tag, Const>:\
    \ IteratorBase<Derived, std::bidirectional_iterator_tag, Const> {\n        using\
    \ iterator_category = std::random_access_iterator_tag;\n\n        virtual constexpr\
    \ Derived operator +(std::ptrdiff_t rhs) const noexcept;\n        virtual constexpr\
    \ std::ptrdiff_t operator -(const Derived&) const noexcept;\n\n    private:\n\
    \        virtual constexpr int compare(const Derived&) const noexcept;\n\n   \
    \ public:\n\n        constexpr Derived& operator +=(std::ptrdiff_t rhs) noexcept\
    \ {\n            return *this = *this + rhs;\n        }\n\n        constexpr Derived\
    \ operator -(std::ptrdiff_t rhs) const noexcept {\n            return *this +\
    \ -rhs;\n        }\n\n        constexpr Derived& operator -=(std::ptrdiff_t rhs)\
    \ noexcept {\n            return *this = *this - rhs;\n        }\n\n        virtual\
    \ constexpr std::conditional_t<Const, const decltype(*std::declval<Derived>()),\
    \ decltype(*std::declval<Derived>())> operator [](std::size_t idx) const noexcept\
    \ {\n            return *(*this + idx);\n        }\n\n        virtual constexpr\
    \ bool operator ==(const Derived& rhs) const noexcept {\n            return compare(rhs)\
    \ == 0;\n        }\n        virtual constexpr bool operator !=(const Derived&\
    \ rhs) const noexcept {\n            return compare(rhs) != 0;\n        }\n  \
    \      virtual constexpr bool operator <(const Derived& rhs) const noexcept {\n\
    \            return compare(rhs) < 0;\n        }\n        virtual constexpr bool\
    \ operator <=(const Derived& rhs) const noexcept {\n            return compare(rhs)\
    \ <= 0;\n        }\n        virtual constexpr bool operator >(const Derived& rhs)\
    \ const noexcept {\n            return compare(rhs) > 0;\n        }\n        virtual\
    \ constexpr bool operator >=(const Derived& rhs) const noexcept {\n          \
    \  return compare(rhs) >= 0;\n        }\n    };\n} // namespace kyopro\n"
  code: "#pragma once\n#include <cstddef>\n#include <iterator>\n#include <type_traits>\n\
    \nnamespace kyopro {\n    template<class, class, bool = false>\n    struct IteratorBase;\n\
    \n    template<class Derived, bool Const>\n    struct IteratorBase<Derived, std::forward_iterator_tag,\
    \ Const> {\n        using value_type = std::decay_t<decltype(*std::declval<Derived>())>;\n\
    \        using pointer = value_type*;\n        using reference = value_type&;\n\
    \        using difference_type = std::ptrdiff_t;\n        using iterator_category\
    \ = std::forward_iterator_tag;\n\n        virtual constexpr std::conditional_t<Const,\
    \ const decltype(*std::declval<Derived>()), decltype(*std::declval<Derived>())>\
    \ operator *() const noexcept;\n        virtual constexpr Derived& operator ++()\
    \ noexcept;\n        virtual constexpr bool operator ==(const Derived&) const\
    \ noexcept;\n\n        constexpr Derived operator ++(int) noexcept {\n       \
    \     Derived before = *this;\n            ++*this;\n            return before;\n\
    \        }\n\n        constexpr bool operator !=(const Derived& rhs) const noexcept\
    \ {\n            return !(*this == rhs);\n        }\n    };\n\n    template<class\
    \ Derived, bool Const>\n    struct IteratorBase<Derived, std::bidirectional_iterator_tag,\
    \ Const>: IteratorBase<Derived, std::forward_iterator_tag, Const> {\n        using\
    \ iterator_category = std::bidirectional_iterator_tag;\n\n        virtual constexpr\
    \ Derived& operator --() noexcept;\n\n        constexpr Derived operator --(int)\
    \ noexcept {\n            Derived before = *this;\n            --*this;\n    \
    \        return before;\n        }\n    };\n\n    template<class Derived, bool\
    \ Const>\n    struct IteratorBase<Derived, std::random_access_iterator_tag, Const>:\
    \ IteratorBase<Derived, std::bidirectional_iterator_tag, Const> {\n        using\
    \ iterator_category = std::random_access_iterator_tag;\n\n        virtual constexpr\
    \ Derived operator +(std::ptrdiff_t rhs) const noexcept;\n        virtual constexpr\
    \ std::ptrdiff_t operator -(const Derived&) const noexcept;\n\n    private:\n\
    \        virtual constexpr int compare(const Derived&) const noexcept;\n\n   \
    \ public:\n\n        constexpr Derived& operator +=(std::ptrdiff_t rhs) noexcept\
    \ {\n            return *this = *this + rhs;\n        }\n\n        constexpr Derived\
    \ operator -(std::ptrdiff_t rhs) const noexcept {\n            return *this +\
    \ -rhs;\n        }\n\n        constexpr Derived& operator -=(std::ptrdiff_t rhs)\
    \ noexcept {\n            return *this = *this - rhs;\n        }\n\n        virtual\
    \ constexpr std::conditional_t<Const, const decltype(*std::declval<Derived>()),\
    \ decltype(*std::declval<Derived>())> operator [](std::size_t idx) const noexcept\
    \ {\n            return *(*this + idx);\n        }\n\n        virtual constexpr\
    \ bool operator ==(const Derived& rhs) const noexcept {\n            return compare(rhs)\
    \ == 0;\n        }\n        virtual constexpr bool operator !=(const Derived&\
    \ rhs) const noexcept {\n            return compare(rhs) != 0;\n        }\n  \
    \      virtual constexpr bool operator <(const Derived& rhs) const noexcept {\n\
    \            return compare(rhs) < 0;\n        }\n        virtual constexpr bool\
    \ operator <=(const Derived& rhs) const noexcept {\n            return compare(rhs)\
    \ <= 0;\n        }\n        virtual constexpr bool operator >(const Derived& rhs)\
    \ const noexcept {\n            return compare(rhs) > 0;\n        }\n        virtual\
    \ constexpr bool operator >=(const Derived& rhs) const noexcept {\n          \
    \  return compare(rhs) >= 0;\n        }\n    };\n} // namespace kyopro"
  dependsOn: []
  isVerificationFile: false
  path: range/iterator_base.hpp
  requiredBy:
  - range/all.hpp
  - range/range_base.hpp
  - range/imap.hpp
  timestamp: '2022-08-08 07:54:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: range/iterator_base.hpp
layout: document
redirect_from:
- /library/range/iterator_base.hpp
- /library/range/iterator_base.hpp.html
title: range/iterator_base.hpp
---
