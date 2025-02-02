#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#include <utility>
#include "../../kpr/data_structure/SegmentTree.hpp"
#include "../../kpr/io/io.hpp"
#include "../../kpr/math/ModInt.hpp"

using S = std::pair<kpr::ModInt<998244353>, kpr::ModInt<998244353>>;
struct Op
{
    S operator()(const S &a, const S &b) const noexcept
    {
        return {a.first * b.first, a.second * b.first + b.second};
    }

    static S id() noexcept
    {
        return {1, 0};
    }
};

int main()
{
    int n, q;
    kpr::scan(n, q);
    std::vector<S> ab(n);
    kpr::scan(ab);
    kpr::SegmentTree<S, Op> seg(ab);
    for (int i = 0; i < q; ++i)
    {
        int t;
        kpr::scan(t);
        if (t == 0)
        {
            int p, c, d;
            kpr::scan(p, c, d);
            seg.set(p, {c, d});
        }
        else
        {
            int l, r, x;
            kpr::scan(l, r, x);
            auto [a, b] = seg.prod(l, r);
            kpr::println(a * x + b);
        }
    }
}
