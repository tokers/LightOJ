/*************************************************************************
    > File Name: LightOJ1191.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年08月10日 星期一 21时05分17秒
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

LL dp[55][55];

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n, k, m;
		scanf("%d%d%d", &n, &k, &m);
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= min(i, k); ++j) {
				for (int l = i; l >= max(1, i - m + 1); --l) {
					dp[i][j] += dp[l - 1][j - 1];
				}
			}
		}
		LL ans = dp[n][k];
		printf("Case %d: %lld\n", icase++, ans);
	}
	return 0;
}
