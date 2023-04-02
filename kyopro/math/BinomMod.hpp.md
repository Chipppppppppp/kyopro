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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: kyopro/function/monoid.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include <array>\n#include <cstdint>\n#include \"kyopro/meta/constant.hpp\"\
    \n#include \"ModInt.hpp\"\n\nnamespace kpr {\n    // mod\u4E8C\u9805\u4FC2\u6570\
    \n    template<std::size_t max = 1000000, KYOPRO_BASE_UINT m = mod>\n    struct\
    \ BinomMod {\n        static std::array<std::uint_fast64_t, max> fact, factinv,\
    \ inv;\n        constexpr BinomMod() noexcept {\n            fact[0] = fact[1]\
    \ = 1;\n            factinv[0] = factinv[1] = 1;\n            inv[1] = 1;\n  \
    \          for (int i = 2; i < (int)max; ++i) {\n                fact[i] = fact[i\
    \ - 1] * i % m;\n                inv[i] = m - inv[m % i] * (m / i) % m;\n    \
    \            factinv[i] = factinv[i - 1] * inv[i] % m;\n            }\n      \
    \  }\n\n        constexpr ModInt<m> c(KYOPRO_BASE_UINT n, KYOPRO_BASE_UINT r)\
    \ noexcept {\n            if (n < r) return 0;\n            return ModInt<m>(fact[n]\
    \ * factinv[n - r] % m * factinv[r]);\n        }\n        constexpr ModInt<m>\
    \ p(KYOPRO_BASE_UINT n) noexcept {\n            return ModInt<m>::raw(fact[n]);\n\
    \        }\n        constexpr ModInt<m> p(KYOPRO_BASE_UINT n, KYOPRO_BASE_UINT\
    \ r) noexcept {\n            if (n < r) return 0;\n            return ModInt<m>(fact[n]\
    \ * factinv[n - r]);\n        }\n        constexpr ModInt<m> h(KYOPRO_BASE_UINT\
    \ n, KYOPRO_BASE_UINT r) noexcept {\n            return c(n + r - 1, r);\n   \
    \     }\n    };\n} // namespace kpr\n"
  dependsOn: []
  isVerificationFile: false
  path: kyopro/math/BinomMod.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kyopro/math/BinomMod.hpp
layout: document
redirect_from:
- /library/kyopro/math/BinomMod.hpp
- /library/kyopro/math/BinomMod.hpp.html
title: kyopro/math/BinomMod.hpp
---
