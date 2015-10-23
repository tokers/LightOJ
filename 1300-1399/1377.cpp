/*************************************************************************
    > File Name: LightOJ1377.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015/10/21 22:46:52
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

char mat[222][222];
bool vis[222][222][2];
vector < pair <int, int> > pos;
queue < pair < pair <int, bool> , pair <int, int> > > qu;
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

int bfs(int sx, int sy, int n, int m) {
    while (!qu.empty()) {
        qu.pop();
    }
    int ans = -1;
    memset(vis, 0, sizeof(vis));
    vis[sx][sy][0] = 1;
    qu.push(make_pair(make_pair(0, 0), make_pair(sx, sy)));
    while (!qu.empty()) {
        pair <pair <int, bool>, pair <int, int> > now = qu.front();
        qu.pop();
        int x = now.second.first, y = now.second.second;
        int t = now.first.first;
        bool flag = now.first.second;
        if (mat[x][y] == 'D') {
            ans = t;
            break;
        }
        if (mat[x][y] == '*') {
            int size = pos.size();
            bool f = 0;
            for (int j = 0; j < size; ++j) {
                int xx = pos[j].first;
                int yy = pos[j].second;
                if (xx == x && yy == y) {
                    f = 1;
                    continue;
                }
                if (!vis[xx][yy][1]) {
                    vis[xx][yy][1] = 1;
                    qu.push(make_pair(make_pair(t + 1, 1), make_pair(xx, yy)));
                }
            }
            pos.clear();
            if (f) {
                pos.push_back(make_pair(x, y));
            }
            if(flag == 0) {
                continue;
            }
        }
        for (int j = 0; j < 4; ++j) {
            int xx = x + dir[j][0];
            int yy = y + dir[j][1];
            if (xx < 0 || xx >= n || yy < 0 || yy >= m || vis[xx][yy][0] || mat[xx][yy] == '#') {
                continue;
            }
            vis[xx][yy][0] = 1;
            qu.push(make_pair(make_pair(t + 1, 0), make_pair(xx, yy)));
        }
    }
    return ans;
}

int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
    int n, m;
    scanf("%d%d", &n, &m);
    int sx, sy;
    pos.clear();
    for (int i = 0; i < n; ++i) {
        scanf("%s", mat[i]);
        for (int j = 0; j < m; ++j) {
            if (mat[i][j] == 'P') {
                sx = i, sy = j;
            }
            else if (mat[i][j] == '*') {
                pos.push_back(make_pair(i, j));
            }
        }
    }
    int ans = bfs(sx, sy, n, m);
    printf("Case %d:", icase++);
    if (ans == -1) {
        printf(" impossible\n");
    }
    else {
        printf(" %d\n", ans);
    }
  }
  return 0;
}
