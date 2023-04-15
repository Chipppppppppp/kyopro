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
  code: "#pragma once\r\n#include <array>\r\n#include <cstddef>\r\n#include <cstdint>\r\
    \n#include <type_traits>\r\n#include \"../algorithm/bit.hpp\"\r\n#include \"../meta/setting.hpp\"\
    \r\n#include \"DynamicModInt.hpp\"\r\n\r\nnamespace kpr {\r\n    [[maybe_unused]]\
    \ inline constexpr struct {\r\n        template<class T>\r\n        constexpr\
    \ bool operator ()(T x) const {\r\n            using U = std::make_unsigned_t<T>;\r\
    \n            using dmint = DynamicModInt<U, 0, true>;\r\n            constexpr\
    \ std::array<std::uint_fast64_t, 3> miller_rabin32 = {2, 7, 61};\r\n         \
    \   constexpr std::array<std::uint_fast64_t, 7> miller_rabin64 = {2, 325, 9375,\
    \ 28178, 450775, 9780504, 1795265022};\r\n            U n = x;\r\n           \
    \ if (n <= 1) return false;\r\n            if (!(n & 1)) return n == 2;\r\n  \
    \          dmint::set_mod(n);\r\n            std::uint_fast64_t d = (n - 1) >>\
    \ rzero_count(n - 1);\r\n            dmint one = 1, minus_one = n - 1;\r\n   \
    \         auto ng = [&](std::uint_fast64_t a) noexcept {\r\n                auto\
    \ y = dmint(a).pow(d);\r\n                std::uint_fast64_t t = d;\r\n      \
    \          while (y != one and y != minus_one and t != n - 1) y *= y, t <<= 1;\r\
    \n                if (y != minus_one and !(t & 1)) return true;\r\n          \
    \      return false;\r\n            };\r\n            if constexpr (std::numeric_limits<U>::digits\
    \ <= 32) {\r\n                for (auto i: miller_rabin32) {\r\n             \
    \       if (n <= i) return true;\r\n                    if (ng(i)) return false;\r\
    \n                }\r\n            } else if (n < (static_cast<U>(1) << 32)) {\r\
    \n                for (auto i: miller_rabin32) {\r\n                    if (n\
    \ <= i) return true;\r\n                    if (ng(i)) return false;\r\n     \
    \           }\r\n            } else {\r\n                for (auto i: miller_rabin64)\
    \ {\r\n                    if (n <= i) return true;\r\n                    if\
    \ (ng(i)) return false;\r\n                }\r\n            }\r\n            return\
    \ true;\r\n        }\r\n    } is_prime;\r\n} // namespace kpr\r\n"
  dependsOn: []
  isVerificationFile: false
  path: kpr/math/is_prime.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kpr/math/is_prime.hpp
layout: document
redirect_from:
- /library/kpr/math/is_prime.hpp
- /library/kpr/math/is_prime.hpp.html
title: kpr/math/is_prime.hpp
---
