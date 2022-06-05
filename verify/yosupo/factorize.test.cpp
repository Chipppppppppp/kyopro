#define PROBLEM "https://judge.yosupo.jp/problem/factorize"
#include "../../math/factorize.hpp"
#include "../../system/all.hpp"

int main() {
  long long q;
  kyopro::scan(q);
  for (int i = 0; i < q; ++i) {
    long long a;
    kyopro::scan(a);
    auto res = kyopro::factorize(a);
    kyopro::println(res.size(), res);
  }
}