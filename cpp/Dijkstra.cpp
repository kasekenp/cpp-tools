#include <bits/stdc++.h>
using namespace std;

class Dijkstra {
   public:
    typedef pair<long long, long long> P;
    const long long INF = (1LL << 62);
    vector<long long> min_path(vector<vector<P>> &to, int start) {
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<long long> d((int)to.size(), INF);
        d.at(start) = 0;
        pq.emplace(0, start);
        while (!pq.empty()) {
            long long dv, v;
            tie(dv, v) = pq.top();
            pq.pop();
            if (d.at(v) < dv) {
                continue;
            }
            for (auto p : to.at(v)) {
                long long u, du;
                tie(u, du) = p;
                if (d.at(u) > d.at(v) + du) {
                    d.at(u) = d.at(v) + du;
                    pq.emplace(d.at(u), u);
                }
            }
        }
        return d;
    }
};

int main() {
    int V, E, r;
    cin >> V >> E >> r;
    vector<vector<Dijkstra::P>> to(V);
    for (int i = 0; i < E; i++) {
        long long s, t, d;
        cin >> s >> t >> d;
        to[s].emplace_back(t, d);
    }
    Dijkstra dijkstra;
    auto res = dijkstra.min_path(to, r);
    for (const auto n : res) {
        cout << (n == Dijkstra::INF ? "INF" : to_string(n)) << endl;
    }
}
