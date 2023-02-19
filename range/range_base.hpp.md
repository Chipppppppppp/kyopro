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
    path: range/imap.hpp
    title: range/imap.hpp
  - icon: ':warning:'
    path: range/irange.hpp
    title: range/irange.hpp
  - icon: ':warning:'
    path: range/range.hpp
    title: range/range.hpp
  - icon: ':warning:'
    path: verify/hello_world.cpp
    title: verify/hello_world.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"range/range_base.hpp\"\n#include <cstddef>\r\n#include <iterator>\r\
    \n#include <type_traits>\r\n\r\nnamespace kpr {\r\n    template<class Derived,\
    \ class ValueType>\r\n    struct RangeBase {\r\n        using value_type = std::decay_t<ValueType>;\r\
    \n        using size_type = std::size_t;\r\n        using difference_type = std::ptrdiff_t;\r\
    \n        using reference = value_type&;\r\n        using const_reference = const\
    \ value_type&;\r\n        using pointer = value_type*;\r\n        using const_pointer\
    \ = const value_type*;\r\n\r\n        Derived& down_cast() noexcept {\r\n    \
    \        return static_cast<Derived&>(*this);\r\n        }\r\n        const Derived&\
    \ down_cast() const noexcept {\r\n            return static_cast<const Derived&>(*this);\r\
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
    \ + idx);\r\n        }\r\n    };\r\n} // namespace kpr\r\n"
  code: "#pragma once\r\n#include <cstddef>\r\n#include <iterator>\r\n#include <type_traits>\r\
    \n\r\nnamespace kpr {\r\n    template<class Derived, class ValueType>\r\n    struct\
    \ RangeBase {\r\n        using value_type = std::decay_t<ValueType>;\r\n     \
    \   using size_type = std::size_t;\r\n        using difference_type = std::ptrdiff_t;\r\
    \n        using reference = value_type&;\r\n        using const_reference = const\
    \ value_type&;\r\n        using pointer = value_type*;\r\n        using const_pointer\
    \ = const value_type*;\r\n\r\n        Derived& down_cast() noexcept {\r\n    \
    \        return static_cast<Derived&>(*this);\r\n        }\r\n        const Derived&\
    \ down_cast() const noexcept {\r\n            return static_cast<const Derived&>(*this);\r\
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
    \ + idx);\r\n        }\r\n    };\r\n} // namespace kpr\r\n"
  dependsOn: []
  isVerificationFile: false
  path: range/range_base.hpp
  requiredBy:
  - range/range.hpp
  - range/imap.hpp
  - range/irange.hpp
  - verify/hello_world.cpp
  - all/all.hpp
  - all.hpp
  timestamp: '2023-02-11 02:36:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: range/range_base.hpp
layout: document
redirect_from:
- /library/range/range_base.hpp
- /library/range/range_base.hpp.html
title: range/range_base.hpp
---
