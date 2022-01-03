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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../base/base_int.hpp:\
    \ line -1: no such header\n"
  code: "#ifndef KYOPRO_FENWICK_TREE\n#define KYOPRO_FENWICK_TREE\n/* FenwickTree\
    \ */\n#include <cstdint>\n#include <vector>\n#include <utility>\n#include \"../base/base_int.hpp\"\
    \n\nnamespace kyopro {\n  template<class KyoproT, class KyoproContainer = std::vector<KyoproT>>\n\
    \  struct FenwickTree {\n  private:\n    KyoproContainer kyopro_tree;\n  public:\n\
    \    using value_type = KyoproT;\n    using size_type = std::size_t;\n    using\
    \ reference = KyoproT&;\n    using const_reference = const KyoproT&;\n    FenwickTree()\
    \ noexcept = default;\n    FenwickTree(std::size_t kyopro_n) noexcept: kyopro_tree(kyopro_n)\
    \ {}\n    std::size_t size() noexcept { return kyopro_tree.size(); }\n    void\
    \ add(int kyopro_p, const KyoproT& kyopro_x) {\n      ++kyopro_p;\n      while\
    \ (kyopro_p <= (int)size()) {\n        kyopro_tree[kyopro_p - 1] += kyopro_x;\n\
    \        kyopro_p += kyopro_p & -kyopro_p;\n      }\n    }\n    void set(int kyopro_p,\
    \ const KyoproT& kyopro_x) { add(kyopro_p, kyopro_x - get(kyopro_p)); }\n    KyoproT\
    \ query(int kyopro_r) {\n      KyoproT kyopro_s = 0;\n      while (kyopro_r >\
    \ 0) {\n        kyopro_s += kyopro_tree[kyopro_r - 1];\n        kyopro_r -= kyopro_r\
    \ & -kyopro_r;\n      }\n      return kyopro_s;\n    }\n    KyoproT query(int\
    \ kyopro_l, int kyopro_r) { return query(kyopro_r) - query(kyopro_l); }\n    KyoproT\
    \ get(int kyopro_p) { return query(kyopro_p + 1) - query(kyopro_p); }\n    KyoproT\
    \ all_query() { return query(kyopro_tree.size()); }\n  };\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/FenwickTree.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/FenwickTree.hpp
layout: document
redirect_from:
- /library/structure/FenwickTree.hpp
- /library/structure/FenwickTree.hpp.html
title: structure/FenwickTree.hpp
---
