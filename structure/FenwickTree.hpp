#pragma once
/* FenwickTree */
#include <vector>
#include <utility>
#include "../base/settings.hpp"
#include "../base/monoid.hpp"

namespace kyopro {
  template<class KyoproT, class KyoproOp = Plus<KyoproT>, class KyoproContainer = std::vector<KyoproT>>
  struct FenwickTree {
  private:
    KyoproContainer kyopro_tree;
  public:
    using value_type = KyoproT;
    using size_type = KYOPRO_BASE_UINT;
    using reference = KyoproT&;
    using const_reference = const KyoproT&;
    FenwickTree() noexcept = default;
    FenwickTree(KYOPRO_BASE_UINT kyopro_n) noexcept: kyopro_tree(kyopro_n, KyoproOp::id) {}
    KYOPRO_BASE_UINT size() noexcept { return kyopro_tree.size(); }
    void apply(int kyopro_p, const KyoproT& kyopro_x) {
      ++kyopro_p;
      while (kyopro_p <= (int)size()) {
        kyopro_tree[kyopro_p - 1] = KyoproOp::op(kyopro_tree[kyopro_p - 1], kyopro_x);
        kyopro_p += kyopro_p & -kyopro_p;
      }
    }
    KyoproT prod(int kyopro_r) const {
      KyoproT kyopro_s = KyoproOp::id;
      while (kyopro_r > 0) {
        kyopro_s = KyoproOp::op(kyopro_s, kyopro_tree[kyopro_r - 1]);
        kyopro_r -= kyopro_r & -kyopro_r;
      }
      return kyopro_s;
    }
    KyoproT prod(int kyopro_l, int kyopro_r) const { return KyoproOp::op(prod(kyopro_r), KyoproOp::inv(prod(kyopro_l))); }
    KyoproT get(int kyopro_p) { return KyoproOp::op(prod(kyopro_p + 1), KyoproOp::inv(prod(kyopro_p))); }
    KyoproT all_query() { return prod(kyopro_tree.size()); }
    void set(int kyopro_p, const KyoproT& kyopro_x) { apply(kyopro_p, KyoproOp::op(kyopro_x, KyoproOp::inv(get(kyopro_p)))); }
  };
}
