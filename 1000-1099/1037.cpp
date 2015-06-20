/*************************************************************************
    > File Name: LightOJ1037.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年06月20日 星期六 12时54分58秒
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

int dp[(1 << 15) + 10];
char mat[20][20];
int hel[20];

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &hel[i]);
		}
		for (int i = 0; i < n; ++i) {
			scanf("%s", mat[i]);
		}
		memset(dp, inf, sizeof(dp));
		dp[0] = 0;
		for (int i = 0; i < (1 << n); ++i) {
			for (int j = 0; j < n; ++j) {
				if (i & (1 << j)) {
					continue;
				}
				dp[i | (1 << j)] = min(dp[i] + hel[j], dp[i | (1 << j)]);
				for (int k = 0; k < n; ++k) {
					if ((i & (1 << k)) && mat[k][j] != '0') {
						dp[i | (1 << j)] = min(dp[i | (1 << j)], dp[i] + hel[j] / (mat[k][j] - '0') + (hel[j] % (mat[k][j] - '0') ? 1 : 0));
					}
				}
			}
		}
		printf("Case %d: %d\n", icase++, dp[(1 << n) - 1]);
	}
	return 0;
}
