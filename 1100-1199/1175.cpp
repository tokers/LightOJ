/*************************************************************************
    > File Name: LightOJ1175.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015/10/20 20:47:22
 ************************************************************************/
 
#include <iostream>
#include <fstream>
#include <cstring>
#include <climits>
#include <deque>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>
#include <string>
#include <vector>
#include <cstdio>
#include <bitset>
#include <functional>
#include <algorithm>
 
using namespace std;
 
const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;
const double eps = 1e-15;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int, int> PLL;
const LL INF = (1LL << 60);
 
char mat[333][333];
int fired[333][333];
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
int n, m;
 
void bfs1(int sx, int sy) {
  fired[sx][sy] = 0;
  queue < pair <int, pair <int, int> > > qu;
  qu.push(make_pair(0, make_pair(sx, sy)));
  while (!qu.empty()) {
    pair <int, pair <int, int> > now = qu.front();
    qu.pop();
    int x1 = now.second.first;
    int y1 = now.second.second;
    int t1 = now.first;
    for (int i = 0; i < 4; ++i) {
      int x2 = x1 + dir[i][0];
      int y2 = y1 + dir[i][1];
      if (x2 >= 0 && x2 < n && y2 >= 0 && y2 < m && mat[x2][y2] != '#') {
        if (fired[x2][y2] > t1 + 1) {
          qu.push(make_pair(t1 + 1, make_pair(x2, y2)));
          fired[x2][y2] = t1 + 1;
        }
      }
    }
  }
}
 
bool vis[333][333];
 
int bfs2(int sx, int sy) {
  memset(vis, 0, sizeof(vis));
  vis[sx][sy] = 1;
  queue < pair <int, pair <int, int> > > qu;
  qu.push(make_pair(0, make_pair(sx, sy)));
  int ans = -1;
  while (!qu.empty()) {
        pair <int, pair <int, int> > now = qu.front();
        qu.pop();
        int x1 = now.second.first;
        int y1 = now.second.second;
        int t1 = now.first;
        for (int i = 0; i < 4; ++i) {
          int x2 = x1 + dir[i][0];
          int y2 = y1 + dir[i][1];
          if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= m) {
            ans = t1 + 1;
            break;
          }
          if (mat[x2][y2] == '#' || vis[x2][y2] || t1 + 1 >= fired[x2][y2]) {
            continue;
          }
          vis[x2][y2] = 1;
          qu.push(make_pair(t1 + 1, make_pair(x2, y2)));
        }
        if (ans != -1) {
          break;
        }
  }
  return ans;
}
 
int main() {
  int t, icase = 1;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    memset(fired, inf, sizeof(fired));
    for (int i = 0; i < n; ++i) {
      scanf("%s", mat[i]);
    }
    int sx, sy;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (mat[i][j] == 'F') {
          bfs1(i, j);
        }
        else if (mat[i][j] == 'J') {
          sx = i;
          sy = j;
        }
      }
    }
    int ans = bfs2(sx, sy);
    printf("Case %d: ", icase++);
    if (ans == -1) {
      printf("IMPOSSIBLE\n");
    }
    else {
      printf("%d\n", ans);
    }
  }
  return 0;
}
