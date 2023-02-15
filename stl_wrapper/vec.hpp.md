---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"stl_wrapper/vec.hpp\"\n#include <cstdint>\n#include <vector>\n\
    \nnamespace kpr {\n    namespace helper {\n        template<std::size_t i = 0,\
    \ std::size_t n, class T>\n        auto make_vec(const std::size_t (&d)[n], const\
    \ T& init) noexcept {\n            if constexpr (i < n) return std::vector(d[i],\
    \ make_vec<i + 1>(d, init));\n            else return init;\n        }\n    }\n\
    \    template<class T, std::size_t n>\n    struct Vec: decltype(helper::make_vec(std::declval<const\
    \ std::size_t (&)[n]>(), std::declval<const T&>())) {\n        using super = decltype(helper::make_vec(std::declval<const\
    \ std::size_t (&)[n]>(), std::declval<const T&>()));\n        using super::vector,\
    \ super::operator =;\n\n        Vec(const std::size_t (&d)[n], const T& init)\
    \ noexcept: super{helper::make_vec(d, init)} {}\n    };\n} // namespace kpr\n"
  code: "#pragma once\n#include <cstdint>\n#include <vector>\n\nnamespace kpr {\n\
    \    namespace helper {\n        template<std::size_t i = 0, std::size_t n, class\
    \ T>\n        auto make_vec(const std::size_t (&d)[n], const T& init) noexcept\
    \ {\n            if constexpr (i < n) return std::vector(d[i], make_vec<i + 1>(d,\
    \ init));\n            else return init;\n        }\n    }\n    template<class\
    \ T, std::size_t n>\n    struct Vec: decltype(helper::make_vec(std::declval<const\
    \ std::size_t (&)[n]>(), std::declval<const T&>())) {\n        using super = decltype(helper::make_vec(std::declval<const\
    \ std::size_t (&)[n]>(), std::declval<const T&>()));\n        using super::vector,\
    \ super::operator =;\n\n        Vec(const std::size_t (&d)[n], const T& init)\
    \ noexcept: super{helper::make_vec(d, init)} {}\n    };\n} // namespace kpr\n"
  dependsOn: []
  isVerificationFile: false
  path: stl_wrapper/vec.hpp
  requiredBy: []
  timestamp: '2023-02-16 00:00:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: stl_wrapper/vec.hpp
layout: document
redirect_from:
- /library/stl_wrapper/vec.hpp
- /library/stl_wrapper/vec.hpp.html
title: stl_wrapper/vec.hpp
---
