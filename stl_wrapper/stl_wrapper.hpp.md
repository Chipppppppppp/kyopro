---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: stl_wrapper/vec.hpp
    title: stl_wrapper/vec.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  - icon: ':warning:'
    path: all/all.hpp
    title: all/all.hpp
  - icon: ':warning:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':warning:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':warning:'
    path: verify/hello_world.cpp
    title: verify/hello_world.cpp
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
    \ noexcept: super{helper::make_vec(d, init)} {}\n    };\n} // namespace kpr\n\
    #line 3 \"stl_wrapper/stl_wrapper.hpp\"\n"
  code: '#pragma once

    #include "vec.hpp"

    '
  dependsOn:
  - stl_wrapper/vec.hpp
  isVerificationFile: false
  path: stl_wrapper/stl_wrapper.hpp
  requiredBy:
  - verify/hello_world.cpp
  - template/template.hpp
  - template/alias.hpp
  - all/all.hpp
  - all.hpp
  timestamp: '2023-02-19 20:56:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: stl_wrapper/stl_wrapper.hpp
layout: document
redirect_from:
- /library/stl_wrapper/stl_wrapper.hpp
- /library/stl_wrapper/stl_wrapper.hpp.html
title: stl_wrapper/stl_wrapper.hpp
---
