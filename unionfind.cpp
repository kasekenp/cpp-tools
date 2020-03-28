#include <bits/stdc++.h>
using namespace std;
int MAXN = 100001;
vector<int> Tree(MAXN, 0);

void init(int N)
{
  for (int i = 1; i <= N; i++)
    Tree.at(i) = i;
}

int root(int x)
{
  if (Tree.at(x) == x)
    return x; // 根
  else
    return Tree.at(x) = root(Tree.at(x)); // 経路圧縮
}

bool same(int x, int y)
{
  return root(x) == root(y);
}

void unite(int x, int y)
{
  x = root(x);
  y = root(y);
  if (x == y)
    return;
  Tree.at(x) = y;
}

int main()
{
  int N, Q, p, a, b;
  cin >> N >> Q;
  init(N);
  for (int i = 0; i < Q; i++)
  {
    cin >> p >> a >> b;
    if (p)
      cout << (same(a, b) ? "Yes" : "No") << endl;
    else
      unite(a, b);
  }
}
