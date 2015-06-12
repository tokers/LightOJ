/*************************************************************************
    > File Name: LightOJ1031.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年06月12日 星期五 12时46分32秒
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
 
int dp[110][110][2];
int Arr[110];
int sum[110];
int n;
 
int dfs(int l, int r, int flag) {
    if (l > r) {
        return dp[l][r][flag] = 0;
    }
    if (dp[l][r][flag] != -inf) {
        return dp[l][r][flag];
    }
    int ans = -inf;
    if (flag) {
        ans = inf;
    }
    for (int i = l; i <= r; ++i) {
        int getS = sum[i] - sum[l - 1];
        if (!flag) {
            ans = max(ans, dfs(i + 1, r, 1) + getS);
        }
        else {
            ans = min(ans, dfs(i + 1, r, 0) - getS);
        }
    }
    for (int i = r; i >= l; --i) {
        int getS = sum[r] - sum[i - 1];
        if (!flag) {
            ans = max(ans, dfs(l, i - 1, 1) + getS);
        }
        else {
            ans = min(ans, dfs(l, i - 1, 0) - getS);
        }
    }
    return dp[l][r][flag] = ans;
}
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        sum[0] = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &Arr[i]);
            sum[i] = sum[i - 1] + Arr[i];
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j][0] = dp[i][j][1] = -inf;
            }
        }
        printf("Case %d: %d\n", icase++, dfs(1, n, 0));
    }
    return 0;
}
