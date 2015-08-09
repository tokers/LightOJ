/*************************************************************************
    > File Name: LightOJ1158.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年08月05日 星期三 21时56分30秒
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

int dp[1100][1100];
int bit[11];
int num[11];
char str[12];
int tmp[11];
int m;

void dfs(int now, int sta) {
	if (now <= 9) {
		for (int i = 0; i <= num[now]; ++i) {
			tmp[now] = i;
			dfs(now + 1, sta + i * bit[now]);
		}
	}
	else {
		for (int i = 0; i < m; ++i) {
			for (int k = 0; k <= 9; ++k) {
				if (tmp[k] == num[k]) {
					continue;
				}
				dp[sta + bit[k]][(i * 10 + k) % m] += dp[sta][i];
			}
		}
	}
}

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%s%d", str, &m);
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		memset(num, 0, sizeof(num));
		int len = strlen(str);
		for (int i = 0; i < len; ++i) {
			++num[str[i] - '0'];
		}
		int S = num[0];
		bit[0] = 1;
		for (int i = 1; i <= 9; ++i) {
			bit[i] = bit[i - 1] * (num[i - 1] + 1);
			S += bit[i] * num[i];
		}
		dfs(0, 0);
		printf("Case %d: %d\n", icase++, dp[S][0]);
	}
	return 0;
}
