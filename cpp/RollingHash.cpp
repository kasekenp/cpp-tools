#include <bits/stdc++.h>
using namespace std;

struct RollingHash {
    typedef unsigned long long ull;
    const ull B = 1000000007;

    // check if a is included in b
    bool contain(string a, string b) {
        const int alen = a.size(), blen = b.size();
        if (alen > blen) {
            return false;
        }
        ull t = 1;
        for (int i = 0; i < alen; i++) {
            t *= B;
        }
        ull ahash = 0, bhash = 0;
        for (int i = 0; i < alen; i++) {
            ahash = ahash * B + a[i];
            bhash = bhash * B + b[i];
        }
        for (int i = 0; i + alen <= blen; i++) {
            if (ahash == bhash) {
                return true;
            }
            if (i + alen < blen) {
                bhash = bhash * B + b[i + alen] - b[i] * t;
            }
        }
        return false;
    }
};
