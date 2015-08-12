/*************************************************************************
    > File Name: LightOJ1201.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年08月12日 星期三 12时36分03秒
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
 
vector <int> tree[1010];
int dp[1010][2];
bool vis[1010];
 
void dfs(int u, int fa) {
    int size = tree[u].size();
    dp[u][1] = 1;
    vis[u] = 1;
    for (int i = 0; i < size; ++i) {
        int v = tree[u][i];
        if (v == fa) {
            continue;
        }
        dfs(v, u);
        dp[u][1] += dp[v][0];
        dp[u][0] += max(dp[v][1], dp[v][0]);
    }
}
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) {
            tree[i].clear();
            vis[i] = 0;
            dp[i][1] = dp[i][0] = 0;
        }
        int u, v;
        for (int i = 1; i <= m; ++i) {
            scanf("%d%d", &u, &v);
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (!vis[i]) {
                dfs(i, -1);
                ans += max(dp[i][0], dp[i][1]);
            }
        }
        printf("Case %d: %d\n", icase++, ans);
    }
    return 0;
}
