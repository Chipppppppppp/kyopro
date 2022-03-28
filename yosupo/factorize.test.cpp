#define PROBLEM "https://judge.yosupo.jp/problem/factorize"
#include "../math/factorize.hpp"
#include "../system/all.hpp"

int main() {
  ll q;
  kyopro::scan(q);
  for (int i = 0; i < q; ++i) {
    ll a;
    kyopro::scan(a);
    auto res = kyopro::factorize(a);
    println(len(res), res);
  }
}