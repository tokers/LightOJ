/*************************************************************************
    > File Name: LightOJ1071.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年06月29日 星期一 16时12分03秒
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

int dp[110][110][110];
int mat[110][110];
int n, m;

int DP(int x1, int y1, int x2) {
	if (~dp[x1][y1][x2]) {
		return dp[x1][y1][x2];
	}
	if (x1 == n && y1 == m) {
		return dp[x1][y1][x2] = 0;
	}
	int ans = 0;
	int y2 = x1 + y1 - x2;
	if ((x1 == n && y1 == m - 1 && x2 == n - 1 && y2 == m) || (x2 == n && y2 == m - 1 && x1 == n - 1 && y1 == m)) {
		return dp[x1][y1][x2] = DP(n, m, n) + mat[n][m];
	}
	if (x1 < n && x2 < n && x1 != x2) {
		ans = max(ans, DP(x1 + 1, y1, x2 + 1) + mat[x1 + 1][y1] + mat[x2 + 1][y2]);
	}
	if (x1 < n && y2 < m && (x1 + 1) != x2) {
		ans = max(ans, DP(x1 + 1, y1, x2) + mat[x1 + 1][y1] + mat[x2][y2 + 1]);
	}
	if (y1 < m && x2 < n && x1 != x2 + 1) {
		ans = max(ans, DP(x1, y1 + 1, x2 + 1) + mat[x1][y1 + 1] + mat[x2 + 1][y2]);
	}
	if (y1 < m && y2 < m && x1 != x2) {
		ans = max(ans, DP(x1, y1 + 1, x2) + mat[x1][y1 + 1] + mat[x2][y2 + 1]);
	}
	return dp[x1][y1][x2] = ans;
}

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				scanf("%d", &mat[i][j]);
			}
		}
		memset(dp, -1, sizeof(dp));
		printf("Case %d: %d\n", icase++, DP(1, 1, 1) + mat[1][1]);
	}
	return 0;
}
