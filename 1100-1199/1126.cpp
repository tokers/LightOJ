/*************************************************************************
    > File Name: LightOJ1126.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年08月10日 星期一 12时49分21秒
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

int dp[2][1001000];
int val[55];
int sum[55];

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		memset(dp, -1, sizeof(dp));
		sum[0] = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &val[i]);
			sum[i] = sum[i - 1] + val[i];
		}
		int offset = sum[n];
		int cnt = 0;
		dp[0][offset] = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = -sum[i] + offset; j <= sum[i] + offset; ++j) {
				if (j >= offset && sum[n] - sum[i] < j - offset) {
					break;
				}
				if (j < offset && sum[n] - sum[i] < -(j - offset)) {
					continue;
				}
				if (dp[i & 1][j] == -1) {
					continue;
				}
				dp[1 - (i & 1)][j] = max(dp[1 - (i & 1)][j], dp[i & 1][j]);
				dp[1 - (i & 1)][j + val[i + 1]] = max(dp[1 - (i & 1)][j + val[i + 1]], dp[i & 1][j] + val[i + 1]);
				dp[1 - (i & 1)][j - val[i + 1]] = max(dp[1 - (i & 1)][j - val[i + 1]], dp[i & 1][j]);
			}
			memset(dp[i & 1], -1, sizeof(dp[i & 1]));
		}
		if (dp[n & 1][offset] == 0) {
			printf("Case %d: impossible\n", icase++);
		}
		else {
			printf("Case %d: %d\n", icase++, dp[n & 1][offset]);
		}
	}
	return 0;
}
