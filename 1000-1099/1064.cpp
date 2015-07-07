/*************************************************************************
    > File Name: LightOJ1064.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年07月07日 星期二 19时02分48秒
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

ULL dp[30][200];

ULL gcd(ULL a, ULL b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n, x;
		scanf("%d%d", &n, &x);
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for (int i = 0; i < n; ++i) {
			for (int j = i; j <= 6 * i; ++j) {
				if (dp[i][j]) {
					for (int k = 1; k <= 6; ++k) {
						dp[i + 1][j + k] += dp[i][j];
					}
				}
			}
		}
		ULL ans = 0;
		for (int i = x; i <= n * 6; ++i) {
			ans += dp[n][i];
		}
		ULL all = 1;
		for (int i = 1; i <= n; ++i) {
			all *= 6;
		}
		ULL g = gcd(ans, all);
		if (ans == 0) {
			printf("Case %d: 0\n", icase++);
		}
		else if (ans == all) {
			printf("Case %d: 1\n", icase++);
		} 
		else {
			printf("Case %d: %llu/%llu\n", icase++, ans / g, all / g);
		}
	}
	return 0;
}
