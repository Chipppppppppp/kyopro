---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: kpr/all.hpp
    title: kpr/all.hpp
  - icon: ':warning:'
    path: kpr/template/template.hpp
    title: kpr/template/template.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"kpr/template/range_cast.hpp\"\n#include <iterator>\n\nnamespace\
    \ kpr {\n    // Range\u306E\u578B\u5909\u63DB\n    template<class To>\n    struct\
    \ RangeCast {\n        template<class From>\n        constexpr To operator ()(From&&\
    \ container) const noexcept {\n            return To(std::begin(container), std::end(container));\n\
    \        }\n    };\n\n    template<class To>\n    inline constexpr RangeCast<To>\
    \ range_cast;\n} // namespace kpr\n"
  code: "#pragma once\n#include <iterator>\n\nnamespace kpr {\n    // Range\u306E\u578B\
    \u5909\u63DB\n    template<class To>\n    struct RangeCast {\n        template<class\
    \ From>\n        constexpr To operator ()(From&& container) const noexcept {\n\
    \            return To(std::begin(container), std::end(container));\n        }\n\
    \    };\n\n    template<class To>\n    inline constexpr RangeCast<To> range_cast;\n\
    } // namespace kpr\n"
  dependsOn: []
  isVerificationFile: false
  path: kpr/template/range_cast.hpp
  requiredBy:
  - kpr/all.hpp
  - kpr/template/template.hpp
  timestamp: '2023-07-07 08:38:53+01:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kpr/template/range_cast.hpp
layout: document
redirect_from:
- /library/kpr/template/range_cast.hpp
- /library/kpr/template/range_cast.hpp.html
title: kpr/template/range_cast.hpp
---
