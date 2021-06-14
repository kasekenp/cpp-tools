#include <bits/stdc++.h>
using namespace std;

class Combination {
   private:
    static const long long MOD = 1000000007;
    vector<long long> fac, finv, inv;

   public:
    Combination(long long N) {
        fac.resize(N + 1);
        finv.resize(N + 1);
        inv.resize(N + 1);
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for (int i = 2; i <= N; i++) {
            fac[i] = fac[i - 1] * i % MOD;
            inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
            finv[i] = finv[i - 1] * inv[i] % MOD;
        }
    }

    long long nCk(int n, int k) {
        if (n < k) return 0;
        if (n < 0 || k < 0) return 0;
        return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
    }

    long long nHk(int n, int k) { return nCk(n + k - 1, k); }
};