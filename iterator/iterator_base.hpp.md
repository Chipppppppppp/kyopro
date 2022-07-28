---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: iterator/imap.hpp
    title: iterator/imap.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"iterator/iterator_base.hpp\"\n#include <iterator>\n#include\
    \ <cstddef>\n\nnamespace kyopro {\n    template<class, class, class, class>\n\
    \    struct IteratorBase;\n\n    template<class Derived, class ValueType, class\
    \ Dereference>\n    struct IteratorBase<Derived, ValueType, Dereference, std::forward_iterator_tag>\
    \ {\n        using value_type = ValueType;\n        using pointer = ValueType*;\n\
    \        using reference = ValueType&;\n        using difference_type = std::ptrdiff_t;\n\
    \        using iterator_category = std::forward_iterator_tag;\n\n        virtual\
    \ constexpr reference operator *() const noexcept;\n        virtual constexpr\
    \ Derived& operator ++() noexcept;\n        virtual constexpr bool operator ==(const\
    \ Derived&) const noexcept;\n\n        constexpr Derived operator ++(int) noexcept\
    \ {\n            Derived before = *this;\n            ++*this;\n            return\
    \ before;\n        }\n        constexpr Dereference operator !=(const Derived&\
    \ rhs) const noexcept {\n            return !(*this == rhs);\n        }\n    };\n\
    \n    template<class Derived, class ValueType, class Dereference>\n    struct\
    \ IteratorBase<Derived, ValueType, Dereference, std::bidirectional_iterator_tag>:\
    \ IteratorBase<Derived, ValueType, Dereference, std::forward_iterator_tag> {\n\
    \        using iterator_category = std::bidirectional_iterator_tag;\n\n      \
    \  virtual constexpr Derived& operator --() noexcept;\n\n        constexpr Derived\
    \ operator --(int) noexcept {\n            Derived before = *this;\n         \
    \   --*this;\n            return before;\n        }\n    };\n\n    template<class\
    \ Derived, class ValueType, class Dereference>\n    struct IteratorBase<Derived,\
    \ ValueType, Dereference, std::random_access_iterator_tag>: IteratorBase<Derived,\
    \ ValueType, Dereference, std::bidirectional_iterator_tag> {\n        using iterator_category\
    \ = std::random_access_iterator_tag;\n\n        virtual constexpr Derived operator\
    \ +(std::ptrdiff_t rhs) const noexcept;\n        virtual constexpr std::ptrdiff_t\
    \ operator -(const Derived&) const noexcept;\n\n    private:\n        virtual\
    \ constexpr int compare(const Derived&) const noexcept;\n\n    public:\n\n   \
    \     constexpr Derived& operator +=(std::ptrdiff_t rhs) noexcept {\n        \
    \    return *this = *this + rhs;\n        }\n        constexpr Derived operator\
    \ -(std::ptrdiff_t rhs) const noexcept {\n            return *this + -rhs;\n \
    \       }\n        constexpr Derived& operator -=(std::ptrdiff_t rhs) noexcept\
    \ {\n            return *this = *this - rhs;\n        }\n        virtual constexpr\
    \ bool operator ==(const Derived& rhs) const noexcept {\n            return compare(rhs)\
    \ == 0;\n        }\n        virtual constexpr bool operator !=(const Derived&\
    \ rhs) const noexcept {\n            return compare(rhs) != 0;\n        }\n  \
    \      virtual constexpr bool operator <(const Derived& rhs) const noexcept {\n\
    \            return compare(rhs) < 0;\n        }\n        virtual constexpr bool\
    \ operator <=(const Derived& rhs) const noexcept {\n            return compare(rhs)\
    \ <= 0;\n        }\n        virtual constexpr bool operator >(const Derived& rhs)\
    \ const noexcept {\n            return compare(rhs) > 0;\n        }\n        virtual\
    \ constexpr bool operator >=(const Derived& rhs) const noexcept {\n          \
    \  return compare(rhs) >= 0;\n        }\n        virtual constexpr bool operator\
    \ [](std::size_t idx) const noexcept {\n            return *(*this + idx);\n \
    \       }\n    };\n} // namespace kyopro\n"
  code: "#pragma once\n#include <iterator>\n#include <cstddef>\n\nnamespace kyopro\
    \ {\n    template<class, class, class, class>\n    struct IteratorBase;\n\n  \
    \  template<class Derived, class ValueType, class Dereference>\n    struct IteratorBase<Derived,\
    \ ValueType, Dereference, std::forward_iterator_tag> {\n        using value_type\
    \ = ValueType;\n        using pointer = ValueType*;\n        using reference =\
    \ ValueType&;\n        using difference_type = std::ptrdiff_t;\n        using\
    \ iterator_category = std::forward_iterator_tag;\n\n        virtual constexpr\
    \ reference operator *() const noexcept;\n        virtual constexpr Derived& operator\
    \ ++() noexcept;\n        virtual constexpr bool operator ==(const Derived&) const\
    \ noexcept;\n\n        constexpr Derived operator ++(int) noexcept {\n       \
    \     Derived before = *this;\n            ++*this;\n            return before;\n\
    \        }\n        constexpr Dereference operator !=(const Derived& rhs) const\
    \ noexcept {\n            return !(*this == rhs);\n        }\n    };\n\n    template<class\
    \ Derived, class ValueType, class Dereference>\n    struct IteratorBase<Derived,\
    \ ValueType, Dereference, std::bidirectional_iterator_tag>: IteratorBase<Derived,\
    \ ValueType, Dereference, std::forward_iterator_tag> {\n        using iterator_category\
    \ = std::bidirectional_iterator_tag;\n\n        virtual constexpr Derived& operator\
    \ --() noexcept;\n\n        constexpr Derived operator --(int) noexcept {\n  \
    \          Derived before = *this;\n            --*this;\n            return before;\n\
    \        }\n    };\n\n    template<class Derived, class ValueType, class Dereference>\n\
    \    struct IteratorBase<Derived, ValueType, Dereference, std::random_access_iterator_tag>:\
    \ IteratorBase<Derived, ValueType, Dereference, std::bidirectional_iterator_tag>\
    \ {\n        using iterator_category = std::random_access_iterator_tag;\n\n  \
    \      virtual constexpr Derived operator +(std::ptrdiff_t rhs) const noexcept;\n\
    \        virtual constexpr std::ptrdiff_t operator -(const Derived&) const noexcept;\n\
    \n    private:\n        virtual constexpr int compare(const Derived&) const noexcept;\n\
    \n    public:\n\n        constexpr Derived& operator +=(std::ptrdiff_t rhs) noexcept\
    \ {\n            return *this = *this + rhs;\n        }\n        constexpr Derived\
    \ operator -(std::ptrdiff_t rhs) const noexcept {\n            return *this +\
    \ -rhs;\n        }\n        constexpr Derived& operator -=(std::ptrdiff_t rhs)\
    \ noexcept {\n            return *this = *this - rhs;\n        }\n        virtual\
    \ constexpr bool operator ==(const Derived& rhs) const noexcept {\n          \
    \  return compare(rhs) == 0;\n        }\n        virtual constexpr bool operator\
    \ !=(const Derived& rhs) const noexcept {\n            return compare(rhs) !=\
    \ 0;\n        }\n        virtual constexpr bool operator <(const Derived& rhs)\
    \ const noexcept {\n            return compare(rhs) < 0;\n        }\n        virtual\
    \ constexpr bool operator <=(const Derived& rhs) const noexcept {\n          \
    \  return compare(rhs) <= 0;\n        }\n        virtual constexpr bool operator\
    \ >(const Derived& rhs) const noexcept {\n            return compare(rhs) > 0;\n\
    \        }\n        virtual constexpr bool operator >=(const Derived& rhs) const\
    \ noexcept {\n            return compare(rhs) >= 0;\n        }\n        virtual\
    \ constexpr bool operator [](std::size_t idx) const noexcept {\n            return\
    \ *(*this + idx);\n        }\n    };\n} // namespace kyopro"
  dependsOn: []
  isVerificationFile: false
  path: iterator/iterator_base.hpp
  requiredBy:
  - iterator/imap.hpp
  timestamp: '2022-07-28 17:38:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: iterator/iterator_base.hpp
layout: document
redirect_from:
- /library/iterator/iterator_base.hpp
- /library/iterator/iterator_base.hpp.html
title: iterator/iterator_base.hpp
---
