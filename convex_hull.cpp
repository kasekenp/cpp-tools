#include <bits/stdc++.h>
using namespace std;
long double EPS = 1e-10;
long double add(long double a, long double b)
{
  if (abs(a + b) < EPS * (abs(a) + abs(b)))
    return 0;
  return a + b;
}

struct P
{
  long double x, y;
  P() {}
  P(long double x, long double y) : x(x), y(y)
  {
  }
  P operator+(P p)
  {
    return P(add(x, p.x), add(y, p.y));
  }
  P operator-(P p)
  {
    return P(add(x, -p.x), add(y, -p.y));
  }
  P operator*(long double d)
  {
    return P(x * d, y * d);
  }
  long double dot(P p)
  {
    return add(x * p.x, y * p.y);
  }
  long double det(P p)
  {
    return add(x * p.y, -y * p.x);
  }
};

bool cmp_x(const P &p, const P &q)
{
  if (p.x != q.x)
    return p.x < q.x;
  return p.y < q.y;
}

vector<P> convex_hull(P *ps, int n)
{
  sort(ps, ps + n, cmp_x);
  int k = 0;
  vector<P> qs(n * 2);
  for (int i = 0; i < n; i++)
  {
    while (k > 1 && (qs[k - 1] - qs[k - 2]).det(ps[i] - qs[k - 1]) <= 0)
    {
      k--;
    }
    qs[k++] = ps[i];
  }
  for (int i = n - 2, t = k; i >= 0; i--)
  {
    while (k > t && (qs[k - 1] - qs[k - 2]).det(ps[i] - qs[k - 1]) <= 0)
    {
      k--;
    }
    qs[k++] = ps[i];
  }
  qs.resize(k - 1);
  return qs;
}

long double dist(P p, P q)
{
  return (p - q).dot(p - q);
}