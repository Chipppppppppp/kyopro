#pragma once
#include <type_traits>
#include <utility>
#include <vector>
#include "../function/monoid.hpp"
#include "../meta/settings.hpp"

namespace kyopro {
  template<class T, class Op = Plus<T>, class Container = std::vector<T>>
  struct FenwickTree {
  private:
    [[no_unique_address]] Op op;
    Container tree;

  public:
    using value_type = T;
    using size_type = KYOPRO_BASE_UINT;
    using reference = T&;
    using const_reference = const T&;

    FenwickTree() noexcept = default;
    FenwickTree(KYOPRO_BASE_UINT n) noexcept: tree(n, op.id) {}
    template<class C, std::enable_if_t<std::is_same_v<Container, std::decay_t<C>>>>
    FenwickTree(C&& tree): tree(std::forward<C>(tree)) {}

    KYOPRO_BASE_UINT size() noexcept { return tree.size(); }

    void apply(int p, const T& x) {
      ++p;
      while (p <= (int)size()) {
        tree[p - 1] = op(tree[p - 1], x);
        p += p & -p;
      }
    }

    T prod(int r) const {
      T s = op.id;
      while (r > 0) {
        s = op(s, tree[r - 1]);
        r -= r & -r;
      }
      return s;
    }
    T prod(int l, int r) const { return op(prod(r), op.inv(prod(l))); }

    T all_prod() { return prod(tree.size()); }

    T get(int p) { return op(prod(p + 1), op.inv(prod(p))); }

    void set(int p, const T& x) { apply(p, op(x, op.inv(get(p)))); }
  };
}
