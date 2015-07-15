/*************************************************************************
    > File Name: LightOJ1105.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年07月15日 星期三 18时14分38秒
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
 
LL dp[80][2];
int bit[80];
 
LL dfs(int cur, int e, bool flag) {
    if (cur == -1) {
        return 1;
    }
    if (~dp[cur][e] && !flag) {
        return dp[cur][e];
    }
    int end = flag ? bit[cur] : 1;
    int ans = 0;
    for (int i = 0; i <= end; ++i) {
        if (e == 1 && i == 1) {
            continue;
        }
        ans += dfs(cur - 1, i, flag && (i == end));
    }
    if (!flag) {
        dp[cur][e] = ans;
    }
    return ans;
}
 
LL calc(LL n) {
    int cnt = 0;
    while (n) {
        bit[cnt++] = n % 2;
        n /= 2;
    }
    return dfs(cnt - 1, 0, 1) - 1;
}
 
int main() {
    int t, icase = 1;
    memset(dp, -1, sizeof(dp));
    scanf("%d", &t);
    for (int i = 1; i <= 20; ++i) {
        int ans = calc(i);
    }
    while (t--) {
        int n;
        scanf("%d", &n);
        LL l = 1, r = (1LL << 45), mid;
        LL ans;
        while (l <= r) {
            mid = (l + r) >> 1;
            int sum = calc(mid);
            if (sum >= n) {
                ans =  mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        int cnt = 0;
        while (ans) {
            bit[cnt++] = ans % 2;
            ans /= 2;
        }
        printf("Case %d: ", icase++);
        for (int i = cnt - 1; i >= 0; --i) {
            printf("%d", bit[i]);
        }
        printf("\n");
    }
    return 0;
}
