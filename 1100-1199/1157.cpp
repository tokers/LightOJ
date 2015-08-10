/*************************************************************************
    > File Name: LightOJ1157.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年08月10日 星期一 13时22分10秒
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

char A[1010];
char B[1010];
int dp[1010][1010];
int LCS[1010][1010];
const int mod = 1000007;

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%s%s", A, B);
		memset(dp, 0, sizeof(dp));
		int n = strlen(A);
		int m = strlen(B);
		memset(LCS, 0, sizeof(LCS));
		for (int i = 0; i <= n; ++i) {
			dp[i][0] = 1;
		}
		for (int j = 0; j <= m; ++j) {
			dp[0][j] = 1;
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (A[i - 1] == B[j - 1]) {
					LCS[i][j] = LCS[i - 1][j - 1] + 1;
					dp[i][j] = dp[i - 1][j - 1];
					dp[i][j] %= mod;
				}
				else {
					LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
					if (LCS[i][j] == LCS[i - 1][j]) {
						dp[i][j] += dp[i - 1][j];
					}
					if (LCS[i][j] == LCS[i][j - 1]) {
						dp[i][j] += dp[i][j - 1];
					}
					if (LCS[i][j] == LCS[i - 1][j - 1]) {
						dp[i][j] -= dp[i - 1][j - 1];
					}
					dp[i][j] = (dp[i][j] % mod + mod) % mod;
				}
			}
		}
		printf("Case %d: %d\n", icase++, dp[n][m]);
	}
	return 0;
}
