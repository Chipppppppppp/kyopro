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
  code: "#pragma once\r\n#include <cstddef>\r\n#include <utility>\r\n#include <vector>\r\
    \n#include \"../function/monoid.hpp\"\r\n\r\nnamespace kpr {\r\n    // Binary\
    \ Indexed Tree\r\n    template<class T, class Op = Add<T>>\r\n    struct FenwickTree\
    \ {\r\n        using value_type = T;\r\n        using size_type = std::size_t;\r\
    \n        using reference = T&;\r\n        using const_reference = const T&;\r\
    \n        using operator_type = Op;\r\n\r\n    private:\r\n        Op op;\r\n\
    \        std::vector<T> tree;\r\n\r\n    public:\r\n        FenwickTree() noexcept\
    \ = default;\r\n        explicit FenwickTree(std::size_t n) noexcept: tree(n,\
    \ op.id()) {}\r\n\r\n        std::size_t size() const noexcept {\r\n         \
    \   return tree.size();\r\n        }\r\n\r\n        void apply(int p, const T&\
    \ x) {\r\n            ++p;\r\n            while (p <= (int)tree.size()) {\r\n\
    \                tree[p - 1] = op(tree[p - 1], x);\r\n                p += p &\
    \ -p;\r\n            }\r\n        }\r\n\r\n        void set(int p, const T& x)\
    \ {\r\n            static_assert(has_inv_v<Op>, \"Operator doesn't have an inverse\"\
    );\r\n            apply(p, op(x, op.inv(get(p))));\r\n        }\r\n\r\n      \
    \  T get(int p) const {\r\n            static_assert(has_inv_v<Op>, \"Operator\
    \ doesn't have an inverse\");\r\n            return op(prod(p + 1), op.inv(prod(p)));\r\
    \n        }\r\n\r\n        T prod(int r) const {\r\n            T s = op.id();\r\
    \n            while (r > 0) {\r\n                s = op(s, tree[r - 1]);\r\n \
    \               r -= r & -r;\r\n            }\r\n            return s;\r\n   \
    \     }\r\n        T prod(int l, int r) const {\r\n            static_assert(has_inv_v<Op>,\
    \ \"Operator doesn't have an inverse\");\r\n            return op(prod(r), op.inv(prod(l)));\r\
    \n        }\r\n\r\n        T all_prod() const {\r\n            return prod(tree.size());\r\
    \n        }\r\n    };\r\n} // namespace kpr\r\n"
  dependsOn: []
  isVerificationFile: false
  path: kpr/data_structure/FenwickTree.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kpr/data_structure/FenwickTree.hpp
layout: document
redirect_from:
- /library/kpr/data_structure/FenwickTree.hpp
- /library/kpr/data_structure/FenwickTree.hpp.html
title: kpr/data_structure/FenwickTree.hpp
---
