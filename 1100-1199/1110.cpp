/*************************************************************************
    > File Name: LightOJ1110.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年09月10日 星期四 09时18分24秒
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

const int N = 110;
int dp[N][N];
string f[N][N];
char A[N], B[N];

int main() {
	int t, icase = 1;
	while (~scanf("%d", &t)) {
		memset(dp, 0, sizeof(dp));
		scanf("%s%s", A, B);
		int n = strlen(A);
		int m = strlen(B);
		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j <= m; ++j) {
				f[i][j] = "";
			}
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (A[i - 1] == B[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
					f[i][j] = f[i - 1][j - 1] + A[i - 1];
				}
				else {
					if (dp[i - 1][j] > dp[i][j - 1]) {
						dp[i][j] = dp[i - 1][j];
						f[i][j] = f[i - 1][j];
					}
					else if (dp[i - 1][j] < dp[i][j - 1]) {
						dp[i][j] = dp[i][j - 1];
						f[i][j] = f[i][j - 1];
					}
					else {
						dp[i][j] = dp[i][j - 1];
						f[i][j] = min(f[i - 1][j], f[i][j - 1]);
					}
				}
			}
		}
		if (dp[n][m] == 0) {
			f[n][m] = ":(";
		}
		cout << "Case " << icase++ << ": " << f[n][m] << endl;
	}
	return 0;
}
