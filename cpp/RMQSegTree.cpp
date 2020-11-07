#include <bits/stdc++.h>
using namespace std;
const int64_t INF = (1LL << 31) - 1;
const int64_t MAXN = (1 << 17); // 131072

int64_t n, dat[2 * MAXN - 1];

void init(int64_t _n)
{
  n = 1;
  while (n < _n)
  {
    n *= 2; // 要素数をnの冪乗に
  }
  for (int i = 0; i < 2 * n - 1; i++)
  {
    dat[i] = INF;
  }
}

// k番目の値(0-indexed)をaに変更
void update(int64_t k, int64_t a)
{
  k += n - 1;
  dat[k] = a;
  while (k > 0)
  {
    k = (k - 1) / 2;
    dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
  }
}

// [a, b)の最小値を求める
// kは節点の番号、l,rはその節点が[l, r)に対応していることを示す
int64_t query(int64_t a, int64_t b, int64_t k, int64_t l, int64_t r)
{
  if (b <= l || r <= a)
    return INF;
  if (a <= l && r <= b)
    return dat[k];
  int64_t vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
  int64_t vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
  return min(vl, vr);
}

int main()
{
  int64_t N, Q, q, x, y;
  queue<int64_t> ans;
  cin >> N >> Q;
  init(N);
  for (int i = 0; i < Q; i++)
  {
    cin >> q >> x >> y;
    if (q)
    {
      ans.push(query(x, y + 1, 0, 0, n));
    }
    else
    {
      update(x, y);
    }
  }
  while (ans.size())
  {
    cout << ans.front() << endl;
    ans.pop();
  }
}