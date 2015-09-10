/*************************************************************************
    > File Name: LightOJ1264.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年09月10日 星期四 09时31分48秒
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
 
int dp[(1 << 14) + 10];
int mat[16][16];
int val[(1 << 14) + 10];
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        memset(dp, inf, sizeof(dp));
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &mat[i][j]);
            }
        }
        for (int i = 0; i < (1 << n); ++i) {
            val[i] = 0;
            for (int j = 0; j < n; ++j) {
                if (!(i & (1 << j))) {
                    continue;
                }
                for (int k = 0; k < n; ++k) {
                    if (i & (1 << k)) {
                        val[i] += mat[j][k];
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 1; i < (1 << n); ++i) {
            for (int j = i; j > 0; j = (j - 1) & i) {
                    dp[i] = min(dp[i], dp[i - j] + val[j]);
            }
            ans = min(ans, dp[i]);
        }
        printf("Case %d: %d\n", icase++, ans);
    }
    return 0;
}
