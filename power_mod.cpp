#include <bits/stdc++.h>
using namespace std;
const int64_t MOD = 1000000007;

int64_t pow_mod(int64_t x, int64_t n)
{
  int64_t res = 1;
  if (n > 0)
  {
    res = pow_mod(x, n / 2);
    if (n % 2 == 0)
      res = (res * res) % MOD;
    else
      res = (((res * res) % MOD) * x) % MOD;
  }
  return res;
}

int main()
{
  int64_t M, N;
  cin >> M >> N;
  cout << pow_mod(M, N) << endl;
}