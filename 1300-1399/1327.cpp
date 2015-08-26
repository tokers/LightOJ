/*************************************************************************
    > File Name: LightOJ1327.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年08月26日 星期三 12时04分27秒
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
 
LL dp[2][(1 << 15) + 10][8];
int mat[20][20];
vector <int> sta[16];
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            sta[i].clear();
            for (int j = 1; j <= n; ++j) {
                scanf("%d", &mat[i][j]);
            }
        }
        sta[0].clear();
        for (int i = 0; i < (1 << n); ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    ++cnt;
                }
            }
            sta[cnt].push_back(i);
        }
        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = 1;
        for (int i = 0; i < n; ++i) {
            int size = sta[i].size();
            for (int j = 0; j < size; ++j) {
                int s = sta[i][j];
                for (int k = 0; k < 8; ++k) {
                    if (dp[i % 2][s][k]) {
                        for (int l = 0; l < n; ++l) {
                            if ( s & (1 << l)) {
                                continue;
                            }
                            dp[1 - i % 2][s | (1 << l)][k | (1 << mat[i + 1][l + 1])] += dp[i % 2][s][k];
                        }
                    }
                }
            }
            memset(dp[i % 2], 0, sizeof(dp[i % 2]));
        }
        LL ans = dp[n % 2][(1 << n) - 1][5] + dp[n % 2][(1 << n) - 1][7];
        ans += dp[n % 2][(1 << n) - 1][2] + dp[n % 2][(1 << n) - 1][4] + dp[n % 2][(1 << n) - 1][6];
        printf("Case %d: %lld\n", icase++, ans);
    }
    return 0;
}
