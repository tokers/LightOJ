/*************************************************************************
    > File Name: LightOJ1068.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年06月28日 星期日 19时37分54秒
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
 
int dp[13][100][100];
int bit[13];
int mod;
 
int dfs(int cur, int mod1, int mod2, bool flag) {
    if (cur == -1) {
        return mod1 == 0 && mod2 == 0;
    }
    if (!flag && ~dp[cur][mod1][mod2]) {
        return dp[cur][mod1][mod2];
    }
    int ans = 0;
    int end = flag ? bit[cur] : 9;
    for (int i = 0; i <= end; ++i) {
        ans += dfs(cur - 1, (mod1 * 10 + i) % mod, (mod2 + i) % mod, flag && i == end);
    }
    if (!flag) {
        dp[cur][mod1][mod2] = ans;
    }
    return ans;
}
 
int calc(int n) {
    int cnt = 0;
    while (n) {
        bit[cnt++] = n % 10;
        n /= 10;
    }
    return dfs(cnt - 1, 0, 0, 1);
}
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        int l, r;
        memset(dp, -1, sizeof(dp));
        scanf("%d%d%d", &l, &r, &mod);
        int ans = 0;
        if (mod >= 100) {
            ans = 0;
        }
        else {
            ans = calc(r) - calc(l - 1);
        }
        printf("Case %d: %d\n", icase++, ans);
    }
    return 0;
}
