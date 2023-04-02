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
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: kyopro/function/monoid.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\r\n#include <limits>\r\n#include \"kyopro/math/power.hpp\"\r\
    \n#include \"setting.hpp\"\r\n\r\nnamespace kpr {\r\n    // \u554F\u984C\u3067\
    \u8A2D\u5B9A\u3055\u308C\u305Fmod\r\n    template<class T>\r\n    inline constexpr\
    \ T MOD = KYOPRO_DEFAULT_MOD;\r\n    // \u554F\u984C\u3067\u8A2D\u5B9A\u3055\u308C\
    \u305Fmod\r\n    inline constexpr KYOPRO_BASE_INT mod = MOD<KYOPRO_BASE_INT>;\r\
    \n\r\n    // \u7121\u9650\u5927\u3092\u8868\u3059\u6574\u6570\r\n    template<class\
    \ T>\r\n    inline constexpr T INF = std::numeric_limits<T>::max() / KYOPRO_INF_DIV;\r\
    \n    // \u7121\u9650\u5927\u3092\u8868\u3059\u6574\u6570\r\n    inline constexpr\
    \ KYOPRO_BASE_INT inf = INF<KYOPRO_BASE_INT>;\r\n\r\n    // \u8A31\u5BB9\u3055\
    \u308C\u308B\u5C0F\u6570\u8AA4\u5DEE\r\n    template<class T, KYOPRO_BASE_UINT\
    \ decimal_precision = KYOPRO_DECIMAL_PRECISION>\r\n    inline constexpr KYOPRO_BASE_FLOAT\
    \ EPS = static_cast<T>(1) / power(10ULL, decimal_precision);\r\n    // \u8A31\u5BB9\
    \u3055\u308C\u308B\u5C0F\u6570\u8AA4\u5DEE\r\n    inline constexpr KYOPRO_BASE_FLOAT\
    \ eps = EPS<KYOPRO_BASE_FLOAT>;\r\n\r\n    // \u5186\u5468\u7387\r\n    template<class\
    \ T>\r\n    inline constexpr T PI = 3.14159265358979323846;\r\n    // \u5186\u5468\
    \u7387\r\n    inline constexpr KYOPRO_BASE_FLOAT pi = PI<KYOPRO_BASE_FLOAT>;\r\
    \n} // namespace kpr\r\n"
  dependsOn: []
  isVerificationFile: false
  path: kyopro/meta/constant.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kyopro/meta/constant.hpp
layout: document
redirect_from:
- /library/kyopro/meta/constant.hpp
- /library/kyopro/meta/constant.hpp.html
title: kyopro/meta/constant.hpp
---
