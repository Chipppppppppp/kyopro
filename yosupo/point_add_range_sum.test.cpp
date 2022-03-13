#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../base/io.hpp"
#include "../structure/FenwickTree.hpp"

int main() {
  int n, q;
  kyopro::scan(n, q);
  kyopro::FenwickTree<long long> ft(n);
  for (int i = 0; i < n; ++i) {
    int a;
    kyopro::scan(a);
    ft.apply(i, a);
  }
  for (int i = 0; i < q; ++i) {
    int t, x, y;
    kyopro::scan(t, x, y);
    if (t == 0) ft.apply(x, y);
    else kyopro::println(ft.prod(x, y));
  }
}