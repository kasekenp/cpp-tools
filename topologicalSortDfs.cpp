#include <bits/stdc++.h>
using namespace std;
const int MAXV = 10005;
vector<int> to[MAXV];
vector<int> out;

bool visited[MAXV];
void dfs(int v)
{
  if (visited[v])
  {
    return;
  }
  visited[v] = true;
  for (int u : to[v])
  {
    dfs(u);
  }
  out.push_back(v);
}

int main()
{
  int V, E, s, t;
  cin >> V >> E;
  for (int i = 0; i < E; i++)
  {
    cin >> s >> t;
    to[s].push_back(t);
  }
  for (int i = 0; i < V; i++)
  {
    dfs(i);
  }
  reverse(out.begin(), out.end());
  for (int v : out)
  {
    cout << v << endl;
  }
}