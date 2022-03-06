#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include <iostream>
#include "../structure/UnionFind.hpp"
#include "../base/out.hpp"

int main() {
  int n, q;
  std::cin >> n >> q;
  kyopro::UnionFind uf(n);
  for (int i = 0; i < q; ++i) {
    int t, u, v;
    std::cin >> t >> u >> v;
    if (t == 0) uf.merge(u, v);
    else kyopro::println(uf.same(u, v));
  }
}
