/*************************************************************************
    > File Name: LightOJ1252.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年09月16日 星期三 14时47分11秒
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
 
const int N = 110;
int dp[N][N][N];
vector <PLL> edge[N];
int sz[N];
int n, k;
 
void dfs(int u, int fa) {
    sz[u] = 0;
    int size = edge[u].size();
    for (int i = 0; i < size; ++i) {
        int v = edge[u][i].first;
        if (v == fa) {
            continue;
        }
        ++sz[u];
        dfs(v, u);
    }
    dp[u][0][0] = 1;
    int now = 0;
    for (int i = 0; i < size; ++i) {
        int v = edge[u][i].first;
        int w = edge[u][i].second;
        if (v == fa) {
            continue;
        }
        ++now;
        for (int j = 0; j <= k; ++j) {
            for (int l = 0; l <= k; ++l) {
                dp[u][now][j] = min(dp[u][now][j], dp[u][now - 1][j] + dp[v][sz[v]][l]);
                if (j - w - l >= 0) {
                    dp[u][now][j] = min(dp[u][now][j], dp[u][now - 1][j - w - l] + dp[v][sz[v]][l] - 1);
                }
            }
        }
    }
}
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; ++i) {
            edge[i].clear();
        }
        memset(dp, inf, sizeof(dp));
        int u, v, w;
        for (int i = 1; i <= n - 1; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            edge[u].push_back(make_pair(v, w));
            edge[v].push_back(make_pair(u, w));
        }
        dfs(1, -1);
        int ans = inf;
        for (int i = 0; i <= k; ++i) {
            ans = min(ans, dp[1][sz[1]][i]);
        }
        printf("Case %d: %d\n", icase++, ans);
    }
    return 0;
}
