/*************************************************************************
    > File Name: LightOJ1066.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年06月29日 星期一 15时36分30秒
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
 
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
struct node {
    int x, y;
    int step;
    node(int _x, int _y, int _step) : x(_x), y(_y), step(_step) {}
};
 
bool vis[15][15];
queue <node> qu;
char mat[15][15];
int n;
int sx, sy;
 
bool judge(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= n) {
        return 0;
    }
    return 1;
}
 
int bfs(char c, int x1, int y1) {
    while (!qu.empty()) {
        qu.pop();
    }
    memset(vis, 0, sizeof(vis));
    vis[x1][y1] = 1;
    mat[x1][y1] = '.';
    qu.push(node(x1, y1, 0));
    while (!qu.empty()) {
        node now = qu.front();
        qu.pop();
        int x1 = now.x;
        int y1 = now.y;
        int t = now.step;
        if (mat[x1][y1] == c) {
            sx = x1;
            sy = y1;
            return t;
        }
        for (int i = 0; i < 4; ++i) {
            int x2 = x1 + dir[i][0];
            int y2 = y1 + dir[i][1];
            if (!judge(x2, y2) || vis[x2][y2]) {
                continue;
            }
            if (mat[x2][y2] == '#' || (mat[x2][y2] >= 'A' && mat[x2][y2] <= 'Z' && mat[x2][y2] != c)) {
                continue;
            }
            vis[x2][y2] = 1;
            qu.push(node(x2, y2, t + 1));
        }
    }
    return -1;
}
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int maxs = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%s", mat[i]);
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 'A') {
                    sx = i;
                    sy = j;
                }
                if (mat[i][j] >= 'A' && mat[i][j] <= 'Z') {
                    maxs = max(maxs, mat[i][j] - 'A');
                }
             }
        }
        bool flag = 1;
        int ans = 0;
        for (int i = 1; i <= maxs; ++i) {
            int tmp = bfs(i + 'A', sx, sy);
            if (tmp == -1) {
                flag = 0;
                break;
            }
            ans += tmp;
        }
        if (flag) {
            printf("Case %d: %d\n", icase++, ans);
        }
        else {
            printf("Case %d: Impossible\n", icase++);
        }
    }
    return 0;
}
