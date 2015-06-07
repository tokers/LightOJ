/*************************************************************************
    > File Name: LightOJ1013.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年06月07日 星期日 21时41分25秒
 ************************************************************************/

#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <map>
#include <bitset>
#include <set>
#include <vector>

using namespace std;

const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;
const double eps = 1e-15;
typedef long long LL;
typedef pair <int, int> PLL;

string A, B;
LL dp[50][50];
int f[50][50];

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		cin >> A >> B;
		int n = A.length();
		int m = B.length();
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		memset(f, inf, sizeof(f));
		f[0][0] = 0;
		for (int i = 1; i <= n; ++i) {
			f[i][0] = i;
			dp[i][0] = 1;
		}
		for (int j = 1; j <= m; ++j) {
			f[0][j] = j;
			dp[0][j] = 1;
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (f[i][j] > f[i - 1][j] + 1) {
					f[i][j] = f[i - 1][j] + 1;
				}
				if (f[i][j] > f[i][j - 1] + 1) {
					f[i][j] = f[i][j - 1] + 1;
				}
				if (A[i - 1] == B[j - 1]) {
					if (f[i][j] > f[i - 1][j - 1] + 1) {
						f[i][j] = f[i - 1][j - 1] + 1;
					}
				}
				if (f[i][j] == f[i - 1][j] + 1 && A[i - 1] != B[j - 1]) {
					dp[i][j] += dp[i - 1][j];
				}
				if (f[i][j] == f[i][j - 1] + 1 && A[i - 1] != B[j - 1]) {
					dp[i][j] += dp[i][j - 1];
				}
				if (A[i - 1] == B[j - 1] && f[i][j] == f[i - 1][j - 1] + 1) {
					dp[i][j] += dp[i - 1][j - 1];
				}
				
			}
		}
		printf("Case %d: %d %lld\n", icase++, f[n][m], dp[n][m]);
	}
}
