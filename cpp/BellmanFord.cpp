#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2505;
const int MAXM = 5005;
const int64_t INF = (1LL << 62);
struct edge
{
  int64_t from, to, cost;
};
edge es[MAXM];

vector<int64_t> d(MAXN, INF);
bool BellmanFord(int s, int V, int E)
{
  d[s] = 0;
  for (int i = 0; i < V; i++)
  {
    for (int j = 0; j < E; j++)
    {
      edge e = es[j];
      if (d[e.from] == INF)
        continue;
      if (d[e.to] > d[e.from] + e.cost)
      {
        d[e.to] = d[e.from] + e.cost;
        if (i == V - 1)
        {
          return false;
        }
      }
    }
  }
  return true;
}