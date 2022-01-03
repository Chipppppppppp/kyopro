---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ structure/FenwickTree.hpp: line 2: #pragma once found in a non-first line\n"
  code: "#define problem \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include <iostream>\n#include <vector>\n#include \"../structure/FenwickTree.hpp\"\
    \nusing ll = long long;\n\nint main() {\n  int n, q;\n  std::cin >> n >> q;\n\
    \  kyopro::FenwickTree<ll> ft;\n  for (int i = 0; i < n; ++i) {\n    int a;\n\
    \    std::cin >> a;\n    ft.add(i, a);\n  }\n  for (int i = 0; i < q; ++i) {\n\
    \    int t, x, y;\n    std::cin >> t >> x >> y;\n    if (t == 0) ft.add(x, y);\n\
    \    else std::cout << ft.query(x, y) << '\\n';\n  }\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: yosupo/FenwickTree.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: yosupo/FenwickTree.test.cpp
layout: document
redirect_from:
- /verify/yosupo/FenwickTree.test.cpp
- /verify/yosupo/FenwickTree.test.cpp.html
title: yosupo/FenwickTree.test.cpp
---
