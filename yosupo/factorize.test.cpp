#define PROBLEM "https://judge.yosupo.jp/problem/factorize"
#include <iostream>
#include "../math/factorize.hpp"

int main() {
  int q;
  std::cin >> q;
  for (int i = 0; i < q; ++i) {
    long long a;
    std::cin >> a;
    auto primes = kyopro::factorize(a);
    std::cout << primes.size();
    for (auto i: primes) std::cout << ' ' << i;
    std::cout << '\n';
  }
}