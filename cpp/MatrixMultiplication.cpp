#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;

vector<vector<long long>> mul(vector<vector<long long>> a, vector<vector<long long>> b)
{
  vector<vector<long long>> ret((int)a.size(), vector<long long>((int)b.at(0).size(), 0));
  for (int i = 0; i < (int)a.size(); i++)
  {
    for (int j = 0; j < (int)b.at(0).size(); j++)
    {
      for (int k = 0; k < (int)b.size(); k++)
      {
        (ret.at(i).at(j) += a.at(i).at(k) * b.at(k).at(j)) %= MOD;
      }
    }
  }
  return ret;
}