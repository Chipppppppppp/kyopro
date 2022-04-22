#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C&lang=ja"
#include "../../math/is_prime.hpp"
#include "../../system/all.hpp"

int main() {
  int t;
  kyopro::scan(t);
  int cnt = 0;
  for (int i = 0; i < t; ++i) {
    long long x;
    kyopro::scan(x);
    if (kyopro::is_prime(x)) ++cnt;
  }
  kyopro::println(cnt);
}