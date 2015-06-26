/*************************************************************************
    > File Name: LightOJ1046.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年06月26日 星期五 15时52分29秒
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
 
int n, m;
bool vis[111][11][11];
int cost[111][11][11];
int id, cnt;
int can[111];
char mat[11][11];
int dir[8][2] = {1, 2, 1, -2, 2, 1, 2, -1, -1, 2, -1, -2, -2, 1, -2, -1};
struct Node {
    int x, y;
    int id;
    int rest;
    int t;
 
    Node(int _x, int _y, int _id, int _rest, int _t) {
        x = _x;
        y = _y;
        id = _id;
        rest = _rest;
        t = _t;
    }
};
 
queue <Node> qu;
 
bool judge(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) {
        return 0;
    }
    return 1;
}
 
void bfs() {
    while (!qu.empty()) {
        Node Now = qu.front();
        qu.pop();
        int x1 = Now.x;
        int y1 = Now.y;
        int t1 = Now.t;
        int rest = Now.rest;
        int id = Now.id;
        vis[id][x1][y1] = 1;
        cost[id][x1][y1] = t1;
        for (int i = 0; i < 8; ++i) {
            int x2 = x1 + dir[i][0];
            int y2 = y1 + dir[i][1];
            if (!judge(x2, y2) || vis[id][x2][y2]) {
                continue;
            }
            if (rest == 0) {
                qu.push(Node(x2, y2, id, can[id] - 1, t1 + 1));
            }
            else {
                qu.push(Node(x2, y2, id, rest - 1, t1));
            }
        }
    }
}
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        while (!qu.empty()) {
            qu.pop();
        }
        int id = 0;
        memset(vis, 0, sizeof(vis));
        memset(cost, inf, sizeof(cost));
        for (int i = 0; i < n; ++i) {
            scanf("%s", mat[i]);
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] >= '1' && mat[i][j] <= '9') {
                    qu.push(Node(i, j, ++id, 0, 0));
                    can[id] = mat[i][j] - '0';
                }
            }
        }
        bfs();
        int ans = inf;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                bool flag = 1;
                int tmp = 0;
                for (int k = 1; k <= id; ++k) {
                    if (cost[k][i][j] == inf) {
                        flag = 0;
                        break;
                    }
                    tmp += cost[k][i][j];
                }
                if (flag) {
                    ans = min(ans, tmp);
                }
            }
        }
        if (ans == inf) {
            ans = -1;
        }
        printf("Case %d: %d\n", icase++, ans);
    }
    return 0;
}
