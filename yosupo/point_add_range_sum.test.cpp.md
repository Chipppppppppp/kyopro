---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../base/io.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include \"../base/io.hpp\"\n#include \"../structure/FenwickTree.hpp\"\n\nint\
    \ main() {\n  int n, q;\n  kyopro::scan(n, q);\n  kyopro::FenwickTree<long long>\
    \ ft(n);\n  for (int i = 0; i < n; ++i) {\n    int a;\n    kyopro::scan(a);\n\
    \    ft.apply(i, a);\n  }\n  for (int i = 0; i < q; ++i) {\n    int t, x, y;\n\
    \    kyopro::scan(t, x, y);\n    if (t == 0) ft.apply(x, y);\n    else kyopro::println(ft.prod(x,\
    \ y));\n  }\n}"
  dependsOn: []
  isVerificationFile: true
  path: yosupo/point_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: yosupo/point_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/yosupo/point_add_range_sum.test.cpp
- /verify/yosupo/point_add_range_sum.test.cpp.html
title: yosupo/point_add_range_sum.test.cpp
---
