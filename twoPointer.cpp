#include <bits/stdc++.h>
using namespace std;

void solve(int64_t x, vector<int64_t> &A)
{
  int64_t r = 0, s = 0, n = A.size(), ans = 0;
  for (int l = 0; l < n; l++)
  {
    while (r < n && s + A.at(r) <= x)
    {
      s += A.at(r);
      r++;
    }
    ans += (r - l);

    if (r == l)
      r++;
    else
      s -= A.at(l);
  }
  cout << ans << endl;
}

int main()
{
  int64_t N, Q, x;
  cin >> N >> Q;
  vector<int64_t> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A.at(i);
  }
  for (int i = 0; i < Q; i++)
  {
    cin >> x;
    solve(x, A);
  }
}