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
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 412, in update\n    raise BundleErrorAt(path, i + 1, \"unmatched #if /\
    \ #ifdef / #ifndef\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ kpr/meta/setting.hpp: line 41: unmatched #if / #ifdef / #ifndef\n"
  code: "#pragma once\n#include <algorithm>\n#include <type_traits>\n#include <unordered_map>\n\
    #include <utility>\n#include <vector>\n#include \"../function/monoid.hpp\"\n#include\
    \ \"../meta/setting.hpp\"\n#include \"../meta/trait.hpp\"\n\nnamespace kpr {\n\
    \    template<class T, class Op = Add<T>>\n    struct WeightedUnionFind {\n  \
    \  private:\n        std::vector<int> par;\n        std::vector<T> diff_weight;\n\
    \        Op op;\n\n    public:\n        WeightedUnionFind() noexcept = default;\n\
    \        WeightedUnionFind(std::size_t n) noexcept: par(n, -1), diff_weight(n,\
    \ op.id()) {}\n\n        void resize(std::size_t n) {\n            par.resize(n,\
    \ -1);\n            diff_weight.resize(n, op.id());\n        }\n        void assign(std::size_t\
    \ n) {\n            par.assign(n, -1);\n            diff_weight.assign(n, op.id());\n\
    \        }\n        void clear() {\n            std::fill(par.begin(), par.end(),\
    \ -1);\n            std::fill(diff_weight.begin(), diff_weight.end(), op.id());\n\
    \        }\n\n        std::size_t size() const noexcept {\n            return\
    \ par.size();\n        }\n\n        KYOPRO_BASE_INT find(int x) {\n          \
    \  if (par[x] < 0) return x;\n            int r = find(par[x]);\n            diff_weight[x]\
    \ = op(std::move(diff_weight[x]), diff_weight[par[x]]);\n            return par[x]\
    \ = r;\n        }\n\n        T weight(int x) {\n            return find(x), diff_weight[x];\n\
    \        }\n\n        T diff(int x, int y) {\n            return op(weight(y),\
    \ op.inv(weight(x)));\n        }\n\n        bool merge(int x, int y, T w) {\n\
    \            w = op(std::move(w), op(weight(x), op.inv(weight(y))));\n       \
    \     x = find(x), y = find(y);\n            if (x == y) return false;\n     \
    \       if (par[x] > par[y]) {\n                par[y] += par[x];\n          \
    \      par[x] = y;\n                diff_weight[x] = op.inv(w);\n            }\
    \ else {\n                par[x] += par[y];\n                par[y] = x;\n   \
    \             diff_weight[y] = w;\n            }\n            return true;\n \
    \       }\n\n        bool same(int x, int y) {\n            return find(x) ==\
    \ find(y);\n        }\n\n        KYOPRO_BASE_INT group_size(int x) {\n       \
    \     return -par[find(x)];\n        }\n\n        std::vector<int> group_members(int\
    \ x) {\n            x = find(x);\n            std::vector<int> a;\n          \
    \  for (int i = 0; i < (int)(size()); ++i) if (find(i) == x) a.emplace_back(i);\n\
    \            return a;\n        }\n\n        template<class Vector = std::vector<KYOPRO_BASE_INT>>\n\
    \        Vector roots() const {\n            Vector a;\n            for (int i\
    \ = 0; i < (int)(size()); ++i) if (par[i] < 0) a.emplace_back(i);\n          \
    \  return a;\n        }\n\n        KYOPRO_BASE_INT group_count() const {\n   \
    \         KYOPRO_BASE_INT cnt = 0;\n            for (int i = 0; i < (int)(size());\
    \ ++i) if (par[i] < 0) ++cnt;\n            return cnt;\n        }\n\n        template<class\
    \ Map = std::unordered_map<KYOPRO_BASE_INT, std::vector<KYOPRO_BASE_INT>>>\n \
    \       Map all_group_members() {\n            Map group_members;\n          \
    \  for (int member = 0; member < (int)(size()); ++member) group_members[find(member)].emplace_back(member);\n\
    \            return group_members;\n        }\n    };\n} // namespace kpr\n"
  dependsOn: []
  isVerificationFile: false
  path: kpr/data_structure/WeightedUnionFind.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kpr/data_structure/WeightedUnionFind.hpp
layout: document
redirect_from:
- /library/kpr/data_structure/WeightedUnionFind.hpp
- /library/kpr/data_structure/WeightedUnionFind.hpp.html
title: kpr/data_structure/WeightedUnionFind.hpp
---
