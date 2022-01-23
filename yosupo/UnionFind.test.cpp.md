---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base/settings.hpp
    title: base/settings.hpp
  - icon: ':heavy_check_mark:'
    path: structure/UnionFind.hpp
    title: structure/UnionFind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"yosupo/UnionFind.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n#include <iostream>\n#line 2 \"structure/UnionFind.hpp\"\n/* UnionFind */\n\
    #include <vector>\n#include <unordered_map>\n#include <algorithm>\n#line 2 \"\
    base/settings.hpp\"\n#include <cstdint>\n\n#ifndef KYOPRO_BASE_INT\n#define KYOPRO_BASE_INT\
    \ std::int64_t\n#endif\n\n#ifndef KYOPRO_BASE_UINT\n#define KYOPRO_BASE_UINT std::size_t\n\
    #endif\n\n#ifndef KYOPRO_BASE_FLOAT\n#define KYOPRO_BASE_FLOAT double\n#endif\n\
    \n#ifndef KYOPRO_DEFAULT_MOD\n#define KYOPRO_DEFAULT_MOD static_cast<KYOPRO_BASE_UINT>(1000000007)\n\
    #endif\n\n#ifndef KYOPRO_DECIMAL_PRECISION\n#define KYOPRO_DECIMAL_PRECISION static_cast<KYOPRO_BASE_UINT>(12)\n\
    #endif\n\n#ifndef KYOPRO_INF_DIV\n#define KYOPRO_INF_DIV static_cast<KYOPRO_BASE_UINT>(3)\n\
    #endif\n\n#ifndef KYOPRO_BUFFER_SIZE\n#define KYOPRO_BUFFER_SIZE static_cast<KYOPRO_BASE_UINT>(2048)\n\
    #endif\n#line 7 \"structure/UnionFind.hpp\"\n\nnamespace kyopro {\n  struct UnionFind\
    \ {\n  private:\n    std::vector<int> _par;\n\n  public:\n    UnionFind() noexcept\
    \ = default;\n    UnionFind(KYOPRO_BASE_UINT _n) noexcept: _par(_n, -1) {}\n\n\
    \    void resize(KYOPRO_BASE_UINT _x) { _par.resize(_x, -1); }\n    void assign(KYOPRO_BASE_UINT\
    \ _x) { _par.assign(_x, -1); }\n    void reset() { std::fill(std::begin(_par),\
    \ std::end(_par), -1); }\n\n    KYOPRO_BASE_UINT size() const noexcept { return\
    \ _par.size(); }\n\n    KYOPRO_BASE_INT find(int _x) {\n      int _p = _x;\n \
    \     while (_par[_p] >= 0) _p = _par[_p];\n      while (_x != _p) {\n       \
    \ int _tmp = _x;\n        _x = _par[_x];\n        _par[_tmp] = _p;\n      }\n\
    \      return _p;\n    }\n\n    bool merge(int _x, int _y) {\n      _x = find(_x),\
    \ _y = find(_y);\n      if (_x == _y) return false;\n      if (_par[_x] > _par[_y])\
    \ {\n        int _tmp = _x;\n        _x = _y;\n        _y = _tmp;\n      }\n \
    \     _par[_x] += _par[_y];\n      _par[_y] = _x;\n      return true;\n    }\n\
    \n    bool same(int _x, int _y) { return find(_x) == find(_y); }\n\n    KYOPRO_BASE_INT\
    \ group_size(int _x) { return -_par[find(_x)]; }\n\n    std::vector<int> group_members(int\
    \ _x) {\n      _x = find(_x);\n      std::vector<int> _a;\n      for (int _i =\
    \ 0; _i < (int)(size()); ++_i) if (find(_i) == _x) _a.emplace_back(_i);\n    \
    \  return _a;\n    }\n\n    template<class _typeVector = std::vector<KYOPRO_BASE_INT>>\n\
    \    _typeVector roots() const {\n      _typeVector _a;\n      for (int _i = 0;\
    \ _i < (int)(size()); ++_i) if (_par[_i] < 0) _a.emplace_back(_i);\n      return\
    \ _a;\n    }\n\n    KYOPRO_BASE_INT group_count() const {\n      KYOPRO_BASE_INT\
    \ _cnt = 0;\n      for (int _i = 0; _i < (int)(size()); ++_i) if (_par[_i] < 0)\
    \ ++_cnt;\n      return _cnt;\n    }\n\n    template<class _typeMap = std::unordered_map<KYOPRO_BASE_INT,\
    \ std::vector<KYOPRO_BASE_INT>>>\n    _typeMap all_group_members() {\n      _typeMap\
    \ _group_members;\n      for (int _member = 0; _member < (int)(size()); ++_member)\
    \ _group_members[find(_member)].emplace_back(_member);\n      return _group_members;\n\
    \    }\n  };\n}\n#line 4 \"yosupo/UnionFind.test.cpp\"\n\nint main() {\n  int\
    \ n, q;\n  std::cin >> n >> q;\n  kyopro::UnionFind uf(n);\n  for (int i = 0;\
    \ i < q; ++i) {\n    int t, u, v;\n    std::cin >> t >> u >> v;\n    if (t ==\
    \ 0) uf.merge(u, v);\n    else std::cout << uf.same(u, v) << '\\n';\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#include <iostream>\n\
    #include \"../structure/UnionFind.hpp\"\n\nint main() {\n  int n, q;\n  std::cin\
    \ >> n >> q;\n  kyopro::UnionFind uf(n);\n  for (int i = 0; i < q; ++i) {\n  \
    \  int t, u, v;\n    std::cin >> t >> u >> v;\n    if (t == 0) uf.merge(u, v);\n\
    \    else std::cout << uf.same(u, v) << '\\n';\n  }\n}\n"
  dependsOn:
  - structure/UnionFind.hpp
  - base/settings.hpp
  isVerificationFile: true
  path: yosupo/UnionFind.test.cpp
  requiredBy: []
  timestamp: '2022-01-23 17:08:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: yosupo/UnionFind.test.cpp
layout: document
redirect_from:
- /verify/yosupo/UnionFind.test.cpp
- /verify/yosupo/UnionFind.test.cpp.html
title: yosupo/UnionFind.test.cpp
---
