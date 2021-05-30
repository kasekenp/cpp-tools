#include <bits/stdc++.h>
using namespace std;

struct WeightedUnionFind {
    vector<int> par;
    vector<int> sz;
    vector<long long> diff_weight;  // parとの差分

    WeightedUnionFind(int n = 1) { init(n); }

    void init(int n = 1) {
        par.resize(n);
        sz.resize(n);
        diff_weight.resize(n);
        for (int i = 0; i < n; ++i) {
            par[i] = i;
            sz[i] = 1;
            diff_weight[i] = 0;
        }
    }

    int root(int x) {
        if (par[x] == x) return x;

        auto r = root(par[x]);
        diff_weight[x] += diff_weight[par[x]];  // 累積和
        return par[x] = r;
    }

    bool isSame(int x, int y) { return root(x) == root(y); }

    // weight(y) = weight(x) + w となるようにxとyをマージ
    void merge(int x, int y, int w) {
        w += weight(x);
        w -= weight(y);
        x = root(x);
        y = root(y);
        if (x == y) return;
        if (sz[x] < sz[y]) {
            swap(x, y);
            w = -w;
        };
        par[y] = x;
        sz[x] += sz[y];
        diff_weight[y] = w;
        return;
    }

    int size(int x) { return sz[root(x)]; }

    long long weight(int x) {
        root(x);  // 経路圧縮
        return diff_weight.at(x);
    }

    // x と y とが同じグループにいるとき、weight(y) - weight(x)
    long long diff(int x, int y) { return weight(y) - weight(x); }
};

int main() {
    long long N, Q;
    cin >> N >> Q;
    WeightedUnionFind wuf(N);
    for (int i = 0; i < Q; i++) {
        int type;
        cin >> type;
        if (type == 0) {  // relate
            int x, y, z;
            cin >> x >> y >> z;
            wuf.merge(x, y, z);
        } else {  // diff
            int x, y;
            cin >> x >> y;
            if (wuf.isSame(x, y)) {
                cout << wuf.diff(x, y) << endl;
            } else {
                cout << '?' << endl;
            }
        }
    }
}
