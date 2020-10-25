#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> P;
const long long INF = (1LL << 62);
const int MAXV = 100010;
long long V, E, r;
vector<P> to[MAXV];

void dijkstra(int start)
{
  priority_queue<P, vector<P>, greater<P>> PQ;
  vector<long long> D(V, INF);
  vector<bool> visited(V, false);

  D.at(start) = 0;
  PQ.emplace(0, start);
  while (!PQ.empty())
  {
    long long dv, v;
    tie(dv, v) = PQ.top();
    PQ.pop();
    visited.at(v) = true;
    if (D.at(v) < dv)
    {
      continue;
    }
    for (auto p : to[v])
    {
      long long u, du;
      tie(u, du) = p;
      if (visited.at(u))
      {
        continue;
      }
      if (D.at(u) > D.at(v) + du)
      {
        D.at(u) = D.at(v) + du;
        PQ.emplace(D.at(u), u);
      }
    }
  }

  for (auto d : D)
  {
    cout << (d == INF ? "INF" : to_string(d)) << endl;
  }
}

int main()
{
  cin >> V >> E >> r;
  for (int i = 0; i < E; i++)
  {
    long long s, t, d;
    cin >> s >> t >> d;
    to[s].emplace_back(t, d);
  }
  dijkstra(r);
}
