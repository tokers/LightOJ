/*************************************************************************
    > File Name: LightOJ1228.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年09月09日 星期三 18时53分57秒
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
 
LL dp[(1 << 12) + 10][20][20];
int hate[20][20];
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        int n, k, q;
        scanf("%d%d%d", &n, &k, &q);
        memset(dp, 0, sizeof(dp));
        memset(hate, 0, sizeof(hate));
        for (int i = 0; i < n; ++i) {
            int cnt;
            scanf("%d", &cnt);
            while (cnt--) {
                int u;
                scanf("%d", &u);
                --u;
                hate[i][u] = 1;
            }
        }
        for (int i = 0; i < n; ++i) {
            dp[(1 << i)][i][0] = 1;
        }
        int cnt = 0;
        for (int i = 1; i < (1 << n); ++i) {
            cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    ++cnt;
                }
            }
            for (int j = 0; j < n; ++j) {
                if (!(i & (1 << j))) {
                    continue;
                }
                for (int c = 0; c < cnt; ++c) {
                    for (int l = 0; l < n; ++l) {
                        if (i & (1 << l)) {
                            continue;
                        }
                        dp[i | (1 << l)][l][hate[l][j] + c] += dp[i][j][c];
                    }
                }
            }
        }
        int r;
        printf("Case %d:\n", icase++);
        while (q--) {
            scanf("%d", &r);
            if (k) {
                r /= k;
            }
            else {
                r = n;
            }
            if (r > n) {
                r = n;
            }
            LL ans = 0;
            for (int i = 0; i <= r; ++i) {
                for (int j = 0; j < n; ++j) {
                    ans += dp[(1 << n) - 1][j][i];
                }
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}
