---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ yosupo/FenwickTree.test.hpp: line 2: #pragma once found in a non-first line\n"
  code: "/* FenwickTree */\n#pragma once\n#include <cstdint>\n#include <vector>\n\
    #include \"../base_int.hpp\"\n\nnamespace kyopro {\n  template<class T, class\
    \ Container = std::vector<T>>\n  struct FenwickTree {\n  private:\n    Container\
    \ kyopro_tree;\n  public:\n    using value_type = T;\n    using size_type = std::size_t;\n\
    \    using reference = T&;\n    using const_reference = const T&;\n    FenwickTree()\
    \ noexcept = default;\n    FenwickTree(std::size_t kyopro_n) noexcept: kyopro_tree(kyopro_n)\
    \ {}\n    std::size_t size() noexcept { return kyopro_tree.size(); }\n    void\
    \ add(int kyopro_p, const T& kyopro_x) {\n      ++kyopro_p;\n      while (kyopro_p\
    \ <= (int)size()) {\n        kyopro_tree[kyopro_p - 1] += kyopro_x;\n        kyopro_p\
    \ += kyopro_p & -kyopro_p;\n      }\n    }\n    T query(int kyopro_r) {\n    \
    \  T kyopro_s = 0;\n      while (kyopro_r > 0) {\n        kyopro_s += kyopro_tree[kyopro_r\
    \ - 1];\n        kyopro_r -= kyopro_r & -kyopro_r;\n      }\n      return kyopro_s;\n\
    \    }\n    T query(int kyopro_l, int kyopro_r) { return query(kyopro_r) - query(kyopro_l);\
    \ }\n    T get(int kyopro_idx) { return query(kyopro_idx + 1) - query(kyopro_idx);\
    \ }\n    T all_query() { return query(kyopro_tree.size()); }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: yosupo/FenwickTree.test.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: yosupo/FenwickTree.test.hpp
layout: document
redirect_from:
- /verify/yosupo/FenwickTree.test.hpp
- /verify/yosupo/FenwickTree.test.hpp.html
title: yosupo/FenwickTree.test.hpp
---
