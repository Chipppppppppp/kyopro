#define PROBLEM "https://judge.yosupo.jp/problem/factorize"
#include "../../kpr/io/io.hpp"
#include "../../kpr/math/factorize.hpp"

int main()
{
    long long q;
    kpr::scan(q);
    for (int i = 0; i < q; ++i)
    {
        long long a;
        kpr::scan(a);
        auto res = kpr::factorize(a);
        kpr::println(res.size(), res);
    }
}
