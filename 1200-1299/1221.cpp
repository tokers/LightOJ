/*************************************************************************
    > File Name: LightOJ1221.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年08月25日 星期二 11时47分44秒
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
		int n, m, p;
		int u, v, w, c;
		scanf("%d%d%d", &n, &m, &p);
		memset(dp, inf, sizeof(dp));
		for (int i = 1; i <= m; ++i) {
			scanf("%d%d%d%d", &u, &v, &w, &c);
			++u, ++v;
			dp[u][v] = c * p - w;
		}
		for (int i = 1; i <= n; ++i) {
			dp[i][i] = 0;
		}
		for (int k = 1; k <= n; ++k) {
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= n; ++j) {
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
				}
			}
		}
		bool flag = 0;
		for (int i = 1; i <= n; ++i) {
			if (dp[i][i] < 0) {
				flag = 1;
				break;
			}
		}
		printf("Case %d: %s\n", icase++, flag ? "YES" : "NO");
	}
	return 0;
}
