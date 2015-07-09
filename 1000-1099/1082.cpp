/*************************************************************************
    > File Name: LightOJ1082.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年07月09日 星期四 16时29分15秒
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

const int N = 100100;
int dp[N][20];
int LOG[N];

int main() {
	int t, icase = 1;
	LOG[0] = -1;
	for (int i = 1; i <= 100000; ++i) {
		LOG[i] = (i & (i - 1)) ? LOG[i - 1] : LOG[i - 1] + 1;
	}
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &dp[i][0]);
		}
		for (int j = 1; j <= LOG[n]; ++j) {
			for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
				dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
			}
		}
		printf("Case %d:\n", icase++);
		while (m--) {
			int l, r;
			scanf("%d%d", &l, &r);
			int k = LOG[r - l + 1];
			printf("%d\n", min(dp[l][k], dp[r - (1 << k) + 1][k]));
		}
	}
	return 0;
}
