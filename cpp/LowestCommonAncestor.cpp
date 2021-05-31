#include <bits/stdc++.h>
using namespace std;
vector<int> to[100010];
vector<int> euler_d;
vector<int> euler_v;
vector<int> first_visit(100010, -1);

int t = 0;
void dfs(long long v, long long depth) {
    euler_d.push_back(depth);
    euler_v.push_back(v);
    if (first_visit.at(v) == -1) {
        first_visit.at(v) = t;
    }
    t++;
    for (const auto u : to[v]) {
        dfs(u, depth + 1);
        t++;
        euler_d.push_back(depth);
        euler_v.push_back(v);
    }
}

class RangeMinQuery {
   private:
    int N;
    vector<pair<int, int>> data;  // TODO: use generics

    // [l, r)
    pair<int, int> _query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) {
            return {INT_MAX, INT_MAX};
        }
        if (a <= l && r <= b) {
            return data[k];
        }
        pair<int, int> vl = _query(a, b, k * 2 + 1, l, (l + r) / 2);
        pair<int, int> vr = _query(a, b, k * 2 + 2, (l + r) / 2, r);
        return min(vl, vr);
    }

   public:
    RangeMinQuery(int n) : N(1), data(n * 4, {INT_MAX, INT_MAX}) {
        while (n > N) {
            N *= 2;
        }
    }

    // update the value of position i with x
    void update(int i, pair<int, int> x) {
        i += N - 1;
        data[i] = x;
        while (i > 0) {
            i = (i - 1) / 2;
            data[i] = min(data[i * 2 + 1], data[i * 2 + 2]);
        }
    }

    // return the maximum in [a, b)
    pair<int, int> query(int a, int b) { return _query(a, b, 0, 0, N); }
};

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int child;
            cin >> child;
            to[i].push_back(child);
        }
    }
    dfs(0, 0);
    const int M = euler_d.size();
    RangeMinQuery rmq(M);
    for (int i = 0; i < M; i++) {
        rmq.update(i, make_pair(euler_d[i], euler_v[i]));
    }
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int u, v;
        cin >> u >> v;
        int a = first_visit.at(u), b = first_visit.at(v);
        if (a > b) swap(a, b);
        cout << rmq.query(a, b + 1).second << endl;
    }
}