#pragma once
#include <cstddef>
#include <utility>
#include <vector>
#include "../function/monoid.hpp"

namespace kpr {
    // Binary Indexed Tree
    template<class T, class Op = Add<T>>
    struct FenwickTree {
        using value_type = T;
        using size_type = std::size_t;
        using reference = T&;
        using const_reference = const T&;
        using operator_type = Op;

    private:
        Op op;
        std::vector<T> tree;

    public:
        FenwickTree() noexcept = default;
        explicit FenwickTree(std::size_t n) noexcept: tree(n, op.id()) {}

        std::size_t size() const noexcept {
            return tree.size();
        }

        void apply(int p, const T& x) {
            ++p;
            while (p <= (int)tree.size()) {
                tree[p - 1] = op(tree[p - 1], x);
                p += p & -p;
            }
        }

        void set(int p, const T& x) {
            static_assert(has_inv_v<Op>, "Operator doesn't have an inverse");
            apply(p, op(x, op.inv(get(p))));
        }

        T get(int p) const {
            static_assert(has_inv_v<Op>, "Operator doesn't have an inverse");
            return op(prod(p + 1), op.inv(prod(p)));
        }

        T prod(int r) const {
            T s = op.id();
            while (r > 0) {
                s = op(s, tree[r - 1]);
                r -= r & -r;
            }
            return s;
        }
        T prod(int l, int r) const {
            static_assert(has_inv_v<Op>, "Operator doesn't have an inverse");
            return op(prod(r), op.inv(prod(l)));
        }

        T all_prod() const {
            return prod(tree.size());
        }
    };
} // namespace kpr
