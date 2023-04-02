---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: kyopro/template/template.hpp
    title: kyopro/template/template.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"kyopro/template/range_cast.hpp\"\n#include <iterator>\n\n\
    namespace kpr {\n    // Range\u306E\u578B\u5909\u63DB\n    [[maybe_unused]] inline\
    \ constexpr struct {\n        template<class To, class From>\n        constexpr\
    \ To operator ()(From&& container) const noexcept {\n            return To(std::begin(container),\
    \ std::end(container));\n        }\n    } range_cast;\n} // namespace kpr\n"
  code: "#pragma once\n#include <iterator>\n\nnamespace kpr {\n    // Range\u306E\u578B\
    \u5909\u63DB\n    [[maybe_unused]] inline constexpr struct {\n        template<class\
    \ To, class From>\n        constexpr To operator ()(From&& container) const noexcept\
    \ {\n            return To(std::begin(container), std::end(container));\n    \
    \    }\n    } range_cast;\n} // namespace kpr\n"
  dependsOn: []
  isVerificationFile: false
  path: kyopro/template/range_cast.hpp
  requiredBy:
  - kyopro/template/template.hpp
  timestamp: '2023-04-02 21:40:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kyopro/template/range_cast.hpp
layout: document
redirect_from:
- /library/kyopro/template/range_cast.hpp
- /library/kyopro/template/range_cast.hpp.html
title: kyopro/template/range_cast.hpp
---