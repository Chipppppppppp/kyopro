#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_B"
#include "kyopro/data_structure/WeightedUnionFind.hpp"
#include "kyopro/io/io.hpp"

int main() {
    int n, q;
    kpr::scan(n, q);
    kpr::WeightedUnionFind<long long> wuf(n);
    for (int i = 0; i < q; ++i) {
        int t;
        kpr::scan(t);
        if (t == 0) {
            int x, y, z;
            kpr::scan(x, y, z);
            wuf.merge(x, y, z);
        } else {
            int x, y;
            kpr::scan(x, y);
            if (wuf.same(x, y)) kpr::println(wuf.diff(x, y));
            else kpr::println('?');
        }
    }
}
