#ifndef KYOPRO_FENWICK_TREE
#define KYOPRO_FENWICK_TREE
/* FenwickTree */
#include <cstdint>
#include <vector>
#include <utility>
#include "../base/base_int.hpp"

namespace kyopro {
  template<class KyoproT, class KyoproContainer = std::vector<KyoproT>>
  struct FenwickTree {
  private:
    KyoproContainer kyopro_tree;
  public:
    using value_type = KyoproT;
    using size_type = std::size_t;
    using reference = KyoproT&;
    using const_reference = const KyoproT&;
    FenwickTree() noexcept = default;
    FenwickTree(std::size_t kyopro_n) noexcept: kyopro_tree(kyopro_n) {}
    std::size_t size() noexcept { return kyopro_tree.size(); }
    void add(int kyopro_p, const KyoproT& kyopro_x) {
      ++kyopro_p;
      while (kyopro_p <= (int)size()) {
        kyopro_tree[kyopro_p - 1] += kyopro_x;
        kyopro_p += kyopro_p & -kyopro_p;
      }
    }
    void set(int kyopro_p, const KyoproT& kyopro_x) { add(kyopro_p, kyopro_x - get(kyopro_p)); }
    KyoproT query(int kyopro_r) {
      KyoproT kyopro_s = 0;
      while (kyopro_r > 0) {
        kyopro_s += kyopro_tree[kyopro_r - 1];
        kyopro_r -= kyopro_r & -kyopro_r;
      }
      return kyopro_s;
    }
    KyoproT query(int kyopro_l, int kyopro_r) { return query(kyopro_r) - query(kyopro_l); }
    KyoproT get(int kyopro_p) { return query(kyopro_p + 1) - query(kyopro_p); }
    KyoproT all_query() { return query(kyopro_tree.size()); }
  };
}
#endif
