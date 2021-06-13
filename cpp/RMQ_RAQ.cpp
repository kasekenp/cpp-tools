#include <bits/stdc++.h>
using namespace std;

class RangeMinQuery {
   private:
    int N;
    vector<long long> data, lazy;

    void eval(int k, int l, int r) {
        if (lazy.at(k) == 0) return;
        data.at(k) += lazy.at(k);
        if (r - l > 1) {
            lazy.at(2 * k + 1) += lazy.at(k);
            lazy.at(2 * k + 2) += lazy.at(k);
        }
        lazy.at(k) = 0;
    }

   public:
    RangeMinQuery(int n, long long v = 0) {
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
            lazy.at(k) += x;
            eval(k, l, r);
            return;
        }
        add(a, b, x, 2 * k + 1, l, (l + r) / 2);
        add(a, b, x, 2 * k + 2, (l + r) / 2, r);
        data.at(k) = min(data.at(2 * k + 1), data.at(2 * k + 2));
    }

    long long query(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = N;
        if (b <= l || r <= a) return INT_MAX;
        eval(k, l, r);
        if (a <= l && r <= b) return data.at(k);
        long long vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
        long long vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
        return min(vl, vr);
    }
};

int main() {
    int N, Q;
    cin >> N >> Q;
    RangeMinQuery RMQ(N);
    vector<long long> res;
    for (int i = 0; i < Q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            cin >> l >> r;
            res.push_back(RMQ.query(l, r + 1));
            continue;
        }
        long long l, r, x;
        cin >> l >> r >> x;
        RMQ.add(l, r + 1, x);
    }
    for (const auto n : res) {
        cout << n << endl;
    }
}
