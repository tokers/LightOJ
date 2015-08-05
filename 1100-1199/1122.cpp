/*************************************************************************
    > File Name: LightOJ1122.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年08月05日 星期三 22时13分34秒
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

int S[15];
int dp[15][15];

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int m, n;
		scanf("%d%d", &m, &n);
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= m; ++i) {
			scanf("%d", &S[i]);
			dp[1][S[i]] = 1;
		}
		for (int i = 2; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				for (int k = 1; k <= m; ++k) {
					if (abs(S[j] - S[k]) <= 2) {
						dp[i][S[j]] += dp[i - 1][S[k]];
					}
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= m; ++i) {
			ans += dp[n][S[i]];
		}
		printf("Case %d: %d\n", icase++, ans);
	}
	return 0;
}
