#include <bits/stdc++.h>
using namespace std;

class RangeMinQuery {
   private:
    int N;
    vector<long long> data;  // TODO: use generics

    // [l, r)
    long long _query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) {
            return INT_MAX;
        }
        if (a <= l && r <= b) {
            return data[k];
        }
        long long vl = _query(a, b, k * 2 + 1, l, (l + r) / 2);
        long long vr = _query(a, b, k * 2 + 2, (l + r) / 2, r);
        return min(vl, vr);
    }

   public:
    RangeMinQuery(int n) : N(1), data(n * 4, INT_MAX) {
        while (n > N) {
            N *= 2;
        }
    }

    // update the value of position i with x
    void update(int i, long long x) {
        i += N - 1;
        data[i] = x;
        while (i > 0) {
            i = (i - 1) / 2;
            data[i] = min(data[i * 2 + 1], data[i * 2 + 2]);
        }
    }

    // return the maximum in [a, b)
    long long query(int a, int b) { return _query(a, b, 0, 0, N); }
};

int main() {
    int N, Q;
    cin >> N >> Q;
    RangeMinQuery rmq(N);
    for (int i = 0; i < Q; i++) {
        int type, x, y;
        cin >> type >> x >> y;
        if (type == 0) {
            rmq.update(x, y);
        } else {
            cout << rmq.query(x, y + 1) << endl;
        }
    }
}