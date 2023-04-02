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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: kyopro/function/compare.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include <algorithm>\n#include <iterator>\n#include <unordered_map>\n\
    #include <vector>\n#include \"kyopro/function/compare.hpp\"\n\nnamespace kpr {\n\
    \    // \u5EA7\u6A19\u5727\u7E2E\n    [[maybe_unused]] inline constexpr struct\
    \ {\n        template<class T, class Compare = Less, class Container = std::unordered_map<typename\
    \ std::iterator_traits<T>::value_type, KYOPRO_BASE_INT>>\n        auto operator\
    \ ()(T first, T last, Compare comp = {}) const {\n            std::vector<typename\
    \ Container::key_type> a(first, last);\n            std::sort(a.begin(), a.end(),\
    \ comp);\n            auto itr = unique(a.begin(), a.end());\n            Container\
    \ mem;\n            int cnt = -1;\n            for (auto i = std::begin(a); i\
    \ != itr; ++i) mem[*i] = ++cnt;\n            return mem;\n        }\n    } compress;\n\
    } // namespace kpr\n"
  dependsOn: []
  isVerificationFile: false
  path: kyopro/algorithm/compress.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kyopro/algorithm/compress.hpp
layout: document
redirect_from:
- /library/kyopro/algorithm/compress.hpp
- /library/kyopro/algorithm/compress.hpp.html
title: kyopro/algorithm/compress.hpp
---
