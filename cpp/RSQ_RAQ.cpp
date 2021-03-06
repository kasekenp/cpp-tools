#include <bits/stdc++.h>
using namespace std;

class RangeSumQuery {
   private:
    int N;
    vector<long long> data, lazy;

    void eval(int k, int l, int r) {
        if (lazy.at(k) == 0) return;
        data.at(k) += lazy.at(k);
        if (r - l > 1) {
            lazy.at(2 * k + 1) += lazy.at(k) / 2;
            lazy.at(2 * k + 2) += lazy.at(k) / 2;
        }
        lazy.at(k) = 0;
    }

   public:
    RangeSumQuery(int n, long long v = 0) {
        N = 1;
        while (N < n) N *= 2;
        data.resize(2 * N - 1, v);
        lazy.resize(2 * N - 1, 0);
    }

    void add(int a, int b, long long x, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = N;
        eval(k, l, r);
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            lazy.at(k) += (r - l) * x;
            eval(k, l, r);
            return;
        }
        add(a, b, x, 2 * k + 1, l, (l + r) / 2);
        add(a, b, x, 2 * k + 2, (l + r) / 2, r);
        data.at(k) = data.at(2 * k + 1) + data.at(2 * k + 2);
    }

    long long sum(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = N;
        if (b <= l || r <= a) return 0;
        eval(k, l, r);
        if (a <= l && r <= b) return data.at(k);
        long long vl = sum(a, b, 2 * k + 1, l, (l + r) / 2);
        long long vr = sum(a, b, 2 * k + 2, (l + r) / 2, r);
        return vl + vr;
    }
};

int main() {
    int N, Q;
    cin >> N >> Q;
    RangeSumQuery RSQ(N);
    vector<long long> res;
    for (int i = 0; i < Q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            cin >> l >> r;
            l--, r--;
            res.push_back(RSQ.sum(l, r + 1));
            continue;
        }
        long long l, r, x;
        cin >> l >> r >> x;
        l--, r--;
        RSQ.add(l, r + 1, x);
    }
    for (const auto n : res) {
        cout << n << endl;
    }
}