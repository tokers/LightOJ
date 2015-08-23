/*************************************************************************
    > File Name: LightOJ1233.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年08月23日 星期日 19时31分10秒
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

int dp[100110];
int A[110], C[110];

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &A[i]);
		}
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &C[i]);
		}
		memset(dp, -1, sizeof(dp));
		dp[0] = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= m; ++j) {
				if (dp[j] >= 0) {
					dp[j] = C[i + 1];
				}
				else {
					if (j < A[i + 1] || dp[j - A[i + 1]] <= 0) {
						dp[j] = -1;
					}
					else {
						dp[j] = dp[j - A[i + 1]] - 1;
					}
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= m; ++i) {
			if (dp[i] >= 0) {
				++ans;
			}
		}
		printf("Case %d: %d\n", icase++, ans);
	}
	return 0;
}
