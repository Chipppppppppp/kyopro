#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "../meta/io.hpp"
#include "../structure/UnionFind.hpp"

int main() {
  int n, q;
  kyopro::scan(n, q);
  kyopro::UnionFind uf(n);
  for (int i = 0; i < q; ++i) {
    int t, u, v;
    kyopro::scan(t, u, v);
    if (t == 0) uf.merge(u, v);
    else kyopro::println(uf.same(u, v));
  }
}
