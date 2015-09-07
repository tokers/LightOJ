/*************************************************************************
    > File Name: LightOJ1283.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年09月07日 星期一 19时45分32秒
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
 
int dp[110][110][110];
int val[110];
int xis[110];
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &val[i]);
            xis[i] = val[i];
        }
        sort(xis + 1, xis + 1 + n);
        int cnt = unique(xis + 1, xis + 1 + n) - xis - 1;
        memset(dp, -1, sizeof(dp));
        dp[0][0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            val[i] = lower_bound(xis + 1, xis + cnt + 1, val[i]) - xis;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= cnt; ++j) {
                for (int k = 0; k <= cnt; ++k) {
                    if (dp[i][j][k] != -1) {
                        if (j == 0 || k == 0) {
                            if (j == 0 && k == 0) {
                                dp[i + 1][val[i + 1]][k] = max(dp[i + 1][val[i + 1]][k], dp[i][j][k] + 1);
                                dp[i + 1][j][val[i + 1]] = max(dp[i + 1][j][val[i + 1]], dp[i][j][k] + 1);
                            }
                            else if (j == 0 && val[i + 1] <= k) {
                                dp[i + 1][val[i + 1]][k] = max(dp[i + 1][val[i + 1]][k], dp[i][j][k] + 1);
                                dp[i + 1][j][val[i + 1]] = max(dp[i + 1][j][val[i + 1]], dp[i][j][k] + 1);
                            }
                            else if (k == 0 && val[i + 1] >= j) {
                                dp[i + 1][j][val[i + 1]] = max(dp[i + 1][j][val[i + 1]], dp[i][j][k] + 1);
                                dp[i + 1][val[i + 1]][k] = max(dp[i + 1][val[i + 1]][k], dp[i][j][k] + 1);
                            }
                        }
                        else if ((val[i + 1] >= j && val[i + 1] <= k)) {
                            dp[i + 1][val[i + 1]][k] = max(dp[i + 1][val[i + 1]][k], dp[i][j][k] + 1);
                            dp[i + 1][j][val[i + 1]] = max(dp[i + 1][j][val[i + 1]], dp[i][j][k] + 1);
                        }
                        dp[i + 1][j][k] = max(dp[i][j][k], dp[i + 1][j][k]);
                    }
                }
            }
        }
        for (int j = 0; j <= cnt; ++j) {
            for (int k = 0; k <= cnt; ++k) {
                ans = max(ans, dp[n][j][k]);
            }
        }
        printf("Case %d: %d\n", icase++, ans);
    }
    return 0;
}
