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
  code: "#ifndef KYOPRO_UNION_FIND\n#define KYOPRO_UNION_FIND\n/* UnionFind */\n#include\
    \ <vector>\n#include <unordered_map>\n#include <algorithm>\n#include <initializer_list>\n\
    #include <cstdint>\n#include \"../base/base_int.hpp\"\n\nnamespace kyopro {\n\
    \  template<class KyoproContainer = std::vector<int>>\n  struct UnionFind {\n\
    \  private:\n    KyoproContainer kyopro_par;\n  public:\n    UnionFind() noexcept\
    \ = default;\n    UnionFind(std::size_t kyopro_n) noexcept: kyopro_par(kyopro_n,\
    \ -1) {}\n    void resize(std::size_t kyopro_x) { kyopro_par.resize(kyopro_x,\
    \ -1); }\n    void assign(std::size_t kyopro_x) { kyopro_par.assign(kyopro_x,\
    \ -1); }\n    void reset() { std::fill(std::begin(kyopro_par), std::end(kyopro_par),\
    \ -1); }\n    std::size_t size() const noexcept { return kyopro_par.size(); }\n\
    \    KYOPRO_BASE_INT find(int kyopro_x) {\n      int kyopro_p = kyopro_x;\n  \
    \    while (kyopro_par[kyopro_p] >= 0) kyopro_p = kyopro_par[kyopro_p];\n    \
    \  while (kyopro_x != kyopro_p) {\n        int kyopro_tmp = kyopro_x;\n      \
    \  kyopro_x = kyopro_par[kyopro_x];\n        kyopro_par[kyopro_tmp] = kyopro_p;\n\
    \      }\n      return kyopro_p;\n    }\n    bool unite(int kyopro_x, int kyopro_y)\
    \ {\n      kyopro_x = find(kyopro_x), kyopro_y = find(kyopro_y);\n      if (kyopro_x\
    \ == kyopro_y) return false;\n      if (kyopro_par[kyopro_x] > kyopro_par[kyopro_y])\
    \ {\n        int kyopro_tmp = kyopro_x;\n        kyopro_x = kyopro_y;\n      \
    \  kyopro_y = kyopro_tmp;\n      }\n      kyopro_par[kyopro_x] += kyopro_par[kyopro_y];\n\
    \      kyopro_par[kyopro_y] = kyopro_x;\n      return true;\n    }\n    bool same(int\
    \ kyopro_x, int kyopro_y) { return find(kyopro_x) == find(kyopro_y); }\n    KYOPRO_BASE_INT\
    \ group_size(int kyopro_x) { return -kyopro_par[find(kyopro_x)]; }\n    KyoproContainer\
    \ group_members(int kyopro_x) {\n      int root = find(kyopro_x);\n      KyoproContainer\
    \ kyopro_a;\n      for (int kyopro_i = 0; kyopro_i < (int)(size()); ++kyopro_i)\
    \ if (find(kyopro_i) == root) kyopro_a.emplace_back(kyopro_i);\n      return kyopro_a;\n\
    \    }\n    std::vector<KYOPRO_BASE_INT> roots() const {\n      std::vector<KYOPRO_BASE_INT>\
    \ kyopro_a;\n      for (int kyopro_i = 0; kyopro_i < (int)(size()); ++kyopro_i)\
    \ if (kyopro_par[kyopro_i] < 0) kyopro_a.emplace_back(kyopro_i);\n      return\
    \ kyopro_a;\n    }\n    KYOPRO_BASE_INT group_count() const {\n      KYOPRO_BASE_INT\
    \ cnt = 0;\n      for (int kyopro_i = 0; kyopro_i < (int)(size()); ++kyopro_i)\
    \ if (kyopro_par[kyopro_i] < 0) ++cnt;\n      return cnt;\n    }\n    template<class\
    \ Container = std::unordered_map<KYOPRO_BASE_INT, std::vector<KYOPRO_BASE_INT>>>\n\
    \    Container all_group_members() {\n      Container group_members;\n      for\
    \ (int member = 0; member < (int)(size()); ++member) group_members[find(member)].emplace_back(member);\n\
    \      return group_members;\n    }\n  };\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/UnionFind.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/UnionFind.hpp
layout: document
redirect_from:
- /library/structure/UnionFind.hpp
- /library/structure/UnionFind.hpp.html
title: structure/UnionFind.hpp
---
