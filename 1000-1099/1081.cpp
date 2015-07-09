/*************************************************************************
    > File Name: LightOJ1081.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年07月09日 星期四 21时34分12秒
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

int dp[510][510][10];
int LOG[510];
int mat[510][510];

void initRMQ(int n) {
	LOG[0] = -1;
	for (int i = 1; i <= 500; ++i) {
		LOG[i] = (i & (i - 1)) ? LOG[i - 1] : LOG[i - 1] + 1;
	}
	for (int i = 1; i <= n;++i) {
		for (int j = 1; j <= n; ++j) {
			dp[i][j][0] = mat[i][j];
		}
	}
	for (int k = 1; k <= LOG[n]; ++k) {
		for (int i = 1; i + (1 << k) - 1 <= n; ++i) {
			for (int j = 1; j + (1 << k) - 1 <= n; ++j) {
				dp[i][j][k] = max(dp[i][j][k - 1], dp[i][j + (1 << (k - 1))][k - 1]);
				dp[i][j][k] = max(dp[i][j][k], dp[i + (1 << (k - 1))][j][k - 1]);
				dp[i][j][k] = max(dp[i][j][k], dp[i + (1 << (k - 1))][j + (1 << (k - 1))][k - 1]);
			}
		}
	}
}

int ST(int x1, int y1, int x2, int y2) {
	int k = LOG[x2 - x1 + 1];
    int ans = dp[x1][y1][k];
	ans = max(ans, dp[x2 - (1 << k) + 1][y1][k]);
	ans = max(ans, dp[x1][y2 - (1 << k) + 1][k]);
	ans = max(ans, dp[x2 - (1 << k) + 1][y2 - (1 << k) + 1][k]);
	return ans;
}

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				scanf("%d", &mat[i][j]);
			}
		}
		initRMQ(n);
		printf("Case %d:\n", icase++);
		int x, y, s;
		while (m--) {
			scanf("%d%d%d", &x, &y, &s);
			printf("%d\n", ST(x, y, x + s - 1, y + s - 1));
		}
	}
	return 0;
}
