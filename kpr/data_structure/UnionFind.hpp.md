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
    , line 412, in update\n    raise BundleErrorAt(path, i + 1, \"unmatched #if /\
    \ #ifdef / #ifndef\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ kpr/meta/setting.hpp: line 41: unmatched #if / #ifdef / #ifndef\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <type_traits>\r\n#include\
    \ <unordered_map>\r\n#include <utility>\r\n#include <vector>\r\n#include \"../meta/setting.hpp\"\
    \r\n#include \"../meta/trait.hpp\"\r\n\r\nnamespace kpr {\r\n    struct UnionFind\
    \ {\r\n    private:\r\n        std::vector<int> par;\r\n\r\n    public:\r\n  \
    \      UnionFind() noexcept = default;\r\n        UnionFind(std::size_t n) noexcept:\
    \ par(n, -1) {}\r\n\r\n        void resize(std::size_t n) {\r\n            par.resize(n,\
    \ -1);\r\n        }\r\n        void assign(std::size_t n) {\r\n            par.assign(n,\
    \ -1);\r\n        }\r\n        void clear() {\r\n            std::fill(par.begin(),\
    \ par.end(), -1);\r\n        }\r\n\r\n        std::size_t size() const noexcept\
    \ {\r\n            return par.size();\r\n        }\r\n\r\n        KYOPRO_BASE_INT\
    \ find(int x) {\r\n            int p = x;\r\n            while (par[p] >= 0) p\
    \ = par[p];\r\n            while (x != p) {\r\n                int tmp = x;\r\n\
    \                x = par[x];\r\n                par[tmp] = p;\r\n            }\r\
    \n            return p;\r\n        }\r\n\r\n        bool merge(int x, int y) {\r\
    \n            x = find(x), y = find(y);\r\n            if (x == y) return false;\r\
    \n            if (par[x] > par[y]) {\r\n                par[y] += par[x];\r\n\
    \                par[x] = y;\r\n            } else {\r\n                par[x]\
    \ += par[y];\r\n                par[y] = x;\r\n            }\r\n            return\
    \ true;\r\n        }\r\n\r\n        bool same(int x, int y) {\r\n            return\
    \ find(x) == find(y);\r\n        }\r\n\r\n        KYOPRO_BASE_INT group_size(int\
    \ x) {\r\n            return -par[find(x)];\r\n        }\r\n\r\n        std::vector<int>\
    \ group_members(int x) {\r\n            x = find(x);\r\n            std::vector<int>\
    \ a;\r\n            for (int i = 0; i < (int)(size()); ++i) if (find(i) == x)\
    \ a.emplace_back(i);\r\n            return a;\r\n        }\r\n\r\n        template<class\
    \ Vector = std::vector<KYOPRO_BASE_INT>>\r\n        Vector roots() const {\r\n\
    \            Vector a;\r\n            for (int i = 0; i < (int)(size()); ++i)\
    \ if (par[i] < 0) a.emplace_back(i);\r\n            return a;\r\n        }\r\n\
    \r\n        KYOPRO_BASE_INT group_count() const {\r\n            KYOPRO_BASE_INT\
    \ cnt = 0;\r\n            for (int i = 0; i < (int)(size()); ++i) if (par[i] <\
    \ 0) ++cnt;\r\n            return cnt;\r\n        }\r\n\r\n        template<class\
    \ Map = std::unordered_map<KYOPRO_BASE_INT, std::vector<KYOPRO_BASE_INT>>>\r\n\
    \        Map all_group_members() {\r\n            Map group_members;\r\n     \
    \       for (int member = 0; member < (int)(size()); ++member) group_members[find(member)].emplace_back(member);\r\
    \n            return group_members;\r\n        }\r\n    };\r\n} // namespace kpr\r\
    \n"
  dependsOn: []
  isVerificationFile: false
  path: kpr/data_structure/UnionFind.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kpr/data_structure/UnionFind.hpp
layout: document
redirect_from:
- /library/kpr/data_structure/UnionFind.hpp
- /library/kpr/data_structure/UnionFind.hpp.html
title: kpr/data_structure/UnionFind.hpp
---
