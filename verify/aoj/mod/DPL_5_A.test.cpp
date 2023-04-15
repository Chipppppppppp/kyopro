#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DPL_5_A"
#include "kpr/io/io.hpp"
#include "kpr/math/ModInt.hpp"

int main() {
    int n, k;
    kpr::scan(n, k);
    kpr::println(kpr::ModInt<1000000007>{k}.pow(n));
}
