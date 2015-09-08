/*************************************************************************
    > File Name: LightOJ1205.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年09月08日 星期二 18时18分56秒
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
 
int bit[30];
int cnt;
int use[30];
LL dp[30][30][2];
 
LL dfs(int s, int now, bool ok, bool flag) {
    if(now == -1) {
        return ok;
    }
    if (!flag && ~dp[s][now][ok]) {
        return dp[s][now][ok];
    }
    LL res = 0;
    int end = flag ? bit[now] : 9;
    for (int i = 0; i <= end; ++i) {
        use[now] = i;
        if (i == 0 && now == s) {
            res += dfs(s - 1, now - 1, ok, flag && (i == end));
        }
        else if (now < (s + 1) / 2 && ok) {
            res += dfs(s, now - 1, ok && (i == use[s - now]), flag && i == end);
        }
        else {
            res += dfs(s, now - 1, ok, flag && i == end);
        }
    }
    if (!flag) {
        dp[s][now][ok] = res;
    }
    return res;
}
 
LL calc(LL n) {
    cnt = 0;
    while(n) {
        bit[cnt++] = n % 10;
        n /= 10;
    }
    return dfs(cnt - 1, cnt - 1, 1, 1);
}
 
int main() {
    memset(dp, -1, sizeof(dp));
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        LL a, b;
        scanf("%lld%lld", &a, &b);
        if (a > b) {
            swap(a, b);
        }
        LL ans = calc(b);
        if (a) {
            ans -= calc(a - 1);
        }
        printf("Case %d: %lld\n", icase++, ans);
    }
    return 0;
}
