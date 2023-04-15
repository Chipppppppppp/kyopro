---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 412, in update\n    raise BundleErrorAt(path, i + 1, \"unmatched #if /\
    \ #ifdef / #ifndef\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ kpr/meta/setting.hpp: line 41: unmatched #if / #ifdef / #ifndef\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#include <utility>\n#include \"../../kpr/data_structure/SegmentTree.hpp\"\n\
    #include \"../../kpr/io/io.hpp\"\n#include \"../../kpr/math/ModInt.hpp\"\n\nusing\
    \ S = std::pair<kpr::ModInt<998244353>, kpr::ModInt<998244353>>;\nstruct Op {\n\
    \    S operator ()(const S& a, const S& b) const noexcept {\n        return {a.first\
    \ * b.first, a.second * b.first + b.second};\n    }\n\n    static S id() noexcept\
    \ {\n        return {1, 0};\n    }\n};\n\nint main() {\n    int n, q;\n    kpr::scan(n,\
    \ q);\n    std::vector<S> ab(n);\n    kpr::scan(ab);\n    kpr::SegmentTree<S,\
    \ Op> seg(ab);\n    for (int i = 0; i < q; ++i) {\n        int t;\n        kpr::scan(t);\n\
    \        if (t == 0) {\n            int p, c, d;\n            kpr::scan(p, c,\
    \ d);\n            seg.set(p, {c, d});\n        } else {\n            int l, r,\
    \ x;\n            kpr::scan(l, r, x);\n            auto [a, b] = seg.prod(l, r);\n\
    \            kpr::println(a * x + b);\n        }\n    }\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: verify/yosupo/point_set_range_composite.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo/point_set_range_composite.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/point_set_range_composite.test.cpp
- /verify/verify/yosupo/point_set_range_composite.test.cpp.html
title: verify/yosupo/point_set_range_composite.test.cpp
---
