#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DPL_5_C"
#include "kpr/io/io.hpp"
#include "kpr/math/BinomMod.hpp"
#include "kpr/math/ModInt.hpp"

int main() {
    using mint = kpr::ModInt<1000000007>;
    kpr::BinomMod<1000000, mint> bnm;
    int n, k;
    kpr::scan(n, k);
    mint ans = 0;
    for (int i = 0; i <= k; ++i) {
        ans += mint{-1}.pow(k - i) * bnm.c(k, i) * mint{i}.pow(n);
    }
    kpr::println(ans);
}
