#include <bits/stdc++.h>
using namespace std;

int64_t modinv(int64_t a, int64_t m)
{
  int64_t b = m, u = 1, v = 0;
  while (b)
  {
    int64_t t = a / b;
    a -= t * b;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  u %= m;
  if (u < 0)
    u += m;
  return u;
}
