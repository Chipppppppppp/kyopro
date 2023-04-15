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
  code: "#pragma once\r\n#include <limits>\r\n#include <type_traits>\r\n#include \"\
    ../meta/setting.hpp\"\r\n#include \"../meta/trait.hpp\"\r\n\r\nnamespace kpr {\r\
    \n    // \u7ACB\u3063\u3066\u3044\u308Bbit\u306E\u500B\u6570\u3092\u8FD4\u3059\
    \r\n    [[maybe_unused]] inline constexpr struct {\r\n        template<class T>\r\
    \n        constexpr KYOPRO_BASE_INT operator ()(T x) const noexcept {\r\n    \
    \        static_assert(is_integer_v<T>, \"The argument must be an integer\");\r\
    \n            constexpr auto digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;\r\
    \n            static_assert(digits <= std::numeric_limits<unsigned long long>::digits,\
    \ \"The integer type of the argument is too large\");\r\n            if constexpr\
    \ (digits <= std::numeric_limits<unsigned int>::digits) return __builtin_popcount(x);\r\
    \n            else if constexpr (digits <= std::numeric_limits<unsigned long>::digits)\
    \ return __builtin_popcountl(x);\r\n            else return __builtin_popcountll(x);\r\
    \n        }\r\n    } pop_count;\r\n\r\n    // \u6700\u4E0A\u4F4Dbit\u3088\u308A\
    \u5DE6\u306E\u9023\u7D9A\u3057\u305F0\u30D3\u30C3\u30C8\u306E\u6570\u3092\u8FD4\
    \u3059\r\n    [[maybe_unused]] inline constexpr struct {\r\n        template<class\
    \ T>\r\n        constexpr KYOPRO_BASE_INT operator ()(T x) const noexcept {\r\n\
    \            static_assert(is_integer_v<T>, \"The argument must be an integer\"\
    );\r\n            constexpr auto digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;\r\
    \n            static_assert(digits <= std::numeric_limits<unsigned long long>::digits,\
    \ \"The integer type of the argument is too large\");\r\n            if (x ==\
    \ 0) return 0;\r\n            if constexpr (digits <= std::numeric_limits<unsigned\
    \ int>::digits) return __builtin_clz(x) + digits - std::numeric_limits<unsigned\
    \ int>::digits;\r\n            else if constexpr (digits <= std::numeric_limits<unsigned\
    \ long>::digits) return __builtin_clzl(x) + digits - std::numeric_limits<unsigned\
    \ long>::digits;\r\n            else return __builtin_clzll(x) + digits - std::numeric_limits<unsigned\
    \ long long>::digits;\r\n        }\r\n    } lzero_count;\r\n\r\n    // 1\u306E\
    \u4F4D\u304B\u3089\u9023\u7D9A\u3057\u305F0\u30D3\u30C3\u30C8\u306E\u6570\u3092\
    \u8FD4\u3059\r\n    [[maybe_unused]] inline constexpr struct {\r\n        template<class\
    \ T>\r\n        constexpr KYOPRO_BASE_INT operator ()(T x) const noexcept {\r\n\
    \            static_assert(is_integer_v<T>, \"The argument must be an integer\"\
    );\r\n            constexpr auto digits = std::numeric_limits<std::make_unsigned_t<T>>::digits;\r\
    \n            if (x == 0) return digits;\r\n            static_assert(digits <=\
    \ std::numeric_limits<unsigned long long>::digits, \"The integer type of the argument\
    \ is too large\");\r\n            if constexpr (digits <= std::numeric_limits<unsigned\
    \ int>::digits) return __builtin_ctz(x);\r\n            else if constexpr (digits\
    \ <= std::numeric_limits<unsigned long>::digits) return __builtin_ctzl(x);\r\n\
    \            else return __builtin_ctzll(x);\r\n        }\r\n    } rzero_count;\r\
    \n\r\n    // \u30D3\u30C3\u30C8\u5E45\u3092\u8FD4\u3059\r\n    [[maybe_unused]]\
    \ inline constexpr struct {\r\n        template<class T>\r\n        constexpr\
    \ KYOPRO_BASE_INT operator ()(T x) const noexcept {\r\n            static_assert(is_integer_v<T>,\
    \ \"The argument must be an integer\");\r\n            constexpr auto digits =\
    \ std::numeric_limits<std::make_unsigned_t<T>>::digits;\r\n            static_assert(digits\
    \ <= std::numeric_limits<unsigned long long>::digits, \"The integer type of the\
    \ argument is too large\");\r\n            if (x == 0) return 0;\r\n         \
    \   if constexpr (digits <= std::numeric_limits<unsigned int>::digits) return\
    \ std::numeric_limits<unsigned int>::digits - __builtin_clz(x);\r\n          \
    \  else if constexpr (digits <= std::numeric_limits<unsigned long>::digits) return\
    \ std::numeric_limits<unsigned long>::digits - __builtin_clzl(x);\r\n        \
    \    else return std::numeric_limits<unsigned long long>::digits - __builtin_clzll(x);\r\
    \n        }\r\n    } bit_len;\r\n\r\n    // 1 << n \u304C\u4E0E\u3048\u3089\u308C\
    \u305F\u6570\u4EE5\u4E0B\u3067\u3042\u308B\u6700\u5927\u306E n \u3092\u8FD4\u3059\
    \ (0 \u306E\u5834\u5408\u30010\u3092\u8FD4\u3059)\r\n    [[maybe_unused]] inline\
    \ constexpr struct {\r\n        template<class T>\r\n        constexpr KYOPRO_BASE_INT\
    \ operator ()(T x) const noexcept {\r\n            return bit_len(x >> static_cast<T>(1));\r\
    \n        }\r\n    } floor_bit;\r\n\r\n    // 1 << n \u304C\u4E0E\u3048\u3089\u308C\
    \u305F\u6570\u4EE5\u4E0A\u3067\u3042\u308B\u6700\u5C0F\u306E n \u3092\u8FD4\u3059\
    \r\n    [[maybe_unused]] inline constexpr struct {\r\n        template<class T>\r\
    \n        constexpr KYOPRO_BASE_INT operator ()(T x) const noexcept {\r\n    \
    \        if (x == 0) return 0;\r\n            return bit_len(x - static_cast<T>(1));\r\
    \n        }\r\n    } ceil_bit;\r\n} // namespace kpr\r\n"
  dependsOn: []
  isVerificationFile: false
  path: kpr/algorithm/bit.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: kpr/algorithm/bit.hpp
layout: document
redirect_from:
- /library/kpr/algorithm/bit.hpp
- /library/kpr/algorithm/bit.hpp.html
title: kpr/algorithm/bit.hpp
---
