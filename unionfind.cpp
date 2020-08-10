#include <bits/stdc++.h>
using namespace std;

struct UnionFind
{
  vector<int> par;
  vector<int> sz;
  vector<int> es;

  UnionFind(int n = 1)
  {
    init(n);
  }

  void init(int n = 1)
  {
    par.resize(n);
    sz.resize(n);
    es.resize(n);
    for (int i = 0; i < n; ++i)
    {
      par[i] = i;
      sz[i] = 1;
    }
  }

  int root(int x)
  {
    if (par[x] == x)
      return x;
    return par[x] = root(par[x]);
  }

  bool same(int x, int y)
  {
    return root(x) == root(y);
  }

  void unite(int x, int y)
  {
    x = root(x);
    y = root(y);
    es[x]++;
    if (x == y)
      return;
    if (sz[x] > sz[y])
      swap(x, y);
    par[x] = y;
    sz[y] += sz[x];
    es[y] += es[x];
    return;
  }

  int size(int x)
  {
    return sz[root(x)];
  }

  int esize(int x)
  {
    return es[root(x)];
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
