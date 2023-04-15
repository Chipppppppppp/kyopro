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
  bundledCode: "#line 2 \"kpr/template/range_cast.hpp\"\n#include <iterator>\n\nnamespace\
    \ kpr {\n    // Range\u306E\u578B\u5909\u63DB\n    [[maybe_unused]] inline constexpr\
    \ struct {\n        template<class To, class From>\n        constexpr To operator\
    \ ()(From&& container) const noexcept {\n            return To(std::begin(container),\
    \ std::end(container));\n        }\n    } range_cast;\n} // namespace kpr\n"
  code: "#pragma once\n#include <iterator>\n\nnamespace kpr {\n    // Range\u306E\u578B\
    \u5909\u63DB\n    [[maybe_unused]] inline constexpr struct {\n        template<class\
    \ To, class From>\n        constexpr To operator ()(From&& container) const noexcept\
    \ {\n            return To(std::begin(container), std::end(container));\n    \
    \    }\n    } range_cast;\n} // namespace kpr\n"
  dependsOn: []
  isVerificationFile: false
  path: kpr/template/range_cast.hpp
  requiredBy: []
  timestamp: '2023-04-04 01:42:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kpr/template/range_cast.hpp
layout: document
redirect_from:
- /library/kpr/template/range_cast.hpp
- /library/kpr/template/range_cast.hpp.html
title: kpr/template/range_cast.hpp
---
