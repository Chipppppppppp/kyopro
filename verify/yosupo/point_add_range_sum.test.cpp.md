---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../structure/FenwickTree.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\r\
    \n#include \"../../structure/FenwickTree.hpp\"\r\n#include \"../../system/system.hpp\"\
    \r\n\r\nint main() {\r\n  int n, q;\r\n  kpr::scan(n, q);\r\n  kpr::FenwickTree<long\
    \ long> ft(n);\r\n  for (int i = 0; i < n; ++i) {\r\n    int a;\r\n    kpr::scan(a);\r\
    \n    ft.apply(i, a);\r\n  }\r\n  for (int i = 0; i < q; ++i) {\r\n    int t,\
    \ x, y;\r\n    kpr::scan(t, x, y);\r\n    if (t == 0) ft.apply(x, y);\r\n    else\
    \ kpr::println(ft.prod(x, y));\r\n  }\r\n}\r\n"
  dependsOn: []
  isVerificationFile: true
  path: verify/yosupo/point_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo/point_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/point_add_range_sum.test.cpp
- /verify/verify/yosupo/point_add_range_sum.test.cpp.html
title: verify/yosupo/point_add_range_sum.test.cpp
---
