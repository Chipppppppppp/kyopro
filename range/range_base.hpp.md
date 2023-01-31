---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: range/imap.hpp
    title: range/imap.hpp
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
  bundledCode: "#line 2 \"range/range_base.hpp\"\n#include <cstddef>\n#include <iterator>\n\
    #include <type_traits>\n\nnamespace kpr {\n    template<class Derived, class ValueType>\n\
    \    struct RangeBase {\n        using value_type = std::decay_t<ValueType>;\n\
    \        using size_type = std::size_t;\n        using difference_type = std::ptrdiff_t;\n\
    \        using reference = value_type&;\n        using const_reference = const\
    \ value_type&;\n        using pointer = value_type*;\n        using const_pointer\
    \ = const value_type*;\n\n        Derived& down_cast() noexcept {\n          \
    \  return static_cast<Derived&>(*this);\n        }\n        const Derived& down_cast()\
    \ const noexcept {\n            return static_cast<const Derived&>(*this);\n \
    \       }\n\n        constexpr auto begin() const noexcept {\n            return\
    \ down_cast().begin();\n        }\n\n        constexpr auto end() const noexcept\
    \ {\n            return down_cast().end();\n        }\n\n        constexpr auto\
    \ cbegin() const noexcept {\n            return down_cast().cbegin();\n      \
    \  }\n\n        constexpr auto cend() const noexcept {\n            return down_cast().cend();\n\
    \        }\n\n        constexpr bool empty() const noexcept {\n            return\
    \ begin() == end();\n        }\n\n        constexpr decltype(auto) front() noexcept\
    \ {\n            return *begin();\n        }\n        constexpr decltype(auto)\
    \ front() const noexcept {\n            return *cbegin();\n        }\n\n     \
    \   constexpr decltype(auto) rbegin() const noexcept {\n            return std::reverse_iterator(end());\n\
    \        }\n\n        constexpr decltype(auto) rend() const noexcept {\n     \
    \       return std::reverse_iterator(begin());\n        }\n\n        constexpr\
    \ decltype(auto) crbegin() const noexcept {\n            return std::reverse_iterator(cend());\n\
    \        }\n\n        constexpr decltype(auto) crend() const noexcept {\n    \
    \        return std::reverse_iterator(cbegin());\n        }\n\n        constexpr\
    \ decltype(auto) back() noexcept {\n            return *rbegin();\n        }\n\
    \        constexpr decltype(auto) back() const noexcept {\n            return\
    \ *crbegin();\n        }\n\n        constexpr std::size_t size() const noexcept\
    \ {\n            return end() - begin();\n        }\n\n        constexpr decltype(auto)\
    \ operator [](std::size_t idx) {\n            return *(begin() + idx);\n     \
    \   }\n        constexpr decltype(auto) operator [](std::size_t idx) const {\n\
    \            return *(cbegin() + idx);\n        }\n    };\n} // namespace kpr\n"
  code: "#pragma once\n#include <cstddef>\n#include <iterator>\n#include <type_traits>\n\
    \nnamespace kpr {\n    template<class Derived, class ValueType>\n    struct RangeBase\
    \ {\n        using value_type = std::decay_t<ValueType>;\n        using size_type\
    \ = std::size_t;\n        using difference_type = std::ptrdiff_t;\n        using\
    \ reference = value_type&;\n        using const_reference = const value_type&;\n\
    \        using pointer = value_type*;\n        using const_pointer = const value_type*;\n\
    \n        Derived& down_cast() noexcept {\n            return static_cast<Derived&>(*this);\n\
    \        }\n        const Derived& down_cast() const noexcept {\n            return\
    \ static_cast<const Derived&>(*this);\n        }\n\n        constexpr auto begin()\
    \ const noexcept {\n            return down_cast().begin();\n        }\n\n   \
    \     constexpr auto end() const noexcept {\n            return down_cast().end();\n\
    \        }\n\n        constexpr auto cbegin() const noexcept {\n            return\
    \ down_cast().cbegin();\n        }\n\n        constexpr auto cend() const noexcept\
    \ {\n            return down_cast().cend();\n        }\n\n        constexpr bool\
    \ empty() const noexcept {\n            return begin() == end();\n        }\n\n\
    \        constexpr decltype(auto) front() noexcept {\n            return *begin();\n\
    \        }\n        constexpr decltype(auto) front() const noexcept {\n      \
    \      return *cbegin();\n        }\n\n        constexpr decltype(auto) rbegin()\
    \ const noexcept {\n            return std::reverse_iterator(end());\n       \
    \ }\n\n        constexpr decltype(auto) rend() const noexcept {\n            return\
    \ std::reverse_iterator(begin());\n        }\n\n        constexpr decltype(auto)\
    \ crbegin() const noexcept {\n            return std::reverse_iterator(cend());\n\
    \        }\n\n        constexpr decltype(auto) crend() const noexcept {\n    \
    \        return std::reverse_iterator(cbegin());\n        }\n\n        constexpr\
    \ decltype(auto) back() noexcept {\n            return *rbegin();\n        }\n\
    \        constexpr decltype(auto) back() const noexcept {\n            return\
    \ *crbegin();\n        }\n\n        constexpr std::size_t size() const noexcept\
    \ {\n            return end() - begin();\n        }\n\n        constexpr decltype(auto)\
    \ operator [](std::size_t idx) {\n            return *(begin() + idx);\n     \
    \   }\n        constexpr decltype(auto) operator [](std::size_t idx) const {\n\
    \            return *(cbegin() + idx);\n        }\n    };\n} // namespace kpr\n"
  dependsOn: []
  isVerificationFile: false
  path: range/range_base.hpp
  requiredBy:
  - range/range.hpp
  - range/irange.hpp
  - range/imap.hpp
  timestamp: '2023-02-01 00:00:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: range/range_base.hpp
layout: document
redirect_from:
- /library/range/range_base.hpp
- /library/range/range_base.hpp.html
title: range/range_base.hpp
---
