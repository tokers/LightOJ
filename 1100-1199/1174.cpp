/*************************************************************************
    > File Name: LightOJ1174.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年08月24日 星期一 13时34分48秒
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

int dp[110][110];
int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		memset(dp, inf, sizeof(dp));
		for (int i = 0; i < n; ++i) {
			dp[i][i] = 0;
		}
		int u, v;
		for (int i = 1; i <= m; ++i) {
			scanf("%d%d", &u, &v);
			dp[u][v] = 1;
			dp[v][u] = 1;
		}
		for (int k = 0; k < n; ++k) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
				}
			}
		}
		int s, d;
		int ans = 0;
		scanf("%d%d", &s, &d);
		for (int i = 0; i < n; ++i) {
			ans = max(ans, dp[s][i] + dp[i][d]);
		}
		printf("Case %d: %d\n", icase++, ans);
	}
	return 0;
}
