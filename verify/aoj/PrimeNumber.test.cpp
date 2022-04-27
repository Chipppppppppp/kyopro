#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C&lang=ja"
#include "../../math/is_prime.hpp"
#include "../../system/all.hpp"

int main() {
  int t;
  kpr::scan(t);
  int cnt = 0;
  for (int i = 0; i < t; ++i) {
    long long x;
    kpr::scan(x);
    if (kpr::is_prime(x)) ++cnt;
  }
  kpr::println(cnt);
}