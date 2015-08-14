/*************************************************************************
    > File Name: LightOJ1125.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年08月14日 星期五 20时51分50秒
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

LL dp[210][15][22][22];
int Arr[210];

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n, q;
		scanf("%d%d", &n, &q);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &Arr[i]);
		}
		memset(dp, 0, sizeof(dp));
		for (int mod = 1; mod <= 20; ++mod) {
			dp[0][0][0][mod] = 1;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j <= min(10, n); ++j) {
					for (int k = 0; k < mod; ++k) {
						dp[i + 1][j][k][mod] += dp[i][j][k][mod];
						if (j + 1 <= n) {
							int x = k + Arr[i + 1];
							x = (x % mod + mod) % mod; // without this step, got WA
							dp[i + 1][j + 1][x][mod] += dp[i][j][k][mod];
						}
					}
				}
			}
		}
		int d, m;
		printf("Case %d:\n", icase++);
		while (q--) {
			scanf("%d%d", &d, &m);
			printf("%lld\n", dp[n][m][0][d]);
		}
	}
	return 0;
}
