/*************************************************************************
    > File Name: LightOJ1302.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年09月18日 星期五 19时51分12秒
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

LL dp[80][80];
char str[80];

bool go(int i, int j, int k) {
	int cnt = 0;
	if (str[i] == 'R') {
		++cnt;
	}
	if (str[j] == 'R') {
		++cnt;
	}
	if (str[k] == 'R') {
		++cnt;
	}
	return cnt <= 1;
}

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%s", str);
		int n = strlen(str);
		memset(dp, 0, sizeof(dp));
		for (int i = n - 1; i >= 0; --i) {
			for (int j = i + 2; j < n; j += 3) { // len % 3 == 0
				for (int k = i + 1; k <= j; k += 3) {
					for (int l = k + 1; l <= j; l += 3) {
						if (go(i, k, l)) {
							LL now = 1;
							if (i + 1 <= k - 1) {
								now *= dp[i + 1][k - 1];
							}
							if (k + 1 <= l - 1) {
								now *= dp[k + 1][l - 1];
							}
							if (l + 1 <= j) {
								now *= dp[l + 1][j];
							}
							dp[i][j] += now;
						}
					}
				}
			}
		}
		printf("Case %d: %lld\n", icase++, dp[0][n - 1]);
	}
	return 0;
}
