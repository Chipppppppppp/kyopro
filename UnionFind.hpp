/* UnionFind */
#pragma once
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <initializer_list>
#include <cstdint>
#include "../base_int.hpp"

namespace kyopro {
  template<class KyoproContainer = std::vector<int>>
  struct UnionFind {
  private:
    KyoproContainer kyopro_par;
  public:
    UnionFind() noexcept = default;
    UnionFind(std::size_t kyopro_n) noexcept: kyopro_par(kyopro_n, -1) {}
    void resize(std::size_t kyopro_x) { kyopro_par.resize(kyopro_x, -1); }
    void assign(std::size_t kyopro_x) { kyopro_par.assign(kyopro_x, -1); }
    void reset() { std::fill(std::begin(kyopro_par), std::end(kyopro_par), -1); }
    std::size_t size() const noexcept { return kyopro_par.size(); }
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
      int root = find(kyopro_x);
      KyoproContainer kyopro_a;
      for (int kyopro_i = 0; kyopro_i < (int)(size()); ++kyopro_i) if (find(kyopro_i) == root) kyopro_a.emplace_back(kyopro_i);
      return kyopro_a;
    }
    std::vector<KYOPRO_BASE_INT> roots() const {
      std::vector<KYOPRO_BASE_INT> kyopro_a;
      for (int kyopro_i = 0; kyopro_i < (int)(size()); ++kyopro_i) if (kyopro_par[kyopro_i] < 0) kyopro_a.emplace_back(kyopro_i);
      return kyopro_a;
    }
    KYOPRO_BASE_INT group_count() const {
      KYOPRO_BASE_INT cnt = 0;
      for (int kyopro_i = 0; kyopro_i < (int)(size()); ++kyopro_i) if (kyopro_par[kyopro_i] < 0) ++cnt;
      return cnt;
    }
    template<class Container = std::unordered_map<KYOPRO_BASE_INT, std::vector<KYOPRO_BASE_INT>>>
    Container all_group_members() {
      Container group_members;
      for (int member = 0; member < (int)(size()); ++member) group_members[find(member)].emplace_back(member);
      return group_members;
    }
  };
}