/*************************************************************************
    > File Name: LightOJ1004.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年06月03日 星期三 10时41分43秒
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
 
int n;
int mat[250][250];
int dp[250][250];
 
int dfs(int row, int col) {
    if (dp[row][col] != -1) {
        return dp[row][col];
    }
    int ans = 0;
    if (row < n) {
        ans = dfs(row + 1, col) + mat[row + 1][col];
        ans = max(ans, dfs(row + 1, col + 1) + mat[row + 1][col + 1]);
    }
    else {
        if (col <= 2 * n - row) {
            ans = dfs(row + 1, col) + mat[row + 1][col];
        }
        if (col > 1) {
            ans = max(ans, dfs(row + 1, col - 1) + mat[row + 1][col - 1]);
        }
    }
    return dp[row][col] = ans;
}
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        memset(dp, -1, sizeof(dp));
        memset(mat, 0, sizeof(mat));
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                scanf("%d", &mat[i][j]);
            }
        }
        for (int i = n + 1; i <= 2 * n - 1; ++i) {
            for (int j = 1; j <= 2 * n - i; ++j) {
                scanf("%d", &mat[i][j]);
            }
        }
        dp[2 * n - 1][1] = 0;
        printf("Case %d: %d\n", icase++, dfs(1, 1) + mat[1][1]);
    }
    return 0;
}
