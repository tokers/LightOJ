/*************************************************************************
    > File Name: LightOJ1193.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年08月24日 星期一 21时44分44秒
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
 
const int mod = 100000007;
int sum[15010];
int pre[15010];
int tmpsum[15010];
int tmppre[15010];
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        int n, k, s;
        scanf("%d%d%d", &n, &k, &s);
        memset(sum, 0, sizeof(sum));
        memset(pre, 0, sizeof(pre));
        memset(tmpsum, 0, sizeof(tmpsum));
        memset(tmppre, 0, sizeof(tmppre));
        for (int i = 1; i <= k; ++i) {
            if (i > s) {
                break;
            }
            sum[i] = sum[i - 1] + i;
            pre[i] = pre[i - 1] + (LL)i * (s - i);
            sum[i] %= mod;
            pre[i] %= mod;
        }
        for (int i = k + 1; i <= s; ++i) {
            pre[i] = pre[i - 1];
            sum[i] = sum[i - 1];
        }
        int ans = 0;
        if (n == 1) {
            ans = s;
        }
        for (int i = 2; i <= n; ++i) {
            for (int j = i; j <= min(i * k, s); ++j) {
                int res = pre[j - 1];
                int res2 = sum[j - 1];
                if (j - k - 1 > 0) {
                    res2 -= sum[j - k - 1];
                    res2 = (res2 % mod + mod) % mod;
                    res -= pre[j - k - 1];
                    res = (res % mod + mod) % mod;
                }
                res -= (LL)res2 * (s - j) % mod;
                res = (res % mod + mod) % mod;
                tmpsum[j] = res;
                tmppre[j] = (LL)(s - j) * res % mod;
                if (i == n && j == s) {
                    ans = res;
                    break;
                }
            }
            for (int j = 1; j <= s; ++j) {
                sum[j] = tmpsum[j];
                pre[j] = tmppre[j];
                tmpsum[j] = tmppre[j] = 0;
                sum[j] += sum[j - 1];
                pre[j] += pre[j - 1];
                sum[j] %= mod;
                pre[j] %= mod;
            }  
        }
        printf("Case %d: %d\n", icase++, ans);
    }
    return 0;
}
