#include <bits/stdc++.h>
using namespace std;

template <typename T>
class FenwickTree
{
public:
  int N;
  vector<T> dat;

  FenwickTree(int n, T m = 0)
  {
    init(n, m);
  }

  void init(int n, int m)
  {
    N = n;
    dat.resize(n + 1);
    for (int i = 0; i < dat.size(); i++)
    {
      dat[i] = m;
    }
  }

  int64_t sum(int i)
  {
    T s = 0;
    while (i > 0)
    {
      s += dat[i];
      i -= i & -i;
    }
    return s;
  }

  void add(int i, T x)
  {
    while (i <= N)
    {
      dat[i] += x;
      i += i & -i;
    }
  }
};