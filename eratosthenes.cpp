#include <bits/stdc++.h>
using namespace std;
const int64_t MOD = 1000000007;
const int MXN = 1000010;
bool Seive[MXN];
vector<int64_t> Primes;

void initSeive(int64_t N)
{
  for (int i = 0; i <= N; i++)
    Seive[i] = true;
}

bool isPrime(int64_t x)
{
  return Seive[x];
}

void makeSeive(int64_t N)
{
  initSeive(N);
  Seive[0] = Seive[1] = false;
  for (int64_t i = 2; i <= N; i++)
  {
    if (!isPrime(i))
      continue;
    Primes.emplace_back(i);
    for (int64_t j = 2; i * j <= N; j++)
    {
      Seive[i * j] = false;
    }
  }
}