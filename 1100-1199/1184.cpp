/*************************************************************************
    > File Name: LightOJ1184.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年09月07日 星期一 12时48分28秒
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
 
int un, vn;
bool edge[55][55];
bool vis[55];
int match[55];
 
bool dfs(int u) {
    for (int v = 1; v <= vn; ++v) {
        if (edge[u][v] && !vis[v]) {
            vis[v] = 1;
            if (match[v] == -1 || dfs(match[v])) {
                match[v] = u;
                return 1;
            }
        }
    }
    return 0;
}
 
int hungry() {
    memset(match, -1, sizeof(match));
    int ans = 0;
    for (int i = 1; i <= un; ++i) {
        memset(vis, 0, sizeof(vis));
        if (dfs(i)) {
            ++ans;
        }
    }
    return ans;
}
 
pair < pair<int, int>, int > H[2][55];
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &un, &vn);
        memset(edge, 0, sizeof(edge));
        for (int i = 1; i <= un; ++i) {
            scanf("%d%d%d", &H[0][i].first.first, &H[0][i].first.second, &H[0][i].second);
        }
        for (int i = 1; i <= vn; ++i) {
            scanf("%d%d%d", &H[1][i].first.first, &H[1][i].first.second, &H[1][i].second);
        }
        for (int i = 1; i <= un; ++i) {
            for (int j = 1; j <= vn; ++j) {
                if (H[0][i].second != H[1][j].second) {
                    continue;
                }
                if (abs(H[0][i].first.first - H[1][j].first.first) > 12) {
                    continue;
                }
                if (abs(H[0][i].first.second - H[1][j].first.second) > 5) {
                    continue;
                }
                edge[i][j] = 1;
            }
        }
        printf("Case %d: %d\n", icase++, hungry());
    }
    return 0;
}
