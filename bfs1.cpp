#include <bits/stdc++.h>
using namespace std;
const int64_t INF = (1LL << 62);
int H, W, sh, sw, gh, gw;
vector<vector<bool>> Grid(100, vector<bool>(100, 0));
vector<vector<int64_t>> Steps(100, vector<int64_t>(100, INF));
queue<pair<int, int>> Q;
int dh[] = {1, -1, 0, 0};
int dw[] = {0, 0, 1, -1};

void bfs()
{
  while (!Q.empty())
  {
    int h, w;
    tie(h, w) = Q.front();
    Q.pop();
    for (int i = 0; i < 4; i++)
    {
      int nh = h + dh[i], nw = w + dw[i];
      if (nh < 0 || nw < 0 || nh >= H || nw >= W)
        continue;
      if (!Grid.at(nh).at(nw) || Steps.at(nh).at(nw) <= Steps.at(h).at(w) + 1)
        continue;
      Steps.at(nh).at(nw) = Steps.at(h).at(w) + 1;
      Q.push({nh, nw});
    }
  }
}

int main()
{
  cin >> H >> W >> sh >> sw >> gh >> gw;
  char c;
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      cin >> c;
      if (c == '.')
        Grid.at(i).at(j) = 1;
    }
  }
  Q.push({sh - 1, sw - 1});
  Steps.at(sh - 1).at(sw - 1) = 0;
  bfs();
  cout << Steps.at(gh - 1).at(gw - 1) << endl;
}