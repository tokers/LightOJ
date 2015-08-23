/*************************************************************************
    > File Name: LightOJ1231.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年08月23日 星期日 18时53分47秒
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
int A[55];
int C[55];
int dp[55][1010];

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n, k;
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &A[i]);
		}
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &C[i]);
		}
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= k; ++j) {
				for (int l = 0; l <= C[i + 1]; ++l) {
					if (l * A[i + 1] + j <= k) {
						dp[i + 1][l * A[i + 1] + j] += dp[i][j];
						dp[i + 1][l * A[i + 1] + j] %= mod;
					}
				}
			}
		}
		printf("Case %d: %d\n", icase++, dp[n][k]);
	}
	return 0;
}
