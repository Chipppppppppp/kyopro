#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include "../../structure/UnionFind.hpp"
#include "../../system/system.hpp"

int main() {
  int n, q;
  kpr::scan(n, q);
  kpr::UnionFind uf(n);
  for (int i = 0; i < q; ++i) {
    int t, u, v;
    kpr::scan(t, u, v);
    if (t == 0) uf.merge(u, v);
    else kpr::println(uf.same(u, v));
  }
}
