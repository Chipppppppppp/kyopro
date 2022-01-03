#ifndef KYOPRO_FENWICK_TREE
#define KYOPRO_FENWICK_TREE
/* FenwickTree */
#include <cstdint>
#include <vector>
#include "../base/base_int.hpp"

namespace kyopro {
  template<class T, class Container = std::vector<T>>
  struct FenwickTree {
  private:
    Container kyopro_tree;
  public:
    using value_type = T;
    using size_type = std::size_t;
    using reference = T&;
    using const_reference = const T&;
    FenwickTree() noexcept = default;
    FenwickTree(std::size_t kyopro_n) noexcept: kyopro_tree(kyopro_n) {}
    std::size_t size() noexcept { return kyopro_tree.size(); }
    void add(int kyopro_p, const T& kyopro_x) {
      ++kyopro_p;
      while (kyopro_p <= (int)size()) {
        kyopro_tree[kyopro_p - 1] += kyopro_x;
        kyopro_p += kyopro_p & -kyopro_p;
      }
    }
    T query(int kyopro_r) {
      T kyopro_s = 0;
      while (kyopro_r > 0) {
        kyopro_s += kyopro_tree[kyopro_r - 1];
        kyopro_r -= kyopro_r & -kyopro_r;
      }
      return kyopro_s;
    }
    T query(int kyopro_l, int kyopro_r) { return query(kyopro_r) - query(kyopro_l); }
    T all_query() { return query(kyopro_tree.size()); }
  };
}
#endif
