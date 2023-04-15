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
  code: "#pragma once\n#include <algorithm>\n#include <cstdint>\n#include <utility>\n\
    #include <vector>\n#include \"../algorithm/bit.hpp\"\n#include \"../function/monoid.hpp\"\
    \n#include \"../meta/setting.hpp\"\n\nnamespace kpr {\n    template<class T, class\
    \ Op = Add<T>>\n    struct SegmentTree {\n        using value_type = T;\n    \
    \    using num_type = std::size_t;\n        using reference = T&;\n        using\
    \ const_reference = const T&;\n        using operator_type = Op;\n\n    private:\n\
    \        int n, log, num;\n        std::vector<T> tree;\n        Op op;\n\n  \
    \      void update(int k) {\n            tree[k] = op(tree[2 * k], tree[2 * k\
    \ + 1]);\n        }\n\n    public:\n        SegmentTree() noexcept = default;\n\
    \        template<class... Args>\n        explicit SegmentTree(Args&&... args)\
    \ {\n            std::vector<T> v(std::forward<Args>(args)...);\n            n\
    \ = v.size();\n            log = ceil_bit(n);\n            num = 1 << log;\n \
    \           tree = std::vector<T>(num * 2, op.id());\n            std::move(v.begin(),\
    \ v.end(), tree.begin() + num);\n            for (int i = num - 1; i >= 1; --i)\
    \ update(i);\n        }\n\n        std::size_t size() const noexcept {\n     \
    \       return n;\n        }\n\n        void set(int p, const T& x) {\n      \
    \      p += num;\n            tree[p] = x;\n            for (int i = 1; i <= log;\
    \ ++i) update(p >> i);\n        }\n\n        T get(int p) const {\n          \
    \  return tree[p + num];\n        }\n\n        T prod(int r) const {\n       \
    \     T sl = op.id(), sr = op.id();\n            int l = num;\n            r +=\
    \ num;\n            while (l < r) {\n                if (l & 1) {\n          \
    \          sl = op(std::move(sl), tree[l]);\n                    ++l;\n      \
    \          }\n                if (r & 1) {\n                    --r;\n       \
    \             sr = op(tree[r], std::move(sr));\n                }\n          \
    \      l >>= 1;\n                r >>= 1;\n            }\n            return op(sl,\
    \ sr);\n        }\n        T prod(int l, int r) const {\n            T sl = op.id(),\
    \ sr = op.id();\n            l += num;\n            r += num;\n            while\
    \ (l < r) {\n                if (l & 1) {\n                    sl = op(std::move(sl),\
    \ tree[l]);\n                    ++l;\n                }\n                if (r\
    \ & 1) {\n                    --r;\n                    sr = op(tree[r], std::move(sr));\n\
    \                }\n                l >>= 1;\n                r >>= 1;\n     \
    \       }\n            return op(sl, sr);\n        }\n\n        T all_prod() const\
    \ {\n            return tree[1];\n        }\n\n        template<class F>\n   \
    \     KYOPRO_BASE_INT max_right(int l, F&& func) const {\n            if (l ==\
    \ n) return n;\n            l += num;\n            T s = op.id();\n          \
    \  do {\n                while (!(l & 1)) l >>= 1;\n                if (!func(op(s,\
    \ tree[l]))) {\n                    while (l < num) {\n                      \
    \  l *= 2;\n                        if (func(op(s, tree[l]))) {\n            \
    \                s = op(std::move(s), tree[l]);\n                            ++l;\n\
    \                        }\n                    }\n                    return\
    \ l - num;\n                }\n                s = op(std::move(s), tree[l]);\n\
    \                ++l;\n            } while ((l & -l) != l);\n            return\
    \ n;\n        }\n\n        template<class F>\n        KYOPRO_BASE_INT min_left(int\
    \ r, F&& func) const {\n            if (r == 0) return 0;\n            r += num;\n\
    \            T s = op.id();\n            do {\n                --r;\n        \
    \        while (r > 1 && (r & 1)) r >>= 1;\n                if (!func(op(tree[r],\
    \ s))) {\n                    while (r < num) {\n                        r = r\
    \ * 2 + 1;\n                        if (func(op(tree[r], s))) {\n            \
    \                s = op(tree[r], std::move(s));\n                            --r;\n\
    \                        }\n                    }\n                    return\
    \ r + 1 - num;\n                }\n                s = op(tree[r], std::move(s));\n\
    \            } while ((r & -r) != r);\n            return 0;\n        }\n    };\n\
    } // namespace kpr\n"
  dependsOn: []
  isVerificationFile: false
  path: kpr/data_structure/SegmentTree.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kpr/data_structure/SegmentTree.hpp
layout: document
redirect_from:
- /library/kpr/data_structure/SegmentTree.hpp
- /library/kpr/data_structure/SegmentTree.hpp.html
title: kpr/data_structure/SegmentTree.hpp
---
