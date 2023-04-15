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
  code: "#pragma once\r\n#include <cstdint>\r\n#include \"../meta/setting.hpp\"\r\n\
    \r\nnamespace kpr {\r\n    // \u30AA\u30A4\u30E9\u30FC\u306E\u03C6\u95A2\u6570\
    \r\n    [[maybe_unused]] inline constexpr struct {\r\n        constexpr KYOPRO_BASE_INT\
    \ operator ()(std::uint_fast64_t n) const noexcept {\r\n            std::uint_fast64_t\
    \ res = n;\r\n            if ((n & 1) == 0) {\r\n                res -= res >>\
    \ 1;\r\n                n >>= 1;\r\n                while ((n & 1) == 0) n >>=\
    \ 1;\r\n            }\r\n            for (std::uint_fast64_t i = 3; i * i <= n;\
    \ i += 2) {\r\n                if (n % i == 0) {\r\n                res -= res\
    \ / i;\r\n                n /= i;\r\n                while (n % i == 0) n /= i;\r\
    \n                }\r\n            }\r\n            if (n != 1) res -= res / n;\r\
    \n            return res;\r\n        }\r\n    } euler_phi;\r\n} // namespace kpr\r\
    \n"
  dependsOn: []
  isVerificationFile: false
  path: kpr/math/euler_phi.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kpr/math/euler_phi.hpp
layout: document
redirect_from:
- /library/kpr/math/euler_phi.hpp
- /library/kpr/math/euler_phi.hpp.html
title: kpr/math/euler_phi.hpp
---
