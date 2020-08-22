#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000;
const int logMAX = 17; //2^17>=100000(=MAX)

int V;
vector<int> G[MAX];
int root;
int parent[logMAX][MAX];
int depth[MAX];

void dfs(int v, int p, int d)
{
  parent[0][v] = p;
  depth[v] = d;
  for (int i = 0; i < G[v].size(); i++)
  {
    if (G[v][i] != p)
      dfs(G[v][i], v, d + 1);
  }
  return;
}

void init()
{
  dfs(root, -1, 0);
  for (int k = 0; k + 1 < logMAX; k++)
  {
    for (int v = 0; v < V; v++)
    {
      if (parent[k][v] < 0)
        parent[k + 1][v] = -1;
      else
        parent[k + 1][v] = parent[k][parent[k][v]];
    }
  }
  return;
}

int lca(int u, int v)
{
  if (depth[u] > depth[v])
    swap(u, v);
  for (int k = 0; k < logMAX; k++)
  {
    if ((depth[v] - depth[u]) >> k & 1)
    {
      v = parent[k][v];
    }
  }
  if (u == v)
    return u;
  for (int k = logMAX - 1; k >= 0; k--)
  {
    if (parent[k][u] != parent[k][v])
    {
      u = parent[k][u];
      v = parent[k][v];
    }
  }
  return parent[0][u];
}

int main()
{
  root = 0;
  cin >> V;
  for (int i = 0; i < V; i++)
  {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++)
    {
      int u;
      cin >> u;
      G[i].push_back(u);
      G[u].push_back(i);
    }
  }
  init();
  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++)
  {
    int u, v;
    cin >> u >> v;
    cout << lca(u, v) << endl;
  }
}