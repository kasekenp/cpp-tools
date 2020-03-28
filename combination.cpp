#include <bits/stdc++.h>
using namespace std;

int64_t nCk(int64_t n, int64_t k)
{
  int64_t res = 1;
  for (int64_t i = 1; i <= k; i++)
  {
    res = (res * (n - i + 1)) / i;
  }
  return res;
}
