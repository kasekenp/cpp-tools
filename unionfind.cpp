#include <bits/stdc++.h>
using namespace std;

struct UnionFind
{
  vector<int> par;
  vector<int> rank;

  UnionFind(int n = 1)
  {
    init(n);
  }

  void init(int n = 1)
  {
    par.resize(n);
    rank.resize(n);
    for (int i = 0; i < n; ++i)
      par[i] = i, rank[i] = 0;
  }

  int root(int x)
  {
    if (par[x] == x)
      return x;
    int r = root(par[x]);
    return par[x] = r;
  }

  bool same(int x, int y)
  {
    return root(x) == root(y);
  }

  bool unite(int x, int y)
  {
    x = root(x);
    y = root(y);
    if (x == y)
      return false;
    if (rank[x] < rank[y])
      swap(x, y);
    if (rank[x] == rank[y])
      ++rank[x];
    par[y] = x;
    return true;
  }
};

int main()
{
  int64_t N, Q, c, x, y;
  cin >> N >> Q;
  UnionFind uf(N);
  vector<tuple<bool, int, int>> vt;
  for (int i = 0; i < Q; i++)
  {
    cin >> c >> x >> y;
    vt.push_back(make_tuple(c, x, y));
  }
  for (int i = 0; i < Q; i++)
  {
    tie(c, x, y) = vt.at(i);
    if (c)
      cout << uf.same(x, y) << endl;
    else
      uf.unite(x, y);
  }
}
