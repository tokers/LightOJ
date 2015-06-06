/*************************************************************************
    > File Name: LightOJ1011.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年06月06日 星期六 10时52分57秒
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
 
int dp[20][70000];
int mat[20][20];
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                scanf("%d", &mat[i][j]);
            }
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < (1 << n); ++j) {
                int cnt = 0;
                for (int k = 0; k < n; ++k) {
                    if (j & (1 << k)) {
                        ++cnt;
                    }
                }
                if (cnt != i - 1) {
                    continue;
                }
                for (int k = 0; k < n; ++k) {
                    if (j & (1 << k)) {
                        continue;
                    }
                    dp[i][j | (1 << k)] = max(dp[i][j | (1 << k)], dp[i - 1][j] + mat[i][k + 1]);
                }
            }
        }
        printf("Case %d: %d\n", icase++, dp[n][(1 << n) - 1]);
    }
    return 0;
}
