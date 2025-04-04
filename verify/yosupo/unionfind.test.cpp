#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include "../../kpr/data_structure/UnionFind.hpp"
#include "../../kpr/io/io.hpp"

int main()
{
    int n, q;
    kpr::scan(n, q);
    kpr::UnionFind uf(n);
    for (int i = 0; i < q; ++i)
    {
        int t, u, v;
        kpr::scan(t, u, v);
        if (t == 0)
            uf.merge(u, v);
        else
            kpr::println(uf.same(u, v));
    }
}
