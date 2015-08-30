/*************************************************************************
    > File Name: LightOJ1173.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年08月30日 星期日 20时34分03秒
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
 
ULL dp[55][55][2];
 
int main() {
    memset(dp, 0, sizeof(dp));
    dp[1][1][0] = dp[1][1][1] = 1;
    for (int i = 2; i <= 50; ++i) {
        for (int j = 1; j <= i; ++j) {
            for (int k = j; k <= i - 1; ++k) {
                dp[i][j][0] += dp[i - 1][k][1];
            }
            for (int k = 1; k < j; ++k) {
                dp[i][j][1] += dp[i - 1][k][0];
            }
        }
    }
    int t, n, m, icase = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        printf("Case %d: ", icase++);
        ULL ans = 0;
        if(n == 1 && m == 1) {
            printf("1\n");
            continue;
        }
        if (n == 2 && m == 1) {
            printf("1\n");
            continue;
        }
        if (m != 1) {
            for (int i = 1; i < m; ++i) {
                ans += dp[n - 1][i][0];
            }
        }
        else {
            ans = dp[n - 1][2][1];
        }
        printf("%llu\n", ans);
    }
    return 0;
}
