#include <bits/stdc++.h>
using namespace std;
const long long INF = (1LL << 62);

long long rec(int i, int j, vector<vector<long long>> &m, vector<vector<int>> &s, vector<int> &col, vector<int> &row)
{
  if (m[i][j] != INF)
  {
    return m[i][j];
  }
  long long mi = INF;
  for (int k = i; k < j; k++)
  {
    long long res = rec(i, k, m, s, col, row) + rec(k + 1, j, m, s, col, row) + row[i] * col[k] * col[j];
    if (res < mi)
    {
      mi = res;
      s[i][j] = k + 1;
    }
  }
  return m[i][j] = mi;
}

int main()
{
  int n;
  cin >> n;
  vector<int> row(n), col(n);
  vector<vector<long long>> m(n, vector<long long>(n, INF));
  vector<vector<int>> s(n, vector<int>(n, 0)); // m[i,s-1],m[s,j]で区切ると最適
  for (int i = 0; i < n; i++)
  {
    cin >> row[i] >> col[i];
  }
  for (int i = 0; i < n; i++)
  {
    m[i][i] = 0;
  }
  cout << rec(0, n - 1, m, s, col, row) << endl;
  for (int i = 0; i < n; i++)
  {
    for (int j = i; j < n; j++)
    {
      cout << m[i][j] << ',' << s[i][j] << ' ';
    }
    cout << endl;
  }
}