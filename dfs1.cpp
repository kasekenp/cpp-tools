#include <bits/stdc++.h>
using namespace std;
const int MAXH = 510;
int H, W, sh, sw, gh, gw;
vector<vector<bool>> Grid(MAXH, vector<bool>(MAXH, 0));
vector<vector<int>> Steps(MAXH, vector<int>(MAXH, -1));

void dfs(int h, int w, int step)
{
  if (h < 0 || w < 0 || h >= H || w >= W)
    return;
  if (!Grid.at(h).at(w) || Steps.at(h).at(w) != -1)
    return;
  Steps.at(h).at(w) = step;
  dfs(h + 1, w, step + 1);
  dfs(h - 1, w, step + 1);
  dfs(h, w + 1, step + 1);
  dfs(h, w - 1, step + 1);
}

int main()
{
  cin >> H >> W;
  char c;
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      cin >> c;
      if (c == '#')
        continue;
      Grid.at(i).at(j) = 1;
      if (c == 's')
      {
        sh = i;
        sw = j;
      }
      if (c == 'g')
      {
        gh = i;
        gw = j;
      }
    }
  }
  dfs(sh, sw, 0);
  cout << ((Steps.at(gh).at(gw) == -1) ? "No" : "Yes") << endl;
}
