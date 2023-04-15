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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 412, in update\n    raise BundleErrorAt(path, i + 1, \"unmatched #if /\
    \ #ifdef / #ifndef\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ kpr/meta/setting.hpp: line 41: unmatched #if / #ifdef / #ifndef\n"
  code: "#pragma once\r\n#include <cstdint>\r\n#include <vector>\r\n#include \"../meta/setting.hpp\"\
    \r\n\r\nnamespace kpr {\r\n    // \u5168\u3066\u306E\u6B63\u306E\u7D04\u6570\u3092\
    \u8FD4\u3059\r\n    [[maybe_unused]] inline constexpr struct {\r\n        std::vector<KYOPRO_BASE_INT>\
    \ operator ()(std::uint_fast64_t n) const {\r\n            std::vector<KYOPRO_BASE_INT>\
    \ lower, upper;\r\n            std::uint_fast64_t i;\r\n            for (i = 1;\
    \ i * i < n; ++i) if (n % i == 0) {\r\n                lower.emplace_back(i);\r\
    \n                upper.emplace_back(n / i);\r\n            }\r\n            if\
    \ (i * i == n) lower.emplace_back(i);\r\n            lower.insert(end(lower),\
    \ upper.rbegin(), upper.rend());\r\n            return lower;\r\n        }\r\n\
    \    } divisors;\r\n} // namespace kpr\r\n"
  dependsOn: []
  isVerificationFile: false
  path: kpr/math/divisors.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kpr/math/divisors.hpp
layout: document
redirect_from:
- /library/kpr/math/divisors.hpp
- /library/kpr/math/divisors.hpp.html
title: kpr/math/divisors.hpp
---
