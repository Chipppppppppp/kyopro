#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DPL_5_D"
#include "kpr/io/io.hpp"
#include "kpr/math/BinomMod.hpp"

int main() {
    kpr::BinomMod<1000000, kpr::ModInt<1000000007>> bnm;
    int n, k;
    kpr::scan(n, k);
    kpr::println(bnm.h(k, n));
}
