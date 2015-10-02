/*************************************************************************
    > File Name: LightOJ1223.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年10月02日 星期五 15时48分10秒
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
 
LL dp[110][110][110];
 
int main() {
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= 100; ++i) {
        for (int j = i; j <= 100; ++j) {
            dp[1][i][j] = (LL)(i + j) * (j - i + 1) / 2;
        }
    }
    for (int i = 2; i <= 100; ++i) {
        for (int j = 100; j >= 1; --j) {
            for (int k = j; k <= 100; ++k) {
                LL &res = dp[i][j][k];
                res = INF;
                for (int u = j; u <= k; ++u) {
                    res = min(res, u + max(dp[i - 1][j][u - 1], dp[i][u + 1][k]));
                }
            }
        }
    }
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        int k, m;
        scanf("%d%d", &k, &m);
        printf("Case %d: %lld\n", icase++, dp[k][1][m]);
    }
    return 0;
}
