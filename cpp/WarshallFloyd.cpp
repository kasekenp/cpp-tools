#include <bits/stdc++.h>
using namespace std;

struct WarshallFloyd
{
  const long long INF = 1LL << 60;
  vector<vector<long long>> d;
  WarshallFloyd(int V)
  {
    d.resize(V);
    for (int i = 0; i < V; i++)
    {
      d.at(i).assign(V, INF);
    }
    for (int i = 0; i < V; i++)
    {
      d[i][i] = 0;
    }
  }

  void addEdge(int from, int to, long long cost)
  {
    d[from][to] = cost;
  }

  void calculateShortestPath()
  {
    int V = d.size();
    for (int k = 0; k < V; k++)
    {
      for (int i = 0; i < V; i++)
      {
        for (int j = 0; j < V; j++)
        {
          if (d[i][k] == INF || d[k][j] == INF)
          {
            continue;
          }
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
      }
    }
  }

  long long shortestPath(int from, int to)
  {
    return d[from][to];
  }

  bool hasNegativeCycle()
  {
    int V = d.size();
    for (int i = 0; i < V; i++)
    {
      if (d[i][i] < 0)
      {
        return true;
      }
    }
    return false;
  }
};

int main()
{
  int v, e;
  cin >> v >> e;
  WarshallFloyd wf(v);
  for (int i = 0; i < e; i++)
  {
    long long s, t, d;
    cin >> s >> t >> d;
    wf.addEdge(s, t, d);
  }
  wf.calculateShortestPath();
  if (wf.hasNegativeCycle())
  {
    cout << "NEGATIVE CYCLE" << endl;
    return 0;
  }
  for (int from = 0; from < v; from++)
  {
    for (int to = 0; to < v; to++)
    {
      long long d = wf.shortestPath(from, to);
      if (to)
      {
        cout << ' ';
      }
      cout << (d == wf.INF ? "INF" : to_string(d));
    }
    cout << endl;
  }
}