/*************************************************************************
    > File Name: LightOJ1057.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年06月28日 星期日 19时03分46秒
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
 
int dp[(1 << 17) + 10][20];
 
char mat[20][20];
int T[20][20][20];
int edge[20][20];
bool vis[20][20];
int num[20][20];
int dir[8][2] = {1, 0, -1, 0, 0, 1, 0, -1, 1, -1, 1, 1, -1, 1, -1, -1};
int n, m;
 
struct Node {
    int x, y;
    int step;
 
    Node(int _x, int _y, int _step) : x(_x), y(_y), step(_step) {}
};
 
bool is_ok(int x, int y) {
    if (x < 1 || x > n || y < 1 || y > m) {
        return 0;
    }
    return !vis[x][y];
}
 
queue <Node> qu;
 
void bfs(int id, int x, int y) {
    memset(T[id], inf, sizeof(T[id]));
    memset(vis, 0, sizeof(vis));
    vis[x][y] = 1;
    while (!qu.empty()) {
        qu.pop();
    }
    qu.push(Node(x, y, 0));
    while (!qu.empty()) {
        Node now = qu.front();
        qu.pop();
        int x1 = now.x;
        int y1 = now.y;
        T[id][x1][y1] = now.step;
        if (num[x1][y1] != -1) {
            edge[id][num[x1][y1]] = now.step;
        }
        for (int i = 0; i < 8; ++i) {
            int x2 = x1 + dir[i][0];
            int y2 = y1 + dir[i][1];
            if (!is_ok(x2, y2)) {
                continue;
            }
            vis[x2][y2] = 1;
            qu.push(Node(x2, y2, now.step + 1));
        }
    }
}
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        memset(edge, inf, sizeof(edge));
        memset(num, -1, sizeof(num));
        memset(dp, inf, sizeof(dp));
        int ret = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%s", mat[i] + 1);
            for (int j = 1; j <= m; ++j) {
                if (mat[i][j] == 'x') {
                    num[i][j] = ret++;
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (mat[i][j] == 'g') {
                    num[i][j] = ret++;
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (mat[i][j] == 'x' || mat[i][j] == 'g') {
                    bfs(num[i][j], i, j);
                }
            }
        }
        for (int i = 0; i < ret; ++i) {
            edge[i][ret] = edge[ret][i] = edge[0][i];
        }
        ++ret;
        dp[1][0] = 0;
        for (int i = 1; i < (1 << ret); ++i) {
            for (int j = 0; j < ret; ++j) {
                if (dp[i][j] == inf) {
                    continue;
                }
                if (i & (1 << j)) {
                    for (int k = 0; k < ret; ++k) {
                        if ((i & (1 << k)) == 0) {
                            dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], dp[i][j] + edge[j][k]);
                        }
                    }
                }
            }
        }
        printf("Case %d: %d\n", icase++, dp[(1 << ret) - 1][ret - 1]);
    }
    return 0;
}
