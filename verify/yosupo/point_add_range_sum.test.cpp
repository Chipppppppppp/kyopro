#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include "../../data_structure/FenwickTree.hpp"
#include "../../system/system.hpp"

int main() {
  int n, q;
  kpr::scan(n, q);
  kpr::FenwickTree<long long> ft(n);
  for (int i = 0; i < n; ++i) {
    int a;
    kpr::scan(a);
    ft.apply(i, a);
  }
  for (int i = 0; i < q; ++i) {
    int t, x, y;
    kpr::scan(t, x, y);
    if (t == 0) ft.apply(x, y);
    else kpr::println(ft.prod(x, y));
  }
}
