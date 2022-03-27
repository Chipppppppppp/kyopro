#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C&lang=ja"
#include "../math/is_prime.hpp"
#include "../system/all.hpp"

int main() {
  int t;
  kyopro::scan(t);
  for (int i = 0; i < t; ++i) {
    long long x;
    kyopro::scan(x);
    kyopro::println(kyopro::is_prime(x));
  }
}