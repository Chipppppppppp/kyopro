#ifndef KYOPRO_UNION_FIND
#define KYOPRO_UNION_FIND
/* UnionFind */
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <initializer_list>
#include <cstdint>
#include "../base/types.hpp"

namespace kyopro {
  template<class KyoproContainer = std::vector<int>>
  struct UnionFind {
  private:
    KyoproContainer kyopro_par;
  public:
    UnionFind() noexcept = default;
    UnionFind(KYOPRO_BASE_UINT kyopro_n) noexcept: kyopro_par(kyopro_n, -1) {}
    void resize(KYOPRO_BASE_UINT kyopro_x) { kyopro_par.resize(kyopro_x, -1); }
    void assign(KYOPRO_BASE_UINT kyopro_x) { kyopro_par.assign(kyopro_x, -1); }
    void reset() { std::fill(std::begin(kyopro_par), std::end(kyopro_par), -1); }
    KYOPRO_BASE_UINT size() const noexcept { return kyopro_par.size(); }
    KYOPRO_BASE_INT find(int kyopro_x) {
      int kyopro_p = kyopro_x;
      while (kyopro_par[kyopro_p] >= 0) kyopro_p = kyopro_par[kyopro_p];
      while (kyopro_x != kyopro_p) {
        int kyopro_tmp = kyopro_x;
        kyopro_x = kyopro_par[kyopro_x];
        kyopro_par[kyopro_tmp] = kyopro_p;
      }
      return kyopro_p;
    }
    bool unite(int kyopro_x, int kyopro_y) {
      kyopro_x = find(kyopro_x), kyopro_y = find(kyopro_y);
      if (kyopro_x == kyopro_y) return false;
      if (kyopro_par[kyopro_x] > kyopro_par[kyopro_y]) {
        int kyopro_tmp = kyopro_x;
        kyopro_x = kyopro_y;
        kyopro_y = kyopro_tmp;
      }
      kyopro_par[kyopro_x] += kyopro_par[kyopro_y];
      kyopro_par[kyopro_y] = kyopro_x;
      return true;
    }
    bool same(int kyopro_x, int kyopro_y) { return find(kyopro_x) == find(kyopro_y); }
    KYOPRO_BASE_INT group_size(int kyopro_x) { return -kyopro_par[find(kyopro_x)]; }
    KyoproContainer group_members(int kyopro_x) {
      kyopro_x = find(kyopro_x);
      KyoproContainer kyopro_a;
      for (int kyopro_i = 0; kyopro_i < (int)(size()); ++kyopro_i) if (find(kyopro_i) == kyopro_x) kyopro_a.emplace_back(kyopro_i);
      return kyopro_a;
    }
    template<class KyoproVector = std::vector<KYOPRO_BASE_INT>>
    KyoproVector roots() const {
      KyoproVector kyopro_a;
      for (int kyopro_i = 0; kyopro_i < (int)(size()); ++kyopro_i) if (kyopro_par[kyopro_i] < 0) kyopro_a.emplace_back(kyopro_i);
      return kyopro_a;
    }
    KYOPRO_BASE_INT group_count() const {
      KYOPRO_BASE_INT kyopro_cnt = 0;
      for (int kyopro_i = 0; kyopro_i < (int)(size()); ++kyopro_i) if (kyopro_par[kyopro_i] < 0) ++kyopro_cnt;
      return kyopro_cnt;
    }
    template<class KyoproMap = std::unordered_map<KYOPRO_BASE_INT, std::vector<KYOPRO_BASE_INT>>>
    KyoproMap all_group_members() {
      KyoproMap kyopro_group_members;
      for (int kyopro_member = 0; kyopro_member < (int)(size()); ++kyopro_member) kyopro_group_members[find(kyopro_member)].emplace_back(kyopro_member);
      return kyopro_group_members;
    }
  };
}
#endif
