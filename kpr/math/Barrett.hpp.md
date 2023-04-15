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
  code: "#pragma once\r\n#include <cstdint>\r\n#include <limits>\r\n#include <type_traits>\r\
    \n#include \"../meta/setting.hpp\"\r\n#include \"../meta/trait.hpp\"\r\n\r\nnamespace\
    \ kpr {\r\n    // Barrett Reduction\r\n    template<class T>\r\n    struct Barrett\
    \ {\r\n        static_assert(is_unsigned_integer_v<T>, \"The given type must be\
    \ an unsigned integer type\");\r\n\r\n        using value_type = T;\r\n\r\n  \
    \      T mod;\r\n\r\n    private:\r\n        using larger_type = next_integer_t<T>;\r\
    \n\r\n        larger_type m;\r\n\r\n    public:\r\n        constexpr void set_mod(T\
    \ mod) noexcept {\r\n            this->mod = mod;\r\n            m = (static_cast<larger_type>(1)\
    \ << 64) / mod;\r\n        }\r\n\r\n        constexpr KYOPRO_BASE_INT get_mod()\
    \ const noexcept {\r\n            return mod;\r\n        }\r\n\r\n        Barrett()\
    \ noexcept = default;\r\n        Barrett(T mod) noexcept: mod(mod), m((static_cast<larger_type>(1)\
    \ << 64) / mod) {}\r\n\r\n        constexpr T reduce(T x) const noexcept {\r\n\
    \            x -= static_cast<T>((x * m) >> 64) * mod;\r\n            return x\
    \ < mod ? x : x - mod;\r\n        }\r\n    };\r\n} // namespace kpr\r\n"
  dependsOn: []
  isVerificationFile: false
  path: kpr/math/Barrett.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kpr/math/Barrett.hpp
layout: document
redirect_from:
- /library/kpr/math/Barrett.hpp
- /library/kpr/math/Barrett.hpp.html
title: kpr/math/Barrett.hpp
---
