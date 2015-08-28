/*************************************************************************
    > File Name: LightOJ1326.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年08月28日 星期五 20时18分40秒
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

const int mod = 10056;
int dp[1010][1010];
int fac[1010];

int main() {
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	fac[0] = 1;
	for (int i = 1; i <= 1000; ++i) {
		fac[i] = fac[i - 1] * i % mod;
		for (int j = 1; j <= i; ++j) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] * j % mod;;
			dp[i][j] %= mod;
		}
	}
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n;
		int ans = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			ans += dp[n][i] * fac[i] % mod;
			ans %= mod;
		}
		printf("Case %d: %d\n", icase++, ans);
	}
	return 0;
}
