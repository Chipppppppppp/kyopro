#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb"
#include "../../io/io.hpp"

int main() {
  int t;
  kpr::scan(t);
  for (int i = 0; i < t; ++i) {
    long long a, b;
    kpr::scan(a, b);
    kpr::println(a + b);
  }
}
