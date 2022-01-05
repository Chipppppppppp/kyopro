#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include <iostream>
#include "../all.hpp"
using ll = long long;

int main() {
  int n, q;
  std::cin >> n >> q;
  kyopro::FenwickTree<ll> ft(n);
  for (int i = 0; i < n; ++i) {
    int a;
    std::cin >> a;
    ft.apply(i, a);
  }
  for (int i = 0; i < q; ++i) {
    int t, x, y;
    std::cin >> t >> x >> y;
    if (t == 0) ft.apply(x, y);
    else std::cout << ft.prod(x, y) << '\n';
  }
}
