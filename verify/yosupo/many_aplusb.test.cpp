#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb"
#include "../../system/all.hpp"

int main() {
  int t;
  kyopro::scan(t);
  for (int i = 0; i < t; ++i) {
    long long a, b;
    kyopro::scan(a, b);
    kyopro::println(a + b);
  }
}