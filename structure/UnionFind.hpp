#pragma once
#include <algorithm>
#include <type_traits>
#include <unordered_map>
#include <utility>
#include <vector>
#include "../meta/settings.hpp"
#include "../meta/trait.hpp"

namespace kpr {
  template<class Container = std::vector<int>>
  struct UnionFind {
    using value_type = iterable_value_t<Container>;
    using container_type = Container;

  private:
    Container par;

  public:
    UnionFind() noexcept = default;
    UnionFind(KYOPRO_BASE_UINT n) noexcept: par(n, -1) {}
    template<class C, std::enable_if_t<std::is_same_v<Container, std::decay_t<C>>>>
    UnionFind(C&& par): par(std::forward<C>(par)) {}

    void resize(KYOPRO_BASE_UINT x) { par.resize(x, -1); }
    void assign(KYOPRO_BASE_UINT x) { par.assign(x, -1); }
    void reset() { std::fill(std::begin(par), std::end(par), -1); }

    KYOPRO_BASE_UINT size() const noexcept { return par.size(); }

    KYOPRO_BASE_INT find(int x) {
      int p = x;
      while (par[p] >= 0) p = par[p];
      while (x != p) {
        int tmp = x;
        x = par[x];
        par[tmp] = p;
      }
      return p;
    }

    bool merge(int x, int y) {
      x = find(x), y = find(y);
      if (x == y) return false;
      if (par[x] > par[y]) {
        int tmp = x;
        x = y;
        y = tmp;
      }
      par[x] += par[y];
      par[y] = x;
      return true;
    }

    bool same(int x, int y) { return find(x) == find(y); }

    KYOPRO_BASE_INT group_size(int x) { return -par[find(x)]; }

    std::vector<int> group_members(int x) {
      x = find(x);
      std::vector<int> a;
      for (int i = 0; i < (int)(size()); ++i) if (find(i) == x) a.emplace_back(i);
      return a;
    }

    template<class Vector = std::vector<KYOPRO_BASE_INT>>
    Vector roots() const {
      Vector a;
      for (int i = 0; i < (int)(size()); ++i) if (par[i] < 0) a.emplace_back(i);
      return a;
    }

    KYOPRO_BASE_INT group_count() const {
      KYOPRO_BASE_INT cnt = 0;
      for (int i = 0; i < (int)(size()); ++i) if (par[i] < 0) ++cnt;
      return cnt;
    }

    template<class Map = std::unordered_map<KYOPRO_BASE_INT, std::vector<KYOPRO_BASE_INT>>>
    Map all_group_members() {
      Map group_members;
      for (int member = 0; member < (int)(size()); ++member) group_members[find(member)].emplace_back(member);
      return group_members;
    }
  };
}
