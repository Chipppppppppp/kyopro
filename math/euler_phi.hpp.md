---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: all.hpp
    title: all.hpp
  - icon: ':warning:'
    path: math/all.hpp
    title: math/all.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/euler_phi.hpp\"\n#include <cstdint>\n\nnamespace kyopro\
    \ {\n  constexpr std::uint64_t euler_phi(std::uint64_t _n) noexcept {\n    std::uint64_t\
    \ _res = _n;\n    if ((_n & 1) == 0) {\n      _res -= _res >> 1;\n      _n >>=\
    \ 1;\n      while ((_n & 1) == 0) _n >>= 1;\n    }\n    for (std::uint64_t _i\
    \ = 3; _i * _i <= _n; _i += 2) {\n      if (_n % _i == 0) {\n        _res -= _res\
    \ / _i;\n        _n /= _i;\n        while (_n % _i == 0) _n /= _i;\n      }\n\
    \    }\n    if (_n != 1) _res -= _res / _n;\n    return _res;\n  }\n}\n"
  code: "#pragma once\n#include <cstdint>\n\nnamespace kyopro {\n  constexpr std::uint64_t\
    \ euler_phi(std::uint64_t _n) noexcept {\n    std::uint64_t _res = _n;\n    if\
    \ ((_n & 1) == 0) {\n      _res -= _res >> 1;\n      _n >>= 1;\n      while ((_n\
    \ & 1) == 0) _n >>= 1;\n    }\n    for (std::uint64_t _i = 3; _i * _i <= _n; _i\
    \ += 2) {\n      if (_n % _i == 0) {\n        _res -= _res / _i;\n        _n /=\
    \ _i;\n        while (_n % _i == 0) _n /= _i;\n      }\n    }\n    if (_n != 1)\
    \ _res -= _res / _n;\n    return _res;\n  }\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/euler_phi.hpp
  requiredBy:
  - math/all.hpp
  - all.hpp
  timestamp: '2022-01-11 23:13:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/euler_phi.hpp
layout: document
redirect_from:
- /library/math/euler_phi.hpp
- /library/math/euler_phi.hpp.html
title: math/euler_phi.hpp
---
