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
  code: "#pragma once\r\n#include <algorithm>\r\n#include <cstddef>\r\n#include <cstdint>\r\
    \n#include <numeric>\r\n#include <random>\r\n#include <type_traits>\r\n#include\
    \ \"../algorithm/bit.hpp\"\r\n#include \"../meta/setting.hpp\"\r\n#include \"\
    DynamicModInt.hpp\"\r\n#include \"is_prime.hpp\"\r\n\r\nnamespace kpr {\r\n  \
    \  // \u7D20\u56E0\u6570\u5206\u89E3\r\n    [[maybe_unused]] inline constexpr\
    \ struct {\r\n        template<class T>\r\n        constexpr T operator ()(T p,\
    \ KYOPRO_BASE_UINT c) const {\r\n            using U = std::make_unsigned_t<T>;\r\
    \n            using dmint = DynamicModInt<U, 0, true>;\r\n            U n = p;\r\
    \n            dmint::set_mod(n);\r\n            dmint cc = c;\r\n            auto\
    \ f = [=](dmint x) noexcept {\r\n                return x * x + cc;\r\n      \
    \      };\r\n            auto x = dmint::raw(1), y = dmint::raw(2), z = dmint::raw(1),\
    \ q = dmint::raw(1);\r\n            U g = 1;\r\n            const int m = 1 <<\
    \ (floor_bit(n) / 5);\r\n            for (int r = 1; g == 1; r <<= 1) {\r\n  \
    \              x = y;\r\n                for (int i = 0; i < r; ++i) y = f(y);\r\
    \n                for (int k = 0; k < r && g == 1; k += m) {\r\n             \
    \       z = y;\r\n                    int min = std::min(m, r - k);\r\n      \
    \              for (int i = 0; i < min; ++i) {\r\n                        y =\
    \ f(y);\r\n                        q *= x - y;\r\n                    }\r\n  \
    \                  g = std::gcd(static_cast<U>(q), n);\r\n                }\r\n\
    \            }\r\n            if (g == n) {\r\n                do {\r\n      \
    \              z = f(z);\r\n                    g = std::gcd(static_cast<U>(x\
    \ - z), n);\r\n                } while (g == 1);\r\n            }\r\n        \
    \    return g;\r\n        }\r\n    } pollard_rho;\r\n\r\n    [[maybe_unused]]\
    \ inline constexpr struct {\r\n        KYOPRO_BASE_UINT operator ()(KYOPRO_BASE_UINT\
    \ n) const noexcept {\r\n            static std::mt19937_64 mt(std::random_device{}());\r\
    \n            std::uniform_int_distribution<std::uint_fast64_t> rnd(0, n - 1);\r\
    \n            if (is_prime(n)) return n;\r\n            for (int i = 0; i < 100;\
    \ ++i) {\r\n                std::uint_fast64_t m = pollard_rho(n, rnd(mt));\r\n\
    \                if (is_prime(m)) return m;\r\n                n = m;\r\n    \
    \        }\r\n            return 1;\r\n        }\r\n    } find_factor;\r\n\r\n\
    \    [[maybe_unused]] inline constexpr struct {\r\n        template<bool sorted\
    \ = true, class Container = std::vector<KYOPRO_BASE_INT>>\r\n        Container\
    \ operator ()(KYOPRO_BASE_UINT n) const {\r\n            Container res;\r\n  \
    \          for (int p = 2; p < 100 && static_cast<KYOPRO_BASE_UINT>(p * p) <=\
    \ n; ++p) {\r\n                while (n % p == 0) {\r\n                    n /=\
    \ p;\r\n                    res.emplace_back(p);\r\n                }\r\n    \
    \        }\r\n            while (n > 1) {\r\n                std::uint_fast64_t\
    \ p = find_factor(n);\r\n                do {\r\n                    n /= p;\r\
    \n                    res.emplace_back(p);\r\n                } while (n % p ==\
    \ 0);\r\n            }\r\n            if constexpr (sorted) std::sort(res.begin(),\
    \ res.end());\r\n            return res;\r\n        }\r\n    } factorize;\r\n\
    } // namespace kpr\r\n"
  dependsOn: []
  isVerificationFile: false
  path: kpr/math/factorize.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kpr/math/factorize.hpp
layout: document
redirect_from:
- /library/kpr/math/factorize.hpp
- /library/kpr/math/factorize.hpp.html
title: kpr/math/factorize.hpp
---
