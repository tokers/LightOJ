/*************************************************************************
    > File Name: LightOJ1018.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年06月25日 星期四 21时32分29秒
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
 
int sta[20][20];
int dp[(1 << 16) + 10];
PLL po[20];
int n;
 
bool judge(int i, int j, int k) {
    int x1 = po[i].first;
    int y1 = po[i].second;
    int x2 = po[j].first;
    int y2 = po[j].second;
    int x3 = po[k].first;
    int y3 = po[k].second;
    return (x2 - x1)* (y3 - y1) == (x3 - x1) * (y2 - y1);
}
 
int dfs(int now) {
    if (dp[now] != inf) {
        return dp[now];
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (now & (1 << i)) {
            ++cnt;
        }
    }
    if (cnt == 0) {
        return dp[now] = 0;
    }
    if (cnt <= 2) {
        return dp[now] = 1;
    }
    for (int i = 0; i < n; ++i) {
        if (now & (1 << i)) {
            for (int j = i + 1; j < n; ++j) {
                if (now & (1 << j)) {
                    dp[now] = min(dp[now], dfs(now - (now & sta[i][j])) + 1);
                }
            }
            break;
        }
    }
    return dp[now];
}
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &po[i].first, &po[i].second);
        }
        memset(sta, 0, sizeof(sta));
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (judge(i, j , k)) {
                        sta[i][j] |= (1 << k);
                    }
                }
            }
        }
        memset(dp, inf, sizeof(dp));
        printf("Case %d: %d\n", icase++, dfs((1 << n) - 1));
    }
    return 0;
}
