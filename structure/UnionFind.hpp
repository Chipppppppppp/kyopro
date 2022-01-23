#pragma once
/* UnionFind */
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "../base/settings.hpp"

namespace kyopro {
  struct UnionFind {
  private:
    std::vector<int> _par;

  public:
    UnionFind() noexcept = default;
    UnionFind(KYOPRO_BASE_UINT _n) noexcept: _par(_n, -1) {}

    void resize(KYOPRO_BASE_UINT _x) { _par.resize(_x, -1); }
    void assign(KYOPRO_BASE_UINT _x) { _par.assign(_x, -1); }
    void reset() { std::fill(std::begin(_par), std::end(_par), -1); }

    KYOPRO_BASE_UINT size() const noexcept { return _par.size(); }

    KYOPRO_BASE_INT find(int _x) {
      int _p = _x;
      while (_par[_p] >= 0) _p = _par[_p];
      while (_x != _p) {
        int _tmp = _x;
        _x = _par[_x];
        _par[_tmp] = _p;
      }
      return _p;
    }

    bool merge(int _x, int _y) {
      _x = find(_x), _y = find(_y);
      if (_x == _y) return false;
      if (_par[_x] > _par[_y]) {
        int _tmp = _x;
        _x = _y;
        _y = _tmp;
      }
      _par[_x] += _par[_y];
      _par[_y] = _x;
      return true;
    }

    bool same(int _x, int _y) { return find(_x) == find(_y); }

    KYOPRO_BASE_INT group_size(int _x) { return -_par[find(_x)]; }

    std::vector<int> group_members(int _x) {
      _x = find(_x);
      std::vector<int> _a;
      for (int _i = 0; _i < (int)(size()); ++_i) if (find(_i) == _x) _a.emplace_back(_i);
      return _a;
    }

    template<class _typeVector = std::vector<KYOPRO_BASE_INT>>
    _typeVector roots() const {
      _typeVector _a;
      for (int _i = 0; _i < (int)(size()); ++_i) if (_par[_i] < 0) _a.emplace_back(_i);
      return _a;
    }

    KYOPRO_BASE_INT group_count() const {
      KYOPRO_BASE_INT _cnt = 0;
      for (int _i = 0; _i < (int)(size()); ++_i) if (_par[_i] < 0) ++_cnt;
      return _cnt;
    }

    template<class _typeMap = std::unordered_map<KYOPRO_BASE_INT, std::vector<KYOPRO_BASE_INT>>>
    _typeMap all_group_members() {
      _typeMap _group_members;
      for (int _member = 0; _member < (int)(size()); ++_member) _group_members[find(_member)].emplace_back(_member);
      return _group_members;
    }
  };
}
