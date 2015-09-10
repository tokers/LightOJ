/*************************************************************************
    > File Name: LightOJ1119.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年09月10日 星期四 21时01分03秒
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

int dp[(1 << 14) + 10];
int mat[15][15];

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				scanf("%d", &mat[i][j]);
			}
		}
		memset(dp, inf, sizeof(dp));
		dp[0] = 0;
		for (int i = 0; i < (1 << n); ++i) {
			for (int j = 0; j < n; ++j) {
				if (i & (1 << j)) {
					continue;
				}
				int res = mat[j][j];
				for (int k = 0; k < n; ++k) {
					if (k == j || !(i & (1 << k))) {
						continue;
					}
					res += mat[j][k];
				}
				dp[i | (1 << j)] = min(dp[i | (1 << j)], dp[i] + res);
			}
		}
		printf("Case %d: %d\n", icase++, dp[(1 << n) - 1]);
	}
	return 0;
}
