/*************************************************************************
    > File Name: LightOJ1019.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年06月09日 星期二 11时54分30秒
 ************************************************************************/
 
#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <map>
#include <bitset>
#include <set>
#include <vector>
 
using namespace std;
 
const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;
const double eps = 1e-15;
typedef long long LL;
typedef pair <int, int> PLL;
 
int dp[110][110];
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        memset(dp, inf, sizeof(dp));
        for (int i = 1; i <= n; ++i) {
            dp[i][i] = 0;
        }
        int u, v, w;
        for (int i = 1; i <= m; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            dp[u][v] = dp[v][u] = min(dp[u][v], w);
        }
        for (int k = 1; k <= n; ++k) {
            for (int i = 1; i <= n; ++i) {
                for(int j = 1; j <= n; ++j) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
        printf("Case %d: ", icase++);
        if (dp[1][n] == inf) {
            printf("Impossible\n");
        }
        else {
            printf("%d\n", dp[1][n]);
        }
    }
    return 0;
}
