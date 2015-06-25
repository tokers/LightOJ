/*************************************************************************
    > File Name: LightOJ1047.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年06月25日 星期四 20时30分14秒
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
 
int house[22][3];
int dp[22][3];
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        memset(dp, inf, sizeof(dp));
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d%d", &house[i][0], &house[i][1], &house[i][2]);
        }
        dp[1][0] = house[1][0];
        dp[1][1] = house[1][1];
        dp[1][2] = house[1][2];
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    if (j == k) {
                        continue;
                    }
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + house[i][j]);
                }
            }
        }
        int ans = min(min(dp[n][0], dp[n][1]), dp[n][2]);
        printf("Case %d: %d\n", icase++, ans);
    }
    return 0;
}
