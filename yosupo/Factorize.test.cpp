#define PROBLEM "https://judge.yosupo.jp/problem/factorize"
#include "../base/io.hpp"
#include "../math/factorize.hpp"

int main() {
  int q;
  kyopro::scan(q);
  for (int i = 0; i < q; ++i) {
    long long a;
    kyopro::scan(a);
    auto ans = kyopro::factorize(a);
    kyopro::println(ans.size(), ans);
  }
}